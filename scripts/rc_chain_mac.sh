#!/bin/bash
# rc_chain_mac.sh <tag> <bin> A|B|C|D|E|all [arcade|x360]   -- RC1 Q5 "rc_chain": the chained-flow smoke for BOTH hosted modes (Mac).
#   A  MODE SWAP x5     one process: 5x (card ARCADE -> hub -> return to top -> card LEFT XBOX 360 -> hub -> return to top); [modswap] #2..#10
#   B  RESTART          TRAINING stage 1 -> pause -> RESTART -> stage re-entry -> pause -> RETURN TO TITLE -> hub          (per mode)
#   C  CONTINUE         Normal Play Original idle death -> CONTINUE countdown -> START -> play resumes -> idle death -> expiry
#                       -> game over -> replay-save prompt (decline) -> title/ranking                                      (per mode)
#   D  SCORE ATTACK     hub -> SCORE ATTACK -> Xbox LIVE sign-in dialog -> decline (A:OK) -> what follows                 (per mode)
#   E  REMAP            OPTION -> Controller -> change one binding -> quit -> relaunch same save -> read back -> play proof -> restore
#   T2                  (DC-1) training start from the panel that re-opens after PREVIOUS MENU, then a THIRD start via the hub (T3)
#   CX                  (DC-2) START once at each CONTINUE? countdown, CX_N tries (default 3), CX_DELAY s in (default 3); needs RT_PAUSEPROBE=1
#   SM / SM2            shell smoke steps of app_smoke_mac.sh against a probe binary (title -> card -> hub -> top), then relaunch: save read back
#   RCC_ROOT / SAVEPFX  bank root (default _local/rc1/q5c) / save-dir prefix (default q5c)
#   all                 A, then B C D E for arcade and x360.     Mode arg (or MODE=) limits B-E to one mode; A always runs both.
# The binary must be a uniquely-named copy of the host (cp build/<x>/futari_combined build/<x>/<name>): the leg is killed with `pkill -x <name>` ONLY.
#   bash scripts/rc_chain_mac.sh r1 build/q5c_probe/q5c_probe all
# Bank: _local/rc1/q5c/<tag>_<item>[_<mode>]/{shot_NN_*.png, guest.log, steps.txt, VERDICT.txt, facts.txt}. Saves: _local/saves/q5c_* (seeded from
# _local/saves/save_rc1_rc1m_<mode>); never the .app's. DRIVE LOCK: mkdir /tmp/futari_drive.lock per leg (sleep-60 loop up to LOCKWAIT s), rmdir on exit,
# never removed if not ours; waits while `pgrep -x futari_merged` (the user is playing).
# ---- ITEM F, the gates on the bundle engine (separate scripts; invocations used for RC1 Q5, evidence _local/rc1/q5c/):
#   (control = identical copy: mkdir build/q5c_control; cp build/q5c_probe/futari_game_*.dylib build/q5c_probe/futari_combined build/q5c_control/; cp .../futari_combined .../q5c_control)
#   bash scripts/rc_stagepix_lock_mac.sh q5c build/q5c_probe/q5c_probe build/q5c_control/q5c_control     # stagepix_mac.sh under the drive lock + own save; expect PASS (identical arms)
#   RETRIES=2 bash scripts/rc_plate_dll_mac.sh q5c famk1       # boss plate gate on the dylib engine (boss_plate_gate.sh itself needs build_mac.sh object dirs); NO-VERDICT = lockstep coin flip, rerun
#   (cd ../futari_decomp/tools/instruments && PYTHONDONTWRITEBYTECODE=1 python3 -B constpool_audit.py --selftest; python3 -B constpool_audit.py --out <tsv>;
#    same for regcontract_audit.py)   -- sweeps read the CURRENT decomp tree + this repo's out_reco*/shell/gen; findings are banked, never fixed.
# Markers: shell-side [mstate]/[decide]/[modeidx]/[modswap]/[gemsg]/[p0build]/[mcur] hold in both modules; module-side d76 etc come from [navreal] (ARCADE)
# and RT_NAV360=1 [nav360] (XBOX 360, dshift 0x60). [cue] lines print ONCE per cue per run: never gate a repeated press on one.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?bin}"; ITEM="${3:-all}"; ONLYMODE="${4:-${MODE:-}}"; PN="$(basename "$BIN")"
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
ROOT="${RCC_ROOT:-_local/rc1/q5c}"; LOCK=/tmp/futari_drive.lock; FIFO="${FIFO:-/tmp/futari_pad_q5c}"; GOT=0; SAVEPFX="${SAVEPFX:-q5c}"
mkdir -p "$ROOT" _local/saves
OVERALL=0

