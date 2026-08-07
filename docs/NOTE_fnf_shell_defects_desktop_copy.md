
## 2026-07-28 latest — user re-test: TWO residuals named precisely
1. **M2-hold ghost persists** (user + re-scan: stationary dark ring, ~150 px constant through the
   bright hold t=6.5-8.4s, one cyan flash f00248; becomes the fade ghost). Guest dismissal proven
   + per-frame clear proven ⇒ mechanism = SELF-SUSTAINING RESTORE LOOP: guest restore draw
   samples resolve 0x723000; our LAYER-SEG resolves write it only PARTIALLY (compdbg: 2-batch
   segs, nonclear=53k px) so the loading-phase ring never leaves the resolve; each frame re-
   imprints it. On hardware the resolve carries the FULL accumulated EDRAM frame. Fix lane:
   make the shell resolve carry the full composed frame (resolve AFTER full accumulation, or
   clear-init the resolve target when the clear byte fires). NEXT INSTRUMENT: RVK_DUMPRES of
   0x723000 during the M2 hold — the ring should be visibly baked in it.
2. **Stray text glyph on TOP MENU** (user screenshot: single 「を」 from the description string
   floating beside Ver1.01) = FNF-7 extra-draw class; RVK_DRAWTRIP instrument is purpose-built
   for it (buffer shell-frame draws, dump when count exceeds N).
Everything else user-confirmed good ("otherwise yep nice").

## 2026-07-28 ~02:05 — GHOST-DRAW FIX FAILED USER ACCEPTANCE = STRIKE 2 ⇒ BACKLOG; PIVOT

User playtest on the fixed build (fix VERIFIED LIVE in the session log: per-draw A fired,
collapse honored — playtest_0728_0201.log): **flicker unchanged. STRIKE 2** on the flicker item
(strike 1 = wait-path cluster 01eee6a). Per the two-strikes rule: NO further legs; item to
backlog for re-ranking. The ghost-draw fix STAYS (register-true, instrument-verified — the
collapse-class draws were real defects; they are not the user-perceived term. Same shape as
strike 1: real fix, wrong dominant term.)

**★ NEW USER CHARACTERIZATION (materially reshapes the item):** flicker is NOT circle-specific —
"press start button flashing also flickers", "main logo sometimes". So: M2 circles + TOP MENU
glyph + PRESS START + title logo = **element-level transient flicker across MANY shell elements**.
The extra-draw arm is now closed (fixed above); what remains is most plausibly element DROPOUT /
partial-frame compose (no missing-draw census was ever run — drawtrip counted EXTRA only), i.e.
the compose-atomicity class. NOTE: user knows this game deeply — the press-start report means
flicker BEYOND its authentic rhythmic blink (do not re-chase the authentic blink, see title-blink
ledger).

**RE-RANK OUTCOME (BACKLOG.md updated):** flicker is no longer chased as its own defect. It is
FOLDED INTO the already-ratified **shell compose 1:1 campaign** (user 07-28 "decomp 1:1 time";
SPEC_shell_compose_1to1.md = the bible; decomp FUN_821CDBE8 family + veil FUN_82182A68,
implement intro/shell compose register-true, retire the heuristic persist/layer-seg compose) —
whose acceptance criteria now explicitly include: no transient flicker on press-start/logo/
circles/glyph over a full intro+TOP MENU soak, judged by the user. Correct-by-construction
replaces whack-a-mole; that honors both the two-strikes rule (different approach) and the ship
gate (menus/shell must be right).

## 2026-07-28 MORNING — RESKEEP=3 FAILED USER ACCEPTANCE ("nope same"); FLICKER PARKED; **PIVOT**

The pixel-proven flash class ([r5pix] partial-frame deliveries) is REAL and is suppressed by
RESKEEP=3 — and the user's perceived flicker is UNCHANGED. **The measured class ≠ the perceived
defect.** RESKEEP=3 unpinned from playtest.sh (lever + census + r5pix + gdprobe all stay in-tree,
default-off, positive-controlled).

**HONEST INSTRUMENT GAP for whoever reopens this:** every overnight instrument observed up to the
resolve/compose layer. The GLASS layer (swapchain present, the 720p->1080p/1920 RVK_WINSIZE window
blit, present-timing interaction) was NEVER directly observed — the display was off all night and
PrintWindow captures white (the banked trap). The perceived flicker may live between resolve and
glass. Do NOT chase this now — recorded as the top lead for whenever the item reopens.

**STATUS: flicker PARKED (not another leg).** Dossier: draw census clean; [r5pix] flash class
proven + suppressible; frame-straddle roster datum for atomic windows (e9c4339); glass layer
unobserved. Per USER DIRECTIVE (bedtime 07-28 + this morning's "PIVOT"): the project moves to the
**decomp→recomp campaign** — wholesale matching decomp/translation (UnleashedRecomp model,
[[futari-matching-decomp-goal]]), where compose correctness arrives by construction instead of
by renderer forensics. Shell-compose 1:1 (SPEC + presence contracts + Leg-2 datum) folds into
that campaign as the compositor subsystem's spec, not as standalone renderer legs.
