# NOTE_other_modes.md — "how big is getting the other modes working?"

> **→ 2026-10-12: superseded as the working plan by `docs/PLAN_other_modes.md`** (mode matrix, bring-up recipe on the regen_abn template, dry regen of all 6 modules + hook-survival census, Black Label DLC found in `dlc/` and verified; recommended order and timing after the RC1 cut).

> ⚠ **CORRECTIONS (2026-07-30, evidence-grade — see _tmpscripts/abn_hook_census.md +
> namespacing_research_repo.md + NOTE_campaign_decomp.md same date):**
> (1) §3's reco_abnormal figures (28.1% fn-start / 22.4% word identity) are DELTA-0-ONLY
> measurement artifacts. TRUTH: reco_abnormal = reco_normal + ONE 2-instruction insertion in
> sub_880DEF88; below 0x880DEF88 same address, at/above 0x880DF080 everything exactly +8;
> alignment-aware identity ~97.6%. §8's "MEDIUM (~1 full recomp leg)" for modeIdx 1 is an
> OVERestimate; the hirow/kiniro/palm overlap percentages carry the same delta-0 flaw (re-sweep
> before trusting), though no single-delta rule can exist for them.
> (2) §8's "runtime mode-switching = LARGE new subsystem" is superseded: the ruling is ONE DLL
> PER MODULE + host resolver (unload→reload lifecycle PROVEN in-process via RT_REATTACH,
> user-driven 2x clean; mapping table is runtime data). N-exes-behind-launcher is REJECTED.
> (3) First-leg steps 1 (XenonUtils fix) and 2 (RT_MODEIDX + loud guard) LANDED 2026-07-30.

2026-07-29 assessment leg. **Static (zero-boot) except where marked EMPIRICAL. No source edit,
no build, no commit.** Question posed by the user: Ver 1.5 Original (`reco_normal.xex`) is the
played path — what would the other 7 modules cost?

Tools/artifacts used: `ghidra_futari_decomp/xexdump.exe` (flat XEX images + `.pdata` function
lists), a pure-Python XEX2 BASIC extractor written for this leg (see §0 landmine), byte/`.pdata`
diffs, a `bl`-target scan of `default.img.bin`. Scratch scripts live in the session scratchpad
(`cmp2.py`, `bl.py`, `dis.py`, `pyxex.py`, `hooks.py`, `milli.py`, `modeprobe.sh`).

---

## 0. TOOLING LANDMINE FOUND FIRST (fix before anyone repeats this work)

`xexdump.exe` silently writes a **0-byte** image for `kiniro_normal.xex`, `kiniro_abnormal.xex`
and `palm_normal.xex` — it still prints `wrote flat image -> ... (N bytes)` and **exits 0**.

ROOT CAUSE (`xr-derisk/XenonUtils/xex.cpp`, `XEX_COMPRESSION_BASIC` branch): the result buffer is
allocated from the **recomputed** `imageSize = Σ(dataSize+zeroSize)` over the basic-compression
blocks, but line 262 then overwrites `image.size = security->imageSize`. For these three titles
the block sum is **smaller** than `security->imageSize`:

| module | `security->imageSize` | Σ blocks | delta |
|---|---|---|---|
| kiniro_normal / kiniro_abnormal | 0x7B0000 | 0x7A8000 | **-0x8000** |
| palm_normal | 0x910000 | 0x908000 | **-0x8000** |
| (all five others) | — | equal | 0 |

`out.write(image.data.get(), image.size)` therefore reads 32 KB past the heap block; the CRT's
`WriteFile` fails with `ERROR_NOACCESS`, sets `badbit`, and writes **nothing** — no crash, no
non-zero exit. Fix = allocate `max(Σblocks, security->imageSize)` (or clamp `image.size`).
⚠ **XenonRecomp uses the same `Image::ParseImage`**, so any future recompile of kiniro/palm_normal
inherits this over-read. `.text`/`.pdata` are far below the truncation point, so it is probably
benign for recomp, but it is un-audited.

Workaround used here: `pyxex.py` (AES-CBC via `cryptography` + retail key `20 B1 85 A5 ...`),
positive-controlled against `reco_normal` (reproduces `Rom\cg_v154.bin` exactly).

