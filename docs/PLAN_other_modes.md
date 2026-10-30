# PLAN — the other modes (Arrange, Novice, Ver 1.01, Black Label) on the post-beta-3 port

Scoping window, 2026-10-12 (Mac, unattended, Opus). User: "did we want to scope out the rest of the modes now? black
label, arrange etc?" This is analysis plus a plan. No engine, decomp, `.app` or asset change was made, and nothing
was booted, so no drive lock was needed. The template a new module follows is the XBOX 360 MODE bring-up
(`scripts/regen_abn_mac.sh`, `build_mac_dll.sh`, `host/module_registry.cpp`, `host/futari_module_desc.h`).
Sources: NOTE_other_modes.md (all of it, including the 07-30 corrections), TITLE_SCREEN_NOTES.md, DUMPING.md,
PLAN_beta3_mac.md, PLAN_RC1.md §0, NAV_MAP.md (the 360 section), NOTE_fnf_shell_defects.md (10-04 beta-3 entry and
G-START), SAVE_DESIGN.md, shell/gen/stubs.cpp (the DLC gate, now at :280-330), out_reco/merged/merged_shell.cpp
([modestub] L1/L2/L3), and the top block of futari_decomp NOTE_campaign_decomp.md (r23-w157).

**New measurements in this window**, all on scratch and none committed:
- **M1, dry regeneration of all six other modules** with the Mac's eqv-fixed XenonRecomp, using the same binary
  regen_abn_mac.sh uses. Outputs are in `build/scope_arrange/<mod>/` (gitignored). Each run used only the millicode
  anchors from NOTE_other_modes §3, with no switch table and no harvested functions.
