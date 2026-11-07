// futari_ini.h -- the player-facing settings file (futari.ini), mapped onto the engine's existing env levers.
//
// WHY A HEADER: the same code runs in two processes. The engine (out_reco/harness.cpp: BEFORE C++ static initialisation --
// a .CRT$XCT pointer on Windows, a constructor elsewhere -- with a no-op fallback at the top of main()) and the macOS
// bundle launcher (mac-build/launcher.c, before its own "only if unset" defaults). Everything the engine reads is an
// environment variable, read at first use and often cached in a function-local static, so turning ini keys into
// environment variables before anything runs reaches every lever with no engine change. "Before static init" matters:
// the first w1107 build applied the ini at the top of main() and the log showed the shell/gen/rt_audio.cpp [env] banner
// (a file-scope initializer that resolves and caches RT_SINKWASAPI and the RT_AUDIO* levers) printing BEFORE the [ini]
// lines, so audio.sink would have been ignored; with the .CRT$XCT hook the [ini] lines are the log's first lines and
// audio.sink = wasapi reaches the banner. Two namespace-scope getenv initialisers also exist (out_reco/rt.cpp
// RT_EVT14TRACE, shell/gen/rt.cpp RT_LRBAND); debug levers, reachable only through [env], and covered by the same hook.
//
// PRECEDENCE (highest first):
//   1. a variable already set in the environment (every drive script, a terminal launch, a tester's override) -- never touched
//   2. futari.ini
//   3. launcher defaults: FUTARI_DEFAULTS="NAME=value;NAME=value" (the Windows launcher's player-facing values), or on
//      macOS the launcher's own def() calls, which run after this.
// A key whose ini value means "off/auto" (e.g. vsync = auto, keyboard = false) DECIDES the variable as unset, so a launcher
// default for it is not applied either.
//
// WHERE THE FILE IS: $FUTARI_INI if set; else futari.ini next to the executable; else (macOS) ~/Library/Application
// Support/Futari Realcomp/futari.ini. Relative paths inside it resolve against the ini's own folder.
//
// LOG: one "[ini]" line per decision on stderr (the session log). A launcher that already applied the file passes the
// list on in FUTARI_INI_APPLIED, so the engine's log still names which values came from the ini.
//
// The key table below is the reference; tools/settings/futari.ini.template documents every key for players and
// tools/settings/futari_settings.py writes the file. Keep the three in step.
#pragma once
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#else
#include <limits.h>
#include <unistd.h>
#endif
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

