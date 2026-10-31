# BACKLOG.md — ranked open work (re-rank of 2026-07-27, the long-queued t3)

## 2026-10-31 — 🎉 BLACK LABEL (kiniro_normal, modeIdx 4) BOOTS AND PLAYS TO GAME OVER (step 3; opt-in build; Mac)
- ✅ **Step 3 landed** (77644df + docs): on the 3-slot host (`MODULES="normal abn kiniro"`) with a PRIVATE game root holding the
  user-extracted DLC, a no-input drive went title -> hub -> Mode Select (Original/Maniac/God) -> Character Select (Reco & Kiniro)
  -> stage 1 -> GAME OVER -> replay prompt with **0 FATAL / 0 `[indirect] UNMAPPED` / 0 `[kdrop]`** (3 drives). The harvest loop
  therefore has nothing to add yet. Full write-up: docs/PLAN_kiniro_bringup.md "Step 3".
- Two fixes made it run: (1) the shell mounts the DLC as root `bldata:` and opens `bldata:\Rom\cg_black.bin` -> the type-2
  XamContentCreateEx branch now registers that root READ-ONLY onto `<RT_GAME_ROOT>/media` (boot 1 had MISSed it and shown the
  shell's "DLC cannot be read" dialog); (2) `rt_kgate()` (merged_common.h) refuses the eight RT_ levers whose stores go through
  reco_normal .data literals when the module is not reco-layout (the audit found no other literal writer among the 93 installed hooks).
- Non-regression on the default build: arcade leg clean, x360 leg's single dropout is the pre-swap title residual. No `[kgate]`
  on the reco pair.
- ✅ **Step 3b + 4c (same day, unattended):** RT_DESCPROBE positive controls (field_active / gm_frame_gate / mb_credited move identically
  on the reco control and on both kiniro modules at the same drive points; asset_commit / mb_reload / mb_mode64 flat on the control too,
  so still structural) · `scripts/kiniro_gate_mac.sh` regression gate (13 asserts; first runs 13/13 on both modes) · **kiniro_abnormal =
  Black Label XBOX 360 MODE boots and plays first try** (+8-law symbol map 8243/8243, twin-vote descriptor all +0x100 with a 0-disagreement
  reco control, 4/4 host mask 0x33). PLAN_kiniro_bringup "Step 3b" / "Step 4c".
- ✅ **Step 3c:** `RT_NAVMOD` nav observer set per module (scene_fsm / select_d76 / slot0 / credit) live-controlled on both kiniro modules
  (identical 17-edge sequence vs the reco control; select_d76 = the -0xA748 candidate). Gate repeatability 6/6. PLAN "Step 3c".
- ✅ **The three calls taken 2026-10-31 (user: "all three if we can do unattended"; revertable by ruling):** DATA PATH = second root
  `RT_DLC_ROOT` (default `<save dir>/../dlc`, searched before the game root; bundle README tells the player the exact extractor
  command) · BUILD SHAPE = `build_mac_dll.sh` default MODULES auto-includes kiniro + kiniro_abn when their trees exist, bundle copies
  whatever dylibs exist (row stays grey without data) · QUALITY BAR = the 11-row Black Label scorecard in PLAN_kiniro_bringup, with
  two new pixel rungs in the gate (PIX-RICH stage richness floor, PIX-REGRESS hub frame vs banked reference). Linux/Deck build arms
  for modules 4/5 still owed (Deck image keeps the 2-module shape).
- ✅ **Q11 + soaks (2026-10-31 midday):** rc3 DRY RUN ladder ALL-PASS on the 4-module bundle (after fixing app_smoke's pad delivery and the
  2/2 literals); kiniro_abnormal attract soak FLAT (+11 MB). Two user-requested sessions run in parallel: the divide-guard twin for Black Label
  (`bl-divguard`) and the Deck AppImage with Black Label + on-device boot (`bl-deck`).
- ⏳ **Owed next for Black Label**: Q10 hands-on (owner) · a drive (stagepix/boss plate/q-census assume reco data; no reference pixels for BL); triage of the 52 dropped hooks; a drive that
  makes asset_commit / mb_reload / mb_mode64 move on the control, to judge those three candidates; the Ver 1.01 DLC root (same type-2
  path, untested); how a USER gets the DLC in: `tools/extract/futari_extract.py <dlc folder> --out <private root>` exists, the app needs
  an "extra game root" story before Black Label can be offered (data NEVER in assets/ -> never in the bundle); Windows build arms for
  modules 4/5 (build_win_dll.sh has none).

## 2026-10-30 — POST-RC1 QUEUE, unattended Mac seat ("go nuts"): G5-fix LANDED · 360 START-wire CLOSED · Black Label steps 0-2 · RT_ROTATE
- ✅ **G5-fix (Darwin/Linux page release) LANDED as `RT_POOLRELEASE=<ms>`** (098809f, 08fce44; NOTE_fnf_shell_defects.md 2026-10-30):
  the PREREG_q5 oracle went from +139 MB (control) to +9 / +6 MB (two pilots) over the 12-min ARCADE demo loop, 210-233 MB of
  pooled pages returned per run, heap trajectory identical, stagepix PASS, boss plate PASS (46/46 lockstep, identical push sets), 6 same-binary A/B legs dropout-free.
  Plus x360 soak +8 MB FLAT and rc_chain A swap x5 PASS with the lever on. **DEFAULT ON for macOS/Linux -- USER RULING
  2026-10-30 "flip it on"** (`RT_POOLRELEASE=0` reverts). Known residual for the rc3 eyes pass: a deterministic title-screen
  dropout mode (7 frames, one element) in 3/11 lever-on vs 0/9 lever-off runs, always before the first release.
- ✅ **360 START-wire address CLOSED** (PLAN_RC1 §0.5 item 2): `0x88699894 + futari_desc()->dshift`; G-START x360 9/9 no leak, rc_chain B x360 PASS.
- **Black Label (kiniro) bring-up steps 0-2 DONE, static** (4013f33, docs/PLAN_kiniro_bringup.md): mulhdu + xex-size fix in the eqv
  patch, out_kiniro/ + out_kiniro_abn/ regenerate in ~4 s with 0 dropped instructions (8,375 functions, 33 TUs each), 62+62 jump
  tables from a recogniser that reproduces the reco pair's 57+57 exactly. Next = step 3 (indirect-only harvest loop, needs step 4a
  first) and step 4 (symbol map 210 unique / 35 ambiguous / 52 no-match hooks; descriptor data -- NOTE: the kiniro twin's data side is
  PIECEWISE (+0x100 / +0xF0 / -0x28), not one dshift; START EXCH candidate 0x8868F6AC / 0x8868F7AC needs a live positive control).
  ✅ The shared external/xr-derisk recompiler on the Mac now carries the full patch (re-applied + rebuilt 10-30 evening via
  `scripts/regen_kiniro_mac.sh`): kiniro regenerates identically through it, `regen_abn_mac.sh` reproduces out_reco_abn
  BYTE-IDENTICAL (33/33 TUs by md5), and a relink against the rebuilt libXenonUtils boots clean.
  ✅ **Step 4a DONE (bind, not run)**: `MODULES="normal abn kiniro"` builds futari_game_kiniro.dylib (modeIdx 4) and the host binds 3/3, mask=0x13; the Black Label row un-greys (with RT_DLCFORCE=1); 167/219 hooks mapped, 52 dropped; descriptor values UNVERIFIED -- docs/PLAN_kiniro_bringup.md "Step 4a".
