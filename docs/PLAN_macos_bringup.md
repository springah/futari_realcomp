# PLAN — macOS bring-up handoff (written 2026-10-03 on the Linux proving ground)

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
# then the two cmake/ninja lines in the header of build_mac.sh, then:
bash build_mac.sh
```
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

- **xWMA decoder** (`shell/gen/rt_xwma.cpp`): Media Foundation DMO on Windows, stub elsewhere.
  Compressed SE/voice/system wave banks are silent. Port = libavcodec `wmav2`/`wmapro` behind
  `rx_dmo_decode`'s contract; same work serves Linux.
- **Module DLL arm** (`host/module_registry.cpp`): the combined executable does not need it; the
  per-mode module bundles (`build_win_dll.sh`) do. dlopen + `.dylib`, post-first-boot.
- **16 KB pages**: `rt_phys.cpp`'s POSIX arm has no page math (only the Windows arm commits/resets
  pages), so nothing to change until something faults; keep it in mind for any `madvise` added later.
- **Host keyboard**: `RT_PAD_HOST` is an X11 `XQueryKeymap` poller; on macOS it logs "dlopen libX11
  FAILED" and disables itself. Replace with `SDL_GetKeyboardState` in the pump when a keyboard is
  wanted (controllers already work through SDL).
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
