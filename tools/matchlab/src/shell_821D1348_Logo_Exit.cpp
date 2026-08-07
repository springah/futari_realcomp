// 0x821D1348 (shell) — boot-logo FSM, final state: EXIT to title.
//
// SPEC_shell_compose_1to1.md 20.5. The logo task's state runner (0x821D1310) tail-dispatches
// task->state; this is the last state it ever runs. It does NOT advance task->state. Instead it
// allocates a one-shot delegate bound to (task, Task_Kill) and parks it in the task's SERIAL
// child list. That has two effects, both load-bearing:
//   * the dual tick 0x82173B98 only runs the state fn while the serial list is EMPTY, so the FSM
//     stops here by itself — no repeated pushes;
//   * on the next serial walk the delegate fires Task_Kill(task) -> task->life = 2, the logo task
//     dies, and the root FSM's join state (0x821CE400) is unblocked -> the title comes up.
//
// Codegen note: the original contains an `addi r11,r31,0x10` whose result is never used. That is
// the `this` of the INLINED member call on the child-list sub-object at task+0x10 — the optimizer
// re-bases every use onto r31 with a +0x24 displacement but leaves the address computation behind.
// Writing the same three stores as flat field accesses (`*task->serial.tail = d; ...`) drops that
// instruction and re-allocates the registers: 19 insn, 5/20 the same. The member call is the shape.

typedef unsigned int u32;

struct Node;

// Intrusive singly-linked child list. `tail` always points AT the last node's `next` field (at
// `head` when the list is empty), which is why appending is three stores and no branch.
struct NodeList
{
    const void* vtbl;       // 0x00  0x8204FA8C for the logo task's serial (A) sub-node
    u32         pad04[3];   // 0x04..0x0C
    Node*       head;       // 0x10
    Node**      tail;       // 0x14

    void push_back(Node* n);
};

// Every scene/task object starts with this header; `next` is the link the parent's child list
// threads through.
struct Node
{
    const void* vtbl;       // 0x00
    Node*       next;       // 0x04
    u32         life;       // 0x08  2 = dead, unlinked and destroyed by the next serial walk
};

inline void NodeList::push_back(Node* n)
{
    *tail = n;
    tail  = &n->next;
    n->next = 0;
}

struct LogoTask
{
    const void* vtbl;       // 0x00  0x8204FA5C
    Node*       next;       // 0x04
    u32         life;       // 0x08
    u32         pad0C;      // 0x0C
    NodeList    serial;     // 0x10  the A list: head at task+0x20, tail-slot at task+0x24
};

// 0x820735C8 — allocates a 0x1C-byte delegate node (vptr 0x820514A8), stores arg at +0x14 and
// fn at +0x18. Its tick (Action_Run, 0x82073638) calls fn(arg) once and then self-kills.
extern Node* Delegate_New(void* arg, void (*fn)(void*));

// 0x820619F0 — the self-kill action: task->life = 2.
extern void Task_Kill(LogoTask* task);

void Logo_Exit(LogoTask* task)
{
    Node* d = Delegate_New(task, (void (*)(void*))Task_Kill);
    task->serial.push_back(d);
}
