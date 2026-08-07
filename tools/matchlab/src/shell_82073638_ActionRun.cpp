// 0x82073638 (shell) — deferred-action delegate: invoke the stored callback, then self-kill.
// Original:  lwz r11,0x18(r3) / mr r31,r3 / lwz r3,0x14(r3) / mtctr r11 / bctrl
//            li r10,2 / stw r10,8(r31)
// Part of the deferred-action / self-kill triple (plan 9.1 #3).
typedef unsigned int u32;

struct Action
{
    u32   pad00[2];              // 0x00, 0x04
    u32   state;                 // 0x08
    u32   pad0C[2];              // 0x0C, 0x10
    void* arg;                   // 0x14
    void (*fn)(void*);           // 0x18
};

void Action_Run(Action* a)
{
    a->fn(a->arg);
    a->state = 2;
}
