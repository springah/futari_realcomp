# Asset extraction — design

**Goal.** futari_realcomp ships no game data. The user supplies a copy of
Mushihimesama Futari Ver. 1.5 (title `435A07D7`) that they dumped themselves, and
a first-run step turns it into the `assets/` tree the port runs on.

Today the beta bundle carries **1.1 GB of copyrighted game data** (`assets/` 1.1 GB
plus a duplicate `shell/default.xex`). Removing it is the last irreversible-decision
item before any public release. The repo itself is already clean — `.gitignore`
blocks `assets/`, `dlc/`, `*.xex`, `*.bin` — so this is purely about what the
**distributed bundle** contains and what replaces it.

**Status of this document.** Day-4 prep. The mapping below is empirically verified
by hash except where marked; the prototype (`futari_extract.py`) reproduces the
whole `assets/` tree from a real console disc install plus DLC.

---

## 1. Prior art — futari_recomp v1.5.1

The separate public recomp project ships exactly this feature for **the same
game**, so this is an adaptation job, not a new build.

| Prior-art file | What it gives us |
|---|---|
| `futari_recomp/scripts/extract_iso.py` | The whole extractor: XDVDFS reader, SVOD/"Games on Demand" container reader with hash-tree verification, DLC discovery, fail-loudly problem accounting |
| `futari_recomp/extract_assets.bat` | The drag-and-drop wrapper and its Python-locating logic |
| `futari_recomp/docs/DUMPING.md` | The user-facing dumping guide, the reference MD5 table for the 9 executables, and the "title updates are not used" ruling |
| `rexglue-sdk/src/filesystem/devices/stfs_container_device.cpp` | STFS block maths for DLC packages (the one thing the recomp extractor does *not* do — it copies DLC packages verbatim and lets the runtime mount them) |

Two lessons carried over verbatim, **do not re-learn them**:

- **`fs_base = descriptor_offset − 0x10000`.** XDVDFS sector numbers are
  partition-relative and the volume descriptor sits at sector 32 of its partition.
  An earlier version returned the descriptor offset itself, shifting every read 32
  sectors late — ISO extraction had never actually worked, and every extracted file
  was garbage.
- **A short read must fail the run.** The original loop broke on a short read and
  then printed the size from the directory table rather than the bytes written, so a
  truncated dump extracted to empty files and the script still exited 0. The failure
  resurfaced hours later as a confusing codegen error, with a green extraction log as
  evidence. Every short read, bad hash and unsafe name now lands in `PROBLEMS` and
  fails the run.

---

## 2. What realcomp consumes at runtime

`RT_GAME_ROOT` (default `assets`) is the asset root; the guest's `game:\` paths
resolve under it. Consumers: `render/vk_render.cpp:8764`, `shell/gen/rt_audio.cpp:729`,
`shell/gen/rt_xwma.cpp:450`, and the NT file layer in `out_reco/rt.cpp`.

**58 files, 1,127,472,739 bytes** — full listing with hashes in `manifest_v1.tsv`.

```
assets/
├── $SystemUpdate/          2 files   7.9 MB   (on-disc system update; unused by the port)
├── AvatarAssetPack        14.5 MB            (on-disc; unused by the port)
├── default.xex             2.8 MB            ← also needed as shell/default.xex
├── nxeart                  1.0 MB            (on-disc STFS package; unused by the port)
├── reco_normal.xex         3.5 MB            ← DERIVED: copy of media/Module/reco_normal.xex
└── media/
    ├── Module/             8 files  28.4 MB  the 8 game modules
    ├── Rom/                7 files 819.7 MB  4 on-disc + 3 from the Black Label DLC
    ├── Sound/             12 files 202.4 MB  XACT banks
    ├── font/               4 files            
    ├── motion/             6 files            
    ├── text/               1 file             
    └── wall/              13 files  47.9 MB  wallpapers
```

