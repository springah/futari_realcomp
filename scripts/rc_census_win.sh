#!/bin/bash
# WINDOWS PORT -- generated from scripts/rc_census_mac.sh by scripts/win_port.sh (2026-10-29); edit the Mac original and regenerate. Differences: win_shim.sh
# (pkill/pgrep/ps/md5), run_win.sh as the launcher, /c/tmp for the FIFO + drive lock. Engine copy: a uniquely named .exe beside the module DLLs.
# rc_census_mac.sh <tag> <BIN> <arcade|x360> [minutes=6]  -- the Q1 flicker-census route on a GIVEN engine binary (RC1 PLAN §6.5 item 2).
# ONE launch: shell title idle SHELL_SECS (default 120) -> START -> top menu -> card (x360: LEFT first) -> mode decide -> HANDS OFF <minutes>
# (the demo loop) with RVK_DRAWCENSUS=2, per-30 s RSS/frame samples. Adapted from _local/rc1/q1/q1_run.sh (the env block is its verbatim copy) with the
# binary as a parameter. The engine is killed with `pkill -x <basename BIN>` ONLY (use a uniquely named copy; rc_cut_mac.sh makes one).
# Verdict (RESULT: PASS|FAIL on the last line of <bank>/VERDICT.txt, exit 0/1; exit 3 = no lock):
#   FAIL on any FATAL, VK_ERROR/VUID, [slowframe], audio underrun, live-sink stall, a hands-off minute outside 3600 +-10 frames, or any
#   DROPOUT-CONFIRMED whose base is not a NAMED AUTHENTIC deterministic class: 0x2530000 (PRESS START strobe), 0x34E0000 (360 card-LEFT quad),
#   0x49C4000 (w136 menu-atlas pair); the strobe and the card-LEFT quad are also matched by their v0 key ((-190.5,181.5) / len=1 v0=(41.5,-284.5)) because the
#   base moves between builds (0x34E0000 on the Q1 probe, 0x34D0000 on the RC bundle engine) -- Q9/G11, docs/NOTE_fnf_shell_defects.md 2026-10-12;
#   360 NOW-LOADING ring particles (the two hand-over lines of the 0.3.0-rc1 dry run): len=3 v0=(253.5,273.6) and len=2 v0=(251.0,-5.4), base
#   0x1C?4000 (0x1C04000/0x1C44000 on the dry-run engine, 0x1C14000/0x1C54000 on the HEAD probes) -- a ring-sprite type with zero live particles
#   between its last particle expiring and the next burst; occurs only for some press timings, identical when the presses land on the same guest
#   ticks (NOTE_fnf_shell_defects.md 2026-10-12 "360 NOW-LOADING ring particles").  Named-class hits are listed as INFO.
# DRIVE LOCK: mkdir /c/tmp/futari_drive.lock, 60 s polls up to LOCKWAIT s (default 7200), also waits while `pgrep -x futari_merged` (someone is playing);
# rmdir only a lock this process created. Bank: ${RCC_ROOT:-_local/rc/census}/<tag>/.
set -u
source "$(dirname "$0")/win_shim.sh"   # Windows: pkill/pgrep/ps/md5 shims, /c/tmp
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?bin}"; MODE="${3:?arcade|x360}"; MIN="${4:-6}"; PN="$(basename "$BIN")"
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
case "$MODE" in arcade|x360) ;; *) echo "mode arcade|x360"; exit 2;; esac
B="${RCC_ROOT:-_local/rc/census}/$TAG"; rm -rf "$B"; mkdir -p "$B/png"; OUT="$B/steps.txt"; : > "$OUT"; V="$B/VERDICT.txt"; : > "$V"
LOCK=/c/tmp/futari_drive.lock; HAVE=0
rel(){ [ "$HAVE" = 1 ] && rmdir "$LOCK" 2>/dev/null; HAVE=0; }
trap 'pkill -x "$PN" 2>/dev/null; rel' EXIT
W=0
while :; do
  if mkdir "$LOCK" 2>/dev/null; then HAVE=1
    if pgrep -x futari_merged >/dev/null; then rel; else break; fi
  fi
  [ $W -ge "${LOCKWAIT:-7200}" ] && { echo "NO LOCK after ${W}s" | tee -a "$OUT"; exit 3; }; sleep 60; W=$((W+60))
done
FIFO=/c/tmp/futari_pad_rcc; echo 0 > "$FIFO"
SAVE="_local/saves/rc_census_$TAG"; rm -rf "$SAVE"; cp -R "_local/saves/save_rc1_rc1m_$MODE" "$SAVE"
L="_local/logs/rc_census_${TAG}.log"; mkdir -p _local/logs
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
[ "$MODE" = x360 ] && export RT_NAV360=1
"$BIN" 8208A2B8 0 "$XR_SHELL_XEX" 2>"$L" &
PID=$!
T0=$(date +%s); say(){ echo "t+$(( $(date +%s)-T0 ))s $*" | tee -a "$OUT"; }
say "census $TAG mode=$MODE min=$MIN bin=$BIN pid=$PID log=$L lockwait=${W}s start=$(date '+%F %T')"
cnt(){ grep -a -c -- "$1" "$L"; }
fin(){ kill "$PID" 2>/dev/null; sleep 2; kill -9 "$PID" 2>/dev/null; wait "$PID" 2>/dev/null; pkill -x "$PN" 2>/dev/null
  grep -a 'DROPOUT-CONFIRMED\|\[census\] status' "$L" > "$B/census_lines.txt"; grep -a 'DROPOUT-CONFIRMED' "$L" > "$B/dropouts.txt"; cp "$L" "$B/guest.log"; rel; }
