// 0x821CDBE8 (shell) — CRscBankMgr::CRscBankMgr, the resource-bank manager constructor.
//
// ✅ EXACT* — 81/81 instructions, sha1 cecd85963436, XDK 9328 cl 15.00.8327, `-O2 -Oc`.
//    12 relocated fields, every one resolved and checked against the spec:
//      +8/+13   -> 0x8204FA8C  sub-node A vtable (SERIAL container)
//      +16/+23  -> 0x82050348  sub-node B vtable (PARALLEL container)
//      +18/+27  -> 0x8204FAB8  the manager's own vtable
//      +51 bl   -> 0x82079FD8  operator new
//      +54 bl   -> 0x821CDB18  CRscIndicator's constructor
//      +57/+59  -> 0x821F85A4  the app-root holder (DAT_821F85A4)
//      +71/+73  -> 0x821CD490  the first state fn
//
// ⚠ NAME.  The backlog calls this "Compose_Root" and the file is named for that, but the
// function is NOT a compositor root: it is the ctor of the 500-byte resource-bank manager
// `DAT_821F856C`.  SPEC_shell_compose_1to1.md §7 carries the same correction for the object.
//
// SPEC_shell_compose_1to1.md §7 (the compose bible) reads this object as:
//   +0x00 vptr 0x8204FAB8 { dtor, tick FUN_82173B98, draw FUN_82173900, +0x0C state-dispatch }
//   +0x10 embedded sub-node A, vptr 0x8204FA8C  (SERIAL container; +0x1C hide, +0x20/+0x24 list)
//   +0x2C embedded sub-node B, vptr 0x82050348  (PARALLEL container; +0x38 hide, +0x3C/+0x40 list)
//   +0x48 state fn = FUN_821CD490 (wait for the NOW-LOADING indicator to build)
//   +0x4C .. +0x1EB  8 x 0x34 resource-bank records (std::string name, key, kind, ready, handle…)
//   +0x1EC u8 all-banks-ready
//   +0x1F0 the CRscIndicator ("NOW LOADING") task, 0x7C bytes, ctor FUN_821CDB18
// and the tail appends that indicator to the APP NODE's parallel list
// (`*(DAT_821F85A4+0x10) + 0x40`), which is why the overlay is permanent for the session.
//
// This is NOT a layer list — see the ⚠ CORRECTION in §7.

typedef unsigned int  u32;
typedef unsigned char u8;

// ---- the three vtables this ctor plants -------------------------------------------------------
extern const void* const g_RscBankMgrVtbl;    // 0x8204FAB8
extern const void* const g_SerialNodeVtbl;    // 0x8204FA8C  tick 82173CD8 / draw 821739E8
extern const void* const g_ParallelNodeVtbl;  // 0x82050348  tick 82173C20 / draw 82173978

// ---- the 0x1C-byte scene-graph container embedded twice in every task -------------------------
struct CNode
{
    const void* vtbl;       // 0x00
    CNode*      next;       // 0x04  intrusive link, written by the owner's list append
    u32         life;       // 0x08  0 = alive (the tick gate)
    u8          hidden;     // 0x0C
    u8          visible;    // 0x0D
    u8          f0E;        // 0x0E
    u8          f0F;        // 0x0F
    CNode*      childHead;  // 0x10
    CNode**     childTail;  // 0x14  == &childHead while empty
    u32         f18;        // 0x18

    CNode(const void* vt)
    {
        vtbl      = vt;
        life      = 0;
        hidden    = 0;
        visible   = 0;
        f0F       = 0;
        childHead = 0;
        childTail = &childHead;
        f0E       = 0;
    }

    void Append(CNode* child)
    {
        *childTail = child;
        childTail  = &child->next;
        child->next = 0;
    }
};

// ---- MSVC/VS2005 std::string, 0x1C bytes ------------------------------------------------------
// _Bx is the usual pointer/SSO-buffer union, and _Myptr() is the usual capacity test.  Both are
// load-bearing for codegen: the ternary is what keeps `&_Bx._Buf[0]` a materialised value, and
// that is why the ctor loop walks `rec->name._Bx._Buf` with a plain `addi` instead of collapsing
// into a single update-form store (see the note at the bottom of this file).
struct CString
{
    void* proxy;                             // 0x00  container proxy (not touched by the ctor)
    union { char* ptr; char buf[16]; } bx;   // 0x04  _Bx: heap pointer or the SSO buffer
    u32   size;                              // 0x14  _Mysize
    u32   cap;                               // 0x18  _Myres