---

## 1. WHAT IS ACTUALLY IN `assets/media/Module/` (8 files, all distinct md5)

```
hirow_abnormal.xex 3547136   kiniro_abnormal.xex 3481600   palm_abnormal.xex 3678208   reco_abnormal.xex 3547136
hirow_normal.xex   3547136   kiniro_normal.xex   3481600   palm_normal.xex   3579904   reco_normal.xex   3547136
```
All XEX2, retail-encrypted, BASIC compression, all load at guest base **0x88000000**.

## 2. THE COMPLETE modeIdx → MODULE MAP (register-true, from the dispatcher itself)

`FUN_821C3B90` = `GameDriverTask::ProcessInit` (the atlas §8.6 "next probe" target — now decoded).
Disassembly of 0x821C3B90..0x821C3CF4 (`dis.py`):

```
lwz  r11,104(r3)      ; r11 = driverObj+0x68 = modeIdx
addi r11,r11,-1
cmplwi cr6,r11,6
bgt  0x821C3CCC       ; >6 (incl. modeIdx 0 and the port's synthetic 8) -> DEFAULT
mtctr r11 ; cmpwi cr6,r11,0
bdzf ... x5 / bne     ; 6-way ladder
```
Resolved call sites (`bl.py`, exact `bl` targets — no inference):

| modeIdx | dev string @0x8204E76C.. | loader ctor | module file | ROM data it opens |
|---|---|---|---|---|
| **0** | `Bootup MODULE_154_3` | 0x821C8A80 **(default branch)** | **reco_normal.xex** | `Rom\cg_v154.bin` ✅ present |
| 1 | `Bootup MODULE_154_3_HI` | 0x821C8200 | reco_abnormal.xex | `Rom\cg_v154hi.bin` ✅ present |
| 2 | `Bootup MODULE_ARRANGE` | 0x821C7980 | palm_normal.xex | `Rom\cg_v154hi.bin` ✅ present |
| 3 | `Bootup MODULE_EASY` | 0x821C2F58 | palm_abnormal.xex | `Rom\cg_v154hi.bin` ✅ present |
| 4 | `Bootup MODULE_BLACK` | 0x821C4D70 | kiniro_normal.xex | `Rom\cg_black.bin` + `Rom\dropprm.bl` ❌ **ABSENT** |
| 5 | `Bootup MODULE_BLACK_HI` | 0x821C44F0 | kiniro_abnormal.xex | `Rom\cg_blackhi.bin` + `dropprm.bl` ❌ **ABSENT** |
| 6 | `Bootup MODULE_102` | 0x821C9B80 | hirow_normal.xex | `Rom\cg_v102.bin` ✅ present |
| 7 | `Bootup MODULE_102_HI` | 0x821C9300 | hirow_abnormal.xex | `Rom\cg_v102hi.bin` ✅ present |

Three **independent** confirmations that the `Bootup MODULE_*` literal order IS modeIdx order:
(a) the atlas's `modeIdx == 4 || 5` DLC gate (`FUN_821897C0`) lands exactly on the two `kiniro`
entries, whose ROM is `cg_black*` = the 277 MB **Black Label** DLC; (b) `assets/media/Rom/`
contains exactly `cg_v102.bin cg_v102hi.bin cg_v154.bin cg_v154hi.bin` — the four on-disc titles
and no others; (c) modeIdx 0 = the default branch = `reco_normal` = the module the port actually
loads (`[xex] XexLoadImage("game:\media\Module\reco_normal.xex")` in every banked boot log).
The `Bootup MODULE_*` strings are otherwise **dead literals** — zero references in the image.

So: prefix = title (`reco`=Ver 1.5, `palm`=Arrange/Easy, `kiniro`=Black Label, `hirow`=Ver 1.01),
suffix `normal`/`abnormal` = the `arcade_front` sub answer (ARCADE / XBOX-360-"HI"), except
title 1 where the two subs are ARRANGE / EASY(Novice) — both on the 1.5-HI ROM.
NB `reco`/`palm` here are **not** the pilots: the pilot/shot-type space is a separate shell
concept (`Reco/Normal`.. `PANEL_PALM_A` @0x82046D54/0x8204B510, ranking panels).