- **M2, a hook-survival census.** For each of the **297** reco_normal functions the port hooks (132 `PPC_FUNC`
  wrappers in out_reco/merged/merged_game.cpp plus every override in futari_decomp decomp/game/*.cpp), the census
  looked for a body with the same instruction-mnemonic sequence in each regenerated tree. Positive control: on
  reco_abnormal it finds 260 unique matches, and every one sits at delta 0 or +8, which is the known split law.
- **M3, a dry extraction of the DLC packages** found in `dlc/` into the session scratchpad. It was SHA-256-checked
  against tools/extract/manifest_v1.tsv and then deleted. Nothing was written to `assets/`.

---

## §1 THE MODE MATRIX

The shell folds the game-select into `modeIdx = titleIdx*2 + sub` (FUN_821B7CC0). The title rows are 0 = Ver 1.5,
1 = Arrange, 2 = Black Label and 3 = Ver 1.01. `sub` is 0 for the ARCADE-position card and 1 for the XBOX-360-position
card. The dispatcher's map is register-true (NOTE_other_modes §2). The ROM sizes and presence below were re-verified
on disk today.

| Mode (dispatcher string) | modeIdx | Module file (assets/media/Module) | Layout (M1) | ROM data needed | Present? |
|---|---|---|---|---|---|
| Ver 1.5 ARCADE (`MODULE_154_3`) | 0 | reco_normal.xex | 0x7B0000 image, code 0x88070000+0x1DEEB0 | Rom/cg_v154.bin 58,343,840 | ✅ **hosted** |
| Ver 1.5 XBOX 360 (`MODULE_154_3_HI`) | 1 | reco_abnormal.xex | 0x7B0000, +0x1DEEB8 | Rom/cg_v154hi.bin 211,780,472 | ✅ **hosted** |
| **Arrange** (`MODULE_ARRANGE`) | 2 | palm_normal.xex | **0x910000** image, .data 0x88260000, code +0x1E2560 | Rom/cg_v154hi.bin | ✅ present |
| **Novice / Easy** (`MODULE_EASY`) | 3 | palm_abnormal.xex | 0x7D0000, **code 0x88080000** (rebased +0x10000), +0x1E88A0 | Rom/cg_v154hi.bin | ✅ present |
| **Black Label ARCADE** (`MODULE_BLACK`) | 4 | kiniro_normal.xex | 0x7B0000, +0x1DDEA4 | Rom/cg_black.bin 57,743,518 + Rom/dropprm.bl 3,184 | ❌ not in assets/, ✅ **in `dlc/`** (M3) |
| **Black Label XBOX 360** (`MODULE_BLACK_HI`) | 5 | kiniro_abnormal.xex | 0x7B0000 | Rom/cg_blackhi.bin 216,869,269 + dropprm.bl | ❌ not in assets/, ✅ **in `dlc/`** (M3) |
| **Ver 1.01 ARCADE** (`MODULE_102`) | 6 | hirow_normal.xex | 0x7B0000, +0x1DBE30 | Rom/cg_v102.bin 58,356,684 | ✅ present |
| **Ver 1.01 XBOX 360** (`MODULE_102_HI`) | 7 | hirow_abnormal.xex | 0x7B0000 | Rom/cg_v102hi.bin 211,933,902 | ✅ present |

The eight modules imply no other modes. modeIdx 8 is the port's own synthetic selector, and it falls to the default
branch, which is reco_normal.

### 1.1 DLC / entitlement, per mode

- **Ver 1.5 (both), Arrange and Novice:** these need no DLC. The disc carries everything they use.
- **Ver 1.01 (6/7):** this mode is gated by DLC package `9893A78CA6062B935BD1F53EA43CFD546B7246DF43`.
  - That package is a 57,344-byte LIVE container holding an 11-byte unlock license and **no game data**. The ROM
    archives `cg_v102*.bin` are on the disc.
  - Two things depend on owning it. The shell builds the `menu_title_menu` movie, with a Ver 1.01 row, only when
    `*(DAT_821F858C+0x38F0) & 2` is set; otherwise it builds `menu_title_menu_del1.01`, which has no row.
  - The port's harness (`rt_dlc_owned`, stubs.cpp) answers OWNED whenever `cg_v102.bin` + `cg_v102hi.bin` exist, so
    every full disc dump owns it. **The user has nothing to do for Ver 1.01.**
- **Black Label (4/5):** this mode is gated twice. The shell checks `FUN_821897C0`, which tests modeIdx 4 or 5, and
  the ctor greys row 2 itself when bit 1 is clear. The port's `rt_dlc_owned(0)` serves the type-2 content as OWNED
  only when `cg_black.bin` + `cg_blackhi.bin` exist under the asset root. **The data is a DLC package the port never
  ships.**
  - **What to look for on the console:**
    - path: `Content\0000000000000000\435A07D7\00000002\496F816DD4B53DAEFF931838B6C69831AAD7663043`
    - format: LIVE container, content type 0x00000002, title 0x435A07D7
    - size: **277,135,360 bytes**. DUMPING.md calls it "~264 MB", which is the same file in MiB.
    - contents: `cg_black.bin`, `cg_blackhi.bin`, `dropprm.bl`
  - **New finding (M3): that package is already on this Mac.** The two DLC packages sit in the gitignored `dlc/`
    folder of this repo:
    - Black Label: 277,135,360 bytes, md5 f5031409…
    - Ver 1.01: 57,344 bytes, md5 638d1a2e…

    TITLE_SCREEN_NOTES.md also records them on the SHARED Deck share, and both are LIVE, type 2, title 435A07D7.
    `python3 tools/extract/futari_extract.py <folder containing them> --out <dir>` unpacked all three Black Label files
    in under a second, and **all three match the manifest's SHA-256**.
  - So Black Label is **not blocked on data on this Mac**. The data is one extractor command away, provided this is
    the user's own purchase, which only the user can confirm.
  - **Do not extract it into `assets/` before kiniro is hosted.** mac-build/build_mac_app.sh copies all of `assets/`
    into the bundle, which would add 275 MB of DLC to every F&F zip for a mode that is still greyed.

### 1.2 Wiring needed to un-grey a mode (shell side)

None of this is new code. The [modestub] layers are already driven by the hosted mask:
- **L1** (sub_821B80D0) greys every title row whose two modeIdx bits are both absent from `g_futari_hosted_mask`.
- **L2** (sub_821B7CC0) vetoes a `sub` that is not hosted on a row that is otherwise live.

Binding a third module un-greys its row. If only one card of a pair is hosted, the other card on that row declines
cleanly (L2), which is the same mechanism ARCADE and XBOX 360 use today. Three edits are required:
1. Add a descriptor in `host/futari_module_desc.h`.
2. Relax that file's `static_assert(normal.hosted_mode_idx/2 == abnormal.hosted_mode_idx/2, "both arms are title 0")`.
3. Add a `g_slots[]` row in `host/module_registry.cpp`. Its comment says "Adding a third module is one row plus its
   DLL", which is true **for reco-layout modules only** (see §1.4).

### 1.3 The module-blind bridge (NOTE_other_modes §5): **LANDED, closed**

`merged_bridge.cpp:76` `path_is_game` now resolves the guest path through `futari_registry_resolve_path()`, which
matches each *bound* slot's own basename. `GAME_ENTRY_ORD1` was retired at L3 and is now
`FutariModuleDesc::entry_ord1` (there is a `#error` guard at :29-30). An unbound module gets L1/L2 greying plus the
L3 safety net back to the top menu, so it never substitutes silently. **The §7 "silent wrong mode" hazard is
therefore closed in the combined build.** It can only come back through a *mislabelled* dylib, and the registry's
`IS THE WRONG MODULE` check refuses those.

### 1.4 Per-module data/address work (the analogue of 360's +0x60)

For reco_abnormal everything was one law: `.text` shifts +8 above 0x880DF080, and `.data` shifts +0x60 above
0x88351830. The other six modules follow no global law, but M1/M2 found more structure than the July note assumed.

| Module | vs reco_normal (M2: 297 hooks) | Renderer bridge (5 nvk twins, load-bearing under the shipped `RT_NVK=2`) | Sibling relation (M1) |
|---|---|---|---|
| kiniro_normal (BL) | 210 unique / 35 ambiguous / **52 no match** | **delta 0**: same addresses as reco | kiniro_abnormal = **+8 twin** (2,111 bodies at +8, 972 at 0; identical profile to reco→abn's 2,155/967) |
| hirow_normal (1.01) | 222 / 35 / **40** | +0x10 (ECA0→ECB0 …) | hirow_abnormal = **+8 twin** (2,139 at +8, 957 at 0) |
| palm_normal (Arrange) | 200 / 35 / **62** | +0x10 | palm_abnormal is **not** a twin (25 % unique, scattered deltas) |
| palm_abnormal (Novice) | 199 / 33 / **65** | +0x10000 (the rebase) | — |
| (control) reco_abnormal | 260 / 35 / 2, all at 0 / +8 | delta 0 | — |

"Ambiguous" means two or more functions share the same mnemonic body, and it is about 35 in every tree, including
the control. A call-graph tiebreak resolves those, as the +8 law did for 360. "No match" means the code changed, and
these are the real per-module hand work: 13-22 % of the hooks. GameEntry (export ordinal 1) and the XEX entry come
from the XEX headers, not from signatures.

The data side has three tiers:
1. The **6 descriptor addresses** (`FutariModuleAddrs`).
2. The **nav observer fields**: scene FSM 0x884D66A8, select FSM d76 0x884D678C, death 0x884D6878, slot0/credit
   0x884D6CE8/EA. These are the RT_NAV360 lever's set, re-based today by `dshift`.
3. The **START-wire EXCH word 0x88699894**. G-START found it misaddressed already in the 360 module.

For reco_abnormal all three tiers were one `dshift`. For the others each address has to be derived from the matched
functions' `lis/addi` immediates, which is mechanical once M2's map exists. `FUTARI_ADDRS_FROM_RECO_NORMAL(D)` cannot
express the result, so non-reco modules need explicit per-module address rows. The other ~314 `0x88……` literals in
merged_game.cpp are mostly log-only instruments. Under a non-reco module they read the wrong bytes, as the START wire
already does in 360. Each one must be gated per module or dropped, never trusted.

**One registry hazard is new for Arrange and Novice.** module_registry's swap is documented as safe because both
modules share one image window and one table window ("SAME image size"). palm_normal's image is 0x910000, so its
table starts at 0x88910000. reco's table window, 0x887B0000..0x88B6DD60, lies **inside** palm_normal's image. On a
palm→reco swap, step 4 zeros only the *incoming* image window (0x88000000..0x887B0000). Step 5 then installs reco's
slots over palm's left-over .data/.bss. The residue check only scans the *outgoing* table window, so any reco slot
that is not explicitly installed would hold palm data, and would be dispatched as a host pointer if ever called.
**The fix is to zero the union of both modules' image and table windows on every swap.** It belongs in the first
window that hosts palm_*. kiniro and hirow are 0x7B0000 like reco and are not affected.

### 1.5 Can the decomp campaign's harness and gates be reused?

- **Shell gates: yes, as-is.** The shell (default.xex) is the same for all eight modes. Routes B1/B2/B4/C1h/C7b, the
  per-function differential harness and INDCENSUS all keep working. One caveat: un-greying a top-menu row changes
  every top-menu shot, which does not matter for pilot-vs-control because both arms share the build. Cross-build
  comparisons (stagepix bundle vs merged) need a fresh baseline once the hosted mask changes.
- **Game-module gates: no.** The 84 MATCHED game rows, the readable game TUs, the boss plate gate and stagepix are
  all reco_normal addresses and reco_normal content. 360 already excludes 31 of the decomp/game TUs because of their
  `.data` literals. A palm/kiniro/hirow module links **none** of decomp/game except a re-pointed nvk_game_hooks, so
  it runs pure generated code. The campaign does not cover these game trees, and nothing in it transfers except the
  method.

---

## §2 BRING-UP RECIPE (per module, following the 360 template)

Steps 0 and 4a are **one-time**, paid by the first non-reco module. Every other step repeats for each module.

0. **Recompiler (one-time, ~10 min):**
   - Add `mulhdu` to `tools/xenonrecomp_mac_eqv_fixes.patch`. M1 found exactly one dropped instruction outside the
     reco pair: `Unrecognized instruction … mulhdu` at 0x881557B8 (palm_normal), 0x881541E8 (kiniro_normal) and
     0x881541F0 (kiniro_abnormal). hirow and palm_abnormal have none.
   - Apply NOTE_other_modes §0's one-line `xex.cpp` fix. Line 261 `image.size = security->imageSize` is still
     unpatched on the Mac. It did **not** crash M1 for kiniro or palm_normal, but it remains an un-audited 32 KB
     over-read.
1. **Regenerate** (`scripts/regen_<mod>_mac.sh`, cloned from regen_abn_mac.sh): a toml with the module's anchors
   (NOTE_other_modes §3), a `out_<mod>/` tree, the postregen import wrap, and the dropped-instruction census, which
   must be 0. M1 measured **0.6 s per module, 33 TUs, about 1.15 M lines, about 8,300 mapped functions**. Regeneration
   costs nothing.
2. **Switch tables:** run abn's recogniser on the module's own image to produce `config/futari_switches_<mod>.toml`.
   M1's switch-shaped `bctr` count is 65 in palm_normal and 65 in reco_abnormal, and the truth for reco_abnormal is
   57, so expect about 57 tables per module.
3. **Indirect-only functions:** futari_reco.toml carries 25 functions harvested from the SDK oracle's live memory, and
   abn ported them by the +8 law. For an independent build no oracle is on this Mac. Harvest instead from the port:
   every `rt_indirect_call` miss is logged loudly, so boot, add the function to the toml, regenerate and repeat. This
   loop is the main unknown in the estimate.
4. **Symbol map + descriptor:**
   - a. (one-time) generalise the build for non-reco modules:
     - build_mac_dll.sh: a per-module `MAP` header, and an exclusion of *all* decomp/game TUs except a per-module
       nvk_game_hooks.
     - explicit `FutariModuleAddrs` rows.
     - the [modestub] static_assert.
     - the registry union-zero for palm_*.
     - `moduleshim/module_shim_<mod>.cpp`.
   - b. (per module) generate `out_<mod>/<mod>_symbol_map.h` from M2's matcher, which is the analogue of
     abn_symbol_map.h:
     - unique matches → `#define sub_X sub_Y`.
     - ambiguous matches → call-graph tiebreak.
     - no-match hooks → **dropped from that module's link** by a per-module exclusion list, then triaged. Only the
       ones the module needs to reach stage 1 are hand-derived.
   - c. (per module) derive the data addresses (the 6 descriptor fields, the nav set, the START EXCH word) and put
     them in the descriptor.
5. **Build + bind:** add a `build_module <mod> out_<mod> <idx>` arm and a `g_slots[]` row. The proof is
   `[modreg] N/N bound, mask=0x..` with the new bit, and `[modreg] … IS THE WRONG MODULE` never firing.
6. **Card un-grey:** nothing to write. The row un-greys from the mask, and L2 declines the sibling card until it is
   hosted.
7. **Markers:** generalise RT_NAV360 into `RT_NAVMOD`, which reads the six observer fields from the live descriptor
   instead of `dshift`. Then map the module's screens into NAV_MAP.md the way the 360 section was done (title/attract,
   hub, MODE SELECT, stage 1).
8. **Smoke:**
   - card → decide → `[modswap] DONE` → module title → hub → NORMAL PLAY → stage 1 (first BGM cue new in the run)
     → pause → RESUME → RETURN TO TITLE → top menu.
   - a swap cycle A→new→A with `residue=0` at both retirements.
   - for palm_*, also the swap into and out of a *different-size* module.
9. **RC-style measurements** (Sonnet, PLAN_RC1's criteria R1-R16):
   - a stage sweep through TRAINING if the module's hub has it. The hub is shell-owned, so it should, but whether
     Arrange or Black Label expose TRAINING is unverified.
   - Black Label's stage 5 / second loop and Arrange's own scoring are new content with no reco reference.
   - persistence (settings, replay save/playback), co-op through the P2 path, game over, ≥5 swap cycles across *all*
     hosted modules, and a 20-min soak.
10. **Bundle:** `build_mac_app.sh` gains the dylib (about 10-45 MB per module, judging by the Deck .so sizes). For
    Black Label, the extracted DLC data in `ASSETS_SRC` also goes in, which means user-supplied F&F links only. The
    app smoke and the modes drive gain the new card.

### 2.1 Effort, calibrated on the XBOX 360 module

How 360 was actually spent (from the ledger and git; the July Windows docs live on iacon, so the counts are
approximate):
- 1 sizing window (07-29).
- About 2 windows for the abn recomp and the +8/+0x60 census (07-30).
- About 4 windows of **one-time** combined-exe infrastructure (07-31 L3-L5 DLL arm, registry, [modestub]).
- About 4 windows of abn ship-blocker fixes (08-07…08-15: harness re-sync, the +0x60 exclusions in asset_*/objaction).
- 1 long Opus window for the Mac regen and the module arm (10-04, beta 3).
- About 6-7 Sonnet measurement windows to reach RC1 level (Q2, Q2b, Q3-X, Q4b, Q7-360, Q3-sweep, 10-11/12).

