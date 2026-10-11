# NAV_MAP.md — the VERIFIED menu graph + log markers for scripted drives (2026-08-11)

Built screen-by-screen with a screenshot after EVERY press (user ruling 08-11: blind-cadence
nav desyncs — it silently entered SCORE ATTACK, joined 2P, and pressed into wrong menus).
Every transition below was seen on screen AND matched to its log marker in the same session.
**Driver rule #1: never press without asserting the current screen first** — via these markers
(scripts) or a screenshot (interactive). Fixed sleeps are for animation settle only (<= 4s);
anything longer must be marker-waited.

## Screen graph (both modules unless noted)

SHELL TITLE ("PRESS START", CAVE copyright)
  START -> TOP MENU................................. [mstate] BA4D8(ACTIVE) state 0x82061D50

TOP MENU (Ver1.5 / Arrange+BlackLabel+Ver1.01 greyed by modestub / EXIT)
  A -> CARD PANEL................................... [mstate] BB1D8(commit-wait) then 92E8 bind
  ⚠ the panel ALWAYS RESETS to the ARCADE card — it does not remember the last session's card.
  ⚠ the mstate cursor field does NOT track the card; verify the card VISUALLY or by outcome.
  LEFT -> "Xbox 360" card (desc bar: Xbox 360版をプレイします)
  ⚠ 3.0s DWELL GATE before any decide is honored (shell FUN_821bd1b8, +0x100 >= 0xB4) — use 3.6s.
  A (decide) -> module swap IFF the target module differs. [modswap] #N DONE / XexLoadImage
  ⚠ RETURN TO TOP MENU does NOT swap modules back — the swap is LAZY, fired by the next decide.

360 MODULE, cold boot (~40s): may land DIRECTLY at MODE SELECT (countdown timer).
360 MODULE, re-entry: animated Ver1.5 logo TITLE -> START -> HUB.
ARCADE MODULE: DEMONSTRATION attract with HUD -> START -> HUB.

HUB (7 items, identical layout in both modules):
  SCORE ATTACK(0) / NORMAL PLAY(1) / TRAINING(2) / REPLAY DATA(3) / OPTION(4) / CLOSE(5)
  / RETURN TO TOP MENU(6)
  markers: [p0build] item[k] name=..., [mcur] cursor a->b, [decide] ... item=k
  NORMAL PLAY = DOWN x1 (assert [mcur] 0->1) + A.

NORMAL PLAY SUBMENU: 1P SIDE START / 2P SIDE START / CONFIG / EXIT
  ⚠⚠ THE 2P JOIN TRAP: a stray DOWN before A here starts 2P SIDE. This is what the blind
  driver hit. Assert cursor (or press A immediately — 1P SIDE START is the default).

1P SIDE START -> MODE SELECT (Original/Maniac/Ultra, countdown) -> A
  -> CHARACTER SELECT -> A -> SHOT TYPE SELECT -> A -> STAGE.

TRAINING (hub row 2) — MAPPED BY EYE 2026-08-15 (computer-use, screenshot per press). The
log-only probe could not resolve this branch: **no `[mcur]` fires on its first screen**, so a
marker-driven driver sees "not a list screen" and learns nothing. The flow is:
  A on TRAINING ...... caption 「トレーニングをプレイします。」 -> **STAGE SELECT**
  STAGE SELECT ....... caption 「ステージを選択します。」, controls ⬅➡:選択 START:開始 B:戻る.
    ⚠ CORRECTED 09-20: RIGHT DOES move the Stage row (kind-3 choice list of 10: Stage 1, Stage 1 Boss, …,
      Stage 5 Boss; no save gate — decomp training_config.cpp/options_panel_base.cpp). The 08-15 "changes
      NOTHING" was a DROPPED PRESS (frame stall). RIGHT×1 + START reached the stage-1 boss in ~100 s
      (scripts/boss1/boss1_drive2.sh ROUTE=training NRIGHT=1). The rows are INVISIBLE in the port = FNF-15.
  START .............. -> MODE SELECT (Original/Maniac/Ultra, 48-count) -> A -> char -> shot -> STAGE
  ⚠ TRAINING GIVES NO INVINCIBILITY: an idle ship dies and the run ends in the ordinary NORMAL
    PLAY game-over flow (replay-save prompt 「リプレイを保存しますか?」, B declines). So training
    is NOT a route to a boss for an unattended drive.

