#!/usr/bin/env python3
"""
futari_realcomp settings tool: writes futari.ini, the player settings file the
engine reads at start-up (host/futari_ini.h turns each key into the engine's
environment lever; an environment variable that is already set wins).

    python futari_settings.py                 # interactive: asks the common questions
    python futari_settings.py show            # the file's current values
    python futari_settings.py set display.fullscreen=true display.window_size=2560x1440
    python futari_settings.py get storage.save_dir
    python futari_settings.py init            # create futari.ini from the template if missing
    python futari_settings.py path            # print where futari.ini is

--ini PATH works with every command. Default location:
    Windows / Linux: futari.ini in the release folder (two levels above this script)
    macOS:           ~/Library/Application Support/Futari Realcomp/futari.ini

Edits are made in place: comments and the order of lines are kept, a key that
is missing is added to its section. Values are checked against the same rules
the engine applies (host/futari_ini.h). Needs Python 3.8+, no packages.
"""
import argparse
import os
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
TEMPLATE = HERE / "futari.ini.template"

# section.key -> (env lever, checker, short prompt). Keep in step with host/futari_ini.h keys().
BOOL = ("true", "false")


def _bool(v):
    l = v.lower()
    if l in ("1", "true", "on", "yes"):
        return "true"
    if l in ("0", "false", "off", "no"):
        return "false"
    raise ValueError("expected true or false")


def _winsize(v):
    m = re.fullmatch(r"\s*(\d+)\s*[xX]\s*(\d+)\s*", v)
    if not m:
        raise ValueError("expected WIDTHxHEIGHT, e.g. 1920x1080")
    w, h = int(m.group(1)), int(m.group(2))
    if not (320 <= w <= 7680 and 240 <= h <= 4320):
        raise ValueError("between 320x240 and 7680x4320")
    return f"{w}x{h}"


def _choice(*opts):
    def f(v):
        l = v.lower()
        if l not in opts:
            raise ValueError("expected one of: " + ", ".join(opts))
        return l
    return f


def _vsync(v):
    l = v.lower()
    if l in ("auto", "on", "off"):
        return l
    return {"true": "on", "false": "off"}[_bool(l)]


def _uint(v):
    if not v.isdigit():
        raise ValueError("expected a whole number of milliseconds")
    return v


def _any(v):
    return v


KEYS = {
    "display.window_size":    ("RVK_WINSIZE", _winsize),
    "display.fullscreen":     ("RVK_FULLSCREEN", _bool),
    "display.vsync":          ("RVK_VSYNC", _vsync),
    "display.f11_fullscreen": ("RVK_NOF11", _bool),
    "display.rotate":         ("RT_ROTATE", _choice("0", "90", "270")),
    "display.gpu":            ("RVK_GPU", _any),
    "audio.sink":             ("RT_SINKWASAPI", _choice("sdl", "wasapi")),
    "input.keyboard":         ("RT_PAD_HOST", _bool),
    "input.background_input": ("RT_PAD_UNFOCUSED", _bool),
    "input.xinput":           ("RT_NOXINPUT", _bool),
    "storage.save_dir":       ("RT_SAVE", _any),
    "storage.game_data":      ("RT_GAME_ROOT", _any),
    "storage.dlc_dir":        ("RT_DLC_ROOT", _any),
    "memory.pool_release_ms": ("RT_POOLRELEASE", _uint),
}


def default_ini():
    if sys.platform == "darwin":
        return Path.home() / "Library" / "Application Support" / "Futari Realcomp" / "futari.ini"
    return HERE.parent.parent / "futari.ini"


def check(key, value):
    key = key.strip().lower()
    if key.startswith("env."):
        name = key[4:].upper()
        if not re.fullmatch(r"(RT|RVK|XR)_[A-Z0-9_]+", name):
            raise ValueError(f"{name}: not an RT_/RVK_/XR_ lever name")
        return "env." + name, value.strip()
    if key not in KEYS:
        raise ValueError(f"unknown key {key!r}; known: " + ", ".join(KEYS))
    value = value.strip()
    if value == "":
        return key, ""          # empty = default
    return key, KEYS[key][1](value)


# ---------------------------------------------------------------- the file
SEC_RE = re.compile(r"^\s*\[([^\]]+)\]\s*$")
KV_RE = re.compile(r"^(\s*)([A-Za-z0-9_.]+)(\s*=\s*)(.*?)(\s+[#;].*)?$")


def read_lines(ini: Path):
    if ini.is_file():
        return ini.read_text(encoding="utf-8-sig").splitlines()
    if TEMPLATE.is_file():
        return TEMPLATE.read_text(encoding="utf-8").splitlines()
    return []


def parse(lines):
    """{section.key: (line index, value)}"""
    out, sec = {}, ""
    for i, line in enumerate(lines):
        s = line.strip()
        if not s or s[0] in "#;":
            continue
        m = SEC_RE.match(line)
        if m:
            sec = m.group(1).strip().lower()
            continue
        m = KV_RE.match(line)
        if m:
            k = m.group(2)
            full = (sec + "." if sec else "") + (k if sec == "env" else k.lower())
            out[full] = (i, m.group(4).strip())
    return out


