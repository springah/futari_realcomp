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

GAME OVER (idle ship dies in ~30-60s of stage 1):
  replay-save prompt (リプレイを保存しますか) ..... B declines
  score-register prompt (スコアを登録しますか) .... B declines
  ranking-cancelled OK dialog ..................... A
  -> module TITLE (NOT the shell top menu).

RETURN TO SHELL: title START -> HUB -> DOWN x6 (assert [mcur] 5->6) -> A -> confirm A
  -> shell TOP MENU. (No module swap occurs here.)

IN-STAGE PAUSE (START, only when actually in a stage):
  RESUME / RESTART / OPTION / RETURN TO TITLE (DOWN x3 + A + confirm A).
  ⚠ START is join-wired (RT_STARTWIRE): pressing START anywhere that is not title/pause/hub
  intent risks a join. Never use START as a generic "advance" button.

## Instruments that carry drive verdicts (all shell-side = module-agnostic)
  [mstate]/[engst]  menu engine states     [mcur] cursor moves     [decide] item commits
  [p0build]         hub item list w/ names [modswap]/[swapinv]     module swaps
  [epochinval]/[idcol] texture identity    [quadcensus]            armed frame census
  ⚠ [intap]/[scenelog] read reco_NORMAL globals — FROZEN/GARBAGE under reco_abnormal.
