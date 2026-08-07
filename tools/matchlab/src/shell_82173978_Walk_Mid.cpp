// 0x82173978 (shell) — compose-tree DRAW walk, "parallel" flavour.
//
// Draws every child of `self` in child-list order (first child = bottom of the
// paint stack), skipping any child whose `hide` byte is set. The call is the
// node's virtual draw, vtable slot +0x08, and the argument the group was handed
// is forwarded unchanged to each child.
//
// This is the vtable-0x08 entry of the "parallel container" class (vtable
// 0x82050348) and of several group nodes; the serial/front-only siblings are
// FUN_821739E8 (front child only) and FUN_82173900 (dual container).
// Layout and vtable slots per SPEC_shell_compose_1to1.md §1.3.
//
// Original shape:
//   lwz r31,0x10(r3) / mr r30,r4 / cmplwi r31,0 / beq end
//   loop: lbz r11,0xc(r31) / cmplwi r11,0 / bne skip
//         lwz r11,0(r31) / mr r4,r30 / mr r3,r31 / lwz r10,8(r11) / mtctr / bctrl
//   skip: lwz r31,4(r31) / cmplwi r31,0 / bne loop

typedef unsigned char u8;

struct Node;

// Base vtable shared by every compose node; derived virtuals continue at +0x0C.
struct NodeVtbl
{
    void (*destroy)(Node* self, int freeMemory);   // 0x00
    void (*tick)(Node* self);                      // 0x04
    void (*draw)(Node* self, void* arg);           // 0x08
};

struct Node
{
    const NodeVtbl* vtbl;      // 0x00
    Node*           next;      // 0x04  next sibling in the parent's child list
    unsigned int    life;      // 0x08  0 = alive, 2 = dead (unlink + destroy)
    u8              hide;      // 0x0C  re-read every frame by the draw walks
    u8              flag0D;    // 0x0D  set on the two embedded sub-containers
    u8              autodie;   // 0x0E  die once the child list empties
    u8              flag0F;    // 0x0F
    Node*           childHead; // 0x10  head of the singly-linked child list
    Node**          childTail; // 0x14  == &childHead when the list is empty
};

void Walk_Mid(Node* self, void* arg)
{
    for (Node* child = self->childHead; child != 0; child = child->next)
    {
        if (child->hide == 0)
            child->vtbl->draw(child, arg);
    }
}
