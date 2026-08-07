// 0x820735C8 (shell) — factory for a deferred-action node.
//
// Allocates a 0x1C-byte node with vtable 0x820514A8 and remembers a (arg, fn) pair in it.
// The node's tick slot (vtbl+0x04) is Action_Run @0x82073638, which calls fn(arg) once and
// then parks the node at state 2 so the owning list can reap it — see
// matchlab/src/shell_82073638_ActionRun.cpp and ATLAS_scene_system.md line 619.
//
// Callers pass a task pointer plus a plain function address, e.g.
//   FUN_820735C8(task, 0x820619F0)   // Task_Kill: "kill this task on the next tick"
// and then append the returned node to a task's intrusive list, which is what fills in
// `next` (+0x04) immediately afterwards.
//
// Original codegen:  li r3,0x1C / bl operator new / cmplwi cr6,r3,0 / beq -> li r3,0
// i.e. the canonical MSVC `new T(...)` sequence with the constructor inlined. The redundant
// `li r3,0` on the null path is the front-end's new-expression shape and survives -O2; an
// equivalent hand-written `if (p) {...} return p;` would fold it away.
//
// EXACT* 27/27 (XDK 9328 cl 15.00.8327, -O2), sha1 005713dd33bf, 3 link-time relocations:
//   +8   bl  ??2@YAPAXI@Z          -> 0x82079FD8  (verified: malloc/_callnewh retry loop,
//                                                  i.e. the CRT's operator new(size_t))
//   +11  lis 0x8205  \  &g_DeferredNodeVtbl -> 0x820514A8 (verified: slot +0x04 holds
//   +15  addi 0x14A8 /                                     0x82073638 == Action_Run)

typedef unsigned int  u32;
typedef unsigned char u8;

// The deferred action itself: invoked as fn(arg) by Action_Run.
typedef void (*DeferredFn)(void* arg);

// 0x820514A8 — the node's vtable. [0x00] = 0x82079F38 (deleting destructor),
// [0x04] = 0x82073638 (Action_Run, the tick).
extern const void* const g_DeferredNodeVtbl;

struct DeferredNode
{
    const void*   vtbl;     // 0x00  -> g_DeferredNodeVtbl
    DeferredNode* next;     // 0x04  intrusive list link; written by the list append, not here
    u32           state;    // 0x08  0 = pending, 2 = done (Action_Run sets it)
    u8            cancelled;// 0x0C
    u32           pad10;    // 0x10
    void*         arg;      // 0x14  first argument handed back to fn
    DeferredFn    fn;       // 0x18  the deferred call
                            // 0x1C  == sizeof(DeferredNode)

    DeferredNode(void* a, DeferredFn f)
    {
        vtbl      = &g_DeferredNodeVtbl;
        state     = 0;
        cancelled = 0;
        arg       = a;
        fn        = f;
    }
};

DeferredNode* Deferred_Node(void* arg, DeferredFn fn)
{
    return new DeferredNode(arg, fn);
}
