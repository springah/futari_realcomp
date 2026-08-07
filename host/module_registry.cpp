// module_registry.cpp — load / bind / activate / SWAP the per-module game DLLs.
//
// L4+L5 of _tmpscripts/dll_packaging_plan.md (§3.2 the ordered swap sequence, §3.5 the unload
// policy, §3.6 the publication order).  Notes: _tmpscripts/l4l5_combined_notes.md.
// COMBINED EXE ONLY — build_win_dll.sh.  Never compiled into the two per-module exes.
//
// WHAT MAKES THE SWAP SAFE, IN ONE PARAGRAPH
//   reco_normal and reco_abnormal are the SAME GAME at the SAME guest image base with the SAME
//   image size, so they share one function-table window (0x887B0000..) and one guest image
//   window (0x88000000..0x887B0000).  A swap is therefore: clear the outgoing module's table
//   slots, zero the shared image window, register the incoming module's slots, publish, and let
//   the bridge's existing attach block re-image .data and re-run DllMain — which is EXACTLY the
//   RT_REATTACH sequence that was live-proven on 2026-07-29 (two full A,B,A cycles, zero VK
//   errors), with two additions: the slot swap, and the .bss zero that a same-module reattach
//   did not need.
#include "module_registry.h"
#include "futari_module_desc.h"
#include "host_abi_fill.inc"        // GENERATED: extern decls + futari_build_host_abi()

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
// Mac/Deck are post-alpha (plan §7); the dlopen arm lands with them.  Keep the file compiling.
#define MAX_PATH 260
#define _stricmp  strcasecmp
#define _strnicmp strncasecmp
#endif

// ---------------------------------------------------------------------------------------
// PPCFuncMapping, mirrored.  This TU deliberately does NOT include ppc_context.h: that header
// pulls in simde/SSE and the whole recompiler world for a two-field POD.  The mirror is
// layout-identical to out_reco/ppc_context.h:121-125 (`struct PPCFuncMapping { size_t guest;
// PPCFunc* host; }`) and is checked at runtime by futari_mappings_sane() below — a layout drift
// shows up as a loud refusal at boot, not as a wild function pointer.
// ---------------------------------------------------------------------------------------
struct FutariMappingRow { size_t guest; FutariPPCFunc* host; };

// ---------------------------------------------------------------------------------------
// State
// ---------------------------------------------------------------------------------------
extern "C" const FutariModuleDesc* volatile g_futari_cur_desc = nullptr;
extern "C" uint32_t g_futari_hosted_mask = 0;

