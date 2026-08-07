// 0x82173B98 (shell) — Walk::Tick, the per-element scheduler tick.
//
// This is virtual slot index 4 (vtable+0x10) of a widely-derived shell base class: the word
// 0x82173B98 appears at that slot in ~115 vtables between 0x8204FA50 and 0x82057F08, i.e. it
// is the *inherited* tick body that almost every element uses unchanged.
//
// What it does, in order:
//   1. Unless the element is suspended, run its own class-specific step through virtual slot 3
//      (vtable+0x0C) — the per-class hook each derived element overrides.
//   2. Run each of the two embedded sub-tasks (at +0x10 and +0x2C) through their own virtual
//      slot 1 (vtable+0x04), skipping any sub-task that has already reported "finished".
//
// Nothing is stored back here; the tick is pure dispatch, which is why the frame only has to
// preserve r31 (the element pointer) across the three bctrl's.
//
// Two details the original bytes pin down and this source has to reproduce:
//
//   * SIGNEDNESS. The suspend flag at 0x20 is tested with `cmplwi` (unsigned) while the two
//     sub-task flags at 0x18 / 0x34 are tested with `cmpwi` (signed) — hence `unsigned int
//     suspended` but `int finished`.
//
//   * POINTER MATERIALISATION. The original computes `addi r3,r31,0x10` *before* the compare
//     and then loads the vptr with `lwz r11,0(r3)`. Writing the calls as plain member accesses
//     (`w->enter.Run()`) instead folds the sub-object offset into the vptr load
//     (`lwz r11,0x10(r31)`) and emits the addi separately inside the guarded block — same 33
//     instructions, but 8 of them in the wrong order. Naming the sub-task pointer in a local,
//     as below, is what makes the compiler materialise the address once and use it as the base
//     for the vptr load. That is the tell for a sub-object reached through a pointer/reference
//     in the source rather than by direct member syntax.

struct SubTask                       // 16 bytes; embedded twice inside Walk
{
    virtual void Release();          // vtbl+0x00
    virtual void Run();              // vtbl+0x04  — the tick entry point
    unsigned int pad04;              // 0x04
    int          finished;           // 0x08  — nonzero once the sub-task is done (signed: cmpwi)
    unsigned int pad0C;              // 0x0C
};

struct Walk                          // the scheduler element; only the touched fields are named
{
    virtual void v0();               // vtbl+0x00
    virtual void v1();               // vtbl+0x04
    virtual void v2();               // vtbl+0x08
    virtual void Advance();          // vtbl+0x0C  — per-class step, overridden by each element
    unsigned int pad04[3];           // 0x04, 0x08, 0x0C
    SubTask      enter;              // 0x10
    unsigned int suspended;          // 0x20  — nonzero suppresses Advance() (unsigned: cmplwi)
    unsigned int pad24[2];           // 0x24, 0x28
    SubTask      leave;              // 0x2C
};

void Walk_Tick(Walk* w)
{
    if (w->suspended == 0)
        w->Advance();

    SubTask* e = &w->enter;
    if (e->finished == 0)
        e->Run();

    SubTask* l = &w->leave;
    if (l->finished == 0)
        l->Run();
}
