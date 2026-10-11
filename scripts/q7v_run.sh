#!/bin/bash
# q7v_run.sh <tag> <BIN> <ctest|quad> [arg]  -- RC1 Q9/G11 (single instance, drive lock, per-process FIFO/save/log).
#   ctest <secs> [level]   RVK_CENSUSTEST=<level 1|2> positive control: shell title idle for <secs>, census must report the injected dropouts
#   quad  [Karm]           XBOX 360 hand-over leg (tick-scheduled presses, as Q1 leg_x360) with RVK_QUADCENSUS armed from the host
#                          by `touch /tmp/rvk_quad_now` a few presents after the LEFT press, so the per-quad lines cover the LEFT+13 loss.
#   bank: _local/rc1/q7v/<tag>/{census_lines.txt,quad_lines.txt,guest.log,facts.txt}; the env block is q1_run.sh's verbatim.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?bin}"; KIND="${3:?ctest|quad}"; ARG="${4:-240}"; PN="$(basename "$BIN")"
LEVEL="${5:-1}"
B="_local/rc1/q7v/$TAG"; rm -rf "$B"; mkdir -p "$B/png"; OUT="$B/steps.txt"; : > "$OUT"
LOCK=/tmp/futari_drive.lock; HAVE=0
rel(){ [ "$HAVE" = 1 ] && rmdir "$LOCK" 2>/dev/null; HAVE=0; }
trap 'pkill -x "$PN" 2>/dev/null; rel' EXIT
W0=$(date +%s)
for ((w=0; w<${LOCKWAIT_MIN:-180}; w++)); do
  if pgrep -x futari_merged >/dev/null; then sleep 60; continue; fi
  mkdir "$LOCK" 2>/dev/null && { HAVE=1; break; }
  sleep 60
done
[ "$HAVE" = 1 ] || { echo "NO LOCK" | tee -a "$OUT"; exit 3; }
WAITED=$(( $(date +%s)-W0 ))
FIFO=/tmp/futari_pad_q7v; echo 0 > "$FIFO"
SAVE="_local/saves/q7v_$TAG"; rm -rf "$SAVE"; cp -R _local/saves/save_mac "$SAVE"
L="_local/logs/q7v_${TAG}.log"
export RT_GAME_ROOT="$PWD/assets" XR_SHELL_XEX=assets/default.xex RT_SAVE="$SAVE"
export RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1
export RT_AUDIO=1 RT_AUDIOWORKER=1 RT_AUDIOBRIDGE=1 RT_CUEBRIDGE=1
export RT_VK=1 RT_NVK=2 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_BLEND=1 RVK_REALALPHA=1
export RT_WALLPAPER=1 RVK_TEXPITCH=1 RVK_FMT3KEY=1 RVK_GPFIELD=1 RVK_C255=0.00625:0.00390625:-1:0
export RVK_RESALIAS=1 RVK_RESFRESH=1 RVK_FIXB2=1 RVK_RESREAL=1 RVK_HDR=0
export RVK_WINDOW=1 RVK_WINSIZE=1280x720 RVK_DIMFIX=1
export RT_NAVREAL=1 RT_STARTWIRE=1 RT_SNDQFREE=1 RT_RESCACHE=1 RT_HEAPLOCK=1
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_SAMPLES=0 RT_AUDIOSTARVE=1
export RT_NVKPNG=300 RVK_DUMPDIR="$PWD/$B/png"
export RVK_DRAWCENSUS=2 RVK_TITLEPROBE=1
[ "$KIND" = ctest ] && export RVK_CENSUSTEST="$LEVEL"
[ "$KIND" = quad ] && export RT_TICKLOG=1 RVK_QUADCENSUS=1 RVK_QUADCENSUS_K="${KARM:-16}"
rm -f /tmp/rvk_quad_now
"$BIN" 8208A2B8 0 "$XR_SHELL_XEX" 2>"$L" &
PID=$!
T0=$(date +%s); say(){ echo "t+$(( $(date +%s)-T0 ))s $*" | tee -a "$OUT"; }
say "q7v $TAG kind=$KIND arg=$ARG level=$LEVEL bin=$BIN pid=$PID lockwait=${WAITED}s start=$(date '+%F %T')"
cnt(){ grep -a -c "$1" "$L"; }
fin(){ kill "$PID" 2>/dev/null; sleep 2; kill -9 "$PID" 2>/dev/null; wait "$PID" 2>/dev/null; rm -f /tmp/rvk_quad_now
  grep -a 'DROPOUT-CONFIRMED\|\[census\] status\|CENSUSTEST' "$L" > "$B/census_lines.txt"; grep -a 'DROPOUT-CONFIRMED' "$L" > "$B/dropouts.txt"
  grep -a '\[quadcensus\]' "$L" > "$B/quad_lines.txt"; cp "$L" "$B/guest.log"
  say "END fatal=$(cnt FATAL) vkerr=$(cnt 'VK_ERROR\|VUID') slowframe=$(cnt '\[slowframe\]') dropout=$(cnt 'DROPOUT-CONFIRMED') testmarks=$(cnt 'CENSUSTEST ARMED\|CENSUSTEST inject') quadlines=$(cnt '\[quadcensus\]')"
  rel; }
die(){ say "FAIL: $*"; fin; exit 1; }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; }
tick(){ tail -n 200 "$L" | grep -a -o '^\[tick\] p[0-9]*' | tail -1 | tr -dc 0-9; }
MARK=0; mark(){ MARK=$(wc -l < "$L" | tr -d ' '); }
waitnew(){ local pat="$1" n="${2:-20}" i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$L" | grep -a -q "$pat" && return 0; sleep 0.5; done; return 1; }
for ((i=0;i<90;i++)); do grep -a -q "name='motion/title.lzx'" "$L" && break; kill -0 "$PID" 2>/dev/null || die "process died before title"; sleep 1; done
grep -a -q "name='motion/title.lzx'" "$L" || die "no title"
say "shell title loaded"; sleep 4
if [ "$KIND" = ctest ]; then
  say "ctest: idle $ARG s at the shell title, CENSUSTEST=$LEVEL"; sleep "$ARG"; cp "$B/png/nvk_last.png" "$B/shot_end.png" 2>/dev/null; fin; exit 0
fi
# ---- quad: tick-scheduled presses (Q1 tpress shape; the LEFT press additionally arms the quad census from the host) ----
tpress(){ local pad="$1" arm="${2:-0}" now T i f armed=0; now=$(tick); [ -n "$now" ] || now=0; T=$((now+25)); echo "t$T:$pad" > "$FIFO"
  for ((i=0;i<1000;i++)); do f=$(tick)
    if [ "$arm" = 1 ] && [ $armed = 0 ] && [ -n "$f" ] && [ "$f" -ge $((T+${ARMAT:-2})) ]; then touch /tmp/rvk_quad_now; armed=1; say "ARM touch at tick $f (T=$T)"; fi
    [ -n "$f" ] && [ "$f" -ge $((T+12)) ] && break; sleep 0.02; done; echo 0 > "$FIFO"; LASTT=$T; }
step(){ local pad="$1" pat="$2" settle="$3" try; for try in 1 2; do mark; tpress "$pad"; waitnew "$pat" && { say "pad $pad @tick $LASTT -> $pat"; sleep "$settle"; return 0; }; done; die "no $pat after pad $pad"; }
step 10   'SYS_BGM cue0 (mushifuta_Menu02)' 4
step 1000 'SYS_SE cue1 (SE_OK01)' 3
mark; tpress 4 1; TL=$LASTT; say "LEFT pressed @tick $TL"
sleep 4
say "hold done; tick=$(tick)"
fin