GAME OVER — TWO FLOWS, do not conflate (the 08-11/08-12 confusion):

GAME OVER, NORMAL PLAY side (idle-die, NON-RANKING score) — MAPPED BY EYE 08-13, screenshot per
press, marker per transition (nav_gameover_np_to_topmenu implements it):
  replay-save prompt (リプレイを保存しますか A:はい B:いいえ; NO log marker of its own; the
  continue "PRESS START BUTTON" screen sits BENEATH the dialog)
    B (decline) .......... [gemsg] msg=10 (+ [modegate] +120 5->0) -> MODULE TITLE (attract)
    START at title ....... [gemsg] msg=11 + hub [p0build] 7 items, vt=0x820503B0, cursor->0
    B on hub ............. [decide] item=-1 (return-to-top confirm)
    A (はい) ............. [gemsg] msg=13 then msg=3 (quit/detach) -> SHELL TOP MENU vt=0x82050518
  NO score-register prompt, NO ranking-cancelled dialog on this path (small score). A RANKING
  score may add prompts — unobserved on NP; assert by marker, don't assume the count.
  Death timing varies 30-60s and the prompt is marker-less => the leg B-POLLS (in-stage stray
  B = bomb, harmless; at-title B = no-op) until msg=10 fires.

GAME OVER, SCORE ATTACK side — MAPPED BY EYE 08-12 (RenderDoc + direct screenshot):
  replay-save prompt (リプレイを保存しますか) ..... B declines
  score-register prompt (スコアを登録しますか) .... B declines
  ranking-cancelled OK dialog ..................... A
  -> the MODULE HUB (the 7-item menu, cursor on SCORE ATTACK) — NOT a title, NOT a dead state.
  ⚠ The 08-11 "engst parks at D70 / vt 0x8204FDB8" was a RED HERRING: [engst] D70-PARKED fires
    CONSTANTLY from a persistent background object (seen firing even at the shell TOP MENU),
    regardless of screen. It is NOT a screen state — never gate nav on it.
  ⚠ Why the old return leg desynced: NORMAL PLAY has ONE prompt, so the blind B,B,A pressed two
    extra buttons into the title/attract. The flows split at the SECOND prompt.

RETURN TO SHELL from the hub (VERIFIED, 3-press, shorter than the DOWNx6 item route):
  B (on the hub root) -> "トップメニューに戻ります。よろしいですか?" confirm ([decide] item=-1)
  A (はい) -> shell TOP MENU.  (No module swap; the swap is lazy on next card-decide.)
  ⚠⚠ MARKER AMBIGUITY: the module HUB and the shell TOP MENU BOTH fire [mstate] BA4D8(ACTIVE)
    state 0x82061D50. Disambiguate by the vt field: HUB vt=0x820503B0 (arcade) ; shell TOP MENU
    vt=0x82050518. This is why blind BA4D8-matching desynced prior sessions.

(Legacy note, superseded: the DOWN x6 -> RETURN TO TOP MENU item -> A -> confirm A route also
reaches the shell, but the hub-B route above is fewer presses and needs no cursor walk.)

IN-STAGE PAUSE (START, only when actually in a stage):
  RESUME / RESTART / OPTION / RETURN TO TITLE (DOWN x3 + A + confirm A).
  ⚠ START is join-wired (RT_STARTWIRE): pressing START anywhere that is not title/pause/hub
  intent risks a join. Never use START as a generic "advance" button.

## Instruments that carry drive verdicts (all shell-side = module-agnostic)
  [mstate]/[engst]  menu engine states     [mcur] cursor moves     [decide] item commits
  [p0build]         hub item list w/ names [modswap]/[swapinv]     module swaps
  [epochinval]/[idcol] texture identity    [quadcensus]            armed frame census
  ⚠ [intap]/[scenelog] read reco_NORMAL globals — FROZEN/GARBAGE under reco_abnormal.

