#!/usr/bin/env python3
# bindiff.py a b -- byte-level diff of two files: offset (hex), a, b; groups contiguous runs
import sys
a=open(sys.argv[1],'rb').read(); b=open(sys.argv[2],'rb').read()
print(f"len {len(a)} {len(b)}")
d=[i for i in range(min(len(a),len(b))) if a[i]!=b[i]]
runs=[]
for i in d:
    if runs and i-runs[-1][1]<=1: runs[-1][1]=i
    else: runs.append([i,i])
print(f"{len(d)} bytes differ in {len(runs)} run(s)")
for s,e in runs: print(f"  +0x{s:04X}..+0x{e:04X}: {a[s:e+1].hex()} -> {b[s:e+1].hex()}")
