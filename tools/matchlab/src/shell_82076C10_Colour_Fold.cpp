// 0x82076C10 (shell module, default.xex) — the picture node's per-vertex colour-filter FOLD.
//
// Called exactly four times in the whole image, all from the picture-node draw
// FUN_82168E58 (0x82169128/60/98/D0) — once per quad corner, immediately before the
// DrawVerticesUP submit.  It threads one vertex colour through every filter installed on
// the node, handing each filter the *transformed position of that corner* so a filter can
// be position dependent (a screen-space gradient/fade hook).  With an empty filter vector
// — which is the case for every node on this title — it is a pure pass-through of the
// incoming colour, which is why the caller-side contract is simply `vcolour[k] = Q->colour[k]`.
// See SPEC_shell_compose_1to1.md §21.
//
// MATCHED against the original: 38/38 instructions, EXACT* — the only two masked words are
// `bl __savegprlr_28` (+1) and `b __restgprlr_28` (+37), the compiler's own prologue/epilogue
// helpers; their resolved guest targets 0x8207C988 / 0x8207C9D8 were read out of the image and
// are exactly `std r28..r31 / stw r12` and `ld r28..r31 / lwz r12 / mtlr r12`.
// Compiler: XDK 9328 "Version 15.00.8327 for PowerPC", flags: -O2 -TP.
//
// Load-bearing shape notes:
//   * `addi r31,r3,0x28` — the base register is the *sub-object* address, not the address of
//     the first field it touches (+0x34), which is why the loads are `0xC(r31)` / `0x10(r31)`.
//     That is the fingerprint of an inlined member function called on a member container: the
//     inlined `this` is `node + 0x28`.  Reading the same words off a flat struct instead keeps
//     `r31 = node` and emits `0x34(r31)` / `0x38(r31)` — a visibly different function.
//   * `size()` is re-read from first/last on *every* iteration, both for the loop condition and
//     for the subscript check: the virtual call may reallocate the vector, so the compiler is
//     not allowed to hoist either one.  Writing the count into a local before the loop does not
//     match.
//   * `cmplw` (unsigned) comes from `size()` returning u32; the index's own signedness is
//     invisible here — declaring `i` as `int` compiles to a byte-identical word stream.
//   * The accumulator never needs a callee-saved register: it is only live *into* the call, and
//     it is already sitting in r5, the third argument register.  Hence `mr r5,r3` right after
//     `bctrl` and the bare `mr r3,r5` on the empty-vector path.

typedef unsigned int       u32;
typedef unsigned long long u64;   // the packed { f32 x, f32 y } corner position, one 64-bit GPR

extern "C" void __debugbreak();   // twi 31,r0,0x16 — the container's range-check trap

// A colour filter object.  Only slot 1 of its vtable is used here.
struct ColourFilter
{
    virtual ~ColourFilter();                              // vtable +0x00
    virtual u32 Filter(u64 packedPos, u32 colour);        // vtable +0x04
};

// One entry of the filter vector: 8 bytes, the object pointer living in the second word.
struct FilterEntry
{
    u32           tag;        // 0x00  (never read here)
    ColourFilter* filter;     // 0x04
};

// The node's container: a 12-byte allocator/guard header followed by the usual
// first/last/end triple.  All four vectors in the picture node have this 0x18-byte shape
// (node +0x10, +0x28, +0x40, +0x58); the subscript is range checked.
struct FilterVector
{
    u32          m_alloc[3];  // 0x00  allocator / guard header
    FilterEntry* m_first;     // 0x0C
    FilterEntry* m_last;      // 0x10
    FilterEntry* m_end;       // 0x14

    u32 size() const { return (u32)(m_last - m_first); }

    FilterEntry& operator[](u32 i)
    {
        if (i >= size())
            __debugbreak();
        return m_first[i];
    }
};

// Only the filter vector at +0x28 matters here.
struct PicNode
{
    u32          m_head[0x28 / 4];   // 0x00  vptr, life, hide, and the element-record vector
    FilterVector m_filters;          // 0x28  (first/last at +0x34/+0x38)
};

u32 Colour_Fold(PicNode* node, u64 packedPos, u32 colour)
{
    for (u32 i = 0; i < node->m_filters.size(); ++i)
        colour = node->m_filters[i].filter->Filter(packedPos, colour);

    return colour;
}
