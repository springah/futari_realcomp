#!/bin/bash
# rc_census_mac.sh <tag> <BIN> <arcade|x360> [minutes=6]  -- the Q1 flicker-census route on a GIVEN engine binary (RC1 PLAN §6.5 item 2).
# ONE launch: shell title idle SHELL_SECS (default 120) -> START -> top menu -> card (x360: LEFT first) -> mode decide -> HANDS OFF <minutes>
# (the demo loop) with RVK_DRAWCENSUS=2, per-30 s RSS/frame samples. Adapted from _local/rc1/q1/q1_run.sh (the env block is its verbatim copy) with the
# binary as a parameter. The engine is killed with `pkill -x <basename BIN>` ONLY (use a uniquely named copy; rc_cut_mac.sh makes one).
# Verdict (RESULT: PASS|FAIL on the last line of <bank>/VERDICT.txt, exit 0/1; exit 3 = no lock):
#   FAIL on any FATAL, VK_ERROR/VUID, [slowframe], audio underrun (bar ONE stall-adjacent window, ruling 2026-11-03), live-sink stall, a hands-off minute outside 3600 +-10 frames, or any
#   DROPOUT-CONFIRMED whose base is not a NAMED AUTHENTIC deterministic class: 0x2530000 (PRESS START strobe), 0x34E0000 (360 card-LEFT quad),
#   0x49C4000 (w136 menu-atlas pair); the strobe and the card-LEFT quad are also matched by their v0 key ((-190.5,181.5) / len=1 v0=(41.5,-284.5)) because the
#   base moves between builds (0x34E0000 on the Q1 probe, 0x34D0000 on the RC bundle engine) -- Q9/G11, docs/NOTE_fnf_shell_defects.md 2026-10-12;
#   360 NOW-LOADING ring particles (the two hand-over lines of the 0.3.0-rc1 dry run): len=3 v0=(253.5,273.6) and len=2 v0=(251.0,-5.4), base
#   0x1C?4000 (0x1C04000/0x1C44000 on the dry-run engine, 0x1C14000/0x1C54000 on the HEAD probes; 0x1C18000/0x1C58000 on the 0.3.0-rc5 engine,
#   i.e. 0x1C?[48]000 -- the page moves with the build, the frame/len/v0 key does not) -- a ring-sprite type with zero live particles
#   between its last particle expiring and the next burst; occurs only for some press timings, identical when the presses land on the same guest
#   ticks (NOTE_fnf_shell_defects.md 2026-10-12 "360 NOW-LOADING ring particles").  Named-class hits are listed as INFO.
# DRIVE LOCK: mkdir /tmp/futari_drive.lock, 60 s polls up to LOCKWAIT s (default 7200), also waits while `pgrep -x futari_merged` (someone is playing);
# rmdir only a lock this process created. Bank: ${RCC_ROOT:-_local/rc/census}/<tag>/.
# OPT-IN ARMS (2026-11-07; both unset = the gate above, unchanged):
#   CENSUS_APP=<path to .app> (BIN arg ignored, pass -): launch THE BUNDLE through LaunchServices (`open --env ... -a`, as app_smoke_mac.sh;
#     the pad FIFO must show on the [padhost] line) instead of a bare engine copy, the census levers passed by --env, RT_SAVE still a private
#     copy under _local/saves/. CENSUS_FS=1 (the default in this arm; 0 = windowed control of the same bundle) presses F11 at the title through
#     mac-build/fs_inject.m (DYLD_INSERT_LIBRARIES; posts a real F11 NSEvent into the app's own queue -- ssh cannot type keys, it is not
#     Accessibility-trusted) and requires "[rvk][win] F11 -> fullscreen". Game Mode is READ from gamepolicyd (`log stream`, subsystem
#     com.apple.gamepolicyd: "Full screen gaming session is now active", "Game mode status is now on|paused|off") and reported as INFO
#     gamemode=ON(held)|ON(lost..)|PAUSED|OFF|NONE -- it never changes RESULT. This arm scores every underrun (RT_CENSUS_NOFORGIVE defaults to 1).
#     Engine kills target only the pid this run started (never `pkill -x futari_merged`).
#   CENSUS_INFO=1 (any arm; implied by CENSUS_APP): INFO lines with the `[vblank] stall` marker count and the CPU of mediaanalysisd /
#     mds_stores / mdworker_shared / mds before, per minute (backgrounded after the frame sample) and after -- arm-symmetric instruments.
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; BIN="${2:?bin}"; MODE="${3:?arcade|x360}"; MIN="${4:-6}"; PN="$(basename "$BIN")"
APPARM=0; INFO="${CENSUS_INFO:-0}"
if [ -n "${CENSUS_APP:-}" ]; then APPARM=1; INFO=1; FS="${CENSUS_FS:-1}"; : "${RT_CENSUS_NOFORGIVE=1}"
  [ "$(uname)" = Darwin ] || { echo "CENSUS_APP is macOS-only"; exit 2; }
  [ -x "$CENSUS_APP/Contents/MacOS/Futari Realcomp" ] || { echo "no launcher in $CENSUS_APP"; exit 2; }
  BIN="$(cd "$CENSUS_APP" && pwd -P)/Contents/MacOS/futari_merged"; PN=""
  FSLIB="$PWD/build/fs_inject.dylib"
  if [ "$FS" = 1 ] && { [ ! -f "$FSLIB" ] || [ mac-build/fs_inject.m -nt "$FSLIB" ]; }; then mkdir -p build
    clang -dynamiclib -fobjc-arc -framework AppKit -o "$FSLIB" mac-build/fs_inject.m || { echo "fs_inject build failed"; exit 2; }; fi
