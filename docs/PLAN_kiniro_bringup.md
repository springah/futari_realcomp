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

---

## Step 4a (2026-10-30, Mac): kiniro_normal BINDS as a third module dylib (opt-in)

Commits abc9dfa (arm, descriptor, map, shim, slot) and 49e117d (bind drive script). The module is bound, **not run**:
nothing below proves a kiniro address at runtime.

### What was added

| Piece | File(s) | Notes |
|---|---|---|
| build arm | `build_mac_dll.sh` | `MODULES="normal abn kiniro"` -> `futari_game_kiniro.dylib` from out_kiniro/, `-DFUTARI_MODULE=4`. Default `MODULES` stays `"normal abn"`. |
| decomp exclusion | `build_mac_dll.sh` | the kiniro arm links **no** decomp/game TU except `nvk_game_hooks` (w186 LAW 1), and no game_abn/. |
| symbol map | `out_kiniro/kiniro_symbol_map.h` | GENERATED by `out_kiniro/tools_kiniro/gen_symbol_map.py`; force-included on merged_game.cpp + nvk_game_hooks.cpp only. |
| exclusion list + stubs | `out_kiniro/kiniro_hook_stubs.cpp` | GENERATED with the map: one loud weak stub per dropped hook symbol (below). |
| evidence | `out_kiniro/tools_kiniro/hook_match_kiniro.txt`, `desc_candidates_kiniro.txt` | per-symbol class/target/votes; descriptor derivation output with its controls. |
| descriptor | `host/futari_module_desc.h` | `g_futari_desc_kiniro_normal`, explicit literals, every one marked UNVERIFIED; accessor arm `FUTARI_MODULE == 4`; any other index is now an `#error`. |
| registry slot | `host/module_registry.cpp` | third `g_slots[]` row `{futari_game_kiniro, kiniro_normal, 4}` under `#if FUTARI_HOST_KINIRO`; the build passes `-DFUTARI_HOST_KINIRO=1` to the host only when `MODULES` names kiniro. |
| shim | `moduleshim/module_shim_kiniro_normal.cpp` | the generated reco_abnormal shim with its two name strings changed (same ABI, same 59 kernel imports: kiniro's import set is identical to abn's, 120/120). `tools/gen_host_abi.py` now knows module 4 (`MODNAMES`). |
| tree support files | `out_kiniro/rt_indirect.h`, `out_kiniro/win_compat.h` | rt_indirect.h = out_reco_abn's verbatim. win_compat.h = out_reco_abn's plus out_reco's 4-line macOS `xr_gettid` arm. |

**Call made: no kiniro copies of harness.cpp / rt.cpp / rt_phys.cpp / stubs.cpp.** In the combined build those are HOST
objects compiled from out_reco/ only (`game_rt`, `game_stubs`, `game_harness`, `game_rt_phys`). A module dylib never
compiles them, and out_reco_abn's copies exist only for the Windows per-module exe. A kiniro copy would be dead code.
abn_hook_stubs.cpp's role is taken by the generated kiniro_hook_stubs.cpp.

### Index / mask convention

The module index passed as `-DFUTARI_MODULE` **is** the shell's modeIdx (`titleIdx*2 + sub`). It equals
`hosted_mode_idx` and the slot's `mode_idx`, and it is the bit in `g_futari_hosted_mask`. So kiniro_normal is 4,
mask bit 0x10. A 3-module host prints mask **0x13**. Next modules: 5 kiniro_abnormal, 6/7 hirow, 2/3 palm.

The [modestub] `"both arms are title 0"` assert was **not** relaxed. It is a statement about the reco pair, and it is
still true. kiniro adds three asserts: no collision with 0/1, modeIdx == 4, and reco's image base/size (the registry's
single-window swap depends on it). L1 already greys by `futari_title_hosted(row)` over the whole mask, so it needed no
edit.

### Symbol map (219 reco_normal function symbols named by merged_game.cpp + nvk_game_hooks.cpp)

- **Matcher.** Whole-extent body equality, where extent is `[start, next ppc_func_mapping start)`. Each word is
  normalised:
  - the D/DS-form immediate or displacement is masked;
  - the b/bc target is masked;
  - aligned code-address words (inline jump tables) are masked;
  - registers and opcodes are kept.

  Ties go to a call-graph tiebreak. A candidate gets one vote when:
  - a uniquely-matched caller's `bl` at the same instruction index lands on it;
  - its own `bl`s land on the twins of the reco callees;
  - the nearest uniquely-matched neighbours' delta lands on it.

  A tie is resolved only when one candidate is the only one voted, or is dominant (at least 3 votes and at least 3x
  the runner-up).
- **Positive control** (`--control`, reco_normal -> reco_abnormal): 218 of 219 matched, **0 disagreements** with the
  +8 law.
- **kiniro_normal result:**
  - **159 UNIQUE.**
  - **8 TIEBROKEN:**
    - 0x88075C08, 0x880781C8 and 0x88083170 -> same address;
    - 0x88092460 -> 0x88092448;
    - 0x88093760 -> 0x88093758;
    - 0x880937C8 -> 0x880937C0;
    - 0x880A51A0 -> 0x880A7E90;
    - 0x880DCD70 -> 0x880DF950.
  - That makes **167 mapped**: 119 renamed (`#define`) and 48 at the same address. All the renderer-bridge
    PPC_FUNCs (8807ECA0, 8807DD88, 8807D4F8, 8807A578, 88077E78) and 13 of the 15 NVK_GHOOK taps are at the same
    address.
  - **2 AMBIGUOUS, dropped:** 0x880A3F98 (votes 14 vs 13) and 0x880A4B20 (2/1/1).
  - **50 NOMATCH, dropped:** 0x880702B0 0x8808E298 0x8809BE18 0x8809C220 0x880A0360 0x880A0478 0x880A0A10 0x880A0C48
    0x880A3CA8 0x880A4628 0x880EA968 0x880EE880 0x880F1448 0x880FA720 0x88100280 0x88100588 0x881025D0 0x88103048
    0x88104230 0x881332E8 0x88133E30 0x88134048 0x88134658 0x88135D20 0x88137498 0x88137708 0x881378A0 0x88137C28
    0x88137ED8 0x881383A0 0x88138F00 0x8813A5F0 0x8814B930 0x8814BF10 0x8814D400 0x8814F558 0x8814FDF8 0x88153BB0
    0x88153D18 0x88153DF8 0x881602F0 0x88163CF0 0x88168F98 0x881EB1F0 0x881F0BC8 0x881F1968 0x88226EB0 0x882272E8
    0x8822BE60 0x8824E698.
- **How dropping works.** `sub_X` and `__imp__sub_X` are renamed to `sub_X_KDROP`. Nothing in the kiniro tree
  references that name, so the override is never installed into PPCFuncMappings. It also cannot override an
  unrelated kiniro function at reco's address. Any call into it reaches a weak stub in kiniro_hook_stubs.cpp, which
  prints `[kdrop] ...` and exits 97 (`RT_KDROP_CONT=1` turns it into a logged no-op).
  - 50 of the 52 dropped names carry a hook body.
  - 0x88133E30 and 0x88134658 are only declared and wrapped, with no override.
  - No chain: no target is also a renamed key (the generator aborts if one is). No collision either: two reco symbols
    never map onto one kiniro symbol.
