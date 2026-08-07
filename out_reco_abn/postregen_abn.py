#!/usr/bin/env python3
"""Post-XenonRecomp fixups for out_reco_abn/ (reco_abnormal parallel tree).

Idempotent -- safe to re-run; build_win_abn.sh calls it every time.

Mirrors what keep_reco/postregen_wrap_imports.py does for out_reco/, plus the second
hand edit that lives in out_reco/ppc_recomp_shared.h (the rt_mftb declaration).

1. extern "C" { } around the PPC_EXTERN_FUNC(__imp__...) import decls.
   XenonRecomp does not emit this wrapper; without it every TU that defines an import with
   PPC_FUNC_IMPL (shell/gen/rt.cpp, shell/gen/stubs.cpp, out_reco_abn/rt.cpp, ...) fails with
   `__imp__X has a different language linkage`.
2. `extern "C" unsigned long long rt_mftb(void);` -- the scaled 49.875 MHz guest timebase used
   by the generated mftb sites (defined in shell/gen/rt.cpp).
"""
import sys, os

P = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ppc_recomp_shared.h")
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
        sys.exit('ERROR: could not find #include "ppc_context.h" anchor')

# --- (1) extern "C" wrap of the import decls ---
idx = [i for i, l in enumerate(lines) if l.startswith("PPC_EXTERN_FUNC(__imp__")]
if not idx:
    sys.exit("ERROR: no PPC_EXTERN_FUNC(__imp__ ...) import decls found")
first, last = idx[0], idx[-1]
if 'extern "C"' not in lines[first - 1]:
    lines.insert(last + 1, '} // extern "C" (import decls)\n')
    lines.insert(first, 'extern "C" {  // import decls must match PPC_FUNC_IMPL linkage in rt.cpp/stubs.cpp\n')
    changed.append(f"wrapped {len(idx)} import decls")

if changed:
    open(P, "w", encoding="utf-8", newline="").writelines(lines)
    print("postregen_abn: " + "; ".join(changed))
else:
    print("postregen_abn: already applied (no change)")
