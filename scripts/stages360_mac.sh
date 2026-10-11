#!/bin/bash
# stages360_mac.sh <tag> <stage 1-5> [BIN] -- RC1 Q7-360: XBOX 360 MODE stage sweep via the TRAINING panel (the 360 mirror of ARCADE route C).
#   card -> 360 title -> HUB -> DOWN x2 + A = TRAINING panel -> Shot Power Max / Bomb Stock Infinity / Player Stock Infinity (game's own
#   options) -> Stage k (RIGHT x 2(k-1)) -> A, A -> stage entry -> autofire + bomb (wall clock, host FIFO) until the boss-defeat [fade]
#   -> stage end (d76=8, results tally) -> B -> hub.   Markers via RT_NAV360=1 ([nav360] ... d76=).
#   bash scripts/stages360_mac.sh s1 1 build/q7x_probe/q7x_probe
#   bank: _local/rc1/q7x/<tag>/{shot_NN_*.png, guest.log, steps.txt, VERDICT.txt, facts.txt}
# DRIVE LOCK as nav360_mac.sh (mkdir /tmp/futari_drive.lock, sleep-60 loop up to LOCKWAIT s, rmdir on exit); pkill -x <basename BIN> ONLY.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; STAGE="${2:?stage 1-5}"; BIN="${3:-build/q7x_probe/q7x_probe}"; PN="$(basename "$BIN")"
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
B="${BANK:-_local/rc1/q7x/$TAG}"; rm -rf "$B"; mkdir -p "$B/png"
FIFO="${FIFO:-/tmp/futari_pad_q7x}"; echo 0 > "$FIFO"; LOCK=/tmp/futari_drive.lock
w=0; while :; do
  if mkdir "$LOCK" 2>/dev/null; then
    if pgrep -x futari_merged >/dev/null; then rmdir "$LOCK" 2>/dev/null; echo "user is playing (futari_merged) -- waiting"; else break; fi
  fi
  [ $w -ge "${LOCKWAIT:-7200}" ] && { echo "lock busy ${w}s -- giving up"; exit 3; }; sleep 60; w=$((w+60)); done
