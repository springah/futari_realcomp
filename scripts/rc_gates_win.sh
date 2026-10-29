#!/bin/bash
# rc_gates_win.sh <version>  -- the Windows twin of rc_cut_mac.sh step (c): run the scripted RC smoke against the STAGED Windows folder
# (scripts/rc_stage_win.sh output) and write ../_rc/<version>-win/SMOKE.md. Steps, each PASS/FAIL, all run even after a FAIL:
#   1 boot_smoke   scripts/rc_smoke_win.sh on the staged folder itself (build id = HEAD, 2/2 modules bound, 0 FATAL, 0 VK_ERROR)
#   2 gstart       scripts/gstart_win.sh ARCADE (HUBSTART=1) + XBOX 360 -- no LEAK=YES row
#   3 q1_ctest     scripts/q7v_run_win.sh ... ctest 240 1 : RVK_CENSUSTEST positive control must report 60 DROPOUT-CONFIRMED / 60 injected
#   4 q1_census    scripts/rc_census_win.sh arcade + x360 : single launch, dropouts only in the named AUTHENTIC classes, 0 FATAL/VK/slow/underrun, 3600 fpm
#   5 rc_chain     scripts/rc_chain_win.sh all (swap x5, restart, continue, score-attack decline, remap; both modes) + T2 (DC-1) + CX (DC-2)
# Steps 2-5 run a BYTE-IDENTICAL copy of the staged futari_combined.exe (cmp-checked, md5 in SMOKE.md) renamed `rcwin_eng.exe` beside copies of the
# staged module DLLs, under _rc/<version>-win/smoke_engine/, so `taskkill /IM rcwin_eng.exe` can only ever hit it and the gates' FIFO/save/log
# plumbing never touches the staged folder. Same bytes = same code; the folder-only properties (launcher .bat, README) are the user's hands.
# The gate scripts take the drive lock (/c/tmp/futari_drive.lock) per leg and wait while futari_combined.exe (the launcher's image) is running.
#   bash scripts/rc_gates_win.sh 0.3.0-rc2          # ~1.5 h; CENSUS_MIN=<n> SHELL_SECS=<s> LOCKWAIT=<s> as in rc_cut_mac.sh
set -u
cd "$(dirname "$0")/.."
source scripts/win_shim.sh
REPO="$PWD"; PROJ="$(cd .. && pwd)"
VER="${1:?usage: rc_gates_win.sh <version>}"
RC="$PROJ/_rc"; RD="$RC/$VER-win"; NAME="Futari-Realcomp-Windows-v$VER"; ST="$RD/$NAME"; SMOKE="$RD/SMOKE.md"; LG="$RD/logs"
ENGDIR="$RD/smoke_engine"; PN=rcwin_eng.exe; ENG="$ENGDIR/$PN"
SAFE="$(echo "$VER" | tr -c 'A-Za-z0-9\n' '_')"; BANK="_local/rc/$SAFE"; LOCKWAIT="${LOCKWAIT:-7200}"
die(){ echo "[gates] STOP: $*" >&2; exit 1; }
log(){ echo "[gates] $(date +%H:%M:%S) $*"; }
trap 'pkill -x "$PN" 2>/dev/null' EXIT
[ -f "$ST/futari_combined.exe" ] || die "no staged folder $ST (run scripts/rc_stage_win.sh $VER)"
mkdir -p "$LG" "$BANK"; [ -f "$SMOKE" ] && mv -f "$SMOKE" "$RD/SMOKE.prev.md"
HR=$(git rev-parse HEAD); HD=$(git -C "$PROJ/futari_decomp" rev-parse HEAD)
BID=$(sed -n 's/^exe_build_id=//p' "$ST/BUILD.txt" 2>/dev/null)

# ---- the engine copy
rm -rf "$ENGDIR"; mkdir -p "$ENGDIR"
cp "$ST/futari_combined.exe" "$ENG"; cp "$ST/futari_game_normal.dll" "$ST/futari_game_abn.dll" "$ENGDIR/"
cmp -s "$ENG" "$ST/futari_combined.exe" && CMP=IDENTICAL || die "engine copy differs from the staged exe"
ENGMD5=$(md5sum "$ENG" | cut -c1-32)
{ echo "# SMOKE -- $VER (WINDOWS, staged folder)"; echo
  echo "- started $(date '+%F %T'); folder \`$ST\` ($(du -sh "$ST" | cut -f1)); exe build id ${BID:-?}"
  echo "- futari_realcomp \`$HR\`; futari_decomp \`$HD\`"
  echo "- script-driven steps run \`$ENG\` = a copy of the staged futari_combined.exe ($CMP, md5 $ENGMD5) beside copies of the staged module DLLs"
  echo; echo "| step | result | secs | detail |"; echo "|---|---|---|---|"; } > "$SMOKE"

# ---- step machinery (rc_cut_mac.sh (c), Windows names)
FAILED=""; DETAIL=""
others(){ pgrep -x futari_combined.exe 2>/dev/null; }     # the launcher's image = the user is playing
wait_quiet(){ local w=0; while [ -n "$(others)" ]; do [ $w -ge "$LOCKWAIT" ] && return 1; [ $((w%600)) = 0 ] && log "waiting: futari_combined.exe is running ($(others | tr '\n' ' '))"; sleep 60; w=$((w+60)); done; return 0; }
run_step(){ local name="$1" fn="$2" t0 r=""; t0=$(date +%s); log ">>> step $name"; DETAIL=""
  wait_quiet || { DETAIL="futari_combined.exe ran for ${LOCKWAIT}s"; r=FAIL; }
  if [ -z "$r" ]; then "$fn" > "$LG/$name.log" 2>&1 && r=PASS || r=FAIL; fi
  echo "| $name | **$r** | $(( $(date +%s)-t0 )) | ${DETAIL//|/\/} |" >> "$SMOKE"; log "<<< step $name: $r  ${DETAIL}"
  [ $r = FAIL ] && FAILED="$FAILED $name"; return 0; }

