#!/bin/bash
# Futari — flip through the captured front-end screens (title / TOP MENU+DLC / in-game menu).
# Use the ← / → arrow keys to move between them; Esc or q to close.
export DISPLAY="${DISPLAY:-:1}"
cd "$HOME/xr-work" || exit 1
feh --title "Futari — captured screens (use ← / → arrows, q to close)" \
    -g 1280x720 --zoom fill \
    futari_titlescreen_2026-07-08.png \
    futari_topmenu_dlc_2026-07-08.png \
    futari_ingame_menu_2026-07-08.png 2>/dev/null
