// 0x82182A68 (shell), 89 insn -- Compose_Veil(target, durationFrames): the ONLY public entry that
// arms the screen-wide veil / global fade.  SPEC_shell_compose_1to1.md 6.1, ATLAS_scene_system.md
// 8.4.  Callers: root FSM phase 3 `(-1, 0)` = HOLD, phase 4 `(0, 0)` = RELEASE, and the
// settings-apply FUN_82187EE0 `(wallpaperIdx + 1, brightness)`.
//
//   target == -1  HOLD    -- latch the "held" flag so later requests queue instead of starting,
//                            and reset the FX transition registers (layer table + phase/scale).
//   target ==  0  RELEASE -- clear the flag, snap the phase again, and re-issue whatever request
//                            was stashed while held.
//   otherwise             -- if held, stash (target, duration) and return; else fall into the tail.
//
// The shared tail sets the fade speed and then either starts the effect load (FUN_82182960) or
// leaves the id in `queued` for the per-frame tick FUN_82182BD0 to hot-swap.
//
// ---------------------------------------------------------------------------------------------
// STATUS: 89/89 instructions, same=56/89, 8 structural mismatches (-O2 -Oc).  Every remaining
// mismatch is instruction ORDER / register NUMBER inside two windows; the opcode sequence, the
// CFG and the operand offsets are all correct.  What is left:
//
//   idx 10/11  orig `li r10,0 / stb r7,0x30(r11)`, ours the reverse (2 S).
//   idx 46-52  a rotation of one 7-instruction window: orig runs the int->float chain tight
//              (`std` then `lfd` back to back, exactly like the isolated conversion the compiler
//              emits for `(float)n * K`) and appends `lwz req` + `cmpwi cur` at the end; ours
//              fills the std->lfd gap with those two and pushes the FP chain three slots later
//              (6 S).  The register pair follows the same split: orig allocates the extsw temp
//              first (r10, later reused for `req`) and `cur` second (r9); ours the other way.
//
// RULED OUT for that window (all measured, all identical at same=56/89 S=8 -- a flat sweep, so
// per README rule 18 it is NOT a syntax problem):
//   * `g_composeConsts[66] * (float)frames`, `frames * g_composeConsts[66]`, `(float)(long)`,
//     `(float)(__int64)`, `int n = frames;` first, a `static float Fx_FramesToSpeed(int)` helper.
//   * declaring `cur` / `req` before or after the speed store, in either order (4 orderings).
//   * flags: -O2 / -O2 -Oc -Ou / -O2 -Oc -Op are all identical; -Os/-Ot explode to 130 insn.
//   * the OTHER XDK 9328 compiler (15.00.8153, C:/Users/shant/Desktop/projects/_tools/xdk/xdk9328_ship/cl.exe): identical, 56/89.
//
// OTHER MEASURED NEGATIVES (these cost real instructions, do not re-try them):
//   * `int req = veil->requested;` as a LOCAL instead of three re-reads: 84 insn, same=26.  The
//     local lets MSVC jump-thread the second `req == 0` test away; the original keeps all three
//     tests, so `requested` must be re-read at each site and left to CSE.  (This is the single
//     biggest lever in the function: 84 -> 89 insn, S 33 -> 9.)
//   * separate `next` and `cur` locals (Ghidra renders it that way): 90 insn -- the two arms then
//     land in different registers and MSVC reconciles them through the stack.  ONE variable.
//   * the SPEC's compact form `if (!q && cur != target) load(); else if (q != target) queue;`
//     and `if (q == 0) { if (cur == target) return; load(); }`: both 84 insn, same=26/27.
//   * duplicating the `cur == target` test into both arms instead of one `cur`: 88 insn, same=44.
//   * `0.01f` written as a literal: 88 insn -- a literal gets its own `__real@3c23d70a` COMDAT and
//     folds to `lis`+`lfs`.  The original spends THREE instructions (`lis`/`addi`/`lfs 0x108`),
//     which is what an `extern` object referenced at a NON-ZERO offset costs, hence the pool array.
//   * `Fx_SnapPhase()` taking no argument and re-reading the global: 90 insn -- the global reload
//     inside the HOLD branch is a real instruction, so the settings pointer IS a caller local.
//   * moving `veil->held = 1` after the layer reset / into the middle of it: same=42..51 (worse).
//   * `fx->scale` snapped before `fx->phase`: same=52 (worse).

