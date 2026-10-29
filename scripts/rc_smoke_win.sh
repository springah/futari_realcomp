#!/bin/bash
# rc_smoke_win.sh <staged folder> [secs]  -- BOOT SMOKE of a staged Windows RC folder (rc_stage_win.sh output), the Windows twin
# of scripts/app_smoke_mac.sh step 1: launch the folder's own exe with the folder's own launcher environment (the env block of
# "Futari 1.5.bat", re-exported here), from a COPY of the folder's fresh-save template, no synthetic input beyond RT_NAV_SEQ START
# presses to leave the title; run <secs> (default 60); kill; read the log:
#   PASS/FAIL  both module DLLs bound ("2/2 module DLL(s) bound")      PASS/FAIL  0 FATAL     PASS/FAIL  0 VK_ERROR
#   PASS/FAIL  build id names a commit (not -dirty / unknown)           note       slowframe count, present count
# Nothing is written inside the staged folder: save + log go to _local/rc/smoke_win_<ts>/.  Kills ONLY the pid it started.
set -u
ST="${1:?usage: rc_smoke_win.sh <staged folder> [secs]}"; SECS="${2:-60}"
cd "$(dirname "$0")/.."
[ -f "$ST/futari_combined.exe" ] || { echo "no futari_combined.exe in $ST"; exit 2; }
export MSYS_NO_PATHCONV=1
TS=$(date +%Y%m%d_%H%M%S); W="$PWD/_local/rc/smoke_win_$TS"; mkdir -p "$W"
cp -r "$ST/save_freshcard" "$W/save"
LOG="$W/futari.log"
STW=$(cygpath -w "$ST"); WW=$(cygpath -w "$W")
say(){ echo "[smoke] $*"; }

# the launcher's environment ("Futari 1.5.bat"), verbatim, plus RT_PAD so START is pressed for us
export RT_GAME_ROOT="$STW\\assets" RT_SAVE="$WW\\save"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_AUDIO=1 RT_AUDIOWORKER=1 RT_AUDIOBRIDGE=1 RT_AUDIOXWMA=1 RT_CUEBRIDGE=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0 RVK_WINDOW=1 RVK_WINSIZE=1280x720 RVK_DIMFIX=1
export RT_NAVREAL=1 RT_STARTWIRE=1 RT_PAD_HOST=1 RT_SNDQFREE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_PAD=1 RT_NAV_SEQ="8000:STARTx20@500" RT_NOXINPUT=1

say "exe $(md5sum "$ST/futari_combined.exe" | cut -c1-12)  normal $(md5sum "$ST/futari_game_normal.dll" | cut -c1-12)  abn $(md5sum "$ST/futari_game_abn.dll" | cut -c1-12)"
( cd "$ST" && ./futari_combined.exe 8208A2B8 0 "shell\\default.xex" 2>"$LOG" >"$W/stdout.txt" ) &
PID=$!
say "pid $PID running ${SECS}s ..."; sleep "$SECS"
# kill only our process tree
powershell -NoProfile -Command "Get-CimInstance Win32_Process | Where-Object { \$_.Name -eq 'futari_combined.exe' -and \$_.CommandLine -like '*$(basename "$ST")*' } | ForEach-Object { Stop-Process -Id \$_.ProcessId -Force }" 2>/dev/null
kill $PID 2>/dev/null; wait $PID 2>/dev/null

FAIL=0
BID=$(grep -o -m1 "build=[^ ]*" "$LOG" | head -1)
case "$BID" in build=unknown|build=*-dirty|"") say "FAIL build id: ${BID:-missing}"; FAIL=1;; *) say "PASS $BID";; esac
grep -q "2/2 module DLL(s) bound" "$LOG" && say "PASS both modules bound" || { say "FAIL modules not both bound: $(grep -m3 '\[modreg\]' "$LOG" | tr '\n' '|')"; FAIL=1; }
NF=$(grep -c FATAL "$LOG"); [ "$NF" = 0 ] && say "PASS no FATAL" || { say "FAIL FATAL x$NF: $(grep -m2 FATAL "$LOG" | tr '\n' '|')"; FAIL=1; }
NV=$(grep -c "VK_ERROR" "$LOG"); [ "$NV" = 0 ] && say "PASS no VK_ERROR" || { say "FAIL VK_ERROR x$NV"; FAIL=1; }
say "note: slowframe x$(grep -c '\[slowframe\]' "$LOG"), navreal lines x$(grep -c '\[navreal\]' "$LOG"), log $(wc -l < "$LOG") lines -> $LOG"
grep -m1 "\[navreal\]" "$LOG" >/dev/null && say "note: first navreal: $(grep -m1 '\[navreal\]' "$LOG" | cut -c1-120)"
[ $FAIL = 0 ] && echo "WIN SMOKE: PASS" || { echo "WIN SMOKE: FAIL"; exit 1; }
