# D1 LEG NOTES — the GameDriverTask command surface (decomp/shell/driver_msgs.cpp/.inl)

_2026-08-12, decomp side-gig session. Governing docs: `HUMAN_READABLE_DECOMP_PLAN.md` §4 rank 5
("8 near-identical clones collapse into one template — the largest LOC reduction per effort in
the project") and §9.1 row 5 (the msg-12/13/19 senders). Same discipline as
`decomp/game/PILOT_NOTES.md` (C1); this file is its shell-side sibling._

## 1. What is overridden

**96 guest functions = 12 shapes × 8 clones**, one contiguous protocol surface: the wrappers the
shell's GameDriverTask uses to talk to the loaded game module (`driver+0xFC` = the GameEntry proc
pointer from `XexGetProcAddr(ordinal 1)`).

| vt slot | shape | what it does | clones |
|---|---|---|---|
| +0x1C | E `Driver_ArmMode` | msg 10 mode-arm; `launchState = arg?5:0`, `modeArg = arg` | 8 |
| +0x20 | G `Driver_SendConfigBlockFromArg` | msg 15 block: 16B copied from r4 + r5 as 5th word | 8 |
| +0x24 | C `Driver_SendWord` | msg 16 single-word setter | 8 |
| +0x28 | D `Driver_QueryWord` | msg 17 MAGIC-VALIDATE query `{value,&out}` → out | 8 |
| +0x2C | B `Driver_SendTail` | msg 18, TAIL call, caller r4 passed through | 8 |
| +0x30 | H `Driver_SendConfigBlockFromRegion` | msg 15 block from `**DAT_821F858C`, 5th word −1 | 8 |
| +0x38 | A `Driver_IsPhase5Sub` | predicate `st[4]==5 && st[6]==1` | 8 |
| +0x3C | B `Driver_SendTail` | msg 12 MODE64-ARM, TAIL call | 8 |
| +0x40 | B `Driver_SendTail` | msg 13 RETURN-TO-MENU, TAIL call | 8 |
| +0x44 | A `Driver_IsPhase5Sub` | predicate `st[4]==5 && st[6]==4 && st[3]==0` | 8 |
| +0x4C | C `Driver_SendWord` | msg 19 MODE-SELECT setter | 8 |
| +0x50 | F `Driver_SetRankLevel` | msg 11 rank/level → signed rank mask | 8 |

**The clone sets are MEASURED, not transcribed.** Every generated body in
`shell/gen/ppc_recomp.*.cpp` was extracted, its address literals normalised away, and the results
grouped: each of the twelve shapes has **exactly eight** members, and every pair is identical
modulo addresses. That is also why each shape derives the return addresses it must publish from
its entry address at a fixed offset (`entry+0x24`, `+0x34`, `+0x40`, `+0x5C`, …) — the offsets
were verified equal across all 8 clones of every shape. The scan is a dozen lines of Python and
should be re-run after any regen (`shell/gen/ppc_recomp.*.cpp` are tracked, so a regen that
changes a body will change the grouping).

Clone → vtable: `vt 0x8204FFA8` = the `0x821C2xxx` clone, `vt 0x8204FC38` = the `0x821C8xxx`
clone (`reference/ghidra_futari_decomp/vt_gdtask_0727.txt`); the other six follow the same slot
layout at `0x821C40xx / 0x821C49xx / 0x821C75xx / 0x821C7Dxx / 0x821C8Exx / 0x821C96xx`.

## 2. Seam — plain `PPC_FUNC`, not `__imp__`

`out_reco/merged/*` hooks **none** of the 96 addresses (checked mechanically), so the plain
strong-over-weak form is correct; the `__imp__` shadowed-hook form of PILOT_NOTES §2 is only
needed where an instrument already owns the strong symbol. None of these wrappers is ever called
by name either — all 96 are vtable slots, so every call arrives through
`PPC_CALL_INDIRECT_FUNC → PPCFuncMappings → sub_82XXXXXX`, which the strong definition now owns.