namespace futari_ini {

inline std::string trim(const std::string& s) {
  size_t a = 0, b = s.size();
  while (a < b && std::isspace((unsigned char)s[a])) ++a;
  while (b > a && std::isspace((unsigned char)s[b - 1])) --b;
  return s.substr(a, b - a);
}
inline std::string lower(std::string s) { for (auto& c : s) c = (char)std::tolower((unsigned char)c); return s; }
inline bool is_sep(char c) { return c == '/' || c == '\\'; }
inline bool is_abs(const std::string& p) {
#ifdef _WIN32
  return (p.size() >= 2 && p[1] == ':') || (!p.empty() && is_sep(p[0]));
#else
  return !p.empty() && p[0] == '/';
#endif
}
inline std::string dir_of(const std::string& p) {
  size_t k = p.find_last_of("/\\");
  return k == std::string::npos ? std::string(".") : p.substr(0, k);
}
inline bool file_exists(const std::string& p) { FILE* f = std::fopen(p.c_str(), "rb"); if (!f) return false; std::fclose(f); return true; }

inline std::string exe_dir() {
#ifdef _WIN32
  char buf[MAX_PATH * 2] = {0};
  DWORD n = GetModuleFileNameA(nullptr, buf, (DWORD)sizeof buf);
  if (n == 0 || n >= sizeof buf) return std::string();
  return dir_of(buf);
#elif defined(__APPLE__)
  char buf[4096]; uint32_t n = sizeof buf;
  if (_NSGetExecutablePath(buf, &n) != 0) return std::string();
  char real[PATH_MAX]; if (!realpath(buf, real)) return dir_of(buf);
  return dir_of(real);
#else
  char buf[4096]; ssize_t n = readlink("/proc/self/exe", buf, sizeof buf - 1);
  if (n <= 0) return std::string();
  buf[n] = 0; return dir_of(buf);
#endif
}

// Candidate locations, in search order (the first that exists wins).
inline std::vector<std::string> candidates() {
  std::vector<std::string> v;
  if (const char* e = std::getenv("FUTARI_INI")) { if (*e) { v.push_back(e); return v; } }
  std::string d = exe_dir();
#ifdef _WIN32
  if (!d.empty()) v.push_back(d + "\\futari.ini");
#else
  if (!d.empty()) v.push_back(d + "/futari.ini");
#endif
#ifdef __APPLE__
  if (const char* h = std::getenv("HOME")) v.push_back(std::string(h) + "/Library/Application Support/Futari Realcomp/futari.ini");
#endif
  return v;
}

inline bool env_set(const char* k) { const char* e = std::getenv(k); return e != nullptr; }
inline void env_put(const char* k, const std::string& v) {
#ifdef _WIN32
  _putenv_s(k, v.c_str());   // also updates the process environment block, so module DLLs and SDL see it
#else
  setenv(k, v.c_str(), 0);
#endif
}

// value kinds a key can take
enum Kind { STR, PATH, BOOL_SET1, BOOL_INV_SET1, VSYNC, ROTATE, UINT, SINK, WINSIZE };
struct Key { const char* name; const char* env; Kind kind; const char* help; };
// THE KEY TABLE. section.key -> env lever. Every row is an EXISTING lever except RVK_FULLSCREEN (added with this file:
// render/vk_render.cpp rvkWindowInit opens the window in borderless fullscreen; F11 still toggles).
inline const std::vector<Key>& keys() {
  static const std::vector<Key> k = {
    {"display.window_size",      "RVK_WINSIZE",       WINSIZE,       "WxH client size, 320x240..7680x4320; the 1280x720 picture is scaled into it"},
    {"display.fullscreen",       "RVK_FULLSCREEN",    BOOL_SET1,     "true = start in borderless fullscreen (F11 toggles either way)"},
    {"display.vsync",            "RVK_VSYNC",         VSYNC,         "auto (MAILBOX where offered) | on (FIFO) | off (IMMEDIATE, may tear)"},
    {"display.f11_fullscreen",   "RVK_NOF11",         BOOL_INV_SET1, "false = F11 does nothing"},
    {"display.rotate",           "RT_ROTATE",         ROTATE,        "0 | 90 | 270: rotate the window picture (portrait monitors)"},
    {"display.gpu",              "RVK_GPU",           STR,           "part of the GPU name to prefer (case-sensitive); empty = discrete first"},
    {"audio.sink",               "RT_SINKWASAPI",     SINK,          "sdl (default) | wasapi (Windows only: the legacy direct WASAPI output)"},
    {"input.keyboard",           "RT_PAD_HOST",       BOOL_SET1,     "true = keyboard plays as pad 1"},
    {"input.background_input",   "RT_PAD_UNFOCUSED",  BOOL_SET1,     "true = keyboard is read even when the game window is not in front (Windows)"},
    {"input.xinput",             "RT_NOXINPUT",       BOOL_INV_SET1, "false = ignore XInput pads (Windows)"},
    {"storage.save_dir",         "RT_SAVE",           PATH,          "save folder (settings, scores, replays)"},
    {"storage.game_data",        "RT_GAME_ROOT",      PATH,          "the extracted assets/ folder"},
    {"storage.dlc_dir",          "RT_DLC_ROOT",       PATH,          "a second folder searched for Black Label data"},
    {"memory.pool_release_ms",   "RT_POOLRELEASE",    UINT,          "return long-unused guest memory after N ms; 0 = never (Windows default 0, macOS 10000)"},
  };
  return k;
}

struct State {
  std::vector<std::string> decided;   // env names decided by THIS apply (set, or decided-unset)
  std::string applied;                // comma list of names this apply SET from the ini (passed on to a child)
  int nset = 0, nenv = 0, nbad = 0;
};

inline bool parse_bool(const std::string& v, bool& out) {
  std::string l = lower(v);
  if (l == "1" || l == "true" || l == "on" || l == "yes") { out = true; return true; }
  if (l == "0" || l == "false" || l == "off" || l == "no") { out = false; return true; }
  return false;
}

// Turn one ini value into the env value. Returns 1 = set `out`, 0 = decided unset, -1 = invalid.
inline int convert(const Key& k, const std::string& raw, const std::string& inidir, std::string& out, std::string& why) {
  std::string v = raw;
  if (v.size() >= 2 && ((v.front() == '"' && v.back() == '"') || (v.front() == '\'' && v.back() == '\''))) v = v.substr(1, v.size() - 2);
  if (v.empty()) { why = "empty = launcher/engine default"; return -2; }
  bool b = false;
  switch (k.kind) {
    case STR: if (v.empty()) return 0; out = v; return 1;
    case PATH:
      if (v.empty()) { why = "empty = launcher/engine default"; return -2; }
#ifdef _WIN32
      out = is_abs(v) ? v : inidir + "\\" + v;
      for (auto& c : out) if (c == '/') c = '\\';
#else
      out = is_abs(v) ? v : inidir + "/" + v;
#endif
      return 1;
    case BOOL_SET1:     if (!parse_bool(v, b)) { why = "expected true/false"; return -1; } if (b) { out = "1"; return 1; } return 0;
    case BOOL_INV_SET1: if (!parse_bool(v, b)) { why = "expected true/false"; return -1; } if (!b) { out = "1"; return 1; } return 0;
    case VSYNC: {
      std::string l = lower(v);
      if (l == "auto" || l.empty()) return 0;
      if (parse_bool(l, b)) { out = b ? "1" : "0"; return 1; }
      why = "expected auto/on/off"; return -1;
    }
    case ROTATE: if (v == "0" || v.empty()) return 0; if (v == "90" || v == "270") { out = v; return 1; } why = "expected 0, 90 or 270"; return -1;
    case UINT: {
      if (v.empty() || lower(v) == "default") { why = "default"; return -2; }
      for (char c : v) if (!std::isdigit((unsigned char)c)) { why = "expected a whole number"; return -1; }
      out = v; return 1;
    }
    case SINK: {
      std::string l = lower(v);
      if (l == "sdl" || l.empty()) return 0;
#ifdef _WIN32
      if (l == "wasapi") { out = "1"; return 1; }
#else
      if (l == "wasapi") { why = "wasapi exists on Windows only"; return -1; }
#endif
      why = "expected sdl or wasapi"; return -1;
    }
    case WINSIZE: {
      unsigned w = 0, h = 0; char x = 0;
      if (std::sscanf(v.c_str(), "%u%c%u", &w, &x, &h) == 3 && (x == 'x' || x == 'X') && w >= 320 && h >= 240 && w <= 7680 && h <= 4320) {
        out = std::to_string(w) + "x" + std::to_string(h); return 1; }
      why = "expected WxH between 320x240 and 7680x4320"; return -1;
    }
  }
  return -1;
}

inline bool was_applied_by_parent(const char* name) {
  const char* a = std::getenv("FUTARI_INI_APPLIED"); if (!a) return false;
  std::string s = std::string(",") + a + ",", n = std::string(",") + name + ",";
  return s.find(n) != std::string::npos;
}

inline void decide(State& st, const char* env, const std::string& origin, int rc, const std::string& val, const std::string& why) {
  for (auto& d : st.decided) if (d == env) { std::fprintf(stderr, "[ini]   %s: later line ignored (already decided)\n", origin.c_str()); return; }
  if (env_set(env)) {
    if (was_applied_by_parent(env)) std::fprintf(stderr, "[ini]   %s -> %s=%s (ini, applied by the launcher)\n", origin.c_str(), env, std::getenv(env));
    else { std::fprintf(stderr, "[ini]   %s -> %s kept '%s' (set in the environment; env wins over the ini)\n", origin.c_str(), env, std::getenv(env)); ++st.nenv; }
    st.decided.push_back(env); return;
  }
  if (rc == 1) {
    env_put(env, val); st.decided.push_back(env); ++st.nset;
    st.applied += (st.applied.empty() ? "" : ","); st.applied += env;
    std::fprintf(stderr, "[ini]   %s -> %s=%s\n", origin.c_str(), env, val.c_str());
  } else if (rc == 0) {
    st.decided.push_back(env);
    std::fprintf(stderr, "[ini]   %s -> %s left unset (engine default)\n", origin.c_str(), env);
  } else if (rc == -2) {
    std::fprintf(stderr, "[ini]   %s -> %s not decided here (%s)\n", origin.c_str(), env, why.c_str());
  } else {
    ++st.nbad; std::fprintf(stderr, "[ini]   %s: INVALID value '%s' (%s) -- ignored\n", origin.c_str(), val.c_str(), why.c_str());
  }
}

inline bool lever_name_ok(const std::string& n) {
  if (n.compare(0, 3, "RT_") && n.compare(0, 4, "RVK_") && n.compare(0, 3, "XR_")) return false;
  for (char c : n) if (!(std::isupper((unsigned char)c) || std::isdigit((unsigned char)c) || c == '_')) return false;
  return true;
}

// Apply the ini. `who` names the caller in the log ("engine" / "launcher"). Returns the number of variables set.
inline int apply(const char* who) {
  State st;
  std::string path;
  for (auto& c : candidates()) if (file_exists(c)) { path = c; break; }
  if (path.empty()) {
    std::string tried; for (auto& c : candidates()) { tried += (tried.empty() ? "" : " | "); tried += c; }
    std::fprintf(stderr, "[ini] %s: no futari.ini (looked at: %s)\n", who, tried.empty() ? "nothing" : tried.c_str());
  } else {
    std::fprintf(stderr, "[ini] %s: reading %s\n", who, path.c_str());
    std::string inidir = dir_of(path);
    FILE* f = std::fopen(path.c_str(), "rb");
    std::string section; char line[4096]; int ln = 0;
    while (f && std::fgets(line, sizeof line, f)) {
      ++ln;
      std::string s(line);
      if (ln == 1 && s.size() >= 3 && (unsigned char)s[0] == 0xEF && (unsigned char)s[1] == 0xBB && (unsigned char)s[2] == 0xBF) s = s.substr(3);
      // comments: a line starting with # or ;, or " #" / " ;" after a value
      for (size_t i = 0; i < s.size(); ++i) {
        if ((s[i] == '#' || s[i] == ';') && (i == 0 || std::isspace((unsigned char)s[i - 1]))) { s.resize(i); break; }
      }
      s = trim(s);
      if (s.empty()) continue;
      if (s.front() == '[' && s.back() == ']') { section = lower(trim(s.substr(1, s.size() - 2))); continue; }
      size_t eq = s.find('=');
      if (eq == std::string::npos) { std::fprintf(stderr, "[ini]   line %d: no '=' -- ignored\n", ln); ++st.nbad; continue; }
      std::string key = trim(s.substr(0, eq)), val = trim(s.substr(eq + 1));
      std::string origin = (section.empty() ? "" : section + ".") + key;
      if (section == "env") {   // escape hatch: [env] NAME = value for any RT_/RVK_/XR_ lever
        if (!lever_name_ok(key)) { std::fprintf(stderr, "[ini]   %s: not an RT_/RVK_/XR_ lever name -- ignored\n", origin.c_str()); ++st.nbad; continue; }
        if (val.empty()) { std::fprintf(stderr, "[ini]   %s: empty -- ignored\n", origin.c_str()); continue; }
        decide(st, key.c_str(), origin, 1, val, "");
        continue;
      }
      std::string lk = lower(origin);
      const Key* hit = nullptr;
      for (auto& k : keys()) if (lk == k.name) { hit = &k; break; }
      if (!hit) { std::fprintf(stderr, "[ini]   %s: unknown key -- ignored\n", origin.c_str()); ++st.nbad; continue; }
      std::string out, why;
      int rc = convert(*hit, val, inidir, out, why);
      decide(st, hit->env, origin, rc, rc == 1 ? out : val, why);
      // game_data also names the shell image (default.xex) unless something already did
      if (rc == 1 && !std::strcmp(hit->env, "RT_GAME_ROOT") && !env_set("XR_SHELL_XEX")) {
        env_put("XR_SHELL_XEX", out + "/default.xex");
        st.applied += ",XR_SHELL_XEX";
        std::fprintf(stderr, "[ini]   %s -> XR_SHELL_XEX=%s/default.xex\n", origin.c_str(), out.c_str());
      }
    }
    if (f) std::fclose(f);
  }
  // launcher defaults: lowest priority, only for variables nobody decided
  if (const char* d = std::getenv("FUTARI_DEFAULTS")) {
    std::string all(d);
    size_t p = 0;
    while (p <= all.size()) {
      size_t q = all.find(';', p); if (q == std::string::npos) q = all.size();
      std::string item = trim(all.substr(p, q - p)); p = q + 1;
      size_t eq = item.find('='); if (item.empty() || eq == std::string::npos) continue;
      std::string n = trim(item.substr(0, eq)), v = trim(item.substr(eq + 1));
      bool dec = false; for (auto& x : st.decided) if (x == n) dec = true;
      if (dec) continue;
      if (env_set(n.c_str())) { std::fprintf(stderr, "[ini]   default %s -> kept '%s' (environment)\n", n.c_str(), std::getenv(n.c_str())); continue; }
      env_put(n.c_str(), v);
      std::fprintf(stderr, "[ini]   default %s=%s (launcher default; no ini line)\n", n.c_str(), v.c_str());
    }
  }
  if (!st.applied.empty()) {
    std::string prev = std::getenv("FUTARI_INI_APPLIED") ? std::getenv("FUTARI_INI_APPLIED") : "";
    env_put("FUTARI_INI_APPLIED", prev.empty() ? st.applied : prev + "," + st.applied);
#ifndef _WIN32
    setenv("FUTARI_INI_APPLIED", (prev.empty() ? st.applied : prev + "," + st.applied).c_str(), 1);
#endif
  }
  std::fprintf(stderr, "[ini] %s: %d set from the ini, %d kept from the environment, %d ignored -- applied before any engine init\n",
               who, st.nset, st.nenv, st.nbad);
  std::fflush(stderr);
  return st.nset;
}

// Once per process: the engine calls this from a pre-static-init hook (out_reco/harness.cpp) AND from the top of
// main() as a fallback; whichever runs first applies the file, the other is a no-op.
inline int apply_once(const char* who) {
  static bool done = false;
  if (done) return 0;
  done = true;
  return apply(who);
}

}  // namespace futari_ini
