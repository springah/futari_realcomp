#!/bin/bash
# stagepix_mac.sh <tag> <pilot_bin> <control_bin> -- the STAGE PIXEL GATE on the Mac (ladder rung "stagepix").
# Drives each arm through the proven Normal Play route (HUB > NORMAL PLAY > 1P SIDE START > Original > Reco >
# Normal shot > stage 1) with the renderer dumping every 20 frames, dwells 12 s in the stage, then scores the
# last 6 frames' playfield richness pilot vs control (scripts/stagepix_mac.py). ~70 s per arm.
#   bash scripts/stagepix_mac.sh sp1 build/plate_final_pilot build/plate_final_control
set -u
cd "$(dirname "$0")/.."
source "$(dirname "${BASH_SOURCE[0]}")/pymac.sh"   # $PYTHON = a python with numpy + Pillow (10-30 landmine)
TAG="${1:?tag}"; PB="${2:?pilot bin}"; CB="${3:?control bin}"
for arm in control pilot; do
  bin=$([ "$arm" = control ] && echo "$CB" || echo "$PB")
  NVKPNG=20 RUN_SECS=110 bash scripts/nav_mac.sh "sp_${TAG}_$arm" "$bin" -- hub 2 's:0.5' 1000 's:3' 1000 's:3' 1000 's:3' 1000 's:3' 1000 'w:m02_stg' 's:12' shot 2>&1 | grep "DONE\|TIMEOUT" | cut -c1-80
done
"$PYTHON" scripts/stagepix_mac.py compare "sp_${TAG}_pilot" "sp_${TAG}_control"
