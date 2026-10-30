# PLAN — Black Label (kiniro) bring-up: steps 0-2 DONE (static)

2026-10-30, Mac, unattended. Scope: the **static** steps 0, 1 and 2 of the bring-up recipe in
`docs/PLAN_other_modes.md` §2 for the user-ruled next module pair (§4: Black Label, kiniro_normal first, then its
twin kiniro_abnormal). Nothing was built, booted or driven. `assets/`, `dlc/`, `build/`, `out_reco*/` and
`external/` were not touched; all scratch lives in `_local/kiniro/` (gitignored).

| Module | Card / modeIdx | Tree | Config | Jump tables |
|---|---|---|---|---|
| kiniro_normal.xex | Black Label ARCADE, `MODULE_BLACK`, 4 | `out_kiniro/` | `config/futari_kiniro.toml` | `config/futari_switches_kiniro.toml` |
| kiniro_abnormal.xex | Black Label XBOX 360, `MODULE_BLACK_HI`, 5 | `out_kiniro_abn/` | `config/futari_kiniro_abn.toml` | `config/futari_switches_kiniro_abn.toml` |

---

## 1. What was generated

- **Step 0, recompiler.** `tools/xenonrecomp_mac_eqv_fixes.patch` gained two hunks:
  - `PPC_INST_MULHDU` in `XenonRecomp/recompiler.cpp`: `rD = (unsigned __int128)rA * rB >> 64`. `__int128` is
    already used in the tree (shell/gen's hand-fixed `mulhd`). The `mulhdu.` form sets CR0 from the 64-bit result;
    no `mulhdu.` site exists in either kiniro module.
  - NOTE_other_modes §0's xex fix in `XenonUtils/xex.cpp`. The BASIC branch allocates
    `max(Σblocks, security->imageSize)`, zero-filled. The line `image.size = security->imageSize` stays, and the
    buffer now covers it. For kiniro_* the block sum is 0x7A8000, which is 0x8000 short of the 0x7B0000 image. The
    missing tail lies past `.XBMOVIE` (0x887A3608) and is zero by construction.
- **Step 1, trees.**
  - `scripts/regen_kiniro_mac.sh` is cloned from regen_abn_mac.sh and does steps 0-2 in one run, in about 4 s.
  - `out_kiniro/postregen_kiniro.py` is the postregen_abn.py clone: the `extern "C"` import wrap plus the `rt_mftb`
    declaration, with the tree as an argument.
  - `out_kiniro*/` hold the generated trees.
  - `out_kiniro/tools_kiniro/ppc_context_kiniro.h` is the context header passed to XenonRecomp. It is
    out_reco_abn/ppc_context.h with the r23-w68 instrument block (RT_TRIOTAP/RT_WITNESS/RT_WITNESS2) removed. That
    leaves upstream plus the `ppc_div*` helpers the patch emits calls to, plus `<cstdio>`/`<atomic>`. See §5.3 for
    why the seed exists.
- **Step 2, tables.**
  - `out_kiniro/tools_kiniro/scan_switches.py` is abn's recogniser (tools_abn/scan.py, the same logic) plus a new
    **byte-map decoder**, both positive-controlled. Its `--control` mode must reproduce `futari_switches.toml`
    (57) and `futari_switches_abn.toml` (57) exactly before the script writes anything.
  - `xexflat.cpp` is the Mac replacement for xexdump.exe. It dumps the flat image through XenonUtils, so it needs
    the xex fix.
  - `ppcmini.py` holds the shared helpers and `census_dropped.py` is the census as a file.
- **Git.** This mirrors out_reco_abn exactly. `out_kiniro*/ppc_recomp.*.cpp` are gitignored (new .gitignore lines
  under the out_reco_abn block). The support files (`ppc_config.h`, `ppc_context.h`, `ppc_func_mapping.cpp`,
  `ppc_recomp_shared.h`), the postregen script and `tools_kiniro/` are tracked.

## 2. Exact commands

```bash
# what was run tonight: a PRIVATE recompiler copy, so external/xr-derisk (whose build/XenonUtils/libXenonUtils.a
# build_mac*.sh link into the game) was not rebuilt under the agents building the game at the same time
rsync -a --exclude build --exclude build-linux external/xr-derisk/ _local/kiniro/xr-derisk/
#   ... then applied the new patch hunks there; regen_kiniro_mac.sh configures + builds it if build.ninja is absent
XRD=_local/kiniro/xr-derisk bash scripts/regen_kiniro_mac.sh            # steps 0-2, writes out_kiniro*/ + tables
NOSWITCH=1 W=_local/kiniro/after_noswitch XRD=_local/kiniro/xr-derisk bash scripts/regen_kiniro_mac.sh   # no tables, trees untouched

# default (XRD=external/xr-derisk): the script restores recompiler.cpp + xex.cpp from git, re-applies the whole
# patch (that checkout still has the PRE-mulhdu patch applied), rebuilds XenonRecomp, which also rebuilds
# libXenonUtils.a, and builds xexflat next to it. Do that when no game build is running.
bash scripts/regen_kiniro_mac.sh

python3 out_kiniro/tools_kiniro/scan_switches.py --control --imgdir _local/kiniro/regen/img --config config
```

The **reco_abnormal identity check** (step 0's gate) was run by hand:
- **Setup.** config/futari_reco_abn.toml and the switch tables were regenerated into
  `_local/kiniro/regen_check_abn/`, once with the new binary and once with the old
  `external/xr-derisk/build/XenonRecomp/XenonRecomp`. The header was the same as regen_abn_mac.sh's.
- **New against old.** All 37 output files are byte-identical. reco_normal's own 37 are byte-identical too.
- **New against the tracked out_reco_abn/.**
  - 30 files are byte-identical: all 28 untracked TUs, `ppc_config.h` and `ppc_func_mapping.cpp`.
  - `ppc_recomp_shared.h` is byte-identical after postregen_abn.py.
  - The remaining 6 differ, and both kinds of difference are expected:
    - `ppc_context.h`: it carries the tracked w68 instruments.
    - The 5 tracked TUs 4/5/6/8/19: they were generated on Windows in alias mode and carry the w68 taps.
      regen_abn_mac.sh never overwrites them, and new == old holds for them as well.
- **Verdict:** the patch changes nothing for the reco pair.

## 3. Counts

| | kiniro_normal | kiniro_abnormal |
|---|---|---|
| dropped instructions, **old** binary (no tables) | **1**: `mulhdu r4,r11,r6` @0x881541E8 in sub_881541C0 | **1**: same @0x881541F0 in sub_881541C8 |
| dropped instructions, **new** binary | **0** (regen.log: 0 `Unrecognized instruction`) | **0** |
| TUs / lines (with tables) | 33 / 1,142,975 | 33 / 1,142,979 |
| lines without tables | 1,139,826 | 1,139,830 |
| mapped functions (`ppc_func_mapping.cpp`) | 8,375 | 8,375 |
| .pdata functions | 3,594 (reco: 3,618) | 3,594 |
| jump tables | **62** = 59 inline + 3 byte-map | **62** = 59 + 3 |
| provenance vs reco_normal | 3 same address (the 3 byte-maps), 44 fingerprint-matched elsewhere, **15 NEW** | identical split |
| switch-shaped `bctr` left unresolved | **0** | **0** |
| other `bctr` (not switches) | 6: 5 fn-pointer/vtable tail calls (ctr ← lwz), 1 register-argument tail call | same 6 |

The positive control is the reason to trust the table list. On reco_normal the same code finds exactly 57 = 54 inline
+ 3 byte-map, and reproduces futari_switches.toml **57/57**: every base, `r` and label, with no misses and no extras.
On reco_abnormal it reproduces futari_switches_abn.toml **57/57**. The 3 byte-map tables are the session-6
SDK-verified ones. abn could only carry those over by hand, and they are now decoded mechanically:
- `lhzx` u16 map + base for sub_880714E0.
- `lbzx` u8 map ×4 + base for sub_8807D838 and sub_8808B330.

Every `bctr` in `.text` is classified, so "0 unresolved" is a census, not an absence of evidence. The reco pair has
the same 6 non-switch tail calls and runs without tables at them.

Each kiniro tree emits 62 `switch (ctx.rN.u64)` blocks with tables and 0 without.

## 4. The kiniro pair is a +8 twin (as PLAN_other_modes §1.4 predicted)

kiniro_abnormal is kiniro_normal with one 2-instruction insertion in **sub_880E1B68**, which grows from 0xF8 to
0x100 bytes. reco's analogue is sub_880DEF88.
- **Code.** Starts at or below 0x880E1B68 keep their address (1,031 functions). Starts at or above 0x880E1C60 move
  +8 (2,563 functions). That covers 3,594/3,594 with no exceptions.
- **Tables.** 17 are at the same address and 45 are at +8.
- **Millicode anchors.** They are at reco's addresses (0x88071120/70, 0x88088230/7C) and **byte-identical** to
  reco_normal's in both modules.
- **Data does NOT follow one `dshift`.** This differs from the reco pair's +0x60. A first census compared the D-form
  immediates of the 3,593 twin-paired functions (same address below the split, +8 above it), resolving each
  through its `lis`. It found these deltas from
  kiniro_normal to kiniro_abnormal:

  | Delta | Sites | Where |
  |---|---|---|
  | **+0x100** | 9,418 | the dominant .data shift |
  | **+0xF0** | 3,344 | a sub-range of .data/.bss, so the map is piecewise |
  | +0x8 | 2,803 | code addresses above the split |
  | -0x28 / -0x30 | 540 / 13 | .rdata |
  | +0x168, +0x114, -0x660 | handful | stragglers |

  Step 4 needs the exact piecewise map. `FUTARI_ADDRS_FROM_RECO_NORMAL(D)`-style single-`D` derivation will not
  work even inside the kiniro pair.

## 5. What step 3 and step 4 need next

### 5.1 Step 3: indirect-only harvest (the main unknown)

Both tomls carry **no** `functions = [...]`. reco's 25 SDK-harvested entries are reco_normal addresses and do not
transfer. No oracle is on this Mac, so the loop has to run on the port:
1. Boot kiniro_normal, which needs step 4a first.
2. Collect every `[indirect] UNMAPPED guest target=0x88…` line.
3. Add each target with its `size` (distance to the next real function start) to futari_kiniro.toml.
4. Rerun `bash scripts/regen_kiniro_mac.sh` (4 s), and repeat.

Each kiniro_normal entry ports to kiniro_abnormal by the +8 law: +8 at or above 0x880E1C60, the same address below
0x880E1B68. That is how abn ported reco's 25. A static head start is possible: look for the 25 reco targets'
bodies in kiniro with M2's mnemonic matcher. Any that match are the likely first misses.

### 5.2 Step 4: symbol map, descriptor and data

**a. One-time build generalisation** (PLAN_other_modes §2 4a, unchanged). It needs:
- a per-module `MAP` header and the all-decomp/game exclusion in build_mac_dll.sh.
- explicit `FutariModuleAddrs` rows.
- the [modestub] static_assert relaxed.
- `moduleshim/module_shim_kiniro.cpp`.
- the out_reco_abn support files kiniro does not have yet: `harness.cpp`, `rt.cpp`, `rt_indirect.h`,
  `rt_phys.cpp`, `stubs.cpp`, `win_compat.h`, and the hook stubs.

kiniro's context carries **no** RT_ harness instruments, so nothing in the build may assume the w68 taps exist.

**b. Symbol maps.**
- `out_kiniro/kiniro_symbol_map.h` comes from M2's matcher against reco_normal: 210 unique, 35 ambiguous (call-graph
  tiebreak) and 52 no-match hooks (drop them, then triage).
- `out_kiniro_abn/` is then mechanical off kiniro_normal's map, by the +8 law in §4.

**c. Data addresses.**
- **The START EXCH word.** reco's EXCH word 0x88699894 is the `r4` argument that reco's `sub_8808E468` builds
  (`lis r9,0x886A; addi r4,r9,-0x676C`) right before its callback `bctr`. That function matches kiniro's
  **sub_8808E3F8** 100 % (169 instructions, immediates and displacements masked). There the same `addi r4` gives:
  - kiniro_normal: **0x8868F6AC**
  - kiniro_abnormal: **0x8868F7AC** (+0x100)

  Its neighbour, the callback slot `0x887AD5A8` in reco, becomes 0x887A33D0 / 0x887A34D0. These are structural
  candidates. Positive-control them on a live module before any gate trusts them (PLAN_other_modes §3.5).
- **The rest of the descriptor.** The 6 descriptor fields and the nav observer set (scene FSM 0x884D66A8, select FSM
  0x884D678C, death 0x884D6878, slot0/credit 0x884D6CE8/EA in reco) need the same treatment. Find each reader
  function's kiniro twin, then read its `lis/addi` immediates. The kiniro_abnormal values come from the piecewise
  map in §4, not from one shift.
- **GameEntry (export ordinal 1).** reco's GameEntry body (0x8824E698, 270 instructions) has **no** same-length
  twin in kiniro: the best match is 2 %, so it was rewritten. Read it from the XEX export instead. `.edata` sits at
  RVA 0x7B0000, which is at or beyond the image size, so it is **not** in the flat image. kiniro_abnormal's value is
  kiniro_normal's +8 if it lies above the split.
- **The other ~314 `0x88……` instrument literals** in merged_game.cpp are reco addresses. Gate each one per module
  or drop it.

## 6. Surprises and judgement calls

1. **62 tables, not about 57.** Black Label has 15 jump tables with no reco counterpart, and 10 of reco's 57 have
   none in kiniro. This fits it being a different game build. The byte-map dispatchers (early engine/library code)
   are the only tables at reco's own addresses.
2. **The new patch hunks are not picked up by regen_abn_mac.sh's guard.** That script only greps "futari eqv-fix",
   so `external/xr-derisk` on this Mac still has the **pre-mulhdu** patch applied and its binary has no MULHDU.
   That is harmless for the reco pair (identity proven above). regen_kiniro_mac.sh checks for both new markers and
   re-applies the whole patch when either is missing. **Call made:** external/ was left untouched tonight, because
   rebuilding it rebuilds the libXenonUtils.a that every game build links, and other agents were building.
3. **XenonRecomp's own detector is blind here.** Its "Found a switch jump table … with no switch table entry"
   heuristic, which keys on the word before `bctr`, reports **0** for kiniro even with no tables at all, so it
   cannot serve as a detector. M1's "65 switch-shaped bctr" came from a different count. The recogniser's full
   `bctr` census replaces it.
4. **The upstream context header lacks `ppc_div*`.** The patch emits calls to those helpers, so out_reco_abn only
   compiles because its tracked `ppc_context.h` has them. That is why `ppc_context_kiniro.h` exists.
5. **`.edata`, `.idata`, `.XBLD` and `.reloc` have VAs at or beyond `security->imageSize`** in every module.
   XenonUtils' `Image::Map` records pointers past the buffer for them. This predates tonight's work, and XenonRecomp
   never reads them.
6. **Unpatched neighbours.** The patch still has no `MULHD`. The shell's one site is hand-fixed (FIX 2026-07-24),
   and neither kiniro tree drops it.
