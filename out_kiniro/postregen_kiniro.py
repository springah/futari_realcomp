#!/usr/bin/env python3
"""Post-XenonRecomp fixups for the Black Label trees, out_kiniro/ (kiniro_normal) and out_kiniro_abn/
(kiniro_abnormal). A clone of out_reco_abn/postregen_abn.py with the tree as an argument.

Idempotent -- safe to re-run; scripts/regen_kiniro_mac.sh calls it for both trees after every regen.
  python3 out_kiniro/postregen_kiniro.py [TREE ...]        (default: the directory this file lives in)

1. extern "C" { } around the PPC_EXTERN_FUNC(__imp__...) import decls.
   XenonRecomp does not emit this wrapper; without it every TU that defines an import with
   PPC_FUNC_IMPL (shell/gen/rt.cpp, shell/gen/stubs.cpp, out_reco_abn/rt.cpp, ...) fails with
   `__imp__X has a different language linkage`.
2. `extern "C" unsigned long long rt_mftb(void);` -- the scaled 49.875 MHz guest timebase used
   by the generated mftb sites (defined in shell/gen/rt.cpp).
"""
import sys, os


def fix(tree):
    P = os.path.join(tree, "ppc_recomp_shared.h")
    lines = open(P, encoding="utf-8", newline="").readlines()
    changed = []

    # --- (2) rt_mftb decl, right after the two #includes ---
    if not any("rt_mftb" in l for l in lines):
        for i, l in enumerate(lines):
            if l.startswith('#include "ppc_context.h"'):
                lines[i+1:i+1] = [
                    "\n",
                    "// rt_mftb: scaled guest timebase (49.875MHz) - see shell/gen/ppc_recomp_shared.h note.\n",
                    'extern "C" unsigned long long rt_mftb(void);\n',
                ]
                changed.append("added rt_mftb decl")
                break
        else:
            sys.exit(f'ERROR: {P}: could not find #include "ppc_context.h" anchor')

    # --- (1) extern "C" wrap of the import decls ---
    idx = [i for i, l in enumerate(lines) if l.startswith("PPC_EXTERN_FUNC(__imp__")]
    if not idx:
        sys.exit(f"ERROR: {P}: no PPC_EXTERN_FUNC(__imp__ ...) import decls found")
    first, last = idx[0], idx[-1]
    if 'extern "C"' not in lines[first - 1]:
        lines.insert(last + 1, '} // extern "C" (import decls)\n')
        lines.insert(first, 'extern "C" {  // import decls must match PPC_FUNC_IMPL linkage in rt.cpp/stubs.cpp\n')
        changed.append(f"wrapped {len(idx)} import decls")

    if changed:
        open(P, "w", encoding="utf-8", newline="").writelines(lines)
        print(f"postregen_kiniro [{tree}]: " + "; ".join(changed))
    else:
        print(f"postregen_kiniro [{tree}]: already applied (no change)")


for t in (sys.argv[1:] or [os.path.dirname(os.path.abspath(__file__))]):
    fix(t)
