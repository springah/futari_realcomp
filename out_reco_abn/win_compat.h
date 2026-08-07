#pragma once
// ===========================================================================
// win_compat.h — native Windows (clang++ -target x86_64-pc-windows-msvc) shim
// for the futariRealComp merged-binary port. On Linux this header is inert, so
// the existing WSL/Arch build is unaffected; every Windows-only replacement is
// gated behind _WIN32. Include this from the kernel/harness TUs and wrap their
// POSIX includes in `#ifndef _WIN32`.
// ===========================================================================
#ifdef _WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <process.h>      // _beginthreadex/_endthreadex, _exit
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <thread>
#include <chrono>

// --- POSIX types the recomp kernel casts to but Windows doesn't declare -----
typedef unsigned long useconds_t;
// NOTE: MSVC's <sys/types.h> already typedefs off_t (32-bit); we don't redefine it.
// The one 64-bit seek cast in rt.cpp uses (long long) directly instead.

// --- timing: usleep(3) -> std::this_thread::sleep_for --------------------
static inline int usleep(useconds_t us) {
    std::this_thread::sleep_for(std::chrono::microseconds((long long)us));
    return 0;
}

// --- POSIX alarm(2): no-op stub. The SIGALRM hang-sampler watchdog is a
//     debug-only aid; for the native bring-up it is disarmed (the sigaction
//     path that consumed SIGALRM is removed in harness.cpp on Windows). -----
static inline unsigned int alarm(unsigned int) { return 0; }

// --- diagnostic host thread id: syscall(SYS_gettid) -> GetCurrentThreadId --
static inline long xr_gettid() { return (long)GetCurrentThreadId(); }

// --- case-insensitive compare: strncasecmp -> _strnicmp ------------------
static inline int strncasecmp(const char* a, const char* b, size_t n) {
    return _strnicmp(a, b, n);
}

// --- 64-bit file seek/tell: fseeko/ftello -> _fseeki64/_ftelli64 ---------
static inline int  fseeko(FILE* f, long long off, int whence) { return _fseeki64(f, off, whence); }
static inline long long ftello(FILE* f) { return _ftelli64(f); }

// --- guest 4GB flat arena: mmap(MAP_ANONYMOUS|MAP_NORESERVE) -> VirtualAlloc.
//     Commit the whole range up front (zero-filled, matching MAP_ANONYMOUS);
//     4GB commit needs pagefile headroom but keeps the flat-address model the
//     recompiled kernel assumes (every guest address is backed). ------------
static inline uint8_t* xr_guest_arena(unsigned long long size) {
    return (uint8_t*)VirtualAlloc(nullptr, (SIZE_T)size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

#else  // !_WIN32 — Linux/WSL keeps its native POSIX; expose a uniform gettid.

#include <unistd.h>
#include <sys/syscall.h>
static inline long xr_gettid() { return (long)syscall(SYS_gettid); }

#endif // _WIN32

