#!/bin/bash
# Build futari_merged: game (out_reco) + shell (shell/gen) recompiled trees linked into
# ONE process with a UNIFIED kernel layer (Gate 1).
#
# Kernel-layer unification: the GAME's kernel (out_reco/rt.cpp + stubs.cpp: real host file
# I/O, pthread thread model, fixed NtAllocateVirtualMemory ABI, rt_indirect_call) is the base
# for the 59 imports SHARED between game and shell. The SHELL's REAL kernel (shell/gen/rt.cpp
# + stubs.cpp: null-GPU vblank pump, notification model, signin, D3D9 hooks) is compiled in
# and supplies the 108 imports that are SHELL-ONLY (game does not use them). Where both trees
# define the same import symbol, the shell's copy is `objcopy --weaken-symbol`'d so the
# linker keeps the GAME's strong definitions (real file I/O / real threads) and only takes
# the shell's copy for the 108 truly shell-only symbols. out_reco/shell_only_stubs.cpp (108
# trivial return-0 link-satisfiers) is REMOVED from the link -- replaced by the real shell
# kernel objects.
#
# Does NOT touch obj/ (futari_mode) or obj_shell/ (futari_shell) -- separate obj_merged/.
set -u
cd ~/xr-work || exit 1
mkdir -p obj_merged
rm -f obj_merged/*.o obj_merged/*.err futari_merged

GAME_INC="-I $HOME/xr-work/out_reco -I $HOME/xr-derisk/XenonUtils -I $HOME/xr-derisk/thirdparty/simde"
SHELL_INC="-I $HOME/xr-work/shell/gen -I $HOME/xr-derisk/thirdparty/simde"
STD="-std=c++20 -O2"
# XenonRecomp always names each module's CRT entry thunk "_xstart" (guest-address-derived
# names like sub_88xxxxxx / sub_82xxxxxx never collide across modules, but this ONE fixed
# name does). Both _xstart and its real implementation __imp___xstart are emitted `weak`
# by the recompiler (its standard aliasing pattern for every guest symbol) -- so without a
# rename, the linker silently resolves ALL __imp___xstart/_xstart references project-wide
# to whichever copy is strong (the game's, since only the shell's copy gets
# --weaken-symbol'd below for shared imports/millicode), which POINTS THE SHELL'S OWN
# 0x8208A2B8 FUNC-TABLE ENTRY AT THE GAME'S CRT ENTRY. (Found via RT_BOOT_SHELL returning
# instantly with imports=0 -- the "shell boot" was silently running the game's tiny CRT
# init instead.) Fix: rename _xstart/__imp___xstart to *_shell via -D for EVERY shell
# compile (guest ppc_recomp objects + ppc_func_mapping + the 2 kernel objects), so the
# shell's entry is a distinctly-named, non-colliding symbol.
SHELL_XSTART_DEF="-D_xstart=_xstart_shell -D__imp___xstart=__imp___xstart_shell"

# ---- GAME tree: out_reco/*.cpp EXCEPT shell_only_stubs.cpp (replaced by the shell's real
# kernel objects below) -- compiled against the GAME's headers. ----
for f in out_reco/*.cpp; do
  n=$(basename "$f" .cpp)
  [ "$n" = "shell_only_stubs" ] && continue
  echo "GAME:$n"
done | xargs -P12 -I@@ bash -c '
  tag="${1#GAME:}"
  clang++ '"$STD"' -include "$HOME/xr-work/out_reco/rt_indirect.h" '"$GAME_INC"' \
    -c "$HOME/xr-work/out_reco/$tag.cpp" -o "$HOME/xr-work/obj_merged/game_$tag.o" \
    2> "$HOME/xr-work/obj_merged/game_$tag.err" \
    || { echo "FAILED: game/$tag"; head -20 "$HOME/xr-work/obj_merged/game_$tag.err"; }
' _ @@

# ---- SHELL tree: shell/gen/ppc_recomp.*.cpp (guest code), cross-module shim force-included
# so shell-internal indirect calls also route through rt_indirect_call (via the rt_indirect()
# forwarder in out_reco/rt.cpp -- shell's own ppc_recomp_shared.h independently hardcodes a
# legacy `PPC_CALL_INDIRECT_FUNC(x) -> rt_indirect(x,ctx,base)` shim that wins over ours once
# the TU's own #include runs; see comments in out_reco/rt_indirect.h and out_reco/rt.cpp). ----
for f in shell/gen/ppc_recomp.*.cpp; do
  n=$(basename "$f" .cpp)
  echo "$n"
done | xargs -P12 -I@@ bash -c '
  clang++ '"$STD"' '"$SHELL_XSTART_DEF"' -include "$HOME/xr-work/out_reco/rt_indirect.h" '"$SHELL_INC"' \
    -c "$HOME/xr-work/shell/gen/@@.cpp" -o "$HOME/xr-work/obj_merged/shell_@@.o" \
    2> "$HOME/xr-work/obj_merged/shell_@@.err" \
    || { echo "FAILED: shell/@@"; head -20 "$HOME/xr-work/obj_merged/shell_@@.err"; }
' _ @@

# ---- shell's ppc_func_mapping.cpp, renamed export symbol to avoid collision with the
# game's PPCFuncMappings ----
clang++ $STD -DPPCFuncMappings=PPCFuncMappings_shell $SHELL_XSTART_DEF -include "$HOME/xr-work/out_reco/rt_indirect.h" $SHELL_INC \
  -c shell/gen/ppc_func_mapping.cpp -o obj_merged/shell_ppc_func_mapping.o \
  2> obj_merged/shell_ppc_func_mapping.err \
  || { echo "FAILED: shell/ppc_func_mapping"; head -20 obj_merged/shell_ppc_func_mapping.err; }

# ---- shell's REAL kernel layer: rt.cpp + stubs.cpp (the 108 shell-only imports' real
# implementations: vblank pump, notifications, signin, D3D9 hooks, etc). Compiled against
# shell headers WITHOUT shell/gen/harness.cpp (its main() would conflict with the game's). ----
for n in rt stubs; do
  echo "KERNEL:$n"
done | xargs -P4 -I@@ bash -c '
  tag="${1#KERNEL:}"
  clang++ '"$STD"' '"$SHELL_XSTART_DEF"' -include "$HOME/xr-work/out_reco/rt_indirect.h" '"$SHELL_INC"' \
    -c "$HOME/xr-work/shell/gen/$tag.cpp" -o "$HOME/xr-work/obj_merged/shellkernel_$tag.o" \
    2> "$HOME/xr-work/obj_merged/shellkernel_$tag.err" \
    || { echo "FAILED: shellkernel/$tag"; head -30 "$HOME/xr-work/obj_merged/shellkernel_$tag.err"; }
' _ @@

# ---- Gate 2: Xex loader bridge + reco_normal load injection (futari_merged only;
# out_reco/merged/ is excluded from the default out_reco/*.cpp glob) ----
# merged_xex.cpp was split 3 ways at L2 (dll_packaging_plan.md §2.3): merged_game.cpp (sub_88
# game hooks) / merged_bridge.cpp (the 3 Xex fns) / merged_shell.cpp (sub_82 shell hooks).
# NOTE: this legacy Linux build is NOT the shipping recipe (that is build_win.sh) and has not
# been re-validated since the split.
for mm in merged_game merged_bridge merged_shell; do
clang++ $STD -include "$HOME/xr-work/out_reco/rt_indirect.h" $GAME_INC \
  -c "out_reco/merged/$mm.cpp" -o "obj_merged/$mm.o" \
  2> "obj_merged/$mm.err" \
  || { echo "FAILED: $mm"; head -20 "obj_merged/$mm.err"; }
done

# ---- Our own Vulkan renderer (render/vk_render.cpp) — rexglue-free. Provides strong
# extern "C" rvk_present() that the shell's D3D9 Present hook (weakly-declared) calls under
# RT_VK=1. System Vulkan headers only; linked against libvulkan below. ----
clang++ $STD -c render/vk_render.cpp -o obj_merged/vk_render.o \
  2> obj_merged/vk_render.err \
  || { echo "FAILED: vk_render"; head -20 obj_merged/vk_render.err; }

# ---- host audio sink (shell/gen/rt_audio.cpp): rt_audio_submit / rt_audio_can_accept,
# referenced by shell/gen/stubs.cpp (XAudioSubmitRenderDriverFrame) + rt.cpp (audiopump gate).
# RT_AUDIODUMP wav capture is portable; the RT_AUDIO live backend is Windows-only (WASAPI,
# _WIN32-gated inside the file) — on Linux RT_AUDIO logs a one-shot "no backend" notice. ----
clang++ $STD -c shell/gen/rt_audio.cpp -o obj_merged/rt_audio.o \
  2> obj_merged/rt_audio.err \
  || { echo "FAILED: rt_audio"; head -20 obj_merged/rt_audio.err; }

NOBJ=$(ls obj_merged/*.o 2>/dev/null | wc -l)
NSRC_GAME=$(($(ls out_reco/*.cpp | wc -l) - 1))   # minus shell_only_stubs.cpp
NSRC=$((NSRC_GAME + 37 + 1 + 2 + 3 + 1 + 1))   # game files + 37 ppc_recomp + ppc_func_mapping + 2 shell kernel objs + 3 merged_* objs (L2 split) + vk_render.o + rt_audio.o
echo "objects: $NOBJ / expect $NSRC"
if [ "$NOBJ" -ne "$NSRC" ]; then
  echo "COMPILE_INCOMPLETE"
  echo "--- failed logs ---"
  for f in obj_merged/*.err; do
    if [ -s "$f" ]; then echo "$f:"; head -20 "$f"; fi
  done
  exit 1
fi

# ---- Weaken the shared XenonRecomp CRT/ABI millicode-helper symbols in the SHELL objects
# only, so they don't collide with the byte-identical copies compiled into the GAME
# objects: __savegprlr_{14..31}, __restgprlr_{14..31}, __savefpr_{14..31}, __restfpr_{14..31}
# (register-spill/reload thunks). These ARE generic per-recompiler-output boilerplate, not
# guest-address-specific code -- both bodies are byte-identical logic, so weakening one side
# and letting the linker pick either copy is semantically safe. (NOTE: _xstart is NOT in
# this list -- unlike the millicode helpers, _xstart/__imp___xstart is each module's OWN
# CRT-entry thunk with module-specific guest logic; it merely happens to share the same
# fixed name across modules. Weakening it here previously caused the shell's function table
# to silently resolve 0x8208A2B8 to the GAME's _xstart. Fixed instead via -D rename
# (SHELL_XSTART_DEF above) so the names never collide in the first place.) ----
DUPSYMS=()
for reg in savegprlr restgprlr savefpr restfpr; do
  for n in $(seq 14 31); do DUPSYMS+=("--weaken-symbol=__imp____${reg}_${n}"); done
done
for o in obj_merged/shell_*.o; do
  objcopy "${DUPSYMS[@]}" "$o" || { echo "FAILED: objcopy weaken (millicode) on $o"; exit 1; }
done
echo "weakened ${#DUPSYMS[@]} millicode symbols across shell_*.o objects"

# ---- Weaken the 59 imports SHARED between game and shell + the g_import_calls global,
# in the two new shell KERNEL objects only (shellkernel_rt.o / shellkernel_stubs.o), so the
# linker keeps the GAME's strong definitions (real file I/O, real pthread threads, fixed
# NtAllocateVirtualMemory ABI) for shared imports, and only takes the SHELL's copy for the
# 108 truly shell-only imports (VdSwap, VdSetGraphicsInterruptCallback, notifications,
# signin, D3D9 hooks, etc). List = out_reco/imports_need.txt (the game's import set)
# intersected with the shell kernel objects' defined __imp__ symbols (both sets = 59). ----
SHARED_IMPORTS=(
  __imp__DbgPrint __imp__ExCreateThread __imp__ExGetXConfigSetting
  __imp__ExRegisterTitleTerminateNotification __imp__ExTerminateThread __imp__KeBugCheck
  __imp__KeBugCheckEx __imp__KeDelayExecutionThread __imp__KeGetCurrentProcessType
  __imp__KeQuerySystemTime __imp__KeSetAffinityThread __imp__KeSetBasePriorityThread
  __imp__KeTlsAlloc __imp__KeTlsFree __imp__KeTlsGetValue __imp__KeTlsSetValue
  __imp__KfAcquireSpinLock __imp__KfReleaseSpinLock __imp__MmAllocatePhysicalMemoryEx
  __imp__MmFreePhysicalMemory __imp__NtAllocateVirtualMemory __imp__NtClearEvent
  __imp__NtClose __imp__NtCreateEvent __imp__NtCreateFile __imp__NtDuplicateObject
  __imp__NtFlushBuffersFile __imp__NtFreeVirtualMemory __imp__NtOpenFile
  __imp__NtQueryDirectoryFile __imp__NtQueryFullAttributesFile __imp__NtQueryInformationFile
  __imp__NtQueryVirtualMemory __imp__NtQueryVolumeInformationFile __imp__NtReadFile
  __imp__NtReadFileScatter __imp__NtResumeThread __imp__NtSetEvent __imp__NtSetInformationFile
  __imp__NtWaitForMultipleObjectsEx __imp__NtWaitForSingleObjectEx __imp__NtWriteFile
  __imp__ObDereferenceObject __imp__ObReferenceObjectByHandle __imp__RtlCompareMemoryUlong
  __imp__RtlEnterCriticalSection __imp__RtlImageXexHeaderField __imp__RtlInitAnsiString
  __imp__RtlInitializeCriticalSection __imp__RtlInitializeCriticalSectionAndSpinCount
  __imp__RtlLeaveCriticalSection __imp__RtlNtStatusToDosError __imp__RtlRaiseException
  __imp__RtlTimeFieldsToTime __imp__RtlTimeToTimeFields __imp__VdShutdownEngines
  __imp____C_specific_handler __imp___vsnprintf __imp__sprintf
)
# Extra non-import globals/helpers both trees define strongly (dup-symbol at link time
# otherwise): g_import_calls (std::atomic<long>, defined in both stubs.cpp files) and
# rt_indirect (extern "C" forwarder/dispatcher -- out_reco/rt.cpp defines it as a thin
# forwarder to rt_indirect_call (correct: range-dispatches to BOTH game+shell tables);
# shell/gen/rt.cpp independently defines its own native rt_indirect() that only knows its
# own module's table. Weakening the shell's copy keeps the game's cross-module-aware
# forwarder, which is what we want in the unified/merged binary.)
EXTRA_DUP_GLOBALS=( g_import_calls rt_indirect )

WEAKEN2=()
for s in "${SHARED_IMPORTS[@]}"; do WEAKEN2+=("--weaken-symbol=$s"); done
for s in "${EXTRA_DUP_GLOBALS[@]}"; do WEAKEN2+=("--weaken-symbol=$s"); done
objcopy "${WEAKEN2[@]}" obj_merged/shellkernel_rt.o || { echo "FAILED: objcopy weaken (shared imports) on shellkernel_rt.o"; exit 1; }
objcopy "${WEAKEN2[@]}" obj_merged/shellkernel_stubs.o || { echo "FAILED: objcopy weaken (shared imports) on shellkernel_stubs.o"; exit 1; }
echo "weakened ${#SHARED_IMPORTS[@]} shared imports + ${#EXTRA_DUP_GLOBALS[@]} dup globals across shellkernel_*.o"

# ---- Gate 2: weaken the shell kernel's return-0 Xex stubs so merged_xex.o's real bridge wins ----
objcopy --weaken-symbol=__imp__XexLoadImage --weaken-symbol=__imp__XexGetProcedureAddress --weaken-symbol=__imp__XexGetModuleHandle obj_merged/shellkernel_stubs.o || { echo "FAILED: objcopy weaken (xex) on shellkernel_stubs.o"; exit 1; }
echo "weakened 3 Xex stubs on shellkernel_stubs.o"

clang++ -O2 -std=c++20 obj_merged/*.o -o futari_merged \
  -Wl,--start-group \
  ~/xr-derisk/build/XenonUtils/libXenonUtils.a \
  ~/xr-derisk/build/XenonAnalyse/libLibXenonAnalyse.a \
  ~/xr-derisk/build/thirdparty/disasm/libdisasm.a \
  ~/xr-derisk/build/thirdparty/xxHash/cmake_unofficial/libxxhash.a \
  ~/xr-derisk/build/thirdparty/fmt/libfmt.a \
  -Wl,--end-group -lpthread -lvulkan \
  2> obj_merged/link.err \
  && echo "LINK_OK" || { echo "LINK_FAILED"; cat obj_merged/link.err; }
