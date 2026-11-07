// fs_inject.m -- TEST INSTRUMENT, never shipped: a DYLD_INSERT_LIBRARIES dylib that lets a drive script press F11 inside an
// UNMODIFIED bundle (scripts/rc_census_mac.sh CENSUS_APP= arm, 2026-11-07). Over ssh there is no way to type a key: the ssh
// session is not Accessibility-trusted (AXIsProcessTrusted / CGPreflightPostEventAccess both false), so System Events and
// CGEventPost cannot reach the game. An app may post events into ITS OWN queue without any permission, so this library,
// loaded into the engine, watches a trigger file and posts a real F11 keyDown/keyUp NSEvent ([NSApp postEvent:atStart:],
// documented as callable from a secondary thread). SDL's Cocoa pump turns it into SDL_SCANCODE_F11 and the engine's own
// handler (render/vk_render.cpp rvkToggleFullscreenSdl) runs -- the same code path as a player's F11, logged as
// "[rvk][win] F11 -> fullscreen WxH". Inert unless FUTARI_FS_TRIGGER=<file> is set and the host executable is futari_merged
// (the bundle launcher, which also inherits DYLD_INSERT_LIBRARIES before it execs the engine, is skipped).
//   build: clang -dynamiclib -fobjc-arc -framework AppKit -o fs_inject.dylib mac-build/fs_inject.m   (ad hoc signed by the linker)
#import <AppKit/AppKit.h>
#include <mach-o/dyld.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char g_trig[1024];

static void post_f11(void) {
  NSApplication* app = NSApp;
  if (!app) { fprintf(stderr, "[fsinject] trigger seen but NSApp is nil -- nothing posted\n"); return; }
  NSWindow* w = app.keyWindow ? app.keyWindow : (app.mainWindow ? app.mainWindow : app.windows.firstObject);
  NSInteger wn = w ? w.windowNumber : 0;
  NSString* ch = [NSString stringWithFormat:@"%C", (unichar)NSF11FunctionKey];
  for (int up = 0; up < 2; up++) {
    NSEvent* e = [NSEvent keyEventWithType:(up ? NSEventTypeKeyUp : NSEventTypeKeyDown) location:NSZeroPoint
                             modifierFlags:NSEventModifierFlagFunction timestamp:[[NSProcessInfo processInfo] systemUptime]
                              windowNumber:wn context:nil characters:ch charactersIgnoringModifiers:ch isARepeat:NO keyCode:103];
    [app postEvent:e atStart:NO];
  }
  fprintf(stderr, "[fsinject] posted F11 down+up (window #%ld, key=%d, active=%d)\n", (long)wn, app.keyWindow != nil, app.isActive);
}

static void* watch(void* unused) { (void)unused;
  for (;;) {
    if (access(g_trig, F_OK) == 0) { unlink(g_trig); @autoreleasepool { post_f11(); } }
    usleep(200000);
  }
  return NULL;
}

__attribute__((constructor)) static void fs_inject_init(void) {
  const char* t = getenv("FUTARI_FS_TRIGGER"); if (!t || !*t) return;
  char exe[4096]; uint32_t n = sizeof exe; if (_NSGetExecutablePath(exe, &n) != 0) return;
  const char* b = strrchr(exe, '/'); b = b ? b + 1 : exe;
  if (strcmp(b, "futari_merged") != 0) return;   // the launcher (Futari Realcomp) passes through untouched
  snprintf(g_trig, sizeof g_trig, "%s", t);
  pthread_t th; pthread_create(&th, NULL, watch, NULL); pthread_detach(th);
  fprintf(stderr, "[fsinject] armed: touch %s to post F11\n", g_trig);
}