echo "lock acquired after ${w}s" > "$B/lockwait.txt"
trap 'kill $FIRER 2>/dev/null; pkill -x "$PN" 2>/dev/null; sleep 1; rmdir "$LOCK" 2>/dev/null' EXIT
FIRER=""
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG=30 RVK_DUMPDIR="$PWD/$B/png" RT_NAV360=1
export RVK_DRAWCENSUS=2 RT_MENULOG=1 RT_NVKRTLOG=1 RT_TRAINPROBE=1
export RT_SAVE="${RT_SAVE:-_local/saves/q7x_$TAG}"; SEED="${SEED:-_local/saves/save_rc1_rc1m_x360}"
[ -d "$SEED" ] || { echo "no save seed $SEED"; exit 2; }; rm -rf "$RT_SAVE"; cp -R "$SEED" "$RT_SAVE"
BIN="$BIN" RUN_SECS="${RUN_SECS:-1500}" bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s); LOGF=""
for ((i=0;i<40;i++)); do LOGF=$(sed -n 's/^log: //p' "$B/run_out.txt" 2>/dev/null | head -1); [ -n "$LOGF" ] && break; sleep 0.25; done
[ -n "$LOGF" ] || { echo "no log path from run_mac.sh"; exit 1; }
V="$B/VERDICT.txt"; : > "$V"; FAIL=0; N=0
say(){ echo "[stg360] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; sleep "${2:-0.6}"; say "pad $1"; }
waitnew(){ local pat="$1" n=$(( ${2:-10}*2 )) i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -a -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
shot(){ N=$((N+1)); sleep 0.3; local f; f=$(printf '%s/shot_%02d_%s.png' "$B" "$N" "$1"); cp "$B/png/nvk_last.png" "$f" 2>/dev/null && say "shot $(basename "$f")" || say "no frame for $1"; }
subf(){ grep -a -o 'submit f[0-9]*' "$LOGF" | tail -1 | tr -dc 0-9; }
finish(){ sleep 1; kill $FIRER 2>/dev/null; echo 0 > "$FIFO"; pkill -x "$PN" 2>/dev/null; sleep 2; cp "$LOGF" "$B/guest.log"; local L="$B/guest.log"
  { echo "tag=$TAG stage=$STAGE diff=${DIFF:-0} wall=$(( $(date +%s)-T0 ))s"
    echo "FATAL=$(grep -a -c FATAL "$L") VKERR=$(grep -a -c 'VK_ERROR\|VUID' "$L") DROPOUT=$(grep -a -c DROPOUT-CONFIRMED "$L") SLOW=$(grep -a -c '\[slowframe\]' "$L") UNDERRUN_NONZERO=$(grep -a '\[starve\]' "$L" | grep -a -vc 'underruns=0 (total=0)')"
    echo "census_distinct_bases: $(grep -a 'DROPOUT-CONFIRMED' "$L" | grep -a -o 'base=0x[0-9A-Fa-f]*' | sort | uniq -c | tr '\n' ' ')"
    echo "BGM first-seen: $(grep -a -o 'BGM cue[0-9]* ([a-z0-9_]*)' "$L" | awk '!s[$0]++' | tr '\n' ';')"
    echo "trainprobe msg18: $(grep -a 'trainprobe\] msg=18' "$L" | head -1 | cut -c1-140)"
    echo "nav360 lines: $(grep -a -c '\[nav360\]' "$L")"; } > "$B/facts.txt"
  nf=$(grep -a -c 'FATAL\|VK_ERROR\|VUID' "$L"); [ "$nf" = 0 ] && echo "PASS no FATAL/VK_ERROR" >> "$V" || { echo "FAIL $nf FATAL/VK_ERROR lines" >> "$V"; FAIL=1; }
  [ $FAIL = 0 ] && echo "VERDICT PASS" >> "$V" || echo "VERDICT FAIL" >> "$V"; say "DONE -> $B"; cat "$V" "$B/facts.txt"; exit $FAIL; }
step(){ local name="$1" pad="$2" pat="$3" to="$4" st="$5" gap="${6:-0.6}"
  mark; [ "$pad" != "-" ] && press "$pad" "$gap"
  if [ "$pat" = "-" ]; then say "node $name (no marker)"
  elif waitnew "$pat" "$to"; then say "PASS $name"; echo "PASS $name" >> "$V"
  else say "TIMEOUT $name ($pat)"; echo "FAIL $name (no '$pat' in ${to}s)" >> "$V"; FAIL=1; shot "${name}_FAIL"; finish; fi
  sleep "$st"; }

# ---- shell + 360 module to the HUB (nav360_mac.sh nodes 0-6, identical) ----
mark; step shell_title - "name='motion/title.lzx'" 60 4
# the title ignores START until it has finished loading (marker = load REQUEST, 3-13 s before it is ready): press START every 4 s until the top-menu BGM
mark; ok=0; for try in 1 2 3 4 5 6 7 8; do press 10 0.2; waitnew 'SYS_BGM cue0 (mushifuta_Menu02)' 4 && { ok=1; break; }; done
if [ $ok = 1 ]; then say "PASS top_menu (START try $try)"; echo "PASS top_menu" >> "$V"; else say "TIMEOUT top_menu"; echo "FAIL top_menu" >> "$V"; FAIL=1; shot top_menu_FAIL; finish; fi
sleep 3
step card_panel 1000 'SYS_SE cue1 (SE_OK01)' 10 2 0.2
step card_x360 4 '-' 0 3.6 0.2
step decide_x360 1000 '\[modswap\] #2 DONE' 120 0 0.2
step x360_title - '\[nav360\] D=0x60 st=3 ' 120 6
step hub 10 '\[p0build\] menu_game_title' 15 3 0.2
# ---- hub DOWN x2 -> TRAINING ----
step hub_down1 2 '\[mcur\] .*cursor 0->1' 5 1.5
step hub_down2 2 '\[mcur\] .*cursor 1->2' 5 1.5
shot hub_training_cursor
step training_open 1000 '96660(load)' 15 3 0.2
shot panel_open
# ---- DIFF (optional, default 0 = Original = unchanged behaviour): TRAINING panel row 1 "Mode" = Original/Maniac/Ultra: DOWN, RIGHT x DIFF, UP ----
DIFF="${DIFF:-0}"
if [ "$DIFF" -gt 0 ]; then press 2; for ((d=0;d<DIFF;d++)); do press 8; done; shot opt_mode_diff$DIFF; press 1; fi
# ---- option recipe: Shot Power Max, Bomb Stock Inf, Player Stock Inf, back to row 0, Stage k ----
for _ in 1 2 3; do press 2; done; for _ in 1 2 3 4 5 6 7 8; do press 8; done; shot opt_shotpower
press 2; for _ in 1 2 3 4 5 6 7 8; do press 8; done; shot opt_bomb
press 2; for _ in 1 2 3 4 5 6 7; do press 8; done; shot opt_player
for _ in 1 2 3 4 5; do press 1; done
for ((k=1;k<STAGE;k++)); do press 8; press 8; done
sleep 1; shot panel_configured
# ---- start: A (dialog) then A -> stage entry ----
mark; press 1000 0.2; waitnew 'dclose.*vt=0x82050F00' 8 && say "dclose seen" || say "no dclose marker (continuing)"; sleep 1; shot after_A1
mark; press 1000 0.2
if waitnew '\[nav360\] D=0x60 st=5 d76=4 ' 90; then say "PASS stage${STAGE}_entry (d76=4)"; echo "PASS entry stage$STAGE" >> "$V"; else say "TIMEOUT entry"; echo "FAIL entry stage$STAGE" >> "$V"; FAIL=1; shot entry_FAIL; finish; fi
ENTRYMARK=$(wc -l < "$LOGF" | tr -d ' '); TE=$(date +%s); FE=$(subf); say "ENTRY f=$FE"
# the stage BGM cue prints at d76=3 (before d76=4): look in the whole log since the training press
grep -a -o 'BGM cue[0-9]* ([a-z0-9_]*)' <(tail -n +"$((MARK))" "$LOGF") | tr '\n' ' ' > "$B/entry_cues.txt"; say "cues since A2: $(cat "$B/entry_cues.txt")"
sleep 4; shot entry_plus4
# ---- autofire (A 0.2 s on/off, A+B every 10th) in the background ----
firer(){ local n=0 p; while :; do n=$((n+1)); p=1000; [ $((n%10)) -eq 0 ] && p=3000; echo "$p" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; sleep 0.2; done; }
BOSS=0; BOSST=""; END=0; LASTSHOT=0; BOSSF=""; ENDT=0; ENDF=""
# 360 has NO boss-defeat [fade] line (ARCADE route C's stop marker): the autofire runs until d76=8 is seen (0.2 s poll on the log tail) and is
# killed AT ONCE (a stray A after the stage end lands on the re-opened training panel = restarts training). Boss = [cue] boss BGM or the
# [cuetally] BGM cue2= (m03_boss, stages 1-4) / cue10= (m11_lbs1, stage 5) -- the 48-line [cue] detail cap hides the boss [cue] line.
firer & FIRER=$!
while :; do
  now=$(date +%s); el=$((now-TE))
  [ $el -gt "${STAGECAP:-900}" ] && { say "STAGE CAP ${STAGECAP:-900}s hit"; break; }
  pgrep -x "$PN" >/dev/null || { say "PROCESS GONE"; echo "FAIL process gone" >> "$V"; FAIL=1; break; }
  for ((q=0;q<8;q++)); do
    if tail -n 400 "$LOGF" | grep -a -q '\[nav360\] D=0x60 st=5 d76=8 '; then END=1; break; fi; sleep 0.2; done
  if [ $END = 1 ]; then ENDMARK=$(wc -l < "$LOGF" | tr -d ' '); kill $FIRER 2>/dev/null; wait $FIRER 2>/dev/null; echo 0 > "$FIFO"; ENDT=$(( $(date +%s)-TE )); ENDF=$(subf); say "STAGE END d76=8 at +${ENDT}s f=$ENDF (autofire killed)"; break; fi
  if [ $BOSS = 0 ]; then bc=$(tail -n +"$((ENTRYMARK+1))" "$LOGF" | grep -a -o 'm03_boss\|m11_lbs1\|m12_lbs2\|BGM cue2=[0-9]*\|BGM cue10=[0-9]*\|BGM cue12=[0-9]*' | head -1)
    if [ -n "$bc" ]; then BOSS=1; BOSST=$el; BOSSF=$(subf); say "BOSS BGM at +${el}s f=$BOSSF ($bc)"; shot boss; fi; fi
  gap=30; [ $BOSS = 1 ] && gap=5   # after the boss BGM: a shot every 5 s so the boss-defeat / results tally is caught
  if [ $((el-LASTSHOT)) -ge $gap ]; then LASTSHOT=$el; shot "play_${el}s"; fi
done
kill $FIRER 2>/dev/null; wait $FIRER 2>/dev/null; echo 0 > "$FIFO"
[ $BOSS = 1 ] && echo "PASS boss stage$STAGE (+${BOSST}s)" >> "$V" || { echo "FAIL boss stage$STAGE not reached" >> "$V"; FAIL=1; }
[ $END = 1 ] && echo "PASS results/stage end stage$STAGE (+${ENDT}s, d76=8)" >> "$V" || { echo "FAIL stage end stage$STAGE not reached" >> "$V"; FAIL=1; }
if [ $END = 1 ]; then
  sleep 0.5; shot results_plus0_5; sleep 1.5; shot results_plus2
  say "frames: entry f=$FE end f=$ENDF over ${ENDT}s wall"
  MARK=$ENDMARK; waitnew '96660(load)#2' 20 && { say "PASS training panel re-opened (96660(load)#2)"; echo "PASS panel reopen" >> "$V"; } || { say "no panel re-open marker"; echo "NOTE no panel reopen marker" >> "$V"; }
  sleep 3; shot panel_reopened
  press 2000 0.2; say "B on the re-opened panel -> hub (no new [p0build]: the hub is already built under the panel; asserted by shot)"; echo "NOTE return hub by shot" >> "$V"
  sleep 3; shot hub_after
fi
finish