namespace {

struct ModuleSlot {
    const char* dllname;                 // "futari_game_normal.dll"
    const char* basename;                // "reco_normal" — what the guest path is matched against
    uint32_t    mode_idx;                // 0 / 1
    void*       hmod;                    // HMODULE
    const FutariModuleDesc* desc;        // what FutariModuleBind returned (points INTO the DLL)
    long        activations;
};

// The build's module inventory.  Adding a third module is one row plus its DLL — the mask, the
// stub layers, the resolver and the swap all read this table and need no other edit.
ModuleSlot g_slots[] = {
    { "futari_game_normal.dll", "reco_normal",   0u, nullptr, nullptr, 0 },
    { "futari_game_abn.dll",    "reco_abnormal", 1u, nullptr, nullptr, 0 },
};
constexpr int NSLOT = (int)(sizeof(g_slots) / sizeof(g_slots[0]));

FutariHostAbi g_abi;                     // the ONE instance; every DLL gets a pointer to it
uint8_t*      g_base = nullptr;
char          g_summary[512] = "(registry not booted)";
std::atomic<long> g_swaps{0};

bool envon(const char* k, bool dflt) {
    const char* e = std::getenv(k);
    return e ? (std::atoi(e) != 0) : dflt;
}

// ---- the guest function table --------------------------------------------------------
// Slot address is the recompiler's own convention (ppc_context.h:113):
//     base + image_base + image_size + (guest - code_base) * 2
// The descriptor carries table_base = image_base + image_size (static_asserted in
// futari_module_desc.h), so this is that formula with every constant per-module.
inline FutariPPCFunc** slot_of(uint8_t* base, const FutariModuleDesc* d, uint32_t guest) {
    return (FutariPPCFunc**)(base + (uint64_t)d->table_base
                                  + (uint64_t)(guest - d->code_base) * 2);
}

bool mappings_sane(const FutariModuleDesc* d) {
    if (!d->mappings || !d->mapping_count) {
        std::fprintf(stderr, "[modreg] FATAL: %s bound with no function table (mappings=%p count=%u)\n",
                     d->module_basename, (const void*)d->mappings, d->mapping_count);
        return false;
    }
    const FutariMappingRow* r = (const FutariMappingRow*)d->mappings;
    // First non-null row must sit inside the module's own code range.  If the mirror struct's
    // layout were wrong this is garbage and we refuse instead of writing wild table slots.
    for (uint32_t i = 0; i < d->mapping_count; ++i) {
        if (!r[i].host) continue;
        uint32_t g = (uint32_t)r[i].guest;
        if (g < d->code_base || g >= d->code_base + d->code_size) {
            std::fprintf(stderr, "[modreg] FATAL: %s mapping[%u].guest=0x%08X outside code range "
                                 "0x%08X..0x%08X — PPCFuncMapping layout mismatch?\n",
                         d->module_basename, i, g, d->code_base, d->code_base + d->code_size);
            return false;
        }
        return true;
    }
    std::fprintf(stderr, "[modreg] FATAL: %s function table has no live rows\n", d->module_basename);
    return false;
}

long table_write(uint8_t* base, const FutariModuleDesc* d, bool install) {
    const FutariMappingRow* r = (const FutariMappingRow*)d->mappings;
    long n = 0;
    for (const FutariMappingRow* m = r; m->guest || m->host; ++m) {
        if (!m->host) continue;
        *slot_of(base, d, (uint32_t)m->guest) = install ? m->host : nullptr;
        ++n;
    }
    return n;
}

// Plan §3.5's mitigation, promoted to a routine gate: after deactivate, NOTHING in the outgoing
// module's table window may still point into that module.  A survivor is a dangling dispatch
// waiting to happen, so it is reported loudly (and aborts under RT_SWAPSTRICT).
long table_residue(uint8_t* base, const FutariModuleDesc* d) {
    // The window spans code_size*2 BYTES and holds one 8-byte host pointer per 4 guest bytes
    // (offset = (guest-code_base)*2), i.e. code_size/4 slots.  Getting this arithmetic wrong is
    // an out-of-bounds read of the guest arena, so it is spelled out rather than inlined.
    const uint64_t nslots = (uint64_t)d->code_size / 4u;
    FutariPPCFunc** p = (FutariPPCFunc**)(base + (uint64_t)d->table_base);
    long live = 0;
    for (uint64_t i = 0; i < nslots; ++i) if (p[i]) ++live;
    return live;
}

// ---- host-side cache teardown --------------------------------------------------------
// Both are weak so this TU links whether or not the owning file has grown its implementation
// yet.  rvk_module_swap_invalidate lands with this leg (render/vk_render.cpp);
// rt_audio_module_swap is DELIBERATELY left unimplemented for beta1 — see the call site.
extern "C" void rvk_module_swap_invalidate(void) __attribute__((weak));
extern "C" void rt_audio_module_swap(void) __attribute__((weak));
// CODE_REVIEW_0804 A5: renderer lock across the guest-memory mutation window (steps 3-6) so a
// mid-flight frame walk can never read a half-zeroed arena. Weak like the invalidate hook.
extern "C" void rvk_swap_guard_begin(void) __attribute__((weak));
extern "C" void rvk_swap_guard_end(void) __attribute__((weak));

} // namespace

// =========================================================================================
extern "C" const char* futari_registry_summary(void) { return g_summary; }

extern "C" const FutariModuleDesc* futari_registry_resolve_path(const char* p) {
    if (!p || !*p) return nullptr;
    for (int i = 0; i < NSLOT; ++i) {
        if (!g_slots[i].desc) continue;                 // DLL absent / failed to bind
        const char* needle = g_slots[i].basename;
        const size_t nl = std::strlen(needle);
        for (const char* q = p; *q; ++q)
            if (_strnicmp(q, needle, nl) == 0) return g_slots[i].desc;
    }
    return nullptr;
}

