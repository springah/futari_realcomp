// futari_ini_preinit.cpp -- applies futari.ini before every other static initializer in a Mach-O image (macOS builds).
//
// WHY A TU OF ITS OWN (w1107 MAC-CONFIG-VERIFY, 2026-11-07): Mach-O has no initializer priorities. Apple's toolchain
// accepts __attribute__((constructor(101))) and init_priority and IGNORES the number; dyld runs __mod_init_func in the
// order of the objects on the link line (proved with a two-TU test: a file-scope initializer in the first object runs
// before a constructor(101) in the second). The engine's link line starts with the decomp census objects (decomp_*.o,
// first-definition-wins), whose file-scope banners read RT_*CENSUS at static init, so the constructor that used to live
// in out_reco/harness.cpp (game_harness.o) ran AFTER four of them: the first macOS log showed [menunodecensus],
// [shellcensus], [tvdcensus] and [xnotifycensus] before the [ini] lines. build_mac.sh and build_mac_dll.sh compile this
// file as preinit_futari_ini.o and put it FIRST on the link line, so the ini is applied before anything else in the
// image initialises. Linux/ELF and Windows keep the harness.cpp hooks (constructor(101) / .CRT$XCT), which their
// toolchains honour. apply_once() makes the second hook a no-op.
#include "futari_ini.h"
__attribute__((constructor)) static void futari_ini_preinit(void) { futari_ini::apply_once("engine, before static init"); }
