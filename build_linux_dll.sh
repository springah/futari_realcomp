#!/bin/bash
# build_linux_dll.sh — the COMBINED engine on Linux x86_64 (the Steam Deck family-and-friends build):
#
#   build/linux/futari_combined              the module-agnostic host (shell + kernel + renderer + bridge)
#   build/linux/futari_game_normal.so        reco_normal   (ARCADE 1.5,    modeIdx 0)  <- out_reco/
#   build/linux/futari_game_abn.so           reco_abnormal (XBOX 360 mode, modeIdx 1)  <- out_reco_abn/
#
# The ELF twin of build_mac_dll.sh / build_win_dll.sh: same three compile shapes, same object split (the L2 module
# line), same link order (decomp_* first), same abn exclusion case list. ELF needs none of the Mach-O machinery:
# `-Wl,--allow-multiple-definition` is the first-definition-wins merge (build_linux.sh), __attribute__((alias)) is
# native, and host/module_registry.cpp's POSIX arm dlopens futari_game_<mod>.so from RT_MODDLL_DIR / the executable's
# directory. Module objects are -fPIC (a shared object on x86-64 cannot take non-PIC text relocations).
#   -march=x86-64-v3: the Deck's Zen 2 has AVX2; the recompiled guest is CPU-bound and simde maps SSE natively anyway.
#   Meant to run INSIDE the build container (mac-build/deck/Dockerfile) via mac-build/deck/build_deck.sh, where
#   DERISK_BUILD / SDL_BUILD point at the Linux builds of the two dependencies (build-linux/ dirs, see that script).
#
#   bash build_linux_dll.sh                HOST_ONLY=1 / MODULES_ONLY=1 / LINK_ONLY=1 / MODULES="normal abn" / DECOMP_SKIP="..."
set -u
cd "$(dirname "$0")"
OUTDIR="${OUTDIR:-build/linux}"; mkdir -p "$OUTDIR"
CXX="${CXX:-clang++}"
DERISK="${DERISK:-external/xr-derisk}"; DERISK_BUILD="${DERISK_BUILD:-$DERISK/build-linux}"
SDL_SRC="${SDL_SRC:-external/SDL}"; SDL_BUILD="${SDL_BUILD:-$SDL_SRC/build-linux}"
MODULES="${MODULES:-normal abn}"   # Black Label arms (kiniro, kiniro_abn) exist below but are NOT in the Linux default yet: untested in the Deck container (2026-10-31)
HAS_KINIRO=0; HAS_KINIRO_ABN=0; for m in $MODULES; do [ "$m" = kiniro ] && HAS_KINIRO=1; [ "$m" = kiniro_abn ] && HAS_KINIRO_ABN=1; done
for need in "$DERISK/XenonUtils/image.h" "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$SDL_BUILD/libSDL3.a" "$SDL_SRC/include/SDL3/SDL.h" \
            out_reco/ppc_recomp.0.cpp moduleshim/module_shim_reco_normal.cpp; do
  [ -e "$need" ] || { echo "MISSING DEPENDENCY: $need"; exit 2; }
done
BUILD_ID="$(git rev-parse --short HEAD 2>/dev/null || echo nogit)$(git diff --quiet 2>/dev/null || echo -dirty)"
ARCH_FLAGS="${ARCH_FLAGS:--march=x86-64-v3}"
BASE="-std=c++20 -O2 $ARCH_FLAGS -Wno-macro-redefined -DFUTARI_BUILD_ID=\"$BUILD_ID\" ${EXTRA_CXX:-}"
XS="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"
export DECOMP_DIR="${DECOMP_DIR:-../futari_decomp/decomp}"
DECOMP_SKIP="${DECOMP_SKIP:-}"
decomp_skipped(){ local n="$1" k; for k in $DECOMP_SKIP; do [ "$n" = "$k" ] && return 0; done; return 1; }
JOBS="${JOBS:-$(nproc 2>/dev/null || echo 4)}"
LIBS_HOST=( "$DERISK_BUILD/XenonUtils/libXenonUtils.a" "$DERISK_BUILD/XenonAnalyse/libLibXenonAnalyse.a"
       "$DERISK_BUILD/thirdparty/disasm/libdisasm.a" "$DERISK_BUILD/thirdparty/xxHash/cmake_unofficial/libxxhash.a"
       "$DERISK_BUILD/thirdparty/fmt/libfmt.a" "$SDL_BUILD/libSDL3.a" -lvulkan -lpthread -ldl -lm )
