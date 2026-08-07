#pragma once

// Minimal mirror of UnleashedRecomp's shader_cache.h, just enough for the
// XenosRecomp-generated shader_cache_shell.h to compile standalone.
//
// Mirrored EXACTLY (field order, types, const-ness) from:
//   ~/UnleashedRecomp/UnleashedRecompLib/shader/shader_cache.h
//
// The `guestShader` member is never referenced by the generated cache file
// (it's runtime-only state used by the real engine), so `GuestShader` only
// needs to exist as an incomplete type here.

#include <cstdint>
#include <cstddef>

struct ShaderCacheEntry
{
    const uint64_t hash;
    const uint32_t dxilOffset;
    const uint32_t dxilSize;
    const uint32_t spirvOffset;
    const uint32_t spirvSize;
    const uint32_t specConstantsMask;
    struct GuestShader* guestShader;
};

extern ShaderCacheEntry g_shaderCacheEntries[];
extern const size_t g_shaderCacheEntryCount;

extern const uint8_t g_compressedDxilCache[];
extern const size_t g_dxilCacheCompressedSize;
extern const size_t g_dxilCacheDecompressedSize;

extern const uint8_t g_compressedSpirvCache[];
extern const size_t g_spirvCacheCompressedSize;
extern const size_t g_spirvCacheDecompressedSize;
