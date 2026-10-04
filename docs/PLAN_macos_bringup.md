# PLAN — macOS bring-up handoff (written 2026-10-03 on the Linux proving ground)

> **2026-10-03, later the same day, ON THE MAC (M3 Max, macOS 27.0.1): DRIVEN TO GREEN.**
> `bash build_mac.sh` compiles 150 objects and links in 48 s wall; headless run returns cleanly;
> `scripts/run_mac.sh` boots the real shell to the animated title screen (logo, PRESS START
> BUTTON blink, copyright) in a Cocoa window on MoltenVK at 60 fps (f2101 at 35 s), host
> controllers enabled through SDL3, audio worker up, zero faults. Capture:
> `_local/captures/mac_title_20261003_26s.png`. What the Linux map got wrong or missed, in the
> order it was hit (each is now handled in the script or the source):
>
> 1. **`__attribute__((alias))` does not exist on Mach-O** ("aliases are not supported on
>    darwin") — 17,749 lines across all 70 recompiled TUs, the single biggest blind spot. Fixed by a
>    pre-pass in `build_mac.sh` (header item 4): the alias line becomes a weak forwarding stub in a
>    copy under `build/obj_mac/src/`; tracked sources untouched. One hand-patched line
>    (`shell/gen/ppc_recomp.5.cpp` `_xstart`, `alias(RT_XSTART_ALIAS_STR)`) needed the macro
>    spelled out in the regex.
> 2. **Apple ld demangles C++ names in duplicate-symbol errors**, so `--redefine-sym` silently
>    matched nothing for the `sub_X(PPCContext&, unsigned char*)` groups; and **three-way
>    duplicates exist** (game_rt + game_stubs + shellkernel_stubs for the Ke*/Kf* kernel imports),
>    which the two-object regex missed. The parser now maps printed names back through
>    llvm-nm + llvm-cxxfilt, takes every object in a group, and uses a per-object rename suffix
>    (two losers of the same symbol collided under one suffix). Measured: 182 groups, 185 renames,
>    18 objects.
> 3. **Two missing includes** macOS libc++ does not pull in transitively: `<unistd.h>` in
>    `out_reco/harness.cpp` (alarm/usleep/_exit), `<thread>` in `out_reco/rt.cpp`.
> 4. **The shell-boot hang sampler kills an attended session at ~22 s** (alarm(6) + 5 samples +
>    `_exit(42)`; it is a Linux proving-ground watchdog). `RT_SAMPLES=0` now means attended: no
>    alarm at all; `scripts/run_mac.sh` sets it.
> 5. **XenonRecomp's vendored fmt does not compile against the macOS 27 SDK** (`malloc`/`free`
>    undeclared in `fmt/format.h`): one-line `#include <cstdlib>` in the gitignored checkout — the
>    recipe below has it.
> 6. Not blind after all, confirmed working first try: main-thread window marshalling,
>    `SDL_RunOnMainThread`, portability enumeration, 16 MB guest stacks, `MAP_NORESERVE` fallback,
>    `pthread_threadid_np`, the arm64 cycle counter, NEON via simde.
>
> **Same evening, keyboard + sound (both measured, not inferred):**
> - **Keyboard**: the SDL pump on the main thread keeps a pad word from KEY_DOWN/KEY_UP
>   (`rvk_sdl_host_buttons`, render/vk_render.cpp); the `RT_PAD_HOST` poller's non-Windows arm reads
>   it under `RVK_WINDOW` instead of dlopen'ing libX11 (weak reference, so renderer-less builds
>   still link and fall through to X11). Proof: `[rvk][win] key Return down -> pad 0x0010` →
>   `[xinput] press pad=0x0010` → the save-data dialog, then A → save written under
>   `_local/saves/save_mac/`, then START → top menu. Instantaneous synthetic presses (System
>   Events `key code`) are too short for the 4 ms poller/60 Hz guest; held keys and humans are fine.
> - **Sound was never a decoder problem on this port**: the guest renders ALL audio itself (music
>   via the XMP status stub, SE/VOICE/SYS_SE natively since the 08-01 de-doubling), and the whole
>   live-sink block in rt_audio.cpp sat under `#ifdef _WIN32`, so macOS/Linux printed "no live
>   backend" and were silent even for PCM. The SDL3 sink (CoreAudio here) now starts on every
>   platform; only the legacy WASAPI revert arm is Windows-only. Measured on the RT_AUDIODUMP mix:
>   title = true digital zero (the ledger's "authentically SILENT" gate holds), SE_OK02 at the START
>   press (2.9 s decay = the sample's length), `mushifuta_Menu02` sustained rms 0.04-0.05 from the
>   menu transition on. The §3 "compressed SE/voice silent" claim and README's "still missing: the
>   xWMA decoder" were stale carry-overs from the bridge era.
> - **xWMA host decoder, libavcodec arm** (`-DRT_XWMA_AVCODEC`, build_mac.sh finds Homebrew
>   ffmpeg): same packets, same 6-byte flags2=31 extradata the xwma demuxer synthesizes. Bit-exact
>   against the banks' dpds oracle (delta=0 on SE mono 44.1k, VOICE, SYS_SE stereo 48k;
>   `build/rt_xwma <bank> N out.wav`), and plays in-process through RT_XWMATEST. It serves the
>   bridge/A-B arms (`RT_BRIDGESE=1`, `RT_XWMATEST`), not the shipping path.
>
> **10-04: `.app` DONE** — `bash mac-build/build_mac_app.sh` → `~/Desktop/projects/Futari Realcomp.app` (892 MB with
> the assets inside, family-and-friends build): combined engine relinked without libavcodec, SDL3 + MoltenVK in
> Contents/Frameworks with the load commands rewritten (no Homebrew/checkout paths survive), `mac-build/launcher.c`
> as CFBundleExecutable (sets run_mac.sh's env, bundle-relative paths, saves under ~/Library/Application Support,
> log under ~/Library/Logs, then exec()s the engine), ad-hoc signed. Finder launch → title, 0 FATAL. On another
> Mac: right-click > Open once. Still open: module-DLL arm (only for per-mode bundles), and the rest of
> docs/BACKLOG.md which is platform-independent. `presentMode` is FIFO (MoltenVK offers no
> MAILBOX) — fine at 60 Hz.

Target: the user's Mac — **arm64, macOS 27.0.1, Command Line Tools, Homebrew with llvm 23, cmake,
ninja, molten-vk 1.4.2** (no vulkan-loader). Neither repo is on it yet; neither is the game dump.
Everything below was prepared WITHOUT a Mac: read it as a map, not as verified fact. The Linux
build (`build_linux.sh`, same code) is green and smoke-tested, so the open items are exactly the
macOS-specific ones listed here.

## 0. First five minutes on the Mac

```bash
brew install vulkan-headers            # molten-vk alone has the dylib; headers are separate
git clone https://github.com/springah/futari_realcomp && git clone https://github.com/springah/futari_decomp
cd futari_realcomp && mkdir -p external
git clone --depth 1 --recurse-submodules --shallow-submodules https://github.com/hedge-dev/XenonRecomp external/xr-derisk
git clone --depth 1 --branch release-3.4.8 https://github.com/libsdl-org/SDL external/SDL
# the vendored fmt needs one include against the macOS 27 SDK (malloc/free undeclared):
sed -i '' 's|^#  include <cstring>  // std::memcpy|#  include <cstdlib>  // malloc, free\n#  include <cstring>  // std::memcpy|' external/xr-derisk/thirdparty/fmt/include/fmt/format.h
# then the two cmake/ninja lines in the header of build_mac.sh (pass -DCMAKE_C_COMPILER/-DCMAKE_CXX_COMPILER
# = Homebrew llvm for xr-derisk), then:
bash build_mac.sh
bash scripts/run_mac.sh      # attended session: boots the shell in a window; RUN_SECS=<n> to cap
```
A game dump already on the Mac can be used directly: `assets/` is a pure relocation of the disc
(tools/extract/STATUS_day4_extract_prep.md), so any other port's extracted `assets/` + `dlc/`
copies straight in (that is how this session got its data).
Copy the game dump from the Windows box the way `docs/DUMPING.md` describes; the port boots
headless without it (the harness returns cleanly), which is enough to prove the link.

## 1. What is already done (Linux-verified, macOS arms added blind)

| area | state |
|---|---|
| kernel/harness (mmap arena, pthreads, sigaction) | green on Linux; `MAP_NORESERVE` fallback and `xr_gettid` via `pthread_threadid_np` added for Apple |
| recompiled PPC + VMX | simde → NEON on arm64, no code change expected; `__rdtsc` has an arm64 arm (`RT_MFTB_RAW` only) |
| audio | SDL3 (`rt_audio.cpp`), portable; CoreAudio comes with the SDL build |
| window, Vulkan surface, event pump | SDL3 arm in `render/vk_render.cpp`, smoke-tested on Xvfb+llvmpipe; Apple adds the main-thread marshalling below |
| host controllers | SDL3 gamepad arm in `shell/gen/stubs.cpp` (XInput slot) |
| guest thread stacks | 16 MB on Apple (`out_reco/rt.cpp`); macOS secondary threads default to 512 KB |
| MoltenVK plumbing | `VK_KHR_portability_enumeration` (+ create flag) and `VK_KHR_portability_subset` added only when offered; `RVK_VULKAN_LIBRARY` makes SDL load the same MoltenVK dylib the binary links |
| build script | `build_mac.sh` (untested) |

## 2. The three designs that differ from Linux

**Main thread.** Cocoa requires window creation and the event pump on the process main thread; the
guest and its presents run on guest threads. Under `RVK_WINDOW`, `out_reco/harness.cpp` `main()` now
hands the harness to `rvk_run_on_main_thread()` (vk_render.cpp): SDL video is initialised on the main
thread, the real harness runs as `guest_main` on a 64 MB-stack thread, and the main thread pumps
events at ~500 Hz. Window + surface creation (`rvkWindowCreateNative`) runs through
`SDL_RunOnMainThread`; presents skip the pump when they are not SDL's main thread. Linux behaviour is
unchanged (there SDL's main thread IS the presenting thread). **Untested on Cocoa** — first thing to
watch: does `SDL_RunOnMainThread` return, does the window appear, does F11 (handled on the main
thread) work.

**Linker.** Apple's ld has no `--allow-multiple-definition` (ld64.lld neither), and
`llvm-objcopy --weaken-symbol` silently does nothing on Mach-O. `--redefine-sym` DOES work on Mach-O
(verified here). `build_mac.sh` therefore links once, parses the duplicate-symbol errors, renames the
losing definition (the object later in the link line, same order as build_win.sh) to `<sym>__dup_dropped`
with llvm-objcopy, and relinks. The Linux link without the flag lists **174 duplicates**: 72 millicode
helpers (`__imp____save/restgprlr/fpr_NN`, shell tree), ~70 shared kernel imports (shell kernel vs game
kernel), the 3 Xex stubs (shell stubs vs merged_bridge), 3 game_rt-vs-game_stubs, and ~30
`__imp__sub_*` decomp overrides vs the recompiled copies. Two parsers are in the script for the
ld64 and ld-prime message formats; if the Mac's ld prints something else, fix the regex, that is all.
Semantics note: renaming also redirects intra-object references to the renamed copy — which is what
clang's local binding already does on ELF, so this matches the Linux link.

**Vulkan.** MoltenVK linked directly, no loader. Known MoltenVK gaps to check against what
`vk_render.cpp` enables: `shaderInt64`, `bufferDeviceAddress`, `runtimeDescriptorArray`,
`shaderSampledImageArrayNonUniformIndexing` (initVk warns if a feature is missing — read those lines
first), and any `logicOp` use in pipelines. `apiVersion` is 1.2. If a feature is missing the
renderer will say so at `[rvk]` lines before the first present.

## 3. Still untouched (known)

- ~~**xWMA decoder**~~ DONE 10-03 evening: libavcodec arm behind `rx_dmo_decode`'s contract
  (`-DRT_XWMA_AVCODEC`); and the shipping path never needed it — see the top block.
- **Module DLL arm** (`host/module_registry.cpp`): the combined executable does not need it; the
  per-mode module bundles (`build_win_dll.sh`) do. dlopen + `.dylib`, post-first-boot.
- **16 KB pages**: `rt_phys.cpp`'s POSIX arm has no page math (only the Windows arm commits/resets
  pages), so nothing to change until something faults; keep it in mind for any `madvise` added later.
- ~~**Host keyboard**~~ DONE 10-03 evening: the SDL pump feeds the poller (top block).
- **Code signing / bundle**: a bare executable is fine for development.

## 4. If it fights back — the order to look

1. `bash build_mac.sh` compile errors → almost certainly Apple-header spellings in `#else` arms
   (fix in place with `#if defined(__APPLE__)`).
2. Link pass 1 must FAIL with duplicate symbols; pass 2 must succeed. If pass 1 fails on anything
   else, read `build/obj_mac/link.err`.
3. Headless run: `build/futari_merged` → `[harness] RETURNED cleanly`. Proves arena, threads, simde.
4. `RVK_WINDOW=1 build/futari_merged` → `[rvk] Vulkan up: device="Apple M…"` then
   `[rvk][win] SDL3 window up (… video=cocoa)`.
5. Then the game dump and the real shell boot (`RT_BOOT_SHELL=1`, see `scripts/run_futari.sh` for
   the Windows env set; strip Windows-only levers).
