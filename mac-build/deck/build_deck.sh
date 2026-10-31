#!/bin/bash
# build_deck.sh -- build the Steam Deck (linux-amd64) two-mode engine from this Mac, inside the futari-deck-build
# container (mac-build/deck/Dockerfile, run through colima with Rosetta), then stage the family-and-friends folder:
#   ~/Desktop/projects/Futari-Realcomp-Deck/   futari_combined, futari_game_{normal,abn}.so, assets/ (lowercase module/),
#                                              futari-realcomp (the launcher script), README.txt, save/, logs/
#   bash mac-build/deck/build_deck.sh            (DEPS_ONLY=1 builds just the container-side dependencies; STAGE_ONLY=1 skips the build)
set -eu
cd "$(dirname "$0")/../.."
ROOT="$PWD"; DECOMP="$(cd ../futari_decomp && pwd)"
IMG=futari-deck-build; OUT="${OUT:-$HOME/Desktop/projects/Futari-Realcomp-Deck}"
docker image inspect "$IMG" >/dev/null 2>&1 || docker build --platform linux/amd64 -t "$IMG" mac-build/deck
run(){ docker run --rm --platform linux/amd64 -v "$ROOT:/work/futari_realcomp" -v "$DECOMP:/work/futari_decomp" -w /work/futari_realcomp "$IMG" bash -c "$1"; }
if [ "${STAGE_ONLY:-0}" != "1" ]; then
  echo "== [container] dependencies: xr-derisk (XenonUtils etc.) + SDL3 static, Linux builds in build-linux/ dirs =="
  run 'set -e
    if [ ! -f external/xr-derisk/build-linux/XenonUtils/libXenonUtils.a ]; then
      cmake -S external/xr-derisk -B external/xr-derisk/build-linux -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ >/dev/null
      ninja -C external/xr-derisk/build-linux XenonUtils LibXenonAnalyse disasm xxhash fmt | tail -1
    fi
    if [ ! -f external/SDL/build-linux/libSDL3.a ]; then
      cmake -S external/SDL -B external/SDL/build-linux -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
        -DSDL_SHARED=OFF -DSDL_STATIC=ON -DSDL_AUDIO=ON -DSDL_VIDEO=ON -DSDL_VULKAN=ON -DSDL_JOYSTICK=ON -DSDL_HIDAPI=ON \
        -DSDL_OPENGL=OFF -DSDL_OPENGLES=OFF -DSDL_RENDER=OFF -DSDL_GPU=OFF -DSDL_HAPTIC=OFF -DSDL_CAMERA=OFF -DSDL_SENSOR=OFF \
        -DSDL_POWER=OFF -DSDL_DIALOG=OFF -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF -DSDL_INSTALL=OFF -DSDL_X11=ON -DSDL_X11_XTEST=OFF -DSDL_WAYLAND=ON >/dev/null
      ninja -C external/SDL/build-linux | tail -1
    fi
    ls -la external/xr-derisk/build-linux/XenonUtils/libXenonUtils.a external/SDL/build-linux/libSDL3.a'
  [ "${DEPS_ONLY:-0}" = "1" ] && exit 0
  echo "== [container] build_linux_dll.sh =="
  # DECK_MODULES: which module .so files to build in the container (default = the Ver 1.5 pair; "normal abn kiniro kiniro_abn"
  # adds Black Label -- 2026-10-31, needs the out_kiniro*/ trees + symbol maps in the checkout the container mounts).
  run "MODULES='${DECK_MODULES:-normal abn}' bash build_linux_dll.sh 2>&1 | grep -v '^\[' | tail -15"
  run 'file build/linux/futari_combined build/linux/*.so | cut -c1-120; objdump -T build/linux/futari_combined | grep -o "GLIBC_[0-9.]*" | sort -Vu | tail -1'
  echo "== [container] headless smoke (no window): the harness must return cleanly with both modules bound =="
  run 'RT_GAME_ROOT=assets XR_SHELL_XEX=assets/default.xex RT_SAVE=/tmp/save RT_SAMPLES=0 timeout 60 build/linux/futari_combined 8208A2B8 0 assets/default.xex 2>&1 | grep -m6 "\[modreg\]\|RETURNED\|FATAL\|harness\]" | cut -c1-140' || true
fi
echo "== stage $OUT =="
rm -rf "$OUT"; mkdir -p "$OUT/save" "$OUT/logs"
cp build/linux/futari_combined build/linux/futari_game_normal.so build/linux/futari_game_abn.so "$OUT/"
for k in kiniro kiniro_abn; do [ -f "build/linux/futari_game_$k.so" ] && cp "build/linux/futari_game_$k.so" "$OUT/"; done   # Black Label, when built
echo "   modules staged: $(ls "$OUT"/futari_game_*.so | xargs -n1 basename | tr '\n' ' ')"
cp mac-build/deck/futari-realcomp "$OUT/"; chmod +x "$OUT/futari-realcomp"
VER="${VER:-0.2.0-beta3}"
sed -e "s/@VER@/$VER/" -e "s/@BUILD@/$(git rev-parse --short HEAD)$(git diff --quiet || echo -dirty)/" mac-build/deck/README.deck.txt > "$OUT/README.txt"
# The dump's own case is kept verbatim: the realcomp's file layer maps guest paths 1:1 under RT_GAME_ROOT and the bridge
# opens media/Module/<mod>.xex with the capital M (merged_bridge.cpp) -- the lowercase-`module` rule belongs to the
# ReXGlue recomp, not here. The Deck's filesystem is case-sensitive, so the dump must be copied, never re-cased.
echo "   game data -> assets/ (case kept verbatim)"
ditto assets "$OUT/assets"
cp -r save_freshcard "$OUT/save_freshcard" 2>/dev/null || true
du -sh "$OUT"; ls "$OUT"
