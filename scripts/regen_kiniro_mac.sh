#!/bin/bash
# regen_kiniro_mac.sh -- Black Label bring-up steps 0-2 (docs/PLAN_other_modes.md §2, docs/PLAN_kiniro_bringup.md):
# regenerate out_kiniro/ (kiniro_normal, MODULE_BLACK, modeIdx 4) and out_kiniro_abn/ (kiniro_abnormal,
# MODULE_BLACK_HI, modeIdx 5) on the Mac. Cloned from scripts/regen_abn_mac.sh; static only (no build, no boot).
#
#   0. recompiler: tools/xenonrecomp_mac_eqv_fixes.patch must be FULLY applied to $XRD. The 2026-10-30 hunks
#      (PPC_INST_MULHDU, and the xex.cpp "futari xex-size-fix" -- NOTE_other_modes §0) are newer than the
#      first eqv-fix hunks, so regen_abn_mac.sh's "futari eqv-fix" guard is not enough here: when either is
#      missing, the two patched files are restored from git and the whole patch is re-applied (this discards
#      any OTHER local edit to exactly those two files), then XenonRecomp is rebuilt with ninja.
#      NB rebuilding $XRD also rebuilds $XRD/build/XenonUtils/libXenonUtils.a, which build_mac*.sh LINK into the
#      game; the xex fix is a no-op for the reco pair (block sum == imageSize there), but if other seats are
#      building, point XRD at a private copy instead (that is how this was first run, XRD=_local/kiniro/xr-derisk).
#   1. regenerate both trees (seed context header: out_kiniro/tools_kiniro/ppc_context_kiniro.h = the
#      instrument-free half of out_reco_abn/ppc_context.h, i.e. upstream + the ppc_div* helpers the patch calls),
#      apply the postregen import wrap, and run the dropped-instruction census -- which MUST be 0.
#   2. jump tables: out_kiniro/tools_kiniro/scan_switches.py re-reads each module's own flat image (xexflat) into
#      config/futari_switches_kiniro{,_abn}.toml, after a positive control on the reco pair (must reproduce
#      futari_switches.toml and futari_switches_abn.toml exactly, else this script stops).
#
# The out_kiniro*/ppc_recomp.*.cpp are gitignored as regenerable (zero hand patches, like out_reco_abn's); the
# support files (ppc_config.h, ppc_context.h, ppc_func_mapping.cpp, ppc_recomp_shared.h) are tracked.
#   bash scripts/regen_kiniro_mac.sh                  (full: patch check, tables, both trees)
#   NOSWITCH=1 bash scripts/regen_kiniro_mac.sh       (measurement only: regen WITHOUT tables into $W, trees untouched)
#   XRD=_local/kiniro/xr-derisk bash scripts/regen_kiniro_mac.sh    (use a private recompiler checkout)
set -euo pipefail
cd "$(dirname "$0")/.."
XRD="${XRD:-external/xr-derisk}"; XR="$XRD/build/XenonRecomp/XenonRecomp"
W="${W:-_local/kiniro/regen}"; T=out_kiniro/tools_kiniro; SEED="$PWD/$T/ppc_context_kiniro.h"
PATCH="$PWD/tools/xenonrecomp_mac_eqv_fixes.patch"
for m in kiniro_normal kiniro_abnormal reco_normal reco_abnormal; do
  [ -f "assets/media/Module/$m.xex" ] || { echo "no assets/media/Module/$m.xex"; exit 2; }
done

# ---- step 0: recompiler -------------------------------------------------------------------------------------
if ! grep -q "PPC_INST_MULHDU" "$XRD/XenonRecomp/recompiler.cpp" || ! grep -q "futari xex-size-fix" "$XRD/XenonUtils/xex.cpp"; then
  echo "== (re)applying tools/xenonrecomp_mac_eqv_fixes.patch to $XRD (restoring its 2 target files first) =="
  git -C "$XRD" checkout -- XenonRecomp/recompiler.cpp XenonUtils/xex.cpp
  git -C "$XRD" apply --check "$PATCH" && git -C "$XRD" apply "$PATCH"
fi
if [ ! -f "$XRD/build/build.ninja" ]; then
  cmake -G Ninja -S "$XRD" -B "$XRD/build" -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=/opt/homebrew/opt/llvm/bin/clang -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++ > /dev/null
fi
ninja -C "$XRD/build" XenonRecomp > /dev/null
XF="$XRD/build/xexflat"
if [ ! -x "$XF" ] || [ "$T/xexflat.cpp" -nt "$XF" ] || [ "$XRD/build/XenonUtils/libXenonUtils.a" -nt "$XF" ]; then
  /opt/homebrew/opt/llvm/bin/clang++ -std=c++20 -O2 -w -I "$XRD/XenonUtils" -I "$XRD/thirdparty" -o "$XF" "$T/xexflat.cpp" \
    "$XRD/build/XenonUtils/libXenonUtils.a" $(find "$XRD/build/thirdparty" -name '*.a')
fi

# ---- step 2 first (the trees are generated WITH the tables): flat images, positive control, tables ----------
mkdir -p "$W/img"
for m in kiniro_normal kiniro_abnormal reco_normal reco_abnormal; do
  "$XF" "assets/media/Module/$m.xex" "$W/img/$m.img.bin" > "$W/img/$m.sections.txt"
done
python3 "$T/scan_switches.py" --control --imgdir "$W/img" --config config | tail -1
if [ "${NOSWITCH:-0}" != 1 ]; then
  python3 "$T/scan_switches.py" --img "$W/img/kiniro_normal.img.bin" --module kiniro_normal \
    --out config/futari_switches_kiniro.toml --fp-ref "$W/img/reco_normal.img.bin"
  python3 "$T/scan_switches.py" --img "$W/img/kiniro_abnormal.img.bin" --module kiniro_abnormal \
    --out config/futari_switches_kiniro_abn.toml --fp-ref "$W/img/reco_normal.img.bin"
fi

# ---- step 1: regenerate both trees ----------------------------------------------------------------------------
rc=0
for row in "kiniro_normal out_kiniro futari_kiniro.toml futari_switches_kiniro.toml" \
           "kiniro_abnormal out_kiniro_abn futari_kiniro_abn.toml futari_switches_kiniro_abn.toml"; do
  set -- $row; m=$1; out=$2; toml=$3; sw=$4
  D="$W/$m"; rm -rf "$D"; mkdir -p "$D/$out" "$D/assets/media/Module"
  if [ "${NOSWITCH:-0}" = 1 ]; then grep -v '^switch_table_file_path' "config/$toml" > "$D/$toml"
  else cp "config/$toml" "config/$sw" "$D/"; fi
  ln -sf "$PWD/assets/media/Module/$m.xex" "$D/assets/media/Module/$m.xex"
  case "$XR" in /*) XRA="$XR";; *) XRA="$PWD/$XR";; esac
  ( cd "$D" && "$XRA" "$toml" "$SEED" > regen.log 2>&1 ) || { tail -5 "$D/regen.log"; exit 1; }
  if [ "${NOSWITCH:-0}" = 1 ]; then G="$D/$out"
  else
    mkdir -p "$out"; rm -f "$out"/ppc_recomp.*.cpp; cp "$D/$out"/* "$out/"; G="$out"
  fi
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
done
[ "$rc" = 0 ] || { echo "dropped-instruction census is NOT 0 -- see above"; exit 1; }