So the cost specific to 360 was about **6 design + about 7 measurement windows**, and 360 had **free hooks** because
the +8 law made the whole symbol map mechanical.

| Module | Opus (design/bring-up) | Sonnet (measurement to RC level) | Why |
|---|---|---|---|
| **First independent module** (kiniro_normal or hirow_normal) | **4-5** (+1 one-time §2 step 4a) | **5** | regen/tables free; 40-52 hooks with no match plus the data map plus the indirect-harvest loop are the work; defects after first play budgeted at 1 |
| Its **+8 twin** (kiniro_abnormal / hirow_abnormal) | **1-2** | **3-4** | exactly the abn template: +8 symbol map off the sibling, a `dshift`-style data census, the same exclusions |
| **Arrange** (palm_normal) | **4-5** (+1 if first to need the union-zero swap) | **5** | most no-match hooks (62), the different image size |
| **Novice** (palm_abnormal) | **4-5** | **4-5** | independent build, rebased code base (the descriptor carries `code_base`, but every hard 0x8807…/0x8808… instrument is wrong by 0x10000) |
| **All six** | **about 20-24** | **about 24-27** | about 45-50 windows; read the cost as several RC1s, because each module needs its own RC measurement |

---

## §3 RISKS

1. **Recompiler coverage.** Coverage is good (M1): 0 dropped instructions except one `mulhdu` each in palm_normal and
   kiniro_*, and every module regenerates. The July note's "1.7-28 % identity" figures were delta-0 artefacts. With
   offset-aware matching, 67-75 % of the hooked functions are found unchanged in every module (M2). What M1 does not
   prove: correct code at the ~57 switch sites until the tables exist, and correct handling of whatever the
   indirect-only functions are.
