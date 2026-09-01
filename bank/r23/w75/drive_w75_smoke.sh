#!/bin/bash
# drive_w75_smoke.sh <tag>
#
# r23-w75 DRIVER -- FAST BOOT-ONLY SMOKE TEST for RT_TABREAD attempt 1 (single-width U32,
# 5-narrow-range guard). w74's own crash reproduced deep in shell boot BEFORE the top menu with
# zero [tabread]/[instwatch] hits preceding it -- so a boot-only leg is sufficient to catch a
# repeat of the SAME crash class cheaply, before spending a full scoring leg. Pre-registration:
# bank/r23/w75/PREREG_w75.txt.
#
# DERIVED FROM bank/r23/w74/drive_w74_menutour.sh (env block/lock/kill-verify/single-instance
# discipline), truncated to boot -> top menu only.
set -u
TAG="${1:?usage: drive_w75_smoke.sh <tag>}"

ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp"; cd "$ROOT_DIR" || exit 1
export MSYS_NO_PATHCONV=1
BANK="C:/Users/shant/Desktop/projects/futari_decomp/bank/r23/w75"; mkdir -p "$BANK/eyes"; mkdir -p /c/tmp

BIN="${BIN:-./build/futari_combined.exe}"
[ -x "$BIN" ] || { echo "!! missing host exe $BIN"; exit 1; }
[ -f "build/futari_game_normal.dll" ] || { echo "!! missing build/futari_game_normal.dll"; exit 1; }
[ -f "build/futari_game_abn.dll" ]    || { echo "!! missing build/futari_game_abn.dll"; exit 1; }
CARDSAVE="${CARDSAVE:-save_freshcard}"
[ -d "$CARDSAVE" ] || { echo "!! missing card $CARDSAVE"; exit 1; }

export LOG="$BANK/${TAG}.log"
: > "$LOG"

export RT_GAME_ROOT="$ROOT_DIR/assets"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0 RVK_WINDOW=1 RVK_WINSIZE=1280x720
export RT_NAVREAL=1 RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_MSGLOG=1 RT_STARTWIRE=1 RT_INPUTFORCE=1 RT_MENULOG=1 RVK_DIMFIX=1
export RVK_DIEHARD=1
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="/tmp/futari_pad_r23w75" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1
export FIFO="/c/tmp/futari_pad_r23w75"
export RT_SAVE="save_r23w75_${TAG}"
# ---- ★★★★★ THE MISSION INSTRUMENT ----
export RT_TRIOTAP=1     # drive-alive liveness control
export RT_TABREAD=1     # r23-w75 retry -- single-width U32, 5-narrow-range guard

echo "[r23w75] tag=$TAG"
echo "[r23w75] exe md5 $(md5sum "$BIN" | cut -c1-12)"
echo "[r23w75] normal dll md5 $(md5sum build/futari_game_normal.dll | cut -c1-12)"
echo "[r23w75] abn dll md5    $(md5sum build/futari_game_abn.dll | cut -c1-12)"

# ---- SINGLE-INSTANCE LOCK ----------------------------------------------------------------------
LOCKF="/c/tmp/.w75_drive.lock"
if [ -e "$LOCKF" ]; then
  OTHER="$(cat "$LOCKF" 2>/dev/null)"
  if kill -0 "$OTHER" 2>/dev/null; then echo "!! another w75 drive is LIVE (pid $OTHER) -- REFUSING."; exit 1; fi
  echo "[r23w75] stale lock from dead pid $OTHER -- reclaiming"
fi
echo $$ > "$LOCKF"
trap 'rm -f "$LOCKF"' EXIT

# ---- ORPHAN KILL-VERIFY (hard gate) -------------------------------------------------------------
MYSTART="$(powershell -NoProfile -Command "(Get-Date).AddSeconds(-5).ToString('yyyy-MM-dd HH:mm:ss')" | tr -d '\r')"
kill_mine(){ powershell -NoProfile -Command "
    Get-CimInstance Win32_Process -Filter \"Name='futari_combined.exe'\" |
      Where-Object { \$_.CreationDate -ge [datetime]'$MYSTART' } |
      ForEach-Object { Stop-Process -Id \$_.ProcessId -Force -ErrorAction SilentlyContinue }" >/dev/null 2>&1; }
FOREIGN="$(powershell -NoProfile -Command "
  @(Get-CimInstance Win32_Process -Filter \"Name='futari_combined.exe'\" |
     Where-Object { \$_.CreationDate -lt [datetime]'$MYSTART' }).Count" 2>/dev/null | tr -d '\r ')"
if [ "${FOREIGN:-0}" != "0" ]; then echo "!! $FOREIGN futari_combined process(es) predate this script -- REFUSING."; exit 1; fi
XEN="$(powershell -NoProfile -Command "@(Get-Process | Where-Object { \$_.ProcessName -like 'xenia*' -or \$_.ProcessName -like 'XeniaManager*' }).Count" 2>/dev/null | tr -d '\r ')"
[ "${XEN:-0}" != "0" ] && { echo "!! $XEN xenia process(es) live -- REFUSING (never concurrent)."; exit 1; }
kill_mine; sleep 2

echo 0 > "$FIFO"
rm -rf "$RT_SAVE"; cp -r "$CARDSAVE" "$RT_SAVE"
"$BIN" 8208A2B8 0 shell/default.xex 2>"$LOG" </dev/null >/dev/null & PID=$!
T0=$(date +%s)
echo "[r23w75] pid=$PID log=$LOG"

source scripts/futari_nav.sh
alive(){ kill -0 "$PID" 2>/dev/null; }
FAILS=0
die(){ echo "[r23w75] FAIL: $*"; FAILS=$((FAILS+1)); }
tabr_now(){ grep -ac '\[tabread\] #' "$LOG" 2>/dev/null || echo 0; }
ctrl_now(){ grep -ac '\[tabread\].*cluster=E-ctrl' "$LOG" 2>/dev/null || echo 0; }
armed_now(){ grep -ac '\[tabread\] ARMED' "$LOG" 2>/dev/null || echo 0; }
phase(){ local t=$(( $(date +%s) - T0 ))
  printf 't+%-5ss %-20s alive=%-5s armed=%-3s tabread=%-6s ctrl(E)=%-6s\n' "$t" "$1" "$(alive && echo yes || echo NO)" "$(armed_now)" "$(tabr_now)" "$(ctrl_now)" | tee -a "$BANK/${TAG}_phases.txt"
}

# ============================== SMOKE LEG (boot only) ==========================================
nav_boot_to_topmenu             || die "boot -> top menu"
phase "boot -> top menu"
sleep 10
phase "10s dwell at top menu"

echo "[r23w75] stopping"
kill "$PID" 2>/dev/null; sleep 1
kill_mine

echo "=== SMOKE VERDICT ==="
echo "alive=$(alive && echo yes || echo NO) armed=$(armed_now) tabread=$(tabr_now) ctrl(E)=$(ctrl_now) fails=$FAILS"
echo "[tabread] lines:"; grep -a '\[tabread\]' "$LOG" | head -40
echo "--- tail of log (last 30 lines, crash context if any) ---"
tail -n 30 "$LOG"
