#!/bin/bash
# boss1_drive_mac.sh <tag> [BIN] [DUR] — training route to the STAGE-1 BOSS on the Mac, focus-independent.
# All input goes through a pad FIFO OR'd into the HOST keyboard channel (RT_PAD_HOST_FIFO), so the user may keep
# using the Mac while it runs and the game sees exactly what a keyboard press is. Frames come from the renderer's own dump (RT_NVKPNG every 60 frames into RVK_DUMPDIR), so
# window overlap does not matter either. Route: START A A A DOWN DOWN A = Training panel; RIGHT x NRIGHT (1 =
# "Stage 1 Boss"); A = 開始 (NOT START: START is the in-game PAUSE, GameEntry msg=10); A x4 through the selects; then a dwell with
# autofire (A 2 s on / 0.4 off). Needs a card with a save (_local/saves/save_mac).
# Bank: _local/boss1_mac/<tag>/{png/nvk_f<frame>.png, guest.log, presses.txt}
# Route is MARKER-DRIVEN (10-05): each press waits for its own log confirmation and retries once -- see step().
set -u
cd "$(dirname "$0")/../.."
TAG="${1:-pilot}"; BIN="${2:-build/futari_merged}"; DUR="${3:-120}"
B="_local/boss1_mac/$TAG"; rm -rf "$B"; mkdir -p "$B/png"
FIFO=/tmp/futari_pad_boss1; echo 0 > "$FIFO"
# Input rides the HOST keyboard channel (RT_PAD_HOST_FIFO, shell/gen/stubs.cpp): indistinguishable from a human
# at the keyboard. The synthetic channel (RT_PAD + RT_PAD_FIFO) stalled the training launch on the game's
# transition flag -- the user's keyboard runs never did.
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO"   # no RT_NOXINPUT: the user plays with SDL controllers enabled (a synthetic pad0 is reported)
# RT_NOPAUSE (the old Windows driver's spin-breaker: forces the game's "transition in progress" flag 0x887AD534
# back to 0 every frame) is OPT-IN here (NOPAUSE=1): suspected of aborting the training STAGE JUMP to the boss
# segment -- the user's manual runs never set it.
[ "${NOPAUSE:-0}" = "1" ] && export RT_NOPAUSE=1
export RT_NVKPNG="${NVKPNG:-60}" RVK_DUMPDIR="$PWD/$B/png"
pkill -f "build/ctl_\|build/futari_merged\|build/plate_" 2>/dev/null; sleep 1
PREVLOG=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1)
BIN="$BIN" RUN_SECS=$((DUR+100)) bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s)
# pin THIS launch's log: the newest mac_*.log is the previous run's until run_mac.sh creates ours, and that one
# already holds every marker (a whole-log wait would fire at once)
LOGF=""; for ((i=0;i<60;i++)); do L=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1); [ -n "$L" ] && [ "$L" != "$PREVLOG" ] && { LOGF="$L"; break; }; sleep 0.5; done
[ -n "$LOGF" ] || { echo "[boss1] no new log appeared -- did $BIN start? ($B/run_out.txt)"; exit 1; }
log(){ echo "$LOGF"; }
say(){ echo "[boss1] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/presses.txt"; }
press(){ echo "$1" > "$FIFO"; sleep "${3:-0.2}"; echo 0 > "$FIFO"; say "pad $1 ($2)"; }
waitfor(){ local pat="$1" to="$2" lbl="$3" i; for ((i=0;i<to;i++)); do grep -q "$pat" "$(log)" 2>/dev/null && { say "marker: $lbl"; return 0; }; sleep 1; done; say "TIMEOUT: $lbl"; return 1; }
# Marker-driven route (10-05): every step waits for ITS OWN confirmation line, counted from the log position at
# press time (the SE/BGM cue lines repeat, so a whole-log grep would match an earlier step), and a press whose
# marker never shows is re-pressed once. Replaces the blind `sleep 14` before START and the fixed 5 s gaps: a
# fresh binary's cold first launch slipped the old timings and the run desynced in the menus (plate_allgame 10-04).
MARK=0
mark(){ MARK=$(wc -l < "$(log)" 2>/dev/null | tr -d ' '); MARK=${MARK:-0}; }
waitnew(){ local pat="$1" to="$2" lbl="$3" i; for ((i=0;i<to*2;i++)); do tail -n +"$((MARK+1))" "$(log)" 2>/dev/null | grep -q "$pat" && { say "marker: $lbl"; return 0; }; sleep 0.5; done; say "TIMEOUT: $lbl"; return 1; }
step(){ # pad label marker timeout [settle]  -- press, wait for the marker since the press; one retry on timeout
  local pad="$1" lbl="$2" pat="$3" to="$4" settle="${5:-1}" try
  for try in 1 2; do mark; press "$pad" "$lbl"; waitnew "$pat" "$to" "$lbl -> $pat" && { sleep "$settle"; return 0; }; say "retry $lbl"; done; return 1; }