Verified in a fresh `build/futari_merged.map`: **96/96** `sub_*` symbols resolve to
`decomp_driver_msgs.o`, and **96/96** generated `__imp__` bodies are still linked (dead weight =
the rollback path). No build-file change was needed: `build_win.sh`, `build_win_abn.sh` and
`build_win_dll.sh` all glob `decomp/shell/*.cpp` and link decomp objects first.

**Rollback** = delete `decomp/shell/driver_msgs.cpp` (or drop `obj_win/decomp_driver_msgs.o`
from the link line). Nothing else in the tree was edited.

## 3. Gate — `_local/_tmpscripts/d1_play_drive.sh`

The boot→attract drive the C1 gate used is **useless for this cluster**: on that path the shell
never calls any of these slots (measured — a canary build logged zero calls in a 95 s attract
run). The messages that do flow at attract come from the init driver and the mode setters, not
from the vtable command surface. So the gate is a **nav-driven arcade NORMAL PLAY entry drive**
(`scripts/futari_nav.sh`, entry path only — the post-game-over return is the library's documented
unreliable branch), which reaches a real mode launch and a real quit.

Results (all logs in `_local/logs/d1_*`):

| comparison | verdict |
|---|---|
| control ×4 (generated bodies) | 3 runs raw-identical; the 4th took the other **guest-stack** pointer arm (`r4=0x5150B2C` vs `0x6160B2C`) ⇒ that pointer drift class is proven **translation-independent, control-vs-control** (the C1 drift class, one level up: stack not heap) |
| control vs pilot, matched arm (`ctrl_d` vs `pilot_b`) | **RAW CANONICAL-IDENTICAL 94/94 — GATE PASS** |
| control vs pilot, mismatched arm (`ctrl_a` vs `pilot_a`) | 6 raw line-deltas, all from **one** `[gemsg] msg=5 call#7200` heartbeat line landing one menu-event earlier; splitting the stream: protocol 68/68 identical, heartbeat 26/26 identical |
| pilot ×2 | differ only in the same stack-pointer arm |

The msg-5 heartbeat is the per-frame handshake logged every 600th call from the render thread;
its interleaving against the menu thread carries no protocol meaning, and both arms of it appear
on control runs as well.

**Positive control (instruments lie until positively controlled).** A one-shot `RT_DRVCANARY`
build (canary removed immediately after, the gated source is the one committed) proved the bodies
actually run on the same drive:

```
12345 × sub_821C8690  (+0x38 predicate — polled every frame)
    6 × sub_821C88E8  (+0x30 msg-15 region block)
    3 × sub_821C87D8  (+0x1C msg-10 mode arm)
    3 × sub_821C85A0  (+0x50 msg-11 rank/level)
    1 × sub_821C8780  (+0x20 msg-15 block from caller)
    1 × sub_821C8660  (+0x40 msg-13 RETURN-TO-MENU)
```

⇒ **six of the twelve shapes have live-fire execution proof**, including the msg-13 sender — which
closes half of the C1 pilot's outstanding msg-12/13/14 live-fire debt from the SENDER side (the
`[msglog] PRE msg=13 lr=0x821C391C` line in the gate logs is that tail call, with `lr` left as the
mode dispatcher's return address exactly as a `bctr` requires).

**Registry status** is set accordingly, per function: the six executed addresses are `MATCHED`;
the other 90 are `DRAFT` — linked, seam-proven, and the drive passed with them linked, but they
never executed on this drive, so no per-function gate has fired for them. Not covered live:
shapes C (msg 16 / msg 19 setters), D (msg 17 query), B-with-msg-18, B-with-msg-12, and predicate
A-with-sub-4.

## 4. Deliberately-accepted residual differences

- **Predicates are natural C** (shape A): they are leaves, so there is no call boundary at which
  the incidental register file can be observed, and the generated bodies' volatile leftovers
  (`r10`, `r11`, `cr6`) are not reproduced. Same reasoning and same precedent as
  `decomp/shell/task_kill.cpp`.
- Every shape that reaches GameEntry mirrors the generated stream verbatim at the boundary — the
  C1 gate lesson is not re-litigated here: frame stores, staging slots, `r3/r4/r5`,
  `r9/r10/r11/r12/r30/r31`, `ctr`, and `ctx.lr` (exact generated return address before a `bctrl`,
  untouched before a `bctr`).
