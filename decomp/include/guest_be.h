// guest_be.h — one field type that means "a guest big-endian value".
//
// The whole point: ONE source compiles two ways.
//   * Under the XDK 9328 PowerPC compiler the guest IS big-endian, so be<T> is the identity
//     and the generated instructions are byte-identical to plain T (this is checked by
//     ppcmatch, not assumed).
//   * Under the host compiler (clang-cl, x86) it byte-swaps, matching PPC_LOAD_*/PPC_STORE_*
//     in out_reco/ppc_context.h, so the same code is correct when linked into the port.
//
// Only fields that live in GUEST MEMORY need this. Locals and parameters are host-native.

#ifndef GUEST_BE_H
#define GUEST_BE_H

#if defined(_XENON) || defined(_M_PPC) || defined(__powerpc__) || defined(__POWERPC__)
#  define GUEST_IS_BIG_ENDIAN 1
#else
#  define GUEST_IS_BIG_ENDIAN 0
#endif

template <class T>
struct be
{
    T raw;

#if GUEST_IS_BIG_ENDIAN
    static T swap(T v) { return v; }
#else
    static T swap(T v)
    {
        unsigned int x = (unsigned int)v;
        x = (x >> 24) | ((x >> 8) & 0x0000FF00u) | ((x << 8) & 0x00FF0000u) | (x << 24);
        return (T)x;
    }
#endif

    operator T() const { return swap(raw); }
    be& operator=(T v) { raw = swap(v); return *this; }
};

#endif
