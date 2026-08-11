#!/usr/bin/env python3
"""gen_host_abi.py — emit the host<->module-DLL ABI from a MEASUREMENT, not from a list.

L4 / E6 of `_tmpscripts/dll_packaging_plan.md` (§1.3 bind-struct, §4.2 "the generator must
abort loudly on any new symbol").  Notes: `_tmpscripts/l4l5_combined_notes.md`.

WHAT IT DOES
    1. runs `llvm-nm` over the objects that will make up a module DLL,
    2. subtracts the symbols that group defines itself,
    3. classifies every remaining symbol into exactly one of
           GLOBALS   — a host object the DLL must reach through a pointer
           HELPERS   — a host function with a known C signature
           KERNEL    — an `__imp__<KernelName>` PPC import stub (uniform signature)
           CRT       — satisfied by the DLL's own CRT / kernel32 link; NOT in the ABI
    4. **aborts** if anything is unclassified.  That abort is the whole point: a recompiler
       upgrade or a new host call from a game hook must not silently become a link error at
       the far end of a two-hour build — it stops here with the symbol named.
    5. emits three generated files (all marked DO NOT EDIT):
           host/futari_host_abi.h        the struct, shared verbatim by host and every DLL
           host/host_abi_fill.inc        the host-side initialiser + extern decls
           <moddir>/module_shim.cpp      per-module: thunks + descriptor + FutariModuleBind

WHY NAMED FIELDS, NOT `imp[59]`
    The plan sketched a fixed-index array.  A named-field struct in ONE generated header that
    both sides compile against removes the index-order agreement entirely, and `struct_size` +
    `abi_hash` turn a stale DLL into a loud refusal at bind time instead of a wild call.

USAGE (read-only w.r.t. the build; writes only the three generated files)
    python tools/gen_host_abi.py --objdir obj_win --moddir out_reco     --module 0
    python tools/gen_host_abi.py --objdir obj_win_abn --moddir out_reco_abn --module 1
    python tools/gen_host_abi.py --objdir obj_win --check      # classify only, write nothing
"""
import argparse, glob, os, subprocess, sys

NM = r"C:\Program Files\LLVM\bin\llvm-nm.exe"
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# ---------------------------------------------------------------------------------------
# The objects that become a module DLL.  Everything else in the obj dir stays in the exe.
# Keep in sync with build_win_dll.sh's DLL compile list — the two are cross-checked by the
# `--check` mode's object count.
# ---------------------------------------------------------------------------------------
DLL_OBJ_GLOBS = [
    "game_ppc_recomp.*.o",
    "game_ppc_func_mapping.o",
    "merged_game.o",
    "decomp_game_entry_msgs.o",
    "decomp_game_entry_msgs_abn.o",
    "decomp_nvk_game_hooks.o",
    "decomp_crt_hooks.o",
]

# ---------------------------------------------------------------------------------------
# GLOBALS — host-owned data the DLL reads or writes.  A thunk cannot express these, so the
# shim declares a pointer that FutariModuleBind fills and merged_common.h #defines the
# ORIGINAL NAME onto a deref of it.  That keeps every use site in the game half untouched.
#   key   = the symbol as llvm-nm prints it (mangled for C++ linkage)
#   ptr   = the C++ type of the ABI pointer field
#   field = the FutariHostAbi field name
#   shim  = the `extern "C"` pointer the DLL-side macro derefs (declared in merged_common.h)
#   host  = the expression the HOST uses to take the address
# ---------------------------------------------------------------------------------------
GLOBALS = {
    "?g_import_calls@@3U?$atomic@J@std@@A": dict(
        ptr="std::atomic<long>*", field="pg_import_calls",
        shim="futari_p_import_calls", host="&g_import_calls",
        note="out_reco/stubs.cpp — one process-wide import counter"),
    "?g_rt_startline@@3U?$atomic@H@std@@A": dict(
        ptr="std::atomic<int>*", field="pg_rt_startline",
        shim="futari_p_rt_startline", host="&g_rt_startline",
        note="shell/gen/stubs.cpp — P1 START button LEVEL, host input layer"),
    "g_rt_romactive": dict(
        ptr="volatile int*", field="pg_rt_romactive",
        shim="futari_p_rt_romactive", host="&g_rt_romactive",
        note="★ was DEFINED in merged_game.cpp; MOVED to merged_bridge.cpp (host) at L4 — "
             "vk_render/shell rt.cpp/merged_shell all read it, so a per-DLL copy would split it"),
    "g_rt_realstage": dict(
        ptr="volatile int*", field="pg_rt_realstage",
        shim="futari_p_rt_realstage", host="&g_rt_realstage",
        note="★ same class as g_rt_romactive: DLL writes, vk_render reads"),
}