- **RT_ROTATE=90|270** (b737e13, 3097d95; see the PORTRAIT TOO bullet below for the lane's own entry).
- Not touched tonight: the 5 UNDER kernel stubs (§0.5 item 1, still "one per window with a pixel gate"), WIN-AUDIO-1 (parked by
  the user), Deck re-cut (the Deck was offline), the two decomp harness leads 881C11A0 / 880E60C0 (decomp-campaign route items).
- ✅ Harness landmine CLOSED (42ce68c): Homebrew `python3` → 3.15 without numpy; the gate scripts now source `scripts/pymac.sh`, which
  picks a python that imports numpy + Pillow (`PYTHON=` overrides).

## 2026-08-03 — USER-RULING CLOSURE SWEEP (attended session after the tid-fix ship)
- ✅ **Magenta-block corruption — RESOLVED-UNTIL-RECURRENCE** (user: "only happened once...
  we 'resolve' it for now, until it shows up again anyway"). No capture rig built. Re-open
  needs a fresh sighting + the continuous-capture plan.
- ✅ **Handover-fade fix (RT_FADEGAIN) — CLOSED WITHOUT DEPLOY** (user: "its all working
  perfect right now, lets close that one off too"). Likely OBE: the fix targeted the
  bridge→guest music handover, and the bridge music streamer was retired 08-01 — there is no
  host handover left to fade. The lever + code stay in-tree, default off.
- ✅ **Score Attack sign-in decline (#10) — CLOSED** (user: "we're able to pass by hitting A").
  The authentic declined flow dismisses cleanly = exactly the 07-29 ruling's definition of done.
- ✅ **Keyboard double-fire (#4)** — closed earlier today (gone for days; see item 4).
- ✅ **Audio (#11)** — the whole lane is CLOSED as of the 08-04 tid fix: guest renders ALL
  music + SE natively, levels reference-exact, user-ear-signed and deployed. Entry kept below
  for history only.

## 2026-10-29 — PARKED: WIN-AUDIO-1 demo-loop audio ring underruns on the PC (user: not audible)
- The Windows rc2 census legs log audio ring underruns in 20-30 s bursts about every 75 s in the hands-off attract loop (ARCADE 6/6 legs,
  XBOX 360 1/3; Mac 0), each burst right after an `[epochinval]`/`[texreval3]` texture re-decode cluster at a scene change. Controls excluded
  the sink (WASAPI worse) and the RT_VBSLEEP gate. User listened 2026-10-29: clean. Known issue in RC_KNOWN_ISSUES.md; evidence
  `_local/rc/0_3_0_rc2/{census,audio}/`, defect note 2026-10-29. When re-opened: (1) beta-2 engine (3827d81) on `scripts/rc_census_win.sh arcade 6`
  = regression-or-preexisting; (2) why textures are freed-since-decode every scene and whether the re-decode can leave the present path;
  (3) the audio worker's CPU during the storm (RT_AUDIOSTARVE + per-frame ms).

## 2026-10-12 — ADDED: iOS / iPadOS VERSION (post-RC1 follow-on, user-requested)
- **SCOPE RULING 2026-10-12 (user): iPad ONLY, "nothing fancy at all", touch controls NOT wanted (deferred).**
  Shape: landscape, the 720p frame letterboxed into 4:3; input = BT/MFi pad or a keyboard via SDL3's existing
  GameController + keyboard paths (zero new input code; no pad → a one-line "connect a controller" screen);
  the game's own TATE option covers portrait. Memory: a modern iPad's per-app limit holds the ~720 MB plateau,
  so the Darwin page-release fix becomes nice-to-have, not a prerequisite. New work, by risk: SDL3 + MoltenVK
  iOS static builds (CMake iOS toolchain), the COMBINED single-binary link (FUTARI_COMBINED=1), UIKit lifecycle
  around our main loop (SDL3 callback mode), saves in the app Documents dir, codesign. Distribution for one
  person: an ad-hoc developer-account build on the user's own iPad (1 year), no TrollStore. Skip: touch,
  portrait UI, haptics, iCloud, Game Center, App Store. Revised cost ≈ 3 design + 3 measurement windows.
  Option 0 (no engineering): Sunshine (Mac) + Moonlight (iPad) + a BT pad — tells us whether iPad Futari is
  wanted before any port work.
- **PORTRAIT TOO (user 2026-10-12).** The game has its own TATE/rotation option in Screen Setting, which draws the
  vertical playfield rotated inside the 1280x720 frame; the port only needs a HOST-SIDE 90-degree present
  rotation so that 720p frame's long edge maps to the iPad's long edge (16:9 inside 3:4 portrait = small
  top/bottom bars). Implement it as a renderer lever `RT_ROTATE=90|270` (final-blit rotation or swapchain
  pre-transform where MoltenVK allows) on the MAC build FIRST — testable today in a tall window / a rotated
  monitor, no iOS toolchain needed — then the iPad build inherits it and follows device orientation (or a
  setting). Pad-only input makes portrait trivial. Cost: +1 design window on the Mac, ~0 on iPad.
  **2026-10-30: Mac lever LANDED (b737e13 + debug dump 3097d95).** `RT_ROTATE=90` (clockwise: frame top on the
  window's RIGHT) / `270` (counter-clockwise: top on the LEFT); unset/0 = the old present blit, untouched. Only
  the window present changes (render/vk_render.cpp `rvkRot*`): vkCmdBlitImage cannot rotate, so under the lever
  the present is a tiny graphics pass -- render pass on the swapchain format (UNDEFINED -> clear black ->
  PRESENT_SRC_KHR; the clear is the bars), view + framebuffer per swapchain image rebuilt with the swapchain,
  fullscreen-triangle pipeline (push constant = rotation), cached view + NEAREST/LINEAR sets per present source
  (g.image / imageShow / imageLdr / FrameDelay ring slot), viewport = the rotated 720x1280 frame aspect-fit into
  the swapchain, filter by the blit's RVK_UPFILTER rule. The source goes TRANSFER_SRC -> SHADER_READ_ONLY ->
  TRANSFER_SRC around the pass, so compose, FrameDelay ring, readbacks and PNG dumps are unrotated and unchanged;
  imageShow/imageLdr/ring gain SAMPLED usage only under the lever. Shaders: shaders/rotate_{vs,ps}.hlsl ->
  render/rotate_spirv.h via `python -I tools/gen_rotate_spirv.py` (DXC on Windows; the Mac needs no compiler).
  Debug lever `RVK_PRESENTDUMP=<path>` (+ `_AT=<n>` default 900, `_EVERY=<m>`, `%ld` = present #) reads the
  FINISHED swapchain image back to a PNG, because `screencapture` over ssh fails ("could not create image from
  display"). Verified on the M3 Max (build/rot, `OUTDIR=build/rot OBJSFX=_rot bash build_mac_dll.sh`), one 45 s
  run each, title screen at window present #1800:
  `BIN=build/rot/futari_combined RUN_SECS=45 RVK_WINSIZE=720x1280 RT_ROTATE=90|270 RVK_PRESENTDUMP=/tmp/rotpng/x_%05ld.png RVK_PRESENTDUMP_AT=600 RVK_PRESENTDUMP_EVERY=300 bash scripts/run_mac.sh`
  -> 90 and 270 fill the 720x1280 window exactly (NEAREST, 1:1), mirror rotations of each other, no stretch;
  `RVK_WINSIZE=768x1024 RT_ROTATE=90` (iPad-portrait 3:4) -> 576x1024 fit at x=96, black pillars left/right
  (LINEAR); control (RT_ROTATE unset, 1280x720) -> title as before. VK_ERROR/VUID 0 in all four logs (0 in the
  preceding soak logs too); no FAILED lines. Known gaps: F11 fullscreen with the lever was not exercised (the
  fit is recomputed from the swapchain extent per present, so it should pillarbox); the default Mac run is
  RVK_HDR=0 sync present (source = g.image) -- the HDR/async sources (imageLdr, imageShow, ring slots under
  FrameDelay 2V/3V) are wired but unexercised; no live toggle or orientation-follow (iOS follow-up: drive
  RT_ROTATE from device orientation / a setting, or use the surface preTransform where MoltenVK honours it);
  input is not rotated (pad input needs none; touch would).
- **iOS/iPadOS port of the realcomp** (user 2026-10-12: "add an iOS version to the todo"). Viability was
  assessed for the recomp on 2026-06-29 and carries over: the port is AOT static recompilation (no JIT),
  so iOS's W^X ban does not apply; SDL3 and MoltenVK both ship iOS targets; perf is a non-issue on A17+/M-series.
  Realcomp-specific prerequisites learned this week: (1) **G5-fix first** — rt_phys.cpp never returns pooled
  pages on Darwin (ARCADE plateaus ~720 MB RSS, Q5/Q6 2026-10-11); fine on macOS, a jetsam risk on iPhone,
  so the Darwin page-release arm (RT_DECOMMIT) is a hard prerequisite, iPad likely tolerant either way;
  (2) **combined build, not module dylibs** — iOS will not dlopen unsigned dylibs; the host already has the
  FUTARI_COMBINED=1 arm (build_mac_dll.sh header) — the iOS bundle links both modules in (or embeds them as
  signed frameworks); (3) **input** = GameController framework for MFi/BT pads (easy) + a touch overlay
  (net-new UI; TATE shmup → portrait touch-drag-move is a good fit); (4) **distribution** = sideload only
  (TrollStore preferred; AltStore 7-day re-sign fallback) — same bring-your-own-dump rule as the F&F .app,
  never the App Store; (5) **build** = CMake iOS toolchain + cross-compiled SDL3/MoltenVK + codesign/provisioning,
  budget one TBDR render-debug pass. Order: after the RC1 cut and after at least the Black Label module
  (PLAN_other_modes §4), unless the user re-ranks. Cost guess: ~6 design + ~6 measurement windows for a
  first TrollStore build of the two RC1 modes; measure committed RSS on-device before declaring viable.

Ranking axes: **gate relevance** (user ruling 07-26: "nothing ships until menus/shell is
done"), **severity class** (correctness > survivable-failure > fidelity > feature), and
**cost confidence** (measured vs speculative). Two-strikes rule applies per item: two
consecutive ship-nothing legs ⇒ back here for re-ranking, not another leg.

## POST-BETA RESEARCH (2026-08-03)
- **Swap-stale heap descriptors**: repeat mode swaps leave typed texture fetch constants with
  garbage fmt bits (fmt=54, heap base 0x20B7000, 320x240) — runtime-heap state from the prior
  attach survives the re-image (only xex DATA sections re-image). Mitigated 5addec0 (black
  placeholder, RVK_UNSUPWHITE=1 reverts); find the descriptor owner + whether other stale-heap
  classes lurk behind the same seam. Related: ~21 dirty XACT packets/attract (same freed-state
  family, see the audio lane notes).

## 2026-09-20 — POST-FIX PLAN ratified by the user: docs/PLAN_after_boss1_0920.md (Phase 0 boss-1 head bisect · Phase 1 constant-pool audit tool + boss plate gate + parked debts · Phase 2 decomp slate w130 / Opus items / rulings owed).

## NOW — the gate path (menus/shell → F&F build)
- ✅ **G-START (RC1, 2026-10-12) FIXED**: START in the hub / a hub submenu no longer starts the ARCADE game behind the shell -- RT_STARTWIRE now obeys the shell's own game-input gate (cb3 0x821C5618 *(ctx+152)); host-only, default ON, `RT_STARTWIRE_NOGATE=1` = old path. NOTE_fnf_shell_defects.md 2026-10-12. .app needs a rebuild to carry it.
- ✅ **DC-2 (RC1, 2026-10-12) FIXED**: ARCADE START at 「CONTINUE?」 no longer opens PAUSE -- the RT_STARTWIRE line now reaches the game only after the shell's driver tick has evaluated the same START edge (g_rt_startedge; the game used to take the continue first, then the shell paused); ARCADE CX 8/8, 360 3/3; RT_STARTWIRE_RAWLEVEL=1 = old timing. Host-only, .app rebuild carries it.
- ✅ **DC-1 (RC1, 2026-10-12) NOT A DEFECT**: "second TRAINING start dead in-process" was rc_chain gating on the per-process-capped `[dclose]` log line; repeated training starts work (T2+T3 PASS x2 per mode); script fixed.
- ✅ **KSTUB-OVERCLEAR (RC1, 2026-10-12) FIXED**: XGetVideoMode / VdQueryVideoMode wrote 0x50 bytes into 0x30-byte guest buffers (clobbered callers' saved r26-r28/f31, f30/f31/r14) -> exactly sizeof(X_VIDEO_MODE); no screen changed; audit docs/AUDIT_kstub_sizes.md leaves 5 READ-UNDER stubs (VdGetCurrentDisplayInformation, VdGetCurrentDisplayGamma, VdGetSystemCommandBuffer, ExGetXConfigSetting tz names, XamUserGetXUID) for their own A/B windows; .app rebuild to ship.

0. **SHELL COMPOSE 1:1 (decomp-grounded) — THE flicker lane (re-rank 07-28 ~02:05).**
   Two strikes on the flicker item (wait-path cluster; ghost-draw fix — both real fixes, both
   failed user acceptance) ⇒ stop whack-a-mole. New user characterization: element-transient
   flicker on MANY shell elements (M2 circles, TOP MENU glyph, PRESS START beyond its authentic
   blink, title logo sometimes) ⇒ suspect element dropout / partial-frame compose, NOT extra
   draws (that arm is closed, 4336c86). Plan = the already-ratified "decomp 1:1 time" campaign:
   decomp FUN_821CDBE8 compositor family + veil FUN_82182A68 (SPEC_shell_compose_1to1.md is the
   bible), implement shell/intro compose register-true, retire heuristic persist/layer-seg for
   shell scenes. ACCEPTANCE: user-judged full intro+TOP MENU soak with zero transient flicker
   on those elements; plus a missing-draw census instrument (drawtrip only ever counted EXTRA).

1. ✅ **CLOSED 2026-07-29 — RVK_DECOUPLE DEFAULT FLIPPED ON** (user ruled input feel ACCEPTED).
   `vk_render.cpp` ~9440 default `-1` -> `(asyncRender && rbudgetEnvA != 0) ? 1 : 0`;
   `RVK_DECOUPLE=0` still reverts, and the legacy `RVK_ASYNCRENDER=0` / `RVK_RENDERBUDGET_MS=0`
   pins still mean inline so no forensic script changed meaning. Ship envs needed no stripping
   (they never pinned either lever); redundant `RVK_DECOUPLE=1` pins removed from 8 drives.
   GATES: in-stage ticks 11/11 windows **59.926-59.971/s**; `c3_verdict t9 vs c1` **PASS**
   (G1-G5 all true, f16501/300s, zero VUID/VK_ERROR/no-pipeline/FATAL).
   ⚠ **CARRY-FORWARD:** the flip is **inert under `RT_NVK=2`** — `rt.cpp:2450` bypasses
   `rvk_present()` entirely, so nvk has no decoupling at all (t9: 0 fast + 0 inline presents in
   16501 frames). nvk measures 59.905-59.979/s in-stage today only because its submit is cheap;
   if that cost grows, the welded clock returns and this lever cannot rescue it. See the
   NOTE_campaign_decomp.md entry of the same date.
   Follow-through (still open): deferred texel gate for the WC-swizzle fix (attract border +
   4_legal, needs unlocked workstation, minutes).

2. ✅ **CLOSED 2026-07-31 — FNF-1 was never a streaming race; already cured.** Design pass
   (_tmpscripts/fnf1_fix_design.md) proved the white mass was ADDITIVE ACCUMULATION from
   uncleared frames (2.4x white density vs SDK in same footprint; partially-streamed RAM
   decodes DARK not white; RT_ASYNCIO v2 is synchronous; guest fences the overlay itself;
   RVK_ZSCAN never fired positive in 15 bases). Curer = the 07-28 clear-byte 1:1 change
   (RVK_NOCLEARBYTE=1 reverts). R0 confirmation boot 2026-07-31 on ship renderer (RT_NVK=2):
   Vulkan readbacks rvk_frame40/60.png INSIDE the historical f40-105 window = clean distinct
   rings, zero white mass. Do NOT carry a "streaming-race" entry forward (mislabel cost two
   legs). Surviving instrument debt re-filed as item 2b.

2b. **RVK_TEXREVAL3 warm-up dense revalidation** (small, standalone; from fnf1_fix_design.md
   §B/R2): bootstrap bug — `fires>=2` unreachable when the 64-sample hash is too sparse to
   see the change that would increment it. Plan banked with levers RVK_REVALWARMUP/
   RVK_REVALSAMPLES, [reval3warm] instrument, HI stream-pool positive control. Not urgent
   (its defect class has no open reproducer since the 512MB saga closed).

3. **FNF-7 transient extra menu quad** — backlogged (two-strikes), now better-scoped.
   NOT present-coupling (survives the atomic-window worker at baseline rate — 07-27), NOT
   duplicate-emission (FALSIFIER.md: 96.7% unique). It is a guest-state/decode-class defect;
   known identity (n=4 menu-atlas quads base=0x1DB1000 vs=1 ps=2, one ~2.6s burst after menu
   entry). One-frame visual blip. Re-open only with a NEW instrument idea, per rule.

4. ✅ **CLOSED 2026-08-03 — user: "double fire has been good for a while now, i have not had
   it happen for days."** Cause unpinned; most plausibly collateral benefit of the thread-
   priority fix (6f83567) or the unique-thread-id fix (d03cb52) — both changed input/timing
   interleaving, and the ATLAS cause class was "input double-fire = cross-consumer" (a race
   shape the tid fix directly serializes). Re-open only on recurrence WITH a repro.

4b. ✅ **CLOSED — ROOT CAUSE FOUND AND FIXED, s2B leg 11 (2026-07-29).** The border shadow was
    never dropped by any gate: `FUN_82182008`'s ring draws reach the display segment every frame
    (`[nvkdbg] vs=5 ps=14 st=12`, blend 07060706), but `matchImLoad` resolved their VERTEX shader
    by 32-byte prefix + size, which twelve 132-byte shell VS share — so idx5 (writes interpolator 0,
    ZEROES 16) was substituted for idx15 (writes interpolator 16 = COLOR0), and PS idx14
    (`out = interp16 * c2`) shaded the whole ring to (0,0,0,0). Fixed by a full-ucode byte-distance
    VS tiebreak (`RVK_NOSHADOWFIX=1` reverts); pixel-verified in the t6 bank. Both older diagnoses
    below (save-gating, then menuLive/overlay-replay gating) were WRONG — kept only as history.
    ⛔ **SUPERSEDED / MOOT ON THE SHIP PATH (s2B leg 10, 2026-07-29). Do NOT implement the replay
    split below.** The whole `doOverlay`/`menuLive`/pillarbox machinery lives inside
    `renderFrameReal`, and `shell/gen/rt.cpp:2450-2457` short-circuits Present with a bare
    `return;` whenever `nvk_mode() >= 2` — it never reaches `rt_render_maybe()`. Under RT_NVK=2
    (the campaign's renderer) there is no overlay replay, no pillarbox and no menuLive gate at
    all, so nothing is dropped: the GUEST composes the window and its furniture draws flow through
    natively. Confirmed in the t3 bank — f3600's final display segment is `SEG [53,87)` = 34
    guest-native `vs=1 ps=2 prim=5 n=4 st=24` quads into the display surface 00358590, and the
    border-gradient profile outside the panel is pixel-identical between the t3 (nvk) and c1
    (legacy) arms. The design below is still the correct fix FOR THE LEGACY PATH; it should be
    closed with that path, or re-opened only if RT_NVK=2 is ever abandoned. If a shadow defect is
    still visible to the user under RT_NVK=2 it is a DIFFERENT bug (the ring is being drawn — the
    question would be with what colour/blend), and must be re-diagnosed on the nvk stream.
    Original entry kept below for the reasoning and the savegame map:

    **Border shadow missing — ROOT FOUND 2026-07-29 (NOT save-gated; user framing refuted by
    A/B: save_playtest savegame.bin is byte-identical to freshcard, shadow missing in BOTH arms
    unconditionally).** Guest emits the ring every ROM frame (FUN_82182008: 4 edge strips 16.0f
    extrude 0xFF080808→0 + 4 corner fans; caller FUN_82183C68; gate = DropShadow@0x16E0 &&
    !SimplifyDraw@0x16E8 — both default-on in every card). PORT drops it: overlay replay is
    gated on menuLive (vk_render.cpp ~7638 doOverlay), so ALL shell window furniture (ovN=8,
    do=0 on 4772/5000 presents) is discarded during attract/gameplay. This is backlog-#7's
    class and explains ATLAS_shell_menus "DropShadow toggle has no effect". FIX DESIGN (banked,
    from investigation): split overlay replay into panel-furniture (always replay, discriminate
    by target rect vs panel rect dev+0x17a0..0x17ac) vs shell dialog sprites (keep menuLive
    gate); route furniture through the panel's anti-diagonal transform; lever RVK_PANELFURN=0.
    Discriminator hook [shadowring] on sub_82182008 IS IN TREE — confirm 1x/frame + gate dwords
    on the next boot before implementing. Savegame layout fully mapped en route (screen-settings
    block 0x16D8+: wallpaper/brightness/DropShadow/FrameDelay/SimplifyDraw/Layout/Picture).

## SURVIVABLE-OPEN (mitigated, not solved)

5. **FNF-2 device-loss lottery** — ~1 hit/10 game drives; die-loud makes it a clean fast-fail
   instead of a hang. Root-cause STOPPED per panel ruling (make it survivable, let tester
   GPUs surface it). Standing evidence: snap-shape drives exercise it, fnf2 harness shape
   does not; CDL layer installed; parallel LANES now enable cheap 50-100-boot soaks if ever
   resumed. Optional next: device-recreate instead of exit (bigger, attended).

## FIDELITY DEBTS (post-gate, cheap-ish, attended)
- **[09-20 CLOSED] FNF-14 NOW LOADING black during loads** — decomp regression (logo_indicator.cpp float pool 0x40 low, 08-14); fixed in futari_decomp + host exe rebuilt; see NOTE_fnf_shell_defects.md 2026-09-20. Owed: user eyes on boot feel + whether in-GAME stage loads also show now.
- **[10-03 CLOSED on the Mac] FNF-15 TRAINING config panel draws NO rows** — root cause = missing `r4 = renderer` before the font-measure bctrl in the readable stateBuild (menu_base_states.cpp), fixed in futari_decomp, verified 0.758 (see NOTE_fnf_shell_defects.md 2026-10-03; the two Picture/Simple-panel divergences found alongside are still open). Was: **[09-20 OPEN]** (only the tips caption; the dialog is live but invisible). CONTROL-PROVEN readable-C regression in one of eight shell TUs (menu_base_states menunode_states menu_containers options_panel_base options_panel_hooks options_decide_builders training_config textview_draw); eight single-TU control exes built (build/futari_combined_ctl_<arm>.exe) + metric scripts/boss1/panelcheck.py — bisect NOT run (user stop 09-20, pivot to decomp). See NOTE_fnf_shell_defects.md 2026-09-20 FNF-15.
- **[09-20 PARKED] BOSS 1 HEAD — training route to the boss now WORKS** (scripts/boss1/boss1_drive2.sh, ~2 min, RIGHT on the invisible Stage row + START; NAV_MAP's "fresh card locks stage" was dropped presses). Head verdict and the old-build bisect NOT reached (08-07 exe repeats a held DOWN). Same ledger entry.
- **[10-04 CLOSED on the Mac] BOSS 1 HEAD L/R TEXTURE SWAP** — two operand slips in the readable boss-1 draw body (futari_decomp decomp/game/objaction_queue.cpp sub_880DCE90, straight-ahead pose, second face-mosaic pair: DY byte routed into X, base word G-15584 dropped); found by the all-game revert arm + per-push trace diff, verified head matches the arcade reference (NOTE_fnf_shell_defects.md 2026-10-04). Was: **[09-06 USER RE-REPORT] BOSS 1 HEAD L/R TEXTURE SWAP — STILL PRESENT.** "boss 1 head still also has the
  defect, left texture on the right and the right texture on the left." First banked r23-w35 (08-24): captures in
  futari_decomp/bank/r23/w35 (not clean plates); first hypothesis class = the mirrored-pair sprite machinery
  (cf. 0x8819DF88 mirrored sprite emitters, w4). Still OPEN; no fix ever shipped. Measure-first plan when a
  realcomp lane is next ruled: RenderDoc capture of the boss-1 head draw (port) vs the SDK/Xenia oracle frame at
  the same phase; compare per-quad UV rects + the mirror flag path (Q+0x08 overlay mode / u-flip) for the two
  head halves. Decomp angle (cheap, in-scope): the boss-1 head draw body's mirror/flip operand handling in the
  readable C — a decomp read may name the bug without a drive. Ruling 09-06: NOTED, not laned (decomp first).

6. ✅ **CLOSED 2026-10-05 — MOOT ON THE SHIP PATH. D3 wall-dim exact factor at composite** (0.875
   vs 0.90 = 1/16 quantization). Both wall-dim blocks (the `lround(0.9*16)/16` line at
   vk_render.cpp:6677 and the live-guest-read block at :9218) sit inside `renderFrameReal`, the
   LEGACY compose path that `shell/gen/rt.cpp:2560` short-circuits whenever `nvk_mode() >= 2`.
   Measured 10-05 under the attended env (RT_NVK=2): `RVK_WALLDIMLOG=1` through the hub and the
   Options screens = **0 `[walldim]` samples across 97 presented frames** (_local/nav_mac/walldim/).
   Under RT_NVK=2 the wallpaper's dim is the GUEST's own draw (the same re-derivation that closed #7),
   so there is no host factor to quantise. Re-open only if RT_NVK=2 is ever abandoned.
7. **Honor-settings work-list — ✅ CLOSED BY RE-DERIVATION 2026-08-13 (Day-3): the premise was
   legacy-renderer-era.** Under RT_NVK=2 the GUEST applies its own settings and the renderer
   reproduces them (settings_audit.md's own 0-PRE rotation proof, now extended). Save-poke
   matrix on the ship build (evidence /c/tmp/day3/, ledger 08-13 Day-3 block): Rotation/TATE ✓,
   Layout preset incl. ExtraView multi-panel ✓, Picture preset (scanline/effect renders) ✓,
   Brightness ✓ (90→30 visibly dim), DropShadow ✓ + SimplifyDraw ✓ ([shadowring] gate14/gate18
   track the save bytes — the guest gates its own draws), Wallpaper ✓ (pre-known). B1 (settings
   reset when a replay exists — single-item enumerator) VERIFIED FIXED live: pkgs=2, both
   SAVEGAME items served, savegame.bin resolves under systemdata.bin.
   **FrameDelay ✅ HONORED 2026-08-15 (user-signed design call):** decomp recovered full
   semantics (save 0x16E4 = display-latency enum 0V Tearing/1V Fast/2V PCB/3V Slow, default
   1V; futari_decomp NOTE_options_game.md §4). Guest chain reaches a PM4 present-interval
   packet nothing walks at RT_NVK=2 — now honored in the window-present path (vk_render.cpp):
   reads the guest-applied shell global DAT_821F8558 per present; 2V/3V = composed-frame
   delay ring (+1/+2 frames of display latency, tear-free, zero contact with frameclock or
   game logic); 0V ≡ 1V BY DESIGN (MAILBOX is already non-blocking minimal-latency; the 360
   needed tearing only to dodge its vsync wait). Lever RVK_FRAMEDELAY=0 reverts to inert.
   Smoke: day3_poke 0x16E4:2/3 → "[rvk] framedelay=1V→2V/3V" transitions (proves renderer
   read + guest applier), attract runs clean, frameclock cadence unchanged (logs
   /c/tmp/day3/poke_fd2v.log, poke_fd3v.log). **⚠ 10-05 (macOS): 3V is a DEFECT, not a feel
   question -- the port runs at ~210 presents/s with the ring engaged (57 at 1V) and menu input
   drops/repeats; NOTE_fnf_shell_defects.md 2026-10-05. FIXED same session: RT_FDPACE paces 2V/3V on
   the vblank counter in the VdSwap hook (the guest drops its vsync-wait flag in those modes and the
   port's instant-retire GPU gave no back-pressure); 3V now ~55 presents/s, menus navigable.** Sub-offsets PINNED 10-05 (same note: card +0x16F8 preset record, zoom +0x08,
   X +0x18, Y +0x1C; FrameDelay byte +0x16E7); B3 menu save round-trip PASSED scripted 10-05
   (four bytes, atomic publish, read back on a fresh boot). Still open: oracle-grade pixel
   fidelity of the effects (post-beta).
8. **Card-page clipped fragment / title blink** — ledger says authentic/known; do not re-chase.

## FEATURES (post-gate)

9. **2P join — ✅ OPENED AND WORKING 2026-08-14 (Day-6, commit 94030b2; ledger NIGHT-6).**
   The "no game-side writer" mystery was input-starvation: the writer (sub_881366D0) fires the
   moment user==1 input exists. Physical XInput idx 1 was ALREADY a ship feature; added the
   scripted P2 channel (pad FIFO optional 4th hex field → user==1). Verified live end-to-end:
   P2 START at char select → [joinp] WILL-JOIN slot=1 → 2P frame fills → both selects →
   TWO-SHIP co-op stage → 2P game-over reaches the replay prompt cleanly. The 07-23 post-join
   freeze did NOT reproduce (retired by the 08-03 pause-flow fix). ✅ POLISH ROW DONE
   2026-08-14: nav_2p_join()/nav_2p_press() in futari_nav.sh; scripted co-op validation
   (day8_2p_validate.sh) COOP_arcade_PASS + COOP_360_PASS (join → dual selects → two-ship
   stage, unattended, both modules); 2P SIDE START route mapped (fires the SAME join handler,
   [decide] item=1 → mirrored char select with the 1P seat "No Entry"); NAV_MAP.md 2P section.
   Movement distinctness: pad-level proven (separate user0/user1 words drove separate
   seats/selects); in-stage two-ship visual captured mid-hold. Remaining: the user's own
   two-pad couch session (attended acceptance).
10. **Score Attack sign-in: GRACEFULLY DECLINE — ✅ VERIFIED END-TO-END 2026-08-13 (Day-5;
    08-03 user ruling re-proven scripted).** Hub A → the guest's own "sign in to Xbox LIVE to
    access rankings / A:OK" dialog → A → clean dismissal → the SCORE ATTACK submenu with only
    LEADERBOARD greyed (declined-but-playable). No hang, no crash, no fake profile. Ledger
    NIGHT-5 block has the marker chain + screenshots.
11. **Audio** — PARKED by user 07-25; resume spec banked (xWMA decoder = highest value,
    design ready in [[futari-audio-bringup]]). Large. Bridge = audible fallback meanwhile.

## PLATFORM / END-GOAL

12. **[10-04 late] macOS = BETA 3 TARGET, two modes** (docs/PLAN_beta3_mac.md): the module arm is ported
    (`build_mac_dll.sh`, dylibs; abn tree regenerated on the Mac with the reconstructed eqv-fixed recompiler,
    `scripts/regen_abn_mac.sh`); the F&F flicker gate ships as a KNOWN ISSUE by user ruling 10-04.
    **Deck/Linux + macOS ports — RE-OPENED 2026-10-03 (user: "could we whip up a macos version";
    the user's only machine is now an arm64 Mac).** Linux build resurrected and green
    (`build_linux.sh`: links, runs headless, SDL3 window smoke-tested on Xvfb+llvmpipe); macOS
    handoff written blind (`build_mac.sh` + `docs/PLAN_macos_bringup.md`), to be driven to green
    by a session on the Mac. Previous ruling (2026-07-27: "Windows only for now") superseded.
    Banked for that day: the welded-clock fix (RVK_DECOUPLE) was the "slow by construction"
    mechanism the old Deck pacing notes blamed — a Deck retest under decouple is the first
    step and may make the old timer-granularity work moot.
13. **Ship targets: no-SDK, user-supplied-dump extraction — ✅ FUNCTIONALLY DONE 2026-08-13
    (Day-4; ledger NIGHT-4 block).** tools/extract/ (GoD/ISO/STFS/unpacked, hash-verified,
    manifest-checked, fail-loud) + DLC entitlement gate in stubs.cpp (RT_DLCFORCE=1 reverts) +
    dist/next_release launcher first-run wizard (tested end-to-end) + docs/DUMPING.md. Port
    boot-verified on an extracted tree. Remaining before a public bundle: stage tools/extract
    + DUMPING.md into the zip, drop the bundled assets, one attended user run of the wizard;
    honest gaps: no Futari ISO or packed BL STFS on this machine to test against.
14. **Decomp→recomp hand-rolled elimination** — the long game ([[futari-matching-decomp-goal]],
    [[futari-hand-rolled-backlog]]); biggest single item now = the atomic-frame-boundary /
    renderer heuristics reduction that decoupling started. Background cadence.

## STANDING INFRA (done 07-27, listed for visibility)
- Survivability: die-loud + crash filter + WM_CLOSE exit (+ RVK_TESTDIE/RVK_TESTCRASH controls).
- Instruments: RT_TICKRATE, RVK_SLOWPRESENT/SLOWRENDER, [wperf], [slowframe], [fetchraw],
  RVK_DECOUPLE/RVK_WALKFULL levers.
- s2B leg 10 levers: **RT_NVKRING8=1** reverts per-target register-true colour formats (ring RT
  R16G16B16A16_SFLOAT for cfmt 3 = 7e3 float, resolve tex A2B10G10R10_UNORM_PACK32 for fetch
  fmt 54/7) back to the single g_rtFmt. **RT_NVKDBGEVERY=<n>** retunes the nvk census period —
  the hardcoded 600 divides the 4800-frame attract cycle exactly, so the CAVELOGO phase (~3300)
  was structurally invisible to every [nvkseg]/[nvkdbg]/[nvkhole]/[nvkvtx] census ever recorded;
  use 700 (hits f3500 on cycle 1, gcd 100 sweeps all phases). Unset = 600 = byte-identical.
- s2B leg 11 lever: **RVK_NOSHADOWFIX=1** disables the full-ucode byte-distance VS tiebreak in
  matchImLoad (render/vk_render.cpp) and restores the historical lowest-index-wins behaviour for
  prefix-colliding vertex shaders — i.e. puts the panel drop-shadow ring back to invisible. The
  tiebreak is scoped to RT_NVK>=2, so the legacy PM4 arm is byte-identical with or without it.
  Reference data: g_futari_vs_ucode[] in render/shaders_futari.h, regenerate with
  `python _tmpscripts/gen_vs_ucode.py <out.h>` (4 positive controls, refuses to write on failure).
  **(2026-07-31 RETRACTION: the "NOSHADOWFIX hangs the boot at ~f4200" report is NOT REPRODUCED —
  re-run on the current build it ran clean to f8701 / 150 s / 0 VK errors. The banked shadow_b log
  just ends at `[nvk] submit f4201` with no error and no die-loud, i.e. a harness DUR expiry. Every
  fence wait in this renderer is bounded at 10 s and would have logged a timeout. Not a landmine.)**
- New census: **[nvkring]** (always on) logs every stride-12 draw = the drop-shadow ring, with
  vs/ps/prim/blend/vteCntl/target and first+last vertex — a boot log alone decides whether it can
  reach pixels. **(2026-07-31: its throttle period was 4800 and the ring is 8 draws/frame, so every
  sample after #9 was the SAME strip of the SAME window — the corner fans had never once appeared
  in a bank. Now 4793, prime, and the sample walks all 8 slots.)**
- 2026-07-31 ranking-square leg levers (all default off, unset = byte-identical):
  **RVK_SHADOWDUMP=\<everyN\>** dumps every draw of every Nth frame with the **screen-space** rect
  (shell VS c10..c13 + batch viewport) plus identity/blend/c2; stride-12 draws also print every
  vertex with colour. ⚠ its transform is valid only for `vte&1` (matrix-class) draws — the ROM's
  `vte=400` offscreen draws output screen pixels directly and their printed rects are WRONG; fix
  before trusting an offscreen line. **RVK_SHADOWDUMPST=\<stride\>** restricts the dump.
  **RVK_RINGOFF=1** drops every stride-12 draw (the clean "is the ring the author" A/B — prefer it
  over RVK_NOSHADOWFIX, no shader-matcher side effects). **RVK_MODOFF=\<hex blendReg\>** drops one
  blend class (used to exonerate 0x05000500, the modulate/sprite-shadow class).
  Harness `_tmpscripts/shadowprobe.sh` (waits out a running play-test, kills only its own pid) +
  `_tmpscripts/shadowcap.ps1` (PrintWindow ladder that also logs z-ordered occluders).
- Throughput: parallel LANES (rate soaks), dec_soak.sh, EVIDENCE_INDEX.md.

## DECOMP FINDINGS LOG (new items surfaced by elimination work)
- **2026-07-27: starved shell event 0x3551C0** — surfaced by the rank-23 faithful-wait fix:
  an INFINITE KeWaitForSingleObject waiter hits the 10s watchdog repeatedly all session (the
  old code silently returned bogus SUCCESS every 10s, hiding it). Some shell thread waits on
  an event no producer ever signals — a stubbed/missing producer upstream. Harmless to every
  drive (waiter tolerates 0x102) but it is a real fidelity gap.
  **TRACED (same day): the waiter is shell worker thread 0x820B4248** (lrs 0x820B42E4/
  0x820B438C inside its body) — one of the TWO unmapped shell workers the threading atlas
  flags as a decomp COVERAGE GAP (spawned 2x/boot, stack 0x10000, "body absent from dump",
  ATLAS_threading_kernel.md:69/243). The event (0x3551C0, rt_alloc'd struct, lazily created
  on first wait — its KeInitializeEvent never runs) has NO producer in the port. Next step:
  ForceFunc-decomp 0x820B4248's body (decomp_shell.bat pipeline) -> name the event's role
  and intended producer -> decide stub-vs-implement. Self-contained Ghidra job, no game
  process needed.
  **RESOLVED (2026-07-27, Ghidra pass → ATLAS_threading_kernel.md §7): KEEP AS-IS / faithful
  idle.** 0x820B4248 = the shell D3D runtime's multi-core command-buffer-replay (predicated
  tiling) worker pool, one thread per enabled core (2 on Futari's device mask), per-thread
  record dev+0x2c40+n*0x6c; the 0x3551C0 event is the record's embedded KEVENT (rec+0x3c).
  Its ONLY producers are (a) DPC FUN_820B36B8 (queued kernel-side off the GPU ISR only when a
  title runs a tiling pass — Futari never does) and (b) device-shutdown FUN_820B36F0. So the
  event never fires on hardware either — nothing to implement. Optional cosmetics: whitelist
  lrs 0x820B42E4/0x820B438C in the faithful-wait watchdog log. Bonus fact for FNF-5 context:
  the designated-core worker waits with a 30ms timeout and PRESENTS (FUN_820a5408 VdSwap) when
  a swap is pending and the owner thread is starved — hardware D3D itself had a decoupled
  present fallback.
- **2026-07-27: FNF-11 handback chain decompiled** (→ ATLAS_scene_system.md §7 +
  ghidra_futari_decomp/NOTE_fnf11_handback_decomp.md). RETURN TO TOP MENU confirm = GameEntry
  msg 13 → mailbox 0x887AD58C=1 → outer FSM st 5→2 (destroy all session scenes) → state-2 FULL
  teardown: releases EVERY cached GPU texture of categories 2..0x22 (FUN_8813a3c0 →
  FUN_88090b48 → FUN_8808d5b0 destroy-marks in upload table 0x887518D0), zeroes the asset job
  ring + 0x3D8EC asset table, scene-manager reset, zeroes session workspace → st 2→5, session
  FSM restarts 0→1 and RE-REQUESTS all art (fresh decode+upload burst). Display-side contract:
  honor destroy marks (no host cache keyed on pre-teardown texture identity — FNF-10 lesson
  generalized), resync any job-ring mirror, expect full re-upload. Freeze suspect ranking:
  stale host texture/wallpaper cache > stale PM4/compose replay > shell scenes (shell logic
  provably advances). Honest gap: shell msg-13 sender not nameable statically (no li rX,0xd
  near any indirect call in the whole shell image; value arrives computed via widget-msg
  forwarding) — cheap decisive probe = LR log in GameEntry when msg==13.
- **2026-07-27 late: FNF-11 PART 2 ROOT-CAUSED (decomp only, no build)** â†’ ATLAS_scene_system.md
  Â§8 + ghidra_futari_decomp/NOTE_fnf11_handback_decomp.md "PART 2". **The menu-level quit is NOT a
  handback and NOT texture staleness â€” it UNLOADS THE ROM.** At the in-ROM `game_title` menu,
  `item_close` (id 5, TIPS_GAMETITLE_EXIT, **no dialog**) â†’ clears the driver run mode
  (`driverObj+0x78=0`) + **msg 12** (`FUN_821C2B50`, `li r3,0xC` â†’ GameEntry case 0xB:
  `DAT_88252D58=-1`, `DAT_887AD584=3`, `DAT_887AD59C=0x8000`, **no mailbox**); `item_return to top
  menu` (id 6) â€” which **B/cancel is byte-identical to** (same dialog
  `YESNO_GAMETITLE_CONFIRM_RETURN` @0x8204DE60, cursor force-set to 6, `FUN_821D0CB0(-1)`) â†’ **msg
  13** (`FUN_821C2B38`, `li r3,0xD`) **plus `FUN_820735C8(owner, 0x820619F0)` = kill the owner
  task**. Measured in fnf11_fix_partial.log: msg 13 then **msg 3 + `XexUnloadImage`** in the same
  frame, owner task dies, shell root FSM `FUN_821CE098` re-enters phase 5 and builds a fresh TOP
  MENU (`FUN_821B80D0`, vt 0x82050518, movie `menu_title_menu`). No `st 5->2` is *possible* here
  (msg 5, the ROM tick, stops before the mailbox can be consumed) â€” that is faithful, not a bug.
  **Port fix class = compose routing after `XexUnloadImage`: the post-ROM twin of the pre-ROM
  compose gap fixed by RVK_PREROMWIN/1cfbfc3.** `[mvt] NEW vt 0x82050518 ticking BB298 while ROM
  live` is the smoking gun (stale ROM-live predicate). **Register-true gate already in the guest:
  `FUN_821CE400` sets `[0x821F8588]+0x64 = 1` whenever the shell root phase is 4..6** ("shell
  front-end owns the screen"). The degenerate `tx=146.25 ty=-280.00` matrices are the new top
  menu's items *born hidden at scale 0* â€” D1-B rule holds, repair stays OFF.
  Corrections owed to earlier notes: (a) part 1's `st 5->2` came from the **session-FSM state-8
  route**, not the msg-13 mailbox (msg 13 fired exactly once all session, on this quit);
  (b) ATLAS_scene_system Â§7.5's "msg-13 sender not nameable" is CLOSED â€” the literal is
  `li r3,0xD` (msg id in **r3**, arg in r4, `bctr` tail-branch), which is why the old byte-scan for
  "`li rX,0xd` near an indirect call" missed it; (c) Â§7's "msg 3 is a never-observed path / the game
  never hands the display away" is REFUTED for these routes.
- **2026-07-27 late: FNF-12 hide mechanism NAMED** â†’ ATLAS_scene_system.md Â§8.5. The boot logos and
  the NOW-LOADING overlay are **shell PSB movies**, not game assets: `motion/logo.lzx`
  (`FUN_821D1BF8` â†’ `FUN_821D1B50` â†’ build `FUN_821D1890` â†’ tick `FUN_821D1780`) with elements
  **`cave`** and **`M2`**; and `motion/loading_replay.lzx` = the *CRscIndicator* overlay
  (`FUN_821CDB18`/`FUN_821CDB08` â†’ `FUN_821CDA60` â†’ build `FUN_821CD4B0`, ramp `FUN_821CD140`) with
  elements `loading`(clip **`now_loading`**), `connecting`, `accessing`, `replay`.
  **Every one of those elements is created HIDDEN: `element+0x0C = 1` and `record+0x1DD = 0`**, and
  is shown only when its own state fn clears `+0x0C` (the logo tick does exactly that at each
  60-frame window start). **Display-side contract: re-read `element+0x0C` EVERY frame (it is the
  authoritative hide flag â€” same field the D1-B leg called `hide0C`), honor `record+0x1DD` as
  "clip running" and `record+0x1E0/+0x1E4` as the clip frame range, and apply the per-element RGBA
  modulate written by `FUN_821796B0(elemCtx, packedRGBA, alpha)` â€” the logo fades ARE that ramp, not
  a framebuffer blend.** A port that samples `+0x0C` once at bind time draws the loading pic through
  the whole logo sequence = the reported flicker. The screen-wide veil is separate
  (`FUN_82182A68(target, frames)` on `DAT_821F8574`; -1 = HOLD, 0 = RELEASE + replay stashed).
  Boot LZX working set (for the user-supplied-dump extraction step): `FUN_821CD378` preloads
  `motion/menu_dialog|menu_panel|menu_title.lzx`, `font/font8bm|font16bm|font24tt|font32tt.lzx`,
  `text/StringTable.lzx` from a table at 0x821ECB78..0x821ECD38.
  Still open for a 1:1 intro: `LAB_821D1740` (logo stage 2), `FUN_821CD270`, and **who creates/kills
  the CRscIndicator task** (`FUN_821CDB18`'s caller) â€” i.e. the exact frame windows.
- **2026-07-27 late: ARCADE vs XBOX 360 MODE â€” where the flag lives** (compact, per scope
  directive; game-side consumption deferred post-alpha) â†’ ATLAS_scene_system.md Â§8.6. Shell
  GAME-SELECT = `FUN_821B80D0` (vt 0x82050518, movie `menu_title_menu`, or
  `menu_title_menu_del1.01` when `*(DAT_821F858C+0x38F0) & 2 == 0`; tips TIPS_GAMESELECT_VER154 /
  _ARRANGE / _BLACKLABEL / _BLACKLABEL_DISABLE). Picking a title opens the nested **`arcade_front`**
  menu (`FUN_821B7F30` â†’ `FUN_821D2628`) whose 0/1 answer is the **ARCADE / XBOX-360** choice;
  `FUN_821B7CC0` folds them: **`modeIdx = titleIdx*2 + sub` (0..7)**, ids 4/5 gated by the
  DLC/entitlement check `FUN_821897C0()`. It is stored in the shell root task at **`root+0x54`**,
  handed to `FUN_821C3F38(mem, modeIdx)` (GameDriverTask ctor, vptr 0x8204FF94) which parks it at
  **`driverObj+0x68`**, readable via `driverVt+0x10` (`0x82061450`). Game-side consumer NOT traced;
  refuted candidates: `DAT_88252DD8` (a divisor/counter) and `DAT_887AD584` (the *game-mode*
  selector 0..3). Next probe when needed: `FUN_821C3B90` (driver first state) and the msg-1 config
  block it builds, even vs odd modeIdx.
- **2026-07-27 late: new Ghidra tooling (additive)** in ghidra_futari_decomp: `vt_shell.bat`
  (vtable dumps), `asm_shell.bat` (raw asm range), `refs_shell.bat` + `gs/RefsOnly.java` (reference
  listing WITHOUT decompiling every referrer â€” much cheaper than findrefs_shell.bat for call-graph
  questions). `decomp_game.bat` is still the missing wrapper. Decomp-to-C readiness ranking for the
  intro + 1.5 arcade path appended as HUMAN_READABLE_DECOMP_PLAN.md Â§8.

- **2026-07-27 late (addendum): FNF-12 lifecycle CLOSED — the NOW-LOADING overlay is PERMANENT.**
  Shell root ctor `FUN_821CE528` creates `DAT_821F8588` (global config, ctor `FUN_8218A358`) and
  `DAT_821F856C` (the LAYER/COMPOSITOR manager, ctor `FUN_821CDBE8` — the object merged_xex's
  `[layer]` probe already walks at `[DAT_821F856C]+0x68` stride 0x34), and **`FUN_821CDBE8`
  itself constructs the CRscIndicator task (`FUN_821CDB18`)** — i.e. the overlay exists before
  root phase 1, before the logo task, and for the whole session. **There is NO create/destroy
  lifecycle for the port to mirror: the only dismissal is the per-element `+0x0C` hide byte plus
  the `FUN_821CD140` alpha ramp.** Logo timeline now read end-to-end: `FUN_821D1890` build (both
  elements hidden) -> `FUN_821D1780` **60f FADE IN** (unhides on its first tick) -> `LAB_821D1740`
  **120f HOLD** -> `LAB_821D1670` **60f FADE OUT** (`a' = 0x80 - a`) -> `0x821D1540` (stage swap,
  undecoded). So 1s/2s/1s per logo at 60Hz, all via `FUN_821796B0` per-element constant-colour
  ramps. Detail: ATLAS_scene_system.md 8.9.
- **2026-07-27 late: FNF-12 HIDER FOUND — and it is UNREACHABLE BY DESIGN (not a port control-flow
  bug)** -> new note `ghidra_futari_decomp/NOTE_fnf12_loading_overlay.md` + ATLAS_scene_system.md
  8.10. `indicator = *(u32*)(DAT_821F856C + 0x1F0)` (CRscIndicator, permanent). **`FUN_821CD120`
  is the ONLY writer of `element+0x0C = 1`** (real entry 0x821CD120 — ⚠ Ghidra mis-bounds it at
  0x821CD140; installed by `FUN_821CD4B0` at +0x48). It fires only when
  **`indicator+0x71 == 0` AND `indicator+0x78` (f32 alpha) `> 0.0f`**: it ramps alpha down by
  `DAT_8204F878` = 1/60 per tick (full fade = 60 frames) and **at exactly 0.0f sets
  `*(u8*)([indicator+0x5C]+0x0C) = 1` and `*(u8*)(*(u32*)([indicator+0x5C]+0x10C)+0x1DD) = 0`**.
  `FUN_821CCC48(ind,1)` = SHOW (instant: `+0x71=1`, `elem+0x0C=0`, `rec+0x1DD=1`);
  `FUN_821CCC48(ind,0)` = HIDE arms the ramp ONLY and never touches `+0x0C`. Five arm sites, all
  literal: SHOW only at `FUN_821CD378`+0x821CD474 (r4=1); HIDE at `FUN_821CE4B8`/0x821CE500,
  `FUN_821CDE00`/0x821CDE50, `FUN_821CDF30`/0x821CDFB8, and **`FUN_821C69F0`/0x821C6A4C = a
  per-frame WATCHDOG hide** (the fn the port probes as `[modegate] 69F0`, thousands of calls).
  **=> `+0x71` is 0 essentially always, so the up-ramp never runs, alpha stays at its ctor value
  0.0f, and the hide store is unreachable — on hardware too. Hardware draws nothing because the
  per-element ALPHA is 0, not because of the hide byte.** The port shows the pic because it does not
  honour the modulate `FUN_821796B0(elem+0x10, (u8)(alpha*255) | (*(u32*)(elem+0xFC) & 0xFFFFFF00))`
  — **the alpha is the LOW BYTE of `elem+0xFC`**. Verified NOT a translation defect: generated
  `sub_821CD120` in shell/gen/ppc_recomp.35.cpp has `PPC_LOAD_U8(r3+113)`, both `fcmpu` guards
  and both stores (`PPC_STORE_U8(r10+12,..)`, `PPC_STORE_U8(r11+477,..)`) intact.
  **PORT CONTRACT: draw a PSB movie element with the alpha from the low byte of `element+0xFC` AND
  skip it when `element+0x0C != 0`. Both are needed — `+0x0C` is 0 all session for the loading
  overlay (only alpha suppresses it) while the boot logos rely on `+0x0C` flipping at their
  60-frame boundaries. DO NOT force `+0x0C = 1` (fudge factor; it would also mask the same
  renderer gap the logo fades need).**
  "Loading is done" flags, named: **`[DAT_821F856C]+0x1EC` = 1** (boot-ready, set by
  `FUN_821CD270` after all 8 preload entries bind; per-entry ready byte =
  `mgr+0x78+n*0x34+0x14`, n=0..7, `+0x10` = kind 2 font / 3 container), plus
  `[indicator]+0x70` (built, polled by `FUN_821CD490`) and the root's second gate
  `*(u32*)(*(u32*)(DAT_821F8588+0x54)+0x5C) != 0`. `FUN_821CC8F0` (mgr terminal state) = `return`.
  **⚠ RE-PROBE OFFSETS:** `indicator+0x4C`/`+0x50` are list nodes with NO hide byte and
  `+0x58` is the CONTAINER whose `+0x0C=0` is set on purpose and is correct forever; only
  `+0x5C`(loading/now_loading), `+0x60`(connecting), `+0x64`(accessing), `+0x68`(replay) are
  elements. Open gap: nothing read this pass can set `+0x60/+0x64/+0x68` to `+0x0C=0` (their
  enable bytes `+0x72/+0x73/+0x74` have un-enumerated setters) — if they truly read hide=0, log the
  guest LR at that store.

---

## 2026-07-28 — ★★★ SHELL COMPOSITOR SPEC LANDED (decomp; no code touched)

**Read `ghidra_futari_decomp/SPEC_shell_compose_1to1.md` before touching any shell/menu/intro
render path.** It is the implementation spec for the user-ratified "implement the shell intro
compose 1:1 from decomp" leg. `ATLAS_INDEX.md` + `ATLAS_scene_system.md` §9 carry dated pointers.

Ranked work items it produces (highest payoff first):

1. **★★★ CLEAR POLICY — the ghost-spinner fix.** The shell's whole-screen clear is issued by
   `FUN_8216D2F8` (`D3DDevice_Clear` = `FUN_820A19F0`, `Flags=0x3F` colour+Z+stencil, colour =
   `*(u32*)(R+0x218)` where `R = *(DAT_821F85B0+0x9C)`) and it is **conditional on the single guest
   byte `DAT_821EC65B`**. `FUN_82184CC8` (the veil pass, msg-5 pump) sets it to **1 only while
   `*(*(DAT_821F858C+0xC)+0x598) == 0`** (no veil effect running) and to **0 while one is** — the
   veil's own full-screen 1280x720 quad covers the previous frame instead. Screen call site =
   the thunk `FUN_82173200` (vt `0x820514CC`+0x34): `FUN_8216D2F8(R, this->+0x68, NULL,
   DAT_821EC65B)`. **Nothing else clears the screen; the logo scenes clear nothing at all.**
   ⇒ Replace the `RVK_PERSIST` heuristic (vk_render.cpp:5966-5979, the biased "clear more often"
   guess) for shell frames with a real read of `DAT_821EC65B` + `R+0x218`. `DAT_821EC65B` is 1 in
   the static image, so frame 0 clears.
   ⚠ Do NOT model this on `FUN_8216B9A0` (the RT-layer render with clear=1) — it has ZERO callers
   and exists only in .pdata. Its live no-clear sibling is `FUN_8216A860`.

2. **★★ Colour-multiply semantics — `0x80` is unity, not `0xFF`.** `FUN_8206D328(c,m)` does
   `min(255, (c_byte*m_byte) >> 7)` per channel with an identity fast-path at `m == 0x80808080`.
   The logo fade writes `(a,a,a,0x80)` with `a = (u8)(cnt * (1/60) * 128.0f)` → 0..125 (RGB fade to
   black, **alpha pinned at 1.0**), while the NOW-LOADING ramp writes `(u8)(alpha01 * 255.0f)`
   (`DAT_8204F8A8`) so a full-on overlay is ~1.99x **over-bright**. A port implementing `c*m/255`
   halves every fade. Two multiplies stack: the per-record alpha `rec+0x1D8` (0..255, `/0xFF`)
   pre-scales the low byte, then `FUN_8206D328(c, *(u32*)(ctx+0xEC))` where
   `ctx+0xEC == element+0xFC` and `FUN_821796B0` propagates it recursively over the subtree.
   (This SUPERSEDES the loose reading in the 07-28 FNF-12 entry above.)

3. **★★ Veil globals — the black-rotated-slash fix.** `FUN_82184CC8` writes, every frame,
   `DAT_821F859C` (**global rotation**, rad) and `DAT_821EC938` (**global scale**), and
   `FUN_821CEA38` — the draw of *every* transform-group node (class vt `0x820514C0`, 0x48 B) — bakes
   both into the node's matrix about its own pivot (`+0x1C/+0x20`), alongside the node's own
   scale (`+0x2C/+0x30`), rotation (`+0x34`), offset (`+0x24/+0x28`) and clip rect
   (`+0x38..+0x44`; `x1 < x0` = "no clip" sentinel). Reset = rotation 0 / scale 1.0
   (`FUN_821CC200`; phase origin 3pi/2 = `DAT_8204F894`). The captured port quad
   (corners `(-356.5,-261.5)/(411.5,-261.5)/(411.5,50.5)`, colour `0xFFB5B5B5`) is a normal shell
   quad through a rotated matrix — the `.5` fractions are the `-0.5f` vertex bias.
   **NOT a park/degenerate class — do not re-enable `repairMatrix()`.**

4. **★★ FNF-12(b)/FNF-13 placement — measure, don't scale.** The shell has ONE 1280x720 render
   target and ONE resolve+present per frame; **no tiled or sub-rect passes exist on the intro path**.
   The "2x2 tiles at x=512 / y=448" are **authored PSB sub-quads** (each QuadRec carries its own
   `srcX/Y/W/H` from `rec+0x6C/70/74/78` and its own dest anchor `T` from `rec+0x1B8/1BC`); hardware
   abuts them because `T(next) = T(prev) + (w,0)` exactly, `-0.5f` is applied uniformly to positions,
   and **no half-texel is added to UVs**. The measured gap (513-523 / 447-456) is a uniform
   **~2.0-2.2% canvas→clip scale error** (512*1.021≈523, 448*1.020≈457), not tiling.
   Canvas = `DAT_821ECF30` = 1280x720 (`FUN_8216EBE8`), mapped by `FUN_8216B6A8` to the centred rect
   **(-640,-360)-(+640,+360)** (factors +/-0.5f at `DAT_8204F80C`/`DAT_8204F810`; the non-16:9 mode
   uses +/-0.6666667f). ⇒ **Measurement first:** on a held logo frame dump the VS constants written by
   `sub_8216BED0`, plus `DAT_821F85B0+0x80/+0x84` (canvas) and `+0x88..+0x94` (live clip rect), and
   two adjacent QuadRecs' `T`/`w,h`/srcRect. Compare against the port's synthesised
   `{2/320, 2/512, -1, 0}` basis (vk_render.cpp:6406). No eyeball scaling fudge (doctrine).
   ⚠ `FUN_8216BED0` is VMX128 and **Ghidra cannot disassemble it** — runtime only.

5. **★ Emit/submit path to mirror exactly.** `FUN_82178E78(elem+0x10)` walks the record vector
   (`ctx+0xFC..+0x100`, stride **0x20C**) in the order given by the index list at **`ctx+0x11C`,
   traversed in REVERSE**, skipping record 0; type 4 = group (recurse over `*(rec+0x208)+0x3C..+0x40`),
   type 3 = nested movie, type 0 emits **iff `rec+0x1B4 && rec+0x1B5 && rec+0x5C`**; output is a
   **0x64-byte QuadRec** pushed by `FUN_82178D78` into the picture node's queue
   (`P+0x4C/+0x50/+0x54`). `FUN_82168E58` (vt `0x82051478`+0x08) **sorts** the queue, expands each
   QuadRec to 4 vertices (**24 B: `x,y,z=0,D3DCOLOR,u,v`**; anchor `T` = the transformed
   **bottom-right** corner, `V0=T+M(-w,-h) V1=T+M(0,-h) V2=T V3=T+M(-w,0)`, positions minus 0.5f,
   `uv = srcRect/texDims`), optionally emits a **second overlay pass** (`Q+0x08` 1/2/3 → mode 8/9/10
   with colour `Q+0x0C`), then RESETS the queue. `FUN_8216DAA0` does SetTexture + blend
   (`FUN_8216D598`, table `DAT_82051700`, 6 modes x 2 dwords) + `FUN_8209DC98(dev, prim=5, 4,
   verts, 0x18)` = DrawVerticesUP TRIANGLESTRIP. `mode&7 == 2` takes a **3-draw mask path**.

6. **★ Paint order.** Base node: `+0x08` life (0 alive / 2 dead), `+0x0C` hide (**re-read every
   frame**), `+0x10/+0x14` child list, vt `+0x04` tick / `+0x08` draw. The dual-container composite
   (app node vt `0x820516BC`, resource mgr vt `0x8204FAB8`, screen/view vt `0x820514CC`) draws via
   `FUN_82173900`: sub-node **B (`+0x2C`, parallel, `FUN_82173978`, ALL children in list order)
   UNDERNEATH**, then sub-node **A (`+0x10`, serial, `FUN_821739E8`, FRONT CHILD ONLY) ON TOP**.
   The NOW-LOADING overlay lives in the app node's **B** list (`FUN_821CDBE8` appends to
   `*(DAT_821F85A4+0x10)+0x40`).

7. **(correction, no work)** The 8x0x34 array in `FUN_821CDBE8` is **NOT a layer list** — it is a
   keyed **resource-bank cache** at `mgr+0x4C+n*0x34` (name std::string 0x1C B, **KEY@+0x1C**,
   kind@+0x20 {2=font,3=movie}, ready@+0x24, **bank handle@+0x28**, outs@+0x2C/+0x30). Fix the stale
   comment at `out_reco/merged/merged_xex.cpp:6242` ("layerobj@+12") when that file is next edited —
   `FUN_821B9FC0` returns an **LZX bank handle**, not a compositing layer. Also: item 12 above
   ("per-entry ready byte = `mgr+0x78+n*0x34+0x14`") should read **`mgr+0x4C+n*0x34+0x24`**.

**Honest gaps (do not implement from guesses):** `FUN_8216BED0` (matrix→VS constants, VMX128);
the caller of vt `0x820514CC`+0x34; `FUN_82173400` (so whether the `"CAVE360"` root task sits in the
app node's serial or parallel container is unread — it decides whether the overlay paints under or
over the boot scenes); the `DAT_82051700` values → `D3DBLEND` mapping (value 0 is not a legal
`D3DBLEND`, so trace `FUN_82096FD0`/`FUN_82097060` first); the `D3DCLEAR_*` flag split for
`0x3F` vs `1`; `FUN_820A2280`=Resolve / `FUN_820A19F0`=Clear are strong inferences, not symbols;
`FUN_82182FC8` post-FX pass rects (off the intro path).