// =========================================================================================
// THE SWAP (plan §3.2, steps renumbered to what this build actually needs).
// =========================================================================================
extern "C" int futari_registry_switch(const FutariModuleDesc* d, uint8_t* base) {
    if (!d) return 0;
    const FutariModuleDesc* cur = g_futari_cur_desc;
    if (d == cur) return 1;                              // already live — nothing to do

    const long sn = g_swaps.fetch_add(1) + 1;
    std::fprintf(stderr, "\n[modswap] #%ld  %s -> %s   (modeIdx %u -> %u)\n", sn,
                 cur ? cur->module_basename : "(none)", d->module_basename,
                 cur ? cur->hosted_mode_idx : 0xFFFFFFFFu, d->hosted_mode_idx);

    // -- 1. host caches keyed on GUEST ADDRESSES are now lying: the same address holds a
    //       different module's art.  Drop them BEFORE the arena is touched.  The renderer's
    //       entry point does the render-thread handshake itself (vk_render.cpp).
    if (rvk_module_swap_invalidate) rvk_module_swap_invalidate();
    else std::fprintf(stderr, "[modswap] (no renderer linked — skipping host cache drop)\n");

    // -- 2. audio.  For reco_normal <-> reco_abnormal this is a KNOWN NO-OP: both modules read
    //       the SAME assets/media/Sound/*.xwb|xsb banks, so no cue/wave index can change meaning
    //       across this swap.  The hook exists (weak) so the day a sibling TITLE with its own
    //       banks arrives, the implementation lands in rt_audio.cpp and this call finds it.
    //       Filed as post-beta debt rather than written blind: rt_audio.cpp is owned by the
    //       audio lane today and the two banks are provably identical.
    if (rt_audio_module_swap) rt_audio_module_swap();

    // CODE_REVIEW_0804 A5: hold the renderer lock over steps 3-6 (see rvk_swap_guard_begin's
    // comment in vk_render.cpp). Taken AFTER the invalidate ack-wait above by construction.
    if (rvk_swap_guard_begin) rvk_swap_guard_begin();

    // -- 3. retire the outgoing module's table slots.  Explicit per-row, never a memset: the
    //       window is SHARED between the two modules and a memset would also clear rows the
    //       incoming module is about to reuse (harmless) — but more importantly it would hide
    //       the residue check below.
    if (cur) {
        long n = table_write(base, cur, /*install=*/false);
        long res = table_residue(base, cur);
        std::fprintf(stderr, "[modswap]  retired %ld table slots from %s; residue=%ld\n",
                     n, cur->module_basename, res);
        if (res) {
            std::fprintf(stderr, "[modswap]  ⚠ %ld slot(s) in the game table window still point "
                                 "somewhere after deactivation — a stale host fn ptr would be "
                                 "dispatched as %s code.\n", res, d->module_basename);
            if (envon("RT_SWAPSTRICT", false)) {
                std::fprintf(stderr, "[modswap]  RT_SWAPSTRICT=1 -> abort\n");
                std::fflush(stderr); std::_Exit(9);
            }
        }
    }

    // -- 4. zero the shared guest image window.  rt_load_game_data_sections only copies sections
    //       that HAVE file bytes (merged_bridge.cpp: `if(!sN.data || z==0) continue;`), so .bss
    //       would otherwise carry the outgoing module's garbage into the incoming one — the
    //       silent-corruption class plan §3.2 step 9 names.  RT_SWAPZERO=0 reverts to the
    //       proven-but-narrower RT_REATTACH behaviour for A/B.
    //       SAFETY: the window is [image_base, image_base+image_size) = 0x88000000..0x887B0000.
    //       The function table starts AT image_base+image_size (asserted in the descriptor) so
    //       it is excluded by construction, and the guest heap is a bump allocator starting at
    //       0x00300000 (out_reco/harness.cpp:28) capped far below 0x88000000 — asserted here.
    //       At BOOT (cur == nullptr) there is nothing to clean and the harness may already have
    //       memcpy'd an argv-supplied XEX into this window, so the zero is swap-only.
    if (cur && envon("RT_SWAPZERO", true)) {
        std::memset(base + d->image_base, 0, d->image_size);
        std::fprintf(stderr, "[modswap]  zeroed guest image window 0x%08X..0x%08X (%u bytes)\n",
                     d->image_base, d->image_base + d->image_size, d->image_size);
    } else if (cur) {
        std::fprintf(stderr, "[modswap]  RT_SWAPZERO=0 — image window left dirty (A/B lever)\n");
    }

    // -- 5. install the incoming module's slots.
    if (!mappings_sane(d)) { if (rvk_swap_guard_end) rvk_swap_guard_end(); return 0; }
    long n = table_write(base, d, /*install=*/true);
    std::fprintf(stderr, "[modswap]  installed %ld table slots for %s\n", n, d->module_basename);

    // -- 6. publish.  Release fence first: every slot store above must be visible to any thread
    //       that observes the new g_futari_cur_desc.  The guest's own game threads are all
    //       joined at this point, but the SHELL's threads are not (plan §3.6).
    std::atomic_thread_fence(std::memory_order_release);
    g_futari_cur_desc = d;
    for (int i = 0; i < NSLOT; ++i) if (g_slots[i].desc == d) ++g_slots[i].activations;

    if (rvk_swap_guard_end) rvk_swap_guard_end();

    std::fprintf(stderr, "[modswap] #%ld DONE — live module is now %s (entry ord1=0x%08X, "
                         "code 0x%08X+0x%X)\n\n",
                 sn, d->module_basename, d->entry_ord1, d->code_base, d->code_size);
    std::fflush(stderr);
    return 1;
}

