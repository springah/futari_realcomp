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
# EXTRA_CXX (r23-w85): optional env passthrough for ONE-OFF instrument compile flags, e.g.
#   EXTRA_CXX="-DRT_TABREAD_FULL=1" bash build_win_dll.sh   (re-arm a compiled-out RT_* cluster)
# Empty by default => byte-identical to the unmodified build. HARNESS-ONLY, NEVER SHIP with it set.
EXTRA_CXX="${EXTRA_CXX:-}"
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
# -I . : decomp TUs reference host/render headers realcomp-root-relative (repo split).
for f in "$DECOMP_DIR"/shell/*.cpp; do n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $GI -I . $RT; done

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
  mkdir -p "$OBJ"; rm -f "$OBJ"/*.o "$OBJ"/*.err
  # r23-w38: the pre-clean used to `rm -f "$OUT"`, so a FAILING link DESTROYED the last good
  # module DLL (w37: the only build/futari_game_abn.dll on the machine, three days old, gone —
  # and every gate leg with it).  Staleness must still be impossible under $OUT, so RETIRE the
  # artifact instead of deleting it: a failed link now leaves $OUT absent and $OUT.lastgood intact.
  [ -f "$OUT" ] && mv -f "$OUT" "$OUT.lastgood"
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
  for f in "$DECOMP_DIR"/game/*.cpp; do
    n=$(basename "$f" .cpp)
    # ABN-EXCLUDED TUs: bodies that carry reco_normal .data literals, which move +0x60 in the
    # abn image. The +8 symbol map renames FUNCTION symbols only — embedded data addresses are
    # not translated, so these TUs read/write the wrong abn globals. game_entry_msgs was the
    # first (decomp/game_abn/ carries its re-earned twin); the four asset-pipeline TUs joined
    # 2026-08-13 when the MATCHED differential caught the abn job pump dead on the shipped DLL
    # (0 read-jobs, "Now Loading" hang: pump TOC ptr addi -11864 vs abn's -11768 = +0x60).
    # Their abn arms run the GENERATED bodies until game_abn twins are earned.
    if [ "$MIDX" = "1" ]; then
      # objaction joined 2026-08-16: its four allocator constants (bytemap 0x88507DE8 / arena
      # 0x88508468 / bytemap 0x884F20A0 / arena 0x884EBCA0) are reco_normal .data literals.
      # objaction_queue joined 2026-08-16 (r18 leg): sub_880DCE90 embeds SIX reco_normal .data
      # pages (0x88280000/0x88290000/0x884D0000/0x88310000/0x88060000/0x887B0000) and
      # sub_880D8BB8 embeds 16 distinct .data addresses (twelve 0x882750xx words + three
      # byte-table bases + 0x887AD164).  Its abn arm runs the GENERATED bodies.
      # bossvein_object joined 2026-08-16 (r20 leg): 24 distinct reco_normal .data globals
      # across five pages (sine LUT 0x88062550, session 0x884Dxxxx, scene ptr 0x887AD130,
      # nodepark 0x883E0240/01D8, spawn gate 0x884D66A4, …), all decimal-emitted.
      # objaction_queue2 joined 2026-08-16 (r22ext leg): the remaining 14 bodies of the queue
      # slice embed 642 distinct reco_normal data addresses (530 after collapsing adjacent byte
      # pairs) across EIGHT pages — 0x88060000 (.rdata, incl. the sine LUT), 0x88250000,
      # 0x88260000, 0x88270000, 0x88310000 (the RNG seed page), 0x88350000, 0x884D0000 and
      # 0x887A0000 (incl. the 0x887AD164 emit counter).  Measured by walking the generated
      # bodies' asm COMMENTS and re-executing the address arithmetic
      # (decomp/game/drafts/ABN_EXCLUSION_queue_r22.txt §B): the recompiler emits these constants
      # in DECIMAL, so a hex scan for 0x........ reports a FALSE ZERO for all fourteen.
      # Its abn arm runs the GENERATED bodies.
      # fam4_object joined 2026-08-16 (r23 window 3), PROMOTED r23 window 5: family 4's
      # installer, its seven wired slot bodies and the shared gated shot emitter.  Embeds 22
      # distinct reco_normal data addresses (19 after collapsing adjacent byte pairs) across
      # EIGHT pages — 0x88060000 (.rdata, the 0x88062550 sine LUT), 0x88280000 (three lbzx
      # sprite-offset tables), 0x88310000 (the RNG seed), 0x88350000 (the SPAWN_X/Y/PA/PB emit
      # parameter block), 0x883E0000 (the node-park registry), 0x884D0000 (four run-state words),
      # 0x88560000 and 0x887A0000 (incl. the 0x887AD164 emit counter and the 0x887AD130 scene
      # POINTER).  Measured from the asm COMMENTS, decimal-emitted — a hex scan for 0x........
      # reports a false zero.  Its abn arm runs the GENERATED bodies.
      # (decomp/game/drafts/ABN_EXCLUSION_fam4_w3.txt §A/§C/§D.)
      # fam{1,3,9,10}_arms joined 2026-08-18 (r23 window 8, promoted out of staging/ this leg): the
      # +0x48 mode-arm trios of four families — the scene[84]-selected fire-control arms, three per
      # family, exactly one installed per object per run.  Each TU embeds reco_normal data addresses
      # on the 0x884D0000 run-state page (0x884D66A4 the emit ENABLE gate, read by all twelve
      # bodies; 0x884D6738 G_SUBSCREEN_SEQ in fam-3; 0x884D673C G_FLAGS_673C in fam-9's ==2 arm);
      # fam10_arms additionally embeds 0x88500000 and 0x88560000 (the scene-guard neighbourhood).
      # SIX distinct addresses / THREE pages over 2,022 instructions — the smallest data footprint
      # yet gated — and ALL READS, no `stw` to any module global anywhere in the twelve bodies.
      # ⚠ ALL-READS DOES NOT MAKE THE EXCLUSION OPTIONAL: without it the abn arm MISREADS the
      # +0x60-shifted enable gate, and a misread enable gate silently changes whether an arm fires
      # at all — a behaviour divergence that would be attributed to the conversion.
      # Measured from the asm COMMENTS, which the recompiler emits in DECIMAL — a hex scan for
      # 0x........ reports a false zero for every one of the six.
      # (decomp/game/drafts/ABN_EXCLUSION_arms_w7.txt §A/§C/§D.)  Their abn arms run the GENERATED
      # bodies.  ★ FOUR basenames, four independent rollback units — a promotion that moves three
      # of the four TUs and forgets the fourth is the exact failure shape §5.4 warns about.
      #
      # fam11_tick joined 2026-08-22 (r23 window 30, the four-leg gate): sub_88117AE8 / FamK2_Tick,
      # THE FACTORED TU (STANDARD s5.5).  Embeds 24 distinct reco_normal data addresses across
      # NINE pages -- 0x88060000 (.rdata, the 0x88062550 sine LUT), 0x88280000 (the kind tables
      # 0x88288F88/FA4, the T3 table 0x88288EE8, the sound source 0x8828C470), 0x88310000 (the
      # RNG seed), 0x88350000 (the A2+ emit block, FOUR words), 0x884D0000 (scroll freeze, blink
      # flags, three sound words), 0x884E0000 (the audio queue lock/base/cursor), 0x88500000 (lane
      # scroll-x, the deferred-destroy queue), 0x88560000 (destroy count, the family guard) and
      # 0x887A0000 (the scene POINTER 0x887AD130, the danmaku arena root 0x887AC97C).  WRITES as
      # well as reads.  Inventory = the TU's own G_* constant table (lis/addi-derived, LAWS T1),
      # proven complete by the s3 diff-audit: LOADS + STORES streams identical to the generated
      # body on 18 trials (decomp/game/converted/audit_88117AE8/audit_PASS.log).  Its abn arm runs
      # the GENERATED body.  (decomp/game/drafts/ABN_EXCLUSION_fam11_w30.txt.)
      #
      # paperdoll2_draw joined 2026-08-24 (r23 window 33, the four-leg gate): sub_881AE5D8, the
      # +0x44 per-frame paper-doll DRAW, THE SECOND FACTORED TU (STANDARD s5.5 as precedent).
      # Embeds THREE distinct reco_normal data addresses on THREE pages -- 0x88060000 (the 512-word
      # sine LUT 0x88062550, base of 20 lwzx), 0x88280000 (the placement page 0x88285428 and its
      # four sub-tables at +0/+24/+48/+60, base of 10 lbzx) and 0x887B0000 (the global sprite-emit
      # counter 0x887AD164 -- READ 4 sites / WRITTEN 22 sites).  Inventory = the TU's own G_*
      # constant table (lis/addi-derived, LAWS T1), proven complete by the s3 diff-audit: LOADS +
      # STORES streams identical to the generated body on every trial
      # (decomp/game/converted/audit_881AE5D8/audit_PASS.log), and RUN not asserted -- the union of
      # every 0x88...... effective address in the audit's own 16-trial dumps is 61 addresses, ALL
      # inside exactly those three pages, zero outside.
      # ⚠ THE NARROWEST EXCLUSION SINCE THE ARMS WAVE -- AND UNLIKE THAT WAVE, THIS ONE WRITES.
      # 0x887AD164 shares its lis with two live words 4 bytes away: 0x887AD130 (THE scene pointer,
      # read by 42 of the 43 class installers) and 0x887AD168 (the arcade-slowdown accumulator).
      # A +0x60 shift lands this body's 22 counter writes in that neighbourhood, so a missing
      # exclusion here is CORRUPTION, not merely a wrong read.  Its abn arm runs the GENERATED
      # body.  (decomp/game/drafts/ABN_EXCLUSION_881AE5D8_w31.txt.)
      #
      # class233_236_draw joined 2026-08-24 (r23 window 33, the four-leg gate, promoted SERIALLY
      # after paperdoll2_draw -- never two promotions in flight): sub_88111790, the +0x44 per-frame
      # DRAW callback of the class 233-236 family, THE THIRD FACTORED TU (STANDARD s5.5 as
      # precedent).  Embeds EIGHT distinct reco_normal table bases on ONE page -- 0x88350000, union
      # span 0x883513D4..0x88351637 (612 bytes), one halfword-pair table per counted loop.
      # ★ READ-ONLY: this TU writes NO module global (its 16 stw target the record returned by
      # Sprite_Emit), which makes it the first factored TU with a read-only abn footprint -- the
      # exclusion is still MANDATORY, because a +0x60 shift would MISREAD all eight tables and a
      # misread geometry table is a silent behaviour change, not a crash.  Inventory = the TU's own
      # kTbl* constant table (lis/addi-derived, LAWS T1, plus the derived trip counts), proven
      # complete by the s3 diff-audit: LOADS+STORES streams identical to the generated body on
      # every trial, with the union of every guest EA in the audit dumps inside the span above
      # (decomp/game/converted/audit_88111790/audit_PASS.log).  Its abn arm runs the GENERATED
      # body.  (decomp/game/drafts/ABN_EXCLUSION_88111790_w32.txt.)
      #
      # actor3pose_draw joined 2026-08-24 (r23 window 35, the four-leg gate, promoted SERIALLY
      # after class233_236_draw -- never two promotions in flight): sub_881A1428, the +0x44
      # per-frame THREE-POSE camera-relative paper-doll DRAW, THE FOURTH FACTORED TU
      # (STANDARD s5.5 as precedent).  Embeds THREE distinct reco_normal data addresses on TWO
      # 64K pages:
      #   0x88280000 : 0x88283440, the index/pair byte-table cursor (lis r9,-30680 + 13376),
      #                base of most of the 57 lbzx; ten sub-tables at -160..+0.
      #   0x887A0000 : 0x887ACFD0, the block-C {dx,dy} table cursor (lis r8,-30597 - 12336), and
      #                0x887AD164, the global sprite-emit counter G_EMITS (same lis, -11932).
      # ★★ WRITES: G_EMITS is written at ELEVEN of the 38 emit sites (1 seed+1, 9 cache+1, 1
      # scratch).  A +0x60 shift lands those writes at 0x887AD1C4, in the live neighbourhood of
      # the scene pointer 0x887AD130 and the slowdown accumulator 0x887AD168 -- so a missing
      # exclusion here is CORRUPTION, not a wrong read.  It is the FIRST factored TU since
      # paperdoll2_draw whose abn footprint WRITES.
      # Inventory = the TU's own T_*/G_EMITS constant table (lis/addi-derived, LAWS T1), proven
      # complete by the s3 diff-audit: LOADS+STORES streams identical to the generated body on
      # all 19 trials, and the union of every guest EA in the 0x88 space over those trials is
      # 175 distinct addresses, ALL inside these two pages, ZERO outside, with exactly ONE write
      # target (0x887AD164).  Measured spans: 0x882832A6..0x882834F9 and 0x887ACEC2..0x887AD164.
      # (The spans run BELOW the cursor bases because the per-limb index byte is SIGN-EXTENDED
      # and a negative k indexes backwards -- real behaviour, same page.)
      # Its abn arm runs the GENERATED body.  RE-CERTIFIED from the promoted path at promotion
      # (STANDARD w34 amendment 5): audit PASS/PASS + negctl 7/7, both byte-identical to the
      # banked w34 verdicts (futari_decomp/bank/r23/w35/gate_A_recert_*_w35.log).
      # (decomp/game/drafts/ABN_EXCLUSION_881A1428_w34.txt.)
      #
      # ⚠ THIS CASE LIST MATCHES ON TU BASENAME ($n = basename $f .cpp).  A TU renamed on
      # promotion — which the CONVERTED tier does BY DESIGN — must have its new basename added
      # here in the same change, or the exclusion silently does nothing: no build error, and the
      # abn arm links the TU and reads the wrong +0x60-shifted globals.
      case "$n" in game_entry_msgs|asset_decode|asset_pump|archive|mem_util|asset_upload|page_bake|objaction|objaction_queue|objaction_queue2|bossvein_object|fam4_object|fam1_arms|fam3_arms|fam9_arms|fam10_arms|fam11_tick|paperdoll2_draw|class233_236_draw|actor3pose_draw) continue;; esac
    fi
    cc "decomp_$n" "$f" $GI -I . $RT $MAP
  done
  if [ "$MIDX" = "1" ]; then
    for f in "$DECOMP_DIR"/game_abn/*.cpp; do n=$(basename "$f" .cpp); cc "decomp_$n" "$f" $GI -I . $RT; done
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