- The `slw` in shape F is reproduced through the recomp's exact masked-shift expression rather
  than a C `<<`, and shape F's `subfic` carry-out is mirrored into `ctx.xer.ca`.

## 5. What the next session should pick up

1. **Live-fire the remaining six shapes.** msg 16/17/19 setters and the msg-12 sender fire on
   paths this arcade-only exe (`futari_merged.exe`, modeIdx mask 0x01) does not reach. Options:
   a `futari_combined.exe` build + the 360 card path, or a TRAINING/other-mode launch, or the
   quit path once `futari_nav.sh`'s post-game-over branch is screenshot-mapped (that mapping is
   already an open item in the nav library's header).
2. **The four remaining slot shapes** in the same vtable, all with 8 clones each and all read but
   not yet translated: `+0x14` (msg-10 EXTENDED, 25 insn), `+0x18` (51 insn), `+0x34` (22 insn),
   and the init driver `+0x70` (`FUN_821C30B8`/`FUN_821C8BE0`, the 6/7/1/2/8/9 sequence — it is
   the biggest and the most exercised, and it would give live-fire on almost everything).
3. `decomp/registry.toml` has a **pre-existing** strict-TOML break at line 1394 (an unescaped
   `Rom\cg_v154hi.bin` inside a `role` string, from the 07-30 abn twin row). The D1 block parses
   clean; the file as a whole does not. One-character fix, left alone here to avoid touching a
   row another session may be editing.

## 6. Findings for the atlas conflict ledger (log only — atlases not edited from this task)

- **`driver+0xB4` is the game's own status block.** GameEntry msg 8 stores `0x887AD544` into
  `*arg` (`decomp/game/game_entry_msgs.cpp` case 7), and `+0xB4` is where the driver keeps that
  pointer, so the two predicate shapes read GAME-module globals live from the shell:
  `st[3] = 0x887AD547` (**the same byte msg 14 CREDIT-ARM uses as its guard**),
  `st[4] = 0x887AD548`, `st[6] = 0x887AD54A`. `ATLAS_shell_menus` §3 records `+0xB4` only as
  "persistent state block → msg 8 arg".
- **The msg-13 send at attract-to-menu comes from the mode dispatcher**, call site `0x821C3918`
  (`lr=0x821C391C`), through the vt+0x40 tail wrapper — not from a direct send.
- `ATLAS_shell_menus` §2 lists `FUN_821c2b90` (msg 19) and `FUN_821c2c20` (msg 16) as
  "single-param config setter" without noting that the parameter is passed **by pointer to a
  stack temporary in the caller's outgoing-parameter area** (new `r1+124` == old `r1+28`), which
  is what makes GameEntry's `arg[0]` read work.

## 7. ROUND-2 (2026-08-12, branch `decomp-gig-2`) — the four remaining vtable slots

The four slots §5.2 flagged as read-but-untranslated are now four more shapes (32 fns = 4 shapes ×
8 clones), same file, same seam. The clone sets were derived the same mechanical way (normalise
address literals out of every generated body in `shell/gen/ppc_recomp.*.cpp`, group → **exactly 8
byte-identical members each**, entry-relative return offsets verified equal across all 8):

| vt slot | shape | what it does | msgs |
|---|---|---|---|
| +0x14 | I `Driver_ArmModeExt` | mode-arm EXTENDED: 2 extra params → driver+0x8C/+0x90, launchState=(arg?1:0) | 10 |
| +0x34 | J `Driver_SendDescriptor` | DESCRIPTOR-IN: `{*DAT_821F858C + idx*720 + 16, driver+0xC0}` | 20 |
| +0x18 | K `Driver_ArmModeStaged` | mode-arm STAGED: launchState 2/3/4 by r5, primes 2 toggle-keyed slots, calls its OWN vt+0x50 (rank/level) at level 4 — **no direct send** | (via +0x50) |
| +0x70 | L `Driver_Init` | INIT DRIVER (`FUN_821C30B8`): boot-path burst 6,7,1,2,8,9 + `sub_821C64E8` + 304-byte `sub_8207DAC0` copy, then DESCRIPTOR-IN via its own vt+0x34 | 6,7,1,2,8,9,20 |