    char* Myptr() { return 16 <= cap ? bx.ptr : bx.buf; }

    // _Tidy() then _Eos(0): capacity first, then the size, then the terminator.
    void Init()
    {
        cap = 15;
        size = 0;
        Myptr()[0] = 0;
    }
};

// ---- one preloaded resource bank, 0x34 bytes --------------------------------------------------
struct RscBank
{
    CString name;   // 0x00  "motion/menu_dialog.lzx" &c — filled in by FUN_821CD378
    u32     key;    // 0x1C  what FUN_821B9FC0 matches against model+0x54
    u32     kind;   // 0x20  2 = FONT, 3 = MOVIE container
    u8      ready;  // 0x24  written by the asset system
    u8      pad25[3];
    void*   handle; // 0x28  the loaded LZX/PSB bank
    void*   movie;  // 0x2C  out: movie container (kind 3)
    void*   font;   // 0x30  out: font object (kind 2)
};

// ---- the NOW-LOADING indicator task (0x7C, ctor 0x821CDB18) -----------------------------------
struct CRscIndicator : public CNode
{
    CRscIndicator();
    u8 rest[0x7C - 0x1C];
};

// ---- the app root holder (DAT_821F85A4, 0x14 bytes, vt 0x820516B8) ----------------------------
struct CTaskNode
{
    const void* vtbl;      // 0x00
    CNode*      next;      // 0x04
    u32         life;      // 0x08
    u8          hidden;    // 0x0C
    u8          pad0D[3];
    CNode       serial;    // 0x10
    CNode       parallel;  // 0x2C
};

struct CAppRoot
{
    const void* vtbl;      // 0x00
    u32         pad04[3];
    CTaskNode*  appNode;   // 0x10  the app node — everything on screen hangs off it
};

extern CAppRoot* g_appRoot;   // 0x821F85A4

struct CRscBankMgr;
typedef void (*RscState)(CRscBankMgr* mgr);

// 0x821CD490 — first state: spin until the indicator has built, then go collect the banks.
extern void RscBankMgr_WaitIndicator(CRscBankMgr* mgr);

// The 0x10-byte task header every scene-graph task starts with.  Its constructor clears the
// tick gate and the hide byte; the vptr slot is filled in by the most-derived constructor.
struct CTaskHead
{
    const void* vtbl;        // 0x00
    CNode*      next;        // 0x04
    u32         life;        // 0x08
    u8          hidden;      // 0x0C
    u8          pad0D[3];

    CTaskHead()
    {
        life   = 0;
        hidden = 0;
    }
};

struct CRscBankMgr : public CTaskHead
{
    CNode       serial;      // 0x10  sub-node A
    CNode       parallel;    // 0x2C  sub-node B
    RscState    state;       // 0x48
    RscBank     banks[8];    // 0x4C
    u8          allReady;    // 0x1EC
    u8          pad1ED[3];
    CRscIndicator* indicator;// 0x1F0
                             // 0x1F4 == sizeof

    CRscBankMgr();
};

// SPEC §7 says 500 = 0x1F4 bytes at the call site, and the record stride is 0x34.  These asserts
// are inert for codegen (verified: the function stays EXACT* with and without them).
typedef char _size_check[(sizeof(CRscBankMgr) == 0x1F4 && sizeof(RscBank) == 0x34 &&
                          sizeof(CNode) == 0x1C) ? 1 : -1];

CRscBankMgr::CRscBankMgr()
    : serial(&g_SerialNodeVtbl), parallel(&g_ParallelNodeVtbl)
{
    vtbl = &g_RscBankMgrVtbl;

    serial.visible   = 1;
    parallel.visible = 1;

    RscBank* rec = banks;
    int n = 8;
    do
    {
        rec->name.Init();
        rec++;
    } while (--n != 0);

    allReady = 0;

    indicator = new CRscIndicator();

    if (g_appRoot != 0)
    {
        CTaskNode* app = g_appRoot->appNode;
        if (app != 0)
            app->parallel.Append(indicator);
    }

    state = RscBankMgr_WaitIndicator;
}

