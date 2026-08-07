# C1 PILOT NOTES — GameEntry msg 12/13/14 slice (decomp/game/game_entry_msgs.cpp)

_2026-07-28, first decomp→recomp session. Governing doc: ghidra_futari_decomp/HUMAN_READABLE_DECOMP_PLAN.md §5.
Registry status: **DRAFT** (C written, NOT gated, NOT linked into any build)._

## 1. What is overridden

| Guest addr | Symbol seam | Conceptual name | Source of truth |
|---|---|---|---|
| **0x8824E698** | `PPC_FUNC_IMPL(__imp__sub_8824E698)` | `GameEntry_Dispatch` (GameEntry(msg,arg), export ord 1) | out_reco/ppc_recomp.32.cpp:25606-26270 (register-exact) + reco_normal_decomp_all.txt:304974-305151 (pseudo-C) + ATLAS_shell_menus §4 Anchor 3 |

**The whole 20-case function is translated, not just cases 0xb/0xc/0xd.** The plan's ≤120-line
slice wording assumed per-case replacement, but replacement granularity is one function, and the
only clean seam is `__imp__sub_8824E698` (below). Once the generated `__imp__` body is displaced
by first-def-wins it is unreachable, so the unhandled cases cannot be delegated — they had to be
translated too. Every case was verified line-by-line against the generated recomp (ground truth
per plan §3.5: recomp checked against Ghidra decomp — they agree at every point here; no
dropped-insn suspects in this function).

**Framing artifact (repeated from atlas):** Ghidra's `iVar3 = FUN_8807115c(); switch(iVar3-1)` is
NOT a call returning a msg id — 0x8807115C is `__savegprlr_29` millicode. The switch operand is
the incoming r3 (msg), r4 = arg pointer; `mr r3,r4` at 0x8824E6AC means every case body sees
r3 = arg (mirrored exactly in the C).

## 2. Why the `__imp__` seam (SHADOWED-HOOK landmine — live on this exact function)

`out_reco/merged/merged_xex.cpp:5711` **already defines strong `PPC_FUNC(sub_8824E698)`** — the
`[gemsg]`/RT_MSGLOG instrument, which tail-calls `__imp__sub_8824E698`. The gate (below) depends
on that instrument staying alive. Consequences:

- A second strong `sub_8824E698` (the naive plan-§3 idiom) would collide with the instrument:
  with `/FORCE:MULTIPLE` first-def-wins, either it kills the instrument (linked earlier) or is
  silently dead (linked later). Both outcomes are wrong.
- Therefore the C body takes the **`__imp__sub_8824E698`** symbol instead. Chain after the link:
  `caller → rt_indirect → PPCFuncMappings[0x8824E698]=sub_8824E698 (strong hook in merged_xex.o,
  beats the generated weak alias) → [gemsg] instrument → __imp__sub_8824E698 = THIS C BODY`
  (first on the link line, displacing the generated definition in game_ppc_recomp.32.o, which
  remains as dead bytes — the plan-§3 rollback shape).
