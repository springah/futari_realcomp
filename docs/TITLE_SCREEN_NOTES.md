# Title screen — WORKING (2026-07-08)

The shell title screen (虫姫さまふたり logo, sky bg, silhouettes, ©CAVE, white outline)
renders correctly, matching the SDK. Screenshot: `futari_titlescreen_2026-07-08.png`.

## Working run config
```sh
RT_GAME_ROOT=/home/shant/xr-work/assets \
VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json \
RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1 RT_GAMEPUMP=1 \
RT_VK=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_REALALPHA=1 RVK_BLEND=1 \
./futari_merged 8208A2B8 0 shell/default.xex
```
(No game-forcing levers, no RT_PAD — the shell boots and holds the title.)

## The 3 renderer fixes (all new env levers, default-OFF, in render/vk_render.cpp)
1. **RVK_NOHALVE** — skip the clip-range `halvePosRows` matrix-halving. The halving + doubled
   `currentViewport()` is a fix for content mapping to ndc[0,2] (replay/gameplay panel); the
   shell TITLE authors its matrix to ndc[-1,1] already, so halving shrank it to the top-left
   quadrant. Skipping it + FIXVP maps the title 1:1 to the full 1280x720.
2. **RVK_FIXVP** — pin the VkViewport to {0,0,kW,kH} instead of the doubled clip-fix viewport.
3. **RVK_REALALPHA** — use the texture's TRUE stored alpha instead of the luminance-key trick
   (A0 ? A0 : max(RGB)). The trick turned the logo's WHITE transparent padding into an opaque
   white box; real alpha lets the sky show through.
4. **RVK_BLEND** — honor the guest per-draw blend (RB_BLENDCONTROL 0x2201). The title's white
   glow/outline is 10 additive draws (0x01060106 = SRC_ALPHA/ONE); the hardcoded alpha blend
   dimmed them. Now bright, matching the SDK. Also added RVK_DUMPTEX (dump decoded textures).

## KNOWN: these are TITLE-tuned. NOHALVE/FIXVP are global levers that fit the title's ndc[-1,1]
## matrix but likely break scenes that map to ndc[0,2] (menu/gameplay). A proper multi-scene
## boot needs per-draw/auto transform selection, not global levers.

## Title -> menu blocker (open)
After the title, START -> save-data flow: [devsel] (XamShowDeviceSelectorUI type=0x1) +
XamContentCreateEnumerator (finds 1 save, items=1) -> STUCK on a "しますか？(Yes/No)" save
dialog, never reaches the TOP MENU. Menu/dialog scenes also render black-bg + mis-positioned
top-left (menu transform differs from title).

## DLC (missing from merged assets)
merged assets/media has the 8 base modes (reco/kiniro/palm/hirow x normal/abnormal .xex) but
NO dlc. The DLC lives at ~/Desktop/SHARED/Mushihimesama-Futari-Deck/dlc/:
  496F816DD4B53DAEFF931838B6C69831AAD7663043 (277MB = Black Label)
  9893A78CA6062B935BD1F53EA43CFD546B7246DF43 (57KB  = Ver1.01?)