waitfor "name='motion/title.lzx'" 60 "title loaded"; sleep "${TITLE_SETTLE:-4}"
step 10 START 'SYS_BGM cue0 (mushifuta_Menu02)' 10 4            # menu BGM = START accepted; the save-data check slides by itself
step 1000 "A 1" 'SYS_SE cue1 (SE_OK01)' 6 3
step 1000 "A 2" '\[modeidx\] .*ARCADE' 6 3                    # mode chosen
step 1000 "A 3" '\[p0build\] menu_game_title' 8 2             # hub menu built (items incl. item_training)
step 2 "DOWN 1" 'SYS_SE cue5 (SE_Select01)' 4 0.6
step 2 "DOWN 2" 'SYS_SE cue5 (SE_Select01)' 4 0.8
step 1000 "A (training)" '96660(load)' 10 2                   # training panel
for ((i=0;i<${NRIGHT:-1};i++)); do step 8 "RIGHT (Stage row)" 'SYS_SE cue4 (SE_Select02)' 4 1; done   # the Stage row's move cue (10-05); the four selects after 開始 leave no marker and stay timed
sleep 1; step 1000 "A (開始)" 'dclose.*vt=0x82050F00' 8 2     # panel closed
for i in 1 2 3 4; do press 1000 "A select $i"; sleep 3; done
waitfor 'BGM cue1\|m02_stg\|BGM cue[0-9]* (m0[2-9]' 20 "stage BGM"
STAGE_T0=$(date +%s); say "STAGE_T0 — dwell ${DUR}s autofire via FIFO (QUIET=${QUIET:-0}s hold-fire first)"
# QUIET=<s> (boss plate gate): no shots for the first QUIET seconds of the dwell, so the boss intro -- the frames the
# per-push trace captures -- sees no player input at all and two arms stay in lockstep (shots landing a frame apart
# perturbed the boss path from its third frame, plate_v2 / plate_neg 10-04).
P=0
while [ $(( $(date +%s)-STAGE_T0 )) -lt "$DUR" ]; do
  if [ $(( $(date +%s)-STAGE_T0 )) -lt "${QUIET:-0}" ]; then sleep 1; continue; fi
  echo 1000 > "$FIFO"; sleep 2.0; echo 0 > "$FIFO"; sleep 0.4; P=$((P+1))
  # NO START pulses in the dwell: START is PAUSE in-game (GameEntry msg=10). The old Windows driver pulsed it
  # and masked the result with RT_NOPAUSE; the user's log (10-03 22:28) shows the game needs no START at all.
  if [ $((P%8)) -eq 0 ]; then say "dwell t+$(( $(date +%s)-STAGE_T0 ))s pngs=$(ls "$B/png" | wc -l | tr -d ' ')"; fi
  pgrep -f "$BIN" >/dev/null || { say "child exited"; break; }
done
echo 0 > "$FIFO"; say "dwell end"
pkill -x "$(basename "$BIN")" 2>/dev/null; sleep 1; cp "$(log)" "$B/guest.log"
echo "[boss1] DONE tag=$TAG pngs=$(ls "$B/png" | wc -l | tr -d ' ') cues: $(grep -o 'BGM cue[0-9]* ([a-z0-9_]*)' "$B/guest.log" | sort | uniq -c | tr '\n' ';')"
