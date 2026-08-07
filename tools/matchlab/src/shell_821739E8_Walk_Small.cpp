// 0x821739E8 (shell) — draw walk, FRONT CHILD ONLY.
//
// This is the `draw` virtual (vtable +0x08) of the 0x1C-byte "serial container"
// class (vptr 0x8204FA8C, SPEC_shell_compose_1to1.md §1.3/§2.2). Where the
// parallel container's draw (FUN_82173978) paints every child in list order,
// this one paints ONLY the head of the child list — the front-most scene — and
// only when that child is not hidden. It is how the scene slot shows exactly
// one full-screen scene at a time.
//
// Original (11 instructions):
//   lwz  r3,0x10(r3)      ; front = self->childHead      (r4 = arg untouched)
//   cmplwi cr6,r3,0 / beqlr cr6
//   lbz  r11,0xC(r3)      ; front->hide
//   cmplwi cr6,r11,0 / bnelr cr6
//   lwz  r11,0(r3) / lwz r10,8(r11) / mtctr r10 / bctr   ; TAIL call vt->draw
//   blr
//
// The final `bctr` (no LK) is the compiler's tail call of the child's draw:
// r3 already holds `front` and r4 still holds our own `arg`, so nothing has to
// be shuffled — the callee returns straight to our caller.

typedef unsigned int  u32;
typedef unsigned char u8;

struct Node;

// Base compose-node vtable. Derived-class virtuals continue at +0x0C.
struct NodeVtbl
{
    void (*destroy)(Node* self, int deleteFlag);   // 0x00
    void (*tick)(Node* self);                      // 0x04
    void (*draw)(Node* self, u32 arg);             // 0x08
};

// Base node/task object shared by every node on the compose path (§1.3).
struct Node
{
    const NodeVtbl* vtable;         // 0x00
    Node*           next;           // 0x04  sibling in the parent's child list
    u32             life;           // 0x08  0 = alive, 2 = dead
    u8              hide;           // 0x0C  re-read every frame by the draw walks
    u8              flag0D;         // 0x0D
    u8              autodie;        // 0x0E
    u8              flag0F;         // 0x0F
    Node*           childHead;      // 0x10  front-most child
    Node**          childTailSlot;  // 0x14  == &childHead when the list is empty
};

void Walk_Small(Node* self, u32 arg)
{
    Node* front = self->childHead;
    if (front == 0)
        return;
    if (front->hide)
        return;

    front->vtable->draw(front, arg);
}
