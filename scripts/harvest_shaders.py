#!/usr/bin/env python3
"""Xenos shader micro-code harvester over captured PM4 command streams (xr-work).

Reuses the packet-walking approach from swraster.py (TYPE0/TYPE2/TYPE3, big-endian
dwords, count-1 encoding) and adds decoding for the two shader-upload PM4 opcodes:

  PM4_IM_LOAD (0x27):
    dword0 = (ucode_guest_addr & ~3) | shader_type   (shader_type: 0=vertex, 1=pixel)
    dword1 = (start_dword << 16) | size_in_dwords
    The actual micro-code bytes are NOT inline -- they live in guest memory at
    ucode_guest_addr (+ start_dword*4), and must be dereferenced from a memory dump.
    Verified against this project's captures: dword0=0xabc000 (type 0, vertex) and
    dword0=0xabd001 (addr 0xabd000, type 1, pixel) both appear, with size fields
    0x27 (39 dwords) and 0xf (15 dwords) respectively -- matches the Xenia convention
    exactly, so no layout deviation was needed here.

  PM4_IM_LOAD_IMMEDIATE (0x2B):
    dword0 = shader_type (0/1, no address -- this is a same-packet inline upload)
    dword1 = (start_dword << 16) | size_in_dwords
    followed immediately by size_in_dwords more payload dwords = the raw micro-code.
    (Not observed in either of our two captures -- see report notes.)

Both captures in this project needed an extra wrinkle vs. the naive "one flat
memory dump" model:
  - cap_replay_screen.bin (256MB) covers guest [0, 256MB) as a single flat dump,
    including the ring at 0x079B3000 (~127MB) AND the shader micro-code at
    0xABC000/0xABD000 (~11MB) -- one region is enough.
  - caps_s8/cap_low.bin is only 64MB (guest [0, 64MB)). Its own ring_base
    (0x079B3000, ~127MB) is *beyond* that truncation boundary, so the ring itself
    is physically absent from cap_low.bin even though the manifest describes it.
    The capture directory includes a second file, cap_ring.bin (exactly 0x20000
    bytes = the ring size), which is a separate targeted dump of just the ring
    region (file offset 0 == guest ring_base). This script auto-detects that
    sibling file and uses it for all ring/packet walking, while still using
    cap_low.bin to dereference micro-code addresses (which DO fall under 64MB).

Usage:
  python3 harvest_shaders.py --low <dump.bin> --manifest <m.txt> --out <dir> \
      [--ring <ring_dump.bin>] [--capture-name NAME]
"""
import argparse, hashlib, json, os, struct, sys


def be32(d, a):
    return struct.unpack_from('>I', d, a)[0]


def parse_manifest(path):
    m = {}
    for line in open(path):
        if '=' in line:
            k, v = line.strip().split('=', 1)
            m[k] = v
    return m


class MemMap:
    """Guest-physical-address -> bytes, backed by one or more flat dump files."""

    def __init__(self):
        self.regions = []  # list of (base, data, name), earlier = higher priority

    def add(self, base, data, name):
        self.regions.append((base, data, name))

    def read(self, addr, size):
        for base, data, name in self.regions:
            if base <= addr and addr + size <= base + len(data):
                return data[addr - base: addr - base + size]
        return None

    def region_for(self, addr):
        for base, data, name in self.regions:
            if base <= addr < base + len(data):
                return name
        return None


# ---- PM4 packet walk -------------------------------------------------------

