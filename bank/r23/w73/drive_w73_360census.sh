#!/bin/bash
# drive_w73_360census.sh <tag> [PLAY_S]
#
# r23-w73 DRIVER -- THE RESIDUE EXECUTION CENSUS, fresh-leg component. Extends the reco_abnormal
# (360-card) tree with RT_INDCENSUS coverage for the FIRST time in campaign history (checked:
# no *_indcensus.txt exists under any abn/360-card tag before this window; w68's own abn360 leg
# armed RT_WITNESS/RT_WITNESS2/RT_TRIOTAP but not RT_INDCENSUS). Pre-registration:
# bank/r23/w73/PREREG_w73.txt SS3(b).
#
# DERIVED FROM bank/r23/w68/drive_w68_abn360.sh VERBATIM (env block, nav sequence, kill-verify,
# single-instance lock, module-load verification, positive control). NEW here: RT_INDCENSUS=1
# added, dump path unique to this leg, PLAY_S default raised 360->600 for more dispatch depth,
# verdict block extended with a roster hit count (against bank/r23/w73/drive_floor_w73_base.tsv).
set -u
TAG="${1:?usage: drive_w73_360census.sh <tag> [PLAY_S]}"
PLAY_S="${2:-600}"

ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp"; cd "$ROOT_DIR" || exit 1
export MSYS_NO_PATHCONV=1
ROOT="$(pwd -W 2>/dev/null || pwd)"
BANK="C:/Users/shant/Desktop/projects/futari_decomp/bank/r23/w73"; mkdir -p "$BANK"; mkdir -p /c/tmp

BIN="${BIN:-./build/futari_combined.exe}"
[ -x "$BIN" ] || { echo "!! missing host exe $BIN"; exit 1; }
[ -f "build/futari_game_normal.dll" ] || { echo "!! missing build/futari_game_normal.dll"; exit 1; }
[ -f "build/futari_game_abn.dll" ]    || { echo "!! missing build/futari_game_abn.dll"; exit 1; }
CARDSAVE="${CARDSAVE:-save_r17_boss}"
[ -d "$CARDSAVE" ] || { echo "!! missing card $CARDSAVE"; exit 1; }

export LOG="$BANK/${TAG}.log"
PHASES="$BANK/${TAG}_phases.txt"
: > "$LOG"; : > "$PHASES"

export RT_GAME_ROOT="$ROOT/assets"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0 RVK_WINDOW=1
export RT_NAVREAL=1 RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_MSGLOG=1 RT_STARTWIRE=1 RT_INPUTFORCE=1 RT_MENULOG=1 RVK_DIMFIX=1
export RVK_DIEHARD=1
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="/tmp/futari_pad_r23w73" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1
export FIFO="/c/tmp/futari_pad_r23w73"
export RT_SAVE="save_r23w73_${TAG}"
# ---- ★★★★★ THE MISSION INSTRUMENTS ----
export RT_TRIOTAP=1                                          # RE-ARM: drive-alive liveness control
export RT_INDCENSUS=1 RT_INDCENSUS_OUT="$BANK/${TAG}_indcensus.txt" RT_INDCENSUS_EVERY=200000  # NEW this leg on abn tree

echo "[r23w73] tag=$TAG play=${PLAY_S}s"
echo "[r23w73] exe md5 $(md5sum "$BIN" | cut -c1-12)"
echo "[r23w73] normal dll md5 $(md5sum build/futari_game_normal.dll | cut -c1-12)"
echo "[r23w73] abn dll md5    $(md5sum build/futari_game_abn.dll | cut -c1-12)"

# ---- SINGLE-INSTANCE LOCK ----------------------------------------------------------------------
LOCKF="/c/tmp/.w73_drive.lock"
if [ -e "$LOCKF" ]; then
  OTHER="$(cat "$LOCKF" 2>/dev/null)"
  if kill -0 "$OTHER" 2>/dev/null; then echo "!! another w73 drive is LIVE (pid $OTHER) -- REFUSING."; exit 1; fi
  echo "[r23w73] stale lock from dead pid $OTHER -- reclaiming"
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
echo "[r23w73] pid=$PID log=$LOG"

source scripts/futari_nav.sh
nav_press(){ echo "$1" > "$FIFO"; sleep "${2:-0.2}"; echo 0 > "$FIFO"; sleep "${3:-0.9}"; }
alive(){ kill -0 "$PID" 2>/dev/null; }
FAILS=0
die(){ echo "[r23w73] FAIL: $*"; FAILS=$((FAILS+1)); }