## 3. STATIC: ARE THE OTHER MODULES BYTE-TWINS AT THE SAME ADDRESSES? **NO.**

Section layout (xexdump):

| module | entry | .text base..end | .data base | image |
|---|---|---|---|---|
| reco_normal | 0x88070588 | 0x88070000..0x8824EEB0 | 0x88250000 | 0x7B0000 |
| reco_abnormal | 0x88070588 | ..0x8824EEB8 | 0x88250000 | 0x7B0000 |
| hirow_* | 0x88070598 | ..0x8824BE30/E38 | 0x88250000 | 0x7B0000 |
| kiniro_* | 0x88070588 | ..0x8824DEA4/EAC | 0x88250000 | 0x7B0000 |
| **palm_normal** | 0x88070598 | ..0x88252560 | **0x88260000** | **0x910000** |
| **palm_abnormal** | **0x88080588** | **0x88080000**..0x882688A0 | **0x88270000** | 0x7D0000 |

`.pdata` function-start set vs reco_normal (3618 fns), and `.text` word identity **at the same
guest address**:

| module | shared fn starts | .text words identical |
|---|---|---|
| reco_abnormal | 1017 / 3618 (**28.1%**) | 22.41% |
| kiniro_normal / _abnormal | 339 / 331 (**9.4% / 9.1%**) | 0.0% |
| hirow_normal / _abnormal | 65 / 70 (**1.8% / 1.9%**) | 0.30% |
| palm_normal / _abnormal | 60 / 56 (**1.7% / 1.5%**) | 0.0% / 0.10% |

Spot-check of the port's own anchor functions (`cmp2.py`, first 6 words at the same address):
- **GameEntry 0x8824E698** — a `.pdata` start ONLY in reco_normal. In reco_abnormal the same
  prologue sits at **0x8824E6A0 (+8)**; in every other module the address is **all-zero padding**
  (hirow/kiniro/palm) or unrelated code (palm_abnormal).
- **draw core 0x8807ECA0** and **SETRT 0x88077E78** are **byte-identical and still function
  starts in reco_abnormal** (early engine/library `.text` is aligned between the reco pair), but
  in hirow they are displaced by 16 bytes and in kiniro/palm they are elsewhere entirely.
- ⇒ reco_abnormal is a **shifted sibling** of reco_normal (identical prologue region, divergence
  growing toward the tail); the other six are **independent builds**.

Millicode anchors (needed for each `XenonRecomp` toml — found by byte-pattern):

| modules | save/restgprlr_14 | save/restfpr_14 |
|---|---|---|
| reco_*, kiniro_* | 0x88071120 / 0x88071170 | 0x88088230 / 0x8808827C |
| hirow_*, palm_normal | 0x88071130 / 0x88071180 | 0x88088240 / 0x8808828C |
| palm_abnormal | **0x88081120 / 0x88081170** | **0x88098230 / 0x8809827C** |

## 4. STATIC: HOW MUCH OF THE PORT IS reco_normal-SHAPED?

- `futari_merged.exe` links **one** statically recompiled game module: `out_reco/ppc_recomp.*.cpp`,
  **33 files / 1,129,258 lines**, generated from `futari_reco.toml` (`file_path = "reco_normal.xex"`).
- `futari_switches.toml` — **57 hand-derived jump tables** for reco_normal, each recovered by
  full-word PPC reconstruction and cross-checked against the SDK oracle (header comment).
- `futari_reco.toml` also carries **25 hand-harvested indirect-call-only functions** that
  XenonRecomp's static analysis missed, "harvested from SDK oracle live gameplay memory".
- Host-side hooks keyed on reco_normal addresses: **121 distinct `PPC_FUNC(sub_88……)` overrides**
  (116 in `out_reco/merged/merged_xex.cpp`, 5 in `decomp/game/nvk_game_hooks.cpp` = the nvk draw
  path `8807ECA0/8807DD88/8807D4F8/8807A578/88077E78`), plus `decomp/game/game_entry_msgs.cpp`
  (the C1 MATCHED GameEntry at 0x8824E698), plus **295 distinct `0x88……` address literals**
  (globals: `DAT_884D66A8`, `0x887AD58C`, `0x88252504`, …).
