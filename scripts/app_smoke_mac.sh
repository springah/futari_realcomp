#!/bin/bash
# app_smoke_mac.sh [APP] -- the BUNDLE smoke (beta 3 todo item 4): launches the .app the way a tester does (LaunchServices,
# `open -a`), drives it through the pad FIFO (title -> top menu -> card panel -> ARCADE -> hub -> back to the top menu),
# quits it through the app's own Quit (SDL_EVENT_QUIT), then checks: the session log landed in ~/Library/Logs, the save
# landed in ~/Library/Application Support, both modules bound, no FATAL; relaunches and checks the save is read back.
# The pad FIFO reaches a LaunchServices-started process through launchctl setenv (cleared again at the end).
#   bash scripts/app_smoke_mac.sh "$HOME/Desktop/projects/Futari Realcomp.app"
set -u
cd "$(dirname "$0")/.."
APP="${1:-$HOME/Desktop/projects/Futari Realcomp.app}"
[ -x "$APP/Contents/MacOS/Futari Realcomp" ] || { echo "no launcher in $APP"; exit 2; }
LOGS="$HOME/Library/Logs/Futari Realcomp"; SAVE="$HOME/Library/Application Support/Futari Realcomp/save"
FIFO=/tmp/futari_pad_app; echo 0 > "$FIFO"
pkill -f "Contents/MacOS/futari_merged" 2>/dev/null; sleep 1
FAIL=0; say(){ echo "[app] $*"; }
press(){ echo "$1" > "$FIFO"; sleep 0.25; echo 0 > "$FIFO"; say "pad $1"; }
waitlog(){ local pat="$1" n="${2:-40}" i; for ((i=0;i<n;i++)); do grep -q "$pat" "$LOG" 2>/dev/null && { say "marker: $pat"; return 0; }; sleep 0.5; done; say "TIMEOUT: $pat"; FAIL=1; return 1; }
launch(){ # $1 = tag
  PREV=$(ls -t "$LOGS"/futari_*.log 2>/dev/null | head -1)
  launchctl setenv RT_PAD_HOST_FIFO "$FIFO"
  open -a "$APP" || { say "open failed"; exit 1; }
  for ((i=0;i<40;i++)); do LOG=$(ls -t "$LOGS"/futari_*.log 2>/dev/null | head -1); [ -n "$LOG" ] && [ "$LOG" != "$PREV" ] && break; sleep 0.5; done
  [ -n "$LOG" ] && [ "$LOG" != "$PREV" ] || { say "no new log in $LOGS"; FAIL=1; return 1; }
  say "$1: log $LOG"
  waitlog "name='motion/title.lzx'" 120; sleep 4
}
quit(){ osascript -e 'tell application "Futari Realcomp" to quit' >/dev/null 2>&1; for ((i=0;i<20;i++)); do pgrep -f "Contents/MacOS/futari_merged" >/dev/null || break; sleep 0.5; done
  if pgrep -f "Contents/MacOS/futari_merged" >/dev/null; then say "FAIL: engine still running after Quit"; FAIL=1; pkill -f "Contents/MacOS/futari_merged"; else say "quit clean (no process left)"; fi; }

say "== launch 1: fresh"
launch first || exit 1
press 10; waitlog "SYS_BGM cue0 (mushifuta_Menu02)"; sleep 3
press 1000; waitlog "SYS_SE cue1 (SE_OK01)"; sleep 3.6   # the card panel honours no decide for 3.0 s (NAV_MAP)
press 1000; waitlog "\[modeidx\] .*ARCADE"; sleep 3
press 1000; waitlog "\[p0build\] menu_game_title" 60; sleep 2
press 2000; sleep 2; press 1000; waitlog "\[decide\].*item=-1\|vt=0x82050518" 30; sleep 4
quit
grep -q "2/2 module DLL(s) bound" "$LOG" && say "PASS both modules bound" || { say "FAIL modules not both bound"; FAIL=1; }
[ "$(grep -c FATAL "$LOG")" = 0 ] && say "PASS no FATAL" || { say "FAIL FATAL in log"; FAIL=1; }
grep -q "window closed by user\|SDL_EVENT_QUIT\|RETURNED" "$LOG" && say "PASS clean exit logged" || say "note: no exit marker in log"
ls "$SAVE"/435A07D7/00000001/systemdata.bin/savegame.bin >/dev/null 2>&1 && say "PASS save written under Application Support" || { say "FAIL no savegame.bin under $SAVE"; FAIL=1; }

say "== launch 2: the save must be read back"
launch second || exit 1
press 10; waitlog "SYS_BGM cue0 (mushifuta_Menu02)"; sleep 2
grep -q "existed=1" "$LOG" && say "PASS save read back (existed=1)" || { say "FAIL save not found on relaunch"; FAIL=1; }
quit
launchctl unsetenv RT_PAD_HOST_FIFO
[ $FAIL = 0 ] && echo "APP SMOKE: PASS" || echo "APP SMOKE: FAIL"
exit $FAIL
