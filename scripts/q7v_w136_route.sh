#!/bin/bash
# q7v_w136_route.sh <tag> <bin> -- RC1 Q9/G11: futari_decomp bank/r23/w136 drive_w136_shellgate_v3.sh + route_w136_v3.sh (ARCADE Options tour) with
# (1) outputs under _local/rc1/q7v/w136_<tag> (the sibling repo stays read-only), (2) the drive lock, (3) RVK_QUADCENSUS armed from the host
# at each frame in ARMFRAMES (the five banked press-coincident 0x49C4000 losses: f2370/4173/7133/7497/7759, armed 12 frames early, K=20).
# Same route, instruments and bank layout as drive_w136_shellgate.sh, but NO wall-clock sleeps between the game's
# state and our presses/shots. The clock is the renderer's RT_NVKPNG=5 dump log line "[rvk] wrote .../nvk_f<N>.png"
# (one per 5 frames, printed after the file is complete), polled every 10 ms; the host pad thread reads the FIFO every
# 4 ms (shell/gen/stubs.cpp:725). Every press is scheduled at a frame; every shot is the dump of a specific frame.
# Step grammar (space-separated):
#   m:<regex>   wait (<= 30 s) for a NEW log line matching it; the cursor becomes the frame that line was logged at
#   p:<pad>     press <pad> at the cursor frame (10=START 1000=A 2000=B 1=UP 2=DOWN 4=LEFT 8=RIGHT); cursor += 48 (0.8 s)
#   s:<n>       cursor += 60*n   (n seconds of game time, as frames)
#   shot        shot = nvk_f<cursor rounded down to 5>.png, taken once the clock has passed it; cursor += 6
# Runs from futari_realcomp's root.
set -u
cd "$(dirname "$0")/.." || exit 1
source "$(dirname "${BASH_SOURCE[0]}")/pymac.sh"   # $PYTHON = a python with numpy + Pillow (10-30 landmine)
TAG="${1:?tag}"; BIN="${2:?bin}"; shift 2
set --   "m:name='motion/title.lzx'" s:4 p:10    "m:SYS_BGM cue0 (mushifuta_Menu02)" s:4 p:1000    "m:SYS_SE cue1 (SE_OK01)" s:3 p:1000    "m:\\[modeidx\\] .*ARCADE" s:3 p:1000    "m:\\[p0build\\] menu_game_title" s:2    p:2 m:mcur s:1 p:2 m:mcur s:1 p:2 m:mcur s:1 p:2 m:mcur s:4 shot    p:1000 s:4 shot    p:1000 s:4 shot    p:2000 s:4 shot    p:2 s:1 p:1000 s:4 shot    p:8 s:4 shot p:4 s:4 shot    p:2 p:2 p:2 p:2 p:2 p:2 s:4 shot    p:1000 s:4 shot p:1000 s:4 shot p:1000 s:4 shot    p:2000 s:3 p:2 p:1000 s:4 shot    p:2000 s:3 p:2 p:1000 s:4 shot    p:2000 s:3 p:2 p:1000 s:3 p:1000 s:4 shot    p:2000 s:3 p:2000 s:3 p:2 p:2 p:1000 s:4 shot    p:2000 s:3 p:2000 s:4 shot 
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
BANK="_local/rc1/q7v/w136_$TAG"; mkdir -p "$BANK"
LOCK=/tmp/futari_drive.lock; HAVE=0; PN="$(basename "$BIN")"
trap 'pkill -x "$PN" 2>/dev/null; [ "$HAVE" = 1 ] && rmdir "$LOCK" 2>/dev/null' EXIT
for ((w=0; w<180; w++)); do
  pgrep -x futari_merged >/dev/null && { sleep 60; continue; }
  mkdir "$LOCK" 2>/dev/null && { HAVE=1; break; }; sleep 60; done