2. **Structurally different builds.** Black Label is a different game (new ROM, new scoring, `dropprm.bl`), and its
   no-match hooks are where it differs. Ver 1.01 is the *original* arcade port (hirow): 40 no-match hooks, and it
   keeps reco's layout. Arrange has a bigger image (0x910000, .data 0x88260000), and Novice is rebased. Neither palm
   module is a twin of the other, so they cost two full bring-ups.
3. **Audio/assets.** All modules read the same `assets/media/Sound` banks (one BGM/SE/SYS_*/VOICE set), so
   `rt_audio_module_swap` stays a no-op. But the cue *numbers* each title plays are unmapped, and the ARCADE-card
   modules run the CV1000 ROM under the emulator layer, firing no XACT BGM (beta-3 lesson). Marker design must not
   assume `m02_stg1`-style cues on ARCADE cards. Black Label's ROM archives are DLC-only (see §4 for distribution).
4. **Save layout.**
   - The save container is shell-owned and shared by every mode: one `systemdata.bin` and one `replaydata.bin` under
     title 435A07D7 (SAVE_DESIGN.md §4; settings bytes shell-owned, RC1 R5a).
   - Per-mode bytes inside it (ranking, unlocks) are guest-defined and unmapped. RC1 R5b could not even locate the
     Ver 1.5 ranking.
   - A replay recorded in a module only plays back when that module is hosted. The REPLAY DATA list is shell-owned
     and would list it regardless. Measure what L2/L3 do when a replay of an unhosted mode is picked.
