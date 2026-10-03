#!/bin/bash
# build_linux.sh — NATIVE LINUX build of build/futari_merged (2026-10-03).
#   clang++ (host triple) + lld, port of build_win.sh with the SAME merge strategy:
#   `-Wl,--allow-multiple-definition` is ELF's /FORCE:MULTIPLE — the linker keeps the FIRST
#   definition of every duplicate — so the object order (decomp, GAME + merged, vk_render,
#   shell guest, shell kernel) is copied from build_win.sh verbatim and carries the same
#   first-def-wins semantics (shared imports, byte-identical millicode, g_import_calls,
#   rt_indirect, Xex stubs). The strong-over-weak guest overrides (PPC_WEAK_FUNC) resolve
#   natively. This replaces the objcopy --weaken-symbol dance of the retired
#   scripts/build_merged.sh, which pre-dates the L2 merged_xex split and the decomp repo.
#
# This is the macOS/Deck proving ground (BACKLOG #12): everything except the GPU surface and
# the audio device is identical on macOS, so a Linux compile+link flushes out portability
# breakage without a Mac in the loop. Since 2026-10-03 the on-screen window (RVK_WINDOW), the
# Vulkan surface and host controllers come from SDL3 on this build (Win32 + XInput stay on
# Windows); host keyboard (RT_PAD_HOST) is the pre-existing X11 XQueryKeymap poller. What is
# NOT here yet: the xWMA decoder (Media Foundation DMO; rt_xwma reports "no host decoder backend").
#
# Dependencies (all under external/, gitignored — see README "external/"):
#   external/xr-derisk           XenonRecomp checkout (XenonUtils + simde) built with
#                                 cmake -S external/xr-derisk -B external/xr-derisk/build -G Ninja
#                                 ninja -C external/xr-derisk/build XenonUtils LibXenonAnalyse disasm xxhash fmt
#   external/SDL                 SDL 3.x static build with audio + video (X11 and/or Wayland) +
#                                 Vulkan + joystick/gamepad (the window, surface and controllers):
#                                 cmake -S external/SDL -B external/SDL/build -G Ninja -DSDL_SHARED=OFF -DSDL_STATIC=ON
#                                   -DSDL_AUDIO=ON -DSDL_VIDEO=ON -DSDL_VULKAN=ON -DSDL_JOYSTICK=ON -DSDL_HIDAPI=ON
#                                   -DSDL_OPENGL=OFF -DSDL_OPENGLES=OFF -DSDL_RENDER=OFF -DSDL_GPU=OFF -DSDL_HAPTIC=OFF
#                                   -DSDL_CAMERA=OFF -DSDL_SENSOR=OFF -DSDL_POWER=OFF -DSDL_DIALOG=OFF
#                                   -DSDL_TESTS=OFF -DSDL_EXAMPLES=OFF -DSDL_INSTALL=OFF
#                                 ninja -C external/SDL/build
#                                 (X11 needs libx11-dev + the extension -dev packages SDL's README
#                                 lists; any missing extension can be switched off with -DSDL_X11_<EXT>=OFF.
#                                 SDL dlopens X11/Wayland/udev at runtime, so nothing extra is linked here.)
#   system                       libvulkan-dev (headers + loader), clang, lld
#   ../futari_decomp             the readable-decomp sibling repo (DECOMP_DIR, same as build_win.sh)
set -u
cd "$(dirname "$0")"
mkdir -p build
CXX="${CXX:-clang++}"
DERISK="${DERISK:-external/xr-derisk}"
DERISK_BUILD="${DERISK_BUILD:-$DERISK/build}"
SDL_SRC="${SDL_SRC:-external/SDL}"
SDL_BUILD="${SDL_BUILD:-$SDL_SRC/build}"
for need in "$DERISK/XenonUtils/image.h" "$DERISK/thirdparty/simde/x86/sse.h" \
            "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$SDL_BUILD/libSDL3.a" "$SDL_SRC/include/SDL3/SDL.h"; do
  [ -e "$need" ] || { echo "MISSING DEPENDENCY: $need (see the header of this script)"; exit 2; }