fail=0
banner(){ echo; echo "=============== $* ==============="; }
i=0; sem(){ i=$((i+1)); if [ $((i%JOBS)) -eq 0 ]; then wait; fi; }
cc(){ local name="$1" src="$2"; shift 2; ( "$CXX" $STD "$@" -c "$src" -o "$OBJ/$name.o" 2>"$OBJ/$name.err" || echo "FAILED: $name" ) & sem; }
check_errs(){ local bad=0 e; for e in "$OBJ"/*.err; do grep -q 'error:' "$e" 2>/dev/null && { echo "--- $e ---"; grep -A2 'error:' "$e" | head -12; bad=1; }; done; return $bad; }

if [ "${MODULES_ONLY:-0}" != "1" ]; then
banner "1. HOST ($OUTDIR/futari_combined)"
OBJ=build/obj_linux_host; OUT="$OUTDIR/futari_combined"; mkdir -p "$OBJ"
STD="$BASE -DFUTARI_COMBINED=1 -DFUTARI_MODULE=0"
GI="-I out_reco -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde"
SI="-I shell/gen -I out_reco -I $DERISK/thirdparty/simde"
RT="-include out_reco/rt_indirect.h"
if [ "${LINK_ONLY:-0}" != "1" ]; then
  rm -f "$OBJ"/*.o "$OBJ"/*.err; i=0
  for f in "$DECOMP_DIR"/shell/*.cpp; do n=$(basename "$f" .cpp); decomp_skipped "$n" && { echo "   [DECOMP_SKIP] shell/$n"; continue; }; cc "decomp_$n" "$f" $SI -I . $XS $RT; done
  cc "game_rt"      "out_reco/rt.cpp"      $GI $RT
  cc "game_stubs"   "out_reco/stubs.cpp"   $GI $RT
  cc "game_harness" "out_reco/harness.cpp" $GI $RT
  cc "game_rt_phys" "out_reco/rt_phys.cpp" $GI $RT
  KIN_HOST=""; [ "$HAS_KINIRO" = 1 ] && KIN_HOST="-DFUTARI_HOST_KINIRO=1"; [ "$HAS_KINIRO_ABN" = 1 ] && KIN_HOST="$KIN_HOST -DFUTARI_HOST_KINIRO_ABN=1"
  cc "host_module_registry" "host/module_registry.cpp" $GI $RT $KIN_HOST
  cc "merged_bridge" "out_reco/merged/merged_bridge.cpp" $GI $RT
  cc "merged_shell"  "out_reco/merged/merged_shell.cpp"  $GI $RT
  for f in shell/gen/ppc_recomp.*.cpp; do n=$(basename "$f" .cpp); cc "shell_$n" "$f" $SI $XS $RT; done
  cc "shell_ppc_func_mapping" "shell/gen/ppc_func_mapping.cpp" $SI $XS $RT -DPPCFuncMappings=PPCFuncMappings_shell
  cc "shellkernel_rt"       "shell/gen/rt.cpp"       $SI $XS $RT
  cc "shellkernel_stubs"    "shell/gen/stubs.cpp"    $SI $XS $RT -I "$SDL_SRC/include"
  cc "shellkernel_rt_audio" "shell/gen/rt_audio.cpp" -I "$SDL_SRC/include"
  cc "shellkernel_rt_xwma"  "shell/gen/rt_xwma.cpp"
  cc "vk_render" "render/vk_render.cpp" -I "$SDL_SRC/include"
  wait
  check_errs || { echo "HOST COMPILE_INCOMPLETE"; exit 1; }
  echo "host objects: $(ls "$OBJ"/*.o | wc -l)"
fi
# ORDER IS LOAD-BEARING (build_win_dll.sh "1. HOST EXE"): decomp_* first, game_* kernel before shell_*/shellkernel_*.
"$CXX" -fuse-ld=lld -O2 -std=c++20 $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/game_*.o "$OBJ"/host_module_registry.o \
  "$OBJ"/merged_bridge.o "$OBJ"/merged_shell.o "$OBJ"/vk_render.o "$OBJ"/shell_*.o "$OBJ"/shellkernel_*.o \
  -o "$OUT" "${LIBS_HOST[@]}" -Wl,--allow-multiple-definition -Wl,-rpath,'$ORIGIN' -Wl,-Map,"$OUT.map" 2>"$OBJ/link.err" \
  && echo "LINK_OK -> $OUT" || { echo "HOST LINK_FAILED"; grep -i "undefined" "$OBJ/link.err" | sort -u | head -20; tail -20 "$OBJ/link.err"; exit 1; }
fi

build_module(){   # $1 name  $2 tree  $3 modidx  $4 out
  local NAME="$1" TREE="$2" MIDX="$3" OUTM="$4"
  banner "2. MODULE $OUTM  ($NAME, modeIdx $MIDX, tree $TREE)"
  OBJ="build/obj_linux_mod_$NAME"; mkdir -p "$OBJ"
  [ -f "$OUTM" ] && mv -f "$OUTM" "$OUTM.lastgood"
  STD="$BASE -fPIC -DFUTARI_MODULE=$MIDX -DFUTARI_IN_MODULE_DLL=1"
  local GI="-I $TREE -I $DERISK/XenonUtils -I $DERISK/thirdparty/simde" RT="-include $TREE/rt_indirect.h" MAP=""
  [ "$MIDX" = "1" ] && MAP="-include $TREE/abn_symbol_map.h"
  [ "$MIDX" = "4" ] && MAP="-include $TREE/kiniro_symbol_map.h"        # Black Label ARCADE (mirrors build_mac_dll.sh)
  [ "$MIDX" = "5" ] && MAP="-include $TREE/kiniro_abn_symbol_map.h"    # Black Label XBOX 360 MODE
  if [ "${LINK_ONLY:-0}" != "1" ]; then
    rm -f "$OBJ"/*.o "$OBJ"/*.err; i=0
    for f in $TREE/ppc_recomp.*.cpp; do n=$(basename "$f" .cpp); cc "gen_$n" "$f" $GI $RT; done
    cc "gen_ppc_func_mapping" "$TREE/ppc_func_mapping.cpp" $GI $RT
    cc "merged_game" "out_reco/merged/merged_game.cpp" $GI $RT $MAP
    for f in "$DECOMP_DIR"/game/*.cpp; do
      n=$(basename "$f" .cpp)
      decomp_skipped "$n" && { echo "   [DECOMP_SKIP] game/$n"; continue; }
      # ABN-EXCLUDED TUs (reco_normal .data literals, +0x60 in the abn image): build_mac_dll.sh / build_win_dll.sh's list,
      # VERBATIM -- keep the three in sync. 2026-10-31: this list had fallen 16 TUs behind (the w162/w165 readable-C TUs);
      # results_w162's literal 0x88103048 (a reco_normal callback; abn twin sub_88103050) then rode into futari_game_abn.so
      # and the XBOX 360 character select spun on `[indirect] UNMAPPED 0x88103048` on the Deck (docs/DECK.md, Black Label).
      if [ "$MIDX" = "1" ]; then
        case "$n" in game_entry_msgs|asset_decode|asset_pump|archive|mem_util|asset_upload|page_bake|objaction|objaction_queue|objaction_queue2|bossvein_object|fam4_object|fam1_arms|fam3_arms|fam9_arms|fam10_arms|fam11_tick|paperdoll2_draw|class233_236_draw|actor3pose_draw|objnode_park|objnode_parkcensus|famk1|famk9|pagescene|famk2|famk11|famk12|famk30|famk5|famk28|bossscript_w165|classes_w165|cutscene_w165|encounter_w165|famk21_w165|famk4_7_w165|famk8_10_w165|frontend_w162|objects_w162|pagetrans_w162|pump_w162|results_w162|scene_w165|select_w165|ship_w162|tracking_w165) continue;; esac
      fi
      # NON-RECO MODULES (4/5): every decomp/game TU is reco_normal content; only the renderer bridge rides along (build_mac_dll.sh law)
      if { [ "$MIDX" = "4" ] || [ "$MIDX" = "5" ]; } && [ "$n" != nvk_game_hooks ]; then continue; fi
      cc "decomp_$n" "$f" $GI -I . $RT $MAP
    done
    if [ "$MIDX" = "1" ]; then
      for f in "$DECOMP_DIR"/game_abn/*.cpp; do n=$(basename "$f" .cpp); decomp_skipped "$n" && continue; cc "decomp_$n" "$f" $GI -I . $RT; done
    fi
    if [ "$MIDX" = "4" ] || [ "$MIDX" = "5" ]; then cc "modstub_kiniro_hook_stubs" "$TREE/kiniro_hook_stubs.cpp" $GI $RT; fi
    cc "module_shim" "moduleshim/module_shim_$NAME.cpp" $GI $RT
    wait
    check_errs || { echo "MODULE COMPILE_INCOMPLETE ($OUTM)"; fail=1; return; }
    echo "module objects: $(ls "$OBJ"/*.o | wc -l)"
  fi
  # --no-undefined: the shim is the module's ENTIRE host-facing surface; an undefined symbol = an ABI gap (the tripwire).
  "$CXX" -fuse-ld=lld -O2 -std=c++20 -shared $(ls "$OBJ"/decomp_*.o 2>/dev/null) "$OBJ"/merged_game.o $(ls "$OBJ"/modstub_*.o 2>/dev/null) "$OBJ"/module_shim.o "$OBJ"/gen_*.o \
    -o "$OUTM" -Wl,--allow-multiple-definition -Wl,--no-undefined -Wl,-soname,"$(basename "$OUTM")" 2>"$OBJ/link.err" \
    && echo "LINK_OK -> $OUTM" || { echo "MODULE LINK_FAILED -> $OUTM"; grep -i "undefined" "$OBJ/link.err" | sort -u | head -20; tail -10 "$OBJ/link.err"; fail=1; }
}
if [ "${HOST_ONLY:-0}" != "1" ]; then
  for m in $MODULES; do case "$m" in
    normal) build_module reco_normal   out_reco     0 "$OUTDIR/futari_game_normal.so";;
    abn)    [ -f out_reco_abn/ppc_recomp.0.cpp ] || { echo "MISSING: out_reco_abn generated tree (scripts/regen_abn_mac.sh)"; fail=1; continue; }
            build_module reco_abnormal out_reco_abn 1 "$OUTDIR/futari_game_abn.so";;
    kiniro) [ -f out_kiniro/ppc_recomp.0.cpp ] && [ -f out_kiniro/kiniro_symbol_map.h ] || { echo "MISSING: out_kiniro tree / symbol map"; fail=1; continue; }
            build_module kiniro_normal out_kiniro 4 "$OUTDIR/futari_game_kiniro.so";;
    kiniro_abn) [ -f out_kiniro_abn/ppc_recomp.0.cpp ] && [ -f out_kiniro_abn/kiniro_abn_symbol_map.h ] || { echo "MISSING: out_kiniro_abn tree / symbol map"; fail=1; continue; }
            build_module kiniro_abnormal out_kiniro_abn 5 "$OUTDIR/futari_game_kiniro_abn.so";;
  esac; done
fi
banner "SUMMARY"; ls -la "$OUTDIR"/futari_combined "$OUTDIR"/*.so 2>/dev/null
[ $fail -eq 0 ] && echo "BUILD_OK -- combined host + module .so files" || { echo "BUILD_INCOMPLETE"; exit 1; }
