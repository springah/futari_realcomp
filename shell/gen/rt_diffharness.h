// rt_diffharness.h -- r23-w150H PER-FUNCTION DIFFERENTIAL HARNESS, CAPTURE SIDE ("shadow mode").
// Design: futari_decomp/docs/PLAN_diffharness.md. HARNESS-ONLY, NEVER SHIP.
//
// Included ONLY by the generated capture TU (futari_decomp/tools/diffharness/dh_gen.py capture), compiled with
// -DRT_DIFFHARNESS into $OBJ/decomp_00dh_capture.o and linked FIRST (first-definition-wins: its strong
// extern "C" __imp__sub_X replaces the generated one, which link_merge.py renames as a loser). No tracked engine
// TU includes this header, so a normal build is byte-for-byte unchanged (default OFF by construction).
//
// The capture TU holds a VERBATIM COPY of each target's generated body whose guest loads/stores (PPC_LOAD_*,
// PPC_STORE_*, VMX lvx/stvx, dcbz memset, lwarx/stwcx) log into a per-call record, and whose calls snapshot the
// full PPCContext before/after. Env (read once):
//   RT_DH_DIR    output directory; UNSET = capture off (the copies still run = the generated bodies)
//   RT_DH_CAP    distinct records written per function (default 32)
//   RT_DH_EVERY  record call #i when i < 8 or i % EVERY == 0 (default 25)
// Output: <dir>/<FN>_<hash16>.dhr (format DHR1, below) + <dir>/dh_counts.txt (calls seen per function = the
// direct-call WITNESS count). Banner "[dh] ARMED" on stderr once (LAWS M+).
//
// DHR1 (little-endian host): char magic[4]="DHR1"; u32 ctxsize, fn, flags, nev, nblob, ncalls, pad;
//   ctx_in[ctxsize]; ctx_out[ctxsize]; ev[nev] = {u32 addr; u8 kind(1 READ 2 WRITE 3 CALL 4 MFTB); u8 size; u16 pad;
//   u32 off (blob offset of the memory-order bytes, or the call index)}; blob[nblob];
//   per call: {u32 target; u32 pad; before[ctxsize]; after[ctxsize]}.
#ifndef RT_DIFFHARNESS
#error "rt_diffharness.h is harness-only (r23-w150H): compile with -DRT_DIFFHARNESS"
#endif

#ifndef RT_DIFFHARNESS_PART1
#define RT_DIFFHARNESS_PART1
#include <cstdint>
#include <cstddef>
struct PPCContext;
struct DhRec;
uint64_t dh_ld(DhRec* r, uint8_t* base, uint32_t ea, unsigned n);
void dh_st(DhRec* r, uint8_t* base, uint32_t ea, unsigned n, uint64_t v);
void dh_bytes_rd(DhRec* r, uint8_t* base, uint32_t ea, unsigned n, void* out);
void dh_bytes_wr(DhRec* r, uint8_t* base, uint32_t ea, unsigned n, const void* in);
void dh_memset(DhRec* r, uint8_t* base, uint32_t ea, int c, size_t n);
bool dh_cas32(DhRec* r, uint8_t* base, uint32_t ea, uint32_t expect_raw, uint32_t new_raw);
uint32_t dh_raw32(DhRec* r, uint8_t* base, uint32_t ea);
void dh_call_pre(DhRec* r, PPCContext& ctx, uint32_t target);
void dh_call_post(DhRec* r, PPCContext& ctx);
DhRec* dh_begin(uint32_t fn, PPCContext& ctx, uint8_t* base);
void dh_end(DhRec* r, PPCContext& ctx);
template<class T> inline T dh_vld_t(DhRec* r, uint8_t* b, uint32_t e){ T v; dh_bytes_rd(r, b, e, 16, &v); return v; }
template<class T> inline void dh_vst_t(DhRec* r, uint8_t* b, uint32_t e, T v){ dh_bytes_wr(r, b, e, 16, &v); }
#define PPC_LOAD_U8(x)  ((uint8_t) dh_ld(dhr, base, (uint32_t)(x), 1))
#define PPC_LOAD_U16(x) ((uint16_t)dh_ld(dhr, base, (uint32_t)(x), 2))
#define PPC_LOAD_U32(x) ((uint32_t)dh_ld(dhr, base, (uint32_t)(x), 4))
#define PPC_LOAD_U64(x) ((uint64_t)dh_ld(dhr, base, (uint32_t)(x), 8))
#define PPC_STORE_U8(x, y)  dh_st(dhr, base, (uint32_t)(x), 1, (uint64_t)(uint8_t)(y))
#define PPC_STORE_U16(x, y) dh_st(dhr, base, (uint32_t)(x), 2, (uint64_t)(uint16_t)(y))
#define PPC_STORE_U32(x, y) dh_st(dhr, base, (uint32_t)(x), 4, (uint64_t)(uint32_t)(y))
#define PPC_STORE_U64(x, y) dh_st(dhr, base, (uint32_t)(x), 8, (uint64_t)(y))
#define DH_VLD(b, e)        dh_vld_t<simde__m128i>(dhr, b, (uint32_t)(e))
#define DH_VST(b, e, v)     dh_vst_t(dhr, b, (uint32_t)(e), v)
#define DH_MEMSET(b, e, c, n) dh_memset(dhr, b, (uint32_t)(e), c, n)
#define DH_CAS32(b, e, a, v)  dh_cas32(dhr, b, (uint32_t)(e), (uint32_t)(a), (uint32_t)(v))
#define DH_RAW32(b, e)        dh_raw32(dhr, b, (uint32_t)(e))
unsigned long long dh_mftb(DhRec* r);
#endif  // RT_DIFFHARNESS_PART1