- **Drops worth knowing:**
  - **0x8824E698**, the [gemsg]/[msglog] GameEntry wrapper. kiniro's GameEntry is rewritten.
  - **0x880702B0 G_BatchQuadRectlist and 0x8808E298 G_SpriteEmit**, two nvk taps. Both bodies changed codegen; the
    first is at the same address with a different data layout. Neither tap name is read by vk_render.cpp: they are
    `nvk_ev` log taps.
  - **0x881EF798 became UNIQUE** once inline jump-table words were masked.
- **Near-misses for triage.** Same length or nearly, and only a few differing words:
  - 0x88100588 -> 0x881032A8: 3 words, `addi` vs `lis` codegen.
  - 0x88226EB0 -> 0x88225788: prefix-identical, kiniro 26 instructions longer.
  - 0x880A4628 -> 0x880A7310: 19 of 318 words.

  The caller hints are in hook_match_kiniro.txt.

### Descriptor (UNVERIFIED candidates; `derive_desc.py`)

- **Controls.** Both pass:
  - The XEX walk gives reco_normal entry 0x88070588 / ord1 0x8824E698 and reco_abnormal ord1 0x8824E6A0. The walk is
    entry header 0x00010100, then the security info's +0x160 export table, then ordOffset + (imagebaseaddr<<16).
  - The by-twin .data walk onto reco_abnormal gives **+0x60 for all 12 referenced addresses**.
