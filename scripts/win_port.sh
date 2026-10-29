#!/bin/bash
# win_port.sh -- (re)generate the Windows gate scripts from their Mac originals. The Mac scripts are the source of truth; the
# Windows copies differ only by (1) sourcing scripts/win_shim.sh (pkill/pgrep/ps/md5 shims), (2) the launcher (run_win.sh),
# (3) /tmp -> /c/tmp for the FIFO / drive lock / arm files. Anything else that needs to differ belongs in the shim or run_win.sh.
#   bash scripts/win_port.sh        -> scripts/{gstart,rc_census,rc_chain,q7v_run}_win.sh (committed; regenerate after editing a Mac original)
set -u
cd "$(dirname "$0")/.."
for pair in gstart_mac:gstart_win rc_census_mac:rc_census_win rc_chain_mac:rc_chain_win q7v_run:q7v_run_win; do
  src="scripts/${pair%%:*}.sh"; dst="scripts/${pair##*:}.sh"; [ -f "$src" ] || { echo "no $src"; exit 1; }
  { sed -n 1p "$src"
    echo "# WINDOWS PORT -- generated from $src by scripts/win_port.sh ($(date +%F)); edit the Mac original and regenerate. Differences: win_shim.sh"
    echo "# (pkill/pgrep/ps/md5), run_win.sh as the launcher, /c/tmp for the FIFO + drive lock. Engine copy: a uniquely named .exe beside the module DLLs."
    sed -n '2,$p' "$src" \
      | sed -e 's|scripts/run_mac\.sh|scripts/run_win.sh|g' \
            -e 's|/tmp/|/c/tmp/|g' \
            -e '0,/^set -u$/s|^set -u$|set -u\nsource "$(dirname "$0")/win_shim.sh"   # Windows: pkill/pgrep/ps/md5 shims, /c/tmp|'
  } > "$dst"
  bash -n "$dst" || { echo "syntax error in $dst"; exit 1; }
  echo "wrote $dst ($(wc -l < "$dst") lines; $(grep -c '/c/tmp/' "$dst") /c/tmp refs; shim: $(grep -c win_shim "$dst"))"
done
