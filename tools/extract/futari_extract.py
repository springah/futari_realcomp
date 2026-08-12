#!/usr/bin/env python3
"""
futari_realcomp asset extractor.

Builds the port's `assets/` tree from a copy of Mushihimesama Futari Ver. 1.5
(title 435A07D7) that you dumped yourself. Ships no game data.

Accepts any of:
  - a console disc install ("Games on Demand" / SVOD container) - the `00007000`
    folder copied off console storage, or any folder above it
  - a disc ISO (XDVDFS filesystem)
  - a marketplace DLC package (STFS), or a folder of them (`00000002`)
  - a DLC package already unpacked to a folder (`.../<contentid>/Rom/...`)
  - an already-extracted disc folder (one holding `default.xex` + `media/`)
  - a `Content\\...\\435A07D7` folder holding several of the above, which does
    the whole job in one go

Usage:
    python tools/extract/futari_extract.py <path> [--out assets] [--shell shell]
    python tools/extract/futari_extract.py --verify-only --out assets

Provenance of this file: adapted from futari_recomp's scripts/extract_iso.py
(the shipped, hash-verified v1.5.1 extractor for this same game). The XDVDFS
reader, the SVOD/GoD hash-tree reader and the failure accounting are that code
essentially unchanged - including the `fs_base = descriptor_offset - 0x10000`
correction that made ISO extraction work at all. New here: the STFS reader for
DLC packages, the already-extracted/already-unpacked input paths, the derived
duplicates realcomp needs, and manifest verification.
"""

import argparse
import hashlib
import os
import shutil
import struct
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

TITLE_ID = 0x435A07D7  # Mushihimesama Futari Ver. 1.5
XDVDFS_MAGIC = b"MICROSOFT*XBOX*MEDIA"
SECTOR_SIZE = 2048

XCONTENT_MAGICS = (b"LIVE", b"CON ", b"PIRS")
CONTENT_TYPE_DLC = 0x2
CONTENT_TYPE_INSTALLED_DISC = 0x7000

# Known offsets where the XDVDFS volume descriptor can appear.
CANDIDATE_OFFSETS = [
    0x10000,       # Standard XGD / most disc rips; also GoD installs
    0x2080000,     # XGD2 backup partition
    0x0FDA0000,    # XGD2 with video partition (Mushi Futari RF rip)
    0x1FB20000,    # XGD3
]

# The Black Label DLC. Its package-internal Rom\ files are what modes 4 and 5
# (kiniro_normal / kiniro_abnormal) open; the port reads them loose out of
# assets/media/Rom/, so they are unpacked rather than left as a package.
DLC_BLACK_LABEL = "496F816DD4B53DAEFF931838B6C69831AAD7663043"
DLC_VER101 = "9893A78CA6062B935BD1F53EA43CFD546B7246DF43"

# Package-internal path -> assets-relative path, for DLC contents the port uses.
# Anything in a DLC package that is not listed here is not consumed by the port
# (spa.bin, ver101_key.bin) and is skipped; see DESIGN.md.
DLC_WANTED = {
    "Rom/cg_black.bin": "media/Rom/cg_black.bin",
    "Rom/cg_blackhi.bin": "media/Rom/cg_blackhi.bin",
    "Rom/dropprm.bl": "media/Rom/dropprm.bl",
}

# Copies the port needs beyond the plain disc layout. Both are byte-identical
# duplicates - see DESIGN.md section "Derived files".
#   assets/reco_normal.xex : the data bridge the merged exe reads (XR_RECO_NORMAL)
#   <shell>/default.xex    : the module named on the command line
DERIVED_IN_ASSETS = {"media/Module/reco_normal.xex": "reco_normal.xex"}
DERIVED_SHELL_XEX = "default.xex"

MANIFEST = Path(__file__).with_name("manifest_v1.tsv")

# Problems that must fail the run. A truncated or corrupt dump used to be
# reported as a success and resurface hours later as a codegen error; every
# short read, bad hash and unsafe name lands here instead.
PROBLEMS = []


def problem(msg):
    PROBLEMS.append(msg)


# ---------------------------------------------------------------------------
# XContent package headers (console-created files: disc installs and DLC)
# ---------------------------------------------------------------------------

def read_xcontent_header(path: Path):
    """Return {magic, content_type, title_id, header_size} if `path` is an
    XContent package (LIVE/CON/PIRS), else None."""
    try:
        if path.stat().st_size < 0x400:
            return None
        with open(path, "rb") as f:
            head = f.read(0x400)
    except OSError:
        return None
    if len(head) < 0x400 or head[:4] not in XCONTENT_MAGICS:
        return None
    return {
        "magic": head[:4],
        "header_size": struct.unpack_from(">I", head, 0x340)[0],
        "content_type": struct.unpack_from(">I", head, 0x344)[0],
        "title_id": struct.unpack_from(">I", head, 0x360)[0],
        "volume_type": struct.unpack_from(">I", head, 0x3A1)[0],
    }


# ---------------------------------------------------------------------------
# SVOD / "Games on Demand" container - a console disc install
# ---------------------------------------------------------------------------

