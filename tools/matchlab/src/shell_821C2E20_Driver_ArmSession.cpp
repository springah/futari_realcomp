// 0x821C2E20 (8 identical instances, one per GameDriverTask) — arm a play session.
//
// Stages the session kind into armState, publishes a fresh descriptor into one half of a
// double-buffered slot pair (the half selected by slotIndex, with the other half invalidated
// to -1), then calls a virtual method on the task itself.
//
// The descriptor comes from a three-hop chain off a global table:
//     *g_sessionTable -> +0x4C -> +0x50 -> +0x24
// and the slot pair lives inside the task object at +0x80, indexed by slotIndex (0 or 1),
// which is why the original stores through stwx with (slotIndex + 0x20) * 4.

typedef unsigned int u32;

struct GameDriverTask;

struct GameDriverTaskVtbl
{
    u32  pad00[0x50 / 4];
    void (*OnSessionArmed)(GameDriverTask* self, int what);   // 0x50
};

struct GameDriverTask
{
    const GameDriverTaskVtbl* vtbl;     // 0x00
    u32  pad04[(0x74 - 0x04) / 4];
    u32  slotIndex;                     // 0x74  selects which half of slot[] is live
    u32  armState;                      // 0x78  0 / 2 / 3 / 4
    u32  pending;                       // 0x7C  cleared when a kind is recognised
    u32  slot[2];                       // 0x80  double-buffered descriptor pair
    u32  flags;                         // 0x88
    u32  pad8C[(0x98 - 0x8C) / 4];
    int   arg;                          // 0x98
};

// 0x821F8588 — holds a pointer to the table whose entry chain yields the descriptor.
extern u32* g_sessionTable;

void Driver_ArmSession(GameDriverTask* d, int arg, u32 kind)
{
    d->armState = 0;
    if (arg != 0)
    {
        d->armState = 2;
        if (kind != 3)
        {
            if (kind == 4)
            {
                d->armState = 4;
                d->pending = 0;
            }
        }
        else
        {
            d->armState = 3;
            d->pending = 0;
        }

        u32* a = g_sessionTable;
        u32* b = (u32*)a[0x4C / 4];
        u32* c = (u32*)b[0x50 / 4];
        ((u32*)d)[d->slotIndex + 0x20] = c[0x24 / 4];
        ((u32*)d)[(d->slotIndex ^ 1) + 0x20] = 0xFFFFFFFF;

        d->flags = 0;
        d->vtbl->OnSessionArmed(d, 4);
    }
    d->arg = arg;
}
