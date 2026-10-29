# win_shim.sh -- sourced by the *_win.sh gate scripts (generated from the *_mac.sh originals by scripts/win_port.sh).
# Bash functions shadow the four macOS/BSD commands the Mac gates use, so the gate logic itself runs unchanged under Git Bash:
#   pkill -x <name>        -> taskkill /F /IM <name>         (the gates name their engine copy uniquely, e.g. rcwin_eng.exe)
#   pgrep -x <name>        -> Windows pids of <name>; "futari_merged" (the Mac user-play name) maps to futari_combined.exe, the
#                             image the Windows launcher .bat runs, so "the user is playing" still blocks a gate
#   ps -o rss= -p <pid>    -> WorkingSet64/1024 (KB, like BSD ps rss) via PowerShell; <pid> may be an MSYS pid ($! of a native
#                             child, mapped through `ps -p` WINPID) or a Windows pid (from the pgrep shim)
#   md5 -r <files>         -> md5sum, "hash path" per line (only ever compared against itself)
# Paths: the gates keep their FIFO / lock / dump files under /c/tmp (Git Bash converts a /c/... value in an exported variable to
# C:/... for the native exe, so the SAME string serves bash writes and the engine's fopen). Never set MSYS_NO_PATHCONV here.
mkdir -p /c/tmp
# scripts/winbin holds EXECUTABLE twins of the shims that must also work under `find -exec` (a bash function is invisible there): md5.
export PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/winbin:$PATH"
pkill(){ local name="${2:-$1}"; [ "$1" = -x ] && name="$2"; taskkill //F //IM "$name" >/dev/null 2>&1; return 0; }
pgrep(){ local name="${2:-$1}"; [ "$1" = -x ] && name="$2"; [ "$name" = futari_merged ] && name=futari_combined.exe
  tasklist //FI "IMAGENAME eq $name" //FO CSV //NH 2>/dev/null | tr -d '\r' | grep -i "^\"$name\"" | awk -F'","' '{print $2}' | grep .; }
ps(){ local pid="" ; while [ $# -gt 0 ]; do case "$1" in -p) pid="$2"; shift;; esac; shift; done
  [ -n "$pid" ] || { command ps; return; }
  local win; win=$(command ps -p "$pid" 2>/dev/null | awk 'NR==2{print $4}'); [ -n "$win" ] || win="$pid"
  # tasklist (~0.2 s) not PowerShell (~1-2 s): the census samples RSS every minute and scores the frame delta per sample, so the probe must be quick
  tasklist //FI "PID eq $win" //FO CSV //NH 2>/dev/null | tr -d '\r' | grep -i '^"' | awk -F'","' '{gsub(/[^0-9]/,"",$5); print $5}' | grep .; }
md5(){ [ "${1:-}" = -r ] && shift; md5sum "$@" | sed 's/ \*/ /;s/  / /'; }