Beyond `assets/`, one more path matters: **`shell/default.xex`** is named on the
command line (`futari_combined.exe 8208A2B8 0 shell/default.xex` — see
`scripts/run_window.sh`, `scripts/run_menu_win.ps1`, and the beta bundle's launcher
`.bat`). It is a **byte-identical copy** of `assets/default.xex`
(`6e619344…a434`), so it is produced, not shipped.

The beta bundle's `shell/` folder is 32 MB, but 2.8 MB of that is `default.xex`
and the rest is recompiler config and generated-source scaffolding — only
`default.xex` is game data.

---

## 3. The mapping: dump → assets

**Verdict: pure relocation. Every byte of `assets/` is an unmodified copy of a file
in the dump. Nothing is transformed, repacked, converted, or byte-patched.**

Established empirically — SHA-256 of futari_realcomp's `assets/` tree compared
against futari_recomp's independently extracted copy of the same disc, and against
the DLC contents on disk:

| # | assets path | Source | Transform | Verified |
|---|---|---|---|---|
| 54 | `$SystemUpdate/*`, `AvatarAssetPack`, `default.xex`, `nxeart`, `media/**` except the 3 below | XDVDFS root of the disc (GoD container or ISO) — same relative path | none — byte copy | ✅ **54/54 SHA-256 identical** to futari_recomp's extraction, and reproduced end-to-end from the raw GoD container by this prototype |
| 3 | `media/Rom/cg_black.bin`, `media/Rom/cg_blackhi.bin`, `media/Rom/dropprm.bl` | Black Label DLC package `496F816D…7663043`, package-internal `Rom/*` | none — byte copy, package unwrapped | ✅ SHA-256 identical to the unpacked package contents on disk. ⚠️ the *package-internal path* `Rom/…` is **inferred** — see §5 |
| 1 | `reco_normal.xex` (assets root) | derived — copy of `media/Module/reco_normal.xex` | none — byte copy | ✅ SHA-256 identical (`cf13982e…8fcf`) |
| — | `shell/default.xex` (outside assets) | derived — copy of `assets/default.xex` | none — byte copy | ✅ SHA-256 identical (`6e619344…a434`) |

Notes on the derived pair:

