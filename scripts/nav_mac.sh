#!/bin/bash
# nav_mac.sh <tag> [BIN] -- <step>...   generic marker-driven menu navigation on the Mac, with screenshots.
#
# Boots the shell, waits for the title, then executes the steps. A step is one of:
#   <pad>            press a pad word through the host FIFO (10=START 1000=A 2000=B 1=UP 2=DOWN 4=LEFT 8=RIGHT)
#   w:<regex>        wait (<= 10 s) for a NEW log line matching the regex since the previous step
#   W:<regex>        the same with a 120 s ceiling (module boots: the XBOX 360 module's cold boot is ~40 s)
#   s:<secs>         sleep
#   shot             copy the renderer's current frame (RVK_DUMPDIR/nvk_last.png) to $B/shot_<n>.png
#   hub              the proven route TITLE -> HUB (START, A, A, A with their markers)
#   log:<regex>      print every new log line matching the regex since the previous step (grep -c too)
# Bank: _local/nav_mac/<tag>/{shot_N.png, guest.log, steps.txt}. Same FIFO/marker machinery as boss1_drive_mac.sh.
#   bash scripts/nav_mac.sh opt1 build/futari_merged -- hub 2 2 2 2 'w:mcur' 1000 's:3' shot 'log:p0build'
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; shift
BIN="build/futari_merged"; if [ "${1:-}" != "--" ]; then BIN="$1"; shift; fi; [ "${1:-}" = "--" ] && shift
B="_local/nav_mac/$TAG"; rm -rf "$B"; mkdir -p "$B/png"
FIFO=/tmp/futari_pad_nav; echo 0 > "$FIFO"
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG="${NVKPNG:-30}" RVK_DUMPDIR="$PWD/$B/png"
pkill -f "build/ctl_\|build/futari_merged\|build/plate_" 2>/dev/null; sleep 1
PREVLOG=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1)
BIN="$BIN" RUN_SECS="${RUN_SECS:-240}" bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s)
LOGF=""; for ((i=0;i<60;i++)); do L=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1); [ -n "$L" ] && [ "$L" != "$PREVLOG" ] && { LOGF="$L"; break; }; sleep 0.5; done
[ -n "$LOGF" ] || { echo "no new log"; exit 1; }
say(){ echo "[nav] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; say "pad $1"; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
waitnew(){ local pat="$1" n="${2:-20}" i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -q "$pat" && { say "marker: $pat"; return 0; }; sleep 0.5; done; say "TIMEOUT: $pat"; return 1; }
step(){ local pad="$1" pat="$2" settle="${3:-1}" try; for try in 1 2; do mark; press "$pad"; waitnew "$pat" && { sleep "$settle"; return 0; }; say "retry"; done; return 1; }
N=0
for ((i=0;i<60;i++)); do grep -q "name='motion/title.lzx'" "$LOGF" && break; sleep 1; done; say "title loaded"; sleep 4
for st in "$@"; do
  case "$st" in
    hub) step 10 'SYS_BGM cue0 (mushifuta_Menu02)' 4; step 1000 'SYS_SE cue1 (SE_OK01)' 3; step 1000 '\[modeidx\] .*ARCADE' 3; step 1000 '\[p0build\] menu_game_title' 2; say "HUB";;
    w:*) waitnew "${st#w:}";;
    W:*) waitnew "${st#W:}" 240;;
    s:*) sleep "${st#s:}";;
    shot) N=$((N+1)); sleep 0.3; cp "$B/png/nvk_last.png" "$B/shot_$N.png" 2>/dev/null && say "shot_$N.png" || say "no frame yet";;
    log:*) say "log lines matching ${st#log:} since last step:"; tail -n +"$((MARK+1))" "$LOGF" | grep "${st#log:}" | head -40 | sed 's/^/      /' | cut -c1-160;;
    *) mark; press "$st"; sleep 0.8;;
  esac
done
sleep 1; pkill -x "$(basename "$BIN")" 2>/dev/null; sleep 1; cp "$LOGF" "$B/guest.log"; say "DONE -> $B"
