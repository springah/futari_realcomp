# decomp/ — the human-readable matching-decomp tree

This tree holds hand-written, behavior-matching C++ that progressively displaces the
recompiled PPC bodies (UnleashedRecomp model). **Governing doc:**
`../../ghidra_futari_decomp/HUMAN_READABLE_DECOMP_PLAN.md` — read it before adding anything
here; its conventions (naming, layout, replacement mechanics, gates) are binding.
Function knowledge router: `../../ghidra_futari_decomp/ATLAS_INDEX.md` (extend, never re-derive).

## Layout

- `game/`  — 0x88 module (game/ROM, `reco_normal.img.bin`). Subsystem folders per plan §1:
  `scene/ select/ asset/ save/ input/ audio/ gameplay/ entry/` (created as first files land).
- `shell/` — 0x82 module (shell/frontend, `default.img.bin`): `task/ menu/ driver/ d3d/ xact/`.
- `registry.toml` — the function registry: one `[[fn]]` per guest function, seeded from the
  243-function named census in ATLAS_INDEX.md §1.

## Status ladder (plan §2)

```
RAW        recomp only — nothing known beyond the generated PPC body
NAMED      atlas role known (all 243 seeded entries start here)
DRAFT      human C written, not yet gated       (plan calls this DRAFT; "TRANSLATED" is the
                                                 same rung in older campaign notes)
ASM-EXACT  the C compiles to the original's instruction bytes under the period-correct
           compiler (XDK 9328) — proof of TRANSLATION fidelity, but not linked and not run
MATCHED    passed its per-function acceptance gate, linked in via first-definition-wins
LOCKED     shipped in a build users actually ran
```

Gate per function, never per subsystem (plan §3.3). Two consecutive gate failures ⇒ back to
DRAFT and re-rank (the 07-26 two-ship-nothing rule).

**ASM-EXACT is a separate axis from MATCHED, and `registry.toml` stays BEHAVIOURAL.** Its
`status` field only ever holds RAW/NAMED/DRAFT/MATCHED/LOCKED — the same meanings as before.
ASM-EXACT is recorded in `../matchlab/functions.json`, and a registry row cross-references it
with the optional `asm_exact` / `matchlab` fields. The two rungs answer different questions:

| | asks | evidence | cost |
|---|---|---|---|
| ASM-EXACT | is this C the same *program* the original was? | SHA1 over instruction bytes | < 1 s, offline |
| MATCHED | does the port still behave right with this linked in? | scripted drive + gate | ~an evening |

A function can be ASM-EXACT without being MATCHED (nothing is linked yet) and MATCHED without
being ASM-EXACT (`GameEntry_Dispatch`, which is a `PPC_FUNC` ctx-shaped body, not natural C++ —
there is nothing for the 9328 compiler to compare it against). Neither implies the other; the
ladder order above reflects increasing *total* evidence, not a required path.

## Rules inherited from the plan

- Match-first, no fudge factors: constants cite a guest address.
- decomp/ stays OUTSIDE the generated trees (regen clobbers hand edits).
- A rewritten fn displaces the generated body by winning the link, but the SHAPE depends on
  whether the function is already hooked. Unhooked: `PPC_FUNC(sub_XXXXXXXX)` (strong beats the
  generated weak alias). Already carrying a strong `PPC_FUNC(sub_XXXXXXXX)` instrument hook in
  `out_reco/merged/`: use `PPC_FUNC_IMPL(__imp__sub_XXXXXXXX)` instead, so the hook keeps its
  strong definition and the translation displaces the GENERATED body underneath it — a second
  strong definition would either kill the instrument or be silently dead. (This is the C1
  shadowed-hook landmine; see decomp/game/PILOT_NOTES.md §2.) Either way the object links BEFORE
  the generated one, and dropping it from the link = instant rollback.
- Never change a callee's observable contract while callers are still generated.
- Pilot (plan §5): GameEntry msg 12/13/14 slice + mailbox consumers, gated on RT_QDIAG/[navreal]
  transition-log equality.