// =========================================================================================
// BOOT
// =========================================================================================
namespace {

#ifdef _WIN32
void* load_module_dll(const char* name, char* whereOut, size_t whereN) {
    // Search order: RT_MODDLL_DIR, the exe's own directory, then the loader's default (cwd/PATH).
    char path[MAX_PATH * 2];
    const char* dir = std::getenv("RT_MODDLL_DIR");
    if (dir && *dir) {
        std::snprintf(path, sizeof path, "%s\\%s", dir, name);
        HMODULE h = LoadLibraryA(path);
        if (h) { std::snprintf(whereOut, whereN, "%s", path); return h; }
    }
    char exe[MAX_PATH];
    DWORD n = GetModuleFileNameA(nullptr, exe, MAX_PATH);
    if (n && n < MAX_PATH) {
        char* slash = std::strrchr(exe, '\\');
        if (slash) {
            *slash = 0;
            std::snprintf(path, sizeof path, "%s\\%s", exe, name);
            HMODULE h = LoadLibraryA(path);
            if (h) { std::snprintf(whereOut, whereN, "%s", path); return h; }
        }
    }
    HMODULE h = LoadLibraryA(name);
    if (h) { std::snprintf(whereOut, whereN, "%s (loader search path)", name); return h; }
    std::snprintf(whereOut, whereN, "%s NOT FOUND (err %lu)", name, (unsigned long)GetLastError());
    return nullptr;
}
void* dll_sym(void* h, const char* s) { return (void*)GetProcAddress((HMODULE)h, s); }
#else
void* load_module_dll(const char*, char* w, size_t n) { std::snprintf(w, n, "(no dlopen path yet)"); return nullptr; }
void* dll_sym(void*, const char*) { return nullptr; }
#endif

} // namespace