- **kiniro_normal:**
  - entry 0x88070588;
  - **GameEntry ord1 0x8824D678**;
  - field_active **0x885B7838** (8/8 twin votes);
  - gm_frame_gate **0x887A2770** (1/1);
  - asset_commit **0x887A278B** (5/5);
  - mb_credited **0x887A336F** (2/2);
  - mb_mode64 **0x887A33AC** (5/5);
  - mb_reload **0x887A33B4**: *no referencing twin*, interpolated from its mailbox cluster's -0xA1D8;
  - START EXCH **0x8868F6AC** (2/2, the same as §5.2's independent derivation);
  - callback slot 0x887A33D0 (4/4).
- **Nav set** (not in the descriptor; RT_NAV360 uses dshift):
  - scene FSM 0x884CBF58 (15/15);
  - death 0x884CC130 (8/8);
  - slot0 0x884CC69C (5/5);
  - select d76 and credit have no referencing twin.
  - The cluster moved -0xA750 / -0xA748 / -0xA64C, so **not** one shift.
- **dshift = -0xA1E8 (0xFFFF5E18).** This is the EXCH twin delta, chosen so the one dshift consumer that WRITES
  (RT_STARTWIRE) hits the candidate. RT_NAV360 reads garbage under kiniro until step 7's RT_NAVMOD.

### Proof of bind (`scripts/kiniro_bind_mac.sh`, three boots under the drive lock)

| Boot | [modreg] summary | L1 GREY rows | Black Label row on the TOP MENU (cursor on it) |
|---|---|---|---|
| k4a_force: 3-slot host build/kin, `RT_DLCFORCE=1` | `3/3 module DLL(s) bound, hosted modeIdx mask=0x13, boot module=reco_normal` | 1, 3 | **un-greyed**: caption says Black Label will be played, A = decide |
| k4a_nodlc: 3-slot host, no DLC data | `3/3 ... mask=0x13` | 1, 3 | greyed by the **shell's own DLC gate** (`[xenum] DLC gate: entry 0 -> MISSING`): "purchase on Xbox LIVE Marketplace required" caption |
| k4a_ctl2: default 2-slot host build/kinnr, `RT_DLCFORCE=1` | `2/2 ... mask=0x03` | 1, **2**, 3 | greyed by **L1** (the control) |

- All three kiniro BOUND lines read `kiniro_normal modeIdx 4 ord1=0x8824D678 code=0x88070000+0x1DDEA4 maps=8375`.
- `IS THE WRONG MODULE`: 0. `[kdrop]`: 0. FATAL: 0.
- The shots are in `_local/nav_mac/k4a_{force,nodlc,ctl2}/shot_2.png` on the Mac.
- So Black Label needs **both** the bound dylib (L1) **and** the DLC data (or RT_DLCFORCE) to un-grey. Step 3's boots
  will need the user-extracted DLC (§1.1) or `RT_DLCFORCE=1` plus a crash on load.

### Non-regression (default `MODULES`, `OUTDIR=build/kinnr OBJSFX=_kinnr`): BUILD_OK, host + 2 dylibs

- **`kin_nr arcade 1`:**
  - `[modreg] 2/2 ... mask=0x03`;
  - ARCADE decided (`[modeidx] ... ARCADE`) and the demo started (`demo_go=1`);
  - `END fatal=0 vkerr=0 slowframe=0 dropout=0 audio_stall=0 underruns=0`.
- **`kin_nr360 x360 1`:**
  - `[modreg] 2/2`;
  - `[modswap] #2 DONE -- live module is now reco_abnormal`;
  - `END fatal=0 vkerr=0 slowframe=0 dropout=1 audio_stall=0 underruns=0`.
  - The one dropout is at f1381, on the shell title **before** the swap (log line 1471 vs the swap at 1555). That is
    the known title-dropout residual of the RT_POOLRELEASE default (NOTE_fnf_shell_defects 2026-10-30). Nothing this
    step compiles into the default host or modules changed.

### Still UNVERIFIED / owed

- **Descriptor values.** All 6 addrs (mb_reload is interpolated), entry_ord1 0x8824D678, the START EXCH word and dshift.
- **Nav set.** d76 and credit are underived, and RT_NAV360 is wrong under kiniro.
- **The other `0x88...` literals** in merged_game.cpp (~314) and in the 167 mapped hooks' bodies are reco_normal
  .data addresses, and **none are gated per module**.
  - Most are env-gated instruments, but a hook that is on by default and writes a reco literal would corrupt kiniro
    .data.
  - Audit the 167 mapped hook bodies for default-on literal writes **before** the first kiniro boot.
- **Dropped hooks.** 52 are OFF. Whether kiniro reaches stage 1 without any of them is step 3+.
- **Step 4c for kiniro_abnormal is not started.** It needs a map built off this one by the +8 law and the piecewise
  data map (§4).

### Exact commands

```bash
python3 out_kiniro/tools_kiniro/gen_symbol_map.py --imgdir _local/kiniro/img --control      # must say 0 disagreements
python3 out_kiniro/tools_kiniro/gen_symbol_map.py --imgdir _local/kiniro/img [--check]      # (re)writes map + stubs + evidence
python3 out_kiniro/tools_kiniro/derive_desc.py   --imgdir _local/kiniro/img                 # descriptor candidates + controls
MODULES="normal abn kiniro" OUTDIR=build/kin OBJSFX=_kin bash build_mac_dll.sh               # BUILD_OK -- host + 3 module dylibs (~5 min)
RT_DLCFORCE=1 bash scripts/kiniro_bind_mac.sh k4a_force build/kin/futari_combined              # takes the drive lock itself
OUTDIR=build/kinnr OBJSFX=_kinnr bash build_mac_dll.sh                                         # default (rc) shape
BIN=build/kinnr/futari_combined bash _local/g5/g5_run.sh kin_nr arcade 1
BIN=build/kinnr/futari_combined bash _local/g5/g5_run.sh kin_nr360 x360 1
```

### What step 3 (indirect harvest) should do first

1. **Audit the 167 mapped hooks** in merged_game.cpp for default-on (non-env-gated) stores to `0x88...` literals, and
   gate them on `FUTARI_MODULE != 4` or route them through the descriptor. The descriptor-driven GA_* fields are
   already per-module. Without this, the first kiniro boot can corrupt its own .data.
2. **Get Black Label data.** Either the user confirms and extracts the DLC to a *private* game root (never assets/),
   or boot with `RT_DLCFORCE=1` and expect the ROM load to fail.
3. **Run the loop.** Decide Black Label ARCADE on the 3-slot host. `RT_STARTMODULE=kiniro_normal` would skip the
   menu, but the shell's loader path is the one the swap was proven on. Collect `[indirect] UNMAPPED guest
   target=0x88...`, `[kdrop]` and FATAL lines, add the functions to config/futari_kiniro.toml, run
   regen_kiniro_mac.sh, rerun gen_symbol_map.py (the function extents change), rebuild, and repeat.
4. **Positive-control the descriptor.** Check field_active and the mailbox writes on the first live boot.

## Step 3 (2026-10-31, Mac): FIRST BLACK LABEL BOOT -- title, hub, Mode Select, Character Select, stage 1, GAME OVER

Commit 77644df (+ the docs/script follow-up). Host `build/kin` (3-slot, `MODULES="normal abn kiniro" OUTDIR=build/kin
OBJSFX=_kin`), private game root `_local/blroot` on the Mac. **The module runs.** Three drives, none with a FATAL, an
`[indirect] UNMAPPED`, a `[kdrop]`, a `VK_ERROR` or an `IS THE WRONG MODULE` line:

| Drive | What happened | Shots (`_local/nav_mac/<tag>/`) |
|---|---|---|
| `k3_boot1` (90 s hold) | Decide reached the arcade_front panel ("Black Label Arcade" card, "アーケード版をプレイします。"); the second A gave the shell's **"the DLC on the storage device cannot be read, download it again"** dialog. Cause in the log: `[file] open "bldata:\Rom\cg_black.bin" ... -> MISS`. | shot_2 panel, shot_3 dialog |
| `k3_boot2` (120 s hold, mount fix in) | `[modeidx] modeIdx=4 (ARCADE, title=2)` -> `[modswap] #2 DONE -- live module is now kiniro_normal`; DllMain, `XexGetProcedureAddress(ord 1) -> 0x8824D678`, the game-main spawn chain (`[gm]` 87F88 -> F798 -> 168D48), pump ticking (87,000 `[pump]` calls in 120 s), **legal screen (2007/12/11), then the Black Label title** (ブラックレーベル logo, hi-score table, ©2007,2009 CAVE), ~270 draws/frame, SE bank (70 cues) + VOICE cues playing. 64 `[kgate] RT_SNDQFREE REFUSED` (the cap). | shot_3 legal, shot_6/11 title |
| `k3_play1` (START, A x4, 120 s hold) | START -> **hub** (`[p0build] menu_game_title`: SCORE ATTACK / NORMAL PLAY / TRAINING / ... / RETURN TO TOP MENU; A on SCORE ATTACK gives the "sign in to Xbox LIVE for the ranking" dialog) -> **Mode Select (Original / Maniac / God, timer)** -> **Character Select (Reco & Kiniro, 1P)** -> BGM `m01_slct` -> `m02_stg1` (**stage 1**) -> `m05_govr` -> **GAME OVER (HIGH 53837836, Original Mode)** -> "save the replay?" dialog, parked there to the end. `[startwire]` fired 6x at the candidate EXCH 0x8868F6AC. | shot_5 hub+dialog, shot_7 mode, shot_8 chara, shot_9 stage, shot_10 game over, shot_12 replay prompt |

### What had to change (all byte-inert for the reco pair; non-regression below)

1. **Literal audit, then a compile-time gate** (`merged_common.h` `FUTARI_RECO_DATA` / `rt_kgate(lever)`). merged_game.cpp
   has 131 hooks and 464 lines with a `0x88……` reco_normal .data literal. kiniro_symbol_map.h DROPS 38 of the hooks
   (never installed, their literal stores cannot run) and installs 93; 51 of those carry literals, **but every literal
   STORE and every literal-driven register/call override among them sits behind one of eight `RT_` levers**:
   RT_SNDQFREE (the only one the drive scripts set), RT_PUMPFIX, RT_CLEAR312, RT_NOPAUSE, RT_TICKGP, RT_FIXSPAWN,
   RT_FORCEPLAYER(2), RT_JOINMARK. Each is now also gated on `rt_kgate("<lever>")`: a constant `true` on modules 0/1,
   a once-per-lever `[kgate] ... REFUSED` on module 4. Everything else is a READ, harmless under the flat 4 GB guest
   arena (instruments log garbage). RT_STARTWIRE stays live on purpose: it stores through `futari_desc()->dshift`,
   i.e. the descriptor's EXCH candidate, and the log names the address it hit.
2. **The DLC is a real mount.** The shell passes the root name `bldata` to XamContentCreateEx(type 2) and then opens
   `bldata:\Rom\cg_black.bin` / `bldata:\Rom\dropprm.bl`. The stub now registers that root **read-only** onto
   `<RT_GAME_ROOT>/media` (`rt_content_register_root_ro`; fopen "rb" only, never create/truncate whatever the
   disposition), because tools/extract relocates the package's `Rom/` there. Nothing in the reco pair opens a
   `<dlcroot>:\` path.
3. **Distinct-target logging** for the harvest loop (`[indirect] UNMAPPED NEW #k target=... (lr=...)`, 256 max) and
   `harvest_unmapped.py` (log -> `futari_kiniro.toml` rows, size = next function start; +8-law port to the abn toml).
   **Harvest result so far: 0 targets** through title, hub, mode/character select, stage 1 and game over.
4. **Drive**: `scripts/kiniro_boot_mac.sh <tag> <host> [hold] ` with `KIN_STEPS` for the post-swap inputs;
   `scripts/run_mac.sh` honours a preset `RT_GAME_ROOT`.

### Private game root (never assets/)

`_local/blroot/` = symlinks to every entry of `assets/` (media/ and media/Rom/ as real directories of symlinks) plus
the three DLC files from `python3 tools/extract/futari_extract.py dlc --out _local/bl_extract --no-verify`
(cg_black.bin 57,743,518 / cg_blackhi.bin 216,869,269 / dropprm.bl 3,184). The bundle copies `assets/`, so the DLC
stays out of it; the drives pass `RT_GAME_ROOT=$PWD/_local/blroot`.

### Non-regression (default `MODULES`, `OUTDIR=build/kinnr OBJSFX=_kinnr`, same tree): BUILD_OK host + 2 dylibs

- `kin3_nr arcade 1`: `[modreg] 2/2 ... mask=0x03`, ARCADE decided, demo started (`demo_go=1`),
  `END fatal=0 vkerr=0 slowframe=0 dropout=0 audio_stall=0 underruns=0`.
- `kin3_nr360 x360 1`: `[modswap] #2 DONE -- live module is now reco_abnormal`, `END fatal=0 vkerr=0 slowframe=0
  dropout=1 audio_stall=0 underruns=0`; the one dropout is at f1384 on the shell title (log line 1473), BEFORE the
  swap (line 1557): the known RT_POOLRELEASE title residual (NOTE_fnf_shell_defects 2026-10-30), unchanged.
- No `[kgate]` and no `UNMAPPED NEW` line in either reco leg (as designed).

### Still UNVERIFIED / owed after step 3

- **Descriptor values** are still candidates. Evidence for two of them now: `entry_ord1 0x8824D678` is what the
  loader resolved and the module booted through it; the START EXCH word 0x8868F6AC took the 1P-START OR and the game
  went from the title into the hub/select flow. field_active / gm_frame_gate / asset_commit / the three mailboxes have
  NOT been positive-controlled (step-7-style probes).
- **The nav set** (RT_NAV360 reads) is wrong under kiniro (piecewise shifts); the RT_NAVREAL observer lives in a
  DROPPED hook (sub_88138F00), so no `[navreal]` lines exist for Black Label yet.
- **Gameplay quality**: one no-input run to game over; nothing about pacing, pixels or audio has been gated for this
  module (stagepix / boss plate / q-census all assume reco_normal's data). The 52 dropped hooks are OFF; which of
  them Black Label needs is the step-3+ triage.
- **kiniro_abnormal (step 4c)**: not started; `harvest_unmapped.py --apply` already ports rows by the +8 law.
- Ver 1.01 DLC root name: the same type-2 path will register whatever root the shell names; untested.

### Exact commands

```bash
python3 tools/extract/futari_extract.py dlc --out _local/bl_extract --no-verify     # the 3 DLC files, private
#  ... build _local/blroot as above (symlinks into assets/ + the 3 files)
MODULES="normal abn kiniro" OUTDIR=build/kin OBJSFX=_kin bash build_mac_dll.sh      # 3-slot host + 3 dylibs
bash scripts/kiniro_boot_mac.sh k3_boot2 build/kin/futari_combined 120               # title only
KIN_STEPS='10 w:\[p0build\]\ menu_game_title s:3 shot 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot' \
  bash scripts/kiniro_boot_mac.sh k3_play1 build/kin/futari_combined 120             # hub -> stage 1 -> game over
python3 out_kiniro/tools_kiniro/harvest_unmapped.py _local/nav_mac/k3_play1/guest.log [--apply]
OUTDIR=build/kinnr OBJSFX=_kinnr bash build_mac_dll.sh                                # default (rc) shape
BIN=build/kinnr/futari_combined bash _local/g5/g5_run.sh kin3_nr arcade 1
BIN=build/kinnr/futari_combined bash _local/g5/g5_run.sh kin3_nr360 x360 1
```

## Step 3b (2026-10-31, Mac): descriptor POSITIVE CONTROLS and the Black Label SMOKE GATE

### RT_DESCPROBE: the six fields, same drive on both modules

`merged_game.cpp` sub_88090480 (the game service callback, live on every module, ~700 calls/s) reads the six
`GA_*` fields through `futari_desc()` and edge-logs them (`[descprobe]`, gm_frame_gate as a toggle count). The
same drive (`scripts/kiniro_boot_mac.sh`, `KIN_MODEIDX=0` = the Ver 1.5 ARCADE control, `4` = Black Label):
hub -> DOWN -> NORMAL PLAY -> A x5 -> stage 1 -> idle death -> GAME OVER, 120 s. Drives `k3b_ctl` / `k3b_kin`.

| Field | reco_normal (proven addresses) | kiniro_normal (candidates) | Verdict |
|---|---|---|---|
| field_active | 0 -> 1 at t+23.2 s (stage entry), stays 1 | 0 -> 1 at t+19.6 s (stage entry), stays 1 | **CONTROLLED** |
| gm_frame_gate | toggles every frame (1,235 by t+82 s), then FROZEN through game over | toggles every frame (1,337 by t+74 s), then frozen | **CONTROLLED** |
| mb_credited | 0->1 at hub entry (t+10.5), 1->0 in the stage (t+42), 0->1 at game over (t+74) | 0->1 (t+7.0), 1->0 (t+33), 0->1 (t+64): the same three edges | **CONTROLLED** |
| asset_commit | 0x00 throughout | 0x00 throughout | not discriminated (flat on the control too) |
| mb_reload | 0 throughout; also 0 on the hub-B -> confirm -> A return route (`k3c_ctl`) | 0 throughout (`k3c_kin` the same) | not discriminated |
| mb_mode64 | 0 throughout (both routes) | 0 throughout | not discriminated |

Plus the two that the first boot already answered: `entry_ord1 0x8824D678` (the loader resolved it and the module
booted through it) and the START EXCH word 0x8868F6AC (the 1P-START OR fired 6x and the title went into the flow).
So 5 of the 8 descriptor values are LIVE-CONTROLLED; asset_commit / mb_reload / mb_mode64 stay structural candidates
(no drive so far makes them move on the control either; a drive that does is what would judge them).

### The gate: `scripts/kiniro_gate_mac.sh <tag> <host>` -- a REGRESSION gate, not a quality gate

Runs the play drive with the dropout census armed and asserts: decide (modeIdx 4) · swap to kiniro_normal · hub after
the swap · stage (BGM m02_stg1) · game over (BGM m05_govr) · >= 150 draws/frame in the stage · 0 FATAL · 0 VK_ERROR ·
0 UNMAPPED · 0 kdrop · 0 wrong-module · 0 DROPOUT-CONFIRMED after the swap (the pre-swap shell-title dropouts are the
known RT_POOLRELEASE residual, reported as a NOTE) · every `[kgate]` lever is one of the eight the audit listed.
First run `k3gate1`: **13 PASS / 0 FAIL** (max 304 draws/frame in the stage; 8 pre-swap title dropouts noted).
Repeatability the same morning: modeIdx 4 `k3gate{1,2,3}` 3/3 all-PASS, modeIdx 5 `k4cgate{1,2,3}` 3/3 all-PASS (pre-swap
title dropouts 7-8 each time, 0 after the swap). No reference pixels exist for this module, so there is no
stagepix/boss-plate analogue yet.
Default-build (`build/kinnr`) non-regression after step 4c: ARCADE legs `kin4_nr{,2,3}` dropout 9 / 0 / 0 (the 9 = 7 on the
shell title before the decide + 2 at the demo-start transition, f1535/f1580, not seen in the other two legs or in
`kin3_nr`: the known intermittent RT_POOLRELEASE title mode), x360 leg 1 pre-swap title dropout; fatal/vkerr/underruns 0 everywhere.

## Step 4c (2026-10-31, Mac): kiniro_abnormal = Black Label XBOX 360 MODE (modeIdx 5) BOOTS AND PLAYS, first try

Everything mechanical off kiniro_normal, as §4 predicted:
- **Symbol map by the +8 law**: `out_kiniro/tools_kiniro/gen_symbol_map_abn.py` composes kiniro_symbol_map.h with
  "at or below 0x880E1B68 keep, at or above 0x880E1C60 +8" -> `out_kiniro_abn/kiniro_abn_symbol_map.h` (119 renamed,
  48 same, 52 DROPPED = the same set; `kiniro_hook_stubs.cpp` copied). The law's own control: **8243/8243**
  kiniro_normal function starts land on a kiniro_abnormal function start, none inside the window.
- **Descriptor by twin vote**: `derive_desc_abn.py` (derive_desc.py's refs/translate, source kiniro_normal, target
  kiniro_abnormal, pairs = the +8 law). Control reco_normal -> reco_abnormal reproduces the +0x60 law for all 13
  fields, 0 disagreements. Result: every kiniro field is **+0x100** with unanimous votes (field_active 15/15,
  gm_frame_gate 1/1, asset_commit 5/5, mb_reload 15/15, mb_credited 5/5, mb_mode64 9/9, START EXCH 2/2, callback
  slot 6/6); entry_ord1 = 0x8824D680 (+8); code size 0x1DDEAC (+8). `g_futari_desc_kiniro_abnormal`, static_asserts
  pin the pair's +8 / +0x100 relations and the accessor gained `FUTARI_MODULE == 5`.
- **Build/registry**: `MODULES=... kiniro_abn` arm (tree out_kiniro_abn, modeIdx 5, dylib futari_game_kiniro_abn),
  its own opt-in host flag `-DFUTARI_HOST_KINIRO_ABN=1` (fourth `g_slots[]` row), shim
  `moduleshim/module_shim_kiniro_abnormal.cpp` (by copy, like kiniro_normal's), gen_host_abi MODNAMES row 5, the
  out_kiniro support headers copied into out_kiniro_abn. `kiniro_boot_mac.sh` presses LEFT on the arcade_front panel
  for an odd `KIN_MODEIDX`; the gate takes `KIN_MODEIDX=5`.
- **First boot `k4c_boot1`** (host build/kin4, `MODULES="normal abn kiniro kiniro_abn"`): `[modreg] 4/4 ... mask=0x33`,
  `[modeidx] modeIdx=5 (XBOX-360 MODE, title=2)`, `[modswap] #2 DONE -- live module is now kiniro_abnormal (entry
  ord1=0x8824D680, code 0x88070000+0x1DDEAC)`, `bldata:\Rom\cg_blackhi.bin` opened through the read-only DLC mount,
  legal -> title -> hub -> Mode Select -> Character Select -> **stage 1 in the 360-mode HD field with its own HUD
  (bomb counter, "PRESS 2P START")** -> idle death -> GAME OVER. 0 FATAL / 0 UNMAPPED / 0 kdrop / 0 VK_ERROR.
  `[descprobe]` on the +0x100 candidates shows the SAME pattern as kiniro_normal and the reco control (field_active
  0->1 at t+19.7 s, mb_credited three edges, gm_frame_gate toggling then frozen at game over): field_active,
  gm_frame_gate, mb_credited, entry and START EXCH are live-controlled for this module too; asset_commit / mb_reload /
  mb_mode64 remain structural.
- Shots: `_local/nav_mac/k4c_boot1/shot_{3,7,8,9,10}.png` on the Mac.

## Step 3c (2026-10-31, Mac): the NAV OBSERVER SET for both kiniro modules, live-controlled

RT_NAVREAL/RT_NAV360 live in sub_88138F00, which the kiniro map DROPS, so Black Label had no `[navreal]` markers.
`RT_NAVMOD=1` (merged_game.cpp, the same pump-hook probe point as RT_DESCPROBE) edge-logs a per-module nav set:
scene_fsm, select_d76, death, slot0, credit. kiniro_normal's addresses come from derive_desc.py's twin votes
(scene -0xA750 15/15, death -0xA748 8/8, slot0 -0xA64C 5/5; select_d76 had no referencing twin, so both shift
candidates were read; credit = slot0+2), kiniro_abnormal's are +0x100 (derive_desc_abn.py, 44/44, 17/17, 7/7, d76
candidates 2/2 and 3/3). Same play drive on all three modules (`k3d_nav0/4/5`), hold 100 s:

| module | the 17 edges (pump-hook timeline) |
|---|---|
| reco_normal (control) | scene 0,1 (boot) -> 3,5 (hub, t+10.5 s) ; d76 1 -> 2 (t+23 s, slot0=1 cred=3) -> 3,4 (stage) ; cred 3,2,1,0 (deaths) ; slot0 0 -> d76 5,6,8 -> scene 2 (game over, t+80 s) |
| kiniro_normal | the SAME sequence, same order, t+7.0 / 19.6 / 71 s |
| kiniro_abnormal | the SAME sequence, same order, t+7.0 / 19.6 / 71 s |

Verdict: **scene_fsm, select_d76, slot0 and credit are LIVE-CONTROLLED** for both Black Label modules. select_d76 is
the -0xA748 candidate (kiniro 0x884CC044, abn 0x884CC144); the -0xA750 one (0x884CC03C) stayed 0 throughout and is
refuted. `death` stayed 0 on the control as well (this route does not exercise it). So a marker-driven Black Label
drive can now wait on `[navmod] ... d76=8` (real stage) / `scene=2` (teardown) exactly as the Ver 1.5 drives wait on
`[navreal]`.

## Step 3e (2026-10-31): 12-minute Black Label ATTRACT SOAK (the G5 oracle shape) -- FLAT

`k3soak1`: kiniro_normal decided, no inputs after the swap, 720 s hold, RSS sampled every 30 s (`kiniro_boot_mac.sh`
now writes `rss.csv`). RSS 290 MB at boot -> 368 MB at 2 min -> 375 MB at 10 min -> 378 MB at the end: **+7 MB over
the PREREG_q5 window = FLAT** (the Ver 1.5 ARCADE figure after the G5-fix was +9/+6, the pre-fix control +139).
40 `[poolrelease]` sweeps after the swap, 0 DROPOUT-CONFIRMED after the swap, 0 FATAL / UNMAPPED / kdrop / VK_ERROR.

## Step 3d (2026-10-31): the 52 DROPPED hooks, triaged statically

What a dropped hook means: merged_game.cpp's override for a reco_normal symbol with no kiniro twin is never
installed, so under Black Label the GAME'S OWN function runs unmodified. The question is whether any of them was a
FIX the port needs rather than an instrument. Census over the 52 (`out_kiniro/kiniro_symbol_map.h` NOMATCH +
AMBIGUOUS; store / return-override / getenv per body):

| Class | Count | Members (abridged) | Under Black Label |
|---|---|---|---|
| no override body at all (nvk_game_hooks taps or `__imp__`-only references) | 14 | sub_880702B0, 8808E298, 880A0360/0478/0A10/0C48, 880F1448, 88133E30, 88134658, 881378A0, 881383A0, 88153BB0/D18/DF8 | nothing to lose |
| log-only wrappers, no store, no return change | 29 | sub_8809BE18, 8809C220, 880A3CA8, 880A3F98, 880A4B20, 880EA968, 880EE880, 880FA720, 88100280, 88100588, 881025D0, 88104230, 881332E8, 88134048, 88135D20, 88137C28, 8813A5F0, 8814B930, 8814BF10, 8814D400, 8814F558, 8814FDF8, 881602F0, 88163CF0, 881EB1F0, 881F0BC8, 88226EB0, 8822BE60, 880A4628 | instruments silent (RT_S5 / RT_744P / RT_JOINP / RT_TRACERES / RT_CARDFSM / RT_WGATE families) |
| env-gated LEVERS that store (default OFF, none drive-set) | 7 | sub_88103048 (RT_DECIDE/RT_744P), 88137498 (RT_START352/RT_MENUADV), 88137708 (RT_MENUADV), 88137ED8 (RT_CSHOLD*/RT_SLOTHOLD), 881F1968 (RT_F1968_POKE), 88168F98 (RT_SLOWCLAMP return clamp), 8824E698 (RT_TRAINSTAGE poke; also the `[msglog]` / `[gemsg]`-side GameEntry instrument) | levers unavailable; the GameEntry wrapper's logs are absent (no `[msglog]` for BL) |
| the OBSERVER + its holds | 1 | sub_88138F00: RT_NAVREAL / RT_NAV360 observers, RT_NAVREAL>=2 holds, the msg-14 credited arm (GA_MB_RELOAD=2 / GA_MB_CREDITED) | replaced by RT_NAVMOD (step 3c) for the observer part; the holds/arms are levers, OFF by default |
| **DEFAULT-ON FIX** | **1** | **sub_882272E8**: `RT_DIVGUARD` (default ON) repairs a zero divisor at 0x887ACE14 before the original divides (`[sfpe]`) | **absent under Black Label.** Its reco function has no kiniro twin, and the divisor's kiniro address is unknown. No FPE has been seen in any BL drive (title, hub, select, stage 1, game over, 12-min attract), so either Black Label never hits the zero or the crash is in a flow not yet driven. Candidate for the first BL-specific hook: find the twin by hand, re-derive the divisor address. |

So the port's one default-on game-side repair that Black Label lacks is the divide guard; everything else dropped is
instrumentation or an opt-in lever.

## Step 3f (2026-10-31): the DIVIDE GUARD's Black Label twin -- found by hand, hooked, proved live

The one default-on fix step 3d found missing. `PPC_FUNC(sub_882272E8)` in merged_game.cpp (`RT_DIVGUARD`, default
ON, tag `[sfpe]`) repairs the player ship's blink-period divisor at 0x887ACE14 from 0 to 1 before the player-ship
draw callback divides by it (`divwu`; the ucode's `twllei` trap is dropped by XenonRecomp, so a zero is a host
integer-divide fault). gen_symbol_map.py found no whole-body twin (NOMATCH, "0 cand. no matched caller"), so under
Black Label the hook was DROPPED and the game's own body ran unguarded.

### The twin: `sub_88225C28` (kiniro_normal) / `sub_88225C30` (kiniro_abnormal, the +8 code law)

Why the matcher could not see it: the body changed (reco 607 insns, kiniro 630; the normalised bodies are 95.2 %
similar with a cluster of inserted words around insns 43-100 and one extra callee), and it has NO `bl` caller in
either image -- it is registered by ADDRESS (the ship constructor passes it to the id-33 registrar), the class the
callback census is blind to. Four independent routes agree on the candidate (`out_kiniro/tools_kiniro` matcher
classes reused from a scratch script over the four flat images):

1. **The registrar's argument.** The only reference to 0x882272E8 in reco_normal is `sub_8814DDC8` (ShipCtor) at
   instruction index 159 (`lis/addi`, the id-33 registration). ShipCtor is UNIQUE -> `sub_8814F2E0` in kiniro, and
   that body's lis-tracked reference at the SAME index 159 is **0x88225C28**.
2. **Neighbour delta.** The nearest uniquely matched functions on both sides, `sub_88227160 -> 0x88225AA0` and
   `sub_88227220 -> 0x88225B60`, both move by -0x16C0; 0x882272E8 - 0x16C0 = **0x88225C28**.
3. **Callees.** The two reco callees with UNIQUE twins (`sub_881538C0 -> 0x88154BD8`, the sprite-emit helper called
   18 times, and `sub_8814B0F0 -> 0x8814C6C0`) are both called by 0x88225C28; the three per-player notifies
   (`sub_881E3100/6278/5198`) have no unique twin, kiniro's body calls `0x881E2D70/61F0/4FF0` in their place.
4. **The divide itself.** Of the 5 kiniro_normal functions containing a lis-tracked `lwz` feeding a `divwu`,
   exactly one is anywhere near this size: 0x88225C28 (630 insns). Same shape, two instructions earlier:

| image | function | lis | lwz | divwu | divisor (.data) | initial value in the image |
|---|---|---|---|---|---|---|
| reco_normal | 0x882272E8 (607 insns) | insn 61 `lis r10,-30597` | insn 62 `lwz r10,-12780(r10)` | insn 63 `divwu r8,r11,r10` | **0x887ACE14** | 0 |
| kiniro_normal | 0x88225C28 (630 insns) | insn 59 `lis r11,-30598` | insn 60 `lwz r11,11308(r11)` (0x2C2C) | insn 61 `divwu r9,r10,r11` | **0x887A2C2C** | 0 |
| kiniro_abnormal | 0x88225C30 (630 insns, body identical to kiniro_normal after normalisation) | insn 59 `lis r11,-30598` | insn 60 `lwz r11,11564(r11)` (0x2D2C) | insn 61 `divwu r9,r10,r11` | **0x887A2D2C** (the +0x100 data law) | 0 |

The divisor was READ from each body, not shifted: kiniro's .data moved the word by -0xA1E8 while the code moved by
-0x16C0, and the abnormal twin's data sits +0x100 from kiniro_normal's as derive_desc_abn found for every other
field. Both kiniro symbols are function starts (`ppc_func_mapping.cpp`, `PPC_EXTERN_FUNC` in `ppc_recomp_shared.h`),
neither address is a reco_normal function start, and neither appears in either symbol map, so the maps pass the
names through untouched.

**What the divisor is** (`futari_decomp draft_882272E8.md`, r22): the ship's BLINK-PERIOD divisor;
`(entity[164] / *(u32*)divisor) & 1` picks one of two packed tint words for the invulnerability blink. Its only
writer is `sub_881378A0` (reco, `stw` at insn 142; the stored value is a mode-selected period, `li r11,500` /
`li r11,2000` by a `cmpwi r8` chain) -> kiniro `sub_8813ABF0` (`stw` at insn 90; kiniro_abnormal `sub_8813ABF8`).
Other readers: reco `sub_880F5438` (x2), `sub_88103338`, `sub_8815E208`; kiniro `sub_880F7D38` (x2), `sub_88106080`,
`sub_8815FB20` and one reader with no reco counterpart, `sub_88148FA8`. **The guard is NOT moot for Black Label:**
the word is 0 at load in all three images (the eight words around it are 0 too) and is only made non-zero by that
writer, so a draw before the write divides by zero exactly as in Ver 1.5.

### The hook (merged_game.cpp, right after the reco guard; reco hook untouched)

`#if FUTARI_MODULE == 4` -> `PPC_FUNC(sub_88225C28)` guarding 0x887A2C2C; `#elif FUTARI_MODULE == 5` ->
`PPC_FUNC(sub_88225C30)` guarding 0x887A2D2C; both through one `kin_divguard(base, module, addr)`: the same
`RT_DIVGUARD` lever (default ON, `RT_DIVGUARD=0` reverts), the same 0 -> 1 repair, `[sfpe] <module> divisor@... was
0 -> repaired to 1` (first 8), plus a once-per-run `[sfpe] <module> hook entered (sub_... twin of sub_882272E8;
divisor@...=<value>; RT_DIVGUARD on|off)` so a drive proves the override is installed and shows the value it read.

### Proof (Mac, kiniro/divguard worktree sharing the main checkout's generated trees, `_local` and `assets`)

The rc3 dry run owned the Mac until 12:13; the proof ran after it from a `kiniro/divguard` worktree (main
checkout untouched), module-only rebuild of all four modules into `build/kinnr` (BUILD_OK, 92 s; `nm` shows
`___imp__sub_88225C28` / `___imp__sub_88225C30` in the two Black Label dylibs, i.e. the override is linked in).

| run | mode | result | `[sfpe]` |
|---|---|---|---|
| `dg_gate4` | 4 kiniro_normal | 14 PASS / 1 FAIL -- the one FAIL is `PIX-REGRESS` (hub shot_4 vs the banked reference: 7.57 %, tolerance 6 %); every engine assert PASS (decide, swap, hub, stage, game over, draws 314/frame, 0 FATAL / VK / UNMAPPED / kdrop / wrong-module / post-swap dropout, kgate known, PIX-RICH 31,474 colours) | line 3246 `kiniro_normal hook entered (... divisor@0x887A2C2C=3000; RT_DIVGUARD on)`, 0 repairs |
| `dg_gate5` | 5 kiniro_abnormal | **15 PASS / 0 FAIL** (draws 306/frame, PIX-RICH 30,649, PIX-REGRESS 2.28 %) | line 3341 `kiniro_abnormal hook entered (... divisor@0x887A2D2C=3000; RT_DIVGUARD on)`, 0 repairs |
| `dg_gate4b` | 4 kiniro_normal, rerun | 14 PASS / 1 FAIL -- PIX-REGRESS now **PASS at 3.93 %** (the backdrop phase, as argued below); the one FAIL is `dropout after swap (1)`: ONE `DROPOUT-CONFIRMED` (f2068, len=3, surface vs=1/ps=2, log line 2596) between the swap (line 1766) and the hub (2681), i.e. on the Black Label module's own TITLE, the same vs=1/ps=2 title class as the 7 pre-swap ones, **before the hook's first entry (line 3279)**; first post-swap dropout in 25 Black Label banks | line 3279 `hook entered ... divisor=3000`, 0 repairs |
| `dg_gate4c` | 4 kiniro_normal, third sample | **15 PASS / 0 FAIL** (draws 300/frame, PIX-RICH 31,485, PIX-REGRESS **0.00 %**, 0 post-swap dropouts) | line 3284 `hook entered ... divisor=3000`, two lines before the stage cue (3286), 0 repairs |
| `dg_drive4` | 4, `RT_DIVGUARD=1`, the play route | title -> hub -> select -> stage 1 -> game over, 0 FATAL / kdrop / UNMAPPED | line 3023 `hook entered ... divisor=3000`, two lines BEFORE `BGM cue1 (m02_stg1)` = the first player-ship draw at stage entry; 0 repairs |
| `dg_drive0` | 0 reco_normal control, `RT_DIVGUARD=1`, same route | same route, 0 FATAL | **none**: the reco guard only logs a REPAIR, and its divisor was already non-zero on this route too |

**Drive point.** The hook is first entered at stage entry (the frame before the stage-1 BGM cue; shot_4 at the hub is
18 s earlier), which is where the ship is first drawn, and it reads **3000**: kiniro's writer `sub_8813ABF0` (li-chain
`3000` / `2000`; reco's chain is `500` / `2000`) has already run by then, in every run of both modes. So on the gate's
route Black Label never divides by zero and the repair path never fires; the reco control logs no `[sfpe]` on the same
route for the same reason (its guard was earned on a different route, the 2026-07-12 RT_SAVE options-menu recipe, and
only logs when it repairs). The guard is LIVE (installed, entered, lever read) and has the same insurance value it has
in Ver 1.5: the word is 0 at load and only that writer sets it.

**The PIX-REGRESS miss on `dg_gate4` is not the hook.** (a) The hook's first entry (log line 3246) is after shot_4
(taken at t+48 s, the hub); nothing of this change had executed when the frame was captured. (b) The differing pixels
are confined to the menu-panel column (x 398-887); the panel itself is identical in geometry and brightness (panel
mean RGB 90.7/76.9/68.0 vs 90.1/74.8/66.4, bright-pixel share 17.9 % vs 16.5 %, no translation improves the match);
what differs is the animated backdrop seen THROUGH the translucent panel, i.e. the animation phase at capture, the
same mechanism that already put XBOX 360 MODE at 2.41 % when its reference was banked (and 2.28 % here). (c) The engine
built here differs from the build that banked the reference only by this hook (the two commits between are scripts
and docs). The three ARCADE samples on this build read 7.57 / 3.93 / 0.00 %: the rung measures the backdrop's phase at
capture, not the build. Owed: a phase-insensitive hub compare (mask the backdrop) or a tolerance from more samples.
Likewise `dg_gate4b`'s single post-swap dropout sits on the Black Label module's own title screen (between the swap and
the hub), is the vs=1/ps=2 title class every run shows 7-9 times before the swap, and precedes the hook's first
execution by ~700 log lines; it is the known title residual showing up on the second title of the drive, not this
change (0 post-swap in the other four Black Label runs of this build and in the 20 earlier banks).

**Verdict: guard ADDED and LIVE in both Black Label modes; needed in principle (divisor 0 at load, same write-before-
draw dependence as Ver 1.5), not exercised on the gate's route (3000 at first draw, 0 repairs, reco control also silent).**
Owed: a Black Label pass over the route that made reco repair (the options-menu recipe) to see whether the kiniro
writer order differs there.

### Exact commands

```
# twin hunt (Windows, the four flat images copied from the Mac; gen_symbol_map.py's Tree/match reused)
python -I hunt.py           # callers / callees / address refs / neighbour delta / lis-lwz-divwu scan
# Mac proof, after the rc3 dry run released the machine
MODULES_ONLY=1 MODULES="normal abn kiniro kiniro_abn" OUTDIR=build/kinnr OBJSFX=_kinnr bash build_mac_dll.sh
KIN_MODEIDX=4 bash scripts/kiniro_gate_mac.sh dg_gate4 build/kinnr/futari_combined
KIN_MODEIDX=5 bash scripts/kiniro_gate_mac.sh dg_gate5 build/kinnr/futari_combined
RT_DIVGUARD=1 KIN_MODEIDX=4 KIN_STEPS='10 w:\[p0build\]\ menu_game_title s:3 shot 2 s:1.5 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot 1000 s:4 shot' bash scripts/kiniro_boot_mac.sh dg_drive4 build/kinnr/futari_combined 120
RT_DIVGUARD=1 KIN_MODEIDX=0 KIN_STEPS='...same...' bash scripts/kiniro_boot_mac.sh dg_drive0 build/kinnr/futari_combined 120   # reco control
```

## The three calls, taken 2026-10-31 (user: "all three if we can do unattended") -- revert any of them by ruling

1. **Data path = a SECOND ROOT, the player's DLC folder.** `RT_DLC_ROOT`, default `<save dir>/../dlc`: on the Mac
   bundle `~/Library/Application Support/Futari Realcomp/dlc`, on the Deck `~/.local/share/futari-realcomp/dlc`, on the
   PC folder layout `./dlc`, in the developer checkout `./dlc` (cwd). Laid out as `tools/extract/futari_extract.py
   <package folder> --out <that dlc root>` writes it (`media/Rom/cg_black.bin`, `cg_blackhi.bin`, `dropprm.bl`). The
   shell's DLC gate (`rt_dlc_owned`) looks there FIRST, then in the game root (the developer's private-root shape);
   the type-2 mount maps `bldata:` onto whichever root had every required file. Nothing is ever written into assets/.
   The bundle README gained a BLACK LABEL section with the exact command. `[xenum] DLC gate` names the root it used.
2. **Build shape = the Black Label modules ship by default when their trees exist.** `build_mac_dll.sh`'s default
   `MODULES` adds `kiniro` and `kiniro_abn` when `out_kiniro*/ppc_recomp.0.cpp` and the symbol maps are present (a
   machine without them builds the 2-module shape unchanged; `MODULES="normal abn"` forces it). `build_mac_app.sh`
   copies whatever module dylibs the build produced and says so. Without DLC data the row is greyed by the shell's
   own gate (step 4a `k4a_nodlc`), so shipping the engine is inert. Linux/Deck: `build_linux_dll.sh` has NO arms for
   modules 4/5 yet (owed; the Deck image keeps the 2-module shape).
3. **Quality bar = the scorecard below.** Modelled on PLAN_RC1 §0; the gate enforces the mechanical rows.

### Black Label scorecard

| # | Criterion | Mechanism | Status 2026-10-31 |
|---|---|---|---|
| Q1 | boots, decides, swaps, reaches the hub, stage 1, game over; no FATAL / VK_ERROR / UNMAPPED / kdrop / wrong-module | `kiniro_gate_mac.sh` (13 asserts) | **PASS 6/6** runs (3 per mode) |
| Q2 | no renderer dropouts after the swap | gate (`DROPOUT-CONFIRMED` after `[modswap] #2`) | **PASS 6/6** (pre-swap title dropouts = the Ver 1.5 residual, noted) |
| Q3 | a textured stage frame exists | gate pixel rung `PIX-RICH` (stagepix control floor: colours >= 15000, edges >= 15 on the richest post-hub frame) | **PASS** both modes on the default build (`k5gate4` 31,528 colours / 21.4 edges; `k5gate5` 30,642 / 21.6; the Ver 1.5 stage reads ~24k / ~29) |
| Q4 | the hub frame does not drift between builds | gate pixel rung `PIX-REGRESS` (hub shot vs a banked per-mode reference, < 6 % pixels differing by > 40) | references BANKED from `k5gate4/5` (`_local/kiniro/ref/mode{4,5}/hub.png`); reruns `k5gate4b/5b` **PASS** at 0.00 % (ARCADE) and 2.41 % (XBOX 360 MODE, an animated hub element), which is why the tolerance is 6 % and not the 3 % first tried |
| Q5 | memory flat over the attract loop (G5 oracle shape) | `kiniro_boot_mac.sh` soak, `rss.csv` 2 -> 10 min | **FLAT both**: kiniro_normal +7 MB (`k3soak1`), kiniro_abnormal +11 MB (534 -> 545 MB, `k4soak1` on the 4-module default build; 29 pool sweeps, 0 post-swap dropouts) |
| Q6 | descriptor and nav fields are the module's own | RT_DESCPROBE / RT_NAVMOD vs the reco control | 5/8 descriptor + 4/5 nav live-controlled; asset_commit / mb_reload / mb_mode64 / death structural |
| Q7 | the DLC path works for a PLAYER (second root) and stays grey without data | `k3e_dlcroot` (RT_DLC_ROOT, stock assets root) / `k3e_nodlc` (no data) | **PASS**: with the stock assets root and `RT_DLC_ROOT=_local/bl_extract`, `[xenum] DLC gate: entry 0 -> OWNED (data present in .../bl_extract)`, `mount 'BLDATA:' -> .../bl_extract/media (READ-ONLY)`, cg_black.bin opened from there, swap to kiniro_normal, hub reached; with `RT_DLC_ROOT=/nonexistent` and no data in assets: `MISSING (stays grey; ... looked in RT_DLC_ROOT '/nonexistent' and the game root)` on the 4-module host. The Ver 1.01 DLC mounts under its own root name `TEMP_DLC:` through the same path. |
| Q8 | the port's default-on game-side fixes are present | dropped-hook triage + step 3f | **PRESENT**: the one missing fix, RT_DIVGUARD, now has a Black Label hook (sub_88225C28 / sub_88225C30 guarding 0x887A2C2C / 0x887A2D2C, step 3f); gates dg_gate4c 15/15 and dg_gate5 15/15 (dg_gate4 PIX-REGRESS 7.57 % = backdrop phase, dg_gate4b one title-class dropout before the hook ever ran; see 3f), hook ENTERED in both modes at the first ship draw with divisor 3000, 0 repairs needed on the gate route; reco control silent on the same route |
| Q9 | audio: SE/BGM/VOICE banks resolve, no underruns | gate log counts (`underruns=`, `[cue]`) | banks resolve (70-cue SE bank, VOICE, BGM m01/m02/m05); underrun count not yet asserted |
| Q10 | hands-on: a human plays both modes, pads and keyboard, TATE, replay save, continue, ranking dialogs | the owner | **not done** (same as RC1's hands checklist) |
| Q11 | Ver 1.5 unaffected by the 4-module default build | g5 legs + the rc gates on the default build | legs on the auto-4-module `build/kinnr`: ARCADE fatal 0 / dropout 0 but **31 audio underruns** in the leg that started 75 s after the build finished (load 3.1: the post-build indexing landmine of 2026-10-30); x360 clean. The underruns sat in the shell-title boot window (log lines 1311-2400, before the decide at 1499-2400 region's `[modeidx]`), and the repeat ARCADE leg 60 s later (`kin5_nr2`) is clean: fatal 0, dropout 0, **underruns 0** -- the build-indexing landmine, not the 4-module shape. The full rc ladder (app_smoke, gstart, q1_ctest, q1_census, rc_chain) is NOT rerun on the 4-module shape yet |

Rows Q3/Q4/Q7 and Q11's ladder are what the next unattended pass fills; Q10 is the owner's.

## Why these three were owner calls (kept for the record)

Black Label runs, but only from a developer build with a private game root. Before it can be offered, three calls
are the owner's, not the engine's:
1. **Data path.** The DLC package (`496F816D...`, 277 MB STFS) is the user's own purchase. `tools/extract/
   futari_extract.py <folder with the package> --out <dir>` already unpacks its three files. The engine today finds
   them only under `<RT_GAME_ROOT>/media/Rom/`, i.e. the SAME root as the disc assets. Options: (a) the extractor
   writes into the user's existing assets root (simplest; the bundle law "assets/ is copied into the zip" is a
   BUILD-side rule, a user's installed assets folder is theirs); (b) a second root (`RT_DLC_ROOT`, or a `dlc/`
   folder beside the app) searched after the main one; (c) keep it developer-only.
2. **Build shape.** The two Black Label modules add ~17 MB of dylibs and a fourth/fifth registry row. Ship them in
   the default `MODULES` (rows un-grey only when the data is present, the shell's own gate), or keep them opt-in.
3. **Quality bar.** The smoke gate is a regression gate. Black Label has no reference pixels, no boss plate, no
   census baseline, no hands-on play. What must be true before a row is offered is the same question RC1 answered
   for Ver 1.5 (PLAN_RC1.md §0), and it has not been asked for Black Label.
The Ver 1.01 DLC (`9893A78C...`, 57 KB) is the same mechanism with a different root name; its data files are
disc-sourced and already in assets/, so it is the cheaper second case once a module exists for it.
