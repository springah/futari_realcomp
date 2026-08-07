#!/usr/bin/env python3
import sys, struct, mmap, os
sys.path.insert(0,os.path.dirname(__file__))
from pm4 import GuestMem, Walker

def analyze(capdir, start, end, label):
    mem = GuestMem(capdir)
    w = Walker(mem, sys.stdout)
    w.walk(start, end)
    print("\n########## %s  window [0x%X,0x%X)  draws=%d ##########" % (label,start,end,w.ndraw))
    # sampled bases histogram
    sampled = {}
    prim_hist = {}
    fmt_hist = {}
    resolves = []
    mode_draws = {}
    for d in w.draws:
        for (s,b,f) in d['allbases']:
            sampled.setdefault(b, 0); sampled[b]+=1
        sampled.setdefault(d['texbase'],0)  # ensure tex0 counted
        prim_hist[d['prim']] = prim_hist.get(d['prim'],0)+1
        fmt_hist[d['fmt']] = fmt_hist.get(d['fmt'],0)+1
        mode_draws[d['mode']] = mode_draws.get(d['mode'],0)+1
    # find resolve draws (mode==6 or copy_ctrl nonzero) and RB_COPY register sets
    print("prim histogram:", prim_hist)
    print("fmt histogram :", fmt_hist)
    print("draw edram_mode histogram:", mode_draws)
    print("distinct sampled texture bases (%d):" % len(sampled))
    for b in sorted(sampled):
        print("   0x%08X  x%d" % (b, sampled[b]))
    # RB_COPY events
    print("--- RB_COPY / RT register writes (chronological) ---")
    for e in w.events:
        if e[0]=='REG' and e[2] in (0x2000,0x2001,0x2318,0x2319,0x231A,0x231B,0x2208):
            _,i,r,val,old = e
            name = {0x2000:'RB_SURFACE_INFO',0x2001:'RB_COLOR_INFO',0x2208:'RB_MODECONTROL',
                    0x2318:'RB_COPY_CONTROL',0x2319:'RB_COPY_DEST_BASE',
                    0x231A:'RB_COPY_DEST_PITCH',0x231B:'RB_COPY_DEST_INFO'}[r]
            print("   @0x%X %-18s(0x%04X) = 0x%08X" % (i,name,r,val))
    # decode the resolve(s): find any draw with mode==6
    print("--- RESOLVE draws (edram_mode==6 kCopy) ---")
    for d in w.draws:
        if d['mode']==6:
            decode_resolve(w, d)
    return w, sampled, resolves

def decode_resolve(w, d):
    r = w.reg
    cc = r.get(0x2318,0); cb = r.get(0x2319,0); cp = r.get(0x231A,0); ci = r.get(0x231B,0)
    surf = r.get(0x2000,0); col = r.get(0x2001,0)
    # RB_COPY_DEST_BASE : raw guest byte address (tile-aligned)
    dest = cb
    # RB_COPY_DEST_PITCH : pitch:14 @0 ; height:14 @16  (units = pixels)
    pitch = cp & 0x3FFF
    height = (cp>>16) & 0x3FFF
    # RB_COPY_DEST_INFO fields (Xenos xe_gpu_copy_dest_info_t)
    endian = ci & 0x7
    dst_array = (ci>>3)&1
    dst_slice = (ci>>4)&0x7
    dst_fmt = (ci>>7)&0x3F        # ColorFormat
    dst_number = (ci>>13)&0x7
    dst_bias = (ci>>16)&0x3F
    dst_swap = (ci>>25)&0x3
    # RB_COPY_CONTROL fields
    copy_src_select = cc & 0x7
    copy_sample_select = (cc>>4)&0x7
    copy_cmd = (cc>>20)&0x3
    # RB_SURFACE_INFO
    surf_pitch = surf & 0x3FFF
    msaa = (surf>>16)&0x3
    # RB_COLOR_INFO
    color_base_tile = col & 0xFFF
    color_fmt = (col>>16)&0xF
    print("  RESOLVE @0x%X:" % d['i'])
    print("    RB_COPY_CONTROL   0x%08X  src_select=%d sample_select=%d copy_command=%d" % (cc,copy_src_select,copy_sample_select,copy_cmd))
    print("    RB_COPY_DEST_BASE 0x%08X  -> DEST guest byte addr = 0x%08X" % (cb,dest))
    print("    RB_COPY_DEST_PITCH0x%08X  -> pitch=%d height=%d (pixels)" % (cp,pitch,height))
    print("    RB_COPY_DEST_INFO 0x%08X  -> endian=%d fmt=%d(0x%X) number=%d bias=%d swap=%d array=%d slice=%d" % (ci,endian,dst_fmt,dst_fmt,dst_number,dst_bias,dst_swap,dst_array,dst_slice))
    print("    RB_SURFACE_INFO   0x%08X  -> surface_pitch=%d msaa=%d" % (surf,surf_pitch,msaa))
    print("    RB_COLOR_INFO     0x%08X  -> edram_color_base_tile=%d color_fmt=%d" % (col,color_base_tile,color_fmt))
    print("    front buffer (manifest fb_virtual) = 0x006E2000 ; is DEST==fb? %s" % (dest==0x006E2000))

if __name__=='__main__':
    w2,samp2,_ = analyze('/home/shant/xr-work/caps_gp2', 0x079BB000, 0x079BE094, 'GAMEPLAY caps_gp2')
    w1,samp1,_ = analyze('/home/shant/xr-work/caps_gp',  0x079B3000+0x8000, 0x079BE624, 'HUD caps_gp')
    # cross reference
    print("\n\n===== CROSS-REFERENCE =====")
    dests2 = sorted({d['copy_base'] for d in w2.draws if d['mode']==6} | {w2.reg.get(0x2319,0)} if any(d['mode']==6 for d in w2.draws) else set())
    print("caps_gp2 resolve dest(s):", [hex(x) for x in dests2])
    print("Is caps_gp2 resolve dest 0x00DBD000 sampled by any caps_gp2 draw? ", 0x00DBD000 in samp2)
    print("Is caps_gp2 resolve dest 0x00DBD000 sampled by any caps_gp  draw? ", 0x00DBD000 in samp1)
