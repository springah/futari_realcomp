#!/bin/bash
# boss1_drive.sh <tag> [dur] — np_orig route on save_r17_boss (the w35 boss-reach recipe), autofire + DIEHARD dwell,
# RT_NVKPNG frame dumps + [nvkrect] vs45 census every RT_NVKDBGEVERY frames. Ship DLLs from build/ (no arm dir).
set -u
TAG="${1:-boss1}"; DUR="${2:-420}"
ROOT_DIR="C:/Users/shant/Desktop/projects/futari_realcomp"; cd "$ROOT_DIR" || exit 1
export MSYS_NO_PATHCONV=1
ROOT="$(pwd -W 2>/dev/null || pwd)"
BANK="/c/tmp/boss1/$TAG"; mkdir -p "$BANK/png"
BIN="${BIN:-./build/futari_combined.exe}"; echo "[boss1] BIN=$BIN ($(stat -c %y "$BIN" | cut -c1-16))"
export RVK_DIEHARD=1 RT_FAM4=1 RT_FAM11=1
export LOG="$BANK/drive.log"; PRESSES="$BANK/presses.txt"
export RT_GAME_ROOT="$ROOT/assets"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0 RVK_WINDOW=1
export RT_NAVREAL=1 RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_MSGLOG=1 RT_STARTWIRE=1 RT_INPUTFORCE=1 RT_MENULOG=1 RVK_DIMFIX=1
unset RT_MENUHOLD
export RT_INDCENSUS=1 RT_INDCENSUS_OUT="$BANK/indcensus.txt" RT_INDCENSUS_EVERY=200000
export RT_PAD=1 RT_PAD_FIFO=1 RT_PAD_FIFO_PATH="/tmp/futari_pad_boss1" RT_NAV_SEQ="9999999:START" RT_NOXINPUT=1
export FIFO="/c/tmp/futari_pad_boss1"
export RT_SAVE="save_boss1_${TAG}"
if [ -n "${MODDLL:-}" ]; then export RT_MODDLL_DIR="C:/Users/shant/Desktop/projects/futari_realcomp/build/${MODDLL}"; echo "[boss1] RT_MODDLL_DIR=$RT_MODDLL_DIR"; fi
# instruments
export RT_NVKPNG="${NVKPNG:-60}" RT_NVKDBG=1 RT_NVKDBGEVERY="${DBGEVERY:-600}" RT_NVKDBGFROM="${DBGFROM:-4500}" RT_NVKVTXALL=45
rm -f /c/tmp/nvk_f*.png /c/tmp/nvk_last.png
powershell -NoProfile -Command "Stop-Process -Name futari_combined*,futari_merged*,futari_ctrl* -Force -ErrorAction SilentlyContinue"; sleep 2
echo 0 > "$FIFO"; : > "$LOG"; : > "$PRESSES"
rm -rf "$RT_SAVE"; cp -r "${CARD:-save_r17_boss}" "$RT_SAVE"; echo "[boss1] CARD=${CARD:-save_r17_boss}"
"$BIN" 8208A2B8 0 shell/default.xex 2>"$LOG" </dev/null >/dev/null & PID=$!
echo "[boss1] pid=$PID log=$LOG t0=$(date +%s)"
source scripts/futari_nav.sh
nav_press(){ echo "$1" >> "$PRESSES"; echo "$1" > "$FIFO"; sleep "${2:-0.2}"; echo 0 > "$FIFO"; sleep "${3:-0.9}"; }
# press_until <code> <marker-regex> <timeout> <label> [tries] — marker-gated retry (a press dropped by a frame stall is re-issued)
press_until(){ local code="$1" pat="$2" to="$3" lbl="$4" tries="${5:-3}" t; for (( t=1; t<=tries; t++ )); do nav_base; nav_press "$code" 0.15 0.6
  nav_wait_new "$pat" "$to" "$lbl (try $t)" && return 0; done; nav_say "GAVE UP: $lbl"; return 1; }
die(){ echo "[boss1] FAIL: $*"; }
hub_open(){ sleep 40; local r; for r in 1 2 3 4 5 6 7 8; do nav_base; nav_press 10 0.3 2.5
  nav_wait_new '\[p0build\]\|\[mcur\]\|\[decide\]' 10 "hub open (try $r)" && return 0; nav_say "hub not up — retrying START"; done; return 1; }