- Fraction of those 121 hook addresses that are even a **function start** in another module:
  reco_abnormal **42.1%**, kiniro **12.4/13.2%**, palm **6.6/4.1%**, hirow **0.0/0.8%**.
  (reco_normal itself scores 88.4% because 14 of the 121 are the toml-harvested non-`.pdata` fns.)
- `decomp/registry.toml`: **139 of 243** registry rows are module `"game"` = reco_normal addresses.

**Hard architectural constraint:** all 8 modules load at **0x88000000** and the port's guest
address space is one flat host mapping with globally-named `sub_88XXXXXX` symbols and one
`PPCFuncMappings` table. Two game modules **cannot coexist** in one `futari_merged.exe` — every
symbol collides and every guest address is claimed twice. Runtime mode-switching would need
per-module symbol namespacing (a XenonRecomp feature, not present) + a swappable func-mapping
table + a guest-image swap on `XexUnloadImage`.

## 5. THE PORT'S MODULE BRIDGE IS MODULE-BLIND (silent-substitution hazard)

`out_reco/merged/merged_xex.cpp:67`
```c
static bool path_is_game(const uint8_t* base, uint32_t p){
  const char* s = (const char*)(base + p);
  return std::strstr(s,"reco")||std::strstr(s,"RECO")||std::strstr(s,"Module")||std::strstr(s,"module");
}
```
Every one of the eight `game:\media\Module\*.xex` paths contains `Module`, so `XexLoadImage`
returns the **same** resident `hmodule 0x88000000` and `XexGetProcedureAddress(ord 1)` returns the
**same** hard-coded `GAME_ENTRY_ORD1 = 0x8824E698` for all of them. Selecting any other mode today
does **not** fail loudly — it silently runs reco_normal. (Data bridge: `rt_load_game_data_sections`
loads `reco_normal.xex`, overridable by env `XR_RECO_NORMAL`.)
`RT_LOADGAME`'s injection path additionally hard-codes `PPC_STORE_U32(modectx+104, 8)` — selector
8 → the dispatcher's default branch → reco_normal. There is **no modeIdx lever** in the build.

## 6. ENTITLEMENT (ids 4/5) — reachable at the SHELL level, unusable at the ASSET level

- `shell/gen/stubs.cpp:194-246`: the harness hands back **both** DLC packages
  (`496F816D…` Black Label, `9893A78C…` Ver 1.01) as type-2 content and answers
  `XamContentCreateEx(ctype==2)` with `997 + completed overlapped (OWNED)` — i.e. the shell's
  DLC-ownership task un-greys the Black Label entry. `FUN_821897C0` itself is the real recompiled
  function; the port only wraps it for `[gsel]` logging + the `RT_DEVFREE` point hack.
- BUT `kiniro_*` open `Rom\cg_black.bin` / `Rom\cg_blackhi.bin` / `Rom\dropprm.bl`, none of which
  exist in `assets/media/Rom/` (the 277 MB Black Label package is not in this tree —
  `TITLE_SCREEN_NOTES.md:38`). **modeIdx 4/5 are asset-blocked regardless of the entitlement stub.**

## 7. EMPIRICAL — 2 probe boots, real game-select drive. **SILENT WRONG-MODE CONFIRMED.**

Script banked at `scratchpad/modeprobe.sh`: env verbatim from `_tmpscripts/c3_fieldaccept.sh`,
log-only (`RT_NVKPNG=0`, display-independent), pre-check aborts if any `futari*` process is live.
(One foreign `futari_merged.exe`, pid 21716, was running at first attempt — the leg poll-waited
and did **not** kill it, then ran once clear.) `RT_NAV_SEQ` supports `START/A/B/UP/DOWN/LEFT/RIGHT`
(`shell/gen/stubs.cpp:489-512`), so a non-default modeIdx is drivable with **no code change**.