5. **Silent wrong mode.** Closed for unbound modules (§1.3). What remains is the *instrument* version of it: every
   reco-literal observer reads garbage under another module. That is how [navreal] went blind in 360, and how the
   START wire is misaddressed there today. Rule for every new module: no marker or gate is trusted until it is
   descriptor-driven and positive-controlled on that module.
6. **Swap-window hazard** for palm_* (§1.4). Silent .data/.bss carry-over into the next module's function table
   window. The fix is cheap, but it must land before any palm module ships.
7. **Smoke/bundle churn.** Every added module changes the bundle, the hosted mask, the top-menu pixels and the modes
   drive. That is why this work should start after the RC1 cut, not before it.

---

## §4 RECOMMENDED ORDER

> **USER RULING 2026-10-12:** the `dlc/496F816D…` package is the user's own Black Label purchase (confirmed). Order is **Black Label pair → Arrange → Novice → Ver 1.01 pair** — "1.01 is less wanted than the other modes". Start after the RC1 cut, per §5.

The brief expected "Arrange first because no DLC, Black Label last because DLC absent". **The measurements change
that.** Black Label's data is on this Mac and verifies, and kiniro is the closest independent build to reco: same
image layout, same millicode anchors, renderer bridge at the same addresses, and a +8 twin.

