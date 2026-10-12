#!/bin/bash
# rc_stagepix_lock_mac.sh <tag> <pilot_bin> <control_bin> -- scripts/stagepix_mac.sh under the drive lock with its own seeded save (stagepix/nav_mac.sh take neither).
cd "$(dirname "$0")/.."; LOCK=/tmp/futari_drive.lock; w=0
until mkdir "$LOCK" 2>/dev/null; do sleep 60; w=$((w+60)); done
while pgrep -x futari_merged >/dev/null; do sleep 30; done
trap 'pkill -x "$(basename "$2")" "$(basename "$3")" 2>/dev/null; rmdir "$LOCK" 2>/dev/null' EXIT
echo "lockwait=${w}s"; export RT_SAVE="_local/saves/q5c_sp_$1"; rm -rf "$RT_SAVE"; cp -R _local/saves/save_rc1_rc1m_arcade "$RT_SAVE"
bash scripts/stagepix_mac.sh "$@"
