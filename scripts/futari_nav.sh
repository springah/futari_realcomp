#!/bin/bash
# futari_nav.sh — assertion-based menu-driver library implementing docs/NAV_MAP.md (2026-08-11).
# Source this from a drive script after exporting:
#   LOG  = path to the exe's stderr log      FIFO = RT_PAD_FIFO path (e.g. /c/tmp/futari_pad)
# Every helper asserts its outcome from log markers on NEW LINES ONLY (baseline-tracked), per
# the 08-11 ruling: never press without knowing where you are. A failed assertion prints the
# recent log tail and returns nonzero — callers should `|| exit`.
# Words: A=1000 B=2000 START=10 DPAD U/D/L/R=1/2/4/8.

NAV_FAILS=0; NAV_PASSES=0
nav_say(){ echo "[nav t$SECONDS] $*"; }
nav_press(){ echo "$1" > "$FIFO"; sleep "${2:-0.2}"; echo 0 > "$FIFO"; sleep "${3:-0.9}"; }
nav_base(){ NAV_BASE=$(wc -l < "$LOG"); }
nav_new(){ tail -n +"$((NAV_BASE + 1))" "$LOG"; }
nav_wait_new(){ # pattern timeout label -> waits for pattern in NEW lines
  for _i in $(seq 1 "$2"); do
    nav_new | grep -aq "$1" && { nav_say "PASS: $3 (${_i}s)"; NAV_PASSES=$((NAV_PASSES+1)); return 0; }
    sleep 1
  done
  nav_say "FAIL: $3 (timeout ${2}s waiting '$1')"; NAV_FAILS=$((NAV_FAILS+1))
  tail -5 "$LOG" | sed 's/^/  [log] /'; return 1
}
nav_mcur(){ nav_new | grep -a '\[mcur\]' | tail -1 | sed 's/.*->//'; }