def walk_packets(mem, start, end, tolerant, seen_packet_addrs, hits, log_prefix):
    """Walk PM4 packets in [start, end) (guest addresses) via mem.

    tolerant=False: mirrors swraster.collect_draws -- stop the whole walk on
      any unknown packet type or truncated/out-of-range packet (this is the
      "strict" pass used only as a sanity cross-check).
    tolerant=True: on any bad/truncated packet, resync by advancing one dword
      and keep going (the main harvesting pass, swept across the whole ring).

    Appends (packet_addr, opcode, payload_dwords) to `hits` for opcodes 0x27
    and 0x2B, deduping physical packet instances via `seen_packet_addrs`
    (a packet found by both the strict window and the tolerant sweep is only
    counted once).
    """
    i = start
    bad = 0
    n_packets = 0
    while i < end:
        header_bytes = mem.read(i, 4)
        if header_bytes is None:
            if tolerant:
                i += 4
                bad += 1
                continue
            print(f"{log_prefix}: unmapped memory @ {i:#x} -- stopping strict walk")
            break
        w = struct.unpack('>I', header_bytes)[0]
        t = w >> 30
        if t == 0:
            cnt = ((w >> 16) & 0x3fff) + 1
            if i + 4 * (1 + cnt) > end + (0x40 if not tolerant else 0):
                if tolerant:
                    i += 4
                    bad += 1
                    continue
                break
            i += 4 * (1 + cnt)
        elif t == 3:
            opc = (w >> 8) & 0x7f
            cnt = ((w >> 16) & 0x3fff) + 1
            payload_bytes = mem.read(i + 4, cnt * 4)
            if payload_bytes is None:
                if tolerant:
                    i += 4
                    bad += 1
                    continue
                print(f"{log_prefix}: truncated TYPE3 payload @ {i:#x} -- stopping strict walk")
                break
            n_packets += 1
            if opc in (0x27, 0x2b):
                payload = [struct.unpack_from('>I', payload_bytes, k * 4)[0] for k in range(cnt)]
                if i not in seen_packet_addrs:
                    seen_packet_addrs.add(i)
                    hits.append((i, opc, payload))
            i += 4 * (1 + cnt)
        elif t == 2:
            i += 4
        else:
            if tolerant:
                i += 4
                bad += 1
                continue
            print(f"{log_prefix}: unknown packet type {t} @ {i:#x} val={w:08x} -- stopping strict walk")
            break
    return n_packets, bad


# ---- shader record extraction ----------------------------------------------

def decode_im_load(mem, packet_addr, payload):
    """PM4_IM_LOAD (0x27): dword0 = (addr&~3)|shader_type, dword1 = (start<<16)|size."""
    if len(payload) < 2:
        return None
    d0, d1 = payload[0], payload[1]
    shader_type = d0 & 3          # 0 = vertex, 1 = pixel (per Xenia convention; verified below)
    guest_addr = d0 & ~3
    start_dwords = (d1 >> 16) & 0xFFFF
    size_dwords = d1 & 0xFFFF
    read_addr = guest_addr + start_dwords * 4
    size_bytes = size_dwords * 4
    ucode = mem.read(read_addr, size_bytes) if size_bytes else None
    return {
        'kind': 'im_load',
        'packet_addr': packet_addr,
        'shader_type': shader_type,
        'guest_addr': guest_addr,
        'start_dwords': start_dwords,
        'size_dwords': size_dwords,
        'ucode': ucode,
        'truncated': ucode is None and size_bytes > 0,
    }


def decode_im_load_immediate(payload):
    """PM4_IM_LOAD_IMMEDIATE (0x2B): dword0 = shader_type, dword1 = (start<<16)|size,
    followed by size_dwords of inline micro-code in the same payload."""
    if len(payload) < 2:
        return None
    shader_type = payload[0] & 3
    d1 = payload[1]
    start_dwords = (d1 >> 16) & 0xFFFF
    size_dwords = d1 & 0xFFFF
    inline = payload[2:2 + size_dwords]
    ucode = b''.join(struct.pack('>I', v) for v in inline) if len(inline) == size_dwords else None
    return {
        'kind': 'im_load_immediate',
        'shader_type': shader_type,
        'start_dwords': start_dwords,
        'size_dwords': size_dwords,
        'ucode': ucode,
        'truncated': ucode is None,
    }


TYPE_NAME = {0: 'vs', 1: 'ps'}