1. **Black Label ARCADE (kiniro_normal), then Black Label XBOX 360 (kiniro_abnormal, +8 twin).**
   - Most wanted, and structurally the cheapest independent build.
   - It needs no registry change, and it pays the one-time §2 step 4a.
   - **Prerequisite (user, by hand):** confirm that `dlc/496F816D…` is from their own console purchase, and approve
     extracting it, for example `python3 tools/extract/futari_extract.py dlc --out assets`, at bring-up time and not
     before. If it is not theirs, it must be dumped from their console, path in §1.1.
   - Distribution: the port ships zero game content. The F&F bundle already carries the user's own disc data, and
     adding the DLC data follows the same F&F-only rule. Never put it in a public release.
2. **Ver 1.01 ARCADE (hirow_normal), then Ver 1.01 XBOX 360 (hirow_abnormal, +8 twin).**
   - Data on the disc, the DLC is an 11-byte license the harness already satisfies, and it has the best hook
     survival (40 no-match).
   - This is the cheapest pair if the user values Ver 1.01 over Black Label: swap 1 and 2 freely.
3. **Arrange (palm_normal).** It needs the union-zero swap fix first. Its data is present and it needs no DLC.
4. **Novice (palm_abnormal).** Independent build plus the rebase. Do it last.

**Hard blocker:** only Black Label's data, and only if the `dlc/` copy is not the user's own; then they must dump the
package from their console (DUMPING.md "Black Label DLC"). Nothing else is blocked on user data.

