#!/bin/bash
# nav360_mac.sh <tag> [BIN] -- the XBOX 360 MODE marker-asserted route on the Mac (RC1 Q2, docs/NAV_MAP.md
# "XBOX 360 MODE" section). Every node = one press (or none) + the log marker that proves the screen + a screenshot.
#
#   cold boot -> shell title -> TOP MENU -> card panel -> LEFT (Xbox 360 card) -> decide -> module swap #2
#   -> 360 module title -> START -> HUB -> NORMAL PLAY -> 1P SIDE START -> MODE SELECT -> CHARACTER -> SHOT
#   -> STAGE 1 -> PAUSE (START) -> RESUME (A on RESUME) -> play -> PAUSE -> RETURN TO TITLE (DOWNx3, A, A)
#   -> 360 module title -> START -> HUB -> B -> "return to top menu?" A -> shell TOP MENU
#
#   bash scripts/nav360_mac.sh r1 build/w152_q2/w152_q2
#   bank: _local/rc1/q2/<tag>/{shot_NN_<node>.png, guest.log, steps.txt, VERDICT.txt}  (BANK=<dir> overrides)
#   STRICT=1 (default) stops at the first node whose marker times out; STRICT=0 records the TIMEOUT and goes on.
#   The process is killed with `pkill -x <basename BIN>` ONLY -- give the binary a unique name (cp the host).
#   DRIVE LOCK (project rule): mkdir /tmp/futari_drive.lock before launch (waits up to LOCKWAIT s, default 9000,
#   in 60 s steps), rmdir on exit. NOLOCK=1 skips it (only when the caller already holds the lock).
# Markers: the shell-side instruments ([mstate]/[mcur]/[decide]/[p0build]/[modswap]/[gemsg]/[cue]) are
# module-agnostic and hold in the 360 module unchanged; the module-side [navreal] cluster does NOT (reco_normal
# .data addresses, +0x60 in reco_abnormal) -- RT_NAV360=1 is the dshift-aware twin and is set here.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:-build/w152_q2/w152_q2}"; PN="$(basename "$BIN")"
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
B="${BANK:-_local/rc1/q2/$TAG}"; rm -rf "$B"; mkdir -p "$B/png"
FIFO="${FIFO:-/tmp/futari_pad_q2}"; echo 0 > "$FIFO"
STRICT="${STRICT:-1}"; LOCK=/tmp/futari_drive.lock
if [ "${NOLOCK:-0}" != 1 ]; then
  w=0; until mkdir "$LOCK" 2>/dev/null; do [ $w -ge "${LOCKWAIT:-9000}" ] && { echo "lock busy ${w}s -- giving up"; exit 3; }; sleep 60; w=$((w+60)); done
  trap 'pkill -x "$PN" 2>/dev/null; sleep 1; rmdir "$LOCK" 2>/dev/null' EXIT
