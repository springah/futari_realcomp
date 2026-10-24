#!/bin/bash
# build_mac_dll.sh — the COMBINED engine on macOS (the two-mode family-and-friends build, beta 3):
#
#   build/futari_combined              the module-agnostic host (shell + kernel + renderer + bridge)
#   build/futari_game_normal.dylib     reco_normal   (ARCADE 1.5,    modeIdx 0)  <- out_reco/
#   build/futari_game_abn.dylib        reco_abnormal (XBOX 360 mode, modeIdx 1)  <- out_reco_abn/
#
# The macOS twin of build_win_dll.sh: same three compile shapes (-DFUTARI_COMBINED=1 host;
# -DFUTARI_MODULE=<0|1> -DFUTARI_IN_MODULE_DLL=1 modules), same object split (the L2 module line), same
# link-line order (decomp_* first, first-definition-wins), same abn exclusion case list -- read that
# script's header for WHY each of those is what it is. What is Mac-specific is exactly what build_mac.sh
# documents: the de-alias pre-pass (mac-build/dealias.py), the rename-on-duplicate link
# (mac-build/link_merge.py; here also for the -dynamiclib links), MoltenVK + shared SDL3, and the module
# file being a .dylib found by host/module_registry.cpp's dlopen arm (RT_MODDLL_DIR, then the executable's
# own directory). The ABI (host/futari_host_abi.h + the two moduleshim/ files) is NOT regenerated here:
# tools/gen_host_abi.py measures COFF objects; the checked-in ABI is the one the Windows build last
# measured, and a module link that needs a symbol it lacks fails loudly at link (undefined symbol), which
# is the same tripwire one step later.
#
#   bash build_mac_dll.sh                       host + both modules
#   HOST_ONLY=1 / MODULES_ONLY=1                one half
#   LINK_ONLY=1                                 relink from the existing object dirs (no compile)
#   DECOMP_SKIP="tu tu"                         control-arm switch, same contract as build_mac.sh (HARNESS-ONLY)
#   MVK_LOADPATH=...  FFM=/nonexistent          as build_mac.sh (the .app build passes both)
#   MACOSX_DEPLOYMENT_TARGET=13.0               default; the bundle must run on more than the build Mac
#   OUTDIR=build/app OBJSFX=_app                 separate outputs/object dirs (the .app build uses these so it never
#                                               overwrites the drive/gate binaries under build/)
set -u
cd "$(dirname "$0")"
mkdir -p build
BREW="$(brew --prefix 2>/dev/null || echo /opt/homebrew)"
CXX="${CXX:-$BREW/opt/llvm/bin/clang++}"; [ -x "$CXX" ] || CXX=clang++
OBJCOPY="${OBJCOPY:-$BREW/opt/llvm/bin/llvm-objcopy}"
DERISK="${DERISK:-external/xr-derisk}"; DERISK_BUILD="${DERISK_BUILD:-$DERISK/build}"
SDL_SRC="${SDL_SRC:-external/SDL}"; SDL_BUILD="${SDL_BUILD:-$SDL_SRC/build}"
MVK="${MVK:-$BREW/opt/molten-vk}"; VKH="${VKH:-$BREW/opt/vulkan-headers/include}"; [ -d "$VKH/vulkan" ] || VKH="$MVK/include"
MVK_DYLIB="$MVK/lib/libMoltenVK.dylib"; MVK_LOADPATH="${MVK_LOADPATH:-$MVK_DYLIB}"
export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-13.0}"
FFM="${FFM:-$BREW/opt/ffmpeg}"
if [ -f "$FFM/include/libavcodec/avcodec.h" ] && ls "$FFM"/lib/libavcodec.*.dylib >/dev/null 2>&1; then
  XWMA_FLAGS="-DRT_XWMA_AVCODEC -I $FFM/include"; XWMA_LIBS=( -L"$FFM/lib" -lavcodec -lavutil -Wl,-rpath,"$FFM/lib" ); echo "xWMA: libavcodec from $FFM"
