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
  [ "$1" = "360" ] && { nav_press 4 0.25 0.3; nav_say "LEFT -> Xbox 360 card"; }
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
  nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]' 10 "hub reachable" || return 1
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
    if nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]' 10 "arcade hub open (try $_r)"; then
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
nav_module_title_to_topmenu(){
  # The game-over prompt timing is unmapped (no log marker yet), so the title may not be up
  # on the first try — PROBE-VERIFY with retries: START, check for hub markers; if absent,
  # re-run the prompt-dismissal tail (harmless if prompts are gone: B=bomb only in-stage,
  # A on hub = SCORE ATTACK decide which the RETURN flow below never reaches... so use B,B
  # then A ONLY when a prompt could still be pending) and try again.
  local _r _pref=$NAV_FAILS
  for _r in 1 2 3 4; do
    nav_base; nav_press 10 0.3 2.5                            # START -> hub (or nothing)
    if nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]' 10 "hub open (try $_r)"; then
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
nav_verdict(){ nav_say "assertions: $NAV_PASSES passed, $NAV_FAILS failed"; [ "$NAV_FAILS" -eq 0 ]; }

# ⚠ KNOWN GAP (08-11 validation): the game-over return flow after a NORMAL-PLAY-entered stage
# does NOT reach the hub via the mapped title flow (engst parks at D70/vt 0x8204FDB8; 4 probe
# rounds found no hub markers). The SCORE-ATTACK-side flow mapped in NAV_MAP.md differs.
# nav_module_title_to_topmenu is UNRELIABLE post-game-over until that branch is screenshot-
# mapped. The ENTRY path (boot -> card -> land -> selects -> stage) is validated 8/8 green.
