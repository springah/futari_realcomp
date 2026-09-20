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