else XWMA_FLAGS=""; XWMA_LIBS=(); echo "xWMA: NO libavcodec -- the shipping audio path is guest-native, nothing lost"; fi
MODULES="${MODULES:-normal abn}"
OUTDIR="${OUTDIR:-build}"; OBJSFX="${OBJSFX:-}"; mkdir -p "$OUTDIR"     # which module dylibs to build (MODULES="normal" while the abn tree is absent)
for need in "$DERISK/XenonUtils/image.h" "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$SDL_SRC/include/SDL3/SDL.h" "$MVK_DYLIB" "$VKH/vulkan/vulkan.h" "$OBJCOPY" \
            out_reco/ppc_recomp.0.cpp moduleshim/module_shim_reco_normal.cpp; do
  [ -e "$need" ] || { echo "MISSING DEPENDENCY: $need"; exit 2; }
done
SDL_DYLIB=$(ls "$SDL_BUILD"/libSDL3.*.dylib 2>/dev/null | head -1); [ -n "$SDL_DYLIB" ] || { echo "MISSING: shared SDL3 build"; exit 2; }
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
EXTRA_CXX="${EXTRA_CXX:-}"
BASE="-std=c++20 -O2 -Wno-macro-redefined -DFUTARI_BUILD_ID=\"$BUILD_ID\" -DRVK_VULKAN_LIBRARY=\"$MVK_LOADPATH\" $EXTRA_CXX"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"
DECOMP_SKIP="${DECOMP_SKIP:-}"
decomp_skipped(){ local n="$1" k; for k in $DECOMP_SKIP; do [ "$n" = "$k" ] && return 0; done; return 1; }
JOBS="${JOBS:-$(sysctl -n hw.ncpu 2>/dev/null || echo 8)}"
SRC="build/obj_mac_dll_src$OBJSFX"   # the de-aliased copies, shared by every arm (names are path-encoded)
LIBS_HOST=( "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$DERISK_BUILD/XenonAnalyse/libLibXenonAnalyse.a"
       "$DERISK_BUILD/thirdparty/disasm/libdisasm.a" "$DERISK_BUILD/thirdparty/xxHash/cmake_unofficial/libxxhash.a"
       "$DERISK_BUILD/thirdparty/fmt/libfmt.a" "$SDL_DYLIB" "$MVK_DYLIB" "${XWMA_LIBS[@]}" -lpthread -ldl -lm
       -Wl,-rpath,"$(cd "$(dirname "$SDL_DYLIB")" && pwd)" -Wl,-rpath,"$MVK/lib" )
