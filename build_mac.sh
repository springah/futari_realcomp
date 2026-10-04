#!/bin/bash
# build_mac.sh — NATIVE macOS build of build/futari_merged (2026-10-03 handoff; UNTESTED on a Mac —
#   written on the Linux proving ground, to be driven to green by a session on the Mac itself).
#
# Same shape as build_linux.sh, three differences:
#   1. The linker. Apple's ld has NO --allow-multiple-definition and llvm-objcopy cannot weaken
#      Mach-O symbols — but it CAN rename them (--redefine-sym, verified). So the merge is done as:
#      link once, parse ld's "duplicate symbol" errors, rename the LOSING definition in the object
#      that comes LATER in the link line (same first-definition-wins order as build_win.sh /
#      build_linux.sh), relink. The rename list is derived every build, so new decomp promotions
#      (which add __imp__sub_* duplicates) need no maintenance. See docs/PLAN_macos_bringup.md.
#   2. Vulkan = MoltenVK, linked directly (Homebrew molten-vk); no loader needed. The same dylib
#      path is baked in as RVK_VULKAN_LIBRARY so SDL loads the one we link.
#   3. SDL3 built SHARED (so Cocoa/Metal/CoreAudio/GameController frameworks come along without a
#      hand-maintained -framework list) and found by rpath next to the executable.
#   4. Mach-O has NO __attribute__((alias)) ("aliases are not supported on darwin"), and every
#      recompiled TU opens each function with `__attribute__((alias("__imp__sub_X"))) PPC_WEAK_FUNC(sub_X);`
#      (17,439 of them + the millicode helpers). A pre-pass rewrites that one line shape into a weak
#      forwarding stub, `PPC_FUNC_IMPL(__imp__sub_X); PPC_WEAK_FUNC(sub_X) { __imp__sub_X(ctx, base); }`,
#      in a copy under build/obj_mac/src/ -- the tracked sources are untouched and regeneration needs
#      nothing. Same linkage (weak, C++-mangled sub_X; strong extern "C" __imp__sub_X), same override
#      semantics (a strong sub_X elsewhere still wins), one extra `b` per call (clang tail-calls it).
#
# STATUS 2026-10-03: GREEN on an M3 Max / macOS 27.0.1 -- builds, links, boots the shell to the title
# screen in a Cocoa window on MoltenVK (docs/PLAN_macos_bringup.md, top block).
#
# Dependencies:
#   brew install llvm cmake ninja molten-vk vulkan-headers
#   (xr-derisk's vendored fmt needs `#include <cstdlib>` in include/fmt/format.h against the macOS 27 SDK;
#    configure xr-derisk with -DCMAKE_C_COMPILER/-DCMAKE_CXX_COMPILER pointing at Homebrew llvm)
#   external/xr-derisk   XenonRecomp checkout:  cmake -S external/xr-derisk -B external/xr-derisk/build -G Ninja
#                        -DCMAKE_BUILD_TYPE=Release && ninja -C external/xr-derisk/build XenonUtils LibXenonAnalyse disasm xxhash fmt
#   external/SDL         SDL 3.x:  cmake -S external/SDL -B external/SDL/build -G Ninja -DCMAKE_BUILD_TYPE=Release
#                        -DSDL_SHARED=ON -DSDL_STATIC=OFF -DSDL_AUDIO=ON -DSDL_VIDEO=ON -DSDL_VULKAN=ON -DSDL_METAL=ON
#                        -DSDL_JOYSTICK=ON -DSDL_HIDAPI=ON -DSDL_RENDER=OFF -DSDL_GPU=OFF -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF
#                        && ninja -C external/SDL/build
#   ../futari_decomp     the readable-decomp sibling repo (DECOMP_DIR)
set -u
cd "$(dirname "$0")"
mkdir -p build
BREW="$(brew --prefix 2>/dev/null || echo /opt/homebrew)"
CXX="${CXX:-$BREW/opt/llvm/bin/clang++}"
[ -x "$CXX" ] || CXX=clang++
OBJCOPY="${OBJCOPY:-$BREW/opt/llvm/bin/llvm-objcopy}"
DERISK="${DERISK:-external/xr-derisk}"
DERISK_BUILD="${DERISK_BUILD:-$DERISK/build}"
SDL_SRC="${SDL_SRC:-external/SDL}"
SDL_BUILD="${SDL_BUILD:-$SDL_SRC/build}"
MVK="${MVK:-$BREW/opt/molten-vk}"
VKH="${VKH:-$BREW/opt/vulkan-headers/include}"
[ -d "$VKH/vulkan" ] || VKH="$MVK/include"
MVK_DYLIB="$MVK/lib/libMoltenVK.dylib"
# MVK_LOADPATH: the path SDL is told to dlopen for Vulkan (baked in as RVK_VULKAN_LIBRARY). Defaults to the
# dylib we link; the .app build passes "@executable_path/../Frameworks/libMoltenVK.dylib" so the bundle is
# self-contained (build_mac_app.sh). Linking is unchanged -- the load command is rewritten after the link.
MVK_LOADPATH="${MVK_LOADPATH:-$MVK_DYLIB}"
# Deployment target (beta 3, 2026-10-04): without it clang stamps the host SDK's own version as the minimum OS,
# and the 10-04 bundle would only launch on macOS 27. 13.0 = Ventura, the oldest Apple-silicon-era release.
export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-13.0}"
# xWMA (compressed SE/voice banks): libavcodec's wmav2 via Homebrew ffmpeg when present; otherwise the
# decoder stays a stub and those voices are silent (PCM BGM plays either way through the SDL3 sink).
FFM="${FFM:-$BREW/opt/ffmpeg}"
if [ -f "$FFM/include/libavcodec/avcodec.h" ] && ls "$FFM"/lib/libavcodec.*.dylib >/dev/null 2>&1; then
  XWMA_FLAGS="-DRT_XWMA_AVCODEC -I $FFM/include"; XWMA_LIBS=( -L"$FFM/lib" -lavcodec -lavutil -Wl,-rpath,"$FFM/lib" )
  echo "xWMA: libavcodec from $FFM"
