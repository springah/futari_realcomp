# The MSVC 15.00.8327 PowerPC nonvolatile allocation rule

Derived 2026-08-05 by controlled experiment (five independent probes + a synthesis pass), because
eight functions were blocked with **every instruction present and correct** and only the choice of
which nonvolatile held which value differing. Per-function source sweeps came back FLAT every
time — and this document explains why they had to.

Scope: GPR nonvolatiles r19-r31, `-O2`, cl 15.00.8327 for PowerPC. FPR/VMX, other `-O` levels and
actually-spilling functions are untested.

## The rule

The allocator computes one scalar priority per live range, sorts descending, and hands out
`r31, r30, r29 …` contiguously downward. Priority has **two regimes**, and the regime switch is
the whole story:

**Step 0 — partition.** For each value ask: *does its live range cross a basic-block boundary*
(a branch or a join)? **Calls do not split blocks** for this purpose — a value live across three
calls inside one block is still local.

* **GLOBAL** (crosses a branch): ranked by **loop-weighted reference count, descending**.
* **BB-LOCAL** (born and dies in one block): **reference count is ignored entirely.**
  Rank = **source declaration order**, earliest declaration takes the higher register.
* **Every global outranks every local**, regardless of count.

**Step 1 — weights (globals only).** Every machine reference counts 1 — defs and reads alike, a
read-modify-write counts twice. A reference at loop depth *d* is worth **~2^d**. It is **~2× per
level, not 4×/10×/11×**.

**Step 2 — tie-break among equal-scoring globals:** order of **definition** (assignment) in the
stream. Declaration order is inert in the global regime.

