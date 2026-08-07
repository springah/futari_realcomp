#!/usr/bin/env python3
"""Ship-gate progress: how much of the work the PORT actually needs is matched.

`ppcmatch.py` answers "is this function exact?" and the board answers "how much of the image is
matched?" -- 0.58% at the time of writing.  Neither answers the question that decides whether the
port ships, because the board's denominator is all 3,492,516 code bytes and almost none of that is
work anybody needs to do.  This does.

THREE DENOMINATORS, measured 2026-08-05, in increasing order of usefulness:

  whole image        873,129 insn   the board's denominator.  Misleading: 36% of matched
                                    instructions are compiler boilerplate (scalar deleting
                                    destructors, vcall thunks) that the port never needed, and the
                                    223 targets come from only 46 unique bodies.
  registry            ~26,000 insn  decomp/registry.toml -- 247 functions already identified as
                                    mattering (3.1% of the image).  ASM-EXACT covers 494 of those
                                    instructions across 16 functions: ~2% done.
  SHIP GATE              963 insn   the nine functions below.  This is the number to track: the
                                    user's ruling is "nothing ships until menus/shell is done",
                                    and these are the functions that decides.

Run it with no arguments.  Anything not yet at 100% is remaining gate work.
"""
import json
import os
import re
import subprocess
import sys

import ppcmatch as pm

# The gate: BACKLOG.md "NOW" item 0 (the compose/flicker lane) plus the parked compose family.
# `src` None means no source exists yet -- greenfield, and the whole body is remaining.
# (name, module, addr, insn, src, role, symbol) -- symbol defaults to name when None.
GATE = [
    ("Compose_Root",           "shell", 0x821CDBE8, 81,
     "src/shell_821CDBE8_CRscBankMgr_ctor.cpp",
     "compositor family root -- BACKLOG NOW item 0, the flicker lane", "??0CRscBankMgr@@QAA@XZ"),
    ("Compose_Veil",           "shell", 0x82182A68, 89,
     "src/shell_82182A68_Compose_Veil.cpp", "compose veil", None),
    ("Page_Bake",              "game",  0x8808DC10, 216, "src/game_8808DC10_Page_Bake.cpp",
     "bake+paste the scroll-backdrop pages"),
    ("Sprite_FlushBatch",      "game",  0x8808E468, 169, "src/game_8808E468_Sprite_FlushBatch.cpp",
     "flush the sprite batch"),
    ("Render_SelectBlend",     "game",  0x88070000, 171, "src/game_88070000_Render_SelectBlend.cpp",
     "blend-mode select from the packed render-state word"),
    ("Sprite_EmitQuad",        "game",  0x8808E298, 116, "src/game_8808E298_Sprite_EmitQuad.cpp",
     "emit one sprite quad"),
    ("Page_EnsureTexture",     "game",  0x8808D838, 50,  "src/game_8808D838_PageEnsureTexture.cpp",
     "guarantee a page has a live texture of the requested size"),
    ("Root_Join",              "shell", 0x821CE400, 46,  "src/shell_821CE400_Root_Join.cpp",
     "root task join: pick the next root state"),
    ("Driver_SendStageRecord", "shell", 0x821C2D68, 22,  "src/shell_driver_msgs.cpp",
     "msg 20, hand over the stage record (x8 clones = 176 insn)"),
]
GATE = [g if len(g) == 7 else (*g, None) for g in GATE]


def score(module, addr, symbol, src, insn, flags=("-O2", "-Oc")):
    """(matched_words, total, exact) for one gate entry; (0, insn, False) if there is no source."""
    if src is None or not os.path.exists(os.path.join(pm.HERE, src)):
        return 0, insn, False
    r = subprocess.run(
        [sys.executable, "ppcmatch.py", "--check", module, f"0x{addr:08X}", symbol, src,
         "--insn", str(insn), "--flags", " ".join(flags)],
        capture_output=True, text=True, cwd=pm.HERE)
    out = (r.stdout + r.stderr).strip().splitlines()
    line = out[-1] if out else ""
    if line.startswith("EXACT"):
        return insn, insn, True
    m = re.search(r"same=(\d+)/(\d+)", line)
    return (int(m.group(1)), int(m.group(2)), False) if m else (0, insn, False)


def main():
    print(f"{'function':<24}{'module':<7}{'matched':>12}  {'%':>5}  role")
    print("-" * 100)
    done = total = exact = 0
    open_fns = 0
    for name, module, addr, insn, src, role, symbol in GATE:
        k, n, is_exact = score(module, addr, symbol or name, src, insn)
        done += k
        total += n
        exact += is_exact
        open_fns += not is_exact
        mark = "EXACT" if is_exact else ("--" if src is None else "")
        print(f"{name:<24}{module:<7}{k:>6}/{n:<5} {k/n*100:>5.0f}%  {role}  {mark}")
    print("-" * 100)
    print(f"{'SHIP GATE':<24}{'':<7}{done:>6}/{total:<5} {done/total*100:>5.1f}%   "
          f"{exact}/{len(GATE)} functions exact")
    print(f"\nremaining: {total - done} instructions across {open_fns} functions")
    print("\nNote: a partial score is NOT partial credit -- a function counts for the port only when\n"
          "it is exact. The per-function percentages are progress indicators, not delivered work.")


if __name__ == "__main__":
    main()