# ---- shell ----
nav_boot_to_topmenu(){ # from a freshly-launched exe
  sleep 12; nav_base
  for _t in 1 2 3 4 5 6; do
    nav_press 10 0.2 1.5
    nav_new | grep -aq 'BA4D8(ACTIVE)' && break
  done
  nav_wait_new 'BA4D8(ACTIVE)' 20 "top menu (BA4D8/1D50)"
}
nav_card_decide(){ # $1 = arcade|360 ; $2 = 1 if a module swap is expected
  nav_base; nav_press 1000 0.2 0.5
  nav_wait_new '92E8 bind' 10 "card panel open" || return 1
  # ⚠ the panel ALWAYS resets to the ARCADE card (NAV_MAP) — LEFT only for 360.
  # ⚠ DECK TRAP (08-12 agent, screenshot-verified): a LEFT inside the panel-open ANIMATION
  # (~0.7s) is SWALLOWED → the decide silently takes ARCADE. The XexLoadImage retry below
  # catches it, but the positional assert is: 360-card art load = '[res] id=140' from
  # lr=0x821B9D24 (id=140 from lr=0x8207BF20 is unrelated). Panel WRAPS: never re-LEFT after
  # that marker fired. NAV_PANEL_SETTLE pre-LEFT settle; Deck drives needed 4 (wall-clock slow).
  [ "$1" = "360" ] && { sleep "${NAV_PANEL_SETTLE:-0}"; nav_press 4 0.25 0.3; nav_say "LEFT -> Xbox 360 card"; }
  sleep "${NAV_CARD_DWELL:-3.6}"   # card-panel dwell gate: 0xB4=180 FRAMES (3.0s at 60fps) — a
  # welded-slow present OR an unfocused/compositor-throttled window stretches it in wall time
  # (08-12: a 3.6s dwell that passed 5x was refused on run 6 — frame-rate variance, not timing
  # luck). So the decide is RETRIED: a refused A is harmless (the panel just stays up).
  nav_base; nav_press 1000 0.35 2.0
  if [ "${2:-0}" = "1" ]; then
    # ⚠ VERIFY THE RIGHT MODULE (08-12): a LEFT press dropped under throttle picks the ARCADE
    # card, and matching a bare 'modswap DONE' let the drive silently run reco_normal while
    # believing it was on 360 (poisoned a whole frameclock measurement). The 360 case MUST see
    # reco_abnormal; the arcade case reco_normal. XexLoadImage carries the module name.
    local _want='reco_normal'; [ "$1" = "360" ] && _want='reco_abnormal'
    local _try _pref=$NAV_FAILS
    for _try in 1 2 3; do
      if nav_wait_new "$_want" "${NAV_SWAP_WAIT:-40}" "$1 card -> $_want (try $_try)"; then
        NAV_FAILS=$_pref; break
      fi
      [ "$_try" = "3" ] && { nav_say "FAIL: $1 card never loaded $_want (wrong card picked?)"; return 1; }
      nav_say "decide likely dwell-refused or wrong card — re-LEFT + extra dwell + re-decide"
      [ "$1" = "360" ] && nav_press 4 0.25 0.3   # re-assert the 360 card
      sleep 5; nav_base; nav_press 1000 0.35 2.0
    done
  fi
  nav_say "card '$1' decided"
}
# ---- 360 module: landing is AMBIGUOUS (cold boot -> Mode Select; re-entry -> title).
# Active probe per NAV_MAP: DOWN moves a cursor only at Mode Select ([mcur] fires); a title
# ignores it. Blind START here is the 2P trap — never.
nav_360_land_to_modeselect(){
  sleep "${NAV_LAND_SETTLE:-40}"   # module/ROM settle (stretches if logic is welded-slow)
  nav_base; nav_press 2 0.15 1.2
  if nav_new | grep -aq '\[mcur\]'; then
    nav_say "landing probe: MODE SELECT (cursor moved) — restoring"
    nav_press 1 0.15 1.0   # UP restores Original
    NAV_PASSES=$((NAV_PASSES+1)); return 0
  fi
  nav_say "landing probe: TITLE (no cursor) — entering hub"
  nav_base; nav_press 10 0.3 2.5                              # START -> hub
  nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]\|\[mstate\].*vt=0x820503B0' 10 "hub reachable" || return 1
  nav_base; nav_press 2 0.15 1.0                              # DOWN -> NORMAL PLAY
  nav_wait_new 'mcur\].*0->1' 5 "hub cursor at NORMAL PLAY" || return 1
  nav_press 1000 0.2 2.0                                      # A
  nav_press 1000 0.2 3.0                                      # A on 1P SIDE START (default row)
  nav_say "via hub: NORMAL PLAY -> 1P SIDE START"
}
# ---- arcade module: lands in DEMONSTRATION attract (HUD gameplay demo; NAV_MAP). START exits
# attract -> HUB directly. ⚠ the attract is a FIELD scene, so under a field-gated present
# throttle (RT_PRESENT_THROTTLE_MS) it runs welded-slow and a START can drop — PROBE-VERIFY
# with retries like the title flow (a dropped/early press is harmless; the attract stays up).
nav_arcade_land_to_hub(){
  sleep "${NAV_LAND_SETTLE:-40}"   # module/ROM settle (attract slower still under throttle)
  local _r _pref=$NAV_FAILS
  for _r in 1 2 3 4; do
    nav_base; nav_press 10 0.3 2.5                            # START -> hub (or dropped)
    if nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]\|\[mstate\].*vt=0x820503B0' 10 "arcade hub open (try $_r)"; then
      NAV_FAILS=$_pref; break                                 # retried probes are not failures
    fi
    [ "$_r" = "4" ] && return 1
    nav_say "arcade hub not up — attract still running (throttled?); retrying START"
  done
  nav_base; nav_press 2 0.15 1.0                              # DOWN -> NORMAL PLAY
  nav_wait_new 'mcur\].*0->1' 5 "arcade hub cursor at NORMAL PLAY" || return 1
  nav_press 1000 0.2 2.0                                      # A
  nav_press 1000 0.2 3.0                                      # A on 1P SIDE START (default row)
  nav_say "arcade via hub: NORMAL PLAY -> 1P SIDE START"
}
nav_selects_to_stage(){ # from Mode Select: Original -> char -> shot -> stage
  nav_press 1000 0.2 3.0   # A Original
  nav_press 1000 0.2 3.0   # A character
  nav_base; nav_press 1000 0.2 4.0   # A shot -> stage streams assets
  nav_wait_new 'epochinval\|nvk\] f\|\[emit\]' 15 "stage activity"
}
nav_idle_die_to_module_title(){ # Original stage 1 kills an idle ship; death timing VARIES
  nav_say "idling in stage until game over"
  sleep 50
  nav_press 2000 0.25 3.0   # B decline replay save (a stray B in-stage is just a bomb)
  nav_press 2000 0.25 3.0   # B decline score register
  nav_press 1000 0.25 8.0   # A OK ranking-cancelled -> module title
}
# ---- game-over -> shell TOP MENU (MAPPED BY EYE 08-12; see NAV_MAP GAME OVER). From in-stage:
# idle-die, decline both save prompts (B,B), OK the ranking-cancelled dialog (A) -> module HUB,
# then B -> return-to-top confirm -> A (はい) -> shell TOP MENU. Asserts the shell landing by the
# vt discriminator (BA4D8 alone is ambiguous: hub AND shell both fire it — hub vt=0x820503B0,
# shell TOP MENU vt=0x82050518). NEVER gate on [engst] D70 — it is a background object, not a
# screen (the 08-11 dead-end). Probe-verified with retries (game-over prompt timing varies).
nav_gameover_to_topmenu(){
  nav_say "game-over: declining save prompts to reach the hub"
  nav_press 2000 0.25 3.0   # B decline replay-save (stray in-stage B = bomb, harmless)
  nav_press 2000 0.25 3.0   # B decline score-register
  nav_press 1000 0.25 8.0   # A OK ranking-cancelled -> HUB
  local _r _pref=$NAV_FAILS
  for _r in 1 2 3 4; do
    nav_base; nav_press 2000 0.25 2.0                          # B on hub -> return-to-top confirm
    if nav_wait_new '\[decide\].*item=-1\|トップメニュー\|BB298' 8 "return-to-top confirm (try $_r)"; then
      NAV_FAILS=$_pref; break; fi
    [ "$_r" = "4" ] && { nav_say "FAIL: return-to-top confirm never came up"; return 1; }
    nav_say "confirm not up (prompts still clearing?) — re-dismiss + retry"
    nav_press 1000 0.25 4.0
  done
  nav_base; nav_press 1000 0.25 3.0                            # A (はい) -> shell TOP MENU
  # assert the SHELL top menu by vt (not bare BA4D8 — the hub shares it)
  nav_wait_new 'vt=0x82050518\|BB298(load-wait)' 10 "shell TOP MENU (vt=0x82050518)"
}
nav_module_title_to_topmenu(){
  # The game-over prompt timing is unmapped (no log marker yet), so the title may not be up
  # on the first try — PROBE-VERIFY with retries: START, check for hub markers; if absent,
  # re-run the prompt-dismissal tail (harmless if prompts are gone: B=bomb only in-stage,
  # A on hub = SCORE ATTACK decide which the RETURN flow below never reaches... so use B,B
  # then A ONLY when a prompt could still be pending) and try again.
  local _r _pref=$NAV_FAILS
  for _r in 1 2 3 4; do
    nav_base; nav_press 10 0.3 2.5                            # START -> hub (or nothing)
    if nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]\|\[mstate\].*vt=0x820503B0' 10 "hub open (try $_r)"; then
      NAV_FAILS=$_pref; break                                 # retried probes are not failures
    fi
    [ "$_r" = "4" ] && return 1
    nav_say "hub not up — re-dismissing game-over prompts (round $_r)"
    nav_press 2000 0.25 3.0; nav_press 2000 0.25 3.0; nav_press 1000 0.25 8.0
  done
  for _d in 1 2 3 4 5 6; do nav_press 2 0.15 0.5; done        # DOWN x6
  c=$(nav_mcur)
  if [ "$c" != "6" ]; then
    nav_say "FAIL: hub cursor at '$c', want 6 (RETURN TO TOP MENU)"; NAV_FAILS=$((NAV_FAILS+1)); return 1
  fi
  nav_say "PASS: hub cursor 6 (RETURN TO TOP MENU)"; NAV_PASSES=$((NAV_PASSES+1))
  nav_base; nav_press 1000 0.2 1.5; nav_press 1000 0.2 2.0    # A + confirm A
  nav_wait_new 'BA4D8(ACTIVE)' 20 "shell TOP MENU"
}
# ---- NORMAL PLAY game-over -> shell TOP MENU (MAPPED BY EYE 2026-08-13, screenshot per press;
# validated by this leg's own assertions on the scripted re-runs). The NORMAL PLAY death flow is
# NOT the Score-Attack flow NAV_MAP mapped 08-12: with a non-ranking score there is exactly ONE
# prompt (replay-save リプレイを保存しますか, A:はい B:いいえ — NO log marker of its own; the
# continue "PRESS START BUTTON" screen sits beneath it) and NO score-register / ranking dialogs.
#   B (decline)  -> [gemsg] msg=10 (+ modegate +120 5->0)  -> MODULE TITLE (attract entry)
#   START        -> [gemsg] msg=11 + hub [p0build] items / vt=0x820503B0
#   B            -> [decide] item=-1 (return-to-top confirm)
#   A            -> [gemsg] msg=13 then msg=3 (quit/detach) -> SHELL TOP MENU vt=0x82050518
# Death timing varies 30-60s and the prompt is marker-less => B-POLL: press B every ~5s until
# msg=10 appears in NEW lines (stray in-stage B = bomb, harmless; at-title B = no-op).
# ⚠ A RANKING score may add the score-register prompt (unobserved on NP; the Score-Attack flow
# has it) — the B-poll would decline it and the msg id would differ; assert, don't assume.
# ⚠ [gemsg] per-msg detail prints only each msg's first 3 calls per session — this leg is
# single-shot per boot; a multi-gameover soak must not key on msg=10 reappearing.
nav_gameover_np_to_topmenu(){
  nav_say "NP game-over: B-polling for the replay-save prompt (msg=10)"
  local _r _ok=0 _pref=$NAV_FAILS
  for _r in 1 2 3 4 5 6 7 8; do
    nav_base; nav_press 2000 0.25 2.5
    if nav_new | grep -aq 'msg=10'; then
      _ok=1; nav_say "PASS: replay prompt declined (msg=10, poll $_r)"; NAV_PASSES=$((NAV_PASSES+1)); break
    fi
    sleep 3
  done
  [ $_ok = 1 ] || { nav_say "FAIL: msg=10 never fired (death not reached?)"; NAV_FAILS=$((NAV_FAILS+1)); return 1; }
  sleep 4                                                     # title fade-in
  for _r in 1 2 3 4; do
    nav_base; nav_press 10 0.3 2.5                            # START -> hub (probe-verified)
    if nav_wait_new 'msg=11\|\[p0build\]\|\[mstate\].*vt=0x820503B0' 8 "title -> hub (try $_r)"; then NAV_FAILS=$_pref; break; fi
    [ "$_r" = "4" ] && return 1
  done
  nav_base; nav_press 2000 0.25 2.0                           # B on hub -> confirm
  nav_wait_new '\[decide\].*item=-1' 8 "return-to-top confirm" || return 1
  nav_base; nav_press 1000 0.25 3.0                           # A (はい)
  nav_wait_new 'vt=0x82050518' 12 "shell TOP MENU (vt=0x82050518)"
}
# ---- 2P join at character select (Day-6/8 2P row). P2 input = the pad FIFO's 4th hex field
# ("<p1> <lt> <rt> <p2>"), served on the user==1 XamInputGetState LEVEL channel. Marker = the
# game-side join handler: '[joinp] *** 881366D0 ... WILL-JOIN ***' (RT_JOINP arms it; the
# [xinput] P2 line proves delivery even without RT_JOINP). Retry-safe: a P2 START when already
# joined is a no-op.
nav_2p_press(){ echo "0 0 0 $1" > "$FIFO"; sleep "${2:-0.3}"; echo 0 > "$FIFO"; sleep "${3:-1.5}"; }
nav_2p_join(){
  local _r _pref=$NAV_FAILS
  for _r in 1 2 3; do
    nav_base; nav_2p_press 10 0.3 2.0
    if nav_wait_new 'WILL-JOIN\|P2 buttons' 6 "2P join (try $_r)"; then NAV_FAILS=$_pref; return 0; fi
    [ "$_r" = "3" ] && { nav_say "FAIL: 2P join never registered"; return 1; }
  done
}
nav_verdict(){ nav_say "assertions: $NAV_PASSES passed, $NAV_FAILS failed"; [ "$NAV_FAILS" -eq 0 ]; }

# ⚠ KNOWN GAP (08-11 validation): the game-over return flow after a NORMAL-PLAY-entered stage
# does NOT reach the hub via the mapped title flow (engst parks at D70/vt 0x8204FDB8; 4 probe
# rounds found no hub markers). The SCORE-ATTACK-side flow mapped in NAV_MAP.md differs.
# nav_module_title_to_topmenu is UNRELIABLE post-game-over until that branch is screenshot-
# mapped. The ENTRY path (boot -> card -> land -> selects -> stage) is validated 8/8 green.