fi
kpn(){ if [ $APPARM = 1 ]; then [ -n "${PID:-}" ] && kill "$PID" 2>/dev/null; else pkill -x "$PN" 2>/dev/null; fi; }
dcpu(){ top -l 2 -s 1 -stats command,cpu 2>/dev/null | awk -v t="$1" '/^COMMAND/{blk++} blk==2 && $1~/^(mediaanalysisd|mds_stores|mdworker_shared|mds)$/{c[$1]+=$2} END{printf "%s", t; for(k in c) printf " %s=%.1f", k, c[k]; print ""}'; }
[ -x "$BIN" ] || { echo "no $BIN"; exit 2; }
case "$MODE" in arcade|x360) ;; *) echo "mode arcade|x360"; exit 2;; esac
B="${RCC_ROOT:-_local/rc/census}/$TAG"; rm -rf "$B"; mkdir -p "$B/png.noindex"; OUT="$B/steps.txt"; : > "$OUT"; V="$B/VERDICT.txt"; : > "$V"
LOCK=/tmp/futari_drive.lock; HAVE=0
rel(){ [ "$HAVE" = 1 ] && rmdir "$LOCK" 2>/dev/null; HAVE=0; }
trap 'kpn; [ -n "${GMPID:-}" ] && kill "$GMPID" 2>/dev/null; rel' EXIT
W=0
while :; do
  if mkdir "$LOCK" 2>/dev/null; then HAVE=1
    if pgrep -x futari_merged >/dev/null; then rel; else break; fi
  fi
  [ $W -ge "${LOCKWAIT:-7200}" ] && { echo "NO LOCK after ${W}s" | tee -a "$OUT"; exit 3; }; sleep 60; W=$((W+60))
