#!/bin/bash
# rc_gates_win.sh <version>  -- the Windows twin of rc_cut_mac.sh step (c): run the scripted RC smoke against the STAGED Windows folder
# (scripts/rc_stage_win.sh output) and write ../_rc/<version>-win/SMOKE.md. Steps, each PASS/FAIL, all run even after a FAIL:
#   1 boot_smoke   scripts/rc_smoke_win.sh on the staged folder itself (build id = HEAD, 2/2 modules bound, 0 FATAL, 0 VK_ERROR)
#   2 gstart       scripts/gstart_win.sh ARCADE (HUBSTART=1) + XBOX 360 -- no LEAK=YES row
#   3 q1_ctest     scripts/q7v_run_win.sh ... ctest 240 1 : RVK_CENSUSTEST positive control: every injected dropout confirmed (>= 60 in 240 s)
#   4 q1_census    scripts/rc_census_win.sh arcade + x360 : single launch, dropouts only in the named AUTHENTIC classes, 0 FATAL/VK/slow/underrun, 3600 fpm
#   5 rc_chain     scripts/rc_chain_win.sh all (swap x5, restart, continue, score-attack decline, remap; both modes) + T2 (DC-1) + CX (DC-2)
# Steps 2-5 run a BYTE-IDENTICAL copy of the staged futari_combined.exe (cmp-checked, md5 in SMOKE.md) renamed `rcwin_eng.exe` beside copies of the
# staged module DLLs, under _rc/<version>-win/smoke_engine/, so `taskkill /IM rcwin_eng.exe` can only ever hit it and the gates' FIFO/save/log
# plumbing never touches the staged folder. Same bytes = same code; the folder-only properties (launcher .bat, README) are the user's hands.
# The gate scripts take the drive lock (/c/tmp/futari_drive.lock) per leg and wait while futari_combined.exe (the launcher's image) is running.
#   bash scripts/rc_gates_win.sh 0.3.0-rc2                       # all five steps, ~1.5 h; fresh SMOKE.md (the old one -> SMOKE.prev.md)
#   STEPS="q1_ctest q1_census" bash scripts/rc_gates_win.sh 0.3.0-rc2   # a subset: rows are APPENDED to the existing SMOKE.md, tagged "re-run HH:MM"
#   CHAIN_ITEMS="E" ...                                          # rc_chain items for step 5 (default "all T2 CX"; the Mac cut's set)
#   CENSUS_MIN=<n> SHELL_SECS=<s> LOCKWAIT=<s>                   # as in rc_cut_mac.sh
set -u
cd "$(dirname "$0")/.."
source scripts/win_shim.sh
REPO="$PWD"; PROJ="$(cd .. && pwd)"
VER="${1:?usage: rc_gates_win.sh <version>}"
RC="$PROJ/_rc"; RD="$RC/$VER-win"; NAME="Futari-Realcomp-Windows-v$VER"; ST="$RD/$NAME"; SMOKE="$RD/SMOKE.md"; LG="$RD/logs"
ENGDIR="$RD/smoke_engine"; PN=rcwin_eng.exe; ENG="$ENGDIR/$PN"
SAFE="$(echo "$VER" | tr -c 'A-Za-z0-9\n' '_')"; BANK="_local/rc/$SAFE"; LOCKWAIT="${LOCKWAIT:-7200}"
STEPS="${STEPS:-boot_smoke gstart q1_ctest q1_census rc_chain}"; CHAIN_ITEMS="${CHAIN_ITEMS:-all T2 CX}"
SUBSET=0; [ "$STEPS" != "boot_smoke gstart q1_ctest q1_census rc_chain" ] && SUBSET=1
die(){ echo "[gates] STOP: $*" >&2; exit 1; }
log(){ echo "[gates] $(date +%H:%M:%S) $*"; }
trap 'pkill -x "$PN" 2>/dev/null' EXIT
[ -f "$ST/futari_combined.exe" ] || die "no staged folder $ST (run scripts/rc_stage_win.sh $VER)"
mkdir -p "$LG" "$BANK"
HR=$(git rev-parse HEAD); HD=$(git -C "$PROJ/futari_decomp" rev-parse HEAD)
BID=$(sed -n 's/^exe_build_id=//p' "$ST/BUILD.txt" 2>/dev/null)