def process_capture(mem, ring_base, ring_size, frame_start, ring_cur, capture_name,
                     sanity):
    seen_packet_addrs = set()
    hits = []

    # Strict pass: [frame_start, ring_cur) -- exactly the swraster.py frame window,
    # break-on-error like the reference walker. Used as a cross-check only; its
    # hits still feed the same seen_packet_addrs set so nothing is double counted.
    strict_end_ok = mem.read(frame_start, 4) is not None
    if strict_end_ok:
        n, bad = walk_packets(mem, frame_start, ring_cur, tolerant=False,
                               seen_packet_addrs=seen_packet_addrs, hits=hits,
                               log_prefix=f"[{capture_name}] strict")
        print(f"[{capture_name}] strict frame window [{frame_start:#x},{ring_cur:#x}): "
              f"{n} packets walked, {len(hits)} IM_LOAD(_IMMEDIATE) so far")
    else:
        print(f"[{capture_name}] strict frame window [{frame_start:#x},{ring_cur:#x}) "
              f"not mapped in any input file -- skipping strict pass")

    # Tolerant full-ring sweep: [ring_base, ring_base+ring_size), resync on error.
    ring_end = ring_base + ring_size
    if mem.read(ring_base, 4) is not None:
        n, bad = walk_packets(mem, ring_base, ring_end, tolerant=True,
                               seen_packet_addrs=seen_packet_addrs, hits=hits,
                               log_prefix=f"[{capture_name}] sweep")
        print(f"[{capture_name}] tolerant ring sweep [{ring_base:#x},{ring_end:#x}): "
              f"{n} packets walked, {bad} bad dwords resynced, "
              f"{len(hits)} total distinct IM_LOAD(_IMMEDIATE) packets")
    else:
        print(f"[{capture_name}] ring [{ring_base:#x},{ring_end:#x}) not mapped in "
              "any input file -- skipping tolerant sweep (no ring bytes available)")

    records = []
    for packet_addr, opc, payload in hits:
        if opc == 0x27:
            rec = decode_im_load(mem, packet_addr, payload)
        else:
            rec = decode_im_load_immediate(payload)
        if rec is None:
            continue
        rec['packet_addr'] = rec.get('packet_addr', packet_addr)
        rec['capture'] = capture_name
        records.append(rec)

        if opc == 0x27 and rec['shader_type'] == 0 and rec['guest_addr'] == 0xABC000:
            sanity['vs_0xABC000_seen'] = True
        if opc == 0x27 and rec['shader_type'] == 1 and rec['guest_addr'] == 0xABD000:
            sanity['ps_0xABD000_seen'] = True

    return records


