#!/bin/bash
# boss_plate_gate.sh <tag> <decomp_tu>... -- the BOSS PLATE GATE (PLAN_after_boss1_0920.md Phase 1 item 2), Mac.
#
# Drives the training-mode stage-1 boss on a PILOT arm (every readable TU linked) and a CONTROL arm (the
# named TUs left out, so first-definition-wins hands their addresses back to the GENERATED bodies), both
# under the per-push trace levers, then scores pilot vs control with scripts/boss1/boss_plate_gate.py:
# the head-symmetry pixel plate AND the anchor-relative push-signature diff.  ~6 min wall.
#
#   bash scripts/boss1/boss_plate_gate.sh w140 objaction_queue famk1 famk9
#       -> _local/boss1_mac/plate_w140_pilot/, plate_w140_control/, plate_w140_pilot/plate_verdict.txt
#
#   env: PRISTINE=1   recompile build/obj_pristine first (otherwise reused when present; it MUST be the
#                     current tree -- the gate links BOTH arms from it so they differ only in the skipped TUs)
#        DUR=<s>      dwell at the boss (default 100; ~70 dump frames)
#        QUIET=<s>    hold fire for the first QUIET s of the dwell (default 10): the per-push trace covers the
#                     boss intro, and shots landing a frame apart between arms knocked the boss off its path
#                     from its third frame (plate_v2/plate_neg) -- the structural witness needs LOCKSTEP arms
#        PILOT_BIN=   use an already-built pilot instead of linking one from obj_pristine
#        NEGCTL=1     LAWS M4 negative control: the "pilot" is rebuilt with the PRE-FIX objaction_queue.cpp
#                     (futari_decomp d7dc0f34^, the inside-out head) -- the gate MUST FAIL, naming the
#                     (+/-9,-40) group in the structural diff and the symmetry drop in the pixel plate.
#                     Takes one extra compile (~50 s); the TU list is ignored (control = objaction_queue skipped).
#
# Levers (HARNESS-ONLY, never ship armed): RT_EMITTRACE=lr:880DCD70-880DEE68 covers the composite plate
# drawer sub_880DCD70 and the whole of sub_880DCE90 (the head's own emits, anchor pushes at 880DD32C/880DD3A4);
# RT_DCD70TRACE=1 logs the drawer's call sites + args.  Input rides RT_PAD_HOST_FIFO (boss1_drive_mac.sh), so
# the Mac stays usable while this runs; do not move the game window off-screen (the dump is the renderer's own).
set -u
cd "$(dirname "$0")/../.."
TAG="${1:?usage: boss_plate_gate.sh <tag> <decomp_tu>...}"; shift
TUS="$*"
[ "${NEGCTL:-0}" = "1" ] && TUS="objaction_queue"
[ -n "$TUS" ] || { echo "no TUs named"; exit 2; }
DUR="${DUR:-100}"
export QUIET="${QUIET:-10}"     # hold fire through the boss intro: the traced frames must be input-free (lockstep)
export RT_EMITTRACE="${RT_EMITTRACE:-lr:880DCD70-880DEE68}" RT_DCD70TRACE=1
PR=build/obj_pristine
if [ "${PRISTINE:-0}" = "1" ] || [ ! -d "$PR" ] || [ "$(ls "$PR"/*.o 2>/dev/null | wc -l | tr -d ' ')" -lt 100 ]; then
  echo "== compiling pristine objects ($PR)"; COMPILE_ONLY=1 OBJ="$PR" OUT="$PR/.unused" bash build_mac.sh   # OUT must not default to build/futari_merged: build_mac.sh rm -f's $OUT before compiling > "_local/plate_${TAG}_pristine.log" 2>&1 || { tail -20 "_local/plate_${TAG}_pristine.log"; exit 1; }
