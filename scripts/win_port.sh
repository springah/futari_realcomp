#!/bin/bash
# win_port.sh -- (re)generate the Windows gate scripts from their Mac originals. The Mac scripts are the source of truth; the
# Windows copies differ only by (1) sourcing scripts/win_shim.sh (pkill/pgrep/ps/md5 shims), (2) the launcher (run_win.sh),
# (3) /tmp -> /c/tmp for the FIFO / drive lock / arm files. Anything else that needs to differ belongs in the shim or run_win.sh.
#   bash scripts/win_port.sh        -> scripts/{gstart,rc_census,rc_chain,q7v_run}_win.sh (committed; regenerate after editing a Mac original)
set -u
cd "$(dirname "$0")/.."
# w1107 (2026-11-07, WIN-MODULES lane): the module gate chain joins -- nav_mac -> kiniro_boot_mac -> mod_gate_mac, and
# mod_swap_mac. Extra rewrites for that chain only (MODCHAIN): the callee scripts' _mac names -> _win, the engine log glob
# _local/logs/mac_*.log -> win_*.log (run_win.sh's name), the Mac private root _local/blroot -> assets (run_win.sh pins
# RT_GAME_ROOT=assets; the Ver 1.01 / Arrange / Novice data is on the disc dump), the Mac gate save _local/saves/save_mac ->
# the repo's save_freshcard (bl_boot_win.sh's), the PIX-REGRESS reference dir _local/kiniro/ref -> ref_win (a Windows frame
# is never scored against a Mac reference), and `grep` -> `grep -a` (the Windows guest log is stderr and may carry stray
# binary bytes; GNU grep would then print "Binary file matches" instead of the line). Banks stay _local/nav_mac/<tag>
# (kiniro_pix.py / stagepix_mac.py read that path).
#   bash scripts/win_port.sh [src:dst ...]   (default: every pair)
PAIRS="gstart_mac:gstart_win rc_census_mac:rc_census_win rc_chain_mac:rc_chain_win q7v_run:q7v_run_win nav_mac:nav_win kiniro_boot_mac:kiniro_boot_win mod_gate_mac:mod_gate_win mod_swap_mac:mod_swap_win"
[ $# -gt 0 ] && PAIRS="$*"
for pair in $PAIRS; do
  src="scripts/${pair%%:*}.sh"; dst="scripts/${pair##*:}.sh"; [ -f "$src" ] || { echo "no $src"; exit 1; }
  case "$pair" in nav_mac:*|kiniro_boot_mac:*|mod_gate_mac:*|mod_swap_mac:*) MODCHAIN=1;; *) MODCHAIN=0;; esac
  { sed -n 1p "$src"
    echo "# WINDOWS PORT -- generated from $src by scripts/win_port.sh ($(date +%F)); edit the Mac original and regenerate. Differences: win_shim.sh"
    echo "# (pkill/pgrep/ps/md5), run_win.sh as the launcher, /c/tmp for the FIFO + drive lock. Engine copy: a uniquely named .exe beside the module DLLs."
    sed -n '2,$p' "$src" \
      | sed -e 's|scripts/run_mac\.sh|scripts/run_win.sh|g' \
            -e 's|/tmp/|/c/tmp/|g' \
            -e '0,/^set -u$/s|^set -u$|set -u\nsource "$(dirname "$0")/win_shim.sh"   # Windows: pkill/pgrep/ps/md5 shims, /c/tmp|' \
      | if [ "$MODCHAIN" = 1 ]; then
          sed -e 's|scripts/nav_mac\.sh|scripts/nav_win.sh|g' -e 's|scripts/kiniro_boot_mac\.sh|scripts/kiniro_boot_win.sh|g' \
              -e 's|_local/logs/mac_\*\.log|_local/logs/win_*.log|g' -e 's|_local/blroot|assets|g' \
              -e 's|_local/saves/save_mac|save_freshcard|g' -e 's|_local/kiniro/ref/|_local/kiniro/ref_win/|g' \
              -e 's/\([^a-z]\)grep /\1grep -a /g'
        else cat; fi
  } > "$dst"
  bash -n "$dst" || { echo "syntax error in $dst"; exit 1; }
  echo "wrote $dst ($(wc -l < "$dst") lines; $(grep -c '/c/tmp/' "$dst") /c/tmp refs; shim: $(grep -c win_shim "$dst"))"
done
