// 0x820EE800 (shell) — IN-MEMORY BASE WAVE constructor.
// registry.toml: "In-memory base wave ctor (0x170, vtable 0x82014688)".
//
// Five interface pointers are seated after the base constructor runs, all from the same 0x82014xxx
// block but each materialised with its OWN `lis`+`addi` — this compiler emits a separate base per
// distinct symbol, so these are five distinct objects, not one table read at five offsets.
//
// ⚠ THE EMITTED STORE ORDER IS NOT THE SOURCE ORDER. The image stores 0x00, 0x0C, 0x04, 0x08,
// 0x18, and my first draft assumed that was what the source said — it is not. Writing the
// assignments in that order scores 13/27; writing them in plain ASCENDING FIELD ORDER
// (0x00, 0x04, 0x08, 0x0C, 0x18) is EXACT. MSVC materialises the five symbols in source order and
// then schedules the stores around the `addi`s, which permutes them. All six orderings of the
// three middle fields were measured: 13, 14, 14, **27**, 13, 14.
// ⇒ Do not read an out-of-order store run as evidence of out-of-order source. Try the natural
//   order first; here it was the only one that matched.

typedef unsigned int u32;

struct BaseWave;

// 0x82014688 / 0x82014684 / 0x82014730 / 0x82014680 / 0x82014670
extern const void* const g_baseWaveVtbl;
extern const void* const g_baseWaveIfaceC;
extern const void* const g_baseWaveIface4;
extern const void* const g_baseWaveIface8;
extern const void* const g_baseWaveIface18;

extern "C" void BaseWave_BaseCtor(BaseWave* self);      // 0x820EDD40

struct BaseWave
{
    const void* vtbl;               // 0x00
    const void* iface4;             // 0x04
    const void* iface8;             // 0x08
    const void* ifaceC;             // 0x0C
    u32         pad10[(0x18 - 0x10) / 4];
    const void* iface18;            // 0x18
};

BaseWave* BaseWave_Ctor(BaseWave* self)
{
    BaseWave_BaseCtor(self);

    self->vtbl    = &g_baseWaveVtbl;
    self->iface4  = &g_baseWaveIface4;
    self->iface8  = &g_baseWaveIface8;
    self->ifaceC  = &g_baseWaveIfaceC;
    self->iface18 = &g_baseWaveIface18;
    return self;
}