fi
link_arm(){ # name  skip-list  [extra-obj-dir-with-replacements]
  local name="$1" skip="$2" repl="${3:-}" s
  local O="build/obj_plate_${TAG}_$name" B="build/plate_${TAG}_$name"
  rm -rf "$O"; cp -R "$PR" "$O"
  for s in $skip; do [ -f "$O/decomp_$s.o" ] || { echo "   $name: no decomp_$s.o in $PR (is $s a linked TU?)"; }; rm -f "$O/decomp_$s.o"; done
  [ -n "$repl" ] && cp "$repl"/*.o "$O"/
  OBJ="$O" OUT="$B" LINK_ONLY=1 bash build_mac.sh > "$O/link.log" 2>&1
  grep -q LINK_OK "$O/link.log" || { echo "   $name: LINK FAILED"; tail -8 "$O/link.log"; exit 1; }
  echo "   $name: $B (skip=[$skip]${repl:+ repl=$repl})"
}
echo "== arms"
if [ "${NEGCTL:-0}" = "1" ]; then
  # the pre-fix TU compiled through build_mac.sh itself (same flags, same de-alias pre-pass): swap the file
  # in a copy of the decomp tree and compile only that object dir, then take the one object out of it.
  T="build/decomp_prefix_$TAG"; rm -rf "$T"; cp -R "${DECOMP_DIR:-../futari_decomp/decomp}" "$T"
  git -C ../futari_decomp show d7dc0f34^:decomp/game/objaction_queue.cpp > "$T/game/objaction_queue.cpp"
  echo "   compiling the pre-fix objaction_queue (d7dc0f34^) -> build/obj_plate_${TAG}_prefix"
  COMPILE_ONLY=1 OBJ="build/obj_plate_${TAG}_prefix" OUT="build/obj_plate_${TAG}_prefix/.unused" DECOMP_DIR="$T" bash build_mac.sh > "_local/plate_${TAG}_prefix.log" 2>&1 || { tail -20 "_local/plate_${TAG}_prefix.log"; exit 1; }
  mkdir -p "build/obj_plate_${TAG}_repl"; cp "build/obj_plate_${TAG}_prefix/decomp_objaction_queue.o" "build/obj_plate_${TAG}_repl/"
  link_arm pilot "" "build/obj_plate_${TAG}_repl"
else
  if [ -n "${PILOT_BIN:-}" ]; then echo "   pilot: $PILOT_BIN (given)"; else link_arm pilot ""; fi
fi
link_arm control "$TUS"
PB="${PILOT_BIN:-build/plate_${TAG}_pilot}"; CB="build/plate_${TAG}_control"
echo "== drives (DUR=$DUR, levers RT_EMITTRACE=$RT_EMITTRACE RT_DCD70TRACE=1)"
bash scripts/boss1/boss1_drive_mac.sh "plate_${TAG}_control" "$CB" "$DUR" | tail -2
bash scripts/boss1/boss1_drive_mac.sh "plate_${TAG}_pilot"   "$PB" "$DUR" | tail -2
echo "== score"
python3 scripts/boss1/boss_plate_gate.py compare "plate_${TAG}_pilot" "plate_${TAG}_control"
rc=$?
# The boss intro has TWO paths (y 343.03 / 345.69 at its third frame) chosen per run by something the drive does
# not control (plate_final 10-05 diverged WITH QUIET=10). Lockstep is a coin flip, so on a lockstep NO-VERDICT
# re-drive the CONTROL (then the pilot) up to RETRIES more times until the anchors match -- an honest retry:
# each arm's bank is replaced whole, never merged.
for ((try=1; try<=${RETRIES:-3} && rc==2; try++)); do
  grep -q "lockstep frames" "_local/boss1_mac/plate_${TAG}_pilot/plate_verdict.txt" || break
  arm=$([ $((try%2)) -eq 1 ] && echo control || echo pilot); bin=$([ "$arm" = control ] && echo "$CB" || echo "$PB")
  echo "== retry $try: arms not in lockstep -- re-driving $arm"
  bash scripts/boss1/boss1_drive_mac.sh "plate_${TAG}_$arm" "$bin" "$DUR" | tail -1
  python3 scripts/boss1/boss_plate_gate.py compare "plate_${TAG}_pilot" "plate_${TAG}_control"; rc=$?
done
[ "${NEGCTL:-0}" = "1" ] && { [ $rc -eq 1 ] && echo "NEGCTL: the gate FAILED the pre-fix arm as it must (M4 control holds)" || echo "NEGCTL: ⚠ the gate did NOT fail the pre-fix arm -- the instrument is broken, do not trust a PASS"; }
exit $rc