#if defined(RT_DIFFHARNESS_IMPL) && !defined(RT_DIFFHARNESS_IMPL_DONE)
#define RT_DIFFHARNESS_IMPL_DONE
// ppc_recomp_shared.h (included between the two parts) redefines PPC_CALL_INDIRECT_FUNC unconditionally to
// rt_indirect(x, ctx, base); wrap exactly that dispatch with the call snapshots.
#undef PPC_CALL_INDIRECT_FUNC
#define PPC_CALL_INDIRECT_FUNC(x) do { uint32_t _dh_t = (uint32_t)(x); dh_call_pre(dhr, ctx, _dh_t); \
    rt_indirect(_dh_t, ctx, base); dh_call_post(dhr, ctx); } while (0)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <mutex>
#include <map>
#include <set>
#include <atomic>

struct DhEv { uint32_t addr; uint8_t kind; uint8_t size; uint16_t pad; uint32_t off; };
struct DhCall { uint32_t target; PPCContext before; PPCContext after; };
struct DhRec {
    uint32_t fn; uint32_t flags = 0;
    PPCContext in;
    std::vector<DhEv> ev; std::vector<uint8_t> blob; std::vector<DhCall> calls;
};
struct DhFnState { unsigned long long calls = 0; unsigned recs = 0; std::set<uint64_t> hashes; };

static std::mutex& dh_mu() { static std::mutex m; return m; }
static std::map<uint32_t, DhFnState>& dh_fns() { static std::map<uint32_t, DhFnState> m; return m; }
static const char* dh_dir() { static const char* d = std::getenv("RT_DH_DIR"); return d; }
static unsigned dh_env(const char* k, unsigned dflt) { const char* v = std::getenv(k); return v ? (unsigned)std::strtoul(v, nullptr, 0) : dflt; }

