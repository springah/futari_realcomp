// 0x88092AA8 (game) — RAW FETCH by id: bounds-check an id against the raw table, then hand the
// entry's two descriptor words to the copier.  registry.toml: "id -> raw bytes recipe:
// bound-check, entry = TOC + id*0x14".  Each entry is 0x14 bytes (the image builds id*5, <<2).
//
// PARKED at 18/30 (from 8/30), length exact.  Insns 16 onward — the whole index-scale-and-fetch
// tail, the two field loads and the call — are byte-identical.
//
// ★ THE COUNT AND THE TABLE POINTER ARE ONE OBJECT, NOT TWO SYMBOLS. +9 words.
//   The image materialises a SINGLE base (`lis` + `addi` to 0x887AD1A8) and reaches both through
//   it: `lwz r9,-0xc(r10)` for the count and `lwz r10,0(r10)` for the entries pointer.  Two
//   separate `extern`s cannot produce that — this compiler emits a separate `lis` per distinct
//   symbol (the same rule the float-pool base obeys), which is what the first draft did and why
//   it scored 8.  Declaring them as members of one object is what fixes the addressing.
//
// ⏭ WHAT IS LEFT, both measured, neither reachable by the spellings tried:
//   1. THE SIGN OF THE COUNT'S DISPLACEMENT.  The image has the count at -0xC from the base, so
//      its base is the ENTRIES member; ours is the struct start, so the count comes out at +0xC.
//      Same instruction, wrong displacement.  Tried: entries at offset 0 with count at 0xC (this
//      file, 18); count at 0 with entries at 0xC (17); count at 0xC behind a 3-word pad run so
//      the numeric offsets match the image (17); reading entries into a local first to make MSVC
//      base there (17).  Nothing makes MSVC pick a non-zero member as the base.
//   2. BLOCK PLACEMENT of the `return 0`.  The image puts both tests adjacent, then the fail
//      block, then the success block — its second branch is `bne -> success`, falling through
//      into the failure path.  Ours jumps forward over an inlined fail block and back.  The `||`
//      spelling gives the right branch SENSES but scores 10 because the tail then misaligns; the
//      two-`if` spelling here scores 18.  Same block-placement class as Page_Bake's preheader.

typedef unsigned int u32;

struct RawEntry
{
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
};

// One object at 0x887AD1A8: the entries pointer, with the count 0xC away. Modelled with the
// pointer first because that is the member the image uses as its addressing base.
struct RawTable
{
    RawEntry* entries;      // 0x887AD1A8
    u32       pad[2];
    u32       count;        // 0xC away from `entries` (the image reaches it at -0xC)
};
extern RawTable g_rawTable;

// 0x880927A8 — the copier.
extern "C" void Raw_Copy(void* dst, u32 a, u32 b);

extern "C" int Raw_Fetch(u32 id, void* out)
{
    if (id >= g_rawTable.count)
        return 0;
    if (out == 0)
        return 0;

    RawEntry* e = &g_rawTable.entries[id];
    Raw_Copy(out, e->f08, e->f04);
    return 1;
}