- Callees are invoked through plain `sub_*` symbols, so their own instrument wrappers
  (e.g. `sub_8808FDF8`'s merged_xex wrapper) keep firing exactly as they do for the generated body.

## 3. Link recipe (deferred — plan §7: no build change until the gate passes; this session builds nothing)

In `build_win.sh`:

1. After the GAME tree loop add:
   `cc "decomp_game_entry_msgs" "decomp/game/game_entry_msgs.cpp" $GAME_INC $RT`
2. In the link line, place the decomp object **FIRST** (before `obj_win/game_*.o` — this is what
   makes `__imp__sub_8824E698` resolve to the C body):
   `obj_win/decomp_*.o obj_win/game_*.o obj_win/merged_xex.o obj_win/vk_render.o obj_win/shell_*.o obj_win/shellkernel_*.o`

**Seam-took verification (mandatory, instruments lie until positively controlled):**
- `futari_merged.map`: `__imp__sub_8824E698` must resolve to `decomp_game_entry_msgs.o`, and
  `sub_8824E698` must still resolve to `merged_xex.o`.
- Positive control: an RT_MSGLOG drive must still print `[gemsg]`/`[msglog]` lines (instrument
  alive), and a deliberate one-byte canary check (e.g. temporarily log from the C body under a
  new default-off env) may be used ONCE to prove the body executes, then removed before gating.

**Rollback** = drop the object from the link (remove the two build_win.sh lines, or just delete
`obj_win/decomp_*.o` from the link line). No existing file was edited; the generated body is
byte-for-byte still present in game_ppc_recomp.32.o and takes over again instantly.

## 4. How the slice reaches the transition log (expected lines)

Producer (this function) → mailboxes → consumer (still generated, deliberately):

- msg 13 → `0x887AD58C (DAT_887ad58c) = 1`; msg 14 → `if (u8)0x887AD547==0 then 0x887AD58C = 2`;
  msg 12 → `0x88252D58 = -1, 0x887AD584 (mode64) = 3, 0x887AD59C = 0x8000`.
- Consumer = outer-FSM `FUN_88138f00` mailbox read block (reco_normal_decomp_all.txt:126014-126023):
  reads 0x887AD58C and 0x88252D58, clears them (58C→0, 2D58→-1), calls `FUN_881383A0` when the
  2D58 value was >= 0. **It cannot be independently overridden** (it is a mid-function block of
  the outer FSM, far over budget), so the pilot gate exercises C-producer + generated-consumer.

Expected instrument lines (all from merged_xex.cpp, all already in-tree):
- `[gemsg] GameEntry(msg=12|13|14, r4=0x...) call#N` — first 3 of each msg id, then every 600th.
- With `RT_MSGLOG=1`: `[msglog] PRE msg=13#1 lr=0x... r4=... arg[0..3]=... | 58c=0 547=... 584=...`
  and `[msglog] POST msg=13#1 -> r3=0x0 | 58c=1 547=...`; msg 14 POST shows `58c=2` when 547==0
  (the "msg14 arms credited when 58c->2" probe). r3 must read 0 on all three msgs.
- With `RT_QDIAG=1`: `[q]`-line state trace on every change of scene state / `*(0x887AD58C)` /
  mode64 `*(0x887AD584)` — this is the consumer-side visibility of the same mailboxes.
- `[navreal]` st/d76 transitions cover the downstream FSM edges.

## 5. Byte-equality gate recipe (per plan §3.3 — gate BEFORE any status advance past DRAFT)

A/B on the SAME scripted drive (attract→menu→handback; the qa_playab.sh MODE=lever/oracle
harness discipline applies: verify snaps must be READ, decide presses press-and-verify):

1. Build A = current tree (generated body). Build B = identical tree + the two build_win.sh
   lines from §3. Confirm the §3 map-file seam check on B.
2. Run both with `RT_MSGLOG=1 RT_QDIAG=1`, same drive script, same save profile.
3. Extract and diff the instrument streams (they carry no timestamps/PIDs):
   `grep -E '^\[(gemsg|msglog|q|navreal)\]' stderr_A > A.log` (same for B) → `diff A.log B.log`
   must be EMPTY. This is the "RT_QDIAG/[navreal] transition logs byte-identical" gate of plan §5.
4. Cheap state snapshot (second, independent instrument): at drive end compare the staged-record
   / mailbox cluster bytes 0x887AD584, 0x887AD58C, 0x887AD59C, 0x887AD534/538, 0x88252D58,
   0x88252DD8, and the msg-1/2/9 target clusters (0x887AD5A0..5AC, 0x887AD5CC..5F4, 0x885C5BB0
   +0x60, 0x887AC718+8) — byte-identical A vs B.
5. Two consecutive gate failures ⇒ back to DRAFT and re-rank (07-26 two-ship-nothing rule).

## 6. Residual, deliberately-accepted differences (all invisible to the gates)

- Guest-stack scratch: the back-chain store and SP move ARE emulated (so callee frames and the
  msg-2 zero-staging at old-r1-48 land at generated addresses), but the `__savegprlr_29`
  register-save scratch bytes are not written (they hold host-register state with no guest
  meaning; nothing walks the back chain per the rt.cpp LR-band note).
- ctx nonvolatile registers r29/r30/r31 are simply never touched (the generated body clobbers
  then restores them) — strictly MORE conservative than the original.
- Volatile-register exit state (r4-r12, cr, ctr) differs from the generated body's leftovers;
  no correct caller/instrument reads callee-clobbered volatiles ([gemsg] reads only r3 after).
- `ctx.lr` is set to the exact generated return addresses before every callee call, so any
  lr-keyed instrument (e.g. the sub_88083200 RT_FIXSPAWN check pattern) behaves identically.

## 7. Findings for the atlas conflict ledger (do NOT edit atlases from this task; log only)

- **ATLAS_shell_menus §Anchor 3 msg-10/11 rows are off-by-one vs the binary**: msg 10
  (case 9, 0x8824E960) = `0x887AD534=*arg; 0x887AD538=0`; msg 11 (case 10, 0x8824E980) =
  `0x88252DD8=*arg` — msg 11 is NOT "unimplemented", and the `DAT_88252dd8` store belongs to
  msg 11, not msg 10. (Msg 4 unimplemented→-1 is confirmed.)
- Ghidra's case-1 "copy `auStack_31` stack garbage to 0x887ac717" is resolved by the recomp:
  it is `std r30(=0),80(r1)` staging + an 8-byte copy → the true effect is zeroing
  0x887AC718..1F. Not garbage, fully derivable.