def build_mem_map(low_path, manifest, explicit_ring):
    mem = MemMap()
    low_data = open(low_path, 'rb').read()
    mem.add(0, low_data, os.path.basename(low_path))

    ring_base = int(manifest['ring_base'], 16)
    ring_size = 0x20000  # per project memory: ring is always 0x20000 bytes total

    ring_path = None
    if explicit_ring:
        ring_path = explicit_ring
    else:
        # Auto-detect a sibling cap_ring.bin only if the main dump doesn't already
        # cover the ring (avoids needlessly shadowing a perfectly good flat dump).
        if ring_base + ring_size > len(low_data):
            candidate = os.path.join(os.path.dirname(os.path.abspath(low_path)), 'cap_ring.bin')
            if os.path.isfile(candidate):
                ring_path = candidate

    if ring_path:
        ring_data = open(ring_path, 'rb').read()
        mem.add(ring_base, ring_data, os.path.basename(ring_path))
        print(f"note: main dump does not cover ring_base {ring_base:#x} "
              f"(dump is {len(low_data):#x} bytes, {len(low_data)/(1<<20):.0f}MB); "
              f"using sibling ring dump {ring_path} ({len(ring_data):#x} bytes) for "
              f"packet walking. Micro-code dereferencing still uses the main dump.")
    elif ring_base + ring_size > len(low_data):
        print(f"WARNING: ring_base {ring_base:#x}+{ring_size:#x} exceeds main dump size "
              f"{len(low_data):#x} and no sibling cap_ring.bin was found -- ring packets "
              f"in [{len(low_data):#x}, {ring_base+ring_size:#x}) are UNAVAILABLE and will "
              f"be reported as unmapped.")

    return mem, ring_base, ring_size


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--low', required=True, help='guest memory dump (file offset == guest phys addr)')
    ap.add_argument('--manifest', required=True, help='cap manifest (ring_base=, ring_cur=, ...)')
    ap.add_argument('--out', required=True, help='output directory for harvested shaders')
    ap.add_argument('--ring', default=None,
                     help='optional explicit ring-only dump (file offset 0 == ring_base); '
                          'auto-detected as a sibling cap_ring.bin if omitted and needed')
    ap.add_argument('--capture-name', default=None,
                     help='label for this capture in summary.txt (default: --low basename)')
    args = ap.parse_args()

    os.makedirs(args.out, exist_ok=True)
    capture_name = args.capture_name or os.path.basename(args.low.rstrip('/'))
    if capture_name in ('cap_low.bin',):
        # disambiguate the two captures' identical low-dump basenames
        capture_name = os.path.basename(os.path.dirname(os.path.abspath(args.low))) or capture_name

    manifest = parse_manifest(args.manifest)
    ring_base = int(manifest['ring_base'], 16)
    ring_cur = int(manifest['ring_cur'], 16)
    frame_start = ring_base + 0x8000

    mem, ring_base, ring_size = build_mem_map(args.low, manifest, args.ring)

    sanity = {'vs_0xABC000_seen': False, 'ps_0xABD000_seen': False}
    records = process_capture(mem, ring_base, ring_size, frame_start, ring_cur,
                               capture_name, sanity)

    # ---- dedup by sha1 of raw micro-code bytes, merged with any prior run's index ----
    index_path = os.path.join(args.out, '_index.json')
    index = {}
    if os.path.isfile(index_path):
        index = json.load(open(index_path))

    n_truncated = 0
    for rec in records:
        ucode = rec['ucode']
        if ucode is None:
            n_truncated += 1
            continue
        digest = hashlib.sha1(ucode).hexdigest()
        stype = TYPE_NAME.get(rec['shader_type'], f"t{rec['shader_type']}")
        if rec['kind'] == 'im_load':
            source = f"{rec['guest_addr']:#x}"
            fname_source = f"{rec['guest_addr']:08x}"
        else:
            source = 'immediate'
            fname_source = 'imm'

        entry = index.get(digest)
        if entry is None:
            fname = f"{stype}_{fname_source}_{digest[:8]}.bin"
            entry = {
                'type': stype,
                'source': source,
                'size_dwords': rec['size_dwords'],
                'sha1': digest,
                'filename': fname,
                'captures': {},
            }
            index[digest] = entry
            with open(os.path.join(args.out, fname), 'wb') as f:
                f.write(ucode)
        entry['captures'][capture_name] = entry['captures'].get(capture_name, 0) + 1

    json.dump(index, open(index_path, 'w'), indent=2)

    # ---- summary.txt (regenerated from the full merged index every run) ----
    summary_path = os.path.join(args.out, 'summary.txt')
    rows = sorted(index.values(), key=lambda e: (e['type'], e['source']))
    with open(summary_path, 'w') as f:
        f.write(f"{'type':4} {'source':12} {'dwords':7} {'sha1':10} {'captures (im_load count)'}\n")
        for e in rows:
            cap_str = ', '.join(f"{k}:{v}" for k, v in e['captures'].items())
            f.write(f"{e['type']:4} {e['source']:12} {e['size_dwords']:7} "
                     f"{e['sha1'][:10]:10} {cap_str}  -> {e['filename']}\n")

    n_vs = sum(1 for e in index.values() if e['type'] == 'vs')
    n_ps = sum(1 for e in index.values() if e['type'] == 'ps')
    print(f"[{capture_name}] {len(records)} IM_LOAD(_IMMEDIATE) packets decoded, "
          f"{n_truncated} truncated (ucode outside mapped memory)")
    print(f"[{capture_name}] sanity: VS@0xABC000 seen={sanity['vs_0xABC000_seen']} "
          f"PS@0xABD000 seen={sanity['ps_0xABD000_seen']}")
    print(f"distinct shaders so far in {args.out}: {n_vs} vs, {n_ps} ps "
          f"(total {len(index)}) -- summary: {summary_path}")


if __name__ == '__main__':
    main()
