# Day-4 prep — asset extraction pipeline

Branch `day4-extract-prep`. Everything lives in `tools/extract/`.

**Headline: the mapping is pure relocation — every byte of `assets/` is an
unmodified copy of a file in the dump — and the prototype reproduces the entire
1.1 GB tree, all 58 files SHA-256-identical, from the user's real console disc
install plus their Black Label DLC.** There is no transform step to write.

---

## Done

| Deliverable | Where |
|---|---|
| Extraction design, mapping table, failure modes, integration recommendation | `tools/extract/DESIGN.md` |
| Ground-truth manifest — path / size / SHA-256 for all 58 assets files | `tools/extract/manifest_v1.tsv` |
| Working extractor (GoD, ISO, STFS DLC, unpacked DLC, extracted folder; self-verifying) | `tools/extract/futari_extract.py` |
| Drag-and-drop wrapper | `tools/extract/extract_assets.bat` |

The extractor is adapted from futari_recomp's shipped v1.5.1 extractor
(`scripts/extract_iso.py`) — same game, same containers. Its XDVDFS reader, its
SVOD/GoD hash-tree verifier and its fail-loudly accounting are carried over
essentially unchanged, including the `fs_base = descriptor − 0x10000` fix that
made ISO extraction work at all. New here: an STFS reader for the DLC, the
already-extracted / already-unpacked input paths, the derived duplicates
realcomp's layout needs, and manifest verification.

## Verified by hash

| Claim | Evidence |
|---|---|
| `assets/` is a pure relocation of the disc | all **54** disc-sourced files SHA-256-identical to futari_recomp's independent extraction of the same disc — zero mismatches, zero transforms |
| The 3 Black Label files are unmodified DLC contents | SHA-256-identical to the unpacked package on `D:\360\00000002\496F816D…` |
| `assets/reco_normal.xex` and `shell/default.xex` are duplicates, not data | SHA-256-identical to `media/Module/reco_normal.xex` and `assets/default.xex` |
| **GoD container → full tree** | ran against the user's real disc install (6 data files, 0.85 GB): hash tree clean, **54/54 match**; then DLC folder → **58/58 match** |
| Already-extracted folder → full tree | **55/55 match** (54 + derived) |
| The new STFS reader is correct | positive-controlled on 4 unrelated real packages incl. a 240 MB / 162-file / 58,250-block one exercising hash levels 0–2: **every block of every file matched its level-0 SHA-1** |
| XDVDFS/ISO parser works on a real 360 ISO | found the volume descriptor at `0x0FDA0000` on a 7.8 GB Xbox 360 ISO and parsed a sane root directory (unrelated title — parser smoke only) |

## Not verified — Day 4 owns these

1. **A Futari ISO.** None on this machine. The XDVDFS code is unchanged from
   futari_recomp's, which is verified against a Futari XGD2 rip, so risk is low —
   but this repo has never run it on one.
2. **A real Black Label STFS package.** The user's console storage has no
   `00000002` folder; the DLC exists here only already-unpacked. The STFS reader is
   proven, but never on *this* package, and **`DLC_WANTED`'s package-internal paths
   are inferred** from the unpacked layout — mitigated with a basename fallback that
   is itself untested against a real package.
3. **Corrupt-input failure paths.** Inherited from proven code, not exercised here.
   Closing this is a five-minute job: flip a byte in a copy of a `DataNNNN` and
   confirm the run fails naming that file.
4. **The port booting on an extracted tree.** The output is byte-identical to what
   the port runs on today, so this is a formality — but it is the acceptance test
   and it has not been run.

## Decisions Day 4 must make

1. **Integration shape.** DESIGN.md §7 recommends: standalone Python tool +
   drag-and-drop `.bat`, launcher `.bat` runs it on first run when `assets\` is
   absent (the bundle's launcher already does this exact shape for `save\`), and
   the exe *checks* for `default.xex` at startup but never does the extraction
   itself. Needs a ruling.
2. **⚠️ Gate the DLC entitlement stub.** `shell/gen/stubs.cpp:283-293` hardcodes
   both DLC content IDs and answers "owned" unconditionally, so the top menu
   un-greys Black Label whether or not the user has it. Harmless while the bundle
   ships the files; **a crash-on-select the moment assets become user-supplied.**
   Gate the two `g_dlc[]` entries on `media/Rom/cg_black*.bin` being present. This
   is a source change outside `tools/extract/` and is the one real code defect this
   work surfaced.
3. **Drop `shell/default.xex`.** Point the launcher's third argument at
   `assets/default.xex` and delete the duplicate — removes 2.8 MB of duplicated game
   data and a whole derived-file rule. The prototype stages it (`--shell`) so
   nothing breaks meanwhile.
4. **Skip the 23 MB the port never opens?** `$SystemUpdate/*`, `AvatarAssetPack`
   and `nxeart` come free with a disc walk but are never read. Keep or drop.
5. **Python dependency at release.** Fine for beta (futari_recomp already requires
   it). The tool is a single dependency-free file, so PyInstaller stays available if
   it becomes a support burden.
6. **Write the user-facing dumping guide.** futari_recomp's `docs/DUMPING.md` is
   directly reusable — same game, same title ID, same routes. Needs a realcomp
   `docs/DUMPING.md` adapted from it, pointing at `manifest_v1.tsv` instead of its
   9-executable MD5 table.

## Notes

- Nothing outside this worktree was modified; `futari_realcomp` and
  `futari_decomp_gig` were read only. Nothing pushed.
- No game data is committed here — the manifest is hashes only, and the worktree's
  `.gitignore` already blocks `assets/`, `dlc/`, `*.xex`, `*.bin`.
- The repo has *never* tracked the assets; the 1.1 GB lives only in the
  distributed bundle (`_local/archive/releases/futari_beta1/assets`, plus
  `shell/default.xex`). That is what this work removes.