# ---------------------------------------------------------------------------------------
# HELPERS — host functions with a known signature.  `sig` is the full C declaration with the
# parameter names used verbatim in the generated forwarding body.
# ---------------------------------------------------------------------------------------
def H(field, ret, params, args, note):
    return dict(field=field, ret=ret, params=params, args=args, note=note)

HELPERS = {
  "rt_indirect_call": H("fn_rt_indirect_call", "void",
      "PPCContext& __restrict ctx, uint8_t* base, uint32_t target", "ctx, base, target",
      "out_reco/rt.cpp — the checked indirect-call dispatcher; ~191 call sites per module tree"),
  "rt_frameclock_present_skip": H("fn_rt_frameclock_present_skip", "int", "void* grantfn", "grantfn",
      "shell/gen/rt.cpp — 08-12 tick/present decoupling: 1 = the 59.94Hz vblank thread owns "
      "the ABN frame grant and GameEntry msg-5 must skip the present-path handshake; grantfn is "
      "the module's &sub_8808FA68 (void*, cross-module — the shell's rt_lookup can't resolve it)"),
  "rt_frameclock_disarm": H("fn_rt_frameclock_disarm", "void", "const char* why", "why",
      "shell/gen/rt.cpp — drop vblank frame-clock ownership (msg-3 teardown; also called "
      "host-side at module swap)"),
  "roundevenf": H("fn_roundevenf", "float", "float x", "x",
      "out_reco/harness.cpp"),
  "rt_mftb": H("fn_rt_mftb", "unsigned long long", "void", "",
      "scaled guest timebase; called from the GENERATED tree (ppc_recomp.3.cpp)"),
  "rt_jankstate_tick": H("fn_rt_jankstate_tick", "void",
      "long long n, long long d_us", "n, d_us",
      "merged_shell.cpp — the L3 stage-1 replacement for the 3 cross-line g_js_* statics"),
  "rt_jankstate_summary": H("fn_rt_jankstate_summary", "void",
      "long long frames, long long slow, long long maxd, long long meand",
      "frames, slow, maxd, meand", "merged_shell.cpp"),
  "rt_audio_stage_play_volume": H("fn_rt_audio_stage_play_volume", "void", "int vol64", "vol64",
      "shell/gen/rt_audio.cpp — per-play volume staging (round-5 audio leg; merged_game crux)"),
  "rt_audio_bridge_enabled": H("fn_rt_audio_bridge_enabled", "int", "void", "",
      "shell/gen/rt_audio.cpp"),
  "rt_audio_cuebridge_enabled": H("fn_rt_audio_cuebridge_enabled", "int", "void", "",
      "shell/gen/rt_audio.cpp"),
  "rt_audio_bridge_play": H("fn_rt_audio_bridge_play", "void",
      "int bankType, int waveIdx", "bankType, waveIdx", "shell/gen/rt_audio.cpp"),
  "rvk_handback_invalidate": H("fn_rvk_handback_invalidate", "void", "void", "",
      "render/vk_render.cpp — the FNF-11 guest-teardown cache drop; sole call site is the "
      "GAME half's sub_8813A5F0 wrapper, so it becomes a module->host call at L4"),
  "nvk_mode": H("fn_nvk_mode", "int", "void", "", "decomp/shell/nvk.cpp"),
  "nvk_ev": H("fn_nvk_ev", "void",
      "const char* fn, unsigned long long r3, unsigned long long r4, unsigned long long r5, "
      "unsigned long long r6, unsigned long long r7, unsigned long long r8, unsigned long long r9",
      "fn, r3, r4, r5, r6, r7, r8, r9", "decomp/shell/nvk.cpp"),
  "nvk_on_clear": H("fn_nvk_on_clear", "void", "unsigned colorARGB", "colorARGB",
      "decomp/shell/nvk.cpp"),
  "nvk_on_draw_core": H("fn_nvk_on_draw_core", "void",
      "uint8_t* base, unsigned dev, unsigned prim, unsigned count, unsigned strideB, "
      "unsigned scratch, unsigned dirtyPre, unsigned isGame",
      "base, dev, prim, count, strideB, scratch, dirtyPre, isGame", "decomp/shell/nvk.cpp"),
  "nvk_on_setrt": H("fn_nvk_on_setrt", "void",
      "uint8_t* base, unsigned dev, unsigned idx, unsigned surf", "base, dev, idx, surf",
      "decomp/shell/nvk.cpp"),
  "nvk_on_resolve": H("fn_nvk_on_resolve", "void",
      "uint8_t* base, unsigned dev, unsigned flags, unsigned pDestTex, unsigned pSrcRect, "
      "unsigned clearColor, unsigned pDestPoint",
      "base, dev, flags, pDestTex, pSrcRect, clearColor, pDestPoint",
      "decomp/shell/nvk.cpp"),
  "nvk_pack_cc": H("fn_nvk_pack_cc", "unsigned",
      "uint8_t* base, unsigned pcc", "base, pcc",
      "decomp/shell/nvk.cpp — CODE_REVIEW_0804 B9: D3DVECTOR4 pClearColor -> packed ARGB"),
}