// STATUS 2026-08-05: 59/89, 7 structural. Length exact, and insns 14-28 (the layer-reset loop,
// both float snaps and the whole first-branch epilogue) are byte-identical.
//
// +3 THIS LEG: the `veil->held = 1` store belongs BETWEEN the two settings reads, not before them
// — the image materialises the loop count and the flag before storing (structural 8 -> 7). Six
// other openings were inert: a `zero` local feeding the three resets, a `n = 4` loop-count local,
// both together, `held = 1` through a local, and a countdown do/while for the layer reset.
//
// ❌ RULED OUT — THE TWO SNAP SITES CANNOT BE ORDERED FROM SOURCE. The image emits `Fx_SnapPhase`'s
// two loads in OPPOSITE orders at its two call sites: branch 1 reads phaseTarget (0x5AC) then
// scaleTarget (0x5B4), branch 2 reads scaleTarget first. Four spellings were measured — writing
// site 2 out inline with the scale read first, with the phase read first, writing BOTH sites out
// with the image's per-site order, and a second helper carrying the swapped order — and ALL FOUR
// are byte-identical at 59/89. The per-site order is chosen by the scheduler, not the source, so
// the single `Fx_SnapPhase` helper stays: it is the most readable form and costs nothing.

typedef unsigned char u8;
typedef unsigned int  u32;

// ---------------------------------------------------------------------------------------------
// The FX / transition register block -- *(g_shellSettings + 0x0C), built by FUN_82188550, which
// runs this exact same layer reset.  FUN_82184CC8 (the per-frame veil pass) eases +0x5B0 toward
// +0x5AC and +0x5B8 toward +0x5B4 by 0.15f a frame and publishes them as the global veil rotation
// (DAT_821F859C) and scale (DAT_821EC938) -- so "target" here is where the ease is heading.

struct FxLayer                              // 0x20 bytes, table base FX+0x60C
{
    u32 enable;                             // 0x00  set to 1 per built scene layer (FUN_8219D8E0)
    u32 rest[(0x20 - 0x04) / 4];            // 0x04
};

struct FxRegs
{
    u32   pad000[0x14 / 4];                 // 0x000  FUN_82188550 zeroes 0..0x580 wholesale
    u32   layerCount;                       // 0x014  cleared together with +0x590
    u32   pad018[(0x590 - 0x018) / 4];      // 0x018  the post-FX param block sits at +0x580
    u32   layersDirty;                      // 0x590  also cleared by the scene builder
    u32   pad594;                           // 0x594
    u32   veilRunning;                      // 0x598  != 0 while an effect draws (suppresses clear)
    u32   pad59C[(0x5AC - 0x59C) / 4];      // 0x59C
    float phaseTarget;                      // 0x5AC
    float phase;                            // 0x5B0
    float scaleTarget;                      // 0x5B4
    float scale;                            // 0x5B8
    u32   pad5BC[(0x60C - 0x5BC) / 4];      // 0x5BC
    FxLayer layers[4];                      // 0x60C
};

// DAT_821F858C -- the shell settings/holder object (lazily built by FUN_82188908).
struct ShellSettings
{
    u32     pad000[0x0C / 4];               // 0x000  +0x00 = the 0x16B0 live settings block
    FxRegs* fx;                             // 0x00C
};

extern ShellSettings* g_shellSettings;      // 0x821F858C

