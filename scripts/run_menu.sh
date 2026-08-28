#!/bin/bash
# Futari FRONT-END baseline — boots to a CLEAN, STABLE TOP MENU (verified 2026-07-11).
# FIXED IN-BINARY 2026-07-11 (rt.cpp): RVK_RINGFULL's kick-capture (103ba59) is now gameplay-
# scoped on the game-field flag 0x885C1A20, so the shell/front-end uses the legacy window
# automatically and the menu renders clean with ALL RENDERER DEFAULTS — no RVK_RINGFULL=0
# override needed anymore. (Bisect had shown RINGFULL was the sole front-end-regression cause;
# it drops the menu-item gold panels + streaks the dialog when applied to shell frames.)
# For A/B: RVK_RINGFULL_ALL=1 forces the old always-on capture; RVK_RINGFULL=0 forces legacy.
cd "$HOME/xr-work" || exit 1
export DISPLAY="${DISPLAY:-:1}"
pkill -9 -x futari_merged 2>/dev/null; sleep 0.3
RT_GAME_ROOT="$HOME/xr-work/assets" \
VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json \
RT_BOOT_SHELL=1 RT_THREADS=1 RT_DEFERDRIVER=1 RT_ASYNCIO=1 RT_EHCONTAIN=1 RT_AUDIOPUMP=1 \
RT_VK=1 RVK_PERSIST=1 RVK_RENDER_FROM=1 RVK_NOHALVE=1 RVK_FIXVP=1 RVK_REALALPHA=1 RVK_BLEND=1 \
RT_PAD=1 RT_NAV_SEQ="0:START,5000:A,8000:A,11000:A" RT_PAD_HOST=1 \
# RT_NOPAUSE=1 below is HARNESS-ONLY, NEVER SHIP (w50 adjudication D7: ship default is env-unset = the authentic pause, w45-measured; np1 exists because an unattended leg cannot press RESUME and the orphaned post-run pause -- w47, never rare -- would wedge every leg)
RT_SNDQFREE=1 RT_NOPAUSE=1 RT_RESCACHE=1 RT_HEAPLOCK=1 \
RT_SAMPLES=100000 \
./futari_merged 8208A2B8 0 shell/default.xex >/tmp/futari_menu.log 2>&1 &
sleep 0.6
feh --title "Futari TOP MENU (clean front-end)" --reload 0.15 --zoom fill -g 1280x720 /tmp/rvk_last.png 2>/dev/null
pkill -9 -x futari_merged 2>/dev/null