**P1** `TAG=mp_sub1 DUR=85 NAV="18000:START,24000:A,25400:DOWN,26800:A"` — confirm title row 0,
then DOWN in the `arcade_front` sub-menu, then confirm. `/c/tmp/modeprobe/mp_sub1/boot.log`:
```
1280 [modeidx] sub_821C3F38 modeIdx=1 (XBOX-360 MODE, title=0) lr=0x821CE3C0
1282   [xex] loaded 4 game DATA sections (6060812 bytes) from reco_normal.xex
1288   [xex] XexLoadImage("game:\media\Module\reco_abnormal.xex") -> resident hmodule=0x88000000
1289   [xex] XexGetProcedureAddress(0x88000000, ord=1) -> 0x8824E698
1470   [file] open "game:\media\Rom\cg_v154.bin"      <-- NOT cg_v154hi.bin
```
**P2** `TAG=mp_row1 DUR=75 NAV="18000:START,22500:DOWN,24000:A,26800:A"` — DOWN at the game-select
list (row 1), then confirm twice. `/c/tmp/modeprobe/mp_row1/boot.log`:
```
1280 [modeidx] sub_821C3F38 modeIdx=2 (ARCADE, title=1) lr=0x821CE3C0
1288   [xex] XexLoadImage("game:\media\Module\palm_normal.xex") -> resident hmodule=0x88000000
1470   [file] open "game:\media\Rom\cg_v154.bin"      <-- NOT cg_v154hi.bin
```

FINDINGS:
1. **The shell side already works end-to-end for other modes** — menu row → `titleIdx`,
   `arcade_front` → `sub`, fold → `modeIdx`, dispatcher → the correct per-module loader, correct
   `game:\media\Module\<name>.xex` path. Nothing to build there. Menu row order is confirmed
   `row 0 = titleIdx 0 (Ver 1.5)`, `row 1 = titleIdx 1 (Arrange)`, matching the tips-string order
   VER154 / ARRANGE / BLACKLABEL.
2. **The failure signature is NOT a crash — it is a silent substitution.** Both probes ran the
   full 75–85 s (`[nvk] submit f4801`, GameEntry msgs flowing, **zero** VUID/VK_ERROR/`no
   pipeline`/FATAL), rendering Ver 1.5 ARCADE while the shell believed it had launched
   1.5-HI / Arrange. Root cause is §5 (`path_is_game` matching `"Module"`).
   ⚠ This means "the other modes" cannot be smoke-tested by eyeball at all today — the screen
   looks right because it *is* Ver 1.5. Any future report of "mode X works" is untrustworthy
   until the bridge is made module-specific (first-leg step 2).

---

## 8. SIZING VERDICT

| module | modeIdx | verdict | why |
|---|---|---|---|
| **reco_normal** | 0 | **WORKS ALREADY** | the played path |
| **reco_abnormal** (Ver 1.5 HI / Xbox-360) | 1 | **MEDIUM** (~1 full recomp leg) | closest sibling: same millicode anchors, same entry, `8807ECA0`/`88077E78` byte-identical at the same address, but only **28%** of fn starts and **22%** of `.text` words coincide and GameEntry moves +8. Needs its own XenonRecomp run, its own switch-table sweep, its own indirect-fn harvest, and re-derivation of 121 hooks + 295 literals. Assets present. |
| **hirow_normal / _abnormal** (Ver 1.01 / HI) | 6 / 7 | **MEDIUM–LARGE** | same recipe as above but a **fully independent build** (1.8% fn overlap, 0.3% byte overlap, different millicode anchors, 0.0–0.8% hook survival) — nothing transfers by inspection. Assets present (`cg_v102*.bin`). |
| **palm_normal** (Arrange) | 2 | **MEDIUM–LARGE + tooling fix** | independent build, `.data` relocated to 0x88260000, image 0x910000. Blocked on the §0 `XenonUtils` BASIC-size bug before it can even be dumped. Assets present. |
| **palm_abnormal** (Easy/Novice) | 3 | **MEDIUM–LARGE + rebase** | independent build **and** the whole image is shifted +0x10000 (`.text` 0x88080000, entry 0x88080588) — every hard-coded 0x88 constant in the port is wrong by construction, and the harness's `GAME_XSTART`/`GAME_HMODULE` assumptions need parameterizing. Assets present. |
| **kiniro_normal / _abnormal** (Black Label) | 4 / 5 | **LARGE / BLOCKED** | independent build **plus** the ROM data (`cg_black.bin`, `cg_blackhi.bin`, `dropprm.bl`) is the 277 MB DLC package that is **not in this tree** — an extraction step the user must supply first (same class as the `no bundled assets` ruling, `futari-fable-direction-verdict-0726`). Also both hit the §0 dump bug. |
| **"the game-select menu actually works"** (all 8 selectable at runtime) | — | **LARGE — new subsystem** | all 8 modules live at 0x88000000; one exe can host one module. Needs either per-module symbol namespacing in XenonRecomp + a swappable `PPCFuncMappings` + guest-image swap on `XexUnloadImage`, or N separate binaries behind a launcher shim. |