else trap 'pkill -x "$PN" 2>/dev/null' EXIT; fi
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG="${NVKPNG:-30}" RVK_DUMPDIR="$PWD/$B/png"
# NOLEVER=1 = the RT_NAV360 inertness run: lever unset, module-side [nav360] markers replaced by shell-side ones / screen-only
[ "${NOLEVER:-0}" = 1 ] && unset RT_NAV360 || export RT_NAV360=1
if [ "${NOLEVER:-0}" = 1 ]; then M_TITLE='-'; S_TITLE=14; M_MODE='-'; M_GO='BGM cue1 (m02_stg1)'; else S_TITLE=6; M_TITLE='\[nav360\] D=0x60 st=3 '; M_MODE='\[nav360\] D=0x60 st=5 d76=2 field=1 .*slot0=1'; M_GO='\[nav360\] D=0x60 st=5 d76=4 '; fi
# SAVE SEED: a FRESH save dir puts a "save data not found -- create?" dialog (A) + "created" (A) over the shell title
# (SYS_SE cue6 SE_OK02) and desyncs every later press; each run therefore starts from a COPY of a known save.
export RT_SAVE="${RT_SAVE:-_local/saves/save_q2_$TAG}"; SEED="${SEED:-_local/saves/save_rc1_rc1m_x360}"
[ -d "$SEED" ] || { echo "no save seed $SEED"; exit 2; }; rm -rf "$RT_SAVE"; cp -R "$SEED" "$RT_SAVE"
BIN="$BIN" RUN_SECS="${RUN_SECS:-600}" bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s); LOGF=""
for ((i=0;i<40;i++)); do LOGF=$(sed -n 's/^log: //p' "$B/run_out.txt" 2>/dev/null | head -1); [ -n "$LOGF" ] && break; sleep 0.25; done
[ -n "$LOGF" ] || { echo "no log path from run_mac.sh"; exit 1; }
V="$B/VERDICT.txt"; : > "$V"; FAIL=0; N=0
say(){ echo "[nav360] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; say "pad $1"; }
waitnew(){ local pat="$1" n=$(( ${2:-10}*2 )) i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
shot(){ N=$((N+1)); sleep 0.3; local f; f=$(printf '%s/shot_%02d_%s.png' "$B" "$N" "$1"); cp "$B/png/nvk_last.png" "$f" 2>/dev/null && say "shot $(basename "$f")" || say "no frame for $1"; }
# node <name> <pad|-> <marker regex> <timeout s> <settle s>  -- press, assert the marker, settle, screenshot
node(){ local name="$1" pad="$2" pat="$3" to="$4" st="$5"
  mark; [ "$pad" != "-" ] && press "$pad"
  if [ "$pat" = "-" ]; then say "node $name (no marker; screen only)"
  elif waitnew "$pat" "$to"; then say "PASS $name  ($pat)"; echo "PASS $name" >> "$V"
  else say "TIMEOUT $name  ($pat)"; echo "FAIL $name (no '$pat' in ${to}s)" >> "$V"; FAIL=1
       [ "$STRICT" = 1 ] && { shot "${name}_FAIL"; finish; }; fi
  sleep "$st"; shot "$name"; }
finish(){ sleep 1; pkill -x "$PN" 2>/dev/null; sleep 2; cp "$LOGF" "$B/guest.log"
  local nf; nf=$(grep -c 'FATAL\|VK_ERROR' "$B/guest.log"); [ "$nf" = 0 ] && echo "PASS no FATAL/VK_ERROR" >> "$V" || { echo "FAIL $nf FATAL/VK_ERROR lines" >> "$V"; FAIL=1; }
  [ $FAIL = 0 ] && echo "VERDICT PASS" >> "$V" || echo "VERDICT FAIL" >> "$V"; say "DONE -> $B"; cat "$V"; exit $FAIL; }

# ---- shell: title -> top menu -> card panel -> Xbox 360 card -> decide (NAV_MAP CARD PANEL law) ----
mark; node shell_title     -     "name='motion/title.lzx'"                 60 4
node top_menu              10    'SYS_BGM cue0 (mushifuta_Menu02)'         10 3
node card_panel            1000  'SYS_SE cue1 (SE_OK01)'                   10 2
node card_x360             4     '-'                                       0  3.6     # no marker (SE cue logs print once per run); 3.0 s dwell gate before decide
node decide_x360           1000  '\[modswap\] #2 DONE'                     120 0      # [modeidx] ... XBOX-360 precedes it (checked below)
grep -q '\[modeidx\] .*XBOX-360' "$LOGF" && echo "PASS modeidx XBOX-360" >> "$V" || { echo "FAIL no [modeidx] XBOX-360" >> "$V"; FAIL=1; }
# ---- 360 module: cold boot to its title/attract ([nav360] st=3 = the module's title/attract scene FSM) ----
node x360_title            -     "$M_TITLE"                 120 $S_TITLE
node hub                   10    '\[p0build\] menu_game_title'              15 3
node hub_cursor_np         2     '\[mcur\] .*cursor 0->1'                  5  0.5
node np_submenu            1000  '\[decide\] .*item=1 '                    5  3
# ---- 1P SIDE START -> selects: PRESS CADENCE MATTERS -- the triage's ~4 s spacing reached stage 1; r2's ~13 s spacing
#      ended in the replay-save prompt (d76 4->5->6->8, slot0 1->0, st 5->2) -- see NAV_MAP 360 section ----
node mode_select           1000  "$M_MODE" 10 3
node char_select           1000  '-'                                       0  3
node shot_select           1000  '-'                                       0  3
node stage1_go             1000  "$M_GO"           10 0
# the stage BGM cue prints at d76=3 (BEFORE d76=4), i.e. inside stage1_go's window -- MARK still holds that node's start
if tail -n +"$((MARK+1))" "$LOGF" | grep -q 'BGM cue1 (m02_stg1)'; then say "PASS stage1  (BGM cue1 m02_stg1)"; echo "PASS stage1" >> "$V"
else say "TIMEOUT stage1 (no m02_stg1 cue)"; echo "FAIL stage1 (no m02_stg1 cue)" >> "$V"; FAIL=1; [ "$STRICT" = 1 ] && { shot stage1_FAIL; finish; }; fi
sleep 3; shot stage1
grep -q 'GameEntry(msg=10,' <(tail -n +"$MARK" "$LOGF") && { echo "FAIL stage1 ended at once (msg=10 = replay-save prompt)" >> "$V"; FAIL=1; }
# ---- pause / resume (resume = A on RESUME, cursor 0; START does NOT resume) ----
node pause                 10    'BA4D8(ACTIVE).*vt=0x82050488 .*cursor=0 state 0x82061D50->0x82061D50' 10 2
node resume                1000  'BA4D8(ACTIVE).*vt=0x82050488 .*cursor=0 state 0x82061D50->0x82061D70' 10 4
sleep 5; shot resumed_plus5s
# ---- pause again -> RETURN TO TITLE (DOWN x3, A, confirm A) ----
node pause2                10    'BA4D8(ACTIVE).*vt=0x82050488 .*cursor=0 state 0x82061D50->0x82061D50' 10 2
node pause_down1           2     '-'                                       0  1.2     # in-stage pause model has no [mcur]; cursor asserted at rtt_confirm (cursor=3)
node pause_down2           2     '-'                                       0  1.2     # in-stage pause model has no [mcur]; cursor asserted at rtt_confirm (cursor=3)
node pause_down3           2     '-'                                       0  1.2     # in-stage pause model has no [mcur]; cursor asserted at rtt_confirm (cursor=3)
node rtt_confirm           1000  'BA4D8(ACTIVE).*cursor=3 state 0x82061D50->0x82061D70' 10 2
# RETURN TO TITLE lands DIRECTLY on the rebuilt hub (GameEntry(msg=11), st 5->2, [p0build] menu_game_title#2), not on the module title
node rtt_yes               1000  '\[p0build\] menu_game_title'              25 4
node hub_back              2000  '\[decide\] .*item=-1'                    10 2
node shell_top_menu        1000  'vt=0x82050518'                           20 3
finish
