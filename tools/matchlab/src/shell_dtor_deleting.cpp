// THE SCALAR DELETING DESTRUCTOR FAMILY (shell) — 69 copies, 1380 instructions.
//
// `??_G<Class>@@UAAPAXI@Z` is MSVC's compiler-generated scalar deleting destructor.  It is not a
// source-level function: the compiler emits one per polymorphic class and puts it in the vtable
// so that `delete p` through a base pointer runs the right destructor and then frees the right
// block.  Its body is fixed boilerplate:
//
//     void* Class::`scalar deleting destructor`(unsigned int flags)
//     {
//         this->~Class();
//         if (flags & 1)
//             operator delete(this);
//         return this;
//     }
//
// Found by matchlab/clones.py once outbound call displacements are normalised — by a wide margin
// the largest clone family in either image (20 insn x 69).  This one file is byte-exact against
// ALL 69 addresses.
//
// ⚠ READ THIS BEFORE TRUSTING THE 69 ENTRIES IN functions.json.
// The copies are NOT byte-identical to each other.  They agree on every word except the `bl` at
// +7, which reaches each class's OWN destructor — 69 distinct targets, verified.  ppcmatch
// compares that field as masked, because our object holds a relocation there, so what this file
// proves for each address is: THE SHAPE, THE REGISTER MAP, THE FRAME AND THE `operator delete`
// TARGET ARE EXACT, AND THE REMAINING WORD IS A CALL TO THAT CLASS'S DESTRUCTOR.  Every entry
// records its own destructor address in its `note` so the claim can be audited without re-running
// anything.  What is genuinely shared and verified across all 69:
//     +12 `bl` -> 0x8207A630, the global `operator delete`, IDENTICAL in all 69.
// Naming the 69 classes is a separate job; each of those destructors is its own decomp target,
// and matching one does not depend on this file.
//
// ★ THE SAME SOURCE MATCHES A SECOND FAMILY AT -O1: 19 insn x 20 more copies, +380.
// Twenty further deleting destructors are ONE INSTRUCTION SHORTER because the flags test fuses
// into the record form -- `clrlwi. r11,r30,31` + `beq` against cr0, instead of `clrlwi` +
// `cmplwi cr6` + `beq cr6` -- and the `mr r3,r31` moves below the branch.  That is not a
// different source: it is THIS file compiled `-O1 -Oc` (`-O2 -Os` gives identical bytes).
// Corroborating evidence that they really are library code: they call a DIFFERENT
// `operator delete`, 0x82114628, where the -O2 family calls 0x8207A630.  This is the settled
// TITLE `-O2 -Oc` / LIBRARY `-O1` flag split showing up in the wild rather than being assumed,
// and it is worth remembering as a general move: WHEN A FAMILY IS A FEW INSTRUCTIONS SHORT OF A
// SHAPE YOU ALREADY MATCH, TRY THE OTHER FLAG SET BEFORE TOUCHING THE SOURCE.
//
// TWO MODELLING DEVICES, both needed to make the compiler emit the thunk at all:
//   * The destructor must be DEFINED in this translation unit, or MSVC emits no vtable and hence
//     no `??_G` (measured: declaring it and defining only `vf()` produces no such symbol).
//   * It must then be `__declspec(noinline)`, or MSVC inlines the (trivial) destructor body into
//     the thunk — that drops the call, folds the vptr store inline, and the thunk shrinks to 18
//     instructions (measured 2/20).  The real destructors are ordinary out-of-line functions, so
//     forcing the call restores the image's shape: `flags` then has to survive the call, which is
//     what puts it in r30 and grows the frame to save two nonvolatiles.
// `Element_Teardown` exists only to give the destructor a body the optimiser cannot delete.

struct Element
{
    virtual ~Element();
    virtual void vf();
};

extern "C" void Element_Teardown(void* self);

__declspec(noinline) Element::~Element()
{
    Element_Teardown(this);
}

void Element::vf()
{
}