// ---------------------------------------------------------------------------------------------
// DAT_821F8574 -- the veil object, 0x3C bytes (ctor FUN_82181EC8, owned by task DAT_821F8570).
// Index [0] is the effect currently drawing, [1] the one that just finished loading; the tick
// FUN_82182BD0 promotes [1] into [0] (shader, alpha and id all move together, which is why the
// three fields are pairs at stride 4).

struct Veil
{
    void* shader[2];                        // 0x00 live / 0x04 incoming
    float alpha[2];                         // 0x08 live / 0x0C incoming
    int   effect[2];                        // 0x10 live / 0x14 incoming -- effect id
    float speed;                            // 0x18  duration frames * 0.01f
    float level;                            // 0x1C  eased fade level (read by FUN_82184CC8)
    int   requested;                        // 0x20  id handed to FUN_82182960, 0 when idle
    int   queued;                           // 0x24  id the tick should switch to next
    void* blob;                             // 0x28  the loading / loaded shader blob
    float flash;                            // 0x2C
    u8    held;                             // 0x30  1 = queue requests instead of starting them
    u8    pad31[3];                         // 0x31
    int   heldTarget;                       // 0x34  request stashed while held
    int   heldFrames;                       // 0x38
};

extern Veil* g_veil;                        // 0x821F8574

// 0x8204F7F0 -- this translation unit's float/double constant pool (the compose TU owns it: the
// veil's 4pi / -2pi / 0.15f / 3pi/2 constants all live in the same run).  [66] @0x8204F8F8 =
// 0.01f, the duration-frames -> fade-speed scale, hex-verified in NOTE_field_gfx_defects.md.
extern const float g_composeConsts[];

// FUN_82182960 -- starts the load: veil->requested = id, formats the asset name with FUN_8206C540
// and requests the blob into veil->blob via FUN_82194DF8.
extern void Veil_BeginLoad(Veil* veil, int id);

// Both HOLD and RELEASE snap the eased phase/scale to their targets so the next effect starts
// clean -- the same two lines the veil ctor runs.  Re-reading settings->fx here is not cosmetic:
// the layer stores in the HOLD path may alias it, so the original reloads it too.
static void Fx_SnapPhase(ShellSettings* settings)
{
    FxRegs* fx = settings->fx;
    fx->phase = fx->phaseTarget;
    fx->scale = fx->scaleTarget;
}

void Compose_Veil(int target, int frames)
{
    Veil* veil = g_veil;

    if (target == -1)
    {
        // The `held` store lands BETWEEN the two settings reads: the image materialises the
        // loop count and this flag before storing (+3 words, structural 8 -> 7).
        ShellSettings* settings = g_shellSettings;
        veil->held = 1;
        FxRegs* fx = settings->fx;
        fx->layersDirty = 0;
        fx->layerCount  = 0;
        for (int i = 0; i < 4; i++)
            fx->layers[i].enable = 0;

        Fx_SnapPhase(settings);
        return;
    }

    if (target == 0)
    {
        veil->held = 0;
        Fx_SnapPhase(g_shellSettings);
        target = veil->heldTarget;
        frames = veil->heldFrames;
    }
    else if (veil->held)
    {
        veil->heldTarget = target;
        veil->heldFrames = frames;
        return;
    }

    veil->speed = (float)frames * g_composeConsts[66];

    // The effect the veil is heading for: the one still loading if there is one, else the one on
    // screen.  A load already in flight (`requested`) wins over everything -- it can only be
    // re-aimed through `queued`, never restarted, which is why every arm re-tests it.
    int cur = veil->effect[1];
    if (cur == 0)
    {
        if (veil->requested != 0)
            goto queue;
        cur = veil->effect[0];
    }
    else if (veil->requested != 0)
        goto queue;

    if (cur == target)
        return;
    if (veil->requested == 0)
    {
        Veil_BeginLoad(veil, target);
        return;
    }

queue:
    if (veil->requested != target)
        veil->queued = target;
}