fail=0
banner(){ echo; echo "=============== $* ==============="; }
i=0; sem(){ i=$((i+1)); if [ $((i%JOBS)) -eq 0 ]; then wait; fi; }
cc(){ # name src flags...  (compiles the de-aliased copy when the pre-pass made one)
  local name="$1" src="$2"; shift 2
  local re="$SRC/${src//\//__}"; [ -f "$re" ] && src="$re"
  ( "$CXX" $STD "$@" -c "$src" -o "$OBJ/$name.o" 2>"$OBJ/$name.err" || echo "FAILED: $name" ) &
  sem
}
check_errs(){ local bad=0 e; for e in "$OBJ"/*.err; do grep -q 'error:' "$e" 2>/dev/null && { echo "--- $e ---"; grep -A2 'error:' "$e" | head -12; bad=1; }; done; return $bad; }

if [ "${LINK_ONLY:-0}" != "1" ]; then
  banner "0. de-alias pre-pass (Mach-O has no __attribute__((alias)))"
  rm -rf "$SRC"; mkdir -p "$SRC"
  python3 mac-build/dealias.py "$SRC" out_reco/*.cpp out_reco_abn/*.cpp out_reco/merged/*.cpp shell/gen/*.cpp \
      "$DECOMP_DIR"/game/*.cpp "$DECOMP_DIR"/game_abn/*.cpp "$DECOMP_DIR"/shell/*.cpp moduleshim/*.cpp host/*.cpp || exit 1
fi

# --------------------------------------------------------------------------------------------
# 1. HOST
# --------------------------------------------------------------------------------------------
if [ "${MODULES_ONLY:-0}" != "1" ]; then
banner "1. HOST ($OUTDIR/futari_combined)"
OBJ="build/obj_mac_host$OBJSFX"; OUT="$OUTDIR/futari_combined"; mkdir -p "$OBJ"
STD="$BASE -DFUTARI_COMBINED=1 -DFUTARI_MODULE=0"
GI="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SI="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
RT="-include out_reco/rt_indirect.h"
if [ "${LINK_ONLY:-0}" != "1" ]; then
  rm -f "$OBJ"/*.o "$OBJ"/*.err; i=0
  echo "-- decomp (shell only; decomp/game* rides into the modules)"
  for f in "$DECOMP_DIR"/shell/*.cpp; do n=$(basename "$f" .cpp); decomp_skipped "$n" && { echo "   [DECOMP_SKIP] shell/$n"; continue; }; cc "decomp_$n" "$f" $SI -I . $XS $RT; done
  echo "-- game-tree KERNEL (rt/stubs/harness/rt_phys only; the generated tree has left the host)"
  cc "game_rt"      "out_reco/rt.cpp"      $GI $RT
  cc "game_stubs"   "out_reco/stubs.cpp"   $GI $RT
  cc "game_harness" "out_reco/harness.cpp" $GI $RT
  cc "game_rt_phys" "out_reco/rt_phys.cpp" $GI $RT
  echo "-- module registry (load / bind / activate / swap)"
  cc "host_module_registry" "host/module_registry.cpp" $GI $RT
  echo "-- merged host halves (bridge + shell; merged_game.cpp is module-side)"
  cc "merged_bridge" "out_reco/merged/merged_bridge.cpp" $GI $RT
  cc "merged_shell"  "out_reco/merged/merged_shell.cpp"  $GI $RT
  echo "-- shell guest tree"
  for f in shell/gen/ppc_recomp.*.cpp; do n=$(basename "$f" .cpp); cc "shell_$n" "$f" $SI $XS $RT; done
  cc "shell_ppc_func_mapping" "shell/gen/ppc_func_mapping.cpp" $SI $XS $RT -DPPCFuncMappings=PPCFuncMappings_shell
  echo "-- shell kernel + audio"
  cc "shellkernel_rt"       "shell/gen/rt.cpp"       $SI $XS $RT
  cc "shellkernel_stubs"    "shell/gen/stubs.cpp"    $SI $XS $RT -I "$SDL_SRC/include"
  cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -I "$SDL_SRC/include"
  cc "shellkernel_rt_xwma"  "shell/gen/rt_xwma.cpp"  $XWMA_FLAGS
  echo "-- renderer"
  cc "vk_render" "render/vk_render.cpp" -I "$VKH" -I "$SDL_SRC/include"
  wait
  check_errs || { echo "HOST COMPILE_INCOMPLETE"; exit 1; }
  echo "host objects: $(ls "$OBJ"/*.o | wc -l | tr -d ' ')"
fi
# ORDER IS LOAD-BEARING (build_win_dll.sh "1. HOST EXE"): game_* kernel copies before shell_*/shellkernel_* so the GAME copy of
# the 66 shared __imp__X wins, exactly as the per-mode exes; decomp_* first (first-definition-wins overrides).
LINKLINE=( $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/game_*.o "$OBJ"/host_module_registry.o "$OBJ"/merged_bridge.o "$OBJ"/merged_shell.o "$OBJ"/vk_render.o "$OBJ"/shell_*.o "$OBJ"/shellkernel_*.o )
python3 mac-build/link_merge.py --cxx "$CXX" --objcopy "$OBJCOPY" --out "$OUT" --objdir "$OBJ" -- "${LINKLINE[@]}" -- "${LIBS_HOST[@]}" || { echo "HOST LINK_FAILED"; exit 1; }
fi

# --------------------------------------------------------------------------------------------
# 2. MODULE DYLIBS
# --------------------------------------------------------------------------------------------
build_module(){   # $1 name  $2 tree  $3 modidx  $4 out
  local NAME="$1" TREE="$2" MIDX="$3" OUTM="$4"
  banner "2. MODULE $OUTM  ($NAME, modeIdx $MIDX, tree $TREE)"
  OBJ="build/obj_mac_mod_$NAME$OBJSFX"; mkdir -p "$OBJ"
  [ -f "$OUTM" ] && mv -f "$OUTM" "$OUTM.lastgood"     # a failed link retires, never deletes (r23-w38 lesson)
  STD="$BASE -DFUTARI_MODULE=$MIDX -DFUTARI_IN_MODULE_DLL=1"
  local GI="-I $TREE -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde" RT="-include $TREE/rt_indirect.h" MAP=""
  [ "$MIDX" = "1" ] && MAP="-include $TREE/abn_symbol_map.h"
  if [ "${LINK_ONLY:-0}" != "1" ]; then
    rm -f "$OBJ"/*.o "$OBJ"/*.err; i=0
    echo "-- generated tree"
    for f in $TREE/ppc_recomp.*.cpp; do n=$(basename "$f" .cpp); cc "gen_$n" "$f" $GI $RT; done
    cc "gen_ppc_func_mapping" "$TREE/ppc_func_mapping.cpp" $GI $RT
    echo "-- game hooks (merged_game.cpp, +8 renamed on the abn arm)"
    cc "merged_game" "out_reco/merged/merged_game.cpp" $GI $RT $MAP
    echo "-- decomp game TUs"
    for f in "$DECOMP_DIR"/game/*.cpp; do
      n=$(basename "$f" .cpp)
      decomp_skipped "$n" && { echo "   [DECOMP_SKIP] game/$n"; continue; }
      # ABN-EXCLUDED TUs: bodies that embed reco_normal .data literals (+0x60 in the abn image). THE LIST IS
      # build_win_dll.sh's, verbatim -- every entry is justified there; keep the two in sync.
      if [ "$MIDX" = "1" ]; then
        case "$n" in game_entry_msgs|asset_decode|asset_pump|archive|mem_util|asset_upload|page_bake|objaction|objaction_queue|objaction_queue2|bossvein_object|fam4_object|fam1_arms|fam3_arms|fam9_arms|fam10_arms|fam11_tick|paperdoll2_draw|class233_236_draw|actor3pose_draw|objnode_park|objnode_parkcensus|famk1|famk9|pagescene|famk2|famk11|famk12|famk30|famk5|famk28|bossscript_w165|classes_w165|cutscene_w165|encounter_w165|famk21_w165|famk4_7_w165|famk8_10_w165|frontend_w162|objects_w162|pagetrans_w162|pump_w162|results_w162|scene_w165|select_w165|ship_w162|tracking_w165) continue;; esac
      fi
      cc "decomp_$n" "$f" $GI -I . $RT $MAP
    done
    if [ "$MIDX" = "1" ]; then
      for f in "$DECOMP_DIR"/game_abn/*.cpp; do n=$(basename "$f" .cpp); decomp_skipped "$n" && { echo "   [DECOMP_SKIP] game_abn/$n"; continue; }; cc "decomp_$n" "$f" $GI -I . $RT; done
    fi
    echo "-- host-facing shim (moduleshim/, NEVER a glob-swept dir)"
    cc "module_shim" "moduleshim/module_shim_$NAME.cpp" $GI $RT
    wait
    check_errs || { echo "MODULE COMPILE_INCOMPLETE ($OUTM)"; fail=1; return; }
    echo "module objects: $(ls "$OBJ"/*.o | wc -l | tr -d ' ')"
  fi
  local LL=( $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/merged_game.o "$OBJ"/module_shim.o "$OBJ"/gen_*.o )
  # -undefined error (the default): the shim is the module's ENTIRE host-facing surface, so an undefined
  # symbol here means the ABI is missing one -- the tripwire tools/gen_host_abi.py provides on Windows.
  python3 mac-build/link_merge.py --cxx "$CXX" --objcopy "$OBJCOPY" --out "$OUTM" --objdir "$OBJ" --shared -- "${LL[@]}" -- \
      -Wl,-install_name,"@rpath/$(basename "$OUTM")" -lc++ || { echo "MODULE LINK_FAILED -> $OUTM"; grep -i "undefined symbol" "$OBJ/link.err" | sort -u | head -20; fail=1; return; }
}
if [ "${HOST_ONLY:-0}" != "1" ]; then
  for m in $MODULES; do case "$m" in
    normal) build_module reco_normal   out_reco     0 "$OUTDIR/futari_game_normal.dylib";;
    abn)    [ -f out_reco_abn/ppc_recomp.0.cpp ] || { echo "MISSING: out_reco_abn generated tree"; fail=1; continue; }
            build_module reco_abnormal out_reco_abn 1 "$OUTDIR/futari_game_abn.dylib";;
  esac; done
fi
banner "SUMMARY"
ls -la "$OUTDIR"/futari_combined "$OUTDIR"/futari_game_normal.dylib "$OUTDIR"/futari_game_abn.dylib 2>/dev/null
[ $fail -eq 0 ] && echo "BUILD_OK -- combined host + 2 module dylibs" || { echo "BUILD_INCOMPLETE"; exit 1; }
