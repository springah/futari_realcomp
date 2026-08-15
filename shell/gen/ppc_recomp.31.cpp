#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82191AFC"))) PPC_WEAK_FUNC(sub_82191AFC);
PPC_FUNC_IMPL(__imp__sub_82191AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191B00"))) PPC_WEAK_FUNC(sub_82191B00);
PPC_FUNC_IMPL(__imp__sub_82191B00) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,192(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82191B0C"))) PPC_WEAK_FUNC(sub_82191B0C);
PPC_FUNC_IMPL(__imp__sub_82191B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191B10"))) PPC_WEAK_FUNC(sub_82191B10);
PPC_FUNC_IMPL(__imp__sub_82191B10) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191B14"))) PPC_WEAK_FUNC(sub_82191B14);
PPC_FUNC_IMPL(__imp__sub_82191B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191B18"))) PPC_WEAK_FUNC(sub_82191B18);
PPC_FUNC_IMPL(__imp__sub_82191B18) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191B1C"))) PPC_WEAK_FUNC(sub_82191B1C);
PPC_FUNC_IMPL(__imp__sub_82191B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191B20"))) PPC_WEAK_FUNC(sub_82191B20);
PPC_FUNC_IMPL(__imp__sub_82191B20) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r4,404(r3)
	PPC_STORE_U32(ctx.r3.u32 + 404, ctx.r4.u32);
	// addi r10,r11,6928
	ctx.r10.s64 = ctx.r11.s64 + 6928;
	// stw r10,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191B34"))) PPC_WEAK_FUNC(sub_82191B34);
PPC_FUNC_IMPL(__imp__sub_82191B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191B38"))) PPC_WEAK_FUNC(sub_82191B38);
PPC_FUNC_IMPL(__imp__sub_82191B38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82191B40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,356(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 356);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191b60
	if (ctx.cr6.eq) goto loc_82191B60;
	// bl 0x8207a8a0
	ctx.lr = 0x82191B5C;
	sub_8207A8A0(ctx, base);
	// stw r29,356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 356, ctx.r29.u32);
loc_82191B60:
	// lbz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 352);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191b94
	if (ctx.cr6.eq) goto loc_82191B94;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r30,r31,324
	ctx.r30.s64 = ctx.r31.s64 + 324;
	// addi r3,r11,26592
	ctx.r3.s64 = ctx.r11.s64 + 26592;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82088358
	ctx.lr = 0x82191B80;
	sub_82088358(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089490
	ctx.lr = 0x82191B90;
	sub_82089490(ctx, base);
	// stb r29,352(r31)
	PPC_STORE_U8(ctx.r31.u32 + 352, ctx.r29.u8);
loc_82191B94:
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82191bb0
	if (ctx.cr6.eq) goto loc_82191BB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191bb0
	if (ctx.cr6.eq) goto loc_82191BB0;
	// bl 0x82088d00
	ctx.lr = 0x82191BAC;
	sub_82088D00(ctx, base);
	// stw r29,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r29.u32);
loc_82191BB0:
	// lwz r3,396(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82191bcc
	if (ctx.cr6.eq) goto loc_82191BCC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191bcc
	if (ctx.cr6.eq) goto loc_82191BCC;
	// bl 0x82088d00
	ctx.lr = 0x82191BC8;
	sub_82088D00(ctx, base);
	// stw r29,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r29.u32);
loc_82191BCC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82191BD4"))) PPC_WEAK_FUNC(sub_82191BD4);
PPC_FUNC_IMPL(__imp__sub_82191BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191BD8"))) PPC_WEAK_FUNC(sub_82191BD8);
PPC_FUNC_IMPL(__imp__sub_82191BD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,404(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191BE0"))) PPC_WEAK_FUNC(sub_82191BE0);
PPC_FUNC_IMPL(__imp__sub_82191BE0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// addi r9,r10,6936
	ctx.r9.s64 = ctx.r10.s64 + 6936;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82191c08
	if (ctx.cr6.eq) goto loc_82191C08;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r10,6928
	ctx.r9.s64 = ctx.r10.s64 + 6928;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82191c0c
	if (!ctx.cr6.eq) goto loc_82191C0C;
loc_82191C08:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82191C0C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191C14"))) PPC_WEAK_FUNC(sub_82191C14);
PPC_FUNC_IMPL(__imp__sub_82191C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191C18"))) PPC_WEAK_FUNC(sub_82191C18);
PPC_FUNC_IMPL(__imp__sub_82191C18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
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

__attribute__((alias("__imp__sub_82191C2C"))) PPC_WEAK_FUNC(sub_82191C2C);
PPC_FUNC_IMPL(__imp__sub_82191C2C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191C30"))) PPC_WEAK_FUNC(sub_82191C30);
PPC_FUNC_IMPL(__imp__sub_82191C30) {
	PPC_FUNC_PROLOGUE();
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r10.u32);
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
	// stw r11,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191C50"))) PPC_WEAK_FUNC(sub_82191C50);
PPC_FUNC_IMPL(__imp__sub_82191C50) {
	PPC_FUNC_PROLOGUE();
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r9.u32);
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
	// stw r11,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191C7C"))) PPC_WEAK_FUNC(sub_82191C7C);
PPC_FUNC_IMPL(__imp__sub_82191C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191C80"))) PPC_WEAK_FUNC(sub_82191C80);
PPC_FUNC_IMPL(__imp__sub_82191C80) {
	PPC_FUNC_PROLOGUE();
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r9.u32);
	// stw r11,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191CA8"))) PPC_WEAK_FUNC(sub_82191CA8);
PPC_FUNC_IMPL(__imp__sub_82191CA8) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82191cb8
	if (!ctx.cr6.eq) goto loc_82191CB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82191CB8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820893f0
	sub_820893F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82191CC0"))) PPC_WEAK_FUNC(sub_82191CC0);
PPC_FUNC_IMPL(__imp__sub_82191CC0) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82088d00
	sub_82088D00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82191CCC"))) PPC_WEAK_FUNC(sub_82191CCC);
PPC_FUNC_IMPL(__imp__sub_82191CCC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191CD0"))) PPC_WEAK_FUNC(sub_82191CD0);
PPC_FUNC_IMPL(__imp__sub_82191CD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82191CDC"))) PPC_WEAK_FUNC(sub_82191CDC);
PPC_FUNC_IMPL(__imp__sub_82191CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191CE0"))) PPC_WEAK_FUNC(sub_82191CE0);
PPC_FUNC_IMPL(__imp__sub_82191CE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82191CEC"))) PPC_WEAK_FUNC(sub_82191CEC);
PPC_FUNC_IMPL(__imp__sub_82191CEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191CF0"))) PPC_WEAK_FUNC(sub_82191CF0);
PPC_FUNC_IMPL(__imp__sub_82191CF0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82191CFC"))) PPC_WEAK_FUNC(sub_82191CFC);
PPC_FUNC_IMPL(__imp__sub_82191CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191D00"))) PPC_WEAK_FUNC(sub_82191D00);
PPC_FUNC_IMPL(__imp__sub_82191D00) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191d2c
	if (ctx.cr6.eq) goto loc_82191D2C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82191D2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82191D2C:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r9,r11,6936
	ctx.r9.s64 = ctx.r11.s64 + 6936;
	// lwz r11,424(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 424);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82191d58
	if (ctx.cr6.eq) goto loc_82191D58;
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// addi r8,r9,6928
	ctx.r8.s64 = ctx.r9.s64 + 6928;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82191d5c
	if (!ctx.cr6.eq) goto loc_82191D5C;
loc_82191D58:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82191D5C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191d84
	if (ctx.cr6.eq) goto loc_82191D84;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191d7c
	if (ctx.cr6.eq) goto loc_82191D7C;
	// lwz r10,404(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 404);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82191D7C:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82191D84:
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

__attribute__((alias("__imp__sub_82191D98"))) PPC_WEAK_FUNC(sub_82191D98);
PPC_FUNC_IMPL(__imp__sub_82191D98) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191dc4
	if (ctx.cr6.eq) goto loc_82191DC4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82191DC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82191DC4:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r9,r11,6936
	ctx.r9.s64 = ctx.r11.s64 + 6936;
	// lwz r11,424(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 424);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82191df0
	if (ctx.cr6.eq) goto loc_82191DF0;
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// addi r8,r9,6928
	ctx.r8.s64 = ctx.r9.s64 + 6928;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82191df4
	if (!ctx.cr6.eq) goto loc_82191DF4;
loc_82191DF0:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82191DF4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191e1c
	if (ctx.cr6.eq) goto loc_82191E1C;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191e14
	if (ctx.cr6.eq) goto loc_82191E14;
	// lwz r10,404(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 404);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82191E14:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82191E1C:
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

__attribute__((alias("__imp__sub_82191E30"))) PPC_WEAK_FUNC(sub_82191E30);
PPC_FUNC_IMPL(__imp__sub_82191E30) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191e5c
	if (ctx.cr6.eq) goto loc_82191E5C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82191E5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82191E5C:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r9,r11,6936
	ctx.r9.s64 = ctx.r11.s64 + 6936;
	// lwz r11,424(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 424);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82191e88
	if (ctx.cr6.eq) goto loc_82191E88;
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// addi r8,r9,6928
	ctx.r8.s64 = ctx.r9.s64 + 6928;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82191e8c
	if (!ctx.cr6.eq) goto loc_82191E8C;
loc_82191E88:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82191E8C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191eb4
	if (ctx.cr6.eq) goto loc_82191EB4;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191eac
	if (ctx.cr6.eq) goto loc_82191EAC;
	// lwz r10,404(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 404);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82191EAC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82191EB4:
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

__attribute__((alias("__imp__sub_82191EC8"))) PPC_WEAK_FUNC(sub_82191EC8);
PPC_FUNC_IMPL(__imp__sub_82191EC8) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191ef4
	if (ctx.cr6.eq) goto loc_82191EF4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82191EF4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82191EF4:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r9,r11,6936
	ctx.r9.s64 = ctx.r11.s64 + 6936;
	// lwz r11,424(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 424);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82191f20
	if (ctx.cr6.eq) goto loc_82191F20;
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// addi r8,r9,6928
	ctx.r8.s64 = ctx.r9.s64 + 6928;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82191f24
	if (!ctx.cr6.eq) goto loc_82191F24;
loc_82191F20:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82191F24:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191f4c
	if (ctx.cr6.eq) goto loc_82191F4C;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191f44
	if (ctx.cr6.eq) goto loc_82191F44;
	// lwz r10,404(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 404);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82191F44:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82191F4C:
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

__attribute__((alias("__imp__sub_82191F60"))) PPC_WEAK_FUNC(sub_82191F60);
PPC_FUNC_IMPL(__imp__sub_82191F60) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,324
	ctx.r3.s64 = ctx.r3.s64 + 324;
	// bl 0x82089490
	ctx.lr = 0x82191F84;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82191f9c
	if (!ctx.cr6.eq) goto loc_82191F9C;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,6936
	ctx.r8.s64 = ctx.r11.s64 + 6936;
	// b 0x82191fb0
	goto loc_82191FB0;
loc_82191F9C:
	// cmplwi cr6,r3,996
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 996, ctx.xer);
	// beq cr6,0x82191fc0
	if (ctx.cr6.eq) goto loc_82191FC0;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r9,9
	ctx.r9.s64 = 9;
	// addi r8,r11,6928
	ctx.r8.s64 = ctx.r11.s64 + 6928;
loc_82191FB0:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r8.u32);
	// stw r9,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r9.u32);
	// stb r10,352(r31)
	PPC_STORE_U8(ctx.r31.u32 + 352, ctx.r10.u8);
loc_82191FC0:
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

__attribute__((alias("__imp__sub_82191FD4"))) PPC_WEAK_FUNC(sub_82191FD4);
PPC_FUNC_IMPL(__imp__sub_82191FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191FD8"))) PPC_WEAK_FUNC(sub_82191FD8);
PPC_FUNC_IMPL(__imp__sub_82191FD8) {
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
	// lbz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 128);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192000
	if (ctx.cr6.eq) goto loc_82192000;
	// lwz r3,132(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// bl 0x82089a90
	ctx.lr = 0x82192000;
	sub_82089A90(ctx, base);
loc_82192000:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82192010
	if (ctx.cr6.eq) goto loc_82192010;
	// bl 0x8207a8a0
	ctx.lr = 0x82192010;
	sub_8207A8A0(ctx, base);
loc_82192010:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192024
	if (ctx.cr6.eq) goto loc_82192024;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82192024:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192034
	if (ctx.cr6.eq) goto loc_82192034;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82192034:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192064
	if (ctx.cr6.eq) goto loc_82192064;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
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
loc_82192064:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82192080"))) PPC_WEAK_FUNC(sub_82192080);
PPC_FUNC_IMPL(__imp__sub_82192080) {
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
	// lbz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 128);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821920a8
	if (ctx.cr6.eq) goto loc_821920A8;
	// lwz r3,132(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// bl 0x82089a90
	ctx.lr = 0x821920A8;
	sub_82089A90(ctx, base);
loc_821920A8:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821920b8
	if (ctx.cr6.eq) goto loc_821920B8;
	// bl 0x8207a8a0
	ctx.lr = 0x821920B8;
	sub_8207A8A0(ctx, base);
loc_821920B8:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821920cc
	if (ctx.cr6.eq) goto loc_821920CC;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821920CC:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821920dc
	if (ctx.cr6.eq) goto loc_821920DC;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821920DC:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219210c
	if (ctx.cr6.eq) goto loc_8219210C;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
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
loc_8219210C:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82192128"))) PPC_WEAK_FUNC(sub_82192128);
PPC_FUNC_IMPL(__imp__sub_82192128) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82192130;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,108(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82192184
	if (ctx.cr6.eq) goto loc_82192184;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// addi r11,r3,144
	ctx.r11.s64 = ctx.r3.s64 + 144;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82192160
	if (ctx.cr6.lt) goto loc_82192160;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82192164
	goto loc_82192164;
loc_82192160:
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
loc_82192164:
	// addi r30,r31,72
	ctx.r30.s64 = ctx.r31.s64 + 72;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82088358
	ctx.lr = 0x82192170;
	sub_82088358(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089490
	ctx.lr = 0x82192180;
	sub_82089490(ctx, base);
	// stw r29,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
loc_82192184:
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82192198
	if (ctx.cr6.eq) goto loc_82192198;
	// bl 0x8207a8a0
	ctx.lr = 0x82192194;
	sub_8207A8A0(ctx, base);
	// stw r29,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r29.u32);
loc_82192198:
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821921b4
	if (ctx.cr6.eq) goto loc_821921B4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821921b4
	if (ctx.cr6.eq) goto loc_821921B4;
	// bl 0x82088d00
	ctx.lr = 0x821921B0;
	sub_82088D00(ctx, base);
	// stw r29,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r29.u32);
loc_821921B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821921BC"))) PPC_WEAK_FUNC(sub_821921BC);
PPC_FUNC_IMPL(__imp__sub_821921BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821921C0"))) PPC_WEAK_FUNC(sub_821921C0);
PPC_FUNC_IMPL(__imp__sub_821921C0) {
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
	// bl 0x82191b38
	ctx.lr = 0x821921D8;
	sub_82191B38(ctx, base);
	// addi r31,r31,368
	ctx.r31.s64 = ctx.r31.s64 + 368;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821921f0
	if (ctx.cr6.lt) goto loc_821921F0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821921F0;
	sub_8207A630(ctx, base);
loc_821921F0:
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

__attribute__((alias("__imp__sub_82192218"))) PPC_WEAK_FUNC(sub_82192218);
PPC_FUNC_IMPL(__imp__sub_82192218) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82192220;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x8219223C;
	sub_82088928(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r24,r25,76
	ctx.r24.s64 = ctx.r25.s64 + 76;
	// li r26,-1
	ctx.r26.s64 = -1;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8219224C:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82089cf8
	ctx.lr = 0x82192260;
	sub_82089CF8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x821923f4
	if (ctx.cr6.lt) goto loc_821923F4;
	// bne cr6,0x8219224c
	if (!ctx.cr6.eq) goto loc_8219224C;
	// addi r28,r25,88
	ctx.r28.s64 = ctx.r25.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x82192278;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,172(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 172);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821923e0
	if (ctx.cr6.eq) goto loc_821923E0;
	// addi r31,r25,148
	ctx.r31.s64 = ctx.r25.s64 + 148;
loc_82192288:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bne cr6,0x8219233c
	if (!ctx.cr6.eq) goto loc_8219233C;
	// twi 31,r0,22
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_821922A4:
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821922b4
	if (!ctx.cr6.eq) goto loc_821922B4;
	// twi 31,r0,22
loc_821922B4:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r5,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r5.u32);
	// bl 0x821d5394
	ctx.lr = 0x821922E4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// std r29,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, ctx.r29.u64);
	// std r29,8(r4)
	PPC_STORE_U64(ctx.r4.u32 + 8, ctx.r29.u64);
	// stw r29,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r29.u32);
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r27.u32);
	// bl 0x82089a30
	ctx.lr = 0x82192300;
	sub_82089A30(ctx, base);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82089890
	ctx.lr = 0x8219231C;
	sub_82089890(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82089a10
	ctx.lr = 0x82192324;
	sub_82089A10(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82192344
	if (!ctx.cr6.eq) goto loc_82192344;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82192344
	if (ctx.cr6.eq) goto loc_82192344;
	// li r30,-1
	ctx.r30.s64 = -1;
	// b 0x8219235c
	goto loc_8219235C;
loc_8219233C:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821922a4
	goto loc_821922A4;
loc_82192344:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82088438
	ctx.lr = 0x82192350;
	sub_82088438(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82192344
	if (!ctx.cr6.eq) goto loc_82192344;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8219235C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x82192364;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bne cr6,0x821923ec
	if (!ctx.cr6.eq) goto loc_821923EC;
	// twi 31,r0,22
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82192380:
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82192390
	if (!ctx.cr6.eq) goto loc_82192390;
	// twi 31,r0,22
loc_82192390:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x821923c4
	if (ctx.cr6.eq) goto loc_821923C4;
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
	ctx.lr = 0x821923B8;
	sub_8207A630(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
loc_821923C4:
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821923d4
	if (ctx.cr6.eq) goto loc_821923D4;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_821923D4:
	// lwz r11,172(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 172);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82192288
	if (!ctx.cr6.eq) goto loc_82192288;
loc_821923E0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x821923E8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8219224c
	goto loc_8219224C;
loc_821923EC:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82192380
	goto loc_82192380;
loc_821923F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820889c8
	ctx.lr = 0x821923FC;
	sub_820889C8(ctx, base);
}

__attribute__((alias("__imp__sub_821923FC"))) PPC_WEAK_FUNC(sub_821923FC);
PPC_FUNC_IMPL(__imp__sub_821923FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192400"))) PPC_WEAK_FUNC(sub_82192400);
PPC_FUNC_IMPL(__imp__sub_82192400) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82192408;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,108(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r10,104(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lwz r6,80(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// lwz r30,116(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r8,96(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// addi r5,r7,-4
	ctx.r5.s64 = ctx.r7.s64 + -4;
	// add r29,r8,r11
	ctx.r29.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// cmplw cr6,r9,r30
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82192448
	if (!ctx.cr6.lt) goto loc_82192448;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
loc_82192448:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
	// bl 0x82089698
	ctx.lr = 0x82192464;
	sub_82089698(ctx, base);
	// lis r11,-32290
	ctx.r11.s64 = -2116157440;
	// ori r10,r11,8193
	ctx.r10.u64 = ctx.r11.u64 | 8193;
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82192490
	if (!ctx.cr6.eq) goto loc_82192490;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,8152
	ctx.r9.s64 = ctx.r11.s64 + 8152;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82192490:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821924b4
	if (ctx.cr6.eq) goto loc_821924B4;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,8152
	ctx.r9.s64 = ctx.r11.s64 + 8152;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_821924B4:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821924d0
	if (!ctx.cr6.gt) goto loc_821924D0;
	// stw r9,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
loc_821924D0:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// stw r8,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// blt cr6,0x82192568
	if (ctx.cr6.lt) goto loc_82192568;
	// lbz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219250c
	if (ctx.cr6.eq) goto loc_8219250C;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// bl 0x82089a90
	ctx.lr = 0x8219250C;
	sub_82089A90(ctx, base);
loc_8219250C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r9,r11,-48
	ctx.r9.s64 = ctx.r11.s64 + -48;
	// stw r9,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r9.u32);
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// stw r8,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r8.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192538
	if (ctx.cr6.eq) goto loc_82192538;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82192538:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219254c
	if (ctx.cr6.eq) goto loc_8219254C;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8219254C:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192560
	if (ctx.cr6.eq) goto loc_82192560;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82192560:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82192568:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82192570"))) PPC_WEAK_FUNC(sub_82192570);
PPC_FUNC_IMPL(__imp__sub_82192570) {
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
	// beq cr6,0x82192664
	if (ctx.cr6.eq) goto loc_82192664;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192664
	if (ctx.cr6.eq) goto loc_82192664;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192664
	if (ctx.cr6.eq) goto loc_82192664;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// bl 0x8207a030
	ctx.lr = 0x821925BC;
	sub_8207A030(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821925d4
	if (!ctx.cr6.eq) goto loc_821925D4;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x82192668
	goto loc_82192668;
loc_821925D4:
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x821925E4;
	sub_8207DA20(ctx, base);
	// lis r11,4085
	ctx.r11.s64 = 267714560;
	// li r10,259
	ctx.r10.s64 = 259;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// ori r9,r11,4846
	ctx.r9.u64 = ctx.r11.u64 | 4846;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// sth r10,4(r30)
	PPC_STORE_U16(ctx.r30.u32 + 4, ctx.r10.u16);
	// lis r7,8
	ctx.r7.s64 = 524288;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r8,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r8.u32);
	// addi r6,r31,132
	ctx.r6.s64 = ctx.r31.s64 + 132;
	// stw r7,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r7.u32);
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r10,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r10.u32);
	// bl 0x820896c0
	ctx.lr = 0x8219262C;
	sub_820896C0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8219263c
	if (ctx.cr6.eq) goto loc_8219263C;
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x82192668
	goto loc_82192668;
loc_8219263C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,48
	ctx.r8.s64 = 48;
	// stb r10,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r10.u8);
	// addi r7,r11,9216
	ctx.r7.s64 = ctx.r11.s64 + 9216;
	// stw r9,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r9.u32);
	// stw r8,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// b 0x82192678
	goto loc_82192678;
loc_82192664:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82192668:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// addi r9,r11,8152
	ctx.r9.s64 = ctx.r11.s64 + 8152;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
loc_82192678:
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

__attribute__((alias("__imp__sub_82192690"))) PPC_WEAK_FUNC(sub_82192690);
PPC_FUNC_IMPL(__imp__sub_82192690) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82192698;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821926A4:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lwz r30,0(r9)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x821926d4
	if (!ctx.cr6.lt) goto loc_821926D4;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
loc_821926D4:
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r7,r11,r30
	ctx.r7.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8219274c
	if (ctx.cr6.gt) goto loc_8219274C;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82089a68
	ctx.lr = 0x82192700;
	sub_82089A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8219274c
	if (!ctx.cr6.eq) goto loc_8219274C;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// stw r7,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r7.u32);
	// bge cr6,0x82192768
	if (!ctx.cr6.lt) goto loc_82192768;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821926a4
	if (ctx.cr6.lt) goto loc_821926A4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8219274C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r9,r11,8320
	ctx.r9.s64 = ctx.r11.s64 + 8320;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82192768:
	// lbz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219277c
	if (ctx.cr6.eq) goto loc_8219277C;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// bl 0x82089a90
	ctx.lr = 0x8219277C;
	sub_82089A90(ctx, base);
loc_8219277C:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192790
	if (ctx.cr6.eq) goto loc_82192790;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82192790:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821927a4
	if (ctx.cr6.eq) goto loc_821927A4;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821927A4:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821927b8
	if (ctx.cr6.eq) goto loc_821927B8;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821927B8:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821927C8"))) PPC_WEAK_FUNC(sub_821927C8);
PPC_FUNC_IMPL(__imp__sub_821927C8) {
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
	// lwz r30,76(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821928b8
	if (ctx.cr6.eq) goto loc_821928B8;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821928b8
	if (ctx.cr6.eq) goto loc_821928B8;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821928b8
	if (ctx.cr6.eq) goto loc_821928B8;
	// lis r11,4085
	ctx.r11.s64 = 267714560;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// ori r9,r11,4846
	ctx.r9.u64 = ctx.r11.u64 | 4846;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82192820
	if (ctx.cr6.eq) goto loc_82192820;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x821928bc
	goto loc_821928BC;
loc_82192820:
	// lhz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4);
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF00;
	// cmplwi cr6,r10,256
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 256, ctx.xer);
	// bne cr6,0x821928b0
	if (!ctx.cr6.eq) goto loc_821928B0;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x821928b0
	if (!ctx.cr6.eq) goto loc_821928B0;
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// bl 0x8207a030
	ctx.lr = 0x82192848;
	sub_8207A030(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8219285c
	if (!ctx.cr6.eq) goto loc_8219285C;
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x821928bc
	goto loc_821928BC;
loc_8219285C:
	// addi r6,r31,132
	ctx.r6.s64 = ctx.r31.s64 + 132;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82089ae0
	ctx.lr = 0x82192870;
	sub_82089AE0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82192880
	if (ctx.cr6.eq) goto loc_82192880;
	// li r10,5
	ctx.r10.s64 = 5;
	// b 0x821928bc
	goto loc_821928BC;
loc_82192880:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r10,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r10.u8);
	// addi r7,r11,9872
	ctx.r7.s64 = ctx.r11.s64 + 9872;
	// stw r9,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r9.u32);
	// stw r8,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// stw r6,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r6.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// b 0x821928cc
	goto loc_821928CC;
loc_821928B0:
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x821928bc
	goto loc_821928BC;
loc_821928B8:
	// li r10,1
	ctx.r10.s64 = 1;
loc_821928BC:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// addi r9,r11,8320
	ctx.r9.s64 = ctx.r11.s64 + 8320;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
loc_821928CC:
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

__attribute__((alias("__imp__sub_821928E4"))) PPC_WEAK_FUNC(sub_821928E4);
PPC_FUNC_IMPL(__imp__sub_821928E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821928E8"))) PPC_WEAK_FUNC(sub_821928E8);
PPC_FUNC_IMPL(__imp__sub_821928E8) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,4036
	ctx.r10.s64 = ctx.r11.s64 + 4036;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82192918
	if (ctx.cr6.eq) goto loc_82192918;
	// bl 0x82069c00
	ctx.lr = 0x82192918;
	sub_82069C00(ctx, base);
loc_82192918:
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

__attribute__((alias("__imp__sub_82192938"))) PPC_WEAK_FUNC(sub_82192938);
PPC_FUNC_IMPL(__imp__sub_82192938) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// bl 0x82089490
	ctx.lr = 0x8219295C;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821929c4
	if (!ctx.cr6.eq) goto loc_821929C4;
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// addi r11,r31,144
	ctx.r11.s64 = ctx.r31.s64 + 144;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8219297c
	if (ctx.cr6.lt) goto loc_8219297C;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82192980
	goto loc_82192980;
loc_8219297C:
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
loc_82192980:
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// bl 0x8210e878
	ctx.lr = 0x82192988;
	sub_8210E878(ctx, base);
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821929a4
	if (ctx.cr6.eq) goto loc_821929A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82192128
	ctx.lr = 0x821929A4;
	sub_82192128(ctx, base);
loc_821929A4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,6816
	ctx.r10.s64 = ctx.r11.s64 + 6816;
	// stw r10,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
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
loc_821929C4:
	// cmplwi cr6,r3,996
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 996, ctx.xer);
	// beq cr6,0x821929e8
	if (ctx.cr6.eq) goto loc_821929E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82192128
	ctx.lr = 0x821929D4;
	sub_82192128(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,6808
	ctx.r9.s64 = ctx.r11.s64 + 6808;
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
loc_821929E8:
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

__attribute__((alias("__imp__sub_821929FC"))) PPC_WEAK_FUNC(sub_821929FC);
PPC_FUNC_IMPL(__imp__sub_821929FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192A00"))) PPC_WEAK_FUNC(sub_82192A00);
PPC_FUNC_IMPL(__imp__sub_82192A00) {
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
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r30,r3,72
	ctx.r30.s64 = ctx.r3.s64 + 72;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82192A2C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82192a2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82192A2C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x82192A48;
	sub_82088928(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
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
	// bge cr6,0x82192ad8
	if (!ctx.cr6.lt) goto loc_82192AD8;
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// addi r11,r31,144
	ctx.r11.s64 = ctx.r31.s64 + 144;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82192a84
	if (ctx.cr6.lt) goto loc_82192A84;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82192a88
	goto loc_82192A88;
loc_82192A84:
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
loc_82192A88:
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// bl 0x820883f8
	ctx.lr = 0x82192AA0;
	sub_820883F8(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82192ac4
	if (ctx.cr6.eq) goto loc_82192AC4;
	// cmplwi cr6,r3,1392
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1392, ctx.xer);
	// beq cr6,0x82192abc
	if (ctx.cr6.eq) goto loc_82192ABC;
	// bl 0x8210e878
	ctx.lr = 0x82192AB4;
	sub_8210E878(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// b 0x82192adc
	goto loc_82192ADC;
loc_82192ABC:
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x82192adc
	goto loc_82192ADC;
loc_82192AC4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,10552
	ctx.r9.s64 = ctx.r11.s64 + 10552;
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// b 0x82192ae8
	goto loc_82192AE8;
loc_82192AD8:
	// li r10,5
	ctx.r10.s64 = 5;
loc_82192ADC:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// addi r9,r11,6808
	ctx.r9.s64 = ctx.r11.s64 + 6808;
loc_82192AE8:
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82192B04"))) PPC_WEAK_FUNC(sub_82192B04);
PPC_FUNC_IMPL(__imp__sub_82192B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192B08"))) PPC_WEAK_FUNC(sub_82192B08);
PPC_FUNC_IMPL(__imp__sub_82192B08) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// bl 0x82089490
	ctx.lr = 0x82192B2C;
	sub_82089490(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82192b6c
	if (ctx.cr6.eq) goto loc_82192B6C;
	// cmplwi cr6,r3,996
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 996, ctx.xer);
	// beq cr6,0x82192c14
	if (ctx.cr6.eq) goto loc_82192C14;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// cmplwi cr6,r3,1627
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1627, ctx.xer);
	// addi r8,r10,6808
	ctx.r8.s64 = ctx.r10.s64 + 6808;
	// stw r8,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r8.u32);
	// beq cr6,0x82192b60
	if (ctx.cr6.eq) goto loc_82192B60;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r9,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r9.u32);
	// b 0x82192c14
	goto loc_82192C14;
loc_82192B60:
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r9.u32);
	// b 0x82192c14
	goto loc_82192C14;
loc_82192B6C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82192b8c
	if (!ctx.cr6.eq) goto loc_82192B8C;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r10,6808
	ctx.r8.s64 = ctx.r10.s64 + 6808;
	// stw r9,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r9.u32);
	// stw r8,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r8.u32);
	// b 0x82192c14
	goto loc_82192C14;
loc_82192B8C:
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r11,r31,116
	ctx.r11.s64 = ctx.r31.s64 + 116;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// blt cr6,0x82192ba4
	if (ctx.cr6.lt) goto loc_82192BA4;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82192ba8
	goto loc_82192BA8;
loc_82192BA4:
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
loc_82192BA8:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x8207ae18
	ctx.lr = 0x82192BB4;
	sub_8207AE18(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82192c04
	if (!ctx.cr6.eq) goto loc_82192C04;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x82088d00
	ctx.lr = 0x82192BC4;
	sub_82088D00(ctx, base);
	// lwz r10,172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82192be4
	if (ctx.cr6.eq) goto loc_82192BE4;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r10,10752
	ctx.r9.s64 = ctx.r10.s64 + 10752;
	// b 0x82192c0c
	goto loc_82192C0C;
loc_82192BE4:
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// bl 0x8210e878
	ctx.lr = 0x82192BEC;
	sub_8210E878(ctx, base);
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,6816
	ctx.r8.s64 = ctx.r10.s64 + 6816;
	// stw r9,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r9.u32);
	// stw r8,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r8.u32);
	// b 0x82192c10
	goto loc_82192C10;
loc_82192C04:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r10,11312
	ctx.r9.s64 = ctx.r10.s64 + 11312;
loc_82192C0C:
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
loc_82192C10:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82192C14:
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82192C2C"))) PPC_WEAK_FUNC(sub_82192C2C);
PPC_FUNC_IMPL(__imp__sub_82192C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192C30"))) PPC_WEAK_FUNC(sub_82192C30);
PPC_FUNC_IMPL(__imp__sub_82192C30) {
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
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r7,r3,72
	ctx.r7.s64 = ctx.r3.s64 + 72;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82192C58:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82192c58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82192C58;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x82089a18
	ctx.lr = 0x82192C74;
	sub_82089A18(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,11016
	ctx.r10.s64 = ctx.r11.s64 + 11016;
	// stw r10,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82192C94"))) PPC_WEAK_FUNC(sub_82192C94);
PPC_FUNC_IMPL(__imp__sub_82192C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192C98"))) PPC_WEAK_FUNC(sub_82192C98);
PPC_FUNC_IMPL(__imp__sub_82192C98) {
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
	// bge cr6,0x82192d18
	if (!ctx.cr6.lt) goto loc_82192D18;
	// addi r30,r31,104
	ctx.r30.s64 = ctx.r31.s64 + 104;
	// addi r9,r31,184
	ctx.r9.s64 = ctx.r31.s64 + 184;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82088368
	ctx.lr = 0x82192CEC;
	sub_82088368(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82192d10
	if (!ctx.cr6.eq) goto loc_82192D10;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a030
	ctx.lr = 0x82192CFC;
	sub_8207A030(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// addi r10,r11,11312
	ctx.r10.s64 = ctx.r11.s64 + 11312;
	// stw r10,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
	// b 0x82192d2c
	goto loc_82192D2C;
loc_82192D10:
	// li r10,8
	ctx.r10.s64 = 8;
	// b 0x82192d1c
	goto loc_82192D1C;
loc_82192D18:
	// li r10,5
	ctx.r10.s64 = 5;
loc_82192D1C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// addi r9,r11,6808
	ctx.r9.s64 = ctx.r11.s64 + 6808;
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
loc_82192D2C:
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

__attribute__((alias("__imp__sub_82192D44"))) PPC_WEAK_FUNC(sub_82192D44);
PPC_FUNC_IMPL(__imp__sub_82192D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192D48"))) PPC_WEAK_FUNC(sub_82192D48);
PPC_FUNC_IMPL(__imp__sub_82192D48) {
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
	// bl 0x82192128
	ctx.lr = 0x82192D60;
	sub_82192128(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82192D7C"))) PPC_WEAK_FUNC(sub_82192D7C);
PPC_FUNC_IMPL(__imp__sub_82192D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192D80"))) PPC_WEAK_FUNC(sub_82192D80);
PPC_FUNC_IMPL(__imp__sub_82192D80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82192D88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,4020
	ctx.r10.s64 = ctx.r11.s64 + 4020;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x82192128
	ctx.lr = 0x82192DA0;
	sub_82192128(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r29,r31,144
	ctx.r29.s64 = ctx.r31.s64 + 144;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// lwz r8,168(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x82192dc0
	if (ctx.cr6.lt) goto loc_82192DC0;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82192DC0;
	sub_8207A630(ctx, base);
loc_82192DC0:
	// li r28,0
	ctx.r28.s64 = 0;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r28,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r28.u32);
	// addi r30,r31,116
	ctx.r30.s64 = ctx.r31.s64 + 116;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// stb r28,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r28.u8);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// blt cr6,0x82192dec
	if (ctx.cr6.lt) goto loc_82192DEC;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82192DEC;
	sub_8207A630(ctx, base);
loc_82192DEC:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r28.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r29,r11,-1408
	ctx.r29.s64 = ctx.r11.s64 + -1408;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// sth r28,4(r30)
	PPC_STORE_U16(ctx.r30.u32 + 4, ctx.r28.u16);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82192E10;
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
	ctx.lr = 0x82192E28;
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

__attribute__((alias("__imp__sub_82192E38"))) PPC_WEAK_FUNC(sub_82192E38);
PPC_FUNC_IMPL(__imp__sub_82192E38) {
	PPC_FUNC_PROLOGUE();
	// b 0x82192218
	sub_82192218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82192E3C"))) PPC_WEAK_FUNC(sub_82192E3C);
PPC_FUNC_IMPL(__imp__sub_82192E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192E40"))) PPC_WEAK_FUNC(sub_82192E40);
PPC_FUNC_IMPL(__imp__sub_82192E40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82192E48;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,144(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192ef4
	if (ctx.cr6.eq) goto loc_82192EF4;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addi r30,r3,120
	ctx.r30.s64 = ctx.r3.s64 + 120;
	// lwz r11,120(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bne cr6,0x82192efc
	if (!ctx.cr6.eq) goto loc_82192EFC;
	// twi 31,r0,22
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_82192E80:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82192e90
	if (!ctx.cr6.eq) goto loc_82192E90;
	// twi 31,r0,22
loc_82192E90:
	// lwz r31,8(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192ea4
	if (ctx.cr6.eq) goto loc_82192EA4;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_82192EA4:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192eb4
	if (ctx.cr6.eq) goto loc_82192EB4;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_82192EB4:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82192ec8
	if (ctx.cr6.eq) goto loc_82192EC8;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_82192EC8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82192ed8
	if (ctx.cr6.eq) goto loc_82192ED8;
	// bl 0x8207a8a0
	ctx.lr = 0x82192ED8;
	sub_8207A8A0(ctx, base);
loc_82192ED8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82069ad0
	ctx.lr = 0x82192EE0;
	sub_82069AD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82069dd8
	ctx.lr = 0x82192EE8;
	sub_82069DD8(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,14648
	ctx.r10.s64 = ctx.r11.s64 + 14648;
	// stw r10,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
loc_82192EF4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82192EFC:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82192e80
	goto loc_82192E80;
}

__attribute__((alias("__imp__sub_82192F04"))) PPC_WEAK_FUNC(sub_82192F04);
PPC_FUNC_IMPL(__imp__sub_82192F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82192F08"))) PPC_WEAK_FUNC(sub_82192F08);
PPC_FUNC_IMPL(__imp__sub_82192F08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82192F10;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,144(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219304c
	if (ctx.cr6.eq) goto loc_8219304C;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addi r30,r3,120
	ctx.r30.s64 = ctx.r3.s64 + 120;
	// lwz r11,120(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bne cr6,0x82192fd8
	if (!ctx.cr6.eq) goto loc_82192FD8;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82192F44:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82192f54
	if (!ctx.cr6.eq) goto loc_82192F54;
	// twi 31,r0,22
loc_82192F54:
	// lwz r31,8(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r7,60(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82193014
	if (ctx.cr6.eq) goto loc_82193014;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r11,26480
	ctx.r10.s64 = ctx.r11.s64 + 26480;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_82192F74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x82192f98
	if (ctx.cr6.eq) goto loc_82192F98;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82192f74
	if (ctx.cr6.eq) goto loc_82192F74;
loc_82192F98:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82192ff0
	if (!ctx.cr6.eq) goto loc_82192FF0;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82079fd8
	ctx.lr = 0x82192FA8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82192fe0
	if (ctx.cr6.eq) goto loc_82192FE0;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821743d8
	ctx.lr = 0x82192FCC;
	sub_821743D8(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// b 0x82192ff4
	goto loc_82192FF4;
loc_82192FD8:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82192f44
	goto loc_82192F44;
loc_82192FE0:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// b 0x82192ff4
	goto loc_82192FF4;
loc_82192FF0:
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_82192FF4:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8219300c
	if (ctx.cr6.lt) goto loc_8219300C;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82193010
	goto loc_82193010;
loc_8219300C:
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
loc_82193010:
	// bl 0x8210e878
	ctx.lr = 0x82193014;
	sub_8210E878(ctx, base);
loc_82193014:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82193028
	if (ctx.cr6.eq) goto loc_82193028;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82193028:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219303c
	if (ctx.cr6.eq) goto loc_8219303C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_8219303C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82069ad0
	ctx.lr = 0x82193044;
	sub_82069AD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82069dd8
	ctx.lr = 0x8219304C;
	sub_82069DD8(ctx, base);
loc_8219304C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,14648
	ctx.r10.s64 = ctx.r11.s64 + 14648;
	// stw r10,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82193060"))) PPC_WEAK_FUNC(sub_82193060);
PPC_FUNC_IMPL(__imp__sub_82193060) {
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
	// lwz r11,144(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82193090
	if (!ctx.cr6.eq) goto loc_82193090;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,14648
	ctx.r10.s64 = ctx.r11.s64 + 14648;
	// b 0x82193100
	goto loc_82193100;
loc_82193090:
	// lwz r10,140(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// lwz r11,120(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bne cr6,0x821930f0
	if (!ctx.cr6.eq) goto loc_821930F0;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821930AC:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821930bc
	if (!ctx.cr6.eq) goto loc_821930BC;
	// twi 31,r0,22
loc_821930BC:
	// lwz r31,8(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821930f8
	if (!ctx.cr6.eq) goto loc_821930F8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a8a0
	ctx.lr = 0x821930D4;
	sub_8207A8A0(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r11,12040
	ctx.r10.s64 = ctx.r11.s64 + 12040;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// b 0x82193100
	goto loc_82193100;
loc_821930F0:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x821930ac
	goto loc_821930AC;
loc_821930F8:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,11840
	ctx.r10.s64 = ctx.r11.s64 + 11840;
loc_82193100:
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8219311C"))) PPC_WEAK_FUNC(sub_8219311C);
PPC_FUNC_IMPL(__imp__sub_8219311C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82193120"))) PPC_WEAK_FUNC(sub_82193120);
PPC_FUNC_IMPL(__imp__sub_82193120) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82193128;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r9,r10,4004
	ctx.r9.s64 = ctx.r10.s64 + 4004;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8219316c
	if (ctx.cr6.eq) goto loc_8219316C;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8219316c
	if (ctx.cr6.eq) goto loc_8219316C;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// bl 0x82088440
	ctx.lr = 0x82193158;
	sub_82088440(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,84(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 84);
	// bl 0x82088438
	ctx.lr = 0x82193164;
	sub_82088438(ctx, base);
	// lwz r3,84(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 84);
	// bl 0x82088d00
	ctx.lr = 0x8219316C;
	sub_82088D00(ctx, base);
loc_8219316C:
	// addi r30,r24,72
	ctx.r30.s64 = ctx.r24.s64 + 72;
	// li r31,2
	ctx.r31.s64 = 2;
loc_82193174:
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x82088d00
	ctx.lr = 0x8219317C;
	sub_82088D00(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82193174
	if (!ctx.cr0.eq) goto loc_82193174;
	// lwz r11,140(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 140);
	// addi r28,r24,120
	ctx.r28.s64 = ctx.r24.s64 + 120;
	// lwz r10,120(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 120);
	// li r25,0
	ctx.r25.s64 = 0;
	// li r26,15
	ctx.r26.s64 = 15;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwz r29,80(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_821931B4:
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// beq cr6,0x821931cc
	if (ctx.cr6.eq) goto loc_821931CC;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821931d0
	if (ctx.cr6.eq) goto loc_821931D0;
loc_821931CC:
	// twi 31,r0,22
loc_821931D0:
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82193270
	if (ctx.cr6.eq) goto loc_82193270;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82193260
	if (!ctx.cr6.eq) goto loc_82193260;
	// twi 31,r0,22
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_821931E8:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821931f8
	if (!ctx.cr6.eq) goto loc_821931F8;
	// twi 31,r0,22
loc_821931F8:
	// lwz r30,8(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219320c
	if (ctx.cr6.eq) goto loc_8219320C;
	// bl 0x8207a8a0
	ctx.lr = 0x8219320C;
	sub_8207A8A0(ctx, base);
loc_8219320C:
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// addi r31,r30,32
	ctx.r31.s64 = ctx.r30.s64 + 32;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82193224
	if (ctx.cr6.lt) goto loc_82193224;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82193224;
	sub_8207A630(ctx, base);
loc_82193224:
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r25,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r25.u32);
	// stb r25,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r25.u8);
	// bl 0x8207a630
	ctx.lr = 0x82193238;
	sub_8207A630(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82193268
	if (!ctx.cr6.eq) goto loc_82193268;
	// twi 31,r0,22
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_82193248:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82193258
	if (!ctx.cr6.eq) goto loc_82193258;
	// twi 31,r0,22
loc_82193258:
	// lwz r27,0(r27)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// b 0x821931b4
	goto loc_821931B4;
loc_82193260:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x821931e8
	goto loc_821931E8;
loc_82193268:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x82193248
	goto loc_82193248;
loc_82193270:
	// addi r3,r24,148
	ctx.r3.s64 = ctx.r24.s64 + 148;
	// bl 0x82069e68
	ctx.lr = 0x82193278;
	sub_82069E68(ctx, base);
	// lwz r3,168(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 168);
	// bl 0x8207a630
	ctx.lr = 0x82193280;
	sub_8207A630(ctx, base);
	// stw r25,168(r24)
	PPC_STORE_U32(ctx.r24.u32 + 168, ctx.r25.u32);
	// lwz r3,148(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 148);
	// bl 0x8207a630
	ctx.lr = 0x8219328C;
	sub_8207A630(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82069e68
	ctx.lr = 0x82193294;
	sub_82069E68(ctx, base);
	// lwz r3,20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// bl 0x8207a630
	ctx.lr = 0x8219329C;
	sub_8207A630(ctx, base);
	// stw r25,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r25.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821932A8;
	sub_8207A630(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r3,60(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 60);
	// addi r31,r24,44
	ctx.r31.s64 = ctx.r24.s64 + 44;
	// addi r26,r11,-1408
	ctx.r26.s64 = ctx.r11.s64 + -1408;
	// addi r29,r31,16
	ctx.r29.s64 = ctx.r31.s64 + 16;
	// stw r26,44(r24)
	PPC_STORE_U32(ctx.r24.u32 + 44, ctx.r26.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821932ec
	if (ctx.cr6.eq) goto loc_821932EC;
loc_821932C8:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r30,4(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821932E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x821932c8
	if (!ctx.cr6.eq) goto loc_821932C8;
loc_821932EC:
	// stw r25,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r30,r24,16
	ctx.r30.s64 = ctx.r24.s64 + 16;
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r28,r11,-1456
	ctx.r28.s64 = ctx.r11.s64 + -1456;
	// addi r27,r30,16
	ctx.r27.s64 = ctx.r30.s64 + 16;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r26,16(r24)
	PPC_STORE_U32(ctx.r24.u32 + 16, ctx.r26.u32);
	// lwz r3,32(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219333c
	if (ctx.cr6.eq) goto loc_8219333C;
loc_82193318:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r31,4(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193330;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82193318
	if (!ctx.cr6.eq) goto loc_82193318;
loc_8219333C:
	// stw r27,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r27.u32);
	// stw r28,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// stw r25,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r25.u32);
	// stw r28,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82193354"))) PPC_WEAK_FUNC(sub_82193354);
PPC_FUNC_IMPL(__imp__sub_82193354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82193358"))) PPC_WEAK_FUNC(sub_82193358);
PPC_FUNC_IMPL(__imp__sub_82193358) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82193360;
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
	// addi r9,r11,3988
	ctx.r9.s64 = ctx.r11.s64 + 3988;
	// addi r30,r10,-1408
	ctx.r30.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x82193388;
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
	ctx.lr = 0x821933A0;
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

__attribute__((alias("__imp__sub_821933B0"))) PPC_WEAK_FUNC(sub_821933B0);
PPC_FUNC_IMPL(__imp__sub_821933B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821933B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r8,r8,-1396
	ctx.r8.s64 = ctx.r8.s64 + -1396;
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// lis r30,-32251
	ctx.r30.s64 = -2113601536;
	// stb r11,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// addi r3,r3,840
	ctx.r3.s64 = ctx.r3.s64 + 840;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lis r29,13
	ctx.r29.s64 = 851968;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r9,r30,3988
	ctx.r9.s64 = ctx.r30.s64 + 3988;
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// ori r30,r29,12368
	ctx.r30.u64 = ctx.r29.u64 | 12368;
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// lis r29,2
	ctx.r29.s64 = 131072;
	// stb r11,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stb r11,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r11.u8);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stb r8,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r8.u8);
	// stb r8,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r8.u8);
	// stw r4,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r4.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
	// stw r6,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r6.u32);
	// stw r7,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r7.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// stw r29,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r29.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stb r11,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r11.u8);
	// bl 0x82089758
	ctx.lr = 0x82193490;
	sub_82089758(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r3,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,9584
	ctx.r10.s64 = ctx.r11.s64 + 9584;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821934AC"))) PPC_WEAK_FUNC(sub_821934AC);
PPC_FUNC_IMPL(__imp__sub_821934AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821934B0"))) PPC_WEAK_FUNC(sub_821934B0);
PPC_FUNC_IMPL(__imp__sub_821934B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821934B8;
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
	// addi r9,r11,3972
	ctx.r9.s64 = ctx.r11.s64 + 3972;
	// addi r30,r10,-1408
	ctx.r30.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821934E0;
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
	ctx.lr = 0x821934F8;
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

__attribute__((alias("__imp__sub_82193508"))) PPC_WEAK_FUNC(sub_82193508);
PPC_FUNC_IMPL(__imp__sub_82193508) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82193510;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r30,-32251
	ctx.r30.s64 = -2113601536;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// lis r29,-32251
	ctx.r29.s64 = -2113601536;
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// lis r28,-32251
	ctx.r28.s64 = -2113601536;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r30,r30,-1396
	ctx.r30.s64 = ctx.r30.s64 + -1396;
	// stb r11,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// addi r3,r29,840
	ctx.r3.s64 = ctx.r29.s64 + 840;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// addi r29,r28,3972
	ctx.r29.s64 = ctx.r28.s64 + 3972;
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// li r28,7
	ctx.r28.s64 = 7;
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stb r11,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stb r11,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r11.u8);
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stb r30,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r30.u8);
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stw r4,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r4.u32);
	// stw r5,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r5.u32);
	// stw r6,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r6.u32);
	// stw r7,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r7.u32);
	// stw r8,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r28,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r28.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r9,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stb r11,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r11.u8);
	// bl 0x82089758
	ctx.lr = 0x821935DC;
	sub_82089758(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r3,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,10184
	ctx.r10.s64 = ctx.r11.s64 + 10184;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821935F8"))) PPC_WEAK_FUNC(sub_821935F8);
PPC_FUNC_IMPL(__imp__sub_821935F8) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,4072
	ctx.r10.s64 = ctx.r11.s64 + 4072;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82193628
	if (ctx.cr6.eq) goto loc_82193628;
	// bl 0x82069c00
	ctx.lr = 0x82193628;
	sub_82069C00(ctx, base);
loc_82193628:
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

__attribute__((alias("__imp__sub_82193648"))) PPC_WEAK_FUNC(sub_82193648);
PPC_FUNC_IMPL(__imp__sub_82193648) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,4060
	ctx.r10.s64 = ctx.r11.s64 + 4060;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82193678
	if (ctx.cr6.eq) goto loc_82193678;
	// bl 0x82069c00
	ctx.lr = 0x82193678;
	sub_82069C00(ctx, base);
loc_82193678:
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

__attribute__((alias("__imp__sub_82193698"))) PPC_WEAK_FUNC(sub_82193698);
PPC_FUNC_IMPL(__imp__sub_82193698) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,4048
	ctx.r10.s64 = ctx.r11.s64 + 4048;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x821936c8
	if (ctx.cr6.eq) goto loc_821936C8;
	// bl 0x82069c00
	ctx.lr = 0x821936C8;
	sub_82069C00(ctx, base);
loc_821936C8:
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

__attribute__((alias("__imp__sub_821936E8"))) PPC_WEAK_FUNC(sub_821936E8);
PPC_FUNC_IMPL(__imp__sub_821936E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821936F0;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,15
	ctx.r26.s64 = 15;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r26.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stb r29,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r29.u8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r4,r11,-12408
	ctx.r4.s64 = ctx.r11.s64 + -12408;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x82193728;
	sub_820601F8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206a968
	ctx.lr = 0x82193738;
	sub_8206A968(ctx, base);
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8219374c
	if (ctx.cr6.lt) goto loc_8219374C;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x8219374C;
	sub_8207A630(ctx, base);
loc_8219374C:
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r26.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stb r29,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r29.u8);
	// addi r30,r11,26504
	ctx.r30.s64 = ctx.r11.s64 + 26504;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206a100
	ctx.lr = 0x82193774;
	sub_8206A100(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821937b4
	if (ctx.cr6.eq) goto loc_821937B4;
loc_82193780:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82069ed8
	ctx.lr = 0x82193794;
	sub_82069ED8(ctx, base);
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206a100
	ctx.lr = 0x821937A8;
	sub_8206A100(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82193780
	if (!ctx.cr6.eq) goto loc_82193780;
loc_821937B4:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x821937f4
	if (ctx.cr6.eq) goto loc_821937F4;
	// cmpwi cr6,r27,3
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 3, ctx.xer);
	// beq cr6,0x821937e0
	if (ctx.cr6.eq) goto loc_821937E0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821937d8
	if (!ctx.cr6.lt) goto loc_821937D8;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821937D8:
	// li r8,128
	ctx.r8.s64 = 128;
	// b 0x82193804
	goto loc_82193804;
loc_821937E0:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821937ec
	if (!ctx.cr6.lt) goto loc_821937EC;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821937EC:
	// lis r8,16384
	ctx.r8.s64 = 1073741824;
	// b 0x82193804
	goto loc_82193804;
loc_821937F4:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82193800
	if (!ctx.cr6.lt) goto loc_82193800;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_82193800:
	// lis r8,24576
	ctx.r8.s64 = 1610612736;
loc_82193804:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// bl 0x820891f8
	ctx.lr = 0x8219381C;
	sub_820891F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82193834
	if (ctx.cr6.lt) goto loc_82193834;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x82193834;
	sub_8207A630(ctx, base);
loc_82193834:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// blt cr6,0x82193854
	if (ctx.cr6.lt) goto loc_82193854;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82193854;
	sub_8207A630(ctx, base);
loc_82193854:
	// stw r26,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r29.u32);
	// stb r29,4(r28)
	PPC_STORE_U8(ctx.r28.u32 + 4, ctx.r29.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219386C"))) PPC_WEAK_FUNC(sub_8219386C);
PPC_FUNC_IMPL(__imp__sub_8219386C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82193870"))) PPC_WEAK_FUNC(sub_82193870);
PPC_FUNC_IMPL(__imp__sub_82193870) {
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
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82079fd8
	ctx.lr = 0x82193884;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193920
	if (ctx.cr6.eq) goto loc_82193920;
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
	// addi r5,r8,-1396
	ctx.r5.s64 = ctx.r8.s64 + -1396;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r4,r7,840
	ctx.r4.s64 = ctx.r7.s64 + 840;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r9,r6,4084
	ctx.r9.s64 = ctx.r6.s64 + 4084;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r4,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
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
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82193920:
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

__attribute__((alias("__imp__sub_82193934"))) PPC_WEAK_FUNC(sub_82193934);
PPC_FUNC_IMPL(__imp__sub_82193934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82193938"))) PPC_WEAK_FUNC(sub_82193938);
PPC_FUNC_IMPL(__imp__sub_82193938) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82193940;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,144(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82193a58
	if (ctx.cr6.eq) goto loc_82193A58;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// lwz r11,120(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bne cr6,0x821939c8
	if (!ctx.cr6.eq) goto loc_821939C8;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82193970:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82193980
	if (!ctx.cr6.eq) goto loc_82193980;
	// twi 31,r0,22
loc_82193980:
	// lwz r31,8(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82193a58
	if (ctx.cr6.eq) goto loc_82193A58;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821939a0
	if (ctx.cr6.eq) goto loc_821939A0;
	// bl 0x82088d00
	ctx.lr = 0x821939A0;
	sub_82088D00(ctx, base);
loc_821939A0:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x821939d0
	if (!ctx.cr6.lt) goto loc_821939D0;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,11840
	ctx.r10.s64 = ctx.r11.s64 + 11840;
	// stw r10,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_821939C8:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82193970
	goto loc_82193970;
loc_821939D0:
	// lbz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82193a4c
	if (ctx.cr6.eq) goto loc_82193A4C;
	// li r11,7
	ctx.r11.s64 = 7;
	// li r3,136
	ctx.r3.s64 = 136;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// bl 0x82079fd8
	ctx.lr = 0x821939F0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193a18
	if (ctx.cr6.eq) goto loc_82193A18;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r7,r31,24
	ctx.r7.s64 = ctx.r31.s64 + 24;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r31,20
	ctx.r6.s64 = ctx.r31.s64 + 20;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82193508
	ctx.lr = 0x82193A14;
	sub_82193508(ctx, base);
	// b 0x82193a1c
	goto loc_82193A1C;
loc_82193A18:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82193A1C:
	// lwz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,12384
	ctx.r6.s64 = ctx.r8.s64 + 12384;
	// addi r10,r29,16
	ctx.r10.s64 = ctx.r29.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r6,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82193A4C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,12040
	ctx.r10.s64 = ctx.r11.s64 + 12040;
	// stw r10,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
loc_82193A58:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82193A60"))) PPC_WEAK_FUNC(sub_82193A60);
PPC_FUNC_IMPL(__imp__sub_82193A60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82193A68;
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
	// addi r4,r7,4004
	ctx.r4.s64 = ctx.r7.s64 + 4004;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r28,r31,120
	ctx.r28.s64 = ctx.r31.s64 + 120;
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
	ctx.lr = 0x82193B00;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193b10
	if (ctx.cr6.eq) goto loc_82193B10;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// b 0x82193b14
	goto loc_82193B14;
loc_82193B10:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82193B14:
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82079fd8
	ctx.lr = 0x82193B20;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193b2c
	if (ctx.cr6.eq) goto loc_82193B2C;
	// stw r3,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_82193B2C:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82193b38
	if (ctx.cr0.eq) goto loc_82193B38;
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_82193B38:
	// stw r3,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r30.u32);
	// addi r29,r31,148
	ctx.r29.s64 = ctx.r31.s64 + 148;
	// bl 0x82079fd8
	ctx.lr = 0x82193B4C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193b5c
	if (ctx.cr6.eq) goto loc_82193B5C;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x82193b60
	goto loc_82193B60;
loc_82193B5C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82193B60:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x82193B6C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193b78
	if (ctx.cr6.eq) goto loc_82193B78;
	// stw r3,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_82193B78:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82193b84
	if (ctx.cr0.eq) goto loc_82193B84;
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_82193B84:
	// stw r3,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r3.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r30,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r30.u32);
	// bl 0x821d53a4
	ctx.lr = 0x82193B94;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// stw r30,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82069e68
	ctx.lr = 0x82193BA0;
	sub_82069E68(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82069e68
	ctx.lr = 0x82193BA8;
	sub_82069E68(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r29,r31,72
	ctx.r29.s64 = ctx.r31.s64 + 72;
	// addi r10,r11,14648
	ctx.r10.s64 = ctx.r11.s64 + 14648;
	// li r30,2
	ctx.r30.s64 = 2;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82193BBC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x82193BD0;
	sub_82088928(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r29.u32 = ea;
	// bne 0x82193bbc
	if (!ctx.cr0.eq) goto loc_82193BBC;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r11,11832
	ctx.r5.s64 = ctx.r11.s64 + 11832;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088d88
	ctx.lr = 0x82193BFC;
	sub_82088D88(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82088b08
	ctx.lr = 0x82193C08;
	sub_82088B08(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x820889f0
	ctx.lr = 0x82193C14;
	sub_820889F0(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x82088d48
	ctx.lr = 0x82193C1C;
	sub_82088D48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82193C28"))) PPC_WEAK_FUNC(sub_82193C28);
PPC_FUNC_IMPL(__imp__sub_82193C28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82193C30;
	__savegprlr_27(ctx, base);
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// addi r4,r8,840
	ctx.r4.s64 = ctx.r8.s64 + 840;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,4020
	ctx.r10.s64 = ctx.r7.s64 + 4020;
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// stb r30,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r30.u8);
	// stb r30,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r30.u8);
	// li r8,15
	ctx.r8.s64 = 15;
	// stb r30,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r30.u8);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// addi r29,r3,116
	ctx.r29.s64 = ctx.r3.s64 + 116;
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r4,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r4.u32);
	// addi r3,r3,144
	ctx.r3.s64 = ctx.r3.s64 + 144;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r11,r31,68
	ctx.r11.s64 = ctx.r31.s64 + 68;
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r27,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r27.u32);
	// stb r28,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r28.u8);
	// stb r28,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r28.u8);
	// stw r30,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
	// sth r30,120(r31)
	PPC_STORE_U16(ctx.r31.u32 + 120, ctx.r30.u16);
	// stw r30,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r30.u32);
	// stw r8,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r8.u32);
	// stb r30,148(r31)
	PPC_STORE_U8(ctx.r31.u32 + 148, ctx.r30.u8);
	// stw r30,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stb r30,180(r31)
	PPC_STORE_U8(ctx.r31.u32 + 180, ctx.r30.u8);
	// stw r30,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// stw r30,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// stw r7,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r7.u32);
loc_82193D1C:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82193d1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82193D1C;
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
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// blt cr6,0x82193d64
	if (ctx.cr6.lt) goto loc_82193D64;
	// bl 0x8210e878
	ctx.lr = 0x82193D44;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,6808
	ctx.r9.s64 = ctx.r11.s64 + 6808;
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82193D64:
	// cmplwi cr6,r27,2
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 2, ctx.xer);
	// blt cr6,0x82193d94
	if (ctx.cr6.lt) goto loc_82193D94;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8210e878
	ctx.lr = 0x82193D74;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,6808
	ctx.r9.s64 = ctx.r11.s64 + 6808;
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82193D94:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82193dcc
	if (ctx.cr6.eq) goto loc_82193DCC;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_82193DA0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82193da0
	if (!ctx.cr6.eq) goto loc_82193DA0;
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x82193DC4;
	sub_82060368(ctx, base);
	// stw r30,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// b 0x82193de0
	goto loc_82193DE0;
loc_82193DCC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,27096
	ctx.r4.s64 = ctx.r11.s64 + 27096;
	// bl 0x82060368
	ctx.lr = 0x82193DDC;
	sub_82060368(ctx, base);
	// stw r28,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r28.u32);
loc_82193DE0:
	// stw r28,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r28.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-13944
	ctx.r9.s64 = ctx.r11.s64 + -13944;
	// lwzx r30,r10,r9
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207adf0
	ctx.lr = 0x82193DFC;
	sub_8207ADF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8206a848
	ctx.lr = 0x82193E0C;
	sub_8206A848(ctx, base);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r7,r8,11416
	ctx.r7.s64 = ctx.r8.s64 + 11416;
	// stw r7,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82193E24"))) PPC_WEAK_FUNC(sub_82193E24);
PPC_FUNC_IMPL(__imp__sub_82193E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82193E28"))) PPC_WEAK_FUNC(sub_82193E28);
PPC_FUNC_IMPL(__imp__sub_82193E28) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// addi r30,r11,26920
	ctx.r30.s64 = ctx.r11.s64 + 26920;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,-8
	ctx.r4.s64 = ctx.r30.s64 + -8;
	// bl 0x82060368
	ctx.lr = 0x82193E6C;
	sub_82060368(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,368
	ctx.r4.s64 = ctx.r31.s64 + 368;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82061660
	ctx.lr = 0x82193E80;
	sub_82061660(ctx, base);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// bge cr6,0x82193e94
	if (!ctx.cr6.lt) goto loc_82193E94;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_82193E94:
	// bl 0x82089d00
	ctx.lr = 0x82193E98;
	sub_82089D00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82193ebc
	if (ctx.cr6.eq) goto loc_82193EBC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r31,324
	ctx.r4.s64 = ctx.r31.s64 + 324;
	// bl 0x82088358
	ctx.lr = 0x82193EAC;
	sub_82088358(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,8032
	ctx.r10.s64 = ctx.r11.s64 + 8032;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
	// b 0x82193edc
	goto loc_82193EDC;
loc_82193EBC:
	// bl 0x8210e878
	ctx.lr = 0x82193EC0;
	sub_8210E878(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82191b38
	ctx.lr = 0x82193EC8;
	sub_82191B38(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
loc_82193EDC:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82193ef0
	if (ctx.cr6.lt) goto loc_82193EF0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x82193EF0;
	sub_8207A630(ctx, base);
loc_82193EF0:
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

__attribute__((alias("__imp__sub_82193F08"))) PPC_WEAK_FUNC(sub_82193F08);
PPC_FUNC_IMPL(__imp__sub_82193F08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82193F10;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,416(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// rlwinm r8,r8,0,31,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// addic. r30,r8,1
	ctx.xer.ca = ctx.r8.u32 > 4294967294;
	ctx.r30.s64 = ctx.r8.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8219422c
	if (ctx.cr0.eq) goto loc_8219422C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r26,r3,368
	ctx.r26.s64 = ctx.r3.s64 + 368;
	// li r29,15
	ctx.r29.s64 = 15;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r27,-1
	ctx.r27.s64 = -1;
	// addi r25,r11,26860
	ctx.r25.s64 = ctx.r11.s64 + 26860;
loc_82193F4C:
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// addi r4,r25,-88
	ctx.r4.s64 = ctx.r25.s64 + -88;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r28,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// bl 0x82060368
	ctx.lr = 0x82193F6C;
	sub_82060368(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82061660
	ctx.lr = 0x82193F80;
	sub_82061660(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82193f94
	if (!ctx.cr6.lt) goto loc_82193F94;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
loc_82193F94:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r7,412(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// li r8,128
	ctx.r8.s64 = 128;
	// lwz r4,408(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 408);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x820891f8
	ctx.lr = 0x82193FB0;
	sub_820891F8(ctx, base);
	// stw r3,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82194020
	if (!ctx.cr6.eq) goto loc_82194020;
	// lwz r11,416(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 416);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821941e0
	if (ctx.cr6.eq) goto loc_821941E0;
	// addi r7,r31,12
	ctx.r7.s64 = ctx.r31.s64 + 12;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// bctrl 
	ctx.lr = 0x82193FE4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821941c4
	if (ctx.cr6.eq) goto loc_821941C4;
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194004
	if (ctx.cr6.lt) goto loc_82194004;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82194004;
	sub_8207A630(ctx, base);
loc_82194004:
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stb r28,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
	// bne cr6,0x82193f4c
	if (!ctx.cr6.eq) goto loc_82193F4C;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_82194020:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821940d4
	if (ctx.cr6.eq) goto loc_821940D4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8219408c
	if (ctx.cr6.eq) goto loc_8219408C;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x821940ec
	if (!ctx.cr6.eq) goto loc_821940EC;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821940f8
	if (ctx.cr6.eq) goto loc_821940F8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820893f0
	ctx.lr = 0x82194050;
	sub_820893F0(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82194078
	if (ctx.cr6.lt) goto loc_82194078;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8210e878
	ctx.lr = 0x82194074;
	sub_8210E878(ctx, base);
	// b 0x821940f8
	goto loc_821940F8;
loc_82194078:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r26,4
	ctx.r3.s64 = ctx.r26.s64 + 4;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8210e878
	ctx.lr = 0x82194088;
	sub_8210E878(ctx, base);
	// b 0x821940f8
	goto loc_821940F8;
loc_8219408C:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820893f0
	ctx.lr = 0x82194094;
	sub_820893F0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x821940a8
	if (!ctx.cr6.gt) goto loc_821940A8;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_821940A8:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,396(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x82089890
	ctx.lr = 0x821940BC;
	sub_82089890(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821940f0
	if (ctx.cr6.eq) goto loc_821940F0;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x821940f0
	goto loc_821940F0;
loc_821940D4:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82089768
	ctx.lr = 0x821940E8;
	sub_82089768(ctx, base);
	// b 0x821940f0
	goto loc_821940F0;
loc_821940EC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_821940F0:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82194154
	if (ctx.cr6.eq) goto loc_82194154;
loc_821940F8:
	// lwz r3,396(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x82088d00
	ctx.lr = 0x82194100;
	sub_82088D00(ctx, base);
	// lwz r11,416(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 416);
	// stw r28,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82194138
	if (ctx.cr6.eq) goto loc_82194138;
	// addi r7,r31,12
	ctx.r7.s64 = ctx.r31.s64 + 12;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bctrl 
	ctx.lr = 0x8219412C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82194218
	if (!ctx.cr6.eq) goto loc_82194218;
loc_82194138:
	// addi r3,r25,-56
	ctx.r3.s64 = ctx.r25.s64 + -56;
	// addi r4,r31,324
	ctx.r4.s64 = ctx.r31.s64 + 324;
	// bl 0x82088358
	ctx.lr = 0x82194144;
	sub_82088358(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,8032
	ctx.r10.s64 = ctx.r11.s64 + 8032;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
	// b 0x82194218
	goto loc_82194218;
loc_82194154:
	// lwz r3,396(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x82088d00
	ctx.lr = 0x8219415C;
	sub_82088D00(ctx, base);
	// lwz r11,416(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 416);
	// stw r28,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821941b0
	if (ctx.cr6.eq) goto loc_821941B0;
	// addi r7,r31,12
	ctx.r7.s64 = ctx.r31.s64 + 12;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// bctrl 
	ctx.lr = 0x82194188;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82194218
	if (!ctx.cr6.eq) goto loc_82194218;
	// addi r3,r25,-48
	ctx.r3.s64 = ctx.r25.s64 + -48;
	// addi r4,r31,324
	ctx.r4.s64 = ctx.r31.s64 + 324;
	// bl 0x82088358
	ctx.lr = 0x821941A0;
	sub_82088358(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,8032
	ctx.r10.s64 = ctx.r11.s64 + 8032;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
	// b 0x82194218
	goto loc_82194218;
loc_821941B0:
	// bl 0x8210e878
	ctx.lr = 0x821941B4;
	sub_8210E878(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82191b38
	ctx.lr = 0x821941BC;
	sub_82191B38(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
	// b 0x82194208
	goto loc_82194208;
loc_821941C4:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r4,r31,324
	ctx.r4.s64 = ctx.r31.s64 + 324;
	// bl 0x82088358
	ctx.lr = 0x821941D0;
	sub_82088358(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,8032
	ctx.r10.s64 = ctx.r11.s64 + 8032;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
	// b 0x82194218
	goto loc_82194218;
loc_821941E0:
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821941f4
	if (ctx.cr6.lt) goto loc_821941F4;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// b 0x821941f8
	goto loc_821941F8;
loc_821941F4:
	// addi r3,r26,4
	ctx.r3.s64 = ctx.r26.s64 + 4;
loc_821941F8:
	// bl 0x8210e878
	ctx.lr = 0x821941FC;
	sub_8210E878(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82191b38
	ctx.lr = 0x82194204;
	sub_82191B38(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
loc_82194208:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
loc_82194218:
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219422c
	if (ctx.cr6.lt) goto loc_8219422C;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x8219422C;
	sub_8207A630(ctx, base);
loc_8219422C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82194234"))) PPC_WEAK_FUNC(sub_82194234);
PPC_FUNC_IMPL(__imp__sub_82194234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82194238"))) PPC_WEAK_FUNC(sub_82194238);
PPC_FUNC_IMPL(__imp__sub_82194238) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,324
	ctx.r3.s64 = ctx.r3.s64 + 324;
	// bl 0x82089490
	ctx.lr = 0x8219425C;
	sub_82089490(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821942a0
	if (!ctx.cr6.eq) goto loc_821942A0;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,16136
	ctx.r9.s64 = ctx.r11.s64 + 16136;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
	// bne cr6,0x82194328
	if (!ctx.cr6.eq) goto loc_82194328;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,15912
	ctx.r10.s64 = ctx.r11.s64 + 15912;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
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
loc_821942A0:
	// cmplwi cr6,r4,996
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 996, ctx.xer);
	// beq cr6,0x82194328
	if (ctx.cr6.eq) goto loc_82194328;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8210e878
	ctx.lr = 0x821942B0;
	sub_8210E878(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821942c4
	if (ctx.cr6.eq) goto loc_821942C4;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x821942d4
	goto loc_821942D4;
loc_821942C4:
	// lwz r11,364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82194300
	if (!ctx.cr6.eq) goto loc_82194300;
	// li r10,9
	ctx.r10.s64 = 9;
loc_821942D4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
	// bl 0x82191b38
	ctx.lr = 0x821942EC;
	sub_82191B38(ctx, base);
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
loc_82194300:
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82088d00
	ctx.lr = 0x82194308;
	sub_82088D00(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r8,r11,17216
	ctx.r8.s64 = ctx.r11.s64 + 17216;
	// stw r10,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r10.u32);
	// stw r9,364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 364, ctx.r9.u32);
	// stw r8,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r8.u32);
	// bl 0x8210e878
	ctx.lr = 0x82194328;
	sub_8210E878(ctx, base);
loc_82194328:
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

__attribute__((alias("__imp__sub_8219433C"))) PPC_WEAK_FUNC(sub_8219433C);
PPC_FUNC_IMPL(__imp__sub_8219433C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82194340"))) PPC_WEAK_FUNC(sub_82194340);
PPC_FUNC_IMPL(__imp__sub_82194340) {
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
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r30,r3,324
	ctx.r30.s64 = ctx.r3.s64 + 324;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219436C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219436c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219436C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x82194388;
	sub_82088928(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r3.u32);
	// stw r3,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r3.u32);
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
	// bge cr6,0x8219440c
	if (!ctx.cr6.lt) goto loc_8219440C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r6,364(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 364);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r4,r11,26600
	ctx.r4.s64 = ctx.r11.s64 + 26600;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r31,16
	ctx.r5.s64 = ctx.r31.s64 + 16;
	// bl 0x820883f8
	ctx.lr = 0x821943CC;
	sub_820883F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x821943f8
	if (ctx.cr6.eq) goto loc_821943F8;
	// cmplwi cr6,r3,1392
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1392, ctx.xer);
	// beq cr6,0x821943f0
	if (ctx.cr6.eq) goto loc_821943F0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8210e878
	ctx.lr = 0x821943E8;
	sub_8210E878(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
	// b 0x82194410
	goto loc_82194410;
loc_821943F0:
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x82194410
	goto loc_82194410;
loc_821943F8:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,16952
	ctx.r9.s64 = ctx.r11.s64 + 16952;
	// stb r10,352(r31)
	PPC_STORE_U8(ctx.r31.u32 + 352, ctx.r10.u8);
	// b 0x8219441c
	goto loc_8219441C;
loc_8219440C:
	// li r10,4
	ctx.r10.s64 = 4;
loc_82194410:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
loc_8219441C:
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82194438"))) PPC_WEAK_FUNC(sub_82194438);
PPC_FUNC_IMPL(__imp__sub_82194438) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,324
	ctx.r3.s64 = ctx.r3.s64 + 324;
	// bl 0x82089490
	ctx.lr = 0x8219445C;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219449c
	if (ctx.cr6.eq) goto loc_8219449C;
	// cmplwi cr6,r3,996
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 996, ctx.xer);
	// beq cr6,0x82194588
	if (ctx.cr6.eq) goto loc_82194588;
	// cmplwi cr6,r3,1627
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1627, ctx.xer);
	// beq cr6,0x821944a8
	if (ctx.cr6.eq) goto loc_821944A8;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
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
loc_8219449C:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82194514
	if (!ctx.cr6.eq) goto loc_82194514;
loc_821944A8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821944ec
	if (!ctx.cr6.eq) goto loc_821944EC;
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// stw r11,364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 364, ctx.r11.u32);
	// bl 0x82088d00
	ctx.lr = 0x821944C4;
	sub_82088D00(ctx, base);
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,17216
	ctx.r8.s64 = ctx.r10.s64 + 17216;
	// stw r9,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r9.u32);
	// stw r8,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r8.u32);
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
loc_821944EC:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
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
loc_82194514:
	// lwz r11,356(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 356);
	// addi r10,r31,280
	ctx.r10.s64 = ctx.r31.s64 + 280;
	// addi r11,r11,264
	ctx.r11.s64 = ctx.r11.s64 + 264;
loc_82194520:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194544
	if (ctx.cr6.eq) goto loc_82194544;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82194520
	if (ctx.cr6.eq) goto loc_82194520;
loc_82194544:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8219457c
	if (!ctx.cr6.eq) goto loc_8219457C;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82088d00
	ctx.lr = 0x82194554;
	sub_82088D00(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,17216
	ctx.r9.s64 = ctx.r11.s64 + 17216;
	// stw r10,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r10.u32);
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
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
loc_8219457C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,17824
	ctx.r10.s64 = ctx.r11.s64 + 17824;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
loc_82194588:
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

__attribute__((alias("__imp__sub_8219459C"))) PPC_WEAK_FUNC(sub_8219459C);
PPC_FUNC_IMPL(__imp__sub_8219459C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821945A0"))) PPC_WEAK_FUNC(sub_821945A0);
PPC_FUNC_IMPL(__imp__sub_821945A0) {
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
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r7,r3,324
	ctx.r7.s64 = ctx.r3.s64 + 324;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821945C8:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821945c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821945C8;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,360(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r4,356(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 356);
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// bl 0x82089a18
	ctx.lr = 0x821945E4;
	sub_82089A18(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,17464
	ctx.r10.s64 = ctx.r11.s64 + 17464;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82194604"))) PPC_WEAK_FUNC(sub_82194604);
PPC_FUNC_IMPL(__imp__sub_82194604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82194608"))) PPC_WEAK_FUNC(sub_82194608);
PPC_FUNC_IMPL(__imp__sub_82194608) {
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
	// bge cr6,0x82194688
	if (!ctx.cr6.lt) goto loc_82194688;
	// addi r30,r31,360
	ctx.r30.s64 = ctx.r31.s64 + 360;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r9,r31,400
	ctx.r9.s64 = ctx.r31.s64 + 400;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82088368
	ctx.lr = 0x8219465C;
	sub_82088368(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82194680
	if (!ctx.cr6.eq) goto loc_82194680;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a030
	ctx.lr = 0x8219466C;
	sub_8207A030(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r3,356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 356, ctx.r3.u32);
	// addi r10,r11,17824
	ctx.r10.s64 = ctx.r11.s64 + 17824;
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
	// b 0x8219469c
	goto loc_8219469C;
loc_82194680:
	// li r10,9
	ctx.r10.s64 = 9;
	// b 0x8219468c
	goto loc_8219468C;
loc_82194688:
	// li r10,4
	ctx.r10.s64 = 4;
loc_8219468C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
loc_8219469C:
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

__attribute__((alias("__imp__sub_821946B4"))) PPC_WEAK_FUNC(sub_821946B4);
PPC_FUNC_IMPL(__imp__sub_821946B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821946B8"))) PPC_WEAK_FUNC(sub_821946B8);
PPC_FUNC_IMPL(__imp__sub_821946B8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x821946f0
	if (!ctx.cr6.eq) goto loc_821946F0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821946e8
	if (ctx.cr6.eq) goto loc_821946E8;
	// lwz r11,52(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_821946E8:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82194700
	goto loc_82194700;
loc_821946F0:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82194700
	if (ctx.cr6.eq) goto loc_82194700;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82194700:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82194728
	if (ctx.cr6.eq) goto loc_82194728;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,17928
	ctx.r10.s64 = ctx.r11.s64 + 17928;
	// stw r10,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r10.u32);
	// blr 
	return;
loc_82194728:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r10,404(r3)
	PPC_STORE_U32(ctx.r3.u32 + 404, ctx.r10.u32);
	// stw r9,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82194740"))) PPC_WEAK_FUNC(sub_82194740);
PPC_FUNC_IMPL(__imp__sub_82194740) {
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
	// bne cr6,0x821947b4
	if (!ctx.cr6.eq) goto loc_821947B4;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82194798
	if (ctx.cr6.eq) goto loc_82194798;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x82194788;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82194798
	if (ctx.cr6.eq) goto loc_82194798;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_82194798:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821947b4
	if (!ctx.cr6.eq) goto loc_821947B4;
	// li r11,512
	ctx.r11.s64 = 512;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
loc_821947B4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,18104
	ctx.r10.s64 = ctx.r11.s64 + 18104;
	// stw r10,424(r30)
	PPC_STORE_U32(ctx.r30.u32 + 424, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821947D8"))) PPC_WEAK_FUNC(sub_821947D8);
PPC_FUNC_IMPL(__imp__sub_821947D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821947E0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,7
	ctx.r11.s64 = 7;
	// li r24,15
	ctx.r24.s64 = 15;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 388, ctx.r30.u32);
	// stw r24,392(r3)
	PPC_STORE_U32(ctx.r3.u32 + 392, ctx.r24.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,372(r3)
	PPC_STORE_U8(ctx.r3.u32 + 372, ctx.r30.u8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r10,396(r3)
	PPC_STORE_U32(ctx.r3.u32 + 396, ctx.r10.u32);
	// stw r10,400(r3)
	PPC_STORE_U32(ctx.r3.u32 + 400, ctx.r10.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// stw r30,416(r3)
	PPC_STORE_U32(ctx.r3.u32 + 416, ctx.r30.u32);
	// addi r29,r3,368
	ctx.r29.s64 = ctx.r3.s64 + 368;
	// stw r30,420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 420, ctx.r30.u32);
	// stw r30,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r30.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r3,320
	ctx.r10.s64 = ctx.r3.s64 + 320;
loc_82194838:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82194838
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82194838;
	// li r5,308
	ctx.r5.s64 = 308;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x8207da20
	ctx.lr = 0x82194850;
	sub_8207DA20(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r30,356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 356, ctx.r30.u32);
	// stb r30,352(r31)
	PPC_STORE_U8(ctx.r31.u32 + 352, ctx.r30.u8);
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// bge cr6,0x821948f0
	if (!ctx.cr6.lt) goto loc_821948F0;
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194888
	if (ctx.cr6.lt) goto loc_82194888;
	// lwz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// b 0x8219488c
	goto loc_8219488C;
loc_82194888:
	// addi r5,r27,4
	ctx.r5.s64 = ctx.r27.s64 + 4;
loc_8219488C:
	// addi r26,r31,280
	ctx.r26.s64 = ctx.r31.s64 + 280;
	// li r4,42
	ctx.r4.s64 = 42;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8207abf0
	ctx.lr = 0x8219489C;
	sub_8207ABF0(ctx, base);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x821948b0
	if (ctx.cr6.lt) goto loc_821948B0;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x821948b4
	goto loc_821948B4;
loc_821948B0:
	// addi r5,r28,4
	ctx.r5.s64 = ctx.r28.s64 + 4;
loc_821948B4:
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x8207acd0
	ctx.lr = 0x821948C0;
	sub_8207ACD0(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820601f8
	ctx.lr = 0x821948D4;
	sub_820601F8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x8210e878
	ctx.lr = 0x821948E4;
	sub_8210E878(ctx, base);
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r10,18240
	ctx.r9.s64 = ctx.r10.s64 + 18240;
	// b 0x82194904
	goto loc_82194904;
loc_821948F0:
	// bl 0x8210e878
	ctx.lr = 0x821948F4;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,6928
	ctx.r9.s64 = ctx.r11.s64 + 6928;
	// stw r10,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
loc_82194904:
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219491c
	if (ctx.cr6.lt) goto loc_8219491C;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8219491C;
	sub_8207A630(ctx, base);
loc_8219491C:
	// stw r24,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r24.u32);
	// stw r30,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r30.u32);
	// stb r30,4(r27)
	PPC_STORE_U8(ctx.r27.u32 + 4, ctx.r30.u8);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8219493c
	if (ctx.cr6.lt) goto loc_8219493C;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8219493C;
	sub_8207A630(ctx, base);
loc_8219493C:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r30,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r30.u32);
	// stw r11,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r11.u32);
	// sth r30,4(r28)
	PPC_STORE_U16(ctx.r28.u32 + 4, ctx.r30.u16);
	// lwz r10,24(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82194960
	if (ctx.cr6.lt) goto loc_82194960;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194960;
	sub_8207A630(ctx, base);
loc_82194960:
	// stw r24,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r24.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r30.u32);
	// stb r30,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82194978"))) PPC_WEAK_FUNC(sub_82194978);
PPC_FUNC_IMPL(__imp__sub_82194978) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82194980;
	__savegprlr_22(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,4060
	ctx.r10.s64 = ctx.r11.s64 + 4060;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// li r3,428
	ctx.r3.s64 = 428;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stb r31,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r31.u8);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// bl 0x82079fd8
	ctx.lr = 0x821949BC;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r24,15
	ctx.r24.s64 = 15;
	// li r22,7
	ctx.r22.s64 = 7;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82194a4c
	if (ctx.cr6.eq) goto loc_82194A4C;
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r24.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821949F4;
	sub_820601F8(ctx, base);
	// stw r22,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r22.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r31.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x82194A14;
	sub_82063CC8(ctx, base);
	// stw r24,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r24.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x82194A34;
	sub_820601F8(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821947d8
	ctx.lr = 0x82194A48;
	sub_821947D8(ctx, base);
	// b 0x82194a50
	goto loc_82194A50;
loc_82194A4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82194A50:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r3,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// stw r23,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r23.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r10.u32);
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
	// stw r11,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r11.u32);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82194a80
	if (ctx.cr6.eq) goto loc_82194A80;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_82194A80:
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194a94
	if (ctx.cr6.lt) goto loc_82194A94;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194A94;
	sub_8207A630(ctx, base);
loc_82194A94:
	// stw r24,24(r26)
	PPC_STORE_U32(ctx.r26.u32 + 24, ctx.r24.u32);
	// stw r31,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r31.u32);
	// stb r31,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r31.u8);
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x82194ab4
	if (ctx.cr6.lt) goto loc_82194AB4;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194AB4;
	sub_8207A630(ctx, base);
loc_82194AB4:
	// stw r22,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r22.u32);
	// stw r31,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r31.u32);
	// sth r31,4(r27)
	PPC_STORE_U16(ctx.r27.u32 + 4, ctx.r31.u16);
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194ad4
	if (ctx.cr6.lt) goto loc_82194AD4;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194AD4;
	sub_8207A630(ctx, base);
loc_82194AD4:
	// stw r24,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r24.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r31.u32);
	// stb r31,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r31.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82194AEC"))) PPC_WEAK_FUNC(sub_82194AEC);
PPC_FUNC_IMPL(__imp__sub_82194AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82194AF0"))) PPC_WEAK_FUNC(sub_82194AF0);
PPC_FUNC_IMPL(__imp__sub_82194AF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x82194AF8;
	__savegprlr_20(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r22,r10
	ctx.r22.u64 = ctx.r10.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,4048
	ctx.r10.s64 = ctx.r11.s64 + 4048;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// li r3,428
	ctx.r3.s64 = 428;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stb r31,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r31.u8);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82194B3C;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r21,15
	ctx.r21.s64 = 15;
	// li r20,7
	ctx.r20.s64 = 7;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82194bcc
	if (ctx.cr6.eq) goto loc_82194BCC;
	// stw r21,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r21.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82194B74;
	sub_820601F8(ctx, base);
	// stw r20,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r20.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r31.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x82194B94;
	sub_82063CC8(ctx, base);
	// stw r21,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r21.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x82194BB4;
	sub_820601F8(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821947d8
	ctx.lr = 0x82194BC8;
	sub_821947D8(ctx, base);
	// b 0x82194bd0
	goto loc_82194BD0;
loc_82194BCC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82194BD0:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r3,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r24,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r24.u32);
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// stw r23,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r23.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r22,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r22.u32);
	// stw r9,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r9.u32);
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
	// stw r11,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r11.u32);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82194c0c
	if (ctx.cr6.eq) goto loc_82194C0C;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_82194C0C:
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194c20
	if (ctx.cr6.lt) goto loc_82194C20;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194C20;
	sub_8207A630(ctx, base);
loc_82194C20:
	// stw r21,24(r26)
	PPC_STORE_U32(ctx.r26.u32 + 24, ctx.r21.u32);
	// stw r31,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r31.u32);
	// stb r31,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r31.u8);
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x82194c40
	if (ctx.cr6.lt) goto loc_82194C40;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194C40;
	sub_8207A630(ctx, base);
loc_82194C40:
	// stw r20,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r20.u32);
	// stw r31,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r31.u32);
	// sth r31,4(r27)
	PPC_STORE_U16(ctx.r27.u32 + 4, ctx.r31.u16);
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194c60
	if (ctx.cr6.lt) goto loc_82194C60;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194C60;
	sub_8207A630(ctx, base);
loc_82194C60:
	// stw r21,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r21.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r31.u32);
	// stb r31,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r31.u8);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82194C78"))) PPC_WEAK_FUNC(sub_82194C78);
PPC_FUNC_IMPL(__imp__sub_82194C78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82194C80;
	__savegprlr_21(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,4036
	ctx.r10.s64 = ctx.r11.s64 + 4036;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// li r3,428
	ctx.r3.s64 = 428;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stb r31,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r31.u8);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82194CC0;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r24,15
	ctx.r24.s64 = 15;
	// li r21,7
	ctx.r21.s64 = 7;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82194d50
	if (ctx.cr6.eq) goto loc_82194D50;
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r24.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82194CF8;
	sub_820601F8(ctx, base);
	// stw r21,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r21.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r31.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x82194D18;
	sub_82063CC8(ctx, base);
	// stw r24,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r24.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x82194D38;
	sub_820601F8(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821947d8
	ctx.lr = 0x82194D4C;
	sub_821947D8(ctx, base);
	// b 0x82194d54
	goto loc_82194D54;
loc_82194D50:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82194D54:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r3,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r23,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r23.u32);
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// stw r22,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r22.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r9.u32);
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
	// stw r11,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r11.u32);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82194d8c
	if (ctx.cr6.eq) goto loc_82194D8C;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_82194D8C:
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194da0
	if (ctx.cr6.lt) goto loc_82194DA0;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194DA0;
	sub_8207A630(ctx, base);
loc_82194DA0:
	// stw r24,24(r26)
	PPC_STORE_U32(ctx.r26.u32 + 24, ctx.r24.u32);
	// stw r31,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r31.u32);
	// stb r31,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r31.u8);
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x82194dc0
	if (ctx.cr6.lt) goto loc_82194DC0;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194DC0;
	sub_8207A630(ctx, base);
loc_82194DC0:
	// stw r21,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r21.u32);
	// stw r31,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r31.u32);
	// sth r31,4(r27)
	PPC_STORE_U16(ctx.r27.u32 + 4, ctx.r31.u16);
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194de0
	if (ctx.cr6.lt) goto loc_82194DE0;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194DE0;
	sub_8207A630(ctx, base);
loc_82194DE0:
	// stw r24,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r24.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r31.u32);
	// stb r31,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r31.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82194DF8"))) PPC_WEAK_FUNC(sub_82194DF8);
PPC_FUNC_IMPL(__imp__sub_82194DF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x82194E00;
	__savegprlr_20(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,76
	ctx.r3.s64 = 76;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// mr r21,r9
	ctx.r21.u64 = ctx.r9.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82194E28;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r20,15
	ctx.r20.s64 = 15;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82194eb4
	if (ctx.cr6.eq) goto loc_82194EB4;
	// li r5,76
	ctx.r5.s64 = 76;
	// stw r20,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r20.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r27.u32);
	// addi r28,r3,32
	ctx.r28.s64 = ctx.r3.s64 + 32;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stb r27,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r27.u8);
	// bl 0x8207da20
	ctx.lr = 0x82194E5C;
	sub_8207DA20(ctx, base);
	// stw r20,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r20.u32);
	// li r26,-1
	ctx.r26.s64 = -1;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r27.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r27,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r27.u8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820601f8
	ctx.lr = 0x82194E80;
	sub_820601F8(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821936e8
	ctx.lr = 0x82194E8C;
	sub_821936E8(ctx, base);
	// rotlwi r11,r3,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82194ec8
	if (!ctx.cr6.eq) goto loc_82194EC8;
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194ebc
	if (ctx.cr6.lt) goto loc_82194EBC;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8210e878
	ctx.lr = 0x82194EB0;
	sub_8210E878(ctx, base);
	// b 0x82194f14
	goto loc_82194F14;
loc_82194EB4:
	// bl 0x8210e878
	ctx.lr = 0x82194EB8;
	sub_8210E878(ctx, base);
	// b 0x82194f4c
	goto loc_82194F4C;
loc_82194EBC:
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x8210e878
	ctx.lr = 0x82194EC4;
	sub_8210E878(ctx, base);
	// b 0x82194f14
	goto loc_82194F14;
loc_82194EC8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82194edc
	if (!ctx.cr6.eq) goto loc_82194EDC;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// b 0x82194ee4
	goto loc_82194EE4;
loc_82194EDC:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820893f0
	ctx.lr = 0x82194EE4;
	sub_820893F0(ctx, base);
loc_82194EE4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bne cr6,0x82194efc
	if (!ctx.cr6.eq) goto loc_82194EFC;
	// bl 0x8210e878
	ctx.lr = 0x82194EF8;
	sub_8210E878(ctx, base);
	// b 0x82194f14
	goto loc_82194F14;
loc_82194EFC:
	// bl 0x8207a030
	ctx.lr = 0x82194F00;
	sub_8207A030(ctx, base);
	// rotlwi r11,r3,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82194f74
	if (!ctx.cr6.eq) goto loc_82194F74;
	// bl 0x8210e878
	ctx.lr = 0x82194F14;
	sub_8210E878(ctx, base);
loc_82194F14:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82194f28
	if (ctx.cr6.eq) goto loc_82194F28;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x8207a8a0
	ctx.lr = 0x82194F28;
	sub_8207A8A0(ctx, base);
loc_82194F28:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82194f44
	if (ctx.cr6.eq) goto loc_82194F44;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82194f44
	if (ctx.cr6.eq) goto loc_82194F44;
	// bl 0x82088d00
	ctx.lr = 0x82194F44;
	sub_82088D00(ctx, base);
loc_82194F44:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82069ad0
	ctx.lr = 0x82194F4C;
	sub_82069AD0(ctx, base);
loc_82194F4C:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82194f60
	if (ctx.cr6.lt) goto loc_82194F60;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82194F60;
	sub_8207A630(ctx, base);
loc_82194F60:
	// stw r20,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r20.u32);
	// stw r27,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r27.u32);
	// stb r27,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r27.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_82194F74:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820601f8
	ctx.lr = 0x82194F88;
	sub_820601F8(ctx, base);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// stw r25,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r25.u32);
	// addi r3,r30,120
	ctx.r3.s64 = ctx.r30.s64 + 120;
	// stw r24,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r24.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r23,68(r31)
	PPC_STORE_U8(ctx.r31.u32 + 68, ctx.r23.u8);
	// stw r21,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r21.u32);
	// stw r22,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r22.u32);
	// lwz r11,120(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 120);
	// lwz r10,140(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x8206a238
	ctx.lr = 0x82194FC0;
	sub_8206A238(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r30,88
	ctx.r31.s64 = ctx.r30.s64 + 88;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bl 0x821d5384
	ctx.lr = 0x82194FF0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r4,168(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// addi r3,r30,148
	ctx.r3.s64 = ctx.r30.s64 + 148;
	// lwz r11,148(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x8206a328
	ctx.lr = 0x82195010;
	sub_8206A328(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5394
	ctx.lr = 0x82195018;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// bl 0x82088440
	ctx.lr = 0x82195020;
	sub_82088440(ctx, base);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82195044
	if (ctx.cr6.lt) goto loc_82195044;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8210e878
	ctx.lr = 0x82195034;
	sub_8210E878(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82065fe8
	ctx.lr = 0x8219503C;
	sub_82065FE8(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_82195044:
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x8210e878
	ctx.lr = 0x8219504C;
	sub_8210E878(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82065fe8
	ctx.lr = 0x82195054;
	sub_82065FE8(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219505C"))) PPC_WEAK_FUNC(sub_8219505C);
PPC_FUNC_IMPL(__imp__sub_8219505C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195060"))) PPC_WEAK_FUNC(sub_82195060);
PPC_FUNC_IMPL(__imp__sub_82195060) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8219506C"))) PPC_WEAK_FUNC(sub_8219506C);
PPC_FUNC_IMPL(__imp__sub_8219506C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195070"))) PPC_WEAK_FUNC(sub_82195070);
PPC_FUNC_IMPL(__imp__sub_82195070) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82195078;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,3936
	ctx.r10.s64 = ctx.r11.s64 + 3936;
	// addi r30,r3,80
	ctx.r30.s64 = ctx.r3.s64 + 80;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821950a0
	if (ctx.cr6.eq) goto loc_821950A0;
	// bl 0x8207a630
	ctx.lr = 0x821950A0;
	sub_8207A630(ctx, base);
loc_821950A0:
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
	ctx.lr = 0x821950B8;
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
	ctx.lr = 0x821950CC;
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
	ctx.lr = 0x821950E4;
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

__attribute__((alias("__imp__sub_821950F4"))) PPC_WEAK_FUNC(sub_821950F4);
PPC_FUNC_IMPL(__imp__sub_821950F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821950F8"))) PPC_WEAK_FUNC(sub_821950F8);
PPC_FUNC_IMPL(__imp__sub_821950F8) {
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
	// addi r3,r3,420
	ctx.r3.s64 = ctx.r3.s64 + 420;
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82195148
	if (ctx.cr6.eq) goto loc_82195148;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82089490
	ctx.lr = 0x82195128;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219513c
	if (ctx.cr6.eq) goto loc_8219513C;
	// addi r4,r31,76
	ctx.r4.s64 = ctx.r31.s64 + 76;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x82069740
	ctx.lr = 0x8219513C;
	sub_82069740(ctx, base);
loc_8219513C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,21288
	ctx.r10.s64 = ctx.r11.s64 + 21288;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82195148:
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

__attribute__((alias("__imp__sub_8219515C"))) PPC_WEAK_FUNC(sub_8219515C);
PPC_FUNC_IMPL(__imp__sub_8219515C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195160"))) PPC_WEAK_FUNC(sub_82195160);
PPC_FUNC_IMPL(__imp__sub_82195160) {
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
	// addi r5,r3,420
	ctx.r5.s64 = ctx.r3.s64 + 420;
	// addi r4,r3,412
	ctx.r4.s64 = ctx.r3.s64 + 412;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82088e58
	ctx.lr = 0x82195184;
	sub_82088E58(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82195198
	if (!ctx.cr6.eq) goto loc_82195198;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,20728
	ctx.r10.s64 = ctx.r11.s64 + 20728;
	// b 0x821951a4
	goto loc_821951A4;
loc_82195198:
	// bl 0x8210e878
	ctx.lr = 0x8219519C;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,21288
	ctx.r10.s64 = ctx.r11.s64 + 21288;
loc_821951A4:
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

__attribute__((alias("__imp__sub_821951BC"))) PPC_WEAK_FUNC(sub_821951BC);
PPC_FUNC_IMPL(__imp__sub_821951BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821951C0"))) PPC_WEAK_FUNC(sub_821951C0);
PPC_FUNC_IMPL(__imp__sub_821951C0) {
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
	// lwz r11,420(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82195208
	if (ctx.cr6.eq) goto loc_82195208;
	// lwz r11,448(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821951f8
	if (ctx.cr6.eq) goto loc_821951F8;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,20832
	ctx.r10.s64 = ctx.r11.s64 + 20832;
	// b 0x82195204
	goto loc_82195204;
loc_821951F8:
	// bl 0x8210e878
	ctx.lr = 0x821951FC;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,21288
	ctx.r10.s64 = ctx.r11.s64 + 21288;
loc_82195204:
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82195208:
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

__attribute__((alias("__imp__sub_8219521C"))) PPC_WEAK_FUNC(sub_8219521C);
PPC_FUNC_IMPL(__imp__sub_8219521C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195220"))) PPC_WEAK_FUNC(sub_82195220);
PPC_FUNC_IMPL(__imp__sub_82195220) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82195228;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31352);
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r29,40(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// bge cr6,0x82195310
	if (!ctx.cr6.lt) goto loc_82195310;
	// lwz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r28,r3,420
	ctx.r28.s64 = ctx.r3.s64 + 420;
	// stw r29,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r28,-4
	ctx.r11.s64 = ctx.r28.s64 + -4;
	// stw r8,416(r3)
	PPC_STORE_U32(ctx.r3.u32 + 416, ctx.r8.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219526C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219526c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219526C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,42
	ctx.r4.s64 = 42;
	// addi r30,r11,27476
	ctx.r30.s64 = ctx.r11.s64 + 27476;
	// addi r3,r31,368
	ctx.r3.s64 = ctx.r31.s64 + 368;
	// addi r5,r30,-16
	ctx.r5.s64 = ctx.r30.s64 + -16;
	// bl 0x8207abf0
	ctx.lr = 0x8219528C;
	sub_8207ABF0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x8207acd0
	ctx.lr = 0x8219529C;
	sub_8207ACD0(ctx, base);
	// lwz r11,-31352(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31352);
	// addi r30,r31,104
	ctx.r30.s64 = ctx.r31.s64 + 104;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,84(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// bl 0x821903b8
	ctx.lr = 0x821952B4;
	sub_821903B8(ctx, base);
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821952dc
	if (!ctx.cr6.eq) goto loc_821952DC;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,20832
	ctx.r10.s64 = ctx.r11.s64 + 20832;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821952DC:
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r31,448
	ctx.r5.s64 = ctx.r31.s64 + 448;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82088360
	ctx.lr = 0x821952F4;
	sub_82088360(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82195310
	if (!ctx.cr6.eq) goto loc_82195310;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,20928
	ctx.r10.s64 = ctx.r11.s64 + 20928;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82195310:
	// bl 0x8210e878
	ctx.lr = 0x82195314;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,21288
	ctx.r10.s64 = ctx.r11.s64 + 21288;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82195328"))) PPC_WEAK_FUNC(sub_82195328);
PPC_FUNC_IMPL(__imp__sub_82195328) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r4,r11,-31232
	ctx.r4.s64 = ctx.r11.s64 + -31232;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82195408
	if (ctx.cr0.eq) goto loc_82195408;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82195368
	if (!ctx.cr6.gt) goto loc_82195368;
	// twi 31,r0,22
loc_82195368:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bne cr6,0x821953e4
	if (!ctx.cr6.eq) goto loc_821953E4;
	// twi 31,r0,22
loc_82195380:
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82195390
	if (ctx.cr6.lt) goto loc_82195390;
	// twi 31,r0,22
loc_82195390:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82076a10
	ctx.lr = 0x821953A0;
	sub_82076A10(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r11,-13936
	ctx.r10.s64 = ctx.r11.s64 + -13936;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_821953B8:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r8,r31
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x821953ec
	if (ctx.cr6.eq) goto loc_821953EC;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r8,r10,488
	ctx.r8.s64 = ctx.r10.s64 + 488;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x821953b8
	if (ctx.cr6.lt) goto loc_821953B8;
	// lwz r11,76(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// b 0x8219547c
	goto loc_8219547C;
loc_821953E4:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82195380
	goto loc_82195380;
loc_821953EC:
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r9,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r9.u32);
	// b 0x8219547c
	goto loc_8219547C;
loc_82195408:
	// lwz r11,96(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 96);
	// addi r4,r30,80
	ctx.r4.s64 = ctx.r30.s64 + 80;
	// lwz r10,92(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 92);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8219548c
	if (ctx.cr0.eq) goto loc_8219548C;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82195434
	if (!ctx.cr6.gt) goto loc_82195434;
	// twi 31,r0,22
loc_82195434:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bne cr6,0x821954a4
	if (!ctx.cr6.eq) goto loc_821954A4;
	// twi 31,r0,22
	// li r10,0
	ctx.r10.s64 = 0;
loc_82195450:
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82195460
	if (ctx.cr6.lt) goto loc_82195460;
	// twi 31,r0,22
loc_82195460:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r11,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// bl 0x82076a10
	ctx.lr = 0x82195474;
	sub_82076A10(ctx, base);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
loc_8219547C:
	// beq cr6,0x8219548c
	if (ctx.cr6.eq) goto loc_8219548C;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,21024
	ctx.r10.s64 = ctx.r11.s64 + 21024;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
loc_8219548C:
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
loc_821954A4:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82195450
	goto loc_82195450;
}

__attribute__((alias("__imp__sub_821954AC"))) PPC_WEAK_FUNC(sub_821954AC);
PPC_FUNC_IMPL(__imp__sub_821954AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821954B0"))) PPC_WEAK_FUNC(sub_821954B0);
PPC_FUNC_IMPL(__imp__sub_821954B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,21288
	ctx.r10.s64 = ctx.r11.s64 + 21288;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821954C0"))) PPC_WEAK_FUNC(sub_821954C0);
PPC_FUNC_IMPL(__imp__sub_821954C0) {
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
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r11,-31232
	ctx.r3.s64 = ctx.r11.s64 + -31232;
	// bl 0x82069740
	ctx.lr = 0x821954E0;
	sub_82069740(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821954F0"))) PPC_WEAK_FUNC(sub_821954F0);
PPC_FUNC_IMPL(__imp__sub_821954F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821954F8;
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
	// addi r4,r7,3936
	ctx.r4.s64 = ctx.r7.s64 + 3936;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r29,r31,80
	ctx.r29.s64 = ctx.r31.s64 + 80;
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
	ctx.lr = 0x82195590;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821955a0
	if (ctx.cr6.eq) goto loc_821955A0;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x821955a4
	goto loc_821955A4;
loc_821955A0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821955A4:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// addi r3,r11,-31232
	ctx.r3.s64 = ctx.r11.s64 + -31232;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// bl 0x82066558
	ctx.lr = 0x821955C0;
	sub_82066558(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82066558
	ctx.lr = 0x821955C8;
	sub_82066558(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x821d5194
	ctx.lr = 0x821955D0;
	__imp__XNotifyPositionUI(ctx, base);
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r10,21680
	ctx.r9.s64 = ctx.r10.s64 + 21680;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821955E8"))) PPC_WEAK_FUNC(sub_821955E8);
PPC_FUNC_IMPL(__imp__sub_821955E8) {
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
	// lbz r11,374(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 374);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82195678
	if (!ctx.cr6.eq) goto loc_82195678;
	// lwz r3,360(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219561C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 368);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// lbz r11,369(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 369);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x82195658
	if (ctx.cr6.eq) goto loc_82195658;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,3740
	ctx.r8.s64 = ctx.r9.s64 + 3740;
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
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
loc_82195658:
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,3788
	ctx.r8.s64 = ctx.r9.s64 + 3788;
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
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
loc_82195678:
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r3,6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 6, ctx.xer);
	// ble cr6,0x82195688
	if (!ctx.cr6.gt) goto loc_82195688;
	// li r3,255
	ctx.r3.s64 = 255;
loc_82195688:
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

__attribute__((alias("__imp__sub_8219569C"))) PPC_WEAK_FUNC(sub_8219569C);
PPC_FUNC_IMPL(__imp__sub_8219569C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821956A0"))) PPC_WEAK_FUNC(sub_821956A0);
PPC_FUNC_IMPL(__imp__sub_821956A0) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,373(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 373);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821956d0
	if (!ctx.cr6.eq) goto loc_821956D0;
	// lbz r10,368(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 368);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lbz r11,369(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 369);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// addi r8,r9,3692
	ctx.r8.s64 = ctx.r9.s64 + 3692;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// blr 
	return;
loc_821956D0:
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821956D8"))) PPC_WEAK_FUNC(sub_821956D8);
PPC_FUNC_IMPL(__imp__sub_821956D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821956E0;
	__savegprlr_29(ctx, base);
	// lwz r11,404(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8219579c
	if (!ctx.cr6.eq) goto loc_8219579C;
	// lbz r10,369(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 369);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lbz r7,368(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 368);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addic r6,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// rotlwi r11,r7,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// subfe r10,r6,r10
	temp.u8 = (~ctx.r6.u32 + ctx.r10.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r6.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r7,0
	ctx.r7.s64 = 0;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r5,2
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 2, ctx.xer);
	// addi r31,r9,3680
	ctx.r31.s64 = ctx.r9.s64 + 3680;
	// addi r30,r8,3640
	ctx.r30.s64 = ctx.r8.s64 + 3640;
	// blt cr6,0x8219576c
	if (ctx.cr6.lt) goto loc_8219576C;
	// addi r10,r5,-2
	ctx.r10.s64 = ctx.r5.s64 + -2;
	// lbz r9,370(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 370);
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r4,r9,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82195750:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwzu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 + ctx.r6.u64;
	// bdnz 0x82195750
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82195750;
loc_8219576C:
	// cmplw cr6,r4,r5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x8219578c
	if (!ctx.cr6.lt) goto loc_8219578C;
	// lbz r11,370(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 370);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r10,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// lwzx r11,r9,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8219578C:
	// add r11,r6,r7
	ctx.r11.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mulli r3,r11,60
	ctx.r3.s64 = ctx.r11.s64 * 60;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8219579C:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mulli r3,r11,13500
	ctx.r3.s64 = ctx.r11.s64 * 13500;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821957A8"))) PPC_WEAK_FUNC(sub_821957A8);
PPC_FUNC_IMPL(__imp__sub_821957A8) {
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
	// li r11,2
	ctx.r11.s64 = 2;
	// li r30,0
	ctx.r30.s64 = 0;
	// stb r11,375(r3)
	PPC_STORE_U8(ctx.r3.u32 + 375, ctx.r11.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,374(r3)
	PPC_STORE_U8(ctx.r3.u32 + 374, ctx.r30.u8);
	// lwz r3,360(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821957E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82195818
	if (ctx.cr6.eq) goto loc_82195818;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// ble cr6,0x8219580c
	if (!ctx.cr6.gt) goto loc_8219580C;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// bgt cr6,0x8219580c
	if (ctx.cr6.gt) goto loc_8219580C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// stw r11,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// b 0x82195824
	goto loc_82195824;
loc_8219580C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// b 0x82195824
	goto loc_82195824;
loc_82195818:
	// stw r30,384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// stw r30,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r30.u32);
	// stw r30,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
loc_82195824:
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

__attribute__((alias("__imp__sub_8219583C"))) PPC_WEAK_FUNC(sub_8219583C);
PPC_FUNC_IMPL(__imp__sub_8219583C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195840"))) PPC_WEAK_FUNC(sub_82195840);
PPC_FUNC_IMPL(__imp__sub_82195840) {
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
	// cmplwi cr6,r4,16
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 16, ctx.xer);
	// bgt cr6,0x82195a7c
	if (ctx.cr6.gt) goto loc_82195A7C;
	// lis r12,-32231
	ctx.r12.s64 = -2112290816;
	// rlwinm r0,r4,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,22644
	ctx.r12.s64 = ctx.r12.s64 + 22644;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_821958B8;
	case 1:
		goto loc_821958DC;
	case 2:
		goto loc_821958F4;
	case 3:
		goto loc_8219595C;
	case 4:
		goto loc_82195974;
	case 5:
		goto loc_8219598C;
	case 6:
		goto loc_821959A4;
	case 7:
		goto loc_821959A4;
	case 8:
		goto loc_821959A4;
	case 9:
		goto loc_821959BC;
	case 10:
		goto loc_821959D4;
	case 11:
		goto loc_821959EC;
	case 12:
		goto loc_82195A04;
	case 13:
		goto loc_82195A1C;
	case 14:
		goto loc_82195A34;
	case 15:
		goto loc_82195A4C;
	case 16:
		goto loc_82195A64;
	default:
		__builtin_unreachable();
	}
	// lwz r16,22712(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22712);
	// lwz r16,22748(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22748);
	// lwz r16,22772(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22772);
	// lwz r16,22876(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22876);
	// lwz r16,22900(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22900);
	// lwz r16,22924(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22924);
	// lwz r16,22948(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22948);
	// lwz r16,22948(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22948);
	// lwz r16,22948(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22948);
	// lwz r16,22972(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22972);
	// lwz r16,22996(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 22996);
	// lwz r16,23020(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 23020);
	// lwz r16,23044(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 23044);
	// lwz r16,23068(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 23068);
	// lwz r16,23092(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 23092);
	// lwz r16,23116(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 23116);
	// lwz r16,23140(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 23140);
loc_821958B8:
	// lbz r11,368(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 368);
	// lbz r10,369(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 369);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
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
loc_821958DC:
	// lbz r3,370(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 370);
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
loc_821958F4:
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195908;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82195944
	if (ctx.cr6.eq) goto loc_82195944;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// ble cr6,0x82195920
	if (!ctx.cr6.gt) goto loc_82195920;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// ble cr6,0x82195944
	if (!ctx.cr6.gt) goto loc_82195944;
loc_82195920:
	// lbz r11,371(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 371);
	// lbz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 372);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
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
loc_82195944:
	// lbz r3,371(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 371);
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
loc_8219595C:
	// lbz r3,373(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 373);
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
loc_82195974:
	// lbz r3,374(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 374);
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
loc_8219598C:
	// lbz r3,375(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 375);
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
loc_821959A4:
	// lwz r3,380(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 380);
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
loc_821959BC:
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 384);
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
loc_821959D4:
	// lwz r3,388(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 388);
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
loc_821959EC:
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 392);
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
loc_82195A04:
	// lwz r3,396(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
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
loc_82195A1C:
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
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
loc_82195A34:
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 404);
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
loc_82195A4C:
	// lbz r3,377(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 377);
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
loc_82195A64:
	// lwz r3,408(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 408);
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
loc_82195A7C:
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

__attribute__((alias("__imp__sub_82195A94"))) PPC_WEAK_FUNC(sub_82195A94);
PPC_FUNC_IMPL(__imp__sub_82195A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195A98"))) PPC_WEAK_FUNC(sub_82195A98);
PPC_FUNC_IMPL(__imp__sub_82195A98) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,7504
	ctx.r9.s64 = ctx.r11.s64 + 7504;
	// stw r10,340(r3)
	PPC_STORE_U32(ctx.r3.u32 + 340, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82195AB0"))) PPC_WEAK_FUNC(sub_82195AB0);
PPC_FUNC_IMPL(__imp__sub_82195AB0) {
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
	// bl 0x821b53e0
	ctx.lr = 0x82195AC8;
	sub_821B53E0(ctx, base);
	// lwz r11,344(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 344);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82195b38
	if (ctx.cr6.lt) goto loc_82195B38;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x82195b38
	if (ctx.cr6.gt) goto loc_82195B38;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// mulli r10,r11,132
	ctx.r10.s64 = ctx.r11.s64 * 132;
	// lwz r11,-31352(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,80(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// rlwinm r5,r6,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82195b38
	if (ctx.cr6.eq) goto loc_82195B38;
	// lwz r11,328(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// li r10,80
	ctx.r10.s64 = 80;
	// lwz r9,324(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw r11,r7,r10
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r10.s32);
	// addi r6,r11,-3
	ctx.r6.s64 = ctx.r11.s64 + -3;
	// lwz r5,16(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// stw r6,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r6.u32);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82195B38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82195B38:
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

__attribute__((alias("__imp__sub_82195B4C"))) PPC_WEAK_FUNC(sub_82195B4C);
PPC_FUNC_IMPL(__imp__sub_82195B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195B50"))) PPC_WEAK_FUNC(sub_82195B50);
PPC_FUNC_IMPL(__imp__sub_82195B50) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,3840
	ctx.r10.s64 = ctx.r11.s64 + 3840;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82195B60"))) PPC_WEAK_FUNC(sub_82195B60);
PPC_FUNC_IMPL(__imp__sub_82195B60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82195B68;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,312
	ctx.r3.s64 = ctx.r3.s64 + 312;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// bl 0x82063390
	ctx.lr = 0x82195B80;
	sub_82063390(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195B98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lwz r28,28(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// bne cr6,0x82195bac
	if (!ctx.cr6.eq) goto loc_82195BAC;
	// li r28,-1
	ctx.r28.s64 = -1;
	// b 0x82195c70
	goto loc_82195C70;
loc_82195BAC:
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// beq cr6,0x82195c70
	if (ctx.cr6.eq) goto loc_82195C70;
	// cmpwi cr6,r28,17
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 17, ctx.xer);
	// beq cr6,0x82195c70
	if (ctx.cr6.eq) goto loc_82195C70;
	// lwz r11,364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 364);
	// li r28,16
	ctx.r28.s64 = 16;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82195c70
	if (ctx.cr6.eq) goto loc_82195C70;
	// addi r30,r11,16
	ctx.r30.s64 = ctx.r11.s64 + 16;
	// addi r29,r31,368
	ctx.r29.s64 = ctx.r31.s64 + 368;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82195BE4;
	sub_8207DAC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821956d8
	ctx.lr = 0x82195BEC;
	sub_821956D8(ctx, base);
	// stw r3,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r3.u32);
	// lbz r11,375(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 375);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x82195c00
	if (!ctx.cr6.gt) goto loc_82195C00;
	// li r11,255
	ctx.r11.s64 = 255;
loc_82195C00:
	// stb r11,7(r30)
	PPC_STORE_U8(ctx.r30.u32 + 7, ctx.r11.u8);
	// lbz r11,373(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 373);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82195c34
	if (!ctx.cr6.eq) goto loc_82195C34;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lbz r10,369(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 369);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r8,r9,3692
	ctx.r8.s64 = ctx.r9.s64 + 3692;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// b 0x82195c38
	goto loc_82195C38;
loc_82195C34:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82195C38:
	// stb r11,5(r30)
	PPC_STORE_U8(ctx.r30.u32 + 5, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821955e8
	ctx.lr = 0x82195C44;
	sub_821955E8(ctx, base);
	// stb r3,6(r30)
	PPC_STORE_U8(ctx.r30.u32 + 6, ctx.r3.u8);
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82195C5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82195c70
	if (!ctx.cr6.eq) goto loc_82195C70;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
loc_82195C70:
	// lwz r30,360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// addic. r4,r31,368
	ctx.xer.ca = ctx.r31.u32 > 4294966927;
	ctx.r4.s64 = ctx.r31.s64 + 368;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x82195c90
	if (ctx.cr0.eq) goto loc_82195C90;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r30,200
	ctx.r3.s64 = ctx.r30.s64 + 200;
	// bl 0x8207dac0
	ctx.lr = 0x82195C88;
	sub_8207DAC0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r11.u32);
loc_82195C90:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,23176
	ctx.r10.s64 = ctx.r11.s64 + 23176;
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82195cac
	if (ctx.cr6.eq) goto loc_82195CAC;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_82195CAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82195CB4"))) PPC_WEAK_FUNC(sub_82195CB4);
PPC_FUNC_IMPL(__imp__sub_82195CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195CB8"))) PPC_WEAK_FUNC(sub_82195CB8);
PPC_FUNC_IMPL(__imp__sub_82195CB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82195CC0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r28,80
	ctx.r28.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r31,r3,312
	ctx.r31.s64 = ctx.r3.s64 + 312;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r30,0
	ctx.r30.s64 = 0;
	// divw. r8,r9,r28
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x82195d28
	if (!ctx.cr0.gt) goto loc_82195D28;
loc_82195CE8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82063390
	ctx.lr = 0x82195CF4;
	sub_82063390(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,28(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// bl 0x82195840
	ctx.lr = 0x82195D04;
	sub_82195840(ctx, base);
	// stw r3,40(r27)
	PPC_STORE_U32(ctx.r27.u32 + 40, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r3,44(r27)
	PPC_STORE_U32(ctx.r27.u32 + 44, ctx.r3.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r28
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	// cmpw cr6,r30,r8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x82195ce8
	if (ctx.cr6.lt) goto loc_82195CE8;
loc_82195D28:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821b63c0
	ctx.lr = 0x82195D30;
	sub_821B63C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82195D38"))) PPC_WEAK_FUNC(sub_82195D38);
PPC_FUNC_IMPL(__imp__sub_82195D38) {
	PPC_FUNC_PROLOGUE();
	// b 0x821b6548
	sub_821B6548(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82195D3C"))) PPC_WEAK_FUNC(sub_82195D3C);
PPC_FUNC_IMPL(__imp__sub_82195D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82195D40"))) PPC_WEAK_FUNC(sub_82195D40);
PPC_FUNC_IMPL(__imp__sub_82195D40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82195D48;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32224
	ctx.r26.s64 = -2111832064;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// addi r27,r11,31340
	ctx.r27.s64 = ctx.r11.s64 + 31340;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r11,-26992(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -26992);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// li r21,10
	ctx.r21.s64 = 10;
	// ori r25,r9,34463
	ctx.r25.u64 = ctx.r9.u64 | 34463;
	// addi r29,r10,-27232
	ctx.r29.s64 = ctx.r10.s64 + -27232;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82195e7c
	if (!ctx.cr6.eq) goto loc_82195E7C;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// addi r4,r27,-140
	ctx.r4.s64 = ctx.r27.s64 + -140;
	// stw r11,-26992(r26)
	PPC_STORE_U32(ctx.r26.u32 + -26992, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82060190
	ctx.lr = 0x82195D9C;
	sub_82060190(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,9999
	ctx.r11.s64 = 9999;
	// stw r10,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r10.u32);
	// stw r10,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r10.u32);
	// addi r3,r29,56
	ctx.r3.s64 = ctx.r29.s64 + 56;
	// stw r9,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r9.u32);
	// stw r11,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195DD8;
	sub_82060F40(ctx, base);
	// addi r4,r27,-160
	ctx.r4.s64 = ctx.r27.s64 + -160;
	// addi r3,r29,80
	ctx.r3.s64 = ctx.r29.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x82195DE4;
	sub_82060190(ctx, base);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r21,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r21.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,112(r29)
	PPC_STORE_U32(ctx.r29.u32 + 112, ctx.r10.u32);
	// stw r9,116(r29)
	PPC_STORE_U32(ctx.r29.u32 + 116, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,120(r29)
	PPC_STORE_U32(ctx.r29.u32 + 120, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,9999
	ctx.r11.s64 = 9999;
	// stw r10,124(r29)
	PPC_STORE_U32(ctx.r29.u32 + 124, ctx.r10.u32);
	// stw r9,128(r29)
	PPC_STORE_U32(ctx.r29.u32 + 128, ctx.r9.u32);
	// addi r3,r29,136
	ctx.r3.s64 = ctx.r29.s64 + 136;
	// stw r11,132(r29)
	PPC_STORE_U32(ctx.r29.u32 + 132, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195E24;
	sub_82060F40(ctx, base);
	// addi r4,r27,-180
	ctx.r4.s64 = ctx.r27.s64 + -180;
	// addi r3,r29,160
	ctx.r3.s64 = ctx.r29.s64 + 160;
	// bl 0x82060190
	ctx.lr = 0x82195E30;
	sub_82060190(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r25,212(r29)
	PPC_STORE_U32(ctx.r29.u32 + 212, ctx.r25.u32);
	// stw r11,188(r29)
	PPC_STORE_U32(ctx.r29.u32 + 188, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,196(r29)
	PPC_STORE_U32(ctx.r29.u32 + 196, ctx.r9.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,192(r29)
	PPC_STORE_U32(ctx.r29.u32 + 192, ctx.r10.u32);
	// stw r11,200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 200, ctx.r11.u32);
	// addi r3,r29,216
	ctx.r3.s64 = ctx.r29.s64 + 216;
	// stw r10,204(r29)
	PPC_STORE_U32(ctx.r29.u32 + 204, ctx.r10.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r9,208(r29)
	PPC_STORE_U32(ctx.r29.u32 + 208, ctx.r9.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195E6C;
	sub_82060F40(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,20368
	ctx.r3.s64 = ctx.r11.s64 + 20368;
	// bl 0x8207a878
	ctx.lr = 0x82195E78;
	sub_8207A878(ctx, base);
	// lwz r11,-26992(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -26992);
loc_82195E7C:
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r28,r10,-27472
	ctx.r28.s64 = ctx.r10.s64 + -27472;
	// bne cr6,0x82195f88
	if (!ctx.cr6.eq) goto loc_82195F88;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// addi r4,r27,-80
	ctx.r4.s64 = ctx.r27.s64 + -80;
	// stw r11,-26992(r26)
	PPC_STORE_U32(ctx.r26.u32 + -26992, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82060190
	ctx.lr = 0x82195EA4;
	sub_82060190(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,28(r28)
	PPC_STORE_U32(ctx.r28.u32 + 28, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,36(r28)
	PPC_STORE_U32(ctx.r28.u32 + 36, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,40(r28)
	PPC_STORE_U32(ctx.r28.u32 + 40, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,9999
	ctx.r11.s64 = 9999;
	// stw r10,32(r28)
	PPC_STORE_U32(ctx.r28.u32 + 32, ctx.r10.u32);
	// stw r10,44(r28)
	PPC_STORE_U32(ctx.r28.u32 + 44, ctx.r10.u32);
	// addi r3,r28,56
	ctx.r3.s64 = ctx.r28.s64 + 56;
	// stw r9,48(r28)
	PPC_STORE_U32(ctx.r28.u32 + 48, ctx.r9.u32);
	// stw r11,52(r28)
	PPC_STORE_U32(ctx.r28.u32 + 52, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195EE0;
	sub_82060F40(ctx, base);
	// addi r4,r27,-100
	ctx.r4.s64 = ctx.r27.s64 + -100;
	// addi r3,r28,80
	ctx.r3.s64 = ctx.r28.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x82195EEC;
	sub_82060190(ctx, base);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r21,108(r28)
	PPC_STORE_U32(ctx.r28.u32 + 108, ctx.r21.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,112(r28)
	PPC_STORE_U32(ctx.r28.u32 + 112, ctx.r10.u32);
	// stw r9,116(r28)
	PPC_STORE_U32(ctx.r28.u32 + 116, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,120(r28)
	PPC_STORE_U32(ctx.r28.u32 + 120, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,9999
	ctx.r11.s64 = 9999;
	// stw r10,124(r28)
	PPC_STORE_U32(ctx.r28.u32 + 124, ctx.r10.u32);
	// stw r9,128(r28)
	PPC_STORE_U32(ctx.r28.u32 + 128, ctx.r9.u32);
	// addi r3,r28,136
	ctx.r3.s64 = ctx.r28.s64 + 136;
	// stw r11,132(r28)
	PPC_STORE_U32(ctx.r28.u32 + 132, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195F2C;
	sub_82060F40(ctx, base);
	// addi r4,r27,-120
	ctx.r4.s64 = ctx.r27.s64 + -120;
	// addi r3,r28,160
	ctx.r3.s64 = ctx.r28.s64 + 160;
	// bl 0x82060190
	ctx.lr = 0x82195F38;
	sub_82060190(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,188(r28)
	PPC_STORE_U32(ctx.r28.u32 + 188, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 192, ctx.r10.u32);
	// stw r9,196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 196, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 200, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,30000
	ctx.r11.s64 = 30000;
	// stw r10,204(r28)
	PPC_STORE_U32(ctx.r28.u32 + 204, ctx.r10.u32);
	// stw r9,208(r28)
	PPC_STORE_U32(ctx.r28.u32 + 208, ctx.r9.u32);
	// addi r3,r28,216
	ctx.r3.s64 = ctx.r28.s64 + 216;
	// stw r11,212(r28)
	PPC_STORE_U32(ctx.r28.u32 + 212, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195F78;
	sub_82060F40(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,20232
	ctx.r3.s64 = ctx.r11.s64 + 20232;
	// bl 0x8207a878
	ctx.lr = 0x82195F84;
	sub_8207A878(ctx, base);
	// lwz r11,-26992(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -26992);
loc_82195F88:
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r30,r10,-27712
	ctx.r30.s64 = ctx.r10.s64 + -27712;
	// bne cr6,0x82196094
	if (!ctx.cr6.eq) goto loc_82196094;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// addi r4,r27,-20
	ctx.r4.s64 = ctx.r27.s64 + -20;
	// stw r11,-26992(r26)
	PPC_STORE_U32(ctx.r26.u32 + -26992, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82060190
	ctx.lr = 0x82195FB0;
	sub_82060190(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r25,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r25.u32);
	// stw r11,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r9.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r10.u32);
	// stw r11,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r11.u32);
	// addi r3,r30,56
	ctx.r3.s64 = ctx.r30.s64 + 56;
	// stw r10,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r10.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r9,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r9.u32);
	// bl 0x82060f40
	ctx.lr = 0x82195FEC;
	sub_82060F40(ctx, base);
	// addi r4,r27,-40
	ctx.r4.s64 = ctx.r27.s64 + -40;
	// addi r3,r30,80
	ctx.r3.s64 = ctx.r30.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x82195FF8;
	sub_82060190(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r25,132(r30)
	PPC_STORE_U32(ctx.r30.u32 + 132, ctx.r25.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,108(r30)
	PPC_STORE_U32(ctx.r30.u32 + 108, ctx.r11.u32);
	// stw r10,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,116(r30)
	PPC_STORE_U32(ctx.r30.u32 + 116, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,120(r30)
	PPC_STORE_U32(ctx.r30.u32 + 120, ctx.r11.u32);
	// stw r10,124(r30)
	PPC_STORE_U32(ctx.r30.u32 + 124, ctx.r10.u32);
	// addi r3,r30,136
	ctx.r3.s64 = ctx.r30.s64 + 136;
	// stw r9,128(r30)
	PPC_STORE_U32(ctx.r30.u32 + 128, ctx.r9.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bl 0x82060f40
	ctx.lr = 0x82196038;
	sub_82060F40(ctx, base);
	// addi r4,r27,-60
	ctx.r4.s64 = ctx.r27.s64 + -60;
	// addi r3,r30,160
	ctx.r3.s64 = ctx.r30.s64 + 160;
	// bl 0x82060190
	ctx.lr = 0x82196044;
	sub_82060190(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,188(r30)
	PPC_STORE_U32(ctx.r30.u32 + 188, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 200, ctx.r11.u32);
	// lis r11,15
	ctx.r11.s64 = 983040;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,192(r30)
	PPC_STORE_U32(ctx.r30.u32 + 192, ctx.r10.u32);
	// ori r11,r11,16959
	ctx.r11.u64 = ctx.r11.u64 | 16959;
	// stw r10,204(r30)
	PPC_STORE_U32(ctx.r30.u32 + 204, ctx.r10.u32);
	// stw r9,208(r30)
	PPC_STORE_U32(ctx.r30.u32 + 208, ctx.r9.u32);
	// addi r3,r30,216
	ctx.r3.s64 = ctx.r30.s64 + 216;
	// stw r11,212(r30)
	PPC_STORE_U32(ctx.r30.u32 + 212, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x82196084;
	sub_82060F40(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,20096
	ctx.r3.s64 = ctx.r11.s64 + 20096;
	// bl 0x8207a878
	ctx.lr = 0x82196090;
	sub_8207A878(ctx, base);
	// lwz r11,-26992(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -26992);
loc_82196094:
	// rlwinm r9,r11,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r31,r10,-27952
	ctx.r31.s64 = ctx.r10.s64 + -27952;
	// bne cr6,0x8219619c
	if (!ctx.cr6.eq) goto loc_8219619C;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// addi r4,r27,40
	ctx.r4.s64 = ctx.r27.s64 + 40;
	// stw r11,-26992(r26)
	PPC_STORE_U32(ctx.r26.u32 + -26992, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82060190
	ctx.lr = 0x821960BC;
	sub_82060190(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// lis r11,15
	ctx.r11.s64 = 983040;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// ori r11,r11,16959
	ctx.r11.u64 = ctx.r11.u64 | 16959;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x821960FC;
	sub_82060F40(ctx, base);
	// addi r4,r27,20
	ctx.r4.s64 = ctx.r27.s64 + 20;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x82196108;
	sub_82060190(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r25,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r25.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// addi r3,r31,136
	ctx.r3.s64 = ctx.r31.s64 + 136;
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bl 0x82060f40
	ctx.lr = 0x82196148;
	sub_82060F40(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// bl 0x82060190
	ctx.lr = 0x82196154;
	sub_82060190(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r25,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r25.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// stw r10,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r10.u32);
	// addi r3,r31,216
	ctx.r3.s64 = ctx.r31.s64 + 216;
	// stw r9,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r9.u32);
	// bl 0x82060f40
	ctx.lr = 0x82196190;
	sub_82060F40(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,19960
	ctx.r3.s64 = ctx.r11.s64 + 19960;
	// bl 0x8207a878
	ctx.lr = 0x8219619C;
	sub_8207A878(ctx, base);
loc_8219619C:
	// lwz r3,360(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 360);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821961B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82196348
	if (ctx.cr6.eq) goto loc_82196348;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// ble cr6,0x82196284
	if (!ctx.cr6.gt) goto loc_82196284;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// bgt cr6,0x82196284
	if (ctx.cr6.gt) goto loc_82196284;
	// lbz r11,370(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 370);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// rlwinm r30,r23,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// addi r8,r9,3616
	ctx.r8.s64 = ctx.r9.s64 + 3616;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwzx r4,r30,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r8.u32);
	// bl 0x821b69b0
	ctx.lr = 0x821961F4;
	sub_821B69B0(ctx, base);
	// lbz r11,370(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 370);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// addi r4,r6,3628
	ctx.r4.s64 = ctx.r6.s64 + 3628;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwzx r4,r30,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r4.u32);
	// bl 0x821b69b0
	ctx.lr = 0x8219621C;
	sub_821B69B0(ctx, base);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x82196348
	if (!ctx.cr6.eq) goto loc_82196348;
	// lbz r11,370(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 370);
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r31,52
	ctx.r8.s64 = ctx.r31.s64 + 52;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r7,r23,r10
	ctx.r7.u64 = ctx.r23.u64 + ctx.r10.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r5,r7,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r4,r6,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// lwzx r10,r4,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r9,r5,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82196348
	if (ctx.cr6.eq) goto loc_82196348;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,380(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 380);
	// bne cr6,0x82196340
	if (!ctx.cr6.eq) goto loc_82196340;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 380, ctx.r10.u32);
	// bl 0x82195cb8
	ctx.lr = 0x8219627C;
	sub_82195CB8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_82196284:
	// lbz r11,370(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 370);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// rlwinm r31,r23,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// addi r8,r9,3616
	ctx.r8.s64 = ctx.r9.s64 + 3616;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwzx r4,r31,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// bl 0x821b69b0
	ctx.lr = 0x821962B0;
	sub_821B69B0(ctx, base);
	// lbz r11,370(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 370);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// addi r4,r6,3628
	ctx.r4.s64 = ctx.r6.s64 + 3628;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
	// bl 0x821b69b0
	ctx.lr = 0x821962D8;
	sub_821B69B0(ctx, base);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x82196348
	if (!ctx.cr6.eq) goto loc_82196348;
	// lbz r11,370(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 370);
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r30,52
	ctx.r8.s64 = ctx.r30.s64 + 52;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r7,r23,r10
	ctx.r7.u64 = ctx.r23.u64 + ctx.r10.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r5,r7,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r4,r6,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r30,52
	ctx.r3.s64 = ctx.r30.s64 + 52;
	// lwzx r10,r4,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r9,r5,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82196348
	if (ctx.cr6.eq) goto loc_82196348;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// lwz r11,380(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 380);
	// bne cr6,0x82196340
	if (!ctx.cr6.eq) goto loc_82196340;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 380, ctx.r10.u32);
	// bl 0x82195cb8
	ctx.lr = 0x82196338;
	sub_82195CB8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_82196340:
	// divwu r10,r11,r21
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r21.u32);
	// stw r10,380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 380, ctx.r10.u32);
loc_82196348:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82195cb8
	ctx.lr = 0x82196350;
	sub_82195CB8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82196358"))) PPC_WEAK_FUNC(sub_82196358);
PPC_FUNC_IMPL(__imp__sub_82196358) {
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
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// bl 0x821b62d0
	ctx.lr = 0x82196374;
	sub_821B62D0(ctx, base);
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r8,328(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// li r9,80
	ctx.r9.s64 = 80;
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82196398
	if (ctx.cr6.lt) goto loc_82196398;
	// twi 31,r0,22
loc_82196398:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bgt cr6,0x82196648
	if (ctx.cr6.gt) goto loc_82196648;
	// lis r12,-32231
	ctx.r12.s64 = -2112290816;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,25548
	ctx.r12.s64 = ctx.r12.s64 + 25548;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_82196410;
	case 1:
		goto loc_82196468;
	case 2:
		goto loc_82196494;
	case 3:
		goto loc_8219650C;
	case 4:
		goto loc_82196528;
	case 5:
		goto loc_82196544;
	case 6:
		goto loc_82196560;
	case 7:
		goto loc_82196560;
	case 8:
		goto loc_82196560;
	case 9:
		goto loc_8219657C;
	case 10:
		goto loc_82196598;
	case 11:
		goto loc_821965B4;
	case 12:
		goto loc_821965D0;
	case 13:
		goto loc_821965EC;
	case 14:
		goto loc_82196608;
	case 15:
		goto loc_82196624;
	case 16:
		goto loc_82196640;
	default:
		__builtin_unreachable();
	}
	// lwz r16,25616(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25616);
	// lwz r16,25704(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25704);
	// lwz r16,25748(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25748);
	// lwz r16,25868(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25868);
	// lwz r16,25896(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25896);
	// lwz r16,25924(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25924);
	// lwz r16,25952(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25952);
	// lwz r16,25952(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25952);
	// lwz r16,25952(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25952);
	// lwz r16,25980(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 25980);
	// lwz r16,26008(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26008);
	// lwz r16,26036(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26036);
	// lwz r16,26064(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26064);
	// lwz r16,26092(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26092);
	// lwz r16,26120(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26120);
	// lwz r16,26148(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26148);
	// lwz r16,26176(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26176);
loc_82196410:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stb r9,369(r31)
	PPC_STORE_U8(ctx.r31.u32 + 369, ctx.r9.u8);
	// addic r8,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// stb r10,368(r31)
	PPC_STORE_U8(ctx.r31.u32 + 368, ctx.r10.u8);
	// subfe r11,r8,r9
	temp.u8 = (~ctx.r8.u32 + ctx.r9.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82196454;
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
loc_82196468:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r4,370(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 370);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,370(r31)
	PPC_STORE_U8(ctx.r31.u32 + 370, ctx.r11.u8);
	// bl 0x82195d40
	ctx.lr = 0x82196480;
	sub_82195D40(ctx, base);
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
loc_82196494:
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821964A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x821964e8
	if (ctx.cr6.eq) goto loc_821964E8;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// ble cr6,0x821964c0
	if (!ctx.cr6.gt) goto loc_821964C0;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// ble cr6,0x821964e8
	if (!ctx.cr6.gt) goto loc_821964E8;
loc_821964C0:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// stb r10,371(r31)
	PPC_STORE_U8(ctx.r31.u32 + 371, ctx.r10.u8);
	// stb r9,372(r31)
	PPC_STORE_U8(ctx.r31.u32 + 372, ctx.r9.u8);
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
loc_821964E8:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,372(r31)
	PPC_STORE_U8(ctx.r31.u32 + 372, ctx.r10.u8);
	// stb r11,371(r31)
	PPC_STORE_U8(ctx.r31.u32 + 371, ctx.r11.u8);
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
loc_8219650C:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stb r11,373(r31)
	PPC_STORE_U8(ctx.r31.u32 + 373, ctx.r11.u8);
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
loc_82196528:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stb r11,374(r31)
	PPC_STORE_U8(ctx.r31.u32 + 374, ctx.r11.u8);
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
loc_82196544:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stb r11,375(r31)
	PPC_STORE_U8(ctx.r31.u32 + 375, ctx.r11.u8);
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
loc_82196560:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
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
loc_8219657C:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
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
loc_82196598:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
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
loc_821965B4:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
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
loc_821965D0:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
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
loc_821965EC:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
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
loc_82196608:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
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
loc_82196624:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stb r11,377(r31)
	PPC_STORE_U8(ctx.r31.u32 + 377, ctx.r11.u8);
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
loc_82196640:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
loc_82196648:
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

__attribute__((alias("__imp__sub_8219665C"))) PPC_WEAK_FUNC(sub_8219665C);
PPC_FUNC_IMPL(__imp__sub_8219665C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82196660"))) PPC_WEAK_FUNC(sub_82196660);
PPC_FUNC_IMPL(__imp__sub_82196660) {
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
	// bl 0x821b6d20
	ctx.lr = 0x82196678;
	sub_821B6D20(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82195d40
	ctx.lr = 0x82196688;
	sub_82195D40(ctx, base);
	// lbz r11,369(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 369);
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lbz r9,368(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 368);
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,76(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821966BC;
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

__attribute__((alias("__imp__sub_821966D0"))) PPC_WEAK_FUNC(sub_821966D0);
PPC_FUNC_IMPL(__imp__sub_821966D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x821966D8;
	__savegprlr_14(ctx, base);
	// ld r12,-4096(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-20080(r1)
	ea = -20080 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r3,20100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 20100, ctx.r3.u32);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,6
	ctx.r6.s64 = 6;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821b6748
	ctx.lr = 0x8219670C;
	sub_821B6748(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r30,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r30.u32);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// stw r29,364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 364, ctx.r29.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r30,r11,21768
	ctx.r30.s64 = ctx.r11.s64 + 21768;
	// addi r7,r8,3840
	ctx.r7.s64 = ctx.r8.s64 + 3840;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r30,6036
	ctx.r4.s64 = ctx.r30.s64 + 6036;
	// lfs f13,392(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lfs f12,424(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 424);
	ctx.f12.f64 = double(temp.f32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stfs f0,160(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 160, temp.u32);
	// addi r3,r31,220
	ctx.r3.s64 = ctx.r31.s64 + 220;
	// stfs f13,164(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 164, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 212, temp.u32);
	// stfs f12,216(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 216, temp.u32);
	// bl 0x82060368
	ctx.lr = 0x8219675C;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r29,15
	ctx.r29.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r4,r30,6048
	ctx.r4.s64 = ctx.r30.s64 + 6048;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x82196780;
	sub_82060368(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8219678C:
	// stwu r31,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8219678c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219678C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8219679C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821967b4
	if (ctx.cr6.eq) goto loc_821967B4;
	// addi r11,r1,136
	ctx.r11.s64 = ctx.r1.s64 + 136;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// b 0x821967b8
	goto loc_821967B8;
loc_821967B4:
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
loc_821967B8:
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r4,r30,6056
	ctx.r4.s64 = ctx.r30.s64 + 6056;
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r29,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r29.u32);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821967E0;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,184
	ctx.r11.s64 = ctx.r1.s64 + 184;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821967EC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821967ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821967EC;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821967FC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196814
	if (ctx.cr6.eq) goto loc_82196814;
	// addi r11,r1,216
	ctx.r11.s64 = ctx.r1.s64 + 216;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// b 0x82196818
	goto loc_82196818;
loc_82196814:
	// stw r31,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r31.u32);
loc_82196818:
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r31.u32);
	// addi r4,r30,6072
	ctx.r4.s64 = ctx.r30.s64 + 6072;
	// stw r31,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r31.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r31,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r31.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stw r29,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r29.u32);
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r31.u32);
	// stb r31,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196840;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,264
	ctx.r11.s64 = ctx.r1.s64 + 264;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219684C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219684c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219684C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8219685C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196874
	if (ctx.cr6.eq) goto loc_82196874;
	// addi r11,r1,296
	ctx.r11.s64 = ctx.r1.s64 + 296;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// b 0x82196878
	goto loc_82196878;
loc_82196874:
	// stw r31,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r31.u32);
loc_82196878:
	// stw r31,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r31.u32);
	// addi r4,r30,6080
	ctx.r4.s64 = ctx.r30.s64 + 6080;
	// stw r31,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r31.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stw r29,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r29.u32);
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r31.u32);
	// stb r31,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821968A0;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,344
	ctx.r11.s64 = ctx.r1.s64 + 344;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821968AC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821968ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821968AC;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821968BC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821968d4
	if (ctx.cr6.eq) goto loc_821968D4;
	// addi r11,r1,376
	ctx.r11.s64 = ctx.r1.s64 + 376;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r3.u32);
	// b 0x821968d8
	goto loc_821968D8;
loc_821968D4:
	// stw r31,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r31.u32);
loc_821968D8:
	// stw r31,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r31.u32);
	// addi r4,r30,6096
	ctx.r4.s64 = ctx.r30.s64 + 6096;
	// stw r31,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r31.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r31,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r31.u32);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// stw r29,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r29.u32);
	// stw r31,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r31.u32);
	// stb r31,404(r1)
	PPC_STORE_U8(ctx.r1.u32 + 404, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196900;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,424
	ctx.r11.s64 = ctx.r1.s64 + 424;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219690C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219690c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219690C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8219691C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196934
	if (ctx.cr6.eq) goto loc_82196934;
	// addi r11,r1,456
	ctx.r11.s64 = ctx.r1.s64 + 456;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// b 0x82196938
	goto loc_82196938;
loc_82196934:
	// stw r31,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r31.u32);
loc_82196938:
	// stw r31,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r31.u32);
	// addi r4,r30,6104
	ctx.r4.s64 = ctx.r30.s64 + 6104;
	// stw r31,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r31.u32);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// stw r29,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r29.u32);
	// stw r31,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r31.u32);
	// stb r31,484(r1)
	PPC_STORE_U8(ctx.r1.u32 + 484, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196960;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,504
	ctx.r11.s64 = ctx.r1.s64 + 504;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219696C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219696c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219696C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8219697C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196994
	if (ctx.cr6.eq) goto loc_82196994;
	// addi r11,r1,536
	ctx.r11.s64 = ctx.r1.s64 + 536;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r3.u32);
	// b 0x82196998
	goto loc_82196998;
loc_82196994:
	// stw r31,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r31.u32);
loc_82196998:
	// stw r31,548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 548, ctx.r31.u32);
	// addi r4,r30,6120
	ctx.r4.s64 = ctx.r30.s64 + 6120;
	// stw r31,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r31.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r31,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r31.u32);
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// stw r29,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r29.u32);
	// stw r31,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r31.u32);
	// stb r31,564(r1)
	PPC_STORE_U8(ctx.r1.u32 + 564, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821969C0;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,584
	ctx.r11.s64 = ctx.r1.s64 + 584;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821969CC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821969cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821969CC;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821969DC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821969f4
	if (ctx.cr6.eq) goto loc_821969F4;
	// addi r11,r1,616
	ctx.r11.s64 = ctx.r1.s64 + 616;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// b 0x821969f8
	goto loc_821969F8;
loc_821969F4:
	// stw r31,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r31.u32);
loc_821969F8:
	// stw r31,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r31.u32);
	// addi r4,r30,6128
	ctx.r4.s64 = ctx.r30.s64 + 6128;
	// stw r31,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r31.u32);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// stw r29,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r29.u32);
	// stw r31,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, ctx.r31.u32);
	// stb r31,644(r1)
	PPC_STORE_U8(ctx.r1.u32 + 644, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196A20;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,664
	ctx.r11.s64 = ctx.r1.s64 + 664;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196A2C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196a2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196A2C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82196A3C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196a54
	if (ctx.cr6.eq) goto loc_82196A54;
	// addi r11,r1,696
	ctx.r11.s64 = ctx.r1.s64 + 696;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r3.u32);
	// b 0x82196a58
	goto loc_82196A58;
loc_82196A54:
	// stw r31,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r31.u32);
loc_82196A58:
	// stw r31,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, ctx.r31.u32);
	// addi r4,r30,6144
	ctx.r4.s64 = ctx.r30.s64 + 6144;
	// stw r31,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r31.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r31,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r31.u32);
	// addi r3,r1,720
	ctx.r3.s64 = ctx.r1.s64 + 720;
	// stw r29,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r29.u32);
	// stw r31,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r31.u32);
	// stb r31,724(r1)
	PPC_STORE_U8(ctx.r1.u32 + 724, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196A80;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,744
	ctx.r11.s64 = ctx.r1.s64 + 744;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196A8C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196a8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196A8C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82196A9C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196ab4
	if (ctx.cr6.eq) goto loc_82196AB4;
	// addi r11,r1,776
	ctx.r11.s64 = ctx.r1.s64 + 776;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r3.u32);
	// b 0x82196ab8
	goto loc_82196AB8;
loc_82196AB4:
	// stw r31,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r31.u32);
loc_82196AB8:
	// stw r31,788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 788, ctx.r31.u32);
	// addi r4,r30,6152
	ctx.r4.s64 = ctx.r30.s64 + 6152;
	// stw r31,792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 792, ctx.r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 796, ctx.r31.u32);
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// stw r29,824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 824, ctx.r29.u32);
	// stw r31,820(r1)
	PPC_STORE_U32(ctx.r1.u32 + 820, ctx.r31.u32);
	// stb r31,804(r1)
	PPC_STORE_U8(ctx.r1.u32 + 804, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196AE0;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,824
	ctx.r11.s64 = ctx.r1.s64 + 824;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196AEC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196aec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196AEC;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82196AFC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196b14
	if (ctx.cr6.eq) goto loc_82196B14;
	// addi r11,r1,856
	ctx.r11.s64 = ctx.r1.s64 + 856;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, ctx.r3.u32);
	// b 0x82196b18
	goto loc_82196B18;
loc_82196B14:
	// stw r31,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, ctx.r31.u32);
loc_82196B18:
	// stw r31,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r31.u32);
	// addi r4,r30,6168
	ctx.r4.s64 = ctx.r30.s64 + 6168;
	// stw r31,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r31.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r31,876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 876, ctx.r31.u32);
	// addi r3,r1,4240
	ctx.r3.s64 = ctx.r1.s64 + 4240;
	// stw r29,4264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4264, ctx.r29.u32);
	// stw r31,4260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4260, ctx.r31.u32);
	// stb r31,4244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 4244, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82196B40;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4264
	ctx.r11.s64 = ctx.r1.s64 + 4264;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196B4C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196b4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196B4C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82196B5C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82196b74
	if (ctx.cr6.eq) goto loc_82196B74;
	// addi r11,r1,4296
	ctx.r11.s64 = ctx.r1.s64 + 4296;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,4296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4296, ctx.r3.u32);
	// b 0x82196b78
	goto loc_82196B78;
loc_82196B74:
	// stw r31,4296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4296, ctx.r31.u32);
loc_82196B78:
	// stw r31,4308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4308, ctx.r31.u32);
	// addi r4,r30,6180
	ctx.r4.s64 = ctx.r30.s64 + 6180;
	// stw r31,4312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4312, ctx.r31.u32);
	// addi r3,r1,4320
	ctx.r3.s64 = ctx.r1.s64 + 4320;
	// stw r31,4316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4316, ctx.r31.u32);
	// bl 0x82060190
	ctx.lr = 0x82196B90;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4344
	ctx.r11.s64 = ctx.r1.s64 + 4344;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196B9C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196b9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196B9C;
	// addi r3,r1,4376
	ctx.r3.s64 = ctx.r1.s64 + 4376;
	// bl 0x82060f40
	ctx.lr = 0x82196BAC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6188
	ctx.r4.s64 = ctx.r30.s64 + 6188;
	// addi r3,r1,4400
	ctx.r3.s64 = ctx.r1.s64 + 4400;
	// bl 0x82060190
	ctx.lr = 0x82196BB8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4424
	ctx.r11.s64 = ctx.r1.s64 + 4424;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196BC4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196bc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196BC4;
	// addi r3,r1,4456
	ctx.r3.s64 = ctx.r1.s64 + 4456;
	// bl 0x82060f40
	ctx.lr = 0x82196BD4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6196
	ctx.r4.s64 = ctx.r30.s64 + 6196;
	// addi r3,r1,16320
	ctx.r3.s64 = ctx.r1.s64 + 16320;
	// bl 0x82060190
	ctx.lr = 0x82196BE0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16344
	ctx.r11.s64 = ctx.r1.s64 + 16344;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196BEC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196bec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196BEC;
	// addi r3,r1,16376
	ctx.r3.s64 = ctx.r1.s64 + 16376;
	// bl 0x82060f40
	ctx.lr = 0x82196BFC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6208
	ctx.r4.s64 = ctx.r30.s64 + 6208;
	// addi r3,r1,16400
	ctx.r3.s64 = ctx.r1.s64 + 16400;
	// bl 0x82060190
	ctx.lr = 0x82196C08;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16424
	ctx.r11.s64 = ctx.r1.s64 + 16424;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196C14:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196c14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196C14;
	// addi r3,r1,16456
	ctx.r3.s64 = ctx.r1.s64 + 16456;
	// bl 0x82060f40
	ctx.lr = 0x82196C24;
	sub_82060F40(ctx, base);
	// addi r4,r30,6216
	ctx.r4.s64 = ctx.r30.s64 + 6216;
	// addi r3,r1,16480
	ctx.r3.s64 = ctx.r1.s64 + 16480;
	// bl 0x82060190
	ctx.lr = 0x82196C30;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16504
	ctx.r11.s64 = ctx.r1.s64 + 16504;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196C3C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196c3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196C3C;
	// addi r3,r1,16536
	ctx.r3.s64 = ctx.r1.s64 + 16536;
	// bl 0x82060f40
	ctx.lr = 0x82196C4C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6220
	ctx.r4.s64 = ctx.r30.s64 + 6220;
	// addi r3,r1,17280
	ctx.r3.s64 = ctx.r1.s64 + 17280;
	// bl 0x82060190
	ctx.lr = 0x82196C58;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17304
	ctx.r11.s64 = ctx.r1.s64 + 17304;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196C64:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196c64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196C64;
	// addi r3,r1,17336
	ctx.r3.s64 = ctx.r1.s64 + 17336;
	// bl 0x82060f40
	ctx.lr = 0x82196C74;
	sub_82060F40(ctx, base);
	// addi r4,r30,6232
	ctx.r4.s64 = ctx.r30.s64 + 6232;
	// addi r3,r1,17360
	ctx.r3.s64 = ctx.r1.s64 + 17360;
	// bl 0x82060190
	ctx.lr = 0x82196C80;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17384
	ctx.r11.s64 = ctx.r1.s64 + 17384;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196C8C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196c8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196C8C;
	// addi r3,r1,17416
	ctx.r3.s64 = ctx.r1.s64 + 17416;
	// bl 0x82060f40
	ctx.lr = 0x82196C9C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6248
	ctx.r4.s64 = ctx.r30.s64 + 6248;
	// addi r3,r1,17440
	ctx.r3.s64 = ctx.r1.s64 + 17440;
	// bl 0x82060190
	ctx.lr = 0x82196CA8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17464
	ctx.r11.s64 = ctx.r1.s64 + 17464;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196CB4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196cb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196CB4;
	// addi r3,r1,17496
	ctx.r3.s64 = ctx.r1.s64 + 17496;
	// bl 0x82060f40
	ctx.lr = 0x82196CC4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6260
	ctx.r4.s64 = ctx.r30.s64 + 6260;
	// addi r3,r1,17520
	ctx.r3.s64 = ctx.r1.s64 + 17520;
	// bl 0x82060190
	ctx.lr = 0x82196CD0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17544
	ctx.r11.s64 = ctx.r1.s64 + 17544;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196CDC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196cdc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196CDC;
	// addi r3,r1,17576
	ctx.r3.s64 = ctx.r1.s64 + 17576;
	// bl 0x82060f40
	ctx.lr = 0x82196CEC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6276
	ctx.r4.s64 = ctx.r30.s64 + 6276;
	// addi r3,r1,4640
	ctx.r3.s64 = ctx.r1.s64 + 4640;
	// bl 0x82060190
	ctx.lr = 0x82196CF8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4664
	ctx.r11.s64 = ctx.r1.s64 + 4664;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196D04:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196d04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196D04;
	// addi r3,r1,4696
	ctx.r3.s64 = ctx.r1.s64 + 4696;
	// bl 0x82060f40
	ctx.lr = 0x82196D14;
	sub_82060F40(ctx, base);
	// addi r4,r30,6284
	ctx.r4.s64 = ctx.r30.s64 + 6284;
	// addi r3,r1,4720
	ctx.r3.s64 = ctx.r1.s64 + 4720;
	// bl 0x82060190
	ctx.lr = 0x82196D20;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4744
	ctx.r11.s64 = ctx.r1.s64 + 4744;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196D2C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196d2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196D2C;
	// addi r3,r1,4776
	ctx.r3.s64 = ctx.r1.s64 + 4776;
	// bl 0x82060f40
	ctx.lr = 0x82196D3C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6292
	ctx.r4.s64 = ctx.r30.s64 + 6292;
	// addi r3,r1,16560
	ctx.r3.s64 = ctx.r1.s64 + 16560;
	// bl 0x82060190
	ctx.lr = 0x82196D48;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16584
	ctx.r11.s64 = ctx.r1.s64 + 16584;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196D54:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196d54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196D54;
	// addi r3,r1,16616
	ctx.r3.s64 = ctx.r1.s64 + 16616;
	// bl 0x82060f40
	ctx.lr = 0x82196D64;
	sub_82060F40(ctx, base);
	// addi r4,r30,6308
	ctx.r4.s64 = ctx.r30.s64 + 6308;
	// addi r3,r1,16640
	ctx.r3.s64 = ctx.r1.s64 + 16640;
	// bl 0x82060190
	ctx.lr = 0x82196D70;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16664
	ctx.r11.s64 = ctx.r1.s64 + 16664;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196D7C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196d7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196D7C;
	// addi r3,r1,16696
	ctx.r3.s64 = ctx.r1.s64 + 16696;
	// bl 0x82060f40
	ctx.lr = 0x82196D8C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6312
	ctx.r4.s64 = ctx.r30.s64 + 6312;
	// addi r3,r1,16720
	ctx.r3.s64 = ctx.r1.s64 + 16720;
	// bl 0x82060190
	ctx.lr = 0x82196D98;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16744
	ctx.r11.s64 = ctx.r1.s64 + 16744;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196DA4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196da4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196DA4;
	// addi r3,r1,16776
	ctx.r3.s64 = ctx.r1.s64 + 16776;
	// bl 0x82060f40
	ctx.lr = 0x82196DB4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6316
	ctx.r4.s64 = ctx.r30.s64 + 6316;
	// addi r3,r1,16800
	ctx.r3.s64 = ctx.r1.s64 + 16800;
	// bl 0x82060190
	ctx.lr = 0x82196DC0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16824
	ctx.r11.s64 = ctx.r1.s64 + 16824;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196DCC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196dcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196DCC;
	// addi r3,r1,16856
	ctx.r3.s64 = ctx.r1.s64 + 16856;
	// bl 0x82060f40
	ctx.lr = 0x82196DDC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6320
	ctx.r4.s64 = ctx.r30.s64 + 6320;
	// addi r3,r1,16880
	ctx.r3.s64 = ctx.r1.s64 + 16880;
	// bl 0x82060190
	ctx.lr = 0x82196DE8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16904
	ctx.r11.s64 = ctx.r1.s64 + 16904;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196DF4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196df4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196DF4;
	// addi r3,r1,16936
	ctx.r3.s64 = ctx.r1.s64 + 16936;
	// bl 0x82060f40
	ctx.lr = 0x82196E04;
	sub_82060F40(ctx, base);
	// addi r4,r30,6324
	ctx.r4.s64 = ctx.r30.s64 + 6324;
	// addi r3,r1,16960
	ctx.r3.s64 = ctx.r1.s64 + 16960;
	// bl 0x82060190
	ctx.lr = 0x82196E10;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,16984
	ctx.r11.s64 = ctx.r1.s64 + 16984;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196E1C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196e1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196E1C;
	// addi r3,r1,17016
	ctx.r3.s64 = ctx.r1.s64 + 17016;
	// bl 0x82060f40
	ctx.lr = 0x82196E2C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6328
	ctx.r4.s64 = ctx.r30.s64 + 6328;
	// addi r3,r1,17040
	ctx.r3.s64 = ctx.r1.s64 + 17040;
	// bl 0x82060190
	ctx.lr = 0x82196E38;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17064
	ctx.r11.s64 = ctx.r1.s64 + 17064;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196E44:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196e44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196E44;
	// addi r3,r1,17096
	ctx.r3.s64 = ctx.r1.s64 + 17096;
	// bl 0x82060f40
	ctx.lr = 0x82196E54;
	sub_82060F40(ctx, base);
	// addi r4,r30,6332
	ctx.r4.s64 = ctx.r30.s64 + 6332;
	// addi r3,r1,17120
	ctx.r3.s64 = ctx.r1.s64 + 17120;
	// bl 0x82060190
	ctx.lr = 0x82196E60;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17144
	ctx.r11.s64 = ctx.r1.s64 + 17144;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196E6C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196e6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196E6C;
	// addi r3,r1,17176
	ctx.r3.s64 = ctx.r1.s64 + 17176;
	// bl 0x82060f40
	ctx.lr = 0x82196E7C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6336
	ctx.r4.s64 = ctx.r30.s64 + 6336;
	// addi r3,r1,17200
	ctx.r3.s64 = ctx.r1.s64 + 17200;
	// bl 0x82060190
	ctx.lr = 0x82196E88;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17224
	ctx.r11.s64 = ctx.r1.s64 + 17224;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196E94:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196e94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196E94;
	// addi r3,r1,17256
	ctx.r3.s64 = ctx.r1.s64 + 17256;
	// bl 0x82060f40
	ctx.lr = 0x82196EA4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6340
	ctx.r4.s64 = ctx.r30.s64 + 6340;
	// addi r3,r1,17600
	ctx.r3.s64 = ctx.r1.s64 + 17600;
	// bl 0x82060190
	ctx.lr = 0x82196EB0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17624
	ctx.r11.s64 = ctx.r1.s64 + 17624;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196EBC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196ebc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196EBC;
	// addi r3,r1,17656
	ctx.r3.s64 = ctx.r1.s64 + 17656;
	// bl 0x82060f40
	ctx.lr = 0x82196ECC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6356
	ctx.r4.s64 = ctx.r30.s64 + 6356;
	// addi r3,r1,17680
	ctx.r3.s64 = ctx.r1.s64 + 17680;
	// bl 0x82060190
	ctx.lr = 0x82196ED8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17704
	ctx.r11.s64 = ctx.r1.s64 + 17704;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196EE4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196ee4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196EE4;
	// addi r3,r1,17736
	ctx.r3.s64 = ctx.r1.s64 + 17736;
	// bl 0x82060f40
	ctx.lr = 0x82196EF4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6360
	ctx.r4.s64 = ctx.r30.s64 + 6360;
	// addi r3,r1,17760
	ctx.r3.s64 = ctx.r1.s64 + 17760;
	// bl 0x82060190
	ctx.lr = 0x82196F00;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17784
	ctx.r11.s64 = ctx.r1.s64 + 17784;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196F0C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196f0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196F0C;
	// addi r3,r1,17816
	ctx.r3.s64 = ctx.r1.s64 + 17816;
	// bl 0x82060f40
	ctx.lr = 0x82196F1C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6364
	ctx.r4.s64 = ctx.r30.s64 + 6364;
	// addi r3,r1,17840
	ctx.r3.s64 = ctx.r1.s64 + 17840;
	// bl 0x82060190
	ctx.lr = 0x82196F28;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17864
	ctx.r11.s64 = ctx.r1.s64 + 17864;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196F34:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196f34
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196F34;
	// addi r3,r1,17896
	ctx.r3.s64 = ctx.r1.s64 + 17896;
	// bl 0x82060f40
	ctx.lr = 0x82196F44;
	sub_82060F40(ctx, base);
	// addi r4,r30,6368
	ctx.r4.s64 = ctx.r30.s64 + 6368;
	// addi r3,r1,17920
	ctx.r3.s64 = ctx.r1.s64 + 17920;
	// bl 0x82060190
	ctx.lr = 0x82196F50;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,17944
	ctx.r11.s64 = ctx.r1.s64 + 17944;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196F5C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196f5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196F5C;
	// addi r3,r1,17976
	ctx.r3.s64 = ctx.r1.s64 + 17976;
	// bl 0x82060f40
	ctx.lr = 0x82196F6C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6372
	ctx.r4.s64 = ctx.r30.s64 + 6372;
	// addi r3,r1,18000
	ctx.r3.s64 = ctx.r1.s64 + 18000;
	// bl 0x82060190
	ctx.lr = 0x82196F78;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18024
	ctx.r11.s64 = ctx.r1.s64 + 18024;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196F84:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196f84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196F84;
	// addi r3,r1,18056
	ctx.r3.s64 = ctx.r1.s64 + 18056;
	// bl 0x82060f40
	ctx.lr = 0x82196F94;
	sub_82060F40(ctx, base);
	// addi r4,r30,6376
	ctx.r4.s64 = ctx.r30.s64 + 6376;
	// addi r3,r1,18080
	ctx.r3.s64 = ctx.r1.s64 + 18080;
	// bl 0x82060190
	ctx.lr = 0x82196FA0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18104
	ctx.r11.s64 = ctx.r1.s64 + 18104;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196FAC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196fac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196FAC;
	// addi r3,r1,18136
	ctx.r3.s64 = ctx.r1.s64 + 18136;
	// bl 0x82060f40
	ctx.lr = 0x82196FBC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6380
	ctx.r4.s64 = ctx.r30.s64 + 6380;
	// addi r3,r1,18160
	ctx.r3.s64 = ctx.r1.s64 + 18160;
	// bl 0x82060190
	ctx.lr = 0x82196FC8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18184
	ctx.r11.s64 = ctx.r1.s64 + 18184;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196FD4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196fd4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196FD4;
	// addi r3,r1,18216
	ctx.r3.s64 = ctx.r1.s64 + 18216;
	// bl 0x82060f40
	ctx.lr = 0x82196FE4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6384
	ctx.r4.s64 = ctx.r30.s64 + 6384;
	// addi r3,r1,18240
	ctx.r3.s64 = ctx.r1.s64 + 18240;
	// bl 0x82060190
	ctx.lr = 0x82196FF0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18264
	ctx.r11.s64 = ctx.r1.s64 + 18264;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82196FFC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82196ffc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82196FFC;
	// addi r3,r1,18296
	ctx.r3.s64 = ctx.r1.s64 + 18296;
	// bl 0x82060f40
	ctx.lr = 0x8219700C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6396
	ctx.r4.s64 = ctx.r30.s64 + 6396;
	// addi r3,r1,19120
	ctx.r3.s64 = ctx.r1.s64 + 19120;
	// bl 0x82060190
	ctx.lr = 0x82197018;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19144
	ctx.r11.s64 = ctx.r1.s64 + 19144;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197024:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197024
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197024;
	// addi r3,r1,19176
	ctx.r3.s64 = ctx.r1.s64 + 19176;
	// bl 0x82060f40
	ctx.lr = 0x82197034;
	sub_82060F40(ctx, base);
	// addi r4,r30,6400
	ctx.r4.s64 = ctx.r30.s64 + 6400;
	// addi r3,r1,19200
	ctx.r3.s64 = ctx.r1.s64 + 19200;
	// bl 0x82060190
	ctx.lr = 0x82197040;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19224
	ctx.r11.s64 = ctx.r1.s64 + 19224;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219704C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219704c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219704C;
	// addi r3,r1,19256
	ctx.r3.s64 = ctx.r1.s64 + 19256;
	// bl 0x82060f40
	ctx.lr = 0x8219705C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6404
	ctx.r4.s64 = ctx.r30.s64 + 6404;
	// addi r3,r1,19280
	ctx.r3.s64 = ctx.r1.s64 + 19280;
	// bl 0x82060190
	ctx.lr = 0x82197068;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19304
	ctx.r11.s64 = ctx.r1.s64 + 19304;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197074:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197074
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197074;
	// addi r3,r1,19336
	ctx.r3.s64 = ctx.r1.s64 + 19336;
	// bl 0x82060f40
	ctx.lr = 0x82197084;
	sub_82060F40(ctx, base);
	// addi r4,r30,6408
	ctx.r4.s64 = ctx.r30.s64 + 6408;
	// addi r3,r1,19360
	ctx.r3.s64 = ctx.r1.s64 + 19360;
	// bl 0x82060190
	ctx.lr = 0x82197090;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19384
	ctx.r11.s64 = ctx.r1.s64 + 19384;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219709C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219709c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219709C;
	// addi r3,r1,19416
	ctx.r3.s64 = ctx.r1.s64 + 19416;
	// bl 0x82060f40
	ctx.lr = 0x821970AC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6412
	ctx.r4.s64 = ctx.r30.s64 + 6412;
	// addi r3,r1,19440
	ctx.r3.s64 = ctx.r1.s64 + 19440;
	// bl 0x82060190
	ctx.lr = 0x821970B8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19464
	ctx.r11.s64 = ctx.r1.s64 + 19464;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821970C4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821970c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821970C4;
	// addi r3,r1,19496
	ctx.r3.s64 = ctx.r1.s64 + 19496;
	// bl 0x82060f40
	ctx.lr = 0x821970D4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6416
	ctx.r4.s64 = ctx.r30.s64 + 6416;
	// addi r3,r1,19520
	ctx.r3.s64 = ctx.r1.s64 + 19520;
	// bl 0x82060190
	ctx.lr = 0x821970E0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19544
	ctx.r11.s64 = ctx.r1.s64 + 19544;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821970EC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821970ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821970EC;
	// addi r3,r1,19576
	ctx.r3.s64 = ctx.r1.s64 + 19576;
	// bl 0x82060f40
	ctx.lr = 0x821970FC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6420
	ctx.r4.s64 = ctx.r30.s64 + 6420;
	// addi r3,r1,19600
	ctx.r3.s64 = ctx.r1.s64 + 19600;
	// bl 0x82060190
	ctx.lr = 0x82197108;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19624
	ctx.r11.s64 = ctx.r1.s64 + 19624;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197114:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197114
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197114;
	// addi r3,r1,19656
	ctx.r3.s64 = ctx.r1.s64 + 19656;
	// bl 0x82060f40
	ctx.lr = 0x82197124;
	sub_82060F40(ctx, base);
	// addi r4,r30,6424
	ctx.r4.s64 = ctx.r30.s64 + 6424;
	// addi r3,r1,19680
	ctx.r3.s64 = ctx.r1.s64 + 19680;
	// bl 0x82060190
	ctx.lr = 0x82197130;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19704
	ctx.r11.s64 = ctx.r1.s64 + 19704;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219713C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219713c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219713C;
	// addi r3,r1,19736
	ctx.r3.s64 = ctx.r1.s64 + 19736;
	// bl 0x82060f40
	ctx.lr = 0x8219714C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6428
	ctx.r4.s64 = ctx.r30.s64 + 6428;
	// addi r3,r1,19760
	ctx.r3.s64 = ctx.r1.s64 + 19760;
	// bl 0x82060190
	ctx.lr = 0x82197158;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19784
	ctx.r11.s64 = ctx.r1.s64 + 19784;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197164:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197164
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197164;
	// addi r3,r1,19816
	ctx.r3.s64 = ctx.r1.s64 + 19816;
	// bl 0x82060f40
	ctx.lr = 0x82197174;
	sub_82060F40(ctx, base);
	// addi r4,r30,6432
	ctx.r4.s64 = ctx.r30.s64 + 6432;
	// addi r3,r1,19840
	ctx.r3.s64 = ctx.r1.s64 + 19840;
	// bl 0x82060190
	ctx.lr = 0x82197180;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19864
	ctx.r11.s64 = ctx.r1.s64 + 19864;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219718C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219718c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219718C;
	// addi r3,r1,19896
	ctx.r3.s64 = ctx.r1.s64 + 19896;
	// bl 0x82060f40
	ctx.lr = 0x8219719C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6444
	ctx.r4.s64 = ctx.r30.s64 + 6444;
	// addi r3,r1,18320
	ctx.r3.s64 = ctx.r1.s64 + 18320;
	// bl 0x82060190
	ctx.lr = 0x821971A8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18344
	ctx.r11.s64 = ctx.r1.s64 + 18344;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821971B4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821971b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821971B4;
	// addi r3,r1,18376
	ctx.r3.s64 = ctx.r1.s64 + 18376;
	// bl 0x82060f40
	ctx.lr = 0x821971C4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6460
	ctx.r4.s64 = ctx.r30.s64 + 6460;
	// addi r3,r1,18400
	ctx.r3.s64 = ctx.r1.s64 + 18400;
	// bl 0x82060190
	ctx.lr = 0x821971D0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18424
	ctx.r11.s64 = ctx.r1.s64 + 18424;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821971DC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821971dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821971DC;
	// addi r3,r1,18456
	ctx.r3.s64 = ctx.r1.s64 + 18456;
	// bl 0x82060f40
	ctx.lr = 0x821971EC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6464
	ctx.r4.s64 = ctx.r30.s64 + 6464;
	// addi r3,r1,18480
	ctx.r3.s64 = ctx.r1.s64 + 18480;
	// bl 0x82060190
	ctx.lr = 0x821971F8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18504
	ctx.r11.s64 = ctx.r1.s64 + 18504;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197204:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197204
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197204;
	// addi r3,r1,18536
	ctx.r3.s64 = ctx.r1.s64 + 18536;
	// bl 0x82060f40
	ctx.lr = 0x82197214;
	sub_82060F40(ctx, base);
	// addi r4,r30,6468
	ctx.r4.s64 = ctx.r30.s64 + 6468;
	// addi r3,r1,18560
	ctx.r3.s64 = ctx.r1.s64 + 18560;
	// bl 0x82060190
	ctx.lr = 0x82197220;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18584
	ctx.r11.s64 = ctx.r1.s64 + 18584;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219722C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219722c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219722C;
	// addi r3,r1,18616
	ctx.r3.s64 = ctx.r1.s64 + 18616;
	// bl 0x82060f40
	ctx.lr = 0x8219723C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6472
	ctx.r4.s64 = ctx.r30.s64 + 6472;
	// addi r3,r1,18640
	ctx.r3.s64 = ctx.r1.s64 + 18640;
	// bl 0x82060190
	ctx.lr = 0x82197248;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18664
	ctx.r11.s64 = ctx.r1.s64 + 18664;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197254:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197254
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197254;
	// addi r3,r1,18696
	ctx.r3.s64 = ctx.r1.s64 + 18696;
	// bl 0x82060f40
	ctx.lr = 0x82197264;
	sub_82060F40(ctx, base);
	// addi r4,r30,6476
	ctx.r4.s64 = ctx.r30.s64 + 6476;
	// addi r3,r1,18720
	ctx.r3.s64 = ctx.r1.s64 + 18720;
	// bl 0x82060190
	ctx.lr = 0x82197270;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18744
	ctx.r11.s64 = ctx.r1.s64 + 18744;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219727C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219727c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219727C;
	// addi r3,r1,18776
	ctx.r3.s64 = ctx.r1.s64 + 18776;
	// bl 0x82060f40
	ctx.lr = 0x8219728C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6480
	ctx.r4.s64 = ctx.r30.s64 + 6480;
	// addi r3,r1,18800
	ctx.r3.s64 = ctx.r1.s64 + 18800;
	// bl 0x82060190
	ctx.lr = 0x82197298;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18824
	ctx.r11.s64 = ctx.r1.s64 + 18824;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821972A4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821972a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821972A4;
	// addi r3,r1,18856
	ctx.r3.s64 = ctx.r1.s64 + 18856;
	// bl 0x82060f40
	ctx.lr = 0x821972B4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6484
	ctx.r4.s64 = ctx.r30.s64 + 6484;
	// addi r3,r1,18880
	ctx.r3.s64 = ctx.r1.s64 + 18880;
	// bl 0x82060190
	ctx.lr = 0x821972C0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18904
	ctx.r11.s64 = ctx.r1.s64 + 18904;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821972CC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821972cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821972CC;
	// addi r3,r1,18936
	ctx.r3.s64 = ctx.r1.s64 + 18936;
	// bl 0x82060f40
	ctx.lr = 0x821972DC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6488
	ctx.r4.s64 = ctx.r30.s64 + 6488;
	// addi r3,r1,18960
	ctx.r3.s64 = ctx.r1.s64 + 18960;
	// bl 0x82060190
	ctx.lr = 0x821972E8;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,18984
	ctx.r11.s64 = ctx.r1.s64 + 18984;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821972F4:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821972f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821972F4;
	// addi r3,r1,19016
	ctx.r3.s64 = ctx.r1.s64 + 19016;
	// bl 0x82060f40
	ctx.lr = 0x82197304;
	sub_82060F40(ctx, base);
	// addi r4,r30,6492
	ctx.r4.s64 = ctx.r30.s64 + 6492;
	// addi r3,r1,19040
	ctx.r3.s64 = ctx.r1.s64 + 19040;
	// bl 0x82060190
	ctx.lr = 0x82197310;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,19064
	ctx.r11.s64 = ctx.r1.s64 + 19064;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219731C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219731c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219731C;
	// addi r3,r1,19096
	ctx.r3.s64 = ctx.r1.s64 + 19096;
	// bl 0x82060f40
	ctx.lr = 0x8219732C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6496
	ctx.r4.s64 = ctx.r30.s64 + 6496;
	// addi r3,r1,4800
	ctx.r3.s64 = ctx.r1.s64 + 4800;
	// bl 0x82060190
	ctx.lr = 0x82197338;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4824
	ctx.r11.s64 = ctx.r1.s64 + 4824;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197344:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197344
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197344;
	// addi r3,r1,4856
	ctx.r3.s64 = ctx.r1.s64 + 4856;
	// bl 0x82060f40
	ctx.lr = 0x82197354;
	sub_82060F40(ctx, base);
	// addi r4,r30,6500
	ctx.r4.s64 = ctx.r30.s64 + 6500;
	// addi r3,r1,4880
	ctx.r3.s64 = ctx.r1.s64 + 4880;
	// bl 0x82060190
	ctx.lr = 0x82197360;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4904
	ctx.r11.s64 = ctx.r1.s64 + 4904;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8219736C:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8219736c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8219736C;
	// addi r3,r1,4936
	ctx.r3.s64 = ctx.r1.s64 + 4936;
	// bl 0x82060f40
	ctx.lr = 0x8219737C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6504
	ctx.r4.s64 = ctx.r30.s64 + 6504;
	// addi r3,r1,4480
	ctx.r3.s64 = ctx.r1.s64 + 4480;
	// bl 0x82060190
	ctx.lr = 0x82197388;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4504
	ctx.r11.s64 = ctx.r1.s64 + 4504;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82197394:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82197394
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82197394;
	// addi r3,r1,4536
	ctx.r3.s64 = ctx.r1.s64 + 4536;
	// bl 0x82060f40
	ctx.lr = 0x821973A4;
	sub_82060F40(ctx, base);
	// addi r4,r30,6512
	ctx.r4.s64 = ctx.r30.s64 + 6512;
	// addi r3,r1,4560
	ctx.r3.s64 = ctx.r1.s64 + 4560;
	// bl 0x82060190
	ctx.lr = 0x821973B0;
	sub_82060190(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,4584
	ctx.r11.s64 = ctx.r1.s64 + 4584;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821973BC:
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821973bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821973BC;
	// addi r3,r1,4616
	ctx.r3.s64 = ctx.r1.s64 + 4616;
	// bl 0x82060f40
	ctx.lr = 0x821973CC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6520
	ctx.r4.s64 = ctx.r30.s64 + 6520;
	// addi r3,r1,1920
	ctx.r3.s64 = ctx.r1.s64 + 1920;
	// bl 0x82060190
	ctx.lr = 0x821973D8;
	sub_82060190(ctx, base);
	// li r29,8
	ctx.r29.s64 = 8;
	// li r28,3
	ctx.r28.s64 = 3;
	// stw r31,1948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1948, ctx.r31.u32);
	// stw r29,1952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1952, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,1956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1956, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,1960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1960, ctx.r31.u32);
	// addi r3,r1,1976
	ctx.r3.s64 = ctx.r1.s64 + 1976;
	// stw r31,1964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1964, ctx.r31.u32);
	// stw r31,1968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1968, ctx.r31.u32);
	// stw r31,1972(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1972, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x8219740C;
	sub_821B7900(ctx, base);
	// addi r4,r30,6528
	ctx.r4.s64 = ctx.r30.s64 + 6528;
	// addi r3,r1,2000
	ctx.r3.s64 = ctx.r1.s64 + 2000;
	// bl 0x82060190
	ctx.lr = 0x82197418;
	sub_82060190(ctx, base);
	// li r19,1
	ctx.r19.s64 = 1;
	// stw r29,2032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2032, ctx.r29.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r19,2028(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2028, ctx.r19.u32);
	// addi r4,r1,4240
	ctx.r4.s64 = ctx.r1.s64 + 4240;
	// stw r28,2036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2036, ctx.r28.u32);
	// addi r3,r1,2056
	ctx.r3.s64 = ctx.r1.s64 + 2056;
	// stw r31,2040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2040, ctx.r31.u32);
	// stw r31,2044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2044, ctx.r31.u32);
	// stw r31,2048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2048, ctx.r31.u32);
	// stw r31,2052(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2052, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197448;
	sub_821B7900(ctx, base);
	// addi r4,r30,6536
	ctx.r4.s64 = ctx.r30.s64 + 6536;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x82060190
	ctx.lr = 0x82197454;
	sub_82060190(ctx, base);
	// li r27,2
	ctx.r27.s64 = 2;
	// stw r29,2112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2112, ctx.r29.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r27,2108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2108, ctx.r27.u32);
	// addi r4,r1,17280
	ctx.r4.s64 = ctx.r1.s64 + 17280;
	// stw r28,2116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2116, ctx.r28.u32);
	// addi r3,r1,2136
	ctx.r3.s64 = ctx.r1.s64 + 2136;
	// stw r31,2120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2120, ctx.r31.u32);
	// stw r31,2124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2124, ctx.r31.u32);
	// stw r31,2128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2128, ctx.r31.u32);
	// stw r31,2132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2132, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197484;
	sub_821B7900(ctx, base);
	// addi r4,r30,6548
	ctx.r4.s64 = ctx.r30.s64 + 6548;
	// addi r3,r1,2160
	ctx.r3.s64 = ctx.r1.s64 + 2160;
	// bl 0x82060190
	ctx.lr = 0x82197490;
	sub_82060190(ctx, base);
	// stw r28,2188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2188, ctx.r28.u32);
	// stw r29,2192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2192, ctx.r29.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r28,2196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2196, ctx.r28.u32);
	// addi r4,r1,16560
	ctx.r4.s64 = ctx.r1.s64 + 16560;
	// stw r31,2200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2200, ctx.r31.u32);
	// addi r3,r1,2216
	ctx.r3.s64 = ctx.r1.s64 + 2216;
	// stw r31,2204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2204, ctx.r31.u32);
	// stw r31,2208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2208, ctx.r31.u32);
	// stw r31,2212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2212, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821974BC;
	sub_821B7900(ctx, base);
	// addi r4,r30,6560
	ctx.r4.s64 = ctx.r30.s64 + 6560;
	// addi r3,r1,2240
	ctx.r3.s64 = ctx.r1.s64 + 2240;
	// bl 0x82060190
	ctx.lr = 0x821974C8;
	sub_82060190(ctx, base);
	// li r20,4
	ctx.r20.s64 = 4;
	// stw r29,2272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2272, ctx.r29.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r20,2268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2268, ctx.r20.u32);
	// addi r4,r1,17600
	ctx.r4.s64 = ctx.r1.s64 + 17600;
	// stw r28,2276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2276, ctx.r28.u32);
	// addi r3,r1,2296
	ctx.r3.s64 = ctx.r1.s64 + 2296;
	// stw r31,2280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2280, ctx.r31.u32);
	// stw r31,2284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2284, ctx.r31.u32);
	// stw r31,2288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2288, ctx.r31.u32);
	// stw r31,2292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2292, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821974F8;
	sub_821B7900(ctx, base);
	// addi r4,r30,6572
	ctx.r4.s64 = ctx.r30.s64 + 6572;
	// addi r3,r1,2320
	ctx.r3.s64 = ctx.r1.s64 + 2320;
	// bl 0x82060190
	ctx.lr = 0x82197504;
	sub_82060190(ctx, base);
	// li r21,5
	ctx.r21.s64 = 5;
	// stw r29,2352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2352, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r21,2348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2348, ctx.r21.u32);
	// addi r4,r1,19120
	ctx.r4.s64 = ctx.r1.s64 + 19120;
	// stw r28,2356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2356, ctx.r28.u32);
	// addi r3,r1,2376
	ctx.r3.s64 = ctx.r1.s64 + 2376;
	// stw r27,2360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2360, ctx.r27.u32);
	// stw r27,2364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2364, ctx.r27.u32);
	// stw r31,2368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2368, ctx.r31.u32);
	// stw r31,2372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2372, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197534;
	sub_821B7900(ctx, base);
	// addi r4,r30,6588
	ctx.r4.s64 = ctx.r30.s64 + 6588;
	// addi r3,r1,2400
	ctx.r3.s64 = ctx.r1.s64 + 2400;
	// bl 0x82060190
	ctx.lr = 0x82197540;
	sub_82060190(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// li r22,6
	ctx.r22.s64 = 6;
	// stw r29,2432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2432, ctx.r29.u32);
	// ori r14,r11,34463
	ctx.r14.u64 = ctx.r11.u64 | 34463;
	// stw r27,2436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2436, ctx.r27.u32);
	// stw r22,2428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2428, ctx.r22.u32);
	// addi r3,r1,2456
	ctx.r3.s64 = ctx.r1.s64 + 2456;
	// stw r31,2440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2440, ctx.r31.u32);
	// stw r31,2444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2444, ctx.r31.u32);
	// stw r31,2448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2448, ctx.r31.u32);
	// stw r14,2452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2452, ctx.r14.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197570;
	sub_82060F40(ctx, base);
	// addi r4,r30,6608
	ctx.r4.s64 = ctx.r30.s64 + 6608;
	// addi r3,r1,2480
	ctx.r3.s64 = ctx.r1.s64 + 2480;
	// bl 0x82060190
	ctx.lr = 0x8219757C;
	sub_82060190(ctx, base);
	// li r23,9
	ctx.r23.s64 = 9;
	// li r15,9999
	ctx.r15.s64 = 9999;
	// stw r29,2512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2512, ctx.r29.u32);
	// stw r23,2508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2508, ctx.r23.u32);
	// addi r3,r1,2536
	ctx.r3.s64 = ctx.r1.s64 + 2536;
	// stw r27,2516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2516, ctx.r27.u32);
	// stw r31,2520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2520, ctx.r31.u32);
	// stw r31,2524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2524, ctx.r31.u32);
	// stw r31,2528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2528, ctx.r31.u32);
	// stw r15,2532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2532, ctx.r15.u32);
	// bl 0x82060f40
	ctx.lr = 0x821975A8;
	sub_82060F40(ctx, base);
	// addi r4,r30,6624
	ctx.r4.s64 = ctx.r30.s64 + 6624;
	// addi r3,r1,2560
	ctx.r3.s64 = ctx.r1.s64 + 2560;
	// bl 0x82060190
	ctx.lr = 0x821975B4;
	sub_82060190(ctx, base);
	// li r24,14
	ctx.r24.s64 = 14;
	// stw r29,2592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2592, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r24,2588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2588, ctx.r24.u32);
	// addi r4,r1,18320
	ctx.r4.s64 = ctx.r1.s64 + 18320;
	// stw r28,2596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2596, ctx.r28.u32);
	// addi r3,r1,2616
	ctx.r3.s64 = ctx.r1.s64 + 2616;
	// stw r31,2600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2600, ctx.r31.u32);
	// stw r31,2604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2604, ctx.r31.u32);
	// stw r31,2608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2608, ctx.r31.u32);
	// stw r31,2612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2612, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821975E4;
	sub_821B7900(ctx, base);
	// addi r4,r30,6640
	ctx.r4.s64 = ctx.r30.s64 + 6640;
	// addi r3,r1,2640
	ctx.r3.s64 = ctx.r1.s64 + 2640;
	// bl 0x82060190
	ctx.lr = 0x821975F0;
	sub_82060190(ctx, base);
	// li r17,-199
	ctx.r17.s64 = -199;
	// li r18,20
	ctx.r18.s64 = 20;
	// stw r31,2672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2672, ctx.r31.u32);
	// stw r17,2668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2668, ctx.r17.u32);
	// addi r3,r1,2696
	ctx.r3.s64 = ctx.r1.s64 + 2696;
	// stw r31,2676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2676, ctx.r31.u32);
	// stw r18,2680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2680, ctx.r18.u32);
	// stw r31,2684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2684, ctx.r31.u32);
	// stw r31,2688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2688, ctx.r31.u32);
	// stw r31,2692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2692, ctx.r31.u32);
	// bl 0x82060f40
	ctx.lr = 0x8219761C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6648
	ctx.r4.s64 = ctx.r30.s64 + 6648;
	// addi r3,r1,2720
	ctx.r3.s64 = ctx.r1.s64 + 2720;
	// bl 0x82060190
	ctx.lr = 0x82197628;
	sub_82060190(ctx, base);
	// li r25,16
	ctx.r25.s64 = 16;
	// stw r29,2752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2752, ctx.r29.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r25,2748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2748, ctx.r25.u32);
	// stw r28,2756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2756, ctx.r28.u32);
	// stw r31,2760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2760, ctx.r31.u32);
	// stw r31,2764(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2764, ctx.r31.u32);
	// stw r31,2768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2768, ctx.r31.u32);
	// stw r31,2772(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2772, ctx.r31.u32);
	// addi r4,r1,4480
	ctx.r4.s64 = ctx.r1.s64 + 4480;
	// addi r3,r1,2776
	ctx.r3.s64 = ctx.r1.s64 + 2776;
	// bl 0x821b7900
	ctx.lr = 0x82197658;
	sub_821B7900(ctx, base);
	// addi r4,r30,6664
	ctx.r4.s64 = ctx.r30.s64 + 6664;
	// addi r3,r1,2800
	ctx.r3.s64 = ctx.r1.s64 + 2800;
	// bl 0x82060190
	ctx.lr = 0x82197664;
	sub_82060190(ctx, base);
	// stw r17,2828(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2828, ctx.r17.u32);
	// stw r31,2832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2832, ctx.r31.u32);
	// addi r3,r1,2856
	ctx.r3.s64 = ctx.r1.s64 + 2856;
	// stw r31,2836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2836, ctx.r31.u32);
	// stw r18,2840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2840, ctx.r18.u32);
	// stw r31,2844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2844, ctx.r31.u32);
	// stw r31,2848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2848, ctx.r31.u32);
	// stw r31,2852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2852, ctx.r31.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197688;
	sub_82060F40(ctx, base);
	// addi r4,r30,6672
	ctx.r4.s64 = ctx.r30.s64 + 6672;
	// addi r3,r1,2880
	ctx.r3.s64 = ctx.r1.s64 + 2880;
	// bl 0x82060190
	ctx.lr = 0x82197694;
	sub_82060190(ctx, base);
	// addi r10,r1,2920
	ctx.r10.s64 = ctx.r1.s64 + 2920;
	// li r26,17
	ctx.r26.s64 = 17;
	// stw r31,2912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2912, ctx.r31.u32);
	// stw r31,2916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2916, ctx.r31.u32);
	// addi r3,r1,2936
	ctx.r3.s64 = ctx.r1.s64 + 2936;
	// stw r26,2908(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2908, ctx.r26.u32);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r31.u64);
	// bl 0x82060f40
	ctx.lr = 0x821976B8;
	sub_82060F40(ctx, base);
	// addi r4,r30,6680
	ctx.r4.s64 = ctx.r30.s64 + 6680;
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// bl 0x82060190
	ctx.lr = 0x821976C4;
	sub_82060190(ctx, base);
	// stw r31,908(r1)
	PPC_STORE_U32(ctx.r1.u32 + 908, ctx.r31.u32);
	// stw r29,912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 912, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 916, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r31.u32);
	// addi r3,r1,936
	ctx.r3.s64 = ctx.r1.s64 + 936;
	// stw r31,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, ctx.r31.u32);
	// stw r31,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r31.u32);
	// stw r31,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821976F0;
	sub_821B7900(ctx, base);
	// addi r4,r30,6688
	ctx.r4.s64 = ctx.r30.s64 + 6688;
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// bl 0x82060190
	ctx.lr = 0x821976FC;
	sub_82060190(ctx, base);
	// stw r19,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r19.u32);
	// stw r29,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r29.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r28,996(r1)
	PPC_STORE_U32(ctx.r1.u32 + 996, ctx.r28.u32);
	// addi r4,r1,16320
	ctx.r4.s64 = ctx.r1.s64 + 16320;
	// stw r31,1000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1000, ctx.r31.u32);
	// addi r3,r1,1016
	ctx.r3.s64 = ctx.r1.s64 + 1016;
	// stw r31,1004(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1004, ctx.r31.u32);
	// stw r31,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, ctx.r31.u32);
	// stw r31,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197728;
	sub_821B7900(ctx, base);
	// addi r4,r30,6696
	ctx.r4.s64 = ctx.r30.s64 + 6696;
	// addi r3,r1,1040
	ctx.r3.s64 = ctx.r1.s64 + 1040;
	// bl 0x82060190
	ctx.lr = 0x82197734;
	sub_82060190(ctx, base);
	// stw r27,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r27.u32);
	// stw r29,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r29.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r28,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r28.u32);
	// addi r4,r1,4640
	ctx.r4.s64 = ctx.r1.s64 + 4640;
	// stw r31,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, ctx.r31.u32);
	// addi r3,r1,1096
	ctx.r3.s64 = ctx.r1.s64 + 1096;
	// stw r31,1084(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1084, ctx.r31.u32);
	// stw r31,1088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1088, ctx.r31.u32);
	// stw r31,1092(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1092, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197760;
	sub_821B7900(ctx, base);
	// addi r4,r30,6708
	ctx.r4.s64 = ctx.r30.s64 + 6708;
	// addi r3,r1,1120
	ctx.r3.s64 = ctx.r1.s64 + 1120;
	// bl 0x82060190
	ctx.lr = 0x8219776C;
	sub_82060190(ctx, base);
	// stw r28,1148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1148, ctx.r28.u32);
	// stw r29,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, ctx.r29.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r28,1156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1156, ctx.r28.u32);
	// stw r31,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r31.u32);
	// stw r31,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r31.u32);
	// stw r31,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r31.u32);
	// stw r31,1172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1172, ctx.r31.u32);
	// addi r4,r1,16560
	ctx.r4.s64 = ctx.r1.s64 + 16560;
	// addi r3,r1,1176
	ctx.r3.s64 = ctx.r1.s64 + 1176;
	// bl 0x821b7900
	ctx.lr = 0x82197798;
	sub_821B7900(ctx, base);
	// addi r4,r30,6720
	ctx.r4.s64 = ctx.r30.s64 + 6720;
	// addi r3,r1,1200
	ctx.r3.s64 = ctx.r1.s64 + 1200;
	// bl 0x82060190
	ctx.lr = 0x821977A4;
	sub_82060190(ctx, base);
	// stw r20,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r20.u32);
	// stw r29,1232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1232, ctx.r29.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r28,1236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1236, ctx.r28.u32);
	// addi r4,r1,17600
	ctx.r4.s64 = ctx.r1.s64 + 17600;
	// stw r31,1240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1240, ctx.r31.u32);
	// addi r3,r1,1256
	ctx.r3.s64 = ctx.r1.s64 + 1256;
	// stw r31,1244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1244, ctx.r31.u32);
	// stw r31,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, ctx.r31.u32);
	// stw r31,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821977D0;
	sub_821B7900(ctx, base);
	// addi r4,r30,6732
	ctx.r4.s64 = ctx.r30.s64 + 6732;
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// bl 0x82060190
	ctx.lr = 0x821977DC;
	sub_82060190(ctx, base);
	// stw r21,1308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1308, ctx.r21.u32);
	// stw r29,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,1316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1316, ctx.r28.u32);
	// addi r4,r1,19120
	ctx.r4.s64 = ctx.r1.s64 + 19120;
	// stw r27,1320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1320, ctx.r27.u32);
	// addi r3,r1,1336
	ctx.r3.s64 = ctx.r1.s64 + 1336;
	// stw r27,1324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1324, ctx.r27.u32);
	// stw r31,1328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1328, ctx.r31.u32);
	// stw r31,1332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1332, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197808;
	sub_821B7900(ctx, base);
	// addi r4,r30,6748
	ctx.r4.s64 = ctx.r30.s64 + 6748;
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// bl 0x82060190
	ctx.lr = 0x82197814;
	sub_82060190(ctx, base);
	// lis r9,15
	ctx.r9.s64 = 983040;
	// stw r22,1388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1388, ctx.r22.u32);
	// addi r3,r1,1416
	ctx.r3.s64 = ctx.r1.s64 + 1416;
	// ori r16,r9,16959
	ctx.r16.u64 = ctx.r9.u64 | 16959;
	// stw r29,1392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1392, ctx.r29.u32);
	// stw r27,1396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1396, ctx.r27.u32);
	// stw r31,1400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1400, ctx.r31.u32);
	// stw r31,1404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1404, ctx.r31.u32);
	// stw r31,1408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1408, ctx.r31.u32);
	// stw r16,1412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1412, ctx.r16.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197840;
	sub_82060F40(ctx, base);
	// addi r4,r30,6768
	ctx.r4.s64 = ctx.r30.s64 + 6768;
	// addi r3,r1,1440
	ctx.r3.s64 = ctx.r1.s64 + 1440;
	// bl 0x82060190
	ctx.lr = 0x8219784C;
	sub_82060190(ctx, base);
	// stw r23,1468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1468, ctx.r23.u32);
	// stw r29,1472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1472, ctx.r29.u32);
	// addi r3,r1,1496
	ctx.r3.s64 = ctx.r1.s64 + 1496;
	// stw r27,1476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1476, ctx.r27.u32);
	// stw r31,1480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1480, ctx.r31.u32);
	// stw r31,1484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1484, ctx.r31.u32);
	// stw r31,1488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1488, ctx.r31.u32);
	// stw r15,1492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1492, ctx.r15.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197870;
	sub_82060F40(ctx, base);
	// addi r4,r30,6784
	ctx.r4.s64 = ctx.r30.s64 + 6784;
	// addi r3,r1,1520
	ctx.r3.s64 = ctx.r1.s64 + 1520;
	// bl 0x82060190
	ctx.lr = 0x8219787C;
	sub_82060190(ctx, base);
	// stw r24,1548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1548, ctx.r24.u32);
	// stw r29,1552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1552, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,1556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1556, ctx.r28.u32);
	// addi r4,r1,18320
	ctx.r4.s64 = ctx.r1.s64 + 18320;
	// stw r31,1560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1560, ctx.r31.u32);
	// addi r3,r1,1576
	ctx.r3.s64 = ctx.r1.s64 + 1576;
	// stw r31,1564(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1564, ctx.r31.u32);
	// stw r31,1568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1568, ctx.r31.u32);
	// stw r31,1572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1572, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821978A8;
	sub_821B7900(ctx, base);
	// addi r4,r30,6800
	ctx.r4.s64 = ctx.r30.s64 + 6800;
	// addi r3,r1,1600
	ctx.r3.s64 = ctx.r1.s64 + 1600;
	// bl 0x82060190
	ctx.lr = 0x821978B4;
	sub_82060190(ctx, base);
	// stw r17,1628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1628, ctx.r17.u32);
	// stw r31,1632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1632, ctx.r31.u32);
	// addi r3,r1,1656
	ctx.r3.s64 = ctx.r1.s64 + 1656;
	// stw r31,1636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1636, ctx.r31.u32);
	// stw r18,1640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1640, ctx.r18.u32);
	// stw r31,1644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1644, ctx.r31.u32);
	// stw r31,1648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1648, ctx.r31.u32);
	// stw r31,1652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1652, ctx.r31.u32);
	// bl 0x82060f40
	ctx.lr = 0x821978D8;
	sub_82060F40(ctx, base);
	// addi r4,r30,6808
	ctx.r4.s64 = ctx.r30.s64 + 6808;
	// addi r3,r1,1680
	ctx.r3.s64 = ctx.r1.s64 + 1680;
	// bl 0x82060190
	ctx.lr = 0x821978E4;
	sub_82060190(ctx, base);
	// stw r25,1708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1708, ctx.r25.u32);
	// stw r29,1712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1712, ctx.r29.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r28,1716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1716, ctx.r28.u32);
	// addi r4,r1,4480
	ctx.r4.s64 = ctx.r1.s64 + 4480;
	// stw r31,1720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1720, ctx.r31.u32);
	// addi r3,r1,1736
	ctx.r3.s64 = ctx.r1.s64 + 1736;
	// stw r31,1724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1724, ctx.r31.u32);
	// stw r31,1728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1728, ctx.r31.u32);
	// stw r31,1732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1732, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197910;
	sub_821B7900(ctx, base);
	// addi r4,r30,6824
	ctx.r4.s64 = ctx.r30.s64 + 6824;
	// addi r3,r1,1760
	ctx.r3.s64 = ctx.r1.s64 + 1760;
	// bl 0x82060190
	ctx.lr = 0x8219791C;
	sub_82060190(ctx, base);
	// stw r17,1788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1788, ctx.r17.u32);
	// stw r31,1792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1792, ctx.r31.u32);
	// addi r3,r1,1816
	ctx.r3.s64 = ctx.r1.s64 + 1816;
	// stw r31,1796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1796, ctx.r31.u32);
	// stw r18,1800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1800, ctx.r18.u32);
	// stw r31,1804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1804, ctx.r31.u32);
	// stw r31,1808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1808, ctx.r31.u32);
	// stw r31,1812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1812, ctx.r31.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197940;
	sub_82060F40(ctx, base);
	// addi r4,r30,6832
	ctx.r4.s64 = ctx.r30.s64 + 6832;
	// addi r3,r1,1840
	ctx.r3.s64 = ctx.r1.s64 + 1840;
	// bl 0x82060190
	ctx.lr = 0x8219794C;
	sub_82060190(ctx, base);
	// addi r8,r1,1880
	ctx.r8.s64 = ctx.r1.s64 + 1880;
	// stw r26,1868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1868, ctx.r26.u32);
	// addi r3,r1,1896
	ctx.r3.s64 = ctx.r1.s64 + 1896;
	// stw r31,1872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1872, ctx.r31.u32);
	// stw r31,1876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1876, ctx.r31.u32);
	// std r31,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r31.u64);
	// std r31,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, ctx.r31.u64);
	// bl 0x82060f40
	ctx.lr = 0x8219796C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6840
	ctx.r4.s64 = ctx.r30.s64 + 6840;
	// addi r3,r1,2960
	ctx.r3.s64 = ctx.r1.s64 + 2960;
	// bl 0x82060190
	ctx.lr = 0x82197978;
	sub_82060190(ctx, base);
	// stw r31,2988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2988, ctx.r31.u32);
	// stw r29,2992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2992, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,2996(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2996, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,3000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3000, ctx.r31.u32);
	// addi r3,r1,3016
	ctx.r3.s64 = ctx.r1.s64 + 3016;
	// stw r31,3004(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3004, ctx.r31.u32);
	// stw r31,3008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3008, ctx.r31.u32);
	// stw r31,3012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3012, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821979A4;
	sub_821B7900(ctx, base);
	// addi r4,r30,6848
	ctx.r4.s64 = ctx.r30.s64 + 6848;
	// addi r3,r1,3040
	ctx.r3.s64 = ctx.r1.s64 + 3040;
	// bl 0x82060190
	ctx.lr = 0x821979B0;
	sub_82060190(ctx, base);
	// stw r19,3068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3068, ctx.r19.u32);
	// stw r29,3072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3072, ctx.r29.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r28,3076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3076, ctx.r28.u32);
	// addi r4,r1,4240
	ctx.r4.s64 = ctx.r1.s64 + 4240;
	// stw r31,3080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3080, ctx.r31.u32);
	// addi r3,r1,3096
	ctx.r3.s64 = ctx.r1.s64 + 3096;
	// stw r31,3084(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3084, ctx.r31.u32);
	// stw r31,3088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3088, ctx.r31.u32);
	// stw r31,3092(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3092, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x821979DC;
	sub_821B7900(ctx, base);
	// addi r4,r30,6856
	ctx.r4.s64 = ctx.r30.s64 + 6856;
	// addi r3,r1,3120
	ctx.r3.s64 = ctx.r1.s64 + 3120;
	// bl 0x82060190
	ctx.lr = 0x821979E8;
	sub_82060190(ctx, base);
	// stw r27,3148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3148, ctx.r27.u32);
	// stw r29,3152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3152, ctx.r29.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r28,3156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3156, ctx.r28.u32);
	// addi r4,r1,4640
	ctx.r4.s64 = ctx.r1.s64 + 4640;
	// stw r31,3160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3160, ctx.r31.u32);
	// addi r3,r1,3176
	ctx.r3.s64 = ctx.r1.s64 + 3176;
	// stw r31,3164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3164, ctx.r31.u32);
	// stw r31,3168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3168, ctx.r31.u32);
	// stw r31,3172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3172, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197A14;
	sub_821B7900(ctx, base);
	// addi r4,r30,6868
	ctx.r4.s64 = ctx.r30.s64 + 6868;
	// addi r3,r1,3200
	ctx.r3.s64 = ctx.r1.s64 + 3200;
	// bl 0x82060190
	ctx.lr = 0x82197A20;
	sub_82060190(ctx, base);
	// stw r28,3228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3228, ctx.r28.u32);
	// stw r29,3232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3232, ctx.r29.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r28,3236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3236, ctx.r28.u32);
	// addi r4,r1,16560
	ctx.r4.s64 = ctx.r1.s64 + 16560;
	// stw r31,3240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3240, ctx.r31.u32);
	// addi r3,r1,3256
	ctx.r3.s64 = ctx.r1.s64 + 3256;
	// stw r31,3244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3244, ctx.r31.u32);
	// stw r31,3248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3248, ctx.r31.u32);
	// stw r31,3252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3252, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197A4C;
	sub_821B7900(ctx, base);
	// addi r4,r30,6880
	ctx.r4.s64 = ctx.r30.s64 + 6880;
	// addi r3,r1,3280
	ctx.r3.s64 = ctx.r1.s64 + 3280;
	// bl 0x82060190
	ctx.lr = 0x82197A58;
	sub_82060190(ctx, base);
	// stw r20,3308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3308, ctx.r20.u32);
	// stw r29,3312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3312, ctx.r29.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r28,3316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3316, ctx.r28.u32);
	// addi r4,r1,17600
	ctx.r4.s64 = ctx.r1.s64 + 17600;
	// stw r31,3320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3320, ctx.r31.u32);
	// addi r3,r1,3336
	ctx.r3.s64 = ctx.r1.s64 + 3336;
	// stw r31,3324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3324, ctx.r31.u32);
	// stw r31,3328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3328, ctx.r31.u32);
	// stw r31,3332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3332, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197A84;
	sub_821B7900(ctx, base);
	// addi r4,r30,6892
	ctx.r4.s64 = ctx.r30.s64 + 6892;
	// addi r3,r1,3360
	ctx.r3.s64 = ctx.r1.s64 + 3360;
	// bl 0x82060190
	ctx.lr = 0x82197A90;
	sub_82060190(ctx, base);
	// stw r21,3388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3388, ctx.r21.u32);
	// stw r29,3392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3392, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,3396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3396, ctx.r28.u32);
	// addi r4,r1,19120
	ctx.r4.s64 = ctx.r1.s64 + 19120;
	// stw r27,3400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3400, ctx.r27.u32);
	// addi r3,r1,3416
	ctx.r3.s64 = ctx.r1.s64 + 3416;
	// stw r27,3404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3404, ctx.r27.u32);
	// stw r31,3408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3408, ctx.r31.u32);
	// stw r31,3412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3412, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197ABC;
	sub_821B7900(ctx, base);
	// addi r4,r30,6908
	ctx.r4.s64 = ctx.r30.s64 + 6908;
	// addi r3,r1,3440
	ctx.r3.s64 = ctx.r1.s64 + 3440;
	// bl 0x82060190
	ctx.lr = 0x82197AC8;
	sub_82060190(ctx, base);
	// stw r22,3468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3468, ctx.r22.u32);
	// stw r29,3472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3472, ctx.r29.u32);
	// addi r3,r1,3496
	ctx.r3.s64 = ctx.r1.s64 + 3496;
	// stw r27,3476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3476, ctx.r27.u32);
	// stw r31,3480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3480, ctx.r31.u32);
	// stw r31,3484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3484, ctx.r31.u32);
	// stw r31,3488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3488, ctx.r31.u32);
	// stw r16,3492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3492, ctx.r16.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197AEC;
	sub_82060F40(ctx, base);
	// addi r4,r30,6928
	ctx.r4.s64 = ctx.r30.s64 + 6928;
	// addi r3,r1,3520
	ctx.r3.s64 = ctx.r1.s64 + 3520;
	// bl 0x82060190
	ctx.lr = 0x82197AF8;
	sub_82060190(ctx, base);
	// stw r23,3548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3548, ctx.r23.u32);
	// stw r29,3552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3552, ctx.r29.u32);
	// addi r3,r1,3576
	ctx.r3.s64 = ctx.r1.s64 + 3576;
	// stw r27,3556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3556, ctx.r27.u32);
	// stw r31,3560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3560, ctx.r31.u32);
	// stw r31,3564(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3564, ctx.r31.u32);
	// stw r31,3568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3568, ctx.r31.u32);
	// stw r14,3572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3572, ctx.r14.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197B1C;
	sub_82060F40(ctx, base);
	// addi r4,r30,6944
	ctx.r4.s64 = ctx.r30.s64 + 6944;
	// addi r3,r1,3600
	ctx.r3.s64 = ctx.r1.s64 + 3600;
	// bl 0x82060190
	ctx.lr = 0x82197B28;
	sub_82060190(ctx, base);
	// li r14,12
	ctx.r14.s64 = 12;
	// stw r29,3632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3632, ctx.r29.u32);
	// addi r3,r1,3656
	ctx.r3.s64 = ctx.r1.s64 + 3656;
	// stw r14,3628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3628, ctx.r14.u32);
	// stw r27,3636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3636, ctx.r27.u32);
	// stw r31,3640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3640, ctx.r31.u32);
	// stw r31,3644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3644, ctx.r31.u32);
	// stw r31,3648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3648, ctx.r31.u32);
	// stw r15,3652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3652, ctx.r15.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197B50;
	sub_82060F40(ctx, base);
	// addi r4,r30,6960
	ctx.r4.s64 = ctx.r30.s64 + 6960;
	// addi r3,r1,3680
	ctx.r3.s64 = ctx.r1.s64 + 3680;
	// bl 0x82060190
	ctx.lr = 0x82197B5C;
	sub_82060190(ctx, base);
	// li r7,13
	ctx.r7.s64 = 13;
	// stw r29,3712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3712, ctx.r29.u32);
	// addi r3,r1,3736
	ctx.r3.s64 = ctx.r1.s64 + 3736;
	// stw r7,3708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3708, ctx.r7.u32);
	// stw r27,3716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3716, ctx.r27.u32);
	// stw r31,3720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3720, ctx.r31.u32);
	// stw r31,3724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3724, ctx.r31.u32);
	// stw r31,3728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3728, ctx.r31.u32);
	// stw r15,3732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3732, ctx.r15.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197B84;
	sub_82060F40(ctx, base);
	// addi r4,r30,6976
	ctx.r4.s64 = ctx.r30.s64 + 6976;
	// addi r3,r1,3760
	ctx.r3.s64 = ctx.r1.s64 + 3760;
	// bl 0x82060190
	ctx.lr = 0x82197B90;
	sub_82060190(ctx, base);
	// stw r24,3788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3788, ctx.r24.u32);
	// stw r29,3792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3792, ctx.r29.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r28,3796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3796, ctx.r28.u32);
	// addi r4,r1,18320
	ctx.r4.s64 = ctx.r1.s64 + 18320;
	// stw r31,3800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3800, ctx.r31.u32);
	// addi r3,r1,3816
	ctx.r3.s64 = ctx.r1.s64 + 3816;
	// stw r31,3804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3804, ctx.r31.u32);
	// stw r31,3808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3808, ctx.r31.u32);
	// stw r31,3812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3812, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197BBC;
	sub_821B7900(ctx, base);
	// addi r4,r30,6992
	ctx.r4.s64 = ctx.r30.s64 + 6992;
	// addi r3,r1,3840
	ctx.r3.s64 = ctx.r1.s64 + 3840;
	// bl 0x82060190
	ctx.lr = 0x82197BC8;
	sub_82060190(ctx, base);
	// li r15,15
	ctx.r15.s64 = 15;
	// stw r29,3872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3872, ctx.r29.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r15,3868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3868, ctx.r15.u32);
	// addi r4,r1,4800
	ctx.r4.s64 = ctx.r1.s64 + 4800;
	// stw r28,3876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3876, ctx.r28.u32);
	// addi r3,r1,3896
	ctx.r3.s64 = ctx.r1.s64 + 3896;
	// stw r31,3880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3880, ctx.r31.u32);
	// stw r31,3884(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3884, ctx.r31.u32);
	// stw r31,3888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3888, ctx.r31.u32);
	// stw r31,3892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3892, ctx.r31.u32);
	// bl 0x821b7900
	ctx.lr = 0x82197BF8;
	sub_821B7900(ctx, base);
	// addi r4,r30,7000
	ctx.r4.s64 = ctx.r30.s64 + 7000;
	// addi r3,r1,3920
	ctx.r3.s64 = ctx.r1.s64 + 3920;
	// bl 0x82060190
	ctx.lr = 0x82197C04;
	sub_82060190(ctx, base);
	// stw r17,3948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3948, ctx.r17.u32);
	// stw r31,3952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3952, ctx.r31.u32);
	// addi r3,r1,3976
	ctx.r3.s64 = ctx.r1.s64 + 3976;
	// stw r31,3956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3956, ctx.r31.u32);
	// stw r18,3960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3960, ctx.r18.u32);
	// stw r31,3964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3964, ctx.r31.u32);
	// stw r31,3968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3968, ctx.r31.u32);
	// stw r31,3972(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3972, ctx.r31.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197C28;
	sub_82060F40(ctx, base);
	// addi r4,r30,7008
	ctx.r4.s64 = ctx.r30.s64 + 7008;
	// addi r3,r1,4000
	ctx.r3.s64 = ctx.r1.s64 + 4000;
	// bl 0x82060190
	ctx.lr = 0x82197C34;
	sub_82060190(ctx, base);
	// addi r6,r1,4040
	ctx.r6.s64 = ctx.r1.s64 + 4040;
	// stw r25,4028(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4028, ctx.r25.u32);
	// addi r3,r1,4056
	ctx.r3.s64 = ctx.r1.s64 + 4056;
	// stw r29,4032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4032, ctx.r29.u32);
	// stw r31,4036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4036, ctx.r31.u32);
	// std r31,0(r6)
	PPC_STORE_U64(ctx.r6.u32 + 0, ctx.r31.u64);
	// std r31,8(r6)
	PPC_STORE_U64(ctx.r6.u32 + 8, ctx.r31.u64);
	// bl 0x82060f40
	ctx.lr = 0x82197C54;
	sub_82060F40(ctx, base);
	// addi r4,r30,7024
	ctx.r4.s64 = ctx.r30.s64 + 7024;
	// addi r3,r1,4080
	ctx.r3.s64 = ctx.r1.s64 + 4080;
	// bl 0x82060190
	ctx.lr = 0x82197C60;
	sub_82060190(ctx, base);
	// stw r17,4108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4108, ctx.r17.u32);
	// stw r31,4112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4112, ctx.r31.u32);
	// addi r3,r1,4136
	ctx.r3.s64 = ctx.r1.s64 + 4136;
	// stw r31,4116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4116, ctx.r31.u32);
	// stw r18,4120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4120, ctx.r18.u32);
	// stw r31,4124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4124, ctx.r31.u32);
	// stw r31,4128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4128, ctx.r31.u32);
	// stw r31,4132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4132, ctx.r31.u32);
	// bl 0x82060f40
	ctx.lr = 0x82197C84;
	sub_82060F40(ctx, base);
	// addi r4,r30,7032
	ctx.r4.s64 = ctx.r30.s64 + 7032;
	// addi r3,r1,4160
	ctx.r3.s64 = ctx.r1.s64 + 4160;
	// bl 0x82060190
	ctx.lr = 0x82197C90;
	sub_82060190(ctx, base);
	// addi r5,r1,4200
	ctx.r5.s64 = ctx.r1.s64 + 4200;
	// stw r26,4188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4188, ctx.r26.u32);
	// addi r3,r1,4216
	ctx.r3.s64 = ctx.r1.s64 + 4216;
	// stw r31,4192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4192, ctx.r31.u32);
	// stw r31,4196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4196, ctx.r31.u32);
	// std r31,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.r31.u64);
	// std r31,8(r5)
	PPC_STORE_U64(ctx.r5.u32 + 8, ctx.r31.u64);
	// bl 0x82060f40
	ctx.lr = 0x82197CB0;
	sub_82060F40(ctx, base);
	// stw r31,14992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14992, ctx.r31.u32);
	// addi r4,r30,7040
	ctx.r4.s64 = ctx.r30.s64 + 7040;
	// addi r3,r1,14996
	ctx.r3.s64 = ctx.r1.s64 + 14996;
	// bl 0x82060190
	ctx.lr = 0x82197CC0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15024
	ctx.r3.s64 = ctx.r1.s64 + 15024;
	// bl 0x820602f0
	ctx.lr = 0x82197CD0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15052
	ctx.r3.s64 = ctx.r1.s64 + 15052;
	// bl 0x820602f0
	ctx.lr = 0x82197CE0;
	sub_820602F0(ctx, base);
	// stw r19,15080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15080, ctx.r19.u32);
	// addi r4,r30,7060
	ctx.r4.s64 = ctx.r30.s64 + 7060;
	// addi r3,r1,15084
	ctx.r3.s64 = ctx.r1.s64 + 15084;
	// bl 0x82060190
	ctx.lr = 0x82197CF0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15112
	ctx.r3.s64 = ctx.r1.s64 + 15112;
	// bl 0x820602f0
	ctx.lr = 0x82197D00;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15140
	ctx.r3.s64 = ctx.r1.s64 + 15140;
	// bl 0x820602f0
	ctx.lr = 0x82197D10;
	sub_820602F0(ctx, base);
	// stw r27,15168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15168, ctx.r27.u32);
	// addi r4,r30,7080
	ctx.r4.s64 = ctx.r30.s64 + 7080;
	// addi r3,r1,15172
	ctx.r3.s64 = ctx.r1.s64 + 15172;
	// bl 0x82060190
	ctx.lr = 0x82197D20;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15200
	ctx.r3.s64 = ctx.r1.s64 + 15200;
	// bl 0x820602f0
	ctx.lr = 0x82197D30;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15228
	ctx.r3.s64 = ctx.r1.s64 + 15228;
	// bl 0x820602f0
	ctx.lr = 0x82197D40;
	sub_820602F0(ctx, base);
	// stw r28,15256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15256, ctx.r28.u32);
	// addi r4,r30,7100
	ctx.r4.s64 = ctx.r30.s64 + 7100;
	// addi r3,r1,15260
	ctx.r3.s64 = ctx.r1.s64 + 15260;
	// bl 0x82060190
	ctx.lr = 0x82197D50;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15288
	ctx.r3.s64 = ctx.r1.s64 + 15288;
	// bl 0x820602f0
	ctx.lr = 0x82197D60;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15316
	ctx.r3.s64 = ctx.r1.s64 + 15316;
	// bl 0x820602f0
	ctx.lr = 0x82197D70;
	sub_820602F0(ctx, base);
	// stw r20,15344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15344, ctx.r20.u32);
	// addi r4,r30,7120
	ctx.r4.s64 = ctx.r30.s64 + 7120;
	// addi r3,r1,15348
	ctx.r3.s64 = ctx.r1.s64 + 15348;
	// bl 0x82060190
	ctx.lr = 0x82197D80;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15376
	ctx.r3.s64 = ctx.r1.s64 + 15376;
	// bl 0x820602f0
	ctx.lr = 0x82197D90;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15404
	ctx.r3.s64 = ctx.r1.s64 + 15404;
	// bl 0x820602f0
	ctx.lr = 0x82197DA0;
	sub_820602F0(ctx, base);
	// stw r21,15432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15432, ctx.r21.u32);
	// addi r4,r30,7140
	ctx.r4.s64 = ctx.r30.s64 + 7140;
	// addi r3,r1,15436
	ctx.r3.s64 = ctx.r1.s64 + 15436;
	// bl 0x82060190
	ctx.lr = 0x82197DB0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15464
	ctx.r3.s64 = ctx.r1.s64 + 15464;
	// bl 0x820602f0
	ctx.lr = 0x82197DC0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15492
	ctx.r3.s64 = ctx.r1.s64 + 15492;
	// bl 0x820602f0
	ctx.lr = 0x82197DD0;
	sub_820602F0(ctx, base);
	// stw r22,15520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15520, ctx.r22.u32);
	// addi r4,r30,7160
	ctx.r4.s64 = ctx.r30.s64 + 7160;
	// addi r3,r1,15524
	ctx.r3.s64 = ctx.r1.s64 + 15524;
	// bl 0x82060190
	ctx.lr = 0x82197DE0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15552
	ctx.r3.s64 = ctx.r1.s64 + 15552;
	// bl 0x820602f0
	ctx.lr = 0x82197DF0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15580
	ctx.r3.s64 = ctx.r1.s64 + 15580;
	// bl 0x820602f0
	ctx.lr = 0x82197E00;
	sub_820602F0(ctx, base);
	// li r16,7
	ctx.r16.s64 = 7;
	// addi r4,r30,7188
	ctx.r4.s64 = ctx.r30.s64 + 7188;
	// stw r16,15608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15608, ctx.r16.u32);
	// addi r3,r1,15612
	ctx.r3.s64 = ctx.r1.s64 + 15612;
	// bl 0x82060190
	ctx.lr = 0x82197E14;
	sub_82060190(ctx, base);
	// addi r4,r30,7216
	ctx.r4.s64 = ctx.r30.s64 + 7216;
	// addi r3,r1,15640
	ctx.r3.s64 = ctx.r1.s64 + 15640;
	// bl 0x82060190
	ctx.lr = 0x82197E20;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15668
	ctx.r3.s64 = ctx.r1.s64 + 15668;
	// bl 0x820602f0
	ctx.lr = 0x82197E30;
	sub_820602F0(ctx, base);
	// stw r29,15696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15696, ctx.r29.u32);
	// addi r4,r30,7244
	ctx.r4.s64 = ctx.r30.s64 + 7244;
	// addi r3,r1,15700
	ctx.r3.s64 = ctx.r1.s64 + 15700;
	// bl 0x82060190
	ctx.lr = 0x82197E40;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15728
	ctx.r3.s64 = ctx.r1.s64 + 15728;
	// bl 0x820602f0
	ctx.lr = 0x82197E50;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15756
	ctx.r3.s64 = ctx.r1.s64 + 15756;
	// bl 0x820602f0
	ctx.lr = 0x82197E60;
	sub_820602F0(ctx, base);
	// stw r23,15784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15784, ctx.r23.u32);
	// addi r4,r30,7272
	ctx.r4.s64 = ctx.r30.s64 + 7272;
	// addi r3,r1,15788
	ctx.r3.s64 = ctx.r1.s64 + 15788;
	// bl 0x82060190
	ctx.lr = 0x82197E70;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15816
	ctx.r3.s64 = ctx.r1.s64 + 15816;
	// bl 0x820602f0
	ctx.lr = 0x82197E80;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15844
	ctx.r3.s64 = ctx.r1.s64 + 15844;
	// bl 0x820602f0
	ctx.lr = 0x82197E90;
	sub_820602F0(ctx, base);
	// li r17,10
	ctx.r17.s64 = 10;
	// addi r4,r30,7296
	ctx.r4.s64 = ctx.r30.s64 + 7296;
	// stw r17,15872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15872, ctx.r17.u32);
	// addi r3,r1,15876
	ctx.r3.s64 = ctx.r1.s64 + 15876;
	// bl 0x82060190
	ctx.lr = 0x82197EA4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15904
	ctx.r3.s64 = ctx.r1.s64 + 15904;
	// bl 0x820602f0
	ctx.lr = 0x82197EB4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15932
	ctx.r3.s64 = ctx.r1.s64 + 15932;
	// bl 0x820602f0
	ctx.lr = 0x82197EC4;
	sub_820602F0(ctx, base);
	// li r18,11
	ctx.r18.s64 = 11;
	// addi r4,r30,7320
	ctx.r4.s64 = ctx.r30.s64 + 7320;
	// stw r18,15960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 15960, ctx.r18.u32);
	// addi r3,r1,15964
	ctx.r3.s64 = ctx.r1.s64 + 15964;
	// bl 0x82060190
	ctx.lr = 0x82197ED8;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,15992
	ctx.r3.s64 = ctx.r1.s64 + 15992;
	// bl 0x820602f0
	ctx.lr = 0x82197EE8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16020
	ctx.r3.s64 = ctx.r1.s64 + 16020;
	// bl 0x820602f0
	ctx.lr = 0x82197EF8;
	sub_820602F0(ctx, base);
	// stw r24,16048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16048, ctx.r24.u32);
	// addi r4,r30,7348
	ctx.r4.s64 = ctx.r30.s64 + 7348;
	// addi r3,r1,16052
	ctx.r3.s64 = ctx.r1.s64 + 16052;
	// bl 0x82060190
	ctx.lr = 0x82197F08;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16080
	ctx.r3.s64 = ctx.r1.s64 + 16080;
	// bl 0x820602f0
	ctx.lr = 0x82197F18;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16108
	ctx.r3.s64 = ctx.r1.s64 + 16108;
	// bl 0x820602f0
	ctx.lr = 0x82197F28;
	sub_820602F0(ctx, base);
	// stw r25,16136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16136, ctx.r25.u32);
	// addi r4,r30,7368
	ctx.r4.s64 = ctx.r30.s64 + 7368;
	// addi r3,r1,16140
	ctx.r3.s64 = ctx.r1.s64 + 16140;
	// bl 0x82060190
	ctx.lr = 0x82197F38;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16168
	ctx.r3.s64 = ctx.r1.s64 + 16168;
	// bl 0x820602f0
	ctx.lr = 0x82197F48;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16196
	ctx.r3.s64 = ctx.r1.s64 + 16196;
	// bl 0x820602f0
	ctx.lr = 0x82197F58;
	sub_820602F0(ctx, base);
	// stw r26,16224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16224, ctx.r26.u32);
	// addi r4,r30,7388
	ctx.r4.s64 = ctx.r30.s64 + 7388;
	// addi r3,r1,16228
	ctx.r3.s64 = ctx.r1.s64 + 16228;
	// bl 0x82060190
	ctx.lr = 0x82197F68;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16256
	ctx.r3.s64 = ctx.r1.s64 + 16256;
	// bl 0x820602f0
	ctx.lr = 0x82197F78;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,16284
	ctx.r3.s64 = ctx.r1.s64 + 16284;
	// bl 0x820602f0
	ctx.lr = 0x82197F88;
	sub_820602F0(ctx, base);
	// stw r31,4960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4960, ctx.r31.u32);
	// stw r31,4964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 4964, ctx.r31.u32);
	// addi r4,r30,7400
	ctx.r4.s64 = ctx.r30.s64 + 7400;
	// addi r3,r1,4968
	ctx.r3.s64 = ctx.r1.s64 + 4968;
	// bl 0x82060190
	ctx.lr = 0x82197F9C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,4996
	ctx.r3.s64 = ctx.r1.s64 + 4996;
	// bl 0x820602f0
	ctx.lr = 0x82197FAC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5024
	ctx.r3.s64 = ctx.r1.s64 + 5024;
	// bl 0x820602f0
	ctx.lr = 0x82197FBC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5052
	ctx.r3.s64 = ctx.r1.s64 + 5052;
	// bl 0x820602f0
	ctx.lr = 0x82197FCC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5080
	ctx.r3.s64 = ctx.r1.s64 + 5080;
	// bl 0x820602f0
	ctx.lr = 0x82197FDC;
	sub_820602F0(ctx, base);
	// stw r19,5108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5108, ctx.r19.u32);
	// stw r31,5112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5112, ctx.r31.u32);
	// addi r4,r30,7424
	ctx.r4.s64 = ctx.r30.s64 + 7424;
	// addi r3,r1,5116
	ctx.r3.s64 = ctx.r1.s64 + 5116;
	// bl 0x82060190
	ctx.lr = 0x82197FF0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5144
	ctx.r3.s64 = ctx.r1.s64 + 5144;
	// bl 0x820602f0
	ctx.lr = 0x82198000;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5172
	ctx.r3.s64 = ctx.r1.s64 + 5172;
	// bl 0x820602f0
	ctx.lr = 0x82198010;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5200
	ctx.r3.s64 = ctx.r1.s64 + 5200;
	// bl 0x820602f0
	ctx.lr = 0x82198020;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5228
	ctx.r3.s64 = ctx.r1.s64 + 5228;
	// bl 0x820602f0
	ctx.lr = 0x82198030;
	sub_820602F0(ctx, base);
	// stw r27,5256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5256, ctx.r27.u32);
	// stw r31,5260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5260, ctx.r31.u32);
	// addi r4,r30,7448
	ctx.r4.s64 = ctx.r30.s64 + 7448;
	// addi r3,r1,5264
	ctx.r3.s64 = ctx.r1.s64 + 5264;
	// bl 0x82060190
	ctx.lr = 0x82198044;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5292
	ctx.r3.s64 = ctx.r1.s64 + 5292;
	// bl 0x820602f0
	ctx.lr = 0x82198054;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5320
	ctx.r3.s64 = ctx.r1.s64 + 5320;
	// bl 0x820602f0
	ctx.lr = 0x82198064;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5348
	ctx.r3.s64 = ctx.r1.s64 + 5348;
	// bl 0x820602f0
	ctx.lr = 0x82198074;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5376
	ctx.r3.s64 = ctx.r1.s64 + 5376;
	// bl 0x820602f0
	ctx.lr = 0x82198084;
	sub_820602F0(ctx, base);
	// stw r28,5404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5404, ctx.r28.u32);
	// stw r31,5408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5408, ctx.r31.u32);
	// addi r4,r30,7472
	ctx.r4.s64 = ctx.r30.s64 + 7472;
	// addi r3,r1,5412
	ctx.r3.s64 = ctx.r1.s64 + 5412;
	// bl 0x82060190
	ctx.lr = 0x82198098;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5440
	ctx.r3.s64 = ctx.r1.s64 + 5440;
	// bl 0x820602f0
	ctx.lr = 0x821980A8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5468
	ctx.r3.s64 = ctx.r1.s64 + 5468;
	// bl 0x820602f0
	ctx.lr = 0x821980B8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5496
	ctx.r3.s64 = ctx.r1.s64 + 5496;
	// bl 0x820602f0
	ctx.lr = 0x821980C8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5524
	ctx.r3.s64 = ctx.r1.s64 + 5524;
	// bl 0x820602f0
	ctx.lr = 0x821980D8;
	sub_820602F0(ctx, base);
	// stw r20,5552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5552, ctx.r20.u32);
	// stw r31,5556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5556, ctx.r31.u32);
	// addi r4,r30,7496
	ctx.r4.s64 = ctx.r30.s64 + 7496;
	// addi r3,r1,5560
	ctx.r3.s64 = ctx.r1.s64 + 5560;
	// bl 0x82060190
	ctx.lr = 0x821980EC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5588
	ctx.r3.s64 = ctx.r1.s64 + 5588;
	// bl 0x820602f0
	ctx.lr = 0x821980FC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5616
	ctx.r3.s64 = ctx.r1.s64 + 5616;
	// bl 0x820602f0
	ctx.lr = 0x8219810C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5644
	ctx.r3.s64 = ctx.r1.s64 + 5644;
	// bl 0x820602f0
	ctx.lr = 0x8219811C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5672
	ctx.r3.s64 = ctx.r1.s64 + 5672;
	// bl 0x820602f0
	ctx.lr = 0x8219812C;
	sub_820602F0(ctx, base);
	// stw r21,5700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5700, ctx.r21.u32);
	// stw r31,5704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5704, ctx.r31.u32);
	// addi r4,r30,7520
	ctx.r4.s64 = ctx.r30.s64 + 7520;
	// addi r3,r1,5708
	ctx.r3.s64 = ctx.r1.s64 + 5708;
	// bl 0x82060190
	ctx.lr = 0x82198140;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5736
	ctx.r3.s64 = ctx.r1.s64 + 5736;
	// bl 0x820602f0
	ctx.lr = 0x82198150;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5764
	ctx.r3.s64 = ctx.r1.s64 + 5764;
	// bl 0x820602f0
	ctx.lr = 0x82198160;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5792
	ctx.r3.s64 = ctx.r1.s64 + 5792;
	// bl 0x820602f0
	ctx.lr = 0x82198170;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5820
	ctx.r3.s64 = ctx.r1.s64 + 5820;
	// bl 0x820602f0
	ctx.lr = 0x82198180;
	sub_820602F0(ctx, base);
	// stw r22,5848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5848, ctx.r22.u32);
	// stw r31,5852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5852, ctx.r31.u32);
	// addi r4,r30,7544
	ctx.r4.s64 = ctx.r30.s64 + 7544;
	// addi r3,r1,5856
	ctx.r3.s64 = ctx.r1.s64 + 5856;
	// bl 0x82060190
	ctx.lr = 0x82198194;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5884
	ctx.r3.s64 = ctx.r1.s64 + 5884;
	// bl 0x820602f0
	ctx.lr = 0x821981A4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5912
	ctx.r3.s64 = ctx.r1.s64 + 5912;
	// bl 0x820602f0
	ctx.lr = 0x821981B4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5940
	ctx.r3.s64 = ctx.r1.s64 + 5940;
	// bl 0x820602f0
	ctx.lr = 0x821981C4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,5968
	ctx.r3.s64 = ctx.r1.s64 + 5968;
	// bl 0x820602f0
	ctx.lr = 0x821981D4;
	sub_820602F0(ctx, base);
	// stw r16,5996(r1)
	PPC_STORE_U32(ctx.r1.u32 + 5996, ctx.r16.u32);
	// stw r31,6000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6000, ctx.r31.u32);
	// addi r4,r30,7568
	ctx.r4.s64 = ctx.r30.s64 + 7568;
	// addi r3,r1,6004
	ctx.r3.s64 = ctx.r1.s64 + 6004;
	// bl 0x82060190
	ctx.lr = 0x821981E8;
	sub_82060190(ctx, base);
	// addi r4,r30,7592
	ctx.r4.s64 = ctx.r30.s64 + 7592;
	// addi r3,r1,6032
	ctx.r3.s64 = ctx.r1.s64 + 6032;
	// bl 0x82060190
	ctx.lr = 0x821981F4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6060
	ctx.r3.s64 = ctx.r1.s64 + 6060;
	// bl 0x820602f0
	ctx.lr = 0x82198204;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6088
	ctx.r3.s64 = ctx.r1.s64 + 6088;
	// bl 0x820602f0
	ctx.lr = 0x82198214;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6116
	ctx.r3.s64 = ctx.r1.s64 + 6116;
	// bl 0x820602f0
	ctx.lr = 0x82198224;
	sub_820602F0(ctx, base);
	// stw r29,6144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6144, ctx.r29.u32);
	// stw r31,6148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6148, ctx.r31.u32);
	// addi r4,r30,7616
	ctx.r4.s64 = ctx.r30.s64 + 7616;
	// addi r3,r1,6152
	ctx.r3.s64 = ctx.r1.s64 + 6152;
	// bl 0x82060190
	ctx.lr = 0x82198238;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6180
	ctx.r3.s64 = ctx.r1.s64 + 6180;
	// bl 0x820602f0
	ctx.lr = 0x82198248;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6208
	ctx.r3.s64 = ctx.r1.s64 + 6208;
	// bl 0x820602f0
	ctx.lr = 0x82198258;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6236
	ctx.r3.s64 = ctx.r1.s64 + 6236;
	// bl 0x820602f0
	ctx.lr = 0x82198268;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6264
	ctx.r3.s64 = ctx.r1.s64 + 6264;
	// bl 0x820602f0
	ctx.lr = 0x82198278;
	sub_820602F0(ctx, base);
	// stw r23,6292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6292, ctx.r23.u32);
	// stw r31,6296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6296, ctx.r31.u32);
	// addi r4,r30,7640
	ctx.r4.s64 = ctx.r30.s64 + 7640;
	// addi r3,r1,6300
	ctx.r3.s64 = ctx.r1.s64 + 6300;
	// bl 0x82060190
	ctx.lr = 0x8219828C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6328
	ctx.r3.s64 = ctx.r1.s64 + 6328;
	// bl 0x820602f0
	ctx.lr = 0x8219829C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6356
	ctx.r3.s64 = ctx.r1.s64 + 6356;
	// bl 0x820602f0
	ctx.lr = 0x821982AC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6384
	ctx.r3.s64 = ctx.r1.s64 + 6384;
	// bl 0x820602f0
	ctx.lr = 0x821982BC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6412
	ctx.r3.s64 = ctx.r1.s64 + 6412;
	// bl 0x820602f0
	ctx.lr = 0x821982CC;
	sub_820602F0(ctx, base);
	// stw r17,6440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6440, ctx.r17.u32);
	// stw r31,6444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6444, ctx.r31.u32);
	// addi r4,r30,7664
	ctx.r4.s64 = ctx.r30.s64 + 7664;
	// addi r3,r1,6448
	ctx.r3.s64 = ctx.r1.s64 + 6448;
	// bl 0x82060190
	ctx.lr = 0x821982E0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6476
	ctx.r3.s64 = ctx.r1.s64 + 6476;
	// bl 0x820602f0
	ctx.lr = 0x821982F0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6504
	ctx.r3.s64 = ctx.r1.s64 + 6504;
	// bl 0x820602f0
	ctx.lr = 0x82198300;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6532
	ctx.r3.s64 = ctx.r1.s64 + 6532;
	// bl 0x820602f0
	ctx.lr = 0x82198310;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6560
	ctx.r3.s64 = ctx.r1.s64 + 6560;
	// bl 0x820602f0
	ctx.lr = 0x82198320;
	sub_820602F0(ctx, base);
	// stw r18,6588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6588, ctx.r18.u32);
	// stw r31,6592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6592, ctx.r31.u32);
	// addi r4,r30,7688
	ctx.r4.s64 = ctx.r30.s64 + 7688;
	// addi r3,r1,6596
	ctx.r3.s64 = ctx.r1.s64 + 6596;
	// bl 0x82060190
	ctx.lr = 0x82198334;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6624
	ctx.r3.s64 = ctx.r1.s64 + 6624;
	// bl 0x820602f0
	ctx.lr = 0x82198344;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6652
	ctx.r3.s64 = ctx.r1.s64 + 6652;
	// bl 0x820602f0
	ctx.lr = 0x82198354;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6680
	ctx.r3.s64 = ctx.r1.s64 + 6680;
	// bl 0x820602f0
	ctx.lr = 0x82198364;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6708
	ctx.r3.s64 = ctx.r1.s64 + 6708;
	// bl 0x820602f0
	ctx.lr = 0x82198374;
	sub_820602F0(ctx, base);
	// stw r24,6736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6736, ctx.r24.u32);
	// stw r31,6740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6740, ctx.r31.u32);
	// addi r4,r30,7712
	ctx.r4.s64 = ctx.r30.s64 + 7712;
	// addi r3,r1,6744
	ctx.r3.s64 = ctx.r1.s64 + 6744;
	// bl 0x82060190
	ctx.lr = 0x82198388;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6772
	ctx.r3.s64 = ctx.r1.s64 + 6772;
	// bl 0x820602f0
	ctx.lr = 0x82198398;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6800
	ctx.r3.s64 = ctx.r1.s64 + 6800;
	// bl 0x820602f0
	ctx.lr = 0x821983A8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6828
	ctx.r3.s64 = ctx.r1.s64 + 6828;
	// bl 0x820602f0
	ctx.lr = 0x821983B8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6856
	ctx.r3.s64 = ctx.r1.s64 + 6856;
	// bl 0x820602f0
	ctx.lr = 0x821983C8;
	sub_820602F0(ctx, base);
	// stw r25,6884(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6884, ctx.r25.u32);
	// stw r31,6888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 6888, ctx.r31.u32);
	// addi r4,r30,7736
	ctx.r4.s64 = ctx.r30.s64 + 7736;
	// addi r3,r1,6892
	ctx.r3.s64 = ctx.r1.s64 + 6892;
	// bl 0x82060190
	ctx.lr = 0x821983DC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6920
	ctx.r3.s64 = ctx.r1.s64 + 6920;
	// bl 0x820602f0
	ctx.lr = 0x821983EC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6948
	ctx.r3.s64 = ctx.r1.s64 + 6948;
	// bl 0x820602f0
	ctx.lr = 0x821983FC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,6976
	ctx.r3.s64 = ctx.r1.s64 + 6976;
	// bl 0x820602f0
	ctx.lr = 0x8219840C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7004
	ctx.r3.s64 = ctx.r1.s64 + 7004;
	// bl 0x820602f0
	ctx.lr = 0x8219841C;
	sub_820602F0(ctx, base);
	// stw r26,7032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7032, ctx.r26.u32);
	// stw r31,7036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7036, ctx.r31.u32);
	// addi r4,r30,7760
	ctx.r4.s64 = ctx.r30.s64 + 7760;
	// addi r3,r1,7040
	ctx.r3.s64 = ctx.r1.s64 + 7040;
	// bl 0x82060190
	ctx.lr = 0x82198430;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7068
	ctx.r3.s64 = ctx.r1.s64 + 7068;
	// bl 0x820602f0
	ctx.lr = 0x82198440;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7096
	ctx.r3.s64 = ctx.r1.s64 + 7096;
	// bl 0x820602f0
	ctx.lr = 0x82198450;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7124
	ctx.r3.s64 = ctx.r1.s64 + 7124;
	// bl 0x820602f0
	ctx.lr = 0x82198460;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7152
	ctx.r3.s64 = ctx.r1.s64 + 7152;
	// bl 0x820602f0
	ctx.lr = 0x82198470;
	sub_820602F0(ctx, base);
	// stw r31,12080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12080, ctx.r31.u32);
	// addi r4,r30,7772
	ctx.r4.s64 = ctx.r30.s64 + 7772;
	// addi r3,r1,12084
	ctx.r3.s64 = ctx.r1.s64 + 12084;
	// bl 0x82060190
	ctx.lr = 0x82198480;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12112
	ctx.r3.s64 = ctx.r1.s64 + 12112;
	// bl 0x820602f0
	ctx.lr = 0x82198490;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12140
	ctx.r3.s64 = ctx.r1.s64 + 12140;
	// bl 0x820602f0
	ctx.lr = 0x821984A0;
	sub_820602F0(ctx, base);
	// stw r19,12168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12168, ctx.r19.u32);
	// addi r4,r30,7792
	ctx.r4.s64 = ctx.r30.s64 + 7792;
	// addi r3,r1,12172
	ctx.r3.s64 = ctx.r1.s64 + 12172;
	// bl 0x82060190
	ctx.lr = 0x821984B0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12200
	ctx.r3.s64 = ctx.r1.s64 + 12200;
	// bl 0x820602f0
	ctx.lr = 0x821984C0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12228
	ctx.r3.s64 = ctx.r1.s64 + 12228;
	// bl 0x820602f0
	ctx.lr = 0x821984D0;
	sub_820602F0(ctx, base);
	// stw r27,12256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12256, ctx.r27.u32);
	// addi r4,r30,7812
	ctx.r4.s64 = ctx.r30.s64 + 7812;
	// addi r3,r1,12260
	ctx.r3.s64 = ctx.r1.s64 + 12260;
	// bl 0x82060190
	ctx.lr = 0x821984E0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12288
	ctx.r3.s64 = ctx.r1.s64 + 12288;
	// bl 0x820602f0
	ctx.lr = 0x821984F0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12316
	ctx.r3.s64 = ctx.r1.s64 + 12316;
	// bl 0x820602f0
	ctx.lr = 0x82198500;
	sub_820602F0(ctx, base);
	// stw r28,12344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12344, ctx.r28.u32);
	// addi r4,r30,7832
	ctx.r4.s64 = ctx.r30.s64 + 7832;
	// addi r3,r1,12348
	ctx.r3.s64 = ctx.r1.s64 + 12348;
	// bl 0x82060190
	ctx.lr = 0x82198510;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12376
	ctx.r3.s64 = ctx.r1.s64 + 12376;
	// bl 0x820602f0
	ctx.lr = 0x82198520;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12404
	ctx.r3.s64 = ctx.r1.s64 + 12404;
	// bl 0x820602f0
	ctx.lr = 0x82198530;
	sub_820602F0(ctx, base);
	// stw r20,12432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12432, ctx.r20.u32);
	// addi r4,r30,7852
	ctx.r4.s64 = ctx.r30.s64 + 7852;
	// addi r3,r1,12436
	ctx.r3.s64 = ctx.r1.s64 + 12436;
	// bl 0x82060190
	ctx.lr = 0x82198540;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12464
	ctx.r3.s64 = ctx.r1.s64 + 12464;
	// bl 0x820602f0
	ctx.lr = 0x82198550;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12492
	ctx.r3.s64 = ctx.r1.s64 + 12492;
	// bl 0x820602f0
	ctx.lr = 0x82198560;
	sub_820602F0(ctx, base);
	// addi r4,r30,7872
	ctx.r4.s64 = ctx.r30.s64 + 7872;
	// stw r21,12520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12520, ctx.r21.u32);
	// addi r3,r1,12524
	ctx.r3.s64 = ctx.r1.s64 + 12524;
	// bl 0x82060190
	ctx.lr = 0x82198570;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12552
	ctx.r3.s64 = ctx.r1.s64 + 12552;
	// bl 0x820602f0
	ctx.lr = 0x82198580;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12580
	ctx.r3.s64 = ctx.r1.s64 + 12580;
	// bl 0x820602f0
	ctx.lr = 0x82198590;
	sub_820602F0(ctx, base);
	// stw r22,12608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12608, ctx.r22.u32);
	// addi r4,r30,7892
	ctx.r4.s64 = ctx.r30.s64 + 7892;
	// addi r3,r1,12612
	ctx.r3.s64 = ctx.r1.s64 + 12612;
	// bl 0x82060190
	ctx.lr = 0x821985A0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12640
	ctx.r3.s64 = ctx.r1.s64 + 12640;
	// bl 0x820602f0
	ctx.lr = 0x821985B0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12668
	ctx.r3.s64 = ctx.r1.s64 + 12668;
	// bl 0x820602f0
	ctx.lr = 0x821985C0;
	sub_820602F0(ctx, base);
	// stw r16,12696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12696, ctx.r16.u32);
	// addi r4,r30,7920
	ctx.r4.s64 = ctx.r30.s64 + 7920;
	// addi r3,r1,12700
	ctx.r3.s64 = ctx.r1.s64 + 12700;
	// bl 0x82060190
	ctx.lr = 0x821985D0;
	sub_82060190(ctx, base);
	// addi r4,r30,7948
	ctx.r4.s64 = ctx.r30.s64 + 7948;
	// addi r3,r1,12728
	ctx.r3.s64 = ctx.r1.s64 + 12728;
	// bl 0x82060190
	ctx.lr = 0x821985DC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12756
	ctx.r3.s64 = ctx.r1.s64 + 12756;
	// bl 0x820602f0
	ctx.lr = 0x821985EC;
	sub_820602F0(ctx, base);
	// stw r29,12784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12784, ctx.r29.u32);
	// addi r4,r30,7976
	ctx.r4.s64 = ctx.r30.s64 + 7976;
	// addi r3,r1,12788
	ctx.r3.s64 = ctx.r1.s64 + 12788;
	// bl 0x82060190
	ctx.lr = 0x821985FC;
	sub_82060190(ctx, base);
	// addi r4,r30,8004
	ctx.r4.s64 = ctx.r30.s64 + 8004;
	// addi r3,r1,12816
	ctx.r3.s64 = ctx.r1.s64 + 12816;
	// bl 0x82060190
	ctx.lr = 0x82198608;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12844
	ctx.r3.s64 = ctx.r1.s64 + 12844;
	// bl 0x820602f0
	ctx.lr = 0x82198618;
	sub_820602F0(ctx, base);
	// stw r23,12872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12872, ctx.r23.u32);
	// addi r4,r30,8032
	ctx.r4.s64 = ctx.r30.s64 + 8032;
	// addi r3,r1,12876
	ctx.r3.s64 = ctx.r1.s64 + 12876;
	// bl 0x82060190
	ctx.lr = 0x82198628;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12904
	ctx.r3.s64 = ctx.r1.s64 + 12904;
	// bl 0x820602f0
	ctx.lr = 0x82198638;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12932
	ctx.r3.s64 = ctx.r1.s64 + 12932;
	// bl 0x820602f0
	ctx.lr = 0x82198648;
	sub_820602F0(ctx, base);
	// stw r17,12960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 12960, ctx.r17.u32);
	// addi r4,r30,8056
	ctx.r4.s64 = ctx.r30.s64 + 8056;
	// addi r3,r1,12964
	ctx.r3.s64 = ctx.r1.s64 + 12964;
	// bl 0x82060190
	ctx.lr = 0x82198658;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12992
	ctx.r3.s64 = ctx.r1.s64 + 12992;
	// bl 0x820602f0
	ctx.lr = 0x82198668;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13020
	ctx.r3.s64 = ctx.r1.s64 + 13020;
	// bl 0x820602f0
	ctx.lr = 0x82198678;
	sub_820602F0(ctx, base);
	// stw r18,13048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13048, ctx.r18.u32);
	// addi r4,r30,8080
	ctx.r4.s64 = ctx.r30.s64 + 8080;
	// addi r3,r1,13052
	ctx.r3.s64 = ctx.r1.s64 + 13052;
	// bl 0x82060190
	ctx.lr = 0x82198688;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13080
	ctx.r3.s64 = ctx.r1.s64 + 13080;
	// bl 0x820602f0
	ctx.lr = 0x82198698;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13108
	ctx.r3.s64 = ctx.r1.s64 + 13108;
	// bl 0x820602f0
	ctx.lr = 0x821986A8;
	sub_820602F0(ctx, base);
	// stw r24,13136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13136, ctx.r24.u32);
	// addi r4,r30,8108
	ctx.r4.s64 = ctx.r30.s64 + 8108;
	// addi r3,r1,13140
	ctx.r3.s64 = ctx.r1.s64 + 13140;
	// bl 0x82060190
	ctx.lr = 0x821986B8;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13168
	ctx.r3.s64 = ctx.r1.s64 + 13168;
	// bl 0x820602f0
	ctx.lr = 0x821986C8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13196
	ctx.r3.s64 = ctx.r1.s64 + 13196;
	// bl 0x820602f0
	ctx.lr = 0x821986D8;
	sub_820602F0(ctx, base);
	// stw r25,13224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13224, ctx.r25.u32);
	// addi r4,r30,8128
	ctx.r4.s64 = ctx.r30.s64 + 8128;
	// addi r3,r1,13228
	ctx.r3.s64 = ctx.r1.s64 + 13228;
	// bl 0x82060190
	ctx.lr = 0x821986E8;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13256
	ctx.r3.s64 = ctx.r1.s64 + 13256;
	// bl 0x820602f0
	ctx.lr = 0x821986F8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13284
	ctx.r3.s64 = ctx.r1.s64 + 13284;
	// bl 0x820602f0
	ctx.lr = 0x82198708;
	sub_820602F0(ctx, base);
	// stw r26,13312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13312, ctx.r26.u32);
	// addi r4,r30,8148
	ctx.r4.s64 = ctx.r30.s64 + 8148;
	// addi r3,r1,13316
	ctx.r3.s64 = ctx.r1.s64 + 13316;
	// bl 0x82060190
	ctx.lr = 0x82198718;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13344
	ctx.r3.s64 = ctx.r1.s64 + 13344;
	// bl 0x820602f0
	ctx.lr = 0x82198728;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13372
	ctx.r3.s64 = ctx.r1.s64 + 13372;
	// bl 0x820602f0
	ctx.lr = 0x82198738;
	sub_820602F0(ctx, base);
	// stw r31,7184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7184, ctx.r31.u32);
	// stw r31,7188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7188, ctx.r31.u32);
	// addi r4,r30,8160
	ctx.r4.s64 = ctx.r30.s64 + 8160;
	// addi r3,r1,7192
	ctx.r3.s64 = ctx.r1.s64 + 7192;
	// bl 0x82060190
	ctx.lr = 0x8219874C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7220
	ctx.r3.s64 = ctx.r1.s64 + 7220;
	// bl 0x820602f0
	ctx.lr = 0x8219875C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7248
	ctx.r3.s64 = ctx.r1.s64 + 7248;
	// bl 0x820602f0
	ctx.lr = 0x8219876C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7276
	ctx.r3.s64 = ctx.r1.s64 + 7276;
	// bl 0x820602f0
	ctx.lr = 0x8219877C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7304
	ctx.r3.s64 = ctx.r1.s64 + 7304;
	// bl 0x820602f0
	ctx.lr = 0x8219878C;
	sub_820602F0(ctx, base);
	// stw r19,7332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7332, ctx.r19.u32);
	// stw r31,7336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7336, ctx.r31.u32);
	// addi r4,r30,8184
	ctx.r4.s64 = ctx.r30.s64 + 8184;
	// addi r3,r1,7340
	ctx.r3.s64 = ctx.r1.s64 + 7340;
	// bl 0x82060190
	ctx.lr = 0x821987A0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7368
	ctx.r3.s64 = ctx.r1.s64 + 7368;
	// bl 0x820602f0
	ctx.lr = 0x821987B0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7396
	ctx.r3.s64 = ctx.r1.s64 + 7396;
	// bl 0x820602f0
	ctx.lr = 0x821987C0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7424
	ctx.r3.s64 = ctx.r1.s64 + 7424;
	// bl 0x820602f0
	ctx.lr = 0x821987D0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7452
	ctx.r3.s64 = ctx.r1.s64 + 7452;
	// bl 0x820602f0
	ctx.lr = 0x821987E0;
	sub_820602F0(ctx, base);
	// stw r27,7480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7480, ctx.r27.u32);
	// stw r31,7484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7484, ctx.r31.u32);
	// addi r4,r30,8208
	ctx.r4.s64 = ctx.r30.s64 + 8208;
	// addi r3,r1,7488
	ctx.r3.s64 = ctx.r1.s64 + 7488;
	// bl 0x82060190
	ctx.lr = 0x821987F4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7516
	ctx.r3.s64 = ctx.r1.s64 + 7516;
	// bl 0x820602f0
	ctx.lr = 0x82198804;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7544
	ctx.r3.s64 = ctx.r1.s64 + 7544;
	// bl 0x820602f0
	ctx.lr = 0x82198814;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7572
	ctx.r3.s64 = ctx.r1.s64 + 7572;
	// bl 0x820602f0
	ctx.lr = 0x82198824;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7600
	ctx.r3.s64 = ctx.r1.s64 + 7600;
	// bl 0x820602f0
	ctx.lr = 0x82198834;
	sub_820602F0(ctx, base);
	// stw r28,7628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7628, ctx.r28.u32);
	// stw r31,7632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7632, ctx.r31.u32);
	// addi r4,r30,8232
	ctx.r4.s64 = ctx.r30.s64 + 8232;
	// addi r3,r1,7636
	ctx.r3.s64 = ctx.r1.s64 + 7636;
	// bl 0x82060190
	ctx.lr = 0x82198848;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7664
	ctx.r3.s64 = ctx.r1.s64 + 7664;
	// bl 0x820602f0
	ctx.lr = 0x82198858;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7692
	ctx.r3.s64 = ctx.r1.s64 + 7692;
	// bl 0x820602f0
	ctx.lr = 0x82198868;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7720
	ctx.r3.s64 = ctx.r1.s64 + 7720;
	// bl 0x820602f0
	ctx.lr = 0x82198878;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7748
	ctx.r3.s64 = ctx.r1.s64 + 7748;
	// bl 0x820602f0
	ctx.lr = 0x82198888;
	sub_820602F0(ctx, base);
	// stw r20,7776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7776, ctx.r20.u32);
	// stw r31,7780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7780, ctx.r31.u32);
	// addi r4,r30,8256
	ctx.r4.s64 = ctx.r30.s64 + 8256;
	// addi r3,r1,7784
	ctx.r3.s64 = ctx.r1.s64 + 7784;
	// bl 0x82060190
	ctx.lr = 0x8219889C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7812
	ctx.r3.s64 = ctx.r1.s64 + 7812;
	// bl 0x820602f0
	ctx.lr = 0x821988AC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7840
	ctx.r3.s64 = ctx.r1.s64 + 7840;
	// bl 0x820602f0
	ctx.lr = 0x821988BC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7868
	ctx.r3.s64 = ctx.r1.s64 + 7868;
	// bl 0x820602f0
	ctx.lr = 0x821988CC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7896
	ctx.r3.s64 = ctx.r1.s64 + 7896;
	// bl 0x820602f0
	ctx.lr = 0x821988DC;
	sub_820602F0(ctx, base);
	// stw r21,7924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7924, ctx.r21.u32);
	// stw r31,7928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 7928, ctx.r31.u32);
	// addi r4,r30,8280
	ctx.r4.s64 = ctx.r30.s64 + 8280;
	// addi r3,r1,7932
	ctx.r3.s64 = ctx.r1.s64 + 7932;
	// bl 0x82060190
	ctx.lr = 0x821988F0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7960
	ctx.r3.s64 = ctx.r1.s64 + 7960;
	// bl 0x820602f0
	ctx.lr = 0x82198900;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,7988
	ctx.r3.s64 = ctx.r1.s64 + 7988;
	// bl 0x820602f0
	ctx.lr = 0x82198910;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8016
	ctx.r3.s64 = ctx.r1.s64 + 8016;
	// bl 0x820602f0
	ctx.lr = 0x82198920;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8044
	ctx.r3.s64 = ctx.r1.s64 + 8044;
	// bl 0x820602f0
	ctx.lr = 0x82198930;
	sub_820602F0(ctx, base);
	// stw r22,8072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8072, ctx.r22.u32);
	// addi r4,r30,8304
	ctx.r4.s64 = ctx.r30.s64 + 8304;
	// stw r31,8076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8076, ctx.r31.u32);
	// addi r3,r1,8080
	ctx.r3.s64 = ctx.r1.s64 + 8080;
	// bl 0x82060190
	ctx.lr = 0x82198944;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8108
	ctx.r3.s64 = ctx.r1.s64 + 8108;
	// bl 0x820602f0
	ctx.lr = 0x82198954;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8136
	ctx.r3.s64 = ctx.r1.s64 + 8136;
	// bl 0x820602f0
	ctx.lr = 0x82198964;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8164
	ctx.r3.s64 = ctx.r1.s64 + 8164;
	// bl 0x820602f0
	ctx.lr = 0x82198974;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8192
	ctx.r3.s64 = ctx.r1.s64 + 8192;
	// bl 0x820602f0
	ctx.lr = 0x82198984;
	sub_820602F0(ctx, base);
	// stw r16,8220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8220, ctx.r16.u32);
	// stw r31,8224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8224, ctx.r31.u32);
	// addi r4,r30,8328
	ctx.r4.s64 = ctx.r30.s64 + 8328;
	// addi r3,r1,8228
	ctx.r3.s64 = ctx.r1.s64 + 8228;
	// bl 0x82060190
	ctx.lr = 0x82198998;
	sub_82060190(ctx, base);
	// addi r4,r30,8352
	ctx.r4.s64 = ctx.r30.s64 + 8352;
	// addi r3,r1,8256
	ctx.r3.s64 = ctx.r1.s64 + 8256;
	// bl 0x82060190
	ctx.lr = 0x821989A4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8284
	ctx.r3.s64 = ctx.r1.s64 + 8284;
	// bl 0x820602f0
	ctx.lr = 0x821989B4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8312
	ctx.r3.s64 = ctx.r1.s64 + 8312;
	// bl 0x820602f0
	ctx.lr = 0x821989C4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8340
	ctx.r3.s64 = ctx.r1.s64 + 8340;
	// bl 0x820602f0
	ctx.lr = 0x821989D4;
	sub_820602F0(ctx, base);
	// stw r29,8368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8368, ctx.r29.u32);
	// stw r31,8372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8372, ctx.r31.u32);
	// addi r4,r30,8376
	ctx.r4.s64 = ctx.r30.s64 + 8376;
	// addi r3,r1,8376
	ctx.r3.s64 = ctx.r1.s64 + 8376;
	// bl 0x82060190
	ctx.lr = 0x821989E8;
	sub_82060190(ctx, base);
	// addi r4,r30,8400
	ctx.r4.s64 = ctx.r30.s64 + 8400;
	// addi r3,r1,8404
	ctx.r3.s64 = ctx.r1.s64 + 8404;
	// bl 0x82060190
	ctx.lr = 0x821989F4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8432
	ctx.r3.s64 = ctx.r1.s64 + 8432;
	// bl 0x820602f0
	ctx.lr = 0x82198A04;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8460
	ctx.r3.s64 = ctx.r1.s64 + 8460;
	// bl 0x820602f0
	ctx.lr = 0x82198A14;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8488
	ctx.r3.s64 = ctx.r1.s64 + 8488;
	// bl 0x820602f0
	ctx.lr = 0x82198A24;
	sub_820602F0(ctx, base);
	// stw r23,8516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8516, ctx.r23.u32);
	// stw r31,8520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8520, ctx.r31.u32);
	// addi r4,r30,8424
	ctx.r4.s64 = ctx.r30.s64 + 8424;
	// addi r3,r1,8524
	ctx.r3.s64 = ctx.r1.s64 + 8524;
	// bl 0x82060190
	ctx.lr = 0x82198A38;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8552
	ctx.r3.s64 = ctx.r1.s64 + 8552;
	// bl 0x820602f0
	ctx.lr = 0x82198A48;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8580
	ctx.r3.s64 = ctx.r1.s64 + 8580;
	// bl 0x820602f0
	ctx.lr = 0x82198A58;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8608
	ctx.r3.s64 = ctx.r1.s64 + 8608;
	// bl 0x820602f0
	ctx.lr = 0x82198A68;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8636
	ctx.r3.s64 = ctx.r1.s64 + 8636;
	// bl 0x820602f0
	ctx.lr = 0x82198A78;
	sub_820602F0(ctx, base);
	// stw r17,8664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8664, ctx.r17.u32);
	// stw r31,8668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8668, ctx.r31.u32);
	// addi r4,r30,8448
	ctx.r4.s64 = ctx.r30.s64 + 8448;
	// addi r3,r1,8672
	ctx.r3.s64 = ctx.r1.s64 + 8672;
	// bl 0x82060190
	ctx.lr = 0x82198A8C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8700
	ctx.r3.s64 = ctx.r1.s64 + 8700;
	// bl 0x820602f0
	ctx.lr = 0x82198A9C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8728
	ctx.r3.s64 = ctx.r1.s64 + 8728;
	// bl 0x820602f0
	ctx.lr = 0x82198AAC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8756
	ctx.r3.s64 = ctx.r1.s64 + 8756;
	// bl 0x820602f0
	ctx.lr = 0x82198ABC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8784
	ctx.r3.s64 = ctx.r1.s64 + 8784;
	// bl 0x820602f0
	ctx.lr = 0x82198ACC;
	sub_820602F0(ctx, base);
	// stw r18,8812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8812, ctx.r18.u32);
	// stw r31,8816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8816, ctx.r31.u32);
	// addi r4,r30,8472
	ctx.r4.s64 = ctx.r30.s64 + 8472;
	// addi r3,r1,8820
	ctx.r3.s64 = ctx.r1.s64 + 8820;
	// bl 0x82060190
	ctx.lr = 0x82198AE0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8848
	ctx.r3.s64 = ctx.r1.s64 + 8848;
	// bl 0x820602f0
	ctx.lr = 0x82198AF0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8876
	ctx.r3.s64 = ctx.r1.s64 + 8876;
	// bl 0x820602f0
	ctx.lr = 0x82198B00;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8904
	ctx.r3.s64 = ctx.r1.s64 + 8904;
	// bl 0x820602f0
	ctx.lr = 0x82198B10;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8932
	ctx.r3.s64 = ctx.r1.s64 + 8932;
	// bl 0x820602f0
	ctx.lr = 0x82198B20;
	sub_820602F0(ctx, base);
	// stw r24,8960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8960, ctx.r24.u32);
	// stw r31,8964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 8964, ctx.r31.u32);
	// addi r4,r30,8496
	ctx.r4.s64 = ctx.r30.s64 + 8496;
	// addi r3,r1,8968
	ctx.r3.s64 = ctx.r1.s64 + 8968;
	// bl 0x82060190
	ctx.lr = 0x82198B34;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,8996
	ctx.r3.s64 = ctx.r1.s64 + 8996;
	// bl 0x820602f0
	ctx.lr = 0x82198B44;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9024
	ctx.r3.s64 = ctx.r1.s64 + 9024;
	// bl 0x820602f0
	ctx.lr = 0x82198B54;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9052
	ctx.r3.s64 = ctx.r1.s64 + 9052;
	// bl 0x820602f0
	ctx.lr = 0x82198B64;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9080
	ctx.r3.s64 = ctx.r1.s64 + 9080;
	// bl 0x820602f0
	ctx.lr = 0x82198B74;
	sub_820602F0(ctx, base);
	// stw r25,9108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9108, ctx.r25.u32);
	// stw r31,9112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9112, ctx.r31.u32);
	// addi r4,r30,8520
	ctx.r4.s64 = ctx.r30.s64 + 8520;
	// addi r3,r1,9116
	ctx.r3.s64 = ctx.r1.s64 + 9116;
	// bl 0x82060190
	ctx.lr = 0x82198B88;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9144
	ctx.r3.s64 = ctx.r1.s64 + 9144;
	// bl 0x820602f0
	ctx.lr = 0x82198B98;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9172
	ctx.r3.s64 = ctx.r1.s64 + 9172;
	// bl 0x820602f0
	ctx.lr = 0x82198BA8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9200
	ctx.r3.s64 = ctx.r1.s64 + 9200;
	// bl 0x820602f0
	ctx.lr = 0x82198BB8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9228
	ctx.r3.s64 = ctx.r1.s64 + 9228;
	// bl 0x820602f0
	ctx.lr = 0x82198BC8;
	sub_820602F0(ctx, base);
	// stw r26,9256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9256, ctx.r26.u32);
	// stw r31,9260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9260, ctx.r31.u32);
	// addi r4,r30,8544
	ctx.r4.s64 = ctx.r30.s64 + 8544;
	// addi r3,r1,9264
	ctx.r3.s64 = ctx.r1.s64 + 9264;
	// bl 0x82060190
	ctx.lr = 0x82198BDC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9292
	ctx.r3.s64 = ctx.r1.s64 + 9292;
	// bl 0x820602f0
	ctx.lr = 0x82198BEC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9320
	ctx.r3.s64 = ctx.r1.s64 + 9320;
	// bl 0x820602f0
	ctx.lr = 0x82198BFC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9348
	ctx.r3.s64 = ctx.r1.s64 + 9348;
	// bl 0x820602f0
	ctx.lr = 0x82198C0C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9376
	ctx.r3.s64 = ctx.r1.s64 + 9376;
	// bl 0x820602f0
	ctx.lr = 0x82198C1C;
	sub_820602F0(ctx, base);
	// stw r31,13408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13408, ctx.r31.u32);
	// addi r4,r30,8556
	ctx.r4.s64 = ctx.r30.s64 + 8556;
	// addi r3,r1,13412
	ctx.r3.s64 = ctx.r1.s64 + 13412;
	// bl 0x82060190
	ctx.lr = 0x82198C2C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13440
	ctx.r3.s64 = ctx.r1.s64 + 13440;
	// bl 0x820602f0
	ctx.lr = 0x82198C3C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13468
	ctx.r3.s64 = ctx.r1.s64 + 13468;
	// bl 0x820602f0
	ctx.lr = 0x82198C4C;
	sub_820602F0(ctx, base);
	// stw r19,13496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13496, ctx.r19.u32);
	// addi r4,r30,8576
	ctx.r4.s64 = ctx.r30.s64 + 8576;
	// addi r3,r1,13500
	ctx.r3.s64 = ctx.r1.s64 + 13500;
	// bl 0x82060190
	ctx.lr = 0x82198C5C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13528
	ctx.r3.s64 = ctx.r1.s64 + 13528;
	// bl 0x820602f0
	ctx.lr = 0x82198C6C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13556
	ctx.r3.s64 = ctx.r1.s64 + 13556;
	// bl 0x820602f0
	ctx.lr = 0x82198C7C;
	sub_820602F0(ctx, base);
	// stw r27,13584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13584, ctx.r27.u32);
	// addi r4,r30,8596
	ctx.r4.s64 = ctx.r30.s64 + 8596;
	// addi r3,r1,13588
	ctx.r3.s64 = ctx.r1.s64 + 13588;
	// bl 0x82060190
	ctx.lr = 0x82198C8C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13616
	ctx.r3.s64 = ctx.r1.s64 + 13616;
	// bl 0x820602f0
	ctx.lr = 0x82198C9C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13644
	ctx.r3.s64 = ctx.r1.s64 + 13644;
	// bl 0x820602f0
	ctx.lr = 0x82198CAC;
	sub_820602F0(ctx, base);
	// stw r28,13672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13672, ctx.r28.u32);
	// addi r4,r30,8616
	ctx.r4.s64 = ctx.r30.s64 + 8616;
	// addi r3,r1,13676
	ctx.r3.s64 = ctx.r1.s64 + 13676;
	// bl 0x82060190
	ctx.lr = 0x82198CBC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13704
	ctx.r3.s64 = ctx.r1.s64 + 13704;
	// bl 0x820602f0
	ctx.lr = 0x82198CCC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13732
	ctx.r3.s64 = ctx.r1.s64 + 13732;
	// bl 0x820602f0
	ctx.lr = 0x82198CDC;
	sub_820602F0(ctx, base);
	// stw r20,13760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13760, ctx.r20.u32);
	// addi r4,r30,8636
	ctx.r4.s64 = ctx.r30.s64 + 8636;
	// addi r3,r1,13764
	ctx.r3.s64 = ctx.r1.s64 + 13764;
	// bl 0x82060190
	ctx.lr = 0x82198CEC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13792
	ctx.r3.s64 = ctx.r1.s64 + 13792;
	// bl 0x820602f0
	ctx.lr = 0x82198CFC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13820
	ctx.r3.s64 = ctx.r1.s64 + 13820;
	// bl 0x820602f0
	ctx.lr = 0x82198D0C;
	sub_820602F0(ctx, base);
	// stw r21,13848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13848, ctx.r21.u32);
	// addi r4,r30,8656
	ctx.r4.s64 = ctx.r30.s64 + 8656;
	// addi r3,r1,13852
	ctx.r3.s64 = ctx.r1.s64 + 13852;
	// bl 0x82060190
	ctx.lr = 0x82198D1C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13880
	ctx.r3.s64 = ctx.r1.s64 + 13880;
	// bl 0x820602f0
	ctx.lr = 0x82198D2C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13908
	ctx.r3.s64 = ctx.r1.s64 + 13908;
	// bl 0x820602f0
	ctx.lr = 0x82198D3C;
	sub_820602F0(ctx, base);
	// stw r22,13936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 13936, ctx.r22.u32);
	// addi r4,r30,8676
	ctx.r4.s64 = ctx.r30.s64 + 8676;
	// addi r3,r1,13940
	ctx.r3.s64 = ctx.r1.s64 + 13940;
	// bl 0x82060190
	ctx.lr = 0x82198D4C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13968
	ctx.r3.s64 = ctx.r1.s64 + 13968;
	// bl 0x820602f0
	ctx.lr = 0x82198D5C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,13996
	ctx.r3.s64 = ctx.r1.s64 + 13996;
	// bl 0x820602f0
	ctx.lr = 0x82198D6C;
	sub_820602F0(ctx, base);
	// stw r16,14024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14024, ctx.r16.u32);
	// addi r4,r30,8704
	ctx.r4.s64 = ctx.r30.s64 + 8704;
	// addi r3,r1,14028
	ctx.r3.s64 = ctx.r1.s64 + 14028;
	// bl 0x82060190
	ctx.lr = 0x82198D7C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14056
	ctx.r3.s64 = ctx.r1.s64 + 14056;
	// bl 0x820602f0
	ctx.lr = 0x82198D8C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14084
	ctx.r3.s64 = ctx.r1.s64 + 14084;
	// bl 0x820602f0
	ctx.lr = 0x82198D9C;
	sub_820602F0(ctx, base);
	// stw r29,14112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14112, ctx.r29.u32);
	// addi r4,r30,8732
	ctx.r4.s64 = ctx.r30.s64 + 8732;
	// addi r3,r1,14116
	ctx.r3.s64 = ctx.r1.s64 + 14116;
	// bl 0x82060190
	ctx.lr = 0x82198DAC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14144
	ctx.r3.s64 = ctx.r1.s64 + 14144;
	// bl 0x820602f0
	ctx.lr = 0x82198DBC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14172
	ctx.r3.s64 = ctx.r1.s64 + 14172;
	// bl 0x820602f0
	ctx.lr = 0x82198DCC;
	sub_820602F0(ctx, base);
	// stw r23,14200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14200, ctx.r23.u32);
	// addi r4,r30,8760
	ctx.r4.s64 = ctx.r30.s64 + 8760;
	// addi r3,r1,14204
	ctx.r3.s64 = ctx.r1.s64 + 14204;
	// bl 0x82060190
	ctx.lr = 0x82198DDC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14232
	ctx.r3.s64 = ctx.r1.s64 + 14232;
	// bl 0x820602f0
	ctx.lr = 0x82198DEC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14260
	ctx.r3.s64 = ctx.r1.s64 + 14260;
	// bl 0x820602f0
	ctx.lr = 0x82198DFC;
	sub_820602F0(ctx, base);
	// stw r17,14288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14288, ctx.r17.u32);
	// addi r4,r30,8788
	ctx.r4.s64 = ctx.r30.s64 + 8788;
	// addi r3,r1,14292
	ctx.r3.s64 = ctx.r1.s64 + 14292;
	// bl 0x82060190
	ctx.lr = 0x82198E0C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14320
	ctx.r3.s64 = ctx.r1.s64 + 14320;
	// bl 0x820602f0
	ctx.lr = 0x82198E1C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14348
	ctx.r3.s64 = ctx.r1.s64 + 14348;
	// bl 0x820602f0
	ctx.lr = 0x82198E2C;
	sub_820602F0(ctx, base);
	// stw r18,14376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14376, ctx.r18.u32);
	// addi r4,r30,8816
	ctx.r4.s64 = ctx.r30.s64 + 8816;
	// addi r3,r1,14380
	ctx.r3.s64 = ctx.r1.s64 + 14380;
	// bl 0x82060190
	ctx.lr = 0x82198E3C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14408
	ctx.r3.s64 = ctx.r1.s64 + 14408;
	// bl 0x820602f0
	ctx.lr = 0x82198E4C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14436
	ctx.r3.s64 = ctx.r1.s64 + 14436;
	// bl 0x820602f0
	ctx.lr = 0x82198E5C;
	sub_820602F0(ctx, base);
	// stw r14,14464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14464, ctx.r14.u32);
	// addi r4,r30,8844
	ctx.r4.s64 = ctx.r30.s64 + 8844;
	// addi r3,r1,14468
	ctx.r3.s64 = ctx.r1.s64 + 14468;
	// bl 0x82060190
	ctx.lr = 0x82198E6C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14496
	ctx.r3.s64 = ctx.r1.s64 + 14496;
	// bl 0x820602f0
	ctx.lr = 0x82198E7C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14524
	ctx.r3.s64 = ctx.r1.s64 + 14524;
	// bl 0x820602f0
	ctx.lr = 0x82198E8C;
	sub_820602F0(ctx, base);
	// li r3,13
	ctx.r3.s64 = 13;
	// addi r4,r30,8868
	ctx.r4.s64 = ctx.r30.s64 + 8868;
	// stw r3,14552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14552, ctx.r3.u32);
	// addi r3,r1,14556
	ctx.r3.s64 = ctx.r1.s64 + 14556;
	// bl 0x82060190
	ctx.lr = 0x82198EA0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14584
	ctx.r3.s64 = ctx.r1.s64 + 14584;
	// bl 0x820602f0
	ctx.lr = 0x82198EB0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14612
	ctx.r3.s64 = ctx.r1.s64 + 14612;
	// bl 0x820602f0
	ctx.lr = 0x82198EC0;
	sub_820602F0(ctx, base);
	// stw r24,14640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14640, ctx.r24.u32);
	// addi r4,r30,8892
	ctx.r4.s64 = ctx.r30.s64 + 8892;
	// addi r3,r1,14644
	ctx.r3.s64 = ctx.r1.s64 + 14644;
	// bl 0x82060190
	ctx.lr = 0x82198ED0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14672
	ctx.r3.s64 = ctx.r1.s64 + 14672;
	// bl 0x820602f0
	ctx.lr = 0x82198EE0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14700
	ctx.r3.s64 = ctx.r1.s64 + 14700;
	// bl 0x820602f0
	ctx.lr = 0x82198EF0;
	sub_820602F0(ctx, base);
	// stw r15,14728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14728, ctx.r15.u32);
	// addi r4,r30,8912
	ctx.r4.s64 = ctx.r30.s64 + 8912;
	// addi r3,r1,14732
	ctx.r3.s64 = ctx.r1.s64 + 14732;
	// bl 0x82060190
	ctx.lr = 0x82198F00;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14760
	ctx.r3.s64 = ctx.r1.s64 + 14760;
	// bl 0x820602f0
	ctx.lr = 0x82198F10;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14788
	ctx.r3.s64 = ctx.r1.s64 + 14788;
	// bl 0x820602f0
	ctx.lr = 0x82198F20;
	sub_820602F0(ctx, base);
	// stw r25,14816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14816, ctx.r25.u32);
	// addi r4,r30,8932
	ctx.r4.s64 = ctx.r30.s64 + 8932;
	// addi r3,r1,14820
	ctx.r3.s64 = ctx.r1.s64 + 14820;
	// bl 0x82060190
	ctx.lr = 0x82198F30;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14848
	ctx.r3.s64 = ctx.r1.s64 + 14848;
	// bl 0x820602f0
	ctx.lr = 0x82198F40;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14876
	ctx.r3.s64 = ctx.r1.s64 + 14876;
	// bl 0x820602f0
	ctx.lr = 0x82198F50;
	sub_820602F0(ctx, base);
	// stw r26,14904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 14904, ctx.r26.u32);
	// addi r4,r30,8960
	ctx.r4.s64 = ctx.r30.s64 + 8960;
	// addi r3,r1,14908
	ctx.r3.s64 = ctx.r1.s64 + 14908;
	// bl 0x82060190
	ctx.lr = 0x82198F60;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14936
	ctx.r3.s64 = ctx.r1.s64 + 14936;
	// bl 0x820602f0
	ctx.lr = 0x82198F70;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,14964
	ctx.r3.s64 = ctx.r1.s64 + 14964;
	// bl 0x820602f0
	ctx.lr = 0x82198F80;
	sub_820602F0(ctx, base);
	// stw r31,9408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9408, ctx.r31.u32);
	// stw r31,9412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9412, ctx.r31.u32);
	// addi r4,r30,8972
	ctx.r4.s64 = ctx.r30.s64 + 8972;
	// addi r3,r1,9416
	ctx.r3.s64 = ctx.r1.s64 + 9416;
	// bl 0x82060190
	ctx.lr = 0x82198F94;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9444
	ctx.r3.s64 = ctx.r1.s64 + 9444;
	// bl 0x820602f0
	ctx.lr = 0x82198FA4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9472
	ctx.r3.s64 = ctx.r1.s64 + 9472;
	// bl 0x820602f0
	ctx.lr = 0x82198FB4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9500
	ctx.r3.s64 = ctx.r1.s64 + 9500;
	// bl 0x820602f0
	ctx.lr = 0x82198FC4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9528
	ctx.r3.s64 = ctx.r1.s64 + 9528;
	// bl 0x820602f0
	ctx.lr = 0x82198FD4;
	sub_820602F0(ctx, base);
	// stw r19,9556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9556, ctx.r19.u32);
	// stw r31,9560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9560, ctx.r31.u32);
	// addi r4,r30,8996
	ctx.r4.s64 = ctx.r30.s64 + 8996;
	// addi r3,r1,9564
	ctx.r3.s64 = ctx.r1.s64 + 9564;
	// bl 0x82060190
	ctx.lr = 0x82198FE8;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9592
	ctx.r3.s64 = ctx.r1.s64 + 9592;
	// bl 0x820602f0
	ctx.lr = 0x82198FF8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9620
	ctx.r3.s64 = ctx.r1.s64 + 9620;
	// bl 0x820602f0
	ctx.lr = 0x82199008;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9648
	ctx.r3.s64 = ctx.r1.s64 + 9648;
	// bl 0x820602f0
	ctx.lr = 0x82199018;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9676
	ctx.r3.s64 = ctx.r1.s64 + 9676;
	// bl 0x820602f0
	ctx.lr = 0x82199028;
	sub_820602F0(ctx, base);
	// stw r27,9704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9704, ctx.r27.u32);
	// stw r31,9708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9708, ctx.r31.u32);
	// addi r4,r30,9020
	ctx.r4.s64 = ctx.r30.s64 + 9020;
	// addi r3,r1,9712
	ctx.r3.s64 = ctx.r1.s64 + 9712;
	// bl 0x82060190
	ctx.lr = 0x8219903C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9740
	ctx.r3.s64 = ctx.r1.s64 + 9740;
	// bl 0x820602f0
	ctx.lr = 0x8219904C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9768
	ctx.r3.s64 = ctx.r1.s64 + 9768;
	// bl 0x820602f0
	ctx.lr = 0x8219905C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9796
	ctx.r3.s64 = ctx.r1.s64 + 9796;
	// bl 0x820602f0
	ctx.lr = 0x8219906C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9824
	ctx.r3.s64 = ctx.r1.s64 + 9824;
	// bl 0x820602f0
	ctx.lr = 0x8219907C;
	sub_820602F0(ctx, base);
	// stw r28,9852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9852, ctx.r28.u32);
	// stw r31,9856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 9856, ctx.r31.u32);
	// addi r4,r30,9044
	ctx.r4.s64 = ctx.r30.s64 + 9044;
	// addi r3,r1,9860
	ctx.r3.s64 = ctx.r1.s64 + 9860;
	// bl 0x82060190
	ctx.lr = 0x82199090;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9888
	ctx.r3.s64 = ctx.r1.s64 + 9888;
	// bl 0x820602f0
	ctx.lr = 0x821990A0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9916
	ctx.r3.s64 = ctx.r1.s64 + 9916;
	// bl 0x820602f0
	ctx.lr = 0x821990B0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9944
	ctx.r3.s64 = ctx.r1.s64 + 9944;
	// bl 0x820602f0
	ctx.lr = 0x821990C0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,9972
	ctx.r3.s64 = ctx.r1.s64 + 9972;
	// bl 0x820602f0
	ctx.lr = 0x821990D0;
	sub_820602F0(ctx, base);
	// stw r20,10000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10000, ctx.r20.u32);
	// addi r4,r30,9068
	ctx.r4.s64 = ctx.r30.s64 + 9068;
	// stw r31,10004(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10004, ctx.r31.u32);
	// addi r3,r1,10008
	ctx.r3.s64 = ctx.r1.s64 + 10008;
	// bl 0x82060190
	ctx.lr = 0x821990E4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10036
	ctx.r3.s64 = ctx.r1.s64 + 10036;
	// bl 0x820602f0
	ctx.lr = 0x821990F4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10064
	ctx.r3.s64 = ctx.r1.s64 + 10064;
	// bl 0x820602f0
	ctx.lr = 0x82199104;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10092
	ctx.r3.s64 = ctx.r1.s64 + 10092;
	// bl 0x820602f0
	ctx.lr = 0x82199114;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10120
	ctx.r3.s64 = ctx.r1.s64 + 10120;
	// bl 0x820602f0
	ctx.lr = 0x82199124;
	sub_820602F0(ctx, base);
	// stw r21,10148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10148, ctx.r21.u32);
	// stw r31,10152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10152, ctx.r31.u32);
	// addi r4,r30,9092
	ctx.r4.s64 = ctx.r30.s64 + 9092;
	// addi r3,r1,10156
	ctx.r3.s64 = ctx.r1.s64 + 10156;
	// bl 0x82060190
	ctx.lr = 0x82199138;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10184
	ctx.r3.s64 = ctx.r1.s64 + 10184;
	// bl 0x820602f0
	ctx.lr = 0x82199148;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10212
	ctx.r3.s64 = ctx.r1.s64 + 10212;
	// bl 0x820602f0
	ctx.lr = 0x82199158;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10240
	ctx.r3.s64 = ctx.r1.s64 + 10240;
	// bl 0x820602f0
	ctx.lr = 0x82199168;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10268
	ctx.r3.s64 = ctx.r1.s64 + 10268;
	// bl 0x820602f0
	ctx.lr = 0x82199178;
	sub_820602F0(ctx, base);
	// stw r22,10296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10296, ctx.r22.u32);
	// stw r31,10300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10300, ctx.r31.u32);
	// addi r4,r30,9116
	ctx.r4.s64 = ctx.r30.s64 + 9116;
	// addi r3,r1,10304
	ctx.r3.s64 = ctx.r1.s64 + 10304;
	// bl 0x82060190
	ctx.lr = 0x8219918C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10332
	ctx.r3.s64 = ctx.r1.s64 + 10332;
	// bl 0x820602f0
	ctx.lr = 0x8219919C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10360
	ctx.r3.s64 = ctx.r1.s64 + 10360;
	// bl 0x820602f0
	ctx.lr = 0x821991AC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10388
	ctx.r3.s64 = ctx.r1.s64 + 10388;
	// bl 0x820602f0
	ctx.lr = 0x821991BC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10416
	ctx.r3.s64 = ctx.r1.s64 + 10416;
	// bl 0x820602f0
	ctx.lr = 0x821991CC;
	sub_820602F0(ctx, base);
	// stw r16,10444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10444, ctx.r16.u32);
	// stw r31,10448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10448, ctx.r31.u32);
	// addi r4,r30,9140
	ctx.r4.s64 = ctx.r30.s64 + 9140;
	// addi r3,r1,10452
	ctx.r3.s64 = ctx.r1.s64 + 10452;
	// bl 0x82060190
	ctx.lr = 0x821991E0;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10480
	ctx.r3.s64 = ctx.r1.s64 + 10480;
	// bl 0x820602f0
	ctx.lr = 0x821991F0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10508
	ctx.r3.s64 = ctx.r1.s64 + 10508;
	// bl 0x820602f0
	ctx.lr = 0x82199200;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10536
	ctx.r3.s64 = ctx.r1.s64 + 10536;
	// bl 0x820602f0
	ctx.lr = 0x82199210;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10564
	ctx.r3.s64 = ctx.r1.s64 + 10564;
	// bl 0x820602f0
	ctx.lr = 0x82199220;
	sub_820602F0(ctx, base);
	// stw r29,10592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10592, ctx.r29.u32);
	// stw r31,10596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10596, ctx.r31.u32);
	// addi r4,r30,9164
	ctx.r4.s64 = ctx.r30.s64 + 9164;
	// addi r3,r1,10600
	ctx.r3.s64 = ctx.r1.s64 + 10600;
	// bl 0x82060190
	ctx.lr = 0x82199234;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10628
	ctx.r3.s64 = ctx.r1.s64 + 10628;
	// bl 0x820602f0
	ctx.lr = 0x82199244;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10656
	ctx.r3.s64 = ctx.r1.s64 + 10656;
	// bl 0x820602f0
	ctx.lr = 0x82199254;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10684
	ctx.r3.s64 = ctx.r1.s64 + 10684;
	// bl 0x820602f0
	ctx.lr = 0x82199264;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10712
	ctx.r3.s64 = ctx.r1.s64 + 10712;
	// bl 0x820602f0
	ctx.lr = 0x82199274;
	sub_820602F0(ctx, base);
	// stw r23,10740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10740, ctx.r23.u32);
	// stw r31,10744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10744, ctx.r31.u32);
	// addi r4,r30,9188
	ctx.r4.s64 = ctx.r30.s64 + 9188;
	// addi r3,r1,10748
	ctx.r3.s64 = ctx.r1.s64 + 10748;
	// bl 0x82060190
	ctx.lr = 0x82199288;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10776
	ctx.r3.s64 = ctx.r1.s64 + 10776;
	// bl 0x820602f0
	ctx.lr = 0x82199298;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10804
	ctx.r3.s64 = ctx.r1.s64 + 10804;
	// bl 0x820602f0
	ctx.lr = 0x821992A8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10832
	ctx.r3.s64 = ctx.r1.s64 + 10832;
	// bl 0x820602f0
	ctx.lr = 0x821992B8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10860
	ctx.r3.s64 = ctx.r1.s64 + 10860;
	// bl 0x820602f0
	ctx.lr = 0x821992C8;
	sub_820602F0(ctx, base);
	// stw r17,10888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10888, ctx.r17.u32);
	// stw r31,10892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 10892, ctx.r31.u32);
	// addi r4,r30,9212
	ctx.r4.s64 = ctx.r30.s64 + 9212;
	// addi r3,r1,10896
	ctx.r3.s64 = ctx.r1.s64 + 10896;
	// bl 0x82060190
	ctx.lr = 0x821992DC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10924
	ctx.r3.s64 = ctx.r1.s64 + 10924;
	// bl 0x820602f0
	ctx.lr = 0x821992EC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10952
	ctx.r3.s64 = ctx.r1.s64 + 10952;
	// bl 0x820602f0
	ctx.lr = 0x821992FC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,10980
	ctx.r3.s64 = ctx.r1.s64 + 10980;
	// bl 0x820602f0
	ctx.lr = 0x8219930C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11008
	ctx.r3.s64 = ctx.r1.s64 + 11008;
	// bl 0x820602f0
	ctx.lr = 0x8219931C;
	sub_820602F0(ctx, base);
	// stw r18,11036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11036, ctx.r18.u32);
	// stw r31,11040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11040, ctx.r31.u32);
	// addi r4,r30,9236
	ctx.r4.s64 = ctx.r30.s64 + 9236;
	// addi r3,r1,11044
	ctx.r3.s64 = ctx.r1.s64 + 11044;
	// bl 0x82060190
	ctx.lr = 0x82199330;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11072
	ctx.r3.s64 = ctx.r1.s64 + 11072;
	// bl 0x820602f0
	ctx.lr = 0x82199340;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11100
	ctx.r3.s64 = ctx.r1.s64 + 11100;
	// bl 0x820602f0
	ctx.lr = 0x82199350;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11128
	ctx.r3.s64 = ctx.r1.s64 + 11128;
	// bl 0x820602f0
	ctx.lr = 0x82199360;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11156
	ctx.r3.s64 = ctx.r1.s64 + 11156;
	// bl 0x820602f0
	ctx.lr = 0x82199370;
	sub_820602F0(ctx, base);
	// stw r14,11184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11184, ctx.r14.u32);
	// stw r31,11188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11188, ctx.r31.u32);
	// addi r4,r30,9260
	ctx.r4.s64 = ctx.r30.s64 + 9260;
	// addi r3,r1,11192
	ctx.r3.s64 = ctx.r1.s64 + 11192;
	// bl 0x82060190
	ctx.lr = 0x82199384;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11220
	ctx.r3.s64 = ctx.r1.s64 + 11220;
	// bl 0x820602f0
	ctx.lr = 0x82199394;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11248
	ctx.r3.s64 = ctx.r1.s64 + 11248;
	// bl 0x820602f0
	ctx.lr = 0x821993A4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11276
	ctx.r3.s64 = ctx.r1.s64 + 11276;
	// bl 0x820602f0
	ctx.lr = 0x821993B4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11304
	ctx.r3.s64 = ctx.r1.s64 + 11304;
	// bl 0x820602f0
	ctx.lr = 0x821993C4;
	sub_820602F0(ctx, base);
	// li r29,13
	ctx.r29.s64 = 13;
	// stw r31,11336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11336, ctx.r31.u32);
	// addi r4,r30,9284
	ctx.r4.s64 = ctx.r30.s64 + 9284;
	// stw r29,11332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11332, ctx.r29.u32);
	// addi r3,r1,11340
	ctx.r3.s64 = ctx.r1.s64 + 11340;
	// bl 0x82060190
	ctx.lr = 0x821993DC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11368
	ctx.r3.s64 = ctx.r1.s64 + 11368;
	// bl 0x820602f0
	ctx.lr = 0x821993EC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11396
	ctx.r3.s64 = ctx.r1.s64 + 11396;
	// bl 0x820602f0
	ctx.lr = 0x821993FC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11424
	ctx.r3.s64 = ctx.r1.s64 + 11424;
	// bl 0x820602f0
	ctx.lr = 0x8219940C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11452
	ctx.r3.s64 = ctx.r1.s64 + 11452;
	// bl 0x820602f0
	ctx.lr = 0x8219941C;
	sub_820602F0(ctx, base);
	// stw r24,11480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11480, ctx.r24.u32);
	// stw r31,11484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11484, ctx.r31.u32);
	// addi r4,r30,9308
	ctx.r4.s64 = ctx.r30.s64 + 9308;
	// addi r3,r1,11488
	ctx.r3.s64 = ctx.r1.s64 + 11488;
	// bl 0x82060190
	ctx.lr = 0x82199430;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11516
	ctx.r3.s64 = ctx.r1.s64 + 11516;
	// bl 0x820602f0
	ctx.lr = 0x82199440;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11544
	ctx.r3.s64 = ctx.r1.s64 + 11544;
	// bl 0x820602f0
	ctx.lr = 0x82199450;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11572
	ctx.r3.s64 = ctx.r1.s64 + 11572;
	// bl 0x820602f0
	ctx.lr = 0x82199460;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11600
	ctx.r3.s64 = ctx.r1.s64 + 11600;
	// bl 0x820602f0
	ctx.lr = 0x82199470;
	sub_820602F0(ctx, base);
	// stw r15,11628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11628, ctx.r15.u32);
	// stw r31,11632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11632, ctx.r31.u32);
	// addi r4,r30,9332
	ctx.r4.s64 = ctx.r30.s64 + 9332;
	// addi r3,r1,11636
	ctx.r3.s64 = ctx.r1.s64 + 11636;
	// bl 0x82060190
	ctx.lr = 0x82199484;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11664
	ctx.r3.s64 = ctx.r1.s64 + 11664;
	// bl 0x820602f0
	ctx.lr = 0x82199494;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11692
	ctx.r3.s64 = ctx.r1.s64 + 11692;
	// bl 0x820602f0
	ctx.lr = 0x821994A4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11720
	ctx.r3.s64 = ctx.r1.s64 + 11720;
	// bl 0x820602f0
	ctx.lr = 0x821994B4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11748
	ctx.r3.s64 = ctx.r1.s64 + 11748;
	// bl 0x820602f0
	ctx.lr = 0x821994C4;
	sub_820602F0(ctx, base);
	// stw r25,11776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11776, ctx.r25.u32);
	// stw r31,11780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11780, ctx.r31.u32);
	// addi r4,r30,9356
	ctx.r4.s64 = ctx.r30.s64 + 9356;
	// addi r3,r1,11784
	ctx.r3.s64 = ctx.r1.s64 + 11784;
	// bl 0x82060190
	ctx.lr = 0x821994D8;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11812
	ctx.r3.s64 = ctx.r1.s64 + 11812;
	// bl 0x820602f0
	ctx.lr = 0x821994E8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11840
	ctx.r3.s64 = ctx.r1.s64 + 11840;
	// bl 0x820602f0
	ctx.lr = 0x821994F8;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11868
	ctx.r3.s64 = ctx.r1.s64 + 11868;
	// bl 0x820602f0
	ctx.lr = 0x82199508;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11896
	ctx.r3.s64 = ctx.r1.s64 + 11896;
	// bl 0x820602f0
	ctx.lr = 0x82199518;
	sub_820602F0(ctx, base);
	// stw r26,11924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11924, ctx.r26.u32);
	// stw r31,11928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 11928, ctx.r31.u32);
	// addi r4,r30,9380
	ctx.r4.s64 = ctx.r30.s64 + 9380;
	// addi r3,r1,11932
	ctx.r3.s64 = ctx.r1.s64 + 11932;
	// bl 0x82060190
	ctx.lr = 0x8219952C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11960
	ctx.r3.s64 = ctx.r1.s64 + 11960;
	// bl 0x820602f0
	ctx.lr = 0x8219953C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,11988
	ctx.r3.s64 = ctx.r1.s64 + 11988;
	// bl 0x820602f0
	ctx.lr = 0x8219954C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12016
	ctx.r3.s64 = ctx.r1.s64 + 12016;
	// bl 0x820602f0
	ctx.lr = 0x8219955C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,12044
	ctx.r3.s64 = ctx.r1.s64 + 12044;
	// bl 0x820602f0
	ctx.lr = 0x8219956C;
	sub_820602F0(ctx, base);
	// lwz r31,20100(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20100);
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r30,r31,368
	ctx.r30.s64 = ctx.r31.s64 + 368;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82199584;
	sub_8207DA20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821957a8
	ctx.lr = 0x8219958C;
	sub_821957A8(ctx, base);
	// lwz r31,360(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r11,196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821995b4
	if (ctx.cr6.eq) goto loc_821995B4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821995b4
	if (ctx.cr6.eq) goto loc_821995B4;
	// addi r4,r31,200
	ctx.r4.s64 = ctx.r31.s64 + 200;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x821995B4;
	sub_8207DAC0(ctx, base);
loc_821995B4:
	// lwz r11,196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r31,20100(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821995f4
	if (ctx.cr6.eq) goto loc_821995F4;
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821995D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x821995e8
	if (ctx.cr6.eq) goto loc_821995E8;
	// stw r17,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r17.u32);
	// b 0x821995ec
	goto loc_821995EC;
loc_821995E8:
	// stw r29,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r29.u32);
loc_821995EC:
	// li r11,-99
	ctx.r11.s64 = -99;
	// stw r11,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
loc_821995F4:
	// lwz r3,360(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82199608;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82199680
	if (ctx.cr6.eq) goto loc_82199680;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// ble cr6,0x82199650
	if (!ctx.cr6.gt) goto loc_82199650;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// bgt cr6,0x82199650
	if (ctx.cr6.gt) goto loc_82199650;
	// addic. r3,r31,312
	ctx.xer.ca = ctx.r31.u32 > 4294966983;
	ctx.r3.s64 = ctx.r31.s64 + 312;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82199634
	if (ctx.cr0.eq) goto loc_82199634;
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r4,r1,880
	ctx.r4.s64 = ctx.r1.s64 + 880;
	// bl 0x821b6bd0
	ctx.lr = 0x82199634;
	sub_821B6BD0(ctx, base);
loc_82199634:
	// li r5,15
	ctx.r5.s64 = 15;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r4,r1,12080
	ctx.r4.s64 = ctx.r1.s64 + 12080;
	// bl 0x821bcd20
	ctx.lr = 0x82199644;
	sub_821BCD20(ctx, base);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r4,r1,7184
	ctx.r4.s64 = ctx.r1.s64 + 7184;
	// b 0x821996ac
	goto loc_821996AC;
loc_82199650:
	// addic. r3,r31,312
	ctx.xer.ca = ctx.r31.u32 > 4294966983;
	ctx.r3.s64 = ctx.r31.s64 + 312;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82199664
	if (ctx.cr0.eq) goto loc_82199664;
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r4,r1,1920
	ctx.r4.s64 = ctx.r1.s64 + 1920;
	// bl 0x821b6bd0
	ctx.lr = 0x82199664;
	sub_821B6BD0(ctx, base);
loc_82199664:
	// li r5,15
	ctx.r5.s64 = 15;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r4,r1,14992
	ctx.r4.s64 = ctx.r1.s64 + 14992;
	// bl 0x821bcd20
	ctx.lr = 0x82199674;
	sub_821BCD20(ctx, base);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r4,r1,4960
	ctx.r4.s64 = ctx.r1.s64 + 4960;
	// b 0x821996ac
	goto loc_821996AC;
loc_82199680:
	// addic. r3,r31,312
	ctx.xer.ca = ctx.r31.u32 > 4294966983;
	ctx.r3.s64 = ctx.r31.s64 + 312;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82199694
	if (ctx.cr0.eq) goto loc_82199694;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,2960
	ctx.r4.s64 = ctx.r1.s64 + 2960;
	// bl 0x821b6bd0
	ctx.lr = 0x82199694;
	sub_821B6BD0(ctx, base);
loc_82199694:
	// li r5,18
	ctx.r5.s64 = 18;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r4,r1,13408
	ctx.r4.s64 = ctx.r1.s64 + 13408;
	// bl 0x821bcd20
	ctx.lr = 0x821996A4;
	sub_821BCD20(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r4,r1,9408
	ctx.r4.s64 = ctx.r1.s64 + 9408;
loc_821996AC:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x821996B4;
	sub_821BCC50(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r6,r11,19656
	ctx.r6.s64 = ctx.r11.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,9408
	ctx.r3.s64 = ctx.r1.s64 + 9408;
	// bl 0x82060818
	ctx.lr = 0x821996CC;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r6,r10,19288
	ctx.r6.s64 = ctx.r10.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,13408
	ctx.r3.s64 = ctx.r1.s64 + 13408;
	// bl 0x82060818
	ctx.lr = 0x821996E4;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r6,r9,19656
	ctx.r6.s64 = ctx.r9.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,7184
	ctx.r3.s64 = ctx.r1.s64 + 7184;
	// bl 0x82060818
	ctx.lr = 0x821996FC;
	sub_82060818(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r6,r8,19288
	ctx.r6.s64 = ctx.r8.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,12080
	ctx.r3.s64 = ctx.r1.s64 + 12080;
	// bl 0x82060818
	ctx.lr = 0x82199714;
	sub_82060818(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r6,r7,19656
	ctx.r6.s64 = ctx.r7.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,4960
	ctx.r3.s64 = ctx.r1.s64 + 4960;
	// bl 0x82060818
	ctx.lr = 0x8219972C;
	sub_82060818(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r6,r6,19288
	ctx.r6.s64 = ctx.r6.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,14992
	ctx.r3.s64 = ctx.r1.s64 + 14992;
	// bl 0x82060818
	ctx.lr = 0x82199744;
	sub_82060818(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r6,r4,28680
	ctx.r6.s64 = ctx.r4.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,2960
	ctx.r3.s64 = ctx.r1.s64 + 2960;
	// bl 0x82060818
	ctx.lr = 0x8219975C;
	sub_82060818(ctx, base);
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r6,r3,28680
	ctx.r6.s64 = ctx.r3.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// bl 0x82060818
	ctx.lr = 0x82199774;
	sub_82060818(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r6,r11,28680
	ctx.r6.s64 = ctx.r11.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,1920
	ctx.r3.s64 = ctx.r1.s64 + 1920;
	// bl 0x82060818
	ctx.lr = 0x8219978C;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r10,28680
	ctx.r6.s64 = ctx.r10.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,4480
	ctx.r3.s64 = ctx.r1.s64 + 4480;
	// bl 0x82060818
	ctx.lr = 0x821997A4;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r9,28680
	ctx.r6.s64 = ctx.r9.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,4800
	ctx.r3.s64 = ctx.r1.s64 + 4800;
	// bl 0x82060818
	ctx.lr = 0x821997BC;
	sub_82060818(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r6,r8,28680
	ctx.r6.s64 = ctx.r8.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,18320
	ctx.r3.s64 = ctx.r1.s64 + 18320;
	// bl 0x82060818
	ctx.lr = 0x821997D4;
	sub_82060818(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r6,r7,28680
	ctx.r6.s64 = ctx.r7.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,19120
	ctx.r3.s64 = ctx.r1.s64 + 19120;
	// bl 0x82060818
	ctx.lr = 0x821997EC;
	sub_82060818(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r6,r6,28680
	ctx.r6.s64 = ctx.r6.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,17600
	ctx.r3.s64 = ctx.r1.s64 + 17600;
	// bl 0x82060818
	ctx.lr = 0x82199804;
	sub_82060818(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r6,r4,28680
	ctx.r6.s64 = ctx.r4.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,16560
	ctx.r3.s64 = ctx.r1.s64 + 16560;
	// bl 0x82060818
	ctx.lr = 0x8219981C;
	sub_82060818(ctx, base);
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r3,28680
	ctx.r6.s64 = ctx.r3.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,4640
	ctx.r3.s64 = ctx.r1.s64 + 4640;
	// bl 0x82060818
	ctx.lr = 0x82199834;
	sub_82060818(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,28680
	ctx.r6.s64 = ctx.r11.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,17280
	ctx.r3.s64 = ctx.r1.s64 + 17280;
	// bl 0x82060818
	ctx.lr = 0x8219984C;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r10,28680
	ctx.r6.s64 = ctx.r10.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,16320
	ctx.r3.s64 = ctx.r1.s64 + 16320;
	// bl 0x82060818
	ctx.lr = 0x82199864;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r9,28680
	ctx.r6.s64 = ctx.r9.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,4240
	ctx.r3.s64 = ctx.r1.s64 + 4240;
	// bl 0x82060818
	ctx.lr = 0x8219987C;
	sub_82060818(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r6,r8,28680
	ctx.r6.s64 = ctx.r8.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x82199894;
	sub_82060818(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,20080
	ctx.r1.s64 = ctx.r1.s64 + 20080;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821998A0"))) PPC_WEAK_FUNC(sub_821998A0);
PPC_FUNC_IMPL(__imp__sub_821998A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821998AC"))) PPC_WEAK_FUNC(sub_821998AC);
PPC_FUNC_IMPL(__imp__sub_821998AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821998B0"))) PPC_WEAK_FUNC(sub_821998B0);
PPC_FUNC_IMPL(__imp__sub_821998B0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x821998cc
	if (ctx.cr6.lt) goto loc_821998CC;
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// addi r3,r11,364
	ctx.r3.s64 = ctx.r11.s64 + 364;
	// blr 
	return;
loc_821998CC:
	// addi r3,r11,360
	ctx.r3.s64 = ctx.r11.s64 + 360;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821998D4"))) PPC_WEAK_FUNC(sub_821998D4);
PPC_FUNC_IMPL(__imp__sub_821998D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821998D8"))) PPC_WEAK_FUNC(sub_821998D8);
PPC_FUNC_IMPL(__imp__sub_821998D8) {
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
	ctx.lr = 0x821998F8;
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

__attribute__((alias("__imp__sub_82199928"))) PPC_WEAK_FUNC(sub_82199928);
PPC_FUNC_IMPL(__imp__sub_82199928) {
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
	// bne cr6,0x82199950
	if (!ctx.cr6.eq) goto loc_82199950;
	// lwz r11,52(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x82199958
	goto loc_82199958;
loc_82199950:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82199958:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82199984
	if (ctx.cr6.eq) goto loc_82199984;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82199984
	if (ctx.cr6.eq) goto loc_82199984;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82199984:
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// addi r10,r11,-26408
	ctx.r10.s64 = ctx.r11.s64 + -26408;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82199994"))) PPC_WEAK_FUNC(sub_82199994);
PPC_FUNC_IMPL(__imp__sub_82199994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82199998"))) PPC_WEAK_FUNC(sub_82199998);
PPC_FUNC_IMPL(__imp__sub_82199998) {
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
	// bne cr6,0x82199a00
	if (!ctx.cr6.eq) goto loc_82199A00;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821999f0
	if (ctx.cr6.eq) goto loc_821999F0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x821999E0;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821999f0
	if (ctx.cr6.eq) goto loc_821999F0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_821999F0:
	// li r11,768
	ctx.r11.s64 = 768;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
loc_82199A00:
	// lis r11,-32230
	ctx.r11.s64 = -2112225280;
	// addi r10,r11,-26328
	ctx.r10.s64 = ctx.r11.s64 + -26328;
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

__attribute__((alias("__imp__sub_82199A24"))) PPC_WEAK_FUNC(sub_82199A24);
PPC_FUNC_IMPL(__imp__sub_82199A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82199A28"))) PPC_WEAK_FUNC(sub_82199A28);
PPC_FUNC_IMPL(__imp__sub_82199A28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r6,80
	ctx.r6.s64 = 80;
	// lwz r9,324(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// addi r10,r3,312
	ctx.r10.s64 = ctx.r3.s64 + 312;
	// li r8,0
	ctx.r8.s64 = 0;
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r5,r7,r6
	ctx.r5.s32 = ppc_divw(ctx.r7.s32, ctx.r6.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,-99
	ctx.r5.s64 = -99;
loc_82199A50:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r4,r11,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r9,r4,r6
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82199a6c
	if (ctx.cr6.lt) goto loc_82199A6C;
	// twi 31,r0,22
loc_82199A6C:
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82199a88
	if (ctx.cr6.lt) goto loc_82199A88;
	// bne cr6,0x82199aa0
	if (!ctx.cr6.eq) goto loc_82199AA0;
	// addi r11,r3,364
	ctx.r11.s64 = ctx.r3.s64 + 364;
	// b 0x82199a8c
	goto loc_82199A8C;
loc_82199A88:
	// addi r11,r3,360
	ctx.r11.s64 = ctx.r3.s64 + 360;
loc_82199A8C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82199aa0
	if (ctx.cr6.eq) goto loc_82199AA0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r5,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r5.u32);
	// stw r11,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r11.u32);
loc_82199AA0:
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r7,r7,80
	ctx.r7.s64 = ctx.r7.s64 + 80;
	// subf r4,r9,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw r11,r4,r6
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82199a50
	if (ctx.cr6.lt) goto loc_82199A50;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82199AC4"))) PPC_WEAK_FUNC(sub_82199AC4);
PPC_FUNC_IMPL(__imp__sub_82199AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82199AC8"))) PPC_WEAK_FUNC(sub_82199AC8);
PPC_FUNC_IMPL(__imp__sub_82199AC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82199AD0;
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
	// addi r9,r11,3600
	ctx.r9.s64 = ctx.r11.s64 + 3600;
	// addi r30,r10,-1408
	ctx.r30.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x82199AF8;
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
	ctx.lr = 0x82199B10;
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

__attribute__((alias("__imp__sub_82199B20"))) PPC_WEAK_FUNC(sub_82199B20);
PPC_FUNC_IMPL(__imp__sub_82199B20) {
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
	// addi r5,r8,-1396
	ctx.r5.s64 = ctx.r8.s64 + -1396;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r7,r7,840
	ctx.r7.s64 = ctx.r7.s64 + 840;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r6,r6,3600
	ctx.r6.s64 = ctx.r6.s64 + 3600;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
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
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// beq cr6,0x82199bb4
	if (ctx.cr6.eq) goto loc_82199BB4;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_82199BB4:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32230
	ctx.r10.s64 = -2112225280;
	// addi r9,r10,-26216
	ctx.r9.s64 = ctx.r10.s64 + -26216;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// lwz r6,52(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// stw r6,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82199BDC"))) PPC_WEAK_FUNC(sub_82199BDC);
PPC_FUNC_IMPL(__imp__sub_82199BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82199BE0"))) PPC_WEAK_FUNC(sub_82199BE0);
PPC_FUNC_IMPL(__imp__sub_82199BE0) {
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
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82199C04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x82199c64
	if (ctx.cr6.lt) goto loc_82199C64;
	// lwz r9,328(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// li r8,80
	ctx.r8.s64 = 80;
	// lwz r7,324(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// addi r11,r31,312
	ctx.r11.s64 = ctx.r31.s64 + 312;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// divw r5,r6,r8
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r8.s32);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x82199c64
	if (!ctx.cr6.lt) goto loc_82199C64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82199c4c
	if (ctx.cr6.lt) goto loc_82199C4C;
	// twi 31,r0,22
loc_82199C4C:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x82199c68
	goto loc_82199C68;
loc_82199C64:
	// li r11,-1
	ctx.r11.s64 = -1;
loc_82199C68:
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// stw r10,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r10.u32);
	// bne cr6,0x82199cec
	if (!ctx.cr6.eq) goto loc_82199CEC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82199cb8
	if (!ctx.cr6.eq) goto loc_82199CB8;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x821b52f0
	ctx.lr = 0x82199CA4;
	sub_821B52F0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821b52f0
	ctx.lr = 0x82199CB0;
	sub_821B52F0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82199cd0
	goto loc_82199CD0;
loc_82199CB8:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821b52f0
	ctx.lr = 0x82199CC0;
	sub_821B52F0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821b52f0
	ctx.lr = 0x82199CCC;
	sub_821B52F0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
loc_82199CD0:
	// stw r11,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// ld r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 336);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82199CEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82199CEC:
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

__attribute__((alias("__imp__sub_82199D00"))) PPC_WEAK_FUNC(sub_82199D00);
PPC_FUNC_IMPL(__imp__sub_82199D00) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,3504
	ctx.r10.s64 = ctx.r11.s64 + 3504;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82199D10"))) PPC_WEAK_FUNC(sub_82199D10);
PPC_FUNC_IMPL(__imp__sub_82199D10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82199D18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,312
	ctx.r3.s64 = ctx.r3.s64 + 312;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// bl 0x82063390
	ctx.lr = 0x82199D30;
	sub_82063390(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82199D48;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lwz r30,28(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// bne cr6,0x82199d98
	if (!ctx.cr6.eq) goto loc_82199D98;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_82199D58:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,360(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,23176
	ctx.r8.s64 = ctx.r9.s64 + 23176;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// lwz r6,364(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 364);
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
loc_82199D80:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82199d90
	if (ctx.cr6.eq) goto loc_82199D90;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_82199D90:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82199D98:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x82199d58
	if (ctx.cr6.eq) goto loc_82199D58;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// beq cr6,0x82199db4
	if (ctx.cr6.eq) goto loc_82199DB4;
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// beq cr6,0x82199d58
	if (ctx.cr6.eq) goto loc_82199D58;
	// b 0x82199d80
	goto loc_82199D80;
loc_82199DB4:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82199dcc
	if (ctx.cr6.eq) goto loc_82199DCC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x82199DCC;
	sub_821BC718(ctx, base);
loc_82199DCC:
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82079fd8
	ctx.lr = 0x82199DD4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82199de8
	if (ctx.cr6.eq) goto loc_82199DE8;
	// addi r4,r31,356
	ctx.r4.s64 = ctx.r31.s64 + 356;
	// bl 0x82199b20
	ctx.lr = 0x82199DE4;
	sub_82199B20(ctx, base);
	// b 0x82199dec
	goto loc_82199DEC;
loc_82199DE8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82199DEC:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,25256
	ctx.r6.s64 = ctx.r8.s64 + 25256;
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
	// b 0x82199d80
	goto loc_82199D80;
}

__attribute__((alias("__imp__sub_82199E18"))) PPC_WEAK_FUNC(sub_82199E18);
PPC_FUNC_IMPL(__imp__sub_82199E18) {
	PPC_FUNC_PROLOGUE();
	// b 0x821b6210
	sub_821B6210(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82199E1C"))) PPC_WEAK_FUNC(sub_82199E1C);
PPC_FUNC_IMPL(__imp__sub_82199E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82199E20"))) PPC_WEAK_FUNC(sub_82199E20);
PPC_FUNC_IMPL(__imp__sub_82199E20) {
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
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// bl 0x821b62d0
	ctx.lr = 0x82199E3C;
	sub_821B62D0(ctx, base);
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r8,328(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// li r9,80
	ctx.r9.s64 = 80;
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82199e60
	if (ctx.cr6.lt) goto loc_82199E60;
	// twi 31,r0,22
loc_82199E60:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82199e88
	if (ctx.cr6.lt) goto loc_82199E88;
	// bne cr6,0x82199e9c
	if (!ctx.cr6.eq) goto loc_82199E9C;
	// addi r11,r31,364
	ctx.r11.s64 = ctx.r31.s64 + 364;
	// b 0x82199e8c
	goto loc_82199E8C;
loc_82199E88:
	// addi r11,r31,360
	ctx.r11.s64 = ctx.r31.s64 + 360;
loc_82199E8C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82199e9c
	if (ctx.cr6.eq) goto loc_82199E9C;
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82199E9C:
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

__attribute__((alias("__imp__sub_82199EB0"))) PPC_WEAK_FUNC(sub_82199EB0);
PPC_FUNC_IMPL(__imp__sub_82199EB0) {
	PPC_FUNC_PROLOGUE();
	// b 0x821b6548
	sub_821B6548(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82199EB4"))) PPC_WEAK_FUNC(sub_82199EB4);
PPC_FUNC_IMPL(__imp__sub_82199EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82199EB8"))) PPC_WEAK_FUNC(sub_82199EB8);
PPC_FUNC_IMPL(__imp__sub_82199EB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82199EC0;
	__savegprlr_25(ctx, base);
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x821b6748
	ctx.lr = 0x82199ED4;
	sub_821B6748(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r9,r10,3504
	ctx.r9.s64 = ctx.r10.s64 + 3504;
	// addi r29,r11,31916
	ctx.r29.s64 = ctx.r11.s64 + 31916;
	// stw r9,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r29,-400
	ctx.r4.s64 = ctx.r29.s64 + -400;
	// addi r3,r27,220
	ctx.r3.s64 = ctx.r27.s64 + 220;
	// bl 0x82060368
	ctx.lr = 0x82199EF8;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r31.u32);
	// addi r4,r29,-472
	ctx.r4.s64 = ctx.r29.s64 + -472;
	// stb r31,484(r1)
	PPC_STORE_U8(ctx.r1.u32 + 484, ctx.r31.u8);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r30,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r30.u32);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x82060368
	ctx.lr = 0x82199F1C;
	sub_82060368(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// addi r10,r1,504
	ctx.r10.s64 = ctx.r1.s64 + 504;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82199F2C:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82199f2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82199F2C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82199F3C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82199f54
	if (ctx.cr6.eq) goto loc_82199F54;
	// addi r11,r1,536
	ctx.r11.s64 = ctx.r1.s64 + 536;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r3.u32);
	// b 0x82199f58
	goto loc_82199F58;
loc_82199F54:
	// stw r31,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r31.u32);
loc_82199F58:
	// stw r31,548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 548, ctx.r31.u32);
	// addi r4,r29,-392
	ctx.r4.s64 = ctx.r29.s64 + -392;
	// stw r31,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r31.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r31,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r31.u32);
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// stw r30,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r30.u32);
	// stw r31,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r31.u32);
	// stb r31,564(r1)
	PPC_STORE_U8(ctx.r1.u32 + 564, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82199F80;
	sub_82060368(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r1,584
	ctx.r11.s64 = ctx.r1.s64 + 584;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82199F90:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82199f90
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82199F90;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82199FA0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82199fb8
	if (ctx.cr6.eq) goto loc_82199FB8;
	// addi r11,r1,616
	ctx.r11.s64 = ctx.r1.s64 + 616;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// b 0x82199fbc
	goto loc_82199FBC;
loc_82199FB8:
	// stw r31,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r31.u32);
loc_82199FBC:
	// stw r31,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r31.u32);
	// addi r4,r29,-388
	ctx.r4.s64 = ctx.r29.s64 + -388;
	// stw r31,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r31.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r31,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x82199FE4;
	sub_82060368(ctx, base);
	// li r28,3
	ctx.r28.s64 = 3;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r31.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219A00C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219a024
	if (ctx.cr6.eq) goto loc_8219A024;
	// addi r11,r1,136
	ctx.r11.s64 = ctx.r1.s64 + 136;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// b 0x8219a028
	goto loc_8219A028;
loc_8219A024:
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
loc_8219A028:
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// bl 0x820669a0
	ctx.lr = 0x8219A03C;
	sub_820669A0(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x821b6bd0
	ctx.lr = 0x8219A04C;
	sub_821B6BD0(ctx, base);
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r30.u32);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// addi r4,r29,-368
	ctx.r4.s64 = ctx.r29.s64 + -368;
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r31.u8);
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82060368
	ctx.lr = 0x8219A068;
	sub_82060368(ctx, base);
	// li r25,1
	ctx.r25.s64 = 1;
	// stw r31,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r25,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r25.u32);
	// stw r28,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r28.u32);
	// stw r31,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r31.u32);
	// stw r31,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r31.u32);
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stw r31,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219A090;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219a0a8
	if (ctx.cr6.eq) goto loc_8219A0A8;
	// addi r11,r1,216
	ctx.r11.s64 = ctx.r1.s64 + 216;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// b 0x8219a0ac
	goto loc_8219A0AC;
loc_8219A0A8:
	// stw r31,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r31.u32);
loc_8219A0AC:
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r31.u32);
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// stw r31,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r31.u32);
	// stw r31,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r31.u32);
	// bl 0x820669a0
	ctx.lr = 0x8219A0C0;
	sub_820669A0(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x821b6bd0
	ctx.lr = 0x8219A0D0;
	sub_821B6BD0(ctx, base);
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r30.u32);
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r31.u32);
	// addi r4,r29,-348
	ctx.r4.s64 = ctx.r29.s64 + -348;
	// stb r31,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, ctx.r31.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82060368
	ctx.lr = 0x8219A0EC;
	sub_82060368(ctx, base);
	// addi r11,r1,280
	ctx.r11.s64 = ctx.r1.s64 + 280;
	// li r26,2
	ctx.r26.s64 = 2;
	// stw r31,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r31.u32);
	// stw r31,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r26,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r26.u32);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// bl 0x82079fd8
	ctx.lr = 0x8219A110;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219a128
	if (ctx.cr6.eq) goto loc_8219A128;
	// addi r11,r1,296
	ctx.r11.s64 = ctx.r1.s64 + 296;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// b 0x8219a12c
	goto loc_8219A12C;
loc_8219A128:
	// stw r31,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r31.u32);
loc_8219A12C:
	// stw r31,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r31.u32);
	// addi r4,r29,-328
	ctx.r4.s64 = ctx.r29.s64 + -328;
	// stw r31,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r31.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r31,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r31.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stw r30,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r30.u32);
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r31.u32);
	// stb r31,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A154;
	sub_82060368(ctx, base);
	// li r11,-199
	ctx.r11.s64 = -199;
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r31,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r31.u32);
	// stw r11,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r11.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r31.u32);
	// stw r10,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r10.u32);
	// stw r31,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r31.u32);
	// stw r31,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r31.u32);
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219A180;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219a198
	if (ctx.cr6.eq) goto loc_8219A198;
	// addi r11,r1,376
	ctx.r11.s64 = ctx.r1.s64 + 376;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r3.u32);
	// b 0x8219a19c
	goto loc_8219A19C;
loc_8219A198:
	// stw r31,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r31.u32);
loc_8219A19C:
	// stw r31,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r31.u32);
	// addi r4,r29,-320
	ctx.r4.s64 = ctx.r29.s64 + -320;
	// stw r31,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r31.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r31,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r31.u32);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// stw r30,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r30.u32);
	// stw r31,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r31.u32);
	// stb r31,404(r1)
	PPC_STORE_U8(ctx.r1.u32 + 404, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A1C4;
	sub_82060368(ctx, base);
	// addi r11,r1,440
	ctx.r11.s64 = ctx.r1.s64 + 440;
	// stw r28,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r28.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r31.u32);
	// stw r31,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, ctx.r31.u32);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// bl 0x82079fd8
	ctx.lr = 0x8219A1E4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219a1fc
	if (ctx.cr6.eq) goto loc_8219A1FC;
	// addi r11,r1,456
	ctx.r11.s64 = ctx.r1.s64 + 456;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// b 0x8219a200
	goto loc_8219A200;
loc_8219A1FC:
	// stw r31,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r31.u32);
loc_8219A200:
	// stw r31,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r31.u32);
	// addi r4,r29,-312
	ctx.r4.s64 = ctx.r29.s64 + -312;
	// stw r31,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r31.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r31,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r31.u32);
	// addi r3,r1,644
	ctx.r3.s64 = ctx.r1.s64 + 644;
	// stw r31,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, ctx.r31.u32);
	// stw r30,668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 668, ctx.r30.u32);
	// stw r31,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r31.u32);
	// stb r31,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A22C;
	sub_82060368(ctx, base);
	// stw r30,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r30.u32);
	// stw r31,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, ctx.r31.u32);
	// addi r4,r29,-280
	ctx.r4.s64 = ctx.r29.s64 + -280;
	// stb r31,676(r1)
	PPC_STORE_U8(ctx.r1.u32 + 676, ctx.r31.u8);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// bl 0x82060368
	ctx.lr = 0x8219A248;
	sub_82060368(ctx, base);
	// stw r30,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r30.u32);
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r31.u32);
	// addi r4,r29,-240
	ctx.r4.s64 = ctx.r29.s64 + -240;
	// stb r31,704(r1)
	PPC_STORE_U8(ctx.r1.u32 + 704, ctx.r31.u8);
	// li r5,30
	ctx.r5.s64 = 30;
	// stw r25,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, ctx.r25.u32);
	// addi r3,r1,732
	ctx.r3.s64 = ctx.r1.s64 + 732;
	// stw r30,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r30.u32);
	// stw r31,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r31.u32);
	// stb r31,736(r1)
	PPC_STORE_U8(ctx.r1.u32 + 736, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A274;
	sub_82060368(ctx, base);
	// stw r30,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, ctx.r30.u32);
	// stw r31,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r31.u32);
	// addi r4,r29,-208
	ctx.r4.s64 = ctx.r29.s64 + -208;
	// stb r31,764(r1)
	PPC_STORE_U8(ctx.r1.u32 + 764, ctx.r31.u8);
	// li r5,38
	ctx.r5.s64 = 38;
	// addi r3,r1,760
	ctx.r3.s64 = ctx.r1.s64 + 760;
	// bl 0x82060368
	ctx.lr = 0x8219A290;
	sub_82060368(ctx, base);
	// stw r30,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r30.u32);
	// stw r31,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r31.u32);
	// addi r4,r29,-168
	ctx.r4.s64 = ctx.r29.s64 + -168;
	// stb r31,792(r1)
	PPC_STORE_U8(ctx.r1.u32 + 792, ctx.r31.u8);
	// li r5,26
	ctx.r5.s64 = 26;
	// stw r26,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, ctx.r26.u32);
	// addi r3,r1,820
	ctx.r3.s64 = ctx.r1.s64 + 820;
	// stw r30,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r30.u32);
	// stw r31,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r31.u32);
	// stb r31,824(r1)
	PPC_STORE_U8(ctx.r1.u32 + 824, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A2BC;
	sub_82060368(ctx, base);
	// stw r30,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r30.u32);
	// stw r31,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r31.u32);
	// addi r4,r29,-140
	ctx.r4.s64 = ctx.r29.s64 + -140;
	// stb r31,852(r1)
	PPC_STORE_U8(ctx.r1.u32 + 852, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r30,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, ctx.r30.u32);
	// addi r3,r1,908
	ctx.r3.s64 = ctx.r1.s64 + 908;
	// stw r31,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r31.u32);
	// stb r31,880(r1)
	PPC_STORE_U8(ctx.r1.u32 + 880, ctx.r31.u8);
	// stw r28,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, ctx.r28.u32);
	// stw r30,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r30.u32);
	// stw r31,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r31.u32);
	// stb r31,912(r1)
	PPC_STORE_U8(ctx.r1.u32 + 912, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A2F4;
	sub_82060368(ctx, base);
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r30.u32);
	// stw r31,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, ctx.r31.u32);
	// addi r4,r29,-116
	ctx.r4.s64 = ctx.r29.s64 + -116;
	// stb r31,940(r1)
	PPC_STORE_U8(ctx.r1.u32 + 940, ctx.r31.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// stw r30,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r30.u32);
	// addi r3,r1,1000
	ctx.r3.s64 = ctx.r1.s64 + 1000;
	// stw r31,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r31.u32);
	// stb r31,968(r1)
	PPC_STORE_U8(ctx.r1.u32 + 968, ctx.r31.u8);
	// stw r31,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r31.u32);
	// stw r31,996(r1)
	PPC_STORE_U32(ctx.r1.u32 + 996, ctx.r31.u32);
	// stw r30,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, ctx.r30.u32);
	// stw r31,1020(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1020, ctx.r31.u32);
	// stb r31,1004(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1004, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A330;
	sub_82060368(ctx, base);
	// stw r30,1052(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1052, ctx.r30.u32);
	// stw r31,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, ctx.r31.u32);
	// addi r4,r29,-96
	ctx.r4.s64 = ctx.r29.s64 + -96;
	// stb r31,1032(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1032, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1028
	ctx.r3.s64 = ctx.r1.s64 + 1028;
	// bl 0x82060368
	ctx.lr = 0x8219A34C;
	sub_82060368(ctx, base);
	// stw r30,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, ctx.r30.u32);
	// stw r31,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r31.u32);
	// addi r4,r29,-72
	ctx.r4.s64 = ctx.r29.s64 + -72;
	// stb r31,1060(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1060, ctx.r31.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// stw r30,1108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1108, ctx.r30.u32);
	// addi r3,r1,1148
	ctx.r3.s64 = ctx.r1.s64 + 1148;
	// stw r31,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r31.u32);
	// stb r31,1088(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1088, ctx.r31.u8);
	// stw r30,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r30.u32);
	// stw r31,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r31.u32);
	// stb r31,1116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1116, ctx.r31.u8);
	// stw r25,1140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1140, ctx.r25.u32);
	// stw r31,1144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1144, ctx.r31.u32);
	// stw r30,1172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1172, ctx.r30.u32);
	// stw r31,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r31.u32);
	// stb r31,1152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1152, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A394;
	sub_82060368(ctx, base);
	// stw r30,1200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1200, ctx.r30.u32);
	// stw r31,1196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1196, ctx.r31.u32);
	// addi r4,r29,-52
	ctx.r4.s64 = ctx.r29.s64 + -52;
	// stb r31,1180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1180, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1176
	ctx.r3.s64 = ctx.r1.s64 + 1176;
	// bl 0x82060368
	ctx.lr = 0x8219A3B0;
	sub_82060368(ctx, base);
	// stw r30,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r30.u32);
	// stw r31,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, ctx.r31.u32);
	// addi r4,r29,-28
	ctx.r4.s64 = ctx.r29.s64 + -28;
	// stb r31,1208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1208, ctx.r31.u8);
	// li r5,26
	ctx.r5.s64 = 26;
	// stw r30,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, ctx.r30.u32);
	// addi r3,r1,1296
	ctx.r3.s64 = ctx.r1.s64 + 1296;
	// stw r31,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, ctx.r31.u32);
	// stb r31,1236(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1236, ctx.r31.u8);
	// stw r30,1284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1284, ctx.r30.u32);
	// stw r31,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, ctx.r31.u32);
	// stb r31,1264(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1264, ctx.r31.u8);
	// stw r26,1288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1288, ctx.r26.u32);
	// stw r31,1292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1292, ctx.r31.u32);
	// stw r30,1320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1320, ctx.r30.u32);
	// stw r31,1316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1316, ctx.r31.u32);
	// stb r31,1300(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1300, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219A3F8;
	sub_82060368(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1324
	ctx.r3.s64 = ctx.r1.s64 + 1324;
	// bl 0x820602f0
	ctx.lr = 0x8219A408;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1352
	ctx.r3.s64 = ctx.r1.s64 + 1352;
	// bl 0x820602f0
	ctx.lr = 0x8219A418;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1380
	ctx.r3.s64 = ctx.r1.s64 + 1380;
	// bl 0x820602f0
	ctx.lr = 0x8219A428;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1408
	ctx.r3.s64 = ctx.r1.s64 + 1408;
	// bl 0x820602f0
	ctx.lr = 0x8219A438;
	sub_820602F0(ctx, base);
	// stw r28,1436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1436, ctx.r28.u32);
	// stw r31,1440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1440, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,1444
	ctx.r3.s64 = ctx.r1.s64 + 1444;
	// bl 0x82060190
	ctx.lr = 0x8219A44C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1472
	ctx.r3.s64 = ctx.r1.s64 + 1472;
	// bl 0x820602f0
	ctx.lr = 0x8219A45C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1500
	ctx.r3.s64 = ctx.r1.s64 + 1500;
	// bl 0x820602f0
	ctx.lr = 0x8219A46C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1528
	ctx.r3.s64 = ctx.r1.s64 + 1528;
	// bl 0x820602f0
	ctx.lr = 0x8219A47C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1556
	ctx.r3.s64 = ctx.r1.s64 + 1556;
	// bl 0x820602f0
	ctx.lr = 0x8219A48C;
	sub_820602F0(ctx, base);
	// addic. r3,r27,312
	ctx.xer.ca = ctx.r27.u32 > 4294966983;
	ctx.r3.s64 = ctx.r27.s64 + 312;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8219a4a0
	if (ctx.cr0.eq) goto loc_8219A4A0;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821b6bd0
	ctx.lr = 0x8219A4A0;
	sub_821B6BD0(ctx, base);
loc_8219A4A0:
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,128(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 128);
	// addi r4,r1,640
	ctx.r4.s64 = ctx.r1.s64 + 640;
	// bl 0x821bcd20
	ctx.lr = 0x8219A4B0;
	sub_821BCD20(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,992
	ctx.r4.s64 = ctx.r1.s64 + 992;
	// lwz r3,128(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x8219A4C0;
	sub_821BCC50(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,360(r27)
	PPC_STORE_U32(ctx.r27.u32 + 360, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 364, ctx.r8.u32);
	// bl 0x82199a28
	ctx.lr = 0x8219A4E4;
	sub_82199A28(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lwz r11,-31352(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -31352);
	// lwz r6,76(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r5,84(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	// lwz r4,52(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r4,368(r27)
	PPC_STORE_U32(ctx.r27.u32 + 368, ctx.r4.u32);
	// bne cr6,0x8219a520
	if (!ctx.cr6.eq) goto loc_8219A520;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821b52f0
	ctx.lr = 0x8219A510;
	sub_821B52F0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821b52f0
	ctx.lr = 0x8219A51C;
	sub_821B52F0(ctx, base);
	// stw r26,336(r27)
	PPC_STORE_U32(ctx.r27.u32 + 336, ctx.r26.u32);
loc_8219A520:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,19656
	ctx.r6.s64 = ctx.r11.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,992
	ctx.r3.s64 = ctx.r1.s64 + 992;
	// bl 0x82060818
	ctx.lr = 0x8219A538;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r10,19288
	ctx.r6.s64 = ctx.r10.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x82060818
	ctx.lr = 0x8219A550;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r6,r9,28680
	ctx.r6.s64 = ctx.r9.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x8219A568;
	sub_82060818(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r8,28680
	ctx.r6.s64 = ctx.r8.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x82060818
	ctx.lr = 0x8219A580;
	sub_82060818(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219A58C"))) PPC_WEAK_FUNC(sub_8219A58C);
PPC_FUNC_IMPL(__imp__sub_8219A58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219A590"))) PPC_WEAK_FUNC(sub_8219A590);
PPC_FUNC_IMPL(__imp__sub_8219A590) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8219A5A0"))) PPC_WEAK_FUNC(sub_8219A5A0);
PPC_FUNC_IMPL(__imp__sub_8219A5A0) {
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,196(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,-2064
	ctx.r30.s64 = ctx.r11.s64 + -2064;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f30,60(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f30.f64 = double(temp.f32);
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219A5E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,292(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,12(r8)
	PPC_STORE_U8(ctx.r8.u32 + 12, ctx.r11.u8);
	// lwz r7,296(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// stb r11,12(r7)
	PPC_STORE_U8(ctx.r7.u32 + 12, ctx.r11.u8);
	// lwz r9,-31352(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// lwz r6,76(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a640
	if (ctx.cr6.lt) goto loc_8219A640;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a640
	if (ctx.cr6.gt) goto loc_8219A640;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r8,r10,0,17,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8219a640
	if (ctx.cr6.eq) goto loc_8219A640;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f31,-19612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19612);
	ctx.f31.f64 = double(temp.f32);
loc_8219A640:
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a678
	if (ctx.cr6.lt) goto loc_8219A678;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a678
	if (ctx.cr6.gt) goto loc_8219A678;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r8,r10,0,16,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8219a678
	if (ctx.cr6.eq) goto loc_8219A678;
	// fmuls f31,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f30.f64));
loc_8219A678:
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a6b8
	if (ctx.cr6.lt) goto loc_8219A6B8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a6b8
	if (ctx.cr6.gt) goto loc_8219A6B8;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r8,r10,0,13,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8219a6b8
	if (ctx.cr6.eq) goto loc_8219A6B8;
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f13,280(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
loc_8219A6B8:
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a6f8
	if (ctx.cr6.lt) goto loc_8219A6F8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a6f8
	if (ctx.cr6.gt) goto loc_8219A6F8;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r8,r10,0,12,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8219a6f8
	if (ctx.cr6.eq) goto loc_8219A6F8;
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,280(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
loc_8219A6F8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8219a71c
	if (ctx.cr6.gt) goto loc_8219A71C;
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// stfs f0,280(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// stb r8,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
loc_8219A71C:
	// lwz r11,248(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// lfs f0,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// subf r7,r10,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r10.s64;
	// lfs f12,280(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r31,232
	ctx.r11.s64 = ctx.r31.s64 + 232;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// clrldi r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmsubs f8,f9,f13,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 - ctx.f0.f64));
	// fcmpu cr6,f12,f8
	ctx.cr6.compare(ctx.f12.f64, ctx.f8.f64);
	// blt cr6,0x8219a798
	if (ctx.cr6.lt) goto loc_8219A798;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,296(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// subf r5,r7,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r7.s64;
	// srawi r4,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 2;
	// clrldi r3,r4,32
	ctx.r3.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmsubs f9,f10,f13,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 - ctx.f0.f64));
	// stfs f9,280(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// stb r8,12(r6)
	PPC_STORE_U8(ctx.r6.u32 + 12, ctx.r8.u8);
loc_8219A798:
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a814
	if (ctx.cr6.lt) goto loc_8219A814;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a814
	if (ctx.cr6.gt) goto loc_8219A814;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// clrlwi r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8219a814
	if (ctx.cr6.eq) goto loc_8219A814;
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a800
	if (ctx.cr6.lt) goto loc_8219A800;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a800
	if (ctx.cr6.gt) goto loc_8219A800;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r9,r10,0,12,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC0000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8219a814
	if (!ctx.cr6.eq) goto loc_8219A814;
loc_8219A800:
	// stb r8,300(r31)
	PPC_STORE_U8(ctx.r31.u32 + 300, ctx.r8.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// bl 0x821bb9b0
	ctx.lr = 0x8219A814;
	sub_821BB9B0(ctx, base);
loc_8219A814:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
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

__attribute__((alias("__imp__sub_8219A834"))) PPC_WEAK_FUNC(sub_8219A834);
PPC_FUNC_IMPL(__imp__sub_8219A834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219A838"))) PPC_WEAK_FUNC(sub_8219A838);
PPC_FUNC_IMPL(__imp__sub_8219A838) {
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
	// lwz r4,196(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f30,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f30.f64 = double(temp.f32);
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8219A878;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r6,292(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lwz r7,-31352(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31352);
	// stb r10,12(r6)
	PPC_STORE_U8(ctx.r6.u32 + 12, ctx.r10.u8);
	// lwz r5,296(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// stb r10,12(r5)
	PPC_STORE_U8(ctx.r5.u32 + 12, ctx.r10.u8);
	// lwz r4,76(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r10,80(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219a8d4
	if (ctx.cr6.lt) goto loc_8219A8D4;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219a8d4
	if (ctx.cr6.gt) goto loc_8219A8D4;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8219a8d4
	if (ctx.cr6.eq) goto loc_8219A8D4;
	// lfs f31,96(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	ctx.f31.f64 = double(temp.f32);
loc_8219A8D4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x8219aa44
	if (ctx.cr6.eq) goto loc_8219AA44;
	// lfs f11,184(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
	// ble cr6,0x8219a920
	if (!ctx.cr6.gt) goto loc_8219A920;
	// lfs f12,188(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f13,f31,f12,f13
	ctx.f13.f64 = double(float(-(ctx.f31.f64 * ctx.f12.f64 - ctx.f13.f64)));
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8219a910
	if (!ctx.cr6.lt) goto loc_8219A910;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_8219A910:
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(ctx.f30.f64 - ctx.f13.f64));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// b 0x8219a960
	goto loc_8219A960;
loc_8219A920:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8219a960
	if (!ctx.cr6.lt) goto loc_8219A960;
	// lfs f12,304(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,188(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f31,f13,f12
	ctx.f10.f64 = double(float(ctx.f31.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f10,304(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x8219a944
	if (!ctx.cr6.gt) goto loc_8219A944;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_8219A944:
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bne cr6,0x8219a960
	if (!ctx.cr6.eq) goto loc_8219A960;
	// stfs f0,280(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// stfs f30,304(r31)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_8219A960:
	// lwz r11,244(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// addi r6,r31,232
	ctx.r6.s64 = ctx.r31.s64 + 232;
	// lwz r10,248(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219a978
	if (!ctx.cr6.gt) goto loc_8219A978;
	// twi 31,r0,22
loc_8219A978:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_8219A980:
	// lwz r10,16(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lwz r11,12(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219a994
	if (!ctx.cr6.gt) goto loc_8219A994;
	// twi 31,r0,22
loc_8219A994:
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8219a9a8
	if (ctx.cr6.eq) goto loc_8219A9A8;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8219a9ac
	if (ctx.cr6.eq) goto loc_8219A9AC;
loc_8219A9A8:
	// twi 31,r0,22
loc_8219A9AC:
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8219aac8
	if (!ctx.cr6.lt) goto loc_8219AAC8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8219aa34
	if (!ctx.cr6.eq) goto loc_8219AA34;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_8219A9C4:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219a9d4
	if (ctx.cr6.lt) goto loc_8219A9D4;
	// twi 31,r0,22
loc_8219A9D4:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8219a9f4
	if (ctx.cr6.eq) goto loc_8219A9F4;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x8219aa0c
	if (!ctx.cr6.eq) goto loc_8219AA0C;
loc_8219A9F4:
	// rlwinm r10,r10,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// fctidz f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// or r4,r10,r5
	ctx.r4.u64 = ctx.r10.u64 | ctx.r5.u64;
	// stw r4,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r4.u32);
loc_8219AA0C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8219aa3c
	if (!ctx.cr6.eq) goto loc_8219AA3C;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_8219AA1C:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219aa2c
	if (ctx.cr6.lt) goto loc_8219AA2C;
	// twi 31,r0,22
loc_8219AA2C:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// b 0x8219a980
	goto loc_8219A980;
loc_8219AA34:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8219a9c4
	goto loc_8219A9C4;
loc_8219AA3C:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8219aa1c
	goto loc_8219AA1C;
loc_8219AA44:
	// lfs f13,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r31,232
	ctx.r6.s64 = ctx.r31.s64 + 232;
	// fadds f11,f13,f31
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfs f11,280(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f10,156(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f10.f64 = double(temp.f32);
	// lwz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r5,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 2;
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f12,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// clrldi r4,r5,32
	ctx.r4.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmsubs f6,f7,f12,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 - ctx.f13.f64));
	// fcmpu cr6,f11,f6
	ctx.cr6.compare(ctx.f11.f64, ctx.f6.f64);
	// blt cr6,0x8219aac8
	if (ctx.cr6.lt) goto loc_8219AAC8;
	// lwz r11,16(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lfs f11,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// lwz r10,12(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stfs f11,304(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// clrldi r5,r8,32
	ctx.r5.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmsubs f8,f9,f12,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f13.f64));
	// stfs f8,280(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
loc_8219AAC8:
	// lwz r11,76(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219ac10
	if (ctx.cr6.lt) goto loc_8219AC10;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219ac10
	if (ctx.cr6.gt) goto loc_8219AC10;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r9,r10,0,12,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC0000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8219ac10
	if (ctx.cr6.eq) goto loc_8219AC10;
	// lwz r11,76(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219ab30
	if (ctx.cr6.lt) goto loc_8219AB30;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219ab30
	if (ctx.cr6.gt) goto loc_8219AB30;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8219ac10
	if (!ctx.cr6.eq) goto loc_8219AC10;
loc_8219AB30:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r11,300(r31)
	PPC_STORE_U8(ctx.r31.u32 + 300, ctx.r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bb9b0
	ctx.lr = 0x8219AB48;
	sub_821BB9B0(ctx, base);
	// stfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// lwz r11,12(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r10,16(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219ab60
	if (!ctx.cr6.gt) goto loc_8219AB60;
	// twi 31,r0,22
loc_8219AB60:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_8219AB68:
	// lwz r10,16(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lwz r11,12(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219ab7c
	if (!ctx.cr6.gt) goto loc_8219AB7C;
	// twi 31,r0,22
loc_8219AB7C:
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8219ab90
	if (ctx.cr6.eq) goto loc_8219AB90;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8219ab94
	if (ctx.cr6.eq) goto loc_8219AB94;
loc_8219AB90:
	// twi 31,r0,22
loc_8219AB94:
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8219ac10
	if (!ctx.cr6.lt) goto loc_8219AC10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8219ac00
	if (!ctx.cr6.eq) goto loc_8219AC00;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_8219ABAC:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219abbc
	if (ctx.cr6.lt) goto loc_8219ABBC;
	// twi 31,r0,22
loc_8219ABBC:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8219abd8
	if (!ctx.cr6.eq) goto loc_8219ABD8;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// ori r7,r10,255
	ctx.r7.u64 = ctx.r10.u64 | 255;
	// stw r7,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r7.u32);
loc_8219ABD8:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8219ac08
	if (!ctx.cr6.eq) goto loc_8219AC08;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_8219ABE8:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219abf8
	if (ctx.cr6.lt) goto loc_8219ABF8;
	// twi 31,r0,22
loc_8219ABF8:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// b 0x8219ab68
	goto loc_8219AB68;
loc_8219AC00:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8219abac
	goto loc_8219ABAC;
loc_8219AC08:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8219abe8
	goto loc_8219ABE8;
loc_8219AC10:
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

__attribute__((alias("__imp__sub_8219AC2C"))) PPC_WEAK_FUNC(sub_8219AC2C);
PPC_FUNC_IMPL(__imp__sub_8219AC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219AC30"))) PPC_WEAK_FUNC(sub_8219AC30);
PPC_FUNC_IMPL(__imp__sub_8219AC30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8219AC38;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82080368
	ctx.lr = 0x8219AC40;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,196(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219AC60;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,156(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,248(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 248);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// addi r27,r28,232
	ctx.r27.s64 = ctx.r28.s64 + 232;
	// lfs f0,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// lwz r11,244(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 244);
	// fsubs f30,f12,f10
	ctx.f30.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// fsubs f29,f9,f13
	ctx.f29.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// ble cr6,0x8219aca0
	if (!ctx.cr6.gt) goto loc_8219ACA0;
	// twi 31,r0,22
loc_8219ACA0:
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// lwz r29,0(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f31,184(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	ctx.f31.f64 = double(temp.f32);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r25,1
	ctx.r25.s64 = 1;
	// lfs f28,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f28.f64 = double(temp.f32);
loc_8219ACBC:
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219acd0
	if (!ctx.cr6.gt) goto loc_8219ACD0;
	// twi 31,r0,22
loc_8219ACD0:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8219ace4
	if (ctx.cr6.eq) goto loc_8219ACE4;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8219ace8
	if (ctx.cr6.eq) goto loc_8219ACE8;
loc_8219ACE4:
	// twi 31,r0,22
loc_8219ACE8:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8219ae00
	if (!ctx.cr6.lt) goto loc_8219AE00;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8219ad78
	if (!ctx.cr6.eq) goto loc_8219AD78;
	// twi 31,r0,22
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8219AD00:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219ad10
	if (ctx.cr6.lt) goto loc_8219AD10;
	// twi 31,r0,22
loc_8219AD10:
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219AD2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,280(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,284(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8219AD5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x8219ad80
	if (!ctx.cr6.lt) goto loc_8219AD80;
	// fsubs f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// b 0x8219ad8c
	goto loc_8219AD8C;
loc_8219AD78:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8219ad00
	goto loc_8219AD00;
loc_8219AD80:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// ble cr6,0x8219ada8
	if (!ctx.cr6.gt) goto loc_8219ADA8;
	// fsubs f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
loc_8219AD8C:
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fnmsubs f13,f12,f31,f31
	ctx.f13.f64 = double(float(-(ctx.f12.f64 * ctx.f31.f64 - ctx.f31.f64)));
	// fcmpu cr6,f13,f28
	ctx.cr6.compare(ctx.f13.f64, ctx.f28.f64);
	// bge cr6,0x8219ada8
	if (!ctx.cr6.lt) goto loc_8219ADA8;
	// stb r25,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r25.u8);
	// b 0x8219add0
	goto loc_8219ADD0;
loc_8219ADA8:
	// lfs f0,304(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bne cr6,0x8219adcc
	if (!ctx.cr6.eq) goto loc_8219ADCC;
	// rlwinm r11,r11,0,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF00;
	// fctidz f0,f13
	ctx.f0.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r10,103(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
loc_8219ADCC:
	// stb r26,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r26.u8);
loc_8219ADD0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8219adf8
	if (!ctx.cr6.eq) goto loc_8219ADF8;
	// twi 31,r0,22
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8219ADE0:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219adf0
	if (ctx.cr6.lt) goto loc_8219ADF0;
	// twi 31,r0,22
loc_8219ADF0:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// b 0x8219acbc
	goto loc_8219ACBC;
loc_8219ADF8:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8219ade0
	goto loc_8219ADE0;
loc_8219AE00:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x820803b4
	ctx.lr = 0x8219AE0C;
	__restfpr_28(ctx, base);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219AE10"))) PPC_WEAK_FUNC(sub_8219AE10);
PPC_FUNC_IMPL(__imp__sub_8219AE10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8219AE18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,196(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,3400
	ctx.r10.s64 = ctx.r11.s64 + 3400;
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8219ae4c
	if (ctx.cr6.eq) goto loc_8219AE4C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219AE4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8219AE4C:
	// lwz r3,204(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 204);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219ae6c
	if (ctx.cr6.eq) goto loc_8219AE6C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219AE6C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8219AE6C:
	// lwz r3,268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 268);
	// addi r31,r29,256
	ctx.r31.s64 = ctx.r29.s64 + 256;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219ae8c
	if (ctx.cr6.eq) goto loc_8219AE8C;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x820694f8
	ctx.lr = 0x8219AE84;
	sub_820694F8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x8219AE8C;
	sub_8207A630(ctx, base);
loc_8219AE8C:
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// bl 0x8207a630
	ctx.lr = 0x8219AEA4;
	sub_8207A630(ctx, base);
	// lwz r3,244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 244);
	// addi r31,r29,232
	ctx.r31.s64 = ctx.r29.s64 + 232;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219aeb8
	if (ctx.cr6.eq) goto loc_8219AEB8;
	// bl 0x8207a630
	ctx.lr = 0x8219AEB8;
	sub_8207A630(ctx, base);
loc_8219AEB8:
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8219AECC;
	sub_8207A630(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821be788
	ctx.lr = 0x8219AED4;
	sub_821BE788(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219AEDC"))) PPC_WEAK_FUNC(sub_8219AEDC);
PPC_FUNC_IMPL(__imp__sub_8219AEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219AEE0"))) PPC_WEAK_FUNC(sub_8219AEE0);
PPC_FUNC_IMPL(__imp__sub_8219AEE0) {
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
	// lbz r11,300(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 300);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219af08
	if (ctx.cr6.eq) goto loc_8219AF08;
	// bl 0x8219a838
	ctx.lr = 0x8219AF04;
	sub_8219A838(ctx, base);
	// b 0x8219af0c
	goto loc_8219AF0C;
loc_8219AF08:
	// bl 0x8219a5a0
	ctx.lr = 0x8219AF0C;
	sub_8219A5A0(ctx, base);
loc_8219AF0C:
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,284(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// beq cr6,0x8219af3c
	if (ctx.cr6.eq) goto loc_8219AF3C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,280(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 280);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219AF34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 284, temp.u32);
loc_8219AF3C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,80(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219afd0
	if (ctx.cr6.lt) goto loc_8219AFD0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219afd0
	if (ctx.cr6.gt) goto loc_8219AFD0;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8219afd0
	if (ctx.cr6.eq) goto loc_8219AFD0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,300
	ctx.r11.s64 = ctx.r11.s64 + 300;
loc_8219AF88:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8219afa8
	if (ctx.cr6.eq) goto loc_8219AFA8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// ble cr6,0x8219af88
	if (!ctx.cr6.gt) goto loc_8219AF88;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8219AFA8:
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82188f90
	ctx.lr = 0x8219AFB0;
	sub_82188F90(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
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
loc_8219AFD0:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bc718
	ctx.lr = 0x8219AFE0;
	sub_821BC718(ctx, base);
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

__attribute__((alias("__imp__sub_8219AFF4"))) PPC_WEAK_FUNC(sub_8219AFF4);
PPC_FUNC_IMPL(__imp__sub_8219AFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219AFF8"))) PPC_WEAK_FUNC(sub_8219AFF8);
PPC_FUNC_IMPL(__imp__sub_8219AFF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8219B000;
	__savegprlr_24(ctx, base);
	// stwu r1,-3504(r1)
	ea = -3504 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r26,4
	ctx.r26.s64 = 4;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r31,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r31.u32);
	// stw r26,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r26.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r28,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r28.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stb r31,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, ctx.r31.u8);
	// addi r27,r11,-24393
	ctx.r27.s64 = ctx.r11.s64 + -24393;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
	// addi r4,r27,-121
	ctx.r4.s64 = ctx.r27.s64 + -121;
	// bl 0x82060368
	ctx.lr = 0x8219B03C;
	sub_82060368(ctx, base);
	// stw r31,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r31.u32);
	// stw r28,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r28.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,184(r1)
	PPC_STORE_U8(ctx.r1.u32 + 184, ctx.r31.u8);
	// addi r30,r11,-31664
	ctx.r30.s64 = ctx.r11.s64 + -31664;
	// addi r3,r1,180
	ctx.r3.s64 = ctx.r1.s64 + 180;
	// addi r4,r30,-1900
	ctx.r4.s64 = ctx.r30.s64 + -1900;
	// bl 0x82060368
	ctx.lr = 0x8219B064;
	sub_82060368(ctx, base);
	// stw r26,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r26.u32);
	// stw r28,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r28.u32);
	// addi r4,r27,-120
	ctx.r4.s64 = ctx.r27.s64 + -120;
	// stw r31,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,216(r1)
	PPC_STORE_U8(ctx.r1.u32 + 216, ctx.r31.u8);
	// addi r3,r1,212
	ctx.r3.s64 = ctx.r1.s64 + 212;
	// bl 0x82060368
	ctx.lr = 0x8219B084;
	sub_82060368(ctx, base);
	// stw r31,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r31.u32);
	// stw r28,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r28.u32);
	// addi r4,r30,-1740
	ctx.r4.s64 = ctx.r30.s64 + -1740;
	// stw r31,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r31.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stb r31,248(r1)
	PPC_STORE_U8(ctx.r1.u32 + 248, ctx.r31.u8);
	// addi r3,r1,244
	ctx.r3.s64 = ctx.r1.s64 + 244;
	// bl 0x82060368
	ctx.lr = 0x8219B0A4;
	sub_82060368(ctx, base);
	// stw r26,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r26.u32);
	// stw r28,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r28.u32);
	// addi r4,r27,-105
	ctx.r4.s64 = ctx.r27.s64 + -105;
	// stw r31,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,280(r1)
	PPC_STORE_U8(ctx.r1.u32 + 280, ctx.r31.u8);
	// addi r3,r1,276
	ctx.r3.s64 = ctx.r1.s64 + 276;
	// bl 0x82060368
	ctx.lr = 0x8219B0C4;
	sub_82060368(ctx, base);
	// li r25,2
	ctx.r25.s64 = 2;
	// stw r28,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r28.u32);
	// addi r4,r30,-1724
	ctx.r4.s64 = ctx.r30.s64 + -1724;
	// stw r25,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r25.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stw r31,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r31.u32);
	// addi r3,r1,308
	ctx.r3.s64 = ctx.r1.s64 + 308;
	// stb r31,312(r1)
	PPC_STORE_U8(ctx.r1.u32 + 312, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219B0E8;
	sub_82060368(ctx, base);
	// li r29,3
	ctx.r29.s64 = 3;
	// stw r28,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r28.u32);
	// addi r4,r30,-1704
	ctx.r4.s64 = ctx.r30.s64 + -1704;
	// stw r29,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r29.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stw r31,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r31.u32);
	// addi r3,r1,340
	ctx.r3.s64 = ctx.r1.s64 + 340;
	// stb r31,344(r1)
	PPC_STORE_U8(ctx.r1.u32 + 344, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219B10C;
	sub_82060368(ctx, base);
	// stw r29,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r29.u32);
	// stw r28,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r28.u32);
	// addi r4,r30,-1684
	ctx.r4.s64 = ctx.r30.s64 + -1684;
	// stw r31,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,376(r1)
	PPC_STORE_U8(ctx.r1.u32 + 376, ctx.r31.u8);
	// addi r3,r1,372
	ctx.r3.s64 = ctx.r1.s64 + 372;
	// bl 0x82060368
	ctx.lr = 0x8219B12C;
	sub_82060368(ctx, base);
	// stw r26,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r26.u32);
	// stw r28,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r28.u32);
	// addi r4,r27,-104
	ctx.r4.s64 = ctx.r27.s64 + -104;
	// stw r31,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,408(r1)
	PPC_STORE_U8(ctx.r1.u32 + 408, ctx.r31.u8);
	// addi r3,r1,404
	ctx.r3.s64 = ctx.r1.s64 + 404;
	// bl 0x82060368
	ctx.lr = 0x8219B14C;
	sub_82060368(ctx, base);
	// stw r25,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r25.u32);
	// stw r28,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r28.u32);
	// addi r4,r30,-1664
	ctx.r4.s64 = ctx.r30.s64 + -1664;
	// stw r31,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,440(r1)
	PPC_STORE_U8(ctx.r1.u32 + 440, ctx.r31.u8);
	// addi r3,r1,436
	ctx.r3.s64 = ctx.r1.s64 + 436;
	// bl 0x82060368
	ctx.lr = 0x8219B16C;
	sub_82060368(ctx, base);
	// stw r29,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, ctx.r29.u32);
	// stw r28,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r28.u32);
	// addi r4,r30,-1644
	ctx.r4.s64 = ctx.r30.s64 + -1644;
	// stw r31,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,472(r1)
	PPC_STORE_U8(ctx.r1.u32 + 472, ctx.r31.u8);
	// addi r3,r1,468
	ctx.r3.s64 = ctx.r1.s64 + 468;
	// bl 0x82060368
	ctx.lr = 0x8219B18C;
	sub_82060368(ctx, base);
	// stw r29,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r29.u32);
	// stw r28,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r28.u32);
	// addi r4,r30,-1624
	ctx.r4.s64 = ctx.r30.s64 + -1624;
	// stw r31,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,504(r1)
	PPC_STORE_U8(ctx.r1.u32 + 504, ctx.r31.u8);
	// addi r3,r1,500
	ctx.r3.s64 = ctx.r1.s64 + 500;
	// bl 0x82060368
	ctx.lr = 0x8219B1AC;
	sub_82060368(ctx, base);
	// stw r26,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r26.u32);
	// stw r28,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r28.u32);
	// addi r4,r27,-97
	ctx.r4.s64 = ctx.r27.s64 + -97;
	// stw r31,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,536(r1)
	PPC_STORE_U8(ctx.r1.u32 + 536, ctx.r31.u8);
	// addi r3,r1,532
	ctx.r3.s64 = ctx.r1.s64 + 532;
	// bl 0x82060368
	ctx.lr = 0x8219B1CC;
	sub_82060368(ctx, base);
	// stw r25,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r25.u32);
	// stw r28,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r28.u32);
	// addi r4,r30,-1604
	ctx.r4.s64 = ctx.r30.s64 + -1604;
	// stw r31,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r31.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// stb r31,568(r1)
	PPC_STORE_U8(ctx.r1.u32 + 568, ctx.r31.u8);
	// addi r3,r1,564
	ctx.r3.s64 = ctx.r1.s64 + 564;
	// bl 0x82060368
	ctx.lr = 0x8219B1EC;
	sub_82060368(ctx, base);
	// stw r29,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r29.u32);
	// stw r28,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r28.u32);
	// addi r4,r30,-1576
	ctx.r4.s64 = ctx.r30.s64 + -1576;
	// stw r31,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r31.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// stb r31,600(r1)
	PPC_STORE_U8(ctx.r1.u32 + 600, ctx.r31.u8);
	// addi r3,r1,596
	ctx.r3.s64 = ctx.r1.s64 + 596;
	// bl 0x82060368
	ctx.lr = 0x8219B20C;
	sub_82060368(ctx, base);
	// stw r26,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r26.u32);
	// stw r28,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, ctx.r28.u32);
	// addi r4,r27,-96
	ctx.r4.s64 = ctx.r27.s64 + -96;
	// stw r31,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,632(r1)
	PPC_STORE_U8(ctx.r1.u32 + 632, ctx.r31.u8);
	// addi r3,r1,628
	ctx.r3.s64 = ctx.r1.s64 + 628;
	// bl 0x82060368
	ctx.lr = 0x8219B22C;
	sub_82060368(ctx, base);
	// stw r25,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r25.u32);
	// stw r28,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r28.u32);
	// addi r4,r30,-1548
	ctx.r4.s64 = ctx.r30.s64 + -1548;
	// stw r31,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,664(r1)
	PPC_STORE_U8(ctx.r1.u32 + 664, ctx.r31.u8);
	// addi r3,r1,660
	ctx.r3.s64 = ctx.r1.s64 + 660;
	// bl 0x82060368
	ctx.lr = 0x8219B24C;
	sub_82060368(ctx, base);
	// stw r29,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r29.u32);
	// stw r28,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r28.u32);
	// addi r4,r30,-1528
	ctx.r4.s64 = ctx.r30.s64 + -1528;
	// stw r31,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,696(r1)
	PPC_STORE_U8(ctx.r1.u32 + 696, ctx.r31.u8);
	// addi r3,r1,692
	ctx.r3.s64 = ctx.r1.s64 + 692;
	// bl 0x82060368
	ctx.lr = 0x8219B26C;
	sub_82060368(ctx, base);
	// stw r29,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r29.u32);
	// stw r28,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r28.u32);
	// addi r4,r30,-1508
	ctx.r4.s64 = ctx.r30.s64 + -1508;
	// stw r31,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,728(r1)
	PPC_STORE_U8(ctx.r1.u32 + 728, ctx.r31.u8);
	// addi r3,r1,724
	ctx.r3.s64 = ctx.r1.s64 + 724;
	// bl 0x82060368
	ctx.lr = 0x8219B28C;
	sub_82060368(ctx, base);
	// stw r26,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r26.u32);
	// addi r4,r27,-89
	ctx.r4.s64 = ctx.r27.s64 + -89;
	// stw r28,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r31,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r31.u32);
	// addi r3,r1,756
	ctx.r3.s64 = ctx.r1.s64 + 756;
	// stb r31,760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 760, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219B2AC;
	sub_82060368(ctx, base);
	// stw r25,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, ctx.r25.u32);
	// stw r28,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r28.u32);
	// addi r4,r30,-1488
	ctx.r4.s64 = ctx.r30.s64 + -1488;
	// stw r31,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r31.u32);
	// li r5,25
	ctx.r5.s64 = 25;
	// stb r31,792(r1)
	PPC_STORE_U8(ctx.r1.u32 + 792, ctx.r31.u8);
	// addi r3,r1,788
	ctx.r3.s64 = ctx.r1.s64 + 788;
	// bl 0x82060368
	ctx.lr = 0x8219B2CC;
	sub_82060368(ctx, base);
	// stw r29,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, ctx.r29.u32);
	// stw r28,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r28.u32);
	// addi r4,r30,-1460
	ctx.r4.s64 = ctx.r30.s64 + -1460;
	// stw r31,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r31.u32);
	// li r5,25
	ctx.r5.s64 = 25;
	// stb r31,824(r1)
	PPC_STORE_U8(ctx.r1.u32 + 824, ctx.r31.u8);
	// addi r3,r1,820
	ctx.r3.s64 = ctx.r1.s64 + 820;
	// bl 0x82060368
	ctx.lr = 0x8219B2EC;
	sub_82060368(ctx, base);
	// stw r29,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, ctx.r29.u32);
	// stw r28,876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 876, ctx.r28.u32);
	// addi r4,r30,-1432
	ctx.r4.s64 = ctx.r30.s64 + -1432;
	// stw r31,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r31.u32);
	// li r5,25
	ctx.r5.s64 = 25;
	// stb r31,856(r1)
	PPC_STORE_U8(ctx.r1.u32 + 856, ctx.r31.u8);
	// addi r3,r1,852
	ctx.r3.s64 = ctx.r1.s64 + 852;
	// bl 0x82060368
	ctx.lr = 0x8219B30C;
	sub_82060368(ctx, base);
	// stw r26,880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 880, ctx.r26.u32);
	// stw r28,908(r1)
	PPC_STORE_U32(ctx.r1.u32 + 908, ctx.r28.u32);
	// addi r4,r27,-88
	ctx.r4.s64 = ctx.r27.s64 + -88;
	// stw r31,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,888(r1)
	PPC_STORE_U8(ctx.r1.u32 + 888, ctx.r31.u8);
	// addi r3,r1,884
	ctx.r3.s64 = ctx.r1.s64 + 884;
	// bl 0x82060368
	ctx.lr = 0x8219B32C;
	sub_82060368(ctx, base);
	// stw r25,912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 912, ctx.r25.u32);
	// stw r28,940(r1)
	PPC_STORE_U32(ctx.r1.u32 + 940, ctx.r28.u32);
	// addi r4,r30,-1404
	ctx.r4.s64 = ctx.r30.s64 + -1404;
	// stw r31,936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 936, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,920(r1)
	PPC_STORE_U8(ctx.r1.u32 + 920, ctx.r31.u8);
	// addi r3,r1,916
	ctx.r3.s64 = ctx.r1.s64 + 916;
	// bl 0x82060368
	ctx.lr = 0x8219B34C;
	sub_82060368(ctx, base);
	// stw r29,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, ctx.r29.u32);
	// stw r28,972(r1)
	PPC_STORE_U32(ctx.r1.u32 + 972, ctx.r28.u32);
	// addi r4,r30,-1384
	ctx.r4.s64 = ctx.r30.s64 + -1384;
	// stw r31,968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 968, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,952(r1)
	PPC_STORE_U8(ctx.r1.u32 + 952, ctx.r31.u8);
	// addi r3,r1,948
	ctx.r3.s64 = ctx.r1.s64 + 948;
	// bl 0x82060368
	ctx.lr = 0x8219B36C;
	sub_82060368(ctx, base);
	// stw r29,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, ctx.r29.u32);
	// stw r28,1004(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1004, ctx.r28.u32);
	// addi r4,r30,-1364
	ctx.r4.s64 = ctx.r30.s64 + -1364;
	// stw r31,1000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1000, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,984(r1)
	PPC_STORE_U8(ctx.r1.u32 + 984, ctx.r31.u8);
	// addi r3,r1,980
	ctx.r3.s64 = ctx.r1.s64 + 980;
	// bl 0x82060368
	ctx.lr = 0x8219B38C;
	sub_82060368(ctx, base);
	// stw r29,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, ctx.r29.u32);
	// stw r28,1036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1036, ctx.r28.u32);
	// addi r4,r30,-1344
	ctx.r4.s64 = ctx.r30.s64 + -1344;
	// stw r31,1032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1032, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,1016(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1016, ctx.r31.u8);
	// addi r3,r1,1012
	ctx.r3.s64 = ctx.r1.s64 + 1012;
	// bl 0x82060368
	ctx.lr = 0x8219B3AC;
	sub_82060368(ctx, base);
	// stw r29,1040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1040, ctx.r29.u32);
	// stw r28,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r28.u32);
	// addi r4,r30,-1324
	ctx.r4.s64 = ctx.r30.s64 + -1324;
	// stw r31,1064(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1064, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,1048(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1048, ctx.r31.u8);
	// addi r3,r1,1044
	ctx.r3.s64 = ctx.r1.s64 + 1044;
	// bl 0x82060368
	ctx.lr = 0x8219B3CC;
	sub_82060368(ctx, base);
	// stw r29,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r29.u32);
	// stw r28,1100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1100, ctx.r28.u32);
	// addi r4,r30,-1304
	ctx.r4.s64 = ctx.r30.s64 + -1304;
	// stw r31,1096(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1096, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,1080(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1080, ctx.r31.u8);
	// addi r3,r1,1076
	ctx.r3.s64 = ctx.r1.s64 + 1076;
	// bl 0x82060368
	ctx.lr = 0x8219B3EC;
	sub_82060368(ctx, base);
	// stw r29,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r29.u32);
	// stw r28,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r28.u32);
	// addi r4,r30,-1284
	ctx.r4.s64 = ctx.r30.s64 + -1284;
	// stw r31,1128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1128, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,1112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1112, ctx.r31.u8);
	// addi r3,r1,1108
	ctx.r3.s64 = ctx.r1.s64 + 1108;
	// bl 0x82060368
	ctx.lr = 0x8219B40C;
	sub_82060368(ctx, base);
	// stw r26,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r26.u32);
	// stw r28,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r28.u32);
	// addi r4,r27,-77
	ctx.r4.s64 = ctx.r27.s64 + -77;
	// stw r31,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,1144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1144, ctx.r31.u8);
	// addi r3,r1,1140
	ctx.r3.s64 = ctx.r1.s64 + 1140;
	// bl 0x82060368
	ctx.lr = 0x8219B42C;
	sub_82060368(ctx, base);
	// stw r25,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r25.u32);
	// stw r28,1196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1196, ctx.r28.u32);
	// addi r4,r30,-1264
	ctx.r4.s64 = ctx.r30.s64 + -1264;
	// stw r31,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r31.u32);
	// li r5,23
	ctx.r5.s64 = 23;
	// stb r31,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, ctx.r31.u8);
	// addi r3,r1,1172
	ctx.r3.s64 = ctx.r1.s64 + 1172;
	// bl 0x82060368
	ctx.lr = 0x8219B44C;
	sub_82060368(ctx, base);
	// stw r29,1200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1200, ctx.r29.u32);
	// stw r28,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r28.u32);
	// addi r4,r30,-1240
	ctx.r4.s64 = ctx.r30.s64 + -1240;
	// stw r31,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, ctx.r31.u32);
	// li r5,23
	ctx.r5.s64 = 23;
	// stb r31,1208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1208, ctx.r31.u8);
	// addi r3,r1,1204
	ctx.r3.s64 = ctx.r1.s64 + 1204;
	// bl 0x82060368
	ctx.lr = 0x8219B46C;
	sub_82060368(ctx, base);
	// stw r26,1232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1232, ctx.r26.u32);
	// stw r28,1260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1260, ctx.r28.u32);
	// addi r4,r27,-76
	ctx.r4.s64 = ctx.r27.s64 + -76;
	// stw r31,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,1240(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1240, ctx.r31.u8);
	// addi r3,r1,1236
	ctx.r3.s64 = ctx.r1.s64 + 1236;
	// bl 0x82060368
	ctx.lr = 0x8219B48C;
	sub_82060368(ctx, base);
	// stw r25,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, ctx.r25.u32);
	// stw r28,1292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1292, ctx.r28.u32);
	// addi r4,r30,-1216
	ctx.r4.s64 = ctx.r30.s64 + -1216;
	// stw r31,1288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1288, ctx.r31.u32);
	// li r5,18
	ctx.r5.s64 = 18;
	// stb r31,1272(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1272, ctx.r31.u8);
	// addi r3,r1,1268
	ctx.r3.s64 = ctx.r1.s64 + 1268;
	// bl 0x82060368
	ctx.lr = 0x8219B4AC;
	sub_82060368(ctx, base);
	// stw r29,1296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1296, ctx.r29.u32);
	// stw r28,1324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1324, ctx.r28.u32);
	// addi r4,r30,-1196
	ctx.r4.s64 = ctx.r30.s64 + -1196;
	// stw r31,1320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1320, ctx.r31.u32);
	// li r5,18
	ctx.r5.s64 = 18;
	// stb r31,1304(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1304, ctx.r31.u8);
	// addi r3,r1,1300
	ctx.r3.s64 = ctx.r1.s64 + 1300;
	// bl 0x82060368
	ctx.lr = 0x8219B4CC;
	sub_82060368(ctx, base);
	// stw r29,1328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1328, ctx.r29.u32);
	// stw r28,1356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1356, ctx.r28.u32);
	// addi r4,r30,-1176
	ctx.r4.s64 = ctx.r30.s64 + -1176;
	// stw r31,1352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1352, ctx.r31.u32);
	// li r5,18
	ctx.r5.s64 = 18;
	// stb r31,1336(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1336, ctx.r31.u8);
	// addi r3,r1,1332
	ctx.r3.s64 = ctx.r1.s64 + 1332;
	// bl 0x82060368
	ctx.lr = 0x8219B4EC;
	sub_82060368(ctx, base);
	// stw r29,1360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1360, ctx.r29.u32);
	// stw r28,1388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1388, ctx.r28.u32);
	// addi r4,r30,-1156
	ctx.r4.s64 = ctx.r30.s64 + -1156;
	// stw r31,1384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1384, ctx.r31.u32);
	// li r5,18
	ctx.r5.s64 = 18;
	// stb r31,1368(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1368, ctx.r31.u8);
	// addi r3,r1,1364
	ctx.r3.s64 = ctx.r1.s64 + 1364;
	// bl 0x82060368
	ctx.lr = 0x8219B50C;
	sub_82060368(ctx, base);
	// stw r29,1392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1392, ctx.r29.u32);
	// stw r28,1420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1420, ctx.r28.u32);
	// stw r31,1416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1416, ctx.r31.u32);
	// addi r4,r30,-1136
	ctx.r4.s64 = ctx.r30.s64 + -1136;
	// stb r31,1400(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1400, ctx.r31.u8);
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r3,r1,1396
	ctx.r3.s64 = ctx.r1.s64 + 1396;
	// bl 0x82060368
	ctx.lr = 0x8219B52C;
	sub_82060368(ctx, base);
	// stw r26,1424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1424, ctx.r26.u32);
	// stw r28,1452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1452, ctx.r28.u32);
	// addi r4,r27,-69
	ctx.r4.s64 = ctx.r27.s64 + -69;
	// stw r31,1448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1448, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,1432(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1432, ctx.r31.u8);
	// addi r3,r1,1428
	ctx.r3.s64 = ctx.r1.s64 + 1428;
	// bl 0x82060368
	ctx.lr = 0x8219B54C;
	sub_82060368(ctx, base);
	// stw r25,1456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1456, ctx.r25.u32);
	// stw r28,1484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1484, ctx.r28.u32);
	// addi r4,r30,-1116
	ctx.r4.s64 = ctx.r30.s64 + -1116;
	// stw r31,1480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1480, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stb r31,1464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1464, ctx.r31.u8);
	// addi r3,r1,1460
	ctx.r3.s64 = ctx.r1.s64 + 1460;
	// bl 0x82060368
	ctx.lr = 0x8219B56C;
	sub_82060368(ctx, base);
	// stw r25,1488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1488, ctx.r25.u32);
	// stw r28,1516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1516, ctx.r28.u32);
	// addi r4,r30,-1092
	ctx.r4.s64 = ctx.r30.s64 + -1092;
	// stw r31,1512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1512, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stb r31,1496(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1496, ctx.r31.u8);
	// addi r3,r1,1492
	ctx.r3.s64 = ctx.r1.s64 + 1492;
	// bl 0x82060368
	ctx.lr = 0x8219B58C;
	sub_82060368(ctx, base);
	// stw r29,1520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1520, ctx.r29.u32);
	// stw r28,1548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1548, ctx.r28.u32);
	// addi r4,r30,-1068
	ctx.r4.s64 = ctx.r30.s64 + -1068;
	// stw r31,1544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1544, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stb r31,1528(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1528, ctx.r31.u8);
	// addi r3,r1,1524
	ctx.r3.s64 = ctx.r1.s64 + 1524;
	// bl 0x82060368
	ctx.lr = 0x8219B5AC;
	sub_82060368(ctx, base);
	// stw r25,1552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1552, ctx.r25.u32);
	// addi r4,r30,-1044
	ctx.r4.s64 = ctx.r30.s64 + -1044;
	// addi r3,r1,1556
	ctx.r3.s64 = ctx.r1.s64 + 1556;
	// bl 0x82060190
	ctx.lr = 0x8219B5BC;
	sub_82060190(ctx, base);
	// stw r29,1584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1584, ctx.r29.u32);
	// addi r4,r30,-1020
	ctx.r4.s64 = ctx.r30.s64 + -1020;
	// addi r3,r1,1588
	ctx.r3.s64 = ctx.r1.s64 + 1588;
	// bl 0x82060190
	ctx.lr = 0x8219B5CC;
	sub_82060190(ctx, base);
	// stw r29,1616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1616, ctx.r29.u32);
	// addi r4,r30,-996
	ctx.r4.s64 = ctx.r30.s64 + -996;
	// addi r3,r1,1620
	ctx.r3.s64 = ctx.r1.s64 + 1620;
	// bl 0x82060190
	ctx.lr = 0x8219B5DC;
	sub_82060190(ctx, base);
	// stw r25,1648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1648, ctx.r25.u32);
	// addi r4,r30,-972
	ctx.r4.s64 = ctx.r30.s64 + -972;
	// addi r3,r1,1652
	ctx.r3.s64 = ctx.r1.s64 + 1652;
	// bl 0x82060190
	ctx.lr = 0x8219B5EC;
	sub_82060190(ctx, base);
	// stw r29,1680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1680, ctx.r29.u32);
	// addi r4,r30,-948
	ctx.r4.s64 = ctx.r30.s64 + -948;
	// addi r3,r1,1684
	ctx.r3.s64 = ctx.r1.s64 + 1684;
	// bl 0x82060190
	ctx.lr = 0x8219B5FC;
	sub_82060190(ctx, base);
	// stw r29,1712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1712, ctx.r29.u32);
	// addi r4,r30,-924
	ctx.r4.s64 = ctx.r30.s64 + -924;
	// addi r3,r1,1716
	ctx.r3.s64 = ctx.r1.s64 + 1716;
	// bl 0x82060190
	ctx.lr = 0x8219B60C;
	sub_82060190(ctx, base);
	// stw r26,1744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1744, ctx.r26.u32);
	// addi r4,r27,-68
	ctx.r4.s64 = ctx.r27.s64 + -68;
	// addi r3,r1,1748
	ctx.r3.s64 = ctx.r1.s64 + 1748;
	// bl 0x82060190
	ctx.lr = 0x8219B61C;
	sub_82060190(ctx, base);
	// stw r25,1776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1776, ctx.r25.u32);
	// addi r4,r30,-900
	ctx.r4.s64 = ctx.r30.s64 + -900;
	// addi r3,r1,1780
	ctx.r3.s64 = ctx.r1.s64 + 1780;
	// bl 0x82060190
	ctx.lr = 0x8219B62C;
	sub_82060190(ctx, base);
	// stw r29,1808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1808, ctx.r29.u32);
	// addi r4,r30,-876
	ctx.r4.s64 = ctx.r30.s64 + -876;
	// addi r3,r1,1812
	ctx.r3.s64 = ctx.r1.s64 + 1812;
	// bl 0x82060190
	ctx.lr = 0x8219B63C;
	sub_82060190(ctx, base);
	// stw r29,1840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1840, ctx.r29.u32);
	// addi r4,r30,-852
	ctx.r4.s64 = ctx.r30.s64 + -852;
	// addi r3,r1,1844
	ctx.r3.s64 = ctx.r1.s64 + 1844;
	// bl 0x82060190
	ctx.lr = 0x8219B64C;
	sub_82060190(ctx, base);
	// stw r29,1872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1872, ctx.r29.u32);
	// addi r4,r30,-828
	ctx.r4.s64 = ctx.r30.s64 + -828;
	// addi r3,r1,1876
	ctx.r3.s64 = ctx.r1.s64 + 1876;
	// bl 0x82060190
	ctx.lr = 0x8219B65C;
	sub_82060190(ctx, base);
	// stw r29,1904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1904, ctx.r29.u32);
	// addi r4,r30,-804
	ctx.r4.s64 = ctx.r30.s64 + -804;
	// addi r3,r1,1908
	ctx.r3.s64 = ctx.r1.s64 + 1908;
	// bl 0x82060190
	ctx.lr = 0x8219B66C;
	sub_82060190(ctx, base);
	// stw r26,1936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1936, ctx.r26.u32);
	// addi r4,r27,-53
	ctx.r4.s64 = ctx.r27.s64 + -53;
	// addi r3,r1,1940
	ctx.r3.s64 = ctx.r1.s64 + 1940;
	// bl 0x82060190
	ctx.lr = 0x8219B67C;
	sub_82060190(ctx, base);
	// stw r25,1968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1968, ctx.r25.u32);
	// addi r4,r30,-780
	ctx.r4.s64 = ctx.r30.s64 + -780;
	// addi r3,r1,1972
	ctx.r3.s64 = ctx.r1.s64 + 1972;
	// bl 0x82060190
	ctx.lr = 0x8219B68C;
	sub_82060190(ctx, base);
	// stw r29,2000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2000, ctx.r29.u32);
	// addi r4,r30,-756
	ctx.r4.s64 = ctx.r30.s64 + -756;
	// addi r3,r1,2004
	ctx.r3.s64 = ctx.r1.s64 + 2004;
	// bl 0x82060190
	ctx.lr = 0x8219B69C;
	sub_82060190(ctx, base);
	// stw r26,2032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2032, ctx.r26.u32);
	// addi r4,r27,-52
	ctx.r4.s64 = ctx.r27.s64 + -52;
	// addi r3,r1,2036
	ctx.r3.s64 = ctx.r1.s64 + 2036;
	// bl 0x82060190
	ctx.lr = 0x8219B6AC;
	sub_82060190(ctx, base);
	// stw r25,2064(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2064, ctx.r25.u32);
	// addi r4,r30,-732
	ctx.r4.s64 = ctx.r30.s64 + -732;
	// addi r3,r1,2068
	ctx.r3.s64 = ctx.r1.s64 + 2068;
	// bl 0x82060190
	ctx.lr = 0x8219B6BC;
	sub_82060190(ctx, base);
	// stw r29,2096(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2096, ctx.r29.u32);
	// addi r4,r30,-712
	ctx.r4.s64 = ctx.r30.s64 + -712;
	// addi r3,r1,2100
	ctx.r3.s64 = ctx.r1.s64 + 2100;
	// bl 0x82060190
	ctx.lr = 0x8219B6CC;
	sub_82060190(ctx, base);
	// stw r26,2128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2128, ctx.r26.u32);
	// addi r4,r27,-45
	ctx.r4.s64 = ctx.r27.s64 + -45;
	// addi r3,r1,2132
	ctx.r3.s64 = ctx.r1.s64 + 2132;
	// bl 0x82060190
	ctx.lr = 0x8219B6DC;
	sub_82060190(ctx, base);
	// stw r25,2160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2160, ctx.r25.u32);
	// addi r4,r30,-692
	ctx.r4.s64 = ctx.r30.s64 + -692;
	// addi r3,r1,2164
	ctx.r3.s64 = ctx.r1.s64 + 2164;
	// bl 0x82060190
	ctx.lr = 0x8219B6EC;
	sub_82060190(ctx, base);
	// stw r29,2192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2192, ctx.r29.u32);
	// addi r4,r30,-664
	ctx.r4.s64 = ctx.r30.s64 + -664;
	// addi r3,r1,2196
	ctx.r3.s64 = ctx.r1.s64 + 2196;
	// bl 0x82060190
	ctx.lr = 0x8219B6FC;
	sub_82060190(ctx, base);
	// stw r29,2224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2224, ctx.r29.u32);
	// addi r4,r30,-636
	ctx.r4.s64 = ctx.r30.s64 + -636;
	// addi r3,r1,2228
	ctx.r3.s64 = ctx.r1.s64 + 2228;
	// bl 0x82060190
	ctx.lr = 0x8219B70C;
	sub_82060190(ctx, base);
	// stw r29,2256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2256, ctx.r29.u32);
	// addi r4,r30,-608
	ctx.r4.s64 = ctx.r30.s64 + -608;
	// addi r3,r1,2260
	ctx.r3.s64 = ctx.r1.s64 + 2260;
	// bl 0x82060190
	ctx.lr = 0x8219B71C;
	sub_82060190(ctx, base);
	// stw r29,2288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2288, ctx.r29.u32);
	// addi r4,r30,-580
	ctx.r4.s64 = ctx.r30.s64 + -580;
	// addi r3,r1,2292
	ctx.r3.s64 = ctx.r1.s64 + 2292;
	// bl 0x82060190
	ctx.lr = 0x8219B72C;
	sub_82060190(ctx, base);
	// stw r29,2320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2320, ctx.r29.u32);
	// addi r4,r30,-552
	ctx.r4.s64 = ctx.r30.s64 + -552;
	// addi r3,r1,2324
	ctx.r3.s64 = ctx.r1.s64 + 2324;
	// bl 0x82060190
	ctx.lr = 0x8219B73C;
	sub_82060190(ctx, base);
	// stw r29,2352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2352, ctx.r29.u32);
	// addi r4,r30,-524
	ctx.r4.s64 = ctx.r30.s64 + -524;
	// addi r3,r1,2356
	ctx.r3.s64 = ctx.r1.s64 + 2356;
	// bl 0x82060190
	ctx.lr = 0x8219B74C;
	sub_82060190(ctx, base);
	// stw r26,2384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2384, ctx.r26.u32);
	// addi r4,r27,-44
	ctx.r4.s64 = ctx.r27.s64 + -44;
	// addi r3,r1,2388
	ctx.r3.s64 = ctx.r1.s64 + 2388;
	// bl 0x82060190
	ctx.lr = 0x8219B75C;
	sub_82060190(ctx, base);
	// stw r25,2416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2416, ctx.r25.u32);
	// addi r4,r30,-496
	ctx.r4.s64 = ctx.r30.s64 + -496;
	// addi r3,r1,2420
	ctx.r3.s64 = ctx.r1.s64 + 2420;
	// bl 0x82060190
	ctx.lr = 0x8219B76C;
	sub_82060190(ctx, base);
	// stw r29,2448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2448, ctx.r29.u32);
	// addi r4,r30,-472
	ctx.r4.s64 = ctx.r30.s64 + -472;
	// addi r3,r1,2452
	ctx.r3.s64 = ctx.r1.s64 + 2452;
	// bl 0x82060190
	ctx.lr = 0x8219B77C;
	sub_82060190(ctx, base);
	// stw r29,2480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2480, ctx.r29.u32);
	// addi r4,r30,-448
	ctx.r4.s64 = ctx.r30.s64 + -448;
	// addi r3,r1,2484
	ctx.r3.s64 = ctx.r1.s64 + 2484;
	// bl 0x82060190
	ctx.lr = 0x8219B78C;
	sub_82060190(ctx, base);
	// stw r29,2512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2512, ctx.r29.u32);
	// addi r4,r30,-424
	ctx.r4.s64 = ctx.r30.s64 + -424;
	// addi r3,r1,2516
	ctx.r3.s64 = ctx.r1.s64 + 2516;
	// bl 0x82060190
	ctx.lr = 0x8219B79C;
	sub_82060190(ctx, base);
	// stw r29,2544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2544, ctx.r29.u32);
	// addi r4,r30,-400
	ctx.r4.s64 = ctx.r30.s64 + -400;
	// addi r3,r1,2548
	ctx.r3.s64 = ctx.r1.s64 + 2548;
	// bl 0x82060190
	ctx.lr = 0x8219B7AC;
	sub_82060190(ctx, base);
	// stw r29,2576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2576, ctx.r29.u32);
	// addi r4,r30,-376
	ctx.r4.s64 = ctx.r30.s64 + -376;
	// addi r3,r1,2580
	ctx.r3.s64 = ctx.r1.s64 + 2580;
	// bl 0x82060190
	ctx.lr = 0x8219B7BC;
	sub_82060190(ctx, base);
	// stw r29,2608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2608, ctx.r29.u32);
	// addi r4,r30,-352
	ctx.r4.s64 = ctx.r30.s64 + -352;
	// addi r3,r1,2612
	ctx.r3.s64 = ctx.r1.s64 + 2612;
	// bl 0x82060190
	ctx.lr = 0x8219B7CC;
	sub_82060190(ctx, base);
	// stw r29,2640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2640, ctx.r29.u32);
	// addi r4,r30,-328
	ctx.r4.s64 = ctx.r30.s64 + -328;
	// addi r3,r1,2644
	ctx.r3.s64 = ctx.r1.s64 + 2644;
	// bl 0x82060190
	ctx.lr = 0x8219B7DC;
	sub_82060190(ctx, base);
	// stw r29,2672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2672, ctx.r29.u32);
	// addi r4,r30,-304
	ctx.r4.s64 = ctx.r30.s64 + -304;
	// addi r3,r1,2676
	ctx.r3.s64 = ctx.r1.s64 + 2676;
	// bl 0x82060190
	ctx.lr = 0x8219B7EC;
	sub_82060190(ctx, base);
	// stw r29,2704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2704, ctx.r29.u32);
	// addi r4,r30,-280
	ctx.r4.s64 = ctx.r30.s64 + -280;
	// addi r3,r1,2708
	ctx.r3.s64 = ctx.r1.s64 + 2708;
	// bl 0x82060190
	ctx.lr = 0x8219B7FC;
	sub_82060190(ctx, base);
	// stw r26,2736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2736, ctx.r26.u32);
	// addi r4,r27,-29
	ctx.r4.s64 = ctx.r27.s64 + -29;
	// addi r3,r1,2740
	ctx.r3.s64 = ctx.r1.s64 + 2740;
	// bl 0x82060190
	ctx.lr = 0x8219B80C;
	sub_82060190(ctx, base);
	// stw r25,2768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2768, ctx.r25.u32);
	// addi r4,r30,-256
	ctx.r4.s64 = ctx.r30.s64 + -256;
	// addi r3,r1,2772
	ctx.r3.s64 = ctx.r1.s64 + 2772;
	// bl 0x82060190
	ctx.lr = 0x8219B81C;
	sub_82060190(ctx, base);
	// stw r29,2800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2800, ctx.r29.u32);
	// addi r4,r30,-232
	ctx.r4.s64 = ctx.r30.s64 + -232;
	// addi r3,r1,2804
	ctx.r3.s64 = ctx.r1.s64 + 2804;
	// bl 0x82060190
	ctx.lr = 0x8219B82C;
	sub_82060190(ctx, base);
	// stw r26,2832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2832, ctx.r26.u32);
	// addi r4,r27,-28
	ctx.r4.s64 = ctx.r27.s64 + -28;
	// addi r3,r1,2836
	ctx.r3.s64 = ctx.r1.s64 + 2836;
	// bl 0x82060190
	ctx.lr = 0x8219B83C;
	sub_82060190(ctx, base);
	// stw r25,2864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2864, ctx.r25.u32);
	// addi r4,r30,-208
	ctx.r4.s64 = ctx.r30.s64 + -208;
	// addi r3,r1,2868
	ctx.r3.s64 = ctx.r1.s64 + 2868;
	// bl 0x82060190
	ctx.lr = 0x8219B84C;
	sub_82060190(ctx, base);
	// stw r29,2896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2896, ctx.r29.u32);
	// addi r4,r30,-184
	ctx.r4.s64 = ctx.r30.s64 + -184;
	// addi r3,r1,2900
	ctx.r3.s64 = ctx.r1.s64 + 2900;
	// bl 0x82060190
	ctx.lr = 0x8219B85C;
	sub_82060190(ctx, base);
	// stw r29,2928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2928, ctx.r29.u32);
	// addi r4,r30,-160
	ctx.r4.s64 = ctx.r30.s64 + -160;
	// addi r3,r1,2932
	ctx.r3.s64 = ctx.r1.s64 + 2932;
	// bl 0x82060190
	ctx.lr = 0x8219B86C;
	sub_82060190(ctx, base);
	// stw r29,2960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2960, ctx.r29.u32);
	// addi r4,r30,-136
	ctx.r4.s64 = ctx.r30.s64 + -136;
	// addi r3,r1,2964
	ctx.r3.s64 = ctx.r1.s64 + 2964;
	// bl 0x82060190
	ctx.lr = 0x8219B87C;
	sub_82060190(ctx, base);
	// stw r29,2992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2992, ctx.r29.u32);
	// addi r4,r30,-112
	ctx.r4.s64 = ctx.r30.s64 + -112;
	// addi r3,r1,2996
	ctx.r3.s64 = ctx.r1.s64 + 2996;
	// bl 0x82060190
	ctx.lr = 0x8219B88C;
	sub_82060190(ctx, base);
	// stw r26,3024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3024, ctx.r26.u32);
	// addi r4,r27,-21
	ctx.r4.s64 = ctx.r27.s64 + -21;
	// addi r3,r1,3028
	ctx.r3.s64 = ctx.r1.s64 + 3028;
	// bl 0x82060190
	ctx.lr = 0x8219B89C;
	sub_82060190(ctx, base);
	// stw r25,3056(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3056, ctx.r25.u32);
	// addi r4,r30,-88
	ctx.r4.s64 = ctx.r30.s64 + -88;
	// addi r3,r1,3060
	ctx.r3.s64 = ctx.r1.s64 + 3060;
	// bl 0x82060190
	ctx.lr = 0x8219B8AC;
	sub_82060190(ctx, base);
	// stw r29,3088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3088, ctx.r29.u32);
	// addi r4,r30,-60
	ctx.r4.s64 = ctx.r30.s64 + -60;
	// addi r3,r1,3092
	ctx.r3.s64 = ctx.r1.s64 + 3092;
	// bl 0x82060190
	ctx.lr = 0x8219B8BC;
	sub_82060190(ctx, base);
	// stw r26,3120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3120, ctx.r26.u32);
	// addi r4,r27,-20
	ctx.r4.s64 = ctx.r27.s64 + -20;
	// addi r3,r1,3124
	ctx.r3.s64 = ctx.r1.s64 + 3124;
	// bl 0x82060190
	ctx.lr = 0x8219B8CC;
	sub_82060190(ctx, base);
	// stw r26,3152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3152, ctx.r26.u32);
	// addi r4,r27,-9
	ctx.r4.s64 = ctx.r27.s64 + -9;
	// addi r3,r1,3156
	ctx.r3.s64 = ctx.r1.s64 + 3156;
	// bl 0x82060190
	ctx.lr = 0x8219B8DC;
	sub_82060190(ctx, base);
	// addi r4,r27,-8
	ctx.r4.s64 = ctx.r27.s64 + -8;
	// stw r26,3184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3184, ctx.r26.u32);
	// addi r3,r1,3188
	ctx.r3.s64 = ctx.r1.s64 + 3188;
	// bl 0x82060190
	ctx.lr = 0x8219B8EC;
	sub_82060190(ctx, base);
	// stw r26,3216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3216, ctx.r26.u32);
	// addi r4,r27,-1
	ctx.r4.s64 = ctx.r27.s64 + -1;
	// addi r3,r1,3220
	ctx.r3.s64 = ctx.r1.s64 + 3220;
	// bl 0x82060190
	ctx.lr = 0x8219B8FC;
	sub_82060190(ctx, base);
	// stw r31,3248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3248, ctx.r31.u32);
	// addi r4,r30,-32
	ctx.r4.s64 = ctx.r30.s64 + -32;
	// addi r3,r1,3252
	ctx.r3.s64 = ctx.r1.s64 + 3252;
	// bl 0x82060190
	ctx.lr = 0x8219B90C;
	sub_82060190(ctx, base);
	// stw r31,3280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3280, ctx.r31.u32);
	// addi r4,r30,-16
	ctx.r4.s64 = ctx.r30.s64 + -16;
	// addi r3,r1,3284
	ctx.r3.s64 = ctx.r1.s64 + 3284;
	// bl 0x82060190
	ctx.lr = 0x8219B91C;
	sub_82060190(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r10,3312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3312, ctx.r10.u32);
	// addi r3,r1,3316
	ctx.r3.s64 = ctx.r1.s64 + 3316;
	// bl 0x82060190
	ctx.lr = 0x8219B930;
	sub_82060190(ctx, base);
	// addi r25,r24,256
	ctx.r25.s64 = ctx.r24.s64 + 256;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82069318
	ctx.lr = 0x8219B93C;
	sub_82069318(ctx, base);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// li r24,-1
	ctx.r24.s64 = -1;
loc_8219B948:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82068d08
	ctx.lr = 0x8219B954;
	sub_82068D08(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82068bd0
	ctx.lr = 0x8219B960;
	sub_82068BD0(ctx, base);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x8219ba0c
	if (!ctx.cr6.lt) goto loc_8219BA0C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820602f0
	ctx.lr = 0x8219B98C;
	sub_820602F0(ctx, base);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x8219B9A4;
	sub_820601F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,3392
	ctx.r3.s64 = ctx.r1.s64 + 3392;
	// bl 0x82060190
	ctx.lr = 0x8219B9B0;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,3360
	ctx.r3.s64 = ctx.r1.s64 + 3360;
	// bl 0x821ccf40
	ctx.lr = 0x8219B9C0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8219B9D4;
	sub_820601F8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,3360
	ctx.r3.s64 = ctx.r1.s64 + 3360;
	// bl 0x820602f0
	ctx.lr = 0x8219B9E4;
	sub_820602F0(ctx, base);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820601f8
	ctx.lr = 0x8219B9F8;
	sub_820601F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219ba0c
	if (ctx.cr6.lt) goto loc_8219BA0C;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8219BA0C;
	sub_8207A630(ctx, base);
loc_8219BA0C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r26,r26,32
	ctx.r26.s64 = ctx.r26.s64 + 32;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// cmplwi cr6,r29,100
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 100, ctx.xer);
	// blt cr6,0x8219b948
	if (ctx.cr6.lt) goto loc_8219B948;
	// li r29,99
	ctx.r29.s64 = 99;
	// addi r30,r1,3352
	ctx.r30.s64 = ctx.r1.s64 + 3352;
loc_8219BA30:
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219ba48
	if (ctx.cr6.lt) goto loc_8219BA48;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8219BA48;
	sub_8207A630(ctx, base);
loc_8219BA48:
	// stw r28,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
	// stb r31,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r31.u8);
	// bge 0x8219ba30
	if (!ctx.cr0.lt) goto loc_8219BA30;
	// addi r1,r1,3504
	ctx.r1.s64 = ctx.r1.s64 + 3504;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219BA64"))) PPC_WEAK_FUNC(sub_8219BA64);
PPC_FUNC_IMPL(__imp__sub_8219BA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219BA68"))) PPC_WEAK_FUNC(sub_8219BA68);
PPC_FUNC_IMPL(__imp__sub_8219BA68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x8219BA70;
	__savegprlr_20(ctx, base);
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x82080364
	ctx.lr = 0x8219BA78;
	__savefpr_27(ctx, base);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,196(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f0,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r30,r11,-2064
	ctx.r30.s64 = ctx.r11.s64 + -2064;
	// fneg f13,f0
	ctx.f13.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f12,156(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fneg f29,f12
	ctx.f29.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f31,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// fmuls f30,f13,f31
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219BABC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f11,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,272(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 272);
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// lwz r8,268(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 268);
	// li r31,0
	ctx.r31.s64 = 0;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r23,r25,256
	ctx.r23.s64 = ctx.r25.s64 + 256;
	// rlwinm r6,r7,0,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFE0;
	// mr r22,r31
	ctx.r22.u64 = ctx.r31.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// fmadds f27,f29,f31,f10
	ctx.f27.f64 = double(float(ctx.f29.f64 * ctx.f31.f64 + ctx.f10.f64));
	// stfs f27,108(r1)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ble cr6,0x8219be4c
	if (!ctx.cr6.gt) goto loc_8219BE4C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f29,60(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,32(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f28.f64 = double(temp.f32);
	// addi r20,r25,232
	ctx.r20.s64 = ctx.r25.s64 + 232;
	// li r24,15
	ctx.r24.s64 = 15;
	// li r27,-1
	ctx.r27.s64 = -1;
	// li r21,7
	ctx.r21.s64 = 7;
	// lfs f31,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
loc_8219BB10:
	// ld r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x82068bd0
	ctx.lr = 0x8219BB24;
	sub_82068BD0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x8219bcc0
	if (ctx.cr6.gt) goto loc_8219BCC0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219bbf0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219BBF0;
	// bdzf 4*cr6+eq,0x8219bbf0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219BBF0;
	// bne cr6,0x8219bc58
	if (!ctx.cr6.eq) goto loc_8219BC58;
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82079fd8
	ctx.lr = 0x8219BB50;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219bb6c
	if (ctx.cr6.eq) goto loc_8219BB6C;
	// ld r5,208(r25)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r25.u32 + 208);
	// lwz r4,196(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 196);
	// bl 0x821afc58
	ctx.lr = 0x8219BB64;
	sub_821AFC58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8219bb70
	goto loc_8219BB70;
loc_8219BB6C:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_8219BB70:
	// stw r24,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r24.u32);
	// addi r29,r26,4
	ctx.r29.s64 = ctx.r26.s64 + 4;
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, ctx.r31.u8);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x820601f8
	ctx.lr = 0x8219BB98;
	sub_820601F8(ctx, base);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821afbe0
	ctx.lr = 0x8219BBA4;
	sub_821AFBE0(ctx, base);
	// stw r24,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r24.u32);
	// stw r31,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,292(r1)
	PPC_STORE_U8(ctx.r1.u32 + 292, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x820601f8
	ctx.lr = 0x8219BBCC;
	sub_820601F8(ctx, base);
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// addi r3,r1,360
	ctx.r3.s64 = ctx.r1.s64 + 360;
	// ld r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// lwz r4,196(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 196);
	// bl 0x8216f7a8
	ctx.lr = 0x8219BBE0;
	sub_8216F7A8(ctx, base);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8219bdd4
	goto loc_8219BDD4;
loc_8219BBF0:
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82079fd8
	ctx.lr = 0x8219BBF8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219bc14
	if (ctx.cr6.eq) goto loc_8219BC14;
	// ld r5,208(r25)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r25.u32 + 208);
	// lwz r4,204(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 204);
	// bl 0x821afc58
	ctx.lr = 0x8219BC0C;
	sub_821AFC58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8219bc18
	goto loc_8219BC18;
loc_8219BC14:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_8219BC18:
	// stw r24,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r24.u32);
	// addi r4,r26,4
	ctx.r4.s64 = ctx.r26.s64 + 4;
	// stw r31,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// bl 0x820601f8
	ctx.lr = 0x8219BC3C;
	sub_820601F8(ctx, base);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821afbe0
	ctx.lr = 0x8219BC48;
	sub_821AFBE0(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8219bdd4
	goto loc_8219BDD4;
loc_8219BC58:
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82079fd8
	ctx.lr = 0x8219BC60;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219bc7c
	if (ctx.cr6.eq) goto loc_8219BC7C;
	// ld r5,208(r25)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r25.u32 + 208);
	// lwz r4,204(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 204);
	// bl 0x821afc58
	ctx.lr = 0x8219BC74;
	sub_821AFC58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8219bc80
	goto loc_8219BC80;
loc_8219BC7C:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_8219BC80:
	// stw r24,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r24.u32);
	// addi r4,r26,4
	ctx.r4.s64 = ctx.r26.s64 + 4;
	// stw r31,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,260(r1)
	PPC_STORE_U8(ctx.r1.u32 + 260, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// bl 0x820601f8
	ctx.lr = 0x8219BCA4;
	sub_820601F8(ctx, base);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821afbe0
	ctx.lr = 0x8219BCB0;
	sub_821AFBE0(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f13,f0,f29,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f29.f64 + ctx.f30.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8219bdd4
	goto loc_8219BDD4;
loc_8219BCC0:
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82079fd8
	ctx.lr = 0x8219BCC8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219bce4
	if (ctx.cr6.eq) goto loc_8219BCE4;
	// ld r5,208(r25)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r25.u32 + 208);
	// lwz r4,204(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 204);
	// bl 0x821afc58
	ctx.lr = 0x8219BCDC;
	sub_821AFC58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8219bce8
	goto loc_8219BCE8;
loc_8219BCE4:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_8219BCE8:
	// stw r24,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r24.u32);
	// addi r4,r26,4
	ctx.r4.s64 = ctx.r26.s64 + 4;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// bl 0x820601f8
	ctx.lr = 0x8219BD0C;
	sub_820601F8(ctx, base);
	// stw r24,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r24.u32);
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x820601f8
	ctx.lr = 0x8219BD2C;
	sub_820601F8(ctx, base);
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x821d3a20
	ctx.lr = 0x8219BD38;
	sub_821D3A20(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r28,r30,84
	ctx.r28.s64 = ctx.r30.s64 + 84;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82063cc8
	ctx.lr = 0x8219BD54;
	sub_82063CC8(ctx, base);
	// stw r21,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r21.u32);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// sth r31,164(r1)
	PPC_STORE_U16(ctx.r1.u32 + 164, ctx.r31.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82063cc8
	ctx.lr = 0x8219BD74;
	sub_82063CC8(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// ld r6,112(r30)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r30.u32 + 112);
	// lwz r4,80(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// bl 0x8216f398
	ctx.lr = 0x8219BD88;
	sub_8216F398(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 72, temp.u32);
	// stfs f13,76(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 76, temp.u32);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// blt cr6,0x8219bdb4
	if (ctx.cr6.lt) goto loc_8219BDB4;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8219BDB4;
	sub_8207A630(ctx, base);
loc_8219BDB4:
	// stw r21,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r21.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// sth r31,4(r29)
	PPC_STORE_U16(ctx.r29.u32 + 4, ctx.r31.u16);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219bdd4
	if (ctx.cr6.lt) goto loc_8219BDD4;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8207a630
	ctx.lr = 0x8219BDD4;
	sub_8207A630(ctx, base);
loc_8219BDD4:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x8219bde4
	if (ctx.cr6.eq) goto loc_8219BDE4;
	// stb r31,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r31.u8);
loc_8219BDE4:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219BDFC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x8206e258
	ctx.lr = 0x8219BE08;
	sub_8206E258(ctx, base);
	// lwz r9,80(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 80);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,16(r23)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// fadds f27,f27,f0
	ctx.f27.f64 = double(float(ctx.f27.f64 + ctx.f0.f64));
	// lwz r6,12(r23)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// srawi r4,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 5;
	// stfs f27,108(r1)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// cmpw cr6,r22,r4
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8219bb10
	if (ctx.cr6.lt) goto loc_8219BB10;
loc_8219BE4C:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x820803b0
	ctx.lr = 0x8219BE58;
	__restfpr_27(ctx, base);
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219BE5C"))) PPC_WEAK_FUNC(sub_8219BE5C);
PPC_FUNC_IMPL(__imp__sub_8219BE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219BE60"))) PPC_WEAK_FUNC(sub_8219BE60);
PPC_FUNC_IMPL(__imp__sub_8219BE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8219BE68;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821be810
	ctx.lr = 0x8219BE80;
	sub_821BE810(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r10,r11,3400
	ctx.r10.s64 = ctx.r11.s64 + 3400;
	// addi r26,r31,232
	ctx.r26.s64 = ctx.r31.s64 + 232;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219BE98;
	sub_82079FD8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219beac
	if (ctx.cr6.eq) goto loc_8219BEAC;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
	// b 0x8219beb0
	goto loc_8219BEB0;
loc_8219BEAC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219BEB0:
	// stw r3,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,12(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12, ctx.r30.u32);
	// addi r29,r31,256
	ctx.r29.s64 = ctx.r31.s64 + 256;
	// stw r30,16(r26)
	PPC_STORE_U32(ctx.r26.u32 + 16, ctx.r30.u32);
	// stw r30,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219BECC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219bedc
	if (ctx.cr6.eq) goto loc_8219BEDC;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8219bee0
	goto loc_8219BEE0;
loc_8219BEDC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219BEE0:
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// addi r27,r11,21768
	ctx.r27.s64 = ctx.r11.s64 + 21768;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// addi r4,r27,10292
	ctx.r4.s64 = ctx.r27.s64 + 10292;
	// bl 0x82060368
	ctx.lr = 0x8219BF10;
	sub_82060368(ctx, base);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// lwz r9,-31380(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31380);
	// addi r10,r9,104
	ctx.r10.s64 = ctx.r9.s64 + 104;
loc_8219BF20:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x8219bf70
	if (ctx.cr6.eq) goto loc_8219BF70;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,52
	ctx.r10.s64 = ctx.r10.s64 + 52;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8219bf20
	if (ctx.cr6.lt) goto loc_8219BF20;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8219BF40:
	// stw r11,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x8219BF4C;
	sub_82079FD8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r25,r11,-21836
	ctx.r25.s64 = ctx.r11.s64 + -21836;
	// lfs f31,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x8219bf80
	if (ctx.cr6.eq) goto loc_8219BF80;
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8216fcf0
	ctx.lr = 0x8219BF6C;
	sub_8216FCF0(ctx, base);
	// b 0x8219bf84
	goto loc_8219BF84;
loc_8219BF70:
	// mulli r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 * 52;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,116(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// b 0x8219bf40
	goto loc_8219BF40;
loc_8219BF80:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219BF84:
	// lwz r9,-31380(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31380);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r3,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r3.u32);
	// addi r10,r9,104
	ctx.r10.s64 = ctx.r9.s64 + 104;
loc_8219BF94:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// beq cr6,0x8219bfd8
	if (ctx.cr6.eq) goto loc_8219BFD8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,52
	ctx.r10.s64 = ctx.r10.s64 + 52;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8219bf94
	if (ctx.cr6.lt) goto loc_8219BF94;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8219BFB4:
	// stw r11,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x8219BFC0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219bfe8
	if (ctx.cr6.eq) goto loc_8219BFE8;
	// lwz r4,200(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8216fcf0
	ctx.lr = 0x8219BFD4;
	sub_8216FCF0(ctx, base);
	// b 0x8219bfec
	goto loc_8219BFEC;
loc_8219BFD8:
	// mulli r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 * 52;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,116(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// b 0x8219bfb4
	goto loc_8219BFB4;
loc_8219BFE8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219BFEC:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// lfs f31,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// stfs f31,208(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 208, temp.u32);
	// stfs f31,212(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 212, temp.u32);
	// stfs f31,216(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 216, temp.u32);
	// stfs f31,220(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 220, temp.u32);
	// lfs f0,268(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,272(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,276(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,224(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 224, temp.u32);
	// stfs f13,228(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 228, temp.u32);
	// stfs f31,160(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 160, temp.u32);
	// stfs f12,164(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 164, temp.u32);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219c03c
	if (!ctx.cr6.gt) goto loc_8219C03C;
	// twi 31,r0,22
loc_8219C03C:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x8219c054
	if (!ctx.cr6.gt) goto loc_8219C054;
	// twi 31,r0,22
loc_8219C054:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82069380
	ctx.lr = 0x8219C070;
	sub_82069380(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82066558
	ctx.lr = 0x8219C078;
	sub_82066558(ctx, base);
	// stfs f31,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// stfs f31,284(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8219c090
	if (ctx.cr6.lt) goto loc_8219C090;
	// stw r24,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r24.u32);
	// b 0x8219c0a8
	goto loc_8219C0A8;
loc_8219C090:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// stw r8,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r8.u32);
loc_8219C0A8:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8219c104
	if (!ctx.cr6.eq) goto loc_8219C104;
	// li r3,300
	ctx.r3.s64 = 300;
	// bl 0x82079fd8
	ctx.lr = 0x8219C0BC;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219c0e4
	if (ctx.cr6.eq) goto loc_8219C0E4;
	// addi r4,r25,-2685
	ctx.r4.s64 = ctx.r25.s64 + -2685;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x82060190
	ctx.lr = 0x8219C0D4;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821bcdf0
	ctx.lr = 0x8219C0E0;
	sub_821BCDF0(ctx, base);
	// b 0x8219c0e8
	goto loc_8219C0E8;
loc_8219C0E4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219C0E8:
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
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
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_8219C104:
	// li r29,15
	ctx.r29.s64 = 15;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r30.u32);
	// addi r4,r27,10300
	ctx.r4.s64 = ctx.r27.s64 + 10300;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// li r5,15
	ctx.r5.s64 = 15;
	// stb r30,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r30.u8);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x82060368
	ctx.lr = 0x8219C128;
	sub_82060368(ctx, base);
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// addi r4,r27,10316
	ctx.r4.s64 = ctx.r27.s64 + 10316;
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// li r5,15
	ctx.r5.s64 = 15;
	// stw r29,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r29.u32);
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// stb r30,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, ctx.r30.u8);
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// stw r30,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r30.u32);
	// stw r29,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r29.u32);
	// stw r30,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r30.u32);
	// stb r30,204(r1)
	PPC_STORE_U8(ctx.r1.u32 + 204, ctx.r30.u8);
	// bl 0x82060368
	ctx.lr = 0x8219C164;
	sub_82060368(ctx, base);
	// stw r29,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r29.u32);
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// addi r4,r27,10332
	ctx.r4.s64 = ctx.r27.s64 + 10332;
	// stb r30,232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 232, ctx.r30.u8);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r3,r1,228
	ctx.r3.s64 = ctx.r1.s64 + 228;
	// bl 0x82060368
	ctx.lr = 0x8219C180;
	sub_82060368(ctx, base);
	// stw r29,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r29.u32);
	// stw r30,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r30.u32);
	// addi r4,r27,10348
	ctx.r4.s64 = ctx.r27.s64 + 10348;
	// stb r30,260(r1)
	PPC_STORE_U8(ctx.r1.u32 + 260, ctx.r30.u8);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82060368
	ctx.lr = 0x8219C19C;
	sub_82060368(ctx, base);
	// stw r29,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r29.u32);
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r30,288(r1)
	PPC_STORE_U8(ctx.r1.u32 + 288, ctx.r30.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r29,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r29.u32);
	// stw r30,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r30.u32);
	// stb r30,316(r1)
	PPC_STORE_U8(ctx.r1.u32 + 316, ctx.r30.u8);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// bl 0x821bcd20
	ctx.lr = 0x8219C1C4;
	sub_821BCD20(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x8219C1D4;
	sub_821BCC50(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82064cc8
	ctx.lr = 0x8219C1DC;
	sub_82064CC8(ctx, base);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219c1f0
	if (ctx.cr6.lt) goto loc_8219C1F0;
	// lwz r3,160(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// bl 0x8207a630
	ctx.lr = 0x8219C1F0;
	sub_8207A630(ctx, base);
loc_8219C1F0:
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r29,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r29.u32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r30,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, ctx.r30.u8);
	// blt cr6,0x8219c210
	if (ctx.cr6.lt) goto loc_8219C210;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8207a630
	ctx.lr = 0x8219C210;
	sub_8207A630(ctx, base);
loc_8219C210:
	// lwz r11,124(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// blt cr6,0x8219c230
	if (ctx.cr6.lt) goto loc_8219C230;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x8207a630
	ctx.lr = 0x8219C230;
	sub_8207A630(ctx, base);
loc_8219C230:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219C240"))) PPC_WEAK_FUNC(sub_8219C240);
PPC_FUNC_IMPL(__imp__sub_8219C240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8219C248;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821bf3d8
	ctx.lr = 0x8219C25C;
	sub_821BF3D8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// stw r10,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r10.u32);
	// stw r9,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r9.u32);
	// stw r8,52(r6)
	PPC_STORE_U32(ctx.r6.u32 + 52, ctx.r8.u32);
	// lwz r4,196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8219C29C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82079fd8
	ctx.lr = 0x8219C2A4;
	sub_82079FD8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r26,r11,21768
	ctx.r26.s64 = ctx.r11.s64 + 21768;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f31,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x8219c2d4
	if (ctx.cr6.eq) goto loc_8219C2D4;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,204(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x821afc58
	ctx.lr = 0x8219C2D0;
	sub_821AFC58(ctx, base);
	// b 0x8219c2d8
	goto loc_8219C2D8;
loc_8219C2D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219C2D8:
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r3,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r3.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r30.u8);
	// addi r29,r11,-21836
	ctx.r29.s64 = ctx.r11.s64 + -21836;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r29,-2550
	ctx.r4.s64 = ctx.r29.s64 + -2550;
	// bl 0x82060368
	ctx.lr = 0x8219C304;
	sub_82060368(ctx, base);
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r28.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// addi r4,r26,12112
	ctx.r4.s64 = ctx.r26.s64 + 12112;
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060368
	ctx.lr = 0x8219C320;
	sub_82060368(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821ccf40
	ctx.lr = 0x8219C330;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// bl 0x821afbe0
	ctx.lr = 0x8219C33C;
	sub_821AFBE0(ctx, base);
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// li r27,1
	ctx.r27.s64 = 1;
	// li r3,132
	ctx.r3.s64 = 132;
	// stb r27,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r27.u8);
	// bl 0x82079fd8
	ctx.lr = 0x8219C350;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219c370
	if (ctx.cr6.eq) goto loc_8219C370;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,204(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x821afc58
	ctx.lr = 0x8219C36C;
	sub_821AFC58(ctx, base);
	// b 0x8219c374
	goto loc_8219C374;
loc_8219C370:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8219C374:
	// stw r3,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r3.u32);
	// addi r4,r29,-2549
	ctx.r4.s64 = ctx.r29.s64 + -2549;
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// bl 0x82060368
	ctx.lr = 0x8219C394;
	sub_82060368(ctx, base);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// addi r4,r26,12120
	ctx.r4.s64 = ctx.r26.s64 + 12120;
	// stb r30,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r30.u8);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82060368
	ctx.lr = 0x8219C3B0;
	sub_82060368(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821ccf40
	ctx.lr = 0x8219C3C0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// bl 0x821afbe0
	ctx.lr = 0x8219C3CC;
	sub_821AFBE0(ctx, base);
	// lwz r9,296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// stb r27,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r27.u8);
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,228(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	ctx.f12.f64 = double(temp.f32);
	// lfs f31,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// lfs f30,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f30.f64 = double(temp.f32);
	// fneg f10,f0
	ctx.f10.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// fmuls f8,f13,f30
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// fadds f7,f9,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8219C424;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// lfs f6,228(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f6,f31
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f31.f64));
	// fmuls f3,f5,f30
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f30.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8219C454;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,84(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8219C4A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,224(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 224);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219C4B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,88(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8219C4CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,92(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8219C4E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stb r27,300(r31)
	PPC_STORE_U8(ctx.r31.u32 + 300, ctx.r27.u8);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8219a838
	ctx.lr = 0x8219C4F4;
	sub_8219A838(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219C504"))) PPC_WEAK_FUNC(sub_8219C504);
PPC_FUNC_IMPL(__imp__sub_8219C504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219C508"))) PPC_WEAK_FUNC(sub_8219C508);
PPC_FUNC_IMPL(__imp__sub_8219C508) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x8219c534
	if (ctx.cr6.lt) goto loc_8219C534;
	// beq cr6,0x8219c52c
	if (ctx.cr6.eq) goto loc_8219C52C;
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// addi r3,r11,368
	ctx.r3.s64 = ctx.r11.s64 + 368;
	// blr 
	return;
loc_8219C52C:
	// addi r3,r11,364
	ctx.r3.s64 = ctx.r11.s64 + 364;
	// blr 
	return;
loc_8219C534:
	// addi r3,r11,360
	ctx.r3.s64 = ctx.r11.s64 + 360;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219C53C"))) PPC_WEAK_FUNC(sub_8219C53C);
PPC_FUNC_IMPL(__imp__sub_8219C53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219C540"))) PPC_WEAK_FUNC(sub_8219C540);
PPC_FUNC_IMPL(__imp__sub_8219C540) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r6,80
	ctx.r6.s64 = 80;
	// lwz r9,324(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// addi r10,r3,312
	ctx.r10.s64 = ctx.r3.s64 + 312;
	// li r8,0
	ctx.r8.s64 = 0;
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r5,r7,r6
	ctx.r5.s32 = ppc_divw(ctx.r7.s32, ctx.r6.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,-99
	ctx.r5.s64 = -99;
loc_8219C568:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r4,r11,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r9,r4,r6
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8219c584
	if (ctx.cr6.lt) goto loc_8219C584;
	// twi 31,r0,22
loc_8219C584:
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8219c5b0
	if (ctx.cr6.lt) goto loc_8219C5B0;
	// beq cr6,0x8219c5a8
	if (ctx.cr6.eq) goto loc_8219C5A8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8219c5c8
	if (!ctx.cr6.lt) goto loc_8219C5C8;
	// addi r11,r3,368
	ctx.r11.s64 = ctx.r3.s64 + 368;
	// b 0x8219c5b4
	goto loc_8219C5B4;
loc_8219C5A8:
	// addi r11,r3,364
	ctx.r11.s64 = ctx.r3.s64 + 364;
	// b 0x8219c5b4
	goto loc_8219C5B4;
loc_8219C5B0:
	// addi r11,r3,360
	ctx.r11.s64 = ctx.r3.s64 + 360;
loc_8219C5B4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219c5c8
	if (ctx.cr6.eq) goto loc_8219C5C8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r5,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r5.u32);
	// stw r11,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r11.u32);
loc_8219C5C8:
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r7,r7,80
	ctx.r7.s64 = ctx.r7.s64 + 80;
	// subf r4,r9,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw r11,r4,r6
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8219c568
	if (ctx.cr6.lt) goto loc_8219C568;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219C5EC"))) PPC_WEAK_FUNC(sub_8219C5EC);
PPC_FUNC_IMPL(__imp__sub_8219C5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219C5F0"))) PPC_WEAK_FUNC(sub_8219C5F0);
PPC_FUNC_IMPL(__imp__sub_8219C5F0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,3304
	ctx.r10.s64 = ctx.r11.s64 + 3304;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219C600"))) PPC_WEAK_FUNC(sub_8219C600);
PPC_FUNC_IMPL(__imp__sub_8219C600) {
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
	// std r4,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r4.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,136(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8219c6c0
	if (ctx.cr6.lt) goto loc_8219C6C0;
	// beq cr6,0x8219c680
	if (ctx.cr6.eq) goto loc_8219C680;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8219c640
	if (ctx.cr6.lt) goto loc_8219C640;
	// bl 0x82188f18
	ctx.lr = 0x8219C63C;
	sub_82188F18(ctx, base);
	// b 0x8219c6fc
	goto loc_8219C6FC;
loc_8219C640:
	// bl 0x82188f18
	ctx.lr = 0x8219C644;
	sub_82188F18(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,300
	ctx.r11.s64 = ctx.r11.s64 + 300;
loc_8219C654:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8219c678
	if (ctx.cr6.eq) goto loc_8219C678;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// ble cr6,0x8219c654
	if (!ctx.cr6.gt) goto loc_8219C654;
	// li r4,9
	ctx.r4.s64 = 9;
	// b 0x8219c6f4
	goto loc_8219C6F4;
loc_8219C678:
	// li r4,9
	ctx.r4.s64 = 9;
	// b 0x8219c6f8
	goto loc_8219C6F8;
loc_8219C680:
	// bl 0x82188f18
	ctx.lr = 0x8219C684;
	sub_82188F18(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,300
	ctx.r11.s64 = ctx.r11.s64 + 300;
loc_8219C694:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8219c6b8
	if (ctx.cr6.eq) goto loc_8219C6B8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// ble cr6,0x8219c694
	if (!ctx.cr6.gt) goto loc_8219C694;
	// li r4,8
	ctx.r4.s64 = 8;
	// b 0x8219c6f4
	goto loc_8219C6F4;
loc_8219C6B8:
	// li r4,8
	ctx.r4.s64 = 8;
	// b 0x8219c6f8
	goto loc_8219C6F8;
loc_8219C6C0:
	// bl 0x82188f18
	ctx.lr = 0x8219C6C4;
	sub_82188F18(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,300
	ctx.r11.s64 = ctx.r11.s64 + 300;
loc_8219C6D4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8219c720
	if (ctx.cr6.eq) goto loc_8219C720;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// ble cr6,0x8219c6d4
	if (!ctx.cr6.gt) goto loc_8219C6D4;
	// li r4,7
	ctx.r4.s64 = 7;
loc_8219C6F4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8219C6F8:
	// bl 0x82188f90
	ctx.lr = 0x8219C6FC;
	sub_82188F90(ctx, base);
loc_8219C6FC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821b6210
	ctx.lr = 0x8219C708;
	sub_821B6210(ctx, base);
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
loc_8219C720:
	// li r4,7
	ctx.r4.s64 = 7;
	// b 0x8219c6f8
	goto loc_8219C6F8;
}

__attribute__((alias("__imp__sub_8219C728"))) PPC_WEAK_FUNC(sub_8219C728);
PPC_FUNC_IMPL(__imp__sub_8219C728) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8219C730;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,312
	ctx.r3.s64 = ctx.r3.s64 + 312;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// bl 0x82063390
	ctx.lr = 0x8219C748;
	sub_82063390(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219C760;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lwz r30,28(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// bne cr6,0x8219c7b8
	if (!ctx.cr6.eq) goto loc_8219C7B8;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8219C770:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,360(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,23176
	ctx.r8.s64 = ctx.r9.s64 + 23176;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// lwz r6,364(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 364);
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// lwz r5,368(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 368);
	// stw r5,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r5.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
loc_8219C7A0:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219c7b0
	if (ctx.cr6.eq) goto loc_8219C7B0;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8219C7B0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8219C7B8:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x8219c770
	if (ctx.cr6.eq) goto loc_8219C770;
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// beq cr6,0x8219c7d4
	if (ctx.cr6.eq) goto loc_8219C7D4;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// beq cr6,0x8219c770
	if (ctx.cr6.eq) goto loc_8219C770;
	// b 0x8219c7a0
	goto loc_8219C7A0;
loc_8219C7D4:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r4,r31,360
	ctx.r4.s64 = ctx.r31.s64 + 360;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// lwz r9,-31348(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// bne cr6,0x8219c7f0
	if (!ctx.cr6.eq) goto loc_8219C7F0;
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
loc_8219C7F0:
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// bl 0x82187e88
	ctx.lr = 0x8219C808;
	sub_82187E88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8219c540
	ctx.lr = 0x8219C810;
	sub_8219C540(ctx, base);
	// bl 0x821b63c0
	ctx.lr = 0x8219C814;
	sub_821B63C0(ctx, base);
	// b 0x8219c7a0
	goto loc_8219C7A0;
}

__attribute__((alias("__imp__sub_8219C818"))) PPC_WEAK_FUNC(sub_8219C818);
PPC_FUNC_IMPL(__imp__sub_8219C818) {
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
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// bl 0x821b62d0
	ctx.lr = 0x8219C834;
	sub_821B62D0(ctx, base);
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r8,328(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// li r9,80
	ctx.r9.s64 = 80;
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8219c858
	if (ctx.cr6.lt) goto loc_8219C858;
	// twi 31,r0,22
loc_8219C858:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8219c890
	if (ctx.cr6.lt) goto loc_8219C890;
	// beq cr6,0x8219c888
	if (ctx.cr6.eq) goto loc_8219C888;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8219c8dc
	if (!ctx.cr6.lt) goto loc_8219C8DC;
	// addi r11,r31,368
	ctx.r11.s64 = ctx.r31.s64 + 368;
	// b 0x8219c894
	goto loc_8219C894;
loc_8219C888:
	// addi r11,r31,364
	ctx.r11.s64 = ctx.r31.s64 + 364;
	// b 0x8219c894
	goto loc_8219C894;
loc_8219C890:
	// addi r11,r31,360
	ctx.r11.s64 = ctx.r31.s64 + 360;
loc_8219C894:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219c8dc
	if (ctx.cr6.eq) goto loc_8219C8DC;
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addic. r31,r31,360
	ctx.xer.ca = ctx.r31.u32 > 4294966935;
	ctx.r31.s64 = ctx.r31.s64 + 360;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bne 0x8219c8b8
	if (!ctx.cr0.eq) goto loc_8219C8B8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r31,16(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
loc_8219C8B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82189158
	ctx.lr = 0x8219C8C4;
	sub_82189158(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82189158
	ctx.lr = 0x8219C8D0;
	sub_82189158(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82189158
	ctx.lr = 0x8219C8DC;
	sub_82189158(ctx, base);
loc_8219C8DC:
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

__attribute__((alias("__imp__sub_8219C8F0"))) PPC_WEAK_FUNC(sub_8219C8F0);
PPC_FUNC_IMPL(__imp__sub_8219C8F0) {
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
	// std r4,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r4.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,140(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219c92c
	if (ctx.cr6.lt) goto loc_8219C92C;
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8219c92c
	if (ctx.cr6.eq) goto loc_8219C92C;
	// bl 0x82188f18
	ctx.lr = 0x8219C92C;
	sub_82188F18(ctx, base);
loc_8219C92C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821b6548
	ctx.lr = 0x8219C938;
	sub_821B6548(ctx, base);
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

__attribute__((alias("__imp__sub_8219C950"))) PPC_WEAK_FUNC(sub_8219C950);
PPC_FUNC_IMPL(__imp__sub_8219C950) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8219C958;
	__savegprlr_23(ctx, base);
	// stwu r1,-1920(r1)
	ea = -1920 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// bl 0x821b6748
	ctx.lr = 0x8219C96C;
	sub_821B6748(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r9,r10,3304
	ctx.r9.s64 = ctx.r10.s64 + 3304;
	// addi r29,r11,-31220
	ctx.r29.s64 = ctx.r11.s64 + -31220;
	// stw r9,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r9.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r29,-304
	ctx.r4.s64 = ctx.r29.s64 + -304;
	// addi r3,r25,220
	ctx.r3.s64 = ctx.r25.s64 + 220;
	// bl 0x82060368
	ctx.lr = 0x8219C990;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r4,r29,-296
	ctx.r4.s64 = ctx.r29.s64 + -296;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x8219C9B4;
	sub_82060368(ctx, base);
	// li r28,100
	ctx.r28.s64 = 100;
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r27.u32);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r28.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219C9E0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219c9f8
	if (ctx.cr6.eq) goto loc_8219C9F8;
	// addi r11,r1,136
	ctx.r11.s64 = ctx.r1.s64 + 136;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// b 0x8219c9fc
	goto loc_8219C9FC;
loc_8219C9F8:
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
loc_8219C9FC:
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r4,r29,-284
	ctx.r4.s64 = ctx.r29.s64 + -284;
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r30.u32);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CA24;
	sub_82060368(ctx, base);
	// stw r27,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r27.u32);
	// stw r31,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r27,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r27.u32);
	// stw r28,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r28.u32);
	// stw r28,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r28.u32);
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stw r28,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219CA48;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219ca60
	if (ctx.cr6.eq) goto loc_8219CA60;
	// addi r11,r1,216
	ctx.r11.s64 = ctx.r1.s64 + 216;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// b 0x8219ca64
	goto loc_8219CA64;
loc_8219CA60:
	// stw r31,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r31.u32);
loc_8219CA64:
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r31.u32);
	// addi r4,r29,-272
	ctx.r4.s64 = ctx.r29.s64 + -272;
	// stw r31,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r31.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r30.u32);
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r31.u32);
	// stb r31,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CA8C;
	sub_82060368(ctx, base);
	// li r23,2
	ctx.r23.s64 = 2;
	// stw r31,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r23,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r23.u32);
	// stw r27,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r27.u32);
	// stw r28,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r28.u32);
	// stw r28,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r28.u32);
	// stw r31,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r31.u32);
	// stw r28,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219CAB4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219cacc
	if (ctx.cr6.eq) goto loc_8219CACC;
	// addi r11,r1,296
	ctx.r11.s64 = ctx.r1.s64 + 296;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// b 0x8219cad0
	goto loc_8219CAD0;
loc_8219CACC:
	// stw r31,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r31.u32);
loc_8219CAD0:
	// stw r31,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r31.u32);
	// addi r4,r29,-256
	ctx.r4.s64 = ctx.r29.s64 + -256;
	// stw r31,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r31.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r31,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r31.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stw r30,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r30.u32);
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r31.u32);
	// stb r31,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CAF8;
	sub_82060368(ctx, base);
	// li r24,-199
	ctx.r24.s64 = -199;
	// li r28,20
	ctx.r28.s64 = 20;
	// stw r31,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r31.u32);
	// stw r24,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r24.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r31.u32);
	// stw r28,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r28.u32);
	// stw r31,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r31.u32);
	// stw r31,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r31.u32);
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219CB24;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219cb3c
	if (ctx.cr6.eq) goto loc_8219CB3C;
	// addi r11,r1,376
	ctx.r11.s64 = ctx.r1.s64 + 376;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r3.u32);
	// b 0x8219cb40
	goto loc_8219CB40;
loc_8219CB3C:
	// stw r31,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r31.u32);
loc_8219CB40:
	// stw r31,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r31.u32);
	// addi r4,r29,-248
	ctx.r4.s64 = ctx.r29.s64 + -248;
	// stw r31,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r31.u32);
	// li r5,15
	ctx.r5.s64 = 15;
	// stw r31,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r31.u32);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// stw r30,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r30.u32);
	// stw r31,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r31.u32);
	// stb r31,404(r1)
	PPC_STORE_U8(ctx.r1.u32 + 404, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CB68;
	sub_82060368(ctx, base);
	// addi r11,r1,440
	ctx.r11.s64 = ctx.r1.s64 + 440;
	// li r26,3
	ctx.r26.s64 = 3;
	// stw r31,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r31.u32);
	// stw r31,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r26,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r26.u32);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// bl 0x82079fd8
	ctx.lr = 0x8219CB8C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219cba4
	if (ctx.cr6.eq) goto loc_8219CBA4;
	// addi r11,r1,456
	ctx.r11.s64 = ctx.r1.s64 + 456;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// b 0x8219cba8
	goto loc_8219CBA8;
loc_8219CBA4:
	// stw r31,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r31.u32);
loc_8219CBA8:
	// stw r31,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r31.u32);
	// addi r4,r29,-232
	ctx.r4.s64 = ctx.r29.s64 + -232;
	// stw r31,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r31.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r31,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r31.u32);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// stw r30,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r30.u32);
	// stw r31,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r31.u32);
	// stb r31,484(r1)
	PPC_STORE_U8(ctx.r1.u32 + 484, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CBD0;
	sub_82060368(ctx, base);
	// stw r24,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r24.u32);
	// stw r31,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r31.u32);
	// stw r28,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r28.u32);
	// stw r31,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r31.u32);
	// stw r31,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r31.u32);
	// stw r31,532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 532, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8219CBF4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219cc0c
	if (ctx.cr6.eq) goto loc_8219CC0C;
	// addi r11,r1,536
	ctx.r11.s64 = ctx.r1.s64 + 536;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r3.u32);
	// b 0x8219cc10
	goto loc_8219CC10;
loc_8219CC0C:
	// stw r31,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r31.u32);
loc_8219CC10:
	// stw r31,548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 548, ctx.r31.u32);
	// addi r4,r29,-224
	ctx.r4.s64 = ctx.r29.s64 + -224;
	// stw r31,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r31.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r31,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r31.u32);
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// stw r30,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r30.u32);
	// stw r31,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r31.u32);
	// stb r31,564(r1)
	PPC_STORE_U8(ctx.r1.u32 + 564, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CC38;
	sub_82060368(ctx, base);
	// addi r11,r1,600
	ctx.r11.s64 = ctx.r1.s64 + 600;
	// li r28,4
	ctx.r28.s64 = 4;
	// stw r31,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r31.u32);
	// stw r31,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r28,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r28.u32);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// bl 0x82079fd8
	ctx.lr = 0x8219CC5C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219cc74
	if (ctx.cr6.eq) goto loc_8219CC74;
	// addi r11,r1,616
	ctx.r11.s64 = ctx.r1.s64 + 616;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// b 0x8219cc78
	goto loc_8219CC78;
loc_8219CC74:
	// stw r31,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r31.u32);
loc_8219CC78:
	// stw r31,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r31.u32);
	// addi r4,r29,-216
	ctx.r4.s64 = ctx.r29.s64 + -216;
	// stw r31,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r31,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r31.u32);
	// addi r3,r1,644
	ctx.r3.s64 = ctx.r1.s64 + 644;
	// stw r31,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, ctx.r31.u32);
	// stw r30,668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 668, ctx.r30.u32);
	// stw r31,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r31.u32);
	// stb r31,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CCA4;
	sub_82060368(ctx, base);
	// stw r30,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r30.u32);
	// stw r31,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, ctx.r31.u32);
	// addi r4,r29,-192
	ctx.r4.s64 = ctx.r29.s64 + -192;
	// stb r31,676(r1)
	PPC_STORE_U8(ctx.r1.u32 + 676, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r30,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r30.u32);
	// addi r3,r1,732
	ctx.r3.s64 = ctx.r1.s64 + 732;
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r31.u32);
	// stb r31,704(r1)
	PPC_STORE_U8(ctx.r1.u32 + 704, ctx.r31.u8);
	// stw r27,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, ctx.r27.u32);
	// stw r30,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r30.u32);
	// stw r31,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r31.u32);
	// stb r31,736(r1)
	PPC_STORE_U8(ctx.r1.u32 + 736, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CCDC;
	sub_82060368(ctx, base);
	// stw r30,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, ctx.r30.u32);
	// stw r31,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r31.u32);
	// addi r4,r29,-168
	ctx.r4.s64 = ctx.r29.s64 + -168;
	// stb r31,764(r1)
	PPC_STORE_U8(ctx.r1.u32 + 764, ctx.r31.u8);
	// li r5,23
	ctx.r5.s64 = 23;
	// stw r30,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r30.u32);
	// addi r3,r1,820
	ctx.r3.s64 = ctx.r1.s64 + 820;
	// stw r31,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r31.u32);
	// stb r31,792(r1)
	PPC_STORE_U8(ctx.r1.u32 + 792, ctx.r31.u8);
	// stw r23,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, ctx.r23.u32);
	// stw r30,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r30.u32);
	// stw r31,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r31.u32);
	// stb r31,824(r1)
	PPC_STORE_U8(ctx.r1.u32 + 824, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CD14;
	sub_82060368(ctx, base);
	// stw r30,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r30.u32);
	// stw r31,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r31.u32);
	// addi r4,r29,-144
	ctx.r4.s64 = ctx.r29.s64 + -144;
	// stb r31,852(r1)
	PPC_STORE_U8(ctx.r1.u32 + 852, ctx.r31.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// stw r30,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, ctx.r30.u32);
	// addi r3,r1,908
	ctx.r3.s64 = ctx.r1.s64 + 908;
	// stw r31,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r31.u32);
	// stb r31,880(r1)
	PPC_STORE_U8(ctx.r1.u32 + 880, ctx.r31.u8);
	// stw r26,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, ctx.r26.u32);
	// stw r30,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r30.u32);
	// stw r31,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r31.u32);
	// stb r31,912(r1)
	PPC_STORE_U8(ctx.r1.u32 + 912, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CD4C;
	sub_82060368(ctx, base);
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r30.u32);
	// stw r31,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, ctx.r31.u32);
	// addi r4,r29,-124
	ctx.r4.s64 = ctx.r29.s64 + -124;
	// stb r31,940(r1)
	PPC_STORE_U8(ctx.r1.u32 + 940, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r30,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r30.u32);
	// addi r3,r1,996
	ctx.r3.s64 = ctx.r1.s64 + 996;
	// stw r31,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r31.u32);
	// stb r31,968(r1)
	PPC_STORE_U8(ctx.r1.u32 + 968, ctx.r31.u8);
	// stw r28,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r28.u32);
	// stw r30,1020(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1020, ctx.r30.u32);
	// stw r31,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r31.u32);
	// stb r31,1000(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1000, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CD84;
	sub_82060368(ctx, base);
	// stw r30,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, ctx.r30.u32);
	// stw r31,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r31.u32);
	// addi r4,r29,-100
	ctx.r4.s64 = ctx.r29.s64 + -100;
	// stb r31,1028(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1028, ctx.r31.u8);
	// li r5,25
	ctx.r5.s64 = 25;
	// stw r30,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r30.u32);
	// addi r3,r1,1096
	ctx.r3.s64 = ctx.r1.s64 + 1096;
	// stw r31,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r31.u32);
	// stb r31,1056(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1056, ctx.r31.u8);
	// stw r31,1088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1088, ctx.r31.u32);
	// stw r31,1092(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1092, ctx.r31.u32);
	// stw r30,1120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1120, ctx.r30.u32);
	// stw r31,1116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1116, ctx.r31.u32);
	// stb r31,1100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1100, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CDC0;
	sub_82060368(ctx, base);
	// stw r30,1148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1148, ctx.r30.u32);
	// stw r31,1144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1144, ctx.r31.u32);
	// addi r4,r29,-72
	ctx.r4.s64 = ctx.r29.s64 + -72;
	// stb r31,1128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1128, ctx.r31.u8);
	// li r5,25
	ctx.r5.s64 = 25;
	// stw r30,1176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1176, ctx.r30.u32);
	// addi r3,r1,1244
	ctx.r3.s64 = ctx.r1.s64 + 1244;
	// stw r31,1172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1172, ctx.r31.u32);
	// stb r31,1156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1156, ctx.r31.u8);
	// stw r30,1204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1204, ctx.r30.u32);
	// stw r31,1200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1200, ctx.r31.u32);
	// stb r31,1184(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1184, ctx.r31.u8);
	// stw r30,1232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1232, ctx.r30.u32);
	// stw r31,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r31.u32);
	// stb r31,1212(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1212, ctx.r31.u8);
	// stw r27,1236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1236, ctx.r27.u32);
	// stw r31,1240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1240, ctx.r31.u32);
	// stw r30,1268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1268, ctx.r30.u32);
	// stw r31,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, ctx.r31.u32);
	// stb r31,1248(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1248, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x8219CE14;
	sub_82060368(ctx, base);
	// stw r30,1296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1296, ctx.r30.u32);
	// stw r31,1292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1292, ctx.r31.u32);
	// addi r4,r29,-44
	ctx.r4.s64 = ctx.r29.s64 + -44;
	// stb r31,1276(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1276, ctx.r31.u8);
	// addi r3,r1,1392
	ctx.r3.s64 = ctx.r1.s64 + 1392;
	// stw r30,1324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1324, ctx.r30.u32);
	// stw r31,1320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1320, ctx.r31.u32);
	// stb r31,1304(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1304, ctx.r31.u8);
	// stw r30,1352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1352, ctx.r30.u32);
	// stw r31,1348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1348, ctx.r31.u32);
	// stb r31,1332(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1332, ctx.r31.u8);
	// stw r30,1380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1380, ctx.r30.u32);
	// stw r31,1376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1376, ctx.r31.u32);
	// stb r31,1360(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1360, ctx.r31.u8);
	// stw r23,1384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1384, ctx.r23.u32);
	// stw r31,1388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1388, ctx.r31.u32);
	// bl 0x82060190
	ctx.lr = 0x8219CE58;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1420
	ctx.r3.s64 = ctx.r1.s64 + 1420;
	// bl 0x820602f0
	ctx.lr = 0x8219CE68;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1448
	ctx.r3.s64 = ctx.r1.s64 + 1448;
	// bl 0x820602f0
	ctx.lr = 0x8219CE78;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1476
	ctx.r3.s64 = ctx.r1.s64 + 1476;
	// bl 0x820602f0
	ctx.lr = 0x8219CE88;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1504
	ctx.r3.s64 = ctx.r1.s64 + 1504;
	// bl 0x820602f0
	ctx.lr = 0x8219CE98;
	sub_820602F0(ctx, base);
	// stw r26,1532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1532, ctx.r26.u32);
	// stw r31,1536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1536, ctx.r31.u32);
	// addi r4,r29,-16
	ctx.r4.s64 = ctx.r29.s64 + -16;
	// addi r3,r1,1540
	ctx.r3.s64 = ctx.r1.s64 + 1540;
	// bl 0x82060190
	ctx.lr = 0x8219CEAC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1568
	ctx.r3.s64 = ctx.r1.s64 + 1568;
	// bl 0x820602f0
	ctx.lr = 0x8219CEBC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1596
	ctx.r3.s64 = ctx.r1.s64 + 1596;
	// bl 0x820602f0
	ctx.lr = 0x8219CECC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1624
	ctx.r3.s64 = ctx.r1.s64 + 1624;
	// bl 0x820602f0
	ctx.lr = 0x8219CEDC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1652
	ctx.r3.s64 = ctx.r1.s64 + 1652;
	// bl 0x820602f0
	ctx.lr = 0x8219CEEC;
	sub_820602F0(ctx, base);
	// stw r28,1680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1680, ctx.r28.u32);
	// stw r31,1684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1684, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,1688
	ctx.r3.s64 = ctx.r1.s64 + 1688;
	// bl 0x82060190
	ctx.lr = 0x8219CF00;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1716
	ctx.r3.s64 = ctx.r1.s64 + 1716;
	// bl 0x820602f0
	ctx.lr = 0x8219CF10;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1744
	ctx.r3.s64 = ctx.r1.s64 + 1744;
	// bl 0x820602f0
	ctx.lr = 0x8219CF20;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1772
	ctx.r3.s64 = ctx.r1.s64 + 1772;
	// bl 0x820602f0
	ctx.lr = 0x8219CF30;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1800
	ctx.r3.s64 = ctx.r1.s64 + 1800;
	// bl 0x820602f0
	ctx.lr = 0x8219CF40;
	sub_820602F0(ctx, base);
	// addic. r3,r25,312
	ctx.xer.ca = ctx.r25.u32 > 4294966983;
	ctx.r3.s64 = ctx.r25.s64 + 312;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8219cf54
	if (ctx.cr0.eq) goto loc_8219CF54;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821b6bd0
	ctx.lr = 0x8219CF54;
	sub_821B6BD0(ctx, base);
loc_8219CF54:
	// li r5,5
	ctx.r5.s64 = 5;
	// lwz r3,128(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 128);
	// addi r4,r1,640
	ctx.r4.s64 = ctx.r1.s64 + 640;
	// bl 0x821bcd20
	ctx.lr = 0x8219CF64;
	sub_821BCD20(ctx, base);
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r1,1088
	ctx.r4.s64 = ctx.r1.s64 + 1088;
	// lwz r3,128(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x8219CF74;
	sub_821BCC50(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,360(r25)
	PPC_STORE_U32(ctx.r25.u32 + 360, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 364, ctx.r8.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r7,368(r25)
	PPC_STORE_U32(ctx.r25.u32 + 368, ctx.r7.u32);
	// bl 0x8219c540
	ctx.lr = 0x8219CFA0;
	sub_8219C540(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r6,r6,19656
	ctx.r6.s64 = ctx.r6.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x82060818
	ctx.lr = 0x8219CFB8;
	sub_82060818(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r6,r4,19288
	ctx.r6.s64 = ctx.r4.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x82060818
	ctx.lr = 0x8219CFD0;
	sub_82060818(ctx, base);
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r6,r3,28680
	ctx.r6.s64 = ctx.r3.s64 + 28680;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x8219CFE8;
	sub_82060818(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,1920
	ctx.r1.s64 = ctx.r1.s64 + 1920;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219CFF4"))) PPC_WEAK_FUNC(sub_8219CFF4);
PPC_FUNC_IMPL(__imp__sub_8219CFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219CFF8"))) PPC_WEAK_FUNC(sub_8219CFF8);
PPC_FUNC_IMPL(__imp__sub_8219CFF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8219D008"))) PPC_WEAK_FUNC(sub_8219D008);
PPC_FUNC_IMPL(__imp__sub_8219D008) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x8219d024
	if (ctx.cr6.lt) goto loc_8219D024;
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// addi r3,r11,388
	ctx.r3.s64 = ctx.r11.s64 + 388;
	// blr 
	return;
loc_8219D024:
	// addi r3,r11,384
	ctx.r3.s64 = ctx.r11.s64 + 384;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D02C"))) PPC_WEAK_FUNC(sub_8219D02C);
PPC_FUNC_IMPL(__imp__sub_8219D02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219D030"))) PPC_WEAK_FUNC(sub_8219D030);
PPC_FUNC_IMPL(__imp__sub_8219D030) {
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
	// lwz r4,196(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219D05C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r6,292(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r7,r8,-2064
	ctx.r7.s64 = ctx.r8.s64 + -2064;
	// stb r11,12(r6)
	PPC_STORE_U8(ctx.r6.u32 + 12, ctx.r11.u8);
	// lwz r5,296(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// stb r11,12(r5)
	PPC_STORE_U8(ctx.r5.u32 + 12, ctx.r11.u8);
	// lwz r9,-31352(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// lfs f12,60(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 60);
	ctx.f12.f64 = double(temp.f32);
	// lwz r4,76(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,80(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219d0c4
	if (ctx.cr6.lt) goto loc_8219D0C4;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219d0c4
	if (ctx.cr6.gt) goto loc_8219D0C4;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r8,r10,0,13,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8219d0c4
	if (ctx.cr6.eq) goto loc_8219D0C4;
	// lfs f0,280(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f12
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f13,280(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
loc_8219D0C4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8219d0e8
	if (ctx.cr6.gt) goto loc_8219D0E8;
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// stfs f0,280(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// stb r8,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
loc_8219D0E8:
	// lwz r11,248(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r7,244(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// lfs f0,156(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r31,232
	ctx.r10.s64 = ctx.r31.s64 + 232;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// srawi r5,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 2;
	// clrldi r4,r5,32
	ctx.r4.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// blt cr6,0x8219d1e0
	if (ctx.cr6.lt) goto loc_8219D1E0;
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r11,36(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219d164
	if (ctx.cr6.lt) goto loc_8219D164;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219d164
	if (ctx.cr6.gt) goto loc_8219D164;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r9,60(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r7,r9,0,12,12
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8219d164
	if (ctx.cr6.eq) goto loc_8219D164;
	// lfs f11,280(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,280(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
loc_8219D164:
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f12,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// clrldi r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmsubs f8,f9,f13,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 - ctx.f0.f64));
	// fcmpu cr6,f12,f8
	ctx.cr6.compare(ctx.f12.f64, ctx.f8.f64);
	// blt cr6,0x8219d1e8
	if (ctx.cr6.lt) goto loc_8219D1E8;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r9,296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// subf r7,r10,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// clrldi r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmsubs f9,f10,f13,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 - ctx.f0.f64));
	// stfs f9,280(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// stb r8,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r8.u8);
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
loc_8219D1E0:
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// stb r8,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
loc_8219D1E8:
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

__attribute__((alias("__imp__sub_8219D1FC"))) PPC_WEAK_FUNC(sub_8219D1FC);
PPC_FUNC_IMPL(__imp__sub_8219D1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219D200"))) PPC_WEAK_FUNC(sub_8219D200);
PPC_FUNC_IMPL(__imp__sub_8219D200) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,7504
	ctx.r9.s64 = ctx.r11.s64 + 7504;
	// stw r10,340(r3)
	PPC_STORE_U32(ctx.r3.u32 + 340, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D218"))) PPC_WEAK_FUNC(sub_8219D218);
PPC_FUNC_IMPL(__imp__sub_8219D218) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d230
	if (!ctx.cr6.lt) goto loc_8219D230;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8219d23c
	goto loc_8219D23C;
loc_8219D230:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d240
	if (!ctx.cr6.gt) goto loc_8219D240;
	// li r10,7
	ctx.r10.s64 = 7;
loc_8219D23C:
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
loc_8219D240:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// bgt cr6,0x8219d2a8
	if (ctx.cr6.gt) goto loc_8219D2A8;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219d270
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D270;
	// bdzf 4*cr6+eq,0x8219d280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D280;
	// bdzf 4*cr6+eq,0x8219d290
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D290;
	// bne cr6,0x8219d2a0
	if (!ctx.cr6.eq) goto loc_8219D2A0;
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_8219D270:
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_8219D280:
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_8219D290:
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_8219D2A0:
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
loc_8219D2A8:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D2B0"))) PPC_WEAK_FUNC(sub_8219D2B0);
PPC_FUNC_IMPL(__imp__sub_8219D2B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,7504
	ctx.r9.s64 = ctx.r11.s64 + 7504;
	// stw r10,340(r3)
	PPC_STORE_U32(ctx.r3.u32 + 340, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D2C8"))) PPC_WEAK_FUNC(sub_8219D2C8);
PPC_FUNC_IMPL(__imp__sub_8219D2C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d2e4
	if (!ctx.cr6.lt) goto loc_8219D2E4;
	// stw r3,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r3.u32);
	// b 0x8219d2f4
	goto loc_8219D2F4;
loc_8219D2E4:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d2f4
	if (!ctx.cr6.gt) goto loc_8219D2F4;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
loc_8219D2F4:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// mulli r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 * 44;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219d32c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D32C;
	// bdzf 4*cr6+eq,0x8219d334
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D334;
	// bdzf 4*cr6+eq,0x8219d33c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D33C;
	// bne cr6,0x8219d344
	if (!ctx.cr6.eq) goto loc_8219D344;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// blr 
	return;
loc_8219D32C:
	// addi r3,r11,28
	ctx.r3.s64 = ctx.r11.s64 + 28;
	// blr 
	return;
loc_8219D334:
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// blr 
	return;
loc_8219D33C:
	// addi r3,r11,36
	ctx.r3.s64 = ctx.r11.s64 + 36;
	// blr 
	return;
loc_8219D344:
	// addi r3,r11,40
	ctx.r3.s64 = ctx.r11.s64 + 40;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D34C"))) PPC_WEAK_FUNC(sub_8219D34C);
PPC_FUNC_IMPL(__imp__sub_8219D34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219D350"))) PPC_WEAK_FUNC(sub_8219D350);
PPC_FUNC_IMPL(__imp__sub_8219D350) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,7504
	ctx.r9.s64 = ctx.r11.s64 + 7504;
	// stw r10,340(r3)
	PPC_STORE_U32(ctx.r3.u32 + 340, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D368"))) PPC_WEAK_FUNC(sub_8219D368);
PPC_FUNC_IMPL(__imp__sub_8219D368) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d380
	if (!ctx.cr6.lt) goto loc_8219D380;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8219d38c
	goto loc_8219D38C;
loc_8219D380:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d390
	if (!ctx.cr6.gt) goto loc_8219D390;
	// li r10,7
	ctx.r10.s64 = 7;
loc_8219D38C:
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
loc_8219D390:
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r4,7
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 7, ctx.xer);
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// mulli r9,r9,44
	ctx.r9.s64 = ctx.r9.s64 * 44;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bgt cr6,0x8219d41c
	if (ctx.cr6.gt) goto loc_8219D41C;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219d3dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D3DC;
	// bdzf 4*cr6+eq,0x8219d3e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D3E8;
	// bdzf 4*cr6+eq,0x8219d3f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D3F4;
	// bdzf 4*cr6+eq,0x8219d400
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D400;
	// bdzf 4*cr6+eq,0x8219d40c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D40C;
	// bdzf 4*cr6+eq,0x8219d41c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D41C;
	// bne cr6,0x8219d418
	if (!ctx.cr6.eq) goto loc_8219D418;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_8219D3DC:
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_8219D3E8:
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_8219D3F4:
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_8219D400:
	// addi r10,r11,20
	ctx.r10.s64 = ctx.r11.s64 + 20;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_8219D40C:
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_8219D418:
	// addi r10,r3,364
	ctx.r10.s64 = ctx.r3.s64 + 364;
loc_8219D41C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D424"))) PPC_WEAK_FUNC(sub_8219D424);
PPC_FUNC_IMPL(__imp__sub_8219D424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219D428"))) PPC_WEAK_FUNC(sub_8219D428);
PPC_FUNC_IMPL(__imp__sub_8219D428) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,7504
	ctx.r9.s64 = ctx.r11.s64 + 7504;
	// stw r10,340(r3)
	PPC_STORE_U32(ctx.r3.u32 + 340, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D440"))) PPC_WEAK_FUNC(sub_8219D440);
PPC_FUNC_IMPL(__imp__sub_8219D440) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d458
	if (!ctx.cr6.lt) goto loc_8219D458;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8219d464
	goto loc_8219D464;
loc_8219D458:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d468
	if (!ctx.cr6.gt) goto loc_8219D468;
	// li r10,7
	ctx.r10.s64 = 7;
loc_8219D464:
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_8219D468:
	// lwz r10,364(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r4,5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 5, ctx.xer);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219d4bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D4BC;
	// bdzf 4*cr6+eq,0x8219d4c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D4C4;
	// bdzf 4*cr6+eq,0x8219d4cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D4CC;
	// bdzf 4*cr6+eq,0x8219d4d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D4D4;
	// bne cr6,0x8219d4dc
	if (!ctx.cr6.eq) goto loc_8219D4DC;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_8219D4BC:
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// blr 
	return;
loc_8219D4C4:
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// blr 
	return;
loc_8219D4CC:
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// blr 
	return;
loc_8219D4D4:
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// blr 
	return;
loc_8219D4DC:
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D4E4"))) PPC_WEAK_FUNC(sub_8219D4E4);
PPC_FUNC_IMPL(__imp__sub_8219D4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219D4E8"))) PPC_WEAK_FUNC(sub_8219D4E8);
PPC_FUNC_IMPL(__imp__sub_8219D4E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d500
	if (!ctx.cr6.lt) goto loc_8219D500;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8219d50c
	goto loc_8219D50C;
loc_8219D500:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d510
	if (!ctx.cr6.gt) goto loc_8219D510;
	// li r10,7
	ctx.r10.s64 = 7;
loc_8219D50C:
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_8219D510:
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r4,13
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 13, ctx.xer);
	// rlwinm r9,r9,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// bgt cr6,0x8219d5e0
	if (ctx.cr6.gt) {
		sub_8219D5E0(ctx, base);
		return;
	}
	// lis r12,-32230
	ctx.r12.s64 = -2112225280;
	// rlwinm r0,r4,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-10940
	ctx.r12.s64 = ctx.r12.s64 + -10940;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8219D544"))) PPC_WEAK_FUNC(sub_8219D544);
PPC_FUNC_IMPL(__imp__sub_8219D544) {
	PPC_FUNC_PROLOGUE();
	// lwz r16,-10884(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10884);
	// lwz r16,-10872(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10872);
	// lwz r16,-10824(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10824);
	// lwz r16,-10860(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10860);
	// lwz r16,-10848(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10848);
	// lwz r16,-10836(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10836);
	// lwz r16,-10784(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10784);
	// lwz r16,-10812(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10812);
	// lwz r16,-10800(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10800);
	// lwz r16,-10784(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10784);
	// lwz r16,-10784(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10784);
	// lwz r16,-10784(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10784);
	// lwz r16,-10784(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10784);
	// lwz r16,-10788(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + -10788);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr
	return;
}

__attribute__((alias("__imp__sub_8219D57C"))) PPC_WEAK_FUNC(sub_8219D57C);
PPC_FUNC_IMPL(__imp__sub_8219D57C) {
	PPC_FUNC_PROLOGUE();
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr
	return;
}

__attribute__((alias("__imp__sub_8219D588"))) PPC_WEAK_FUNC(sub_8219D588);
PPC_FUNC_IMPL(__imp__sub_8219D588) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D594"))) PPC_WEAK_FUNC(sub_8219D594);
PPC_FUNC_IMPL(__imp__sub_8219D594) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5A0"))) PPC_WEAK_FUNC(sub_8219D5A0);
PPC_FUNC_IMPL(__imp__sub_8219D5A0) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5AC"))) PPC_WEAK_FUNC(sub_8219D5AC);
PPC_FUNC_IMPL(__imp__sub_8219D5AC) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5B8"))) PPC_WEAK_FUNC(sub_8219D5B8);
PPC_FUNC_IMPL(__imp__sub_8219D5B8) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,20
	ctx.r10.s64 = ctx.r11.s64 + 20;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5C4"))) PPC_WEAK_FUNC(sub_8219D5C4);
PPC_FUNC_IMPL(__imp__sub_8219D5C4) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 24;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5D0"))) PPC_WEAK_FUNC(sub_8219D5D0);
PPC_FUNC_IMPL(__imp__sub_8219D5D0) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r11,28
	ctx.r10.s64 = ctx.r11.s64 + 28;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5DC"))) PPC_WEAK_FUNC(sub_8219D5DC);
PPC_FUNC_IMPL(__imp__sub_8219D5DC) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r3,364
	ctx.r10.s64 = ctx.r3.s64 + 364;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5E0"))) PPC_WEAK_FUNC(sub_8219D5E0);
PPC_FUNC_IMPL(__imp__sub_8219D5E0) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D5E8"))) PPC_WEAK_FUNC(sub_8219D5E8);
PPC_FUNC_IMPL(__imp__sub_8219D5E8) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,360
	ctx.r11.s64 = ctx.r3.s64 + 360;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d604
	if (!ctx.cr6.lt) goto loc_8219D604;
	// stw r3,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r3.u32);
	// b 0x8219d614
	goto loc_8219D614;
loc_8219D604:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d614
	if (!ctx.cr6.gt) goto loc_8219D614;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_8219D614:
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r4,5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 5, ctx.xer);
	// rlwinm r10,r10,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219d650
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D650;
	// bdzf 4*cr6+eq,0x8219d658
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D658;
	// bdzf 4*cr6+eq,0x8219d660
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D660;
	// bdzf 4*cr6+eq,0x8219d668
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D668;
	// bne cr6,0x8219d670
	if (!ctx.cr6.eq) goto loc_8219D670;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_8219D650:
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// blr 
	return;
loc_8219D658:
	// addi r3,r10,8
	ctx.r3.s64 = ctx.r10.s64 + 8;
	// blr 
	return;
loc_8219D660:
	// addi r3,r10,24
	ctx.r3.s64 = ctx.r10.s64 + 24;
	// blr 
	return;
loc_8219D668:
	// addi r3,r10,28
	ctx.r3.s64 = ctx.r10.s64 + 28;
	// blr 
	return;
loc_8219D670:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219D678"))) PPC_WEAK_FUNC(sub_8219D678);
PPC_FUNC_IMPL(__imp__sub_8219D678) {
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
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r3,312
	ctx.r9.s64 = ctx.r3.s64 + 312;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r7,0
	ctx.r7.s64 = 0;
	// divw. r6,r8,r5
	ctx.r6.s32 = ppc_divw(ctx.r8.s32, ctx.r5.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble 0x8219d718
	if (!ctx.cr0.gt) goto loc_8219D718;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r30,-9999
	ctx.r30.s64 = -9999;
loc_8219D6B8:
	// lwz r11,12(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r10,16(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r4,r8,r5
	ctx.r4.s32 = ppc_divw(ctx.r8.s32, ctx.r5.s32);
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x8219d6d4
	if (ctx.cr6.lt) goto loc_8219D6D4;
	// twi 31,r0,22
loc_8219D6D4:
	// add r8,r6,r11
	ctx.r8.u64 = ctx.r6.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,28(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// bl 0x8219d218
	ctx.lr = 0x8219D6E4;
	sub_8219D218(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219d6f8
	if (ctx.cr6.eq) goto loc_8219D6F8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r30,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r30.u32);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
loc_8219D6F8:
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r10,12(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r4,r8,r5
	ctx.r4.s32 = ppc_divw(ctx.r8.s32, ctx.r5.s32);
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8219d6b8
	if (ctx.cr6.lt) goto loc_8219D6B8;
loc_8219D718:
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

__attribute__((alias("__imp__sub_8219D730"))) PPC_WEAK_FUNC(sub_8219D730);
PPC_FUNC_IMPL(__imp__sub_8219D730) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8219D738;
	__savegprlr_29(ctx, base);
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r7,r3,312
	ctx.r7.s64 = ctx.r3.s64 + 312;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// divw. r8,r9,r4
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r4.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x8219d838
	if (!ctx.cr0.gt) goto loc_8219D838;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r30,7
	ctx.r30.s64 = 7;
	// li r31,-9999
	ctx.r31.s64 = -9999;
loc_8219D768:
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,16(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r4
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r4.s32);
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8219d784
	if (ctx.cr6.lt) goto loc_8219D784;
	// twi 31,r0,22
loc_8219D784:
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// add r8,r6,r10
	ctx.r8.u64 = ctx.r6.u64 + ctx.r10.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r9,28(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8219d7a4
	if (!ctx.cr6.lt) goto loc_8219D7A4;
	// stw r29,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r29.u32);
	// b 0x8219d7b0
	goto loc_8219D7B0;
loc_8219D7A4:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x8219d7b0
	if (!ctx.cr6.gt) goto loc_8219D7B0;
	// stw r30,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r30.u32);
loc_8219D7B0:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// mulli r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 * 44;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bgt cr6,0x8219d818
	if (ctx.cr6.gt) goto loc_8219D818;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8219d7e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D7E8;
	// bdzf 4*cr6+eq,0x8219d7f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D7F0;
	// bdzf 4*cr6+eq,0x8219d7f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8219D7F8;
	// bne cr6,0x8219d800
	if (!ctx.cr6.eq) goto loc_8219D800;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8219d804
	goto loc_8219D804;
loc_8219D7E8:
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// b 0x8219d804
	goto loc_8219D804;
loc_8219D7F0:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// b 0x8219d804
	goto loc_8219D804;
loc_8219D7F8:
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// b 0x8219d804
	goto loc_8219D804;
loc_8219D800:
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
loc_8219D804:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219d818
	if (ctx.cr6.eq) goto loc_8219D818;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r31,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r31.u32);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
loc_8219D818:
	// lwz r11,16(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r4
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r4.s32);
	// cmpw cr6,r5,r8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8219d768
	if (ctx.cr6.lt) goto loc_8219D768;
loc_8219D838:
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219D83C"))) PPC_WEAK_FUNC(sub_8219D83C);
PPC_FUNC_IMPL(__imp__sub_8219D83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219D840"))) PPC_WEAK_FUNC(sub_8219D840);
PPC_FUNC_IMPL(__imp__sub_8219D840) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8219D848;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r31,80
	ctx.r31.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r8,r3,312
	ctx.r8.s64 = ctx.r3.s64 + 312;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r6,0
	ctx.r6.s64 = 0;
	// divw. r7,r9,r31
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble 0x8219d8d8
	if (!ctx.cr0.gt) goto loc_8219D8D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r29,-9999
	ctx.r29.s64 = -9999;
loc_8219D878:
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r7,r9,r31
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8219d894
	if (ctx.cr6.lt) goto loc_8219D894;
	// twi 31,r0,22
loc_8219D894:
	// add r7,r5,r11
	ctx.r7.u64 = ctx.r5.u64 + ctx.r11.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// bl 0x8219d368
	ctx.lr = 0x8219D8A4;
	sub_8219D368(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219d8b8
	if (ctx.cr6.eq) goto loc_8219D8B8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r29,44(r7)
	PPC_STORE_U32(ctx.r7.u32 + 44, ctx.r29.u32);
	// stw r11,40(r7)
	PPC_STORE_U32(ctx.r7.u32 + 40, ctx.r11.u32);
loc_8219D8B8:
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r5,r5,80
	ctx.r5.s64 = ctx.r5.s64 + 80;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r7,r9,r31
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	// cmpw cr6,r6,r7
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8219d878
	if (ctx.cr6.lt) goto loc_8219D878;
loc_8219D8D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219D8E0"))) PPC_WEAK_FUNC(sub_8219D8E0);
PPC_FUNC_IMPL(__imp__sub_8219D8E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8219D8E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r30,80
	ctx.r30.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r7,r3,312
	ctx.r7.s64 = ctx.r3.s64 + 312;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// divw. r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x8219d978
	if (!ctx.cr0.gt) goto loc_8219D978;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r28,-9999
	ctx.r28.s64 = -9999;
loc_8219D918:
	// lwz r11,12(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r10,16(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8219d934
	if (ctx.cr6.lt) goto loc_8219D934;
	// twi 31,r0,22
loc_8219D934:
	// add r6,r31,r11
	ctx.r6.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,28(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// bl 0x8219d440
	ctx.lr = 0x8219D944;
	sub_8219D440(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219d958
	if (ctx.cr6.eq) goto loc_8219D958;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r28,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r28.u32);
	// stw r11,40(r6)
	PPC_STORE_U32(ctx.r6.u32 + 40, ctx.r11.u32);
loc_8219D958:
	// lwz r11,16(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// cmpw cr6,r5,r8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8219d918
	if (ctx.cr6.lt) goto loc_8219D918;
loc_8219D978:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219D980"))) PPC_WEAK_FUNC(sub_8219D980);
PPC_FUNC_IMPL(__imp__sub_8219D980) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8219D988;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r31,80
	ctx.r31.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r8,r3,312
	ctx.r8.s64 = ctx.r3.s64 + 312;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r6,0
	ctx.r6.s64 = 0;
	// divw. r7,r9,r31
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble 0x8219da18
	if (!ctx.cr0.gt) goto loc_8219DA18;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r29,-9999
	ctx.r29.s64 = -9999;
loc_8219D9B8:
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r7,r9,r31
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8219d9d4
	if (ctx.cr6.lt) goto loc_8219D9D4;
	// twi 31,r0,22
loc_8219D9D4:
	// add r7,r5,r11
	ctx.r7.u64 = ctx.r5.u64 + ctx.r11.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// bl 0x8219d4e8
	ctx.lr = 0x8219D9E4;
	sub_8219D4E8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219d9f8
	if (ctx.cr6.eq) goto loc_8219D9F8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r29,44(r7)
	PPC_STORE_U32(ctx.r7.u32 + 44, ctx.r29.u32);
	// stw r11,40(r7)
	PPC_STORE_U32(ctx.r7.u32 + 40, ctx.r11.u32);
loc_8219D9F8:
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r5,r5,80
	ctx.r5.s64 = ctx.r5.s64 + 80;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r7,r9,r31
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	// cmpw cr6,r6,r7
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8219d9b8
	if (ctx.cr6.lt) goto loc_8219D9B8;
loc_8219DA18:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219DA20"))) PPC_WEAK_FUNC(sub_8219DA20);
PPC_FUNC_IMPL(__imp__sub_8219DA20) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r6,80
	ctx.r6.s64 = 80;
	// lwz r9,324(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// addi r10,r3,312
	ctx.r10.s64 = ctx.r3.s64 + 312;
	// li r8,0
	ctx.r8.s64 = 0;
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r5,r7,r6
	ctx.r5.s32 = ppc_divw(ctx.r7.s32, ctx.r6.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,-9999
	ctx.r5.s64 = -9999;
loc_8219DA48:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r4,r11,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r9,r4,r6
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8219da64
	if (ctx.cr6.lt) goto loc_8219DA64;
	// twi 31,r0,22
loc_8219DA64:
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8219da80
	if (ctx.cr6.lt) goto loc_8219DA80;
	// bne cr6,0x8219da98
	if (!ctx.cr6.eq) goto loc_8219DA98;
	// addi r11,r3,388
	ctx.r11.s64 = ctx.r3.s64 + 388;
	// b 0x8219da84
	goto loc_8219DA84;
loc_8219DA80:
	// addi r11,r3,384
	ctx.r11.s64 = ctx.r3.s64 + 384;
loc_8219DA84:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219da98
	if (ctx.cr6.eq) goto loc_8219DA98;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r5,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r5.u32);
	// stw r11,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r11.u32);
loc_8219DA98:
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r7,r7,80
	ctx.r7.s64 = ctx.r7.s64 + 80;
	// subf r4,r9,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw r11,r4,r6
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8219da48
	if (ctx.cr6.lt) goto loc_8219DA48;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219DABC"))) PPC_WEAK_FUNC(sub_8219DABC);
PPC_FUNC_IMPL(__imp__sub_8219DABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219DAC0"))) PPC_WEAK_FUNC(sub_8219DAC0);
PPC_FUNC_IMPL(__imp__sub_8219DAC0) {
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
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r10,324(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r3,312
	ctx.r9.s64 = ctx.r3.s64 + 312;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r7,0
	ctx.r7.s64 = 0;
	// divw. r6,r8,r5
	ctx.r6.s32 = ppc_divw(ctx.r8.s32, ctx.r5.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble 0x8219db60
	if (!ctx.cr0.gt) goto loc_8219DB60;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r30,-9999
	ctx.r30.s64 = -9999;
loc_8219DB00:
	// lwz r11,12(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r10,16(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r4,r8,r5
	ctx.r4.s32 = ppc_divw(ctx.r8.s32, ctx.r5.s32);
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x8219db1c
	if (ctx.cr6.lt) goto loc_8219DB1C;
	// twi 31,r0,22
loc_8219DB1C:
	// add r8,r6,r11
	ctx.r8.u64 = ctx.r6.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,28(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// bl 0x8219d5e8
	ctx.lr = 0x8219DB2C;
	sub_8219D5E8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219db40
	if (ctx.cr6.eq) goto loc_8219DB40;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r30,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r30.u32);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
loc_8219DB40:
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r10,12(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r4,r8,r5
	ctx.r4.s32 = ppc_divw(ctx.r8.s32, ctx.r5.s32);
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8219db00
	if (ctx.cr6.lt) goto loc_8219DB00;
loc_8219DB60:
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

__attribute__((alias("__imp__sub_8219DB78"))) PPC_WEAK_FUNC(sub_8219DB78);
PPC_FUNC_IMPL(__imp__sub_8219DB78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8219DB80;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82080368
	ctx.lr = 0x8219DB88;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,196(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219DBA8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,156(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,248(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 248);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// addi r28,r27,232
	ctx.r28.s64 = ctx.r27.s64 + 232;
	// lfs f0,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// lwz r11,244(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 244);
	// fsubs f30,f12,f10
	ctx.f30.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// fsubs f29,f9,f13
	ctx.f29.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// ble cr6,0x8219dbe8
	if (!ctx.cr6.gt) goto loc_8219DBE8;
	// twi 31,r0,22
loc_8219DBE8:
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// lwz r29,0(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f31,184(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	ctx.f31.f64 = double(temp.f32);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r25,1
	ctx.r25.s64 = 1;
	// lfs f28,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f28.f64 = double(temp.f32);
loc_8219DC04:
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219dc18
	if (!ctx.cr6.gt) goto loc_8219DC18;
	// twi 31,r0,22
loc_8219DC18:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8219dc2c
	if (ctx.cr6.eq) goto loc_8219DC2C;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8219dc30
	if (ctx.cr6.eq) goto loc_8219DC30;
loc_8219DC2C:
	// twi 31,r0,22
loc_8219DC30:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8219dd3c
	if (!ctx.cr6.lt) goto loc_8219DD3C;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8219dcc0
	if (!ctx.cr6.eq) goto loc_8219DCC0;
	// twi 31,r0,22
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8219DC48:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219dc58
	if (ctx.cr6.lt) goto loc_8219DC58;
	// twi 31,r0,22
loc_8219DC58:
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219DC74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,280(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,284(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8219DCA4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x8219dcc8
	if (!ctx.cr6.lt) goto loc_8219DCC8;
	// fsubs f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
	// b 0x8219dcd4
	goto loc_8219DCD4;
loc_8219DCC0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8219dc48
	goto loc_8219DC48;
loc_8219DCC8:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// ble cr6,0x8219dcf0
	if (!ctx.cr6.gt) goto loc_8219DCF0;
	// fsubs f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
loc_8219DCD4:
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fnmsubs f13,f12,f31,f31
	ctx.f13.f64 = double(float(-(ctx.f12.f64 * ctx.f31.f64 - ctx.f31.f64)));
	// fcmpu cr6,f13,f28
	ctx.cr6.compare(ctx.f13.f64, ctx.f28.f64);
	// bge cr6,0x8219dcf0
	if (!ctx.cr6.lt) goto loc_8219DCF0;
	// stb r25,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r25.u8);
	// b 0x8219dd0c
	goto loc_8219DD0C;
loc_8219DCF0:
	// rlwinm r11,r11,0,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF00;
	// fctidz f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r10,103(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stb r26,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r26.u8);
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
loc_8219DD0C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8219dd34
	if (!ctx.cr6.eq) goto loc_8219DD34;
	// twi 31,r0,22
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8219DD1C:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8219dd2c
	if (ctx.cr6.lt) goto loc_8219DD2C;
	// twi 31,r0,22
loc_8219DD2C:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// b 0x8219dc04
	goto loc_8219DC04;
loc_8219DD34:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8219dd1c
	goto loc_8219DD1C;
loc_8219DD3C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x820803b4
	ctx.lr = 0x8219DD48;
	__restfpr_28(ctx, base);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219DD4C"))) PPC_WEAK_FUNC(sub_8219DD4C);
PPC_FUNC_IMPL(__imp__sub_8219DD4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219DD50"))) PPC_WEAK_FUNC(sub_8219DD50);
PPC_FUNC_IMPL(__imp__sub_8219DD50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8219DD58;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lfs f11,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r30,r11,1408
	ctx.r30.s64 = ctx.r11.s64 + 1408;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r27,r11,2508
	ctx.r27.s64 = ctx.r11.s64 + 2508;
	// lfs f10,192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,180(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,168(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,164(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
loc_8219DD9C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x8219ddb0
	if (!ctx.cr6.lt) goto loc_8219DDB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8219ddbc
	goto loc_8219DDBC;
loc_8219DDB0:
	// cmpwi cr6,r29,7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 7, ctx.xer);
	// ble cr6,0x8219ddbc
	if (!ctx.cr6.gt) goto loc_8219DDBC;
	// li r10,7
	ctx.r10.s64 = 7;
loc_8219DDBC:
	// lwz r11,360(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 360);
	// rlwinm r10,r10,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r31,r10,32
	ctx.r31.s64 = ctx.r10.s64 + 32;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8219de1c
	if (ctx.cr6.eq) goto loc_8219DE1C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 2;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// subf r4,r6,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r6.s64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lwzx r7,r9,r27
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r27.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// b 0x8219df0c
	goto loc_8219DF0C;
loc_8219DE1C:
	// lfs f0,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8219de7c
	if (!ctx.cr6.lt) goto loc_8219DE7C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f6,28(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stfs f6,32(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// bl 0x8219d980
	ctx.lr = 0x8219DE7C;
	sub_8219D980(ctx, base);
loc_8219DE7C:
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,44(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8219df0c
	if (!ctx.cr6.lt) goto loc_8219DF0C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f6,44(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r11,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 1;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8219def0
	if (!ctx.cr0.eq) goto loc_8219DEF0;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
	// b 0x8219def4
	goto loc_8219DEF4;
loc_8219DEF0:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_8219DEF4:
	// lfs f8,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f0,52(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// stfs f8,48(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// stfs f0,56(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// bl 0x8219d980
	ctx.lr = 0x8219DF0C;
	sub_8219D980(ctx, base);
loc_8219DF0C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// blt cr6,0x8219dd9c
	if (ctx.cr6.lt) goto loc_8219DD9C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219DF20"))) PPC_WEAK_FUNC(sub_8219DF20);
PPC_FUNC_IMPL(__imp__sub_8219DF20) {
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
	// bl 0x8219dd50
	ctx.lr = 0x8219DF38;
	sub_8219DD50(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,7504
	ctx.r9.s64 = ctx.r11.s64 + 7504;
	// stw r10,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8219DF60"))) PPC_WEAK_FUNC(sub_8219DF60);
PPC_FUNC_IMPL(__imp__sub_8219DF60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8219DF68;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lfs f11,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r30,r11,1408
	ctx.r30.s64 = ctx.r11.s64 + 1408;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r28,r11,2508
	ctx.r28.s64 = ctx.r11.s64 + 2508;
	// lfs f10,192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,180(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,168(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,164(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
loc_8219DFA8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x8219dfbc
	if (!ctx.cr6.lt) goto loc_8219DFBC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8219dfc8
	goto loc_8219DFC8;
loc_8219DFBC:
	// cmpwi cr6,r29,7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 7, ctx.xer);
	// ble cr6,0x8219dfc8
	if (!ctx.cr6.gt) goto loc_8219DFC8;
	// li r11,7
	ctx.r11.s64 = 7;
loc_8219DFC8:
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// lwz r10,384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// addi r31,r11,392
	ctx.r31.s64 = ctx.r11.s64 + 392;
	// beq cr6,0x8219e024
	if (ctx.cr6.eq) goto loc_8219E024;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 2;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// subf r4,r6,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r6.s64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r28
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// lwzx r5,r7,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r28.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// b 0x8219e10c
	goto loc_8219E10C;
loc_8219E024:
	// lfs f0,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8219e080
	if (!ctx.cr6.lt) goto loc_8219E080;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r28.u32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f6,28(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stfs f6,32(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// bl 0x8219da20
	ctx.lr = 0x8219E080;
	sub_8219DA20(ctx, base);
loc_8219E080:
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,44(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8219e10c
	if (!ctx.cr6.lt) goto loc_8219E10C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r28.u32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f6,44(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8219e0f4
	if (!ctx.cr0.eq) goto loc_8219E0F4;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
	// b 0x8219e0f8
	goto loc_8219E0F8;
loc_8219E0F4:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_8219E0F8:
	// lfs f8,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// stfs f0,52(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// stfs f8,48(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// stfs f0,56(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// bl 0x8219da20
	ctx.lr = 0x8219E10C;
	sub_8219DA20(ctx, base);
loc_8219E10C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// blt cr6,0x8219dfa8
	if (ctx.cr6.lt) goto loc_8219DFA8;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E120"))) PPC_WEAK_FUNC(sub_8219E120);
PPC_FUNC_IMPL(__imp__sub_8219E120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8219E128;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lfs f11,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r30,r11,1408
	ctx.r30.s64 = ctx.r11.s64 + 1408;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r27,r11,2508
	ctx.r27.s64 = ctx.r11.s64 + 2508;
	// lfs f10,192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,180(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,168(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,164(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
loc_8219E16C:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge cr6,0x8219e180
	if (!ctx.cr6.lt) goto loc_8219E180;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8219e18c
	goto loc_8219E18C;
loc_8219E180:
	// cmpwi cr6,r28,7
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 7, ctx.xer);
	// ble cr6,0x8219e18c
	if (!ctx.cr6.gt) goto loc_8219E18C;
	// li r11,7
	ctx.r11.s64 = 7;
loc_8219E18C:
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// lwz r10,384(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 384);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// cmpw cr6,r10,r28
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r28.s32, ctx.xer);
	// addi r31,r11,392
	ctx.r31.s64 = ctx.r11.s64 + 392;
	// beq cr6,0x8219e1e8
	if (ctx.cr6.eq) goto loc_8219E1E8;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 2;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// subf r4,r6,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r6.s64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lwzx r7,r9,r27
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r27.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// b 0x8219e2d8
	goto loc_8219E2D8;
loc_8219E1E8:
	// lfs f0,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8219e248
	if (!ctx.cr6.lt) goto loc_8219E248;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f6,28(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// stfs f6,32(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// bl 0x8219dac0
	ctx.lr = 0x8219E248;
	sub_8219DAC0(ctx, base);
loc_8219E248:
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,44(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8219e2d8
	if (!ctx.cr6.lt) goto loc_8219E2D8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f6,44(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r11,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 1;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8219e2bc
	if (!ctx.cr0.eq) goto loc_8219E2BC;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
	// b 0x8219e2c0
	goto loc_8219E2C0;
loc_8219E2BC:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_8219E2C0:
	// lfs f8,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f0,52(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// stfs f8,48(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// stfs f0,56(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// bl 0x8219dac0
	ctx.lr = 0x8219E2D8;
	sub_8219DAC0(ctx, base);
loc_8219E2D8:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// blt cr6,0x8219e16c
	if (ctx.cr6.lt) goto loc_8219E16C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E2EC"))) PPC_WEAK_FUNC(sub_8219E2EC);
PPC_FUNC_IMPL(__imp__sub_8219E2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219E2F0"))) PPC_WEAK_FUNC(sub_8219E2F0);
PPC_FUNC_IMPL(__imp__sub_8219E2F0) {
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
	// bl 0x8219d030
	ctx.lr = 0x8219E308;
	sub_8219D030(ctx, base);
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,284(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// beq cr6,0x8219e338
	if (ctx.cr6.eq) goto loc_8219E338;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,280(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 280);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219E330;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 284, temp.u32);
loc_8219E338:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,80(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8219e3b8
	if (ctx.cr6.lt) goto loc_8219E3B8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8219e3b8
	if (ctx.cr6.gt) goto loc_8219E3B8;
	// mulli r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 * 132;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8219e3b8
	if (ctx.cr6.eq) goto loc_8219E3B8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,300
	ctx.r11.s64 = ctx.r11.s64 + 300;
loc_8219E384:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8219e3a4
	if (ctx.cr6.eq) goto loc_8219E3A4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// ble cr6,0x8219e384
	if (!ctx.cr6.gt) goto loc_8219E384;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8219E3A4:
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82188f90
	ctx.lr = 0x8219E3AC;
	sub_82188F90(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8219E3B8:
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

__attribute__((alias("__imp__sub_8219E3CC"))) PPC_WEAK_FUNC(sub_8219E3CC);
PPC_FUNC_IMPL(__imp__sub_8219E3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219E3D0"))) PPC_WEAK_FUNC(sub_8219E3D0);
PPC_FUNC_IMPL(__imp__sub_8219E3D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8219E3D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,196(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,3200
	ctx.r10.s64 = ctx.r11.s64 + 3200;
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8219e40c
	if (ctx.cr6.eq) goto loc_8219E40C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219E40C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8219E40C:
	// lwz r3,204(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 204);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219e42c
	if (ctx.cr6.eq) goto loc_8219E42C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219E42C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8219E42C:
	// lwz r3,268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 268);
	// addi r31,r29,256
	ctx.r31.s64 = ctx.r29.s64 + 256;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219e44c
	if (ctx.cr6.eq) goto loc_8219E44C;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x820694f8
	ctx.lr = 0x8219E444;
	sub_820694F8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x8219E44C;
	sub_8207A630(ctx, base);
loc_8219E44C:
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// bl 0x8207a630
	ctx.lr = 0x8219E464;
	sub_8207A630(ctx, base);
	// lwz r3,244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 244);
	// addi r31,r29,232
	ctx.r31.s64 = ctx.r29.s64 + 232;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219e478
	if (ctx.cr6.eq) goto loc_8219E478;
	// bl 0x8207a630
	ctx.lr = 0x8219E478;
	sub_8207A630(ctx, base);
loc_8219E478:
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8219E48C;
	sub_8207A630(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821be788
	ctx.lr = 0x8219E494;
	sub_821BE788(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E49C"))) PPC_WEAK_FUNC(sub_8219E49C);
PPC_FUNC_IMPL(__imp__sub_8219E49C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219E4A0"))) PPC_WEAK_FUNC(sub_8219E4A0);
PPC_FUNC_IMPL(__imp__sub_8219E4A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,2912
	ctx.r10.s64 = ctx.r11.s64 + 2912;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E4B0"))) PPC_WEAK_FUNC(sub_8219E4B0);
PPC_FUNC_IMPL(__imp__sub_8219E4B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,2816
	ctx.r10.s64 = ctx.r11.s64 + 2816;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E4C0"))) PPC_WEAK_FUNC(sub_8219E4C0);
PPC_FUNC_IMPL(__imp__sub_8219E4C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,2720
	ctx.r10.s64 = ctx.r11.s64 + 2720;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E4D0"))) PPC_WEAK_FUNC(sub_8219E4D0);
PPC_FUNC_IMPL(__imp__sub_8219E4D0) {
	PPC_FUNC_PROLOGUE();
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
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
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
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E50C"))) PPC_WEAK_FUNC(sub_8219E50C);
PPC_FUNC_IMPL(__imp__sub_8219E50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219E510"))) PPC_WEAK_FUNC(sub_8219E510);
PPC_FUNC_IMPL(__imp__sub_8219E510) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,3008
	ctx.r10.s64 = ctx.r11.s64 + 3008;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E520"))) PPC_WEAK_FUNC(sub_8219E520);
PPC_FUNC_IMPL(__imp__sub_8219E520) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,2624
	ctx.r8.s64 = ctx.r10.s64 + 2624;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,1424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1424, ctx.r9.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E544"))) PPC_WEAK_FUNC(sub_8219E544);
PPC_FUNC_IMPL(__imp__sub_8219E544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219E548"))) PPC_WEAK_FUNC(sub_8219E548);
PPC_FUNC_IMPL(__imp__sub_8219E548) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,1424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1424, ctx.r9.u32);
	// b 0x821b5c28
	sub_821B5C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219E56C"))) PPC_WEAK_FUNC(sub_8219E56C);
PPC_FUNC_IMPL(__imp__sub_8219E56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8219E570"))) PPC_WEAK_FUNC(sub_8219E570);
PPC_FUNC_IMPL(__imp__sub_8219E570) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8219E578;
	__savegprlr_23(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,272(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 272);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r11,268(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// addi r27,r3,256
	ctx.r27.s64 = ctx.r3.s64 + 256;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8219e598
	if (!ctx.cr6.gt) goto loc_8219E598;
	// twi 31,r0,22
loc_8219E598:
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x8219e5b0
	if (!ctx.cr6.gt) goto loc_8219E5B0;
	// twi 31,r0,22
loc_8219E5B0:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82069380
	ctx.lr = 0x8219E5CC;
	sub_82069380(ctx, base);
	// lwz r11,308(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 308);
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8219e6f8
	if (!ctx.cr6.gt) goto loc_8219E6F8;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// li r30,15
	ctx.r30.s64 = 15;
	// li r24,-1
	ctx.r24.s64 = -1;
	// addi r23,r11,-19792
	ctx.r23.s64 = ctx.r11.s64 + -19792;
loc_8219E5F4:
	// lwz r11,304(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 304);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r4,r26,r11
	ctx.r4.u64 = ctx.r26.u64 + ctx.r11.u64;
	// bl 0x82068d08
	ctx.lr = 0x8219E604;
	sub_82068D08(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82068bd0
	ctx.lr = 0x8219E610;
	sub_82068BD0(ctx, base);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r30.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stb r31,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r31.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x8219e6d8
	if (!ctx.cr6.lt) goto loc_8219E6D8;
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r30.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r31.u8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82060368
	ctx.lr = 0x8219E648;
	sub_82060368(ctx, base);
	// stw r30,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r30.u32);
	// stw r31,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r31.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// stb r31,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, ctx.r31.u8);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820601f8
	ctx.lr = 0x8219E66C;
	sub_820601F8(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821ccf40
	ctx.lr = 0x8219E67C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820601f8
	ctx.lr = 0x8219E690;
	sub_820601F8(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219e6a4
	if (ctx.cr6.lt) goto loc_8219E6A4;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8207a630
	ctx.lr = 0x8219E6A4;
	sub_8207A630(ctx, base);
loc_8219E6A4:
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r31.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820601f8
	ctx.lr = 0x8219E6C4;
	sub_820601F8(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8219e6d8
	if (ctx.cr6.lt) goto loc_8219E6D8;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x8219E6D8;
	sub_8207A630(ctx, base);
loc_8219E6D8:
	// lwz r11,308(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 308);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r30.u32);
	// addi r26,r26,32
	ctx.r26.s64 = ctx.r26.s64 + 32;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// stb r31,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r31.u8);
	// blt cr6,0x8219e5f4
	if (ctx.cr6.lt) goto loc_8219E5F4;
loc_8219E6F8:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

