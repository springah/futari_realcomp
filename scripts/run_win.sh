#!/bin/bash
# run_win.sh -- the Windows twin of scripts/run_mac.sh: launch a host exe with the attended-session environment (the env set of
# "Futari 1.5.bat" / run_mac.sh), print `log: <path>` first (the gate scripts parse that line), optionally kill after RUN_SECS.
# Used by the *_win.sh gate scripts (generated from the *_mac.sh originals by scripts/win_port.sh). Keyboard: arrows, Z=A X=B C=X
# V=Y, Enter=START, RShift=BACK (GetAsyncKeyState: focus-independent on Windows); file-driven presses via RT_PAD_HOST_FIFO (set by
# the caller). Game data: assets/ (RT_GAME_ROOT) and the shell xex at assets/default.xex (XR_SHELL_XEX; shell/default.xex is the
# duplicate the launcher .bat uses).
#   RUN_SECS=<n>   kill after n seconds (default: run until the window closes)
#   RT_SAVE=...    override the save dir (default _local/saves/save_win, created fresh if absent)
#   BIN=<exe>      run a different executable (the gates pass a uniquely named copy of the staged engine)
set -u
cd "$(dirname "$0")/.."
BIN="${BIN:-build/futari_combined.exe}"
[ -x "$BIN" ] || { echo "no $BIN -- bash build_win_dll.sh first"; exit 2; }
[ -f assets/default.xex ] || { echo "no assets/default.xex -- see docs/DUMPING.md"; exit 2; }
mkdir -p _local/logs _local/saves
export RT_GAME_ROOT="$PWD/assets"
export XR_SHELL_XEX="${XR_SHELL_XEX:-assets/default.xex}"
export RT_SAVE="${RT_SAVE:-_local/saves/save_win}"; mkdir -p "$RT_SAVE"
STAMP=$(date +%Y%m%d_%H%M%S); LOG="_local/logs/win_$STAMP.log"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_AUDIO=1 RT_AUDIOWORKER=1 RT_AUDIOBRIDGE=1 RT_CUEBRIDGE=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0
export RVK_WINDOW=1 RVK_WINSIZE="${RVK_WINSIZE:-1280x720}" RVK_DIMFIX=1
export RT_NAVREAL=1 RT_STARTWIRE=1 RT_SNDQFREE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_PAD_HOST=1 RT_AUDIOXWMA=1   # keyboard via GetAsyncKeyState; xWMA SE/voice
export RT_TRAINPROBE=1                 # logs the shell->game training-flow payload ([trainprobe], two lines per launch; byte-inert)
export RT_SAMPLES="${RT_SAMPLES:-0}"   # 0 = attended: no hang sampler
export RT_NOXINPUT=1                   # gates: a real pad plugged into the PC must not steer the drive
echo "log: $LOG"
"$BIN" 8208A2B8 0 "$XR_SHELL_XEX" 2>"$LOG" &
PID=$!
if [ -n "${RUN_SECS:-}" ]; then
  ( sleep "$RUN_SECS"; kill -TERM "$PID" 2>/dev/null ) &
fi
wait "$PID"; echo "exit=$? log: $LOG"