**Timing: after the RC1 cut** (PLAN_RC1 §6). A third module changes the bundle, the hosted mask, the top menu, the
modes drive and the swap gate, so it would invalidate RC1's measurements.

**Bring-up log:** Black Label steps 0-2 (recompiler fixes, `out_kiniro*/` trees, 62+62 jump tables) are done statically, 2026-10-30: see `docs/PLAN_kiniro_bringup.md`.

---

## §5 DECISION SUMMARY (for the user)

- **Feasible now, no user data needed:** Ver 1.01 (both cards), Arrange and Novice. The ROMs are on the disc dump,
  and the Ver 1.01 "DLC" is an 11-byte license the port already satisfies.
- **Black Label (both cards):** feasible **if** the DLC copy already in `dlc/` is your own purchase. It extracts and
  verifies against the manifest. If it is not yours, you need to dump `…\435A07D7\00000002\496F816DD4B53DAEFF931838B6C69831AAD7663043`
  (277,135,360 bytes) from your 360.
- **Cost per mode** (Opus + Sonnet windows): first new title about 5-6 + 5, its XBOX-360 twin about 1-2 + 3-4,
  Arrange about 5-6 + 5, Novice about 5 + 5. All six come to about 45-50 windows. For reference, the 360 module cost
  about 6 + 7 with every hook free.
- **Recommended order:** Black Label pair → Ver 1.01 pair → Arrange → Novice. **Ruled 2026-10-12:** Black Label pair → Arrange → Novice → Ver 1.01 pair (user: 1.01 is the least wanted); DLC ownership confirmed.
- **Timing:** start **after the RC1 cut**, because a third module changes the bundle and the smoke.
- The silent-wrong-mode bridge bug from July is already fixed. Unhosted modes grey out and decline cleanly.