done
FIFO=/tmp/futari_pad_rcc; echo 0 > "$FIFO"
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
export RT_NVKPNG=300 RVK_DUMPDIR="$PWD/$B/png.noindex"
export RVK_DRAWCENSUS=2 RVK_TITLEPROBE=1
[ "${TICKLOG:-0}" = 1 ] && export RT_TICKLOG=1   # opt-in (Windows gates pass TICKLOG=1): one [tick] p<N> line per present, an EXACT frame count for the sampler below
[ "$MODE" = x360 ] && export RT_NAV360=1
[ "$INFO" = 1 ] && dcpu pre > "$B/daemon_cpu.txt"
if [ $APPARM = 1 ]; then
  ALOGS="$HOME/Library/Logs/Futari Realcomp"; PREV=$(ls -t "$ALOGS"/futari_*.log 2>/dev/null | head -1)
  log stream --style compact --predicate 'subsystem == "com.apple.gamepolicyd"' > "$B/gamepolicy.log" 2>&1 & GMPID=$!
  ENVS=(--env "RT_PAD_HOST_FIFO=$FIFO" --env "RT_SAVE=$PWD/$SAVE" --env RT_SAMPLES=0 --env RT_AUDIOSTARVE=1 --env RT_NVKPNG=300
        --env "RVK_DUMPDIR=$PWD/$B/png.noindex" --env RVK_DRAWCENSUS=2 --env RVK_TITLEPROBE=1)
  [ -n "${RT_TICKLOG:-}" ] && ENVS+=(--env RT_TICKLOG=1); [ "$MODE" = x360 ] && ENVS+=(--env RT_NAV360=1)
  [ "$FS" = 1 ] && ENVS+=(--env "DYLD_INSERT_LIBRARIES=$FSLIB" --env "FUTARI_FS_TRIGGER=$PWD/$B/fs_now")
  sleep 1; open "${ENVS[@]}" -a "$CENSUS_APP" || { echo "open failed" | tee -a "$OUT"; exit 1; }
  NL=""; for ((i=0;i<60;i++)); do NL=$(ls -t "$ALOGS"/futari_*.log 2>/dev/null | head -1); [ -n "$NL" ] && [ "$NL" != "$PREV" ] && break; NL=""; sleep 0.5; done
  [ -n "$NL" ] || { echo "no new log in $ALOGS" | tee -a "$OUT"; exit 1; }
  L="$NL"; PID=""
  for ((i=0;i<40;i++)); do PID=$(pgrep -f -- "$BIN" | while read -r p; do ps -o command= -p "$p" 2>/dev/null | grep -qF -- "$BIN" && echo "$p"; done | head -1); [ -n "$PID" ] && break; sleep 0.25; done
  [ -n "$PID" ] || { echo "bundle engine not found" | tee -a "$OUT"; exit 1; }
else
"$BIN" 8208A2B8 0 "$XR_SHELL_XEX" 2>"$L" &
PID=$!
fi
T0=$(date +%s); say(){ echo "t+$(( $(date +%s)-T0 ))s $*" | tee -a "$OUT"; }
say "census $TAG mode=$MODE min=$MIN bin=$BIN pid=$PID log=$L lockwait=${W}s start=$(date '+%F %T')"
cnt(){ grep -a -c -- "$1" "$L"; }
fin(){ [ -n "${GMPID:-}" ] && { kill "$GMPID" 2>/dev/null; GMPID=""; }   # stop reading gamepolicyd BEFORE the engine exits (its exit flips the status off)
  kill "$PID" 2>/dev/null; sleep 2; kill -9 "$PID" 2>/dev/null; wait "$PID" 2>/dev/null; kpn
  [ "$INFO" = 1 ] && dcpu post >> "$B/daemon_cpu.txt"
  grep -a 'DROPOUT-CONFIRMED\|\[census\] status' "$L" > "$B/census_lines.txt"; grep -a 'DROPOUT-CONFIRMED' "$L" > "$B/dropouts.txt"; cp "$L" "$B/guest.log"; rel; }
