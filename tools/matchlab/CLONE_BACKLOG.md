# Clone backlog — where the unclaimed instructions actually are

Generated 2026-08-07 from `python clones.py --all --min-insn 3`, ranked by
`insn x unclaimed_copies`. Regenerate it rather than trusting these numbers after any promotion:

```bash
python clones.py --all --min-insn 3
```

**124 families. 13,971 instructions sit in families with no ASM-EXACT member.**

⚠ **"UNCLAIMED" MEANS "NO EXACT MEMBER", NOT "UNSTARTED".** `clones.py` reads `functions.json`,
which only ever holds ASM-EXACT rows, so a family that is 90% decompiled and one instruction from
exact looks identical to greenfield. The two biggest shell families are both in that state — do
not open them as if they were new work:

| value | family | reality |
|---|---|---|
| 904 | 113 x 8, shell 0x821C30B8 | `Driver_Init`, **66/112**, `src/shell_821C30B8_Driver_Init.cpp`. Five source shapes ruled out and byte-identical; the file says attack it with ALLOCATOR.md, not syntax. |
| 176 | 22 x 8, shell 0x821C2D68 | `Driver_SendStageRecord`, **16/22**, a SHIP-GATE entry in `shell_driver_msgs.cpp`. 17/22 exists via `volatile` casts and was REFUSED on purpose (2026-08-05) — do not "rediscover" it. |

## The genuinely unstarted value, all of it in the game module

| value | shape | first address | notes |
|---|---|---|---|
| 579 | 193 x 3 | game 0x881EEEC0 | biggest unstarted body on the board |
| 422 | 211 x 2 | game 0x8819A450 | |
| 406 | 203 x 2 | game 0x880AA438 | |
| 324 | 108 x 3 | game 0x8821DAC8 | |
| 288 |  72 x 4 | shell 0x82070018 | the one unstarted shell family of size |
| 282 |  94 x 3 | game 0x8815A470 | |
| 272 | 136 x 2 | game 0x881904C8 | |
| 268 | 134 x 2 | game 0x880A79E0 | |
| 245 |  49 x 5 | game 0x880BD4B8 | **best ratio in the table** — 49 insn buys 245 |
| 236 | 118 x 2 | game 0x880CBB10 | |
| 236 | 118 x 2 | game 0x881E9F58 | |
| 214 | 107 x 2 | game 0x88190E00 | |
| 213 |  71 x 3 | game 0x880D50B0 | |

Then a long tail of 2-3 copy families in the 150-210 range, and ~100 families under 150.

⚠ The memory note "the GAME module has no clone families" is **wrong** and should not be carried
forward — game holds nearly all of the unstarted value. (Shell is where the *matched* clones are,
which is probably where that impression came from.)

## Picking from this table

Ratio, not total: a 49 x 5 family is one 49-instruction decompilation for 245 instructions of
board, where 193 x 3 is four times the work for twice the return. Two rules from the 08-05 sweep
still apply and are cheap to try first on any family here:

* **Audit the RESOLVED reloc targets before promoting a clone.** `clones.py` normalises outbound
  call displacements, which is sound (our obj has a reloc there and `equal_modulo_relocs` masks
  it) but means two copies calling *different* functions can look identical until you check.
* **When a family is a few instructions short of a shape you already match, try the other flag
  set first** — the `-O1` destructor family was exactly that.

And run `python ppcmatch.py --selftest` after touching the tooling: `clones.py` v1 emitted two
false EXACTs, and the self-test is the positive control that caught them.
