# matchlab — byte-exact matching against the original XDK compiler

**Status 2026-08-04: PROVEN. First byte-exact match landed (`0x8206D328`, 56/56 instructions,
SHA1-identical).** This directory is the verification workbench, not a build input — nothing
here is compiled into the port. (`build_win.sh:48` globs only `decomp/game/*.cpp` and
`decomp/shell/*.cpp`; `matchlab/` is deliberately outside that.)

## Why this exists

Until now every human-readable translation had to be validated *behaviourally*: a scripted
drive, a determinism control, `canon()` pointer masking, and usually user eyes. That apparatus
costs an evening per function and is why the Lane-A board sat still from 07-30 to 08-04.

With the period-correct compiler we can instead ask the only question that actually matters:
**does this C++ compile to the same instructions the original does?** That check is local,
offline, deterministic, and takes under a second.

## The toolchain

**XDK build 9328 — but NOT the plain June 2009 base drop.** Two records in the XEX say so; the
second is the stronger one and is what should be cited:

*Import libraries* (header `0x000103FF`) — `reco_normal.xex` and `assets/default.xex` both read
`xboxkrnl.exe` / `xam.xex` version **2.0.9328.0**, version_min **2.0.8498.0**. This is one
inference removed from the toolchain (it is what the title *binds to*).

*Static libraries* (header `0x000200FF`) — the libs actually **linked in**, each independently
versioned. `assets/default.xex` carries 15, `reco_normal.xex` 5:

```
LIBCMT XAPILIB XBOXKRNL D3D9 D3DX9 XGRAPHC XACT3 XAUD XMCORE XNET XONLINE XMP X3DAUD  2.0.9328.0
XAUDIO2  2.0.9328.4        <-- QFE 4
XAPOBA   2.0.9328.4        <-- QFE 4
```

Fifteen libraries agreeing on build 9328 pins the XDK install far harder than the import record
does. Two carry QFE 4, so the build machine had at least QFE 4 applied.

✅ **THE QFE QUESTION IS CLOSED — it does not affect matching.** `cl.exe`, `c1.dll`, `c1xx.dll`
and `c2.dll` are **byte-identical between 9328 base, 9328.5 and 9328.9** (SHA1/MD5 verified after
extracting the QFE drops). **QFE revisions ship libraries, not codegen.** Base 9328 is simply the
right compiler; the earlier "QFE ≥ 4, exact revision indeterminate" caveat is retired and must
not be re-raised as an explanation for a stubborn function.

✅ **AND SO IS THE COMPILER-BUILD QUESTION (2026-08-05).** Sharper than the above, because a
9328 tree contains **two different compilers**, and the sentence "byte-identical across the QFE
drops" is only true slot-for-slot:

| slot | `cl.exe` | version | `c2.dll` |
|---|---|---|---|
| `xdk9328/raw/` (**what `CL` points at**) | `613a7101` | 15.00.**8327** | `7f0cdb62` |
| `XDK/TechPreview/Mar09Compiler/bin/win32/` | `613a7101` | 15.00.**8327** | `7f0cdb62` |
| `XDK/bin/win32/` (the XDK's own default) | `397c3766` | 15.00.**8153** | `01db8e0e` |

So **matchlab's canonical compiler is the TechPreview March-2009 compiler**, not the XDK's
default one — worth knowing, since the two have genuinely different back-ends.

It makes no difference. **All 97 targets are ASM-EXACT under BOTH back-ends, zero DIFFs**, and
so are the three stubborn functions (`Menu_Cancel` 5/8, `Driver_SendStageRecord` 16/22,
`Page_EnsureTexture` 28/50) — identical scores, not merely similar. `MATCHLAB_CL` overrides the
path if this ever needs re-testing. **Do not spend another evening on "maybe it is the other
c2.dll".** For these functions the back-end is not the variable; codegen for our corpus is
invariant across every compiler XDK 9328 ships.

⚠ Still true: **`cl.exe`'s version appears nowhere in the XEX** — the format records linked
*libraries*, so do not write "the title names its own compiler". The warrant is empirical: the
base-9328 compiler reproduces these bodies byte-for-byte.

The base install is at `Z:\tv\_NEW\xdkcollection\2009\9328 June\`. (`C:/Users/shant/Desktop/projects/_tools/xdk/xdk20209` is
Sept 2010 — correct for API signatures, WRONG for matching.)

Compiler banner: `Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 15.00.8327 for PowerPC`.

Note: `shell/default.xex` and `assets/default.xex` are byte-identical — there are two distinct
binaries here, not three.

### Reproducing the extraction (~3 min)

⚠ Do NOT treat `C:/tmp` as durable — this project has already lost `C:\tmp\inventory`
(ELIMINATION_BACKLOG.md) and a XenosRecomp clone to a `/c/tmp` cleanup. The *source archive* on
`Z:` is the durable copy; re-extract rather than relying on the working dir.

```bash
mkdir -p /c/Users/shant/Desktop/projects/_tools/xdk/xdk9328/raw && cd /c/Users/shant/Desktop/projects/_tools/xdk/xdk9328/raw
"/c/Program Files/7-Zip/7z.exe" e "Z:\tv\_NEW\xdkcollection\2009\9328 June\XDKSetupXenon9328.exe" -y
mkdir -p 1033 && cp clui.dll 1033/     # else cl.exe dies with C1510 "cannot load clui.dll"
./cl.exe                                # should print the 15.00.8327 for PowerPC banner
```

### THE FLATTENED EXTRACTION IS LOSSY -- extract the header tree with `7z x` as well

`7z e` drops every directory, so **same-named files from different directories collide and one
silently wins**. The XDK ships BOTH `include/win32/vs2005/xnamath.h` and `include/xbox/xnamath.h`,
and the flattened copy kept the **Windows** one, which `#error`s out on a PowerPC build. That is
why "just include the real d3d9.h" looked impossible -- it was not, the extraction was wrong.

```bash
mkdir -p /c/Users/shant/Desktop/projects/_tools/xdk/xdk9328/tree && cd /c/Users/shant/Desktop/projects/_tools/xdk/xdk9328/tree
"/c/Program Files/7-Zip/7z.exe" x "Z:\tv\_NEW\xdkcollection\2009\9328 June\XDKSetupXenon9328.exe" -y
mkdir -p /c/Users/shant/Desktop/projects/_tools/xdk/xdk9328/compat
printf '#include <xobjbase.h>\n' > /c/Users/shant/Desktop/projects/_tools/xdk/xdk9328/compat/ObjBase.h
```

`ObjBase.h` is a **Platform SDK** header the XDK assumes and does not ship; the shim forwards it to
the Xbox `xobjbase.h`. With those two include dirs a source can `#include <xtl.h>` /
`#include <d3d9.h>` and get the ORIGINAL 9328 declarations instead of a hand-reproduced inline.

### ⚠⚠ `_XBOX` MUST BE DEFINED OR THE HEADERS ARE THE WRONG COMPILER

`d3d9.h` gates its fast paths on `_XBOX`, and **`cl.exe` does not predefine it** — the XDK build
system does. Without it:

* `D3DISINTCONST(x)` is the literal `FALSE` (the x86 arm), so `D3DDevice_SetPixelShaderConstantF`
  **never folds to the F1 inline** and emits a `bl D3DDevice_SetPixelShaderConstantFN` instead;
* `D3DRESTRICT` expands to nothing, so the `__restrict` qualifiers in those inlines vanish.

Measured on a two-line probe calling `SetPixelShaderConstantF(dev, 15, v, 1)`: **without `_XBOX`
21 instructions and a call and a 0x70 frame; with it 15 instructions and a leaf.** A source that
includes the real headers without defining it is measuring a compiler the title never used, and
will conclude the header route "does not work". Put `#define _XBOX 1` above the includes (or pass
`/D_XBOX` via the target's `defines`).
`ppcmatch.py` adds them automatically when the tree exists (`XDK_INCLUDES`), and adding them
changed **no** existing match -- board green, zero DIFFs, selftest ALL PASS.

This matters most for `Render_SelectBlend`, where 15+ statement structures failed to stop the
compiler commoning a read-modify-write the guest keeps in three uncommoned copies; a subtle
difference in the real header is the leading remaining candidate.

⚠ **`7z e` flattens the tree, and `dumpbin.exe` / `link.exe` DO NOT WORK in the flattened layout.**
They fail with **R6034** ("attempt to load the C runtime library incorrectly") because the loose
`msvcr90.dll` is not a valid app-local SxS assembly. Rebuilding
`Microsoft.VC90.CRT/{manifest,msvcr90.dll,msvcp90.dll}` beside them did NOT fix it (link.exe then
fails to start at all, exit 127) — **this is unresolved and deliberately not chased.**

*Nothing in this workbench needs either tool.* `cl.exe` is the only required binary and it works
(it finds `c1.dll`/`c1xx.dll`/`c2.dll` beside it); `cl /FAcs` emits assembly listings and
`ppcmatch.py` parses the COFF itself.

**R6034 puts a MODAL DIALOG on the user's screen and blocks whatever invoked it** — it fired
twice in one session (once from me, once from a verification agent). So the three offenders are
now renamed in the working directory:

```
link.exe    -> link.exe.disabled-R6034
dumpbin.exe -> dumpbin.exe.disabled-R6034
editbin.exe -> editbin.exe.disabled-R6034
```

Nothing can trigger the dialog by accident any more, and `cl -c` never needs the linker. If real
linking is ever wanted (e.g. dc3-style "fully linked" verification), do NOT un-rename these —
re-extract the XDK with paths preserved (`7z x`, or install it properly) so the SxS layout is
correct in the first place.

⚠ Git Bash mangles `/O2` into a path. Use `-O2` (MSVC accepts `-` prefixes) or pass flags from
Python, never through the shell.

## Usage

```bash
python matchlab/ppcmatch.py            # verify every entry in functions.json
python matchlab/ppcmatch.py --diff ColorMul     # side-by-side for one target
python matchlab/ppcmatch.py --sweep ColorMul    # try the flag matrix
python matchlab/clones.py --all --min-insn 3    # where the unclaimed instructions are
python matchlab/gate.py                         # the nine ship-gate functions
```

`CLONE_BACKLOG.md` holds the last `clones.py` census ranked by value, with the two shell families
that look greenfield but are not called out — read it before opening a clone family.

A target is `EXACT` when the bytes `ppcmatch` extracts from our `.obj` equal the bytes it extracts
at the guest address. Know exactly what that extraction is before trusting a verdict:

* **image side** — from the guest address to the first **padding word**, bounded by the next
  entry in `shell_funcs.txt` / `reco_normal_funcs.txt`; the last word must be an unconditional
  `blr` or tail branch. A declared `insn` in functions.json is **reconciled** against that and
  disagreement is a hard error, never a silent truncation.
* **obj side** — the one COFF symbol whose name is exactly `symbol` or `?symbol@…`, which must be
  a **FUNCTION** (`Type 0x20`) in a **CODE** section; extent from the COMDAT section or the next
  function symbol. More than one candidate is a hard error.

⚠ **It is NOT "up to the first blr".** That rule made the first version of this script emit two
false `EXACT`s (see the module docstring). `0x820AC018` has four unconditional `blr`s inside a
25-instruction body; 13–15% of `blr`s in these modules are interior.

Run `--selftest` after touching `ppcmatch.py`. It is **8 checks** and covers both directions:
REJECT the decoys that fooled v1 (interior-blr extent; an unproven declared `insn` at BOTH
plausible truncations of `0x820AC018`; a `const u32` **data array** named like the target, which
v1 graded; a substring-twin symbol; a shifted address) and ACCEPT the two legitimate extent
splits (`split-REFERENCED` and `split-UNREACHABLE`).

**Two independent extent proofs** exist because `.pdata` has no unwind record for LEAF functions,
so a leaf sitting after a target makes derivation over-run:
* **split-REFERENCED** — the address after the declared body is referenced somewhere in the image.
* **split-UNREACHABLE** — nothing in `[0,declared)` can branch into the tail, so it cannot be part
  of this function's behaviour. Reasons about the function's OWN CFG; needs no outside evidence.

No drive, no gate, no eyes — but also no trust without the self-test.

## Compiler flags — settled

| what | flags | evidence |
|---|---|---|
| **TITLE code** | **`-O2 -Oc`** | all 97 targets pass; `-O1` is never right |
| **XDK LIBRARY code** | **`-O1`** | `D3DDevice_CreateTexture` 0x88079970: EXACT at `-O1`, DIFF at `-O2 -Oc` — proven BOTH ways on one function, and matched against the symbol-named d3d9.lib body |

★ **`/Oc` = "disable divide-by-zero exceptions"** and it is INVISIBLE unless the function divides:
without it MSVC emits an extra `twi 6,rB,0` ahead of the `divwu`. It hid behind 84 matches before
`Page_FillFromCpu` exposed it. `/Ou` (prescheduling), `-Og/-Ot/-Oz/-Ox` and the rest: no effect,
ruled out across the stuck functions.
⚠ **XDK 9328 ships TWO compilers** — 15.00.8327 (`TechPreview\Mar09Compiler`) and 15.00.8153
(`bin\win32`). Behaviour is identical where tested, and 9328.9's are MD5-identical to both, so
the QFE question is closed.

## Register allocation

See **`ALLOCATOR.md`** — the nonvolatile allocation rule, derived by controlled experiment
because eight functions were blocked with every instruction correct and only the register MAPPING
differing. Two regimes: branch-crossing values rank by loop-weighted reference count (~2x per
loop level); block-local values ignore count entirely and rank by source declaration order; every
global outranks every local. **It also explains why per-function source sweeps come back flat.**
⚠ It does not pin full permutations in large functions — verify by rebuild, never blind.

## Method notes (each of these cost real time; all generalise)

### A value kept in a VOLATILE register across a call ⇒ the callee is `static` in the same TU

MSVC gives functions with internal linkage a **custom calling convention**: when it can see the
whole callee it tracks which volatiles that callee leaves alone, and lets the caller keep live
values in them. So `mr r5,r3` / `bl X` / `mr r3,r5` — r5 being a volatile parameter register —
is not a whole-program-optimisation artefact, it is a same-file `static` leaf callee.

Measured on `Poll` 0x8810B7B0 (game), all three states:

| callee declared | caller emits | result |
|---|---|---|
| `extern` | `mr r31,r3` + a nonvolatile save | 15 insn, 2/13 — cannot ever match |
| `static`, **not** a leaf | `mr r31,r3` | MSVC promises nothing through a call it cannot see |
| `static` **and** a leaf | `mr r9,r3` — a volatile | 13/13 insn, 9/13 words |

⇒ **When a function holds something in r4-r10 across a `bl`, do not declare that callee `extern`.**
Put it in the same file as `static`. Which volatile gets chosen follows the callee's clobber set
(3-5 globals → r9, 7 → r10), so the caller matches for free once the real callee is decompiled.

Worth ruling out explicitly: this is **not** LTCG. `cl -c -GL` emits an IL object with no machine
code, and `coff_function` cannot read one — so if any function here had been built that way it
would be permanently out of reach. None of the 223 matched targets needed it.

**Signedness, width, and shape**
1. `cmpwi` vs `cmplwi` ⇒ **signedness** (`int` vs `unsigned`). Check this FIRST on any DIFF.
2. `li rX,0` + `oris` (two instructions) vs `lis` (one) ⇒ **argument WIDTH**; the pair is the
   zero-extended doubleword form, so the parameter is 64-bit.
3. A clamp emitted as `addi p,&a / bgt / addi p,&b / lwz` — a POINTER select through stack
   temporaries — means a `const T&`-returning `min`/`max`, not a ternary.
4. A literal bound to a **const reference** makes a fresh stack temporary PER CALL SITE.
5. `&param` spills to the parameter HOME slot (high offset); the address of a local COPY gets a
   fresh low slot.
6. Branch layout shows which arm was written first: branching AWAY on the first test means
   `if (x != A) { if (x == B) … } else { … }`, not `if/else if`.
7. `||` plus a ternary can go BRANCHLESS and lose the match — keep branches explicit.

**Addressing**
8. Deref depth is visible: `extern T** g` with `*g` emits one `lwz` too many. The `lis`/`lwz`
   pair IS the first deref.
9. A nonvolatile holding a `lis` BASE means the global is read 2+ times and RE-LOADED each time —
   the source does NOT cache the pointer in a local. Hoisting it removes an instruction.
10. Indexed (`lwzx rD,rIdx,rBase` off a hoisted base) ⇒ flat-array / pointer arithmetic;
    one base with `+0/+4` offsets ⇒ `T* p = &tbl[i]`. If several bases are hoisted it is
    probably NOT a struct pointer.
    ★ **MEASURED 2026-08-07 (`probe_addr.py`, 16 variants), the exact condition:** this compiler
    collapses base+index into an address register (`add`, then offset form) in exactly two cases —
    the address ESCAPES to a callee, or the pointer is used at **two or more DISTINCT OFFSETS
    across a call**. Touching the SAME offset repeatedly keeps indexed form no matter how many
    times (four accesses over three calls: still `lwzx`), and distinct offsets with no call
    between do not collapse either. ⇒ offset form in the image is positive evidence that the
    original source used a record pointer AND read more than one field through it.
11. A **negative displacement** proves the anchor object starts ABOVE the accessed word; MSVC
    never emits one otherwise.
12. A non-contiguous AND mask costs **two `rlwinm`s, not `andi`** (`x & 9` ⇒ mask 0xF then a
    wrapping mask). Do not invent a bitfield to explain the first `&0xF`.

**Things that are not source at all**
13. `bl 0x880711xx` / `b 0x880711xx` are `__savegprlr_N` / `__restgprlr_N` millicode, not calls.
    **The helper address encodes the lowest nonvolatile saved**, and the frame size follows —
    a free read on register pressure before writing a line of C. Ghidra renders the prologue as
    `iVar = FUN_88071134()`, which looks like an identity call and is not.
14. `lwz r12,0(r3) / lwz r11,SLOT(r12) / mtctr r11 / bctr` is a **compiler-generated vcall
    thunk** (`&Class::VirtualMethod`). The **r12-then-r11** pair is the tell: hand-written
    `e->vtbl->slot(e)` allocates r11-then-r10 and can never match. Reproduce it by declaring the
    construct, never by writing a body.
15. A dead `blr` after a `bctr` is real — the fall-through label after a tail call.
16. `bXXlr` (conditional return) ⇒ leaf function, no frame, a plain early `return;`.
17. CRT functions must be declared by their REAL NAME (`memcpy` as `memcpy`), or argument setup
    order differs.

**Discipline**
18. **When a sweep goes flat, STOP tuning syntax — and ALSO re-read `cl /?` for a flag matching
    the SYMPTOM.** Three separate flat sweeps were resolved by object lifetime, a type, and a
    flag respectively. `ALLOCATOR.md` explains the mechanism: in the global regime a sweep that
    changes no reference count is searching a space where every point is the same point.
19. **Re-verify every delegated match before registering it.** One in four came back wrong.
20. A "compile failed" with no compiler diagnostic is a HARNESS fault, not a source fault.

## Where this sits in the port's ladder

**User ruling 2026-08-04: ASM-EXACT is a new rung; `registry.toml` stays behavioural.** Both are
now implemented:

* The ladder in `../decomp/README.md` and plan §2 gained `ASM-EXACT` between `DRAFT` and
  `MATCHED`, with a two-axis table explaining that neither implies the other.
* `registry.toml`'s `status` field still only ever holds `RAW/NAMED/DRAFT/MATCHED/LOCKED`. The
  three matched functions were seeded there at `status = "DRAFT"` (C exists, no behavioural gate,
  not linked) and carry `asm_exact` / `asm_sha1` / `matchlab` cross-reference fields.
* **`functions.json` here is authoritative for the ASM-EXACT rung.**

A function can be ASM-EXACT without being MATCHED (nothing here is linked) and MATCHED without
being ASM-EXACT — `GameEntry_Dispatch` is `PPC_FUNC_IMPL(__imp__sub_8824E698)`, a ctx-shaped body
manipulating `ctx.rNN`, so there is no natural C++ for 9328 to compile and compare.

The natural end state is the UnleashedRecomp shape: keep the matched natural-C++ body, verify it
with 9328 + `ppcmatch`, and give it a thin adapter that unpacks the guest register file for the
recomp host — which is what the C1 "register-file rule" was hand-deriving.