# ---------------------------------------------------------------------------------------
# CRT / OS — satisfied by the DLL's own /MT link or its own kernel32 import table.  NOT ABI.
# Explicit set, not a wildcard: a NEW crt symbol appearing here is worth one human glance.
# ---------------------------------------------------------------------------------------
CRT = set("""
??2@YAPEAX_K@Z ??3@YAXPEAX_K@Z ??_7type_info@@6B@
?_Throw_Cpp_error@std@@YAXH@Z ?_Xlength_error@std@@YAXPEBD@Z
RtlCaptureStackBackTrace _CxxThrowException
_Init_thread_abort _Init_thread_epoch _Init_thread_footer _Init_thread_header
_Mtx_lock _Mtx_unlock _Query_perf_counter _Query_perf_frequency
__CxxFrameHandler3 __acrt_iob_func __chkstk
__std_exception_copy __std_exception_destroy __std_terminate
__stdio_common_vfprintf __stdio_common_vsprintf
_fltused _invoke_watson _tls_index
atexit atoi ceilf fclose fflush fopen fputc fwrite getenv
memcpy memmove memset strchr strcmp strlen strncmp strtoul truncf
abort calloc free malloc realloc snprintf sprintf sscanf strtol printf puts putchar
""".split())

def is_crt(sym):
    if sym in CRT:
        return True
    # Win32 dllimports: lld spells them `__imp_<Name>` (ONE underscore after imp).  The
    # recompiler's kernel stubs are `__imp__<Name>` (TWO) — the collision plan §1.3 is built
    # around.  Discriminate structurally, exactly as build_win_abn.sh:118 documents.
    if sym.startswith("__imp_") and not sym.startswith("__imp__"):
        return True
    return False


def run_nm(args, objs):
    out = subprocess.run([NM] + args + objs, capture_output=True, text=True).stdout
    return {ln.split()[-1] for ln in out.splitlines() if ln.strip() and not ln.endswith(":")}


def measure(objdir):
    objs = []
    for g in DLL_OBJ_GLOBS:
        objs += sorted(glob.glob(os.path.join(ROOT, objdir, g)))
    if not objs:
        sys.exit(f"FATAL: no DLL-group objects under {objdir}/ — build first")
    und = run_nm(["--undefined-only"], objs)
    dfn = run_nm(["--defined-only"], objs)
    return objs, sorted(und - dfn)


def classify(need):
    # The ABI SHAPE is the declared tables (so the struct is identical whatever state the obj
    # dir happens to be in — e.g. g_rt_romactive is still DLL-defined until merged_game.cpp is
    # edited, and the ABI must carry its slot regardless).  The MEASUREMENT is the tripwire:
    # anything measured that no table claims aborts the run.
    kernel, helpers, globs, crt, unknown = [], sorted(HELPERS), sorted(GLOBALS), [], []
    for s in need:
        if s in GLOBALS or s in HELPERS:
            continue
        elif s.startswith("__imp__sub_"):
            # A guest hook body the DLL group does NOT contain.  Never an ABI member: it means
            # a TU was left out of the DLL compile list.  Loud by design.
            unknown.append(s + "   <-- GUEST HOOK MISSING FROM THE DLL OBJECT LIST")
        elif s.startswith("__imp__"):
            kernel.append(s)
        elif is_crt(s):
            crt.append(s)
        else:
            unknown.append(s)
    return kernel, helpers, globs, crt, unknown


