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
cd "$(dirname "$0")"
mkdir -p build
CXX="/c/Program Files/LLVM/bin/clang++.exe"
DERISK="external/xr-derisk"
VKSDK=$(ls -d /c/VulkanSDK/*/ 2>/dev/null | sort -V | tail -1)
# FUTARI_BUILD_ID: same stamp as build_win.sh — the beta1 smoke printed `build=unknown`,
# i.e. the SHIP build could not name itself (the exact wrong-attribution class the 08-01
# settings audit documented). Stamp here too so the combined [env] banner names the sha.
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
BASE="--target=x86_64-pc-windows-msvc -std=c++20 -O2 -D_CRT_SECURE_NO_WARNINGS -Wno-macro-redefined -DFUTARI_BUILD_ID=\"$BUILD_ID\""
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"

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
OBJ=build/obj_dll_host
mkdir -p "$OBJ"; rm -f "$OBJ"/*.o "$OBJ"/*.err build/futari_combined.exe
STD="$BASE -DFUTARI_COMBINED=1"
GI="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SI="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
RT="-include out_reco/rt_indirect.h"
i=0; sem(){ i=$((i+1)); if [ $((i%12)) -eq 0 ]; then wait; fi; }
cc(){ local n="$1" s="$2"; shift 2
  ( "$CXX" $STD "$@" -c "$s" -o "$OBJ/$n.o" 2>"$OBJ/$n.err" || echo "FAILED: $n" ) & sem; }

echo "-- decomp (shell only; decomp/game* rides into the DLLs)"
for f in decomp/shell/*.cpp; do n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $GI $RT; done

echo "-- game-tree KERNEL (rt/stubs/harness only — the generated tree has left the exe)"
# ORDER IS LOAD-BEARING (plan §4.3): 66 __imp__X are defined in BOTH out_reco/{rt,stubs}.cpp and
# shell/gen/{rt,stubs}.cpp.  shell/gen/rt.cpp:809-814 documents that the SHELL copy must lose.
# These objects are named game_* and listed before shellkernel_* on the link line, exactly as in
# build_win.sh, so /FORCE:MULTIPLE keeps the game copy.  Changing this silently changes which
# kernel implementation the whole binary runs on.
cc "game_rt"      "out_reco/rt.cpp"      $GI $RT
cc "game_stubs"   "out_reco/stubs.cpp"   $GI $RT
cc "game_harness" "out_reco/harness.cpp" $GI $RT

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
  -o build/futari_combined.exe \
  "$DERISK/build-win/XenonUtils/XenonUtils.lib" \
  "$DERISK/build-win/XenonAnalyse/LibXenonAnalyse.lib" \
  "$DERISK/build-win/thirdparty/disasm/disasm.lib" \
  "$DERISK/build-win/thirdparty/xxHash/cmake_unofficial/xxhash.lib" \
  "$DERISK/build-win/thirdparty/fmt/fmt.lib" \
  "${VKSDK}Lib/vulkan-1.lib" \
  thirdparty/sdl3/lib/SDL3-static.lib -luser32 -lole32 -lwinmm -limm32 -loleaut32 -lversion -ladvapi32 -lsetupapi -lshell32 -lgdi32 -luuid \
  -Xlinker /FORCE:MULTIPLE -Xlinker /errorlimit:0 \
  2>"$OBJ"/link.err && echo "LINK_OK -> build/futari_combined.exe" || {
    echo "LINK_FAILED"; grep 'undefined symbol' "$OBJ"/link.err | sort -u | head -30; tail -20 "$OBJ"/link.err; exit 1; }

# --------------------------------------------------------------------------------------------
# 2. MODULE DLLs
# --------------------------------------------------------------------------------------------
# ★ PLAN §4.4's PREDICTION WAS FALSIFIED BY THIS GATE — recorded, not quietly patched.
#
#   §4.4 predicted each DLL would link WITHOUT /FORCE:MULTIPLE ("Probably NO. Predicted clean
#   without it"), on the theory that the decomp/merged shadowing is weak-over-strong.  It ran as
#   a hard gate on 2026-07-31 and FAILED, which is precisely the outcome §4.4 said was worth
#   having: "the error names the exact residual duplicate, which is information we want."
#
#   Two duplicate classes, both STRONG-over-STRONG and therefore genuinely order-dependent:
#
#   (1) THE DOCUMENTED decomp SEAM.  decomp/game/game_entry_msgs.cpp defines
#       __imp__sub_8824E698, and so does the generated body in ppc_recomp.32.  That is not a
#       bug — decomp/game/PILOT_NOTES.md §2 specifies it exactly: the C body takes the __imp__
#       symbol and displaces the generated definition, "which remains as dead bytes — the
#       plan-§3 rollback shape".  The whole decomp override mechanism IS first-def-wins, so it
#       requires /FORCE:MULTIPLE wherever it lives.  (abn twin: __imp__sub_8824E6A0.)
#
#   (2) ★ A PRE-EXISTING SHADOW NOBODY HAD MEASURED.  sub_8807A578 / sub_8807D4F8 / sub_8807DD88
#       carry a strong PPC_FUNC in BOTH decomp/game/nvk_game_hooks.cpp AND merged_game.cpp.
#       Verified in the SHIPPING objects (llvm-nm build/obj_win/): both define all three.  decomp_*.o
#       is first on build_win.sh's link line, so decomp wins and merged_game's wrappers —
#       including R26_BRACKET_WRAP(sub_8807D4F8) — are SILENTLY DEAD in both shipping exes
#       today.  This is the exact "shadowed-hook landmine" PILOT_NOTES §2 warns about, live on
#       three more functions than were documented.  Banked as an instruments-lie finding; NOT
#       fixed here, because changing which body wins would change shipped behaviour and belongs
#       in its own leg with its own A/B.
#
#   CONSEQUENCE FOR THIS SCRIPT: the DLL link uses /FORCE:MULTIPLE with decomp_*.o FIRST —
#   byte-for-byte the exe's resolution order — so a symbol resolves to the SAME body inside the
#   DLL as it does in the per-mode exes.  Reproducing the exe's winner is the correctness
#   requirement; linking without the flag was only ever a nice-to-have proof.
build_dll(){                 # $1 name  $2 tree  $3 modidx  $4 dllout  $5.. extra decomp dirs
  local NAME="$1" TREE="$2" MIDX="$3" OUT="$4"; shift 4
  banner "2. MODULE DLL $OUT  ($NAME, modeIdx $MIDX, tree $TREE)"
  OBJ="build/obj_dll_$NAME"
  mkdir -p "$OBJ"; rm -f "$OBJ"/*.o "$OBJ"/*.err "$OUT"
  STD="$BASE -DFUTARI_MODULE=$MIDX -DFUTARI_IN_MODULE_DLL=1"
  GI="-I $TREE -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
  RT="-include $TREE/rt_indirect.h"
  MAP=""; [ "$MIDX" = "1" ] && MAP="-include $TREE/abn_symbol_map.h"
  i=0
  echo "-- generated tree"
  for f in $TREE/ppc_recomp.*.cpp; do n=$(basename "$f" .cpp); cc "gen_$n" "$f" $GI $RT; done
  cc "gen_ppc_func_mapping" "$TREE/ppc_func_mapping.cpp" $GI $RT
  echo "-- game hooks (merged_game.cpp, +8 renamed on the abn arm)"
  cc "merged_game" "out_reco/merged/merged_game.cpp" $GI $RT $MAP
  echo "-- decomp game TUs"
  for f in decomp/game/*.cpp; do
    n=$(basename "$f" .cpp)
    # game_entry_msgs.cpp is EXCLUDED from the abn arm: its C1 MATCHED body stores to reco_normal
    # .data literals that move +0x60.  decomp/game_abn/ carries the re-earned twin instead.
    [ "$MIDX" = "1" ] && [ "$n" = "game_entry_msgs" ] && continue
    cc "decomp_$n" "$f" $GI $RT $MAP
  done
  if [ "$MIDX" = "1" ]; then
    for f in decomp/game_abn/*.cpp; do n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $GI $RT; done
  fi
  echo "-- host-facing shim (moduleshim/, NEVER a glob-swept dir)"
  cc "module_shim" "moduleshim/module_shim_$NAME.cpp" $GI $RT
  wait
  local f2=0
  for e in "$OBJ"/*.err; do grep -qE ' error|error:' "$e" 2>/dev/null && { echo "--- $e ---"; grep -A2 error "$e" | head -12; f2=1; }; done
  [ $f2 -eq 0 ] || { echo "DLL COMPILE_INCOMPLETE ($OUT)"; fail=1; return; }
  echo "dll objects: $(ls "$OBJ"/*.o | wc -l)"
  # decomp_*.o FIRST — the strong-hook seam (decomp/README.md, PILOT_NOTES.md:25-47) is
  # link-unit-internal, and all three participants now live in THIS link unit.
  "$CXX" --target=x86_64-pc-windows-msvc -fuse-ld=lld -O2 -std=c++20 -shared \
    $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/merged_game.o "$OBJ"/module_shim.o "$OBJ"/gen_*.o \
    -o "$OUT" -Xlinker /FORCE:MULTIPLE -Xlinker /errorlimit:0 \
    2>"$OBJ"/link.err && echo "LINK_OK -> $OUT" || {
      echo "LINK_FAILED -> $OUT"
      echo "--- unresolved (lld prints __imp__sub_X as 'dllimport) _sub_X') ---"
      grep -o 'dllimport) _sub_88[0-9A-Fa-f]*' "$OBJ"/link.err | sed 's/.*_sub_/__imp__sub_/' | sort -u | head -20
      grep 'undefined symbol' "$OBJ"/link.err | grep -v 'dllimport) _sub_88' | sort -u | head -20
      grep -i 'duplicate symbol' "$OBJ"/link.err | sort -u | head -20
      tail -20 "$OBJ"/link.err; fail=1; }
}

build_dll reco_normal   out_reco     0 build/futari_game_normal.dll
build_dll reco_abnormal out_reco_abn 1 build/futari_game_abn.dll

banner "SUMMARY"
ls -la build/futari_combined.exe build/futari_game_normal.dll build/futari_game_abn.dll 2>/dev/null
[ $fail -eq 0 ] && echo "BUILD_OK — combined exe + 2 module DLLs" || { echo "BUILD_INCOMPLETE"; exit 1; }
