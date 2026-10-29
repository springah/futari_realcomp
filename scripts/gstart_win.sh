#!/bin/bash
# WINDOWS PORT -- generated from scripts/gstart_mac.sh by scripts/win_port.sh (2026-10-29); edit the Mac original and regenerate. Differences: win_shim.sh
# (pkill/pgrep/ps/md5), run_win.sh as the launcher, /c/tmp for the FIFO + drive lock. Engine copy: a uniquely named .exe beside the module DLLs.
# gstart_mac.sh <tag> <BIN> [x360]  -- RC1 G-START repro: does a pad press made while a SHELL menu has the screen
# reach the game module ticking behind it?  Boots, goes TITLE -> TOP MENU -> card (ARCADE, or Xbox 360 with x360)
# -> HUB, then probes each button on the HUB and inside the OPTION submenu and prints, per press, the module-side
# [navreal]/[nav360] deltas, [startwire] fires and [cb2gate] transitions since the press. A leak = any st/d76/cred
# change (or a [startwire] fire) while the shell menu stays up.
#   NOGATE=1 -> RT_STARTWIRE_NOGATE=1 (the pre-fix ungated START wire = the bug arm).  HUBSTART=1 -> START on the hub root first.
# Lock: mkdir /c/tmp/futari_drive.lock (60 s retry, LOCKWAIT s), rmdir on exit; kills only `pkill -x <basename BIN>`.
set -u
source "$(dirname "$0")/win_shim.sh"   # Windows: pkill/pgrep/ps/md5 shims, /c/tmp
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?bin}"; MODE="${3:-arcade}"; PN="$(basename "$BIN")"
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
B="_local/gstart/$TAG"; rm -rf "$B"; mkdir -p "$B/png"
FIFO=/c/tmp/futari_pad_gstart; echo 0 > "$FIFO"; LOCK=/c/tmp/futari_drive.lock
w=0; until mkdir "$LOCK" 2>/dev/null; do [ $w -ge "${LOCKWAIT:-7200}" ] && { echo "lock busy ${w}s"; exit 3; }; sleep 60; w=$((w+60)); done
trap 'pkill -x "$PN" 2>/dev/null; sleep 1; rmdir "$LOCK" 2>/dev/null' EXIT
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG=30 RVK_DUMPDIR="$PWD/$B/png" RT_NAV360=1
[ "${NOGATE:-0}" = 1 ] && export RT_STARTWIRE_NOGATE=1
export RT_SAVE="_local/saves/save_gstart_$TAG"; rm -rf "$RT_SAVE"; cp -R _local/saves/save_rc1_rc1m_x360 "$RT_SAVE"
BIN="$BIN" RUN_SECS="${RUN_SECS:-300}" bash scripts/run_win.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s); LOGF=""
for ((i=0;i<40;i++)); do LOGF=$(sed -n 's/^log: //p' "$B/run_out.txt" 2>/dev/null | head -1); [ -n "$LOGF" ] && break; sleep 0.25; done
[ -n "$LOGF" ] || { echo "no log"; exit 1; }
say(){ echo "[gstart] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; }
waitnew(){ local pat="$1" n=$(( ${2:-10}*2 )) i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
step(){ local pad="$1" pat="$2" to="${3:-10}" st="${4:-2}"; mark; press "$pad"; if waitnew "$pat" "$to"; then say "ok pad $pad ($pat)"; else say "TIMEOUT pad $pad ($pat)"; fi; sleep "$st"; }
N=0; shot(){ N=$((N+1)); sleep 0.3; cp "$B/png/nvk_last.png" "$(printf '%s/shot_%02d_%s.png' "$B" "$N" "$1")" 2>/dev/null; }
# probe <screen> <pad> <name>: press, dwell 4 s, report module deltas since the press
probe(){ local scr="$1" pad="$2" nm="$3"; mark; press "$pad"; sleep 4
  local d; d=$(tail -n +"$((MARK+1))" "$LOGF" | grep -E '\[navreal\] (st|d76)|\[nav360\].*(st|d76) [0-9-]+->|\[startwire\]|\[cb2gate\]|\[decide\]|GameEntry\(msg=(1[0-9]|[0-9]),' | grep -v 'msg=5' | head -12)
  local leak=NO; echo "$d" | grep -qE '\[navreal\]|\[nav360\].*->|\[startwire\]' && leak=YES
  say "PROBE $scr x $nm -> LEAK=$leak"; [ -n "$d" ] && echo "$d" | sed 's/^/        /' | tee -a "$B/steps.txt"
  echo "$scr $nm $leak" >> "$B/TABLE.txt"; shot "${scr}_${nm}"; }
for ((i=0;i<60;i++)); do grep -q "name='motion/title.lzx'" "$LOGF" && break; sleep 1; done; say "title"; sleep 4
step 10 'SYS_BGM cue0 (mushifuta_Menu02)' 10 3
step 1000 'SYS_SE cue1 (SE_OK01)' 10 3
if [ "$MODE" = x360 ]; then press 4; sleep 3.6; step 1000 'modswap\] #2 DONE' 120 6
  for ((i=0;i<120;i++)); do tail -n +"$((MARK+1))" "$LOGF" | grep -q 'GameEntry(msg=15,' && break; sleep 1; done; sleep 6
  step 10 '\[p0build\] menu_game_title' 15 3
else step 1000 '\[modeidx\] .*ARCADE' 10 3; step 1000 '\[p0build\] menu_game_title' 15 3; fi
say "HUB"; shot hub; sleep 2
grep -E '\[navreal\]|\[nav360\].*->' "$LOGF" | tail -3 | sed 's/^/   pre-probe module state: /' | tee -a "$B/steps.txt"
[ "${HUBSTART:-0}" = 1 ] && probe hub 10 START   # HUBSTART=1: START on the hub root first (a leak there contaminates later probes)
probe hub 2 DOWN; probe hub 1 UP
for k in 1 2 3 4; do mark; press 2; sleep 0.8; done
step 1000 'BA4D8(ACTIVE).*vt=0x82050440' 6 2; say "OPTION submenu"
probe option 10 START; probe option 2 DOWN; probe option 1000 A; probe option 2000 B
probe hub2 10 START
probe hub2 1000 A_open_submenu; probe sub 2000 B_back
sleep 1; pkill -x "$PN"; sleep 2; cp "$LOGF" "$B/guest.log"
say "DONE -> $B  FATAL=$(grep -c 'FATAL' "$B/guest.log")"; cat "$B/TABLE.txt"
