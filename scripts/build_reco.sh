#!/bin/bash
# Full rebuild of futari_mode from out_reco/ (game module).
# Usage: build_reco.sh [--objs-only]
set -u
cd ~/xr-work || exit 1
rm -f obj/.o
FAIL=0
for f in out_reco/*.cpp; do
  n=$(basename "$f" .cpp)
  echo "$n"
done | xargs -P12 -I@@ sh -c '
  clang++ -O2 -std=c++20 -include "$HOME/xr-work/out_reco/rt_indirect.h" -I "$HOME/xr-work/out_reco" -I "$HOME/xr-derisk/XenonUtils" -I "$HOME/xr-derisk/thirdparty/simde" \
    -c "$HOME/xr-work/out_reco/@@.cpp" -o "$HOME/xr-work/obj/@@.o" 2> "$HOME/xr-work/obj/@@.err" \
    || { echo "FAILED: @@"; head -6 "$HOME/xr-work/obj/@@.err"; }
'
NOBJ=$(ls obj/*.o 2>/dev/null | wc -l)
NSRC=$(ls out_reco/*.cpp | wc -l)
echo "objects: $NOBJ / $NSRC"
[ "$NOBJ" -ne "$NSRC" ] && { echo "COMPILE_INCOMPLETE"; exit 1; }
clang++ -O2 -std=c++20 obj/*.o -o futari_mode \
  -Wl,--start-group \
  ~/xr-derisk/build/XenonUtils/libXenonUtils.a \
  ~/xr-derisk/build/XenonAnalyse/libLibXenonAnalyse.a \
  ~/xr-derisk/build/thirdparty/disasm/libdisasm.a \
  ~/xr-derisk/build/thirdparty/xxHash/cmake_unofficial/libxxhash.a \
  ~/xr-derisk/build/thirdparty/fmt/libfmt.a \
  -Wl,--end-group -lpthread \
  && echo "LINK_OK" || echo "LINK_FAILED"