else
  XWMA_FLAGS=""; XWMA_LIBS=(); echo "xWMA: NO libavcodec (brew install ffmpeg) -- compressed SE/voice will be silent"
fi
for need in "$DERISK/XenonUtils/image.h" "$DERISK/thirdparty/simde/x86/sse.h" "$DERISK_BUILD/XenonUtils/libXenonUtils.a" \
            "$SDL_SRC/include/SDL3/SDL.h" "$MVK_DYLIB" "$VKH/vulkan/vulkan.h" "$OBJCOPY"; do
  [ -e "$need" ] || { echo "MISSING DEPENDENCY: $need (see the header of this script)"; exit 2; }
done
SDL_DYLIB=$(ls "$SDL_BUILD"/libSDL3.*.dylib 2>/dev/null | head -1)
[ -n "$SDL_DYLIB" ] || { echo "MISSING DEPENDENCY: $SDL_BUILD/libSDL3.*.dylib (shared SDL3 build)"; exit 2; }
ARCH="$(uname -m)"
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
# -fms-extensions is NOT used (see build_linux.sh history: it does not cover the goto-past-init
# case and -fms-compatibility breaks libc++/libstdc++).
STD="-std=c++20 -O2 -Wno-macro-redefined -DFUTARI_MODULE=0 -DFUTARI_BUILD_ID=\"$BUILD_ID\" -DRVK_VULKAN_LIBRARY=\"$MVK_LOADPATH\""
GAME_INC="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SHELL_INC="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
RT="-include out_reco/rt_indirect.h"
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"
# DECOMP_SKIP: the A/B CONTROL-ARM SWITCH, same contract as build_win_dll.sh (space-separated decomp TU basenames
# left OUT of the compile loop, so first-definition-wins hands those addresses back to the GENERATED bodies).
# HARNESS-ONLY, NEVER SHIP with it set. OBJ / OUT / COMPILE_ONLY exist for bisects: compile once, then link each
# arm from a copy of the object dir with one decomp_*.o removed (the rename pass mutates objects in place, so a
# relink must start from an un-renamed copy -- see scripts/boss1/fnf15_bisect_mac.sh).
DECOMP_SKIP="${DECOMP_SKIP:-}"
decomp_skipped(){ local n="$1" k; for k in $DECOMP_SKIP; do [ "$n" = "$k" ] && return 0; done; return 1; }
OBJ="${OBJ:-build/obj_mac}"
OUT="${OUT:-build/futari_merged}"
mkdir -p "$OBJ"
if [ "${LINK_ONLY:-0}" != "1" ]; then
rm -f "$OBJ"/*.o "$OBJ"/*.err "$OUT"

JOBS="${JOBS:-$(sysctl -n hw.ncpu 2>/dev/null || echo 8)}"
i=0
sem(){ i=$((i+1)); if [ $((i%JOBS)) -eq 0 ]; then wait; fi; }
cc(){ # name  src  flags...   (compiles the de-aliased copy under $OBJ/src when the pre-pass made one)
  local name="$1" src="$2"; shift 2
  local re="$OBJ/src/${src//\//__}"; [ -f "$re" ] && src="$re"
  ( "$CXX" $STD "$@" -c "$src" -o "$OBJ/$name.o" 2>"$OBJ/$name.err" || echo "FAILED: $name" ) &
  sem
}

echo "== de-alias pre-pass (Mach-O has no __attribute__((alias)); see header item 4; mac-build/dealias.py) =="
mkdir -p "$OBJ/src"; rm -f "$OBJ"/src/*.cpp
python3 mac-build/dealias.py "$OBJ/src" out_reco/*.cpp out_reco/merged/*.cpp shell/gen/*.cpp "$DECOMP_DIR"/game/*.cpp "$DECOMP_DIR"/shell/*.cpp || exit 1

echo "== DECOMP tree ($DECOMP_DIR/game/*.cpp + $DECOMP_DIR/shell/*.cpp — game_abn/ EXCLUDED; __imp__ overrides, linked FIRST) =="
for f in "$DECOMP_DIR"/game/*.cpp; do
  [ -f "$f" ] || continue
  n=$(basename "$f" .cpp); decomp_skipped "$n" && { echo "   [DECOMP_SKIP] game/$n"; continue; }
  cc "decomp_$n" "$f" $GAME_INC -I . $RT
done
for f in "$DECOMP_DIR"/shell/*.cpp; do
  [ -f "$f" ] || continue
  n=$(basename "$f" .cpp); decomp_skipped "$n" && { echo "   [DECOMP_SKIP] shell/$n"; continue; }
  cc "decomp_$n" "$f" $SHELL_INC -I . $XS $RT
done
echo "== GAME tree (out_reco/*.cpp, minus shell_only_stubs) =="
for f in out_reco/*.cpp; do
  n=$(basename "$f" .cpp); [ "$n" = "shell_only_stubs" ] && continue
  cc "game_$n" "$f" $GAME_INC $RT
done
echo "== SHELL guest tree (shell/gen/ppc_recomp.*.cpp) =="
for f in shell/gen/ppc_recomp.*.cpp; do
  n=$(basename "$f" .cpp); cc "shell_$n" "$f" $SHELL_INC $XS $RT
done
cc "shell_ppc_func_mapping" "shell/gen/ppc_func_mapping.cpp" $SHELL_INC $XS $RT -DPPCFuncMappings=PPCFuncMappings_shell
echo "== SHELL kernel =="
cc "shellkernel_rt"       "shell/gen/rt.cpp"       $SHELL_INC $XS $RT
cc "shellkernel_stubs"    "shell/gen/stubs.cpp"    $SHELL_INC $XS $RT -I "$SDL_SRC/include"
cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -I "$SDL_SRC/include"
cc "shellkernel_rt_xwma"  "shell/gen/rt_xwma.cpp" $XWMA_FLAGS
echo "== Gate-2 bridge =="
cc "merged_game"   "out_reco/merged/merged_game.cpp"   $GAME_INC $RT
cc "merged_bridge" "out_reco/merged/merged_bridge.cpp" $GAME_INC $RT
cc "merged_shell"  "out_reco/merged/merged_shell.cpp"  $GAME_INC $RT
echo "== Vulkan renderer (MoltenVK headers; SDL3 window) =="
cc "vk_render" "render/vk_render.cpp" -I "$VKH" -I "$SDL_SRC/include"

wait
NOBJ=$(ls "$OBJ"/*.o 2>/dev/null | wc -l | tr -d ' ')
echo "objects: $NOBJ"
FAILED=0
for e in "$OBJ"/*.err; do if grep -q 'error:' "$e" 2>/dev/null; then echo "--- $e ---"; grep -A2 'error:' "$e" | head -12; FAILED=1; fi; done
if [ "$FAILED" -ne 0 ]; then echo "COMPILE_INCOMPLETE"; exit 1; fi
[ "${COMPILE_ONLY:-0}" = "1" ] && { echo "COMPILE_ONLY: objects in $OBJ (un-renamed)"; exit 0; }
fi  # LINK_ONLY

# ---- link: first-definition-wins via rename-on-duplicate ----
LINKLINE=( $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/game_*.o "$OBJ"/merged_game.o "$OBJ"/merged_bridge.o "$OBJ"/merged_shell.o "$OBJ"/vk_render.o "$OBJ"/shell_*.o "$OBJ"/shellkernel_*.o )
LIBS=( "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$DERISK_BUILD/XenonAnalyse/libLibXenonAnalyse.a"
       "$DERISK_BUILD/thirdparty/disasm/libdisasm.a" "$DERISK_BUILD/thirdparty/xxHash/cmake_unofficial/libxxhash.a"
       "$DERISK_BUILD/thirdparty/fmt/libfmt.a" "$SDL_DYLIB" "$MVK_DYLIB" "${XWMA_LIBS[@]}" -lpthread -ldl -lm
       -Wl,-rpath,"$(cd "$(dirname "$SDL_DYLIB")" && pwd)" -Wl,-rpath,"$MVK/lib" )
# offline xWMA decoder/verifier (rt_xwma.cpp -DRT_XWMA_MAIN): build/rt_xwma <bank.xwb> [N out.wav] | xsb
if [ -n "$XWMA_FLAGS" ]; then
  "$CXX" -std=c++20 -O2 -DRT_XWMA_MAIN $XWMA_FLAGS shell/gen/rt_xwma.cpp "${XWMA_LIBS[@]}" -o build/rt_xwma 2>"$OBJ/rt_xwma_tool.err" \
    && echo "tool: build/rt_xwma" || echo "tool: build/rt_xwma FAILED (see $OBJ/rt_xwma_tool.err)"
fi
# first-definition-wins via rename-on-duplicate: mac-build/link_merge.py (the parser + objcopy pass that used to
# live inline here, shared with build_mac_dll.sh). Mutates the objects in place -- see COMPILE_ONLY above.
python3 mac-build/link_merge.py --cxx "$CXX" --objcopy "$OBJCOPY" --out "$OUT" --objdir "$OBJ" -- "${LINKLINE[@]}" -- "${LIBS[@]}" || { echo "LINK_FAILED"; exit 1; }
