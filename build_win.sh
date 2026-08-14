#!/bin/bash
# build_win.sh — NATIVE WINDOWS build of build/futari_merged.exe.
#   clang++ -target x86_64-pc-windows-msvc + lld-link + the COFF .lib deps in
#   ../xr-derisk/build-win. Port of build_merged.sh. Run from git-bash.
#
# Merge strategy (COFF): llvm-objcopy has no --weaken-symbol for COFF, so instead
# of demoting the shell's duplicate strong symbols we link with lld-link
# /FORCE:MULTIPLE and order GAME + merged_xex objects BEFORE the shell kernel
# objects — the linker keeps the first (game) definition of every duplicate
# (shared imports, byte-identical millicode, g_import_calls, rt_indirect, Xex
# stubs), exactly matching the objcopy-weaken intent. The strong-over-weak guest
# overrides (PPC_WEAK_FUNC) resolve natively. vk_render.cpp is OMITTED for the
# headless bring-up (rvk_present is a weak-undef → resolves to null → renderer
# skipped), so no Vulkan SDK is needed yet.
set -u
cd "$(dirname "$0")"
mkdir -p build
CXX="/c/Program Files/LLVM/bin/clang++.exe"
DERISK="external/xr-derisk"
VKSDK=$(ls -d /c/VulkanSDK/*/ 2>/dev/null | sort -V | tail -1)   # newest installed Vulkan SDK
# -DFUTARI_MODULE=0 selects the reco_normal descriptor in host/futari_module_desc.h (L3/E4 of
# _tmpscripts/dll_packaging_plan.md). It is in STD — i.e. on EVERY TU — deliberately: the
# retired -DGA_DSHIFT / -DGAME_*_VAL flags were sprayed onto a hand-picked subset, so a TU that
# later grew a use of one of them would have silently compiled reco_normal's constants. A macro
# on every TU costs nothing and removes that whole class. 0 is also the header's default, so
# this line is documentation as much as selection.
# FUTARI_BUILD_ID stamps the exe with the git HEAD (+ "-dirty") so the [env] boot banner can name
# the build a finding belongs to. The settings audit (2026-08-01) found a whole class of wrong
# attributions from NOT having this: an audio defect was blamed on a launcher pin when the
# deployed exe simply lacked the hook. Acceptance scripts assert on the banner, never on .bat text.
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
STD="--target=x86_64-pc-windows-msvc -std=c++20 -O2 -D_CRT_SECURE_NO_WARNINGS -Wno-macro-redefined -DFUTARI_MODULE=0 -DFUTARI_BUILD_ID=\"$BUILD_ID\""
GAME_INC="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SHELL_INC="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
RT="-include out_reco/rt_indirect.h"
# DECOMP_DIR: the readable-decomp source tree, split into its own sibling repo
# projects/futari_decomp on 2026-08-14 (registry + atlases + campaign ledger live there too).
# Override with env DECOMP_DIR for a pinned checkout; the seam/link semantics are unchanged —
# only the path moved.
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"
mkdir -p build/obj_win
rm -f build/obj_win/*.o build/obj_win/*.err build/futari_merged.exe

i=0
sem(){ i=$((i+1)); if [ $((i%12)) -eq 0 ]; then wait; fi; }
cc(){ # name  src  flags...
  local name="$1" src="$2"; shift 2
  ( "$CXX" $STD "$@" -c "$src" -o "build/obj_win/$name.o" 2>"build/obj_win/$name.err" || echo "FAILED: $name" ) &
  sem
}

echo "== DECOMP tree ($DECOMP_DIR/game/*.cpp + $DECOMP_DIR/shell/*.cpp — game_abn/ EXCLUDED; __imp__ overrides, linked FIRST) =="
for f in "$DECOMP_DIR"/game/*.cpp; do
  [ -f "$f" ] || continue
  # -I . : decomp TUs reference host/render headers realcomp-root-relative (repo split).
  n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $GAME_INC -I . $RT
done
# Shell-side decomp needs the SHELL headers: shell/gen/ppc_config.h differs from the game's
# (PPC_IMAGE_BASE 0x82000000 vs 0x88000000, different CODE_BASE/SIZE), and SHELL_INC puts
# shell/gen first so its config wins. Compiling a sub_82* body with GAME_INC would build it
# against the wrong module geometry.
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
cc "shellkernel_stubs" "shell/gen/stubs.cpp" $SHELL_INC $XS $RT
# host audio sink (RT_AUDIODUMP wav capture + RT_AUDIO WASAPI backend); pure host code,
# no ppc headers — compiled bare like vk_render. Named shellkernel_* so the link glob takes it.
cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -Ithirdparty/sdl3/include
# host xWMA (WMAudio2) decoder for the compressed SE/VOICE/SYS_SE wave banks (RT_AUDIOXWMA);
# pure host code like rt_audio.cpp — .xwb parsing + the in-box WMA decoder DMO (ole32 only).
cc "shellkernel_rt_xwma" "shell/gen/rt_xwma.cpp"

# merged_xex.cpp was split along the MODULE line (L2 of _tmpscripts/dll_packaging_plan.md §2.3):
#   merged_game.cpp    166 sub_88 game-module hooks   -> becomes the module DLL's TU at E6
#   merged_bridge.cpp  the 3 Xex fns + rt_load_game_data_sections + the RT_REATTACH lever
#   merged_shell.cpp   157 sub_82 shell hooks + the idle/render-loop injection
#   merged_common.h    shared scaffolding (GA_* block, rt_heapdump, the 3 g_js_* inline vars)
# All three keep merged_xex.o's exact position in the link line, game-side first, so the
# first-def-wins ordering against game_*.o / shell_*.o is unchanged.
echo "== Gate-2 bridge (merged_xex 3-way split: game / bridge / shell) =="
cc "merged_game"   "out_reco/merged/merged_game.cpp"   $GAME_INC $RT
cc "merged_bridge" "out_reco/merged/merged_bridge.cpp" $GAME_INC $RT
cc "merged_shell"  "out_reco/merged/merged_shell.cpp"  $GAME_INC $RT

echo "== Vulkan renderer (vk_render, RT_VK-gated) =="
cc "vk_render" "render/vk_render.cpp" -I "${VKSDK}Include"

wait
NOBJ=$(ls build/obj_win/*.o 2>/dev/null | wc -l)
echo "objects: $NOBJ"
FAILED=0
for e in build/obj_win/*.err; do if grep -q ' error' "$e" 2>/dev/null || grep -q 'error:' "$e" 2>/dev/null; then echo "--- $e ---"; grep -A2 'error' "$e" | head -12; FAILED=1; fi; done
if [ "$FAILED" -ne 0 ]; then echo "COMPILE_INCOMPLETE"; exit 1; fi

echo "== LINK (lld-link /FORCE:MULTIPLE, game+merged first) =="
"$CXX" --target=x86_64-pc-windows-msvc -fuse-ld=lld -O2 -std=c++20 \
  $(ls build/obj_win/decomp_*.o 2>/dev/null) build/obj_win/game_*.o build/obj_win/merged_game.o build/obj_win/merged_bridge.o build/obj_win/merged_shell.o build/obj_win/vk_render.o build/obj_win/shell_*.o build/obj_win/shellkernel_*.o \
  -o build/futari_merged.exe \
  "$DERISK/build-win/XenonUtils/XenonUtils.lib" \
  "$DERISK/build-win/XenonAnalyse/LibXenonAnalyse.lib" \
  "$DERISK/build-win/thirdparty/disasm/disasm.lib" \
  "$DERISK/build-win/thirdparty/xxHash/cmake_unofficial/xxhash.lib" \
  "$DERISK/build-win/thirdparty/fmt/fmt.lib" \
  "${VKSDK}Lib/vulkan-1.lib" \
  thirdparty/sdl3/lib/SDL3-static.lib -luser32 -lole32 -lwinmm -limm32 -loleaut32 -lversion -ladvapi32 -lsetupapi -lshell32 -lgdi32 -luuid \
  -Xlinker /FORCE:MULTIPLE \
  -Xlinker /MAP:build/futari_merged.map \
  2>build/obj_win/link.err && echo "LINK_OK -> build/futari_merged.exe" || { echo "LINK_FAILED"; tail -50 build/obj_win/link.err; }
