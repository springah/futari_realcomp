#!/bin/bash
# persist_mac.sh <tag> <arcade|x360> -- <step>...   RC1 Q3/Q4: marker-driven persistence + co-op legs on the Mac.
# One LEG = one launch (drive lock held for it, released on exit). Legs of one TEST share SAVE=<dir> (NO re-seed
# between legs: that is the persistence round-trip); SEED=<dir> copies a known save over SAVE first (leg 1 only).
# Steps (nav_mac.sh grammar + macros):
#   <pad>        P1 word through the host FIFO (10=START 1000=A 2000=B 1=UP 2=DOWN 4=LEFT 8=RIGHT)
#   p2:<word>    P2 word (FIFO 4th field, "0 0 0 <w>")
#   w:<re>  W:<re>  wait (<=10 s / 120 s) for a NEW log line matching <re> since the last press; a miss FAILS the leg
#   s:<secs>     sleep          shot[:name]   copy the current frame     log:<re>  print new matching lines
#   boot_hub     title -> top menu -> card panel -> (LEFT for x360) -> decide -> [module boot] -> HUB  (marker-asserted)
#   hub_to_top   hub B -> item=-1 -> A -> shell TOP MENU (vt=0x82050518)
#   sd:<name>    snapshot the save dir (find/md5) into $B/save_<name>.txt     (diff-able across legs)
# Bank: _local/rc1/q3/<tag>/{shot_NN_*.png, guest.log, steps.txt, VERDICT.txt}. Own binary build/q3_run/futari_q3 (pkill -x).
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; MODE="${2:?arcade|x360}"; shift 2; [ "${1:-}" = "--" ] && shift
BIN="${BIN:-build/q3_run/futari_q3}"; PN="$(basename "$BIN")"; [ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
B="${BANK:-_local/rc1/q3/$TAG}"; rm -rf "$B"; mkdir -p "$B/png"
FIFO="${FIFO:-/tmp/futari_pad_q3}"; echo 0 > "$FIFO"; LOCK=/tmp/futari_drive.lock
w=0; until mkdir "$LOCK" 2>/dev/null; do [ $w -ge "${LOCKWAIT:-12600}" ] && { echo "lock busy ${w}s -- giving up"; exit 3; }; sleep 60; w=$((w+60)); done
echo "lockwait=${w}s" > "$B/lockwait.txt"
trap 'pkill -x "$PN" 2>/dev/null; sleep 1; rmdir "$LOCK" 2>/dev/null' EXIT
while pgrep -x futari_merged >/dev/null; do sleep 30; done      # never fight the user's .app / merged host
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG="${NVKPNG:-30}" RVK_DUMPDIR="$PWD/$B/png"
[ "$MODE" = x360 ] && export RT_NAV360=1
[ -n "${RT_PEEK_SET:-}" ] && export RT_PEEK="$RT_PEEK_SET"
[ "${JOINP:-0}" = 1 ] && export RT_JOINP=1
# CO-OP: the P2 pad word rides the RT_PAD_FIFO channel's 4th field ("0 0 0 <p2>") -- NOT the host FIFO (RT_PAD_HOST_FIFO ORs
# EVERY token into P1: "0 0 0 10" there is P1 START = pause). Q3 finding; shell/gen/stubs.cpp rt_fifo_buttons().
P2FIFO="${P2FIFO:-/tmp/futari_pad_q3p2}"; echo "0 0 0 0" > "$P2FIFO"; export RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="$P2FIFO"
export RT_SAVE="${SAVE:?SAVE=<dir>}"
if [ -n "${SEED:-}" ]; then [ -d "$SEED" ] || { echo "no seed $SEED"; exit 2; }; rm -rf "$RT_SAVE"; cp -R "$SEED" "$RT_SAVE"; fi
[ -d "$RT_SAVE" ] || { echo "no save dir $RT_SAVE (give SEED=)"; exit 2; }
BIN="$BIN" RUN_SECS="${RUN_SECS:-900}" bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s); LOGF=""
for ((i=0;i<40;i++)); do LOGF=$(sed -n 's/^log: //p' "$B/run_out.txt" 2>/dev/null | head -1); [ -n "$LOGF" ] && break; sleep 0.25; done
[ -n "$LOGF" ] || { echo "no log"; exit 1; }
V="$B/VERDICT.txt"; : > "$V"; FAIL=0; N=0
say(){ echo "[q3] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; say "pad $1"; }
press2(){ echo "0 0 0 $1" > "$P2FIFO"; sleep 0.3; echo "0 0 0 0" > "$P2FIFO"; say "pad2 $1"; }
waitnew(){ local pat="$1" n=$(( ${2:-10}*2 )) i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
shot(){ N=$((N+1)); sleep 0.3; local f; f=$(printf '%s/shot_%02d_%s.png' "$B" "$N" "${1:-s}"); cp "$B/png/nvk_last.png" "$f" 2>/dev/null && say "shot $(basename "$f")" || say "no frame for $1"; }
finish(){ sleep 1; pkill -x "$PN" 2>/dev/null; sleep 2; cp "$LOGF" "$B/guest.log"
  local nf; nf=$(grep -c 'FATAL\|VK_ERROR' "$B/guest.log"); [ "$nf" = 0 ] && echo "PASS no FATAL/VK_ERROR" >> "$V" || { echo "FAIL $nf FATAL/VK_ERROR lines" >> "$V"; FAIL=1; }
  [ $FAIL = 0 ] && echo "VERDICT PASS" >> "$V" || echo "VERDICT FAIL" >> "$V"; say "DONE -> $B"; cat "$V"; exit $FAIL; }
# W <label> <regex> <timeout>: assert marker after the last mark
need(){ if waitnew "$2" "$3"; then say "PASS $1 ($2)"; echo "PASS $1" >> "$V"; else say "TIMEOUT $1 ($2)"; echo "FAIL $1 (no '$2' in ${3}s)" >> "$V"; FAIL=1; shot "${1}_FAIL"; finish; fi; }
pstep(){ mark; press "$1"; }
snapdir(){ ( cd "$RT_SAVE" && find . -type f -exec md5 -r {} \; | sort -k2; find . -type f -exec ls -l {} \; | awk '{print $5, $9}' | sort -k2 ) > "$B/save_$1.txt"; say "save snapshot $1"; }
for ((i=0;i<120;i++)); do grep -q "name='motion/title.lzx'" "$LOGF" && break; sleep 0.5; done; say "title loaded (first-run save dialog? check shot)"; sleep 4
for st in "$@"; do
  case "$st" in
    boot_hub)
      pstep 10;   need top_menu 'SYS_BGM cue0 (mushifuta_Menu02)' 10; sleep 3
      pstep 1000; need card_panel 'SYS_SE cue1 (SE_OK01)' 10; sleep 2
      if [ "$MODE" = x360 ]; then mark; press 4; sleep 3.6; pstep 1000; need swap '\[modswap\] #2 DONE' 120
        grep -q '\[modeidx\] .*XBOX-360' "$LOGF" && echo "PASS modeidx XBOX-360" >> "$V" || { echo "FAIL no modeidx XBOX-360" >> "$V"; FAIL=1; }
        sleep 6; mark; press 10; need hub '\[p0build\] menu_game_title' 40; sleep 3
      else sleep 1.6; pstep 1000; need arcade_decide '\[modeidx\] .*ARCADE' 10; sleep 12
        for t in 1 2 3; do mark; press 10; waitnew '\[p0build\] menu_game_title' 12 && break; done; need hub '\[p0build\] menu_game_title' 1; sleep 3; fi;;
    hub_to_top) pstep 2000; need hub_back '\[decide\] .*item=-1' 10; sleep 2; pstep 1000; need top 'vt=0x82050518' 20; sleep 3;;
    p2:*) mark; press2 "${st#p2:}"; sleep 1.5;;
    w:*) tw=$(date +%s); if waitnew "${st#w:}" 10; then say "PASS ${st#w:} (+$(( $(date +%s)-tw ))s)"; else say "TIMEOUT ${st#w:}"; echo "FAIL wait ${st#w:}" >> "$V"; FAIL=1; shot wait_FAIL; finish; fi;;
    W:*) tw=$(date +%s); if waitnew "${st#W:}" 120; then say "PASS ${st#W:} (+$(( $(date +%s)-tw ))s)"; else say "TIMEOUT ${st#W:}"; echo "FAIL wait ${st#W:}" >> "$V"; FAIL=1; shot wait_FAIL; finish; fi;;
    s:*) sleep "${st#s:}";;
    shot|shot:*) n="${st#shot}"; shot "${n#:}";;
    sd:*) snapdir "${st#sd:}";;
    mark) mark;;
    alive) if pgrep -x "$PN" >/dev/null; then say "ALIVE $PN"; else say "EXITED $PN (app quit by itself)"; echo "INFO app exited on its own" >> "$V"; fi;;
    log:*) say "log ${st#log:}:"; tail -n +"$((MARK+1))" "$LOGF" | grep -- "${st#log:}" | head -40 | sed 's/^/      /' | cut -c1-200 | tee -a "$B/steps.txt";;
    *) mark; press "$st"; sleep 1.0;;
  esac
done
finish
