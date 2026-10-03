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
#
# Dependencies:
#   brew install llvm cmake ninja molten-vk vulkan-headers
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
STD="-std=c++20 -O2 -Wno-macro-redefined -DFUTARI_MODULE=0 -DFUTARI_BUILD_ID=\"$BUILD_ID\" -DRVK_VULKAN_LIBRARY=\"$MVK_DYLIB\""
GAME_INC="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SHELL_INC="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
RT="-include out_reco/rt_indirect.h"
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"
OBJ=build/obj_mac
mkdir -p "$OBJ"
if [ "${LINK_ONLY:-0}" != "1" ]; then
rm -f "$OBJ"/*.o "$OBJ"/*.err build/futari_merged

JOBS="${JOBS:-$(sysctl -n hw.ncpu 2>/dev/null || echo 8)}"
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
echo "== SHELL kernel =="
cc "shellkernel_rt"       "shell/gen/rt.cpp"       $SHELL_INC $XS $RT
cc "shellkernel_stubs"    "shell/gen/stubs.cpp"    $SHELL_INC $XS $RT -I "$SDL_SRC/include"
cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -I "$SDL_SRC/include"
cc "shellkernel_rt_xwma"  "shell/gen/rt_xwma.cpp"
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
fi  # LINK_ONLY

# ---- link: first-definition-wins via rename-on-duplicate ----
LINKLINE=( $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/game_*.o "$OBJ"/merged_game.o "$OBJ"/merged_bridge.o "$OBJ"/merged_shell.o "$OBJ"/vk_render.o "$OBJ"/shell_*.o "$OBJ"/shellkernel_*.o )
LIBS=( "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$DERISK_BUILD/XenonAnalyse/libLibXenonAnalyse.a"
       "$DERISK_BUILD/thirdparty/disasm/libdisasm.a" "$DERISK_BUILD/thirdparty/xxHash/cmake_unofficial/libxxhash.a"
       "$DERISK_BUILD/thirdparty/fmt/libfmt.a" "$SDL_DYLIB" "$MVK_DYLIB" -lpthread -ldl -lm
       -Wl,-rpath,"$(cd "$(dirname "$SDL_DYLIB")" && pwd)" -Wl,-rpath,"$MVK/lib" )
link(){ "$CXX" -O2 -std=c++20 "${LINKLINE[@]}" -o build/futari_merged "${LIBS[@]}" -Wl,-map,build/futari_merged.map 2>"$OBJ/link.err"; }
echo "== LINK pass 1 (expect duplicate symbols; they are the merge) =="
if link; then echo "LINK_OK (no duplicates?) -> build/futari_merged"; exit 0; fi
# Apple ld prints either
#   duplicate symbol '_sym' in:\n    a.o\n    b.o           (ld64)
#   ld: duplicate symbol '_sym' in a.o and b.o              (ld-prime)
# Rename the definition in whichever of the two objects appears LATER in LINKLINE.
python3 - "$OBJ/link.err" "${LINKLINE[@]}" <<'EOF'
import re, sys, collections
err = open(sys.argv[1]).read(); order = {p: i for i, p in enumerate(sys.argv[2:])}
def idx(o):
    for p, i in order.items():
        if p.endswith(o) or o.endswith(p): return i
    return None
losers = collections.defaultdict(set)
for m in re.finditer(r"duplicate symbol '([^']+)' in:\s*\n\s*(\S+)\s*\n\s*(\S+)", err):
    s, a, b = m.groups(); ia, ib = idx(a), idx(b)
    if ia is None or ib is None: continue
    losers[a if ia > ib else b].add(s)
for m in re.finditer(r"duplicate symbol '([^']+)' in (\S+) and (\S+)", err):
    s, a, b = m.groups(); ia, ib = idx(a), idx(b)
    if ia is None or ib is None: continue
    losers[a if ia > ib else b].add(s)
n = 0
with open("build/obj_mac/dup_renames.txt", "w") as f:
    for o, syms in sorted(losers.items()):
        for s in sorted(syms): f.write(f"{o} {s}\n"); n += 1
print(f"duplicate definitions to rename: {n} across {len(losers)} objects")
EOF
[ -s "$OBJ/dup_renames.txt" ] || { echo "LINK_FAILED (no duplicate-symbol lines parsed — read $OBJ/link.err)"; tail -40 "$OBJ/link.err"; exit 1; }
echo "== renaming losing definitions (llvm-objcopy --redefine-sym) =="
awk '{print $1}' "$OBJ/dup_renames.txt" | sort -u | while read -r o; do
  args=(); while read -r sym; do args+=("--redefine-sym=${sym}=${sym}__dup_dropped"); done < <(awk -v o="$o" '$1==o{print $2}' "$OBJ/dup_renames.txt")
  src="$o"; [ -f "$src" ] || src="$OBJ/$(basename "$o")"
  "$OBJCOPY" "${args[@]}" "$src" "$src" || { echo "objcopy FAILED on $src"; exit 1; }
done
echo "== LINK pass 2 =="
if link; then echo "LINK_OK -> build/futari_merged"; else echo "LINK_FAILED"; tail -60 "$OBJ/link.err"; exit 1; fi