class GodReader:
    """A console disc install presented as one flat disc image with
    seek()/read(), so the XDVDFS code below reads it exactly like an ISO.

    Layout: beside the header file sits `<name>.data/` holding Data0000,
    Data0001, ... Each file is 0x1000-byte blocks: one level-1 hash-table
    block, then groups of [one level-0 hash-table block + 0xCC data blocks].
    A full file carries 0xCB groups = 0xA1C4 data blocks. The level-0 tables
    hash each data block, the level-1 table hashes the level-0 tables plus the
    NEXT file's level-1 table, and the header's root hash covers the first
    level-1 table - so verify() can prove the whole copy good before extraction
    starts.
    """

    BLOCK = 0x1000
    DATA_PER_L0 = 0xCC             # data blocks covered by one level-0 table
    DATA_PER_FILE = 0xCB * 0xCC    # data blocks in a full data file (0xA1C4)

    def __init__(self, header_path: Path):
        self.header_path = header_path
        header = header_path.read_bytes()
        if header[:4] not in XCONTENT_MAGICS:
            raise ValueError(f"{header_path.name}: not an XContent package")
        self.content_type = struct.unpack_from(">I", header, 0x344)[0]
        self.title_id = struct.unpack_from(">I", header, 0x360)[0]

        # SVOD device descriptor
        desc = header[0x379:0x379 + 0x24]
        self.root_hash = desc[0x04:0x18]
        self.flags = desc[0x18]
        self.data_block_count = int.from_bytes(desc[0x19:0x1C], "big")
        data_block_offset = int.from_bytes(desc[0x1C:0x1F], "big")
        if self.flags or data_block_offset:
            # Console disc installs have both zero. A shifted layout would be
            # absorbed anyway - the extractor locates the filesystem by scanning
            # for its volume descriptor - but say so, since hash verification
            # against this layout is untested.
            print(f"  NOTE: unusual container layout (flags={self.flags:#x}, "
                  f"dataBlockOffset={data_block_offset:#x}) - untested, "
                  "attempting anyway")

        self.data_dir = header_path.parent / (header_path.name + ".data")
        if not self.data_dir.is_dir():
            raise ValueError(f"{self.data_dir.name}: data folder is missing "
                             f"beside {header_path.name}")

        n_files = -(-self.data_block_count // self.DATA_PER_FILE)
        self.data_files = [self.data_dir / f"Data{i:04d}" for i in range(n_files)]
        self._handles = [None] * n_files
        self.size = self.data_block_count * self.BLOCK
        self.pos = 0

    # -- integrity ---------------------------------------------------------

    def _file_shape(self, index):
        """(data blocks, expected byte size) of data file `index`."""
        n = min(self.DATA_PER_FILE,
                self.data_block_count - index * self.DATA_PER_FILE)
        groups = -(-n // self.DATA_PER_L0)
        return n, (1 + groups + n) * self.BLOCK

    def check_files(self):
        """Cheap structural check: every data file present and full size."""
        problems = []
        for i, path in enumerate(self.data_files):
            _, expected = self._file_shape(i)
            if not path.exists():
                problems.append(f"{path.name} is missing "
                                f"(the install has {len(self.data_files)} data files)")
            elif path.stat().st_size != expected:
                problems.append(
                    f"{path.name} is {path.stat().st_size:,} bytes, "
                    f"expected {expected:,} - the copy is incomplete")
        return problems

    def verify(self):
        """Walk the container's own hash tree: root hash -> level-1 tables ->
        level-0 tables -> every data block. Catches a corrupt or truncated copy
        up front, with the exact file named. Returns a list of problems."""
        problems = []
        expected_l1 = self.root_hash
        for i, path in enumerate(self.data_files):
            n_blocks, _ = self._file_shape(i)
            print(f"  verifying {path.name} ...", end="", flush=True)
            bad = None
            with open(path, "rb") as f:
                l1 = f.read(self.BLOCK)
                if hashlib.sha1(l1).digest() != expected_l1:
                    bad = f"{path.name}: level-1 hash table does not match"
                else:
                    done = 0
                    group = 0
                    while done < n_blocks and not bad:
                        take = min(self.DATA_PER_L0, n_blocks - done)
                        l0 = f.read(self.BLOCK)
                        if l1[group * 0x14:(group + 1) * 0x14] != hashlib.sha1(l0).digest():
                            bad = (f"{path.name}: hash table for blocks "
                                   f"{done}-{done + take - 1} does not match")
                            break
                        for j in range(take):
                            block = f.read(self.BLOCK)
                            if l0[j * 0x14:(j + 1) * 0x14] != hashlib.sha1(block).digest():
                                bad = f"{path.name}: data block {done + j} fails its hash"
                                break
                        done += take
                        group += 1
            if bad:
                print(" CORRUPT")
                problems.append(bad + " - the copy is corrupt")
            else:
                print(" ok")
            # entry 0xCB of each level-1 table hashes the next file's level-1
            expected_l1 = l1[0xCB * 0x14:0xCC * 0x14]
        return problems

    # -- file-like interface used by the XDVDFS reader ---------------------

    def _open(self, index):
        if self._handles[index] is None:
            self._handles[index] = open(self.data_files[index], "rb")
        return self._handles[index]

    def seek(self, pos):
        self.pos = pos

    def read(self, n=-1):
        if n < 0:
            n = self.size - self.pos
        out = bytearray()
        while n > 0 and 0 <= self.pos < self.size:
            block, within = divmod(self.pos, self.BLOCK)
            index, fb = divmod(block, self.DATA_PER_FILE)
            # skip the level-1 table and one level-0 table per 0xCC blocks
            offset = (fb + fb // self.DATA_PER_L0 + 2) * self.BLOCK + within
            take = min(n, self.BLOCK - within)
            f = self._open(index)
            f.seek(offset)
            chunk = f.read(take)
            if not chunk:
                break
            out += chunk
            self.pos += len(chunk)
            n -= len(chunk)
        return bytes(out)

    def close(self):
        for h in self._handles:
            if h:
                h.close()


# ---------------------------------------------------------------------------
# STFS container - a marketplace DLC package
# ---------------------------------------------------------------------------

BLOCKS_PER_HASH_LEVEL = (170, 170 * 170, 170 * 170 * 170)
STFS_BLOCK = 0x1000
END_OF_CHAIN = 0xFFFFFF


def _u24le(b):
    return b[0] | (b[1] << 8) | (b[2] << 16)


def _round_up(v, m):
    return (v + m - 1) // m * m


class StfsReader:
    """Reads a marketplace DLC package (STFS volume inside an XContent wrapper).

    Ported from rexglue-sdk's StfsContainerDevice (itself Xenia's), which is the
    reader the recomp runtime uses to install these packages - same block maths,
    same hash-table walk, so a file that comes out here is the same file the
    console would have handed the game. The per-block SHA-1s in the level-0
    hash tables are checked as each file is written, which makes the reader
    self-verifying: wrong offsets show up as hash failures, not as silent
    garbage.
    """

    def __init__(self, path: Path):
        self.path = path
        self.f = open(path, "rb")
        head = self.f.read(0x400)
        if head[:4] not in XCONTENT_MAGICS:
            raise ValueError(f"{path.name}: not an XContent package")
        self.header_size = struct.unpack_from(">I", head, 0x340)[0]
        self.content_type = struct.unpack_from(">I", head, 0x344)[0]
        self.title_id = struct.unpack_from(">I", head, 0x360)[0]
        self.volume_type = struct.unpack_from(">I", head, 0x3A1)[0]
        if self.volume_type != 0:
            raise ValueError(f"{path.name}: not an STFS volume "
                             f"(volume_type={self.volume_type})")

        # StfsVolumeDescriptor at 0x379
        d = head[0x379:0x379 + 0x24]
        if d[0] != 0x24:
            raise ValueError(f"{path.name}: bad STFS volume descriptor "
                             f"(length {d[0]:#x})")
        self.flags = d[2]
        self.read_only = bool(self.flags & 0x01)
        self.root_active_index = bool(self.flags & 0x02)
        self.file_table_block_count = struct.unpack_from("<H", d, 3)[0]
        self.file_table_block_number = _u24le(d[5:8])
        self.total_block_count = struct.unpack_from(">I", d, 0x1C)[0]

        self.bpht = 1 if self.read_only else 2   # blocks per hash table
        self.block_step = (
            BLOCKS_PER_HASH_LEVEL[0] + self.bpht,
            BLOCKS_PER_HASH_LEVEL[1] + (BLOCKS_PER_HASH_LEVEL[0] + 1) * self.bpht,
        )
        self.data_base = _round_up(self.header_size, STFS_BLOCK)
        self._tables = {}

    def close(self):
        self.f.close()

    # -- block maths (1:1 with StfsContainerDevice) -----------------------

    def _block_to_offset(self, block_index):
        base = BLOCKS_PER_HASH_LEVEL[0]
        block = block_index
        for _ in range(3):
            block += ((block_index + base) // base) * self.bpht
            if block_index < base:
                break
            base *= BLOCKS_PER_HASH_LEVEL[0]
        return self.data_base + (block << 12)

    def _hash_block_number(self, block_index, level):
        if level == 0:
            if block_index < BLOCKS_PER_HASH_LEVEL[0]:
                return 0
            block = (block_index // BLOCKS_PER_HASH_LEVEL[0]) * self.block_step[0]
            block += ((block_index // BLOCKS_PER_HASH_LEVEL[1]) + 1) * self.bpht
            if block_index < BLOCKS_PER_HASH_LEVEL[1]:
                return block
            return block + self.bpht
        if level == 1:
            if block_index < BLOCKS_PER_HASH_LEVEL[1]:
                return self.block_step[0]
            return (block_index // BLOCKS_PER_HASH_LEVEL[1]) * self.block_step[1] + self.bpht
        return self.block_step[1]

    def _hash_block_offset(self, block_index, level):
        return self.data_base + (self._hash_block_number(block_index, level) << 12)

    def _read_table(self, offset):
        if offset not in self._tables:
            self.f.seek(offset)
            self._tables[offset] = self.f.read(STFS_BLOCK)
        return self._tables[offset]

    def _block_hash(self, block_index):
        """Return (sha1, next_block) for a data block."""
        secondary = STFS_BLOCK if self.root_active_index else 0
        off0 = self._hash_block_offset(block_index, 0)
        if off0 not in self._tables:
            if self.read_only:
                secondary = 0
            else:
                if self.total_block_count > BLOCKS_PER_HASH_LEVEL[0]:
                    off1 = self._hash_block_offset(block_index, 1)
                    if off1 not in self._tables:
                        if self.total_block_count > BLOCKS_PER_HASH_LEVEL[1]:
                            off2 = self._hash_block_offset(block_index, 2)
                            if off2 not in self._tables:
                                self._tables[off2] = self._read_raw(off2 + secondary)
                            rec = (block_index // BLOCKS_PER_HASH_LEVEL[1]) % BLOCKS_PER_HASH_LEVEL[0]
                            secondary = STFS_BLOCK if self._active_index(self._tables[off2], rec) else 0
                        self._tables[off1] = self._read_raw(off1 + secondary)
                    rec = (block_index // BLOCKS_PER_HASH_LEVEL[0]) % BLOCKS_PER_HASH_LEVEL[0]
                    secondary = STFS_BLOCK if self._active_index(self._tables[off1], rec) else 0
            self._tables[off0] = self._read_raw(off0 + secondary)
        table = self._tables[off0]
        rec = block_index % BLOCKS_PER_HASH_LEVEL[0]
        ent = table[rec * 0x18:(rec + 1) * 0x18]
        info = struct.unpack_from(">I", ent, 0x14)[0]
        return ent[:0x14], info & 0xFFFFFF

    def _read_raw(self, offset):
        self.f.seek(offset)
        return self.f.read(STFS_BLOCK)

    @staticmethod
    def _active_index(table, record):
        info = struct.unpack_from(">I", table, record * 0x18 + 0x14)[0]
        return bool(info & 0x40000000)

    # -- directory ---------------------------------------------------------

    def list_files(self):
        """Return [(path, start_block, length)] for every file in the package."""
        entries = []           # index -> (name, is_dir, parent)
        block = self.file_table_block_number
        for _ in range(max(self.file_table_block_count, 1)):
            data = self._read_raw(self._block_to_offset(block))
            if len(data) < STFS_BLOCK:
                problem(f"{self.path.name}: directory block short read")
                break
            for m in range(0x40):
                e = data[m * 0x40:(m + 1) * 0x40]
                if e[0] == 0:
                    break
                flags = e[0x28]
                name = e[:flags & 0x3F].decode("ascii", errors="replace")
                entries.append({
                    "name": name,
                    "is_dir": bool(flags & 0x80),
                    "start": _u24le(e[0x2F:0x32]),
                    "parent": struct.unpack_from(">H", e, 0x32)[0],
                    "length": struct.unpack_from(">I", e, 0x34)[0],
                })
            _, block = self._block_hash(block)
            if block == END_OF_CHAIN:
                break

        def full_path(i):
            parts = []
            seen = set()
            while i != 0xFFFF and i not in seen and i < len(entries):
                seen.add(i)
                parts.append(entries[i]["name"])
                i = entries[i]["parent"]
            return "/".join(reversed(parts))

        out = []
        for i, e in enumerate(entries):
            if not e["is_dir"]:
                out.append((full_path(i), e["start"], e["length"]))
        return out

    def read_file_to(self, start_block, length, dest: Path, label: str):
        """Write one package file out, checking each block against its
        level-0 SHA-1 as it goes. Returns bytes written."""
        dest.parent.mkdir(parents=True, exist_ok=True)
        remaining = length
        block = start_block
        written = 0
        with open(dest, "wb") as out:
            while remaining > 0 and block != END_OF_CHAIN:
                sha1, nxt = self._block_hash(block)
                self.f.seek(self._block_to_offset(block))
                data = self.f.read(STFS_BLOCK)
                if len(data) < STFS_BLOCK:
                    problem(f"{label}: short read at block {block} - package truncated")
                    break
                if hashlib.sha1(data).digest() != sha1:
                    problem(f"{label}: block {block} fails its hash - package is corrupt")
                    break
                take = min(STFS_BLOCK, remaining)
                out.write(data[:take])
                written += take
                remaining -= take
                block = nxt
        if written != length:
            problem(f"{label}: wrote {written:,} of {length:,} bytes (truncated)")
        return written


# ---------------------------------------------------------------------------
# XDVDFS - the disc filesystem, inside an ISO or a disc install
# ---------------------------------------------------------------------------

def find_volume_descriptor(f):
    """Locate the XDVDFS volume descriptor and return (fs_base, root_sector,
    root_size). The descriptor sits at sector 32 of its partition and every
    sector number in the filesystem is partition-relative, so the base for all
    reads is the descriptor's offset MINUS 0x10000 - verified against both a
    full XGD2 rip (partition at 0xFD90000) and a console disc install (partition
    at 0). Earlier versions returned the descriptor offset itself, which shifted
    every read 32 sectors late and made every extracted file garbage."""
    for base in CANDIDATE_OFFSETS:
        f.seek(base)
        header = f.read(0x800)
        if len(header) < 0x800:
            continue
        if header[:20] == XDVDFS_MAGIC and header[0x7EC:0x7EC + 20] == XDVDFS_MAGIC:
            print(f"  Found XDVDFS volume descriptor at offset 0x{base:08X}")
            root_sector = struct.unpack_from("<I", header, 0x14)[0]
            root_size = struct.unpack_from("<I", header, 0x18)[0]
            return base - 0x10000, root_sector, root_size

    print("  Known offsets failed - scanning for XDVDFS magic (may take a moment)...")
    f.seek(0)
    chunk_size = 1 << 20
    offset = 0
    limit = 2 * (1 << 30)
    while offset < limit:
        chunk = f.read(chunk_size)
        if not chunk:
            break
        idx = chunk.find(XDVDFS_MAGIC)
        while idx != -1:
            base = offset + idx
            f.seek(base)
            header = f.read(0x800)
            if len(header) == 0x800 and header[0x7EC:0x7EC + 20] == XDVDFS_MAGIC:
                print(f"  Found XDVDFS volume descriptor at offset 0x{base:08X}")
                root_sector = struct.unpack_from("<I", header, 0x14)[0]
                root_size = struct.unpack_from("<I", header, 0x18)[0]
                return base - 0x10000, root_sector, root_size
            f.seek(offset + len(chunk))
            idx = chunk.find(XDVDFS_MAGIC, idx + 1)
        offset += len(chunk)

    return None


def read_directory(f, fs_base, sector, size):
    """Parse a flat XDVDFS directory table and return list of entry dicts."""
    f.seek(fs_base + sector * SECTOR_SIZE)
    data = f.read(size)
    entries = []
    offset = 0
    while offset < len(data):
        if offset + 14 > len(data):
            break
        left, right = struct.unpack_from("<HH", data, offset)
        if left == 0xFFFF and right == 0xFFFF:
            offset += 4
            continue
        start_sector, file_size = struct.unpack_from("<II", data, offset + 4)
        attributes = data[offset + 12]
        name_len = data[offset + 13]
        if name_len == 0 or offset + 14 + name_len > len(data):
            break
        name = data[offset + 14: offset + 14 + name_len].decode("ascii", errors="replace")
        entries.append({
            "name": name,
            "start_sector": start_sector,
            "size": file_size,
            "is_dir": bool(attributes & 0x10),
        })
        entry_len = 14 + name_len
        offset += (entry_len + 3) & ~3
    return entries


def safe_name(name: str) -> bool:
    """Reject entry names that would write outside the output directory."""
    return not (name in ("", ".", "..") or "/" in name or "\\" in name or ":" in name)


def extract_tree(f, fs_base, sector, size, dest: Path, rel=""):
    for e in read_directory(f, fs_base, sector, size):
        rel_path = f"{rel}/{e['name']}" if rel else e["name"]
        if not safe_name(e["name"]):
            problem(f"{rel_path}: unsafe entry name in the directory table, skipped")
            print(f"  SKIPPED    {rel_path}  (unsafe name -- corrupt directory table?)")
            continue
        item_path = dest / e["name"]
        if e["is_dir"]:
            item_path.mkdir(parents=True, exist_ok=True)
            extract_tree(f, fs_base, e["start_sector"], e["size"], item_path, rel_path)
            continue
        item_path.parent.mkdir(parents=True, exist_ok=True)
        f.seek(fs_base + e["start_sector"] * SECTOR_SIZE)
        remaining = e["size"]
        written = 0
        with open(item_path, "wb") as out:
            while remaining > 0:
                chunk = f.read(min(1 << 16, remaining))
                if not chunk:
                    break
                out.write(chunk)
                written += len(chunk)
                remaining -= len(chunk)
        if written != e["size"]:
            problem(f"{rel_path}: wrote {written:,} of {e['size']:,} bytes (truncated)")
            print(f"  TRUNCATED  {rel_path}  ({written:,} of {e['size']:,} bytes)")
        else:
            print(f"  extracted  {rel_path}  ({written:,} bytes)")


# ---------------------------------------------------------------------------
# Source classification
# ---------------------------------------------------------------------------

def _walk(root: Path, max_depth=5):
    root = root.resolve()
    for dirpath, dirnames, filenames in os.walk(root):
        depth = len(Path(dirpath).resolve().parts) - len(root.parts)
        if depth >= max_depth:
            dirnames[:] = []
            continue
        yield Path(dirpath), dirnames, filenames


def find_god_installs(root: Path):
    """Disc-install containers (header file + <name>.data folder) for this game."""
    found = []
    for dirpath, dirnames, filenames in _walk(root):
        for name in filenames:
            if name + ".data" not in dirnames:
                continue
            path = dirpath / name
            info = read_xcontent_header(path)
            if (info and info["content_type"] == CONTENT_TYPE_INSTALLED_DISC
                    and info["title_id"] == TITLE_ID):
                found.append(path)
    return found


def find_dlc_packages(root: Path):
    """Marketplace DLC packages (STFS files) for this game."""
    found = []
    for dirpath, dirnames, filenames in _walk(root):
        for name in filenames:
            if name + ".data" in dirnames:
                continue
            path = dirpath / name
            info = read_xcontent_header(path)
            if (info and info["content_type"] == CONTENT_TYPE_DLC
                    and info["title_id"] == TITLE_ID):
                found.append(path)
    return found


def find_unpacked_dlc(root: Path):
    """Folders holding DLC contents that some other tool already unpacked -
    i.e. a `<contentid>/Rom/` tree. Returns the folders that are the package
    root (the parent of `Rom`)."""
    found = []
    for dirpath, dirnames, filenames in _walk(root):
        if dirpath.name.lower() == "rom" and any(
                n.lower() in ("cg_black.bin", "cg_blackhi.bin", "dropprm.bl")
                for n in filenames):
            found.append(dirpath.parent)
    return found


def find_extracted_disc(root: Path):
    """Folders that already hold an extracted disc: default.xex + media/."""
    found = []
    for dirpath, dirnames, filenames in _walk(root):
        if "default.xex" in filenames and "media" in [d.lower() for d in dirnames]:
            found.append(dirpath)
    return found


# ---------------------------------------------------------------------------
# Copy helpers
# ---------------------------------------------------------------------------

def copy_file(src: Path, dest: Path, label: str):
    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.exists() and dest.stat().st_size == src.stat().st_size:
        print(f"  present    {label}  ({src.stat().st_size:,} bytes)")
        return
    shutil.copy2(src, dest)
    if dest.stat().st_size != src.stat().st_size:
        problem(f"{label}: copy came out short")
        print(f"  FAILED     {label}")
    else:
        print(f"  copied     {label}  ({dest.stat().st_size:,} bytes)")


def copy_extracted_disc(src_root: Path, out_dir: Path):
    print(f"Copying an already-extracted disc folder: {src_root}")
    for dirpath, _dirnames, filenames in os.walk(src_root):
        for name in filenames:
            s = Path(dirpath) / name
            rel = s.relative_to(src_root).as_posix()
            copy_file(s, out_dir / rel, rel)


def unpack_dlc_folder(pkg_root: Path, out_dir: Path):
    print(f"Taking DLC contents from an unpacked folder: {pkg_root}")
    took = 0
    for internal, target in DLC_WANTED.items():
        s = pkg_root / internal
        if s.is_file():
            copy_file(s, out_dir / target, target)
            took += 1
    if not took:
        print("  (nothing the port uses in that folder)")
    return took


def unpack_dlc_package(pkg: Path, out_dir: Path):
    print(f"Unpacking DLC package: {pkg.name}")
    try:
        stfs = StfsReader(pkg)
    except ValueError as e:
        problem(f"{pkg.name}: {e}")
        print(f"  FAILED     {pkg.name} ({e})")
        return 0
    took = 0
    try:
        files = stfs.list_files()
        print(f"  {len(files)} file(s) in the package")
        wanted = {k.lower(): v for k, v in DLC_WANTED.items()}
        # Fall back to matching on basename. The package-internal paths above are
        # inferred from an already-unpacked copy of this DLC; no raw package was
        # available to confirm them. A basename match cannot pick the wrong file
        # here - these three names are unique in the package - and it stops a
        # differently-laid-out package from silently yielding nothing.
        by_base = {k.rsplit("/", 1)[-1].lower(): v for k, v in DLC_WANTED.items()}
        for path, start, length in files:
            norm = path.replace("\\", "/").lower()
            target = wanted.get(norm)
            if target is None:
                target = by_base.get(norm.rsplit("/", 1)[-1])
                if target is not None:
                    print(f"  NOTE: {path} matched on name, not on its expected "
                          f"path - package layout differs from the reference")
            if target is None:
                print(f"  skipped    {path}  (not used by the port)")
                continue
            n = stfs.read_file_to(start, length, out_dir / target, target)
            if n == length:
                print(f"  unpacked   {target}  ({n:,} bytes)")
                took += 1
    finally:
        stfs.close()
    return took


# ---------------------------------------------------------------------------
# Derived files and verification
# ---------------------------------------------------------------------------

def make_derived(out_dir: Path, shell_dir: Path | None):
    """The two byte-identical duplicates the port's layout needs beyond the
    disc tree. Both are copies, not new data - see DESIGN.md."""
    for src_rel, dest_rel in DERIVED_IN_ASSETS.items():
        src = out_dir / src_rel
        if src.is_file():
            copy_file(src, out_dir / dest_rel, dest_rel)
        else:
            problem(f"{src_rel}: missing, cannot make the derived {dest_rel}")
    if shell_dir is not None:
        src = out_dir / "default.xex"
        if src.is_file():
            copy_file(src, shell_dir / DERIVED_SHELL_XEX,
                      f"{shell_dir.name}/{DERIVED_SHELL_XEX}")
        else:
            problem("default.xex: missing, cannot stage the shell module")


def load_manifest():
    if not MANIFEST.is_file():
        return None
    rows = {}
    for line in MANIFEST.read_text(encoding="utf-8").splitlines():
        if not line or line.startswith("#") or line.startswith("path\t"):
            continue
        p, size, sha = line.split("\t")
        rows[p] = (int(size), sha)
    return rows


def sha256_file(path: Path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while True:
            b = f.read(1 << 20)
            if not b:
                break
            h.update(b)
    return h.hexdigest()


def verify_against_manifest(out_dir: Path, quick=False):
    """Compare the produced tree against the ground-truth manifest.

    Returns (ok, missing, mismatched, extra). Missing DLC-derived files are
    reported separately by the caller - the port runs without them, only modes
    4 and 5 (Black Label) need them.
    """
    rows = load_manifest()
    if rows is None:
        print(f"NOTE: no manifest at {MANIFEST}, skipping verification")
        return True, [], [], []
    missing, mismatched = [], []
    for rel, (size, sha) in sorted(rows.items()):
        p = out_dir / rel
        if not p.is_file():
            missing.append(rel)
            continue
        actual_size = p.stat().st_size
        if actual_size != size:
            mismatched.append((rel, f"size {actual_size:,} != {size:,}"))
            continue
        if quick:
            continue
        actual = sha256_file(p)
        if actual != sha:
            mismatched.append((rel, f"sha256 {actual[:16]}... != {sha[:16]}..."))
    have = set()
    for dirpath, _d, filenames in os.walk(out_dir):
        for n in filenames:
            have.add((Path(dirpath) / n).relative_to(out_dir).as_posix())
    extra = sorted(have - set(rows))
    return (not missing and not mismatched), missing, mismatched, extra


def report_verification(out_dir, missing, mismatched, extra):
    dlc_rels = set(DLC_WANTED.values())
    missing_dlc = [m for m in missing if m in dlc_rels]
    missing_core = [m for m in missing if m not in dlc_rels]

    if mismatched:
        print(f"\n{len(mismatched)} file(s) DO NOT MATCH the manifest:")
        for rel, why in mismatched:
            print(f"  {rel}: {why}")
        problem(f"{len(mismatched)} file(s) do not match the reference manifest")
    if missing_core:
        print(f"\n{len(missing_core)} required file(s) MISSING:")
        for rel in missing_core:
            print(f"  {rel}")
        problem(f"{len(missing_core)} required file(s) are missing from {out_dir}")
    if missing_dlc:
        print(f"\nBlack Label DLC not supplied - {len(missing_dlc)} file(s) absent:")
        for rel in missing_dlc:
            print(f"  {rel}")
        print("  The port runs; game modes 4 and 5 (Black Label / Black Label HI)")
        print("  will not. Point this tool at your DLC to add them.")
    if extra:
        print(f"\n{len(extra)} extra file(s) not in the manifest (harmless):")
        for rel in extra[:10]:
            print(f"  {rel}")
        if len(extra) > 10:
            print(f"  ... and {len(extra) - 10} more")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def classify(path: Path):
    """Work out what the user handed us."""
    src = {"god": None, "iso": None, "dlc_pkgs": [], "dlc_dirs": [], "extracted": None}
    if path.is_file():
        info = read_xcontent_header(path)
        if info is None:
            src["iso"] = path
            return src
        if info["title_id"] != TITLE_ID:
            sys.exit(f"{path.name} is an Xbox 360 package, but for title "
                     f"{info['title_id']:08X}, not this game ({TITLE_ID:08X}).")
        if info["content_type"] == CONTENT_TYPE_INSTALLED_DISC:
            src["god"] = path
            return src
        if info["content_type"] == CONTENT_TYPE_DLC:
            src["dlc_pkgs"] = [path]
            return src
        sys.exit(f"{path.name}: unsupported package type "
                 f"{info['content_type']:#x} (expected a disc install or DLC).")

    gods = find_god_installs(path)
    src["dlc_pkgs"] = find_dlc_packages(path)
    src["dlc_dirs"] = find_unpacked_dlc(path)
    if gods:
        if len(gods) > 1:
            print(f"  NOTE: {len(gods)} disc installs found; using {gods[0]}")
        src["god"] = gods[0]
    else:
        extracted = find_extracted_disc(path)
        if extracted:
            src["extracted"] = extracted[0]
        else:
            isos = sorted(path.glob("*.iso"))
            if isos:
                src["iso"] = isos[0]
    if not any((src["god"], src["iso"], src["extracted"],
                src["dlc_pkgs"], src["dlc_dirs"])):
        sys.exit(
            f"Nothing usable for this game found under {path}.\n"
            "Expected one of: the console's Content layout (a 00007000 folder\n"
            "holding the installed disc, and/or a 00000002 folder of DLC), a\n"
            "disc ISO, or an already-extracted disc folder.")
    return src


def main():
    parser = argparse.ArgumentParser(
        description="Build futari_realcomp's assets/ tree from your own copy of "
                    "Mushihimesama Futari Ver. 1.5")
    parser.add_argument("source", nargs="?",
                        help="An .iso, a console-install folder (00007000 or "
                             "anything above it), a DLC folder (00000002), or "
                             "an already-extracted disc folder")
    parser.add_argument("--out", default="assets", help="Assets output directory")
    parser.add_argument("--shell", default=None,
                        help="Also stage default.xex into this directory "
                             "(the port's shell/ folder)")
    parser.add_argument("--no-verify", action="store_true",
                        help="Skip the disc install's hash-tree verification")
    parser.add_argument("--verify-only", action="store_true",
                        help="Check an existing --out tree against the manifest "
                             "and stop")
    parser.add_argument("--quick", action="store_true",
                        help="Verify sizes only, not SHA-256 (fast)")
    args = parser.parse_args()

    out_dir = Path(args.out)
    shell_dir = Path(args.shell) if args.shell else None

    if args.verify_only:
        if not out_dir.is_dir():
            sys.exit(f"Nothing to verify: {out_dir} does not exist.")
        print(f"Verifying {out_dir} against {MANIFEST.name}"
              f"{' (sizes only)' if args.quick else ''}...")
        ok, missing, mismatched, extra = verify_against_manifest(out_dir, args.quick)
        report_verification(out_dir, missing, mismatched, extra)
        if PROBLEMS:
            print(f"\nVERIFY FAILED -- {len(PROBLEMS)} problem(s).", file=sys.stderr)
            return 1
        print("\nVerified: every file in the manifest is present and matches.")
        return 0

    if args.source:
        src_path = Path(args.source)
        if not src_path.exists():
            sys.exit(f"Not found: {src_path}")
    else:
        candidates = list(Path(".").glob("*.iso")) + list(Path("game").glob("*.iso"))
        if not candidates:
            sys.exit("Nothing to extract. Pass a path: an .iso, or a folder "
                     "copied off your console.")
        src_path = candidates[0]
        print(f"Auto-detected ISO: {src_path}")

    src = classify(src_path)
    out_dir.mkdir(parents=True, exist_ok=True)

    # -- the disc ---------------------------------------------------------
    disc = None
    if src["god"] is not None:
        print(f"Opening console disc install: {src['god']}")
        disc = GodReader(src["god"])
        print(f"  {len(disc.data_files)} data files, "
              f"{disc.size / 1e9:.2f} GB of game data")
        structural = disc.check_files()
        if not structural and not args.no_verify:
            print("Verifying the copy against the container's own hash tree...")
            structural = disc.verify()
        if structural:
            print(f"\nEXTRACTION FAILED -- {len(structural)} problem(s):", file=sys.stderr)
            for p in structural:
                print(f"  {p}", file=sys.stderr)
            print("\nRe-copy the install from your console's storage and try again;\n"
                  "do not build from a copy that fails these checks.", file=sys.stderr)
            return 1
    elif src["iso"] is not None:
        print(f"Opening {src['iso']} ({src['iso'].stat().st_size / 1e9:.2f} GB)")
        disc = open(src["iso"], "rb")

    if disc is not None:
        result = find_volume_descriptor(disc)
        if result is None:
            sys.exit("Could not find XDVDFS volume descriptor.\n"
                     "The image may be encrypted, split, or an unsupported format.\n"
                     "extract-xiso is a useful second opinion: "
                     "https://github.com/XboxDev/extract-xiso")
        fs_base, root_sector, root_size = result
        print(f"  Root dir: sector {root_sector}, size {root_size} bytes")
        print(f"Extracting to {out_dir}/")
        extract_tree(disc, fs_base, root_sector, root_size, out_dir)
        disc.close()
    elif src["extracted"] is not None:
        copy_extracted_disc(src["extracted"], out_dir)

    # -- the DLC ----------------------------------------------------------
    for pkg in src["dlc_pkgs"]:
        unpack_dlc_package(pkg, out_dir)
    for folder in src["dlc_dirs"]:
        unpack_dlc_folder(folder, out_dir)

    # -- derived copies ---------------------------------------------------
    if (out_dir / "default.xex").is_file():
        print("Staging the copies the port's layout needs...")
        make_derived(out_dir, shell_dir)

    # -- verify -----------------------------------------------------------
    print(f"\nVerifying {out_dir} against {MANIFEST.name}"
          f"{' (sizes only)' if args.quick else ''}...")
    ok, missing, mismatched, extra = verify_against_manifest(out_dir, args.quick)
    report_verification(out_dir, missing, mismatched, extra)

    if PROBLEMS:
        print(f"\nEXTRACTION FAILED -- {len(PROBLEMS)} problem(s):", file=sys.stderr)
        for p in PROBLEMS:
            print(f"  {p}", file=sys.stderr)
        print("\nThe dump is most likely truncated, split across files, or corrupt.\n"
              "Re-copy it and run this again; do not run the port on what was\n"
              "extracted here.", file=sys.stderr)
        return 1

    print("\nDone. assets/ matches the reference manifest.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
