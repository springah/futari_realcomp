# PM4 / render-structure analysis tools

Read-only Python parsers for the captured guest frames (`caps_gp/`, `caps_gp2/`,
`caps_s8/`). They replicate the renderer's PM4 walk (TYPE0/TYPE3, SET_CONSTANT /
LOAD_ALU_CONSTANT / IM_LOAD / DRAW / INDIRECT_BUFFER, and the reg-index maps) so you
can inspect a frame without running the renderer. Built during the EDRAM-resolve work
(LEG-29) and used to reverse-engineer the render-target/resolve pass structure.

- **pm4.py**   — core walker: parse [ring_base+0x8000, ring_cur), follow INDIRECT_BUFFERs,
                 track the register file, list draws + their vertex-fetch / texture bases.
- **analyze.py** — per-frame PASS structure: color RT (RB_SURFACE/COLOR_INFO 0x2000/0x2001),
                 RB_COPY resolves (0x2318 control / 0x2319 dest / 0x231A pitch / 0x231B info),
                 draws per pass, and which later passes SAMPLE the resolved dst addresses.
- **trace.py** — chronological op trace of a frame (RT switches, resolves, draws in order).
- **fetch.py** — decode a vertex/texture fetch constant (base/dims/format/tiled/pitch).
- **dump.py**  — dump/untile a texture from guest memory to PNG (Xenos tiledOff).
- **defdump.py** — parse a shader container's definition table (Float4Definition c-constants).

Point them at a caps dir, e.g. `python3 tools/pm4/analyze.py caps_gp2`. Paths/args are
near the top of each script; the captures themselves are git-ignored (regenerate via a
gameplay capture: RT_CAPONPLAY=1 RT_CAPLOW_MB=272 — see LEG-29 / _tmpscripts/cap_settled.sh).