# ---- the engine copy (re-made every run; cmp-checked against the staged exe)
rm -rf "$ENGDIR"; mkdir -p "$ENGDIR"
cp "$ST/futari_combined.exe" "$ENG"; cp "$ST/futari_game_normal.dll" "$ST/futari_game_abn.dll" "$ENGDIR/"
cmp -s "$ENG" "$ST/futari_combined.exe" && CMP=IDENTICAL || die "engine copy differs from the staged exe"
ENGMD5=$(md5sum "$ENG" | cut -c1-32)
if [ $SUBSET = 1 ] && [ -f "$SMOKE" ]; then
  TAGRUN=" (re-run $(date +%H:%M))"; { echo; echo "re-run $(date '+%F %T') of: $STEPS -- engine copy $CMP, md5 $ENGMD5, realcomp \`$HR\`"; echo; echo "| step | result | secs | detail |"; echo "|---|---|---|---|"; } >> "$SMOKE"
else
  TAGRUN=""; [ -f "$SMOKE" ] && mv -f "$SMOKE" "$RD/SMOKE.prev.md"
  { echo "# SMOKE -- $VER (WINDOWS, staged folder)"; echo
    echo "- started $(date '+%F %T'); folder \`$ST\` ($(du -sh "$ST" | cut -f1)); exe build id ${BID:-?}"
    echo "- futari_realcomp \`$HR\`; futari_decomp \`$HD\`"
    echo "- script-driven steps run \`$ENG\` = a copy of the staged futari_combined.exe ($CMP, md5 $ENGMD5) beside copies of the staged module DLLs"
    echo; echo "| step | result | secs | detail |"; echo "|---|---|---|---|"; } > "$SMOKE"
fi

# ---- step machinery (rc_cut_mac.sh (c), Windows names)
FAILED=""; DETAIL=""
others(){ pgrep -x futari_combined.exe 2>/dev/null; }     # the launcher's image = the user is playing
wait_quiet(){ local w=0; while [ -n "$(others)" ]; do [ $w -ge "$LOCKWAIT" ] && return 1; [ $((w%600)) = 0 ] && log "waiting: futari_combined.exe is running ($(others | tr '\n' ' '))"; sleep 60; w=$((w+60)); done; return 0; }
run_step(){ local name="$1" fn="$2" t0 r=""; case " $STEPS " in *" $name "*) ;; *) return 0;; esac
  t0=$(date +%s); log ">>> step $name"; DETAIL=""
  wait_quiet || { DETAIL="futari_combined.exe ran for ${LOCKWAIT}s"; r=FAIL; }
  if [ -z "$r" ]; then "$fn" > "$LG/$name${TAGRUN:+_rerun}.log" 2>&1 && r=PASS || r=FAIL; fi
  echo "| $name$TAGRUN | **$r** | $(( $(date +%s)-t0 )) | ${DETAIL//|/\/} |" >> "$SMOKE"; log "<<< step $name: $r  ${DETAIL}"
  [ $r = FAIL ] && FAILED="$FAILED $name"; return 0; }

s_boot_smoke(){ bash scripts/rc_smoke_win.sh "$ST" 75; local rc=$?
  DETAIL="$(grep -a 'WIN SMOKE:' "$LG/boot_smoke${TAGRUN:+_rerun}.log" | tail -1 | tr -d '\n'); $(grep -a -c '^\[smoke\] PASS' "$LG/boot_smoke${TAGRUN:+_rerun}.log") PASS lines"; return $rc; }

s_gstart(){ local rc=0 m tag tbl
  for m in arcade x360; do tag="rc_${SAFE}_$m"
    if [ $m = arcade ]; then HUBSTART=1 bash scripts/gstart_win.sh "$tag" "$ENG" arcade; else bash scripts/gstart_win.sh "$tag" "$ENG" x360; fi
    tbl="_local/gstart/$tag/TABLE.txt"
    if [ ! -s "$tbl" ]; then echo "gstart $m: no TABLE (run failed)"; rc=1; DETAIL="$DETAIL $m: NO TABLE;"; continue; fi
    if grep -q ' YES$' "$tbl"; then echo "gstart $m: LEAK rows:"; grep ' YES$' "$tbl"; rc=1; DETAIL="$DETAIL $m: LEAK ($(grep -c ' YES$' "$tbl") rows);"
    else DETAIL="$DETAIL $m: $(wc -l < "$tbl" | tr -d ' ') probes, 0 leaks;"; fi
    [ "$(grep -c FATAL "_local/gstart/$tag/guest.log" 2>/dev/null)" = 0 ] || { rc=1; DETAIL="$DETAIL $m: FATAL;"; }
  done; return $rc; }