def abi_hash(kernel, helpers, globs):
    h = 0xcbf29ce484222325
    for s in kernel + helpers + globs:
        for b in s.encode():
            h = ((h ^ b) * 0x100000001b3) & 0xFFFFFFFFFFFFFFFF
    return h


BANNER = ("// ===================================================================================\n"
          "// GENERATED by tools/gen_host_abi.py — DO NOT EDIT.  Regenerate after any change to\n"
          "// the host<->module symbol surface; the generator ABORTS on an unclassified symbol.\n"
          "// ===================================================================================\n")


def emit_header(path, kernel, helpers, globs, h):
    L = [BANNER, "#pragma once\n#include <stdint.h>\n#include <atomic>\n",
         "struct PPCContext;\n",
         "typedef void FutariPPCFunc(struct PPCContext& __restrict ctx, uint8_t* base);\n",
         "\n#define FUTARI_HOST_ABI_VERSION 1u",
         f"#define FUTARI_HOST_ABI_HASH    0x{h:016X}ull",
         "",
         "// Handed to the DLL once, at FutariModuleBind().  Const to the DLL, owned by the exe.",
         "struct FutariHostAbi {",
         "    uint32_t abi_version;      // == FUTARI_HOST_ABI_VERSION",
         "    uint32_t struct_size;      // == sizeof(FutariHostAbi)",
         "    uint64_t abi_hash;         // == FUTARI_HOST_ABI_HASH (the symbol-set fingerprint)",
         "    uint8_t* base;             // guest arena; informational (every PPCFunc gets it as a param)",
         "",
         f"    // ---- {len(kernel)} kernel/import stubs (out_reco/rt.cpp + stubs.cpp) ----"]
    for s in kernel:
        L.append(f"    FutariPPCFunc* imp_{s[len('__imp__'):]};")
    L.append("")
    L.append(f"    // ---- {len(helpers)} host helper functions ----")
    for s in helpers:
        e = HELPERS[s]
        L.append(f"    {e['ret']} (*{e['field']})({e['params']});   // {s}: {e['note']}")
    L.append("")
    L.append(f"    // ---- {len(globs)} host-owned globals reached by pointer ----")
    for s in globs:
        e = GLOBALS[s]
        L.append(f"    {e['ptr']} {e['field']};   // {e['shim']}: {e['note']}")
    L.append("};\n")
    L.append("struct FutariModuleDesc;")
    L.append("// THE ONE EXPORT every module DLL provides.  Returns nullptr on ABI mismatch.")
    L.append('extern "C" typedef const FutariModuleDesc* (*FutariModuleBindFn)(const FutariHostAbi*);')
    L.append('#define FUTARI_MODULE_BIND_SYMBOL "FutariModuleBind"')
    open(path, "w", newline="\n", encoding="utf-8").write("\n".join(L) + "\n")


def emit_fill(path, kernel, helpers, globs):
    L = [BANNER,
         "// Included ONCE by host/module_registry.cpp.  Declares every host symbol the ABI",
         "// exports and builds the single FutariHostAbi instance.",
         '#include "futari_host_abi.h"', "",
         'extern "C" {']
    for s in kernel:
        L.append(f"    void {s}(struct PPCContext& __restrict, uint8_t*);")
    for s in helpers:
        e = HELPERS[s]
        L.append(f"    {e['ret']} {s}({e['params']});")
    L.append("}")
    L.append("")
    L.append("// The host-side declarations of the shared globals (real names, real types).")
    L.append('extern std::atomic<long> g_import_calls;            // out_reco/stubs.cpp')
    L.append('extern std::atomic<int>  g_rt_startline;            // shell/gen/stubs.cpp')
    L.append('extern "C" { extern volatile int g_rt_romactive; }  // merged_bridge.cpp (moved at L4)')
    L.append('extern "C" { extern volatile int g_rt_realstage; }  // merged_bridge.cpp (moved at L4)')
    L.append("")
    L.append("static FutariHostAbi futari_build_host_abi(uint8_t* base) {")
    L.append("    FutariHostAbi a{};")
    L.append("    a.abi_version = FUTARI_HOST_ABI_VERSION;")
    L.append("    a.struct_size = (uint32_t)sizeof(FutariHostAbi);")
    L.append("    a.abi_hash    = FUTARI_HOST_ABI_HASH;")
    L.append("    a.base        = base;")
    for s in kernel:
        L.append(f"    a.imp_{s[len('__imp__'):]} = &{s};")
    for s in helpers:
        L.append(f"    a.{HELPERS[s]['field']} = &{s};")
    for s in globs:
        L.append(f"    a.{GLOBALS[s]['field']} = {GLOBALS[s]['host']};")
    L.append("    return a;")
    L.append("}")
    open(path, "w", newline="\n", encoding="utf-8").write("\n".join(L) + "\n")


