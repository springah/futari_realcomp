# In-game settings overlay (F2) -- design and estimate (NOT BUILT)

Written 2026-11-07 (w1107 CONFIG lane). Status: proposal. What shipped in w1107 is the cheap half of the player settings
surface: `futari.ini` (read by the engine at start-up, `host/futari_ini.h`), a template that explains every key
(`tools/settings/futari.ini.template`), a terminal settings tool (`tools/settings/futari_settings.py`, run by
`Settings.bat` / `Settings.command` and offered by the first-run wizard). This document is the follow-on: a settings
screen inside the game window, the way futari_recomp has one.

## What futari_recomp has, and what of it carries over

futari_recomp's launcher (`../futari_recomp/src/launcher/*`, `src/ini_merge.h`; 3,840 lines, BSD-3-Clause, same owner)
is a Dear ImGui dialog on the rexglue SDK's overlay stack (`rex/ui/imgui_dialog.h`): the SDK owns the ImGui context, the
font atlas upload, the input routing and the draw on its presenter. It has two modes: first-run setup (pick a dump,
extract it with a C++ extractor, translate the Renut shaders) and the F2 settings screen (renderer, fullscreen, vsync,
window size, DLC found, shader package), saved into `futari.ini` through `ini_merge.h`.

| piece | lines | reusable in realcomp? |
|---|---|---|
| `ini_merge.h` (in-place ini edit that keeps comments) | 211 | yes, as is (pure std) -- replaces the Python editor's logic |
| `launcher_dialog.cpp/.h` (the two screens) | 977 | layout and flow only; every cvar read/write and the ImGuiDialog base are SDK-bound |
| `launcher_font.h` (embedded font) | 275 | yes |
| `game_source.cpp/.h` (C++ ISO / console-install / extracted-folder reader) | 962 | mostly: needs realcomp's manifest (SHA-256, 58 rows) and derived copies; has sha1.h only |
| `file_picker*` (IFileDialog / NSOpenPanel) | 280 | yes |
| `shader_pipeline*` (Renut shaders) | 653 | no (realcomp has no Renut) |
| `update_check*` | 362 | optional |

Licence: borrowing is clean in the direction recomp -> realcomp only if realcomp states a licence. **futari_realcomp has
no LICENSE file** (owner decision, flagged to the banker; this lane did not add one). BSD-3 requires the copyright notice
and the licence text to travel with the copied source, so the borrowed files keep their header and a NOTICE entry.

## What realcomp lacks that the SDK gave recomp for free

1. **An ImGui integration.** No Dear ImGui in `thirdparty/` or `external/`. Needed: imgui core + `imgui_impl_vulkan` +
   `imgui_impl_win32` (Windows window) and `imgui_impl_sdl3` (macOS window), vendored (MIT).
2. **A draw slot on the present path.** `render/vk_render.cpp` presents with `vkCmdBlitImage` onto the swapchain image
   (plus the `RT_ROTATE` graphics pass). An overlay needs a render pass that loads the swapchain image after the blit and
   draws the ImGui lists on top, on the presenting thread (Win32: the pump lives inside guest presents; macOS: SDL's
   main thread owns events, the guest thread presents). One new pipeline, descriptor pool and font texture.
3. **Input arbitration.** Keyboard-as-pad on Windows is `GetAsyncKeyState` polled by its own thread in
   `shell/gen/stubs.cpp`, not window messages; on macOS it is the SDL event word. While the overlay is open the pad
   poller must see no keys (one atomic "overlay owns input" flag read by both arms), XInput/SDL pads likewise, and
   the overlay must get its keys from WndProc / the SDL event pump.
4. **Live-apply semantics.** Almost every lever is read once (function-local statics; another w1107 lane is caching
   the rest). So the screen saves to `futari.ini` and says "applies at the next start", except what can be applied
   live without touching the cached reads: fullscreen (the F11 path), maybe vsync (swapchain recreate already exists).

## Phases and estimate

| phase | content | new/adapted lines | lane time | risk |
|---|---|---|---|---|
| A | vendor ImGui; overlay pass on the present path (Win32 + SDL arms, rotate-aware); F2 toggles it; input gate | ~700-900 new | 2-3 days incl. a Mac seat | present-path change: pacing and audio gates must be re-run (rc census, gstart, q1); MoltenVK |
| B | settings screen: the futari.ini keys (window size, fullscreen, vsync, rotate, keyboard, sink, save folder), saved through `ini_merge.h`, "next start" banner; live fullscreen | ~500 adapted | 1-2 days | low once A is in |
| C | first-run setup inside the exe: `game_source.cpp` + a SHA-256 manifest check + derived copies + the recomp import, replacing the Python wizard (no Python needed) | ~1,100 adapted | 2-3 days | medium: the manifest/derived rules must stay byte-identical to `futari_extract.py` (diff both on the same dumps) |

Total: about 2,300-2,500 lines, 1 to 1.5 weeks of one lane plus a full re-gate on both seats, because phase A changes
the present path every frame goes through. Phase B alone is not possible without A (there is no text renderer; this
window was told not to build one into `vk_render.cpp`).

## Recommendation for the owner

A and B together are the useful unit (a settings screen); C is what removes Python from the first run, which is the
larger player-facing win on Windows. If only one is funded, C has more value than B: the settings that matter are few
and `Settings.bat` / the ini already cover them, while "install Python first" is the main first-run obstacle.
