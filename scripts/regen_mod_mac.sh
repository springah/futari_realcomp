#!/bin/bash
# regen_mod_mac.sh <module> [<module> ...] -- bring-up steps 1-2 (docs/PLAN_other_modes.md §2) for the four modules
# beyond the reco + kiniro pairs: hirow_normal (Ver 1.01 ARCADE, 6), hirow_abnormal (Ver 1.01 XBOX 360, 7),
# palm_normal (Arrange, 2), palm_abnormal (Novice, 3). A clone of scripts/regen_kiniro_mac.sh (2026-11-07, w1107):
# same recompiler (the eqv-fixed XenonRecomp incl. mulhdu + xex-size-fix; XRD defaults to the PRIVATE copy
# _local/kiniro/xr-derisk so external/'s libXenonUtils.a is never rebuilt under a game build), same tools
# (out_kiniro/tools_kiniro: xexflat, scan_switches.py positive control, census_dropped.py; postregen_kiniro.py
# takes the tree as an argument), same seed context header. Never touches out_reco*/ or out_kiniro*/.
#   bash scripts/regen_mod_mac.sh hirow_normal hirow_abnormal
# The dropped-instruction census MUST be 0 (exit 1 otherwise).
set -euo pipefail
cd "$(dirname "$0")/.."
XRD="${XRD:-_local/kiniro/xr-derisk}"; XR="$XRD/build/XenonRecomp/XenonRecomp"; XF="$XRD/build/xexflat"
W="${W:-_local/modregen}"; T=out_kiniro/tools_kiniro; SEED="$PWD/$T/ppc_context_kiniro.h"
grep -q "PPC_INST_MULHDU" "$XRD/XenonRecomp/recompiler.cpp" && grep -q "futari xex-size-fix" "$XRD/XenonUtils/xex.cpp" \
  || { echo "$XRD lacks the full eqv patch (see regen_kiniro_mac.sh step 0)"; exit 2; }
[ -x "$XR" ] && [ -x "$XF" ] || { echo "no $XR / $XF (run regen_kiniro_mac.sh with XRD=$XRD once)"; exit 2; }
row(){ case "$1" in
  hirow_normal)   echo "out_hirow futari_hirow.toml futari_switches_hirow.toml";;
  hirow_abnormal) echo "out_hirow_abn futari_hirow_abn.toml futari_switches_hirow_abn.toml";;
  palm_normal)    echo "out_palm futari_palm.toml futari_switches_palm.toml";;
  palm_abnormal)  echo "out_palm_abn futari_palm_abn.toml futari_switches_palm_abn.toml";;
  *) echo "UNKNOWN module $1" >&2; exit 2;; esac; }
mkdir -p "$W/img"
for m in reco_normal reco_abnormal "$@"; do
  "$XF" "assets/media/Module/$m.xex" "$W/img/$m.img.bin" > "$W/img/$m.sections.txt"
done
python3 "$T/scan_switches.py" --control --imgdir "$W/img" --config config | tail -1 | grep -q "POSITIVE CONTROL PASS" \
  || { echo "switch recogniser positive control FAILED"; exit 1; }
echo "switch recogniser positive control PASS (reco pair 57/57 + 57/57)"
rc=0
for m in "$@"; do
  set -- $(row "$m"); out=$1; toml=$2; sw=$3
  python3 "$T/scan_switches.py" --img "$W/img/$m.img.bin" --module "$m" --out "config/$sw" --fp-ref "$W/img/reco_normal.img.bin"
  D="$W/$m"; rm -rf "$D"; mkdir -p "$D/$out" "$D/assets/media/Module"
  cp "config/$toml" "config/$sw" "$D/"
  ln -sf "$PWD/assets/media/Module/$m.xex" "$D/assets/media/Module/$m.xex"
  case "$XR" in /*) XRA="$XR";; *) XRA="$PWD/$XR";; esac
  ( cd "$D" && "$XRA" "$toml" "$SEED" > regen.log 2>&1 ) || { tail -5 "$D/regen.log"; exit 1; }
  mkdir -p "$out"; rm -f "$out"/ppc_recomp.*.cpp; cp "$D/$out"/* "$out/"; G="$out"
  python3 out_kiniro/postregen_kiniro.py "$G" > /dev/null
  tus=$(ls "$G"/ppc_recomp.*.cpp | wc -l | tr -d ' ')
  lines=$(cat "$G"/ppc_recomp.*.cpp | wc -l | tr -d ' ')
  fns=$(grep -c '^	{ 0x' "$G/ppc_func_mapping.cpp")
  echo "== $m -> $G: $tus TUs, $lines lines, $fns mapped functions"
  echo "   regen.log: $(grep -c 'Unrecognized instruction' "$D/regen.log" || true) unrecognized-instruction," \
       "$(grep -c 'Found a switch jump table' "$D/regen.log" || true) switch-shaped bctr without a table," \
       "$(grep -c 'ERROR: Switch case' "$D/regen.log" || true) out-of-function case labels," \
       "$(grep -c 'Unable to decode' "$D/regen.log" || true) undecodable words (data in .text)"
  grep 'Unrecognized instruction' "$D/regen.log" | sed 's/^/   /' || true
  python3 "$T/census_dropped.py" "$G" || rc=1
  # support headers every module tree carries (verbatim from out_kiniro: rt_indirect.h, win_compat.h)
  cp out_kiniro/rt_indirect.h out_kiniro/win_compat.h "$G/"
done
[ "$rc" = 0 ] || { echo "dropped-instruction census is NOT 0 -- see above"; exit 1; }
echo "REGEN_OK"