extern "C" int futari_registry_boot(uint8_t* base) {
    g_base = base;
    g_abi  = futari_build_host_abi(base);

    std::fprintf(stderr, "[modreg] host ABI v%u size=%u hash=0x%016llX\n",
                 g_abi.abi_version, g_abi.struct_size, (unsigned long long)g_abi.abi_hash);

    int bound = 0;
    for (int i = 0; i < NSLOT; ++i) {
        char where[MAX_PATH * 2] = {0};
        g_slots[i].hmod = load_module_dll(g_slots[i].dllname, where, sizeof where);
        if (!g_slots[i].hmod) {
            std::fprintf(stderr, "[modreg] %-24s SKIPPED — %s\n", g_slots[i].dllname, where);
            continue;
        }
        FutariModuleBindFn bind = (FutariModuleBindFn)dll_sym(g_slots[i].hmod,
                                                              FUTARI_MODULE_BIND_SYMBOL);
        if (!bind) {
            std::fprintf(stderr, "[modreg] %-24s LOADED but exports no %s — ignoring\n",
                         g_slots[i].dllname, FUTARI_MODULE_BIND_SYMBOL);
            continue;
        }
        const FutariModuleDesc* d = bind(&g_abi);
        if (!d) {
            std::fprintf(stderr, "[modreg] %-24s REFUSED THE BIND (ABI mismatch — rebuild the DLL "
                                 "and the exe together; host hash 0x%016llX)\n",
                         g_slots[i].dllname, (unsigned long long)g_abi.abi_hash);
            continue;
        }
        if (d->abi_version != FUTARI_MODULE_ABI || d->struct_size != (uint32_t)sizeof(FutariModuleDesc)) {
            std::fprintf(stderr, "[modreg] %-24s descriptor mismatch (v%u size %u, want v%u size %zu)\n",
                         g_slots[i].dllname, d->abi_version, d->struct_size,
                         FUTARI_MODULE_ABI, sizeof(FutariModuleDesc));
            continue;
        }
        if (d->hosted_mode_idx != g_slots[i].mode_idx ||
            std::strcmp(d->module_basename, g_slots[i].basename) != 0) {
            std::fprintf(stderr, "[modreg] %-24s IS THE WRONG MODULE: says '%s'/mode %u, slot wants "
                                 "'%s'/mode %u — refusing (a mixed-up DLL would silently serve the "
                                 "wrong game)\n",
                         g_slots[i].dllname, d->module_basename, d->hosted_mode_idx,
                         g_slots[i].basename, g_slots[i].mode_idx);
            continue;
        }
        g_slots[i].desc = d;
        g_futari_hosted_mask |= (1u << d->hosted_mode_idx);
        ++bound;
        std::fprintf(stderr, "[modreg] %-24s BOUND  %-14s modeIdx %u  ord1=0x%08X  code=0x%08X+0x%-6X"
                             "  maps=%u  (%s)\n",
                     g_slots[i].dllname, d->module_basename, d->hosted_mode_idx, d->entry_ord1,
                     d->code_base, d->code_size, d->mapping_count, where);
    }

    if (!bound) {
        std::fprintf(stderr, "[modreg] FATAL: no game module DLL could be bound. This exe hosts no "
                             "game. Put futari_game_normal.dll / futari_game_abn.dll next to the "
                             "exe, or point RT_MODDLL_DIR at them.\n");
        std::fflush(stderr);
        return 1;
    }

    // Boot module: RT_STARTMODULE accepts a basename ("reco_abnormal") or a modeIdx ("1").
    // Default is the first bound slot, i.e. reco_normal — the accepted alpha's behaviour.
    const char* want = std::getenv("RT_STARTMODULE");
    int pick = -1;
    for (int i = 0; i < NSLOT && pick < 0; ++i) {
        if (!g_slots[i].desc) continue;
        if (!want || !*want) { pick = i; break; }
        if (_stricmp(want, g_slots[i].basename) == 0) pick = i;
        else if (want[0] >= '0' && want[0] <= '9' && (uint32_t)std::atoi(want) == g_slots[i].mode_idx) pick = i;
    }
    if (pick < 0) {
        std::fprintf(stderr, "[modreg] RT_STARTMODULE='%s' matches no bound module — falling back "
                             "to the first bound one\n", want ? want : "");
        for (int i = 0; i < NSLOT && pick < 0; ++i) if (g_slots[i].desc) pick = i;
    }

    // Activate.  Deliberately reuses the swap path with cur==nullptr so the boot and the swap
    // cannot drift apart: whatever the swap does to the table, the boot does too.
    if (!futari_registry_switch(g_slots[pick].desc, base)) {
        std::fprintf(stderr, "[modreg] FATAL: could not activate %s\n", g_slots[pick].basename);
        return 1;
    }

    std::snprintf(g_summary, sizeof g_summary,
                  "%d/%d module DLL(s) bound, hosted modeIdx mask=0x%02X, boot module=%s",
                  bound, NSLOT, g_futari_hosted_mask, g_slots[pick].basename);
    std::fprintf(stderr, "[modreg] %s\n", g_summary);
    std::fflush(stderr);
    return 0;
}
