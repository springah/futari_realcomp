#!/bin/bash
# persist_coop_mac.sh <tag> <arcade|x360>  -- RC1 Q4 co-op smoke leg (persist_mac.sh steps; P2 via the RT_PAD_FIFO 4th field).
# hub -> NORMAL PLAY -> 1P SIDE START -> mode select -> char select; P2 START (join, [joinp] WILL-JOIN) -> dual selects -> stage 1, 20 s,
# pause EARLY (~11 s: idle ships die ~20-28 s in the 360 module -> CONTINUE? screen, where START = continue not pause), resume, pause again, RETURN TO TITLE. arcade proven 10-12 (_local/rc1/q3/A_p4); x360 NOT yet run (lock starvation) -- run it first thing.
cd "$(dirname "$0")/.."; TAG="${1:?tag}"; MODE="${2:?arcade|x360}"
export SEED="_local/saves/save_rc1_rc1m_$MODE" SAVE="_local/saves/q3_coop_$TAG" JOINP=1
exec bash scripts/persist_mac.sh "$TAG" "$MODE" -- sd:before boot_hub \
 2 1000 s:3 1000 s:3 1000 s:3 shot:coop_char p2:10 'log:joinp\|WILL-JOIN\|P2 buttons' s:2 shot:coop_joined \
 1000 s:2 shot:c1 p2:1000 s:2 shot:c2 1000 s:2 shot:c3 p2:1000 s:8 shot:coop_stage1 'log:joinp\|WILL-JOIN\|P2 buttons' s:3 shot:coop_stage11 \
 10 s:2 shot:coop_pause 1000 s:1.5 shot:coop_resumed 10 s:2 shot:coop_pause2 2 s:1 2 s:1 2 s:1 1000 s:2 shot:rtt_confirm 1000 s:8 shot:coop_back sd:after