done
# FUTARI_MODULE / FUTARI_BUILD_ID: same contract as build_win.sh (see its comments).
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
STD="-std=c++20 -O2 -Wno-macro-redefined -DFUTARI_MODULE=0 -DFUTARI_BUILD_ID=\"$BUILD_ID\""
GAME_INC="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SHELL_INC="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
RT="-include out_reco/rt_indirect.h"
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"
OBJ=build/obj_linux
mkdir -p "$OBJ"
# LINK_ONLY=1: skip the compile phase and relink what is in $OBJ (iteration aid; a full run
# always starts from a clean object dir, like build_win.sh).
if [ "${LINK_ONLY:-0}" != "1" ]; then
rm -f "$OBJ"/*.o "$OBJ"/*.err build/futari_merged

JOBS="${JOBS:-$(nproc 2>/dev/null || echo 4)}"
i=0
sem(){ i=$((i+1)); if [ $((i%JOBS)) -eq 0 ]; then wait; fi; }
cc(){ # name  src  flags...
  local name="$1" src="$2"; shift 2
  ( "$CXX" $STD "$@" -c "$src" -o "$OBJ/$name.o" 2>"$OBJ/$name.err" || echo "FAILED: $name" ) &
  sem
}

echo "== DECOMP tree ($DECOMP_DIR/game/*.cpp + $DECOMP_DIR/shell/*.cpp — game_abn/ EXCLUDED; __imp__ overrides, linked FIRST) =="
for f in "$DECOMP_DIR"/game/*.cpp; do
  [ -f "$f" ] || continue
  n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $GAME_INC -I . $RT
done
for f in "$DECOMP_DIR"/shell/*.cpp; do
  [ -f "$f" ] || continue
  n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $SHELL_INC -I . $XS $RT
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

echo "== SHELL kernel (real vblank/notify/signin/D3D9 layer) =="
cc "shellkernel_rt"    "shell/gen/rt.cpp"    $SHELL_INC $XS $RT
cc "shellkernel_stubs" "shell/gen/stubs.cpp" $SHELL_INC $XS $RT -I "$SDL_SRC/include"   # SDL3 gamepad arm
cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -I "$SDL_SRC/include"
cc "shellkernel_rt_xwma"  "shell/gen/rt_xwma.cpp"

echo "== Gate-2 bridge (merged_xex 3-way split: game / bridge / shell) =="
cc "merged_game"   "out_reco/merged/merged_game.cpp"   $GAME_INC $RT
cc "merged_bridge" "out_reco/merged/merged_bridge.cpp" $GAME_INC $RT
cc "merged_shell"  "out_reco/merged/merged_shell.cpp"  $GAME_INC $RT

echo "== Vulkan renderer (vk_render, RT_VK-gated; system vulkan headers; SDL3 window) =="
cc "vk_render" "render/vk_render.cpp" -I "$SDL_SRC/include"

wait
NOBJ=$(ls "$OBJ"/*.o 2>/dev/null | wc -l)
echo "objects: $NOBJ"
FAILED=0
for e in "$OBJ"/*.err; do if grep -q 'error:' "$e" 2>/dev/null; then echo "--- $e ---"; grep -A2 'error:' "$e" | head -12; FAILED=1; fi; done
if [ "$FAILED" -ne 0 ]; then echo "COMPILE_INCOMPLETE"; exit 1; fi
fi  # LINK_ONLY

echo "== LINK (lld, --allow-multiple-definition, decomp + game + merged first) =="
"$CXX" -fuse-ld=lld -O2 -std=c++20 \
  $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/game_*.o "$OBJ"/merged_game.o "$OBJ"/merged_bridge.o "$OBJ"/merged_shell.o "$OBJ"/vk_render.o "$OBJ"/shell_*.o "$OBJ"/shellkernel_*.o \
  -o build/futari_merged \
  "$DERISK_BUILD/XenonUtils/libXenonUtils.a" \
  "$DERISK_BUILD/XenonAnalyse/libLibXenonAnalyse.a" \
  "$DERISK_BUILD/thirdparty/disasm/libdisasm.a" \
  "$DERISK_BUILD/thirdparty/xxHash/cmake_unofficial/libxxhash.a" \
  "$DERISK_BUILD/thirdparty/fmt/libfmt.a" \
  "$SDL_BUILD/libSDL3.a" \
  -lvulkan -lpthread -ldl -lm \
  -Wl,--allow-multiple-definition \
  -Wl,-Map,build/futari_merged.map \
  2>"$OBJ/link.err" && echo "LINK_OK -> build/futari_merged" || { echo "LINK_FAILED"; tail -50 "$OBJ/link.err"; exit 1; }