- **`assets/reco_normal.xex`** is the data bridge the merged exe reads. Added when
  the abnormal-module build landed (`XR_RECO_NORMAL`; see
  `docs/NOTE_campaign_decomp.md` — "data bridge via `XR_RECO_NORMAL` … root
  `reco_normal.xex` copy is just the default"). A duplicate 3.5 MB file, not new data.
- **`shell/default.xex`** exists only because the launcher names that path. Either
  the extractor stages it (what the prototype does) or the launcher is changed to
  point at `assets/default.xex`. **The second is strictly better** — see §7.

Three of the 54 disc files are dead weight the port never opens (`$SystemUpdate/*`
7.9 MB, `AvatarAssetPack` 14.5 MB, `nxeart` 1.0 MB). They come free with a disc
walk, so extracting them costs nothing but 23 MB of the user's disk. Day 4 may
choose to skip them; the manifest records them because they are what is there today.

---

## 4. Versions and DLC

- **Disc revision.** The port is built against Ver. 1.5 (`default.xex`, 2,760,704
  bytes, MD5 `46A2E233…40DE`). futari_recomp's `docs/DUMPING.md` carries the
  reference MD5s for all 9 executables; a size match with a hash mismatch means a
  different revision or region, not a bad dump. `manifest_v1.tsv` here supersedes
  that table for realcomp — it covers all 58 files with SHA-256 rather than 9 with MD5.
- **Title updates are not used.** Ver. 1.5 is the final revision. The runtime looks
  for a `default.xexp` patch, logs that there is none, and carries on. Nothing to
  extract. (Two `435A07E7` title-update packages were found on the user's console
  storage — different title ID, irrelevant.)
- **The four on-disc ROM sets cover 6 of the 8 game modes.** `cg_v154`/`cg_v154hi`
  (Ver 1.5, modes 0–1), `cg_v102`/`cg_v102hi` (Ver 1.01 + Arrange/Easy, modes 2–3
  and 6–7). See `docs/NOTE_other_modes.md` for the modeIdx → module → ROM table.
- **The Black Label DLC (retail package ~264 MB) is the only DLC that carries data.**
  Its `Rom/cg_black.bin`, `Rom/cg_blackhi.bin` and `Rom/dropprm.bl` are what modes 4
  and 5 (`kiniro_normal` / `kiniro_abnormal`) open. Without them the port runs fine
  and those two modes fail at asset-open.
- **The Ver 1.01 DLC (~56 KB, `9893A78C…246DF43`) carries no game data** — its only
  payload is an 11-byte `ver101_key.bin`. Ver 1.01's actual ROM (`cg_v102*`) is on
  the disc. Nothing to extract; the port ignores it.
- **`spa.bin`** (827 KB, inside the Black Label package) is not consumed by realcomp
  and is skipped.
- **⚠️ Entitlement is currently faked unconditionally.** `shell/gen/stubs.cpp:283-293`
  hardcodes both DLC content IDs and answers "owned" to the type-2 content
  enumeration, so the top menu un-greys Black Label whether or not the user has it.
  Today that is harmless (the bundle ships the files); once assets are user-supplied
  it becomes a **crash-on-select for anyone without the DLC**. Fix belongs with this
  work: gate the two `g_dlc[]` entries on the presence of `media/Rom/cg_black.bin` /
  `cg_blackhi.bin`. Flagged for Day 4 — it is a source change outside `tools/extract/`.

---

## 5. What is verified and what is not

Verified by hash, end to end, on this machine:

| Leg | Input used | Result |
|---|---|---|
| **GoD / SVOD container** | the user's real console disc install (`360 USB/Content/…/435A07D7/00007000`, 6 data files, 0.85 GB) | hash tree verified clean, 54 disc files extracted, **all 54 SHA-256-identical to the manifest**; both derived copies staged correctly |
| **DLC from an unpacked folder** | `D:\360\00000002\496F816D…\Rom\*` | 3 files copied, **58/58 manifest match** |
| **Already-extracted disc folder** | futari_recomp's `assets/` | see STATUS.md |
| **STFS reader** (the new code) | 4 unrelated real STFS packages, incl. a 240 MB / 162-file / 58,250-block one that exercises hash levels 0, 1 and 2 | every file's every block matched its level-0 SHA-1 — **162/162, 238 MB** |

**Not verified — Day 4 must close these:**

1. **ISO input.** No Futari ISO exists on this machine. The XDVDFS code is unchanged
   from futari_recomp's, which *is* verified against a Futari XGD2 rip, so the risk
   is low — but this repo has never run it on one. (The parser was smoke-tested
   against an unrelated Xbox 360 ISO; see STATUS.md.)
2. **A real Black Label STFS package.** The user's console storage has no
   `00000002` folder — the DLC only exists here already unpacked. So:
   - the STFS reader is proven, but never on *this* package;
   - **`DLC_WANTED`'s package-internal paths (`Rom/cg_black.bin`, …) are inferred**
     from the unpacked folder layout. Mitigated: the unpacker falls back to matching
     on **basename** (and says so) when no full-path match is found, so a
     differently-laid-out package still yields the three files rather than silently
     nothing. The fallback itself is untested against a real package.
3. **A corrupt input.** The failure paths (bad hash tree, truncated data file,
   short read) are inherited from proven code but were not exercised here. Cheap to
   close: flip a byte in a copy of a data file and confirm the run fails with that
   file named.
4. **The port actually booting on an extracted tree.** The tree is byte-identical to
   the one the port runs on today, so this is a formality — but it is the acceptance
   test, and it has not been run.

---

## 6. Failure modes and messaging

The rule inherited from the prior art: **never report success on an incomplete
extraction.** Every fault is collected and the run exits non-zero with each problem
named.

| Failure | Detection | Message |
|---|---|---|
| Wrong game | title ID in the XContent header ≠ `435A07D7` | names the title ID found vs expected |
| Corrupt / interrupted console copy | the container's own hash tree, walked before extraction starts | names the exact `DataNNNN` and block; "re-copy the install from your console's storage" |
| Truncated data file | file size vs the size the descriptor implies | names the file, both sizes |
| Not an XDVDFS image | volume descriptor not found at 4 known offsets, nor by a 2 GB scan | suggests `extract-xiso` as a second opinion |
| Corrupt directory table | entry name containing `/`, `\`, `:` or `..` | skipped, named, run fails — this is also the path-traversal guard |
| Short read mid-file | bytes written ≠ directory-table size | `TRUNCATED path (n of m bytes)` |
| Corrupt DLC package | per-block SHA-1 from the level-0 hash tables, checked while unpacking | names the block |
| Output does not match the reference | `manifest_v1.tsv` | names each mismatching file and whether size or hash |
| **DLC simply not supplied** | manifest entries under `media/Rom/cg_black*`, `dropprm.bl` | **not a failure** — reports that modes 4 and 5 will be unavailable and continues |

That last row is the important asymmetry: missing DLC is a normal, supported state;
anything else missing is a hard failure.

---

## 7. First-run integration — recommendation

Three options were considered.

**A. Standalone tool the user runs first (drag-and-drop `.bat`).** What
futari_recomp ships. Simple, debuggable, no game-process risk.

**B. The launcher runs it automatically when `assets/` is absent.** The beta
bundle's `Futari 1.5 - BETA 1.bat` already does exactly this shape for saves:
`if not exist "%HERE%\save" … xcopy from save_freshcard`. Same pattern, one folder
up.

**C. The exe extracts on first run.** Rejected. It puts container parsing, hash
verification and ~1 GB of file I/O inside the game process, in C++, for a
once-per-install operation. It also fights the project's ship target of a native,
rexglue-free binary — the STFS/SVOD readers live in the SDK the port is trying to
shed.

**Recommendation: A + B, with the exe doing a cheap check but never the work.**

1. **`futari_extract.py` stays a standalone Python tool**, shipped with a
   drag-and-drop `extract_assets.bat` — the same shape futari_recomp users already
   deal with, and the same interpreter requirement.
2. **The launcher `.bat` gains a first-run branch**: if `assets\default.xex` is
   missing, print the "you need to supply your own copy" message and run the
   extractor (dragging a dump onto the launcher passes it straight through);
   otherwise launch as now.
3. **The exe checks, and only checks.** At startup, if `RT_GAME_ROOT` has no
   `default.xex`, fail immediately with one clear line pointing at the extractor —
   not a `NtCreateFile` error 200 lines into a boot log. Cheap, and it catches the
   user who moved the folder.

Two follow-on decisions for Day 4:

- **Drop `shell/default.xex`.** Change the launcher's third argument to
  `assets/default.xex` and delete the duplicate. It removes 2.8 MB of duplicated
  game data, one derived-file rule, and one way for the two copies to drift. The
  prototype stages it (`--shell`) so nothing breaks in the meantime, but the
  duplicate should not survive to release.
- **Python dependency.** Acceptable for the beta (futari_recomp already requires
  it, and the extractor is one-shot). If it proves to be a support burden at
  release, freeze it with PyInstaller — the tool is a single dependency-free file
  by design, which keeps that option open.

---

## 8. The manifest as the acceptance gate

`manifest_v1.tsv` — relative path, size, SHA-256 for all 58 files — is the ground
truth. It was captured from the tree the port demonstrably runs on today, which
makes it a *behavioural* guarantee, not just a checksum list: reproduce it and the
port sees exactly the bytes it saw during every test to date.

The extractor verifies its own output against it on every run
(`--verify-only` to check an existing tree, `--quick` for sizes only). Regenerate
it only when the bundled tree legitimately changes, and bump to `manifest_v2.tsv`
rather than editing in place, so an old bundle and a new manifest can never be
silently mismatched.