def set_value(lines, key, value):
    vals = parse(lines)
    sec, k = key.split(".", 1)
    if key in vals:
        i, _old = vals[key]
        m = KV_RE.match(lines[i])
        sep = m.group(3) if (m.group(3).endswith(" ") or not value) else m.group(3) + " "
        lines[i] = f"{m.group(1)}{m.group(2)}{sep}{value}{m.group(5) or ''}"
        return
    # add to the end of its section (create the section if absent)
    start = None
    for i, line in enumerate(lines):
        m = SEC_RE.match(line)
        if m and m.group(1).strip().lower() == sec:
            start = i
            break
    if start is None:
        if lines and lines[-1].strip():
            lines.append("")
        lines += [f"[{sec}]", f"{k} = {value}"]
        return
    end = len(lines)
    for i in range(start + 1, len(lines)):
        if SEC_RE.match(lines[i]):
            end = i
            break
    while end > start + 1 and not lines[end - 1].strip():
        end -= 1
    lines.insert(end, f"{k} = {value}")


def write_lines(ini: Path, lines):
    ini.parent.mkdir(parents=True, exist_ok=True)
    tmp = ini.with_name(ini.name + ".tmp")
    tmp.write_text("\n".join(lines) + "\n", encoding="utf-8")
    os.replace(tmp, ini)


# ---------------------------------------------------------------- commands
def cmd_show(ini):
    lines = read_lines(ini)
    vals = parse(lines)
    print(f"# {ini}{'' if ini.is_file() else '  (does not exist yet: template values shown)'}")
    for key, (env, _f) in KEYS.items():
        v = vals.get(key, (None, ""))[1]
        print(f"{key:26} = {v or '(default)':24} -> {env}")
    for key, (_i, v) in vals.items():
        if key.startswith("env."):
            print(f"{key:26} = {v}")


def cmd_set(ini, pairs):
    lines = read_lines(ini)
    for p in pairs:
        if "=" not in p:
            sys.exit(f"{p!r}: expected key=value")
        k, v = p.split("=", 1)
        try:
            k, v = check(k, v)
        except (ValueError, KeyError) as e:
            sys.exit(f"{k.strip()}: {e}")
        set_value(lines, k, v)
        print(f"  {k} = {v or '(default)'}")
    write_lines(ini, lines)
    print(f"Wrote {ini}")


def ask(prompt, current, checker, hint):
    while True:
        shown = current if current else "default"
        try:
            ans = input(f"{prompt} [{shown}] ({hint}; Enter keeps it): ").strip()
        except EOFError:
            return current
        if ans == "":
            return current
        if ans == "-":
            return ""
        try:
            return checker(ans)
        except (ValueError, KeyError) as e:
            print(f"    {e}")


def cmd_wizard(ini):
    lines = read_lines(ini)
    vals = parse(lines)
    cur = {k: vals.get(k, (None, ""))[1] for k in KEYS}
    print(f"Futari settings -> {ini}")
    print("Enter keeps a value, '-' resets it to the default. Game options (difficulty, buttons,")
    print("TATE, volumes) are the game's own OPTIONS menus, not here.\n")
    q = [
        ("display.window_size", "Window size", "WIDTHxHEIGHT"),
        ("display.fullscreen", "Start fullscreen", "true/false; F11 toggles in game"),
        ("display.vsync", "VSync", "auto/on/off"),
        ("display.rotate", "Rotate the window picture", "0/90/270, for a monitor on its side"),
        ("input.keyboard", "Keyboard plays as player 1", "true/false"),
        ("storage.save_dir", "Save folder", "a path, relative = next to futari.ini"),
    ]
    if os.name == "nt":
        q.insert(5, ("audio.sink", "Sound output", "sdl/wasapi"))
    new = dict(cur)
    for key, prompt, hint in q:
        new[key] = ask(prompt, cur[key], lambda v, k=key: check(k, v)[1], hint)
    changed = [k for k in KEYS if new[k] != cur[k]]
    if not changed and ini.is_file():
        print("\nNothing changed.")
        return
    for k in changed:
        set_value(lines, k, new[k])
    write_lines(ini, lines)
    print(f"\nWrote {ini}" + ("".join(f"\n  {k} = {new[k] or '(default)'}" for k in changed)))


def main():
    ap = argparse.ArgumentParser(description="Edit futari_realcomp's futari.ini")
    ap.add_argument("--ini", default=None, help=f"the file (default: {default_ini()})")
    ap.add_argument("--abs", action="store_true",
                    help="get: print a path value as an absolute path (relative = next to the ini)")
    ap.add_argument("command", nargs="?", default="wizard",
                    choices=["wizard", "show", "get", "set", "init", "path"])
    ap.add_argument("args", nargs="*")
    a = ap.parse_args()
    ini = Path(a.ini).expanduser() if a.ini else default_ini()
    if a.command == "path":
        print(ini)
    elif a.command == "init":
        if ini.is_file():
            print(f"{ini} exists; left as it is")
        else:
            write_lines(ini, read_lines(ini))
            print(f"Created {ini} from {TEMPLATE.name}")
    elif a.command == "show":
        cmd_show(ini)
    elif a.command == "get":
        if len(a.args) != 1:
            sys.exit("get KEY")
        v = parse(read_lines(ini)).get(a.args[0].lower(), (None, ""))[1]
        if a.abs and v:
            p = Path(v).expanduser()
            v = str(p if p.is_absolute() else (ini.parent / p).resolve())
        print(v)
    elif a.command == "set":
        if not a.args:
            sys.exit("set KEY=VALUE [KEY=VALUE ...]")
        cmd_set(ini, a.args)
    else:
        cmd_wizard(ini)
    return 0


if __name__ == "__main__":
    sys.exit(main())
