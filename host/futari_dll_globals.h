#pragma once
// futari_dll_globals.h — the four globals that cross the host<->module-DLL line.
//
// L4/E6 of _tmpscripts/dll_packaging_plan.md.  Notes: _tmpscripts/l4l5_combined_notes.md §2.
//
// WHY THIS FILE EXISTS AS A FILE.  A `static`/`extern` global compiled into BOTH images is TWO
// objects, silently.  The §1.3 bind-struct ABI can only express functions and pointers, so every
// datum shared across the boundary must be host-owned and reached through the bound
// FutariHostAbi.  The macro pair below keeps every USE SITE unchanged: inside a DLL the name
// expands to a deref of the bound pointer, everywhere else it is the plain global it always was.
//
// It was factored out of merged_common.h the moment a SECOND DLL-side TU needed it
// (decomp/game/crt_hooks.cpp, which declared its own `extern std::atomic<long> g_import_calls;`
// and therefore failed to link into the DLL).  Any future DLL-side TU that touches one of these
// four must include THIS header rather than writing its own extern — that is the whole point.
//
//   g_import_calls   host: out_reco/stubs.cpp      DLL: reads/increments
//   g_rt_startline   host: shell/gen/stubs.cpp     DLL: reads (P1 START LEVEL, rapid-fire wiring)
//   g_rt_romactive   host: merged_bridge.cpp       DLL: WRITES (sub_88168D48 = ROM main entered)
//   g_rt_realstage   host: merged_bridge.cpp       DLL: WRITES (RT_NAVREAL real-stage latch)
//
// The last two were DEFINED in merged_game.cpp until L4.  They are written by the game half and
// read by the host (render/vk_render.cpp, shell/gen/rt.cpp, merged_shell.cpp), and vk_render.cpp
// carries a `__attribute__((weak))` definition of g_rt_romactive — so a per-DLL copy would have
// LINKED CLEANLY and left rt_rom_render()'s routing gate and the TATE pillarbox permanently
// false, with no diagnostic anywhere.  That silent class is why the storage is host-owned now.
//
// The pointers are DEFINED in the generated moduleshim/module_shim_<mod>.cpp and assigned inside
// FutariModuleBind(), which the host calls immediately after LoadLibrary and BEFORE any guest
// code, any function-table registration, and any DllMain(PROCESS_ATTACH) — so no DLL code can
// observe a null one.  (The DLL's own C++ static initialisers run earlier, at LoadLibrary time;
// none of them touch these four.)
#include <atomic>

#ifdef FUTARI_IN_MODULE_DLL
extern "C" {
    extern std::atomic<long>* futari_p_import_calls;    // moduleshim/module_shim_<mod>.cpp
    extern std::atomic<int>*  futari_p_rt_startline;
    extern volatile int*      futari_p_rt_romactive;
    extern volatile int*      futari_p_rt_realstage;
}
#define g_import_calls  (*futari_p_import_calls)
#define g_rt_startline  (*futari_p_rt_startline)
#define g_rt_romactive  (*futari_p_rt_romactive)
#define g_rt_realstage  (*futari_p_rt_realstage)
#else
extern std::atomic<long> g_import_calls;                // out_reco/stubs.cpp
extern "C" { extern volatile int g_rt_romactive; }      // merged_bridge.cpp (moved here at L4)
extern "C" { extern volatile int g_rt_realstage; }      // merged_bridge.cpp (moved here at L4)
// g_rt_startline is declared by its own consumers (merged_game.cpp) — it is shell/gen/stubs.cpp's
// symbol and predates this header; not redeclared here to avoid a second source of truth.
#endif
