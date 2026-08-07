// 0x821BA090 (shell module, default.xex) — menu state fn CHILD-RESULT.
//
// Reached through the state-thunk at 0x82063A58 (vt slot +0x44) after a menu has
// spawned a sub-page / dialog and that child has written its answer back into
// Menu::childAnswer (+0xA8).  All this state does is hand the pair
// (id of the item under the cursor, the child's answer) to the class's
// child-result virtual (vt +0x20) and then clear the stashed-cursor slot.
//
// If the cursor is out of range — which is the normal case for a cancel, where
// FUN_821BA4D8 pushed -1 — the id passed on is -1, and the overrides treat -1
// exactly like "return to top menu" (ATLAS_scene_system.md 8.2).
//
// MATCHED against the original: 43/43 instructions byte-identical, no relocations.
// Compiler: XDK 9328 "Microsoft (R) 32-bit C/C++ Optimizing Compiler
//           Version 15.00.8327 for PowerPC", flags: -O2 -TP
//
// Notes on the shape (load-bearing for the match):
//   * The double size() computation is real, not a decompiler artefact: the outer
//     range test and operator[]'s own bounds check each recompute
//     (last - first) / 0x24.  The compiler does NOT CSE them, and it addresses the
//     second one through `addi r11,r3,0x84` (the container sub-object) while the
//     first goes straight off `this` — which is what pins the container to +0x84
//     with first/last at +0x0C/+0x10 inside it rather than being three loose
//     members at +0x90/+0x94/+0x98.
//   * pointer difference by a non-power-of-two stride compiles to a genuine
//     `li r8,0x24 / divw`, never a magic-multiply.
//   * OUTER test is `cmpw` (signed) and INNER is `cmplw` (unsigned): the state
//     compares the cursor as int against the count, operator[] takes an unsigned
//     subscript and validates it unsigned.
//   * Operand ORDER in the subscript check is visible: `pos < size()` puts pos in
//     rA (`cmplw cr6,r10,r6` + `blt` over the trap).  Writing the equivalent
//     `size() <= pos` swaps rA/rB and turns the branch into `bgt` — that one
//     source-level flip was the entire delta on the first attempt (41/43).

typedef unsigned int u32;

extern "C" void __debugbreak();

// One menu row.  0x24 bytes; only the id is read here.
struct MenuItem
{
    u32 pad00[7];      // 0x00 .. 0x18  name/movie node, flags, tips ids
    int id;            // 0x1C  action id handed to the vt+0x1C / vt+0x20 handlers
    u32 pad20;         // 0x20
};

// The menu's item container (ctor FUN_821BA6F0 zeroes first/last/end and hangs a
// 4-byte iterator-proxy block off +0x00).
struct MenuItemArray
{
    void*     proxy;       // 0x00  4-byte block holding &this (iterator bookkeeping)
    void*     allocState;  // 0x04  allocator
    u32       allocPad;    // 0x08
    MenuItem* first;       // 0x0C
    MenuItem* last;        // 0x10
    MenuItem* end;         // 0x14

    int size() const { return (int)(last - first); }

    MenuItem& operator[](u32 pos)
    {
        if (!(pos < (u32)size()))
            __debugbreak();
        return first[pos];
    }
};

struct Menu;

struct MenuVtbl
{
    u32  slots00[8];                                  // 0x00 .. 0x1C
    void (*OnChildResult)(Menu*, int id, int answer); // 0x20
};

struct Menu
{
    MenuVtbl*     vt;             // 0x00
    u32           pad04[32];      // 0x04 .. 0x80
    MenuItemArray items;          // 0x84
    int           cursor;         // 0x9C
    int           stashedCursor;  // 0xA0  saved cursor across a sub-panel
    int*          ownerResult;    // 0xA4
    int           childAnswer;    // 0xA8  written by the child before it dies
};

void Menu_ChildResult(Menu* self)
{
    int id;

    if (self->cursor >= 0 && self->cursor < self->items.size())
        id = self->items[self->cursor].id;
    else
        id = -1;

    self->vt->OnChildResult(self, id, self->childAnswer);
    self->stashedCursor = -1;
}
