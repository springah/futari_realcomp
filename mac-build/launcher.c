// launcher.c -- the .app's CFBundleExecutable: sets the run environment the Windows/Mac attended
// scripts set (scripts/run_mac.sh), resolves every path relative to the bundle, redirects the
// guest log to ~/Library/Logs, and exec()s the real engine (Contents/MacOS/futari_merged).
//
// exec, not spawn: the engine replaces this process, so the Dock icon, activation and the
// window all belong to the bundle LaunchServices started. Every setenv is "only if unset", so
// a terminal launch can still override any lever (RT_NVKPNG=60 RVK_DUMPDIR=... ./Futari\ Realcomp).
#include <mach-o/dyld.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

static void def(const char* k, const char* v) { if (!getenv(k)) setenv(k, v, 1); }
static bool isdir(const std::string& p) { struct stat st; return stat(p.c_str(), &st) == 0 && S_ISDIR(st.st_mode); }
static bool isfile(const std::string& p) { struct stat st; return stat(p.c_str(), &st) == 0 && S_ISREG(st.st_mode); }
static void mkdirs(const std::string& p) { std::string cmd = "mkdir -p '" + p + "'"; system(cmd.c_str()); }

static void dialog(const std::string& msg) {
  std::string cmd = "osascript -e 'display dialog \"" + msg + "\" with title \"Futari Realcomp\" buttons {\"OK\"} default button 1 with icon stop' >/dev/null 2>&1";
  system(cmd.c_str());
}

int main(int argc, char** argv) {
  char buf[4096]; uint32_t n = sizeof buf;
  if (_NSGetExecutablePath(buf, &n) != 0) { dialog("Cannot locate the bundle."); return 1; }
  char real[PATH_MAX]; if (!realpath(buf, real)) strcpy(real, buf);
  std::string exe(real);
  std::string macos = exe.substr(0, exe.rfind('/'));              // Contents/MacOS
  std::string contents = macos.substr(0, macos.rfind('/'));       // Contents
  std::string res = contents + "/Resources";
  std::string engine = macos + "/futari_merged";

  // Game data: inside the bundle (family-and-friends build) or, if absent, beside the .app.
  std::string assets = res + "/assets";
  if (!isdir(assets)) {
    std::string app = contents.substr(0, contents.rfind('/'));   // the .app
    std::string beside = app.substr(0, app.rfind('/')) + "/assets";
    if (isdir(beside)) assets = beside;
  }
  if (!isfile(assets + "/default.xex")) {
    dialog("No game data found.\\n\\nPut your extracted dump at:\\n" + res + "/assets\\n(or an assets folder next to the app).");
    return 2;
  }

  const char* home = getenv("HOME"); if (!home) home = "/tmp";
  std::string support = std::string(home) + "/Library/Application Support/Futari Realcomp";
  std::string logs = std::string(home) + "/Library/Logs/Futari Realcomp";
  mkdirs(support + "/save"); mkdirs(logs);

  // --- the attended-session env set (scripts/run_mac.sh), every value overridable ---
  def("RT_GAME_ROOT", assets.c_str());
  def("RT_MODDLL_DIR", macos.c_str());     // the two module dylibs sit beside the engine (host/module_registry.cpp searches here first)
  std::string xex = assets + "/default.xex"; def("XR_SHELL_XEX", xex.c_str());
  std::string save = support + "/save";      def("RT_SAVE", save.c_str());
  def("RT_BOOT_SHELL", "1"); def("RT_THREADS", "1"); def("RT_DEFERDRIVER", "1"); def("RT_ASYNCIO", "1");
  def("RT_EHCONTAIN", "1"); def("RT_AUDIOPUMP", "1");
  def("RT_AUDIO", "1"); def("RT_AUDIOWORKER", "1"); def("RT_AUDIOBRIDGE", "1"); def("RT_CUEBRIDGE", "1");
  def("RT_VK", "1"); def("RT_NVK", "2"); def("RVK_PERSIST", "1"); def("RVK_RENDER_FROM", "1"); def("RVK_NOHALVE", "1");
  def("RVK_FIXVP", "1"); def("RVK_BLEND", "1"); def("RVK_REALALPHA", "1");
  def("RT_WALLPAPER", "1"); def("RVK_TEXPITCH", "1"); def("RVK_FMT3KEY", "1"); def("RVK_GPFIELD", "1");
  def("RVK_C255", "0.00625:0.00390625:-1:0");
  def("RVK_RESALIAS", "1"); def("RVK_RESFRESH", "1"); def("RVK_FIXB2", "1"); def("RVK_RESREAL", "1"); def("RVK_HDR", "0");
  def("RVK_WINDOW", "1"); def("RVK_WINSIZE", "1280x720"); def("RVK_DIMFIX", "1");
  def("RT_NAVREAL", "1"); def("RT_STARTWIRE", "1"); def("RT_SNDQFREE", "1"); def("RT_RESCACHE", "1"); def("RT_HEAPLOCK", "1");
  def("RT_PAD_HOST", "1");                 // keyboard: arrows, Z=A X=B C=X V=Y, Enter=START, RShift=BACK; pads via SDL3
  def("RT_SAMPLES", "0");                  // attended: no hang sampler
  def("RVK_DUMPDIR", "/tmp");

  // guest log -> ~/Library/Logs/Futari Realcomp/futari_YYYYmmdd_HHMMSS.log (stderr is the log stream)
  time_t t = time(nullptr); struct tm tmv; localtime_r(&t, &tmv);
  char stamp[32]; strftime(stamp, sizeof stamp, "%Y%m%d_%H%M%S", &tmv);
  std::string logf = logs + "/futari_" + stamp + ".log";
  if (!getenv("FUTARI_LOG_TO_TTY")) { if (!freopen(logf.c_str(), "w", stderr)) perror("freopen"); }
  chdir(res.c_str());                      // any relative open lands inside the bundle, never in / or ~

  // argv[0] = the full engine path, so `ps`/Activity Monitor/pkill see the bundle, not a bare "futari_merged"
  char* args[] = { (char*)engine.c_str(), (char*)"8208A2B8", (char*)"0", (char*)xex.c_str(), nullptr };
  execv(engine.c_str(), args);
  perror("execv"); dialog("Cannot start the engine (see the log in ~/Library/Logs/Futari Realcomp).");
  return 3;
}