s_q1_ctest(){ LOCKWAIT_MIN=$((LOCKWAIT/60)) bash scripts/q7v_run_win.sh "rc_$SAFE" "$ENG" ctest 240 1; local o="_local/rc1/q7v/rc_$SAFE/steps.txt" e d t
  e=$(grep -a 'END ' "$o" | tail -1); echo "$e"
  # PASS = every injected dropout confirmed (dropout == testmarks) and >= 60 in the 240 s window; the count is not fixed at 60: the injector arms per
  # guest frame from the title load, so a run that reaches the title a little earlier arms 61 (first Windows run, 2026-10-29). Same rule in rc_cut_mac.sh.
  d=$(echo "$e" | grep -o 'dropout=[0-9]*' | tr -dc 0-9); t=$(echo "$e" | grep -o 'testmarks=[0-9]*' | tr -dc 0-9)
  if [ -n "$d" ] && [ "$d" = "$t" ] && [ "$d" -ge 60 ] && echo "$e" | grep -q 'fatal=0 vkerr=0'; then DETAIL="positive control $d DROPOUT-CONFIRMED for $t INJECT"; return 0; fi
  DETAIL="control off: ${e#*END }"; return 1; }

s_q1_census(){ local rc=0 m
  for m in arcade x360; do TICKLOG=1 LOCKWAIT="$LOCKWAIT" RCC_ROOT="$BANK/census" SHELL_SECS="${SHELL_SECS:-120}" bash scripts/rc_census_win.sh "$m" "$ENG" "$m" "${CENSUS_MIN:-6}"; local r=$?
    local v="$BANK/census/$m/VERDICT.txt"; DETAIL="$DETAIL $m: $(grep -a '^RESULT' "$v" 2>/dev/null | tail -1) ($(grep -a '^INFO named' "$v" 2>/dev/null | sed 's/INFO named-class dropouts: //;s/ (.*//') named, $(grep -a 'outside the named' "$v" 2>/dev/null | sed 's/.*: //') other; $(grep -a '^FATAL' "$v" | sed 's/FATAL=0 VKERR=0 SLOW=0 //'); fpm-off $(grep -a 'off 3600' "$v" | sed 's/.*: //'));"
    [ $r = 0 ] || rc=1; done; return $rc; }

s_rc_chain(){ local rc=0 root="$BANK/chain" bad it TAGS="" V=""
  run_chain(){ local tg="$1" item="$2"; shift 2; TAGS="$TAGS $tg"; env "$@" RCC_ROOT="$root" SAVEPFX="rc_$SAFE" LOCKWAIT="$LOCKWAIT" bash scripts/rc_chain_win.sh "$tg" "$ENG" "$item"; return $?; }
  for it in $CHAIN_ITEMS; do case "$it" in
    all) run_chain rc all X=1 || rc=1;; T2) run_chain rc_t2 T2 X=1 || rc=1;; CX) run_chain rc_cx CX RT_PAUSEPROBE=1 || rc=1;;
    *) run_chain "rc_$(echo "$it" | tr 'A-Z' 'a-z')" "$it" X=1 || rc=1;; esac; done
  # score ONLY the legs this invocation ran (tag-prefixed dirs); a re-run must not re-read an earlier run's VERDICT files
  for it in $TAGS; do V="$V $(ls -d "$root"/${it}_*/VERDICT.txt 2>/dev/null)"; done   # newline-separated; $V is used unquoted
  bad=$(grep -a -H '^FAIL' $V 2>/dev/null)
  local npass; npass=$(cat $V 2>/dev/null | grep -a -c '^PASS')
  if [ -n "$bad" ]; then echo "FAIL lines:"; echo "$bad"; rc=1; fi
  DETAIL="items: $CHAIN_ITEMS; $npass PASS lines; FAIL: $(echo "$bad" | grep -c . | tr -d ' ')$( [ -n "$bad" ] && echo " -- $(echo "$bad" | sed 's|.*/rc[a-z0-9_]*_\([A-Za-z0-9_]*\)/VERDICT.txt:FAIL |\1: |' | cut -c1-110 | head -6 | tr '\n' ';')");$DETAIL"
  return $rc; }

run_step boot_smoke  s_boot_smoke
run_step gstart      s_gstart
run_step q1_ctest    s_q1_ctest
run_step q1_census   s_q1_census
run_step rc_chain    s_rc_chain
{ echo; echo "finished $(date '+%F %T')${TAGRUN}; ENGINE FAILED STEPS:${FAILED:- none}"; } >> "$SMOKE"
echo; cat "$SMOKE"
[ -z "$FAILED" ]