// ---------------------------------------------------------------------------------------------
// HOW IT WAS MATCHED, and what the three load-bearing modelling devices are (2026-08-05)
//
// Score ladder, every step measured: 5/81 -> 11 -> 31 -> 37 -> EXACT*.
//
// 1. `CTaskHead` AS A BASE CLASS  (same=11 -> 31, structural 27 -> 23).  The image stores the
//    manager's `life` (+0x08) and `hidden` (+0x0C) BEFORE either sub-node's fields, but stores
//    its own vptr (+0x00) AFTER both of them.  That is exactly C++ ctor order with those two
//    fields in a base ctor and the vptr assigned in the derived body.  Writing them in the
//    derived body instead puts both stores at the END of the block (measured: idx 40/41).
//    ⚠ The base must NOT be polymorphic: this compiler does not dead-store-eliminate a
//    redundant vptr write (it happily keeps `+0x1D = 0` followed by `+0x1D = 1`), so a
//    polymorphic base would leave two stores to +0x00 and the image has one.
//
// 2. CNode's FIELD ORDER: ..., f0F, childHead, childTail, f0E  (same=31 -> 37, structural 23).
//    Both embedded nodes emit [hidden, visible, +0x0F, childHead, +0x0E] — the +0x0E byte lands
//    after the list head in both, so it is last in the ctor, not adjacent to +0x0F.
//
// 3. ★ std::string's `_Myptr()` TERNARY IS WHAT MAKES THE LOOP A LOOP  (37 -> EXACT).  The
//    remaining delta was five words: the image walks the 8 records with
//        addi r11,r11,4 / stw cap,0x14(r11) / stw size,0x10(r11) / stb 0,0(r11) / addi r11,0x34
//    while every straightforward spelling produced ONE INSTRUCTION LESS — c2 rebases the
//    induction variable to (first - stride) and folds the last store into an update form
//    (`stbu r10,0x34(r11)` / `stwu`).  That fold is unconditional over source shape: pointer
//    walk, `CString*` walk, `for` index, `while (n--)`, comma operator, unsigned counter,
//    `char*` with hand-written displacements, 64-bit counter — ALL twelve gave the same 80
//    instructions, and so did every flag set (-O1 -Oc, -O2 -Os, -O2 -Ot, -Ou, -Ob1/-Ob2, -Oy-,
//    -Oi-, -Oz, -GS-, -Gy, -GF, -GR).  A flat sweep, exactly as matchlab tell #7 predicts.
//    A probe of the rebase rule showed what blocks it: c2 will not rebase when the record-
//    relative ADDRESS is itself a live value.  In real VS2005 `<string>` it always is —
//        `_Elem *_Myptr() { return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf); }`
//    materialises `&_Bx._Buf[0]`, the select folds away (capacity was just set to 15) but the
//    address survives as a value, so the IV becomes `&rec->name._Bx._Buf` (hence the standalone
//    `addi r11,r11,4`) and the increment stays a plain `addi`.  Modelling the string as a flat
//    `char buf[16]` gives the 80-instruction form; adding the union + the ternary gives the
//    image, byte for byte.  Store order `cap, size, buf[0]` is `_Tidy()` then `_Eos(0)`.
//    ⭐ GENERAL LESSON: when a counted loop over records is one instruction short and the
//    difference is an update-form store, the original source had a live address, not a
//    different loop syntax.  Stop permuting the loop.
//
// Two smaller things that fell out for free and are worth reusing:
//   * The image's unfolded address chains (`addi r11,r3,0x10` + `addi r11,r11,0x10`;
//     `addi r11,r3,0x4C` + `addi r11,r11,4`) are the signature of INLINED MEMBER FUNCTIONS —
//     this c2 does not fold an addi chain that crosses an inline boundary.  Modelling the
//     sub-nodes as members with real constructors reproduces them exactly.
//   * The dead `addi r9,r11,0x2C` in the append block is `&app->parallel` — the `this` of the
//     inlined `CNode::Append`, whose every access then folds into `0x40(r11)`.  It comes back
//     for free from writing the append as a member function; do not try to "explain" it as a
//     spare pointer variable.
//
// The Ghidra body (default_decomp_all.txt, `FUN_821cdbe8`) is faithful but flattened: it shows
// the scheduled store order, not the source order, and every one of the three findings above is
// about source order.  It is a starting point, never a template.