static inline void dh_log(DhRec* r, uint8_t kind, uint32_t ea, unsigned n, const uint8_t* bytes) {
    if (r->ev.size() >= (1u << 22)) { r->flags |= 4; return; }   // overflow guard (4M events): record marked, not used
    DhEv e{ea, kind, (uint8_t)n, 0, (uint32_t)r->blob.size()};
    r->ev.push_back(e); r->blob.insert(r->blob.end(), bytes, bytes + n);
}
uint64_t dh_ld(DhRec* r, uint8_t* base, uint32_t ea, unsigned n) {
    uint8_t b[8]; std::memcpy(b, base + ea, n);
    if (r) dh_log(r, 1, ea, n, b);
    uint64_t v = 0; for (unsigned i = 0; i < n; i++) v = (v << 8) | b[i];
    return v;
}
void dh_st(DhRec* r, uint8_t* base, uint32_t ea, unsigned n, uint64_t v) {
    uint8_t b[8]; for (unsigned i = 0; i < n; i++) b[i] = (uint8_t)(v >> (8 * (n - 1 - i)));
    std::memcpy(base + ea, b, n);
    if (r) dh_log(r, 2, ea, n, b);
}
void dh_bytes_rd(DhRec* r, uint8_t* base, uint32_t ea, unsigned n, void* out) {
    std::memcpy(out, base + ea, n); if (r) dh_log(r, 1, ea, n, (const uint8_t*)out);
}
void dh_bytes_wr(DhRec* r, uint8_t* base, uint32_t ea, unsigned n, const void* in) {
    std::memcpy(base + ea, in, n); if (r) dh_log(r, 2, ea, n, (const uint8_t*)in);
}
void dh_memset(DhRec* r, uint8_t* base, uint32_t ea, int c, size_t n) {
    std::memset(base + ea, c, n);
    if (r) for (size_t o = 0; o < n; o += 16) dh_log(r, 2, ea + (uint32_t)o, (unsigned)((n - o) < 16 ? (n - o) : 16), base + ea + o);
}
bool dh_cas32(DhRec* r, uint8_t* base, uint32_t ea, uint32_t expect_raw, uint32_t new_raw) {
    uint32_t cur; std::memcpy(&cur, base + ea, 4);
    if (r) dh_log(r, 1, ea, 4, (const uint8_t*)&cur);
    bool ok = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ea), expect_raw, new_raw);
    if (ok && r) dh_log(r, 2, ea, 4, (const uint8_t*)&new_raw);
    if (r && !ok) r->flags |= 2;   // CAS failed in the recording: contended, mark (replay reproduces the read value)
    return ok;
}
uint32_t dh_raw32(DhRec* r, uint8_t* base, uint32_t ea) {
    uint32_t v; std::memcpy(&v, base + ea, 4); if (r) dh_log(r, 1, ea, 4, (const uint8_t*)&v); return v;
}
unsigned long long dh_mftb(DhRec* r) {   // the timebase is an INPUT: logged as kind 4 (8 bytes)
    unsigned long long v = rt_mftb();
    if (r) dh_log(r, 4, 0, 8, (const uint8_t*)&v);
    return v;
}
void dh_call_pre(DhRec* r, PPCContext& ctx, uint32_t target) {
    if (!r) return;
    DhEv e{target, 3, 0, 0, (uint32_t)r->calls.size()}; r->ev.push_back(e);
    r->calls.emplace_back(); DhCall& c = r->calls.back(); c.target = target;
    std::memcpy((void*)&c.before, (const void*)&ctx, sizeof(PPCContext));
}
void dh_call_post(DhRec* r, PPCContext& ctx) {
    if (!r) return; std::memcpy((void*)&r->calls.back().after, (const void*)&ctx, sizeof(PPCContext));
}
static void dh_write_counts_locked() {
    char p[1024]; std::snprintf(p, sizeof p, "%s/dh_counts.txt", dh_dir());
    if (FILE* f = std::fopen(p, "w")) {
        for (auto& kv : dh_fns()) std::fprintf(f, "%08X\t%llu\t%u\n", kv.first, kv.second.calls, kv.second.recs);
        std::fclose(f);
    }
}
DhRec* dh_begin(uint32_t fn, PPCContext& ctx, uint8_t* base) {
    (void)base;
    if (!dh_dir()) return nullptr;
    static const unsigned cap = dh_env("RT_DH_CAP", 32), every = dh_env("RT_DH_EVERY", 25);
    static std::atomic<bool> armed{false};
    if (!armed.exchange(true)) { std::fprintf(stderr, "[dh] ARMED dir=%s cap=%u every=%u\n", dh_dir(), cap, every); std::fflush(stderr); }
    unsigned long long i; unsigned recs;
    {
        std::lock_guard<std::mutex> g(dh_mu());
        DhFnState& s = dh_fns()[fn]; i = s.calls++; recs = s.recs;
        if (i == 0 || (i & (i - 1)) == 0 || (i % 1024) == 0) dh_write_counts_locked();
    }
    if (recs >= cap) return nullptr;
    if (!(i < 8 || (i % every) == 0)) return nullptr;
    DhRec* r = new DhRec; r->fn = fn;
    std::memcpy((void*)&r->in, (const void*)&ctx, sizeof(PPCContext));
    return r;
}
void dh_end(DhRec* r, PPCContext& ctx) {
    if (!r) return;
    std::vector<uint8_t> out;
    auto put = [&](const void* p, size_t n) { const uint8_t* b = (const uint8_t*)p; out.insert(out.end(), b, b + n); };
    uint32_t hdr[8] = {0, (uint32_t)sizeof(PPCContext), r->fn, r->flags, (uint32_t)r->ev.size(), (uint32_t)r->blob.size(), (uint32_t)r->calls.size(), 0};
    std::memcpy(&hdr[0], "DHR1", 4);
    put(hdr, sizeof hdr); put(&r->in, sizeof(PPCContext)); put(&ctx, sizeof(PPCContext));
    put(r->ev.data(), r->ev.size() * sizeof(DhEv)); put(r->blob.data(), r->blob.size());
    for (auto& c : r->calls) { uint32_t t[2] = {c.target, 0}; put(t, 8); put(&c.before, sizeof(PPCContext)); put(&c.after, sizeof(PPCContext)); }
    uint64_t h = 1469598103934665603ull; for (uint8_t b : out) { h ^= b; h *= 1099511628211ull; }
    bool write = false; unsigned n = 0; unsigned long long calls = 0;
    {
        std::lock_guard<std::mutex> g(dh_mu());
        static const unsigned cap = dh_env("RT_DH_CAP", 32);
        DhFnState& s = dh_fns()[r->fn];
        if (s.recs < cap && s.hashes.insert(h).second) { write = true; n = ++s.recs; calls = s.calls; dh_write_counts_locked(); }
    }
    if (write) {
        char p[1024]; std::snprintf(p, sizeof p, "%s/%08X_%016llx.dhr", dh_dir(), r->fn, (unsigned long long)h);
        if (FILE* f = std::fopen(p, "wb")) { std::fwrite(out.data(), 1, out.size(), f); std::fclose(f); }
        std::fprintf(stderr, "[dh] rec fn=%08X #%u at call %llu ev=%zu calls=%zu bytes=%zu\n", r->fn, n, calls, r->ev.size(), r->calls.size(), out.size());
        std::fflush(stderr);
    }
    delete r;
}
#endif  // RT_DIFFHARNESS_IMPL
