// 0x821D1740 (shell) — logo FSM state 3 of 6: the PURE HOLD after the CAVE logo
// has finished fading in.
//
// The boot logo sequence is a little state machine hung off a scene task: each
// frame the shell calls task->state(task), and a state advances task->frame and
// eventually overwrites task->state with the next state's address.  The full
// chain is
//     FUN_821D1890 -> FUN_821D1780 (CAVE fade-IN, 60f)
//                  -> Logo_Hold2   (this one, HOLD 120f)
//                  -> FUN_821D1670 (CAVE fade-OUT, 60f)
//                  -> FUN_821D1540 (CAVE->M2 element swap) -> ...
// (ATLAS_scene_system.md "logo FSM", SPEC_shell_compose_1to1.md 8.9 row 3.)
//
// This state is the only one in the chain that touches no colour and no
// visibility byte -- it just counts 121 frames and hands over.  Note that it
// deliberately does NOT consume the skip flag: FUN_821D1780 already cleared it
// when it was pressed, so a flag that is still set here means the player is
// holding START, and every hold state collapses to a single frame.

typedef unsigned int u32;

struct LogoScene;
typedef void (*LogoState)(LogoScene* scene);

struct LogoScene
{
    u32           pad00[18];   // 0x00..0x47  scene-task header (link, kill state, ...)
    LogoState     state;       // 0x48  current FSM state, ticked once per frame
    u32           pad4C[6];    // 0x4C..0x63  incl. 0x5C = CAVE logo element, 0x60 = M2 logo element
    int           frame;       // 0x64  frames elapsed inside the current state
    unsigned char skip;        // 0x68  "skip the logos" request (START), set by the input poll
};

// 0x821D1670 — the next state: fades the CAVE logo back out over 60 frames.
extern void Logo_CaveFadeOut(LogoScene* scene);

void Logo_Hold2(LogoScene* scene)
{
    // Skipping just jumps the counter to the end of the hold, so the transition
    // below fires on this very frame instead of 120 frames from now.
    if (scene->skip)
        scene->frame = 0x78;

    if (scene->frame++ < 0x78)
        return;

    scene->frame = 0;
    scene->state = Logo_CaveFadeOut;
}