[ "$HAVE" = 1 ] || { echo "NO LOCK"; exit 3; }
rm -rf "_local/saves/save_q7v_w136_$TAG"; cp -R _local/saves/save_mac "_local/saves/save_q7v_w136_$TAG"
export RT_SAVE="_local/saves/save_q7v_w136_$TAG"
B="_local/rc1/q7v/w136_$TAG/nav"; rm -rf "$B"; mkdir -p "$B"
FIFO=/tmp/futari_pad_q7v; echo 0 > "$FIFO"
export RT_PAD_HOST=1 RT_PAD_HOST_FIFO="$FIFO" RT_NVKPNG=5 RVK_DUMPDIR="$PWD/_local/rc1/q7v/w136_png_$TAG"; rm -rf "$RVK_DUMPDIR"; mkdir -p "$RVK_DUMPDIR"
export RVK_QUADCENSUS=1 RVK_QUADCENSUS_K=20 RVK_DRAWCENSUS=2 RVK_TITLEPROBE=1 RT_MENULOG=1 RT_NVKRTLOG=1
export RT_INDCENSUS=1 RT_INDCENSUS_OUT="$PWD/$BANK/indcensus.txt" RT_INDCENSUS_EVERY=20000
PREVLOG=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1)
BIN="$BIN" RUN_SECS=300 bash scripts/run_mac.sh > "$B/run_out.txt" 2>&1 &
T0=$(date +%s)
LOGF=""; for ((i=0;i<60;i++)); do L=$(ls -t _local/logs/mac_*.log 2>/dev/null | head -1); [ -n "$L" ] && [ "$L" != "$PREVLOG" ] && { LOGF="$L"; break; }; sleep 0.5; done
[ -n "$LOGF" ] || { echo "no new log"; exit 1; }
ARMFRAMES="${ARMFRAMES:-2370 4173 7133 7497 7759}"
( for T in $ARMFRAMES; do while :; do f=$(tail -n 150 "$LOGF" | grep -o 'nvk_f[0-9]*' | tail -1 | tr -dc 0-9); [ -n "$f" ] && [ "$f" -ge $((T-12)) ] && break; kill -0 $$ 2>/dev/null || exit; sleep 0.01; done; touch /tmp/rvk_quad_now; echo "[armer] touched at f$f for target f$T" >> "$B/steps.txt"; sleep 1; done ) & ARMER=$!
# keep the dump dir small: newest 120 frame files (= 600 frames = 10 s) survive
( while kill -0 $$ 2>/dev/null; do ls -t "$RVK_DUMPDIR"/nvk_f*.png 2>/dev/null | tail -n +120 | xargs rm -f 2>/dev/null; sleep 2; done ) & CLEANER=$!
say(){ echo "[nav3] t+$(( $(date +%s)-T0 ))s $*" | tee -a "$B/steps.txt"; }
die(){ say "ROUTE BROKEN: $*"; kill $CLEANER 2>/dev/null; pkill -x "$PN" 2>/dev/null; cp "$LOGF" "$B/guest.log"; exit 1; }
curframe(){ tail -n 150 "$LOGF" | grep -o 'nvk_f[0-9]*' | tail -1 | tr -dc 0-9; }
waitframe(){ local T=$1 i f; for ((i=0;i<9000;i++)); do f=$(curframe); [ -n "$f" ] && [ "$f" -ge "$T" ] && { echo "$f"; return 0; }; sleep 0.01; done; return 1; }
MARK=0; mark(){ MARK=$(wc -l < "$LOGF" | tr -d ' '); }
markframe(){ local pat="$1" i ln f   # grep BRE like the v1 script (parens literal); frame = last dump line before the match
  for ((i=0;i<600;i++)); do
    ln=$(tail -n +"$((MARK+1))" "$LOGF" | grep -n -m1 "$pat" | cut -d: -f1)
    if [ -n "$ln" ]; then f=$(tail -n +"$((MARK+1))" "$LOGF" | head -n "$ln" | grep -o 'nvk_f[0-9]*' | tail -1 | tr -dc 0-9); [ -n "$f" ] || f=$(curframe); echo "$f"; return 0; fi
    sleep 0.05; done; return 1; }
CUR=0; N=0
for st in "$@"; do
  case "$st" in
    m:*) f=$(markframe "${st#m:}") || die "no marker ${st#m:} within 30 s (cursor f$CUR)"; CUR=$f; say "marker '${st#m:}' at f$f";;
    p:*) pad="${st#p:}"; f=$(waitframe "$CUR") || die "clock stalled waiting for f$CUR"; mark; echo "$pad" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; say "pad $pad at f$f (sched f$CUR)"; CUR=$((CUR+48));;
    s:*) CUR=$((CUR + 60*${st#s:}));;
    shot) F=$(( CUR/5*5 )); waitframe $((F+10)) >/dev/null || die "clock stalled before shot f$F"; N=$((N+1)); ok=0
          for d in 0 5 10; do src="$RVK_DUMPDIR/nvk_f$((F-d)).png"; [ -f "$src" ] && "$PYTHON" -c "from PIL import Image; Image.open('$src').load()" 2>/dev/null && { cp "$src" "$B/shot_$N.png"; say "shot_$N = f$((F-d)) (sched f$F)"; ok=1; break; }; done
          [ $ok = 1 ] || say "shot_$N MISSING at f$F"; CUR=$((CUR+6));;
    *) die "bad step $st";;
  esac
done
say "route done at f$(curframe); FATAL=$(grep -c FATAL "$LOGF") VKERR=$(grep -c 'VK_ERROR\|VUID' "$LOGF") DROPOUT=$(grep -c DROPOUT-CONFIRMED "$LOGF")"
sleep 1; kill $CLEANER $ARMER 2>/dev/null; pkill -x "$PN" 2>/dev/null; sleep 1; cp "$LOGF" "$B/guest.log"
mkdir -p "$BANK/shots"; cp "$B"/shot_*.png "$BANK/shots/" 2>/dev/null
cp "$LOGF" "$BANK/guest.log"; grep -a '\[quadcensus\]' "$LOGF" > "$BANK/quad_lines.txt"; grep -a 'DROPOUT-CONFIRMED' "$LOGF" > "$BANK/dropouts.txt"; kill $ARMER 2>/dev/null
rm -rf "$RVK_DUMPDIR"; rm -f /tmp/rvk_quad_now
echo "banked: $BANK"