verdict(){ # $1 = abort reason or empty
  local f=$(cnt FATAL) v=$(cnt 'VK_ERROR\|VUID') s=$(cnt '\[slowframe\]') u st bad named
  u=$(grep -a -o 'underruns=[0-9]*' "$L" | awk -F= '{x+=$2} END{print x+0}'); st=$(cnt 'live sink stalled')
  # ⚖ ruling 2026-11-03: ONE underrun window per run that is the first such window within 40 log lines after a
  # `[vblank] stall: deadline forgiven` line (the present loop >4 frame periods behind = the whole process off the CPU = the box,
  # not audio; NOTE_fnf_shell_defects 2026-11-03 "later still") is reported and not scored. A second window, or one with no stall
  # line before it, is scored as before. RT_CENSUS_NOFORGIVE=1 scores everything.
  local ufg=0 ufw=0 ue
  if [ -z "${RT_CENSUS_NOFORGIVE:-}" ]; then
    read -r ufg ufw <<<"$(awk '/\[vblank\] stall: deadline forgiven/{ls=NR} /underruns=[1-9]/{ if(ls && NR-ls<=40 && fw<1){ match($0,/underruns=[0-9]+/); fg+=substr($0,RSTART+10,RLENGTH-10); fw++ } ls=0 } END{print fg+0, fw+0}' "$L")"
  fi
  ue=$((u-ufg))
  named=$(grep -a 'DROPOUT-CONFIRMED' "$L" | grep -a -c 'base=0x2530000\|base=0x34E0000\|base=0x49C4000\|len=1 base=0x34[0-9A-F]0000 .*v0=(41.5,-284.5)\|base=0x2[0-9A-F]*0000 .*v0=(-190.5,181.5)\|len=3 base=0x1C[0-9A-F][48]000 .*v0=(253.5,273.6)\|len=2 base=0x1C[0-9A-F][48]000 .*v0=(251.0,-5.4)')
  bad=$(grep -a 'DROPOUT-CONFIRMED' "$L" | grep -a -vc 'base=0x2530000\|base=0x34E0000\|base=0x49C4000\|len=1 base=0x34[0-9A-F]0000 .*v0=(41.5,-284.5)\|base=0x2[0-9A-F]*0000 .*v0=(-190.5,181.5)\|len=3 base=0x1C[0-9A-F][48]000 .*v0=(253.5,273.6)\|len=2 base=0x1C[0-9A-F][48]000 .*v0=(251.0,-5.4)')
  local fr
  if [ -n "${RT_TICKLOG:-}" ]; then   # exact per-present counts + ms timestamps: score the RATE per interval, 59.94 +-0.2 fps (= the +-10/3600 band)
    fr=$(awk -F, 'NR>1&&$3!=""&&$4!=""{ if(p!=""){r=($3-p)*1000/($4-pt); if(r<59.74||r>60.14) n++} p=$3; pt=$4 } END{print n+0}' "$B/rss.csv" 2>/dev/null)
  else fr=$(awk -F, 'NR>1&&$3!=""{ if(p!=""){d=$3-p; if(d<3590||d>3610) n++} p=$3 } END{print n+0}' "$B/rss.csv" 2>/dev/null); fi
  local pr=0; [ -s "$B/rss.csv" ] || pr=1
  { echo "census $TAG mode=$MODE minutes=$MIN"; echo "FATAL=$f VKERR=$v SLOW=$s UNDERRUN=$ue SINKSTALL=$st"
    [ "$ufw" != 0 ] && echo "INFO underruns forgiven as stall-adjacent (ruling 2026-11-03): $ufg in $ufw window right after a [vblank] stall line (raw UNDERRUN=$u)"
    echo "INFO named-class dropouts: $named (0x2530000 strobe / 0x34E0000 card-LEFT / 0x49C4000 pair / 0x1C?[48]000 360 loading rings)"
    echo "dropouts outside the named classes: $bad"; echo "hands-off minutes off 3600+-10 frames (60 s samples): $fr"
    if [ "$INFO" = 1 ]; then echo "INFO [vblank] stall markers: $(cnt '\[vblank\] stall') (forgive rule $([ -n "${RT_CENSUS_NOFORGIVE:-}" ] && echo OFF || echo ON))"
      echo "INFO daemon CPU % (top, 1 s): $(head -1 "$B/daemon_cpu.txt" 2>/dev/null) | max per minute: $(grep '^m' "$B/daemon_cpu.txt" 2>/dev/null | awk '{for(i=2;i<=NF;i++){split($i,a,"=");if(a[2]+0>m[a[1]]+0)m[a[1]]=a[2]}} END{for(k in m) printf "%s=%.1f ", k, m[k]}')| $(grep '^post' "$B/daemon_cpu.txt" 2>/dev/null)"; fi
    if [ $APPARM = 1 ]; then local g="$B/gamepolicy.log" gm fsl
      fsl=$(grep -a -c '\[rvk\]\[win\] F11 -> fullscreen' "$L")
      gm=$(awk '/Game mode status is now on/{s="on"; seen=1; next} /Game mode status is now (paused|off)/{ if(seen) lost=1; s=($0~/paused/)?"paused":"off" }
               END{ if(seen && !lost) print "ON(held)"; else if(seen) print "ON(lost,last=" s ")"; else if(s=="paused") print "PAUSED"; else if(s=="off") print "OFF"; else print "NONE" }' "$g" 2>/dev/null)
      echo "INFO app arm: bundle=$CENSUS_APP fs=$FS F11-fullscreen-lines=$fsl gamemode=$gm (gamepolicyd: $(grep -a -c 'Full screen gaming session is now active' "$g" 2>/dev/null) full-screen-session-active, $(grep -a -c 'Game mode status is now on' "$g" 2>/dev/null) status-on, $(grep -a -c 'Game mode status is now paused' "$g" 2>/dev/null) paused, $(grep -a -c 'Game mode status is now off' "$g" 2>/dev/null) off; log $g)"; fi
    [ -n "$1" ] && echo "ABORT: $1"; } >> "$V"
  local r=PASS; { [ -n "$1" ] || [ "$f" != 0 ] || [ "$v" != 0 ] || [ "$s" != 0 ] || [ "$ue" != 0 ] || [ "$st" != 0 ] || [ "$bad" != 0 ] || [ "$fr" != 0 ] || [ $pr = 1 ]; } && r=FAIL
  echo "RESULT: $r" >> "$V"; say "RESULT $r"; cat "$V"; [ $r = PASS ]; }
die(){ say "FAIL: $*"; fin; verdict "$*"; exit 1; }
press(){ echo "$1" > "$FIFO"; sleep 0.2; echo 0 > "$FIFO"; }
MARK=0; mark(){ MARK=$(wc -l < "$L" | tr -d ' '); }
waitnew(){ local pat="$1" n="${2:-20}" i; for ((i=0;i<n;i++)); do tail -n +"$((MARK+1))" "$L" | grep -a -q -- "$pat" && return 0; sleep 0.5; done; return 1; }
step(){ local pad="$1" pat="$2" settle="$3" try; for try in 1 2; do mark; press "$pad"; waitnew "$pat" && { say "pad $pad -> $pat"; sleep "$settle"; return 0; }; done; die "no $pat after pad $pad"; }
for ((i=0;i<120;i++)); do grep -a -q "name='motion/title.lzx'" "$L" && break; kill -0 "$PID" 2>/dev/null || die "process died before title"; sleep 1; done
grep -a -q "name='motion/title.lzx'" "$L" || die "no title"
if [ $APPARM = 1 ]; then grep -a -q "padhost\] ACTIVE.*host FIFO" "$L" || die "pad FIFO NOT wired into the app (no '+ host FIFO' on the [padhost] line)"; say "app arm: pid=$PID log=$L pad FIFO wired"; fi
if [ $APPARM = 1 ] && [ "$FS" = 1 ]; then sleep 2; mark; touch "$B/fs_now"
  waitnew '\[rvk\]\[win\] F11 -> fullscreen' 30 || die "F11 posted but no '[rvk][win] F11 -> fullscreen' line"; say "fullscreen: $(tail -n +"$((MARK+1))" "$L" | grep -a -m1 'F11 -> fullscreen')"
  for ((i=0;i<30;i++)); do grep -a -q 'Game mode status is now on' "$B/gamepolicy.log" && break; sleep 0.5; done
  say "gamepolicyd after F11: $(grep -a 'Game mode status is now\|Full screen gaming session' "$B/gamepolicy.log" | tail -2 | sed 's/.*Common\] //' | tr '\n' ';')"; fi
say "shell title loaded; idle ${SHELL_SECS:-120} s"; sleep 4; sleep "${SHELL_SECS:-120}"
step 10   'SYS_BGM cue0 (mushifuta_Menu02)' 4
step 1000 'SYS_SE cue1 (SE_OK01)' 3
if [ "$MODE" = x360 ]; then
  mark; press 4; sleep 3.6; press 1000
  waitnew '\[modeidx\] .*XBOX-360' 20 || die "no modeidx XBOX-360"
  # keep the mark from BEFORE the card press: on Windows the DLL swap completes within a few lines of [modeidx], so a fresh mark here
  # could land after the DONE line and the wait would time out (seen once, 2026-10-29); the DONE line can only ever follow the press
  waitnew '\[modswap\] #2 DONE' 240 || die "no modswap #2"; say "module swap #2 DONE"
else step 1000 '\[modeidx\] .*ARCADE' 20 2; fi
SAMPLES="$B/rss.csv"; echo "t_s,rss_mb,frame,t_ms" > "$SAMPLES"
samp(){ local rss f; rss=$(ps -o rss= -p "$PID" 2>/dev/null | tr -d ' '); [ -n "$rss" ] || return 1
  # frame = the last [tick] p<N> when RT_TICKLOG is on (exact, per present), else the last "submit f<N>" (quantised to 300 frames: with a
  # sampling interval that is not exactly 60 s the 3600 +-10 criterion then reads 3300/3900 -- the Windows twin's finding, 2026-10-29)
  if [ -n "${RT_TICKLOG:-}" ]; then f=$(tail -c 20000 "$L" | grep -a -o '^\[tick\] p[0-9]*' | tail -1 | tr -dc 0-9); fi
  [ -n "${f:-}" ] || f=$(grep -a -o "submit f[0-9]*" "$L" | tail -1 | tr -dc 0-9)
  echo "$(( $(date +%s)-T0 )),$((rss/1024)),$f,$(date +%s%3N)" >> "$SAMPLES"; RSSNOW=$((rss/1024)); FNOW=$f; return 0; }
say "mode decided; HANDS OFF ${MIN} min"; samp
TS0=$(date +%s)   # sample on an ALIGNED minute grid: the frame criterion (3600 +-10 per 60 s) needs the sampling interval itself to be 60 s, so the
for ((m=1; m<=MIN; m++)); do   # sleep is "until TS0 + 60*m", not "60 s after the previous sample" (a slow RSS probe -- 2 s on Windows -- would stretch it)
  sleep $(( TS0 + 60*m - $(date +%s) > 0 ? TS0 + 60*m - $(date +%s) : 0 )); samp || { say "t+${m}m: PROCESS GONE"; fin; verdict "engine died during the hands-off phase"; exit 1; }
  say "t+${m}m rss=${RSSNOW}MB frames=$FNOW fatal=$(cnt FATAL) slowframe=$(cnt '\[slowframe\]') dropout=$(cnt 'DROPOUT-CONFIRMED')"
  [ "$INFO" = 1 ] && { dcpu "m$m" >> "$B/daemon_cpu.txt" & }
done
fin; verdict ""
