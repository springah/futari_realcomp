// Element vcall thunks (shell, 0x82) — the family HUMAN_READABLE_DECOMP_PLAN 8.1 rank 3 lists as
// "the state-thunk family ... each is 4 instructions".
//
// ★ THEY ARE NOT SOURCE-LEVEL FUNCTIONS. Each is a COMPILER-GENERATED vcall thunk, emitted by
// MSVC when the program takes the ADDRESS OF A VIRTUAL MEMBER FUNCTION. The shape
//     lwz r12,0(r3) / lwz r11,SLOT(r12) / mtctr r11 / bctr
// is fixed codegen, and the r12-then-r11 register pair is the giveaway: ordinary C++ written as
// `e->vtbl->slot(e)` allocates r11-then-r10 and can never match. Verified by emitting one
// directly: `&Element::s30` produces `??_9Element@@$BDA@AA` ("Element::`vcall'{48}'") with
// bytes 81830000 816c0030 7d6903a6 4e800420 — byte-identical to 0x82061D50.
//
// So the honest reproduction is to declare the class and take the member pointers, which is what
// this file does. There is no readable body to write, and none should be invented.
//
//   0x82061D50 -> slot 0x30   0x82061D60 -> 0x50   0x82061D70 -> 0x34   0x82061D80 -> 0x74
//   0x82063A48 -> 0x2C        0x82063A58 -> 0x44
//   0x82065A78 -> 0x3C        0x82065A88 -> 0x40   0x82065A98 -> 0x24
//   0x82065AA8 -> 0x28        0x82065AB8 -> 0x38
//
// ⚠ EXTENT: 4 instructions each; the boundary table has no entry (leaf, no .pdata), so ppcmatch
// accepts the declared 4 via the "unreachable tail" proof.

struct Element
{
    // Slots 0x00..0x20 are whatever the class declares first; only their COUNT matters here,
    // because the vtable offset of a virtual is its index * 4.
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0C();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1C();
    virtual void s20();
    // The slots the thunks actually dispatch to:
    virtual void s24(); virtual void s28(); virtual void s2C(); virtual void s30();
    virtual void s34(); virtual void s38(); virtual void s3C(); virtual void s40();
    virtual void s44();
    virtual void s48(); virtual void s4C();
    virtual void s50();
    virtual void s54(); virtual void s58(); virtual void s5C(); virtual void s60();
    virtual void s64(); virtual void s68(); virtual void s6C(); virtual void s70();
    virtual void s74();
};

typedef void (Element::*ElementPmf)();

// Taking each address is what emits the corresponding vcall thunk COMDAT.
ElementPmf Element_StateThunks(int which)
{
    switch (which)
    {
        case 0x24: return &Element::s24;
        case 0x28: return &Element::s28;
        case 0x2C: return &Element::s2C;
        case 0x30: return &Element::s30;
        case 0x34: return &Element::s34;
        case 0x38: return &Element::s38;
        case 0x3C: return &Element::s3C;
        case 0x40: return &Element::s40;
        case 0x44: return &Element::s44;
        case 0x50: return &Element::s50;
        default:   return &Element::s74;
    }
}