## 2P (mapped 2026-08-14, the polish row)
  JOIN at char select: P2 START (pad FIFO 4th field, `echo "0 0 0 10"`; or physical XInput
  idx 1) -> '[joinp] *** 881366D0 ... WILL-JOIN ***' -> the 2P frame fills. nav_2p_join()
  implements it; nav_2p_press() sends any P2 word. Both players then drive their OWN selects
  (P1 word field 1, P2 word field 4).
  2P SIDE START (NORMAL PLAY submenu row 1, [decide] item=1): fires the SAME join handler
  (slot=1) -> Mode Select -> char select MIRRORED (1P seat "No Entry", 2P side active).
  Verified scripted co-op: both modules, join -> dual selects -> two-ship stage
  (_local/_tmpscripts/day8_2p_validate.sh: COOP_arcade_PASS + COOP_360_PASS).

## XBOX 360 MODE (futari_game_abn.dylib, modeIdx 1) — mapped 2026-10-11 (RC1 Q2, Mac, build/w152_q2)

WHY THE ARCADE DRIVES "LOST" 360: not the shell. Everything the shell draws (top menu, card panel, the module HUB,
NORMAL PLAY submenu, pause menu, return-to-top confirm) is the SAME shell code over the SAME shell .data, so
[mstate]/[mcur]/[decide]/[p0build]/[modswap]/[gemsg] fire identically in both modules (GameEntry's [gemsg] wrapper is
+8-renamed onto 0x8824E6A0 by abn_symbol_map.h). What breaks is every MODULE-side observer that reads game .data by
literal reco_normal address: in reco_abnormal every global >= 0x88351830 sits at +0x60 (host/futari_module_desc.h),
but only six addresses were descriptorised — the scene FSM 0x884D66A8, select FSM d76 0x884D678C, death flag
0x884D6878, slot0 0x884D6CE8/credit 0x884D6CEA cluster was not (static check: the generated `lwz ...,26280(r11)`
scene-FSM load in out_reco is `26376(r11)` = +0x60 in out_reco_abn). So under 360 [navreal] prints its first
"-1->0" pair and then nothing (it is watching unrelated bytes) — and with it every d76-based screen/death assert.
Also: [cue] lines print ONCE per cue per run, so SE-based markers (SE cue2, SYS_SE cue5) are unusable after the attract
has played them — never gate a press on a [cue] line except a cue that is new in the run (m01_slct, m02_stg1).
FIX (harness-only): **RT_NAV360=1** (merged_game.cpp, default OFF) = the [navreal] six-field observer re-based on the
live module's own futari_desc()->dshift (0 in ARCADE, 0x60 in 360), one `[nav360] D=0x.. st= d76= field= go= cred=
slot0=` line per change. Read-only, log-only.

[nav360] field legend (360, measured r2): st = scene FSM (1 boot, 3 module title/attract, 5 game/menus, 2 teardown);
d76 = select FSM; field = gameplay field active; go = demo/teardown flag; cred = slot0 credit countdown; slot0 = 1P seat.

Screen graph (marker = what the drive asserts; settle = sleep after the marker before the next press):

| # | screen | press to get here | marker | ceiling / settle |
|---|---|---|---|---|
| 0 | SHELL TITLE | (boot) | `name='motion/title.lzx'` | 60 s / 4 s |
| 0a | (fresh save dir only) "save data not found — create?" then "created" | — | SYS_SE cue6 (SE_OK02); A, A | AVOID: seed RT_SAVE from a copy (nav360_mac.sh SEED=) |
| 1 | SHELL TOP MENU | START | `SYS_BGM cue0 (mushifuta_Menu02)` (first in run) | 10 s / 3 s |
| 2 | CARD PANEL (resets to ARCADE) | A | `SYS_SE cue1 (SE_OK01)` | 10 s / 2 s |
| 3 | Xbox 360 card | LEFT | none (screen); 3.0 s dwell gate → 3.6 s | — |
| 4 | decide → swap | A | `[modeidx] ... XBOX-360` then `[modswap] #2 DONE` (same second) | 120 s |
| 5 | 360 MODULE TITLE / attract (Original Ranking, a 360 DEMO: `[nav360] st=3 d76 0->3->4 go=1 slot0=1` cycles) | — | `[nav360] D=0x60 st=3 ` (+ `GameEntry(msg=15,` call#1) | 120 s / 6 s (cold ~25-40 s) |
| 6 | HUB (7 items, same shell model as ARCADE, vt=0x820503B0) | START (works on title AND during the demo) | `GameEntry(msg=11,` + `[p0build] menu_game_title` + `[nav360] st=5 d76=1` | 15 s / 3 s |
| 7 | NORMAL PLAY submenu (vt=0x820503F8) | DOWN (`[mcur] 0->1`), A | `[decide] ... item=1 ` | 5 s / 3 s |
| 8 | MODE SELECT (Original/Maniac/Ultra, 48 count) | A (1P SIDE START, default row) | `[nav360] D=0x60 st=5 d76=2 field=1 cred=3 slot0=1` | 10 s / 3 s |
| 9 | CHARACTER SELECT | A | none — d76 does not move; screen only | 3 s |
| 10 | SHOT TYPE SELECT | A | none; screen only | 3 s |
| 11 | STAGE 1 | A | `[nav360] ... d76=4 ` then `BGM cue1 (m02_stg1)` | 60 s / 6 s |
| 12 | PAUSE (RESUME/RESTART/OPTION/RETURN TO TITLE; shell model vt=0x82050488) | START (in stage only) | `GameEntry(msg=10,` + `BA4D8(ACTIVE).*vt=0x82050488 .*cursor=0 state 0x82061D50->0x82061D50` | 10 s / 2 s |
| 13 | RESUME → stage | **A** on RESUME (cursor 0). START does NOT resume (the triage's mistake; caption: A=決定 B=戻る) | `BA4D8(ACTIVE).*vt=0x82050488 .*cursor=0 state 0x82061D50->0x82061D70` | 10 s / 4 s |
| 14 | RETURN TO TITLE → confirm → module title | START, DOWN×3 (`[mcur] 0->1,1->2,2->3`), A, A | `cursor=3 state 0x82061D50->0x82061D70`, then `GameEntry(msg=10,` + `[nav360] st=3` | 20 s / 6 s |
| 15 | back to SHELL TOP MENU | (title) START → hub; B → "トップメニューに戻ります" | `[decide] ... item=-1`; then A → `GameEntry(msg=13,` + `GameEntry(msg=3,` + `vt=0x82050518` | 20 s / 3 s |

⚠ THE 360 REPLAY-SAVE TRAP (r2, 2026-10-11): with ~13 s between the MODE/CHAR/SHOT presses (marker timeouts on SE cues),
the run did NOT reach stage 1: after the SHOT A, `[nav360]` shows d76 3→4, cred 3→2→1→0 (~1 s apart), slot0 1→0, d76
5→6→8, `GameEntry(msg=10,`, st 5→2 — then 「リプレイを保存しますか?」 and the REPLAY SAVE MENU (shots
`_local/rc1/q2/r2/shot_14..18`). The triage (rc1m_x360, ~4 s cadence) reached a live stage 1. nav360_mac.sh uses the
~4 s cadence and FAILS the leg if `GameEntry(msg=10,` precedes the pause press. Cause UNATTRIBUTED (cadence vs the
seat/credit path in the 360 module) — a 360 defect candidate for the Q4/Q9 seats; the ARCADE twin of this symptom was
the 07-14 "credited run dies → replay-save loop" class.

PROOF STATUS (2026-10-12 00:35, 3 h budget hit: the drive lock was held by other windows' sweeps for ~2 h 40 min of it;
only 2 legs ran, r1 = fresh-save desync, r2 = STRICT=0 exploration on build/w152_q2):
- PROVEN 1x (r2, `_local/rc1/q2/r2/` shots + guest.log; r2_events.txt): nodes 0-10 (shell title → top menu → card →
  360 card → decide/swap #2 → 360 title/attract incl. the [nav360] demo cycle → hub → NP submenu → MODE/CHAR/SHOT
  screens) and node 15 (hub B → item=-1 → A → msg=13/msg=3 → shell TOP MENU vt=0x82050518). Node 0a seen in r1.
- PROVEN on another binary only: node 11 + 12 in 360 (triage rc1m_x360, rc1_probe: m02_stg1, pause model
  vt=0x82050488 ACTIVE); node 13 resume-by-A in ARCADE on the Mac (`_local/boss1_mac/gamectl/guest.log`: A at cursor 0
  → `0x82061D50->0x82061D70`, play resumes, the next START builds a new pause model).
- **Q2b 2026-10-12 (Sonnet seat, lock free, 0 wait): the whole route PROVEN x2 (2 consecutive STRICT=1 VERDICT PASS,
  `_local/rc1/q2b/q2a4/`, `_local/rc1/q2b/q2b/`; shots + guest.log + steps.txt each).** Nodes 0-15 all PROVEN(2 runs),
  incl. 11 STAGE 1 (`[nav360] d76=4` + m02_stg1), 12 PAUSE, 13 RESUME (A on RESUME: model `0x82061D50->0x82061D70`; the
  shot ~5 s after shows the stage advanced, e.g. q2a4 shot_16 vs shot_17 differ and the stage scroll moved), 14 RETURN TO
  TITLE (DOWN x3, A, A), 15 hub B -> top menu. Three script fixes were needed first (runs q2a/q2a2/q2a3 stopped at them,
  not at the game): (1) the m02_stg1 cue prints at d76=3, BEFORE d76=4, so it is checked inside stage1_go's window;
  (2) the in-stage pause model (vt 0x82050488) emits no `[mcur]`, so pause DOWN x1-3 are screen-only (cursor=3 is asserted
  at rtt_confirm); (3) **RETURN TO TITLE lands directly on the rebuilt HUB** (`GameEntry(msg=11)`, st 5->2,
  `[p0build] menu_game_title#2`), not on the module title and not msg=10 — the old x360_title_again/hub_again nodes were
  dropped.
- **Replay-save trap: did NOT reproduce** (5 stage entries at the ~4 s cadence, all clean). Observed instead: an
  unattended credited stage 1 dies on its own (q2a, 60 s wait: cred 3->2->1->0 = no-dodge, slot0 1->0, d76 4->5->6->8,
  `GameEntry(msg=10,`, st 5->2, m05_govr) — the SAME signature as Q2 r2. Hypothesis (not investigated): r2 did reach
  stage 1 (its `stage1` marker had the d76=3-ordering bug above) and then game-overed in the idle wait, i.e. the "trap"
  is just the no-input death + replay-save prompt, not a stage-entry defect.
- RT_NAV360 inertness run (NOLEVER=1, `_local/rc1/q2b/q2n/`): lever unset -> 0 `[nav360]` lines in the log; the full
  route still VERDICT PASS on shell markers + screen-only waits (module-side nodes mode_select/stage1_go use the shell
  cue / dwell instead).

Route script: `scripts/nav360_mac.sh <tag> <bin>` (drive lock, save seed, RT_NAV360=1, own FIFO, `pkill -x` only,
verdict file; STRICT=1 stops at the first failed marker). Proof status per node: see PLAN_RC1 §4 "Q2 done".

### XBOX 360 TRAINING nodes -- measured 2026-10-12 (RC1 Q7-360, Mac, build/q7x_probe; `scripts/stages360_mac.sh`, evidence `_local/rc1/q7x/`)
| # | screen | press (from hub) | marker | settle |
|---|---|---|---|---|
| T0 | HUB, cursor TRAINING | DOWN x2 (`[mcur] 0->1`, `1->2`) | `[mcur] .*cursor 1->2` | 1.5 s each |
| T1 | TRAINING panel (identical to ARCADE: Stage / Mode / Character / Shot Power / Bomb Stock / Player Stock / Total Counter / Stage Counter / Survival Rank / Start Training 1P Side / EXIT) | A | `[tstate] 96660(load)` | 3 s |
| T2 | options | DOWN x3, RIGHT x8 (Shot Power Max); DOWN, RIGHT x8 (Bomb Infinity); DOWN, RIGHT x7 (Player Infinity); UP x5 (cursor to Stage); RIGHT x 2(k-1) = Stage k | shots; `[trainprobe] msg=18` word1 0x0007FFFF after start | 0.8 s spacing |
| T3 | start | A (dialog; `dclose ... vt=0x82050F00`), A | `[nav360] D=0x60 st=5 d76=4 ` (stage BGM cue prints at d76=3 before it: cue1/6/7/8/9) | 90 s ceiling |
| T4 | stage play | autofire: A 0.2 s on / 0.2 s off, A+B every 10th | boss = `[cuetally]` `BGM cue2=` (m03_boss, stages 1-4) / `BGM cue10=` (m11_lbs1, stage 5) -- the `[cue]` detail cap (48 lines) hides the boss cue; NO boss-defeat `[fade]` in 360 | st1..5 ends 134/209/287/307/450 s |
| T5 | results tally (gold frame, count rows) then stage end | (stop autofire AT ONCE) | `[nav360] D=0x60 st=5 d76=8 ` then `st=2`, d76 8->0 | shots every 5 s after the boss |
| T6 | panel re-opens by itself, cursor Start Training (hub rebuilt first: `[p0build] menu_game_title#2` then `[tstate] 96660(load)#2`) | -- | `96660(load)#2` | 3 s |
| T7 | back to HUB | B | screen only (hub already built under the panel; no new `[p0build]`) | -- |
Traps: a stray A after d76=8 hits T6 and restarts training (Start Training is under the cursor); never leave a background autofire subshell alive (an orphan keeps pressing A into the shared FIFO of later legs); the title ignores START until it has finished loading (the `title.lzx` marker is the load request, 3-13 s early): press START every 4 s until the top-menu BGM. Stage 5 in 360 TRAINING ends at the boss (m11_lbs1 only), as in ARCADE.

## OPTION / REPLAY / GAME-OVER-SAVE / CO-OP nodes — measured 2026-10-12 (RC1 Q3/Q4, Mac, build/w152_q2 as futari_q3)

Driver: `scripts/persist_mac.sh <tag> <arcade|x360> -- <steps>` (marker-asserted legs; save dir shared between legs of a test; `boot_hub`,
`hub_to_top`, `sd:<name>` = save-dir md5/size snapshot, `p2:<word>` = P2 pad). Byte diff: `scripts/bindiff.py`. Present-frame markers: `scripts/markframes.py`.
All shell-owned screens below are identical in ARCADE and XBOX 360 (same shell models, same save bytes).
- HUB row OPTION (4) (`2`x4 from cursor 0, `[mcur] n->n+1` each, A): panel list = Controller / Screen / Sound / Storage / Staff / Exit.
  DOWN, A on Screen Setting -> "Screen Setting (Maniac)" (the seed's menu mode): Layout Setting [Preset #1], Picture Setting [Preset #A],
  Extra Setting, "Simple" Menu Mode, Default Setting, EXIT. RIGHT on the Picture row = Preset #B. **Persisted bytes: savegame.bin +0x16F7 00->01.**
  The panel needs no log marker; the proof is the on-disk byte and the panel on relaunch. B, B = back to hub (cursor stays on OPTION).
- NORMAL PLAY submenu -> CONFIG (row 2): Player Stock / Bomb Stock / Extend Original, Maniac, Ultra (1st, 2nd) / Default Setting / Initialize Ranking / EXIT.
  Any change shows the red 「設定が変更されているため、実績が解除されません。」 note (achievements off). DOWN, RIGHT on Bomb Stock = 3->4.
  **Persisted bytes: savegame.bin +0x0D..+0x0E 0303->0404** (bomb stock + the post-miss copy). Saved at change time (file already differs before any quit).
- QUIT path: hub B -> confirm (`[decide] item=-1`) -> A -> shell TOP MENU (`vt=0x82050518`); top menu DOWN x4 = EXIT (「タイトル画面に戻ります」),
  A -> the shell TITLE ("PRESS START BUTTON"). The process does NOT exit (the app is closed with the window); a SIGTERM after the title loses nothing.
- REPLAY DATA (hub row 3: `2`x3, A): REPLAY LOAD MENU (6 slots, rows show score / name / mode / stage / continues / date; footer A:ロード B:戻る).
  A on a slot starts the PLAYBACK at once (no confirm): `GameEntry(msg=17,` + `d76 1->2->3->4` (ARCADE `[navreal]`; 360 `[nav360]`) and the stage plays the stored inputs;
  the end is the recorded death (d76 4->5 cred=0, 5->8, `st 5->2`, `LOOP/DEATH`) then `GameEntry(msg=11,` = the rebuilt HUB (cursor 0), not the list.
- GAME OVER after an idle stage 1 (NORMAL PLAY, Original): ~32 s (ARCADE; 360 ~33 s after the stage start) -> `d76 4->5 cred=0` -> `GameEntry(msg=10,` (360: `[nav360] D=0x60 st=2 `)
  -> 「リプレイを保存しますか?」 A:はい B:いいえ. **A -> REPLAY SAVE MENU (6 slots; slot 01 is the seed's replay)**, DOWN = slot 02, A -> "保存しています" (Accessing, ~3 s)
  -> 「リプレイデータの保存が完了しました」 A:OK -> the module TITLE attract (Original Ranking). Disk: replaydata.bin 2444 -> 4062 bytes (second entry; savegame.bin untouched).
  B at the prompt -> the module title directly. NO score-register prompt on this path (score 0-300 never reaches the table).
- "Today's Original Ranking" attract (title, cycles): 1st 6,880,571 KDK / 2nd 4,000,000 NMR / 3rd 3,000,000 TNK ...; these values are NOT in savegame.bin or
  replaydata.bin (searched BE/LE 4/8-byte and ASCII/UTF-16 names) -- the table is not persisted in the seed's two files. SCORE ATTACK row = a dialog 「ランキングにアクセスするには、Xbox LIVE にサインインする…」 (A:OK; out of scope).
- CO-OP: **the host FIFO (`RT_PAD_HOST_FIFO`) OR-merges EVERY whitespace token into P1** -- `echo "0 0 0 10"` there is P1 START (opens the pause menu at character select;
  Q3 first attempt). P2 is the **RT_PAD_FIFO channel's 4th field**: `RT_PAD_FIFO=1 RT_PAD_FIFO_PATH=<file>`, write `0 0 0 <word>` (persist_mac.sh `p2:<word>`, own file /tmp/futari_pad_q3p2).
  At CHARACTER SELECT: P2 START -> `[xinput] P2 buttons=0x0010 (user=1)` + `[joinp] *** 881366D0 ENTER slot=1 ... WILL-JOIN ***` (RT_JOINP=1) -> the 2P panel fills (Palm & Hirou).
  Then each seat drives its own selects: P1 A (char), P2 A (char), P1 A (shot), P2 A (shot) -> stage 1 with PLAYER-1 + PLAYER-2 HUD and two ships. Pause (START), RESUME (A), RETURN TO TITLE (DOWN x3, A, A) -> hub, as solo.
- CO-OP XBOX 360 (Q4b 10-12, G-START-fixed engine): same nodes/markers as ARCADE (`[joinp] ENTER slot=1 WILL-JOIN`, `[xinput] P2 buttons=0x0010`; module data D=0x60). TIMING: idle ships die ~20-28 s after stage start (CONTINUE? screen: START = continue, not pause) -> pause by ~11 s; after RESUME re-pause within ~2 s or the ships die again. persist_coop_mac.sh x360 does this.
- DIFFICULTY SELECT in TRAINING (Q3-sweep 10-12, both modules, no unlock gate): the panel row 1 `Mode` = Original / Maniac / Ultra. From row 0 (Stage): DOWN, RIGHT x1 = Maniac / RIGHT x2 = Ultra, UP (Maniac adds a `Multiply Counter` row; rows 0-5 unchanged), then the usual option recipe + A, A. Marker: `[trainprobe] msg=18` word0 = stage<<24 | mode<<8 (0x100 Maniac / 0x200 Ultra) and the in-stage `Ultra Mode` banner. Normal Play picks it at MODE SELECT (A, 48-count) instead. Ultra stage 5: boss ~325 s after entry but ~1,630 s to the stage end with infinite-stock autofire (stages 1-4 within 350 s) -- STAGECAP 1800 (`scripts/stages_mac.sh`, `scripts/stages360_mac.sh` DIFF=1|2).