s_boot_smoke(){ bash scripts/rc_smoke_win.sh "$ST" 75; local rc=$?
  DETAIL="$(grep -a 'WIN SMOKE:' "$LG/boot_smoke.log" | tail -1 | tr -d '\n'); $(grep -a -c '^\[smoke\] PASS' "$LG/boot_smoke.log") PASS lines"; return $rc; }

s_gstart(){ local rc=0 m tag tbl
  for m in arcade x360; do tag="rc_${SAFE}_$m"
    if [ $m = arcade ]; then HUBSTART=1 bash scripts/gstart_win.sh "$tag" "$ENG" arcade; else bash scripts/gstart_win.sh "$tag" "$ENG" x360; fi
    tbl="_local/gstart/$tag/TABLE.txt"
    if [ ! -s "$tbl" ]; then echo "gstart $m: no TABLE (run failed)"; rc=1; DETAIL="$DETAIL $m: NO TABLE;"; continue; fi
    if grep -q ' YES$' "$tbl"; then echo "gstart $m: LEAK rows:"; grep ' YES$' "$tbl"; rc=1; DETAIL="$DETAIL $m: LEAK ($(grep -c ' YES$' "$tbl") rows);"
    else DETAIL="$DETAIL $m: $(wc -l < "$tbl" | tr -d ' ') probes, 0 leaks;"; fi
    [ "$(grep -c FATAL "_local/gstart/$tag/guest.log" 2>/dev/null)" = 0 ] || { rc=1; DETAIL="$DETAIL $m: FATAL;"; }
  done; return $rc; }

s_q1_ctest(){ LOCKWAIT_MIN=$((LOCKWAIT/60)) bash scripts/q7v_run_win.sh "rc_$SAFE" "$ENG" ctest 240 1; local o="_local/rc1/q7v/rc_$SAFE/steps.txt" e
  e=$(grep -a 'END ' "$o" | tail -1); echo "$e"
  if echo "$e" | grep -q 'dropout=60 testmarks=60' && echo "$e" | grep -q 'fatal=0 vkerr=0'; then DETAIL="positive control 60 DROPOUT-CONFIRMED for 60 INJECT"; return 0; fi
  DETAIL="control off: ${e#*END }"; return 1; }

s_q1_census(){ local rc=0 m
  for m in arcade x360; do LOCKWAIT="$LOCKWAIT" RCC_ROOT="$BANK/census" SHELL_SECS="${SHELL_SECS:-120}" bash scripts/rc_census_win.sh "$m" "$ENG" "$m" "${CENSUS_MIN:-6}"; local r=$?
    local v="$BANK/census/$m/VERDICT.txt"; DETAIL="$DETAIL $m: $(grep -a '^RESULT' "$v" 2>/dev/null | tail -1) ($(grep -a '^INFO named' "$v" 2>/dev/null | sed 's/INFO named-class dropouts: //;s/ (.*//') named, $(grep -a 'outside the named' "$v" 2>/dev/null | sed 's/.*: //') other);"
    [ $r = 0 ] || rc=1; done; return $rc; }

s_rc_chain(){ local rc=0 root="$BANK/chain" bad
  run_chain(){ local tg="$1" item="$2"; shift 2; env "$@" RCC_ROOT="$root" SAVEPFX="rc_$SAFE" LOCKWAIT="$LOCKWAIT" bash scripts/rc_chain_win.sh "$tg" "$ENG" "$item"; return $?; }
  run_chain rc all X=1 || rc=1
  run_chain rc_t2 T2 X=1 || rc=1
  run_chain rc_cx CX RT_PAUSEPROBE=1 || rc=1
  bad=$(grep -a -H '^FAIL' "$root"/rc*_*/VERDICT.txt 2>/dev/null)
  local npass; npass=$(cat "$root"/rc*_*/VERDICT.txt 2>/dev/null | grep -a -c '^PASS')
  if [ -n "$bad" ]; then echo "FAIL lines:"; echo "$bad"; rc=1; fi
  DETAIL="$npass PASS lines; FAIL: $(echo "$bad" | grep -c . | tr -d ' ')$( [ -n "$bad" ] && echo " -- $(echo "$bad" | sed 's|.*/rc[a-z0-9_]*_\([A-Za-z0-9_]*\)/VERDICT.txt:FAIL |\1: |' | cut -c1-110 | head -6 | tr '\n' ';')");$DETAIL"
  return $rc; }

run_step boot_smoke  s_boot_smoke
run_step gstart      s_gstart
run_step q1_ctest    s_q1_ctest
run_step q1_census   s_q1_census
run_step rc_chain    s_rc_chain
{ echo; echo "finished $(date '+%F %T'); ENGINE FAILED STEPS:${FAILED:- none}"; } >> "$SMOKE"
echo; cat "$SMOKE"
[ -z "$FAILED" ]
