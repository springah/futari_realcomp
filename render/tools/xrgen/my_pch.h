#pragma once
// Minimal pch replacement for the XenosRecomp glvl-d3d9 ShaderRecompiler, sufficient to
// generate HLSL text (no FXC / d3dcompiler). Provides be<> and a std::format-backed fmt shim.
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <bit>
#include <string>
#include <string_view>
#include <map>
#include <unordered_map>
#include <filesystem>
#include <format>
#include <iterator>

template<typename T>
static T byteSwap(T value)
{
    if constexpr (sizeof(T) == 1)
        return value;
    else if constexpr (sizeof(T) == 2)
        return static_cast<T>(__builtin_bswap16(static_cast<uint16_t>(value)));
    else if constexpr (sizeof(T) == 4)
        return static_cast<T>(__builtin_bswap32(static_cast<uint32_t>(value)));
    else if constexpr (sizeof(T) == 8)
        return static_cast<T>(__builtin_bswap64(static_cast<uint64_t>(value)));
    assert(false && "Unexpected byte size.");
    return value;
}

template<typename T>
struct be
{
    T value;
    T get() const
    {
        if constexpr (std::is_enum_v<T>)
            return T(byteSwap(std::underlying_type_t<T>(value)));
        else
            return byteSwap(value);
    }
    operator T() const { return get(); }
};

// --- fmt shim mapping the subset used by shader_recompiler onto std::format ---
namespace fmt {
    template<class... Args>
    using format_string = std::format_string<Args...>;

    template<class... Args>
    inline std::string format(std::format_string<Args...> f, Args&&... args) {
        return std::format(f, std::forward<Args>(args)...);
    }

    template<class OutputIt, class... Args>
    inline OutputIt vformat_to(OutputIt out, std::string_view f, std::format_args args) {
        return std::vformat_to(out, f, args);
    }

    template<class... Args>
    inline auto make_format_args(Args&&... args) {
        return std::make_format_args(args...);
    }
}
