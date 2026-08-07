# NOTES_select_compose.md — the game's select-screen compose engine, READ (2026-08-04)

User ruling (08-04, asked twice): no more lever trial-and-error on this family — read the code.
First sitting: the ENTIRE game-side resolve surface read end-to-end. Source: ghidra_futari_decomp/
reco_normal_decomp_all.txt (line numbers below); ATLAS_select_compose.md has the surrounding
sprite/blend map (07-22) — this doc adds the PAGE/BAKE layer it was missing.

## The census that started it
The game module contains exactly THREE D3DDevice_Resolve call sites, all in
out_reco/ppc_recomp.4.cpp: :9407 (sub_8808DA28), :9629 (sub_8808DC10), :11154 (sub_8808E468's
family — via dc10). Seven wrapper-altitude fix legs orbited a three-function surface.

## FUN_8808DA28 (:20439) — per-frame scene resolve. INNOCENT, fully understood.
SetRenderTarget(dev,0,DAT_887ad5dc) → Clear(dev, count=0, rects=NULL, flags=0xF,
color=FF000000, Z=DAT_88063374) → Resolve(dev, **Flags=0**, pSrcRect=NULL,
pDestTex=DAT_887ad5d4, dp=0, pClearColor=0). The main pane resolve every frame.
(Also swaps depth/stencil pair 887ad5f8/5fc ↔ 5e0/5e4 with two FUN_8807c0a8 calls — the
double-buffered depth family.)

## FUN_8808DC10 (:20484) — THE PAGE BAKE. The month-old mystery's home.
- Takes a PHASE in r3, which IS simply dc10's own r3 argument.
  ⚠ **CORRECTION 2026-08-05 (byte-matching leg): the original claim here was WRONG.**
  `0x88071134` is NOT "an EMPTY (blr-only) function = identity on r3". It is
  `std r19,-0x70(r1)` — the entry point of MSVC's **`__savegprlr_19`** register-save millicode.
  Ghidra renders the compiler's PROLOGUE as `iVar3 = FUN_88071134()`, which looks like an
  identity call and is not a call in the source at all. The conclusion (phase = incoming r3)
  stands, but for a different reason: there is no callee involved.
  ★ The millicode table is at 0x88071108-0x880711BC: save side ascends by 4 from
  `__savegprlr_14` @0x88071108 (`std rN, -(0x10+8*(31-N))(r1)`), terminated by
  `stw r12,-8(r1); blr` @0x88071168; restore side `__restgprlr_14` @0x88071170 upward.
  **The helper address directly encodes the LOWEST NONVOLATILE the original allocated** — a free
  read on register pressure before writing a line of C. So dc10 saves from r19 = 13 nonvolatiles;
  0x8808D838 uses __savegprlr_26 (6), 0x8808D930 __savegprlr_29 (3), 0x8808D640 __savegprlr_24 (8).
  Frame size follows: 8 nonvolatiles -> stwu -0xA0, 6 -> -0x90 (constant part 0x58).
- Phase table `local_150[4..10] = {0, 0x1D,0x1E,0x1F, 0x3D,0x3E,0x3F}` — page id 0 (+1) and the
  SIX 512x512 backdrop pages (two triplets = two rows).
- Gate: `if (DAT_887ad5f0 != phase)` — bake only on phase CHANGE; DAT_887ad5f0 = last phase.
- Bake loop (1 page per phase; 2 when last phase was 0): for each page id starting at
  `local_150[lastPhase+4]`:
    - `FUN_8808D838(id, 2)` ensure page texture (see below); skip page if 0.
    - src rect = `{x, 0, x+0x200, 0x200}` with x = 0x200*i, **x and x1 CLAMPED to 0x280 (640)**
      → shapes {0,0,512,512} and {512,0,640,512} — EXACTLY the 08-03 shape census entries.
    - `Resolve(dev, **Flags=0**, pSrcRect=&rect, pDestTex=pageRecord[id].tex, dp=0, cc=0)`.
      ⚠ THE BAKE RESOLVES ARE PLAIN FLAGS=0 RESOLVES — RVK_RES100 (clear-after) was NEVER the
      bake blocker. The recorder has ALWAYS accepted these.
- Then the PASTE-BACK: blend 0x10001 (→ OVER 0x7060706 via FUN_88070000 semantics),
  SetTexture(page.tex) + DrawPrimitiveUP(6=rectlist, 4 verts, stride 0x1C) per page — pastes
  page content back into the pane as strips at x = 0x200*i with a small x-bias DAT_880633ac.