verdict(){ # $1 = abort reason or empty
  local f=$(cnt FATAL) v=$(cnt 'VK_ERROR\|VUID') s=$(cnt '\[slowframe\]') u st bad named
  u=$(grep -a -o 'underruns=[0-9]*' "$L" | awk -F= '{x+=$2} END{print x+0}'); st=$(cnt 'live sink stalled')
  named=$(grep -a 'DROPOUT-CONFIRMED' "$L" | grep -a -c 'base=0x2530000\|base=0x34E0000\|base=0x49C4000\|len=1 base=0x34[0-9A-F]0000 .*v0=(41.5,-284.5)\|base=0x2[0-9A-F]*0000 .*v0=(-190.5,181.5)\|len=3 base=0x1C[0-9A-F]4000 .*v0=(253.5,273.6)\|len=2 base=0x1C[0-9A-F]4000 .*v0=(251.0,-5.4)')
  bad=$(grep -a 'DROPOUT-CONFIRMED' "$L" | grep -a -vc 'base=0x2530000\|base=0x34E0000\|base=0x49C4000\|len=1 base=0x34[0-9A-F]0000 .*v0=(41.5,-284.5)\|base=0x2[0-9A-F]*0000 .*v0=(-190.5,181.5)\|len=3 base=0x1C[0-9A-F]4000 .*v0=(253.5,273.6)\|len=2 base=0x1C[0-9A-F]4000 .*v0=(251.0,-5.4)')
  local fr; fr=$(awk -F, 'NR>1&&$3!=""{ if(p!=""){d=$3-p; if(d<3590||d>3610) n++} p=$3 } END{print n+0}' "$B/rss.csv" 2>/dev/null)
  local pr=0; [ -s "$B/rss.csv" ] || pr=1
  { echo "census $TAG mode=$MODE minutes=$MIN"; echo "FATAL=$f VKERR=$v SLOW=$s UNDERRUN=$u SINKSTALL=$st"
    echo "INFO named-class dropouts: $named (0x2530000 strobe / 0x34E0000 card-LEFT / 0x49C4000 pair / 0x1C?4000 360 loading rings)"
    echo "dropouts outside the named classes: $bad"; echo "hands-off minutes off 3600+-10 frames (60 s samples): $fr"
    [ -n "$1" ] && echo "ABORT: $1"; } >> "$V"
  local r=PASS; { [ -n "$1" ] || [ "$f" != 0 ] || [ "$v" != 0 ] || [ "$s" != 0 ] || [ "$u" != 0 ] || [ "$st" != 0 ] || [ "$bad" != 0 ] || [ "$fr" != 0 ] || [ $pr = 1 ]; } && r=FAIL
  echo "RESULT: $r" >> "$V"; say "RESULT $r"; cat "$V"; [ $r = PASS ]; }
die(){ say "FAIL: $*"; fin; verdict "$*"; exit 1; }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; }
MARK=0; mark(){ MARK=$(wc -l < "$L" | tr -d ' '); }
waitnew(){ local pat="$1" n="${2:-20}" i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$L" | grep -a -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
step(){ local pad="$1" pat="$2" settle="$3" try; for try in 1 2; do mark; press "$pad"; waitnew "$pat" && { say "pad $pad -> $pat"; sleep "$settle"; return 0; }; done; die "no $pat after pad $pad"; }
for ((i=0;i<120;i++)); do grep -a -q "name='motion/title.lzx'" "$L" && break; kill -0 "$PID" 2>/dev/null || die "process died before title"; sleep 1; done
grep -a -q "name='motion/title.lzx'" "$L" || die "no title"
say "shell title loaded; idle ${SHELL_SECS:-120} s"; sleep 4; sleep "${SHELL_SECS:-120}"
step 10   'SYS_BGM cue0 (mushifuta_Menu02)' 4
step 1000 'SYS_SE cue1 (SE_OK01)' 3
if [ "$MODE" = x360 ]; then
  mark; press 4; sleep 3.6; press 1000
  waitnew '\[modeidx\] .*XBOX-360' 20 || die "no modeidx XBOX-360"
  MARK=0; mark; waitnew '\[modswap\] #2 DONE' 240 || die "no modswap #2"; say "module swap #2 DONE"
else step 1000 '\[modeidx\] .*ARCADE' 20 2; fi
SAMPLES="$B/rss.csv"; echo "t_s,rss_mb,frame" > "$SAMPLES"
samp(){ local rss f; rss=$(ps -o rss= -p "$PID" 2>/dev/null | tr -d ' '); [ -n "$rss" ] || return 1; f=$(grep -a -o "submit f[0-9]*" "$L" | tail -1 | tr -dc 0-9); echo "$(( $(date +%s)-T0 )),$((rss/1024)),$f" >> "$SAMPLES"; RSSNOW=$((rss/1024)); FNOW=$f; return 0; }
say "mode decided; HANDS OFF ${MIN} min"; samp
TS0=$(date +%s)   # sample on an ALIGNED minute grid: the frame criterion (3600 +-10 per 60 s) needs the sampling interval itself to be 60 s, so the
for ((m=1; m<=MIN; m++)); do   # sleep is "until TS0 + 60*m", not "60 s after the previous sample" (a slow RSS probe -- 2 s on Windows -- would stretch it)
  sleep $(( TS0 + 60*m - $(date +%s) > 0 ? TS0 + 60*m - $(date +%s) : 0 )); samp || { say "t+${m}m: PROCESS GONE"; fin; verdict "engine died during the hands-off phase"; exit 1; }
  say "t+${m}m rss=${RSSNOW}MB frames=$FNOW fatal=$(cnt FATAL) slowframe=$(cnt '\[slowframe\]') dropout=$(cnt 'DROPOUT-CONFIRMED')"
done
fin; verdict ""