# ---------------------------------------------------------------------------------------------------- leg machinery
leg_begin(){ # name mode [seed-dir]  -- take the lock, set env, launch, find the log
  LEG="$1"; LMODE="$2"; B="$ROOT/${TAG}_$LEG"; rm -rf "$B"; mkdir -p "$B/png"; echo 0 > "$FIFO"
  local w=0
  while :; do
    if mkdir "$LOCK" 2>/dev/null; then GOT=1
      if pgrep -x futari_merged >/dev/null; then rmdir "$LOCK" 2>/dev/null; GOT=0; echo "user is playing (futari_merged) -- waiting"; else break; fi
    fi
    [ $w -ge "${LOCKWAIT:-10800}" ] && { echo "lock busy ${w}s -- giving up"; exit 3; }; sleep 60; w=$((w+60)); done
  echo "lockwait=${w}s" > "$B/lockwait.txt"
  trap 'pkill -x "$PN" 2>/dev/null; sleep 1; [ "$GOT" = 1 ] && rmdir "$LOCK" 2>/dev/null' EXIT
  export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG="${NVKPNG:-30}" RVK_DUMPDIR="$PWD/$B/png" RT_NAVREAL=1 RT_MENULOG=1 RT_TRAINPROBE=1 RVK_DRAWCENSUS=2
  export RT_INDCENSUS=1 RT_INDCENSUS_OUT="$PWD/$ROOT/${LEG}_${TAG}_indcensus.txt" RT_INDCENSUS_EVERY=20000   # coordinator: decomp UNREACHED-row census
  [ "$LMODE" = x360 ] && export RT_NAV360=1 || unset RT_NAV360
  [ -n "${3:-}" ] && { rm -rf "$RT_SAVE_DIR"; cp -R "$3" "$RT_SAVE_DIR"; }
  export RT_SAVE="$RT_SAVE_DIR"
  BIN="$BIN" RUN_SECS="${RUN_SECS:-1500}" bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
  T0=$(date +%s); LOGF=""
  for ((i=0;i<40;i++)); do LOGF=$(sed -n 's/^log: //p' "$B/run_out.txt" 2>/dev/null | head -1); [ -n "$LOGF" ] && break; sleep 0.25; done
  [ -n "$LOGF" ] || { echo "no log path"; exit 1; }
  V="$B/VERDICT.txt"; : > "$V"; FAIL=0; N=0; MARK=0
  say "leg $LEG mode=$LMODE bin=$PN save=$RT_SAVE_DIR lock=$(cat "$B/lockwait.txt")"
}
say(){ echo "[rcc] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; say "pad $1"; sleep "${2:-0.6}"; }
newlog(){ tail -n +"$((MARK+1))" "$LOGF"; }
waitnew(){ local pat="$1" n=$(( ${2:-10}*2 )) i; for ((i=0;i<n;i++)); do newlog | grep -a -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
shot(){ N=$((N+1)); sleep 0.3; local f; f=$(printf '%s/shot_%02d_%s.png' "$B" "$N" "${1:-s}"); cp "$B/png/nvk_last.png" "$f" 2>/dev/null && say "shot $(basename "$f")" || say "no frame for $1"; }
ok(){ say "PASS $1"; echo "PASS $1" >> "$V"; }
bad(){ say "FAIL $1"; echo "FAIL $1" >> "$V"; FAIL=1; }
info(){ say "INFO $1"; echo "INFO $1" >> "$V"; }
rss(){ local p; p=$(pgrep -x "$PN" | head -1); [ -n "$p" ] && ps -o rss= -p "$p" | awk '{printf "%d", $1/1024}' || echo 0; }
# need <label> <regex> <timeout>: wait for a new marker since the last mark(); a miss FAILS the leg (screenshot, end)
need(){ if waitnew "$2" "$3"; then ok "$1"; else bad "$1 (no '$2' in ${3}s)"; shot "${1}_FAIL"; leg_end; fi; }
# pstep <pad> <label> <regex> <timeout> [settle]: mark, press, assert
pstep(){ mark; press "$1" 0.2; need "$2" "$3" "$4"; sleep "${5:-1}"; }
leg_end(){ sleep 1; echo 0 > "$FIFO"; pkill -x "$PN" 2>/dev/null; sleep 2; cp "$LOGF" "$B/guest.log"; local L="$B/guest.log"
  { echo "leg=$LEG mode=$LMODE tag=$TAG wall=$(( $(date +%s)-T0 ))s"
    echo "FATAL=$(grep -a -c FATAL "$L") VKERR=$(grep -a -c 'VK_ERROR\|VUID' "$L") SLOW=$(grep -a -c '\[slowframe\]' "$L") DROPOUT=$(grep -a -c DROPOUT-CONFIRMED "$L") UNDERRUN_NONZERO=$(grep -a '\[starve\]' "$L" | grep -a -vc 'underruns=0 (total=0)')"
    echo "modreg: $(grep -a '\[modreg\].*2/2' "$L" | head -1 | cut -c1-90)"
    echo "modswap: $(grep -a -o '\[modswap\] #[0-9]* DONE — live module is now [a-z_]*' "$L" | sed 's/\[modswap\] //;s/ DONE — live module is now / /' | tr '\n' ';')"
    echo "residue: $(grep -a -o 'residue=[0-9]*' "$L" | sort | uniq -c | tr '\n' ' ')"; } > "$B/facts.txt"
  local nf; nf=$(grep -a -c 'FATAL\|VK_ERROR\|VUID' "$L"); [ "$nf" = 0 ] && echo "PASS no FATAL/VK_ERROR" >> "$V" || { echo "FAIL $nf FATAL/VK_ERROR lines" >> "$V"; FAIL=1; }
  [ $FAIL = 0 ] && echo "VERDICT PASS" >> "$V" || echo "VERDICT FAIL" >> "$V"; say "DONE -> $B"; cat "$V" "$B/facts.txt"
  [ $GOT = 1 ] && { rmdir "$LOCK" 2>/dev/null; GOT=0; }
  exit $FAIL
}

# ---------------------------------------------------------------------------------------------------- navigation macros
title_to_top(){ # shell title -> top menu (the title ignores START until loaded: press every 4 s)
  mark; local ok=0 t; for ((i=0;i<60;i++)); do grep -a -q "name='motion/title.lzx'" "$LOGF" && break; sleep 1; done; sleep 4
  mark; for t in 1 2 3 4 5 6 7 8; do press 10 0.2; waitnew 'SYS_BGM cue0 (mushifuta_Menu02)' 4 && { ok=1; break; }; done
  [ $ok = 1 ] && ok "top_menu (START try $t)" || { bad "top_menu"; shot top_menu_FAIL; leg_end; }; sleep 3; }
card_decide(){ # top menu -> card panel -> (LEFT) -> decide     $1 = arcade|x360 ; asserts [modeidx]
  pstep 1000 "card_panel_$1" '92E8 bind#[0-9]* .*vt=0x82050574' 10 2
  [ "$1" = x360 ] && { press 4 0.2; sleep 3.6; shot "card_x360"; } || sleep 1.6
  local pat='\[modeidx\] .*ARCADE'; [ "$1" = x360 ] && pat='\[modeidx\] .*XBOX-360'
  pstep 1000 "decide_$1" "$pat" 15 0; }
enter_hub(){ # module title/attract -> HUB; $1 = ceiling s. Hub proof = GameEntry(msg=11 OR the hub model (vt 0x820503B0) ACTIVE
  # (a module swapped back to ARCADE re-enters its EXISTING hub model with no msg=11/p0build). START only while neither has been seen.
  local HUBRE='GameEntry(msg=11,\|BA4D8(ACTIVE).*vt=0x820503B0'
  mark; local t ok=0 n=$(( ${1:-90}/5 )); sleep 4
  for ((t=0;t<n;t++)); do waitnew "$HUBRE" 3 && { ok=1; break; }; press 10 0.2; waitnew "$HUBRE" 3 && { ok=1; break; }; done
  [ $ok = 1 ] && { ok "hub (START tries $t)"; } || { bad "hub (not seen in ${1:-90}s)"; shot hub_FAIL; leg_end; }; sleep 3; }
hub_to_top(){ pstep 2000 hub_back '\[decide\] .*item=-1' 10 2; pstep 1000 "top_menu_again" 'GameEntry(msg=3,\|BA4D8(ACTIVE).*vt=0x82050518' 20 4; }
boot_hub(){ # title -> hub in $LMODE
  title_to_top; card_decide "$LMODE"
  if [ "$LMODE" = x360 ]; then need modswap2 '\[modswap\] #2 DONE' 120; enter_hub 90; else sleep 8; enter_hub 60; fi; }
SEEDS(){ echo "_local/saves/save_rc1_rc1m_$1"; }
RT_SAVE_DIR=""; setsave(){ RT_SAVE_DIR="_local/saves/${SAVEPFX}_${TAG}_$1"; }

# ---------------------------------------------------------------------------------------------------- item A
item_A(){
  setsave A; leg_begin A swap "$(SEEDS arcade)"; unset RT_NAV360
  title_to_top; shot title_top
  local c m prev_swaps=0 rssl=""
  for c in 1 2 3 4 5; do
    for m in arcade x360; do
      say "=== cycle $c $m ==="
      card_decide "$m"
      if [ "$m" = arcade ] && [ $c = 1 ]; then ok "c${c}_arcade: boot module, no swap"; sleep 8
      else local k; k=$(( (c-1)*2 + $([ $m = arcade ] && echo 1 || echo 2) ))
        need "c${c}_${m}_modswap#${k}" "\[modswap\] #${k} DONE — live module is now $([ $m = arcade ] && echo reco_normal || echo reco_abnormal)" 120; sleep 4; fi
      enter_hub 120; shot "c${c}_${m}_hub"
      local r; r=$(rss); rssl="$rssl c${c}$m=$r"; info "RSS c${c}_$m=${r}MB"
      hub_to_top
    done
  done
  echo "RSS samples (MB):$rssl" >> "$B/facts.txt"
  # final scoring
  local n; n=$(grep -a -c '\[modswap\] #[0-9]* DONE' "$LOGF"); [ "$n" = 10 ] && ok "10 [modswap] DONE (boot activation #1 + swaps #2..#10; the first ARCADE decide is not a swap)" || bad "modswap DONE count $n != 10"
  [ "$(grep -a -c 'residue=0' "$LOGF")" = 9 ] && ok "residue=0 x9 (every swap)" || bad "residue=0 count $(grep -a -c 'residue=0' "$LOGF") != 9"
  [ "$(grep -a -c '\[modreg\].*2/2 module' "$LOGF")" = 1 ] && ok "modreg 2/2 once" || bad "modreg 2/2 count"
  leg_end
}

# ---------------------------------------------------------------------------------------------------- stage helpers
stage_re(){ [ "$LMODE" = x360 ] && echo '\[nav360\] D=0x60 st=5 d76=4 ' || echo '\[navreal\] d76 3->4'; }
dead_re(){ [ "$LMODE" = x360 ] && echo 'd76=5 ' || echo 'd76 4->5'; }        # continue countdown expired -> game over begins
exit_re(){ [ "$LMODE" = x360 ] && echo 'st=2 d76=8 ' || echo '\[navreal\] d76 6->8'; }   # stage torn down (replay-save prompt follows); [gemsg] msg=N lines are capped at the first calls, never gate on them late
hubback_re(){ [ "$LMODE" = x360 ] && echo '\[nav360\] D=0x60 st=5 d76=1 field=0' || echo '\[navreal\] d76 0->1 '; }   # module back at its hub (d76=1) after a stage teardown -- uncapped
title_re(){ [ "$LMODE" = x360 ] && echo '\[nav360\] D=0x60 st=3 ' || echo '\[navreal\] st 2->3'; }
wander(){ # $1 = pattern to stop on, $2 = ceiling s: fly UP-LEFT / UP-RIGHT (no shots) until the pattern shows; sets WANDER_T
  local t=0 w=5; WANDER_T=-1; while [ $t -lt "$2" ]; do newlog | grep -a -q -- "$1" && { WANDER_T=$t; break; }; [ $((t%3)) = 0 ] && { [ $w = 5 ] && w=9 || w=5; }; echo "$w" > "$FIFO"; sleep 1; t=$((t+1)); done; echo 0 > "$FIFO"; [ "$WANDER_T" -ge 0 ]; }
PAUSE_RE='BA4D8(ACTIVE).*vt=0x82050488 .*cursor=0 state 0x82061D50->0x82061D50'
training_to_stage1(){ # hub -> TRAINING panel -> A (dialog), A -> stage 1 entry (default options; ships die on their own ~20-30 s). Presses can be dropped: each A retried.
  pstep 2 hub_down1 '\[mcur\] .*cursor 0->1' 5 1.5; pstep 2 hub_down2 '\[mcur\] .*cursor 1->2' 5 1.5
  pstep 1000 training_open '\[decide\] .*item=2 ' 8 4; shot panel_open    # [tstate] 96660(load) is not re-emitted on later panels
  # DC-1 (10-12): the start marker is the shell's msg-18 send / the module's own stage entry. The old marker, `[dclose]
  # slide-out ... vt=0x82050F00`, is printed only for the first 8 slide-outs PER PROCESS (merged_shell.cpp sub_821BEED8
  # `if(i<=8)`), and the first training session uses all 8 -- so every later training start in the same process
  # looked "dead" although msg=18 + d76 1->2->3->4 followed the first A (Q5 f4_B/f5_C/f5_D/t2a logs). [gemsg] is capped
  # at 3 calls per msg id, so the stage-entry marker (uncapped, transition-logged) is the one that always holds.
  local t ok=0 pw; TS_A_DEAD=0; local SRE="dclose.*vt=0x82050F00\|GameEntry(msg=18,\|$(stage_re)"
  for t in 1 2 3 4; do pw=1000; [ $t -ge 3 ] && pw=10; mark; press $pw 0.2; waitnew "$SRE" 8 && { ok=1; break; }; say "no start marker after pad $pw try $t"; done
  if [ $ok = 1 ]; then say "training start accepted (pad $pw try $t)"; if [ $t -ge 3 ]; then TS_A_DEAD=1; info "TRAINING panel: A (0x1000) x2 did nothing; pad $pw opened the start dialog"; fi
  else bad "training start never accepted (A x2, START x2: no dclose / msg=18 / stage entry)"; shot dialog_FAIL; [ "${SOFT:-0}" = 1 ] && { TS_OK=0; return 1; }; leg_end; fi; sleep 1
  ok=0; waitnew "$(stage_re)" 6 && { ok=1; t=0; say "stage entered without a dialog press"; }
  [ $ok = 1 ] || for t in 1 2 3; do pw=1000; [ $t = 2 ] && pw=10; mark; press $pw 0.2; waitnew "$(stage_re)" 25 && { ok=1; break; }; say "no stage entry after dialog pad $pw try $t"; done
  [ $ok = 1 ] && ok "stage1_entry (dialog A try $t)" || { bad "stage1_entry"; shot entry_FAIL; [ "${SOFT:-0}" = 1 ] && { TS_OK=0; return 1; }; leg_end; }; TS_OK=1; shot entry; }
np_to_stage1(){ # hub -> NORMAL PLAY -> 1P SIDE START -> mode select (Original) -> char -> shot -> stage 1 (4 s cadence)
  pstep 2 hub_down1 '\[mcur\] .*cursor 0->1' 5 0.5; pstep 1000 np_submenu '\[decide\] .*item=1 ' 5 3
  press 1000 3; shot mode_select; press 1000 3; press 1000 3; mark; press 1000 0.2; need stage1_entry "$(stage_re)" 60 ; shot entry; }
pause_now(){ pstep 10 "pause$1" "$PAUSE_RE" 10 2; shot "pause$1"; }

watch(){ # watch <secs> <interval> <label> -- shot every interval, print the new state lines (no presses)
  local t=0; while [ $t -lt "$1" ]; do mark; sleep "$2"; t=$((t+$2)); shot "$3_$t"
    newlog | grep -a '\[navreal\]\|\[nav360\]\|GameEntry(msg=1[0-9]\|GameEntry(msg=3,' | cut -c1-150 | awk '!s[$0]++' | tee -a "$B/steps.txt" | sed 's/^/    /'; done; }
game_select_to_stage1(){ # at a 1P-SIDE-START submenu row: A -> mode select (A, 48-count) -> char (A) -> shot (A) -> stage 1  (4 s cadence)
  press 1000 3.4; shot mode_select; press 1000 3.4; shot char_select; press 1000 3.4; shot shot_select; mark; press 1000 0.2
  need stage1_entry "$(stage_re)" 60; shot entry; }
idle_death(){ # no input until GameEntry(msg=10 (game over / replay-save prompt) or $1 s; shot every 6 s
  local t=0 mx="${1:-120}"; mark; while [ $t -lt $mx ]; do waitnew "$(exit_re)" 3 && { ok "game over (stage torn down: $(exit_re)) at +${t}s"; return 0; }; t=$((t+3)); [ $((t%6)) = 0 ] && shot "idle_$t"
    newlog | grep -a '\[navreal\]\|\[nav360\]' | cut -c1-150 | awk '!s[$0]++' | tail -3 | sed 's/^/    /'; done; bad "no game over in ${mx}s"; shot idle_FAIL; leg_end; }
body_D(){ say "=== D SCORE ATTACK ($LMODE) ==="; mark; press 1000 0.2; need sa_decide '\[decide\] .*item=0 ' 8; sleep 3; shot sa_dialog
  press 1000 3; shot sa_submenu; info "SA: sign-in dialog -> A:OK -> SCORE ATTACK submenu (1P/2P SIDE START, LEADERBOARD greyed, EXIT)"
  mark; press 1000 0.2; game_select_to_stage1_from_submenu; }
game_select_to_stage1_from_submenu(){ sleep 3; shot sa_mode_select; press 1000 3.4; shot sa_char; press 1000 3.4; shot sa_shot; mark; press 1000 0.2
  need sa_stage1_entry "$(stage_re)" 60; shot sa_entry; idle_death 150; sleep 2; shot sa_gameover_1
  # chain (measured 10-12, both prompts then a dialog): replay-save prompt B -> score-register prompt B -> "ranking registration cancelled" OK dialog A -> MODULE TITLE (ranking attract)
  mark; press 2000 2.5; shot sa_replay_B; mark; press 2000 2.5; shot sa_score_B; mark; press 1000 0.2; need sa_chain_to_title "$(title_re)" 20; sleep 3; shot sa_title
  enter_hub 60; shot sa_hub_again; ok "D SCORE ATTACK chain: sign-in dialog -> OK -> SA submenu -> stage 1 -> idle death -> replay B -> register B -> OK -> title -> hub"; }
body_B(){ say "=== B RESTART ($LMODE) ==="; training_to_stage1; sleep 3; pause_now 1
  press 2 1.2; shot restart_cursor; press 1000 1.5; shot restart_confirm_dialog      # A on RESTART -> 「リスタートします。よろしいですか?」
  mark; press 1000 0.2; need restart_d76_to3 "$([ "$LMODE" = x360 ] && echo 'd76=3 ' || echo 'd76 4->3')" 15; need restart_reentry "$(stage_re)" 30; sleep 6; shot restarted_stage
  pause_now 2; training_exit_to_hub
  ok "ITEM B RESTART ($LMODE): pause -> RESTART -> confirm -> msg=14 + d76 4->3->4 re-entry -> pause -> PREVIOUS MENU -> hub"; }
item_B(){ setsave B_$1; leg_begin B_$1 "$1" "$(SEEDS $1)"; boot_hub; body_B; body_T afterRestartSession; leg_end; }
training_exit_to_hub(){ # (in the training pause menu) PREVIOUS MENU -> confirm -> hub -> the panel re-opens by itself -> B -> hub, cursor back to row 0
  press 2 1.2; press 2 1.2; press 2 1.2; shot previous_menu_cursor      # in TRAINING the 4th pause row reads PREVIOUS MENU (NORMAL PLAY: RETURN TO TITLE)
  press 1000 2.5; shot previous_menu_confirm; mark; press 1000 0.2; need previous_menu_to_hub "p0build\\] menu_game_title\\|GameEntry(msg=11,\\|$(hubback_re)" 25; sleep 4; shot hub_after_training
  sleep 5; shot panel_reopened; press 2000 3; shot hub_cursor_training
  pstep 1 hub_up1 '\[mcur\] .*cursor 2->1' 5 1; pstep 1 hub_up2 '\[mcur\] .*cursor 1->0' 5 1; }
body_T(){ # training start probe in the CURRENT process state ($1 = label): entry, 6 s of play, pause, PREVIOUS MENU, hub. SOFT: records PASS/FAIL, never ends the leg on a missed start
  say "=== T training start after $1 ($LMODE) ==="; SOFT=1; TS_OK=0; training_to_stage1 || true; SOFT=0
  if [ "$TS_OK" = 1 ] && [ "${TS_A_DEAD:-0}" = 1 ]; then echo "FAIL ITEM T training after $1 ($LMODE): A on Start Training dead, START works" >> "$V"; FAIL=1; sleep 6; pause_now "T$1"; training_exit_to_hub
  elif [ "$TS_OK" = 1 ]; then sleep 6; pause_now "T$1"; training_exit_to_hub; ok "ITEM T training after $1 ($LMODE): start works"
  else FAIL=1; echo "FAIL ITEM T training after $1 ($LMODE): TRAINING Start (A) does nothing" >> "$V"; press 2000 3; shot t_exit_B; press 1 1; press 1 1; shot t_hub_cursor0; fi; }
body_C(){ say "=== C CONTINUE ($LMODE) ==="; np_to_stage1; TE=$(date +%s)
  # the idle ship dies ~+16-19 s after entry and CONTINUE? counts 9..0 for ~9-10 s: START at +20 s lands inside it (no log marker on the countdown itself; screenshot-proved)
  while [ $(( $(date +%s)-TE )) -lt 20 ]; do sleep 1; done; shot continue_screen
  local try cont=0; for try in 1 2 3; do mark; press 10 0.2; sleep 3; shot "continue_start_try$try"
    if newlog | grep -a -q 'BA4D8(ACTIVE).*vt=0x82050488'; then info "try $try: START opened the PAUSE menu instead of continuing (A=RESUME, retry)"; press 1000 1.5; continue; fi
    if newlog | grep -a -q "$([ "$LMODE" = x360 ] && echo 'd76=5 ' || echo 'd76 4->5')"; then info "try $try: countdown already expired (game over)"; break; fi
    cont=1; ok "continue try $try: START accepted (no pause menu, no game over within 3 s)"; break; done
  [ $cont = 1 ] || { bad "continue-by-START not accepted in 3 tries"; shot continue_FAIL; leg_end; }
  mark; sleep 12; if newlog | grep -a -q "$([ "$LMODE" = x360 ] && echo 'd76=5 ' || echo 'd76 4->5')"; then bad "game over within 12 s of the continue (play did not resume)"; else ok "play resumed: no d76 4->5 for 12 s after the continue (countdown would have expired in <10 s)"; fi; shot resumed_play
  [ "$LMODE" = x360 ] && newlog | grep -a 'cred=' | cut -c1-140 | tee -a "$B/steps.txt"
  # second death: let the countdown expire -> game over -> replay-save prompt -> decline
  mark; if wander "$(dead_re)" 300; then ok "second death + countdown expiry -> $(dead_re) (+${WANDER_T}s, ship flown UP-LEFT/UP-RIGHT, no shots)"; else bad "no second game over in 300 s"; shot second_FAIL; leg_end; fi
  need gameover_stage_teardown "$(exit_re)" 25; sleep 3; shot replay_save_prompt
  mark; press 2000 3; shot after_decline; newlog | grep -a 'GameEntry(msg=1[0-9]\|modegate' | grep -av 'msg=5,' | cut -c1-110 | head -6 | tee -a "$B/steps.txt"
  info "name entry: none expected (score 0 does not rank) -- shots after_decline/title show the next screen"; sleep 4; shot title_ranking
  enter_hub 60; shot hub_after_gameover
  ok "ITEM C CONTINUE ($LMODE): idle death -> CONTINUE -> START resumes -> idle death -> expiry -> game over -> replay prompt B -> title -> hub"; }
body_CX(){ # DC-2 continue-by-START proof: NORMAL PLAY idle deaths, START once at each CONTINUE? countdown, N times (needs RT_PAUSEPROBE=1:
  # the countdown marker is the game's own P1-continue status byte 0x887AD545 (+0x60 in 360) going 1, read by the shell's pause trigger)
  say "=== CX continue-by-START x${CX_N:-3} ($LMODE) ==="; np_to_stage1; local k cont=0 paused=0 CRE='\[pauseprobe\] st@0x[0-9A-F]* = 00 01 '
  for ((k=1;k<=${CX_N:-3};k++)); do mark; waitnew "$CRE" 150 || { bad "CX#$k: no CONTINUE countdown (p1cont=1) in 150 s"; shot "cx${k}_nodeath"; break; }
    sleep "${CX_DELAY:-3}"; shot "cx${k}_countdown"; mark; press 10 0.2; sleep 3; shot "cx${k}_after_start"
    if newlog | grep -a -q 'BA4D8(ACTIVE).*vt=0x82050488\|GameEntry(msg=10,'; then paused=$((paused+1)); bad "CX#$k: START at CONTINUE opened PAUSE"; press 1000 2   # A = RESUME (the game itself already continued under the pause)
    elif newlog | grep -a -q '\[pauseprobe\] st@0x[0-9A-F]* = 00 00 '; then cont=$((cont+1)); ok "CX#$k: START at CONTINUE continued (p1cont 1->0, no pause)"
    else bad "CX#$k: START at CONTINUE: neither continue nor pause seen"; fi; done
  info "CX ($LMODE): continued $cont / ${CX_N:-3}, paused $paused"; }
item_CX(){ setsave CX_$1; leg_begin CX_$1 "$1" "$(SEEDS $1)"; boot_hub; body_CX; leg_end; }
item_SM(){ # shell smoke steps of app_smoke_mac.sh, run against a probe binary (never the .app): title -> top -> card ARCADE -> hub -> B -> top
  setsave SM; leg_begin SM arcade "$(SEEDS arcade)"; boot_hub; hub_to_top
  grep -a -q "2/2 module DLL(s) bound" "$LOGF" && ok "SM: both modules bound" || bad "SM: modules not both bound"; leg_end; }
item_SM2(){ # relaunch on SM's save (no reseed): the save must be read back
  setsave SM; leg_begin SM2 arcade ""; title_to_top; grep -a -q "existed=1" "$LOGF" && ok "SM2: save read back (existed=1)" || bad "SM2: save not read back"; leg_end; }
item_C(){ setsave C_$1; leg_begin C_$1 "$1" "$(SEEDS $1)"; boot_hub; body_C; body_T NPgameover; leg_end; }
item_D(){ setsave D_$1; leg_begin D_$1 "$1" "$(SEEDS $1)"; boot_hub; body_D; body_T SAgameover; leg_end; }
body_T2(){ # isolation probe: after PREVIOUS MENU the panel re-opens by itself; start training again DIRECTLY from it (no B, no hub round-trip)
  say "=== T2 training restart from the re-opened panel ($LMODE) ==="; training_to_stage1; sleep 3; pause_now T2a
  press 2 1.2; press 2 1.2; press 2 1.2; press 1000 2.5; mark; press 1000 0.2; need t2_to_hub "p0build\\] menu_game_title\\|GameEntry(msg=11,\\|$(hubback_re)" 25; sleep 6; shot t2_panel_reopened
  # DC-1: success = the module's own stage entry (d76 3->4 / nav360 d76=4), not the per-process-capped [dclose] line
  SOFT=1; TS_OK=0; local t ok2=0; for t in 1 2 3; do mark; press 1000 0.2; waitnew "$(stage_re)" 25 && { ok2=1; break; }; done
  if [ $ok2 = 1 ]; then ok "ITEM T2 ($LMODE): A on the re-opened panel starts training (stage entry, try $t)"; shot t2_stage2
    sleep 4; pause_now T2b; training_exit_to_hub; say "=== T3 third training start in the same process, via the hub ($LMODE) ==="
    training_to_stage1 || true; [ "$TS_OK" = 1 ] && [ "${TS_A_DEAD:-0}" = 0 ] && ok "ITEM T3 ($LMODE): third training start (hub -> panel -> A) enters the stage" || { echo "FAIL ITEM T3 ($LMODE): third training start" >> "$V"; FAIL=1; }
  else echo "FAIL ITEM T2 ($LMODE): A on the re-opened panel does not start training (3 tries)" >> "$V"; say "FAIL T2"; FAIL=1; shot t2_FAIL; fi; SOFT=0; }
item_T2(){ setsave T2_$1; leg_begin T2_$1 "$1" "$(SEEDS $1)"; boot_hub; body_T2; leg_end; }
body_E0(){ say "=== E0 explore OPTION > Controller ($LMODE) ==="
  local k; for k in 1 2 3 4; do pstep 2 "hub_down$k" "\[mcur\] .*cursor $((k-1))->$k" 5 1; done
  pstep 1000 option_open '\[decide\] .*item=4 ' 8 3; shot option_list
  press 1000 3; shot controller_panel; press 2 1; shot c_down1; press 1000 2; shot c_A1; press 8 1; shot c_right; press 1 1; shot c_up; press 1000 2; shot c_A2; }
item_E0(){ setsave E0_$1; leg_begin E0_$1 "$1" "$(SEEDS $1)"; boot_hub; body_E0; leg_end; }
snapdir(){ ( cd "$RT_SAVE_DIR" && find . -type f -exec md5 -r {} \; | sort -k2 ) > "$B/save_$1.txt"; say "save snapshot $1: $(grep -a savegame "$B/save_$1.txt" | cut -c1-40)"; }
open_controller(){ local k; for k in 1 2 3 4; do pstep 2 "hub_down$k" "\[mcur\] .*cursor $((k-1))->$k" 5 1; done
  pstep 1000 option_open '\[decide\] .*item=4 ' 8 3; press 1000 3; shot controller_panel; }      # OPTION (row 4) -> list -> A on Controller Setting; cursor starts on EXIT
back_to_hub_from_controller(){ # $1 = number of UP presses to reach EXIT (cursor wraps; 0 when the panel was just opened = cursor already on EXIT); A = save + previous menu; B = leave OPTION
  local u; for ((u=0;u<${1:-0};u++)); do press 1 1; done; shot controller_exit_row; press 1000 2.5; shot controller_saved_exit; press 2000 3; shot hub_back; }
body_E1(){ say "=== E1 remap: change binding ($LMODE) ==="; snapdir before; open_controller
  press 2 1; shot e_row_shot; press 1000 1.5; shot e_shot_capture        # A on SHOT -> "[ A ]" capture state
  press 2000 1.5; shot e_shot_is_B                                         # press B -> SHOT = B
  press 2 1; press 1000 1.5; shot e_bomb_is_A      # BOMB row: the A press assigns A to BOMB at once (swap complete: SHOT=B, BOMB=A); a 2nd A would clear it
  back_to_hub_from_controller 2; snapdir after
  cmp -s "$B/save_before.txt" "$B/save_after.txt" && { bad "save dir unchanged after the remap (binding not persisted)"; } || ok "save dir changed after the remap: $(diff "$B/save_before.txt" "$B/save_after.txt" | grep -a '^>' | cut -c1-60 | tr '\n' ' ')"
  # quit path: hub B -> confirm -> A -> shell top menu -> DOWN x4 (EXIT) -> A -> shell title; then the process is ended (it does not exit by itself)
  hub_to_top; local k; for k in 1 2 3 4; do press 2 0.8; done; shot top_exit_row; press 1000 3; shot after_exit_title; info "quit path taken (top menu EXIT -> shell title); process ended by pkill -x"; }
body_E2(){ say "=== E2 remap: read back + play proof + restore ($LMODE) ==="; snapdir relaunch
  [ -f "$B/../${TAG}_E1_$LMODE/save_after.txt" ] && { cmp -s "$B/save_relaunch.txt" "$B/../${TAG}_E1_$LMODE/save_after.txt" && ok "save dir identical to the end of E1 (persisted across the relaunch)" || bad "save dir differs from E1 end"; }
  open_controller; sleep 1; shot readback_panel; info "READBACK: panel screenshot readback_panel must show SHOT=B-icon BOMB=A-icon (eyes)"; back_to_hub_from_controller 0
  local k; for k in 4 3 2 1; do pstep 1 "hub_up_$k" "\[mcur\] .*cursor $k->$((k-1))" 5 1; done
  # play proof via NORMAL PLAY (the TRAINING start dialog does not respond to A, START or B once remapped/after panel visits -- see REPORT): the game's own
  # select screens (mode/char/shot) are driven with the NEW shot button (B = 0x2000) because the in-game select screens decide with the SHOT binding.
  pstep 2 hub_down1 '\[mcur\] .*cursor 0->1' 5 0.5; pstep 1000 np_submenu '\[decide\] .*item=1 ' 5 3; press 1000 3; shot mode_select_A
  local pw=2000; press $pw 3.4; shot char_select; press $pw 3.4; shot shot_select; mark; press $pw 0.2; need stage1_entry_with_B "$(stage_re)" 60; shot entry
  sleep 3; echo 2000 > "$FIFO"; sleep 3; shot play_B_held; echo 0 > "$FIFO"; sleep 1; shot play_B_released
  mark; press 1000 0.2; sleep 0.5; shot play_A_bomb_a; sleep 0.7; shot play_A_bomb_b; info "PLAY PROOF: B held 3 s = shot stream (play_B_held), single A = bomb effect (play_A_bomb_*) with the swapped binding (eyes)"
  pause_now E2; press 2 1.2; press 2 1.2; press 2 1.2; press 1000 2.5; mark; press 1000 0.2; need return_to_title_hub 'p0build\] menu_game_title\|BA4D8(ACTIVE).*vt=0x820503B0' 30; sleep 4; shot hub_after_play
  shot hub_cursor      # the hub is rebuilt with the cursor on row 0
  # restore the default: Controller panel -> Default Setting row
  sleep 1; open_controller; press 2 1; press 2 1; press 2 1; press 2 1; press 2 1; shot e_default_row;   # rows: SHOT BOMB R.SHOT [Player Change = Arrange-only, selectable but inert] Default Setting EXIT
   press 1000 2; shot e_default_done; press 2 1; press 1000 2.5; shot e_default_exit_saved
  snapdir restored
  info "default restore: Default Setting row A -> panel shows SHOT=A BOMB=B again (e_default_done, eyes); the byte compare vs the seed is not meaningful after play (stats bytes change)"
  ok "ITEM E remap round-trip steps executed ($LMODE)"; }
item_E1(){ setsave E_$1; leg_begin E1_$1 "$1" "$(SEEDS $1)"; boot_hub; body_E1; leg_end; }
item_E2(){ setsave E_$1; leg_begin E2_$1 "$1"; boot_hub; body_E2; leg_end; }      # same save dir, NO re-seed
item_E(){ item_E1 "$1"; ( item_E2 "$1" ); }
item_BCD(){ setsave BCD_$1; leg_begin BCD_$1 "$1" "$(SEEDS $1)"; boot_hub; body_B; body_T afterB; body_C; body_T NPgameover; body_D; body_T SAgameover; leg_end; }

# ---------------------------------------------------------------------------------------------------- dispatch
run_item(){ ( case "$1" in A) item_A;; B) item_B "$2";; C) item_C "$2";; CX) item_CX "$2";; SM) item_SM;; SM2) item_SM2;; BCD) item_BCD "$2";; T2) item_T2 "$2";; E1) item_E1 "$2";; E2) item_E2 "$2";; E0) item_E0 "$2";; D) item_D "$2";; E) ( item_E1 "$2" ); rc1=$?; ( item_E2 "$2" ); exit $(( rc1 | $? ));; *) echo "unknown item $1"; exit 2;; esac ); [ $? = 0 ] || OVERALL=1; }
modes(){ [ -n "$ONLYMODE" ] && echo "$ONLYMODE" || echo "arcade x360"; }
case "$ITEM" in
  A) run_item A;;
  SM|SM2) run_item "$ITEM";;
  all) run_item A; for it in B C D E; do for m in $(modes); do run_item "$it" "$m"; done; done;;
  E1|E2|E0|T2|CX|BCD|B|C|D|E) for m in $(modes); do run_item "$ITEM" "$m"; done;;
  *) echo "usage: rc_chain_mac.sh <tag> <bin> A|B|C|CX|D|E|T2|SM|SM2|all [arcade|x360]"; exit 2;;
esac
exit $OVERALL