triotap_now(){ grep -ac '\[triotap\] #' "$LOG" 2>/dev/null || echo 0; }
ctrl_now(){ grep -ac '\[triotap\].*callee=sub_8808FB90' "$LOG" 2>/dev/null || echo 0; }
ctrlok_now(){ grep -ac '\[triotap\].*callee=sub_8808FB90.*lr=0x88093428' "$LOG" 2>/dev/null || echo 0; }
phase(){ local t=$(( $(date +%s) - T0 ))
  printf 't+%-5ss %-28s triotap=%-6s ctrl=%-6s\n' "$t" "$1" "$(triotap_now)" "$(ctrl_now)" | tee -a "$PHASES"
}

# ============================== THE LEG =======================================================
nav_boot_to_topmenu             || die "boot -> top menu"
phase "boot -> top menu"

nav_card_decide 360 1           || die "card decide 360 (module swap to reco_abnormal)"
phase "360 card decided"
grep -a 'reco_abnormal\|reco_normal\|XexLoadImage' "$LOG" | tail -5

nav_360_land_to_modeselect      || die "360 landing -> mode select"
phase "360 mode-select landed"

nav_selects_to_stage            || die "360 route to stage"
phase "360 stage entered"

echo "[r23w73] --- CALIBRATION CHECKPOINT ---"
echo "[r23w73]   ctrl(sub_8808FB90) : $(ctrl_now)   matching lr=0x88093428: $(ctrlok_now)"
if [ "$(ctrl_now)" = "0" ]; then
  die "POSITIVE CONTROL SILENT at stage entry — instrument may not be live; continuing to log more data but this is a BLOCKER"
fi

nav_say "idling/playing ${PLAY_S}s in-stage on the 360-card route (scored dwell)"
end=$(( $(date +%s) + PLAY_S ))
pulses=0
while [ "$(date +%s)" -lt "$end" ]; do
  alive || { die "guest died during the scored dwell"; break; }
  echo 1000 > "$FIFO"; sleep 2.0; echo 0 > "$FIFO"; sleep 0.4
  pulses=$((pulses+1))
  if [ $((pulses % 3)) -eq 0 ]; then echo 10 > "$FIFO"; sleep 0.3; echo 0 > "$FIFO"; sleep 0.3; fi
  if [ $((pulses % 8)) -eq 0 ]; then phase "IN-STAGE+$(( $(date +%s) - T0 ))s"; fi
done
phase "SCORED-DWELL-DONE"

TOTAL=$(( $(date +%s) - T0 ))
DIED=""; alive || DIED="yes"
kill $PID 2>/dev/null; sleep 1; kill_mine; sleep 1

{
echo "===== [$TAG] r23-w73 THE 360-CARD CENSUS LEG (abn tree, RT_INDCENSUS first time) ====="
echo "    total=${TOTAL}s died=${DIED:-no} script_fails=$FAILS"
grep -a '\[env\]' "$LOG" | head -1 | sed 's/^/    /'
echo "===== [$TAG] MODULE LOAD VERIFICATION ====="
grep -a 'reco_abnormal\|reco_normal\|XexLoadImage' "$LOG" | sed 's/^/    /'
echo "===== [$TAG] POSITIVE CONTROL (drive-alive liveness) ====="
echo "    [triotap] total hits  : $(triotap_now)"
echo "    ctrl (sub_8808FB90)   : $(ctrl_now)"
echo "    ctrl matching lr=0x88093428 : $(ctrlok_now)"
echo "===== [$TAG] INDCENSUS DUMP ====="
if [ -s "$BANK/${TAG}_indcensus.txt" ]; then
  echo "    file: $BANK/${TAG}_indcensus.txt  lines=$(wc -l < "$BANK/${TAG}_indcensus.txt")"
  tail -1 "$BANK/${TAG}_indcensus.txt" | sed 's/^/    /'
else
  echo "    ** MISSING/EMPTY -- indcensus did not write (check Windows-path requirement)"
fi
echo "===== [$TAG] PHASE TRACE ====="
cat "$PHASES" | sed 's/^/    /'
} > "$BANK/${TAG}_verdict.txt" 2>&1

cat "$BANK/${TAG}_verdict.txt"