- Page record table: `DAT_887518D0`, stride 5 dwords (0x14): [0]=texture handle,
  [1]=packed misc (df70 uses (rec[1]&0xffffff)<<8 as a size/pitch), [2]=CPU source buffer ptr,
  [3]=state flag, [4]=size-state. 0x200 records.

## FUN_8808D838 (:20354) — page-texture ensure (the "state machine" was just this).
`(pageId, sizeState)`: valid when pageId<0x200 && sizeState∈{1,2}. If record.sizeState changed
→ release + null. If record.tex==0 → `record.tex = FUN_88079970(S, S, 1, 1, 0, 0x18280143, 0, 3)`
with S = sizeState<<8 (2→512). Returns 0 ONLY on create failure. FUN_88079970 = CreateTexture
(fmt/flags word 0x18280143 — same packed word the bake pass stores at local_b0 in dc10).

## FUN_8808E298 (:20717) — per-quad emit = BAKE-ON-DEMAND TRIGGER.
Before emitting each sprite quad it derives a phase FROM THE QUAD'S OWN packed texid/coords:
`if (((y|t) < 0x40) && ((t & 0x1f) > 0x1c)) phase = ((y|t)>>5) + ((y|(t&~0x1f))>>4) + (t&0x1f) - 0x1c;
 else phase = 0;`
i.e. quads whose texture id decodes into the 0x1D-0x1F / 0x3D-0x3F page space compute phase
1..6; everything else phase 0. Then `FUN_8808DC10(phase)`. So: drawing the strips that SAMPLE
page N is what rotates the bake phase — the pages refresh incrementally as the scroll consumes
them. This is why the bake is invisible at boot altitude: it's woven into the strip batch.

## FUN_8808DF70 (:20666) — CPU-side page fill (the OTHER writer).
Walks all 0x200 page records: where rec.state==0 and rec.srcBuf(rec[2])!=0:
`FUN_8808D838(id, rec[4])` ensure texture → lock/describe (thunk_FUN_88082548 + FUN_88083380 +
FUN_88079948 = GetLevelDesc/LockRect family) → `thunk_FUN_88081EF0(...)` copy from rec[2]
(row-pitch aware) → unlock (FUN_88078308) → `FUN_88083758(rec[2]); rec[2]=0` free the source.
So pages get INITIAL ART from a streamed CPU buffer, then stay fresh via the resolve bake.
The 08-03 "missing page writer (streaming)" theory and the resolve-bake theory were BOTH right —
they are two arms of the same engine. rec[2] arrives from the asset/LZX streaming side.

## FUN_8808D930 (:20393) — teardown: releases all page textures + frees pending src buffers.

## THE ONE REMAINING QUESTION (instrumented, run pending)
Our port records flags=0 resolves and executes them into g_resolveTex entries keyed by the
DEST BASE decoded from pDestTex header (+32 dw1>>12<<12). The 08-03 evidence says the SAMPLED
page bases had everRendered=false entries — so either (a) dc10's resolves never fire (phase
gate / d838 create failing on our port), (b) they fire but the executor's dest-base decode
disagrees with the fetch-side base of the SAME texture, or (c) they fire correctly and the
PASTE-BACK/consumer side is where it breaks. RVK_RESLOG at char-select dwell (running) shows
which: compare [reslog] dst bases against the sampled page bases and the [rvk][resolve]
creation lines. NOTE df70's CPU fill on our port: LockRect writes go to GUEST RAM — but the
08-03 RAWDUMP2 found the page RAM 100% ZERO ⇒ the CPU fill never ran either ⇒ rec[2] source
buffers never arrive ⇒ the STREAMING side (asset/LZX) may be the true root for the INITIAL
art, with the resolve bake only explaining refresh. Check [file]/LZX activity for the page
source reads in the same run.

## Executor-side TODO once attributed (the 1:1 implementation)
- Honor the bake class: resolve-from-pane-window into a 512x512 page entry, then the paste-back
  draws sample it — our RESREAL path must serve the page entry at the FETCH base of the page
  texture (identity: dest base == fetch base, both from the same D3D texture header).
- Retire: origin-zero extend-to-dest stretch heuristic (the {0,0,640,512}→640x512 pane rule
  stays — it's da28's NULL-rect class; the {0,0,512,512} identity copies are dc10's and must
  NOT stretch), RESALIAS guessing for the six pages, and the fmt3-zero "colorkey" consequence.
- RVK_RES100 (clear-after) is a SEPARATE, smaller class — its consumers are elsewhere
  (not the pages); keep default-off until its consumer is read the same way.
