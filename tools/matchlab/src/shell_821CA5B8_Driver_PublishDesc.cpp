// 0x821CA5B8 (shell) — publish one word into the driver-owned record, under the engine lock.
// Two copies (0x821CA5B8 + one more) => 28 instructions.
//
// registry.toml calls this "Cross-module callback (game invokes during msg-1/msg-2)". It is the
// handler whose ADDRESS the msg 1 descriptor carries at +0x18 (see
// src/shell_821C30B8_Driver_Init.cpp), so the game module calls back into the shell through it.
//
// ★ IT ALSO NAMES A GLOBAL FOR US. Driver_Init's descriptor carries 0x82208210 at +0x10 and this
//   function passes that same address to 0x821D5384 / 0x821D5394 — which registry.toml already
//   identifies as the "engine critical-section helper" pair. So 0x82208210 is the ENGINE LOCK,
//   not a descriptor table, and Driver_Init's field was misnamed on first writing. Cross-checking
//   a global against the OTHER functions that touch it is cheap and catches this class of error.
//
// The frame is millicode-bracketed: `bl __savegprlr_29` on entry and a TAIL `b __restgprlr_29`
// on exit, because self, the value, and the lock address are all live across both calls.

typedef unsigned int u32;

struct DriverRecord
{
    u32 pad000[0x23C / 4];
    u32 published;                  // 0x23C
};

// 0x82208210 — the engine critical section. Only its ADDRESS is ever taken.
extern u32 g_engineLock;

extern "C" void Engine_Lock(void* cs);      // 0x821D5384
extern "C" void Engine_Unlock(void* cs);    // 0x821D5394

void Driver_PublishDesc(DriverRecord* self, u32 value)
{
    Engine_Lock(&g_engineLock);
    self->published = value;
    Engine_Unlock(&g_engineLock);
}
