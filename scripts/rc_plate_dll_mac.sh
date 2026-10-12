#!/bin/bash
# rc_plate_dll_mac.sh <tag> <decomp_tu>... -- the BOSS PLATE GATE on the COMBINED (dylib) engine (RC1 Q5/F). boss_plate_gate.sh builds its arms with the
# single-binary build_mac.sh (obj_pristine, 18-TU era); the shipping engine is build_mac_dll.sh, so here: PILOT = build/<tag>_probe_dir copy (every readable TU linked,
# PILOT_DIR=build/q5c_probe by default), CONTROL = a fresh build_mac_dll.sh with DECOMP_SKIP="<tus>" (OUTDIR=build/q5c_plate_control, OBJSFX=_q5c_plate_control; first-
# definition-wins hands the skipped TUs' addresses back to the generated bodies). Then boss1_drive_mac.sh per arm (levers as boss_plate_gate.sh) and
# boss_plate_gate.py compare, with the lockstep RETRIES loop. Own drive lock per arm drive; pkill -x on the two exact arm names only; own save copy.
#   bash scripts/rc_plate_dll_mac.sh q5c famk1        env: RETRIES=3 DUR=100 PILOT_DIR=build/q5c_probe DECOMP_DIR=<decomp tree>
set -u
cd "$(dirname "$0")/.."
TAG="${1:?tag}"; shift; TUS="$*"; [ -n "$TUS" ] || { echo "no TUs named"; exit 2; }
DUR="${DUR:-100}"; PD="${PILOT_DIR:-build/q5c_probe}"; export QUIET="${QUIET:-10}"
export RT_EMITTRACE="${RT_EMITTRACE:-lr:880DCD70-880DEE68}" RT_DCD70TRACE=1
PH="q5c_plate_pilot"; CH="q5c_plate_control"; LOCK=/tmp/futari_drive.lock
CD="build/q5c_plate_control"; PDIR="build/q5c_plate_pilot_dir"
rm -rf "$PDIR"; mkdir -p "$PDIR"; cp "$PD"/futari_game_*.dylib "$PD"/futari_combined "$PDIR"/; cp "$PDIR/futari_combined" "$PDIR/$PH"
DECOMP_SKIP="$TUS" FFM=/nonexistent DECOMP_DIR="${DECOMP_DIR:-$PWD/build/q5c_decomp/decomp}" OUTDIR="$CD" OBJSFX=_q5c_plate_control bash build_mac_dll.sh > "_local/rc1/q5c/plate_control_build.log" 2>&1 || { tail -5 _local/rc1/q5c/plate_control_build.log; echo "control build FAILED"; exit 1; }
cp "$CD/futari_combined" "$CD/$CH"; echo "control: $CD/$CH (skip=[$TUS])  pilot: $PDIR/$PH"
export RT_SAVE="_local/saves/q5c_plate_${TAG}"
drive(){ # arm bin  -- holds the lock for this drive only
  local w=0; until mkdir "$LOCK" 2>/dev/null; do [ $w -ge "${LOCKWAIT:-10800}" ] && { echo "lock busy"; exit 3; }; sleep 60; w=$((w+60)); done
  while pgrep -x futari_merged >/dev/null; do sleep 30; done
  rm -rf "$RT_SAVE"; cp -R _local/saves/save_rc1_rc1m_arcade "$RT_SAVE"
  bash scripts/boss1/boss1_drive_mac.sh "plate_${TAG}_$1" "$2" "$DUR" | tail -2; local rc=$?
  pkill -x "$(basename "$2")" 2>/dev/null; sleep 1; rmdir "$LOCK" 2>/dev/null; return $rc; }
drive control "$CD/$CH"; drive pilot "$PDIR/$PH"
python3 scripts/boss1/boss_plate_gate.py compare "plate_${TAG}_pilot" "plate_${TAG}_control"; rc=$?
for ((try=1; try<=${RETRIES:-3} && rc==2; try++)); do
  grep -q "lockstep frames" "_local/boss1_mac/plate_${TAG}_pilot/plate_verdict.txt" || break
  arm=$([ $((try%2)) -eq 1 ] && echo control || echo pilot); bin=$([ "$arm" = control ] && echo "$CD/$CH" || echo "$PDIR/$PH")
  echo "== retry $try: not in lockstep -- re-driving $arm"; drive "$arm" "$bin"
  python3 scripts/boss1/boss_plate_gate.py compare "plate_${TAG}_pilot" "plate_${TAG}_control"; rc=$?
done
exit $rc
