#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_820CB698"))) PPC_WEAK_FUNC(sub_820CB698);
PPC_FUNC_IMPL(__imp__sub_820CB698) {
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
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,202
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 202, ctx.xer);
	// bne cr6,0x820cb6f0
	if (!ctx.cr6.eq) goto loc_820CB6F0;
	// bl 0x820d52d0
	ctx.lr = 0x820CB6BC;
	sub_820D52D0(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820cb6e8
	if (ctx.cr6.eq) goto loc_820CB6E8;
	// li r11,207
	ctx.r11.s64 = 207;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_820CB6E8:
	// li r11,203
	ctx.r11.s64 = 203;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_820CB6F0:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,203
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 203, ctx.xer);
	// bne cr6,0x820cb7c0
	if (!ctx.cr6.eq) goto loc_820CB7C0;
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820cb7b4
	if (ctx.cr6.eq) goto loc_820CB7B4;
loc_820CB70C:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cb728
	if (ctx.cr6.eq) goto loc_820CB728;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CB728;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CB728:
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CB73C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb79c
	if (ctx.cr6.eq) goto loc_820CB79C;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cb7b4
	if (ctx.cr6.eq) goto loc_820CB7B4;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cb70c
	if (ctx.cr6.eq) goto loc_820CB70C;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x820cb768
	if (ctx.cr6.eq) goto loc_820CB768;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x820cb70c
	if (!ctx.cr6.eq) goto loc_820CB70C;
loc_820CB768:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x820cb70c
	if (ctx.cr6.lt) goto loc_820CB70C;
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// b 0x820cb70c
	goto loc_820CB70C;
loc_820CB79C:
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
loc_820CB7B4:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// b 0x820cb7f4
	goto loc_820CB7F4;
loc_820CB7C0:
	// cmpwi cr6,r11,204
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 204, ctx.xer);
	// beq cr6,0x820cb7f4
	if (ctx.cr6.eq) goto loc_820CB7F4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CB7F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CB7F4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb4e0
	ctx.lr = 0x820CB7FC;
	sub_820CB4E0(ctx, base);
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

__attribute__((alias("__imp__sub_820CB810"))) PPC_WEAK_FUNC(sub_820CB810);
PPC_FUNC_IMPL(__imp__sub_820CB810) {
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
	// li r10,102
	ctx.r10.s64 = 102;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CB844;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,444(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x820cb874
	if (ctx.cr6.eq) goto loc_820CB874;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,61
	ctx.r10.s64 = 61;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CB874;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CB874:
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r31,263
	ctx.r11.s64 = ctx.r31.s64 + 263;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,5
	ctx.r8.s64 = 5;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_820CB88C:
	// stb r10,-31(r11)
	PPC_STORE_U8(ctx.r11.u32 + -31, ctx.r10.u8);
	// stb r9,-15(r11)
	PPC_STORE_U8(ctx.r11.u32 + -15, ctx.r9.u8);
	// stbu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cb88c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CB88C;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r10.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r10,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r10.u32);
	// stw r10,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r10.u32);
	// stb r9,288(r31)
	PPC_STORE_U8(ctx.r31.u32 + 288, ctx.r9.u8);
	// stb r9,289(r31)
	PPC_STORE_U8(ctx.r31.u32 + 289, ctx.r9.u8);
	// stb r10,290(r31)
	PPC_STORE_U8(ctx.r31.u32 + 290, ctx.r10.u8);
	// sth r9,292(r31)
	PPC_STORE_U16(ctx.r31.u32 + 292, ctx.r9.u16);
	// sth r9,294(r31)
	PPC_STORE_U16(ctx.r31.u32 + 294, ctx.r9.u16);
	// stw r10,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r10.u32);
	// stb r10,300(r31)
	PPC_STORE_U8(ctx.r31.u32 + 300, ctx.r10.u8);
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_820CB8E8"))) PPC_WEAK_FUNC(sub_820CB8E8);
PPC_FUNC_IMPL(__imp__sub_820CB8E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820CB8F0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,24(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r4,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r5,228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 228, ctx.r5.u32);
	// bne cr6,0x820cb93c
	if (!ctx.cr6.eq) goto loc_820CB93C;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CB920;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cb934
	if (!ctx.cr6.eq) goto loc_820CB934;
loc_820CB928:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_820CB934:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CB93C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r30,r9,8
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820cb970
	if (!ctx.cr0.eq) goto loc_820CB970;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CB960;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CB970:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 + ctx.r30.u64;
	// bne 0x820cb9a4
	if (!ctx.cr0.eq) goto loc_820CB9A4;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CB994;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CB9A4:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r9.u32);
	// bne 0x820cb9d8
	if (!ctx.cr0.eq) goto loc_820CB9D8;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CB9C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CB9D8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r8,r9,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// stw r8,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
	// bne 0x820cba10
	if (!ctx.cr0.eq) goto loc_820CBA10;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBA00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBA10:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// bne 0x820cba4c
	if (!ctx.cr0.eq) goto loc_820CBA4C;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBA3C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBA4C:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addic. r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// rotlwi r7,r8,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// stw r7,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// bne 0x820cba84
	if (!ctx.cr0.eq) goto loc_820CBA84;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBA74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBA84:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bne 0x820cbac0
	if (!ctx.cr0.eq) goto loc_820CBAC0;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBAB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBAC0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r28,r10,1
	ctx.r28.s64 = ctx.r10.s64 + 1;
	// lwz r6,420(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// addi r29,r9,-1
	ctx.r29.s64 = ctx.r9.s64 + -1;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r7,100
	ctx.r7.s64 = 100;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// addi r30,r30,-8
	ctx.r30.s64 = ctx.r30.s64 + -8;
	// stw r6,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r6.u32);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r5,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r5.u32);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r7,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r7.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CBB1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,444(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r4,16(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820cbb4c
	if (ctx.cr6.eq) goto loc_820CBB4C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,58
	ctx.r10.s64 = 58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CBB4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CBB4C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x820cbb70
	if (!ctx.cr6.gt) goto loc_820CBB70;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x820cbb70
	if (!ctx.cr6.gt) goto loc_820CBB70;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x820cbb90
	if (ctx.cr6.gt) goto loc_820CBB90;
loc_820CBB70:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CBB90;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CBB90:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x820cbbc4
	if (ctx.cr6.eq) goto loc_820CBBC4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CBBC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CBBC4:
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cbbf4
	if (!ctx.cr6.eq) goto loc_820CBBF4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mulli r5,r10,84
	ctx.r5.s64 = ctx.r10.s64 * 84;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820CBBF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r3.u32);
loc_820CBBF4:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x820cbd18
	if (!ctx.cr6.gt) goto loc_820CBD18;
	// addi r30,r11,-68
	ctx.r30.s64 = ctx.r11.s64 + -68;
	// li r25,101
	ctx.r25.s64 = 101;
loc_820CBC10:
	// stw r26,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r26.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820cbc3c
	if (!ctx.cr6.eq) goto loc_820CBC3C;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBC2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r28,0(r27)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r29,4(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBC3C:
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addic. r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r10.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// stw r9,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r9.u32);
	// bne 0x820cbc70
	if (!ctx.cr0.eq) goto loc_820CBC70;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBC60;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBC70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r8,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	// clrlwi r7,r9,28
	ctx.r7.u64 = ctx.r9.u32 & 0xF;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// stw r6,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r6.u32);
	// bne 0x820cbcb4
	if (!ctx.cr0.eq) goto loc_820CBCB4;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBCA4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cb928
	if (ctx.cr6.eq) goto loc_820CB928;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CBCB4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// lwz r8,68(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// addi r29,r10,-1
	ctx.r29.s64 = ctx.r10.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r9.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// lwz r7,76(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 76);
	// stw r7,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// lwz r6,80(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// lwzu r10,84(r30)
	ea = 84 + ctx.r30.u32;
	ctx.r10.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, ctx.r25.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CBD08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpw cr6,r26,r9
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820cbc10
	if (ctx.cr6.lt) goto loc_820CBC10;
loc_820CBD18:
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r28,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// stw r29,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CBD38"))) PPC_WEAK_FUNC(sub_820CBD38);
PPC_FUNC_IMPL(__imp__sub_820CBD38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x820CBD40;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,444(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 444);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r25,24(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r30,0(r25)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r29,4(r25)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820cbd80
	if (!ctx.cr6.eq) goto loc_820CBD80;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,62
	ctx.r10.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CBD80;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CBD80:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820cbdb4
	if (!ctx.cr6.eq) goto loc_820CBDB4;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBD98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cbdac
	if (!ctx.cr6.eq) goto loc_820CBDAC;
loc_820CBDA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_820CBDAC:
	// lwz r30,0(r25)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r29,4(r25)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CBDB4:
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// addic. r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r10.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rotlwi r30,r9,8
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820cbde8
	if (!ctx.cr0.eq) goto loc_820CBDE8;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBDD8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CBDE8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 + ctx.r30.u64;
	// bne 0x820cbe1c
	if (!ctx.cr0.eq) goto loc_820CBE1C;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBE0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CBE1C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,103
	ctx.r8.s64 = 103;
	// lbz r23,0(r11)
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r26,r10,-1
	ctx.r26.s64 = ctx.r10.s64 + -1;
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// stw r8,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r23,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r23.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820CBE54;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r4,r23,3
	ctx.r4.s64 = ctx.r23.s64 + 3;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r30,r3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r3.s32, ctx.xer);
	// bne cr6,0x820cbe74
	if (!ctx.cr6.eq) goto loc_820CBE74;
	// cmpwi cr6,r23,1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 1, ctx.xer);
	// blt cr6,0x820cbe74
	if (ctx.cr6.lt) goto loc_820CBE74;
	// cmpwi cr6,r23,4
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 4, ctx.xer);
	// ble cr6,0x820cbe94
	if (!ctx.cr6.gt) goto loc_820CBE94;
loc_820CBE74:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CBE94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CBE94:
	// stw r23,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r23.u32);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x820cbfc8
	if (!ctx.cr6.gt) goto loc_820CBFC8;
	// addi r22,r31,332
	ctx.r22.s64 = ctx.r31.s64 + 332;
	// li r20,5
	ctx.r20.s64 = 5;
	// li r21,104
	ctx.r21.s64 = 104;
loc_820CBEB0:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x820cbed8
	if (!ctx.cr6.eq) goto loc_820CBED8;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBEC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r28,0(r25)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r26,4(r25)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CBED8:
	// lbz r27,0(r28)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addic. r10,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r10.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// bne 0x820cbf08
	if (!ctx.cr0.eq) goto loc_820CBF08;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBEF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CBF08:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// lbz r29,0(r11)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r26,r10,-1
	ctx.r26.s64 = ctx.r10.s64 + -1;
	// lwz r30,220(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x820cbf48
	if (!ctx.cr6.gt) goto loc_820CBF48;
loc_820CBF28:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpw cr6,r27,r10
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820cbf6c
	if (ctx.cr6.eq) goto loc_820CBF6C;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r30,r30,84
	ctx.r30.s64 = ctx.r30.s64 + 84;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820cbf28
	if (ctx.cr6.lt) goto loc_820CBF28;
loc_820CBF48:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r20,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r20.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r27,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r27.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CBF6C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CBF6C:
	// srawi r11,r29,4
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 4;
	// stwu r30,4(r22)
	ea = 4 + ctx.r22.u32;
	PPC_STORE_U32(ea, ctx.r30.u32);
	ctx.r22.u32 = ea;
	// clrlwi r10,r29,28
	ctx.r10.u64 = ctx.r29.u32 & 0xF;
	// clrlwi r9,r11,28
	ctx.r9.u64 = ctx.r11.u32 & 0xF;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r27,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r27.u32);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r8,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r8.u32);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r7,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r21,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r21.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBFBC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmpw cr6,r24,r23
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r23.s32, ctx.xer);
	// blt cr6,0x820cbeb0
	if (ctx.cr6.lt) goto loc_820CBEB0;
loc_820CBFC8:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x820cbff0
	if (!ctx.cr6.eq) goto loc_820CBFF0;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CBFE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r28,0(r25)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r26,4(r25)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CBFF0:
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addic. r10,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r10.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// stw r9,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r9.u32);
	// bne 0x820cc024
	if (!ctx.cr0.eq) goto loc_820CC024;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC014;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CC024:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r29,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r29.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// stw r9,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r9.u32);
	// bne 0x820cc058
	if (!ctx.cr0.eq) goto loc_820CC058;
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC048;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cbda0
	if (ctx.cr6.eq) goto loc_820CBDA0;
	// lwz r30,0(r25)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r29,4(r25)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_820CC058:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// li r9,105
	ctx.r9.s64 = 105;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// srawi r8,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
	// lwz r7,404(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 404);
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// clrlwi r5,r8,28
	ctx.r5.u64 = ctx.r8.u32 & 0xF;
	// stw r6,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r5,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r5.u32);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// lwz r10,408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 408);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r8,412(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// stw r8,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r8.u32);
	// lwz r7,416(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 416);
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC0B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,444(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// addi r8,r29,-1
	ctx.r8.s64 = ctx.r29.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r10.u32);
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r6.u32);
	// stw r9,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r9.u32);
	// stw r8,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r8.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CC0EC"))) PPC_WEAK_FUNC(sub_820CC0EC);
PPC_FUNC_IMPL(__imp__sub_820CC0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CC0F0"))) PPC_WEAK_FUNC(sub_820CC0F0);
PPC_FUNC_IMPL(__imp__sub_820CC0F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c960
	ctx.lr = 0x820CC0F8;
	__savegprlr_18(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,24(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820cc13c
	if (!ctx.cr6.eq) goto loc_820CC13C;
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC120;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cc134
	if (!ctx.cr6.eq) goto loc_820CC134;
loc_820CC128:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x8207c9b0
	__restgprlr_18(ctx, base);
	return;
loc_820CC134:
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
loc_820CC13C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r29,r9,8
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820cc170
	if (!ctx.cr0.eq) goto loc_820CC170;
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC160;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc128
	if (ctx.cr6.eq) goto loc_820CC128;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
loc_820CC170:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// addi r28,r10,-1
	ctx.r28.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r29
	ctx.r11.u64 = ctx.r9.u64 + ctx.r29.u64;
	// addi r26,r11,-2
	ctx.r26.s64 = ctx.r11.s64 + -2;
	// cmpwi cr6,r26,16
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 16, ctx.xer);
	// ble cr6,0x820cc450
	if (!ctx.cr6.gt) goto loc_820CC450;
	// li r21,80
	ctx.r21.s64 = 80;
	// li r22,0
	ctx.r22.s64 = 0;
	// li r23,86
	ctx.r23.s64 = 86;
	// li r19,8
	ctx.r19.s64 = 8;
	// li r20,30
	ctx.r20.s64 = 30;
loc_820CC1A0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820cc1c8
	if (!ctx.cr6.eq) goto loc_820CC1C8;
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC1B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc128
	if (ctx.cr6.eq) goto loc_820CC128;
	// lwz r31,0(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r28,4(r24)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
loc_820CC1C8:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r25,0(r31)
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r21,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r21.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r25.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CC1FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// stb r22,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r22.u8);
	// li r29,1
	ctx.r29.s64 = 1;
loc_820CC208:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820cc230
	if (!ctx.cr6.eq) goto loc_820CC230;
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC220;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc128
	if (ctx.cr6.eq) goto loc_820CC128;
	// lwz r31,0(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r28,4(r24)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
loc_820CC230:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r29,16
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 16, ctx.xer);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// ble cr6,0x820cc208
	if (!ctx.cr6.gt) goto loc_820CC208;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// lbz r7,81(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r26,r26,-17
	ctx.r26.s64 = ctx.r26.s64 + -17;
	// lbz r9,83(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// lbz r8,86(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r18,88(r1)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// lbz r29,87(r1)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// stw r5,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r5.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// stw r8,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r8.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r29.u32);
	// stw r18,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r18.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r23,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r23.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC2C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lbz r7,89(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// li r4,2
	ctx.r4.s64 = 2;
	// lbz r5,90(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 90);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r9,91(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 91);
	// lbz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 92);
	// lbz r10,93(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 93);
	// lbz r8,94(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 94);
	// lbz r18,96(r1)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// lbz r29,95(r1)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// stw r5,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r5.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// stw r8,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r8.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r29.u32);
	// stw r18,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r18.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r23,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r23.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC330;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r27,256
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 256, ctx.xer);
	// bgt cr6,0x820cc340
	if (ctx.cr6.gt) goto loc_820CC340;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x820cc35c
	if (!ctx.cr6.gt) goto loc_820CC35C;
loc_820CC340:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r19,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r19.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820CC35C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC35C:
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x820cc3b0
	if (!ctx.cr6.gt) goto loc_820CC3B0;
loc_820CC368:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820cc390
	if (!ctx.cr6.eq) goto loc_820CC390;
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC380;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc128
	if (ctx.cr6.eq) goto loc_820CC128;
	// lwz r31,0(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r28,4(r24)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
loc_820CC390:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r28,r28,-1
	ctx.r28.s64 = ctx.r28.s64 + -1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stbx r11,r29,r10
	PPC_STORE_U8(ctx.r29.u32 + ctx.r10.u32, ctx.r11.u8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x820cc368
	if (ctx.cr6.lt) goto loc_820CC368;
loc_820CC3B0:
	// rlwinm r11,r25,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x10;
	// subf r26,r27,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r27.s64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820cc3cc
	if (ctx.cr6.eq) goto loc_820CC3CC;
	// addi r25,r25,-16
	ctx.r25.s64 = ctx.r25.s64 + -16;
	// addi r11,r25,50
	ctx.r11.s64 = ctx.r25.s64 + 50;
	// b 0x820cc3d0
	goto loc_820CC3D0;
loc_820CC3CC:
	// addi r11,r25,46
	ctx.r11.s64 = ctx.r25.s64 + 46;
loc_820CC3D0:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// add r29,r11,r30
	ctx.r29.u64 = ctx.r11.u64 + ctx.r30.u64;
	// blt cr6,0x820cc3e8
	if (ctx.cr6.lt) goto loc_820CC3E8;
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// blt cr6,0x820cc40c
	if (ctx.cr6.lt) goto loc_820CC40C;
loc_820CC3E8:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r20,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r20.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r25.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CC40C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC40C:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cc424
	if (!ctx.cr6.eq) goto loc_820CC424;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d4980
	ctx.lr = 0x820CC420;
	sub_820D4980(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_820CC424:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r5,17
	ctx.r5.s64 = 17;
	// bl 0x8207dac0
	ctx.lr = 0x820CC434;
	sub_8207DAC0(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r11,17
	ctx.r3.s64 = ctx.r11.s64 + 17;
	// li r5,256
	ctx.r5.s64 = 256;
	// bl 0x8207dac0
	ctx.lr = 0x820CC448;
	sub_8207DAC0(ctx, base);
	// cmpwi cr6,r26,16
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 16, ctx.xer);
	// bgt cr6,0x820cc1a0
	if (ctx.cr6.gt) goto loc_820CC1A0;
loc_820CC450:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820cc478
	if (ctx.cr6.eq) goto loc_820CC478;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CC478;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC478:
	// stw r31,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,4(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4, ctx.r28.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x8207c9b0
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CC48C"))) PPC_WEAK_FUNC(sub_820CC48C);
PPC_FUNC_IMPL(__imp__sub_820CC48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CC490"))) PPC_WEAK_FUNC(sub_820CC490);
PPC_FUNC_IMPL(__imp__sub_820CC490) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x820CC498;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,24(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820cc4dc
	if (!ctx.cr6.eq) goto loc_820CC4DC;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC4C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cc4d4
	if (!ctx.cr6.eq) goto loc_820CC4D4;
loc_820CC4C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_820CC4D4:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
loc_820CC4DC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r31,r9,8
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820cc510
	if (!ctx.cr0.eq) goto loc_820CC510;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC500;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc4c8
	if (ctx.cr6.eq) goto loc_820CC4C8;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
loc_820CC510:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// addi r27,r10,-1
	ctx.r27.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addic. r21,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r21.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble 0x820cc760
	if (!ctx.cr0.gt) goto loc_820CC760;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r20,81
	ctx.r20.s64 = 81;
	// li r19,31
	ctx.r19.s64 = 31;
	// li r22,93
	ctx.r22.s64 = 93;
	// addi r23,r11,-3464
	ctx.r23.s64 = ctx.r11.s64 + -3464;
loc_820CC53C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820cc564
	if (!ctx.cr6.eq) goto loc_820CC564;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC554;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc4c8
	if (ctx.cr6.eq) goto loc_820CC4C8;
	// lwz r29,0(r26)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r27,4(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
loc_820CC564:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// clrlwi r31,r10,28
	ctx.r31.u64 = ctx.r10.u32 & 0xF;
	// srawi r24,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r24.s64 = ctx.r10.s32 >> 4;
	// stw r20,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r20.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r31.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r24,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r24.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CC5A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// blt cr6,0x820cc5d4
	if (ctx.cr6.lt) goto loc_820CC5D4;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r19,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r19.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r31.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CC5D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC5D4:
	// addi r11,r31,42
	ctx.r11.s64 = ctx.r31.s64 + 42;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820cc5f4
	if (!ctx.cr6.eq) goto loc_820CC5F4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d4940
	ctx.lr = 0x820CC5F0;
	sub_820D4940(ctx, base);
	// stwx r3,r31,r28
	PPC_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r3.u32);
loc_820CC5F4:
	// lwzx r25,r31,r28
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
loc_820CC5FC:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820cc674
	if (ctx.cr6.eq) goto loc_820CC674;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820cc62c
	if (!ctx.cr6.eq) goto loc_820CC62C;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC61C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc4c8
	if (ctx.cr6.eq) goto loc_820CC4C8;
	// lwz r29,0(r26)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r27,4(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
loc_820CC62C:
	// lbz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addic. r10,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r10.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// rotlwi r31,r9,8
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820cc660
	if (!ctx.cr0.eq) goto loc_820CC660;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC650;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc4c8
	if (ctx.cr6.eq) goto loc_820CC4C8;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
loc_820CC660:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// addi r27,r10,-1
	ctx.r27.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// b 0x820cc6a8
	goto loc_820CC6A8;
loc_820CC674:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820cc69c
	if (!ctx.cr6.eq) goto loc_820CC69C;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC68C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc4c8
	if (ctx.cr6.eq) goto loc_820CC4C8;
	// lwz r29,0(r26)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r27,4(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
loc_820CC69C:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_820CC6A8:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r7,r23,256
	ctx.r7.s64 = ctx.r23.s64 + 256;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r30,r7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r7.s32, ctx.xer);
	// sthx r11,r8,r25
	PPC_STORE_U16(ctx.r8.u32 + ctx.r25.u32, ctx.r11.u16);
	// blt cr6,0x820cc5fc
	if (ctx.cr6.lt) goto loc_820CC5FC;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// blt cr6,0x820cc748
	if (ctx.cr6.lt) goto loc_820CC748;
	// addi r31,r25,-2
	ctx.r31.s64 = ctx.r25.s64 + -2;
	// li r30,8
	ctx.r30.s64 = 8;
loc_820CC6DC:
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
	// stw r7,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 6);
	// stw r5,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
	// lhz r7,10(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 10);
	// stw r7,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r7.u32);
	// lhz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// stw r5,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r5.u32);
	// lhz r9,14(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 14);
	// stw r9,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r9.u32);
	// lhzu r8,16(r31)
	ea = 16 + ctx.r31.u32;
	ctx.r8.u64 = PPC_LOAD_U16(ea);
	ctx.r31.u32 = ea;
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r22,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r22.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820CC740;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x820cc6dc
	if (!ctx.cr0.eq) goto loc_820CC6DC;
loc_820CC748:
	// addi r21,r21,-65
	ctx.r21.s64 = ctx.r21.s64 + -65;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820cc758
	if (ctx.cr6.eq) goto loc_820CC758;
	// addi r21,r21,-64
	ctx.r21.s64 = ctx.r21.s64 + -64;
loc_820CC758:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// bgt cr6,0x820cc53c
	if (ctx.cr6.gt) goto loc_820CC53C;
loc_820CC760:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq cr6,0x820cc788
	if (ctx.cr6.eq) goto loc_820CC788;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CC788;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC788:
	// stw r29,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r27,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r27.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CC79C"))) PPC_WEAK_FUNC(sub_820CC79C);
PPC_FUNC_IMPL(__imp__sub_820CC79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CC7A0"))) PPC_WEAK_FUNC(sub_820CC7A0);
PPC_FUNC_IMPL(__imp__sub_820CC7A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820CC7A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,24(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820cc7ec
	if (!ctx.cr6.eq) goto loc_820CC7EC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC7D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cc7e4
	if (!ctx.cr6.eq) goto loc_820CC7E4;
loc_820CC7D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CC7E4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820CC7EC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r27,r9,8
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820cc820
	if (!ctx.cr0.eq) goto loc_820CC820;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC810;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc7d8
	if (ctx.cr6.eq) goto loc_820CC7D8;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820CC820:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// addi r28,r10,-1
	ctx.r28.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r27
	ctx.r11.u64 = ctx.r9.u64 + ctx.r27.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820cc858
	if (ctx.cr6.eq) goto loc_820CC858;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CC858;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC858:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820cc880
	if (!ctx.cr6.eq) goto loc_820CC880;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC870;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc7d8
	if (ctx.cr6.eq) goto loc_820CC7D8;
	// lwz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r28,4(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820CC880:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addic. r27,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r27.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// rotlwi r28,r11,8
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// bne 0x820cc8b4
	if (!ctx.cr0.eq) goto loc_820CC8B4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC8A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cc7d8
	if (ctx.cr6.eq) goto loc_820CC7D8;
	// lwz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r27,4(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820CC8B4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r9,82
	ctx.r9.s64 = 82;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r28,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r28.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CC8E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r5,r29,1
	ctx.r5.s64 = ctx.r29.s64 + 1;
	// addi r4,r27,-1
	ctx.r4.s64 = ctx.r27.s64 + -1;
	// stw r28,280(r30)
	PPC_STORE_U32(ctx.r30.u32 + 280, ctx.r28.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CC908"))) PPC_WEAK_FUNC(sub_820CC908);
PPC_FUNC_IMPL(__imp__sub_820CC908) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820CC910;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// add r29,r5,r6
	ctx.r29.u64 = ctx.r5.u64 + ctx.r6.u64;
	// cmplwi cr6,r5,14
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 14, ctx.xer);
	// blt cr6,0x820ccae8
	if (ctx.cr6.lt) goto loc_820CCAE8;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,74
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 74, ctx.xer);
	// bne cr6,0x820ccae8
	if (!ctx.cr6.eq) goto loc_820CCAE8;
	// lbz r11,1(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// cmplwi cr6,r11,70
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 70, ctx.xer);
	// bne cr6,0x820ccae8
	if (!ctx.cr6.eq) goto loc_820CCAE8;
	// lbz r11,2(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi cr6,r11,73
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 73, ctx.xer);
	// bne cr6,0x820ccae8
	if (!ctx.cr6.eq) goto loc_820CCAE8;
	// lbz r11,3(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// cmplwi cr6,r11,70
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 70, ctx.xer);
	// bne cr6,0x820ccae8
	if (!ctx.cr6.eq) goto loc_820CCAE8;
	// lbz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ccae8
	if (!ctx.cr6.eq) goto loc_820CCAE8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 284, ctx.r11.u32);
	// lbz r10,5(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// stb r10,288(r3)
	PPC_STORE_U8(ctx.r3.u32 + 288, ctx.r10.u8);
	// lbz r9,6(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// stb r9,289(r3)
	PPC_STORE_U8(ctx.r3.u32 + 289, ctx.r9.u8);
	// lbz r8,7(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// stb r8,290(r3)
	PPC_STORE_U8(ctx.r3.u32 + 290, ctx.r8.u8);
	// lbz r11,9(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// lbz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rotlwi r10,r7,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r5,288(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 288);
	// sth r6,292(r3)
	PPC_STORE_U16(ctx.r3.u32 + 292, ctx.r6.u16);
	// lbz r10,11(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// lbz r3,10(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// rotlwi r11,r3,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// sth r11,294(r31)
	PPC_STORE_U16(ctx.r31.u32 + 294, ctx.r11.u16);
	// beq cr6,0x820cc9f4
	if (ctx.cr6.eq) goto loc_820CC9F4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,119
	ctx.r10.s64 = 119;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lbz r9,288(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 288);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r6,289(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 289);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CC9F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CC9F4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,87
	ctx.r10.s64 = 87;
	// lbz r9,288(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 288);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// lbz r8,289(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 289);
	// stw r8,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r8.u32);
	// lhz r7,292(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 292);
	// stw r7,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r7.u32);
	// lhz r6,294(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 294);
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// lbz r5,290(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 290);
	// stw r5,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r5.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820CCA44;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r8,13(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 13);
	// lbz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820cca94
	if (ctx.cr6.eq) goto loc_820CCA94;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,90
	ctx.r10.s64 = 90;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r6,13(r30)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r30.u32 + 13);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCA94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CCA94:
	// lbz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// addi r10,r29,-14
	ctx.r10.s64 = ctx.r29.s64 + -14;
	// lbz r11,13(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 13);
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x820ccc10
	if (ctx.cr6.eq) goto loc_820CCC10;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,88
	ctx.r9.s64 = 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CCAE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820CCAE8:
	// cmplwi cr6,r5,6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 6, ctx.xer);
	// blt cr6,0x820ccbe4
	if (ctx.cr6.lt) goto loc_820CCBE4;
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,74
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 74, ctx.xer);
	// bne cr6,0x820ccbe4
	if (!ctx.cr6.eq) goto loc_820CCBE4;
	// lbz r11,1(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// cmplwi cr6,r11,70
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 70, ctx.xer);
	// bne cr6,0x820ccbe4
	if (!ctx.cr6.eq) goto loc_820CCBE4;
	// lbz r11,2(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 2);
	// cmplwi cr6,r11,88
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 88, ctx.xer);
	// bne cr6,0x820ccbe4
	if (!ctx.cr6.eq) goto loc_820CCBE4;
	// lbz r11,3(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 3);
	// cmplwi cr6,r11,88
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 88, ctx.xer);
	// bne cr6,0x820ccbe4
	if (!ctx.cr6.eq) goto loc_820CCBE4;
	// lbz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ccbe4
	if (!ctx.cr6.eq) goto loc_820CCBE4;
	// lbz r11,5(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 5);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x820ccbdc
	if (ctx.cr6.eq) goto loc_820CCBDC;
	// cmplwi cr6,r11,17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 17, ctx.xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820ccbb0
	if (ctx.cr6.eq) goto loc_820CCBB0;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// beq cr6,0x820ccb88
	if (ctx.cr6.eq) goto loc_820CCB88;
	// li r10,89
	ctx.r10.s64 = 89;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r8,5(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 5);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820CCB80;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820CCB88:
	// li r10,110
	ctx.r10.s64 = 110;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CCBA8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820CCBB0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,109
	ctx.r10.s64 = 109;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CCBD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820CCBDC:
	// li r10,108
	ctx.r10.s64 = 108;
	// b 0x820ccbe8
	goto loc_820CCBE8;
loc_820CCBE4:
	// li r10,77
	ctx.r10.s64 = 77;
loc_820CCBE8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CCC10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CCC10:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CCC18"))) PPC_WEAK_FUNC(sub_820CCC18);
PPC_FUNC_IMPL(__imp__sub_820CCC18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820CCC20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,12
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 12, ctx.xer);
	// blt cr6,0x820cccf0
	if (ctx.cr6.lt) goto loc_820CCCF0;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,65
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65, ctx.xer);
	// bne cr6,0x820cccf0
	if (!ctx.cr6.eq) goto loc_820CCCF0;
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// cmplwi cr6,r10,100
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 100, ctx.xer);
	// bne cr6,0x820cccf0
	if (!ctx.cr6.eq) goto loc_820CCCF0;
	// lbz r10,2(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi cr6,r10,111
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 111, ctx.xer);
	// bne cr6,0x820cccf0
	if (!ctx.cr6.eq) goto loc_820CCCF0;
	// lbz r10,3(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// cmplwi cr6,r10,98
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 98, ctx.xer);
	// bne cr6,0x820cccf0
	if (!ctx.cr6.eq) goto loc_820CCCF0;
	// lbz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// cmplwi cr6,r10,101
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 101, ctx.xer);
	// bne cr6,0x820cccf0
	if (!ctx.cr6.eq) goto loc_820CCCF0;
	// lbz r8,9(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// li r30,76
	ctx.r30.s64 = 76;
	// lbz r10,7(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rotlwi r6,r8,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// rotlwi r8,r5,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lbz r7,6(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// lbz r5,10(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10);
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lbz r29,11(r11)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 + ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// stw r29,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r29.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r30,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820CCCDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r29,300(r31)
	PPC_STORE_U8(ctx.r31.u32 + 300, ctx.r29.u8);
	// stw r4,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820CCCF0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,78
	ctx.r10.s64 = 78;
	// add r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 + ctx.r6.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CCD20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CCD28"))) PPC_WEAK_FUNC(sub_820CCD28);
PPC_FUNC_IMPL(__imp__sub_820CCD28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820CCD30;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,24(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820ccd74
	if (!ctx.cr6.eq) goto loc_820CCD74;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCD58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820ccd6c
	if (!ctx.cr6.eq) goto loc_820CCD6C;
loc_820CCD60:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_820CCD6C:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CCD74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r30,r9,8
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820ccda8
	if (!ctx.cr0.eq) goto loc_820CCDA8;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCD98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ccd60
	if (ctx.cr6.eq) goto loc_820CCD60;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CCDA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// addi r29,r10,-1
	ctx.r29.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r30
	ctx.r11.u64 = ctx.r9.u64 + ctx.r30.u64;
	// addi r26,r11,-2
	ctx.r26.s64 = ctx.r11.s64 + -2;
	// cmpwi cr6,r26,14
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 14, ctx.xer);
	// blt cr6,0x820ccdcc
	if (ctx.cr6.lt) goto loc_820CCDCC;
	// li r28,14
	ctx.r28.s64 = 14;
	// b 0x820ccddc
	goto loc_820CCDDC;
loc_820CCDCC:
	// subfic r11,r26,0
	ctx.xer.ca = ctx.r26.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r26.s64;
	// rlwinm r10,r26,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0x1;
	// addme r9,r10
	{ uint8_t _ca = (ctx.r10.u32 + 0xFFFFFFFF < ctx.r10.u32) | (ctx.r10.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r9.u64 = ctx.r10.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// and r28,r9,r26
	ctx.r28.u64 = ctx.r9.u64 & ctx.r26.u64;
loc_820CCDDC:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820cce30
	if (ctx.cr6.eq) goto loc_820CCE30;
loc_820CCDE8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820cce10
	if (!ctx.cr6.eq) goto loc_820CCE10;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCE00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ccd60
	if (ctx.cr6.eq) goto loc_820CCD60;
	// lwz r31,0(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r29,4(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_820CCE10:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stbx r11,r30,r10
	PPC_STORE_U8(ctx.r30.u32 + ctx.r10.u32, ctx.r11.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x820ccde8
	if (ctx.cr6.lt) goto loc_820CCDE8;
loc_820CCE30:
	// lwz r11,420(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 420);
	// subf r30,r28,r26
	ctx.r30.s64 = ctx.r26.s64 - ctx.r28.s64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// cmpwi cr6,r11,224
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 224, ctx.xer);
	// beq cr6,0x820cce8c
	if (ctx.cr6.eq) goto loc_820CCE8C;
	// cmpwi cr6,r11,238
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 238, ctx.xer);
	// beq cr6,0x820cce78
	if (ctx.cr6.eq) goto loc_820CCE78;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// li r10,68
	ctx.r10.s64 = 68;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r8,420(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 420);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CCE74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820cce9c
	goto loc_820CCE9C;
loc_820CCE78:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820ccc18
	ctx.lr = 0x820CCE88;
	sub_820CCC18(ctx, base);
	// b 0x820cce9c
	goto loc_820CCE9C;
loc_820CCE8C:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820cc908
	ctx.lr = 0x820CCE9C;
	sub_820CC908(ctx, base);
loc_820CCE9C:
	// stw r31,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r31.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r29.u32);
	// ble cr6,0x820ccec4
	if (!ctx.cr6.gt) goto loc_820CCEC4;
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CCEC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CCEC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CCED0"))) PPC_WEAK_FUNC(sub_820CCED0);
PPC_FUNC_IMPL(__imp__sub_820CCED0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820CCED8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,24(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820ccf1c
	if (!ctx.cr6.eq) goto loc_820CCF1C;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCF00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820ccf14
	if (!ctx.cr6.eq) goto loc_820CCF14;
loc_820CCF08:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CCF14:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
loc_820CCF1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r27,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r27.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// rotlwi r29,r9,8
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x820ccf50
	if (!ctx.cr0.eq) goto loc_820CCF50;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCF40;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ccf08
	if (ctx.cr6.eq) goto loc_820CCF08;
	// lwz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r27,4(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
loc_820CCF50:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,91
	ctx.r9.s64 = 91;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// addi r29,r11,-2
	ctx.r29.s64 = ctx.r11.s64 + -2;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,420(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r29,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r29.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CCF94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r28,1
	ctx.r10.s64 = ctx.r28.s64 + 1;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r9,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// ble cr6,0x820ccfc4
	if (!ctx.cr6.gt) goto loc_820CCFC4;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CCFC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CCFC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CCFD0"))) PPC_WEAK_FUNC(sub_820CCFD0);
PPC_FUNC_IMPL(__imp__sub_820CCFD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820CCFD8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,24(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r31,4(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
loc_820CCFEC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820cd014
	if (!ctx.cr6.eq) goto loc_820CD014;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD004;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd0dc
	if (ctx.cr6.eq) goto loc_820CD0DC;
	// lwz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r31,4(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
loc_820CD014:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// beq cr6,0x820cd07c
	if (ctx.cr6.eq) goto loc_820CD07C;
loc_820CD028:
	// lwz r11,444(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 444);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// bne cr6,0x820cd068
	if (!ctx.cr6.eq) goto loc_820CD068;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD058;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd0dc
	if (ctx.cr6.eq) goto loc_820CD0DC;
	// lwz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r31,4(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
loc_820CD068:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// bne cr6,0x820cd028
	if (!ctx.cr6.eq) goto loc_820CD028;
loc_820CD07C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820cd0a4
	if (!ctx.cr6.eq) goto loc_820CD0A4;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD094;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd0dc
	if (ctx.cr6.eq) goto loc_820CD0DC;
	// lwz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r31,4(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
loc_820CD0A4:
	// lbz r28,0(r29)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r28,255
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 255, ctx.xer);
	// beq cr6,0x820cd07c
	if (ctx.cr6.eq) goto loc_820CD07C;
	// lwz r11,444(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 444);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// bne cr6,0x820cd0e8
	if (!ctx.cr6.eq) goto loc_820CD0E8;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// b 0x820ccfec
	goto loc_820CCFEC;
loc_820CD0DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CD0E8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820cd138
	if (ctx.cr6.eq) goto loc_820CD138;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// li r10,116
	ctx.r10.s64 = 116;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,444(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 444);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r28,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r28.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD12C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,444(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 444);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
loc_820CD138:
	// stw r28,420(r27)
	PPC_STORE_U32(ctx.r27.u32 + 420, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CD150"))) PPC_WEAK_FUNC(sub_820CD150);
PPC_FUNC_IMPL(__imp__sub_820CD150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820CD158;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,24(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820cd19c
	if (!ctx.cr6.eq) goto loc_820CD19C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD180;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cd194
	if (!ctx.cr6.eq) goto loc_820CD194;
loc_820CD188:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820CD194:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820CD19C:
	// lbz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x820cd1cc
	if (!ctx.cr0.eq) goto loc_820CD1CC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD1BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd188
	if (ctx.cr6.eq) goto loc_820CD188;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820CD1CC:
	// lbz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r27,r10,-1
	ctx.r27.s64 = ctx.r10.s64 + -1;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r28,255
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 255, ctx.xer);
	// bne cr6,0x820cd1e8
	if (!ctx.cr6.eq) goto loc_820CD1E8;
	// cmpwi cr6,r30,216
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 216, ctx.xer);
	// beq cr6,0x820cd218
	if (ctx.cr6.eq) goto loc_820CD218;
loc_820CD1E8:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,53
	ctx.r10.s64 = 53;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r28,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r28.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r30,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r30.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CD218;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CD218:
	// stw r30,420(r29)
	PPC_STORE_U32(ctx.r29.u32 + 420, ctx.r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CD230"))) PPC_WEAK_FUNC(sub_820CD230);
PPC_FUNC_IMPL(__imp__sub_820CD230) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820CD238;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,60
	ctx.r27.s64 = 60;
	// li r28,92
	ctx.r28.s64 = 92;
	// li r29,68
	ctx.r29.s64 = 68;
	// li r30,0
	ctx.r30.s64 = 0;
loc_820CD250:
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820cd284
	if (!ctx.cr6.eq) goto loc_820CD284;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820cd278
	if (!ctx.cr6.eq) goto loc_820CD278;
	// bl 0x820cd150
	ctx.lr = 0x820CD274;
	sub_820CD150(ctx, base);
	// b 0x820cd27c
	goto loc_820CD27C;
loc_820CD278:
	// bl 0x820ccfd0
	ctx.lr = 0x820CD27C;
	sub_820CCFD0(ctx, base);
loc_820CD27C:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd530
	if (ctx.cr6.eq) goto loc_820CD530;
loc_820CD284:
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r11,207
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 207, ctx.xer);
	// bgt cr6,0x820cd394
	if (ctx.cr6.gt) goto loc_820CD394;
	// cmpwi cr6,r11,205
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 205, ctx.xer);
	// bge cr6,0x820cd364
	if (!ctx.cr6.lt) goto loc_820CD364;
	// cmpwi cr6,r11,200
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 200, ctx.xer);
	// bgt cr6,0x820cd310
	if (ctx.cr6.gt) goto loc_820CD310;
	// cmpwi cr6,r11,197
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 197, ctx.xer);
	// bge cr6,0x820cd364
	if (!ctx.cr6.lt) goto loc_820CD364;
	// cmpwi cr6,r11,194
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 194, ctx.xer);
	// bgt cr6,0x820cd2f4
	if (ctx.cr6.gt) goto loc_820CD2F4;
	// beq cr6,0x820cd2e0
	if (ctx.cr6.eq) goto loc_820CD2E0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820cd3fc
	if (ctx.cr6.eq) goto loc_820CD3FC;
	// cmpwi cr6,r11,191
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 191, ctx.xer);
	// ble cr6,0x820cd488
	if (!ctx.cr6.gt) goto loc_820CD488;
	// cmpwi cr6,r11,193
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 193, ctx.xer);
	// bgt cr6,0x820cd488
	if (ctx.cr6.gt) goto loc_820CD488;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb8e8
	ctx.lr = 0x820CD2DC;
	sub_820CB8E8(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD2E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb8e8
	ctx.lr = 0x820CD2F0;
	sub_820CB8E8(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD2F4:
	// cmpwi cr6,r11,195
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 195, ctx.xer);
	// beq cr6,0x820cd364
	if (ctx.cr6.eq) goto loc_820CD364;
	// cmpwi cr6,r11,196
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 196, ctx.xer);
	// bne cr6,0x820cd488
	if (!ctx.cr6.eq) goto loc_820CD488;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc0f0
	ctx.lr = 0x820CD30C;
	sub_820CC0F0(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD310:
	// addi r11,r11,-201
	ctx.r11.s64 = ctx.r11.s64 + -201;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x820cd488
	if (ctx.cr6.gt) goto loc_820CD488;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820cd344
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820CD344;
	// bdzf 4*cr6+eq,0x820cd364
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820CD364;
	// bne cr6,0x820cd358
	if (!ctx.cr6.eq) goto loc_820CD358;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb8e8
	ctx.lr = 0x820CD340;
	sub_820CB8E8(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD344:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb8e8
	ctx.lr = 0x820CD354;
	sub_820CB8E8(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD358:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cced0
	ctx.lr = 0x820CD360;
	sub_820CCED0(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD364:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,420(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CD38C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// b 0x820cd250
	goto loc_820CD250;
loc_820CD394:
	// cmpwi cr6,r11,219
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 219, ctx.xer);
	// bgt cr6,0x820cd43c
	if (ctx.cr6.gt) goto loc_820CD43C;
	// beq cr6,0x820cd430
	if (ctx.cr6.eq) goto loc_820CD430;
	// addi r11,r11,-208
	ctx.r11.s64 = ctx.r11.s64 + -208;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x820cd488
	if (ctx.cr6.gt) goto loc_820CD488;
	// lis r12,-32243
	ctx.r12.s64 = -2113077248;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-11324
	ctx.r12.s64 = ctx.r12.s64 + -11324;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_820CD3FC;
	case 1:
		goto loc_820CD3FC;
	case 2:
		goto loc_820CD3FC;
	case 3:
		goto loc_820CD3FC;
	case 4:
		goto loc_820CD3FC;
	case 5:
		goto loc_820CD3FC;
	case 6:
		goto loc_820CD3FC;
	case 7:
		goto loc_820CD3FC;
	case 8:
		goto loc_820CD3F0;
	case 9:
		goto loc_820CD4FC;
	case 10:
		goto loc_820CD4DC;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11268(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11268);
	// lwz r16,-11280(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11280);
	// lwz r16,-11012(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11012);
	// lwz r16,-11044(r12)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r12.u32 + -11044);
loc_820CD3F0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cb810
	ctx.lr = 0x820CD3F8;
	sub_820CB810(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD3FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r9,420(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CD428;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// b 0x820cd250
	goto loc_820CD250;
loc_820CD430:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc490
	ctx.lr = 0x820CD438;
	sub_820CC490(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD43C:
	// cmpwi cr6,r11,239
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 239, ctx.xer);
	// bgt cr6,0x820cd480
	if (ctx.cr6.gt) goto loc_820CD480;
	// cmpwi cr6,r11,224
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 224, ctx.xer);
	// bge cr6,0x820cd468
	if (!ctx.cr6.lt) goto loc_820CD468;
	// cmpwi cr6,r11,220
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 220, ctx.xer);
	// beq cr6,0x820cd358
	if (ctx.cr6.eq) goto loc_820CD358;
	// cmpwi cr6,r11,221
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 221, ctx.xer);
	// bne cr6,0x820cd488
	if (!ctx.cr6.eq) goto loc_820CD488;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cc7a0
	ctx.lr = 0x820CD464;
	sub_820CC7A0(ctx, base);
	// b 0x820cd4cc
	goto loc_820CD4CC;
loc_820CD468:
	// addi r11,r11,-216
	ctx.r11.s64 = ctx.r11.s64 + -216;
	// lwz r10,444(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// b 0x820cd4c4
	goto loc_820CD4C4;
loc_820CD480:
	// cmpwi cr6,r11,254
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 254, ctx.xer);
	// beq cr6,0x820cd4b8
	if (ctx.cr6.eq) goto loc_820CD4B8;
loc_820CD488:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,420(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CD4B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// b 0x820cd250
	goto loc_820CD250;
loc_820CD4B8:
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820CD4C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CD4CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CD4CC:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd530
	if (ctx.cr6.eq) goto loc_820CD530;
	// stw r30,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// b 0x820cd250
	goto loc_820CD250;
loc_820CD4DC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cbd38
	ctx.lr = 0x820CD4E4;
	sub_820CBD38(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd530
	if (ctx.cr6.eq) goto loc_820CD530;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CD4FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,85
	ctx.r10.s64 = 85;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820CD520;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r30,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CD530:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CD53C"))) PPC_WEAK_FUNC(sub_820CD53C);
PPC_FUNC_IMPL(__imp__sub_820CD53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CD540"))) PPC_WEAK_FUNC(sub_820CD540);
PPC_FUNC_IMPL(__imp__sub_820CD540) {
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
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820cd584
	if (!ctx.cr6.eq) goto loc_820CD584;
	// bl 0x820ccfd0
	ctx.lr = 0x820CD564;
	sub_820CCFD0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820cd584
	if (!ctx.cr6.eq) goto loc_820CD584;
loc_820CD56C:
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
loc_820CD584:
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r10,420(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// addi r9,r4,208
	ctx.r9.s64 = ctx.r4.s64 + 208;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x820cd5dc
	if (!ctx.cr6.eq) goto loc_820CD5DC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,98
	ctx.r10.s64 = 98;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,444(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820CD5D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r4,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r4.u32);
	// b 0x820cd5f8
	goto loc_820CD5F8;
loc_820CD5DC:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CD5F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd56c
	if (ctx.cr6.eq) goto loc_820CD56C;
loc_820CD5F8:
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_820CD624"))) PPC_WEAK_FUNC(sub_820CD624);
PPC_FUNC_IMPL(__imp__sub_820CD624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CD628"))) PPC_WEAK_FUNC(sub_820CD628);
PPC_FUNC_IMPL(__imp__sub_820CD628) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820CD630;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,121
	ctx.r10.s64 = 121;
	// lwz r30,420(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r30,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r30.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r28,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r28.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820CD670;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r27,97
	ctx.r27.s64 = 97;
loc_820CD674:
	// cmpwi cr6,r30,192
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 192, ctx.xer);
	// bge cr6,0x820cd684
	if (!ctx.cr6.lt) goto loc_820CD684;
loc_820CD67C:
	// li r31,2
	ctx.r31.s64 = 2;
	// b 0x820cd6f0
	goto loc_820CD6F0;
loc_820CD684:
	// cmpwi cr6,r30,208
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 208, ctx.xer);
	// blt cr6,0x820cd6ec
	if (ctx.cr6.lt) goto loc_820CD6EC;
	// cmpwi cr6,r30,215
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 215, ctx.xer);
	// bgt cr6,0x820cd6ec
	if (ctx.cr6.gt) goto loc_820CD6EC;
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = ctx.r11.s64 + 208;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820cd6ec
	if (ctx.cr6.eq) goto loc_820CD6EC;
	// addi r11,r28,2
	ctx.r11.s64 = ctx.r28.s64 + 2;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = ctx.r11.s64 + 208;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820cd6ec
	if (ctx.cr6.eq) goto loc_820CD6EC;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = ctx.r11.s64 + 208;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820cd67c
	if (ctx.cr6.eq) goto loc_820CD67C;
	// addi r11,r28,-2
	ctx.r11.s64 = ctx.r28.s64 + -2;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = ctx.r11.s64 + 208;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820cd67c
	if (ctx.cr6.eq) goto loc_820CD67C;
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x820cd6f0
	goto loc_820CD6F0;
loc_820CD6EC:
	// li r31,3
	ctx.r31.s64 = 3;
loc_820CD6F0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r27.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r30,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r30.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r31,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r31.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820CD720;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// beq cr6,0x820cd768
	if (ctx.cr6.eq) goto loc_820CD768;
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// beq cr6,0x820cd744
	if (ctx.cr6.eq) goto loc_820CD744;
	// cmpwi cr6,r31,3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 3, ctx.xer);
	// bne cr6,0x820cd674
	if (!ctx.cr6.eq) goto loc_820CD674;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CD744:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820ccfd0
	ctx.lr = 0x820CD74C;
	sub_820CCFD0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cd75c
	if (ctx.cr6.eq) goto loc_820CD75C;
	// lwz r30,420(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 420);
	// b 0x820cd674
	goto loc_820CD674;
loc_820CD75C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820CD768:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,420(r29)
	PPC_STORE_U32(ctx.r29.u32 + 420, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CD77C"))) PPC_WEAK_FUNC(sub_820CD77C);
PPC_FUNC_IMPL(__imp__sub_820CD77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CD780"))) PPC_WEAK_FUNC(sub_820CD780);
PPC_FUNC_IMPL(__imp__sub_820CD780) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,444(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 444);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,220(r3)
	PPC_STORE_U32(ctx.r3.u32 + 220, ctx.r11.u32);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// stw r11,420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 420, ctx.r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r11.u32);
	// stw r11,164(r10)
	PPC_STORE_U32(ctx.r10.u32 + 164, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CD7A8"))) PPC_WEAK_FUNC(sub_820CD7A8);
PPC_FUNC_IMPL(__imp__sub_820CD7A8) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,172
	ctx.r5.s64 = 172;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CD7D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// stw r3,444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 444, ctx.r3.u32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r10,r7,-11728
	ctx.r10.s64 = ctx.r7.s64 + -11728;
	// addi r4,r8,-10368
	ctx.r4.s64 = ctx.r8.s64 + -10368;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// addi r8,r6,-10944
	ctx.r8.s64 = ctx.r6.s64 + -10944;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r7,r5,-12592
	ctx.r7.s64 = ctx.r5.s64 + -12592;
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// stw r7,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r7.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CD81C:
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r8,r9,-12592
	ctx.r8.s64 = ctx.r9.s64 + -12592;
	// stw r8,-64(r10)
	PPC_STORE_U32(ctx.r10.u32 + -64, ctx.r8.u32);
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820cd81c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CD81C;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r8,r10,-13016
	ctx.r8.s64 = ctx.r10.s64 + -13016;
	// addi r7,r9,-13016
	ctx.r7.s64 = ctx.r9.s64 + -13016;
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// stw r7,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r7.u32);
	// lwz r6,444(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// stw r11,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r11,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r11.u32);
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r11.u32);
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r11.u32);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r11.u32);
	// stw r11,164(r6)
	PPC_STORE_U32(ctx.r6.u32 + 164, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_820CD87C"))) PPC_WEAK_FUNC(sub_820CD87C);
PPC_FUNC_IMPL(__imp__sub_820CD87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CD880"))) PPC_WEAK_FUNC(sub_820CD880);
PPC_FUNC_IMPL(__imp__sub_820CD880) {
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
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CD8A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d48f0
	ctx.lr = 0x820CD8AC;
	sub_820D48F0(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r3,r9,-12524
	ctx.r3.s64 = ctx.r9.s64 + -12524;
	// bl 0x8208d988
	ctx.lr = 0x820CD8B8;
	sub_8208D988(ctx, base);
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

__attribute__((alias("__imp__sub_820CD8CC"))) PPC_WEAK_FUNC(sub_820CD8CC);
PPC_FUNC_IMPL(__imp__sub_820CD8CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CD8D0"))) PPC_WEAK_FUNC(sub_820CD8D0);
PPC_FUNC_IMPL(__imp__sub_820CD8D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820CD8F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CD900"))) PPC_WEAK_FUNC(sub_820CD900);
PPC_FUNC_IMPL(__imp__sub_820CD900) {
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
	// lwz r31,0(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x820cd960
	if (!ctx.cr6.lt) goto loc_820CD960;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820cd934
	if (ctx.cr6.eq) goto loc_820CD934;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x820cd940
	if (ctx.cr6.lt) goto loc_820CD940;
loc_820CD934:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD940;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CD940:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
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
loc_820CD960:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x820cd978
	if (ctx.cr6.lt) goto loc_820CD978;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CD978;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CD978:
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

__attribute__((alias("__imp__sub_820CD98C"))) PPC_WEAK_FUNC(sub_820CD98C);
PPC_FUNC_IMPL(__imp__sub_820CD98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CD990"))) PPC_WEAK_FUNC(sub_820CD990);
PPC_FUNC_IMPL(__imp__sub_820CD990) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x820cd9d4
	if (!ctx.cr6.gt) goto loc_820CD9D4;
	// lwz r9,116(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x820cd9d4
	if (ctx.cr6.gt) goto loc_820CD9D4;
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// b 0x820cda04
	goto loc_820CDA04;
loc_820CD9D4:
	// lwz r8,120(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820cda0c
	if (ctx.cr6.eq) goto loc_820CDA0C;
	// lwz r9,124(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820cda0c
	if (ctx.cr6.lt) goto loc_820CDA0C;
	// lwz r6,128(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// bgt cr6,0x820cda0c
	if (ctx.cr6.gt) goto loc_820CDA0C;
	// subf r9,r9,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
loc_820CDA04:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820cda18
	if (!ctx.cr6.eq) goto loc_820CDA18;
loc_820CDA0C:
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
loc_820CDA18:
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820cda48
	if (ctx.cr6.eq) goto loc_820CDA48;
loc_820CDA2C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,37
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 37, ctx.xer);
	// beq cr6,0x820cda90
	if (ctx.cr6.eq) goto loc_820CDA90;
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820cda2c
	if (!ctx.cr6.eq) goto loc_820CDA2C;
loc_820CDA48:
	// lwz r31,52(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r30,48(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// bl 0x8207a8a8
	ctx.lr = 0x820CDA78;
	sub_8207A8A8(ctx, base);
loc_820CDA78:
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
loc_820CDA90:
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,115
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 115, ctx.xer);
	// bne cr6,0x820cda48
	if (!ctx.cr6.eq) goto loc_820CDA48;
	// addi r5,r11,24
	ctx.r5.s64 = ctx.r11.s64 + 24;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8207a8a8
	ctx.lr = 0x820CDAA8;
	sub_8207A8A8(ctx, base);
	// b 0x820cda78
	goto loc_820CDA78;
}

__attribute__((alias("__imp__sub_820CDAAC"))) PPC_WEAK_FUNC(sub_820CDAAC);
PPC_FUNC_IMPL(__imp__sub_820CDAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CDAB0"))) PPC_WEAK_FUNC(sub_820CDAB0);
PPC_FUNC_IMPL(__imp__sub_820CDAB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDAC8"))) PPC_WEAK_FUNC(sub_820CDAC8);
PPC_FUNC_IMPL(__imp__sub_820CDAC8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r10,-10112
	ctx.r4.s64 = ctx.r10.s64 + -10112;
	// addi r10,r5,-13024
	ctx.r10.s64 = ctx.r5.s64 + -13024;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r9,r9,-9984
	ctx.r9.s64 = ctx.r9.s64 + -9984;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// addi r8,r8,-10032
	ctx.r8.s64 = ctx.r8.s64 + -10032;
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r11.u32);
	// addi r7,r7,-9840
	ctx.r7.s64 = ctx.r7.s64 + -9840;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r6,r6,-9552
	ctx.r6.s64 = ctx.r6.s64 + -9552;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r5,123
	ctx.r5.s64 = 123;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r5,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r5.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r11.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDB38"))) PPC_WEAK_FUNC(sub_820CDB38);
PPC_FUNC_IMPL(__imp__sub_820CDB38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,40(r4)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDB60"))) PPC_WEAK_FUNC(sub_820CDB60);
PPC_FUNC_IMPL(__imp__sub_820CDB60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820CDB68;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cdc78
	if (ctx.cr6.eq) goto loc_820CDC78;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820cdc78
	if (ctx.cr6.eq) goto loc_820CDC78;
	// lis r11,15
	ctx.r11.s64 = 983040;
	// ori r11,r11,16960
	ctx.r11.u64 = ctx.r11.u64 | 16960;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820cdbb4
	if (ctx.cr6.gt) goto loc_820CDBB4;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820cdbc4
	if (!ctx.cr6.gt) goto loc_820CDBC4;
loc_820CDBB4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r4,r11,-12368
	ctx.r4.s64 = ctx.r11.s64 + -12368;
	// bl 0x820cab60
	ctx.lr = 0x820CDBC4;
	sub_820CAB60(ctx, base);
loc_820CDBC4:
	// lwz r9,244(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// clrlwi r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stb r11,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r11.u8);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stb r10,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r10.u8);
	// stb r25,26(r31)
	PPC_STORE_U8(ctx.r31.u32 + 26, ctx.r25.u8);
	// stb r9,27(r31)
	PPC_STORE_U8(ctx.r31.u32 + 27, ctx.r9.u8);
	// stb r26,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r26.u8);
	// beq cr6,0x820cdc00
	if (ctx.cr6.eq) goto loc_820CDC00;
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r9,3
	ctx.r9.s64 = 3;
	// bne 0x820cdc04
	if (!ctx.cr0.eq) goto loc_820CDC04;
loc_820CDC00:
	// li r9,1
	ctx.r9.s64 = 1;
loc_820CDC04:
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cdc1c
	if (ctx.cr0.eq) goto loc_820CDC1C;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
loc_820CDC1C:
	// lbz r11,29(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 29);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r10,r9,65535
	ctx.r10.u64 = ctx.r9.u64 | 65535;
	// addi r9,r11,7
	ctx.r9.s64 = ctx.r11.s64 + 7;
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// srawi r9,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 3;
	// divwu r10,r10,r9
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r9.u32);
	// twllei r9,0
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820cdc68
	if (!ctx.cr6.gt) goto loc_820CDC68;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r4,r11,-12432
	ctx.r4.s64 = ctx.r11.s64 + -12432;
	// bl 0x820cab98
	ctx.lr = 0x820CDC60;
	sub_820CAB98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820cdc74
	goto loc_820CDC74;
loc_820CDC68:
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
loc_820CDC74:
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_820CDC78:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CDC80"))) PPC_WEAK_FUNC(sub_820CDC80);
PPC_FUNC_IMPL(__imp__sub_820CDC80) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r5,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r5.u32);
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// sth r6,20(r4)
	PPC_STORE_U16(ctx.r4.u32 + 20, ctx.r6.u16);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDCA8"))) PPC_WEAK_FUNC(sub_820CDCA8);
PPC_FUNC_IMPL(__imp__sub_820CDCA8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stb r5,44(r4)
	PPC_STORE_U8(ctx.r4.u32 + 44, ctx.r5.u8);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDCCC"))) PPC_WEAK_FUNC(sub_820CDCCC);
PPC_FUNC_IMPL(__imp__sub_820CDCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CDCD0"))) PPC_WEAK_FUNC(sub_820CDCD0);
PPC_FUNC_IMPL(__imp__sub_820CDCD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stb r5,44(r4)
	PPC_STORE_U8(ctx.r4.u32 + 44, ctx.r5.u8);
	// ori r10,r10,2049
	ctx.r10.u64 = ctx.r10.u64 | 2049;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lfs f0,-12328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -12328);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r4)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDD00"))) PPC_WEAK_FUNC(sub_820CDD00);
PPC_FUNC_IMPL(__imp__sub_820CDD00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820cdd1c
	if (ctx.cr6.eq) goto loc_820CDD1C;
	// stw r5,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, ctx.r5.u32);
loc_820CDD1C:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820cdd50
	if (ctx.cr6.eq) goto loc_820CDD50;
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r10,r4,52
	ctx.r10.s64 = ctx.r4.s64 + 52;
	// addi r9,r7,-2
	ctx.r9.s64 = ctx.r7.s64 + -2;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CDD38:
	// lhzu r11,2(r9)
	ea = 2 + ctx.r9.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r9.u32 = ea;
	// sthu r11,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r11.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x820cdd38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CDD38;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x820cdd50
	if (!ctx.cr6.eq) goto loc_820CDD50;
	// li r6,1
	ctx.r6.s64 = 1;
loc_820CDD50:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// sth r6,22(r4)
	PPC_STORE_U16(ctx.r4.u32 + 22, ctx.r6.u16);
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CDD64"))) PPC_WEAK_FUNC(sub_820CDD64);
PPC_FUNC_IMPL(__imp__sub_820CDD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CDD68"))) PPC_WEAK_FUNC(sub_820CDD68);
PPC_FUNC_IMPL(__imp__sub_820CDD68) {
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
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// stw r5,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// bl 0x820d2d18
	ctx.lr = 0x820CDD90;
	sub_820D2D18(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x820cdda4
	if (!ctx.cr0.eq) goto loc_820CDDA4;
loc_820CDD9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820cdeb8
	goto loc_820CDEB8;
loc_820CDDA4:
	// bl 0x8215b3e0
	ctx.lr = 0x820CDDA8;
	sub_8215B3E0(ctx, base);
	// lwz r31,80(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq 0x820cddcc
	if (ctx.cr0.eq) goto loc_820CDDCC;
	// lwz r4,1436(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// bl 0x820d2e18
	ctx.lr = 0x820CDDC0;
	sub_820D2E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d2d90
	ctx.lr = 0x820CDDC8;
	sub_820D2D90(ctx, base);
	// b 0x820cdd9c
	goto loc_820CDD9C;
loc_820CDDCC:
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r5,148(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// bl 0x820cab50
	ctx.lr = 0x820CDDDC;
	sub_820CAB50(ctx, base);
	// lwz r11,132(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cddf4
	if (ctx.cr6.eq) goto loc_820CDDF4;
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,49
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 49, ctx.xer);
	// beq cr6,0x820cde04
	if (ctx.cr6.eq) goto loc_820CDE04;
loc_820CDDF4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-12488
	ctx.r4.s64 = ctx.r11.s64 + -12488;
	// bl 0x820cab60
	ctx.lr = 0x820CDE04;
	sub_820CAB60(ctx, base);
loc_820CDE04:
	// li r11,8192
	ctx.r11.s64 = 8192;
	// li r4,8192
	ctx.r4.s64 = 8192;
	// stw r11,1440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1440, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d2da8
	ctx.lr = 0x820CDE18;
	sub_820D2DA8(ctx, base);
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r3,1436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1436, ctx.r3.u32);
	// addi r11,r11,-21312
	ctx.r11.s64 = ctx.r11.s64 + -21312;
	// addi r10,r10,-21200
	ctx.r10.s64 = ctx.r10.s64 + -21200;
	// stw r11,1412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1412, ctx.r11.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r10,1416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1416, ctx.r10.u32);
	// li r5,56
	ctx.r5.s64 = 56;
	// stw r31,1420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1420, ctx.r31.u32);
	// addi r4,r11,-12140
	ctx.r4.s64 = ctx.r11.s64 + -12140;
	// addi r3,r31,1380
	ctx.r3.s64 = ctx.r31.s64 + 1380;
	// bl 0x820d6608
	ctx.lr = 0x820CDE4C;
	sub_820D6608(ctx, base);
	// cmpwi cr6,r3,-6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -6, ctx.xer);
	// beq cr6,0x820cde84
	if (ctx.cr6.eq) goto loc_820CDE84;
	// cmpwi cr6,r3,-4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -4, ctx.xer);
	// beq cr6,0x820cde78
	if (ctx.cr6.eq) goto loc_820CDE78;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x820cde78
	if (ctx.cr6.eq) goto loc_820CDE78;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820cde94
	if (ctx.cr6.eq) goto loc_820CDE94;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12160
	ctx.r4.s64 = ctx.r11.s64 + -12160;
	// b 0x820cde8c
	goto loc_820CDE8C;
loc_820CDE78:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12180
	ctx.r4.s64 = ctx.r11.s64 + -12180;
	// b 0x820cde8c
	goto loc_820CDE8C;
loc_820CDE84:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12200
	ctx.r4.s64 = ctx.r11.s64 + -12200;
loc_820CDE8C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820CDE94;
	sub_820CAB60(ctx, base);
loc_820CDE94:
	// lwz r11,1436(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,1392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1392, ctx.r11.u32);
	// lwz r11,1440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1440);
	// stw r11,1396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1396, ctx.r11.u32);
	// bl 0x820d09b8
	ctx.lr = 0x820CDEB4;
	sub_820D09B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820CDEB8:
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

__attribute__((alias("__imp__sub_820CDECC"))) PPC_WEAK_FUNC(sub_820CDECC);
PPC_FUNC_IMPL(__imp__sub_820CDECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CDED0"))) PPC_WEAK_FUNC(sub_820CDED0);
PPC_FUNC_IMPL(__imp__sub_820CDED0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820CDED8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r31,1564(r3)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1564);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8, ctx.xer);
	// bge cr6,0x820cdf64
	if (!ctx.cr6.lt) goto loc_820CDF64;
	// subfic r30,r31,8
	ctx.xer.ca = ctx.r31.u32 <= 8;
	ctx.r30.s64 = 8 - ctx.r31.s64;
	// add r11,r31,r4
	ctx.r11.u64 = ctx.r31.u64 + ctx.r4.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r11,32
	ctx.r4.s64 = ctx.r11.s64 + 32;
	// bl 0x820d0998
	ctx.lr = 0x820CDF04;
	sub_820D0998(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r29,r27,32
	ctx.r29.s64 = ctx.r27.s64 + 32;
	// stb r11,1564(r28)
	PPC_STORE_U8(ctx.r28.u32 + 1564, ctx.r11.u8);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820cac48
	ctx.lr = 0x820CDF20;
	sub_820CAC48(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdf64
	if (ctx.cr0.eq) goto loc_820CDF64;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// bge cr6,0x820cdf54
	if (!ctx.cr6.lt) goto loc_820CDF54;
	// addi r5,r30,-4
	ctx.r5.s64 = ctx.r30.s64 + -4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820cac48
	ctx.lr = 0x820CDF40;
	sub_820CAC48(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdf54
	if (ctx.cr0.eq) goto loc_820CDF54;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12036
	ctx.r4.s64 = ctx.r11.s64 + -12036;
	// b 0x820cdf5c
	goto loc_820CDF5C;
loc_820CDF54:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12076
	ctx.r4.s64 = ctx.r11.s64 + -12076;
loc_820CDF5C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820cab60
	ctx.lr = 0x820CDF64;
	sub_820CAB60(ctx, base);
loc_820CDF64:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r31,r28,1548
	ctx.r31.s64 = ctx.r28.s64 + 1548;
	// addi r30,r11,-12208
	ctx.r30.s64 = ctx.r11.s64 + -12208;
loc_820CDF70:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d0998
	ctx.lr = 0x820CDF80;
	sub_820D0998(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d76f8
	ctx.lr = 0x820CDF8C;
	sub_820D76F8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820cad38
	ctx.lr = 0x820CDF98;
	sub_820CAD38(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d6b70
	ctx.lr = 0x820CDFA8;
	sub_820D6B70(ctx, base);
	// addi r10,r30,-48
	ctx.r10.s64 = ctx.r30.s64 + -48;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
loc_820CDFB4:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820cdfd4
	if (!ctx.cr0.eq) goto loc_820CDFD4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x820cdfb4
	if (!ctx.cr6.eq) goto loc_820CDFB4;
loc_820CDFD4:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820cdff0
	if (!ctx.cr0.eq) goto loc_820CDFF0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d7860
	ctx.lr = 0x820CDFEC;
	sub_820D7860(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CDFF0:
	// addi r10,r30,-24
	ctx.r10.s64 = ctx.r30.s64 + -24;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
loc_820CDFFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce01c
	if (!ctx.cr0.eq) goto loc_820CE01C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820cdffc
	if (!ctx.cr6.eq) goto loc_820CDFFC;
loc_820CE01C:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce038
	if (!ctx.cr0.eq) goto loc_820CE038;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d7b28
	ctx.lr = 0x820CE034;
	sub_820D7B28(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CE038:
	// addi r10,r30,-32
	ctx.r10.s64 = ctx.r30.s64 + -32;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
loc_820CE044:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce064
	if (!ctx.cr0.eq) goto loc_820CE064;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820ce044
	if (!ctx.cr6.eq) goto loc_820CE044;
loc_820CE064:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce080
	if (!ctx.cr0.eq) goto loc_820CE080;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d7ce0
	ctx.lr = 0x820CE07C;
	sub_820D7CE0(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CE080:
	// addi r10,r30,-40
	ctx.r10.s64 = ctx.r30.s64 + -40;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
loc_820CE08C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce0ac
	if (!ctx.cr0.eq) goto loc_820CE0AC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820ce08c
	if (!ctx.cr6.eq) goto loc_820CE08C;
loc_820CE0AC:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820ce194
	if (ctx.cr0.eq) goto loc_820CE194;
	// addi r10,r30,-16
	ctx.r10.s64 = ctx.r30.s64 + -16;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
loc_820CE0C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce0e0
	if (!ctx.cr0.eq) goto loc_820CE0E0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820ce0c0
	if (!ctx.cr6.eq) goto loc_820CE0C0;
loc_820CE0E0:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce0fc
	if (!ctx.cr0.eq) goto loc_820CE0FC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d7d60
	ctx.lr = 0x820CE0F8;
	sub_820D7D60(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CE0FC:
	// addi r10,r30,-8
	ctx.r10.s64 = ctx.r30.s64 + -8;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
loc_820CE108:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce128
	if (!ctx.cr0.eq) goto loc_820CE128;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820ce108
	if (!ctx.cr6.eq) goto loc_820CE108;
loc_820CE128:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce144
	if (!ctx.cr0.eq) goto loc_820CE144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d7f00
	ctx.lr = 0x820CE140;
	sub_820D7F00(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CE144:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
loc_820CE150:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820ce170
	if (!ctx.cr0.eq) goto loc_820CE170;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820ce150
	if (!ctx.cr6.eq) goto loc_820CE150;
loc_820CE170:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bne 0x820ce18c
	if (!ctx.cr0.eq) goto loc_820CE18C;
	// bl 0x820d8070
	ctx.lr = 0x820CE188;
	sub_820D8070(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CE18C:
	// bl 0x820d82a8
	ctx.lr = 0x820CE190;
	sub_820D82A8(ctx, base);
	// b 0x820cdf70
	goto loc_820CDF70;
loc_820CE194:
	// lwz r11,1368(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1368);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820ce1ac
	if (!ctx.cr0.eq) goto loc_820CE1AC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12104
	ctx.r4.s64 = ctx.r11.s64 + -12104;
	// b 0x820ce1c8
	goto loc_820CE1C8;
loc_820CE1AC:
	// lbz r10,1558(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1558);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x820ce1d0
	if (!ctx.cr6.eq) goto loc_820CE1D0;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce1d0
	if (!ctx.cr0.eq) goto loc_820CE1D0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-12132
	ctx.r4.s64 = ctx.r11.s64 + -12132;
loc_820CE1C8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820cab60
	ctx.lr = 0x820CE1D0;
	sub_820CAB60(ctx, base);
loc_820CE1D0:
	// lwz r11,1368(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1368);
	// stw r29,1532(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1532, ctx.r29.u32);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r11,1368(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1368, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CE1E8"))) PPC_WEAK_FUNC(sub_820CE1E8);
PPC_FUNC_IMPL(__imp__sub_820CE1E8) {
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
	// lwz r11,1372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1372);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce214
	if (!ctx.cr0.eq) goto loc_820CE214;
	// bl 0x820d74e8
	ctx.lr = 0x820CE214;
	sub_820D74E8(ctx, base);
loc_820CE214:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ceda0
	ctx.lr = 0x820CE220;
	sub_820CEDA0(ctx, base);
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

__attribute__((alias("__imp__sub_820CE238"))) PPC_WEAK_FUNC(sub_820CE238);
PPC_FUNC_IMPL(__imp__sub_820CE238) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820CE240;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1372);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce260
	if (!ctx.cr0.eq) goto loc_820CE260;
	// bl 0x820d74e8
	ctx.lr = 0x820CE260;
	sub_820D74E8(ctx, base);
loc_820CE260:
	// lbz r11,1555(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1555);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820ce2b4
	if (ctx.cr0.eq) goto loc_820CE2B4;
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce2b4
	if (ctx.cr0.eq) goto loc_820CE2B4;
	// lbz r11,1556(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820ce4e0
	if (ctx.cr6.lt) goto loc_820CE4E0;
	// beq cr6,0x820ce4b8
	if (ctx.cr6.eq) goto loc_820CE4B8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820ce494
	if (ctx.cr6.lt) goto loc_820CE494;
	// beq cr6,0x820ce46c
	if (ctx.cr6.eq) goto loc_820CE46C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x820ce44c
	if (ctx.cr6.lt) goto loc_820CE44C;
	// beq cr6,0x820ce424
	if (ctx.cr6.eq) goto loc_820CE424;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x820ce2b4
	if (!ctx.cr6.lt) goto loc_820CE2B4;
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce504
	if (ctx.cr0.eq) goto loc_820CE504;
loc_820CE2B4:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce2d0
	if (!ctx.cr0.eq) goto loc_820CE2D0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-11952
	ctx.r4.s64 = ctx.r11.s64 + -11952;
	// bl 0x820cab60
	ctx.lr = 0x820CE2D0;
	sub_820CAB60(ctx, base);
loc_820CE2D0:
	// lwz r11,1484(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1484);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r10,1500(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r28,r9,-11976
	ctx.r28.s64 = ctx.r9.s64 + -11976;
	// stw r11,1396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1396, ctx.r11.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r10,1392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1392, ctx.r10.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r27,r11,-12312
	ctx.r27.s64 = ctx.r11.s64 + -12312;
	// addi r29,r10,-11996
	ctx.r29.s64 = ctx.r10.s64 + -11996;
loc_820CE2F8:
	// lwz r11,1384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ce3e0
	if (!ctx.cr6.eq) goto loc_820CE3E0;
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ce3a4
	if (!ctx.cr6.eq) goto loc_820CE3A4;
	// addi r30,r31,1548
	ctx.r30.s64 = ctx.r31.s64 + 1548;
loc_820CE314:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820CE320;
	sub_820D7768(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0998
	ctx.lr = 0x820CE330;
	sub_820D0998(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d76f8
	ctx.lr = 0x820CE33C;
	sub_820D76F8(ctx, base);
	// stw r3,1532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1532, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad38
	ctx.lr = 0x820CE348;
	sub_820CAD38(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d6b70
	ctx.lr = 0x820CE358;
	sub_820D6B70(ctx, base);
	// addi r10,r27,64
	ctx.r10.s64 = ctx.r27.s64 + 64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
loc_820CE364:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820ce384
	if (!ctx.cr0.eq) goto loc_820CE384;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x820ce364
	if (!ctx.cr6.eq) goto loc_820CE364;
loc_820CE384:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820ce398
	if (ctx.cr0.eq) goto loc_820CE398;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820CE398;
	sub_820CAB60(ctx, base);
loc_820CE398:
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ce314
	if (ctx.cr6.eq) goto loc_820CE314;
loc_820CE3A4:
	// lwz r10,1440(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1440);
	// lwz r4,1436(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r10,1384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1384, ctx.r10.u32);
	// stw r4,1380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1380, ctx.r4.u32);
	// ble cr6,0x820ce3c4
	if (!ctx.cr6.gt) goto loc_820CE3C4;
	// stw r11,1384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1384, ctx.r11.u32);
loc_820CE3C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,1384(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// bl 0x820d6b70
	ctx.lr = 0x820CE3D0;
	sub_820D6B70(ctx, base);
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// lwz r10,1384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,1532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1532, ctx.r11.u32);
loc_820CE3E0:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1380
	ctx.r3.s64 = ctx.r31.s64 + 1380;
	// bl 0x820d6618
	ctx.lr = 0x820CE3EC;
	sub_820D6618(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820ce510
	if (ctx.cr6.eq) goto loc_820CE510;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ce414
	if (ctx.cr6.eq) goto loc_820CE414;
	// lwz r4,1404(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1404);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820ce40c
	if (!ctx.cr6.eq) goto loc_820CE40C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820CE40C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820CE414;
	sub_820CAB60(ctx, base);
loc_820CE414:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ce2f8
	if (!ctx.cr6.eq) goto loc_820CE2F8;
	// b 0x820ce55c
	goto loc_820CE55C;
loc_820CE424:
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce43c
	if (!ctx.cr0.eq) goto loc_820CE43C;
	// lwz r11,1464(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1464);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x820ce2b4
	if (!ctx.cr6.lt) goto loc_820CE2B4;
loc_820CE43C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce504
	if (ctx.cr6.eq) goto loc_820CE504;
	// li r5,85
	ctx.r5.s64 = 85;
	// b 0x820ce4f8
	goto loc_820CE4F8;
loc_820CE44C:
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi r10,r11,30
	ctx.r10.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820ce2b4
	if (ctx.cr6.eq) goto loc_820CE2B4;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce504
	if (ctx.cr6.eq) goto loc_820CE504;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x820ce4b0
	goto loc_820CE4B0;
loc_820CE46C:
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi. r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce484
	if (!ctx.cr0.eq) goto loc_820CE484;
	// lwz r11,1464(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1464);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x820ce2b4
	if (!ctx.cr6.lt) goto loc_820CE2B4;
loc_820CE484:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce504
	if (ctx.cr6.eq) goto loc_820CE504;
	// li r5,51
	ctx.r5.s64 = 51;
	// b 0x820ce4f8
	goto loc_820CE4F8;
loc_820CE494:
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// beq cr6,0x820ce2b4
	if (ctx.cr6.eq) goto loc_820CE2B4;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce504
	if (ctx.cr6.eq) goto loc_820CE504;
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_820CE4B0:
	// beq 0x820ce504
	if (ctx.cr0.eq) goto loc_820CE504;
	// b 0x820ce4f4
	goto loc_820CE4F4;
loc_820CE4B8:
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi. r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ce4d0
	if (!ctx.cr0.eq) goto loc_820CE4D0;
	// lwz r11,1464(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1464);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x820ce2b4
	if (!ctx.cr6.lt) goto loc_820CE2B4;
loc_820CE4D0:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce504
	if (ctx.cr6.eq) goto loc_820CE504;
	// li r5,15
	ctx.r5.s64 = 15;
	// b 0x820ce4f8
	goto loc_820CE4F8;
loc_820CE4E0:
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// clrlwi. r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce2b4
	if (ctx.cr0.eq) goto loc_820CE2B4;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce504
	if (ctx.cr6.eq) goto loc_820CE504;
loc_820CE4F4:
	// li r5,255
	ctx.r5.s64 = 255;
loc_820CE4F8:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d6d10
	ctx.lr = 0x820CE504;
	sub_820D6D10(ctx, base);
loc_820CE504:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d8318
	ctx.lr = 0x820CE50C;
	sub_820D8318(ctx, base);
	// b 0x820ce6b4
	goto loc_820CE6B4;
loc_820CE510:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ce534
	if (!ctx.cr6.eq) goto loc_820CE534;
	// lwz r11,1384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ce534
	if (!ctx.cr6.eq) goto loc_820CE534;
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ce544
	if (ctx.cr6.eq) goto loc_820CE544;
loc_820CE534:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-12020
	ctx.r4.s64 = ctx.r11.s64 + -12020;
	// bl 0x820cab60
	ctx.lr = 0x820CE544;
	sub_820CAB60(ctx, base);
loc_820CE544:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lwz r10,1372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// stw r11,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r11.u32);
	// stw r10,1372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1372, ctx.r10.u32);
loc_820CE55C:
	// lbz r11,1561(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1561);
	// addi r30,r31,1520
	ctx.r30.s64 = ctx.r31.s64 + 1520;
	// lwz r9,1488(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1488);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lbz r7,1562(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1562);
	// lbz r6,1559(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1559);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lbz r8,1558(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// stb r11,1531(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1531, ctx.r11.u8);
	// stw r9,1520(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1520, ctx.r9.u32);
	// stb r7,1530(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1530, ctx.r7.u8);
	// stb r6,1529(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1529, ctx.r6.u8);
	// stb r8,1528(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1528, ctx.r8.u8);
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// lwz r9,1496(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1496);
	// addi r10,r10,7
	ctx.r10.s64 = ctx.r10.s64 + 7;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r10,1524(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1524, ctx.r10.u32);
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// bl 0x820d72b0
	ctx.lr = 0x820CE5BC;
	sub_820D72B0(ctx, base);
	// lwz r11,1480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1480);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,1500(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// lwz r4,1496(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1496);
	// bl 0x820d2e40
	ctx.lr = 0x820CE5D4;
	sub_820D2E40(ctx, base);
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ce5e8
	if (ctx.cr6.eq) goto loc_820CE5E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d07d8
	ctx.lr = 0x820CE5E8;
	sub_820D07D8(ctx, base);
loc_820CE5E8:
	// lbz r11,1555(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1555);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820ce65c
	if (ctx.cr0.eq) goto loc_820CE65C;
	// lwz r6,1376(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r6,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce65c
	if (ctx.cr0.eq) goto loc_820CE65C;
	// lbz r5,1556(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// cmplwi cr6,r5,6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 6, ctx.xer);
	// bge cr6,0x820ce61c
	if (!ctx.cr6.lt) goto loc_820CE61C;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820d6f70
	ctx.lr = 0x820CE61C;
	sub_820D6F70(ctx, base);
loc_820CE61C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce640
	if (ctx.cr6.eq) goto loc_820CE640;
	// lbz r11,1556(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// addi r10,r27,28
	ctx.r10.s64 = ctx.r27.s64 + 28;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x820d6d10
	ctx.lr = 0x820CE640;
	sub_820D6D10(ctx, base);
loc_820CE640:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820ce68c
	if (ctx.cr6.eq) goto loc_820CE68C;
	// lbz r11,1556(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r5,r11,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// b 0x820ce684
	goto loc_820CE684;
loc_820CE65C:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820ce674
	if (ctx.cr6.eq) goto loc_820CE674;
	// li r5,255
	ctx.r5.s64 = 255;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d6d10
	ctx.lr = 0x820CE674;
	sub_820D6D10(ctx, base);
loc_820CE674:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce68c
	if (ctx.cr6.eq) goto loc_820CE68C;
	// li r5,255
	ctx.r5.s64 = 255;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_820CE684:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d6d10
	ctx.lr = 0x820CE68C;
	sub_820D6D10(ctx, base);
loc_820CE68C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d8318
	ctx.lr = 0x820CE694;
	sub_820D8318(ctx, base);
	// lwz r11,1644(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1644);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ce6b4
	if (ctx.cr6.eq) goto loc_820CE6B4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r5,1556(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// lwz r4,1492(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820CE6B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820CE6B4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CE6BC"))) PPC_WEAK_FUNC(sub_820CE6BC);
PPC_FUNC_IMPL(__imp__sub_820CE6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CE6C0"))) PPC_WEAK_FUNC(sub_820CE6C0);
PPC_FUNC_IMPL(__imp__sub_820CE6C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820CE6C8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// bl 0x820ceb70
	ctx.lr = 0x820CE6D8;
	sub_820CEB70(ctx, base);
	// lwz r28,1468(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 1468);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r28,1472(r29)
	PPC_STORE_U32(ctx.r29.u32 + 1472, ctx.r28.u32);
	// ble 0x820ce71c
	if (!ctx.cr0.gt) goto loc_820CE71C;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_820CE6EC:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820ce714
	if (ctx.cr6.eq) goto loc_820CE714;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// addi r30,r27,-4
	ctx.r30.s64 = ctx.r27.s64 + -4;
loc_820CE6FC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzu r4,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r4.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820ce238
	ctx.lr = 0x820CE70C;
	sub_820CE238(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820ce6fc
	if (!ctx.cr0.eq) goto loc_820CE6FC;
loc_820CE714:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x820ce6ec
	if (!ctx.cr0.eq) goto loc_820CE6EC;
loc_820CE71C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CE724"))) PPC_WEAK_FUNC(sub_820CE724);
PPC_FUNC_IMPL(__imp__sub_820CE724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CE728"))) PPC_WEAK_FUNC(sub_820CE728);
PPC_FUNC_IMPL(__imp__sub_820CE728) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820CE730;
	__savegprlr_28(ctx, base);
	// stwu r1,-1472(r1)
	ea = -1472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ce748
	if (ctx.cr6.eq) goto loc_820CE748;
	// bl 0x820cadd8
	ctx.lr = 0x820CE748;
	sub_820CADD8(ctx, base);
loc_820CE748:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820ce75c
	if (ctx.cr6.eq) goto loc_820CE75C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cadd8
	ctx.lr = 0x820CE75C;
	sub_820CADD8(ctx, base);
loc_820CE75C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1436(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// bl 0x820d2e18
	ctx.lr = 0x820CE768;
	sub_820D2E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1500(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// bl 0x820d2e18
	ctx.lr = 0x820CE774;
	sub_820D2E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1496(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1496);
	// bl 0x820d2e18
	ctx.lr = 0x820CE780;
	sub_820D2E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1652(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1652);
	// bl 0x820d2e18
	ctx.lr = 0x820CE78C;
	sub_820D2E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1656(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1656);
	// bl 0x820d2e18
	ctx.lr = 0x820CE798;
	sub_820D2E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1592(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// bl 0x820d2e18
	ctx.lr = 0x820CE7A4;
	sub_820D2E18(ctx, base);
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce7bc
	if (ctx.cr0.eq) goto loc_820CE7BC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1540(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// bl 0x820cad30
	ctx.lr = 0x820CE7BC;
	sub_820CAD30(ctx, base);
loc_820CE7BC:
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce7d4
	if (ctx.cr0.eq) goto loc_820CE7D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1628(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1628);
	// bl 0x820d2e18
	ctx.lr = 0x820CE7D4;
	sub_820D2E18(ctx, base);
loc_820CE7D4:
	// lwz r11,1604(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1604);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ce820
	if (ctx.cr6.eq) goto loc_820CE820;
	// lwz r11,1580(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1580);
	// li r10,1
	ctx.r10.s64 = 1;
	// subfic r11,r11,8
	ctx.xer.ca = ctx.r11.u32 <= 8;
	ctx.r11.s64 = 8 - ctx.r11.s64;
	// slw. r30,r10,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble 0x820ce814
	if (!ctx.cr0.gt) goto loc_820CE814;
	// li r29,0
	ctx.r29.s64 = 0;
loc_820CE7F8:
	// lwz r11,1604(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1604);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r4,r29,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// bl 0x820d2e18
	ctx.lr = 0x820CE808;
	sub_820D2E18(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x820ce7f8
	if (!ctx.cr0.eq) goto loc_820CE7F8;
loc_820CE814:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1604(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1604);
	// bl 0x820d2e18
	ctx.lr = 0x820CE820;
	sub_820D2E18(ctx, base);
loc_820CE820:
	// addi r3,r31,1380
	ctx.r3.s64 = ctx.r31.s64 + 1380;
	// bl 0x820d6420
	ctx.lr = 0x820CE828;
	sub_820D6420(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,1344
	ctx.r5.s64 = 1344;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8207dac0
	ctx.lr = 0x820CE838;
	sub_8207DAC0(ctx, base);
	// li r5,1696
	ctx.r5.s64 = 1696;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,1344(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1344);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,1348(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1348);
	// lwz r28,1352(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1352);
	// bl 0x8207da20
	ctx.lr = 0x820CE854;
	sub_8207DA20(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,1344
	ctx.r5.s64 = 1344;
	// stw r30,1344(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1344, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,1348(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1348, ctx.r29.u32);
	// stw r28,1352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1352, ctx.r28.u32);
	// bl 0x8207dac0
	ctx.lr = 0x820CE870;
	sub_8207DAC0(ctx, base);
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CE878"))) PPC_WEAK_FUNC(sub_820CE878);
PPC_FUNC_IMPL(__imp__sub_820CE878) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820CE880;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// beq cr6,0x820ce8ac
	if (ctx.cr6.eq) goto loc_820CE8AC;
	// lwz r29,0(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_820CE8AC:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820ce8b8
	if (ctx.cr6.eq) goto loc_820CE8B8;
	// lwz r31,0(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
loc_820CE8B8:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ce8c4
	if (ctx.cr6.eq) goto loc_820CE8C4;
	// lwz r30,0(r26)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
loc_820CE8C4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820ce8dc
	if (ctx.cr6.eq) goto loc_820CE8DC;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820ce728
	ctx.lr = 0x820CE8DC;
	sub_820CE728(ctx, base);
loc_820CE8DC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820ce8f0
	if (ctx.cr6.eq) goto loc_820CE8F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d2d90
	ctx.lr = 0x820CE8EC;
	sub_820D2D90(ctx, base);
	// stw r25,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r25.u32);
loc_820CE8F0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820ce904
	if (ctx.cr6.eq) goto loc_820CE904;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d2d90
	ctx.lr = 0x820CE900;
	sub_820D2D90(ctx, base);
	// stw r25,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
loc_820CE904:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820ce918
	if (ctx.cr6.eq) goto loc_820CE918;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d2d90
	ctx.lr = 0x820CE914;
	sub_820D2D90(ctx, base);
	// stw r25,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r25.u32);
loc_820CE918:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CE920"))) PPC_WEAK_FUNC(sub_820CE920);
PPC_FUNC_IMPL(__imp__sub_820CE920) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ce93c
	if (ctx.cr6.eq) goto loc_820CE93C;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ce93c
	if (ctx.cr6.eq) goto loc_820CE93C;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// and r3,r11,r5
	ctx.r3.u64 = ctx.r11.u64 & ctx.r5.u64;
	// blr 
	return;
loc_820CE93C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CE944"))) PPC_WEAK_FUNC(sub_820CE944);
PPC_FUNC_IMPL(__imp__sub_820CE944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CE948"))) PPC_WEAK_FUNC(sub_820CE948);
PPC_FUNC_IMPL(__imp__sub_820CE948) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ce960
	if (ctx.cr6.eq) goto loc_820CE960;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ce960
	if (ctx.cr6.eq) goto loc_820CE960;
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// blr 
	return;
loc_820CE960:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CE968"))) PPC_WEAK_FUNC(sub_820CE968);
PPC_FUNC_IMPL(__imp__sub_820CE968) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ce980
	if (ctx.cr6.eq) goto loc_820CE980;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ce980
	if (ctx.cr6.eq) goto loc_820CE980;
	// lbz r3,29(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29);
	// blr 
	return;
loc_820CE980:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CE988"))) PPC_WEAK_FUNC(sub_820CE988);
PPC_FUNC_IMPL(__imp__sub_820CE988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ce9bc
	if (ctx.cr6.eq) goto loc_820CE9BC;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ce9bc
	if (ctx.cr6.eq) goto loc_820CE9BC;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce9bc
	if (ctx.cr0.eq) goto loc_820CE9BC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820ce9bc
	if (ctx.cr6.eq) goto loc_820CE9BC;
	// lfs f0,40(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfd f0,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.f0.u64);
	// blr 
	return;
loc_820CE9BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CE9C4"))) PPC_WEAK_FUNC(sub_820CE9C4);
PPC_FUNC_IMPL(__imp__sub_820CE9C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CE9C8"))) PPC_WEAK_FUNC(sub_820CE9C8);
PPC_FUNC_IMPL(__imp__sub_820CE9C8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ce9fc
	if (ctx.cr6.eq) goto loc_820CE9FC;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ce9fc
	if (ctx.cr6.eq) goto loc_820CE9FC;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ce9fc
	if (ctx.cr0.eq) goto loc_820CE9FC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820ce9fc
	if (ctx.cr6.eq) goto loc_820CE9FC;
	// lbz r11,44(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 44);
	// li r3,2048
	ctx.r3.s64 = 2048;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_820CE9FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEA04"))) PPC_WEAK_FUNC(sub_820CEA04);
PPC_FUNC_IMPL(__imp__sub_820CEA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEA08"))) PPC_WEAK_FUNC(sub_820CEA08);
PPC_FUNC_IMPL(__imp__sub_820CEA08) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ceb00
	if (ctx.cr6.eq) goto loc_820CEB00;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820ceb00
	if (ctx.cr6.eq) goto loc_820CEB00;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820ceb00
	if (ctx.cr6.eq) goto loc_820CEB00;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820ceb00
	if (ctx.cr6.eq) goto loc_820CEB00;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820ceb00
	if (ctx.cr6.eq) goto loc_820CEB00;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820ceb00
	if (ctx.cr6.eq) goto loc_820CEB00;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// lbz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// lbz r11,25(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// beq cr6,0x820cea74
	if (ctx.cr6.eq) goto loc_820CEA74;
	// lbz r11,26(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_820CEA74:
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cea88
	if (ctx.cr6.eq) goto loc_820CEA88;
	// lbz r10,27(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 27);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_820CEA88:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cea98
	if (ctx.cr6.eq) goto loc_820CEA98;
	// lbz r11,28(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 28);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
loc_820CEA98:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x820ceaac
	if (!ctx.cr6.eq) goto loc_820CEAAC;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820ceab4
	goto loc_820CEAB4;
loc_820CEAAC:
	// rlwinm r11,r10,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
loc_820CEAB4:
	// rlwinm. r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820ceac0
	if (ctx.cr0.eq) goto loc_820CEAC0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820CEAC0:
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// ori r10,r9,65535
	ctx.r10.u64 = ctx.r9.u64 | 65535;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// twllei r11,0
	// divwu r11,r10,r11
	ctx.r11.u32 = ppc_divwu(ctx.r10.u32, ctx.r11.u32);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820ceaf8
	if (!ctx.cr6.gt) goto loc_820CEAF8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-11916
	ctx.r4.s64 = ctx.r11.s64 + -11916;
	// bl 0x820cab98
	ctx.lr = 0x820CEAF8;
	sub_820CAB98(ctx, base);
loc_820CEAF8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820ceb04
	goto loc_820CEB04;
loc_820CEB00:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820CEB04:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEB14"))) PPC_WEAK_FUNC(sub_820CEB14);
PPC_FUNC_IMPL(__imp__sub_820CEB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEB18"))) PPC_WEAK_FUNC(sub_820CEB18);
PPC_FUNC_IMPL(__imp__sub_820CEB18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r11,1376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1376, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEB28"))) PPC_WEAK_FUNC(sub_820CEB28);
PPC_FUNC_IMPL(__imp__sub_820CEB28) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1559(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1559);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stw r11,1376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1376, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEB44"))) PPC_WEAK_FUNC(sub_820CEB44);
PPC_FUNC_IMPL(__imp__sub_820CEB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEB48"))) PPC_WEAK_FUNC(sub_820CEB48);
PPC_FUNC_IMPL(__imp__sub_820CEB48) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1559(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1559);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// li r10,8
	ctx.r10.s64 = 8;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stb r10,1560(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1560, ctx.r10.u8);
	// stw r11,1376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1376, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEB6C"))) PPC_WEAK_FUNC(sub_820CEB6C);
PPC_FUNC_IMPL(__imp__sub_820CEB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEB70"))) PPC_WEAK_FUNC(sub_820CEB70);
PPC_FUNC_IMPL(__imp__sub_820CEB70) {
	PPC_FUNC_PROLOGUE();
	// lbz r10,1555(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1555);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x820ceb94
	if (ctx.cr0.eq) goto loc_820CEB94;
	// lwz r10,1376(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// li r3,7
	ctx.r3.s64 = 7;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stw r10,1376(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1376, ctx.r10.u32);
	// blr 
	return;
loc_820CEB94:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEB9C"))) PPC_WEAK_FUNC(sub_820CEB9C);
PPC_FUNC_IMPL(__imp__sub_820CEB9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEBA0"))) PPC_WEAK_FUNC(sub_820CEBA0);
PPC_FUNC_IMPL(__imp__sub_820CEBA0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// sth r10,1566(r3)
	PPC_STORE_U16(ctx.r3.u32 + 1566, ctx.r10.u16);
	// stw r11,1376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1376, ctx.r11.u32);
	// lwz r11,1372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1372);
	// bne cr6,0x820cebc8
	if (!ctx.cr6.eq) goto loc_820CEBC8;
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
	// b 0x820cebcc
	goto loc_820CEBCC;
loc_820CEBC8:
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
loc_820CEBCC:
	// stw r11,1372(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1372, ctx.r11.u32);
	// lbz r11,1558(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1558);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820cebe4
	if (!ctx.cr6.eq) goto loc_820CEBE4;
	// li r10,4
	ctx.r10.s64 = 4;
	// stb r10,1563(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1563, ctx.r10.u8);
loc_820CEBE4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r11,1559(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1559);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r11,1563(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1563, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEC04"))) PPC_WEAK_FUNC(sub_820CEC04);
PPC_FUNC_IMPL(__imp__sub_820CEC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEC08"))) PPC_WEAK_FUNC(sub_820CEC08);
PPC_FUNC_IMPL(__imp__sub_820CEC08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r11,10(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mullw. r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
loc_820CEC2C:
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cec2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CEC2C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEC44"))) PPC_WEAK_FUNC(sub_820CEC44);
PPC_FUNC_IMPL(__imp__sub_820CEC44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CEC48"))) PPC_WEAK_FUNC(sub_820CEC48);
PPC_FUNC_IMPL(__imp__sub_820CEC48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rlwinm. r11,r9,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lbz r10,9(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x820cecc4
	if (!ctx.cr6.eq) goto loc_820CECC4;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820cec94
	if (!ctx.cr6.eq) goto loc_820CEC94;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
loc_820CEC7C:
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,3(r11)
	ea = 3 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cec7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CEC7C;
	// blr 
	return;
loc_820CEC94:
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r4,-2
	ctx.r11.s64 = ctx.r4.s64 + -2;
loc_820CECAC:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// stb r10,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r10.u8);
	// stbu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cecac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CECAC;
	// blr 
	return;
loc_820CECC4:
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820ced0c
	if (!ctx.cr6.eq) goto loc_820CED0C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CECE4:
	// lbz r11,1(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r9,5(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 5);
	// lbz r8,6(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// lbz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// stb r11,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, ctx.r11.u8);
	// stb r9,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8);
	// stb r8,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r8.u8);
	// stbu r7,6(r10)
	ea = 6 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x820cece4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CECE4;
	// blr 
	return;
loc_820CED0C:
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r4,-3
	ctx.r10.s64 = ctx.r4.s64 + -3;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CED24:
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// lbz r9,7(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// lbz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// lbz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// stb r11,7(r10)
	PPC_STORE_U8(ctx.r10.u32 + 7, ctx.r11.u8);
	// stb r9,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r9.u8);
	// stb r8,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r8.u8);
	// stbu r7,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x820ced24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CED24;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CED4C"))) PPC_WEAK_FUNC(sub_820CED4C);
PPC_FUNC_IMPL(__imp__sub_820CED4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CED50"))) PPC_WEAK_FUNC(sub_820CED50);
PPC_FUNC_IMPL(__imp__sub_820CED50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfd f0,2064(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
	// fmsub f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 * ctx.f2.f64 - ctx.f0.f64;
	// lfd f0,-11864(r10)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + -11864);
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x820ced7c
	if (!ctx.cr6.gt) goto loc_820CED7C;
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// stw r11,1376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1376, ctx.r11.u32);
loc_820CED7C:
	// frsp f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f2.f64));
	// stfs f0,1584(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1584, temp.u32);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,1588(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1588, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CED90"))) PPC_WEAK_FUNC(sub_820CED90);
PPC_FUNC_IMPL(__imp__sub_820CED90) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// stw r11,1376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1376, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEDA0"))) PPC_WEAK_FUNC(sub_820CEDA0);
PPC_FUNC_IMPL(__imp__sub_820CEDA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// li r10,8
	ctx.r10.s64 = 8;
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cee10
	if (ctx.cr0.eq) goto loc_820CEE10;
	// lbz r11,25(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820cede4
	if (!ctx.cr6.eq) goto loc_820CEDE4;
	// lhz r11,1546(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 1546);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r10,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, ctx.r10.u8);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// sth r9,22(r4)
	PPC_STORE_U16(ctx.r4.u32 + 22, ctx.r9.u16);
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stb r11,25(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25, ctx.r11.u8);
	// b 0x820cee10
	goto loc_820CEE10;
loc_820CEDE4:
	// lhz r9,1546(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 1546);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x820cedf8
	if (ctx.cr0.eq) goto loc_820CEDF8;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stb r11,25(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25, ctx.r11.u8);
loc_820CEDF8:
	// lbz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x820cee08
	if (!ctx.cr6.lt) goto loc_820CEE08;
	// stb r10,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, ctx.r10.u8);
loc_820CEE08:
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,22(r4)
	PPC_STORE_U16(ctx.r4.u32 + 22, ctx.r11.u16);
loc_820CEE10:
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cee24
	if (ctx.cr0.eq) goto loc_820CEE24;
	// lfs f0,1584(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1584);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r4)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
loc_820CEE24:
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cee40
	if (ctx.cr0.eq) goto loc_820CEE40;
	// lbz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820cee40
	if (!ctx.cr6.eq) goto loc_820CEE40;
	// stb r10,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, ctx.r10.u8);
loc_820CEE40:
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// li r9,3
	ctx.r9.s64 = 3;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cee80
	if (ctx.cr0.eq) goto loc_820CEE80;
	// lbz r11,25(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820cee64
	if (ctx.cr6.eq) goto loc_820CEE64;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x820cee80
	if (!ctx.cr6.eq) goto loc_820CEE80;
loc_820CEE64:
	// lwz r11,1652(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1652);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cee80
	if (ctx.cr6.eq) goto loc_820CEE80;
	// lbz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820cee80
	if (!ctx.cr6.eq) goto loc_820CEE80;
	// stb r9,25(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25, ctx.r9.u8);
loc_820CEE80:
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cee9c
	if (ctx.cr0.eq) goto loc_820CEE9C;
	// lbz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x820cee9c
	if (!ctx.cr6.lt) goto loc_820CEE9C;
	// stb r10,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, ctx.r10.u8);
loc_820CEE9C:
	// lbz r10,25(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x820ceeb8
	if (ctx.cr6.eq) goto loc_820CEEB8;
	// rlwinm. r11,r10,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ceeb8
	if (ctx.cr0.eq) goto loc_820CEEB8;
	// stb r9,29(r4)
	PPC_STORE_U8(ctx.r4.u32 + 29, ctx.r9.u8);
	// b 0x820ceec0
	goto loc_820CEEC0;
loc_820CEEB8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,29(r4)
	PPC_STORE_U8(ctx.r4.u32 + 29, ctx.r11.u8);
loc_820CEEC0:
	// rlwinm. r11,r10,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ceed4
	if (ctx.cr0.eq) goto loc_820CEED4;
	// lbz r11,29(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,29(r4)
	PPC_STORE_U8(ctx.r4.u32 + 29, ctx.r11.u8);
loc_820CEED4:
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// rlwinm. r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ceefc
	if (ctx.cr0.eq) goto loc_820CEEFC;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820ceef0
	if (ctx.cr6.eq) goto loc_820CEEF0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820ceefc
	if (!ctx.cr6.eq) goto loc_820CEEFC;
loc_820CEEF0:
	// lbz r11,29(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,29(r4)
	PPC_STORE_U8(ctx.r4.u32 + 29, ctx.r11.u8);
loc_820CEEFC:
	// lbz r10,29(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29);
	// lbz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// mullw r11,r10,r9
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stb r10,30(r4)
	PPC_STORE_U8(ctx.r4.u32 + 30, ctx.r10.u8);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CEF28"))) PPC_WEAK_FUNC(sub_820CEF28);
PPC_FUNC_IMPL(__imp__sub_820CEF28) {
	PPC_FUNC_PROLOGUE();
	// lbz r10,9(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x820cf018
	if (ctx.cr6.eq) goto loc_820CF018;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820cefb4
	if (ctx.cr6.eq) goto loc_820CEFB4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bne cr6,0x820cf074
	if (!ctx.cr6.eq) goto loc_820CF074;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r7,r8,1
	ctx.xer.ca = ctx.r8.u32 <= 1;
	ctx.r7.s64 = 1 - ctx.r8.s64;
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf074
	if (ctx.cr6.eq) goto loc_820CF074;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CEF7C:
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// srw r10,r7,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// bne cr6,0x820cefa4
	if (!ctx.cr6.eq) goto loc_820CEFA4;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// b 0x820cefa8
	goto loc_820CEFA8;
loc_820CEFA4:
	// li r10,4
	ctx.r10.s64 = 4;
loc_820CEFA8:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// bdnz 0x820cef7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CEF7C;
	// b 0x820cf074
	goto loc_820CF074;
loc_820CEFB4:
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// clrlwi r8,r10,30
	ctx.r8.u64 = ctx.r10.u32 & 0x3;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// subfic r7,r8,3
	ctx.xer.ca = ctx.r8.u32 <= 3;
	ctx.r7.s64 = 3 - ctx.r8.s64;
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf074
	if (ctx.cr6.eq) goto loc_820CF074;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CEFE0:
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// srw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// clrlwi r7,r7,30
	ctx.r7.u64 = ctx.r7.u32 & 0x3;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// bne cr6,0x820cf008
	if (!ctx.cr6.eq) goto loc_820CF008;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// b 0x820cf00c
	goto loc_820CF00C;
loc_820CF008:
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
loc_820CF00C:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// bdnz 0x820cefe0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CEFE0;
	// b 0x820cf074
	goto loc_820CF074;
loc_820CF018:
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r8,r10,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// subfic r10,r10,7
	ctx.xer.ca = ctx.r10.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r10.s64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf074
	if (ctx.cr6.eq) goto loc_820CF074;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CF040:
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// srw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// bne cr6,0x820cf068
	if (!ctx.cr6.eq) goto loc_820CF068;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// b 0x820cf06c
	goto loc_820CF06C;
loc_820CF068:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820CF06C:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// bdnz 0x820cf040
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF040;
loc_820CF074:
	// lbz r10,10(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// li r9,8
	ctx.r9.s64 = 8;
	// rlwinm r8,r10,3,24,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xF8;
	// stb r9,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r9.u8);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CF094"))) PPC_WEAK_FUNC(sub_820CF094);
PPC_FUNC_IMPL(__imp__sub_820CF094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CF098"))) PPC_WEAK_FUNC(sub_820CF098);
PPC_FUNC_IMPL(__imp__sub_820CF098) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lbz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// beq cr6,0x820cf2c4
	if (ctx.cr6.eq) goto loc_820CF2C4;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm. r10,r8,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// beq 0x820cf0ec
	if (ctx.cr0.eq) goto loc_820CF0EC;
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// li r10,3
	ctx.r10.s64 = 3;
	// lbz r4,1(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// lbz r31,2(r5)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r5.u32 + 2);
	// lbz r30,0(r5)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// subf r4,r4,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r4.s64;
	// subf r31,r31,r9
	ctx.r31.s64 = ctx.r9.s64 - ctx.r31.s64;
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r30.s64;
	// stw r4,-28(r1)
	PPC_STORE_U32(ctx.r1.u32 + -28, ctx.r4.u32);
	// stw r31,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r31.u32);
	// b 0x820cf0fc
	goto loc_820CF0FC;
loc_820CF0EC:
	// lbz r9,3(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 3);
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r4,9(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// subf r9,r9,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r9.s64;
loc_820CF0FC:
	// stw r9,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, ctx.r9.u32);
	// rlwinm. r8,r8,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820cf128
	if (ctx.cr0.eq) goto loc_820CF128;
	// lbz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r5,9(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// addi r4,r1,-32
	ctx.r4.s64 = ctx.r1.s64 + -32;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r9,r9,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r9.s64;
	// stwx r9,r8,r4
	PPC_STORE_U32(ctx.r8.u32 + ctx.r4.u32, ctx.r9.u32);
	// lwz r9,-32(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
loc_820CF128:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x820cf160
	if (!ctx.cr6.gt) goto loc_820CF160;
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820CF138:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x820cf150
	if (ctx.cr6.gt) goto loc_820CF150;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// b 0x820cf154
	goto loc_820CF154;
loc_820CF150:
	// li r6,1
	ctx.r6.s64 = 1;
loc_820CF154:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x820cf138
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF138;
	// lwz r9,-32(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
loc_820CF160:
	// clrlwi. r8,r6,16
	ctx.r8.u64 = ctx.r6.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820cf2c4
	if (ctx.cr0.eq) goto loc_820CF2C4;
	// lbz r8,9(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// beq cr6,0x820cf298
	if (ctx.cr6.eq) goto loc_820CF298;
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// beq cr6,0x820cf240
	if (ctx.cr6.eq) goto loc_820CF240;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// beq cr6,0x820cf1f4
	if (ctx.cr6.eq) goto loc_820CF1F4;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// bne cr6,0x820cf2c4
	if (!ctx.cr6.eq) goto loc_820CF2C4;
	// mullw. r8,r7,r10
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x820cf2c4
	if (ctx.cr0.eq) goto loc_820CF2C4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820CF19C:
	// divwu r8,r9,r10
	ctx.r8.u32 = ppc_divwu(ctx.r9.u32, ctx.r10.u32);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// subf r8,r8,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r8.s64;
	// rotlwi r6,r6,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// twllei r10,0
	// lwzx r6,r4,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi r6,r6,16
	ctx.r6.u64 = ctx.r6.u32 & 0xFFFF;
	// srw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwinm r6,r7,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF;
	// stb r6,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
	// stb r7,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r7.u8);
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// bdnz 0x820cf19c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF19C;
	// b 0x820cf2c4
	goto loc_820CF2C4;
loc_820CF1F4:
	// mullw. r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// beq 0x820cf2c4
	if (ctx.cr0.eq) goto loc_820CF2C4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820CF208:
	// divwu r9,r8,r10
	ctx.r9.u32 = ppc_divwu(ctx.r8.u32, ctx.r10.u32);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r1,-32
	ctx.r6.s64 = ctx.r1.s64 + -32;
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// twllei r10,0
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// srw r9,r7,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r9.u8 & 0x3F));
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf208
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF208;
	// b 0x820cf2c4
	goto loc_820CF2C4;
loc_820CF240:
	// li r8,240
	ctx.r8.s64 = 240;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r7,15
	ctx.r7.s64 = 15;
	// sraw r8,r8,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r8.s64 = ctx.r8.s32 >> temp.u32;
	// rlwinm r8,r8,0,24,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xF0;
	// sraw r7,r7,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r7.s32 < 0) & (((ctx.r7.s32 >> temp.u32) << temp.u32) != ctx.r7.s32);
	ctx.r7.s64 = ctx.r7.s32 >> temp.u32;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// beq cr6,0x820cf2c4
	if (ctx.cr6.eq) goto loc_820CF2C4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820CF278:
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// srw r8,r8,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// and r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 & ctx.r6.u64;
	// stbu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf278
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF278;
	// b 0x820cf2c4
	goto loc_820CF2C4;
loc_820CF298:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820cf2c4
	if (ctx.cr6.eq) goto loc_820CF2C4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820CF2AC:
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// li r12,-43
	ctx.r12.s64 = -43;
	// rlwinm r10,r10,31,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7F;
	// and r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 & ctx.r12.u64;
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf2ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF2AC;
loc_820CF2C4:
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CF2D0"))) PPC_WEAK_FUNC(sub_820CF2D0);
PPC_FUNC_IMPL(__imp__sub_820CF2D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r10,10(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// mullw. r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cf304
	if (ctx.cr0.eq) goto loc_820CF304;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addi r11,r4,-2
	ctx.r11.s64 = ctx.r4.s64 + -2;
loc_820CF2F8:
	// lbzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x820cf2f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF2F8;
loc_820CF304:
	// lbz r11,10(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r11,3,24,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xF8;
	// stb r10,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r10.u8);
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CF328"))) PPC_WEAK_FUNC(sub_820CF328);
PPC_FUNC_IMPL(__imp__sub_820CF328) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r5,r5,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x820cf468
	if (!ctx.cr0.eq) goto loc_820CF468;
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820cf3c8
	if (!ctx.cr6.eq) goto loc_820CF3C8;
	// add r10,r9,r4
	ctx.r10.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm. r11,r6,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq 0x820cf39c
	if (ctx.cr0.eq) goto loc_820CF39C;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x820cf380
	if (!ctx.cr6.gt) goto loc_820CF380;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820CF370:
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf370
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF370;
loc_820CF380:
	// stb r7,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r7.u8);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,16
	ctx.r11.s64 = 16;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
loc_820CF390:
	// stb r10,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r10.u8);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r11.u8);
	// b 0x820cf5e4
	goto loc_820CF5E4;
loc_820CF39C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cf3b8
	if (ctx.cr6.eq) goto loc_820CF3B8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CF3A8:
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf3a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF3A8;
loc_820CF3B8:
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,16
	ctx.r10.s64 = 16;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x820cf5dc
	goto loc_820CF5DC;
loc_820CF3C8:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// rlwinm. r11,r6,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq 0x820cf430
	if (ctx.cr0.eq) goto loc_820CF430;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x820cf410
	if (!ctx.cr6.gt) goto loc_820CF410;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820CF3F4:
	// stbu r5,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf3f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF3F4;
loc_820CF410:
	// li r10,2
	ctx.r10.s64 = 2;
	// li r8,32
	ctx.r8.s64 = 32;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_820CF41C:
	// stbu r5,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// stb r7,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r7.u8);
	// stb r10,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r10.u8);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
	// b 0x820cf5e4
	goto loc_820CF5E4;
loc_820CF430:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cf458
	if (ctx.cr6.eq) goto loc_820CF458;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CF43C:
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// stbu r5,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf43c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF43C;
loc_820CF458:
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,32
	ctx.r10.s64 = 32;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x820cf5dc
	goto loc_820CF5DC;
loc_820CF468:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820cf50c
	if (!ctx.cr6.eq) goto loc_820CF50C;
	// rlwinm. r11,r6,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mulli r11,r9,3
	ctx.r11.s64 = ctx.r9.s64 * 3;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq 0x820cf4d4
	if (ctx.cr0.eq) goto loc_820CF4D4;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x820cf4c0
	if (!ctx.cr6.gt) goto loc_820CF4C0;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820CF4A0:
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf4a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF4A0;
loc_820CF4C0:
	// stb r7,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r7.u8);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,32
	ctx.r11.s64 = 32;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x820cf390
	goto loc_820CF390;
loc_820CF4D4:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cf500
	if (ctx.cr6.eq) goto loc_820CF500;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CF4E0:
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf4e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF4E0;
loc_820CF500:
	// li r10,32
	ctx.r10.s64 = 32;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x820cf5d8
	goto loc_820CF5D8;
loc_820CF50C:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// rlwinm. r11,r6,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mulli r11,r9,6
	ctx.r11.s64 = ctx.r9.s64 * 6;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq 0x820cf588
	if (ctx.cr0.eq) goto loc_820CF588;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x820cf578
	if (!ctx.cr6.gt) goto loc_820CF578;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820CF53C:
	// stbu r5,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf53c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF53C;
loc_820CF578:
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,64
	ctx.r8.s64 = 64;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// b 0x820cf41c
	goto loc_820CF41C;
loc_820CF588:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cf5d0
	if (ctx.cr6.eq) goto loc_820CF5D0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CF594:
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// stbu r5,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// stbu r7,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf594
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF594;
loc_820CF5D0:
	// li r10,64
	ctx.r10.s64 = 64;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
loc_820CF5D8:
	// li r11,4
	ctx.r11.s64 = 4;
loc_820CF5DC:
	// stb r10,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r10.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r11.u8);
loc_820CF5E4:
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820CF5EC"))) PPC_WEAK_FUNC(sub_820CF5EC);
PPC_FUNC_IMPL(__imp__sub_820CF5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CF5F0"))) PPC_WEAK_FUNC(sub_820CF5F0);
PPC_FUNC_IMPL(__imp__sub_820CF5F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820CF5F8;
	__savegprlr_24(ctx, base);
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bgt cr6,0x820cf614
	if (ctx.cr6.gt) goto loc_820CF614;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x820cf624
	if (!ctx.cr6.eq) goto loc_820CF624;
loc_820CF614:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bne cr6,0x820cfa4c
	if (!ctx.cr6.eq) goto loc_820CFA4C;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
loc_820CF624:
	// lbz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x820cf8ac
	if (ctx.cr0.eq) goto loc_820CF8AC;
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// beq cr6,0x820cf7b4
	if (ctx.cr6.eq) goto loc_820CF7B4;
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// beq cr6,0x820cf740
	if (ctx.cr6.eq) goto loc_820CF740;
	// cmplwi cr6,r8,6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 6, ctx.xer);
	// bne cr6,0x820cfa4c
	if (!ctx.cr6.eq) goto loc_820CFA4C;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bne cr6,0x820cf68c
	if (!ctx.cr6.eq) goto loc_820CF68C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CF65C:
	// lbz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x820cf65c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF65C;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF68C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CF69C:
	// lbz r8,1(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// srw r8,r8,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r5,r5,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// clrlwi r4,r9,24
	ctx.r4.u64 = ctx.r9.u32 & 0xFF;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// clrlwi r3,r9,24
	ctx.r3.u64 = ctx.r9.u32 & 0xFF;
	// lwzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lhzx r7,r7,r5
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r5.u32);
	// rlwinm r5,r7,24,8,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// stb r5,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// srw r7,r7,r4
	ctx.r7.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r4.u8 & 0x3F));
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r5,r5,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// lwzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lhzx r7,r7,r5
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r5.u32);
	// rlwinm r5,r7,24,8,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// stb r5,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// srw r7,r7,r3
	ctx.r7.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r3.u8 & 0x3F));
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r5,r5,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// lwzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lhzx r7,r7,r5
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r5.u32);
	// rlwinm r5,r7,24,8,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// stb r5,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// stb r7,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r7.u8);
	// bdnz 0x820cf69c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF69C;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF740:
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bne cr6,0x820cf76c
	if (!ctx.cr6.eq) goto loc_820CF76C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-2
	ctx.r11.s64 = ctx.r10.s64 + -2;
loc_820CF758:
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbzx r10,r10,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// stbu r10,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf758
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF758;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF76C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// addi r11,r10,-3
	ctx.r11.s64 = ctx.r10.s64 + -3;
loc_820CF780:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lwzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lhzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r7.u32);
	// rlwinm r8,r10,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// stb r8,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r8.u8);
	// stbu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf780
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF780;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF7B4:
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bne cr6,0x820cf7f8
	if (!ctx.cr6.eq) goto loc_820CF7F8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CF7C8:
	// lbz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x820cf7c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF7C8;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF7F8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CF808:
	// lbz r8,1(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// srw r8,r8,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r7,r5,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r4,r9,24
	ctx.r4.u64 = ctx.r9.u32 & 0xFF;
	// lwzx r8,r8,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lhzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r7.u32);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rlwinm r8,r8,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// srw r8,r8,r5
	ctx.r8.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r5.u8 & 0x3F));
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lwzx r8,r8,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lhzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r7.u32);
	// rlwinm r7,r8,24,8,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// stb r7,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// srw r7,r7,r4
	ctx.r7.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r4.u8 & 0x3F));
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r5,r5,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// lwzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lhzx r7,r7,r5
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r5.u32);
	// rlwinm r5,r7,24,8,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// stb r5,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// stb r7,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r7.u8);
	// bdnz 0x820cf808
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF808;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF8AC:
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820cf978
	if (!ctx.cr6.eq) goto loc_820CF978;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cf978
	if (ctx.cr6.eq) goto loc_820CF978;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820CF8D0:
	// lbz r8,1(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// clrlwi r4,r8,30
	ctx.r4.u64 = ctx.r8.u32 & 0x3;
	// rlwinm r31,r8,2,28,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xC;
	// rlwinm r30,r8,0,28,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xC;
	// or r31,r31,r4
	ctx.r31.u64 = ctx.r31.u64 | ctx.r4.u64;
	// rlwinm r29,r8,0,26,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x30;
	// rlwinm r28,r8,2,26,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x30;
	// srawi r27,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r27.s64 = ctx.r30.s32 >> 2;
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// or r28,r28,r30
	ctx.r28.u64 = ctx.r28.u64 | ctx.r30.u64;
	// srawi r26,r29,2
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x3) != 0);
	ctx.r26.s64 = ctx.r29.s32 >> 2;
	// or r31,r31,r4
	ctx.r31.u64 = ctx.r31.u64 | ctx.r4.u64;
	// or r26,r26,r29
	ctx.r26.u64 = ctx.r26.u64 | ctx.r29.u64;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r8,0,0,25
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r26,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 2;
	// or r28,r28,r27
	ctx.r28.u64 = ctx.r28.u64 | ctx.r27.u64;
	// srawi r24,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r24.s64 = ctx.r25.s32 >> 2;
	// or r4,r31,r4
	ctx.r4.u64 = ctx.r31.u64 | ctx.r4.u64;
	// rlwinm r8,r8,2,24,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xC0;
	// or r30,r28,r30
	ctx.r30.u64 = ctx.r28.u64 | ctx.r30.u64;
	// or r31,r24,r25
	ctx.r31.u64 = ctx.r24.u64 | ctx.r25.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// srawi r31,r31,2
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x3) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 2;
	// lbzx r4,r4,r5
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// or r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 | ctx.r29.u64;
	// lbzx r30,r30,r5
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r5.u32);
	// or r31,r31,r25
	ctx.r31.u64 = ctx.r31.u64 | ctx.r25.u64;
	// rlwinm r4,r4,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// andi. r30,r30,207
	ctx.r30.u64 = ctx.r30.u64 & 207;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// srawi r31,r31,2
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x3) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 2;
	// lbzx r8,r8,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r5.u32);
	// or r4,r30,r4
	ctx.r4.u64 = ctx.r30.u64 | ctx.r4.u64;
	// or r31,r31,r25
	ctx.r31.u64 = ctx.r31.u64 | ctx.r25.u64;
	// rlwinm r4,r4,30,26,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3F;
	// andi. r8,r8,195
	ctx.r8.u64 = ctx.r8.u64 & 195;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// or r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 | ctx.r8.u64;
	// lbzx r4,r31,r5
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r5.u32);
	// rlwimi r4,r8,30,26,31
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 30) & 0x3F) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFC0);
	// stbu r4,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r4.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x820cf8d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF8D0;
loc_820CF978:
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// bne cr6,0x820cf9d4
	if (!ctx.cr6.eq) goto loc_820CF9D4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820CF9A0:
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r9,r10,0,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// srawi r7,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 4;
	// rlwinm r10,r10,4,24,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF0;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// lbzx r9,r9,r5
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// lbzx r10,r10,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// rlwimi r9,r10,28,28,31
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 28) & 0xF) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFF0);
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf9a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF9A0;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CF9D4:
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bne cr6,0x820cfa00
	if (!ctx.cr6.eq) goto loc_820CFA00;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_820CF9EC:
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbzx r10,r10,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cf9ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CF9EC;
	// b 0x820cfa4c
	goto loc_820CFA4C;
loc_820CFA00:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bne cr6,0x820cfa4c
	if (!ctx.cr6.eq) goto loc_820CFA4C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfa4c
	if (ctx.cr6.eq) goto loc_820CFA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_820CFA1C:
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lwzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lhzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r7.u32);
	// rlwinm r8,r10,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// stb r8,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r8.u8);
	// stbu r10,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cfa1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFA1C;
loc_820CFA4C:
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CFA50"))) PPC_WEAK_FUNC(sub_820CFA50);
PPC_FUNC_IMPL(__imp__sub_820CFA50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820CFA58;
	__savegprlr_29(ctx, base);
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x820cfce8
	if (!ctx.cr6.eq) goto loc_820CFCE8;
	// lbz r10,9(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// li r31,8
	ctx.r31.s64 = 8;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bge cr6,0x820cfbc0
	if (!ctx.cr6.lt) goto loc_820CFBC0;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x820cfb54
	if (ctx.cr6.eq) goto loc_820CFB54;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820cfaec
	if (ctx.cr6.eq) goto loc_820CFAEC;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bne cr6,0x820cfbb4
	if (!ctx.cr6.eq) goto loc_820CFBB4;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r10,r11,2,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfbb4
	if (ctx.cr6.eq) goto loc_820CFBB4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CFAB4:
	// lbz r30,0(r9)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// srw r30,r30,r29
	ctx.r30.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r29.u8 & 0x3F));
	// clrlwi r30,r30,28
	ctx.r30.u64 = ctx.r30.u32 & 0xF;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
	// bne cr6,0x820cfadc
	if (!ctx.cr6.eq) goto loc_820CFADC;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x820cfae0
	goto loc_820CFAE0;
loc_820CFADC:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_820CFAE0:
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// bdnz 0x820cfab4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFAB4;
	// b 0x820cfbb4
	goto loc_820CFBB4;
loc_820CFAEC:
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// clrlwi r8,r10,30
	ctx.r8.u64 = ctx.r10.u32 & 0x3;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// subfic r30,r8,3
	ctx.xer.ca = ctx.r8.u32 <= 3;
	ctx.r30.s64 = 3 - ctx.r8.s64;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfbb4
	if (ctx.cr6.eq) goto loc_820CFBB4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CFB1C:
	// lbz r30,0(r9)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// srw r30,r30,r29
	ctx.r30.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r29.u8 & 0x3F));
	// clrlwi r30,r30,30
	ctx.r30.u64 = ctx.r30.u32 & 0x3;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
	// bne cr6,0x820cfb44
	if (!ctx.cr6.eq) goto loc_820CFB44;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x820cfb48
	goto loc_820CFB48;
loc_820CFB44:
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
loc_820CFB48:
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// bdnz 0x820cfb1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFB1C;
	// b 0x820cfbb4
	goto loc_820CFBB4;
loc_820CFB54:
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// clrlwi r30,r8,29
	ctx.r30.u64 = ctx.r8.u32 & 0x7;
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// subfic r10,r30,7
	ctx.xer.ca = ctx.r30.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r30.s64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfbb4
	if (ctx.cr6.eq) goto loc_820CFBB4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820CFB80:
	// lbz r30,0(r9)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// srw r30,r30,r29
	ctx.r30.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r29.u8 & 0x3F));
	// clrlwi r30,r30,31
	ctx.r30.u64 = ctx.r30.u32 & 0x1;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
	// bne cr6,0x820cfba8
	if (!ctx.cr6.eq) goto loc_820CFBA8;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x820cfbac
	goto loc_820CFBAC;
loc_820CFBA8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820CFBAC:
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// bdnz 0x820cfb80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFB80;
loc_820CFBB4:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stb r31,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r31.u8);
	// stb r31,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r31.u8);
loc_820CFBC0:
	// lbz r10,9(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x820cfce8
	if (!ctx.cr6.eq) goto loc_820CFCE8;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// beq cr6,0x820cfc68
	if (ctx.cr6.eq) goto loc_820CFC68;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// add r9,r8,r4
	ctx.r9.u64 = ctx.r8.u64 + ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// beq cr6,0x820cfc54
	if (ctx.cr6.eq) goto loc_820CFC54;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820CFBF8:
	// lbz r11,-1(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// li r4,255
	ctx.r4.s64 = 255;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x820cfc0c
	if (!ctx.cr6.lt) goto loc_820CFC0C;
	// lbzx r4,r11,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r6.u32);
loc_820CFC0C:
	// stb r4,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r4.u8);
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// lbz r9,-1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lbz r9,2(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// lbz r9,-1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lbz r9,1(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// stbu r9,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// lbzu r9,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// lbzx r9,r9,r5
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// stbu r9,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// bdnz 0x820cfbf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFBF8;
loc_820CFC54:
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r9,4
	ctx.r9.s64 = 4;
	// b 0x820cfcd8
	goto loc_820CFCD8;
loc_820CFC68:
	// mulli r7,r11,3
	ctx.r7.s64 = ctx.r11.s64 * 3;
	// add r9,r7,r4
	ctx.r9.u64 = ctx.r7.u64 + ctx.r4.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cfcc8
	if (ctx.cr6.eq) goto loc_820CFCC8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
loc_820CFC88:
	// lbz r9,-1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lbz r9,2(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// lbz r9,-1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lbz r9,1(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// stbu r9,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// lbzu r9,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// lbzx r9,r9,r5
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// stbu r9,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// bdnz 0x820cfc88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFC88;
loc_820CFCC8:
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,3
	ctx.r9.s64 = 3;
loc_820CFCD8:
	// stb r9,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r9.u8);
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r11.u8);
	// stb r31,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r31.u8);
loc_820CFCE8:
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820CFCEC"))) PPC_WEAK_FUNC(sub_820CFCEC);
PPC_FUNC_IMPL(__imp__sub_820CFCEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820CFCF0"))) PPC_WEAK_FUNC(sub_820CFCF0);
PPC_FUNC_IMPL(__imp__sub_820CFCF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820CFCF8;
	__savegprlr_29(ctx, base);
	// lbz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x820cffe0
	if (!ctx.cr0.eq) goto loc_820CFFE0;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820cfd1c
	if (ctx.cr6.eq) goto loc_820CFD1C;
	// lhz r11,8(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 8);
	// b 0x820cfd20
	goto loc_820CFD20;
loc_820CFD1C:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_820CFD20:
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// li r6,255
	ctx.r6.s64 = 255;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x820cfed8
	if (!ctx.cr6.lt) goto loc_820CFED8;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820cfe50
	if (ctx.cr6.eq) goto loc_820CFE50;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820cfdc4
	if (ctx.cr6.eq) goto loc_820CFDC4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820cfec8
	if (!ctx.cr6.eq) goto loc_820CFEC8;
	// clrlwi r10,r7,16
	ctx.r10.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// mulli r30,r10,17
	ctx.r30.s64 = ctx.r10.s64 * 17;
	// add r11,r9,r4
	ctx.r11.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r10,r8,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r29,r7,2,29,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x4;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subfic r11,r29,4
	ctx.xer.ca = ctx.r29.u32 <= 4;
	ctx.r11.s64 = 4 - ctx.r29.s64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cfec8
	if (ctx.cr6.eq) goto loc_820CFEC8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CFD84:
	// lbz r30,0(r10)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r29,r11,24
	ctx.r29.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// srw r11,r30,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r29.u8 & 0x3F));
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r30,r11,4,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// or r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 | ctx.r11.u64;
	// stb r11,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r11.u8);
	// bne cr6,0x820cfdb4
	if (!ctx.cr6.eq) goto loc_820CFDB4;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x820cfdb8
	goto loc_820CFDB8;
loc_820CFDB4:
	// li r11,4
	ctx.r11.s64 = 4;
loc_820CFDB8:
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// bdnz 0x820cfd84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFD84;
	// b 0x820cfec8
	goto loc_820CFEC8;
loc_820CFDC4:
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// clrlwi r10,r7,16
	ctx.r10.u64 = ctx.r7.u32 & 0xFFFF;
	// clrlwi r7,r11,30
	ctx.r7.u64 = ctx.r11.u32 & 0x3;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// mulli r30,r10,85
	ctx.r30.s64 = ctx.r10.s64 * 85;
	// add r11,r9,r4
	ctx.r11.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r10,r8,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// subfic r29,r7,3
	ctx.xer.ca = ctx.r7.u32 <= 3;
	ctx.r29.s64 = 3 - ctx.r7.s64;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cfec8
	if (ctx.cr6.eq) goto loc_820CFEC8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CFE00:
	// lbz r30,0(r10)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r29,r11,24
	ctx.r29.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// srw r30,r30,r29
	ctx.r30.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r29.u8 & 0x3F));
	// clrlwi r30,r30,30
	ctx.r30.u64 = ctx.r30.u32 & 0x3;
	// rlwinm r29,r30,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// or r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 | ctx.r30.u64;
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// or r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 | ctx.r30.u64;
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// or r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 | ctx.r30.u64;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
	// bne cr6,0x820cfe40
	if (!ctx.cr6.eq) goto loc_820CFE40;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x820cfe44
	goto loc_820CFE44;
loc_820CFE40:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_820CFE44:
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// bdnz 0x820cfe00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFE00;
	// b 0x820cfec8
	goto loc_820CFEC8;
loc_820CFE50:
	// clrlwi r10,r7,16
	ctx.r10.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// mulli r30,r10,255
	ctx.r30.s64 = ctx.r10.s64 * 255;
	// add r11,r9,r4
	ctx.r11.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r10,r8,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r29,r7,29
	ctx.r29.u64 = ctx.r7.u32 & 0x7;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subfic r11,r29,7
	ctx.xer.ca = ctx.r29.u32 <= 7;
	ctx.r11.s64 = 7 - ctx.r29.s64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cfec8
	if (ctx.cr6.eq) goto loc_820CFEC8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CFE88:
	// lbz r30,0(r10)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r29,r11,24
	ctx.r29.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// srw r30,r30,r29
	ctx.r30.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r29.u8 & 0x3F));
	// clrlwi r30,r30,31
	ctx.r30.u64 = ctx.r30.u32 & 0x1;
	// subfic r30,r30,0
	ctx.xer.ca = ctx.r30.u32 <= 0;
	ctx.r30.s64 = 0 - ctx.r30.s64;
	// subfe r30,r30,r30
	temp.u8 = (~ctx.r30.u32 + ctx.r30.u32 < ~ctx.r30.u32) | (~ctx.r30.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r30.u64 = ~ctx.r30.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r30,r6
	ctx.r30.u64 = ctx.r30.u64 & ctx.r6.u64;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
	// bne cr6,0x820cfebc
	if (!ctx.cr6.eq) goto loc_820CFEBC;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x820cfec0
	goto loc_820CFEC0;
loc_820CFEBC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820CFEC0:
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// bdnz 0x820cfe88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFE88;
loc_820CFEC8:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r11.u8);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r11.u8);
loc_820CFED8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820d0194
	if (ctx.cr6.eq) goto loc_820D0194;
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820cff44
	if (!ctx.cr6.eq) goto loc_820CFF44;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r4
	ctx.r11.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820cffc4
	if (ctx.cr6.eq) goto loc_820CFFC4;
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
loc_820CFF18:
	// lbz r8,-1(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820cff2c
	if (!ctx.cr6.eq) goto loc_820CFF2C;
	// stb r31,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r31.u8);
	// b 0x820cff30
	goto loc_820CFF30;
loc_820CFF2C:
	// stb r6,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r6.u8);
loc_820CFF30:
	// lbzu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stbu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820cff18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFF18;
	// b 0x820cffc4
	goto loc_820CFFC4;
loc_820CFF44:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820cffc4
	if (!ctx.cr6.eq) goto loc_820CFFC4;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// beq cr6,0x820cffc4
	if (ctx.cr6.eq) goto loc_820CFFC4;
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820CFF74:
	// lbz r5,-1(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// addi r10,r8,-1
	ctx.r10.s64 = ctx.r8.s64 + -1;
	// lbz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// rotlwi r5,r5,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// cmpw cr6,r5,r7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x820cff9c
	if (!ctx.cr6.eq) goto loc_820CFF9C;
	// stb r31,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// stbu r31,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r31.u8);
	ctx.r11.u32 = ea;
	// b 0x820cffa4
	goto loc_820CFFA4;
loc_820CFF9C:
	// stb r6,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
	// stbu r6,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r11.u32 = ea;
loc_820CFFA4:
	// lbz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stb r5,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stbu r10,-1(r11)
	ea = -1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// bdnz 0x820cff74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820CFF74;
loc_820CFFC4:
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r8,4
	ctx.r8.s64 = 4;
	// rlwinm r11,r11,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFE;
	// stb r10,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r10.u8);
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// b 0x820d0184
	goto loc_820D0184;
loc_820CFFE0:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820d0194
	if (!ctx.cr6.eq) goto loc_820D0194;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820d0194
	if (ctx.cr6.eq) goto loc_820D0194;
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820d0090
	if (!ctx.cr6.eq) goto loc_820D0090;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// beq cr6,0x820d016c
	if (ctx.cr6.eq) goto loc_820D016C;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r6,255
	ctx.r6.s64 = 255;
loc_820D0028:
	// lbz r8,-2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -2);
	// lhz r7,2(r5)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r5.u32 + 2);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820d0060
	if (!ctx.cr6.eq) goto loc_820D0060;
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// lhz r7,4(r5)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820d0060
	if (!ctx.cr6.eq) goto loc_820D0060;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lhz r7,6(r5)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r5.u32 + 6);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820d0060
	if (!ctx.cr6.eq) goto loc_820D0060;
	// stb r31,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r31.u8);
	// b 0x820d0064
	goto loc_820D0064;
loc_820D0060:
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
loc_820D0064:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// bdnz 0x820d0028
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0028;
	// b 0x820d016c
	goto loc_820D016C;
loc_820D0090:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820d016c
	if (!ctx.cr6.eq) goto loc_820D016C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// beq cr6,0x820d016c
	if (ctx.cr6.eq) goto loc_820D016C;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r6,255
	ctx.r6.s64 = 255;
loc_820D00C4:
	// lbz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -4);
	// lbz r7,-5(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + -5);
	// lhz r4,2(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 2);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// cmpw cr6,r8,r4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x820d0124
	if (!ctx.cr6.eq) goto loc_820D0124;
	// lbz r8,-2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -2);
	// lbz r7,-3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + -3);
	// lhz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// cmpw cr6,r8,r4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x820d0124
	if (!ctx.cr6.eq) goto loc_820D0124;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,-1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// lhz r4,6(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 6);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// cmpw cr6,r8,r4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x820d0124
	if (!ctx.cr6.eq) goto loc_820D0124;
	// stb r31,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r31.u8);
	// stbu r31,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r31.u8);
	ctx.r10.u32 = ea;
	// b 0x820d012c
	goto loc_820D012C;
loc_820D0124:
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// stbu r6,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r10.u32 = ea;
loc_820D012C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// lbzu r8,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stbu r8,-1(r10)
	ea = -1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// bdnz 0x820d00c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D00C4;
loc_820D016C:
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r8,4
	ctx.r8.s64 = 4;
	// rlwinm r11,r11,2,24,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFC;
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// stb r8,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r8.u8);
loc_820D0184:
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r11.u8);
	// rlwinm r11,r10,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
loc_820D0194:
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D0198"))) PPC_WEAK_FUNC(sub_820D0198);
PPC_FUNC_IMPL(__imp__sub_820D0198) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820d0200
	if (!ctx.cr6.eq) goto loc_820D0200;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820d0200
	if (ctx.cr6.eq) goto loc_820D0200;
	// lbz r8,9(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// bne cr6,0x820d0200
	if (!ctx.cr6.eq) goto loc_820D0200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d0258
	if (ctx.cr6.eq) goto loc_820D0258;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
loc_820D01D0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// rlwimi r8,r7,5,19,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 5) & 0x1F00) | (ctx.r8.u64 & 0xFFFFFFFFFFFFE0FF);
	// lbzu r7,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// srawi r7,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 3;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwimi r7,r8,2,17,26
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 2) & 0x7FE0) | (ctx.r7.u64 & 0xFFFFFFFFFFFF801F);
	// clrlwi r8,r7,17
	ctx.r8.u64 = ctx.r7.u32 & 0x7FFF;
	// lbzx r8,r8,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r5.u32);
	// stbu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x820d01d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D01D0;
	// b 0x820d0258
	goto loc_820D0258;
loc_820D0200:
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// bne cr6,0x820d0288
	if (!ctx.cr6.eq) goto loc_820D0288;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820d0288
	if (ctx.cr6.eq) goto loc_820D0288;
	// lbz r8,9(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// bne cr6,0x820d0288
	if (!ctx.cr6.eq) goto loc_820D0288;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d0258
	if (ctx.cr6.eq) goto loc_820D0258;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
loc_820D022C:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// rlwimi r8,r7,5,19,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 5) & 0x1F00) | (ctx.r8.u64 & 0xFFFFFFFFFFFFE0FF);
	// lbzu r7,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// srawi r7,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 3;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwimi r7,r8,2,17,26
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 2) & 0x7FE0) | (ctx.r7.u64 & 0xFFFFFFFFFFFF801F);
	// clrlwi r8,r7,17
	ctx.r8.u64 = ctx.r7.u32 & 0x7FFF;
	// lbzx r8,r8,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r5.u32);
	// stbu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x820d022c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D022C;
loc_820D0258:
	// li r11,3
	ctx.r11.s64 = 3;
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r11.u8);
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stb r8,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r8.u8);
	// stb r9,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r9.u8);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
loc_820D0288:
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820D02B4:
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r6.u32);
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820d02b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D02B4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D02C8"))) PPC_WEAK_FUNC(sub_820D02C8);
PPC_FUNC_IMPL(__imp__sub_820D02C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820D02D0;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x82080368
	ctx.lr = 0x820D02D8;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,1584(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1584);
	ctx.f13.f64 = double(temp.f32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lfs f0,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x820d0648
	if (ctx.cr6.eq) goto loc_820D0648;
	// lbz r11,1559(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1559);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x820d039c
	if (ctx.cr6.gt) goto loc_820D039C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,1588(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1588);
	ctx.f0.f64 = double(temp.f32);
	// lfd f12,-11816(r11)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + -11816);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820d0328
	if (!ctx.cr6.gt) goto loc_820D0328;
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfd f0,2064(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
	// fdiv f28,f0,f13
	ctx.f28.f64 = ctx.f0.f64 / ctx.f13.f64;
	// b 0x820d032c
	goto loc_820D032C;
loc_820D0328:
	// lfd f28,2064(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
loc_820D032C:
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d2da8
	ctx.lr = 0x820D0338;
	sub_820D2DA8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,1592(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1592, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r31,0
	ctx.r31.s64 = 0;
	// lfd f29,2072(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2072);
	// lfd f30,-11824(r10)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r10.u32 + -11824);
	// lfd f31,-11832(r9)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r9.u32 + -11832);
loc_820D0358:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmr f2,f28
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f28.f64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fmul f1,f0,f31
	ctx.f1.f64 = ctx.f0.f64 * ctx.f31.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x820D0374;
	sub_8207B7A8(ctx, base);
	// fmadd f0,f1,f30,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64 * ctx.f30.f64 + ctx.f29.f64;
	// lwz r11,1592(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1592);
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lbz r10,95(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// stbx r10,r11,r31
	PPC_STORE_U8(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,256
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 256, ctx.xer);
	// blt cr6,0x820d0358
	if (ctx.cr6.lt) goto loc_820D0358;
	// b 0x820d0648
	goto loc_820D0648;
loc_820D039C:
	// lbz r11,1558(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1558);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d03d0
	if (ctx.cr0.eq) goto loc_820D03D0;
	// lbz r11,1616(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1616);
	// lbz r10,1617(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1617);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x820d03bc
	if (!ctx.cr6.gt) goto loc_820D03BC;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D03BC:
	// lbz r10,1618(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1618);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x820d03d4
	if (!ctx.cr6.gt) goto loc_820D03D4;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x820d03d4
	goto loc_820D03D4;
loc_820D03D0:
	// lbz r11,1619(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1619);
loc_820D03D4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subfic r11,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r11.s64 = 16 - ctx.r11.s64;
	// bgt cr6,0x820d03e4
	if (ctx.cr6.gt) goto loc_820D03E4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D03E4:
	// lwz r10,1376(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1376);
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d03fc
	if (ctx.cr0.eq) goto loc_820D03FC;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x820d03fc
	if (!ctx.cr6.lt) goto loc_820D03FC;
	// li r11,5
	ctx.r11.s64 = 5;
loc_820D03FC:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// ble cr6,0x820d0408
	if (!ctx.cr6.gt) goto loc_820D0408;
	// li r11,8
	ctx.r11.s64 = 8;
loc_820D0408:
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lfs f0,1588(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 1588);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// and r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 & ctx.r11.u64;
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// lfd f12,-11816(r9)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r9.u32 + -11816);
	// subfic r25,r29,8
	ctx.xer.ca = ctx.r29.u32 <= 8;
	ctx.r25.s64 = 8 - ctx.r29.s64;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// stw r11,1580(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1580, ctx.r11.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// slw r24,r8,r25
	ctx.r24.u64 = ctx.r25.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r25.u8 & 0x3F));
	// addi r11,r11,2064
	ctx.r11.s64 = ctx.r11.s64 + 2064;
	// lfd f31,0(r11)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// ble cr6,0x820d0454
	if (!ctx.cr6.gt) goto loc_820D0454;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fdiv f30,f31,f0
	ctx.f30.f64 = ctx.f31.f64 / ctx.f0.f64;
	// b 0x820d0458
	goto loc_820D0458;
loc_820D0454:
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f31.f64;
loc_820D0458:
	// rlwinm r4,r24,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d2da8
	ctx.lr = 0x820D0464;
	sub_820D2DA8(ctx, base);
	// lwz r11,1376(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1376);
	// stw r3,1604(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1604, ctx.r3.u32);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// andi. r11,r11,1152
	ctx.r11.u64 = ctx.r11.u64 & 1152;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820d059c
	if (ctx.cr0.eq) goto loc_820D059C;
	// ble cr6,0x820d04a8
	if (!ctx.cr6.gt) goto loc_820D04A8;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_820D0488:
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d2da8
	ctx.lr = 0x820D0494;
	sub_820D2DA8(ctx, base);
	// lwz r11,1604(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1604);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stwx r3,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x820d0488
	if (!ctx.cr0.eq) goto loc_820D0488;
loc_820D04A8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fdiv f29,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f31.f64 / ctx.f30.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r26,r24,8,0,23
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 8) & 0xFFFFFF00;
	// li r31,0
	ctx.r31.s64 = 0;
	// std r26,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r26.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfd f30,-11840(r11)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r11.u32 + -11840);
	// li r30,0
	ctx.r30.s64 = 0;
	// lfd f31,2072(r10)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2072);
	// fcfid f28,f0
	ctx.f28.f64 = double(ctx.f0.s64);
	// li r27,255
	ctx.r27.s64 = 255;
loc_820D04D8:
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fadd f0,f0,f31
	ctx.f0.f64 = ctx.f0.f64 + ctx.f31.f64;
	// fmul f1,f0,f30
	ctx.f1.f64 = ctx.f0.f64 * ctx.f30.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x820D04F8;
	sub_8207B7A8(ctx, base);
	// fmul f0,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64 * ctx.f28.f64;
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d0550
	if (ctx.cr6.gt) goto loc_820D0550;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// rlwinm r10,r30,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 | ctx.r30.u64;
	// sraw r9,r27,r29
	temp.u32 = ctx.r29.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r27.s32 < 0) & (((ctx.r27.s32 >> temp.u32) << temp.u32) != ctx.r27.s32);
	ctx.r9.s64 = ctx.r27.s32 >> temp.u32;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D052C:
	// and r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 & ctx.r31.u64;
	// lwz r8,1604(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1604);
	// srw r7,r31,r25
	ctx.r7.u64 = ctx.r25.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r25.u8 & 0x3F));
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lwzx r11,r11,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// sthx r10,r11,r7
	PPC_STORE_U16(ctx.r11.u32 + ctx.r7.u32, ctx.r10.u16);
	// bdnz 0x820d052c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D052C;
loc_820D0550:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,256
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 256, ctx.xer);
	// blt cr6,0x820d04d8
	if (ctx.cr6.lt) goto loc_820D04D8;
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x820d0648
	if (!ctx.cr6.lt) goto loc_820D0648;
	// subf r10,r31,r26
	ctx.r10.s64 = ctx.r26.s64 - ctx.r31.s64;
	// sraw r11,r27,r29
	temp.u32 = ctx.r29.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r27.s32 < 0) & (((ctx.r27.s32 >> temp.u32) << temp.u32) != ctx.r27.s32);
	ctx.r11.s64 = ctx.r27.s32 >> temp.u32;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D0570:
	// and r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 & ctx.r31.u64;
	// lwz r9,1604(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1604);
	// srw r8,r31,r25
	ctx.r8.u64 = ctx.r25.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r25.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// sthx r7,r10,r8
	PPC_STORE_U16(ctx.r10.u32 + ctx.r8.u32, ctx.r7.u16);
	// bdnz 0x820d0570
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0570;
	// b 0x820d0648
	goto loc_820D0648;
loc_820D059C:
	// li r27,0
	ctx.r27.s64 = 0;
	// ble cr6,0x820d0648
	if (!ctx.cr6.gt) goto loc_820D0648;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r26,r11,13776
	ctx.r26.s64 = ctx.r11.s64 + 13776;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r25,r29,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfd f29,-11848(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r10.u32 + -11848);
	// li r30,0
	ctx.r30.s64 = 0;
	// lfd f28,-11856(r11)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r11.u32 + -11856);
	// lfd f31,2072(r9)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2072);
loc_820D05CC:
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d2da8
	ctx.lr = 0x820D05D8;
	sub_820D2DA8(ctx, base);
	// lwz r11,1604(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1604);
	// li r31,0
	ctx.r31.s64 = 0;
	// stwx r3,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// lwzx r11,r25,r26
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r26.u32);
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// rlwinm r29,r11,28,4,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
loc_820D05F0:
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fmul f1,f0,f29
	ctx.f1.f64 = ctx.f0.f64 * ctx.f29.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x820D060C;
	sub_8207B7A8(ctx, base);
	// fmadd f0,f1,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64 * ctx.f28.f64 + ctx.f31.f64;
	// lwz r11,1604(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1604);
	// addi r29,r29,256
	ctx.r29.s64 = ctx.r29.s64 + 256;
	// lwzx r11,r30,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// cmpwi cr6,r31,512
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 512, ctx.xer);
	// blt cr6,0x820d05f0
	if (ctx.cr6.lt) goto loc_820D05F0;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpw cr6,r27,r24
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r24.s32, ctx.xer);
	// blt cr6,0x820d05cc
	if (ctx.cr6.lt) goto loc_820D05CC;
loc_820D0648:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x820803b4
	ctx.lr = 0x820D0654;
	__restfpr_28(ctx, base);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D0658"))) PPC_WEAK_FUNC(sub_820D0658);
PPC_FUNC_IMPL(__imp__sub_820D0658) {
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
	// lwz r11,1376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1376);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r30,1558(r3)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1558);
	// rlwinm r11,r11,0,9,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FE000;
	// rlwinm. r11,r11,0,18,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFE03FFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d06dc
	if (ctx.cr0.eq) goto loc_820D06DC;
	// bl 0x820d02c8
	ctx.lr = 0x820D0688;
	sub_820D02C8(ctx, base);
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// bne cr6,0x820d06dc
	if (!ctx.cr6.eq) goto loc_820D06DC;
	// lhz r11,1544(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1544);
	// lwz r10,1540(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x820d06dc
	if (!ctx.cr0.gt) goto loc_820D06DC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_820D06A8:
	// lwz r9,1592(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// stb r10,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// lwz r10,1592(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// lbzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// stb r10,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r10.u8);
	// lwz r10,1592(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// lbzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// stbu r10,3(r11)
	ea = 3 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820d06a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D06A8;
loc_820D06DC:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d07c0
	if (ctx.cr0.eq) goto loc_820D07C0;
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// bne cr6,0x820d07c0
	if (!ctx.cr6.eq) goto loc_820D07C0;
	// lbz r11,1616(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1616);
	// lbz r10,1617(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1617);
	// lbz r7,1618(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1618);
	// subfic r11,r11,8
	ctx.xer.ca = ctx.r11.u32 <= 8;
	ctx.r11.s64 = 8 - ctx.r11.s64;
	// subfic r9,r10,8
	ctx.xer.ca = ctx.r10.u32 <= 8;
	ctx.r9.s64 = 8 - ctx.r10.s64;
	// lhz r8,1544(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1544);
	// subfic r10,r7,8
	ctx.xer.ca = ctx.r7.u32 <= 8;
	ctx.r10.s64 = 8 - ctx.r7.s64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d071c
	if (ctx.cr6.lt) goto loc_820D071C;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// ble cr6,0x820d0720
	if (!ctx.cr6.gt) goto loc_820D0720;
loc_820D071C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D0720:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt cr6,0x820d0730
	if (ctx.cr6.lt) goto loc_820D0730;
	// cmpwi cr6,r9,8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 8, ctx.xer);
	// ble cr6,0x820d0734
	if (!ctx.cr6.gt) goto loc_820D0734;
loc_820D0730:
	// li r9,0
	ctx.r9.s64 = 0;
loc_820D0734:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x820d0744
	if (ctx.cr6.lt) goto loc_820D0744;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// ble cr6,0x820d0748
	if (!ctx.cr6.gt) goto loc_820D0748;
loc_820D0744:
	// li r10,0
	ctx.r10.s64 = 0;
loc_820D0748:
	// clrlwi. r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x820d07c0
	if (ctx.cr0.eq) goto loc_820D07C0;
	// clrlwi r6,r9,24
	ctx.r6.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// li r9,0
	ctx.r9.s64 = 0;
loc_820D0760:
	// lwz r10,1540(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// mulli r11,r9,3
	ctx.r11.s64 = ctx.r9.s64 * 3;
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r30,r6,24
	ctx.r30.u64 = ctx.r6.u32 & 0xFF;
	// srw r8,r8,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r3.u8 & 0x3F));
	// stbx r8,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r8.u8);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// clrlwi r3,r5,24
	ctx.r3.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r10,1540(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbz r8,1(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// srw r8,r8,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r30.u8 & 0x3F));
	// stb r8,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r8.u8);
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// lwz r10,1540(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// srw r8,r10,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r3.u8 & 0x3F));
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stb r8,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r8.u8);
	// blt cr6,0x820d0760
	if (ctx.cr6.lt) goto loc_820D0760;
loc_820D07C0:
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

__attribute__((alias("__imp__sub_820D07D8"))) PPC_WEAK_FUNC(sub_820D07D8);
PPC_FUNC_IMPL(__imp__sub_820D07D8) {
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
	// lwz r11,1500(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1500);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d0804
	if (!ctx.cr6.eq) goto loc_820D0804;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-11772
	ctx.r4.s64 = ctx.r11.s64 + -11772;
	// bl 0x820cab60
	ctx.lr = 0x820D0804;
	sub_820CAB60(ctx, base);
loc_820D0804:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d085c
	if (ctx.cr0.eq) goto loc_820D085C;
	// lbz r11,1528(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1528);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820d083c
	if (!ctx.cr6.eq) goto loc_820D083C;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// lhz r7,1546(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r6,1628(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1628);
	// lwz r5,1540(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// bl 0x820cfa50
	ctx.lr = 0x820D0838;
	sub_820CFA50(ctx, base);
	// b 0x820d085c
	goto loc_820D085C;
loc_820D083C:
	// lhz r11,1546(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// addi r5,r31,1632
	ctx.r5.s64 = ctx.r31.s64 + 1632;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bne 0x820d0858
	if (!ctx.cr0.eq) goto loc_820D0858;
	// li r5,0
	ctx.r5.s64 = 0;
loc_820D0858:
	// bl 0x820cfcf0
	ctx.lr = 0x820D085C;
	sub_820CFCF0(ctx, base);
loc_820D085C:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d0890
	if (ctx.cr0.eq) goto loc_820D0890;
	// lbz r11,1558(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x820d0890
	if (ctx.cr6.eq) goto loc_820D0890;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// lwz r7,1580(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1580);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r6,1604(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1604);
	// lwz r5,1592(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// bl 0x820cf5f0
	ctx.lr = 0x820D0890;
	sub_820CF5F0(ctx, base);
loc_820D0890:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d08ac
	if (ctx.cr0.eq) goto loc_820D08AC;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820cf2d0
	ctx.lr = 0x820D08AC;
	sub_820CF2D0(ctx, base);
loc_820D08AC:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d08ec
	if (ctx.cr0.eq) goto loc_820D08EC;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// lwz r6,1656(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1656);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r5,1652(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1652);
	// bl 0x820d0198
	ctx.lr = 0x820D08D0;
	sub_820D0198(ctx, base);
	// lwz r11,1524(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1524);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d08ec
	if (!ctx.cr6.eq) goto loc_820D08EC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-11808
	ctx.r4.s64 = ctx.r11.s64 + -11808;
	// bl 0x820cab60
	ctx.lr = 0x820D08EC;
	sub_820CAB60(ctx, base);
loc_820D08EC:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d090c
	if (ctx.cr0.eq) goto loc_820D090C;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r5,r31,1621
	ctx.r5.s64 = ctx.r31.s64 + 1621;
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820cf098
	ctx.lr = 0x820D090C;
	sub_820CF098(ctx, base);
loc_820D090C:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d0928
	if (ctx.cr0.eq) goto loc_820D0928;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820cef28
	ctx.lr = 0x820D0928;
	sub_820CEF28(ctx, base);
loc_820D0928:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d0944
	if (ctx.cr0.eq) goto loc_820D0944;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820cec48
	ctx.lr = 0x820D0944;
	sub_820CEC48(ctx, base);
loc_820D0944:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d0968
	if (ctx.cr0.eq) goto loc_820D0968;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// lwz r6,1372(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lhz r5,1566(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1566);
	// bl 0x820cf328
	ctx.lr = 0x820D0968;
	sub_820CF328(ctx, base);
loc_820D0968:
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d0984
	if (ctx.cr0.eq) goto loc_820D0984;
	// lwz r11,1500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1500);
	// addi r3,r31,1520
	ctx.r3.s64 = ctx.r31.s64 + 1520;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820cec08
	ctx.lr = 0x820D0984;
	sub_820CEC08(ctx, base);
loc_820D0984:
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

__attribute__((alias("__imp__sub_820D0998"))) PPC_WEAK_FUNC(sub_820D0998);
PPC_FUNC_IMPL(__imp__sub_820D0998) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,1360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1360);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d09ac
	if (ctx.cr6.eq) goto loc_820D09AC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_820D09AC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-11756
	ctx.r4.s64 = ctx.r11.s64 + -11756;
	// b 0x820cab60
	sub_820CAB60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D09B8"))) PPC_WEAK_FUNC(sub_820D09B8);
PPC_FUNC_IMPL(__imp__sub_820D09B8) {
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
	// lwz r11,1356(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1356);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,1364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1364, ctx.r4.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r5,1360(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1360, ctx.r5.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d0a08
	if (ctx.cr6.eq) goto loc_820D0A08;
	// stw r30,1356(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1356, ctx.r30.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-11672
	ctx.r4.s64 = ctx.r11.s64 + -11672;
	// bl 0x820cab98
	ctx.lr = 0x820D09F8;
	sub_820CAB98(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-11728
	ctx.r4.s64 = ctx.r11.s64 + -11728;
	// bl 0x820cab98
	ctx.lr = 0x820D0A08;
	sub_820CAB98(ctx, base);
loc_820D0A08:
	// stw r30,1568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1568, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_820D0A24"))) PPC_WEAK_FUNC(sub_820D0A24);
PPC_FUNC_IMPL(__imp__sub_820D0A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D0A28"))) PPC_WEAK_FUNC(sub_820D0A28);
PPC_FUNC_IMPL(__imp__sub_820D0A28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,16
	ctx.r11.s64 = 16;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f9,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,14004(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f10.f64 = double(temp.f32);
loc_820D0A40:
	// lfs f13,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f9
	ctx.cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// bne cr6,0x820d0a5c
	if (!ctx.cr6.eq) goto loc_820D0A5C;
	// stfs f9,0(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f9,4(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f9,8(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// b 0x820d0abc
	goto loc_820D0ABC;
loc_820D0A5C:
	// fcmpu cr6,f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// bge cr6,0x820d0abc
	if (!ctx.cr6.lt) goto loc_820D0ABC;
	// lfs f0,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f11,f10,f13
	ctx.f11.f64 = double(float(ctx.f10.f64 / ctx.f13.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0a7c
	if (!ctx.cr6.lt) goto loc_820D0A7C;
	// fmuls f12,f0,f11
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// b 0x820d0a80
	goto loc_820D0A80;
loc_820D0A7C:
	// fmr f12,f10
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f10.f64;
loc_820D0A80:
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,0(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0a98
	if (!ctx.cr6.lt) goto loc_820D0A98;
	// fmuls f12,f0,f11
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// b 0x820d0a9c
	goto loc_820D0A9C;
loc_820D0A98:
	// fmr f12,f10
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f10.f64;
loc_820D0A9C:
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0ab4
	if (!ctx.cr6.lt) goto loc_820D0AB4;
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// b 0x820d0ab8
	goto loc_820D0AB8;
loc_820D0AB4:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_820D0AB8:
	// stfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
loc_820D0ABC:
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bdnz 0x820d0a40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0A40;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D0ACC"))) PPC_WEAK_FUNC(sub_820D0ACC);
PPC_FUNC_IMPL(__imp__sub_820D0ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D0AD0"))) PPC_WEAK_FUNC(sub_820D0AD0);
PPC_FUNC_IMPL(__imp__sub_820D0AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0af4
	if (!ctx.cr6.lt) goto loc_820D0AF4;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// b 0x820d0b08
	goto loc_820D0B08;
loc_820D0AF4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820d0b04
	if (!ctx.cr6.gt) goto loc_820D0B04;
	// fmr f10,f12
	ctx.f10.f64 = ctx.f12.f64;
	// b 0x820d0b08
	goto loc_820D0B08;
loc_820D0B04:
	// fmr f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f0.f64;
loc_820D0B08:
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0b1c
	if (!ctx.cr6.lt) goto loc_820D0B1C;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// b 0x820d0b30
	goto loc_820D0B30;
loc_820D0B1C:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820d0b2c
	if (!ctx.cr6.gt) goto loc_820D0B2C;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// b 0x820d0b30
	goto loc_820D0B30;
loc_820D0B2C:
	// fmr f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f0.f64;
loc_820D0B30:
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0b44
	if (!ctx.cr6.lt) goto loc_820D0B44;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// b 0x820d0b50
	goto loc_820D0B50;
loc_820D0B44:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x820d0b50
	if (ctx.cr6.gt) goto loc_820D0B50;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
loc_820D0B50:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,-18460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -18460);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12868(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12868);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f11,f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f0.f64));
	// lfs f13,-18464(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18464);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f0.f64));
	// fmadds f0,f10,f13,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f0.f64));
	// fctiwz f13,f11
	ctx.f13.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D0BB0"))) PPC_WEAK_FUNC(sub_820D0BB0);
PPC_FUNC_IMPL(__imp__sub_820D0BB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d0bdc
	if (!ctx.cr6.eq) goto loc_820D0BDC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r8,r11,-4820
	ctx.r8.s64 = ctx.r11.s64 + -4820;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r30,r11,-4844
	ctx.r30.s64 = ctx.r11.s64 + -4844;
	// b 0x820d0bec
	goto loc_820D0BEC;
loc_820D0BDC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r8,r11,-4876
	ctx.r8.s64 = ctx.r11.s64 + -4876;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r30,r11,-4908
	ctx.r30.s64 = ctx.r11.s64 + -4908;
loc_820D0BEC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r6,8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 8, ctx.xer);
	// lfs f31,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f31.f64 = double(temp.f32);
	// li r11,16
	ctx.r11.s64 = 16;
	// lfs f5,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f5.f64 = double(temp.f32);
	// fmr f10,f31
	ctx.f10.f64 = ctx.f31.f64;
	// fmr f7,f5
	ctx.f7.f64 = ctx.f5.f64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne cr6,0x820d0c40
	if (!ctx.cr6.eq) goto loc_820D0C40;
loc_820D0C18:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x820d0c28
	if (!ctx.cr6.lt) goto loc_820D0C28;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
loc_820D0C28:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// ble cr6,0x820d0c34
	if (!ctx.cr6.gt) goto loc_820D0C34;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
loc_820D0C34:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820d0c18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0C18;
	// b 0x820d0c80
	goto loc_820D0C80;
loc_820D0C40:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x820d0c58
	if (!ctx.cr6.lt) goto loc_820D0C58;
	// fcmpu cr6,f0,f5
	ctx.cr6.compare(ctx.f0.f64, ctx.f5.f64);
	// ble cr6,0x820d0c58
	if (!ctx.cr6.gt) goto loc_820D0C58;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
loc_820D0C58:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// ble cr6,0x820d0c6c
	if (!ctx.cr6.gt) goto loc_820D0C6C;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x820d0c6c
	if (!ctx.cr6.lt) goto loc_820D0C6C;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
loc_820D0C6C:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820d0c40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0C40;
	// fcmpu cr6,f10,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f7.f64);
	// bne cr6,0x820d0c80
	if (!ctx.cr6.eq) goto loc_820D0C80;
	// fmr f7,f31
	ctx.f7.f64 = ctx.f31.f64;
loc_820D0C80:
	// addi r7,r6,-1
	ctx.r7.s64 = ctx.r6.s64 + -1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrldi r11,r7,32
	ctx.r11.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// std r11,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r11.u64);
	// lfd f0,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f2,22776(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 22776);
	ctx.f2.f64 = double(temp.f32);
	// li r31,0
	ctx.r31.s64 = 0;
	// lfs f4,12868(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12868);
	ctx.f4.f64 = double(temp.f32);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// lfs f3,-4912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4912);
	ctx.f3.f64 = double(temp.f32);
loc_820D0CB4:
	// fsubs f0,f7,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fcmpu cr6,f0,f3
	ctx.cr6.compare(ctx.f0.f64, ctx.f3.f64);
	// blt cr6,0x820d0e20
	if (ctx.cr6.lt) goto loc_820D0E20;
	// fdivs f6,f1,f0
	ctx.f6.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820d0cfc
	if (ctx.cr6.eq) goto loc_820D0CFC;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// subf r10,r8,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r8.s64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
loc_820D0CE0:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// lfsx f13,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f7,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f0.f64));
	// stfsx f0,r9,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820d0ce0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0CE0;
loc_820D0CFC:
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d0d0c
	if (!ctx.cr6.eq) goto loc_820D0D0C;
	// stfs f5,-40(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f31,-36(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + -36, temp.u32);
loc_820D0D0C:
	// li r11,16
	ctx.r11.s64 = 16;
	// fmr f9,f5
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f5.f64;
	// fmr f8,f5
	ctx.f8.f64 = ctx.f5.f64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// fmr f12,f5
	ctx.f12.f64 = ctx.f5.f64;
	// fmr f11,f5
	ctx.f11.f64 = ctx.f5.f64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D0D28:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f10
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// bgt cr6,0x820d0d58
	if (ctx.cr6.gt) goto loc_820D0D58;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d0d50
	if (!ctx.cr6.eq) goto loc_820D0D50;
	// fmuls f13,f10,f4
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x820d0dc0
	if (!ctx.cr6.gt) goto loc_820D0DC0;
loc_820D0D50:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820d0d90
	goto loc_820D0D90;
loc_820D0D58:
	// fcmpu cr6,f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f1.f64);
	// blt cr6,0x820d0d80
	if (ctx.cr6.lt) goto loc_820D0D80;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d0d78
	if (!ctx.cr6.eq) goto loc_820D0D78;
	// fadds f13,f7,f31
	ctx.f13.f64 = double(float(ctx.f7.f64 + ctx.f31.f64));
	// fmuls f13,f13,f4
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x820d0dc0
	if (!ctx.cr6.lt) goto loc_820D0DC0;
loc_820D0D78:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// b 0x820d0d90
	goto loc_820D0D90;
loc_820D0D80:
	// fadds f13,f13,f4
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f4.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f13.u64);
	// lwz r11,-76(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -76);
loc_820D0D90:
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x820d0dc0
	if (!ctx.cr6.lt) goto loc_820D0DC0;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// lfsx f13,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f30,r11,r9
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f12,f13,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lfsx f30,r11,r30
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f11,f30,f30,f11
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f30.f64 + ctx.f11.f64));
	// fmadds f9,f13,f0,f9
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f0.f64 + ctx.f9.f64));
	// fmadds f8,f30,f0,f8
	ctx.f8.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f8.f64));
loc_820D0DC0:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820d0d28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0D28;
	// fcmpu cr6,f12,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f5.f64);
	// ble cr6,0x820d0dd8
	if (!ctx.cr6.gt) goto loc_820D0DD8;
	// fdivs f0,f9,f12
	ctx.f0.f64 = double(float(ctx.f9.f64 / ctx.f12.f64));
	// fsubs f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
loc_820D0DD8:
	// fcmpu cr6,f11,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f5.f64);
	// ble cr6,0x820d0de8
	if (!ctx.cr6.gt) goto loc_820D0DE8;
	// fdivs f0,f8,f11
	ctx.f0.f64 = double(float(ctx.f8.f64 / ctx.f11.f64));
	// fsubs f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f0.f64));
loc_820D0DE8:
	// fcmpu cr6,f10,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f7.f64);
	// ble cr6,0x820d0dfc
	if (!ctx.cr6.gt) goto loc_820D0DFC;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// fmr f10,f7
	ctx.f10.f64 = ctx.f7.f64;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
loc_820D0DFC:
	// fmuls f0,f9,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// bge cr6,0x820d0e14
	if (!ctx.cr6.lt) goto loc_820D0E14;
	// fmuls f0,f8,f8
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// blt cr6,0x820d0e20
	if (ctx.cr6.lt) goto loc_820D0E20;
loc_820D0E14:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8, ctx.xer);
	// blt cr6,0x820d0cb4
	if (ctx.cr6.lt) goto loc_820D0CB4;
loc_820D0E20:
	// fcmpu cr6,f10,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f5.f64);
	// bge cr6,0x820d0e30
	if (!ctx.cr6.lt) goto loc_820D0E30;
	// fmr f0,f5
	ctx.f0.f64 = ctx.f5.f64;
	// b 0x820d0e44
	goto loc_820D0E44;
loc_820D0E30:
	// fcmpu cr6,f10,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f31.f64);
	// ble cr6,0x820d0e40
	if (!ctx.cr6.gt) goto loc_820D0E40;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x820d0e44
	goto loc_820D0E44;
loc_820D0E40:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_820D0E44:
	// stfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fcmpu cr6,f7,f5
	ctx.cr6.compare(ctx.f7.f64, ctx.f5.f64);
	// bge cr6,0x820d0e58
	if (!ctx.cr6.lt) goto loc_820D0E58;
	// fmr f0,f5
	ctx.f0.f64 = ctx.f5.f64;
	// b 0x820d0e6c
	goto loc_820D0E6C;
loc_820D0E58:
	// fcmpu cr6,f7,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f7.f64, ctx.f31.f64);
	// ble cr6,0x820d0e68
	if (!ctx.cr6.gt) goto loc_820D0E68;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x820d0e6c
	goto loc_820D0E6C;
loc_820D0E68:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_820D0E6C:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfd f30,-32(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D0E84"))) PPC_WEAK_FUNC(sub_820D0E84);
PPC_FUNC_IMPL(__imp__sub_820D0E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D0E88"))) PPC_WEAK_FUNC(sub_820D0E88);
PPC_FUNC_IMPL(__imp__sub_820D0E88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820D0E90;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x82080330
	ctx.lr = 0x820D0E98;
	__savefpr_14(ctx, base);
	// cmplwi cr6,r6,3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 3, ctx.xer);
	// bne cr6,0x820d0eb4
	if (!ctx.cr6.eq) goto loc_820D0EB4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r31,r11,-4740
	ctx.r31.s64 = ctx.r11.s64 + -4740;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r30,r11,-4752
	ctx.r30.s64 = ctx.r11.s64 + -4752;
	// b 0x820d0ec4
	goto loc_820D0EC4;
loc_820D0EB4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r31,r11,-4768
	ctx.r31.s64 = ctx.r11.s64 + -4768;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r30,r11,-4784
	ctx.r30.s64 = ctx.r11.s64 + -4784;
loc_820D0EC4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,13808
	ctx.r8.s64 = ctx.r11.s64 + 13808;
	// addi r7,r1,-272
	ctx.r7.s64 = ctx.r1.s64 + -272;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r29,13808(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 13808);
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// lfs f0,9388(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// fmr f26,f0
	ctx.f26.f64 = ctx.f0.f64;
	// lwz r28,8(r8)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// fmr f29,f0
	ctx.f29.f64 = ctx.f0.f64;
	// lwz r8,12(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// fmr f28,f0
	ctx.f28.f64 = ctx.f0.f64;
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r9,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// stw r28,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r28.u32);
	// stw r8,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// lfs f31,-264(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -264);
	ctx.f31.f64 = double(temp.f32);
	// lfs f1,-268(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -268);
	ctx.f1.f64 = double(temp.f32);
	// lfs f30,-272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -272);
	ctx.f30.f64 = double(temp.f32);
loc_820D0F20:
	// lfs f11,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f30
	ctx.cr6.compare(ctx.f11.f64, ctx.f30.f64);
	// bge cr6,0x820d0f30
	if (!ctx.cr6.lt) goto loc_820D0F30;
	// fmr f30,f11
	ctx.f30.f64 = ctx.f11.f64;
loc_820D0F30:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	ctx.cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x820d0f40
	if (!ctx.cr6.lt) goto loc_820D0F40;
	// fmr f1,f12
	ctx.f1.f64 = ctx.f12.f64;
loc_820D0F40:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bge cr6,0x820d0f50
	if (!ctx.cr6.lt) goto loc_820D0F50;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_820D0F50:
	// fcmpu cr6,f11,f26
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f26.f64);
	// ble cr6,0x820d0f5c
	if (!ctx.cr6.gt) goto loc_820D0F5C;
	// fmr f26,f11
	ctx.f26.f64 = ctx.f11.f64;
loc_820D0F5C:
	// fcmpu cr6,f12,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f29.f64);
	// ble cr6,0x820d0f68
	if (!ctx.cr6.gt) goto loc_820D0F68;
	// fmr f29,f12
	ctx.f29.f64 = ctx.f12.f64;
loc_820D0F68:
	// fcmpu cr6,f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f28.f64);
	// ble cr6,0x820d0f74
	if (!ctx.cr6.gt) goto loc_820D0F74;
	// fmr f28,f13
	ctx.f28.f64 = ctx.f13.f64;
loc_820D0F74:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x820d0f20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0F20;
	// fsubs f13,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f1.f64));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fsubs f12,f28,f31
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// fsubs f11,f26,f30
	ctx.f11.f64 = double(float(ctx.f26.f64 - ctx.f30.f64));
	// lfs f10,-4788(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4788);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f13
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f9,f12,f12,f9
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fmadds f3,f11,f11,f9
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f9.f64));
	// fcmpu cr6,f3,f10
	ctx.cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// blt cr6,0x820d12e4
	if (ctx.cr6.lt) goto loc_820D12E4;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fadds f6,f26,f30
	ctx.f6.f64 = double(float(ctx.f26.f64 + ctx.f30.f64));
	// fadds f5,f29,f1
	ctx.f5.f64 = double(float(ctx.f29.f64 + ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fadds f4,f28,f31
	ctx.f4.f64 = double(float(ctx.f28.f64 + ctx.f31.f64));
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r5,-16
	ctx.r11.s64 = ctx.r5.s64 + -16;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// lfs f10,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f10.f64 = double(temp.f32);
	// fmr f9,f0
	ctx.f9.f64 = ctx.f0.f64;
	// fdivs f2,f10,f3
	ctx.f2.f64 = double(float(ctx.f10.f64 / ctx.f3.f64));
	// lfs f27,12868(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12868);
	ctx.f27.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fmuls f6,f6,f27
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f27.f64));
	// fmuls f5,f5,f27
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f27.f64));
	// fmuls f4,f4,f27
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f27.f64));
	// fmuls f11,f2,f11
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// fmuls f13,f2,f13
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fmuls f12,f2,f12
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
loc_820D0FF8:
	// lfs f2,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f25,12(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f25.f64 = double(temp.f32);
	// fsubs f24,f2,f6
	ctx.f24.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// lfsu f2,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f2.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fsubs f25,f25,f5
	ctx.f25.f64 = double(float(ctx.f25.f64 - ctx.f5.f64));
	// fsubs f2,f2,f4
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f4.f64));
	// fmuls f24,f24,f11
	ctx.f24.f64 = double(float(ctx.f24.f64 * ctx.f11.f64));
	// fmuls f25,f25,f13
	ctx.f25.f64 = double(float(ctx.f25.f64 * ctx.f13.f64));
	// fmuls f2,f2,f12
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// fsubs f23,f24,f25
	ctx.f23.f64 = double(float(ctx.f24.f64 - ctx.f25.f64));
	// fadds f22,f25,f24
	ctx.f22.f64 = double(float(ctx.f25.f64 + ctx.f24.f64));
	// fadds f25,f2,f25
	ctx.f25.f64 = double(float(ctx.f2.f64 + ctx.f25.f64));
	// fadds f21,f23,f2
	ctx.f21.f64 = double(float(ctx.f23.f64 + ctx.f2.f64));
	// fsubs f22,f22,f2
	ctx.f22.f64 = double(float(ctx.f22.f64 - ctx.f2.f64));
	// fadds f25,f25,f24
	ctx.f25.f64 = double(float(ctx.f25.f64 + ctx.f24.f64));
	// fsubs f2,f23,f2
	ctx.f2.f64 = double(float(ctx.f23.f64 - ctx.f2.f64));
	// fmadds f8,f21,f21,f8
	ctx.f8.f64 = double(float(ctx.f21.f64 * ctx.f21.f64 + ctx.f8.f64));
	// fmadds f9,f22,f22,f9
	ctx.f9.f64 = double(float(ctx.f22.f64 * ctx.f22.f64 + ctx.f9.f64));
	// fmadds f10,f25,f25,f10
	ctx.f10.f64 = double(float(ctx.f25.f64 * ctx.f25.f64 + ctx.f10.f64));
	// fmadds f7,f2,f2,f7
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f7.f64));
	// bdnz 0x820d0ff8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D0FF8;
	// li r10,3
	ctx.r10.s64 = 3;
	// stfs f7,-260(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -260, temp.u32);
	// stfs f10,-272(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -272, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f9,-268(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -268, temp.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f8,-264(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -264, temp.u32);
	// addi r9,r1,-268
	ctx.r9.s64 = ctx.r1.s64 + -268;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D1070:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f10
	ctx.cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x820d1084
	if (!ctx.cr6.gt) goto loc_820D1084;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_820D1084:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x820d1070
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1070;
	// rlwinm. r11,r8,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d10a4
	if (ctx.cr0.eq) goto loc_820D10A4;
	// fmr f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmr f29,f13
	ctx.f29.f64 = ctx.f13.f64;
loc_820D10A4:
	// clrlwi. r11,r8,31
	ctx.r11.u64 = ctx.r8.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d10b8
	if (ctx.cr0.eq) goto loc_820D10B8;
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
	// fmr f31,f28
	ctx.f31.f64 = ctx.f28.f64;
	// fmr f28,f13
	ctx.f28.f64 = ctx.f13.f64;
loc_820D10B8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f9,-4792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4792);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,-288(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -288, temp.u32);
	// fcmpu cr6,f3,f9
	ctx.cr6.compare(ctx.f3.f64, ctx.f9.f64);
	// blt cr6,0x820d12e4
	if (ctx.cr6.lt) goto loc_820D12E4;
	// addi r8,r6,-1
	ctx.r8.s64 = ctx.r6.s64 + -1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrldi r11,r8,32
	ctx.r11.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// std r11,-272(r1)
	PPC_STORE_U64(ctx.r1.u32 + -272, ctx.r11.u64);
	// lfd f13,-272(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -272);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f24,14000(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14000);
	ctx.f24.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f23,12880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12880);
	ctx.f23.f64 = double(temp.f32);
	// frsp f25,f13
	ctx.f25.f64 = double(float(ctx.f13.f64));
	// lfs f22,-4796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4796);
	ctx.f22.f64 = double(temp.f32);
	// b 0x820d1108
	goto loc_820D1108;
loc_820D1104:
	// lfs f9,-288(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -288);
	ctx.f9.f64 = double(temp.f32);
loc_820D1108:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820d1154
	if (ctx.cr6.eq) goto loc_820D1154;
	// addi r10,r1,-264
	ctx.r10.s64 = ctx.r1.s64 + -264;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// subf r9,r31,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r31.s64;
loc_820D1120:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// lfsx f11,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f13,f1
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fmadds f12,f11,f26,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f26.f64 + ctx.f12.f64));
	// stfs f12,8(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// fmadds f12,f11,f29,f10
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f29.f64 + ctx.f10.f64));
	// stfs f12,12(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fmadds f13,f11,f28,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f28.f64 + ctx.f13.f64));
	// stfsu f13,16(r10)
	temp.f32 = float(ctx.f13.f64);
	ea = 16 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820d1120
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1120;
loc_820D1154:
	// fsubs f13,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f1.f64));
	// fsubs f12,f28,f31
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// fsubs f11,f26,f30
	ctx.f11.f64 = double(float(ctx.f26.f64 - ctx.f30.f64));
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f10,f12,f12,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fmadds f10,f11,f11,f10
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f10,f9
	ctx.cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// blt cr6,0x820d12e4
	if (ctx.cr6.lt) goto loc_820D12E4;
	// fdivs f21,f25,f10
	ctx.f21.f64 = double(float(ctx.f25.f64 / ctx.f10.f64));
	// li r10,16
	ctx.r10.s64 = 16;
	// fmr f3,f0
	ctx.f3.f64 = ctx.f0.f64;
	// addi r11,r5,-16
	ctx.r11.s64 = ctx.r5.s64 + -16;
	// fmr f4,f0
	ctx.f4.f64 = ctx.f0.f64;
	// fmr f5,f0
	ctx.f5.f64 = ctx.f0.f64;
	// fmr f6,f0
	ctx.f6.f64 = ctx.f0.f64;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// fmr f9,f0
	ctx.f9.f64 = ctx.f0.f64;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fmuls f11,f21,f11
	ctx.f11.f64 = double(float(ctx.f21.f64 * ctx.f11.f64));
	// fmuls f2,f21,f13
	ctx.f2.f64 = double(float(ctx.f21.f64 * ctx.f13.f64));
	// fmuls f12,f21,f12
	ctx.f12.f64 = double(float(ctx.f21.f64 * ctx.f12.f64));
loc_820D11B0:
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// lfs f21,16(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f21.f64 = double(temp.f32);
	// fsubs f21,f21,f31
	ctx.f21.f64 = double(float(ctx.f21.f64 - ctx.f31.f64));
	// lfs f20,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f20.f64 = double(temp.f32);
	// fsubs f20,f20,f30
	ctx.f20.f64 = double(float(ctx.f20.f64 - ctx.f30.f64));
	// fmuls f13,f13,f2
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f2.f64));
	// fmadds f13,f21,f12,f13
	ctx.f13.f64 = double(float(ctx.f21.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f13,f20,f11,f13
	ctx.f13.f64 = double(float(ctx.f20.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fcmpu cr6,f13,f25
	ctx.cr6.compare(ctx.f13.f64, ctx.f25.f64);
	// blt cr6,0x820d11e4
	if (ctx.cr6.lt) goto loc_820D11E4;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// b 0x820d11f4
	goto loc_820D11F4;
loc_820D11E4:
	// fadds f13,f13,f27
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f27.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-272(r1)
	PPC_STORE_U64(ctx.r1.u32 + -272, ctx.f13.u64);
	// lwz r10,-268(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -268);
loc_820D11F4:
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f21,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f21.f64 = double(temp.f32);
	// addi r29,r1,-256
	ctx.r29.s64 = ctx.r1.s64 + -256;
	// lfs f20,12(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f20.f64 = double(temp.f32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsu f13,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// addi r28,r1,-252
	ctx.r28.s64 = ctx.r1.s64 + -252;
	// addi r27,r1,-248
	ctx.r27.s64 = ctx.r1.s64 + -248;
	// lfsx f16,r9,r29
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r29.u32);
	ctx.f16.f64 = double(temp.f32);
	// fsubs f21,f16,f21
	ctx.f21.f64 = double(float(ctx.f16.f64 - ctx.f21.f64));
	// lfsx f19,r10,r31
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	ctx.f19.f64 = double(temp.f32);
	// lfsx f18,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	ctx.f18.f64 = double(temp.f32);
	// fmuls f17,f19,f23
	ctx.f17.f64 = double(float(ctx.f19.f64 * ctx.f23.f64));
	// lfsx f14,r9,r28
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	ctx.f14.f64 = double(temp.f32);
	// fmuls f15,f18,f23
	ctx.f15.f64 = double(float(ctx.f18.f64 * ctx.f23.f64));
	// lfsx f16,r9,r27
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r27.u32);
	ctx.f16.f64 = double(temp.f32);
	// fsubs f20,f14,f20
	ctx.f20.f64 = double(float(ctx.f14.f64 - ctx.f20.f64));
	// fsubs f13,f16,f13
	ctx.f13.f64 = double(float(ctx.f16.f64 - ctx.f13.f64));
	// fmadds f10,f19,f17,f10
	ctx.f10.f64 = double(float(ctx.f19.f64 * ctx.f17.f64 + ctx.f10.f64));
	// fmadds f9,f18,f15,f9
	ctx.f9.f64 = double(float(ctx.f18.f64 * ctx.f15.f64 + ctx.f9.f64));
	// fmadds f8,f17,f21,f8
	ctx.f8.f64 = double(float(ctx.f17.f64 * ctx.f21.f64 + ctx.f8.f64));
	// fmadds f7,f17,f20,f7
	ctx.f7.f64 = double(float(ctx.f17.f64 * ctx.f20.f64 + ctx.f7.f64));
	// fmadds f6,f17,f13,f6
	ctx.f6.f64 = double(float(ctx.f17.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fmadds f5,f15,f21,f5
	ctx.f5.f64 = double(float(ctx.f15.f64 * ctx.f21.f64 + ctx.f5.f64));
	// fmadds f4,f15,f20,f4
	ctx.f4.f64 = double(float(ctx.f15.f64 * ctx.f20.f64 + ctx.f4.f64));
	// fmadds f3,f15,f13,f3
	ctx.f3.f64 = double(float(ctx.f15.f64 * ctx.f13.f64 + ctx.f3.f64));
	// bdnz 0x820d11b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D11B0;
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x820d1278
	if (!ctx.cr6.gt) goto loc_820D1278;
	// fdivs f13,f24,f10
	ctx.f13.f64 = double(float(ctx.f24.f64 / ctx.f10.f64));
	// fmadds f30,f13,f8,f30
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f30.f64));
	// fmadds f1,f13,f7,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f1.f64));
	// fmadds f31,f13,f6,f31
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + ctx.f31.f64));
loc_820D1278:
	// fcmpu cr6,f9,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f9.f64, ctx.f0.f64);
	// ble cr6,0x820d1290
	if (!ctx.cr6.gt) goto loc_820D1290;
	// fdivs f13,f24,f9
	ctx.f13.f64 = double(float(ctx.f24.f64 / ctx.f9.f64));
	// fmadds f26,f13,f5,f26
	ctx.f26.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f26.f64));
	// fmadds f29,f13,f4,f29
	ctx.f29.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + ctx.f29.f64));
	// fmadds f28,f13,f3,f28
	ctx.f28.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f28.f64));
loc_820D1290:
	// fmuls f13,f8,f8
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x820d12d8
	if (!ctx.cr6.lt) goto loc_820D12D8;
	// fmuls f13,f7,f7
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x820d12d8
	if (!ctx.cr6.lt) goto loc_820D12D8;
	// fmuls f13,f6,f6
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x820d12d8
	if (!ctx.cr6.lt) goto loc_820D12D8;
	// fmuls f13,f5,f5
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x820d12d8
	if (!ctx.cr6.lt) goto loc_820D12D8;
	// fmuls f13,f4,f4
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f4.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x820d12d8
	if (!ctx.cr6.lt) goto loc_820D12D8;
	// fmuls f13,f3,f3
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// blt cr6,0x820d12e4
	if (ctx.cr6.lt) goto loc_820D12E4;
loc_820D12D8:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r7,8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 8, ctx.xer);
	// blt cr6,0x820d1104
	if (ctx.cr6.lt) goto loc_820D1104;
loc_820D12E4:
	// stfs f30,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f1,4(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f31,8(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f26,0(r4)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f29,4(r4)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f28,8(r4)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8208037c
	ctx.lr = 0x820D1304;
	__restfpr_14(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D1308"))) PPC_WEAK_FUNC(sub_820D1308);
PPC_FUNC_IMPL(__imp__sub_820D1308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x820D1310;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080344
	ctx.lr = 0x820D1318;
	__savefpr_19(ctx, base);
	// stwu r1,-1040(r1)
	ea = -1040 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r3,1060(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1060, ctx.r3.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// stw r6,1084(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1084, ctx.r6.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r24,4
	ctx.r24.s64 = 4;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lfs f19,12868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12868);
	ctx.f19.f64 = double(temp.f32);
	// beq cr6,0x820d13a0
	if (ctx.cr6.eq) goto loc_820D13A0;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r4,12
	ctx.r9.s64 = ctx.r4.s64 + 12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D1350:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f19
	ctx.cr6.compare(ctx.f0.f64, ctx.f19.f64);
	// bge cr6,0x820d1360
	if (!ctx.cr6.lt) goto loc_820D1360;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820D1360:
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bdnz 0x820d1350
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1350;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x820d138c
	if (!ctx.cr6.eq) goto loc_820D138C;
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,2(r8)
	PPC_STORE_U16(ctx.r8.u32 + 2, ctx.r11.u16);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// sth r9,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r9.u16);
	// b 0x820d1ce8
	goto loc_820D1CE8;
loc_820D138C:
	// subfic r11,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r10.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r11.u32);
	// b 0x820d13a4
	goto loc_820D13A4;
loc_820D13A0:
	// stw r24,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r24.u32);
loc_820D13A4:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x820d13bc
	if (ctx.cr6.eq) goto loc_820D13BC;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8207da20
	ctx.lr = 0x820D13BC;
	sub_8207DA20(ctx, base);
loc_820D13BC:
	// li r11,16
	ctx.r11.s64 = 16;
	// lwz r16,1084(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1084);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// addi r29,r1,284
	ctx.r29.s64 = ctx.r1.s64 + 284;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// addi r28,r1,312
	ctx.r28.s64 = ctx.r1.s64 + 312;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// subf r10,r31,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r31.s64;
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// std r11,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// addi r6,r1,348
	ctx.r6.s64 = ctx.r1.s64 + 348;
	// stw r10,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r10.u32);
	// addi r18,r1,344
	ctx.r18.s64 = ctx.r1.s64 + 344;
	// lwz r15,224(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// subf r23,r31,r29
	ctx.r23.s64 = ctx.r29.s64 - ctx.r31.s64;
	// subf r29,r31,r28
	ctx.r29.s64 = ctx.r28.s64 - ctx.r31.s64;
	// subf r22,r31,r9
	ctx.r22.s64 = ctx.r9.s64 - ctx.r31.s64;
	// subf r19,r31,r6
	ctx.r19.s64 = ctx.r6.s64 - ctx.r31.s64;
	// subf r28,r31,r18
	ctx.r28.s64 = ctx.r18.s64 - ctx.r31.s64;
	// stw r22,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r22.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r19,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r19.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r18,-32255
	ctx.r18.s64 = -2113863680;
	// addi r4,r1,280
	ctx.r4.s64 = ctx.r1.s64 + 280;
	// addi r8,r1,316
	ctx.r8.s64 = ctx.r1.s64 + 316;
	// addi r27,r1,328
	ctx.r27.s64 = ctx.r1.s64 + 328;
	// lfs f27,13808(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 13808);
	ctx.f27.f64 = double(temp.f32);
	// addi r5,r1,532
	ctx.r5.s64 = ctx.r1.s64 + 532;
	// lfs f20,12888(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12888);
	ctx.f20.f64 = double(temp.f32);
	// addi r17,r1,528
	ctx.r17.s64 = ctx.r1.s64 + 528;
	// lfs f22,-18484(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + -18484);
	ctx.f22.f64 = double(temp.f32);
	// subf r30,r31,r4
	ctx.r30.s64 = ctx.r4.s64 - ctx.r31.s64;
	// subf r21,r31,r8
	ctx.r21.s64 = ctx.r8.s64 - ctx.r31.s64;
	// subf r4,r31,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r31.s64;
	// addi r27,r9,13808
	ctx.r27.s64 = ctx.r9.s64 + 13808;
	// stw r21,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r21.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// subf r3,r31,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r31.s64;
	// subf r8,r31,r17
	ctx.r8.s64 = ctx.r17.s64 - ctx.r31.s64;
	// addi r7,r1,320
	ctx.r7.s64 = ctx.r1.s64 + 320;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lfs f29,8(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// lis r17,-32255
	ctx.r17.s64 = -2113863680;
	// lfs f31,-18456(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -18456);
	ctx.f31.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f28,4(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// ld r11,176(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// lis r18,-32255
	ctx.r18.s64 = -2113863680;
	// lfs f21,-18480(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -18480);
	ctx.f21.f64 = double(temp.f32);
	// subf r20,r31,r7
	ctx.r20.s64 = ctx.r7.s64 - ctx.r31.s64;
	// lfs f23,-4640(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + -4640);
	ctx.f23.f64 = double(temp.f32);
	// addi r26,r1,332
	ctx.r26.s64 = ctx.r1.s64 + 332;
	// lfs f6,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f6.f64 = double(temp.f32);
	// addi r25,r1,336
	ctx.r25.s64 = ctx.r1.s64 + 336;
	// lfs f30,-18452(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -18452);
	ctx.f30.f64 = double(temp.f32);
	// lfs f7,-18460(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + -18460);
	ctx.f7.f64 = double(temp.f32);
	// stw r20,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r20.u32);
	// lfs f8,-18464(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + -18464);
	ctx.f8.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// subf r26,r31,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r31.s64;
	// subf r25,r31,r25
	ctx.r25.s64 = ctx.r25.s64 - ctx.r31.s64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_820D14CC:
	// lfs f13,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// lfs f12,-4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x820d1504
	if (ctx.cr6.eq) goto loc_820D1504;
	// lwz r6,208(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// addi r9,r1,276
	ctx.r9.s64 = ctx.r1.s64 + 276;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfsx f11,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// lfs f11,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// fadds f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
loc_820D1504:
	// fmadds f11,f13,f8,f19
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f19.f64));
	// addi r6,r1,528
	ctx.r6.s64 = ctx.r1.s64 + 528;
	// fmadds f10,f12,f7,f19
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f7.f64 + ctx.f19.f64));
	// addi r5,r1,532
	ctx.r5.s64 = ctx.r1.s64 + 532;
	// fmadds f9,f0,f8,f19
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f8.f64 + ctx.f19.f64));
	// stfsx f6,r3,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r11.u32, temp.u32);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// fctiwz f11,f11
	ctx.f11.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.f11.u64);
	// fctiwz f11,f10
	ctx.f11.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// lwa r9,180(r1)
	ctx.r9.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 180));
	// fctiwz f10,f9
	ctx.f10.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f10,240(r1)
	PPC_STORE_U64(ctx.r1.u32 + 240, ctx.f10.u64);
	// stfd f11,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.f11.u64);
	// std r9,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r9.u64);
	// lwa r17,244(r1)
	ctx.r17.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 244));
	// lfd f10,192(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// std r17,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r17.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwa r18,180(r1)
	ctx.r18.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 180));
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// std r18,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r18.u64);
	// lfd f11,216(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 216);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// mr r18,r17
	ctx.r18.u64 = ctx.r17.u64;
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fmuls f10,f10,f31
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// stfsx f10,r10,r6
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r6.u32, temp.u32);
	// fmuls f11,f11,f30
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// stfsx f11,r10,r5
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r5.u32, temp.u32);
	// fmuls f9,f9,f31
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// stfsx f9,r8,r11
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, temp.u32);
	// beq cr6,0x820d1654
	if (ctx.cr6.eq) goto loc_820D1654;
	// clrlwi r9,r7,30
	ctx.r9.u64 = ctx.r7.u32 & 0x3;
	// fsubs f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// fsubs f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f9.f64));
	// beq cr6,0x820d15d0
	if (ctx.cr6.eq) goto loc_820D15D0;
	// lfsx f5,r30,r11
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r23,r11
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f5,f13,f23,f5
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f23.f64 + ctx.f5.f64));
	// lfsx f3,r22,r11
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f4,f12,f23,f4
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f23.f64 + ctx.f4.f64));
	// fmadds f3,f0,f23,f3
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f23.f64 + ctx.f3.f64));
	// stfsx f5,r30,r11
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, temp.u32);
	// stfsx f4,r23,r11
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r23.u32 + ctx.r11.u32, temp.u32);
	// stfsx f3,r22,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r22.u32 + ctx.r11.u32, temp.u32);
loc_820D15D0:
	// cmplwi cr6,r7,12
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 12, ctx.xer);
	// bge cr6,0x820d1654
	if (!ctx.cr6.lt) goto loc_820D1654;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820d1604
	if (ctx.cr6.eq) goto loc_820D1604;
	// lfsx f5,r29,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r21,r11
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f5,f13,f22,f5
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f22.f64 + ctx.f5.f64));
	// lfsx f3,r20,r11
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f4,f12,f22,f4
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f22.f64 + ctx.f4.f64));
	// fmadds f3,f0,f22,f3
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f22.f64 + ctx.f3.f64));
	// stfsx f5,r29,r11
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r11.u32, temp.u32);
	// stfsx f4,r21,r11
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r21.u32 + ctx.r11.u32, temp.u32);
	// stfsx f3,r20,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r20.u32 + ctx.r11.u32, temp.u32);
loc_820D1604:
	// lfsx f5,r4,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// lfsx f4,r26,r11
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f5,f13,f21,f5
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f21.f64 + ctx.f5.f64));
	// lfsx f3,r25,r11
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f4,f12,f21,f4
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f21.f64 + ctx.f4.f64));
	// fmadds f3,f0,f21,f3
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f21.f64 + ctx.f3.f64));
	// stfsx f5,r4,r11
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r11.u32, temp.u32);
	// stfsx f4,r26,r11
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r26.u32 + ctx.r11.u32, temp.u32);
	// stfsx f3,r25,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r25.u32 + ctx.r11.u32, temp.u32);
	// beq cr6,0x820d1654
	if (ctx.cr6.eq) goto loc_820D1654;
	// lfsx f5,r28,r11
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f13,f20,f5
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f20.f64 + ctx.f5.f64));
	// lfsx f4,r19,r11
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// lfsx f5,r15,r11
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f12,f12,f20,f4
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f20.f64 + ctx.f4.f64));
	// fmadds f0,f0,f20,f5
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f20.f64 + ctx.f5.f64));
	// stfsx f13,r28,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r28.u32 + ctx.r11.u32, temp.u32);
	// stfsx f12,r19,r11
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r19.u32 + ctx.r11.u32, temp.u32);
	// stfsx f0,r15,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r11.u32, temp.u32);
loc_820D1654:
	// fmuls f0,f10,f27
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f27.f64));
	// stfsx f0,r10,r6
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r6.u32, temp.u32);
	// fmuls f0,f11,f28
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f28.f64));
	// stfsx f0,r10,r5
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r5.u32, temp.u32);
	// fmuls f0,f9,f29
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f29.f64));
	// stfsx f0,r8,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, temp.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bdnz 0x820d14cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D14CC;
	// lwz r18,164(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// addi r5,r1,528
	ctx.r5.s64 = ctx.r1.s64 + 528;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x820d0e88
	ctx.lr = 0x820D1694;
	sub_820D0E88(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f11,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,13824
	ctx.r10.s64 = ctx.r11.s64 + 13824;
	// lfs f10,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,13824(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 13824);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f0,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f10,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f9,f9,f12
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f9,88(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f11,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfs f10,244(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f12,200(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// bl 0x820d0ad0
	ctx.lr = 0x820D16F8;
	sub_820D0AD0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820d0ad0
	ctx.lr = 0x820D1704;
	sub_820D0AD0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r18,4
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 4, ctx.xer);
	// bne cr6,0x820d1738
	if (!ctx.cr6.eq) goto loc_820D1738;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820d1738
	if (!ctx.cr6.eq) goto loc_820D1738;
	// lwz r10,1060(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// sth r3,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r3.u16);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// b 0x820d1ce8
	goto loc_820D1CE8;
loc_820D1738:
	// rlwinm r9,r8,21,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 21) & 0x1F;
	// lwz r17,1060(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// clrlwi r10,r11,27
	ctx.r10.u64 = ctx.r11.u32 & 0x1F;
	// std r9,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r9.u64);
	// rlwinm r7,r11,27,26,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x3F;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// rlwinm r10,r11,21,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1F;
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// rlwinm r9,r8,27,26,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x3F;
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// lfd f13,192(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// std r10,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r10.u64);
	// clrlwi r10,r8,27
	ctx.r10.u64 = ctx.r8.u32 & 0x1F;
	// std r9,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r9.u64);
	// lfd f9,216(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 216);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfd f10,192(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// addi r6,r18,-3
	ctx.r6.s64 = ctx.r18.s64 + -3;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// li r5,-1
	ctx.r5.s64 = -1;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// subfc r10,r9,r7
	ctx.xer.ca = ctx.r7.u32 >= ctx.r9.u32;
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// subfze r10,r5
	{ uint8_t _ca = (~ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r10.u64 = ~ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// rlwinm r6,r6,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fmuls f10,f10,f31
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fmuls f7,f0,f31
	ctx.f7.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f11,f11,f31
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fmuls f9,f9,f30
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f30.f64));
	// fmuls f8,f12,f30
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// fmuls f0,f27,f13
	ctx.f0.f64 = double(float(ctx.f27.f64 * ctx.f13.f64));
	// fmuls f12,f11,f29
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f29.f64));
	// fmuls f11,f10,f27
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f27.f64));
	// fmuls f13,f9,f28
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f28.f64));
	// fmuls f10,f8,f28
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f28.f64));
	// fmuls f9,f7,f29
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f29.f64));
	// bne cr6,0x820d1838
	if (!ctx.cr6.eq) goto loc_820D1838;
	// lfs f8,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f8.f64 = double(temp.f32);
	// sth r8,0(r17)
	PPC_STORE_U16(ctx.r17.u32 + 0, ctx.r8.u16);
	// lfs f7,252(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	ctx.f7.f64 = double(temp.f32);
	// sth r11,2(r17)
	PPC_STORE_U16(ctx.r17.u32 + 2, ctx.r11.u16);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// b 0x820d1860
	goto loc_820D1860;
loc_820D1838:
	// lfs f8,252(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	ctx.f8.f64 = double(temp.f32);
	// sth r11,0(r17)
	PPC_STORE_U16(ctx.r17.u32 + 0, ctx.r11.u16);
	// lfs f7,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f7.f64 = double(temp.f32);
	// sth r8,2(r17)
	PPC_STORE_U16(ctx.r17.u32 + 2, ctx.r8.u16);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
loc_820D1860:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f7,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f8,108(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// cmplwi cr6,r18,3
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 3, ctx.xer);
	// lvsl v0,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsl v7,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// bne cr6,0x820d18fc
	if (!ctx.cr6.eq) goto loc_820D18FC;
	// addi r11,r1,111
	ctx.r11.s64 = ctx.r1.s64 + 111;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,127
	ctx.r8.s64 = ctx.r1.s64 + 127;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r5,8
	ctx.r5.s64 = 8;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v0,v62,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-4656
	ctx.r11.s64 = ctx.r11.s64 + -4656;
	// vperm128 v63,v60,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// vsubfp128 v12,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,12
	ctx.r3.s64 = 12;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r28,r11,-4672
	ctx.r28.s64 = ctx.r11.s64 + -4672;
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v63,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stvewx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r6,r24
	ea = (ctx.r6.u32 + ctx.r24.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r10,r5
	ea = (ctx.r10.u32 + ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r4,r3
	ea = (ctx.r4.u32 + ctx.r3.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// b 0x820d1a48
	goto loc_820D1A48;
loc_820D18FC:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r22,160(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r1,111
	ctx.r10.s64 = ctx.r1.s64 + 111;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// std r7,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r7.u64);
	// addi r6,r1,127
	ctx.r6.s64 = ctx.r1.s64 + 127;
	// std r27,240(r1)
	PPC_STORE_U64(ctx.r1.u32 + 240, ctx.r27.u64);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// stw r28,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r28.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v0,v63,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r11,-4688
	ctx.r8.s64 = ctx.r11.s64 + -4688;
	// vperm128 v63,v61,v60,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// std r26,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r26.u64);
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r30,r1,111
	ctx.r30.s64 = ctx.r1.s64 + 111;
	// std r31,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r31.u64);
	// vsubfp128 v12,v63,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lwz r21,168(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// lwz r17,1060(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// addi r14,r1,127
	ctx.r14.s64 = ctx.r1.s64 + 127;
	// lwz r18,164(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// li r11,12
	ctx.r11.s64 = 12;
	// lwz r16,1084(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1084);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r15,224(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r19,260(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r20,256(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// addi r9,r9,-4704
	ctx.r9.s64 = ctx.r9.s64 + -4704;
	// addi r31,r1,112
	ctx.r31.s64 = ctx.r1.s64 + 112;
	// addi r27,r1,144
	ctx.r27.s64 = ctx.r1.s64 + 144;
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// lvsl v6,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lvsl v5,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r31,r1,144
	ctx.r31.s64 = ctx.r1.s64 + 144;
	// lvsr v4,r0,r27
	temp.u32 = ctx.r27.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// addi r27,r1,144
	ctx.r27.s64 = ctx.r1.s64 + 144;
	// addi r28,r11,-4728
	ctx.r28.s64 = ctx.r11.s64 + -4728;
	// vperm128 v63,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stvewx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r5,r24
	ea = (ctx.r5.u32 + ctx.r24.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r8,160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// stvewx128 v63,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lvx128 v61,r0,r14
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,168(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v0,v62,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v61,v60,v61,v5
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vsubfp128 v12,v61,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v63,v0,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stvewx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r7,r24
	ea = (ctx.r7.u32 + ctx.r24.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// ld r31,216(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 216);
	// stvewx128 v63,r27,r8
	ea = (ctx.r27.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r7,192(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// ld r27,240(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + 240);
	// ld r26,176(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
loc_820D1A48:
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f27,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f27.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// fsubs f13,f0,f27
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f27.f64));
	// lfs f26,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f26.f64 = double(temp.f32);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f25,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f25.f64 = double(temp.f32);
	// fsubs f12,f12,f26
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f26.f64));
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f28,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f28.f64 = double(temp.f32);
	// fsubs f11,f11,f25
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f25.f64));
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f24,f0
	ctx.f24.f64 = double(float(ctx.f0.f64));
	// beq cr6,0x820d1aa8
	if (ctx.cr6.eq) goto loc_820D1AA8;
	// fmuls f0,f12,f12
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f0,f11,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f0.f64));
	// fmadds f0,f13,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f0.f64));
	// fdivs f0,f24,f0
	ctx.f0.f64 = double(float(ctx.f24.f64 / ctx.f0.f64));
	// b 0x820d1aac
	goto loc_820D1AAC;
loc_820D1AA8:
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
loc_820D1AAC:
	// fmuls f31,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// li r29,0
	ctx.r29.s64 = 0;
	// fmuls f30,f0,f12
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// fmuls f29,f0,f11
	ctx.f29.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// beq cr6,0x820d1ad4
	if (ctx.cr6.eq) goto loc_820D1AD4;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8207da20
	ctx.lr = 0x820D1AD4;
	sub_8207DA20(ctx, base);
loc_820D1AD4:
	// li r11,16
	ctx.r11.s64 = 16;
	// lfs f10,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,536
	ctx.r7.s64 = ctx.r1.s64 + 536;
	// lfs f9,4(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r4,r1,340
	ctx.r4.s64 = ctx.r1.s64 + 340;
	// lfs f8,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r10,r1,276
	ctx.r10.s64 = ctx.r1.s64 + 276;
	// addi r6,r1,292
	ctx.r6.s64 = ctx.r1.s64 + 292;
	// addi r5,r1,324
	ctx.r5.s64 = ctx.r1.s64 + 324;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r24,r1,356
	ctx.r24.s64 = ctx.r1.s64 + 356;
	// subf r3,r31,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r31.s64;
	// subf r7,r31,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r31.s64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// subf r30,r31,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r31.s64;
	// subf r6,r31,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r31.s64;
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r31.s64;
	// subf r4,r31,r24
	ctx.r4.s64 = ctx.r24.s64 - ctx.r31.s64;
loc_820D1B24:
	// cmplwi cr6,r18,3
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 3, ctx.xer);
	// bne cr6,0x820d1b44
	if (!ctx.cr6.eq) goto loc_820D1B44;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f19
	ctx.cr6.compare(ctx.f0.f64, ctx.f19.f64);
	// bge cr6,0x820d1b44
	if (!ctx.cr6.lt) goto loc_820D1B44;
	// rlwinm r10,r29,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 30) & 0x3FFFFFFF;
	// oris r29,r10,49152
	ctx.r29.u64 = ctx.r10.u64 | 3221225472;
	// b 0x820d1cd0
	goto loc_820D1CD0;
loc_820D1B44:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// fmuls f13,f0,f8
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f12,f9
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fmuls f11,f0,f10
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// beq cr6,0x820d1b80
	if (ctx.cr6.eq) goto loc_820D1B80;
	// lwz r10,208(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lfs f0,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfsx f7,r30,r11
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fadds f11,f7,f11
	ctx.f11.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// lfsx f0,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
loc_820D1B80:
	// fsubs f0,f12,f26
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f26.f64));
	// fsubs f7,f11,f25
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f25.f64));
	// fsubs f6,f13,f27
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f27.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmadds f0,f7,f29,f0
	ctx.f0.f64 = double(float(ctx.f7.f64 * ctx.f29.f64 + ctx.f0.f64));
	// fmadds f0,f6,f31,f0
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f31.f64 + ctx.f0.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bgt cr6,0x820d1ba8
	if (ctx.cr6.gt) goto loc_820D1BA8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x820d1bd0
	goto loc_820D1BD0;
loc_820D1BA8:
	// fcmpu cr6,f0,f24
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f24.f64);
	// blt cr6,0x820d1bb8
	if (ctx.cr6.lt) goto loc_820D1BB8;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x820d1bd0
	goto loc_820D1BD0;
loc_820D1BB8:
	// fadds f0,f0,f19
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f19.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
loc_820D1BD0:
	// rlwinm r31,r10,30,0,1
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0xC0000000;
	// rlwinm r29,r29,30,2,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 30) & 0x3FFFFFFF;
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// or r29,r31,r29
	ctx.r29.u64 = ctx.r31.u64 | ctx.r29.u64;
	// beq cr6,0x820d1cd0
	if (ctx.cr6.eq) goto loc_820D1CD0;
	// rlwinm r31,r10,4,0,27
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f7,r3,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// addi r24,r1,100
	ctx.r24.s64 = ctx.r1.s64 + 100;
	// addi r14,r1,104
	ctx.r14.s64 = ctx.r1.s64 + 104;
	// clrlwi r10,r9,30
	ctx.r10.u64 = ctx.r9.u32 & 0x3;
	// lfsx f0,r31,r27
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// lfsx f6,r31,r24
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfsx f13,r31,r14
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r14.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f6
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fmuls f0,f0,f7
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f7.f64));
	// fmuls f13,f12,f7
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f7.f64));
	// fmuls f12,f11,f7
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// beq cr6,0x820d1c4c
	if (ctx.cr6.eq) goto loc_820D1C4C;
	// lfsx f11,r23,r11
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f7,r22,r11
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f11,f0,f23,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f23.f64 + ctx.f11.f64));
	// lfsx f6,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f7,f13,f23,f7
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f23.f64 + ctx.f7.f64));
	// fmadds f6,f12,f23,f6
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f23.f64 + ctx.f6.f64));
	// stfsx f11,r23,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r23.u32 + ctx.r11.u32, temp.u32);
	// stfsx f7,r22,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r22.u32 + ctx.r11.u32, temp.u32);
	// stfsx f6,r6,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r11.u32, temp.u32);
loc_820D1C4C:
	// cmplwi cr6,r9,12
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 12, ctx.xer);
	// bge cr6,0x820d1cd0
	if (!ctx.cr6.lt) goto loc_820D1CD0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d1c80
	if (ctx.cr6.eq) goto loc_820D1C80;
	// lfsx f11,r21,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f7,r20,r11
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f11,f0,f22,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f22.f64 + ctx.f11.f64));
	// lfsx f6,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f7,f13,f22,f7
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f22.f64 + ctx.f7.f64));
	// fmadds f6,f12,f22,f6
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f22.f64 + ctx.f6.f64));
	// stfsx f11,r21,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r21.u32 + ctx.r11.u32, temp.u32);
	// stfsx f7,r20,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r20.u32 + ctx.r11.u32, temp.u32);
	// stfsx f6,r5,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r11.u32, temp.u32);
loc_820D1C80:
	// lfsx f11,r26,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// lfsx f7,r25,r11
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f11,f0,f21,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f21.f64 + ctx.f11.f64));
	// lfsx f6,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f7,f13,f21,f7
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f21.f64 + ctx.f7.f64));
	// fmadds f6,f12,f21,f6
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f21.f64 + ctx.f6.f64));
	// stfsx f11,r26,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r26.u32 + ctx.r11.u32, temp.u32);
	// stfsx f7,r25,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r25.u32 + ctx.r11.u32, temp.u32);
	// stfsx f6,r7,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, temp.u32);
	// beq cr6,0x820d1cd0
	if (ctx.cr6.eq) goto loc_820D1CD0;
	// lfsx f11,r19,r11
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f0,f0,f20,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f20.f64 + ctx.f11.f64));
	// lfsx f7,r15,r11
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f11,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f13,f20,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f20.f64 + ctx.f7.f64));
	// fmadds f12,f12,f20,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f20.f64 + ctx.f11.f64));
	// stfsx f0,r19,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r19.u32 + ctx.r11.u32, temp.u32);
	// stfsx f13,r15,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r11.u32, temp.u32);
	// stfsx f12,r4,r11
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r11.u32, temp.u32);
loc_820D1CD0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bdnz 0x820d1b24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1B24;
	// rotlwi r11,r29,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r29.u32, 16);
	// stw r11,4(r17)
	PPC_STORE_U32(ctx.r17.u32 + 4, ctx.r11.u32);
loc_820D1CE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1040
	ctx.r1.s64 = ctx.r1.s64 + 1040;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080390
	ctx.lr = 0x820D1CF8;
	__restfpr_19(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D1CFC"))) PPC_WEAK_FUNC(sub_820D1CFC);
PPC_FUNC_IMPL(__imp__sub_820D1CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D1D00"))) PPC_WEAK_FUNC(sub_820D1D00);
PPC_FUNC_IMPL(__imp__sub_820D1D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820D1D08;
	__savegprlr_23(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lhz r9,2(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 2);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// rlwinm r6,r9,21,11,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x1FFFFF;
	// rlwinm r7,r11,21,11,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1FFFFF;
	// clrlwi r31,r9,27
	ctx.r31.u64 = ctx.r9.u32 & 0x1F;
	// lfs f12,-18452(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18452);
	ctx.f12.f64 = double(temp.f32);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// lfs f0,-18456(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18456);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r10,r11,27,26,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x3F;
	// std r8,-176(r1)
	PPC_STORE_U64(ctx.r1.u32 + -176, ctx.r8.u64);
	// lfd f11,-176(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// std r10,-176(r1)
	PPC_STORE_U64(ctx.r1.u32 + -176, ctx.r10.u64);
	// clrlwi r10,r11,27
	ctx.r10.u64 = ctx.r11.u32 & 0x1F;
	// std r7,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, ctx.r7.u64);
	// lfd f8,-152(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// std r10,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, ctx.r10.u64);
	// lfd f7,-152(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f13,-176(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// std r31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, ctx.r31.u64);
	// lfd f9,-160(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// rlwinm r5,r9,27,26,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x3F;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// addi r7,r1,-144
	ctx.r7.s64 = ctx.r1.s64 + -144;
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// std r6,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, ctx.r6.u64);
	// lfd f10,-168(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// addi r6,r1,-128
	ctx.r6.s64 = ctx.r1.s64 + -128;
	// lfs f13,14004(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14004);
	ctx.f13.f64 = double(temp.f32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stfs f13,-132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -132, temp.u32);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// stfs f13,-116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -116, temp.u32);
	// fcfid f13,f10
	ctx.f13.f64 = double(ctx.f10.s64);
	// fcfid f10,f9
	ctx.f10.f64 = double(ctx.f9.s64);
	// lvsl v7,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// frsp f9,f7
	ctx.f9.f64 = double(float(ctx.f7.f64));
	// lvsl v0,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// frsp f7,f6
	ctx.f7.f64 = double(float(ctx.f6.f64));
	// addi r6,r1,-112
	ctx.r6.s64 = ctx.r1.s64 + -112;
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f11,-128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -128, temp.u32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fmuls f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f9,-136(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -136, temp.u32);
	// fmuls f9,f7,f12
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f9,-140(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -140, temp.u32);
	// fmuls f9,f8,f0
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f9,-144(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -144, temp.u32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f13,-124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -124, temp.u32);
	// fmuls f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f0,-120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -120, temp.u32);
	// bgt cr6,0x820d1e90
	if (ctx.cr6.gt) goto loc_820D1E90;
	// addi r11,r1,-129
	ctx.r11.s64 = ctx.r1.s64 + -129;
	// addi r10,r1,-144
	ctx.r10.s64 = ctx.r1.s64 + -144;
	// addi r9,r1,-113
	ctx.r9.s64 = ctx.r1.s64 + -113;
	// addi r8,r1,-128
	ctx.r8.s64 = ctx.r1.s64 + -128;
	// li r7,8
	ctx.r7.s64 = 8;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-112
	ctx.r10.s64 = ctx.r1.s64 + -112;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v0,v62,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-4656
	ctx.r11.s64 = ctx.r11.s64 + -4656;
	// vperm128 v63,v60,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// li r10,4
	ctx.r10.s64 = 4;
	// li r5,12
	ctx.r5.s64 = 12;
	// vsubfp128 v12,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-112
	ctx.r11.s64 = ctx.r1.s64 + -112;
	// lis r31,-32256
	ctx.r31.s64 = -2113929216;
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v63,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stvewx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r6,r5
	ea = (ctx.r6.u32 + ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f0,9388(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f0,-92(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// stfs f0,-88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// stfs f0,-84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// b 0x820d1f78
	goto loc_820D1F78;
loc_820D1E90:
	// addi r11,r1,-144
	ctx.r11.s64 = ctx.r1.s64 + -144;
	// addi r10,r1,-129
	ctx.r10.s64 = ctx.r1.s64 + -129;
	// addi r9,r1,-128
	ctx.r9.s64 = ctx.r1.s64 + -128;
	// addi r8,r1,-113
	ctx.r8.s64 = ctx.r1.s64 + -113;
	// addi r7,r1,-112
	ctx.r7.s64 = ctx.r1.s64 + -112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-112
	ctx.r10.s64 = ctx.r1.s64 + -112;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v0,v63,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-4688
	ctx.r11.s64 = ctx.r11.s64 + -4688;
	// vperm128 v63,v61,v60,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// li r9,4
	ctx.r9.s64 = 4;
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r5,r1,-112
	ctx.r5.s64 = ctx.r1.s64 + -112;
	// vsubfp128 v12,v63,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,12
	ctx.r11.s64 = 12;
	// addi r29,r1,-113
	ctx.r29.s64 = ctx.r1.s64 + -113;
	// addi r28,r1,-128
	ctx.r28.s64 = ctx.r1.s64 + -128;
	// addi r31,r1,-129
	ctx.r31.s64 = ctx.r1.s64 + -129;
	// addi r30,r1,-144
	ctx.r30.s64 = ctx.r1.s64 + -144;
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// addi r26,r1,-144
	ctx.r26.s64 = ctx.r1.s64 + -144;
	// addi r27,r27,-4704
	ctx.r27.s64 = ctx.r27.s64 + -4704;
	// addi r25,r1,-128
	ctx.r25.s64 = ctx.r1.s64 + -128;
	// addi r24,r1,-96
	ctx.r24.s64 = ctx.r1.s64 + -96;
	// addi r23,r1,-96
	ctx.r23.s64 = ctx.r1.s64 + -96;
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lvsl v6,r0,r26
	temp.u32 = ctx.r26.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r26,r1,-96
	ctx.r26.s64 = ctx.r1.s64 + -96;
	// lvsl v5,r0,r25
	temp.u32 = ctx.r25.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r25,r1,-96
	ctx.r25.s64 = ctx.r1.s64 + -96;
	// lvsr v4,r0,r24
	temp.u32 = ctx.r24.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// addi r24,r1,-96
	ctx.r24.s64 = ctx.r1.s64 + -96;
	// vperm128 v63,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stvewx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r7,r9
	ea = (ctx.r7.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v0,v62,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v61,v60,v61,v5
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vsubfp128 v12,v61,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v63,v0,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stvewx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r26,r9
	ea = (ctx.r26.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r25,r10
	ea = (ctx.r25.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r24,r11
	ea = (ctx.r24.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v63.u32[3 - ((ea & 0xF) >> 2)]);
loc_820D1F78:
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// rotlwi r9,r9,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D1F8C:
	// rlwinm r8,r9,4,26,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0x30;
	// addi r10,r1,-144
	ctx.r10.s64 = ctx.r1.s64 + -144;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfsu f11,16(r11)
	temp.f32 = float(ctx.f11.f64);
	ea = 16 + ctx.r11.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x820d1f8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1F8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D1FC8"))) PPC_WEAK_FUNC(sub_820D1FC8);
PPC_FUNC_IMPL(__imp__sub_820D1FC8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r4,8
	ctx.r4.s64 = ctx.r4.s64 + 8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820d1d00
	ctx.lr = 0x820D1FEC;
	sub_820D1D00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820d2070
	if (ctx.cr0.lt) goto loc_820D2070;
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r9,r31,-4
	ctx.r9.s64 = ctx.r31.s64 + -4;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,-18448(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18448);
	ctx.f0.f64 = double(temp.f32);
loc_820D2010:
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,16(r9)
	temp.f32 = float(ctx.f13.f64);
	ea = 16 + ctx.r9.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x820d2010
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2010;
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r9,r31,124
	ctx.r9.s64 = ctx.r31.s64 + 124;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D2048:
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,16(r9)
	temp.f32 = float(ctx.f13.f64);
	ea = 16 + ctx.r9.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x820d2048
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2048;
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D2070:
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

__attribute__((alias("__imp__sub_820D2088"))) PPC_WEAK_FUNC(sub_820D2088);
PPC_FUNC_IMPL(__imp__sub_820D2088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D2090;
	__savegprlr_29(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// rlwinm r7,r10,8,16,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r6,6(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// rlwinm r5,r9,8,16,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF00;
	// ld r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// rlwinm r9,r9,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r30,r8,8,16,23
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00;
	// rlwinm r29,r6,8,16,23
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00;
	// rlwinm r8,r8,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r6,r6,24,8,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFFFFFF;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// or r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 | ctx.r10.u64;
	// or r10,r5,r9
	ctx.r10.u64 = ctx.r5.u64 | ctx.r9.u64;
	// sth r11,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r11.u16);
	// or r9,r30,r8
	ctx.r9.u64 = ctx.r30.u64 | ctx.r8.u64;
	// or r11,r29,r6
	ctx.r11.u64 = ctx.r29.u64 | ctx.r6.u64;
	// sth r10,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r10.u16);
	// sth r9,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r9.u16);
	// sth r11,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r11.u16);
	// bl 0x820d1d00
	ctx.lr = 0x820D20FC;
	sub_820D1D00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820d22ac
	if (ctx.cr0.lt) goto loc_820D22AC;
	// lbz r11,97(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfs f0,12872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12872);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ble cr6,0x820d21bc
	if (!ctx.cr6.gt) goto loc_820D21BC;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-18444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18444);
	ctx.f0.f64 = double(temp.f32);
loc_820D216C:
	// subfic r9,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r9.s64 = 7 - ctx.r11.s64;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// frsp f11,f10
	ctx.f11.f64 = double(float(ctx.f10.f64));
	// fmadds f13,f11,f12,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820d216c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D216C;
	// b 0x820d2230
	goto loc_820D2230;
loc_820D21BC:
	// li r9,4
	ctx.r9.s64 = 4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,9376(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9376);
	ctx.f0.f64 = double(temp.f32);
loc_820D21CC:
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// subfic r9,r11,5
	ctx.xer.ca = ctx.r11.u32 <= 5;
	ctx.r9.s64 = 5 - ctx.r11.s64;
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmadds f13,f10,f12,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820d21cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D21CC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_820D2230:
	// lbz r8,99(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 99);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 100);
	// addi r9,r31,-4
	ctx.r9.s64 = ctx.r31.s64 + -4;
	// lbz r11,98(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 98);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// rlwimi r11,r8,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
loc_820D2254:
	// rlwinm r10,r11,2,27,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1C;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// lfsx f0,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsu f0,16(r9)
	temp.f32 = float(ctx.f0.f64);
	ea = 16 + ctx.r9.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x820d2254
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2254;
	// lbz r8,102(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 102);
	// li r10,8
	ctx.r10.s64 = 8;
	// lbz r7,103(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// addi r9,r31,124
	ctx.r9.s64 = ctx.r31.s64 + 124;
	// lbz r11,101(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 101);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// rlwimi r11,r8,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
loc_820D2290:
	// rlwinm r10,r11,2,27,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1C;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// lfsx f0,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsu f0,16(r9)
	temp.f32 = float(ctx.f0.f64);
	ea = 16 + ctx.r9.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x820d2290
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2290;
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D22AC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D22B4"))) PPC_WEAK_FUNC(sub_820D22B4);
PPC_FUNC_IMPL(__imp__sub_820D22B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D22B8"))) PPC_WEAK_FUNC(sub_820D22B8);
PPC_FUNC_IMPL(__imp__sub_820D22B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D22C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820d23e8
	if (ctx.cr6.eq) goto loc_820D23E8;
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D22E0:
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x820d22e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D22E0;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r11,r4,12
	ctx.r11.s64 = ctx.r4.s64 + 12;
	// subf r4,r4,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r4.s64;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r31,-32255
	ctx.r31.s64 = -2113863680;
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
	// lfs f10,-18480(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -18480);
	ctx.f10.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f9,12888(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12888);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// lfs f11,-18484(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + -18484);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// lfs f12,-4640(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -4640);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,12868(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 12868);
	ctx.f13.f64 = double(temp.f32);
loc_820D2330:
	// lfs f8,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// lfs f0,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f8.f64));
	// lfs f8,-12(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,-4(r9)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// lfs f7,-8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// stfs f7,0(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f6,4(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f8,f0,f13
	ctx.f8.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fctiwz f8,f8
	ctx.f8.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f8.u64);
	// lwa r5,92(r1)
	ctx.r5.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 92));
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// stfsx f8,r4,r11
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r11.u32, temp.u32);
	// fsubs f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// beq cr6,0x820d2394
	if (ctx.cr6.eq) goto loc_820D2394;
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f8,f0,f12,f8
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f8,0(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_820D2394:
	// cmplwi cr6,r8,12
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 12, ctx.xer);
	// bge cr6,0x820d23d0
	if (!ctx.cr6.lt) goto loc_820D23D0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820d23b0
	if (ctx.cr6.eq) goto loc_820D23B0;
	// lfs f8,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f8,f0,f11,f8
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f11.f64 + ctx.f8.f64));
	// stfs f8,8(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
loc_820D23B0:
	// lfs f8,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// fmadds f8,f0,f10,f8
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f8,12(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// beq cr6,0x820d23d0
	if (ctx.cr6.eq) goto loc_820D23D0;
	// lfs f8,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f0,f0,f9,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64 + ctx.f8.f64));
	// stfs f0,16(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
loc_820D23D0:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820d2330
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2330;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
loc_820D23E8:
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x820d1308
	ctx.lr = 0x820D23F0;
	sub_820D1308(ctx, base);
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2400"))) PPC_WEAK_FUNC(sub_820D2400);
PPC_FUNC_IMPL(__imp__sub_820D2400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D2408;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// beq cr6,0x820d243c
	if (ctx.cr6.eq) goto loc_820D243C;
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D2434:
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x820d2434
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2434;
loc_820D243C:
	// li r11,16
	ctx.r11.s64 = 16;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r31,-32255
	ctx.r31.s64 = -2113863680;
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
	// lfs f8,-18480(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18480);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,-18484(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -18484);
	ctx.f9.f64 = double(temp.f32);
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// lfs f10,-4640(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + -4640);
	ctx.f10.f64 = double(temp.f32);
	// addi r3,r4,12
	ctx.r3.s64 = ctx.r4.s64 + 12;
	// lfs f11,-18448(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -18448);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,12888(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12888);
	ctx.f7.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,12868(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 12868);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,23048(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23048);
	ctx.f13.f64 = double(temp.f32);
loc_820D2484:
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x820d2498
	if (ctx.cr6.eq) goto loc_820D2498;
	// lfs f6,-4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// fadds f0,f6,f0
	ctx.f0.f64 = double(float(ctx.f6.f64 + ctx.f0.f64));
loc_820D2498:
	// fmadds f6,f0,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// rlwinm r11,r9,31,1,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFC;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// rlwinm r5,r10,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// fctiwz f6,f6
	ctx.f6.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r31,r10,28,0,3
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xF0000000;
	// or r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 | ctx.r31.u64;
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// beq cr6,0x820d2534
	if (ctx.cr6.eq) goto loc_820D2534;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// clrlwi r11,r9,30
	ctx.r11.u64 = ctx.r9.u32 & 0x3;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f6,88(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f6
	ctx.f6.f64 = double(ctx.f6.s64);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// frsp f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64));
	// fnmsubs f0,f6,f11,f0
	ctx.f0.f64 = double(float(-(ctx.f6.f64 * ctx.f11.f64 - ctx.f0.f64)));
	// beq cr6,0x820d24f8
	if (ctx.cr6.eq) goto loc_820D24F8;
	// lfs f6,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f6,f0,f10,f6
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f6,0(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
loc_820D24F8:
	// cmplwi cr6,r9,12
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 12, ctx.xer);
	// bge cr6,0x820d2534
	if (!ctx.cr6.lt) goto loc_820D2534;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d2514
	if (ctx.cr6.eq) goto loc_820D2514;
	// lfs f6,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f6,f0,f9,f6
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f9.f64 + ctx.f6.f64));
	// stfs f6,8(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8, temp.u32);
loc_820D2514:
	// lfs f6,12(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// fmadds f6,f0,f8,f6
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f8.f64 + ctx.f6.f64));
	// stfs f6,12(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// beq cr6,0x820d2534
	if (ctx.cr6.eq) goto loc_820D2534;
	// lfs f6,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f0,f0,f7,f6
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f7.f64 + ctx.f6.f64));
	// stfs f0,16(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
loc_820D2534:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x820d2484
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2484;
	// lwz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r7,8
	ctx.r3.s64 = ctx.r7.s64 + 8;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
	// bl 0x820d1308
	ctx.lr = 0x820D2568;
	sub_820D1308(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2570"))) PPC_WEAK_FUNC(sub_820D2570);
PPC_FUNC_IMPL(__imp__sub_820D2570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D2578;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8208034c
	ctx.lr = 0x820D2580;
	__savefpr_21(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f29,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f29.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// fmr f28,f29
	ctx.f28.f64 = ctx.f29.f64;
	// addi r30,r4,12
	ctx.r30.s64 = ctx.r4.s64 + 12;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820d25b8
	if (ctx.cr6.eq) goto loc_820D25B8;
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D25B0:
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x820d25b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D25B0;
loc_820D25B8:
	// li r10,16
	ctx.r10.s64 = 16;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
	// lfs f22,-18480(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18480);
	ctx.f22.f64 = double(temp.f32);
	// lfs f23,-18484(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -18484);
	ctx.f23.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f24,-4640(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4640);
	ctx.f24.f64 = double(temp.f32);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lfs f30,12872(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12872);
	ctx.f30.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f21,12888(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12888);
	ctx.f21.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f27,12868(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 12868);
	ctx.f27.f64 = double(temp.f32);
	// lfs f31,12876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12876);
	ctx.f31.f64 = double(temp.f32);
loc_820D2604:
	// lfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x820d261c
	if (ctx.cr6.eq) goto loc_820D261C;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfsx f0,r11,r10
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_820D261C:
	// fmadds f0,f13,f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f31.f64 + ctx.f27.f64));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwa r9,92(r1)
	ctx.r9.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 92));
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfsx f0,r11,r10
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x820d2658
	if (!ctx.cr6.lt) goto loc_820D2658;
	// fmr f29,f0
	ctx.f29.f64 = ctx.f0.f64;
	// b 0x820d2664
	goto loc_820D2664;
loc_820D2658:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x820d2664
	if (!ctx.cr6.gt) goto loc_820D2664;
	// fmr f28,f0
	ctx.f28.f64 = ctx.f0.f64;
loc_820D2664:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x820d26d4
	if (ctx.cr6.eq) goto loc_820D26D4;
	// clrlwi r9,r8,30
	ctx.r9.u64 = ctx.r8.u32 & 0x3;
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// beq cr6,0x820d268c
	if (ctx.cr6.eq) goto loc_820D268C;
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// lfsx f13,r11,r10
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f0,f24,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f24.f64 + ctx.f13.f64));
	// stfsx f13,r11,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
loc_820D268C:
	// cmplwi cr6,r8,12
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 12, ctx.xer);
	// bge cr6,0x820d26d4
	if (!ctx.cr6.lt) goto loc_820D26D4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820d26ac
	if (ctx.cr6.eq) goto loc_820D26AC;
	// addi r10,r1,172
	ctx.r10.s64 = ctx.r1.s64 + 172;
	// lfsx f13,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f0,f23,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f23.f64 + ctx.f13.f64));
	// stfsx f13,r11,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
loc_820D26AC:
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// lfsx f13,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f0,f22,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f22.f64 + ctx.f13.f64));
	// stfsx f13,r11,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
	// beq cr6,0x820d26d4
	if (ctx.cr6.eq) goto loc_820D26D4;
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// lfsx f13,r11,r10
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f21,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f21.f64 + ctx.f13.f64));
	// stfsx f0,r11,r10
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
loc_820D26D4:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820d2604
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2604;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x820d1308
	ctx.lr = 0x820D26F4;
	sub_820D1308(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820d2b18
	if (ctx.cr0.lt) goto loc_820D2B18;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f25,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f25.f64 = double(temp.f32);
	// fcmpu cr6,f29,f25
	ctx.cr6.compare(ctx.f29.f64, ctx.f25.f64);
	// bne cr6,0x820d272c
	if (!ctx.cr6.eq) goto loc_820D272C;
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r11.u8);
loc_820D2714:
	// addi r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 2;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8207da20
	ctx.lr = 0x820D2728;
	sub_8207DA20(ctx, base);
	// b 0x820d2b14
	goto loc_820D2B14;
loc_820D272C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f26,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f26.f64 = double(temp.f32);
	// fcmpu cr6,f29,f26
	ctx.cr6.compare(ctx.f29.f64, ctx.f26.f64);
	// beq cr6,0x820d2748
	if (ctx.cr6.eq) goto loc_820D2748;
	// fcmpu cr6,f28,f25
	ctx.cr6.compare(ctx.f28.f64, ctx.f25.f64);
	// li r6,8
	ctx.r6.s64 = 8;
	// bne cr6,0x820d274c
	if (!ctx.cr6.eq) goto loc_820D274C;
loc_820D2748:
	// li r6,6
	ctx.r6.s64 = 6;
loc_820D274C:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820d0bb0
	ctx.lr = 0x820D275C;
	sub_820D0BB0(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f31,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f27.f64));
	// fmadds f13,f13,f31,f27
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64 + ctx.f27.f64));
	// cmplwi cr6,r6,8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 8, ctx.xer);
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f0,f13
	ctx.f0.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// bne cr6,0x820d27d4
	if (!ctx.cr6.eq) goto loc_820D27D4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820d2864
	if (!ctx.cr6.eq) goto loc_820D2864;
	// stb r10,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r10.u8);
	// b 0x820d2714
	goto loc_820D2714;
loc_820D27D4:
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d2864
	if (!ctx.cr6.eq) goto loc_820D2864;
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stb r10,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r10.u8);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,9376(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9376);
	ctx.f0.f64 = double(temp.f32);
loc_820D2804:
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// subfic r9,r11,5
	ctx.xer.ca = ctx.r11.u32 <= 5;
	ctx.r9.s64 = 5 - ctx.r11.s64;
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmadds f13,f10,f12,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820d2804
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2804;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stfs f26,120(r1)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f25,124(r1)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r29,r11,-4604
	ctx.r29.s64 = ctx.r11.s64 + -4604;
	// b 0x820d28e0
	goto loc_820D28E0;
loc_820D2864:
	// li r9,6
	ctx.r9.s64 = 6;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stb r10,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r11,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r11.u8);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-18444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18444);
	ctx.f0.f64 = double(temp.f32);
loc_820D288C:
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// clrldi r9,r8,32
	ctx.r9.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmadds f13,f11,f12,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820d288c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D288C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r29,r11,-4636
	ctx.r29.s64 = ctx.r11.s64 + -4636;
loc_820D28E0:
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// fcmpu cr6,f12,f10
	ctx.cr6.compare(ctx.f12.f64, ctx.f10.f64);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f9,f0
	ctx.f9.f64 = double(float(ctx.f0.f64));
	// beq cr6,0x820d2914
	if (ctx.cr6.eq) goto loc_820D2914;
	// fsubs f0,f10,f12
	ctx.f0.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fdivs f11,f9,f0
	ctx.f11.f64 = double(float(ctx.f9.f64 / ctx.f0.f64));
	// b 0x820d2918
	goto loc_820D2918;
loc_820D2914:
	// fmr f11,f26
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f26.f64;
loc_820D2918:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x820d2938
	if (ctx.cr6.eq) goto loc_820D2938;
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D2930:
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x820d2930
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2930;
loc_820D2938:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 1;
	// addi r7,r1,164
	ctx.r7.s64 = ctx.r1.s64 + 164;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
loc_820D2948:
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820d2a8c
	if (!ctx.cr6.lt) goto loc_820D2A8C;
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D2970:
	// lfs f13,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x820d2984
	if (ctx.cr6.eq) goto loc_820D2984;
	// lfs f0,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_820D2984:
	// fsubs f0,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f26
	ctx.cr6.compare(ctx.f0.f64, ctx.f26.f64);
	// bgt cr6,0x820d29b8
	if (ctx.cr6.gt) goto loc_820D29B8;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d29b0
	if (!ctx.cr6.eq) goto loc_820D29B0;
	// fmuls f0,f12,f27
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f27.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x820d29b0
	if (ctx.cr6.gt) goto loc_820D29B0;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x820d2a00
	goto loc_820D2A00;
loc_820D29B0:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820d2a00
	goto loc_820D2A00;
loc_820D29B8:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// blt cr6,0x820d29e8
	if (ctx.cr6.lt) goto loc_820D29E8;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// bne cr6,0x820d29e0
	if (!ctx.cr6.eq) goto loc_820D29E0;
	// fadds f0,f10,f25
	ctx.f0.f64 = double(float(ctx.f10.f64 + ctx.f25.f64));
	// fmuls f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x820d29e0
	if (ctx.cr6.lt) goto loc_820D29E0;
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x820d2a00
	goto loc_820D2A00;
loc_820D29E0:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820d2a00
	goto loc_820D2A00;
loc_820D29E8:
	// fadds f0,f0,f27
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
loc_820D2A00:
	// rlwinm r30,r30,29,3,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r27,r11,21,0,10
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0xFFE00000;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// or r30,r27,r30
	ctx.r30.u64 = ctx.r27.u64 | ctx.r30.u64;
	// beq cr6,0x820d2a78
	if (ctx.cr6.eq) goto loc_820D2A78;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r26,r1,96
	ctx.r26.s64 = ctx.r1.s64 + 96;
	// clrlwi r11,r3,30
	ctx.r11.u64 = ctx.r3.u32 & 0x3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// lfsx f0,r27,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r26.u32);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// beq cr6,0x820d2a3c
	if (ctx.cr6.eq) goto loc_820D2A3C;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f0,f24,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f24.f64 + ctx.f13.f64));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_820D2A3C:
	// cmplwi cr6,r3,12
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 12, ctx.xer);
	// bge cr6,0x820d2a78
	if (!ctx.cr6.lt) goto loc_820D2A78;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d2a58
	if (ctx.cr6.eq) goto loc_820D2A58;
	// lfs f13,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f0,f23,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f23.f64 + ctx.f13.f64));
	// stfs f13,8(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
loc_820D2A58:
	// lfs f13,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// fmadds f13,f0,f22,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f22.f64 + ctx.f13.f64));
	// stfs f13,12(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// beq cr6,0x820d2a78
	if (ctx.cr6.eq) goto loc_820D2A78;
	// lfs f13,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f21,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f21.f64 + ctx.f13.f64));
	// stfs f0,16(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
loc_820D2A78:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820d2970
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2970;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
loc_820D2A8C:
	// lbz r10,83(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lbz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// lbz r3,81(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// addi r5,r5,128
	ctx.r5.s64 = ctx.r5.s64 + 128;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// stb r10,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r10.u8);
	// stb r8,2(r4)
	PPC_STORE_U8(ctx.r4.u32 + 2, ctx.r8.u8);
	// stbu r3,3(r4)
	ea = 3 + ctx.r4.u32;
	PPC_STORE_U8(ea, ctx.r3.u8);
	ctx.r4.u32 = ea;
	// blt cr6,0x820d2948
	if (ctx.cr6.lt) goto loc_820D2948;
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// addi r11,r31,2
	ctx.r11.s64 = ctx.r31.s64 + 2;
	// rlwinm r10,r9,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF00;
	// rlwinm r9,r9,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// addi r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 6;
	// or r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 | ctx.r9.u64;
	// sth r11,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r11.u16);
	// lhz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2);
	// rlwinm r10,r11,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r11,r11,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// sth r11,2(r31)
	PPC_STORE_U16(ctx.r31.u32 + 2, ctx.r11.u16);
	// lhz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
	// rlwinm r10,r11,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r11,r11,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
	// lhz r11,6(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 6);
	// rlwinm r10,r11,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// rlwinm r11,r11,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// sth r11,6(r31)
	PPC_STORE_U16(ctx.r31.u32 + 6, ctx.r11.u16);
loc_820D2B14:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D2B18:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82080398
	ctx.lr = 0x820D2B24;
	__restfpr_21(ctx, base);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2B28"))) PPC_WEAK_FUNC(sub_820D2B28);
PPC_FUNC_IMPL(__imp__sub_820D2B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r10,r4,12
	ctx.r10.s64 = ctx.r4.s64 + 12;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// subf r8,r8,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r8.s64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820D2B4C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f11,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f11,f0,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f13,-8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x820d2b4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2B4C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820d2400
	ctx.lr = 0x820D2B8C;
	sub_820D2400(ctx, base);
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D2BA4"))) PPC_WEAK_FUNC(sub_820D2BA4);
PPC_FUNC_IMPL(__imp__sub_820D2BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2BA8"))) PPC_WEAK_FUNC(sub_820D2BA8);
PPC_FUNC_IMPL(__imp__sub_820D2BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r10,r4,12
	ctx.r10.s64 = ctx.r4.s64 + 12;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// subf r8,r8,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r8.s64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820D2BCC:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f11,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f11,f0,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f13,-8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x820d2bcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2BCC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820d2570
	ctx.lr = 0x820D2C0C;
	sub_820D2570(ctx, base);
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D2C24"))) PPC_WEAK_FUNC(sub_820D2C24);
PPC_FUNC_IMPL(__imp__sub_820D2C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2C28"))) PPC_WEAK_FUNC(sub_820D2C28);
PPC_FUNC_IMPL(__imp__sub_820D2C28) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,11816(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11816);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d2c6c
	if (ctx.cr6.eq) goto loc_820D2C6C;
	// bl 0x820d1fc8
	ctx.lr = 0x820D2C50;
	sub_820D1FC8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820d2c70
	if (ctx.cr0.lt) goto loc_820D2C70;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0a28
	ctx.lr = 0x820D2C60;
	sub_820D0A28(ctx, base);
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
	// b 0x820d2c70
	goto loc_820D2C70;
loc_820D2C6C:
	// bl 0x820d1fc8
	ctx.lr = 0x820D2C70;
	sub_820D1FC8(ctx, base);
loc_820D2C70:
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

__attribute__((alias("__imp__sub_820D2C84"))) PPC_WEAK_FUNC(sub_820D2C84);
PPC_FUNC_IMPL(__imp__sub_820D2C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2C88"))) PPC_WEAK_FUNC(sub_820D2C88);
PPC_FUNC_IMPL(__imp__sub_820D2C88) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,11816(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11816);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d2ccc
	if (ctx.cr6.eq) goto loc_820D2CCC;
	// bl 0x820d2088
	ctx.lr = 0x820D2CB0;
	sub_820D2088(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820d2cd0
	if (ctx.cr0.lt) goto loc_820D2CD0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0a28
	ctx.lr = 0x820D2CC0;
	sub_820D0A28(ctx, base);
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
	// b 0x820d2cd0
	goto loc_820D2CD0;
loc_820D2CCC:
	// bl 0x820d2088
	ctx.lr = 0x820D2CD0;
	sub_820D2088(ctx, base);
loc_820D2CD0:
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

__attribute__((alias("__imp__sub_820D2CE4"))) PPC_WEAK_FUNC(sub_820D2CE4);
PPC_FUNC_IMPL(__imp__sub_820D2CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2CE8"))) PPC_WEAK_FUNC(sub_820D2CE8);
PPC_FUNC_IMPL(__imp__sub_820D2CE8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r11,11816(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11816);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d2cfc
	if (ctx.cr6.eq) goto loc_820D2CFC;
	// b 0x820d2b28
	sub_820D2B28(ctx, base);
	return;
loc_820D2CFC:
	// b 0x820d2400
	sub_820D2400(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2D00"))) PPC_WEAK_FUNC(sub_820D2D00);
PPC_FUNC_IMPL(__imp__sub_820D2D00) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r11,11816(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11816);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d2d14
	if (ctx.cr6.eq) goto loc_820D2D14;
	// b 0x820d2ba8
	sub_820D2BA8(ctx, base);
	return;
loc_820D2D14:
	// b 0x820d2570
	sub_820D2570(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2D18"))) PPC_WEAK_FUNC(sub_820D2D18);
PPC_FUNC_IMPL(__imp__sub_820D2D18) {
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
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820d2d3c
	if (!ctx.cr6.eq) goto loc_820D2D3C;
	// li r30,64
	ctx.r30.s64 = 64;
	// b 0x820d2d48
	goto loc_820D2D48;
loc_820D2D3C:
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x820d2d74
	if (!ctx.cr6.eq) goto loc_820D2D74;
	// li r30,1696
	ctx.r30.s64 = 1696;
loc_820D2D48:
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82088c48
	ctx.lr = 0x820D2D54;
	sub_82088C48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x820d2d6c
	if (ctx.cr0.eq) goto loc_820D2D6C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207da20
	ctx.lr = 0x820D2D6C;
	sub_8207DA20(ctx, base);
loc_820D2D6C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x820d2d78
	goto loc_820D2D78;
loc_820D2D74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D2D78:
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

__attribute__((alias("__imp__sub_820D2D90"))) PPC_WEAK_FUNC(sub_820D2D90);
PPC_FUNC_IMPL(__imp__sub_820D2D90) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// b 0x82088ce0
	sub_82088CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2DA0"))) PPC_WEAK_FUNC(sub_820D2DA0);
PPC_FUNC_IMPL(__imp__sub_820D2DA0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D2DA4"))) PPC_WEAK_FUNC(sub_820D2DA4);
PPC_FUNC_IMPL(__imp__sub_820D2DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2DA8"))) PPC_WEAK_FUNC(sub_820D2DA8);
PPC_FUNC_IMPL(__imp__sub_820D2DA8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d2dfc
	if (ctx.cr6.eq) goto loc_820D2DFC;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820d2dfc
	if (ctx.cr6.eq) goto loc_820D2DFC;
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// bl 0x82088c48
	ctx.lr = 0x820D2DDC;
	sub_82088C48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820d2df4
	if (!ctx.cr0.eq) goto loc_820D2DF4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,-4524
	ctx.r4.s64 = ctx.r11.s64 + -4524;
	// bl 0x820cab60
	ctx.lr = 0x820D2DF4;
	sub_820CAB60(ctx, base);
loc_820D2DF4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x820d2e00
	goto loc_820D2E00;
loc_820D2DFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D2E00:
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

__attribute__((alias("__imp__sub_820D2E18"))) PPC_WEAK_FUNC(sub_820D2E18);
PPC_FUNC_IMPL(__imp__sub_820D2E18) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x82088ce0
	sub_82088CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2E38"))) PPC_WEAK_FUNC(sub_820D2E38);
PPC_FUNC_IMPL(__imp__sub_820D2E38) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D2E3C"))) PPC_WEAK_FUNC(sub_820D2E3C);
PPC_FUNC_IMPL(__imp__sub_820D2E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2E40"))) PPC_WEAK_FUNC(sub_820D2E40);
PPC_FUNC_IMPL(__imp__sub_820D2E40) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// b 0x8207dac0
	sub_8207DAC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2E50"))) PPC_WEAK_FUNC(sub_820D2E50);
PPC_FUNC_IMPL(__imp__sub_820D2E50) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// b 0x8207da20
	sub_8207DA20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D2E60"))) PPC_WEAK_FUNC(sub_820D2E60);
PPC_FUNC_IMPL(__imp__sub_820D2E60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820d2e74
	if (!ctx.cr6.eq) goto loc_820D2E74;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820d2f8c
	goto loc_820D2F8C;
loc_820D2E74:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// not r10,r3
	ctx.r10.u64 = ~ctx.r3.u64;
	// cmplwi cr6,r5,8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 8, ctx.xer);
	// addi r11,r11,-4504
	ctx.r11.s64 = ctx.r11.s64 + -4504;
	// blt cr6,0x820d2f5c
	if (ctx.cr6.lt) goto loc_820D2F5C;
	// rlwinm r9,r5,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820D2E90:
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r8,r10,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// addi r5,r5,-8
	ctx.r5.s64 = ctx.r5.s64 + -8;
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
	// lbzu r9,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// xor r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// lbzu r8,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// xor r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// lwzx r7,r7,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lbzu r3,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r3.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// xor r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lbzu r31,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r31.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// xor r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// xor r9,r6,r10
	ctx.r9.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// xor r9,r3,r10
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// xor r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// xor r9,r31,r10
	ctx.r9.u64 = ctx.r31.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// bdnz 0x820d2e90
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D2E90;
loc_820D2F5C:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820d2f88
	if (ctx.cr6.eq) goto loc_820D2F88;
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
loc_820D2F68:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// rlwinm r7,r10,24,8,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// xor r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// rlwinm r10,r10,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// xor r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r7.u64;
	// bne 0x820d2f68
	if (!ctx.cr0.eq) goto loc_820D2F68;
loc_820D2F88:
	// not r3,r10
	ctx.r3.u64 = ~ctx.r10.u64;
loc_820D2F8C:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D2F94"))) PPC_WEAK_FUNC(sub_820D2F94);
PPC_FUNC_IMPL(__imp__sub_820D2F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D2F98"))) PPC_WEAK_FUNC(sub_820D2F98);
PPC_FUNC_IMPL(__imp__sub_820D2F98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D2FA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r11,r11,65500
	ctx.r11.u64 = ctx.r11.u64 | 65500;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x820d2fc8
	if (ctx.cr6.gt) goto loc_820D2FC8;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x820d2ff0
	if (!ctx.cr6.gt) goto loc_820D2FF0;
loc_820D2FC8:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,41
	ctx.r9.s64 = 41;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r11.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820D2FF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D2FF0:
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x820d3028
	if (ctx.cr6.eq) goto loc_820D3028;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,15
	ctx.r10.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,216(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820D3028;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3028:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x820d306c
	if (!ctx.cr6.gt) goto loc_820D306C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,10
	ctx.r9.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r8,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r8.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x820D306C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D306C:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r27,1
	ctx.r27.s64 = 1;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// stw r27,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r27.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r27,316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 316, ctx.r27.u32);
	// ble cr6,0x820d3120
	if (!ctx.cr6.gt) goto loc_820D3120;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// li r28,18
	ctx.r28.s64 = 18;
loc_820D3098:
	// lwz r11,-4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d30c0
	if (!ctx.cr6.gt) goto loc_820D30C0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x820d30c0
	if (ctx.cr6.gt) goto loc_820D30C0;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d30c0
	if (!ctx.cr6.gt) goto loc_820D30C0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// ble cr6,0x820d30dc
	if (!ctx.cr6.gt) goto loc_820D30DC;
loc_820D30C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D30DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D30DC:
	// lwz r11,312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x820d30f0
	if (ctx.cr6.gt) goto loc_820D30F0;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D30F0:
	// stw r11,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// lwz r11,316(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x820d3108
	if (ctx.cr6.gt) goto loc_820D3108;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D3108:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r11,316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r30,r30,84
	ctx.r30.s64 = ctx.r30.s64 + 84;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d3098
	if (ctx.cr6.lt) goto loc_820D3098;
loc_820D3120:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r28,8
	ctx.r28.s64 = 8;
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r28,320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 320, ctx.r28.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x820d31c4
	if (!ctx.cr6.gt) goto loc_820D31C4;
	// addi r30,r11,-8
	ctx.r30.s64 = ctx.r11.s64 + -8;
loc_820D3140:
	// stw r28,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r28.u32);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// mullw r3,r11,r10
	ctx.r3.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820d5340
	ctx.lr = 0x820D315C;
	sub_820D5340(ctx, base);
	// stw r3,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r3.u32);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r7,316(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// rlwinm r4,r7,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mullw r3,r8,r6
	ctx.r3.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// bl 0x820d5340
	ctx.lr = 0x820D3178;
	sub_820D5340(ctx, base);
	// stw r3,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r3.u32);
	// lwz r4,312(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mullw r3,r5,r3
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32);
	// bl 0x820d5340
	ctx.lr = 0x820D3190;
	sub_820D5340(ctx, base);
	// stw r3,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
	// lwz r4,316(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mullw r3,r11,r10
	ctx.r3.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// bl 0x820d5340
	ctx.lr = 0x820D31A8;
	sub_820D5340(ctx, base);
	// stw r3,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r3.u32);
	// stw r27,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r27.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwu r26,84(r30)
	ea = 84 + ctx.r30.u32;
	PPC_STORE_U32(ea, ctx.r26.u32);
	ctx.r30.u32 = ea;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpw cr6,r29,r9
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820d3140
	if (ctx.cr6.lt) goto loc_820D3140;
loc_820D31C4:
	// lwz r11,316(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820d5340
	ctx.lr = 0x820D31D4;
	sub_820D5340(ctx, base);
	// lwz r10,332(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r3.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820d3204
	if (ctx.cr6.lt) goto loc_820D3204;
	// lwz r11,224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d3204
	if (!ctx.cr6.eq) goto loc_820D3204;
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// stw r26,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820D3204:
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// stw r27,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3214"))) PPC_WEAK_FUNC(sub_820D3214);
PPC_FUNC_IMPL(__imp__sub_820D3214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3218"))) PPC_WEAK_FUNC(sub_820D3218);
PPC_FUNC_IMPL(__imp__sub_820D3218) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820D3220;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,332(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 332);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820d329c
	if (!ctx.cr6.eq) goto loc_820D329C;
	// lwz r11,336(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r9,352(r3)
	PPC_STORE_U32(ctx.r3.u32 + 352, ctx.r9.u32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// stw r8,356(r3)
	PPC_STORE_U32(ctx.r3.u32 + 356, ctx.r8.u32);
	// lwz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// twllei r9,0
	// divwu r5,r6,r9
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r9.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// stw r7,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r7.u32);
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// subf. r8,r4,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820d3284
	if (!ctx.cr0.eq) goto loc_820D3284;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_820D3284:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r8.u32);
	// stw r10,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r10.u32);
	// stw r9,364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 364, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820D329C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d32ac
	if (!ctx.cr6.gt) goto loc_820D32AC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// ble cr6,0x820d32e4
	if (!ctx.cr6.gt) goto loc_820D32E4;
loc_820D32AC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,4
	ctx.r9.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r7,332(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x820D32E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D32E4:
	// lwz r11,312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820d5340
	ctx.lr = 0x820D32F4;
	sub_820D5340(ctx, base);
	// stw r3,352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 352, ctx.r3.u32);
	// lwz r10,316(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r4,r10,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820d5340
	ctx.lr = 0x820D3308;
	sub_820D5340(ctx, base);
	// lwz r9,332(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r3,356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 356, ctx.r3.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r29,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r29.u32);
	// ble cr6,0x820d33fc
	if (!ctx.cr6.gt) goto loc_820D33FC;
	// addi r28,r31,336
	ctx.r28.s64 = ctx.r31.s64 + 336;
	// li r27,13
	ctx.r27.s64 = 13;
loc_820D3328:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// twllei r10,0
	// lwz r6,36(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// divwu r7,r8,r10
	ctx.r7.u32 = ppc_divwu(ctx.r8.u32, ctx.r10.u32);
	// mullw r30,r9,r10
	ctx.r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// stw r30,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r30.u32);
	// stw r9,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r9.u32);
	// mullw r5,r7,r10
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r6,r10
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r4,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r4.u32);
	// subf. r8,r5,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820d336c
	if (!ctx.cr0.eq) goto loc_820D336C;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_820D336C:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// twllei r9,0
	// stw r8,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r8.u32);
	// divwu r8,r10,r9
	ctx.r8.u32 = ppc_divwu(ctx.r10.u32, ctx.r9.u32);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subf. r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d338c
	if (!ctx.cr0.eq) goto loc_820D338C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_820D338C:
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// lwz r11,360(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x820d33bc
	if (!ctx.cr6.gt) goto loc_820D33BC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D33BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D33BC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x820d33e8
	if (!ctx.cr6.gt) goto loc_820D33E8;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
loc_820D33C8:
	// lwz r11,360(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// addi r11,r11,91
	ctx.r11.s64 = ctx.r11.s64 + 91;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r29.u32);
	// lwz r11,360(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r9.u32);
	// bdnz 0x820d33c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D33C8;
loc_820D33E8:
	// lwz r11,332(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d3328
	if (ctx.cr6.lt) goto loc_820D3328;
loc_820D33FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3404"))) PPC_WEAK_FUNC(sub_820D3404);
PPC_FUNC_IMPL(__imp__sub_820D3404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3408"))) PPC_WEAK_FUNC(sub_820D3408);
PPC_FUNC_IMPL(__imp__sub_820D3408) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D3410;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,332(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 332);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d34d8
	if (!ctx.cr6.gt) goto loc_820D34D8;
	// addi r28,r3,336
	ctx.r28.s64 = ctx.r3.s64 + 336;
	// li r26,52
	ctx.r26.s64 = 52;
loc_820D3430:
	// lwz r29,0(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,76(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d34c4
	if (!ctx.cr6.eq) goto loc_820D34C4;
	// lwz r30,16(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820d3468
	if (ctx.cr6.lt) goto loc_820D3468;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bge cr6,0x820d3468
	if (!ctx.cr6.lt) goto loc_820D3468;
	// addi r11,r30,42
	ctx.r11.s64 = ctx.r30.s64 + 42;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820d348c
	if (!ctx.cr6.eq) goto loc_820D348C;
loc_820D3468:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r30,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r30.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D348C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D348C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,132
	ctx.r5.s64 = 132;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D34A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r30,42
	ctx.r9.s64 = ctx.r30.s64 + 42;
	// li r5,132
	ctx.r5.s64 = 132;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// bl 0x8207dac0
	ctx.lr = 0x820D34C0;
	sub_8207DAC0(ctx, base);
	// stw r30,76(r29)
	PPC_STORE_U32(ctx.r29.u32 + 76, ctx.r30.u32);
loc_820D34C4:
	// lwz r11,332(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d3430
	if (ctx.cr6.lt) goto loc_820D3430;
loc_820D34D8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D34E0"))) PPC_WEAK_FUNC(sub_820D34E0);
PPC_FUNC_IMPL(__imp__sub_820D34E0) {
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
	// bl 0x820d3218
	ctx.lr = 0x820D34F8;
	sub_820D3218(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d3408
	ctx.lr = 0x820D3500;
	sub_820D3408(ctx, base);
	// lwz r11,448(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 448);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D3514;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,432(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D3528;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,432(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// lwz r6,440(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_820D354C"))) PPC_WEAK_FUNC(sub_820D354C);
PPC_FUNC_IMPL(__imp__sub_820D354C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3550"))) PPC_WEAK_FUNC(sub_820D3550);
PPC_FUNC_IMPL(__imp__sub_820D3550) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D3558;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,440(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 440);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d357c
	if (ctx.cr6.eq) goto loc_820D357C;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820D357C:
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D3590;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820d3614
	if (ctx.cr6.eq) goto loc_820D3614;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820d3670
	if (!ctx.cr6.eq) goto loc_820D3670;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r10.u32);
	// beq cr6,0x820d35f4
	if (ctx.cr6.eq) goto loc_820D35F4;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820d3670
	if (ctx.cr6.eq) goto loc_820D3670;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,59
	ctx.r10.s64 = 59;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D35E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820D35F4:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x820d3670
	if (!ctx.cr6.gt) goto loc_820D3670;
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820D3614:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d363c
	if (ctx.cr6.eq) goto loc_820D363C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d2f98
	ctx.lr = 0x820D3628;
	sub_820D2F98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820D363C:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d3668
	if (!ctx.cr6.eq) goto loc_820D3668;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,35
	ctx.r10.s64 = 35;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D3668;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3668:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d34e0
	ctx.lr = 0x820D3670;
	sub_820D34E0(ctx, base);
loc_820D3670:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D367C"))) PPC_WEAK_FUNC(sub_820D367C);
PPC_FUNC_IMPL(__imp__sub_820D367C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3680"))) PPC_WEAK_FUNC(sub_820D3680);
PPC_FUNC_IMPL(__imp__sub_820D3680) {
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
	// lwz r11,440(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 440);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r9,r10,13648
	ctx.r9.s64 = ctx.r10.s64 + 13648;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// stw r31,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r31.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820D36CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,444(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 444);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x820D36E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r31,164(r30)
	PPC_STORE_U32(ctx.r30.u32 + 164, ctx.r31.u32);
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

__attribute__((alias("__imp__sub_820D36FC"))) PPC_WEAK_FUNC(sub_820D36FC);
PPC_FUNC_IMPL(__imp__sub_820D36FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3700"))) PPC_WEAK_FUNC(sub_820D3700);
PPC_FUNC_IMPL(__imp__sub_820D3700) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,440(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 440);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r10,13648
	ctx.r9.s64 = ctx.r10.s64 + 13648;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D3714"))) PPC_WEAK_FUNC(sub_820D3714);
PPC_FUNC_IMPL(__imp__sub_820D3714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3718"))) PPC_WEAK_FUNC(sub_820D3718);
PPC_FUNC_IMPL(__imp__sub_820D3718) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D3744;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stw r3,440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 440, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r5,r9,13648
	ctx.r5.s64 = ctx.r9.s64 + 13648;
	// addi r4,r8,13952
	ctx.r4.s64 = ctx.r8.s64 + 13952;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// addi r10,r7,13536
	ctx.r10.s64 = ctx.r7.s64 + 13536;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r9,r6,14080
	ctx.r9.s64 = ctx.r6.s64 + 14080;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_820D37A0"))) PPC_WEAK_FUNC(sub_820D37A0);
PPC_FUNC_IMPL(__imp__sub_820D37A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x820D37A8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// lwz r25,4(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = ctx.r11.u64 | 51696;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r22,54
	ctx.r22.s64 = 54;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820d37f4
	if (!ctx.cr6.gt) goto loc_820D37F4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r22,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r22.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D37F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D37F4:
	// clrlwi r11,r26,29
	ctx.r11.u64 = ctx.r26.u32 & 0x7;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3808
	if (ctx.cr6.eq) goto loc_820D3808;
	// subf r11,r11,r26
	ctx.r11.s64 = ctx.r26.s64 - ctx.r11.s64;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
loc_820D3808:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x820d3818
	if (ctx.cr6.lt) goto loc_820D3818;
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// blt cr6,0x820d3840
	if (ctx.cr6.lt) goto loc_820D3840;
loc_820D3818:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D3840;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3840:
	// addi r11,r31,13
	ctx.r11.s64 = ctx.r31.s64 + 13;
	// li r24,0
	ctx.r24.s64 = 0;
	// rlwinm r23,r11,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// lwzx r11,r23,r25
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r25.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3878
	if (ctx.cr6.eq) goto loc_820D3878;
loc_820D385C:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x820d3950
	if (!ctx.cr6.lt) goto loc_820D3950;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d385c
	if (!ctx.cr6.eq) goto loc_820D385C;
loc_820D3878:
	// addi r29,r26,16
	ctx.r29.s64 = ctx.r26.s64 + 16;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bne cr6,0x820d3894
	if (!ctx.cr6.eq) goto loc_820D3894;
	// addi r9,r11,-3480
	ctx.r9.s64 = ctx.r11.s64 + -3480;
	// b 0x820d389c
	goto loc_820D389C;
loc_820D3894:
	// addi r11,r11,-3480
	ctx.r11.s64 = ctx.r11.s64 + -3480;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
loc_820D389C:
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// lwzx r31,r10,r9
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// ori r10,r11,51712
	ctx.r10.u64 = ctx.r11.u64 | 51712;
	// subf r11,r29,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r29.s64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d38b8
	if (!ctx.cr6.gt) goto loc_820D38B8;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_820D38B8:
	// add r4,r31,r29
	ctx.r4.u64 = ctx.r31.u64 + ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8698
	ctx.lr = 0x820D38C4;
	sub_820D8698(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820d391c
	if (!ctx.cr6.eq) goto loc_820D391C;
	// li r28,2
	ctx.r28.s64 = 2;
loc_820D38D4:
	// rlwinm r31,r31,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,50
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 50, ctx.xer);
	// bge cr6,0x820d3904
	if (!ctx.cr6.lt) goto loc_820D3904;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r22.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r28.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D3904;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3904:
	// add r4,r31,r29
	ctx.r4.u64 = ctx.r31.u64 + ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8698
	ctx.lr = 0x820D3910;
	sub_820D8698(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d38d4
	if (ctx.cr6.eq) goto loc_820D38D4;
loc_820D391C:
	// lwz r10,76(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 76);
	// add r9,r31,r26
	ctx.r9.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// stw r8,76(r25)
	PPC_STORE_U32(ctx.r25.u32 + 76, ctx.r8.u32);
	// stw r24,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
	// stw r24,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r24.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bne cr6,0x820d394c
	if (!ctx.cr6.eq) goto loc_820D394C;
	// stwx r11,r23,r25
	PPC_STORE_U32(ctx.r23.u32 + ctx.r25.u32, ctx.r11.u32);
	// b 0x820d3950
	goto loc_820D3950;
loc_820D394C:
	// stw r11,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_820D3950:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r7,r10,r26
	ctx.r7.u64 = ctx.r10.u64 + ctx.r26.u64;
	// subf r6,r26,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r26.s64;
	// addi r3,r9,16
	ctx.r3.s64 = ctx.r9.s64 + 16;
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3978"))) PPC_WEAK_FUNC(sub_820D3978);
PPC_FUNC_IMPL(__imp__sub_820D3978) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D3980;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// lwz r28,4(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = ctx.r11.u64 | 51696;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r26,54
	ctx.r26.s64 = 54;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820d39cc
	if (!ctx.cr6.gt) goto loc_820D39CC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r26,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r26.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D39CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D39CC:
	// clrlwi r11,r29,29
	ctx.r11.u64 = ctx.r29.u32 & 0x7;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d39e0
	if (ctx.cr6.eq) goto loc_820D39E0;
	// subf r11,r11,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r11.s64;
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
loc_820D39E0:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x820d39f0
	if (ctx.cr6.lt) goto loc_820D39F0;
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// blt cr6,0x820d3a18
	if (ctx.cr6.lt) goto loc_820D3A18;
loc_820D39F0:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r27,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r27.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D3A18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3A18:
	// addi r4,r29,16
	ctx.r4.s64 = ctx.r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8698
	ctx.lr = 0x820D3A24;
	sub_820D8698(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820d3a58
	if (!ctx.cr6.eq) goto loc_820D3A58;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r26.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D3A58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3A58:
	// lwz r11,76(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 76);
	// addi r9,r27,15
	ctx.r9.s64 = ctx.r27.s64 + 15;
	// li r8,0
	ctx.r8.s64 = 0;
	// add r10,r29,r11
	ctx.r10.u64 = ctx.r29.u64 + ctx.r11.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// stw r7,76(r28)
	PPC_STORE_U32(ctx.r28.u32 + 76, ctx.r7.u32);
	// lwzx r6,r11,r28
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stwx r31,r11,r28
	PPC_STORE_U32(ctx.r11.u32 + ctx.r28.u32, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3A94"))) PPC_WEAK_FUNC(sub_820D3A94);
PPC_FUNC_IMPL(__imp__sub_820D3A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3A98"))) PPC_WEAK_FUNC(sub_820D3A98);
PPC_FUNC_IMPL(__imp__sub_820D3A98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D3AA0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// lwz r30,4(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = ctx.r11.u64 | 51696;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// divwu. r31,r10,r5
	ctx.r31.u32 = ppc_divwu(ctx.r10.u32, ctx.r5.u32);
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// twllei r5,0
	// bgt 0x820d3ae8
	if (ctx.cr0.gt) goto loc_820D3AE8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,70
	ctx.r10.s64 = 70;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D3AE8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3AE8:
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x820d3af4
	if (ctx.cr6.lt) goto loc_820D3AF4;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_820D3AF4:
	// stw r31,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r31.u32);
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820d37a0
	ctx.lr = 0x820D3B08;
	sub_820D37A0(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820d3b68
	if (ctx.cr6.eq) goto loc_820D3B68;
loc_820D3B18:
	// subf r11,r30,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r30.s64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d3b28
	if (ctx.cr6.lt) goto loc_820D3B28;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_820D3B28:
	// mullw r5,r31,r28
	ctx.r5.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r28.s32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820d3978
	ctx.lr = 0x820D3B38;
	sub_820D3978(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820d3b60
	if (ctx.cr6.eq) goto loc_820D3B60;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
loc_820D3B54:
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + ctx.r28.u64;
	// bdnz 0x820d3b54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D3B54;
loc_820D3B60:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x820d3b18
	if (ctx.cr6.lt) goto loc_820D3B18;
loc_820D3B68:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3B74"))) PPC_WEAK_FUNC(sub_820D3B74);
PPC_FUNC_IMPL(__imp__sub_820D3B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3B78"))) PPC_WEAK_FUNC(sub_820D3B78);
PPC_FUNC_IMPL(__imp__sub_820D3B78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820D3B80;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// lwz r30,4(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r25,r5,7,0,24
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// ori r10,r11,51696
	ctx.r10.u64 = ctx.r11.u64 | 51696;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// divwu. r31,r10,r25
	ctx.r31.u32 = ppc_divwu(ctx.r10.u32, ctx.r25.u32);
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// twllei r25,0
	// bgt 0x820d3bcc
	if (ctx.cr0.gt) goto loc_820D3BCC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,70
	ctx.r10.s64 = 70;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D3BCC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3BCC:
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x820d3bd8
	if (ctx.cr6.lt) goto loc_820D3BD8;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_820D3BD8:
	// stw r31,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r31.u32);
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d37a0
	ctx.lr = 0x820D3BEC;
	sub_820D37A0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820d3c50
	if (ctx.cr6.eq) goto loc_820D3C50;
loc_820D3BFC:
	// subf r11,r30,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r30.s64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d3c0c
	if (ctx.cr6.lt) goto loc_820D3C0C;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_820D3C0C:
	// mullw r11,r31,r24
	ctx.r11.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r24.s32);
	// rlwinm r5,r11,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820d3978
	ctx.lr = 0x820D3C20;
	sub_820D3978(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820d3c48
	if (ctx.cr6.eq) goto loc_820D3C48;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
loc_820D3C3C:
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// add r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	// bdnz 0x820d3c3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D3C3C;
loc_820D3C48:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x820d3bfc
	if (ctx.cr6.lt) goto loc_820D3BFC;
loc_820D3C50:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3C5C"))) PPC_WEAK_FUNC(sub_820D3C5C);
PPC_FUNC_IMPL(__imp__sub_820D3C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3C60"))) PPC_WEAK_FUNC(sub_820D3C60);
PPC_FUNC_IMPL(__imp__sub_820D3C60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D3C68;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,4(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x820d3cb4
	if (ctx.cr6.eq) goto loc_820D3CB4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r4,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r4.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D3CB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3CB4:
	// li r5,584
	ctx.r5.s64 = 584;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d37a0
	ctx.lr = 0x820D3CC4;
	sub_820D37A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r26.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r27.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r25.u32);
	// stw r28,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r28.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// lwz r11,68(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// stw r3,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3CF4"))) PPC_WEAK_FUNC(sub_820D3CF4);
PPC_FUNC_IMPL(__imp__sub_820D3CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3CF8"))) PPC_WEAK_FUNC(sub_820D3CF8);
PPC_FUNC_IMPL(__imp__sub_820D3CF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D3D00;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,4(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x820d3d4c
	if (ctx.cr6.eq) goto loc_820D3D4C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r4,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r4.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D3D4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D3D4C:
	// li r5,584
	ctx.r5.s64 = 584;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d37a0
	ctx.lr = 0x820D3D5C;
	sub_820D37A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r26.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r27.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r25.u32);
	// stw r28,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r28.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// lwz r11,72(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// stw r3,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3D8C"))) PPC_WEAK_FUNC(sub_820D3D8C);
PPC_FUNC_IMPL(__imp__sub_820D3D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D3D90"))) PPC_WEAK_FUNC(sub_820D3D90);
PPC_FUNC_IMPL(__imp__sub_820D3D90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D3D98;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,4(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// lwz r11,68(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3df0
	if (ctx.cr6.eq) goto loc_820D3DF0;
loc_820D3DBC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820d3de4
	if (!ctx.cr6.eq) goto loc_820D3DE4;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mullw r9,r7,r9
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// add r31,r10,r31
	ctx.r31.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 + ctx.r30.u64;
loc_820D3DE4:
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d3dbc
	if (!ctx.cr6.eq) goto loc_820D3DBC;
loc_820D3DF0:
	// lwz r11,72(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d3e38
	if (ctx.cr6.eq) goto loc_820D3E38;
loc_820D3DFC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820d3e2c
	if (!ctx.cr6.eq) goto loc_820D3E2C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r7,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r10,r6,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// add r31,r9,r31
	ctx.r31.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
loc_820D3E2C:
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d3dfc
	if (!ctx.cr6.eq) goto loc_820D3DFC;
loc_820D3E38:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x820d3fc0
	if (!ctx.cr6.gt) goto loc_820D3FC0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r6,76(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 76);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d8710
	ctx.lr = 0x820D3E54;
	sub_820D8710(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmpw cr6,r3,r30
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r30.s32, ctx.xer);
	// blt cr6,0x820d3e6c
	if (ctx.cr6.lt) goto loc_820D3E6C;
	// lis r30,15258
	ctx.r30.s64 = 999948288;
	// ori r30,r30,51712
	ctx.r30.u64 = ctx.r30.u64 | 51712;
	// b 0x820d3e8c
	goto loc_820D3E8C;
loc_820D3E6C:
	// rotlwi r11,r3,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// divw. r30,r3,r31
	ctx.r30.s32 = ppc_divw(ctx.r3.s32, ctx.r31.s32);
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// twllei r31,0
	// andc r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 & ~ctx.r11.u64;
	// twlgei r10,-1
	// bgt 0x820d3e8c
	if (ctx.cr0.gt) goto loc_820D3E8C;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_820D3E8C:
	// lwz r31,68(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 68);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820d3f24
	if (ctx.cr6.eq) goto loc_820D3F24;
loc_820D3E98:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d3f18
	if (!ctx.cr6.eq) goto loc_820D3F18;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// twllei r10,0
	// divwu r9,r9,r10
	ctx.r9.u32 = ppc_divwu(ctx.r9.u32, ctx.r10.u32);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r8,r30
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x820d3ecc
	if (ctx.cr6.gt) goto loc_820D3ECC;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// b 0x820d3eec
	goto loc_820D3EEC;
loc_820D3ECC:
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// mullw r5,r9,r11
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d8858
	ctx.lr = 0x820D3EE8;
	sub_820D8858(ctx, base);
	// stw r28,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r28.u32);
loc_820D3EEC:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820d3a98
	ctx.lr = 0x820D3F00;
	sub_820D3A98(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lwz r11,80(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 80);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r26.u32);
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
loc_820D3F18:
	// lwz r31,44(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820d3e98
	if (!ctx.cr6.eq) goto loc_820D3E98;
loc_820D3F24:
	// lwz r31,72(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 72);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820d3fc0
	if (ctx.cr6.eq) goto loc_820D3FC0;
loc_820D3F30:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d3fb4
	if (!ctx.cr6.eq) goto loc_820D3FB4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// twllei r10,0
	// divwu r9,r9,r10
	ctx.r9.u32 = ppc_divwu(ctx.r9.u32, ctx.r10.u32);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r8,r30
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x820d3f64
	if (ctx.cr6.gt) goto loc_820D3F64;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// b 0x820d3f88
	goto loc_820D3F88;
loc_820D3F64:
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r5,r8,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d8858
	ctx.lr = 0x820D3F84;
	sub_820D8858(ctx, base);
	// stw r28,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r28.u32);
loc_820D3F88:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820d3b78
	ctx.lr = 0x820D3F9C;
	sub_820D3B78(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lwz r11,80(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 80);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r26.u32);
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
loc_820D3FB4:
	// lwz r31,44(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820d3f30
	if (!ctx.cr6.eq) goto loc_820D3F30;
loc_820D3FC0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D3FC8"))) PPC_WEAK_FUNC(sub_820D3FC8);
PPC_FUNC_IMPL(__imp__sub_820D3FC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D3FD0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,8(r4)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// mullw r28,r10,r26
	ctx.r28.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d409c
	if (!ctx.cr6.gt) goto loc_820D409C;
loc_820D3FFC:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x820d4010
	if (!ctx.cr6.lt) goto loc_820D4010;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D4010:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820d402c
	if (ctx.cr6.lt) goto loc_820D402C;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820D402C:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820d4040
	if (ctx.cr6.lt) goto loc_820D4040;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D4040:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d409c
	if (!ctx.cr6.gt) goto loc_820D409C;
	// mullw r29,r11,r26
	ctx.r29.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// beq cr6,0x820d4078
	if (ctx.cr6.eq) goto loc_820D4078;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// b 0x820d407c
	goto loc_820D407C;
loc_820D4078:
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
loc_820D407C:
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4084;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r29,r28
	ctx.r28.u64 = ctx.r29.u64 + ctx.r28.u64;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r30,r30,r10
	ctx.r30.u64 = ctx.r30.u64 + ctx.r10.u64;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d3ffc
	if (ctx.cr6.lt) goto loc_820D3FFC;
loc_820D409C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D40A4"))) PPC_WEAK_FUNC(sub_820D40A4);
PPC_FUNC_IMPL(__imp__sub_820D40A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D40A8"))) PPC_WEAK_FUNC(sub_820D40A8);
PPC_FUNC_IMPL(__imp__sub_820D40A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D40B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r9,24(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// rlwinm r26,r10,7,0,24
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// mullw r28,r26,r9
	ctx.r28.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r9.s32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d4180
	if (!ctx.cr6.gt) goto loc_820D4180;
loc_820D40E0:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x820d40f4
	if (!ctx.cr6.lt) goto loc_820D40F4;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D40F4:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820d4110
	if (ctx.cr6.lt) goto loc_820D4110;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820D4110:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820d4124
	if (ctx.cr6.lt) goto loc_820D4124;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820D4124:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820d4180
	if (!ctx.cr6.gt) goto loc_820D4180;
	// mullw r29,r11,r26
	ctx.r29.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// beq cr6,0x820d415c
	if (ctx.cr6.eq) goto loc_820D415C;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// b 0x820d4160
	goto loc_820D4160;
loc_820D415C:
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
loc_820D4160:
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4168;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r29,r28
	ctx.r28.u64 = ctx.r29.u64 + ctx.r28.u64;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d40e0
	if (ctx.cr6.lt) goto loc_820D40E0;
loc_820D4180:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D4188"))) PPC_WEAK_FUNC(sub_820D4188);
PPC_FUNC_IMPL(__imp__sub_820D4188) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D4190;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// add r30,r5,r6
	ctx.r30.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// li r28,22
	ctx.r28.s64 = 22;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d41d0
	if (ctx.cr6.gt) goto loc_820D41D0;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d41d0
	if (ctx.cr6.gt) goto loc_820D41D0;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d41ec
	if (!ctx.cr6.eq) goto loc_820D41EC;
loc_820D41D0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D41EC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D41EC:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d4208
	if (ctx.cr6.lt) goto loc_820D4208;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d4294
	if (!ctx.cr6.gt) goto loc_820D4294;
loc_820D4208:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4234
	if (!ctx.cr6.eq) goto loc_820D4234;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,69
	ctx.r10.s64 = 69;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D4234;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D4234:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4258
	if (ctx.cr6.eq) goto loc_820D4258;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d3fc8
	ctx.lr = 0x820D4250;
	sub_820D3FC8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_820D4258:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d426c
	if (!ctx.cr6.gt) goto loc_820D426C;
	// stw r27,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// b 0x820d4284
	goto loc_820D4284;
loc_820D426C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r11,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r11.s64;
	// rlwinm r11,r10,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
loc_820D4284:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d3fc8
	ctx.lr = 0x820D4294;
	sub_820D3FC8(ctx, base);
loc_820D4294:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x820d4324
	if (!ctx.cr6.lt) goto loc_820D4324;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x820d42d0
	if (!ctx.cr6.lt) goto loc_820D42D0;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d42cc
	if (ctx.cr6.eq) goto loc_820D42CC;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D42CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D42CC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_820D42D0:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d42dc
	if (ctx.cr6.eq) goto loc_820D42DC;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
loc_820D42DC:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820d4350
	if (ctx.cr6.eq) goto loc_820D4350;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// subf r10,r10,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r10.s64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820d4324
	if (!ctx.cr6.lt) goto loc_820D4324;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r11,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r11.s64;
loc_820D4308:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x820d5408
	ctx.lr = 0x820D4318;
	sub_820D5408(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x820d4308
	if (!ctx.cr0.eq) goto loc_820D4308;
loc_820D4324:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d4334
	if (ctx.cr6.eq) goto loc_820D4334;
loc_820D432C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_820D4334:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// subf r9,r11,r27
	ctx.r9.s64 = ctx.r27.s64 - ctx.r11.s64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820D4350:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x820d432c
	if (!ctx.cr6.eq) goto loc_820D432C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4374;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820d4334
	goto loc_820D4334;
}

__attribute__((alias("__imp__sub_820D4378"))) PPC_WEAK_FUNC(sub_820D4378);
PPC_FUNC_IMPL(__imp__sub_820D4378) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D4380;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// add r30,r5,r6
	ctx.r30.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// li r28,22
	ctx.r28.s64 = 22;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d43c0
	if (ctx.cr6.gt) goto loc_820D43C0;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d43c0
	if (ctx.cr6.gt) goto loc_820D43C0;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d43dc
	if (!ctx.cr6.eq) goto loc_820D43DC;
loc_820D43C0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D43DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D43DC:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d43f8
	if (ctx.cr6.lt) goto loc_820D43F8;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d4484
	if (!ctx.cr6.gt) goto loc_820D4484;
loc_820D43F8:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4424
	if (!ctx.cr6.eq) goto loc_820D4424;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,69
	ctx.r10.s64 = 69;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D4424;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D4424:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4448
	if (ctx.cr6.eq) goto loc_820D4448;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d40a8
	ctx.lr = 0x820D4440;
	sub_820D40A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_820D4448:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d445c
	if (!ctx.cr6.gt) goto loc_820D445C;
	// stw r27,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// b 0x820d4474
	goto loc_820D4474;
loc_820D445C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r11,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r11.s64;
	// rlwinm r11,r10,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
loc_820D4474:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d40a8
	ctx.lr = 0x820D4484;
	sub_820D40A8(ctx, base);
loc_820D4484:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x820d4518
	if (!ctx.cr6.lt) goto loc_820D4518;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x820d44c0
	if (!ctx.cr6.lt) goto loc_820D44C0;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d44bc
	if (ctx.cr6.eq) goto loc_820D44BC;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D44BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D44BC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_820D44C0:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d44cc
	if (ctx.cr6.eq) goto loc_820D44CC;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
loc_820D44CC:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820d4544
	if (ctx.cr6.eq) goto loc_820D4544;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// subf r10,r10,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r10.s64;
	// rlwinm r28,r9,7,0,24
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820d4518
	if (!ctx.cr6.lt) goto loc_820D4518;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r11,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r11.s64;
loc_820D44FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x820d5408
	ctx.lr = 0x820D450C;
	sub_820D5408(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x820d44fc
	if (!ctx.cr0.eq) goto loc_820D44FC;
loc_820D4518:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d4528
	if (ctx.cr6.eq) goto loc_820D4528;
loc_820D4520:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_820D4528:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// subf r9,r11,r27
	ctx.r9.s64 = ctx.r27.s64 - ctx.r11.s64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820D4544:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x820d4520
	if (!ctx.cr6.eq) goto loc_820D4520;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4568;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820d4528
	goto loc_820D4528;
}

__attribute__((alias("__imp__sub_820D456C"))) PPC_WEAK_FUNC(sub_820D456C);
PPC_FUNC_IMPL(__imp__sub_820D456C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D4570"))) PPC_WEAK_FUNC(sub_820D4570);
PPC_FUNC_IMPL(__imp__sub_820D4570) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D4578;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,4(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x820d4598
	if (ctx.cr6.lt) goto loc_820D4598;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// blt cr6,0x820d45c0
	if (ctx.cr6.lt) goto loc_820D45C0;
loc_820D4598:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r26,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r26.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D45C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D45C0:
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// bne cr6,0x820d464c
	if (!ctx.cr6.eq) goto loc_820D464C;
	// lwz r30,68(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d4608
	if (ctx.cr6.eq) goto loc_820D4608;
loc_820D45D8:
	// lwz r11,40(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d45fc
	if (ctx.cr6.eq) goto loc_820D45FC;
	// stw r27,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r27.u32);
	// addi r4,r30,48
	ctx.r4.s64 = ctx.r30.s64 + 48;
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D45FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D45FC:
	// lwz r30,44(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820d45d8
	if (!ctx.cr6.eq) goto loc_820D45D8;
loc_820D4608:
	// lwz r30,72(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r27,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r27.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d4648
	if (ctx.cr6.eq) goto loc_820D4648;
loc_820D4618:
	// lwz r11,40(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d463c
	if (ctx.cr6.eq) goto loc_820D463C;
	// stw r27,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r27.u32);
	// addi r4,r30,48
	ctx.r4.s64 = ctx.r30.s64 + 48;
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D463C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D463C:
	// lwz r30,44(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820d4618
	if (!ctx.cr6.eq) goto loc_820D4618;
loc_820D4648:
	// stw r27,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r27.u32);
loc_820D464C:
	// addi r11,r26,15
	ctx.r11.s64 = ctx.r26.s64 + 15;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// stwx r27,r11,r31
	PPC_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r27.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820d469c
	if (ctx.cr6.eq) goto loc_820D469C;
loc_820D4664:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r30,0(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r29,r11,16
	ctx.r29.s64 = ctx.r11.s64 + 16;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x820d86f0
	ctx.lr = 0x820D4684;
	sub_820D86F0(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// subf r10,r29,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r29.s64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x820d4664
	if (!ctx.cr6.eq) goto loc_820D4664;
loc_820D469C:
	// addi r11,r26,13
	ctx.r11.s64 = ctx.r26.s64 + 13;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// stwx r27,r11,r31
	PPC_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r27.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820d46ec
	if (ctx.cr6.eq) goto loc_820D46EC;
loc_820D46B4:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r30,0(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r29,r11,16
	ctx.r29.s64 = ctx.r11.s64 + 16;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x820d86f0
	ctx.lr = 0x820D46D4;
	sub_820D86F0(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// subf r10,r29,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r29.s64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x820d46b4
	if (!ctx.cr6.eq) goto loc_820D46B4;
loc_820D46EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D46F4"))) PPC_WEAK_FUNC(sub_820D46F4);
PPC_FUNC_IMPL(__imp__sub_820D46F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D46F8"))) PPC_WEAK_FUNC(sub_820D46F8);
PPC_FUNC_IMPL(__imp__sub_820D46F8) {
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
	// li r31,1
	ctx.r31.s64 = 1;
loc_820D4714:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d4570
	ctx.lr = 0x820D4720;
	sub_820D4570(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x820d4714
	if (!ctx.cr0.lt) goto loc_820D4714;
	// li r5,84
	ctx.r5.s64 = 84;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d86f0
	ctx.lr = 0x820D4738;
	sub_820D86F0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// bl 0x8210e878
	ctx.lr = 0x820D4748;
	sub_8210E878(ctx, base);
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

__attribute__((alias("__imp__sub_820D4760"))) PPC_WEAK_FUNC(sub_820D4760);
PPC_FUNC_IMPL(__imp__sub_820D4760) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D4768;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// bl 0x820d88f8
	ctx.lr = 0x820D477C;
	sub_820D88F8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r4,84
	ctx.r4.s64 = 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8698
	ctx.lr = 0x820D478C;
	sub_820D8698(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820d47c8
	if (!ctx.cr6.eq) goto loc_820D47C8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210e878
	ctx.lr = 0x820D47A0;
	sub_8210E878(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r11,54
	ctx.r11.s64 = 54;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r29.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D47C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D47C8:
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r11,r11,14240
	ctx.r11.s64 = ctx.r11.s64 + 14240;
	// addi r10,r10,14712
	ctx.r10.s64 = ctx.r10.s64 + 14712;
	// addi r9,r9,15000
	ctx.r9.s64 = ctx.r9.s64 + 15000;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// lis r28,-32243
	ctx.r28.s64 = -2113077248;
	// lis r27,-32243
	ctx.r27.s64 = -2113077248;
	// lis r26,15258
	ctx.r26.s64 = 999948288;
	// addi r8,r8,15224
	ctx.r8.s64 = ctx.r8.s64 + 15224;
	// addi r7,r7,15456
	ctx.r7.s64 = ctx.r7.s64 + 15456;
	// addi r6,r6,15608
	ctx.r6.s64 = ctx.r6.s64 + 15608;
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// addi r5,r5,15760
	ctx.r5.s64 = ctx.r5.s64 + 15760;
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// addi r4,r4,16776
	ctx.r4.s64 = ctx.r4.s64 + 16776;
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// addi r3,r3,17272
	ctx.r3.s64 = ctx.r3.s64 + 17272;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// addi r11,r28,17776
	ctx.r11.s64 = ctx.r28.s64 + 17776;
	// stw r4,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r4.u32);
	// addi r10,r27,18168
	ctx.r10.s64 = ctx.r27.s64 + 18168;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// ori r9,r26,51712
	ctx.r9.u64 = ctx.r26.u64 | 51712;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// li r8,84
	ctx.r8.s64 = 84;
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// stw r29,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// stw r29,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// stw r29,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
	// stw r29,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r29.u32);
	// stw r29,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D4888"))) PPC_WEAK_FUNC(sub_820D4888);
PPC_FUNC_IMPL(__imp__sub_820D4888) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d48dc
	if (ctx.cr6.eq) goto loc_820D48DC;
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D48B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820d48d4
	if (ctx.cr6.eq) goto loc_820D48D4;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,200
	ctx.r11.s64 = 200;
	// stw r10,308(r31)
	PPC_STORE_U32(ctx.r31.u32 + 308, ctx.r10.u32);
	// b 0x820d48d8
	goto loc_820D48D8;
loc_820D48D4:
	// li r11,100
	ctx.r11.s64 = 100;
loc_820D48D8:
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_820D48DC:
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

__attribute__((alias("__imp__sub_820D48F0"))) PPC_WEAK_FUNC(sub_820D48F0);
PPC_FUNC_IMPL(__imp__sub_820D48F0) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d491c
	if (ctx.cr6.eq) goto loc_820D491C;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D491C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D491C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_820D493C"))) PPC_WEAK_FUNC(sub_820D493C);
PPC_FUNC_IMPL(__imp__sub_820D493C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D4940"))) PPC_WEAK_FUNC(sub_820D4940);
PPC_FUNC_IMPL(__imp__sub_820D4940) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,132
	ctx.r5.s64 = 132;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D4964;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D497C"))) PPC_WEAK_FUNC(sub_820D497C);
PPC_FUNC_IMPL(__imp__sub_820D497C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D4980"))) PPC_WEAK_FUNC(sub_820D4980);
PPC_FUNC_IMPL(__imp__sub_820D4980) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,280
	ctx.r5.s64 = 280;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D49A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D49BC"))) PPC_WEAK_FUNC(sub_820D49BC);
PPC_FUNC_IMPL(__imp__sub_820D49BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D49C0"))) PPC_WEAK_FUNC(sub_820D49C0);
PPC_FUNC_IMPL(__imp__sub_820D49C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,120(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,220(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bgt cr6,0x820d4a80
	if (ctx.cr6.gt) goto loc_820D4A80;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r10,180(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 180);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r10,320(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820d4a80
	if (!ctx.cr6.eq) goto loc_820D4A80;
	// lwz r11,204(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 204);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_820D4A80:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D4A88"))) PPC_WEAK_FUNC(sub_820D4A88);
PPC_FUNC_IMPL(__imp__sub_820D4A88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820D4A90;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,202
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 202, ctx.xer);
	// beq cr6,0x820d4acc
	if (ctx.cr6.eq) goto loc_820D4ACC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820D4ACC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D4ACC:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r28,4
	ctx.r28.s64 = 4;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820d4b10
	if (ctx.cr6.gt) goto loc_820D4B10;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x820d5340
	ctx.lr = 0x820D4AF4;
	sub_820D5340(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x820d5340
	ctx.lr = 0x820D4B04;
	sub_820D5340(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r3.u32);
	// stw r27,320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 320, ctx.r27.u32);
	// b 0x820d4b94
	goto loc_820D4B94;
loc_820D4B10:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820d4b48
	if (ctx.cr6.gt) goto loc_820D4B48;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x820d5340
	ctx.lr = 0x820D4B28;
	sub_820D5340(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x820d5340
	ctx.lr = 0x820D4B38;
	sub_820D5340(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r3,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r3.u32);
	// stw r11,320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 320, ctx.r11.u32);
	// b 0x820d4b94
	goto loc_820D4B94;
loc_820D4B48:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820d4b7c
	if (ctx.cr6.gt) goto loc_820D4B7C;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x820d5340
	ctx.lr = 0x820D4B60;
	sub_820D5340(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x820d5340
	ctx.lr = 0x820D4B70;
	sub_820D5340(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r3.u32);
	// stw r28,320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 320, ctx.r28.u32);
	// b 0x820d4b94
	goto loc_820D4B94;
loc_820D4B7C:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r10,320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 320, ctx.r10.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
loc_820D4B94:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x820d4c14
	if (!ctx.cr6.gt) goto loc_820D4C14;
	// addi r9,r11,-48
	ctx.r9.s64 = ctx.r11.s64 + -48;
loc_820D4BAC:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 320);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// bge cr6,0x820d4c00
	if (!ctx.cr6.lt) goto loc_820D4C00;
	// lwz r7,312(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mullw r7,r7,r10
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
loc_820D4BC8:
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// rlwinm r4,r5,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x820d4c00
	if (ctx.cr6.gt) goto loc_820D4C00;
	// lwz r5,60(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// lwz r4,316(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// mullw r3,r5,r11
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// mullw r5,r4,r10
	ctx.r5.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r3,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x820d4c00
	if (ctx.cr6.gt) goto loc_820D4C00;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x820d4bc8
	if (ctx.cr6.lt) goto loc_820D4BC8;
loc_820D4C00:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stwu r11,84(r9)
	ea = 84 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d4bac
	if (ctx.cr6.lt) goto loc_820D4BAC;
loc_820D4C14:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x820d4c88
	if (!ctx.cr6.gt) goto loc_820D4C88;
	// addi r30,r11,36
	ctx.r30.s64 = ctx.r11.s64 + 36;
loc_820D4C2C:
	// lwz r11,-28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -28);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r3,r7,r8
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// bl 0x820d5340
	ctx.lr = 0x820D4C4C;
	sub_820D5340(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r3.u32);
	// lwz r6,316(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r5,-24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + -24);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mullw r11,r5,r4
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// mullw r3,r11,r3
	ctx.r3.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820d5340
	ctx.lr = 0x820D4C70;
	sub_820D5340(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r3,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// addi r30,r30,84
	ctx.r30.s64 = ctx.r30.s64 + 84;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpw cr6,r29,r10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820d4c2c
	if (ctx.cr6.lt) goto loc_820D4C2C;
loc_820D4C88:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x820d4cc8
	if (ctx.cr6.gt) goto loc_820D4CC8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820d4cb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820D4CB8;
	// bdzf 4*cr6+eq,0x820d4cb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820D4CB8;
	// bdzf 4*cr6+eq,0x820d4cc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820D4CC0;
	// bne cr6,0x820d4cc0
	if (!ctx.cr6.eq) goto loc_820D4CC0;
	// stw r27,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r27.u32);
	// b 0x820d4cd0
	goto loc_820D4CD0;
loc_820D4CB8:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x820d4ccc
	goto loc_820D4CCC;
loc_820D4CC0:
	// stw r28,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r28.u32);
	// b 0x820d4cd0
	goto loc_820D4CD0;
loc_820D4CC8:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
loc_820D4CCC:
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
loc_820D4CD0:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// bne cr6,0x820d4ce4
	if (!ctx.cr6.eq) goto loc_820D4CE4;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
loc_820D4CE4:
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d49c0
	ctx.lr = 0x820D4CF0;
	sub_820D49C0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820d4d08
	if (ctx.cr6.eq) goto loc_820D4D08;
	// lwz r11,316(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820D4D08:
	// stw r27,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D4D14"))) PPC_WEAK_FUNC(sub_820D4D14);
PPC_FUNC_IMPL(__imp__sub_820D4D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D4D18"))) PPC_WEAK_FUNC(sub_820D4D18);
PPC_FUNC_IMPL(__imp__sub_820D4D18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820D4D20;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,424(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820d4a88
	ctx.lr = 0x820D4D30;
	sub_820D4A88(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,1408
	ctx.r5.s64 = 1408;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D4D4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r3,256
	ctx.r30.s64 = ctx.r3.s64 + 256;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// addi r3,r30,-256
	ctx.r3.s64 = ctx.r30.s64 + -256;
	// bl 0x8207da20
	ctx.lr = 0x820D4D64;
	sub_8207DA20(ctx, base);
	// li r10,256
	ctx.r10.s64 = 256;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D4D74:
	// stbx r11,r11,r30
	PPC_STORE_U8(ctx.r11.u32 + ctx.r30.u32, ctx.r11.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x820d4d74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D4D74;
	// addi r30,r30,128
	ctx.r30.s64 = ctx.r30.s64 + 128;
	// li r10,384
	ctx.r10.s64 = 384;
	// addi r11,r30,128
	ctx.r11.s64 = ctx.r30.s64 + 128;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D4D98:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820d4d98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D4D98;
	// li r5,384
	ctx.r5.s64 = 384;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,512
	ctx.r3.s64 = ctx.r30.s64 + 512;
	// bl 0x8207da20
	ctx.lr = 0x820D4DB0;
	sub_8207DA20(ctx, base);
	// addi r3,r30,896
	ctx.r3.s64 = ctx.r30.s64 + 896;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r4,328(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// bl 0x8207dac0
	ctx.lr = 0x820D4DC0;
	sub_8207DAC0(ctx, base);
	// stw r28,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d49c0
	ctx.lr = 0x820D4DCC;
	sub_820D49C0(ctx, base);
	// stw r3,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r3.u32);
	// stw r28,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r28.u32);
	// stw r28,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r28.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4df0
	if (ctx.cr6.eq) goto loc_820D4DF0;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d4dfc
	if (!ctx.cr6.eq) goto loc_820D4DFC;
loc_820D4DF0:
	// stw r28,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r28.u32);
	// stw r28,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r28.u32);
	// stw r28,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r28.u32);
loc_820D4DFC:
	// li r29,1
	ctx.r29.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4eb0
	if (ctx.cr6.eq) goto loc_820D4EB0;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4e34
	if (ctx.cr6.eq) goto loc_820D4E34;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,47
	ctx.r10.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D4E34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D4E34:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x820d4ed4
	if (ctx.cr6.eq) goto loc_820D4ED4;
	// stw r28,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r28.u32);
	// stw r28,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r28.u32);
	// stw r28,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r28.u32);
loc_820D4E4C:
	// stw r29,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r29.u32);
loc_820D4E50:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r30,48
	ctx.r30.s64 = 48;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4e7c
	if (ctx.cr6.eq) goto loc_820D4E7C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4E7C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D4E7C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4e94
	if (!ctx.cr6.eq) goto loc_820D4E94;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4eb0
	if (ctx.cr6.eq) goto loc_820D4EB0;
loc_820D4E94:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4EB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D4EB0:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4f14
	if (!ctx.cr6.eq) goto loc_820D4F14;
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4efc
	if (ctx.cr6.eq) goto loc_820D4EFC;
	// bl 0x820de258
	ctx.lr = 0x820D4ED0;
	sub_820DE258(ctx, base);
	// b 0x820d4f08
	goto loc_820D4F08;
loc_820D4ED4:
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d4ee8
	if (ctx.cr6.eq) goto loc_820D4EE8;
	// stw r29,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r29.u32);
	// b 0x820d4e50
	goto loc_820D4E50;
loc_820D4EE8:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4e4c
	if (ctx.cr6.eq) goto loc_820D4E4C;
	// stw r29,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
	// b 0x820d4e50
	goto loc_820D4E50;
loc_820D4EFC:
	// bl 0x820dd9d0
	ctx.lr = 0x820D4F00;
	sub_820DD9D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820dcb78
	ctx.lr = 0x820D4F08;
	sub_820DCB78(ctx, base);
loc_820D4F08:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// bl 0x820dc510
	ctx.lr = 0x820D4F14;
	sub_820DC510(ctx, base);
loc_820D4F14:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820dc320
	ctx.lr = 0x820D4F1C;
	sub_820DC320(ctx, base);
	// lwz r11,228(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4f48
	if (ctx.cr6.eq) goto loc_820D4F48;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D4F44;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820d4f64
	goto loc_820D4F64;
loc_820D4F48:
	// lwz r11,224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4f60
	if (ctx.cr6.eq) goto loc_820D4F60;
	// bl 0x820dbe58
	ctx.lr = 0x820D4F5C;
	sub_820DBE58(ctx, base);
	// b 0x820d4f64
	goto loc_820D4F64;
loc_820D4F60:
	// bl 0x820db048
	ctx.lr = 0x820D4F64;
	sub_820DB048(ctx, base);
loc_820D4F64:
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d4f84
	if (!ctx.cr6.eq) goto loc_820D4F84;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d4f88
	if (ctx.cr6.eq) goto loc_820D4F88;
loc_820D4F84:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820D4F88:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820da230
	ctx.lr = 0x820D4F90;
	sub_820DA230(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d4fa8
	if (!ctx.cr6.eq) goto loc_820D4FA8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d8ff0
	ctx.lr = 0x820D4FA8;
	sub_820D8FF0(ctx, base);
loc_820D4FA8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D4FBC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,440(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D4FD0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820d5058
	if (ctx.cr6.eq) goto loc_820D5058;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d5058
	if (!ctx.cr6.eq) goto loc_820D5058;
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820d5058
	if (ctx.cr6.eq) goto loc_820D5058;
	// lwz r11,224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// beq cr6,0x820d5014
	if (ctx.cr6.eq) goto loc_820D5014;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_820D5014:
	// stw r28,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r28.u32);
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r28,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r28.u32);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r11,r3,1
	ctx.r11.u64 = ctx.r3.u64 ^ 1;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r11.u32);
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r10.u32);
loc_820D5058:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D5060"))) PPC_WEAK_FUNC(sub_820D5060);
PPC_FUNC_IMPL(__imp__sub_820D5060) {
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
	// lwz r30,424(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d50a8
	if (ctx.cr6.eq) goto loc_820D50A8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D50A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820d51f0
	goto loc_820D51F0;
loc_820D50A8:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d5124
	if (ctx.cr6.eq) goto loc_820D5124;
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d5124
	if (!ctx.cr6.eq) goto loc_820D5124;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d50ec
	if (ctx.cr6.eq) goto loc_820D50EC;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d50ec
	if (ctx.cr6.eq) goto loc_820D50EC;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,464(r31)
	PPC_STORE_U32(ctx.r31.u32 + 464, ctx.r11.u32);
	// stw r10,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// b 0x820d5124
	goto loc_820D5124;
loc_820D50EC:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d5104
	if (ctx.cr6.eq) goto loc_820D5104;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,464(r31)
	PPC_STORE_U32(ctx.r31.u32 + 464, ctx.r11.u32);
	// b 0x820d5124
	goto loc_820D5124;
loc_820D5104:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,46
	ctx.r10.s64 = 46;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D5124;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D5124:
	// lwz r11,452(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 452);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D5138;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,432(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D514C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x820d51f0
	if (!ctx.cr6.eq) goto loc_820D51F0;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d5178
	if (!ctx.cr6.eq) goto loc_820D5178;
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D5178;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D5178:
	// lwz r11,456(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 456);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D518C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820d51b0
	if (ctx.cr6.eq) goto loc_820D51B0;
	// lwz r11,464(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 464);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D51B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D51B0:
	// lwz r11,436(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subfic r8,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r5,r10
	ctx.r4.u64 = ctx.r5.u64 & ctx.r10.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820D51D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D51F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D51F0:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d5268
	if (ctx.cr6.eq) goto loc_820D5268;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r5,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r5.u32);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820d5268
	if (ctx.cr6.eq) goto loc_820D5268;
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d5268
	if (!ctx.cr6.eq) goto loc_820D5268;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
loc_820D5268:
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

__attribute__((alias("__imp__sub_820D5280"))) PPC_WEAK_FUNC(sub_820D5280);
PPC_FUNC_IMPL(__imp__sub_820D5280) {
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
	// lwz r31,424(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d52b0
	if (ctx.cr6.eq) goto loc_820D52B0;
	// lwz r11,464(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 464);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D52B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D52B0:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_820D52D0"))) PPC_WEAK_FUNC(sub_820D52D0);
PPC_FUNC_IMPL(__imp__sub_820D52D0) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D52FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r3,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// addi r6,r8,20576
	ctx.r6.s64 = ctx.r8.s64 + 20576;
	// addi r5,r7,21120
	ctx.r5.s64 = ctx.r7.s64 + 21120;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r4.u32);
	// bl 0x820d4d18
	ctx.lr = 0x820D532C;
	sub_820D4D18(ctx, base);
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

__attribute__((alias("__imp__sub_820D5340"))) PPC_WEAK_FUNC(sub_820D5340);
PPC_FUNC_IMPL(__imp__sub_820D5340) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// twllei r4,0
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r3,r10,r4
	ctx.r3.s32 = ppc_divw(ctx.r10.s32, ctx.r4.s32);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// andc r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D5364"))) PPC_WEAK_FUNC(sub_820D5364);
PPC_FUNC_IMPL(__imp__sub_820D5364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5368"))) PPC_WEAK_FUNC(sub_820D5368);
PPC_FUNC_IMPL(__imp__sub_820D5368) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// twllei r4,0
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// divw r9,r11,r4
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r4.s32);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// mullw r8,r9,r4
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// subf r6,r8,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r8.s64;
	// andc r5,r4,r7
	ctx.r5.u64 = ctx.r4.u64 & ~ctx.r7.u64;
	// subf r3,r6,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D5398"))) PPC_WEAK_FUNC(sub_820D5398);
PPC_FUNC_IMPL(__imp__sub_820D5398) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820D53A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x820d53e4
	if (!ctx.cr6.gt) goto loc_820D53E4;
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
	// addi r29,r10,-4
	ctx.r29.s64 = ctx.r10.s64 + -4;
loc_820D53CC:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwzu r4,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r4.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// lwzu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x8207dac0
	ctx.lr = 0x820D53DC;
	sub_8207DAC0(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt 0x820d53cc
	if (ctx.cr0.gt) goto loc_820D53CC;
loc_820D53E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D53EC"))) PPC_WEAK_FUNC(sub_820D53EC);
PPC_FUNC_IMPL(__imp__sub_820D53EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D53F0"))) PPC_WEAK_FUNC(sub_820D53F0);
PPC_FUNC_IMPL(__imp__sub_820D53F0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm r5,r5,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x8207dac0
	sub_8207DAC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D5404"))) PPC_WEAK_FUNC(sub_820D5404);
PPC_FUNC_IMPL(__imp__sub_820D5404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5408"))) PPC_WEAK_FUNC(sub_820D5408);
PPC_FUNC_IMPL(__imp__sub_820D5408) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8207da20
	sub_8207DA20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D5414"))) PPC_WEAK_FUNC(sub_820D5414);
PPC_FUNC_IMPL(__imp__sub_820D5414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5418"))) PPC_WEAK_FUNC(sub_820D5418);
PPC_FUNC_IMPL(__imp__sub_820D5418) {
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
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r30,20(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820d5448
	if (!ctx.cr6.gt) goto loc_820D5448;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
loc_820D5448:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d54bc
	if (ctx.cr6.eq) goto loc_820D54BC;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207dac0
	ctx.lr = 0x820D5460;
	sub_8207DAC0(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r30.s64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r30.s64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d54bc
	if (!ctx.cr6.eq) goto loc_820D54BC;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
loc_820D54BC:
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

__attribute__((alias("__imp__sub_820D54D4"))) PPC_WEAK_FUNC(sub_820D54D4);
PPC_FUNC_IMPL(__imp__sub_820D54D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D54D8"))) PPC_WEAK_FUNC(sub_820D54D8);
PPC_FUNC_IMPL(__imp__sub_820D54D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820D54E0;
	__savegprlr_23(ctx, base);
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r28,48(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r5,r7,-262
	ctx.r5.s64 = ctx.r7.s64 + -262;
	// lwz r8,112(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// lwz r26,116(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// add r9,r28,r11
	ctx.r9.u64 = ctx.r28.u64 + ctx.r11.u64;
	// lwz r27,136(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x820d551c
	if (!ctx.cr6.gt) goto loc_820D551C;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// addi r25,r11,262
	ctx.r25.s64 = ctx.r11.s64 + 262;
	// b 0x820d5520
	goto loc_820D5520;
loc_820D551C:
	// li r25,0
	ctx.r25.s64 = 0;
loc_820D5520:
	// add r11,r6,r9
	ctx.r11.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lwz r7,132(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// lwz r30,56(r10)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// addi r5,r9,258
	ctx.r5.s64 = ctx.r9.s64 + 258;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// lwz r29,44(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// lbzx r7,r6,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r9.u32);
	// lbz r31,-1(r11)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// blt cr6,0x820d5548
	if (ctx.cr6.lt) goto loc_820D5548;
	// rlwinm r26,r26,30,2,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 30) & 0x3FFFFFFF;
loc_820D5548:
	// lwz r3,108(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// cmplw cr6,r27,r3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x820d5558
	if (!ctx.cr6.gt) goto loc_820D5558;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_820D5558:
	// add r8,r28,r4
	ctx.r8.u64 = ctx.r28.u64 + ctx.r4.u64;
	// clrlwi r24,r7,24
	ctx.r24.u64 = ctx.r7.u32 & 0xFF;
	// add r11,r8,r6
	ctx.r11.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lbzx r23,r8,r6
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r6.u32);
	// cmplw cr6,r23,r24
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820d5660
	if (!ctx.cr6.eq) goto loc_820D5660;
	// lbz r11,-1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// clrlwi r24,r31,24
	ctx.r24.u64 = ctx.r31.u32 & 0xFF;
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820d5660
	if (!ctx.cr6.eq) goto loc_820D5660;
	// lbz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r24,0(r9)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x820d5660
	if (!ctx.cr6.eq) goto loc_820D5660;
	// lbz r11,1(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// lbzu r24,1(r8)
	ea = 1 + ctx.r8.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r8.u32 = ea;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820d5660
	if (!ctx.cr6.eq) goto loc_820D5660;
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
loc_820D55A8:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r24,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r24.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820d5630
	if (!ctx.cr6.eq) goto loc_820D5630;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x820d55a8
	if (ctx.cr6.lt) goto loc_820D55A8;
loc_820D5630:
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// addi r9,r5,-258
	ctx.r9.s64 = ctx.r5.s64 + -258;
	// addi r11,r11,258
	ctx.r11.s64 = ctx.r11.s64 + 258;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x820d5660
	if (!ctx.cr6.gt) goto loc_820D5660;
	// stw r4,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, ctx.r4.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x820d567c
	if (!ctx.cr6.lt) goto loc_820D567C;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lbzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// lbz r31,-1(r8)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
loc_820D5660:
	// and r11,r29,r4
	ctx.r11.u64 = ctx.r29.u64 & ctx.r4.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r30.u32);
	// cmplw cr6,r4,r25
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r25.u32, ctx.xer);
	// ble cr6,0x820d567c
	if (!ctx.cr6.gt) goto loc_820D567C;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x820d5558
	if (!ctx.cr0.eq) goto loc_820D5558;
loc_820D567C:
	// cmplw cr6,r6,r3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r3.u32, ctx.xer);
	// bgt cr6,0x820d5688
	if (ctx.cr6.gt) goto loc_820D5688;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_820D5688:
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D568C"))) PPC_WEAK_FUNC(sub_820D568C);
PPC_FUNC_IMPL(__imp__sub_820D568C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5690"))) PPC_WEAK_FUNC(sub_820D5690);
PPC_FUNC_IMPL(__imp__sub_820D5690) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D5698;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,36(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_820D56A4:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// subf. r26,r10,r9
	ctx.r26.s64 = ctx.r9.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x820d56d4
	if (!ctx.cr0.eq) goto loc_820D56D4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d56e4
	if (!ctx.cr6.eq) goto loc_820D56E4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820d56e4
	if (!ctx.cr6.eq) goto loc_820D56E4;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// b 0x820d5790
	goto loc_820D5790;
loc_820D56D4:
	// cmpwi cr6,r26,-1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, -1, ctx.xer);
	// bne cr6,0x820d56e4
	if (!ctx.cr6.eq) goto loc_820D56E4;
	// li r26,-2
	ctx.r26.s64 = -2;
	// b 0x820d5790
	goto loc_820D5790;
loc_820D56E4:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// addi r10,r10,-262
	ctx.r10.s64 = ctx.r10.s64 + -262;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820d5790
	if (ctx.cr6.lt) goto loc_820D5790;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// add r4,r3,r28
	ctx.r4.u64 = ctx.r3.u64 + ctx.r28.u64;
	// bl 0x8207dac0
	ctx.lr = 0x820D5708;
	sub_8207DAC0(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r8,r28,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r28.s64;
	// subf r7,r28,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r28.s64;
	// stw r8,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// stw r7,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r7.u32);
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// subf r9,r28,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r28.s64;
	// stw r9,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r9.u32);
loc_820D573C:
	// lhzu r9,-2(r10)
	ea = -2 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// cmplw cr6,r9,r28
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r28.u32, ctx.xer);
	// subf r9,r28,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r28.s64;
	// bge cr6,0x820d5750
	if (!ctx.cr6.lt) goto loc_820D5750;
	// li r9,0
	ctx.r9.s64 = 0;
loc_820D5750:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// bne 0x820d573c
	if (!ctx.cr0.eq) goto loc_820D573C;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_820D576C:
	// lhzu r10,-2(r11)
	ea = -2 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r28.s64;
	// bge cr6,0x820d5780
	if (!ctx.cr6.lt) goto loc_820D5780;
	// li r10,0
	ctx.r10.s64 = 0;
loc_820D5780:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r10,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// bne 0x820d576c
	if (!ctx.cr0.eq) goto loc_820D576C;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
loc_820D5790:
	// lwz r30,0(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d588c
	if (ctx.cr6.eq) goto loc_820D588C;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// add r27,r10,r9
	ctx.r27.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x820d57c8
	if (!ctx.cr6.gt) goto loc_820D57C8;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
loc_820D57C8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820d57d8
	if (!ctx.cr6.eq) goto loc_820D57D8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820d5830
	goto loc_820D5830;
loc_820D57D8:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,24(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820d5804
	if (!ctx.cr6.eq) goto loc_820D5804;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x820de338
	ctx.lr = 0x820D5800;
	sub_820DE338(ctx, base);
	// stw r3,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_820D5804:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207dac0
	ctx.lr = 0x820D5814;
	sub_8207DAC0(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r10,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
loc_820D5830:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x820d5874
	if (ctx.cr6.lt) goto loc_820D5874;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// slw r8,r7,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// xor r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 ^ ctx.r11.u64;
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_820D5874:
	// cmplwi cr6,r10,262
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 262, ctx.xer);
	// bge cr6,0x820d588c
	if (!ctx.cr6.lt) goto loc_820D588C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d56a4
	if (!ctx.cr6.eq) goto loc_820D56A4;
loc_820D588C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D5894"))) PPC_WEAK_FUNC(sub_820D5894);
PPC_FUNC_IMPL(__imp__sub_820D5894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5898"))) PPC_WEAK_FUNC(sub_820D5898);
PPC_FUNC_IMPL(__imp__sub_820D5898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D58A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// ori r30,r30,65535
	ctx.r30.u64 = ctx.r30.u64 | 65535;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// bge cr6,0x820d58c8
	if (!ctx.cr6.lt) goto loc_820D58C8;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_820D58C8:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bgt cr6,0x820d58e8
	if (ctx.cr6.gt) goto loc_820D58E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d5690
	ctx.lr = 0x820D58DC;
	sub_820D5690(ctx, base);
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d59d8
	if (ctx.cr6.eq) goto loc_820D59D8;
loc_820D58E8:
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d5918
	if (ctx.cr6.eq) goto loc_820D5918;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820d596c
	if (ctx.cr6.lt) goto loc_820D596C;
loc_820D5918:
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r9,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// blt cr6,0x820d5938
	if (ctx.cr6.lt) goto loc_820D5938;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820d593c
	goto loc_820D593C;
loc_820D5938:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820D593C:
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r11.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820df998
	ctx.lr = 0x820D594C;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D595C;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d59cc
	if (ctx.cr6.eq) goto loc_820D59CC;
loc_820D596C:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r11.s64;
	// addi r10,r10,-262
	ctx.r10.s64 = ctx.r10.s64 + -262;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820d58c8
	if (ctx.cr6.lt) goto loc_820D58C8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d599c
	if (ctx.cr6.lt) goto loc_820D599C;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820d59a0
	goto loc_820D59A0;
loc_820D599C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820D59A0:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820df998
	ctx.lr = 0x820D59AC;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D59BC;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d58c8
	if (!ctx.cr6.eq) goto loc_820D58C8;
loc_820D59CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D59D0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820D59D8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820d59cc
	if (ctx.cr6.eq) goto loc_820D59CC;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d59f8
	if (ctx.cr6.lt) goto loc_820D59F8;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820d59fc
	goto loc_820D59FC;
loc_820D59F8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820D59FC:
	// addi r10,r29,-4
	ctx.r10.s64 = ctx.r29.s64 + -4;
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r11.s64;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x820df998
	ctx.lr = 0x820D5A18;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D5A28;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d5a50
	if (!ctx.cr6.eq) goto loc_820D5A50;
	// addi r11,r29,-4
	ctx.r11.s64 = ctx.r29.s64 + -4;
	// li r10,2
	ctx.r10.s64 = 2;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x820d59d0
	goto loc_820D59D0;
loc_820D5A50:
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// li r3,3
	ctx.r3.s64 = 3;
	// beq cr6,0x820d59d0
	if (ctx.cr6.eq) goto loc_820D59D0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820d59d0
	goto loc_820D59D0;
}

__attribute__((alias("__imp__sub_820D5A64"))) PPC_WEAK_FUNC(sub_820D5A64);
PPC_FUNC_IMPL(__imp__sub_820D5A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5A68"))) PPC_WEAK_FUNC(sub_820D5A68);
PPC_FUNC_IMPL(__imp__sub_820D5A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D5A70;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// addi r27,r11,640
	ctx.r27.s64 = ctx.r11.s64 + 640;
	// addi r28,r10,1152
	ctx.r28.s64 = ctx.r10.s64 + 1152;
loc_820D5A94:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,262
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 262, ctx.xer);
	// bge cr6,0x820d5ac4
	if (!ctx.cr6.lt) goto loc_820D5AC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d5690
	ctx.lr = 0x820D5AA8;
	sub_820D5690(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,262
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 262, ctx.xer);
	// bge cr6,0x820d5abc
	if (!ctx.cr6.lt) goto loc_820D5ABC;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x820d5dec
	if (ctx.cr6.eq) goto loc_820D5DEC;
loc_820D5ABC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d5df8
	if (ctx.cr6.eq) goto loc_820D5DF8;
loc_820D5AC4:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820d5b2c
	if (ctx.cr6.lt) goto loc_820D5B2C;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// slw r9,r9,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// lwz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lhzx r30,r7,r8
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// sthx r30,r11,r9
	PPC_STORE_U16(ctx.r11.u32 + ctx.r9.u32, ctx.r30.u16);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u16);
loc_820D5B2C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d5b68
	if (ctx.cr6.eq) goto loc_820D5B68;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r30.s64;
	// addi r11,r11,-262
	ctx.r11.s64 = ctx.r11.s64 + -262;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d5b68
	if (ctx.cr6.gt) goto loc_820D5B68;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820d5b68
	if (ctx.cr6.eq) goto loc_820D5B68;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d54d8
	ctx.lr = 0x820D5B64;
	sub_820D54D8(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
loc_820D5B68:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820d5d18
	if (ctx.cr6.lt) goto loc_820D5D18;
	// addi r11,r11,253
	ctx.r11.s64 = ctx.r11.s64 + 253;
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// clrlwi r6,r11,24
	ctx.r6.u64 = ctx.r11.u32 & 0xFF;
	// lwz r7,5788(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5788);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r9,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sthx r11,r7,r10
	PPC_STORE_U16(ctx.r7.u32 + ctx.r10.u32, ctx.r11.u16);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r9,5776(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5776);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stbx r6,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,5784(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5784, ctx.r10.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// lbzx r11,r6,r28
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r28.u32);
	// addi r11,r11,292
	ctx.r11.s64 = ctx.r11.s64 + 292;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// bge cr6,0x820d5bec
	if (!ctx.cr6.lt) goto loc_820D5BEC;
	// lbzx r11,r9,r27
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r27.u32);
	// b 0x820d5bf8
	goto loc_820D5BF8;
loc_820D5BEC:
	// rlwinm r11,r9,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r27,256
	ctx.r10.s64 = ctx.r27.s64 + 256;
	// lbzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
loc_820D5BF8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addi r11,r11,608
	ctx.r11.s64 = ctx.r11.s64 + 608;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lwz r11,5780(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5780);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// subf r7,r10,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r10.s64;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	// cntlzw r9,r7
	ctx.r9.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bgt cr6,0x820d5cd0
	if (ctx.cr6.gt) goto loc_820D5CD0;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x820d5cd0
	if (ctx.cr6.lt) goto loc_820D5CD0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_820D5C54:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// slw r8,r8,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r7.u8 & 0x3F));
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// and r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 & ctx.r11.u64;
	// lwz r6,56(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// xor r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lhzx r30,r8,r5
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r5.u32);
	// sthx r30,r11,r6
	PPC_STORE_U16(ctx.r11.u32 + ctx.r6.u32, ctx.r30.u16);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// sthx r10,r8,r11
	PPC_STORE_U16(ctx.r8.u32 + ctx.r11.u32, ctx.r10.u16);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// bne 0x820d5c54
	if (!ctx.cr0.eq) goto loc_820D5C54;
	// b 0x820d5d88
	goto loc_820D5D88;
loc_820D5CD0:
	// stw r29,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r29.u32);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// xor r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// and r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 & ctx.r7.u64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// b 0x820d5d94
	goto loc_820D5D94;
loc_820D5D18:
	// lwz r11,5784(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,5788(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5788);
	// lbzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// sthx r29,r8,r11
	PPC_STORE_U16(ctx.r8.u32 + ctx.r11.u32, ctx.r29.u16);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// addi r11,r11,35
	ctx.r11.s64 = ctx.r11.s64 + 35;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,5776(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5776);
	// lwz r8,5784(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// stbx r10,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,5784(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5784, ctx.r10.u32);
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// lwz r9,5784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r10,5780(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5780);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_820D5D88:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_820D5D94:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820d5a94
	if (ctx.cr6.eq) goto loc_820D5A94;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d5db4
	if (ctx.cr6.lt) goto loc_820D5DB4;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820d5db8
	goto loc_820D5DB8;
loc_820D5DB4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820D5DB8:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r11.s64;
	// bl 0x820df998
	ctx.lr = 0x820D5DCC;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D5DDC;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d5a94
	if (!ctx.cr6.eq) goto loc_820D5A94;
loc_820D5DEC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D5DF0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820D5DF8:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d5e10
	if (ctx.cr6.lt) goto loc_820D5E10;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820d5e14
	goto loc_820D5E14;
loc_820D5E10:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820D5E14:
	// addi r10,r26,-4
	ctx.r10.s64 = ctx.r26.s64 + -4;
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r11.s64;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x820df998
	ctx.lr = 0x820D5E30;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D5E40;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d5e68
	if (!ctx.cr6.eq) goto loc_820D5E68;
	// addi r11,r26,-4
	ctx.r11.s64 = ctx.r26.s64 + -4;
	// li r10,2
	ctx.r10.s64 = 2;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x820d5df0
	goto loc_820D5DF0;
loc_820D5E68:
	// cmpwi cr6,r26,4
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 4, ctx.xer);
	// li r3,3
	ctx.r3.s64 = 3;
	// beq cr6,0x820d5df0
	if (ctx.cr6.eq) goto loc_820D5DF0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820d5df0
	goto loc_820D5DF0;
}

__attribute__((alias("__imp__sub_820D5E7C"))) PPC_WEAK_FUNC(sub_820D5E7C);
PPC_FUNC_IMPL(__imp__sub_820D5E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D5E80"))) PPC_WEAK_FUNC(sub_820D5E80);
PPC_FUNC_IMPL(__imp__sub_820D5E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820D5E88;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// li r25,2
	ctx.r25.s64 = 2;
	// ori r30,r9,65535
	ctx.r30.u64 = ctx.r9.u64 | 65535;
	// addi r26,r11,640
	ctx.r26.s64 = ctx.r11.s64 + 640;
	// addi r27,r10,1152
	ctx.r27.s64 = ctx.r10.s64 + 1152;
loc_820D5EB8:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,262
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 262, ctx.xer);
	// bge cr6,0x820d5ee8
	if (!ctx.cr6.lt) goto loc_820D5EE8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d5690
	ctx.lr = 0x820D5ECC;
	sub_820D5690(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,262
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 262, ctx.xer);
	// bge cr6,0x820d5ee0
	if (!ctx.cr6.lt) goto loc_820D5EE0;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820d6298
	if (ctx.cr6.eq) goto loc_820D6298;
loc_820D5EE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d62c8
	if (ctx.cr6.eq) goto loc_820D62C8;
loc_820D5EE8:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820d5f50
	if (ctx.cr6.lt) goto loc_820D5F50;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// slw r9,r9,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// lwz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lhzx r28,r7,r8
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// sthx r28,r11,r9
	PPC_STORE_U16(ctx.r11.u32 + ctx.r9.u32, ctx.r28.u16);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u16);
loc_820D5F50:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// stw r25,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r25.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// beq cr6,0x820d5fe8
	if (ctx.cr6.eq) goto loc_820D5FE8;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820d5fe8
	if (!ctx.cr6.lt) goto loc_820D5FE8;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-262
	ctx.r11.s64 = ctx.r11.s64 + -262;
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r28.s64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d5fe8
	if (ctx.cr6.gt) goto loc_820D5FE8;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820d5fb0
	if (ctx.cr6.eq) goto loc_820D5FB0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d54d8
	ctx.lr = 0x820D5FAC;
	sub_820D54D8(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
loc_820D5FB0:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x820d5fe8
	if (ctx.cr6.gt) goto loc_820D5FE8;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x820d5fe4
	if (ctx.cr6.eq) goto loc_820D5FE4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820d5fe8
	if (!ctx.cr6.eq) goto loc_820D5FE8;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// ble cr6,0x820d5fe8
	if (!ctx.cr6.gt) goto loc_820D5FE8;
loc_820D5FE4:
	// stw r25,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r25.u32);
loc_820D5FE8:
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820d61c0
	if (ctx.cr6.lt) goto loc_820D61C0;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d61c0
	if (ctx.cr6.gt) goto loc_820D61C0;
	// addi r10,r11,253
	ctx.r10.s64 = ctx.r11.s64 + 253;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// lwz r8,5784(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r6,5788(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5788);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r8,r11,-3
	ctx.r8.s64 = ctx.r11.s64 + -3;
	// add r11,r10,r30
	ctx.r11.u64 = ctx.r10.u64 + ctx.r30.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sthx r10,r5,r6
	PPC_STORE_U16(ctx.r5.u32 + ctx.r6.u32, ctx.r10.u16);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// lwz r11,5776(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5776);
	// stbx r7,r11,r10
	PPC_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r7.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r11,5784(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5784, ctx.r11.u32);
	// lbzx r11,r7,r27
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r27.u32);
	// addi r11,r11,292
	ctx.r11.s64 = ctx.r11.s64 + 292;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// bge cr6,0x820d6084
	if (!ctx.cr6.lt) goto loc_820D6084;
	// lbzx r11,r9,r26
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r26.u32);
	// b 0x820d6090
	goto loc_820D6090;
loc_820D6084:
	// rlwinm r11,r9,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r26,256
	ctx.r10.s64 = ctx.r26.s64 + 256;
	// lbzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
loc_820D6090:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addi r11,r11,608
	ctx.r11.s64 = ctx.r11.s64 + 608;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r7,5784(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r10,5780(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5780);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	// subf r9,r7,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r7.s64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
loc_820D60DC:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x820d614c
	if (ctx.cr6.gt) goto loc_820D614C;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// slw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// and r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 & ctx.r11.u64;
	// lwz r6,60(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// and r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 & ctx.r5.u64;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lhzx r28,r5,r6
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r6.u32);
	// sthx r28,r11,r7
	PPC_STORE_U16(ctx.r11.u32 + ctx.r7.u32, ctx.r28.u16);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r7,r10
	PPC_STORE_U16(ctx.r7.u32 + ctx.r10.u32, ctx.r11.u16);
loc_820D614C:
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bne 0x820d60dc
	if (!ctx.cr0.eq) goto loc_820D60DC;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r29,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r25,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r25.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// beq cr6,0x820d5eb8
	if (ctx.cr6.eq) goto loc_820D5EB8;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d6190
	if (ctx.cr6.lt) goto loc_820D6190;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// b 0x820d6194
	goto loc_820D6194;
loc_820D6190:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820D6194:
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r11.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820df998
	ctx.lr = 0x820D61A4;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D61B4;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x820d6290
	goto loc_820D6290;
loc_820D61C0:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d62a4
	if (ctx.cr6.eq) goto loc_820D62A4;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,5784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,5788(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5788);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// sthx r29,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r29.u16);
	// lwz r9,5776(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5776);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// addi r11,r11,35
	ctx.r11.s64 = ctx.r11.s64 + 35;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// stbx r8,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,5784(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5784, ctx.r10.u32);
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// lwz r11,5780(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5780);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820d6270
	if (!ctx.cr6.eq) goto loc_820D6270;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d6248
	if (ctx.cr6.lt) goto loc_820D6248;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820d624c
	goto loc_820D624C;
loc_820D6248:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820D624C:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r11.s64;
	// bl 0x820df998
	ctx.lr = 0x820D6260;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D6270;
	sub_820D5418(ctx, base);
loc_820D6270:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
loc_820D6290:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d5eb8
	if (!ctx.cr6.eq) goto loc_820D5EB8;
loc_820D6298:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D629C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_820D62A4:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stw r10,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// b 0x820d5eb8
	goto loc_820D5EB8;
loc_820D62C8:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d6328
	if (ctx.cr6.eq) goto loc_820D6328;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,5784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,5788(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5788);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// sthx r29,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r29.u16);
	// lwz r9,5784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// addi r11,r11,35
	ctx.r11.s64 = ctx.r11.s64 + 35;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,5776(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5776);
	// stbx r8,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u8);
	// lwz r10,5784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5784);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,5784(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5784, ctx.r10.u32);
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// stw r29,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
loc_820D6328:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x820d6340
	if (ctx.cr6.lt) goto loc_820D6340;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820d6344
	goto loc_820D6344;
loc_820D6340:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_820D6344:
	// addi r10,r24,-4
	ctx.r10.s64 = ctx.r24.s64 + -4;
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r11.s64;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x820df998
	ctx.lr = 0x820D6360;
	sub_820DF998(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x820d5418
	ctx.lr = 0x820D6370;
	sub_820D5418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d6394
	if (!ctx.cr6.eq) goto loc_820D6394;
	// addi r11,r24,-4
	ctx.r11.s64 = ctx.r24.s64 + -4;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r25
	ctx.r3.u64 = ctx.r11.u64 & ctx.r25.u64;
	// b 0x820d629c
	goto loc_820D629C;
loc_820D6394:
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// li r3,3
	ctx.r3.s64 = 3;
	// beq cr6,0x820d629c
	if (ctx.cr6.eq) goto loc_820D629C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820d629c
	goto loc_820D629C;
}

__attribute__((alias("__imp__sub_820D63A8"))) PPC_WEAK_FUNC(sub_820D63A8);
PPC_FUNC_IMPL(__imp__sub_820D63A8) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d640c
	if (ctx.cr6.eq) goto loc_820D640C;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d640c
	if (ctx.cr6.eq) goto loc_820D640C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r10.s64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ctx.r9.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x820dfd80
	ctx.lr = 0x820D6404;
	sub_820DFD80(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820d6410
	goto loc_820D6410;
loc_820D640C:
	// li r3,-2
	ctx.r3.s64 = -2;
loc_820D6410:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D6420"))) PPC_WEAK_FUNC(sub_820D6420);
PPC_FUNC_IMPL(__imp__sub_820D6420) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d648c
	if (ctx.cr6.eq) goto loc_820D648C;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d648c
	if (ctx.cr6.eq) goto loc_820D648C;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d648c
	if (ctx.cr6.eq) goto loc_820D648C;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d6468
	if (ctx.cr6.eq) goto loc_820D6468;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820e0780
	ctx.lr = 0x820D6468;
	sub_820E0780(ctx, base);
loc_820D6468:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D647C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// b 0x820d6490
	goto loc_820D6490;
loc_820D648C:
	// li r3,-2
	ctx.r3.s64 = -2;
loc_820D6490:
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

__attribute__((alias("__imp__sub_820D64A4"))) PPC_WEAK_FUNC(sub_820D64A4);
PPC_FUNC_IMPL(__imp__sub_820D64A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D64A8"))) PPC_WEAK_FUNC(sub_820D64A8);
PPC_FUNC_IMPL(__imp__sub_820D64A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D64B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820d65f8
	if (ctx.cr6.eq) goto loc_820D65F8;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,49
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 49, ctx.xer);
	// bne cr6,0x820d65f8
	if (!ctx.cr6.eq) goto loc_820D65F8;
	// cmplwi cr6,r6,56
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 56, ctx.xer);
	// bne cr6,0x820d65f8
	if (!ctx.cr6.eq) goto loc_820D65F8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820d64e8
	if (!ctx.cr6.eq) goto loc_820D64E8;
	// li r3,-2
	ctx.r3.s64 = -2;
	// b 0x820d65fc
	goto loc_820D65FC;
loc_820D64E8:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d650c
	if (!ctx.cr6.eq) goto loc_820D650C;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// addi r11,r11,-752
	ctx.r11.s64 = ctx.r11.s64 + -752;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_820D650C:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d6524
	if (!ctx.cr6.eq) goto loc_820D6524;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// addi r11,r11,-656
	ctx.r11.s64 = ctx.r11.s64 + -656;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_820D6524:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D653C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// bne 0x820d6550
	if (!ctx.cr0.eq) goto loc_820D6550;
	// li r3,-4
	ctx.r3.s64 = -4;
	// b 0x820d65fc
	goto loc_820D65FC;
loc_820D6550:
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r29.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r29.u32);
	// bge cr6,0x820d6574
	if (!ctx.cr6.lt) goto loc_820D6574;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
loc_820D6574:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// blt cr6,0x820d65e4
	if (ctx.cr6.lt) goto loc_820D65E4;
	// cmpwi cr6,r30,15
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 15, ctx.xer);
	// bgt cr6,0x820d65e4
	if (ctx.cr6.gt) goto loc_820D65E4;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r9,-32242
	ctx.r9.s64 = -2113011712;
	// stw r30,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r30.u32);
	// slw r5,r11,r30
	ctx.r5.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r30.u8 & 0x3F));
	// addi r11,r9,-7368
	ctx.r11.s64 = ctx.r9.s64 + -7368;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addic r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & ctx.r11.u64;
	// bl 0x820dfe48
	ctx.lr = 0x820D65B4;
	sub_820DFE48(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r3,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d65d4
	if (!ctx.cr6.eq) goto loc_820D65D4;
	// li r30,-4
	ctx.r30.s64 = -4;
	// b 0x820d65e8
	goto loc_820D65E8;
loc_820D65D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d63a8
	ctx.lr = 0x820D65DC;
	sub_820D63A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820d65fc
	goto loc_820D65FC;
loc_820D65E4:
	// li r30,-2
	ctx.r30.s64 = -2;
loc_820D65E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d6420
	ctx.lr = 0x820D65F0;
	sub_820D6420(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x820d65fc
	goto loc_820D65FC;
loc_820D65F8:
	// li r3,-6
	ctx.r3.s64 = -6;
loc_820D65FC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D6604"))) PPC_WEAK_FUNC(sub_820D6604);
PPC_FUNC_IMPL(__imp__sub_820D6604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D6608"))) PPC_WEAK_FUNC(sub_820D6608);
PPC_FUNC_IMPL(__imp__sub_820D6608) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,15
	ctx.r4.s64 = 15;
	// b 0x820d64a8
	sub_820D64A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D6618"))) PPC_WEAK_FUNC(sub_820D6618);
PPC_FUNC_IMPL(__imp__sub_820D6618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x820D6620;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d69c0
	if (ctx.cr6.eq) goto loc_820D69C0;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69c0
	if (ctx.cr6.eq) goto loc_820D69C0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d69c0
	if (ctx.cr6.eq) goto loc_820D69C0;
	// addi r10,r4,-4
	ctx.r10.s64 = ctx.r4.s64 + -4;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r30,-5
	ctx.r30.s64 = -5;
	// addic r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r7,13
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 13, ctx.xer);
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r29,r11,r30
	ctx.r29.u64 = ctx.r11.u64 & ctx.r30.u64;
	// bgt cr6,0x820d69c0
	if (ctx.cr6.gt) goto loc_820D69C0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r28,13
	ctx.r28.s64 = 13;
	// li r27,5
	ctx.r27.s64 = 5;
	// li r22,0
	ctx.r22.s64 = 0;
	// li r21,12
	ctx.r21.s64 = 12;
	// addi r26,r11,-2756
	ctx.r26.s64 = ctx.r11.s64 + -2756;
	// addi r25,r10,-2780
	ctx.r25.s64 = ctx.r10.s64 + -2780;
	// addi r24,r9,-2800
	ctx.r24.s64 = ctx.r9.s64 + -2800;
	// addi r23,r8,-2828
	ctx.r23.s64 = ctx.r8.s64 + -2828;
loc_820D6698:
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// rlwinm r0,r7,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,-2872
	ctx.r12.s64 = ctx.r12.s64 + -2872;
	// lhzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32243
	ctx.r12.s64 = -2113077248;
	// addi r12,r12,26304
	ctx.r12.s64 = ctx.r12.s64 + 26304;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r7.u64) {
	case 0:
		goto loc_820D66C0;
	case 1:
		goto loc_820D674C;
	case 2:
		goto loc_820D69DC;
	case 3:
		goto loc_820D6A2C;
	case 4:
		goto loc_820D6A84;
	case 5:
		goto loc_820D6AD8;
	case 6:
		goto loc_820D6B38;
	case 7:
		goto loc_820D67C4;
	case 8:
		goto loc_820D6844;
	case 9:
		goto loc_820D6894;
	case 10:
		goto loc_820D68EC;
	case 11:
		goto loc_820D6944;
	case 12:
		goto loc_820D6B5C;
	case 13:
		goto loc_820D6B64;
	default:
		__builtin_unreachable();
	}
loc_820D66C0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820d6720
	if (ctx.cr6.eq) goto loc_820D6720;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r23,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r23.u32);
	// b 0x820d69a8
	goto loc_820D69A8;
loc_820D6720:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x820d6744
	if (!ctx.cr6.gt) goto loc_820D6744;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r24,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r24.u32);
	// b 0x820d69a8
	goto loc_820D69A8;
loc_820D6744:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_820D674C:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,31
	ctx.r8.s64 = 31;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// divwu r8,r9,r8
	ctx.r8.u32 = ppc_divwu(ctx.r9.u32, ctx.r8.u32);
	// mulli r8,r8,31
	ctx.r8.s64 = ctx.r8.s64 * 31;
	// subf. r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820d67b0
	if (ctx.cr0.eq) goto loc_820D67B0;
	// stw r28,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r28.u32);
	// stw r25,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r25.u32);
	// b 0x820d69a8
	goto loc_820D69A8;
loc_820D67B0:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d69d4
	if (!ctx.cr0.eq) goto loc_820D69D4;
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// b 0x820d69b0
	goto loc_820D69B0;
loc_820D67C4:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x820dff30
	ctx.lr = 0x820D67D8;
	sub_820DFF30(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -3, ctx.xer);
	// bne cr6,0x820d67f8
	if (!ctx.cr6.eq) goto loc_820D67F8;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r22,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// b 0x820d69b0
	goto loc_820D69B0;
loc_820D67F8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x820d6804
	if (!ctx.cr6.eq) goto loc_820D6804;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_820D6804:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bne cr6,0x820d69cc
	if (!ctx.cr6.eq) goto loc_820D69CC;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x820dfd80
	ctx.lr = 0x820D6824;
	sub_820DFD80(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820d683c
	if (ctx.cr6.eq) goto loc_820D683C;
	// stw r21,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r21.u32);
	// b 0x820d69b0
	goto loc_820D69B0;
loc_820D683C:
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_820D6844:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,9
	ctx.r8.s64 = 9;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// rotlwi r11,r11,24
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 24);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_820D6894:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,10
	ctx.r8.s64 = 10;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_820D68EC:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r7,11
	ctx.r7.s64 = 11;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
loc_820D6944:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820d6b58
	if (ctx.cr6.eq) goto loc_820D6B58;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
loc_820D69A8:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r27,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
loc_820D69B0:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r7,13
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 13, ctx.xer);
	// ble cr6,0x820d6698
	if (!ctx.cr6.gt) goto loc_820D6698;
loc_820D69C0:
	// li r3,-2
	ctx.r3.s64 = -2;
loc_820D69C4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_820D69CC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x820d69c4
	goto loc_820D69C4;
loc_820D69D4:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_820D69DC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// rotlwi r11,r11,24
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 24);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_820D6A2C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_820D6A84:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r27,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r27.u32);
loc_820D6AD8:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d69cc
	if (ctx.cr6.eq) goto loc_820D69CC;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// b 0x820d69c4
	goto loc_820D69C4;
loc_820D6B38:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r10,r10,-2844
	ctx.r10.s64 = ctx.r10.s64 + -2844;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// b 0x820d69c0
	goto loc_820D69C0;
loc_820D6B58:
	// stw r21,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r21.u32);
loc_820D6B5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820d69c4
	goto loc_820D69C4;
loc_820D6B64:
	// li r3,-3
	ctx.r3.s64 = -3;
	// b 0x820d69c4
	goto loc_820D69C4;
}

__attribute__((alias("__imp__sub_820D6B6C"))) PPC_WEAK_FUNC(sub_820D6B6C);
PPC_FUNC_IMPL(__imp__sub_820D6B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D6B70"))) PPC_WEAK_FUNC(sub_820D6B70);
PPC_FUNC_IMPL(__imp__sub_820D6B70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D6B78;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D6B8C;
	sub_820D0998(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D6B9C;
	sub_820CAD78(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D6BA4"))) PPC_WEAK_FUNC(sub_820D6BA4);
PPC_FUNC_IMPL(__imp__sub_820D6BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D6BA8"))) PPC_WEAK_FUNC(sub_820D6BA8);
PPC_FUNC_IMPL(__imp__sub_820D6BA8) {
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
	// lbz r11,1548(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1548);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,1372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1372);
	// beq 0x820d6be8
	if (ctx.cr0.eq) goto loc_820D6BE8;
	// rlwinm r11,r11,0,22,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x300;
	// cmplwi cr6,r11,768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 768, ctx.xer);
	// bne cr6,0x820d6bf8
	if (!ctx.cr6.eq) goto loc_820D6BF8;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x820d6bf8
	goto loc_820D6BF8;
loc_820D6BE8:
	// rlwinm r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 & ctx.r30.u64;
loc_820D6BF8:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D6C08;
	sub_820D0998(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820d6c54
	if (ctx.cr6.eq) goto loc_820D6C54;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lbz r7,83(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r8,1536(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1536);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subf r11,r11,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r11.s64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x820d6c58
	goto loc_820D6C58;
loc_820D6C54:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D6C58:
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

__attribute__((alias("__imp__sub_820D6C70"))) PPC_WEAK_FUNC(sub_820D6C70);
PPC_FUNC_IMPL(__imp__sub_820D6C70) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,41
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 41, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
	// cmplwi cr6,r11,122
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 122, ctx.xer);
	// bgt cr6,0x820d6d00
	if (ctx.cr6.gt) goto loc_820D6D00;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x820d6c94
	if (!ctx.cr6.gt) goto loc_820D6C94;
	// cmplwi cr6,r11,97
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 97, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
loc_820D6C94:
	// lbz r11,1(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// cmplwi cr6,r11,41
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 41, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
	// cmplwi cr6,r11,122
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 122, ctx.xer);
	// bgt cr6,0x820d6d00
	if (ctx.cr6.gt) goto loc_820D6D00;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x820d6cb8
	if (!ctx.cr6.gt) goto loc_820D6CB8;
	// cmplwi cr6,r11,97
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 97, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
loc_820D6CB8:
	// lbz r11,2(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi cr6,r11,41
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 41, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
	// cmplwi cr6,r11,122
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 122, ctx.xer);
	// bgt cr6,0x820d6d00
	if (ctx.cr6.gt) goto loc_820D6D00;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// ble cr6,0x820d6cdc
	if (!ctx.cr6.gt) goto loc_820D6CDC;
	// cmplwi cr6,r11,97
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 97, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
loc_820D6CDC:
	// lbz r11,3(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// cmplwi cr6,r11,41
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 41, ctx.xer);
	// blt cr6,0x820d6d00
	if (ctx.cr6.lt) goto loc_820D6D00;
	// cmplwi cr6,r11,122
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 122, ctx.xer);
	// bgt cr6,0x820d6d00
	if (ctx.cr6.gt) goto loc_820D6D00;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r11,97
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 97, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_820D6D00:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2612
	ctx.r4.s64 = ctx.r11.s64 + -2612;
	// b 0x820cabb0
	sub_820CABB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D6D0C"))) PPC_WEAK_FUNC(sub_820D6D0C);
PPC_FUNC_IMPL(__imp__sub_820D6D0C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D6D10"))) PPC_WEAK_FUNC(sub_820D6D10);
PPC_FUNC_IMPL(__imp__sub_820D6D10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D6D18;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r9,1531(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1531);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,1500(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1500);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,255
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 255, ctx.xer);
	// bne cr6,0x820d6d54
	if (!ctx.cr6.eq) goto loc_820D6D54;
	// lwz r8,1464(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1464);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// mullw r11,r9,r8
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r5,r11,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x8207dac0
	ctx.lr = 0x820D6D50;
	sub_8207DAC0(ctx, base);
	// b 0x820d6f64
	goto loc_820D6F64;
loc_820D6D54:
	// lwz r11,1464(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1464);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// beq cr6,0x820d6ee0
	if (ctx.cr6.eq) goto loc_820D6EE0;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// beq cr6,0x820d6e58
	if (ctx.cr6.eq) goto loc_820D6E58;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// beq cr6,0x820d6dd0
	if (ctx.cr6.eq) goto loc_820D6DD0;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// rlwinm r29,r9,29,3,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// li r28,128
	ctx.r28.s64 = 128;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d6f64
	if (ctx.cr6.eq) goto loc_820D6F64;
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
loc_820D6D8C:
	// clrlwi r27,r28,24
	ctx.r27.u64 = ctx.r28.u32 & 0xFF;
	// and. r11,r27,r25
	ctx.r11.u64 = ctx.r27.u64 & ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d6da8
	if (ctx.cr0.eq) goto loc_820D6DA8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x820D6DA8;
	sub_8207DAC0(ctx, base);
loc_820D6DA8:
	// add r31,r29,r31
	ctx.r31.u64 = ctx.r29.u64 + ctx.r31.u64;
	// add r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 + ctx.r30.u64;
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// bne cr6,0x820d6dc0
	if (!ctx.cr6.eq) goto loc_820D6DC0;
	// li r28,128
	ctx.r28.s64 = 128;
	// b 0x820d6dc4
	goto loc_820D6DC4;
loc_820D6DC0:
	// rlwinm r28,r28,31,25,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x7F;
loc_820D6DC4:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x820d6d8c
	if (!ctx.cr0.eq) goto loc_820D6D8C;
	// b 0x820d6f64
	goto loc_820D6F64;
loc_820D6DD0:
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r10,4
	ctx.r10.s64 = 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d6f64
	if (ctx.cr6.eq) goto loc_820D6F64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D6DE8:
	// and. r11,r8,r25
	ctx.r11.u64 = ctx.r8.u64 & ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d6e20
	if (ctx.cr0.eq) goto loc_820D6E20;
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// subfic r5,r10,4
	ctx.xer.ca = ctx.r10.u32 <= 4;
	ctx.r5.s64 = 4 - ctx.r10.s64;
	// lbz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// srw r11,r11,r7
	ctx.r11.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r7.u8 & 0x3F));
	// li r3,3855
	ctx.r3.s64 = 3855;
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// sraw r7,r3,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r7.s64 = ctx.r3.s32 >> temp.u32;
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// and r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 & ctx.r6.u64;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
loc_820D6E20:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d6e38
	if (!ctx.cr6.eq) goto loc_820D6E38;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x820d6e3c
	goto loc_820D6E3C;
loc_820D6E38:
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_820D6E3C:
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x820d6e4c
	if (!ctx.cr6.eq) goto loc_820D6E4C;
	// li r8,128
	ctx.r8.s64 = 128;
	// b 0x820d6e50
	goto loc_820D6E50;
loc_820D6E4C:
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
loc_820D6E50:
	// bdnz 0x820d6de8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D6DE8;
	// b 0x820d6f64
	goto loc_820D6F64;
loc_820D6E58:
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r10,6
	ctx.r10.s64 = 6;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d6f64
	if (ctx.cr6.eq) goto loc_820D6F64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D6E70:
	// and. r11,r8,r25
	ctx.r11.u64 = ctx.r8.u64 & ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d6ea8
	if (ctx.cr0.eq) goto loc_820D6EA8;
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// subfic r5,r10,6
	ctx.xer.ca = ctx.r10.u32 <= 6;
	ctx.r5.s64 = 6 - ctx.r10.s64;
	// lbz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// srw r11,r11,r7
	ctx.r11.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r7.u8 & 0x3F));
	// li r3,16191
	ctx.r3.s64 = 16191;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// sraw r7,r3,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r7.s64 = ctx.r3.s32 >> temp.u32;
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// and r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 & ctx.r6.u64;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
loc_820D6EA8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d6ec0
	if (!ctx.cr6.eq) goto loc_820D6EC0;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x820d6ec4
	goto loc_820D6EC4;
loc_820D6EC0:
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
loc_820D6EC4:
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x820d6ed4
	if (!ctx.cr6.eq) goto loc_820D6ED4;
	// li r8,128
	ctx.r8.s64 = 128;
	// b 0x820d6ed8
	goto loc_820D6ED8;
loc_820D6ED4:
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
loc_820D6ED8:
	// bdnz 0x820d6e70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D6E70;
	// b 0x820d6f64
	goto loc_820D6F64;
loc_820D6EE0:
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r10,7
	ctx.r10.s64 = 7;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d6f64
	if (ctx.cr6.eq) goto loc_820D6F64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D6EF8:
	// and. r11,r8,r25
	ctx.r11.u64 = ctx.r8.u64 & ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d6f30
	if (ctx.cr0.eq) goto loc_820D6F30;
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// subfic r5,r10,7
	ctx.xer.ca = ctx.r10.u32 <= 7;
	ctx.r5.s64 = 7 - ctx.r10.s64;
	// lbz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// srw r11,r11,r7
	ctx.r11.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r7.u8 & 0x3F));
	// li r3,32639
	ctx.r3.s64 = 32639;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// sraw r7,r3,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r7.s64 = ctx.r3.s32 >> temp.u32;
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// and r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 & ctx.r6.u64;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
loc_820D6F30:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820d6f48
	if (!ctx.cr6.eq) goto loc_820D6F48;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x820d6f4c
	goto loc_820D6F4C;
loc_820D6F48:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_820D6F4C:
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x820d6f5c
	if (!ctx.cr6.eq) goto loc_820D6F5C;
	// li r8,128
	ctx.r8.s64 = 128;
	// b 0x820d6f60
	goto loc_820D6F60;
loc_820D6F5C:
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
loc_820D6F60:
	// bdnz 0x820d6ef8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D6EF8;
loc_820D6F64:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D6F6C"))) PPC_WEAK_FUNC(sub_820D6F6C);
PPC_FUNC_IMPL(__imp__sub_820D6F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D6F70"))) PPC_WEAK_FUNC(sub_820D6F70);
PPC_FUNC_IMPL(__imp__sub_820D6F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820D6F78;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820d72a4
	if (ctx.cr6.eq) goto loc_820D72A4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d72a4
	if (ctx.cr6.eq) goto loc_820D72A4;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// addi r9,r9,-2704
	ctx.r9.s64 = ctx.r9.s64 + -2704;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// lwzx r25,r8,r9
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// mullw r27,r11,r25
	ctx.r27.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// beq cr6,0x820d71cc
	if (ctx.cr6.eq) goto loc_820D71CC;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820d7100
	if (ctx.cr6.eq) goto loc_820D7100;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// beq cr6,0x820d703c
	if (ctx.cr6.eq) goto loc_820D703C;
	// rlwinm r31,r10,29,3,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// mullw r10,r10,r31
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// mullw r9,r9,r31
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r31.s32);
	// add r30,r10,r4
	ctx.r30.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r26,r9,r4
	ctx.r26.u64 = ctx.r9.u64 + ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d728c
	if (ctx.cr6.eq) goto loc_820D728C;
loc_820D6FEC:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207dac0
	ctx.lr = 0x820D6FFC;
	sub_8207DAC0(ctx, base);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x820d7024
	if (!ctx.cr6.gt) goto loc_820D7024;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
loc_820D7008:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8207dac0
	ctx.lr = 0x820D7018;
	sub_8207DAC0(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// subf r26,r31,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r31.s64;
	// bne 0x820d7008
	if (!ctx.cr0.eq) goto loc_820D7008;
loc_820D7024:
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// subf r30,r31,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r31.s64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d6fec
	if (ctx.cr6.lt) goto loc_820D6FEC;
	// b 0x820d728c
	goto loc_820D728C;
loc_820D703C:
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// addi r8,r27,-1
	ctx.r8.s64 = ctx.r27.s64 + -1;
	// addi r7,r27,-1
	ctx.r7.s64 = ctx.r27.s64 + -1;
	// rlwinm r6,r9,2,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x4;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r8,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r5,r7,2,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x4;
	// subfic r8,r6,4
	ctx.xer.ca = ctx.r6.u32 <= 4;
	ctx.r8.s64 = 4 - ctx.r6.s64;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// subfic r10,r5,4
	ctx.xer.ca = ctx.r5.u32 <= 4;
	ctx.r10.s64 = 4 - ctx.r5.s64;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d728c
	if (ctx.cr6.eq) goto loc_820D728C;
loc_820D7078:
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// clrlwi r5,r8,24
	ctx.r5.u64 = ctx.r8.u32 & 0xFF;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// srw r11,r11,r5
	ctx.r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r5.u8 & 0x3F));
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// ble cr6,0x820d70d4
	if (!ctx.cr6.gt) goto loc_820D70D4;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
loc_820D7098:
	// subfic r4,r10,4
	ctx.xer.ca = ctx.r10.u32 <= 4;
	ctx.r4.s64 = 4 - ctx.r10.s64;
	// lbz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// li r3,3855
	ctx.r3.s64 = 3855;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// sraw r4,r3,r4
	temp.u32 = ctx.r4.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r4.s64 = ctx.r3.s32 >> temp.u32;
	// and r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 & ctx.r5.u64;
	// slw r4,r11,r10
	ctx.r4.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r5,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r5.u8);
	// bne cr6,0x820d70cc
	if (!ctx.cr6.eq) goto loc_820D70CC;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x820d70d0
	goto loc_820D70D0;
loc_820D70CC:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_820D70D0:
	// bdnz 0x820d7098
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D7098;
loc_820D70D4:
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// bne cr6,0x820d70e8
	if (!ctx.cr6.eq) goto loc_820D70E8;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// b 0x820d70ec
	goto loc_820D70EC;
loc_820D70E8:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
loc_820D70EC:
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d7078
	if (ctx.cr6.lt) goto loc_820D7078;
	// b 0x820d728c
	goto loc_820D728C;
loc_820D7100:
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// clrlwi r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// clrlwi r6,r9,30
	ctx.r6.u64 = ctx.r9.u32 & 0x3;
	// addi r7,r27,-1
	ctx.r7.s64 = ctx.r27.s64 + -1;
	// subfic r5,r10,3
	ctx.xer.ca = ctx.r10.u32 <= 3;
	ctx.r5.s64 = 3 - ctx.r10.s64;
	// rlwinm r10,r8,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r7,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// subfic r6,r6,3
	ctx.xer.ca = ctx.r6.u32 <= 3;
	ctx.r6.s64 = 3 - ctx.r6.s64;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d728c
	if (ctx.cr6.eq) goto loc_820D728C;
loc_820D7144:
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// srw r11,r11,r5
	ctx.r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r5.u8 & 0x3F));
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// ble cr6,0x820d71a0
	if (!ctx.cr6.gt) goto loc_820D71A0;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
loc_820D7164:
	// subfic r4,r10,6
	ctx.xer.ca = ctx.r10.u32 <= 6;
	ctx.r4.s64 = 6 - ctx.r10.s64;
	// lbz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// li r3,16191
	ctx.r3.s64 = 16191;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// sraw r4,r3,r4
	temp.u32 = ctx.r4.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r4.s64 = ctx.r3.s32 >> temp.u32;
	// and r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 & ctx.r5.u64;
	// slw r4,r11,r10
	ctx.r4.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r5,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r5.u8);
	// bne cr6,0x820d7198
	if (!ctx.cr6.eq) goto loc_820D7198;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// b 0x820d719c
	goto loc_820D719C;
loc_820D7198:
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
loc_820D719C:
	// bdnz 0x820d7164
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D7164;
loc_820D71A0:
	// cmpwi cr6,r9,6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 6, ctx.xer);
	// bne cr6,0x820d71b4
	if (!ctx.cr6.eq) goto loc_820D71B4;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// b 0x820d71b8
	goto loc_820D71B8;
loc_820D71B4:
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
loc_820D71B8:
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d7144
	if (ctx.cr6.lt) goto loc_820D7144;
	// b 0x820d728c
	goto loc_820D728C;
loc_820D71CC:
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// addi r8,r27,-1
	ctx.r8.s64 = ctx.r27.s64 + -1;
	// addi r7,r27,-1
	ctx.r7.s64 = ctx.r27.s64 + -1;
	// clrlwi r6,r9,29
	ctx.r6.u64 = ctx.r9.u32 & 0x7;
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r8,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r5,r7,29
	ctx.r5.u64 = ctx.r7.u32 & 0x7;
	// subfic r8,r6,7
	ctx.xer.ca = ctx.r6.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r6.s64;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// subfic r10,r5,7
	ctx.xer.ca = ctx.r5.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r5.s64;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d728c
	if (ctx.cr6.eq) goto loc_820D728C;
loc_820D7208:
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// clrlwi r5,r8,24
	ctx.r5.u64 = ctx.r8.u32 & 0xFF;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// srw r11,r11,r5
	ctx.r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r5.u8 & 0x3F));
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// ble cr6,0x820d7264
	if (!ctx.cr6.gt) goto loc_820D7264;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
loc_820D7228:
	// subfic r4,r10,7
	ctx.xer.ca = ctx.r10.u32 <= 7;
	ctx.r4.s64 = 7 - ctx.r10.s64;
	// lbz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// li r3,32639
	ctx.r3.s64 = 32639;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// sraw r4,r3,r4
	temp.u32 = ctx.r4.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r4.s64 = ctx.r3.s32 >> temp.u32;
	// and r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 & ctx.r5.u64;
	// slw r4,r11,r10
	ctx.r4.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r5,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r5.u8);
	// bne cr6,0x820d725c
	if (!ctx.cr6.eq) goto loc_820D725C;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x820d7260
	goto loc_820D7260;
loc_820D725C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820D7260:
	// bdnz 0x820d7228
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D7228;
loc_820D7264:
	// cmpwi cr6,r8,7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 7, ctx.xer);
	// bne cr6,0x820d7278
	if (!ctx.cr6.eq) goto loc_820D7278;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// b 0x820d727c
	goto loc_820D727C;
loc_820D7278:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_820D727C:
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d7208
	if (ctx.cr6.lt) goto loc_820D7208;
loc_820D728C:
	// lbz r11,11(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 11);
	// stw r27,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r27.u32);
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r11,4(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
loc_820D72A4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D72AC"))) PPC_WEAK_FUNC(sub_820D72AC);
PPC_FUNC_IMPL(__imp__sub_820D72AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D72B0"))) PPC_WEAK_FUNC(sub_820D72B0);
PPC_FUNC_IMPL(__imp__sub_820D72B0) {
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
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// blt cr6,0x820d74cc
	if (ctx.cr6.lt) goto loc_820D74CC;
	// beq cr6,0x820d7488
	if (ctx.cr6.eq) goto loc_820D7488;
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// blt cr6,0x820d7454
	if (ctx.cr6.lt) goto loc_820D7454;
	// beq cr6,0x820d73d0
	if (ctx.cr6.eq) goto loc_820D73D0;
	// cmplwi cr6,r7,5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 5, ctx.xer);
	// blt cr6,0x820d7300
	if (ctx.cr6.lt) goto loc_820D7300;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2592
	ctx.r4.s64 = ctx.r11.s64 + -2592;
	// bl 0x820cab98
	ctx.lr = 0x820D72F4;
	sub_820CAB98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// b 0x820d74cc
	goto loc_820D74CC;
loc_820D7300:
	// lbz r9,11(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// addi r9,r9,7
	ctx.r9.s64 = ctx.r9.s64 + 7;
	// srawi. r9,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 3;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// beq 0x820d7340
	if (ctx.cr0.eq) goto loc_820D7340;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820D7324:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x820d7324
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D7324;
loc_820D7340:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820d74cc
	if (ctx.cr6.eq) goto loc_820D74CC;
	// addi r5,r6,-1
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r4,r31,-1
	ctx.r4.s64 = ctx.r31.s64 + -1;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
loc_820D735C:
	// lbzu r8,1(r5)
	ea = 1 + ctx.r5.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r5.u32 = ea;
	// lbzu r7,1(r6)
	ea = 1 + ctx.r6.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r6.u32 = ea;
	// lbzu r9,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// subf. r11,r8,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r8.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// neg r31,r11
	ctx.r31.s64 = -ctx.r11.s64;
	// blt 0x820d737c
	if (ctx.cr0.lt) goto loc_820D737C;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_820D737C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// blt cr6,0x820d738c
	if (ctx.cr6.lt) goto loc_820D738C;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_820D738C:
	// add. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x820d7398
	if (!ctx.cr0.lt) goto loc_820D7398;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_820D7398:
	// cmpw cr6,r31,r3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r3.s32, ctx.xer);
	// bgt cr6,0x820d73b0
	if (ctx.cr6.gt) goto loc_820D73B0;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x820d73b0
	if (ctx.cr6.gt) goto loc_820D73B0;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// b 0x820d73bc
	goto loc_820D73BC;
loc_820D73B0:
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x820d73bc
	if (ctx.cr6.gt) goto loc_820D73BC;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_820D73BC:
	// lbz r11,1(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stbu r11,1(r30)
	ea = 1 + ctx.r30.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r30.u32 = ea;
	// bdnz 0x820d735c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D735C;
	// b 0x820d74cc
	goto loc_820D74CC;
loc_820D73D0:
	// lbz r10,11(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// addi r10,r10,7
	ctx.r10.s64 = ctx.r10.s64 + 7;
	// srawi. r10,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 3;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// beq 0x820d7414
	if (ctx.cr0.eq) goto loc_820D7414;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D73F4:
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x820d73f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D73F4;
loc_820D7414:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820d74cc
	if (ctx.cr6.eq) goto loc_820D74CC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r10,r31,-1
	ctx.r10.s64 = ctx.r31.s64 + -1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820D742C:
	// lbzu r6,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzu r7,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbz r5,1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	// addze r8,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r8.s64 = temp.s64;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stbu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820d742c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D742C;
	// b 0x820d74cc
	goto loc_820D74CC;
loc_820D7454:
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d74cc
	if (ctx.cr6.eq) goto loc_820D74CC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
loc_820D746C:
	// lbzx r9,r10,r6
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r6.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820d746c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D746C;
	// b 0x820d74cc
	goto loc_820D74CC;
loc_820D7488:
	// lbz r11,11(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820d74cc
	if (!ctx.cr6.lt) goto loc_820D74CC;
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820D74B8:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820d74b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D74B8;
loc_820D74CC:
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

__attribute__((alias("__imp__sub_820D74E4"))) PPC_WEAK_FUNC(sub_820D74E4);
PPC_FUNC_IMPL(__imp__sub_820D74E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D74E8"))) PPC_WEAK_FUNC(sub_820D74E8);
PPC_FUNC_IMPL(__imp__sub_820D74E8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,1384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1384, ctx.r11.u32);
	// bl 0x820d0658
	ctx.lr = 0x820D7508;
	sub_820D0658(ctx, base);
	// lbz r11,1555(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1555);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820d757c
	if (ctx.cr0.eq) goto loc_820D757C;
	// lwz r11,1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,1468(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1468);
	// bne 0x820d752c
	if (!ctx.cr0.eq) goto loc_820D752C;
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
loc_820D752C:
	// stw r11,1472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1472, ctx.r11.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lbz r10,1556(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// addi r11,r11,-2732
	ctx.r11.s64 = ctx.r11.s64 + -2732;
	// lwz r9,1464(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1464);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lbz r8,1561(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1561);
	// addi r7,r11,28
	ctx.r7.s64 = ctx.r11.s64 + 28;
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r11,r10,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// subf r10,r6,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r6.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// twllei r11,0
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// divwu r10,r10,r11
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r11.u32);
	// mullw r11,r8,r10
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r10,1488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1488, ctx.r10.u32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// b 0x820d7590
	goto loc_820D7590;
loc_820D757C:
	// lwz r10,1468(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1468);
	// lwz r9,1464(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1464);
	// lwz r11,1480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1480);
	// stw r10,1472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1472, ctx.r10.u32);
	// stw r9,1488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1488, ctx.r9.u32);
loc_820D7590:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r8,1376(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// stw r11,1484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1484, ctx.r11.u32);
	// rlwinm. r10,r8,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lbz r11,1561(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1561);
	// beq 0x820d75b8
	if (ctx.cr0.eq) goto loc_820D75B8;
	// lbz r10,1559(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1559);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bge cr6,0x820d75b8
	if (!ctx.cr6.lt) goto loc_820D75B8;
	// li r11,8
	ctx.r11.s64 = 8;
loc_820D75B8:
	// rlwinm. r10,r8,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d762c
	if (ctx.cr0.eq) goto loc_820D762C;
	// lbz r10,1558(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x820d75e4
	if (!ctx.cr6.eq) goto loc_820D75E4;
	// lhz r11,1546(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x820d762c
	goto loc_820D762C;
loc_820D75E4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820d760c
	if (!ctx.cr6.eq) goto loc_820D760C;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bge cr6,0x820d75f8
	if (!ctx.cr6.lt) goto loc_820D75F8;
	// li r11,8
	ctx.r11.s64 = 8;
loc_820D75F8:
	// lhz r10,1546(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x820d762c
	if (ctx.cr0.eq) goto loc_820D762C;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x820d762c
	goto loc_820D762C;
loc_820D760C:
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x820d762c
	if (!ctx.cr6.eq) goto loc_820D762C;
	// lhz r10,1546(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x820d762c
	if (ctx.cr0.eq) goto loc_820D762C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,3
	ctx.r10.s64 = 3;
	// divw r11,r11,r10
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r10.s32);
loc_820D762C:
	// rlwinm. r10,r8,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7678
	if (ctx.cr0.eq) goto loc_820D7678;
	// lbz r10,1558(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x820d7658
	if (ctx.cr6.eq) goto loc_820D7658;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820d7660
	if (!ctx.cr6.eq) goto loc_820D7660;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bgt cr6,0x820d7658
	if (ctx.cr6.gt) goto loc_820D7658;
	// li r11,16
	ctx.r11.s64 = 16;
	// b 0x820d7678
	goto loc_820D7678;
loc_820D7658:
	// li r11,32
	ctx.r11.s64 = 32;
	// b 0x820d7678
	goto loc_820D7678;
loc_820D7660:
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x820d7678
	if (!ctx.cr6.eq) goto loc_820D7678;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// li r11,32
	ctx.r11.s64 = 32;
	// ble cr6,0x820d7678
	if (!ctx.cr6.gt) goto loc_820D7678;
	// li r11,64
	ctx.r11.s64 = 64;
loc_820D7678:
	// addi r10,r9,7
	ctx.r10.s64 = ctx.r9.s64 + 7;
	// addi r9,r11,7
	ctx.r9.s64 = ctx.r11.s64 + 7;
	// rlwinm r8,r10,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// srawi r10,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 3;
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820d2da8
	ctx.lr = 0x820D76A4;
	sub_820D2DA8(ctx, base);
	// stw r3,1500(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1500, ctx.r3.u32);
	// lwz r11,1480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1480);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x820d2da8
	ctx.lr = 0x820D76B8;
	sub_820D2DA8(ctx, base);
	// stw r3,1496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1496, ctx.r3.u32);
	// lwz r11,1480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1480);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d2e50
	ctx.lr = 0x820D76D4;
	sub_820D2E50(ctx, base);
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// stw r11,1372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1372, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_820D76F4"))) PPC_WEAK_FUNC(sub_820D76F4);
PPC_FUNC_IMPL(__imp__sub_820D76F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D76F8"))) PPC_WEAK_FUNC(sub_820D76F8);
PPC_FUNC_IMPL(__imp__sub_820D76F8) {
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
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lis r7,32767
	ctx.r7.s64 = 2147418112;
	// lbz r11,1(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r9,2(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r10,3(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// ori r7,r7,65535
	ctx.r7.u64 = ctx.r7.u64 | 65535;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r31,r7
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x820d774c
	if (!ctx.cr6.gt) goto loc_820D774C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2556
	ctx.r4.s64 = ctx.r11.s64 + -2556;
	// bl 0x820cab60
	ctx.lr = 0x820D774C;
	sub_820CAB60(ctx, base);
loc_820D774C:
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

__attribute__((alias("__imp__sub_820D7764"))) PPC_WEAK_FUNC(sub_820D7764);
PPC_FUNC_IMPL(__imp__sub_820D7764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D7768"))) PPC_WEAK_FUNC(sub_820D7768);
PPC_FUNC_IMPL(__imp__sub_820D7768) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820D7770;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,1440(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1440);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r29
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x820d77bc
	if (!ctx.cr6.gt) goto loc_820D77BC;
loc_820D7788:
	// lwz r28,1440(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1440);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r27,1436(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D77A0;
	sub_820D0998(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D77B0;
	sub_820CAD78(ctx, base);
	// subf r30,r29,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r29.s64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x820d7788
	if (ctx.cr6.gt) goto loc_820D7788;
loc_820D77BC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d77e8
	if (ctx.cr6.eq) goto loc_820D77E8;
	// lwz r29,1436(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D77D8;
	sub_820D0998(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D77E8;
	sub_820CAD78(ctx, base);
loc_820D77E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d6ba8
	ctx.lr = 0x820D77F0;
	sub_820D6BA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820d7850
	if (ctx.cr0.eq) goto loc_820D7850;
	// lbz r11,1548(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1548);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7810
	if (ctx.cr0.eq) goto loc_820D7810;
	// lwz r10,1372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// rlwinm. r10,r10,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7824
	if (ctx.cr0.eq) goto loc_820D7824;
loc_820D7810:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d7838
	if (!ctx.cr6.eq) goto loc_820D7838;
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7838
	if (ctx.cr0.eq) goto loc_820D7838;
loc_820D7824:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2520
	ctx.r4.s64 = ctx.r11.s64 + -2520;
	// bl 0x820cabf8
	ctx.lr = 0x820D7834;
	sub_820CABF8(ctx, base);
	// b 0x820d7848
	goto loc_820D7848;
loc_820D7838:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2520
	ctx.r4.s64 = ctx.r11.s64 + -2520;
	// bl 0x820cabb0
	ctx.lr = 0x820D7848;
	sub_820CABB0(ctx, base);
loc_820D7848:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820d7854
	goto loc_820D7854;
loc_820D7850:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820D7854:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D785C"))) PPC_WEAK_FUNC(sub_820D785C);
PPC_FUNC_IMPL(__imp__sub_820D785C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D7860"))) PPC_WEAK_FUNC(sub_820D7860);
PPC_FUNC_IMPL(__imp__sub_820D7860) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820D7868;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1368(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d7890
	if (ctx.cr6.eq) goto loc_820D7890;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2248
	ctx.r4.s64 = ctx.r11.s64 + -2248;
	// bl 0x820cab60
	ctx.lr = 0x820D7890;
	sub_820CAB60(ctx, base);
loc_820D7890:
	// cmplwi cr6,r30,13
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 13, ctx.xer);
	// beq cr6,0x820d78a8
	if (ctx.cr6.eq) goto loc_820D78A8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2268
	ctx.r4.s64 = ctx.r11.s64 + -2268;
	// bl 0x820cab60
	ctx.lr = 0x820D78A8;
	sub_820CAB60(ctx, base);
loc_820D78A8:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r11.u32);
	// bl 0x820d0998
	ctx.lr = 0x820D78C4;
	sub_820D0998(ctx, base);
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D78D4;
	sub_820CAD78(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D78E0;
	sub_820D7768(ctx, base);
	// lbz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// lbz r9,97(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 100);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lbz r7,101(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 101);
	// rotlwi r9,r8,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r6,98(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 98);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r5,102(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 102);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// lbz r4,103(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// rlwinm r8,r10,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r8,r6
	ctx.r9.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r10,r5
	ctx.r11.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r27,r11,r4
	ctx.r27.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lbz r7,99(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 99);
	// lbz r28,104(r1)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r1.u32 + 104);
	// lbz r29,105(r1)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 105);
	// add. r30,r8,r7
	ctx.r30.u64 = ctx.r8.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r25,106(r1)
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 106);
	// lbz r24,107(r1)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r1.u32 + 107);
	// lbz r26,108(r1)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r1.u32 + 108);
	// beq 0x820d7970
	if (ctx.cr0.eq) goto loc_820D7970;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d7970
	if (ctx.cr6.gt) goto loc_820D7970;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820d7970
	if (ctx.cr6.eq) goto loc_820D7970;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d7980
	if (!ctx.cr6.gt) goto loc_820D7980;
loc_820D7970:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2296
	ctx.r4.s64 = ctx.r11.s64 + -2296;
	// bl 0x820cab60
	ctx.lr = 0x820D7980;
	sub_820CAB60(ctx, base);
loc_820D7980:
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// beq cr6,0x820d79b8
	if (ctx.cr6.eq) goto loc_820D79B8;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// beq cr6,0x820d79b8
	if (ctx.cr6.eq) goto loc_820D79B8;
	// cmpwi cr6,r28,4
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 4, ctx.xer);
	// beq cr6,0x820d79b8
	if (ctx.cr6.eq) goto loc_820D79B8;
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// beq cr6,0x820d79b8
	if (ctx.cr6.eq) goto loc_820D79B8;
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// beq cr6,0x820d79b8
	if (ctx.cr6.eq) goto loc_820D79B8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2324
	ctx.r4.s64 = ctx.r11.s64 + -2324;
	// bl 0x820cab60
	ctx.lr = 0x820D79B8;
	sub_820CAB60(ctx, base);
loc_820D79B8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820d79d8
	if (ctx.cr6.lt) goto loc_820D79D8;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// beq cr6,0x820d79d8
	if (ctx.cr6.eq) goto loc_820D79D8;
	// cmpwi cr6,r29,5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 5, ctx.xer);
	// beq cr6,0x820d79d8
	if (ctx.cr6.eq) goto loc_820D79D8;
	// cmpwi cr6,r29,6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 6, ctx.xer);
	// ble cr6,0x820d79e8
	if (!ctx.cr6.gt) goto loc_820D79E8;
loc_820D79D8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2352
	ctx.r4.s64 = ctx.r11.s64 + -2352;
	// bl 0x820cab60
	ctx.lr = 0x820D79E8;
	sub_820CAB60(ctx, base);
loc_820D79E8:
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// bne cr6,0x820d79f8
	if (!ctx.cr6.eq) goto loc_820D79F8;
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// bgt cr6,0x820d7a18
	if (ctx.cr6.gt) goto loc_820D7A18;
loc_820D79F8:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// beq cr6,0x820d7a10
	if (ctx.cr6.eq) goto loc_820D7A10;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// beq cr6,0x820d7a10
	if (ctx.cr6.eq) goto loc_820D7A10;
	// cmpwi cr6,r29,6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 6, ctx.xer);
	// bne cr6,0x820d7a28
	if (!ctx.cr6.eq) goto loc_820D7A28;
loc_820D7A10:
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// bge cr6,0x820d7a28
	if (!ctx.cr6.lt) goto loc_820D7A28;
loc_820D7A18:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2404
	ctx.r4.s64 = ctx.r11.s64 + -2404;
	// bl 0x820cab60
	ctx.lr = 0x820D7A28;
	sub_820CAB60(ctx, base);
loc_820D7A28:
	// cmpwi cr6,r26,2
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 2, ctx.xer);
	// blt cr6,0x820d7a40
	if (ctx.cr6.lt) goto loc_820D7A40;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2440
	ctx.r4.s64 = ctx.r11.s64 + -2440;
	// bl 0x820cab60
	ctx.lr = 0x820D7A40;
	sub_820CAB60(ctx, base);
loc_820D7A40:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x820d7a58
	if (ctx.cr6.eq) goto loc_820D7A58;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2476
	ctx.r4.s64 = ctx.r11.s64 + -2476;
	// bl 0x820cab60
	ctx.lr = 0x820D7A58;
	sub_820CAB60(ctx, base);
loc_820D7A58:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820d7a70
	if (ctx.cr6.eq) goto loc_820D7A70;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2508
	ctx.r4.s64 = ctx.r11.s64 + -2508;
	// bl 0x820cab60
	ctx.lr = 0x820D7A70;
	sub_820CAB60(ctx, base);
loc_820D7A70:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,1464(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1464, ctx.r30.u32);
	// clrlwi r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	// stw r27,1468(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1468, ctx.r27.u32);
	// stb r11,1558(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1558, ctx.r11.u8);
	// stb r10,1559(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1559, ctx.r10.u8);
	// stb r26,1555(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1555, ctx.r26.u8);
	// beq 0x820d7ac8
	if (ctx.cr0.eq) goto loc_820D7AC8;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820d7ac0
	if (ctx.cr6.eq) goto loc_820D7AC0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x820d7ac8
	if (ctx.cr6.eq) goto loc_820D7AC8;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x820d7ab8
	if (ctx.cr6.eq) goto loc_820D7AB8;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x820d7ad0
	if (!ctx.cr6.eq) goto loc_820D7AD0;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x820d7acc
	goto loc_820D7ACC;
loc_820D7AB8:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x820d7acc
	goto loc_820D7ACC;
loc_820D7AC0:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x820d7acc
	goto loc_820D7ACC;
loc_820D7AC8:
	// li r11,1
	ctx.r11.s64 = 1;
loc_820D7ACC:
	// stb r11,1562(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1562, ctx.r11.u8);
loc_820D7AD0:
	// lbz r11,1562(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1562);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,1561(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1561, ctx.r11.u8);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r11,1480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1480, ctx.r11.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cdb60
	ctx.lr = 0x820D7B1C;
	sub_820CDB60(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D7B24"))) PPC_WEAK_FUNC(sub_820D7B24);
PPC_FUNC_IMPL(__imp__sub_820D7B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D7B28"))) PPC_WEAK_FUNC(sub_820D7B28);
PPC_FUNC_IMPL(__imp__sub_820D7B28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820D7B30;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1368(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d7b58
	if (!ctx.cr0.eq) goto loc_820D7B58;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2116
	ctx.r4.s64 = ctx.r11.s64 + -2116;
	// b 0x820d7b90
	goto loc_820D7B90;
loc_820D7B58:
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7b80
	if (ctx.cr0.eq) goto loc_820D7B80;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2140
	ctx.r4.s64 = ctx.r11.s64 + -2140;
loc_820D7B6C:
	// bl 0x820cab98
	ctx.lr = 0x820D7B70;
	sub_820CAB98(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7B7C;
	sub_820D7768(ctx, base);
	// b 0x820d7cd8
	goto loc_820D7CD8;
loc_820D7B80:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7b98
	if (ctx.cr0.eq) goto loc_820D7B98;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2164
	ctx.r4.s64 = ctx.r11.s64 + -2164;
loc_820D7B90:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D7B98;
	sub_820CAB60(ctx, base);
loc_820D7B98:
	// li r29,3
	ctx.r29.s64 = 3;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// divwu r9,r30,r29
	ctx.r9.u32 = ppc_divwu(ctx.r30.u32, ctx.r29.u32);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// mulli r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 * 3;
	// stw r10,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r10.u32);
	// subf. r10,r9,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r9.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r27,r11,-2188
	ctx.r27.s64 = ctx.r11.s64 + -2188;
	// beq 0x820d7be4
	if (ctx.cr0.eq) goto loc_820D7BE4;
	// lbz r11,1558(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x820d7bdc
	if (ctx.cr6.eq) goto loc_820D7BDC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-2188
	ctx.r4.s64 = ctx.r11.s64 + -2188;
	// b 0x820d7b6c
	goto loc_820D7B6C;
loc_820D7BDC:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D7BE4;
	sub_820CAB60(ctx, base);
loc_820D7BE4:
	// divw r30,r30,r29
	ctx.r30.s32 = ppc_divw(ctx.r30.s32, ctx.r29.s32);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820cacc0
	ctx.lr = 0x820D7BF8;
	sub_820CACC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x820d7c0c
	if (!ctx.cr0.eq) goto loc_820D7C0C;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D7C0C;
	sub_820CAB60(ctx, base);
loc_820D7C0C:
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// stw r11,1372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1372, ctx.r11.u32);
	// ble cr6,0x820d7c68
	if (!ctx.cr6.gt) goto loc_820D7C68;
	// addi r29,r28,-1
	ctx.r29.s64 = ctx.r28.s64 + -1;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_820D7C28:
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D7C38;
	sub_820D0998(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D7C48;
	sub_820CAD78(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stb r11,1(r29)
	PPC_STORE_U8(ctx.r29.u32 + 1, ctx.r11.u8);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// stb r11,2(r29)
	PPC_STORE_U8(ctx.r29.u32 + 2, ctx.r11.u8);
	// lbz r11,82(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// stbu r11,3(r29)
	ea = 3 + ctx.r29.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r29.u32 = ea;
	// bne 0x820d7c28
	if (!ctx.cr0.eq) goto loc_820D7C28;
loc_820D7C68:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7C74;
	sub_820D7768(ctx, base);
	// stw r28,1540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1540, ctx.r28.u32);
	// sth r30,1544(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1544, ctx.r30.u16);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cdc80
	ctx.lr = 0x820D7C90;
	sub_820CDC80(ctx, base);
	// lbz r11,1558(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820d7cd8
	if (!ctx.cr6.eq) goto loc_820D7CD8;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820d7cd8
	if (ctx.cr6.eq) goto loc_820D7CD8;
	// lwz r11,8(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7cd8
	if (ctx.cr0.eq) goto loc_820D7CD8;
	// lhz r11,1544(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1544);
	// lhz r10,1546(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820d7cd8
	if (!ctx.cr6.gt) goto loc_820D7CD8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2228
	ctx.r4.s64 = ctx.r11.s64 + -2228;
	// bl 0x820cab98
	ctx.lr = 0x820D7CD0;
	sub_820CAB98(ctx, base);
	// lhz r11,1544(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1544);
	// sth r11,1546(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1546, ctx.r11.u16);
loc_820D7CD8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D7CE0"))) PPC_WEAK_FUNC(sub_820D7CE0);
PPC_FUNC_IMPL(__imp__sub_820D7CE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D7CE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1368(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7d0c
	if (ctx.cr0.eq) goto loc_820D7D0C;
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d7d24
	if (!ctx.cr0.eq) goto loc_820D7D24;
loc_820D7D0C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2060
	ctx.r4.s64 = ctx.r11.s64 + -2060;
	// bl 0x820cab60
	ctx.lr = 0x820D7D1C;
	sub_820CAB60(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d7d54
	if (ctx.cr6.eq) goto loc_820D7D54;
loc_820D7D24:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// ori r11,r11,24
	ctx.r11.u64 = ctx.r11.u64 | 24;
	// stw r11,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r11.u32);
	// beq cr6,0x820d7d48
	if (ctx.cr6.eq) goto loc_820D7D48;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2088
	ctx.r4.s64 = ctx.r11.s64 + -2088;
	// bl 0x820cab98
	ctx.lr = 0x820D7D48;
	sub_820CAB98(ctx, base);
loc_820D7D48:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7D54;
	sub_820D7768(ctx, base);
loc_820D7D54:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D7D5C"))) PPC_WEAK_FUNC(sub_820D7D5C);
PPC_FUNC_IMPL(__imp__sub_820D7D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D7D60"))) PPC_WEAK_FUNC(sub_820D7D60);
PPC_FUNC_IMPL(__imp__sub_820D7D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D7D68;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1368(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d7da8
	if (!ctx.cr0.eq) goto loc_820D7DA8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1868
	ctx.r4.s64 = ctx.r11.s64 + -1868;
	// bl 0x820cab60
	ctx.lr = 0x820D7D90;
	sub_820CAB60(ctx, base);
loc_820D7D90:
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820d7e14
	if (ctx.cr6.eq) goto loc_820D7E14;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1896
	ctx.r4.s64 = ctx.r11.s64 + -1896;
	// b 0x820d7dbc
	goto loc_820D7DBC;
loc_820D7DA8:
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7dd0
	if (ctx.cr0.eq) goto loc_820D7DD0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1920
	ctx.r4.s64 = ctx.r11.s64 + -1920;
loc_820D7DB8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820D7DBC:
	// bl 0x820cab98
	ctx.lr = 0x820D7DC0;
	sub_820CAB98(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7DCC;
	sub_820D7768(ctx, base);
	// b 0x820d7ef4
	goto loc_820D7EF4;
loc_820D7DD0:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7dec
	if (ctx.cr0.eq) goto loc_820D7DEC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1944
	ctx.r4.s64 = ctx.r11.s64 + -1944;
	// bl 0x820cab98
	ctx.lr = 0x820D7DE8;
	sub_820CAB98(ctx, base);
	// b 0x820d7d90
	goto loc_820D7D90;
loc_820D7DEC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820d7d90
	if (ctx.cr6.eq) goto loc_820D7D90;
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7d90
	if (ctx.cr0.eq) goto loc_820D7D90;
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d7d90
	if (!ctx.cr0.eq) goto loc_820D7D90;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1968
	ctx.r4.s64 = ctx.r11.s64 + -1968;
	// b 0x820d7db8
	goto loc_820D7DB8;
loc_820D7E14:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820d0998
	ctx.lr = 0x820D7E20;
	sub_820D0998(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D7E30;
	sub_820CAD78(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7E3C;
	sub_820D7768(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820d7ef4
	if (!ctx.cr0.eq) goto loc_820D7EF4;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r7,83(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add. r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7ef4
	if (ctx.cr0.eq) goto loc_820D7EF4;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm. r10,r10,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7ec4
	if (ctx.cr0.eq) goto loc_820D7EC4;
	// clrldi r10,r11,32
	ctx.r10.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfd f0,-1976(r9)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + -1976);
	// lfd f13,-1984(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + -1984);
	// fsub f0,f12,f0
	ctx.f0.f64 = ctx.f12.f64 - ctx.f0.f64;
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x820d7ec4
	if (!ctx.cr6.gt) goto loc_820D7EC4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2040
	ctx.r4.s64 = ctx.r11.s64 + -2040;
	// bl 0x820cab98
	ctx.lr = 0x820D7EC0;
	sub_820CAB98(ctx, base);
	// b 0x820d7ef4
	goto loc_820D7EF4;
loc_820D7EC4:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,-20788(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20788);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f1,1584(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 1584, temp.u32);
	// bl 0x820cdb38
	ctx.lr = 0x820D7EF4;
	sub_820CDB38(ctx, base);
loc_820D7EF4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D7EFC"))) PPC_WEAK_FUNC(sub_820D7EFC);
PPC_FUNC_IMPL(__imp__sub_820D7EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D7F00"))) PPC_WEAK_FUNC(sub_820D7F00);
PPC_FUNC_IMPL(__imp__sub_820D7F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D7F08;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1368(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d7f48
	if (!ctx.cr0.eq) goto loc_820D7F48;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1716
	ctx.r4.s64 = ctx.r11.s64 + -1716;
	// bl 0x820cab60
	ctx.lr = 0x820D7F30;
	sub_820CAB60(ctx, base);
loc_820D7F30:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820d7fac
	if (ctx.cr6.eq) goto loc_820D7FAC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1744
	ctx.r4.s64 = ctx.r11.s64 + -1744;
	// b 0x820d7f5c
	goto loc_820D7F5C;
loc_820D7F48:
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d7f70
	if (ctx.cr0.eq) goto loc_820D7F70;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1768
	ctx.r4.s64 = ctx.r11.s64 + -1768;
loc_820D7F58:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820D7F5C:
	// bl 0x820cab98
	ctx.lr = 0x820D7F60;
	sub_820CAB98(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7F6C;
	sub_820D7768(ctx, base);
	// b 0x820d8064
	goto loc_820D8064;
loc_820D7F70:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7f8c
	if (ctx.cr0.eq) goto loc_820D7F8C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1792
	ctx.r4.s64 = ctx.r11.s64 + -1792;
	// bl 0x820cab98
	ctx.lr = 0x820D7F88;
	sub_820CAB98(ctx, base);
	// b 0x820d7f30
	goto loc_820D7F30;
loc_820D7F8C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820d7f30
	if (ctx.cr6.eq) goto loc_820D7F30;
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d7f30
	if (ctx.cr0.eq) goto loc_820D7F30;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1816
	ctx.r4.s64 = ctx.r11.s64 + -1816;
	// b 0x820d7f58
	goto loc_820D7F58;
loc_820D7FAC:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820d0998
	ctx.lr = 0x820D7FB8;
	sub_820D0998(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D7FC8;
	sub_820CAD78(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D7FD4;
	sub_820D7768(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820d8064
	if (!ctx.cr0.eq) goto loc_820D8064;
	// lbz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// blt cr6,0x820d7ffc
	if (ctx.cr6.lt) goto loc_820D7FFC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1836
	ctx.r4.s64 = ctx.r11.s64 + -1836;
	// bl 0x820cab98
	ctx.lr = 0x820D7FF8;
	sub_820CAB98(ctx, base);
	// b 0x820d8064
	goto loc_820D8064;
loc_820D7FFC:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d8054
	if (ctx.cr0.eq) goto loc_820D8054;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,1584(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 1584);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lfs f0,-1840(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -1840);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfd f0,2072(r10)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2072);
	// lfd f13,-1976(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + -1976);
	// lfd f12,-1984(r8)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r8.u32 + -1984);
	// fadd f0,f11,f0
	ctx.f0.f64 = ctx.f11.f64 + ctx.f0.f64;
	// fsub f0,f0,f13
	ctx.f0.f64 = ctx.f0.f64 - ctx.f13.f64;
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x820d8054
	if (!ctx.cr6.gt) goto loc_820D8054;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-2040
	ctx.r4.s64 = ctx.r11.s64 + -2040;
	// bl 0x820cab98
	ctx.lr = 0x820D8054;
	sub_820CAB98(ctx, base);
loc_820D8054:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cdcd0
	ctx.lr = 0x820D8064;
	sub_820CDCD0(ctx, base);
loc_820D8064:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D806C"))) PPC_WEAK_FUNC(sub_820D806C);
PPC_FUNC_IMPL(__imp__sub_820D806C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D8070"))) PPC_WEAK_FUNC(sub_820D8070);
PPC_FUNC_IMPL(__imp__sub_820D8070) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820D8078;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1368(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820d80fc
	if (!ctx.cr0.eq) goto loc_820D80FC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1516
	ctx.r4.s64 = ctx.r11.s64 + -1516;
	// bl 0x820cab60
	ctx.lr = 0x820D80A0;
	sub_820CAB60(ctx, base);
loc_820D80A0:
	// lbz r11,1558(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1558);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820d8180
	if (!ctx.cr6.eq) goto loc_820D8180;
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d80c8
	if (!ctx.cr0.eq) goto loc_820D80C8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1544
	ctx.r4.s64 = ctx.r11.s64 + -1544;
	// bl 0x820cab98
	ctx.lr = 0x820D80C8;
	sub_820CAB98(ctx, base);
loc_820D80C8:
	// lhz r11,1544(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1544);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820d8174
	if (ctx.cr6.gt) goto loc_820D8174;
	// cmplwi cr6,r30,256
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 256, ctx.xer);
	// bgt cr6,0x820d8174
	if (ctx.cr6.gt) goto loc_820D8174;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne cr6,0x820d8130
	if (!ctx.cr6.eq) goto loc_820D8130;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1568
	ctx.r4.s64 = ctx.r11.s64 + -1568;
	// bl 0x820cab98
	ctx.lr = 0x820D80F4;
	sub_820CAB98(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820d8294
	goto loc_820D8294;
loc_820D80FC:
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d8110
	if (ctx.cr0.eq) goto loc_820D8110;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1592
	ctx.r4.s64 = ctx.r11.s64 + -1592;
	// b 0x820d8288
	goto loc_820D8288;
loc_820D8110:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820d80a0
	if (ctx.cr6.eq) goto loc_820D80A0;
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820d80a0
	if (ctx.cr0.eq) goto loc_820D80A0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1616
	ctx.r4.s64 = ctx.r11.s64 + -1616;
	// b 0x820d8288
	goto loc_820D8288;
loc_820D8130:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820d2da8
	ctx.lr = 0x820D8138;
	sub_820D2DA8(ctx, base);
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// stw r3,1628(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1628, ctx.r3.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r11,1372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1372, ctx.r11.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D815C;
	sub_820D0998(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D816C;
	sub_820CAD78(ctx, base);
	// sth r30,1546(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1546, ctx.r30.u16);
	// b 0x820d8250
	goto loc_820D8250;
loc_820D8174:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1644
	ctx.r4.s64 = ctx.r11.s64 + -1644;
	// b 0x820d8288
	goto loc_820D8288;
loc_820D8180:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820d8204
	if (!ctx.cr6.eq) goto loc_820D8204;
	// cmplwi cr6,r30,6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 6, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820d81a0
	if (ctx.cr6.eq) goto loc_820D81A0;
loc_820D8194:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1644
	ctx.r4.s64 = ctx.r11.s64 + -1644;
	// b 0x820d828c
	goto loc_820D828C;
loc_820D81A0:
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820d0998
	ctx.lr = 0x820D81AC;
	sub_820D0998(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D81BC;
	sub_820CAD78(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// sth r11,1546(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1546, ctx.r11.u16);
	// lbz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// rotlwi r8,r9,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// rotlwi r6,r7,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,83(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r7,85(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// sth r11,1634(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1634, ctx.r11.u16);
	// sth r10,1636(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1636, ctx.r10.u16);
	// sth r9,1638(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1638, ctx.r9.u16);
	// b 0x820d8250
	goto loc_820D8250;
loc_820D8204:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d8280
	if (!ctx.cr6.eq) goto loc_820D8280;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne cr6,0x820d8194
	if (!ctx.cr6.eq) goto loc_820D8194;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x820d0998
	ctx.lr = 0x820D8224;
	sub_820D0998(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D8234;
	sub_820CAD78(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r9,89(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// sth r11,1546(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1546, ctx.r11.u16);
	// lbz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,1640(r31)
	PPC_STORE_U16(ctx.r31.u32 + 1640, ctx.r11.u16);
loc_820D8250:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D825C;
	sub_820D7768(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820d829c
	if (!ctx.cr0.eq) goto loc_820D829C;
	// addi r7,r31,1632
	ctx.r7.s64 = ctx.r31.s64 + 1632;
	// lhz r6,1546(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 1546);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,1628(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1628);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cdd00
	ctx.lr = 0x820D827C;
	sub_820CDD00(ctx, base);
	// b 0x820d829c
	goto loc_820D829C;
loc_820D8280:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,-1688
	ctx.r4.s64 = ctx.r11.s64 + -1688;
loc_820D8288:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820D828C:
	// bl 0x820cab98
	ctx.lr = 0x820D8290;
	sub_820CAB98(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_820D8294:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D829C;
	sub_820D7768(ctx, base);
loc_820D829C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D82A4"))) PPC_WEAK_FUNC(sub_820D82A4);
PPC_FUNC_IMPL(__imp__sub_820D82A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D82A8"))) PPC_WEAK_FUNC(sub_820D82A8);
PPC_FUNC_IMPL(__imp__sub_820D82A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D82B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r3,1548
	ctx.r4.s64 = ctx.r3.s64 + 1548;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x820d6c70
	ctx.lr = 0x820D82C8;
	sub_820D6C70(ctx, base);
	// lbz r11,1548(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1548);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d82ec
	if (!ctx.cr0.eq) goto loc_820D82EC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1488
	ctx.r4.s64 = ctx.r11.s64 + -1488;
	// bl 0x820cabb0
	ctx.lr = 0x820D82E4;
	sub_820CABB0(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820d830c
	if (ctx.cr6.eq) goto loc_820D830C;
loc_820D82EC:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820d8300
	if (ctx.cr0.eq) goto loc_820D8300;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// stw r11,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r11.u32);
loc_820D8300:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D830C;
	sub_820D7768(ctx, base);
loc_820D830C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D8314"))) PPC_WEAK_FUNC(sub_820D8314);
PPC_FUNC_IMPL(__imp__sub_820D8314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D8318"))) PPC_WEAK_FUNC(sub_820D8318);
PPC_FUNC_IMPL(__imp__sub_820D8318) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820D8320;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1492(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1492);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,1472(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1472);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1492(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1492, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820d868c
	if (ctx.cr6.lt) goto loc_820D868C;
	// lbz r10,1555(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1555);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r29,r11,-2732
	ctx.r29.s64 = ctx.r11.s64 + -2732;
	// beq 0x820d8454
	if (ctx.cr0.eq) goto loc_820D8454;
	// stw r25,1492(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1492, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,1480(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1480);
	// lwz r4,1496(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1496);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// bl 0x820d2e50
	ctx.lr = 0x820D8370;
	sub_820D2E50(ctx, base);
	// lbz r11,1556(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
loc_820D8374:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,1556(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1556, ctx.r11.u8);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x820d8448
	if (!ctx.cr6.lt) goto loc_820D8448;
	// lbz r9,1556(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addi r10,r29,28
	ctx.r10.s64 = ctx.r29.s64 + 28;
	// lbz r5,1561(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1561);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// lwz r4,1376(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1376);
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwz r11,1464(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1464);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r29,28
	ctx.r8.s64 = ctx.r29.s64 + 28;
	// rotlwi r6,r6,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// rlwinm. r4,r4,0,30,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r7,r7,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r29.u32);
	// lwzx r9,r6,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// twllei r9,0
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// divwu r10,r11,r9
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r9.u32);
	// mullw r11,r5,r10
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// stw r10,1488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1488, ctx.r10.u32);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1484, ctx.r11.u32);
	// bne 0x820d8448
	if (!ctx.cr0.eq) goto loc_820D8448;
	// lbz r11,1556(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// addi r10,r29,56
	ctx.r10.s64 = ctx.r29.s64 + 56;
	// addi r8,r29,84
	ctx.r8.s64 = ctx.r29.s64 + 84;
	// lwz r4,1488(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1488);
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// rotlwi r6,r11,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// lwz r9,1468(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1468);
	// addi r5,r29,84
	ctx.r5.s64 = ctx.r29.s64 + 84;
	// rotlwi r3,r11,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// lwzx r8,r6,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// lwzx r8,r3,r5
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// twllei r8,0
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// divwu r10,r10,r8
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r8.u32);
	// stw r10,1472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1472, ctx.r10.u32);
	// beq cr6,0x820d8374
	if (ctx.cr6.eq) goto loc_820D8374;
loc_820D8448:
	// lbz r11,1556(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1556);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// blt cr6,0x820d868c
	if (ctx.cr6.lt) goto loc_820D868C;
loc_820D8454:
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820d8650
	if (!ctx.cr0.eq) goto loc_820D8650;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,1392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1392, ctx.r11.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r10,1396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1396, ctx.r10.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r28,r9,-1440
	ctx.r28.s64 = ctx.r9.s64 + -1440;
	// addi r26,r10,-12020
	ctx.r26.s64 = ctx.r10.s64 + -12020;
	// addi r27,r11,-11976
	ctx.r27.s64 = ctx.r11.s64 + -11976;
loc_820D8488:
	// lwz r11,1384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d85b4
	if (!ctx.cr6.eq) goto loc_820D85B4;
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d8560
	if (!ctx.cr6.eq) goto loc_820D8560;
	// addi r30,r31,1548
	ctx.r30.s64 = ctx.r31.s64 + 1548;
loc_820D84A4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d7768
	ctx.lr = 0x820D84B0;
	sub_820D7768(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D84C0;
	sub_820D0998(ctx, base);
	// lbz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r9,86(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r11,1532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1532, ctx.r11.u32);
	// bl 0x820cad38
	ctx.lr = 0x820D84F4;
	sub_820CAD38(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D8504;
	sub_820D0998(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D8514;
	sub_820CAD78(ctx, base);
	// addi r10,r29,112
	ctx.r10.s64 = ctx.r29.s64 + 112;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
loc_820D8520:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820d8540
	if (!ctx.cr0.eq) goto loc_820D8540;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x820d8520
	if (!ctx.cr6.eq) goto loc_820D8520;
loc_820D8540:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820d8554
	if (ctx.cr0.eq) goto loc_820D8554;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D8554;
	sub_820CAB60(ctx, base);
loc_820D8554:
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d84a4
	if (ctx.cr6.eq) goto loc_820D84A4;
loc_820D8560:
	// lwz r10,1440(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1440);
	// lwz r30,1436(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1436);
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r10,1384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1384, ctx.r10.u32);
	// stw r30,1380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1380, ctx.r30.u32);
	// ble cr6,0x820d8580
	if (!ctx.cr6.gt) goto loc_820D8580;
	// stw r11,1384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1384, ctx.r11.u32);
loc_820D8580:
	// lwz r24,1384(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x820d0998
	ctx.lr = 0x820D8594;
	sub_820D0998(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cad78
	ctx.lr = 0x820D85A4;
	sub_820CAD78(ctx, base);
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// lwz r10,1384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,1532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1532, ctx.r11.u32);
loc_820D85B4:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1380
	ctx.r3.s64 = ctx.r31.s64 + 1380;
	// bl 0x820d6618
	ctx.lr = 0x820D85C0;
	sub_820D6618(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820d8604
	if (ctx.cr6.eq) goto loc_820D8604;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820d85e8
	if (ctx.cr6.eq) goto loc_820D85E8;
	// lwz r4,1404(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1404);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820d85e0
	if (!ctx.cr6.eq) goto loc_820D85E0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_820D85E0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D85E8;
	sub_820CAB60(ctx, base);
loc_820D85E8:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d8488
	if (!ctx.cr6.eq) goto loc_820D8488;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D8600;
	sub_820CAB60(ctx, base);
	// b 0x820d8488
	goto loc_820D8488;
loc_820D8604:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d8628
	if (ctx.cr6.eq) goto loc_820D8628;
	// lwz r11,1384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d8628
	if (!ctx.cr6.eq) goto loc_820D8628;
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d8634
	if (ctx.cr6.eq) goto loc_820D8634;
loc_820D8628:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cab60
	ctx.lr = 0x820D8634;
	sub_820CAB60(ctx, base);
loc_820D8634:
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// stw r25,1396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1396, ctx.r25.u32);
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
	// stw r11,1372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1372, ctx.r11.u32);
	// stw r10,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r10.u32);
loc_820D8650:
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d8668
	if (!ctx.cr6.eq) goto loc_820D8668;
	// lwz r11,1384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1384);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d8678
	if (ctx.cr6.eq) goto loc_820D8678;
loc_820D8668:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1464
	ctx.r4.s64 = ctx.r11.s64 + -1464;
	// bl 0x820cab60
	ctx.lr = 0x820D8678;
	sub_820CAB60(ctx, base);
loc_820D8678:
	// addi r3,r31,1380
	ctx.r3.s64 = ctx.r31.s64 + 1380;
	// bl 0x820d63a8
	ctx.lr = 0x820D8680;
	sub_820D63A8(ctx, base);
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// stw r11,1368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1368, ctx.r11.u32);
loc_820D868C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D8694"))) PPC_WEAK_FUNC(sub_820D8694);
PPC_FUNC_IMPL(__imp__sub_820D8694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D8698"))) PPC_WEAK_FUNC(sub_820D8698);
PPC_FUNC_IMPL(__imp__sub_820D8698) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x82088c48
	ctx.lr = 0x820D86B4;
	sub_82088C48(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820d86cc
	if (!ctx.cr6.eq) goto loc_820D86CC;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820D86CC:
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// subf r9,r3,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r3.s64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stb r9,-1(r10)
	PPC_STORE_U8(ctx.r10.u32 + -1, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D86F0"))) PPC_WEAK_FUNC(sub_820D86F0);
PPC_FUNC_IMPL(__imp__sub_820D86F0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r10,-1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// subf r3,r10,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r10.s64;
	// b 0x82088ce0
	sub_82088CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D870C"))) PPC_WEAK_FUNC(sub_820D870C);
PPC_FUNC_IMPL(__imp__sub_820D870C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D8710"))) PPC_WEAK_FUNC(sub_820D8710);
PPC_FUNC_IMPL(__imp__sub_820D8710) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// subf r3,r6,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r6.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D8720"))) PPC_WEAK_FUNC(sub_820D8720);
PPC_FUNC_IMPL(__imp__sub_820D8720) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820D8728;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x8215bb60
	ctx.lr = 0x820D874C;
	sub_8215BB60(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820d8774
	if (ctx.cr6.eq) goto loc_820D8774;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,65
	ctx.r10.s64 = 65;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D8774;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D8774:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8215ba78
	ctx.lr = 0x820D8788;
	sub_8215BA78(ctx, base);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820d87b0
	if (ctx.cr6.eq) goto loc_820D87B0;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,64
	ctx.r10.s64 = 64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D87B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D87B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D87B8"))) PPC_WEAK_FUNC(sub_820D87B8);
PPC_FUNC_IMPL(__imp__sub_820D87B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820D87C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x8215bb60
	ctx.lr = 0x820D87E4;
	sub_8215BB60(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820d880c
	if (ctx.cr6.eq) goto loc_820D880C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,65
	ctx.r10.s64 = 65;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D880C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D880C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820807b8
	ctx.lr = 0x820D8820;
	sub_820807B8(ctx, base);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820d8848
	if (ctx.cr6.eq) goto loc_820D8848;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,66
	ctx.r10.s64 = 66;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820D8848;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D8848:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D8850"))) PPC_WEAK_FUNC(sub_820D8850);
PPC_FUNC_IMPL(__imp__sub_820D8850) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// b 0x82084a80
	sub_82084A80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D8858"))) PPC_WEAK_FUNC(sub_820D8858);
PPC_FUNC_IMPL(__imp__sub_820D8858) {
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
	// bl 0x8215c078
	ctx.lr = 0x820D8878;
	sub_8215C078(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820d88bc
	if (!ctx.cr6.eq) goto loc_820D88BC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,63
	ctx.r10.s64 = 63;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r9,5993
	ctx.r4.s64 = ctx.r9.s64 + 5993;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x8215a990
	ctx.lr = 0x820D88A8;
	sub_8215A990(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820D88BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D88BC:
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lis r9,-32242
	ctx.r9.s64 = -2113011712;
	// addi r8,r11,-30944
	ctx.r8.s64 = ctx.r11.s64 + -30944;
	// addi r7,r10,-30792
	ctx.r7.s64 = ctx.r10.s64 + -30792;
	// addi r6,r9,-30640
	ctx.r6.s64 = ctx.r9.s64 + -30640;
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// stw r7,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r7.u32);
	// stw r6,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_820D88F8"))) PPC_WEAK_FUNC(sub_820D88F8);
PPC_FUNC_IMPL(__imp__sub_820D88F8) {
	PPC_FUNC_PROLOGUE();
	// lis r3,15
	ctx.r3.s64 = 983040;
	// ori r3,r3,16960
	ctx.r3.u64 = ctx.r3.u64 | 16960;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820D8904"))) PPC_WEAK_FUNC(sub_820D8904);
PPC_FUNC_IMPL(__imp__sub_820D8904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D8908"))) PPC_WEAK_FUNC(sub_820D8908);
PPC_FUNC_IMPL(__imp__sub_820D8908) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820D8910;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r27,428(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r30,320(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820D893C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,56(r27)
	PPC_STORE_U32(ctx.r27.u32 + 56, ctx.r3.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r3
	ctx.r7.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r7,60(r27)
	PPC_STORE_U32(ctx.r27.u32 + 60, ctx.r7.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// ble cr6,0x820d89ec
	if (!ctx.cr6.gt) goto loc_820D89EC;
	// addi r26,r30,4
	ctx.r26.s64 = ctx.r30.s64 + 4;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,-48
	ctx.r29.s64 = ctx.r11.s64 + -48;
loc_820D8970:
	// lwz r10,60(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzu r11,84(r29)
	ea = 84 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r7,320(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// rotlwi r11,r8,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r25,r8,r7
	ctx.r25.s32 = ppc_divw(ctx.r8.s32, ctx.r7.s32);
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// mullw r24,r26,r25
	ctx.r24.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r25.s32);
	// andc r11,r7,r5
	ctx.r11.u64 = ctx.r7.u64 & ~ctx.r5.u64;
	// rlwinm r5,r24,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// twllei r7,0
	// twlgei r11,-1
	// bctrl 
	ctx.lr = 0x820D89B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r9,r25,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,56(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 56);
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r9
	ctx.r11.u64 = ctx.r3.u64 + ctx.r9.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stwx r11,r8,r30
	PPC_STORE_U32(ctx.r8.u32 + ctx.r30.u32, ctx.r11.u32);
	// lwz r6,60(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	// stwx r7,r30,r6
	PPC_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpw cr6,r28,r5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x820d8970
	if (ctx.cr6.lt) goto loc_820D8970;
loc_820D89EC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D89F4"))) PPC_WEAK_FUNC(sub_820D89F4);
PPC_FUNC_IMPL(__imp__sub_820D89F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820D89F8"))) PPC_WEAK_FUNC(sub_820D89F8);
PPC_FUNC_IMPL(__imp__sub_820D89F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820D8A00;
	__savegprlr_25(ctx, base);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r29,428(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// lwz r11,220(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r28,320(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// ble cr6,0x820d8b24
	if (!ctx.cr6.gt) goto loc_820D8B24;
	// addi r27,r28,2
	ctx.r27.s64 = ctx.r28.s64 + 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r11,12
	ctx.r31.s64 = ctx.r11.s64 + 12;
	// addi r30,r29,8
	ctx.r30.s64 = ctx.r29.s64 + 8;
loc_820D8A2C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r7,56(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r6,320(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwzx r5,r4,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// lwzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r7,r8,r6
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r6.s32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r6,0
	// andc r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// mullw. r8,r27,r7
	ctx.r8.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r7.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// twlgei r6,-1
	// ble 0x820d8a94
	if (!ctx.cr0.gt) goto loc_820D8A94;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r6,r11,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r11.s64;
loc_820D8A80:
	// lwzx r25,r8,r9
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r25,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r25.u32);
	// stwx r25,r6,r9
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, ctx.r25.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x820d8a80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D8A80;
loc_820D8A94:
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x820d8ae4
	if (!ctx.cr6.gt) goto loc_820D8AE4;
	// addi r8,r28,-2
	ctx.r8.s64 = ctx.r28.s64 + -2;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// mullw r6,r7,r28
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r28.s32);
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r6,r10
	ctx.r9.u64 = ctx.r6.u64 + ctx.r10.u64;
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_820D8AC8:
	// lwzx r10,r8,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// stwx r10,r11,r9
	PPC_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r10,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x820d8ac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D8AC8;
loc_820D8AE4:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x820d8b08
	if (!ctx.cr6.gt) goto loc_820D8B08;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r10,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r10.s64;
loc_820D8AFC:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x820d8afc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D8AFC;
loc_820D8B08:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r31,r31,84
	ctx.r31.s64 = ctx.r31.s64 + 84;
	// cmpw cr6,r26,r11
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d8a2c
	if (ctx.cr6.lt) goto loc_820D8A2C;
loc_820D8B24:
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820D8B28"))) PPC_WEAK_FUNC(sub_820D8B28);
PPC_FUNC_IMPL(__imp__sub_820D8B28) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820D8B30;
	__savegprlr_29(ctx, base);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r31,428(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// lwz r11,220(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r4,320(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// ble cr6,0x820d8c0c
	if (!ctx.cr6.gt) goto loc_820D8C0C;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,12
	ctx.r5.s64 = ctx.r11.s64 + 12;
loc_820D8B54:
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r10,24(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r8,320(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwzx r7,r6,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// lwzx r11,r6,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw. r10,r10,r8
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r8,0
	// andc r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	// ble 0x820d8bf4
	if (!ctx.cr0.gt) goto loc_820D8BF4;
	// addi r9,r4,2
	ctx.r9.s64 = ctx.r4.s64 + 2;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r8,r4,1
	ctx.r8.s64 = ctx.r4.s64 + 1;
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r29,r10,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r9,r29,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r29.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r7,r11,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r11.s64;
loc_820D8BC0:
	// lwzx r29,r7,r10
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stwx r29,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r29.u32);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r29,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lwzx r29,r7,r11
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// stwx r29,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r29.u32);
	// lwz r29,0(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r29,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r29.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x820d8bc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D8BC0;
loc_820D8BF4:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r5,r5,84
	ctx.r5.s64 = ctx.r5.s64 + 84;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820d8b54
	if (ctx.cr6.lt) goto loc_820D8B54;
loc_820D8C0C:
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

