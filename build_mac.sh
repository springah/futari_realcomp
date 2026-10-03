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
STD="-std=c++20 -O2 -Wno-macro-redefined -DFUTARI_MODULE=0 -DFUTARI_BUILD_ID=\"$BUILD_ID\" -DRVK_VULKAN_LIBRARY=\"$MVK_DYLIB\""
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

echo "== de-alias pre-pass (Mach-O has no __attribute__((alias)); see header item 4) =="
mkdir -p "$OBJ/src"; rm -f "$OBJ"/src/*.cpp
python3 - "$OBJ/src" out_reco/*.cpp out_reco/merged/*.cpp shell/gen/*.cpp "$DECOMP_DIR"/game/*.cpp "$DECOMP_DIR"/shell/*.cpp <<'EOF'
import re, sys, os
out = sys.argv[1]
# column-0 only: the generated shape. Comments that quote the shape (decomp notes) start with // and are left alone.
# The target is either a string literal or the one stringified macro the shell tree uses for its CRT entry
# (shell/gen/ppc_recomp.5.cpp: alias(RT_XSTART_ALIAS_STR) == "__imp___xstart", renamed by -D in the merged build);
# as a plain token it goes through the same -D rename, so the stub form needs no special case at link.
pat = re.compile(r'^__attribute__\(\(alias\((?:"(\w+)"|(\w+))\)\)\)\s*PPC_WEAK_FUNC\((\w+)\);', re.M)
macro_targets = {'RT_XSTART_ALIAS_STR': '__imp___xstart'}
def stub(m):
    tgt = m.group(1) or macro_targets[m.group(2)]
    return f'PPC_FUNC_IMPL({tgt}); PPC_WEAK_FUNC({m.group(3)}) {{ {tgt}(ctx, base); }}'
files = total = 0
for f in sys.argv[2:]:
    if not os.path.isfile(f): continue
    t = open(f).read()
    if 'alias(' not in t: continue
    t2, n = pat.subn(stub, t)
    if n == 0: continue
    open(os.path.join(out, f.replace('/', '__')), 'w').write(t2); files += 1; total += n
print(f"rewrote {total} alias lines in {files} TUs -> {out}/")
EOF

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
link(){ "$CXX" -O2 -std=c++20 "${LINKLINE[@]}" -o "$OUT" "${LIBS[@]}" -Wl,-map,"$OUT.map" 2>"$OBJ/link.err"; }
echo "== LINK pass 1 (expect duplicate symbols; they are the merge) =="
if link; then echo "LINK_OK (no duplicates?) -> $OUT"; exit 0; fi
# Apple ld prints either
#   duplicate symbol '_sym' in:\n    a.o\n    b.o [\n    c.o ...]   (ld64 / ld-prime, one object per indented line; three-way
#                                                                   duplicates happen: game_rt + game_stubs + shellkernel_stubs)
#   ld: duplicate symbol '_sym' in a.o and b.o                      (older ld-prime)
# and it DEMANGLES C++ names ('sub_X(PPCContext&, unsigned char*)'), so each name is mapped back to the
# object's mangled symbol through llvm-nm + llvm-cxxfilt before the rename. Every definition except the one
# in the object that appears EARLIEST in LINKLINE is renamed (first-definition-wins, as build_win.sh).
python3 - "$OBJ/link.err" "$OBJCOPY" "$OBJ/dup_renames.txt" "${LINKLINE[@]}" <<'EOF'
import re, sys, collections, subprocess, os
err = open(sys.argv[1]).read(); objcopy = sys.argv[2]; renames_path = sys.argv[3]; linkline = sys.argv[4:]
order = {p: i for i, p in enumerate(linkline)}
def idx(o):
    for p, i in order.items():
        if p == o or o.endswith('/' + p) or p.endswith('/' + o) or os.path.basename(p) == os.path.basename(o): return i
    return None
groups = []  # (symbol-as-printed, [objects])
for m in re.finditer(r"duplicate symbol '([^']+)' in:\n((?:[ \t]+\S+\n?)+)", err):
    groups.append((m.group(1), m.group(2).split()))
for m in re.finditer(r"duplicate symbol '([^']+)' in (\S+) and (\S+)", err):
    groups.append((m.group(1), [m.group(2), m.group(3)]))
cxxfilt = os.path.join(os.path.dirname(objcopy), 'llvm-cxxfilt'); nm = os.path.join(os.path.dirname(objcopy), 'llvm-nm')
_maps = {}
def mangled(obj, printed):
    """ld prints C symbols as-is ('___imp__X') and C++ ones demangled; return the real symbol in obj."""
    if obj not in _maps:
        syms = subprocess.run([nm, '--defined-only', '--format=just-symbols', obj], capture_output=True, text=True).stdout.split()
        dem = subprocess.run([cxxfilt], input='\n'.join(syms), capture_output=True, text=True).stdout.split('\n')
        _maps[obj] = ({s: s for s in syms}, dict(zip(dem, syms)))
    direct, demap = _maps[obj]
    return direct.get(printed) or demap.get(printed)
losers = collections.defaultdict(set); unresolved = []
for sym, objs in groups:
    ranked = [(idx(o), o) for o in objs]
    if any(i is None for i, _ in ranked): unresolved.append((sym, objs)); continue
    ranked.sort()
    for _, o in ranked[1:]:
        real = mangled(o, sym)
        if real is None: unresolved.append((sym, [o])); continue
        losers[o].add(real)
n = 0
with open(renames_path, "w") as f:
    for o, syms in sorted(losers.items()):
        for s in sorted(syms): f.write(f"{o} {s}\n"); n += 1
print(f"duplicate groups: {len(groups)}; definitions to rename: {n} across {len(losers)} objects")
for sym, objs in unresolved: print(f"  UNRESOLVED: {sym} in {objs}")
EOF
[ -s "$OBJ/dup_renames.txt" ] || { echo "LINK_FAILED (no duplicate-symbol lines parsed — read $OBJ/link.err)"; tail -40 "$OBJ/link.err"; exit 1; }
echo "== renaming losing definitions (llvm-objcopy --redefine-sym) =="
awk '{print $1}' "$OBJ/dup_renames.txt" | sort -u | while read -r o; do
  tag="$(basename "$o" .o)"   # per-object suffix: the same symbol can lose in two objects (game_stubs AND shellkernel_stubs)
  args=(); while read -r sym; do args+=("--redefine-sym=${sym}=${sym}__dup_dropped__${tag}"); done < <(awk -v o="$o" '$1==o{print $2}' "$OBJ/dup_renames.txt")
  src="$o"; [ -f "$src" ] || src="$OBJ/$(basename "$o")"
  "$OBJCOPY" "${args[@]}" "$src" "$src" || { echo "objcopy FAILED on $src"; exit 1; }
done
echo "== LINK pass 2 =="
if link; then echo "LINK_OK -> $OUT"; else echo "LINK_FAILED"; tail -60 "$OBJ/link.err"; exit 1; fi