def emit_shim(path, moddir, module_idx, kernel, helpers, globs):
    modname = "reco_abnormal" if module_idx == 1 else "reco_normal"
    L = [BANNER,
         f"// module_shim_{modname}.cpp — the ENTIRE host-facing surface of futari_game_"
         f"{'abn' if module_idx else 'normal'}.dll.",
         "//",
         "// ############################################################################",
         "// # THIS FILE MUST ONLY EVER BE COMPILED INTO A MODULE DLL.                   #",
         "// #                                                                           #",
         "// # It DEFINES all 59 __imp__<kernel> symbols as forwards through a bind-time #",
         "// # pointer.  In an exe that never calls FutariModuleBind() that pointer is    #",
         "// # null, and because lld is invoked with /FORCE:MULTIPLE and these objects   #",
         "// # sort EARLY in the obj_win/game_*.o glob, they would silently WIN over the #",
         "// # real stubs in rt.cpp/stubs.cpp and every kernel call would deref null.    #",
         "// #                                                                           #",
         "// # That is not hypothetical: it happened on 2026-07-31.  Dropping this file  #",
         "// # into out_reco/ put it in build_win.sh's `for f in out_reco/*.cpp` glob and #",
         "// # crashed the ARCADE exe at boot with 0xC0000005 reading 0xB8 — which is    #",
         "// # exactly offsetof(FutariHostAbi, imp_NtAllocateVirtualMemory), reached from #",
         "// # the guest CRT's _heap_init -> heap_create.                                 #",
         "// #                                                                           #",
         "// # Two defences, both required:                                              #",
         "// #   1. it lives in moduleshim/, a directory NO build script globs;          #",
         "// #   2. the #error below turns a future glob accident into a BUILD failure   #",
         "// #      instead of a silent link hijack.                                     #",
         "// ############################################################################",
         "#ifndef FUTARI_IN_MODULE_DLL",
         "#error \"module_shim is DLL-ONLY (see the banner above). It was just compiled without \"",
         "#error \"-DFUTARI_IN_MODULE_DLL=1, which means a build script glob picked it up. Remove \"",
         "#error \"it from that glob -- do NOT define the macro to silence this.\"",
         "#endif",
         "//",
         "// Every symbol below is a one-line forward through the bound FutariHostAbi, so the",
         "// generated tree, merged_game.cpp and decomp/game*/ compile UNCHANGED inside the DLL:",
         "// they still call `rt_indirect_call`, `__imp__NtReadFile`, `nvk_mode` … by their real",
         "// names, and those names are defined right here.  Nothing named `__imp__*` ever crosses",
         "// a PE import boundary (plan §1.3 rationale 1 — the lld `__imp_` dllimport collision).",
         "//",
         "// NOTE ON THE INCLUDE BELOW: living outside the generated tree means",
         "// \"ppc_recomp_shared.h\" resolves purely through the -I <moddir> this file is compiled",
         "// with, never through the quote-include's own-directory rule.  That is strictly safer —",
         "// it is the same own-directory trap out_reco/rt_indirect.h documents at length.",
         '#include "ppc_recomp_shared.h"',
         '#include "../host/futari_host_abi.h"',
         '#include "../host/futari_module_desc.h"', "",
         "static const FutariHostAbi* g_host = nullptr;",
         "",
         "// The DLL-side pointers merged_common.h #defines the real global names onto.",
         'extern "C" {']
    for s in globs:
        e = GLOBALS[s]
        L.append(f"    {e['ptr']} {e['shim']} = nullptr;")
    L.append("}")
    L.append("")
    L.append(f"// ---- {len(kernel)} kernel import thunks ----")
    for s in kernel:
        L.append(f"PPC_FUNC_IMPL({s}){{ g_host->imp_{s[len('__imp__'):]}(ctx, base); }}")
    L.append("")
    L.append(f"// ---- {len(helpers)} host helper thunks ----")
    L.append('extern "C" {')
    for s in helpers:
        e = HELPERS[s]
        call = f"g_host->{e['field']}({e['args']})"
        body = f"return {call};" if e["ret"] != "void" else f"{call};"
        L.append(f"    {e['ret']} {s}({e['params']}) {{ {body} }}")
    L.append("}")
    L.append("")
    L.append("// ---- the descriptor + the ONE export ----")
    L.append(f"// A mutable copy of the constexpr descriptor for {modname}: the DLL is the only")
    L.append("// place that can fill `mappings`/`mapping_count`, because PPCFuncMappings is ITS")
    L.append("// symbol.  Everything else is inherited verbatim from host/futari_module_desc.h.")
    L.append("static FutariModuleDesc g_desc;")
    L.append("")
    L.append('extern "C" __declspec(dllexport)')
    L.append("const FutariModuleDesc* FutariModuleBind(const FutariHostAbi* h) {")
    L.append("    if (!h) return nullptr;")
    L.append("    if (h->abi_version != FUTARI_HOST_ABI_VERSION) return nullptr;")
    L.append("    if (h->struct_size != (uint32_t)sizeof(FutariHostAbi)) return nullptr;")
    L.append("    if (h->abi_hash    != FUTARI_HOST_ABI_HASH) return nullptr;")
    L.append("    g_host = h;")
    for s in globs:
        e = GLOBALS[s]
        L.append(f"    {e['shim']} = h->{e['field']};")
    L.append("    g_desc = *futari_desc();          // the compile-time descriptor for this module")
    L.append("    uint32_t n = 0;")
    L.append("    for (const PPCFuncMapping* m = PPCFuncMappings; m->guest || m->host; ++m) ++n;")
    L.append("    g_desc.mappings      = PPCFuncMappings;")
    L.append("    g_desc.mapping_count = n;")
    L.append("    return &g_desc;")
    L.append("}")
    open(path, "w", newline="\n", encoding="utf-8").write("\n".join(L) + "\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--objdir", default="obj_win")
    ap.add_argument("--moddir", default="out_reco")
    ap.add_argument("--module", type=int, default=0)
    ap.add_argument("--check", action="store_true", help="classify only; write nothing")
    a = ap.parse_args()

    objs, need = measure(a.objdir)
    kernel, helpers, globs, crt, unknown = classify(need)
    print(f"[gen_host_abi] {a.objdir}: {len(objs)} DLL-group objects, {len(need)} unsatisfied")
    print(f"[gen_host_abi]   kernel imports {len(kernel)}   helpers {len(helpers)}"
          f"   globals {len(globs)}   crt/os {len(crt)}")
    if unknown:
        print("\nFATAL: unclassified symbols — the ABI is NOT complete.  Each one is either a "
              "new host service (add it to HELPERS/GLOBALS) or a TU missing from the DLL list:")
        for s in unknown:
            print("   " + s)
        sys.exit(2)
    missing = [s for s in list(HELPERS) + list(GLOBALS) if s not in need]
    if missing:
        print("[gen_host_abi] NOTE: ABI members declared but not (yet) referenced by the built "
              "objects — expected while a source move is in flight: " + ", ".join(missing))
    if a.check:
        return
    h = abi_hash(kernel, helpers, globs)
    emit_header(os.path.join(ROOT, "host", "futari_host_abi.h"), kernel, helpers, globs, h)
    emit_fill(os.path.join(ROOT, "host", "host_abi_fill.inc"), kernel, helpers, globs)
    # ★ The shim goes to moduleshim/, NEVER into out_reco*/ — those are swept by
    # `for f in out_reco/*.cpp` in build_win.sh AND build_merged.sh, and by `for f in $OUT/*.cpp`
    # in build_win_abn.sh.  See the banner emit_shim writes for the crash this caused.
    modname = "reco_abnormal" if a.module == 1 else "reco_normal"
    shimdir = os.path.join(ROOT, "moduleshim")
    os.makedirs(shimdir, exist_ok=True)
    shim = os.path.join(shimdir, f"module_shim_{modname}.cpp")
    emit_shim(shim, a.moddir, a.module, kernel, helpers, globs)
    # Belt: if a previous run left a shim inside the generated tree, remove it — a stale one is
    # a live link hijack, not dead weight.
    stale = os.path.join(ROOT, a.moddir, "module_shim.cpp")
    if os.path.exists(stale):
        os.remove(stale)
        print(f"[gen_host_abi] REMOVED stale glob-swept shim {a.moddir}/module_shim.cpp")
    print(f"[gen_host_abi] wrote host/futari_host_abi.h  host/host_abi_fill.inc  "
          f"moduleshim/module_shim_{modname}.cpp   (abi_hash=0x{h:016X})")


if __name__ == "__main__":
    main()
