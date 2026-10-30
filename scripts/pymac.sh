#!/bin/bash
# pymac.sh -- source this to get $PYTHON = an interpreter that has numpy + Pillow (the gate scorers need both).
# 2026-10-30 landmine: Homebrew `python3` on the Mac moved to 3.15 without numpy/PIL, and the gate ladder's bare
# `python3` calls crashed (stagepix_mac.py, boss_plate_gate.py) after their drives had run. Candidates are tried in
# order; PYTHON= in the environment wins. Works on Windows Git Bash too (falls back to python3 / python).
#   source scripts/pymac.sh; "$PYTHON" scripts/stagepix_mac.py compare ...
if [ -z "${PYTHON:-}" ]; then
  for _p in python3.13 python3.14 python3.12 python3.11 python3 python; do
    if command -v "$_p" >/dev/null 2>&1 && "$_p" -c "import numpy, PIL" >/dev/null 2>&1; then PYTHON="$_p"; break; fi
  done
  [ -n "${PYTHON:-}" ] || { echo "pymac.sh: no python with numpy + Pillow found (tried python3.13 .. python); set PYTHON=" >&2; PYTHON=python3; }
fi
export PYTHON
