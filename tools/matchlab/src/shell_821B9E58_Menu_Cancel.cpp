// 0x821B9E58 — menu cancel: latch the "cancelled" state function, then tail-call the
// element's cancel virtual with -1 (the "no selection" result).
//
// EXTENT NOTE: this function is 8 instructions, not the 13 the boundary table implies.
// A LEAF function starts at 0x821B9E78 and has no .pdata unwind record, so shell_funcs.txt
// has no entry for it and the derived extent over-runs. ppcmatch accepts the declared 8 only
// because 0x821B9E78 is independently referenced elsewhere in the image (see the
// split-verification in original_bytes). Do not "fix" this by widening the extent.
//
// ★ THE LESSON OF THIS FILE — A VTABLE CALL MUST BE WRITTEN AS A REAL C++ VIRTUAL CALL. ★
//
// This function sat at 5/8 with the ONLY defect being that instructions 0 and 1 were SWAPPED:
// the image loads the vtable pointer first and materialises the state-function address second,
// and we did the reverse.  Seven source shapes were measured against a hand-modelled
// `struct MenuElementVtbl { ... void (*OnCancel)(MenuElement*, int); }` — the vtbl in a local
// read before the store, read after it, no local at all, the callee hoisted into a
// function-pointer local, the state function hoisted into a local, the `-1` hoisted into a
// local — and every one scored 5/8 or worse.
//
// The defect was never statement order.  A hand-rolled vtable struct asks the compiler to load
// A POINTER THE SOURCE NAMED, which it schedules like any other user load.  Declaring `OnCancel`
// as an actual `virtual` member and calling `n->OnCancel(-1)` hands the dispatch to MSVC's own
// vcall lowering, which emits the vptr load first.  Same eight instructions — and with that one
// change the function is EXACT.
//
// ⇒ Apply this to every shell function that dispatches through an object's vtable.  The shell is
//   C++ with real virtuals (the Elem_vcall_* thunks already on the board are the compiler's own
//   adjustor thunks, which exist only for genuine virtual inheritance), so modelling a vtable as
//   a plain struct of function pointers is not a neutral transcription: it changes the codegen.
//
// The seven leading `vtblNN` declarations are a MODELLING DEVICE, not knowledge.  They exist only
// to place OnCancel at vtable slot 7 (+0x1C), the offset the image loads.  Name them as the
// atlases identify them.

typedef unsigned int u32;

struct MenuElement
{
    // The vptr occupies 0x00, so the data members below start at 0x04.
    virtual void vtbl00();                       // +0x00
    virtual void vtbl04();                       // +0x04
    virtual void vtbl08();                       // +0x08
    virtual void vtbl0C();                       // +0x0C
    virtual void vtbl10();                       // +0x10
    virtual void vtbl14();                       // +0x14
    virtual void vtbl18();                       // +0x18
    virtual void OnCancel(int result);           // +0x1C  the slot this function calls

    u32   pad04[(0x48 - 0x04) / 4];
    void (*state)(MenuElement* self);            // 0x48  current state function
};

// 0x82065A78 — the state this element parks in once cancelled. One of the small state-thunk
// family (plan 8.1 rank 3); still recompiled, not yet translated.
extern "C" void Menu_StateCancelled(MenuElement* self);

extern "C" void Menu_Cancel(MenuElement* n)
{
    n->state = &Menu_StateCancelled;
    n->OnCancel(-1);
}
