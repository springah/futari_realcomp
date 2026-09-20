#!/bin/bash
# build_win_dll.sh — the COMBINED exe: ONE build/futari_combined.exe hosting BOTH 1.5 modes as
# runtime-loadable module DLLs.
#
#   build/futari_combined.exe      the module-agnostic host (shell + kernel + renderer + bridge)
#   build/futari_game_normal.dll   reco_normal   (ARCADE,    modeIdx 0)  <- out_reco/
#   build/futari_game_abn.dll      reco_abnormal (XBOX 360,  modeIdx 1)  <- out_reco_abn/
#
# L4+L5 of _tmpscripts/dll_packaging_plan.md.  Notes: _tmpscripts/l4l5_combined_notes.md.
#
# ############################################################################################
# # THIS SCRIPT IS PURELY ADDITIVE.  It touches NEITHER build_win.sh NOR build_win_abn.sh,   #
# # and it writes to obj_dll_*/ — never build/obj_win/ or build/obj_win_abn/.  The two per-module exes   #
# # are the beta1 FALLBACK and must keep linking and booting; nothing here can affect them.  #
# ############################################################################################
#
# THE THREE COMPILE MODES, and why each macro exists:
#
#   HOST EXE      -DFUTARI_COMBINED=1
#                 futari_desc() becomes a volatile load of the live module's descriptor, and
#                 futari_hosted_mask() becomes the OR over the DLLs that bound.  This is the ONLY
#                 build shape where either can change at runtime.
#
#   MODULE DLL    -DFUTARI_MODULE=<0|1> -DFUTARI_IN_MODULE_DLL=1     (NOT -DFUTARI_COMBINED)
#                 futari_desc() stays the constexpr fold of THIS module's descriptor — a DLL
#                 contains exactly one module's tree, so its guest addresses cannot be another
#                 module's.  FUTARI_IN_MODULE_DLL also switches the four cross-module-line
#                 globals to derefs of host pointers bound at FutariModuleBind() time
#                 (merged_common.h), and arms the #error tripwire in moduleshim/.
#
# WHAT LIVES WHERE — the split is exactly the L2 module line:
#   host:  out_reco/{rt,stubs,harness}.cpp   (byte-identical across trees; ONE canonical copy)
#          out_reco/merged/{merged_bridge,merged_shell}.cpp   host/module_registry.cpp
#          shell/gen/*   render/vk_render.cpp   decomp/shell/*
#   DLL:   <tree>/ppc_recomp.*.cpp  <tree>/ppc_func_mapping.cpp
#          out_reco/merged/merged_game.cpp     decomp/game*/*   moduleshim/module_shim_<mod>.cpp
#
# Run from git-bash.  cwd-independent.
set -u
cd /c/Users/shant/Desktop/projects/futari_realcomp
mkdir -p build
CXX="/c/Program Files/LLVM/bin/clang++.exe"
DERISK="external/xr-derisk"
VKSDK=$(ls -d /c/VulkanSDK/*/ 2>/dev/null | sort -V | tail -1)
# FUTARI_BUILD_ID: same stamp as build_win.sh — the beta1 smoke printed `build=unknown`,
# i.e. the SHIP build could not name itself (the exact wrong-attribution class the 08-01
# settings audit documented). Stamp here too so the combined [env] banner names the sha.
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
# EXTRA_CXX (r23-w85): optional env passthrough for ONE-OFF instrument compile flags, e.g.
#   EXTRA_CXX="-DRT_TABREAD_FULL=1" bash build_win_dll.sh   (re-arm a compiled-out RT_* cluster)
# Empty by default => byte-identical to the unmodified build. HARNESS-ONLY, NEVER SHIP with it set.
EXTRA_CXX="${EXTRA_CXX:-}"
# DECOMP_SKIP (r23-w86 DRIVER): the A/B CONTROL-ARM SWITCH.  Space-separated list of decomp TU
# BASENAMES to leave OUT of the compile loops, e.g.
#   DECOMP_SKIP="objnode_park" bash build_win_dll.sh   (control arm: those guest bodies fall back
#                                                       to the GENERATED ppc_recomp bodies)
# This invents no new seam: it is the SAME mechanism the MIDX=1 abn exclusion case list already
# uses (skip the .o => /FORCE:MULTIPLE first-def-wins hands the address to gen_ppc_recomp.NN.o).
# Empty by default => byte-identical to the unmodified build.  HARNESS-ONLY, NEVER SHIP with it set.
DECOMP_SKIP="${DECOMP_SKIP:-}"
decomp_skipped(){ local n="$1" k; for k in $DECOMP_SKIP; do [ "$n" = "$k" ] && return 0; done; return 1; }
BASE="--target=x86_64-pc-windows-msvc -std=c++20 -O2 -D_CRT_SECURE_NO_WARNINGS -Wno-macro-redefined -DFUTARI_BUILD_ID=\"$BUILD_ID\" $EXTRA_CXX"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
# DECOMP_DIR: readable-decomp tree, now the sibling repo projects/futari_decomp (2026-08-14
# split). Exported so gen_symbol_map.py/gen_stubs.py see the same override. Defined BEFORE
# step 0 — gen_symbol_map.py scans the shared decomp TUs.
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"

fail=0
banner(){ echo; echo "=============== $* ==============="; }

# --------------------------------------------------------------------------------------------
# 0. Regenerate the ABI + the two shims from a MEASUREMENT of the current objects.
#    The generator ABORTS on any unclassified symbol — that abort is the tripwire that catches a
#    recompiler upgrade or a new host call from a game hook before it becomes a link error.
#    It needs the per-module obj dirs to measure, so those builds must have been run at least
#    once; that is a feature (it keeps the ABI honest against real objects, not against a list).
# --------------------------------------------------------------------------------------------
banner "0. generate host ABI + module shims"
if [ ! -d build/obj_win ] || [ ! -d build/obj_win_abn ]; then
  echo "!! build/obj_win/ and build/obj_win_abn/ must exist (run build_win.sh and build_win_abn.sh once)"; exit 1
fi
python tools/gen_host_abi.py --objdir build/obj_win     --moddir out_reco     --module 0 || exit 1
python tools/gen_host_abi.py --objdir build/obj_win_abn --moddir out_reco_abn --module 1 || exit 1
# Regenerate the abn +8 symbol map from a FRESH scan of the shared decomp TUs — the abn DLL
# force-includes it (below), so a NEW shared TU that references a shifted 0x88 symbol (e.g.
# decomp/game/archive.cpp -> sub_8813A6A0) needs its rename emitted here. Previously only
# build_win_abn.sh regenerated it, so this build consumed a STALE map (2026-08-13 leg fix).
python out_reco_abn/tools_abn/gen_symbol_map.py || exit 1

# --------------------------------------------------------------------------------------------
# 1. HOST EXE
# --------------------------------------------------------------------------------------------
banner "1. HOST EXE (build/futari_combined.exe)"
OBJ=build/obj_dll_host_ctl
mkdir -p "$OBJ"; rm -f "$OBJ"/*.o "$OBJ"/*.err build/futari_combined_ctlshell.exe
STD="$BASE -DFUTARI_COMBINED=1"
GI="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SI="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
RT="-include out_reco/rt_indirect.h"
i=0; sem(){ i=$((i+1)); if [ $((i%12)) -eq 0 ]; then wait; fi; }
cc(){ local n="$1" s="$2"; shift 2
  ( "$CXX" $STD "$@" -c "$s" -o "$OBJ/$n.o" 2>"$OBJ/$n.err" || echo "FAILED: $n" ) & sem; }

echo "-- decomp (shell only; decomp/game* rides into the DLLs)"
# -I . : decomp TUs reference host/render headers realcomp-root-relative (repo split).
for f in "$DECOMP_DIR"/shell/*.cpp; do n=$(basename "$f" .cpp); decomp_skipped "$n" && { echo "   [DECOMP_SKIP] shell/$n"; continue; }; cc "decomp_$n" "$f" $GI -I . $RT; done

echo "-- game-tree KERNEL (rt/stubs/harness only — the generated tree has left the exe)"
# ORDER IS LOAD-BEARING (plan §4.3): 66 __imp__X are defined in BOTH out_reco/{rt,stubs}.cpp and
# shell/gen/{rt,stubs}.cpp.  shell/gen/rt.cpp:809-814 documents that the SHELL copy must lose.
# These objects are named game_* and listed before shellkernel_* on the link line, exactly as in
# build_win.sh, so /FORCE:MULTIPLE keeps the game copy.  Changing this silently changes which
# kernel implementation the whole binary runs on.
cc "game_rt"      "out_reco/rt.cpp"      $GI $RT
cc "game_stubs"   "out_reco/stubs.cpp"   $GI $RT
cc "game_harness" "out_reco/harness.cpp" $GI $RT
cc "game_rt_phys" "out_reco/rt_phys.cpp" $GI $RT

echo "-- module registry (load / bind / activate / swap)"
cc "host_module_registry" "host/module_registry.cpp" $GI $RT

echo "-- merged host halves (bridge + shell; merged_game.cpp is DLL-side)"
cc "merged_bridge" "out_reco/merged/merged_bridge.cpp" $GI $RT
cc "merged_shell"  "out_reco/merged/merged_shell.cpp"  $GI $RT

echo "-- shell guest tree"
for f in shell/gen/ppc_recomp.*.cpp; do n=$(basename "$f" .cpp); cc "shell_$n" "$f" $SI $XS $RT; done
cc "shell_ppc_func_mapping" "shell/gen/ppc_func_mapping.cpp" $SI $XS $RT -DPPCFuncMappings=PPCFuncMappings_shell

echo "-- shell kernel + audio"
cc "shellkernel_rt"       "shell/gen/rt.cpp"       $SI $XS $RT
cc "shellkernel_stubs"    "shell/gen/stubs.cpp"    $SI $XS $RT
cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -Ithirdparty/sdl3/include
cc "shellkernel_rt_xwma"  "shell/gen/rt_xwma.cpp"

echo "-- renderer"
cc "vk_render" "render/vk_render.cpp" -I "${VKSDK}Include"
wait

for e in "$OBJ"/*.err; do grep -qE ' error|error:' "$e" 2>/dev/null && { echo "--- $e ---"; grep -A2 error "$e" | head -12; fail=1; }; done
[ $fail -eq 0 ] || { echo "HOST COMPILE_INCOMPLETE"; exit 1; }
echo "host objects: $(ls "$OBJ"/*.o | wc -l)"

echo "-- link"
"$CXX" --target=x86_64-pc-windows-msvc -fuse-ld=lld -O2 -std=c++20 \
  $(ls "$OBJ"/decomp_*.o) "$OBJ"/game_*.o "$OBJ"/host_module_registry.o \
  "$OBJ"/merged_bridge.o "$OBJ"/merged_shell.o "$OBJ"/vk_render.o \
  "$OBJ"/shell_*.o "$OBJ"/shellkernel_*.o \
  -o build/futari_combined_ctlshell.exe \
  "$DERISK/build-win/XenonUtils/XenonUtils.lib" \
  "$DERISK/build-win/XenonAnalyse/LibXenonAnalyse.lib" \
  "$DERISK/build-win/thirdparty/disasm/disasm.lib" \
  "$DERISK/build-win/thirdparty/xxHash/cmake_unofficial/xxhash.lib" \
  "$DERISK/build-win/thirdparty/fmt/fmt.lib" \
  "${VKSDK}Lib/vulkan-1.lib" \
  thirdparty/sdl3/lib/SDL3-static.lib -luser32 -lole32 -lwinmm -limm32 -loleaut32 -lversion -ladvapi32 -lsetupapi -lshell32 -lgdi32 -luuid \
  -Xlinker /FORCE:MULTIPLE -Xlinker /errorlimit:0 \
  2>"$OBJ"/link.err && echo "LINK_OK -> build/futari_combined_ctlshell.exe" || {
    echo "LINK_FAILED"; grep 'undefined symbol' "$OBJ"/link.err | sort -u | head -30; tail -20 "$OBJ"/link.err; exit 1; }

# --------------------------------------------------------------------------------------------
echo HOST-ONLY BUILD DONE; exit 0