**Step 3 — rematerializable constants get no register at all** (`li rX,k` re-emitted per use). A
constant occupies a nonvolatile only when it is a **variable the function carries**, not a
constant the function spells repeatedly. Two shapes are known to qualify:
* the init of a **loop-carried accumulator** (Page_Bake's paste cursor, r30);
* a **single-exit result variable** — one `u32 result = 0;` at the top, assigned `1` on the
  success path, returned once at the bottom (Page_EnsureTexture, r26).

This distinction is worth more than it looks. On Page_EnsureTexture the image's zero is used
by both `tbl[tex] = 0` and the `return 0` exit, and *every* attempt to spell that as a shared
local (`u32 zero = 0;` in eight declaration positions, used in both places, and for the call's
literal-zero arguments as well) left the function one instruction short at 3/50 — MSVC
constant-propagates and rematerialises each use. Rewriting the control flow so the zero became
a carried `result` produced `li r26,0` in the entry block, grew the frame to save r26, and took
the function to 28/50 with both ends byte-identical. **If the image holds a constant in a
nonvolatile, look for a control-flow reason, not a spelling.**

**Step 3b — LOOP-FREQUENCY WEIGHT IS ASSIGNED EARLY AND SURVIVES THE LOOP'S DELETION.**
⚠ *This started life as "references inside a loop-bearing `__forceinline` inlinee are
rank-discounted", derived from Page_Bake. A review pass the same evening showed that framing is
WRONG — inlinee membership is not the mechanism. Corrected below; the Page_Bake result stands, its
explanation does not.*
Measured on `Page_Bake` 2026-08-05 (144 → 161/216, the single largest jump that function has
had). Moving the paste loop bodily into a `static __forceinline` helper and calling it from
inside the guard changed **no instruction and no reference count** — and rewrote the register
map: the perennial zero rose to r30 (the image's rank 2), `bakeX` to r29, and the float-pool base
fell to r28. Three constraints found with it:

* **The inlinee must contain a loop.** A straight-line inlinee gives NO discount (measured, inert).
* **`__forceinline` is mandatory, not cosmetic.** This `cl` refuses to auto-inline a looping
  callee — plain `static` / `static inline` / `inline` all leave the call outlined (166 insn, 1/216).
* **Nesting does not stack.** A helper inside a helper scores the same; but two *distinct* nested
  guards do compound (a second guard pushed the pool to r27, at the cost of 3 extra instructions).

This is the same family as block frequency (item 4 below): the allocator discounts a reference by
where it sits, not just how often it appears. It is the second confirmed source-level lever on
rank, and unlike block frequency it is **free** — no extra instruction.

**WHAT ACTUALLY GENERALISED — and it is not the inlinee.** On `Sprite_EmitQuad` (no loop at all,
so Step 3b as first written did not even apply) writing the three quad corners as per-corner
tables plus a **countable** `for (k = 0; k < 3; ++k)` moved the map two words closer — and MSVC
**fully unrolls that loop back to the identical 116 instructions**. The loop is not in the output.
So the frequency weight is computed while the loop still exists and is not recomputed after the
structure is erased. Constraints measured: `k < 3` is mandatory (`k != 3` defeats the unroller,
132 insn); `__forceinline` wrapping is **irrelevant** (same score with and without a helper).
⇒ **The lever is a loop existing in the FRONT-END IR, not a helper and not the emitted shape.**
A dead zero-trip loop does NOT work — the front end deletes it before weights are assigned.

⚠ **AND IT DOES NOT FIRE EVERYWHERE.** On `Sprite_FlushBatch`, six topologies — the loop bodily in
a helper, helpers taking `count` / `end` / `(p,end)`, a loop-body-only helper, and the whole locked
section in a loop-bearing helper — left the register map **byte-for-byte unmoved** at 87/169.
Page_Bake's full guard+do/while topology actively hurt (61/169 at 166 insn: the do/while loses the
`divwu` trip-count shape). Tested immediately on `Compose_Veil` (0x82182A68, 59/89), which
also has a loop: wrapping just the loop in a `__forceinline` helper, and wrapping the entire
branch containing it, are **both byte-identical to the baseline**. So Step 3b is not "wrap a loop
and gain words" — it is a *rank* lever, and it only shows up in a function whose residue actually
IS contested nonvolatile allocation. Page_Bake had thirteen nonvolatiles fighting over a rank
order; Compose_Veil's seven remaining structural mismatches are not an allocation problem at all.
**Diagnose the residue before reaching for it:** if the mismatches are `S` (structural) rather
than `r` (register/field only), rank is not what is wrong.

**Step 4 — batching.** Values needed by the first call are materialized in a leading pre-call
batch and rank above later-materialized ones; within a batch, declaration order.

**Step 5 — stray globals.** Any extra branch-crossing value (typically a branch condition that
must survive) is a global, steals a top register, and shifts the whole map down one slot.

## Why it is believed

* **A6 vs A7 — one `if` inverts the map.** Same six values, same reference counts, same
  declarations. A6 (no branch) ⇒ exact *declaration* order, fully anti-correlated with count.
  A7 (one `if` added, nothing else changed) ⇒ exact *descending count* order. The complete reverse.
* **A8/A9/A10 — branch POSITION decides membership.** Branch after all uses, or before all
  definitions ⇒ declaration order. Branch in the middle ⇒ descending count.
* **C1 vs C2 — byte-identical output with two values' counts swapped 2 ↔ 8.** Count is provably
  inert in straight-line code.
* **D1** — a 2-reference global beat an 8-reference local for r31.
* **G1/G2/G3** — reversing declarations == reversing assignments, and both differ from the
  baseline ⇒ in the global regime it is assignment order.
* **Loop weight** — crossover K = 3, 5, 6 for R = 1, 2, 3 in-loop references, fitting w ≈ 1.8-2.0.
* **Blind prediction** — a fresh function predicted before compiling: 6/6 correct on value
  placement; the only surprise was the branch condition taking a register, which is Step 5.

## ⚠ What it does NOT do — read before relying on it

**It is exact on regime and ordering, not on full permutations in large real functions.** It names
the r31 occupant and the top four of `Page_Bake` correctly, but it does **not** reproduce the full
11-way (`Sprite_EmitQuad`) or 13-way (`Page_Bake`) mapping. Both real cases contain a region where
the image ordering is *anti-correlated* with reference count (EmitQuad: x0/y0 at 5 references sit
below six values at 3; Bake: floatPool at 6 sits below count at 2). **There is a further ordering
term, and it dominates where many branch-crossing values tie on count.** Anyone claiming this
model pins an exact 11-way mapping is overclaiming.

**Do not build recipes on "reference kind".** An earlier probe's class ordering
(ALU ≫ store ≫ call-arg ≫ address-base) did not reproduce as an independent axis; C1/C2 show it
was the local/global switch plus definition order wearing a disguise.

**Moving one reference into a loop buys almost nothing** — the weight is ~2×, not 10×. You need
*more* references, not deeper ones.

**Verify by rebuild, never blind.** Five of eight edits tested on real code were completely inert.

## Why the flat sweeps were flat

`Sprite_EmitQuad` already matches the image on instruction count, instruction schedule, definition
indices, live ranges **and every per-value reference count**. Six source levers came back
byte-identical and two made it worse. In the global regime, priority is a function of *counts and
definition order* — so a sweep that permutes declarations, statement order and expression shape
without changing any count **is searching a space in which every point is the same point.** That
is the mechanical reason tell #12 ("when a sweep goes flat, stop tuning syntax") keeps being right.

## Applying it

To raise value V's register: give it **more references**, or make its live range **cross a branch**
when it currently does not (promoting it from local to global outranks every local). To lower it:
sink references, or keep the range inside one block. In the local regime, just reorder the
declarations.


---

## Corrections from real functions (2026-08-05, Page_Bake leg)

Three independent attempts on `Page_Bake` (0x8808DC10, 13 nonvolatiles) measured things the
synthetic probes could not, and **two of them contradict the rule above**. Recorded here rather
than quietly patched, because the rule is still useful and the limits are the point.

**1. Priority is NOT simply weighted reference count.** Our access pattern and the image's are
*identical* — same five loads at the same offsets, all at loop depth 0, instruction multisets
equal by construction — yet the assignment differs. **The difference lives in the IR handed to
the allocator, not in any statistic of what it emitted.**

**2. Address-base references weigh more than value references — roughly 3×.** Measured on the
float-pool base by stripping its accesses: 2 accesses ⇒ r25, 4 ⇒ r29, 5 ⇒ r30. Six base
references outrank the perennial zero's ~18 weighted ordinary ones, while five do not outrank
another value's 11.

**3. The residue is ONE decision, not a permutation.** Simulating "sort by priority, give each
the highest register free over its whole extent" reproduces the image from
`[gfx, zero, bakeX, i, bakeRec, pageCount, pool, firstPage, fmt, 512, pgTbl, 640, phase]` and
ours from `[gfx, pool, bakeX, i, zero, bakeRec, pageCount, firstPage, …]`. **Delete `zero` from
the first and `pool` from the second and both collapse to the same order.** There is exactly one
promoted slot at rank 2: the image gives it to the perennial zero, we give it to the float-pool
base. Every remaining scheduling scramble is downstream of that single choice.

**4. ✅ BLOCK FREQUENCY CONFIRMED — conditional placement discounts rank, but only by one slot.**
The image's three paste-side float loads sit in the loop **PREHEADER**, below the guard branch.
No compiler transform on this cl can put them there — LICM was ruled out three ways
(`extern const`, internal-linkage `static`, `__declspec(noalias)` on the callees) — so the source
placed them there, inside an explicit `if (pageCount != 0)`. **That guard is free**, because its
compare fuses into the record form of the `addic.` that computes `pageCount`; the earlier
"costs 3 instructions" result came from pairing the `if` with an upcount `for`, which MSVC then
re-guards. Paired with a **countdown do/while** it costs nothing, and the guard bytes become
exact.

The rank effect is real but small: the pool base demotes **r30 → r29**, one slot, where the image
has it seven ranks down at r25. **So a value's block frequency IS a term in the priority
function, and it is not the dominant one.** The remaining gap on Page_Bake is two rank edits —
pool 3→7 and `zero` above `bakeX` — with no known source lever. The way to pin the arithmetic is
the synthetic route this document was built with: small functions with a value's references split
between a fall-through block and a fused-if-guarded block, sweeping reference counts, for both
ordinary values and address bases.

## Two whole classes closed (do not re-open)

* **The float "pool" is NOT a compiler literal pool.** Spelling the constants as literals
  (`1.0f/0.0f/0.5f/-0.5f/511.5f`) scores far worse: this `cl.exe` emits a **separate `lis`+`lfs`
  for every distinct float literal** and never builds a shared base. A single base with
  displacements therefore has to be a named object or a run of file-scope statics.
* **LICM cannot be used to sink loads into a loop and let the compiler hoist them.** This `cl`
  treats a call as killing an `extern const` load, so in-loop loads stay in the body, drop to
  volatile FPRs, and the function shrinks.

## New datapoint (2026-08-07, Render_SelectBlend real-header leg)

`Render_SelectBlend` 0x88070000 built against the real XDK `<d3d9.h>` reaches the image's
instruction *structure* over its first 80 instructions (structural mismatches 12 → 2) and then
stops on register numbering alone. Its residue is **two decisions, not a permutation** — the
Page_Bake §3 test reproduces cleanly:

```
guest r31..r23: g_render, factor,   g_batch, alpha, alphaInX, consts, mask,  color, pageId
ours  r31..r23: g_batch,  g_render, factor,  alpha, alphaInX, consts, color, mask,  pageId
```

Delete `g_batch` from both lists and only `mask`/`color` still differ.

⚠ **`g_batch` contradicts Step 1 as written.** Counting machine references in the image,
`g_batch` has **11** and `g_render` **9**. Both are branch-crossing, both are used exclusively as
**address bases** (so correction #2's 3× base weighting applies to both equally and cannot break
the tie), neither is in a loop, and no `if`-guard separates them. Yet the image gives the higher
register to the value with **fewer** references. This is not a near-tie being settled by
definition order either: `g_batch` is defined first (image insn 6 vs 9), so Step 2 would also put
it on top.

✅ **AND IT IS EXPLAINED — BY LIVE-RANGE SPAN, WHICH THIS DOCUMENT DOES NOT CURRENTLY HAVE.**
Normalising the base-weighted count by the live range settles it the image's way:

| value | n | base | span | `(3*base + other) / span` |
|---|---|---|---|---|
| `g_render` (image r31) |  9 |  8 | 112 | **0.223** |
| `g_batch`  (image r29) | 11 | 10 | 150 | 0.207 |

`g_batch` has more references but holds them over a range a third longer, and the image prefers
the denser value. On `Render_SelectBlend` that candidate reproduces the image's 9-way order at
**tau 0.92**, against 0.58 for plain count.

⚠⚠ **AND THE CAUSAL READING OF THAT FIT IS REFUTED — DO NOT REPEAT IT.** It was written up the
same day as "priority is a density, not a total"; `probe_rank.py` then tested it directly and the
**opposite** holds in a controlled setting (see below). The 0.92 is a FIT on nine points, not a
mechanism. It stays here because the anomaly is real and any future model must still account for
it — but density is not the explanation.

⚠ **Do not attack it before the tail-merge defect in that function is settled.** `mask` (the
1<<60 pending-tag constant) is the RMW's operand, and our build merges four RMW sites into two,
which costs `mask` exactly two machine references. The mask/color transposition may be an artefact
of that, not an independent rank fact. Fix the merge, re-measure, then treat what survives as
real.


## The observational route is closed (2026-08-07) — `rank.py`

Seven of the eight ship-gate functions are blocked on register numbering alone (structural
mismatches are down to 1-15 words each while `r` mismatches run 5-38), so this document is the
gate's critical path, not a side quest. `rank.py` measures the image directly: it decodes the
guest bytes of every gate function and scores candidate priority functions by how well their
descending order reproduces the actual r31..r14 assignment.

    3*base + other - span/8      mean tau 0.706     exact 0/5
    n - span/8                            0.676     exact 0/5
    (3*base + other) / span               0.664     exact 0/5
    n   (Step 1 as written)               0.623     exact 0/5
    3*base + other                        0.620     exact 0/5
    base references only                  0.579     exact 0/5
    -span, -def, -last                    0.50, 0.47, 0.44

**What it settles:**

* ★ **Correction #2 holds on data it was not derived from.** Weighting address-base references 3x
  lifts mean tau from 0.623 to 0.706 and wins on three of the five functions.
* ★ **There is a SPAN term.** Every span-aware candidate beats its span-blind twin. This is new;
  the document had only count, loop weight, declaration order and block frequency.
* ⚠ **And no closed form works.** Nothing is exact on a single function, and plain count sits at
  0.623 against the 0.5 a coin gets. **The missing term is not observable from the emitted
  stream** — the same conclusion the Page_Bake leg reached from the other direction. Fitting more
  curves to disassembly is a dead end; do not spend a leg on it.

⇒ **The remaining route is synthetic**, exactly as this document was originally built: probe
functions small enough to read, varying ONE factor against a known baseline. The specific
experiment the data asked for was **count against span at fixed count** — and it was run the same
day. It killed the lead. See below.

⚠ `rank.py` profiles REGISTERS, not VALUES: a nonvolatile holding two values in disjoint ranges
gets their union as its span. Rare for nonvolatiles, but it means tau gaps of ~0.05 are noise.


## The span lead is dead, and so are two older assumptions (2026-08-07) — `probe_rank.py`

The controlled version of the experiment `rank.py` asked for: two branch-crossing address bases in
one function, A referenced in a tight cluster (short range), B referenced one-per-call (long
range), calls interleaved so both must live in nonvolatiles. Declaration order swapped as a
control. Result, across n = 2..7 references each and both orders — **twelve configurations, one
outcome**:

```
 n each   decl   A reg   B reg   winner
      2    A,B     r11     r30        B      <- n=2: A never reaches a nonvolatile at all
      3    A,B     r29     r30        B
      3    B,A     r29     r30        B
      ...   (identical through n=7, both orders)
```

And with **unequal** counts, A fixed at 3 references against B at 2..9: **B wins at every single
count, including nb=2 where A has more references.**

Three things die here, all by controlled measurement rather than inference:

* ⚰ **DENSITY / short-span priority.** The tight value loses everywhere. The observational lead
  (`rank.py`, mean tau 0.706) does not survive contact with a controlled test — it was
  correlation in five functions, and the causal claim written up from it is withdrawn above.
* ⚰ **Step 2's definition-order tie-break, in this regime.** Swapping the declarations changes
  **nothing** in any of the twelve runs. Whatever decides is not declaration order.
* ⚰ **Plain reference count as the discriminator.** At na=3 vs nb=2 the value with FEWER
  references still takes the higher register.

⚠ **What this does NOT establish.** "Longer range wins" is the probe's outcome, but it directly
contradicts the image: on `Render_SelectBlend`, `g_batch` has the longer range (150 vs 112) and
takes the LOWER register. So the probe is not yet in the same regime as the real functions. The
obvious difference is **pressure**: the probe holds three nonvolatiles, the gate functions hold
5-13. A priority allocator only has to make hard choices when values compete, and with three
values and eighteen registers nothing competes.

⏭ **The next probe is therefore a PRESSURE probe:** raise the number of simultaneously-live
branch-crossing values to 9-13 to match `Render_SelectBlend` and `Page_Bake`, then re-run the
count-versus-span sweep inside it. Until the probe reproduces a real function's regime, nothing
measured in it can be promoted to a rule — and that, not another candidate formula, is what the
gate is waiting on.


## The pressure probe (2026-08-07) — `probe_pressure.py`

`probe_rank.py` held three nonvolatiles; the gate functions hold five to thirteen, and a priority
allocator only chooses when values compete. This raises the pressure to ten and re-runs the
sweeps there. Two design fixes were needed first, and both are traps worth naming:

* **Bases must be call results, not global addresses.** `const unsigned* A = gA;` is a
  rematerializable constant (Step 3) and this compiler re-emits `lis`/`addi` instead of keeping it
  live. Every base here comes from `mk(i)`, a call, so it is a real value competing for a register.
* **A value whose references all sit ahead of every call never needs a nonvolatile at all**, and
  the first reference to a value is often based on a scratch volatile materialised for it alone.
  Read the MODAL base per displacement class, or the probe silently measures nothing.

### ✅ Step 0 CONFIRMED at pressure, and it is absolute

Experiment C, ten bases with four references each and spans 3..21: bases 0 and 1 (spans 3 and 5)
die before reaching the `if` and take **r21 and r20 — below every other value**, while the eight
branch-crossing bases take r31..r24. "Every global outranks every local" is exact, not a tendency.

### ✅ Step 1 CONFIRMED at pressure — EXACTLY, when span is held equal

Experiment B, ten bases with counts 2..11 over identical full-body spans:

```
n=11 -> r31    n=9 -> r29    n=7 -> r27    n=5 -> r25    n=3 -> r23
n=10 -> r30    n=8 -> r28    n=6 -> r26    n=4 -> r24    n=2 -> r22
```

Perfectly monotone across ten values. Descending reference count is the primary key and this is
the cleanest confirmation the document has.

### ★ NEW: span is a TIE-BREAK at equal count — and count BEATS it when they conflict

Experiment C (equal counts, spans 7..21 among the branch-crossing bases): **shorter span ranks
higher**, monotonically. So span is a real term, which the document did not have.

Experiment D settles the precedence. Five "dense" bases (4 refs / span 12) interleaved with five
"populous" ones (6 refs / span 23), all branch-crossing — the two models disagree by construction:

```
populous (n=6) -> r31 r30 r29 r28 r27        <- descending COUNT, exactly
dense    (n=4) -> r26 r25 r24 r23 r22        <- density would have put these on top
```

⇒ **count is primary; span only orders values that tie on count.** This also explains why
`probe_rank.py` concluded the opposite ("long range wins"): at three values nothing competed, and
one of its bases was being rematerialized. That reading is superseded.

### ⚠ CORRECTION to #4: block frequency is a HARD PARTITION at pressure, not "one slot"

Experiment E, ten bases with identical counts and identical spans, differing only in whether their
references sit at top level or inside an `if (k)`:

```
top-level bases -> r29 r28 r27 r26 r25
guarded bases   -> r24 r23 r22 r21 r20
```

**Every** unguarded value outranks **every** guarded one. Correction #4 measured "one slot" on
Page_Bake, where the guarded value also differed in count; with count controlled the effect is a
complete partition, ranking alongside Step 0's local/global split rather than as a small discount.

### ⇒ AND THE CONSEQUENCE FOR THE GATE, WHICH IS THE POINT

Profiling the image and our own object for `Render_SelectBlend` side by side, the value sets are
the same — same counts, same spans, 57 machine references against our 56 — and only the assignment
differs:

| | image | ours |
|---|---|---|
| r31 | n=9,  span=112 (`g_render`) | n=11, span=147 (`g_batch`) |
| r30 | n=6,  span=33  (`factor`)   | n=9,  span=109 (`g_render`) |
| r29 | n=11, span=150 (`g_batch`)  | n=6,  span=33  (`factor`) |

**Our top three are descending count (11, 9, 6) — what the probe says this allocator does. The
IMAGE is the one that departs from it**, handing r31 to a nine-reference value over an
eleven-reference one.

That inverts the problem this document has been carrying. The rules are not missing; our output
already follows them. What differs is the INPUT: the original source must distribute the same
references across different blocks than ours does, and by Experiment E block placement is strong
enough to reorder ranks wholesale. ⇒ **Stop hunting for a further ordering term. Hunt for the
source shape that moves references between guarded and unguarded blocks** — which is a
decompilation question, answerable per function, and no longer a compiler-archaeology one.