# hub_row: cursor-TRACKING (marker-driven). Reads the last [mcur] "a->b" after every DOWN, so a dropped press
# (frame stall) and an over-repeated press (old builds repeat a 0.15 s hold) are both handled; 7 hub rows wrap.
hub_cursor(){ grep -a -o 'mcur\] model=0x[0-9A-F]* cursor [0-9]*->[0-9]*' "$LOG" | tail -1 | sed 's/.*->//'; }
hub_row(){ local want="$1" n=0 cur; cur=$(hub_cursor); cur=${cur:-0}
  while [ "$cur" != "$want" ] && [ $n -lt 14 ]; do nav_base; nav_press 2 0.1 0.6; n=$((n+1))
    nav_wait_new 'mcur\]' 3 "hub DOWN #$n (cursor $cur)" >/dev/null; cur=$(hub_cursor); cur=${cur:-0}; done
  [ "$cur" = "$want" ] || { nav_say "hub cursor stuck at $cur (want $want)"; return 1; }
  press_until 1000 '\[decide\]' 5 "hub decide row=$want" || return 1; }
mode_row(){ local want="$1" i; for (( i=0; i<want; i++ )); do nav_press 2 0.15 0.8; done; nav_say "mode select row=$want"; nav_base; nav_press 1000 0.2 3.0; }
selects_tail(){ local i; for i in 1 2 3 4; do nav_base; nav_press 1000 0.25 3.0; done; nav_wait_new 'epochinval\|nvk\] f\|\[emit\]' 20 "stage activity"; }
np_1p(){ nav_press 1000 0.2 3.0; }
nav_boot_to_topmenu || die "boot -> top menu"
nav_card_decide arcade 1 || die "card decide"
hub_open || die "hub open"
if [ "${ROUTE:-np}" = "training" ]; then
  # TRAINING (hub row 2, A) -> STAGE SELECT (caption only in the port: FNF-15, list not drawn; selection works blind)
  #   -> RIGHT x$NRIGHT -> START(開始) -> [mode select?] -> char -> shot.  selects_tail's A presses cover the rest.
  hub_row 2 || die "hub row 2 (TRAINING)"
  nav_wait_new '96660(load)' 8 "training panel load" || die "training panel never loaded"
  sleep 2.0
  for (( i=0; i<${NRIGHT:-1}; i++ )); do nav_press 8 0.15 1.2; done
  nav_say "stage row (blind): pressed RIGHT x${NRIGHT:-1}; START"
  press_until 10 '\[dclose\].*vt=0x82050F00' 5 "panel START (slide-out)" || die "panel did not close on START"
  selects_tail || die "training route to stage"
else
  hub_row 1 && np_1p && mode_row 0 && selects_tail || die "route to stage"
fi
STAGE_T0=$(date +%s); echo "[boss1] STAGE_T0=$STAGE_T0 ($(date +%H:%M:%S)) — dwell ${DUR}s autofire"
END=$(( STAGE_T0 + DUR )); PULSES=0
while [ "$(date +%s)" -lt "$END" ]; do
  echo 1000 > "$FIFO"; sleep 2.0; echo 0 > "$FIFO"; sleep 0.4; PULSES=$((PULSES+1))
  if [ $((PULSES % 3)) -eq 0 ]; then echo 10 > "$FIFO"; sleep 0.3; echo 0 > "$FIFO"; sleep 0.3; fi
  if [ $((PULSES % 10)) -eq 0 ]; then kill -0 "$PID" 2>/dev/null || { echo "[boss1] child exited at ~$(( $(date +%s) - STAGE_T0 ))s"; break; }
    echo "[boss1] t+$(( $(date +%s) - STAGE_T0 ))s pngs=$(ls /c/tmp/nvk_f*.png 2>/dev/null | wc -l) $(grep -a -c '\[nvkrect\]' "$LOG") nvkrect lines"; fi
done
echo "[boss1] dwell end t+$(( $(date +%s) - STAGE_T0 ))s"
powershell -NoProfile -Command "Stop-Process -Name futari_combined*,futari_merged*,futari_ctrl* -Force -ErrorAction SilentlyContinue"
mv /c/tmp/nvk_f*.png "$BANK/png/" 2>/dev/null; echo "[boss1] DONE pngs=$(ls "$BANK/png" | wc -l) log=$(wc -l < "$LOG") lines"
