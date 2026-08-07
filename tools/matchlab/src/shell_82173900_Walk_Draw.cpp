// 0x82173900 (shell) -- the "dual container" node's DRAW virtual (vtable slot 2, byte +0x08).
//
// Installed as draw in ~100 shell vtables (app node 0x820516BC, resource-bank manager
// 0x8204FAB8, screen/view class 0x820514CC, ...).  A dual container owns two *embedded*
// child-list sub-nodes instead of one child list of its own:
//
//     +0x10  A = serial   list (tick FUN_82173CD8, draw FUN_821739E8 -- front child only)
//     +0x2C  B = parallel list (tick FUN_82173C20, draw FUN_82173978 -- every child)
//
// Paint order is fixed HERE and nowhere else: B is drawn first (so it ends up underneath),
// then A on top.  Each sub-node is skipped when its own `hide` byte is non-zero, which is
// why a node effectively has three independent hide bytes -- its own +0x0C (tested by the
// parent's list walk) plus +0x1C (facet A) and +0x38 (facet B), both tested here.
//
// See SPEC_shell_compose_1to1.md 1.3/1.4 and ATLAS_scene_system.md 9.
//
// Source-shape tell (cost one iteration): writing the guard as `self->parallel.hide` folds the
// facet offset into the vptr load and leaves the `addi` inside the taken branch
// (`lwz r11,0x2C(r3) / addi r3,r3,0x2C`).  The original hoists `addi r3,r3,0x2C` ABOVE the
// compare and then loads the vptr at offset 0 -- i.e. the facet pointer is a NAMED LOCAL,
// live from its declaration.  The `hide` load still reads `0x38(r31)` because the optimizer
// reassociates `b + 0x0C` back onto `self`; that mixed addressing is the signature.

typedef unsigned char u8;
typedef unsigned int  u32;

// Base scene/task node -- 0x10 bytes.  Every compose node derives from this.
struct Node
{
    virtual void Destroy(int deleteSelf);   // vtable +0x00
    virtual void Tick();                    // vtable +0x04
    virtual void Draw(void* arg);           // vtable +0x08

    Node* next;         // 0x04  sibling in the parent's singly-linked child list
    u32   life;         // 0x08  0 = alive/ticking, 2 = dead (unlink + destroy)
    u8    hide;         // 0x0C  re-read every frame by the parent's draw walk
    u8    embedded;     // 0x0D  1 for the two sub-nodes of a dual container
    u8    autodie;      // 0x0E  when set, life = 2 once the child list empties
    u8    flag0F;       // 0x0F
};

// A node that owns a singly-linked child list -- 0x1C bytes.
struct ListNode : Node
{
    Node*  childHead;      // 0x10
    Node** childTailSlot;  // 0x14  == &childHead while the list is empty
    u32    reserved18;     // 0x18
};

// The dual container -- 0x48 bytes (task-derived classes add the state fn at +0x48).
struct DualNode : Node
{
    ListNode serial;    // 0x10  facet A: hide +0x1C, head +0x20, tail slot +0x24
    ListNode parallel;  // 0x2C  facet B: hide +0x38, head +0x3C, tail slot +0x40
};

void Walk_Draw(DualNode* self, void* arg)
{
    ListNode* b = &self->parallel;
    if (!b->hide)
        b->Draw(arg);

    ListNode* a = &self->serial;
    if (!a->hide)
        a->Draw(arg);
}