**Seam** — same as round 1: none of the 32 is hooked in `out_reco/merged/*`, so plain
`PPC_FUNC`. Verified in a fresh `build/futari_merged.map`: **32/32** round-2 `sub_*` resolve to
`decomp_driver_msgs.o`; the generated `__imp__` bodies stay linked (rollback). `build_win.sh`
links green. Two callees are reached by name (`sub_8207DAC0`, `sub_821C64E8`) — both declared at
global scope in `driver_msgs.cpp` so they route through the same strong-over-weak seam.

**Constants cross-checked exact** against the recomp decimals: `lis -32224/-32227/-32228` ⇒
`0x82200000 / 0x821D0000 / 0x821C0000`; the four msg-9 callback-fn pointers land on
`0x821C52E8 / 0x821C6208 / 0x821C5618 / 0x821C5230` — and `0x821C5618`/`0x821C5230` are named shell
functions (`sub_821C5618` per-frame pad provider, `sub_821C5230` RT-slot cb), a strong confirmation
of the `lis -32228 = 0x821C0000` base.

**Gate = PENDING-GATE.** These slots fire only after a real mode module loads (a plain boot/attract
calls **no** GameEntry at all — measured 0 `[gemsg]` lines in a 45 s idle boot, matching round 1's
"attract never touches the command surface"). The mode-launch nav drive (`scripts/decomp_d1_gate.sh`)
is the right gate, but its **windowed Vulkan boot segfaults early ~half the runs in the background
side-gig session** (removing `RVK_WINDOW` avoids the window-init crash but boot is still flaky), so a
clean control-vs-pilot pair could not be banked here. `scripts/_gig2_gate.sh` is the windowless copy
staged for it. Registry rows are **DRAFT** accordingly. The main session (which owns this harness and
the game-over nav gap) can bank the stream-equality run: the init driver +0x70 in particular is on
the mode-launch path, so a single arcade entry drive live-fires L (and, through L's tail, shape J).

**Atlas-ledger findings (log only):**
- **The msg-20 DESCRIPTOR-IN sender is vt+0x34**, feeding the per-mode 720-byte config record at
  `*DAT_821F858C[0] + driver+0xA8 * 720 + 16`. `DAT_821F858C` is the same config root shape H
  (msg-15 region) copies from; `+0xA8` is the mode index, `720` the record stride.
- **The init driver back-links the driver into two game globals via msg 6/7**: msg 6 returns
  `&0x887AD5D4` and the init writes `driver+0x4C` through it; msg 7 returns `&0x887AD5DC` and writes
  `driver+0x50`. So `0x887AD5D4/0x887AD5DC` hold shell driver-object fields after boot.
- **msg 8 STATE-BLOCK is sent from the init driver** (`GameEntry(8, driver+0xB4)`), which is what
  populates the `driver+0xB4` block the two predicate shapes (A) read every frame — closing the
  loop noted in round 1 §6 (predicates read game globals live): the init driver is the writer.
- **vt+0x18 (shape K) is an intra-vtable caller**: it invokes vt+0x50 (rank/level) on the same
  object via `*(driver+0)` — the first driver wrapper observed to call a sibling slot rather than
  GameEntry.

## 8. What the next session should pick up (round-2 update)

1. **Bank the PENDING-GATE live-fire.** Run `scripts/_gig2_gate.sh` (or `decomp_d1_gate.sh`) for a
   control (round-1 HEAD) vs pilot (`decomp-gig-2`) pair on a stable mode-launch boot; compare
   `[gemsg]`/`[msglog]` streams (drop msg-5 heartbeat) with `scripts/canon_seq.py`. A canary
   (temporary `RT_DRVCANARY`-style log in each shape, removed before commit) confirms which of I/J/K/L
   executed. Init driver +0x70 and descriptor +0x34 should fire on the plain arcade entry drive;
   +0x14/+0x18 depend on which arm the launched mode arms through.
2. The round-1 §5.1 debt is still open: msg 16/17/19 setters + msg-12 sender need the combined-exe /
   360 / training path.
3. `decomp/registry.toml`'s pre-existing strict-TOML break at (old) line 1394 is still there — the
   round-2 block parses clean in isolation; left alone per round 1.
