#!/bin/bash
# regen_abn_mac.sh -- regenerate the reco_abnormal (XBOX 360 mode) tree, out_reco_abn/, on the Mac.
#
# WHY THIS EXISTS (2026-10-04, beta 3): out_reco_abn/ppc_recomp.*.cpp are gitignored as "regenerable", but the
# recompiler that generated them on Windows is the eqv-fixed XenonRecomp checkout (xr-derisk, a LOCAL git repo on
# the Windows box, never pushed). The Mac's external/xr-derisk is a shallow clone of hedge-dev upstream, which
# (a) emits raw `a / b` for divw/divwu/divd/divdu (host SIGFPE on a benign guest divide), (b) silently DROPS
# lhzu, sthu, stfsu, bdzf, eqv, addc, addme and lwzux (no case in the switch -- the asm comment is emitted, no C
# follows), and (c) emits __rdtsc() for mftb instead of the scaled guest timebase. tools/xenonrecomp_mac_eqv_fixes.patch
# adds exactly those cases (plus the macOS-27-SDK <cstdlib> include in fmt). It was VALIDATED by regenerating
# reco_normal with it and diffing against the tracked out_reco/ (1.1M lines): the residual is exactly the 41
# "FIX 2026" hand patches (which the patch now emits mechanically, same expressions) plus the 24 r23-w6x
# harness-tap hunks -- nothing else (ledger: NOTE_fnf_shell_defects.md 2026-10-04 beta-3 entry).
#
# The five tracked abn TUs (4/5/6/8/19, the r23-w68 witness taps) are NOT overwritten: they already carry the
# fixes by hand and the instruments the decomp campaign relies on. Everything else in out_reco_abn/ is replaced.
#   bash scripts/regen_abn_mac.sh            (needs assets/media/Module/reco_abnormal.xex and the xr-derisk build)
set -eu
cd "$(dirname "$0")/.."
XR=external/xr-derisk/build/XenonRecomp/XenonRecomp; H=external/xr-derisk/XenonUtils/ppc_context.h
[ -f assets/media/Module/reco_abnormal.xex ] || { echo "no assets/media/Module/reco_abnormal.xex"; exit 2; }
if ! grep -q "futari eqv-fix" external/xr-derisk/XenonRecomp/recompiler.cpp; then
  echo "== applying tools/xenonrecomp_mac_eqv_fixes.patch to external/xr-derisk =="
  git -C external/xr-derisk apply --check "$PWD/tools/xenonrecomp_mac_eqv_fixes.patch" && git -C external/xr-derisk apply "$PWD/tools/xenonrecomp_mac_eqv_fixes.patch"
fi
ninja -C external/xr-derisk/build XenonRecomp > /dev/null
W=build/regen_abn; rm -rf "$W"; mkdir -p "$W/out_reco_abn" "$W/assets/media/Module"
cp config/futari_reco_abn.toml config/futari_switches_abn.toml "$W/"
ln -sf "$PWD/assets/media/Module/reco_abnormal.xex" "$W/assets/media/Module/reco_abnormal.xex"
( cd "$W" && "../../$XR" futari_reco_abn.toml "../../$H" > regen.log 2>&1 ) || { tail -5 "$W/regen.log"; exit 1; }
n=0; for f in "$W"/out_reco_abn/ppc_recomp.*.cpp; do
  b=$(basename "$f"); case "$b" in ppc_recomp.4.cpp|ppc_recomp.5.cpp|ppc_recomp.6.cpp|ppc_recomp.8.cpp|ppc_recomp.19.cpp) continue;; esac
  cp "$f" "out_reco_abn/$b"; n=$((n+1))
done
# the tracked support files (ppc_context.h with the abn instruments, ppc_recomp_shared.h post-regen'd, ppc_config.h,
# ppc_func_mapping.cpp) stay as tracked; only the generated bodies are replaced.
python3 out_reco_abn/postregen_abn.py >/dev/null
echo "regenerated $n untracked abn TUs ($(ls out_reco_abn/ppc_recomp.*.cpp | wc -l | tr -d ' ') total); dropped-insn census:"
python3 - <<'PY'
import re, glob, collections
NOOP={'nop','eieio','sync','tdlgei','isync','lwsync','mtmsr','mfmsr','twllei','tweqi','tdllei','twlgei','twi','tw','td','b','db16cyc','cctpl','cctpm'}
c=collections.Counter()
for f in glob.glob('out_reco_abn/ppc_recomp.*.cpp'):
    L=open(f).read().split('\n')
    for i,l in enumerate(L):
        m=re.match(r'^\t// ([a-z][a-z0-9.]*) ',l)
        if not m or m.group(1) in NOOP or m.group(1).startswith('dcb'): continue
        nxt=L[i+1] if i+1<len(L) else ''
        if nxt.startswith('\t// ') or nxt.startswith('loc_') or nxt in ('}',''): c[m.group(1)]+=1
print('   silently-dropped instructions:', sum(c.values()), dict(c))
PY