### Recommended order
1. **reco_abnormal (modeIdx 1)** — the only sibling with real overlap, assets on disc, and it is
   the mode users most often mean by "the Xbox 360 version". It is the cheapest possible probe of
   *"what does a second module actually cost?"* and the answer generalizes to 6/7.
2. **hirow_normal (modeIdx 6, Ver 1.01)** — assets on disc; tells us the cost of a genuinely
   independent build with no overlap to lean on.
3. palm_normal / palm_abnormal (Arrange / Easy) — after the `XenonUtils` fix and the rebase work.
4. kiniro_* (Black Label) — only after the user supplies the DLC extraction.
5. Runtime mode-switching — last, and only if N-binaries-behind-a-launcher is rejected.

### First leg — concrete plan (no new subsystem, one module, one binary)
1. **Fix the tooling landmine (§0)** — `xr-derisk/XenonUtils/xex.cpp` BASIC branch: allocate
   `max(Σblocks, security->imageSize)`. One line; unblocks kiniro/palm dumps and de-risks any
   future recompile. Rebuild `xexdump.exe` via `tools_src/build_xexdump.bat`.
2. **Add the missing lever + make the bridge honest** (small, and useful on its own even if the
   leg stops here): (a) `RT_MODEIDX` to override `PPC_STORE_U32(modectx+104, …)` in the
   `RT_LOADGAME` path; (b) make `path_is_game` match the **specific** module basename the build
   was recompiled from, so a non-default mode fails **loudly** (`[xex] … -> not the game module`)
   instead of silently running Ver 1.5 (§7 finding 2 — this is the highest-value 20 minutes in
   the whole list, independent of whether any other module is ever recompiled). Gate: re-run
   `TAG=mp_sub1 … modeprobe.sh` and see the loud refusal where the log today shows
   `XexLoadImage("…reco_abnormal.xex") -> resident hmodule=0x88000000`.
3. **Recompile reco_abnormal into a parallel tree** — `futari_reco_abnormal.toml`
   (`file_path = "reco_abnormal.xex"`, millicode anchors **identical** to reco_normal's per §3),
   `out_reco_abn/`, then the switch-table sweep (expect ~57 tables again; the reco pair's
   `.rdata`/table layout is the closest of any pair, so the existing sweep script should port).
   Deliverable: it compiles and links **as its own exe** (`futari_merged_v154hi.exe`) with the
   host layer unchanged; no attempt to co-host.
4. **Re-derive the 121 hooks + 295 literals for reco_abnormal**, mechanically where possible:
   `8807ECA0`/`88077E78`/`8807DD88`/`8807D4F8`/`8807A578` are byte-identical at the same address
   (verified) so the nvk draw path should transfer unchanged; `0x8824E698` → **`0x8824E6A0`**
   (GameEntry, +8) is the first known re-point. Build a byte-signature matcher (take the first
   0x40 bytes of each hooked reco_normal function, search reco_abnormal's `.text`) and report
   hit/miss per hook — that census IS the real cost estimate for modules 2–7.
5. **Boot gate**: `modeprobe.sh` against the new exe, expecting `Rom\cg_v154hi.bin` opened and the
   attract loop reaching the same `c3_verdict` H0/G1..G5 bar as reco_normal.

**Honest scope statement for the user:** the other modes are *not* a settings change. Each is a
separate 3600-function static recompilation with its own jump tables and its own copy of every
port-side hook; the shell side (menu → modeIdx → loader → `XexLoadImage`) is already **fully
working and fully mapped** (§2) and costs nothing. Realistic order-of-magnitude: **one dedicated
leg per module** for 1/6/7, **more** for 2/3 (rebase + tooling), and **user-supplied assets**
before 4/5 is even attemptable.
