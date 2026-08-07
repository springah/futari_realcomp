import sys, struct
def be32(d,o): return struct.unpack_from('>I', d, o)[0]
def be16(d,o): return struct.unpack_from('>H', d, o)[0]
def bef(d,o):
    v = be32(d,o); return struct.unpack('>f', struct.pack('>I', v))[0]
for path,gbase in [("caps_s8/cap_image.bin",0x82000000),("caps_s8/cap_gimage.bin",0x88000000)]:
    try: d=open(path,'rb').read()
    except Exception as e: print("skip",path,e); continue
    print(f"=== {path} ({len(d)} bytes, guest 0x{gbase:X}) ===")
    i=0; ncont=0
    while i < len(d)-36:
        flags=be32(d,i)
        if (flags & 0xFFFFFF00)==0x102A1100:
            vsz=be32(d,i+4); psz=be32(d,i+8); f1c=be32(d,i+28); f20=be32(d,i+32)
            if f1c==0 and f20==0 and vsz+psz <= len(d)-i:
                ncont+=1
                isPixel=(flags&1)==0
                defOff=be32(d,i+20)
                if defOff and i+defOff+20 < len(d):
                    dp=i+defOff+20; guard=0
                    while dp+8<=len(d) and be32(d,dp)!=0 and guard<256:
                        hdr=be32(d,dp); regIdx=hdr>>16; count=hdr&0xFFFF; physOff=be32(d,dp+4)
                        for k in range((count+3)//4):
                            reg = regIdx + k - (256 if isPixel else 0)
                            va = i + vsz + physOff + k*16
                            if 250 <= reg <= 256 and va+16<=len(d):
                                print(f"  container@0x{gbase+i:X} {'PS' if isPixel else 'VS'} vsz=0x{vsz:X} defOff=0x{defOff:X}: c{reg} = ({bef(d,va):.6f}, {bef(d,va+4):.6f}, {bef(d,va+8):.6f}, {bef(d,va+12):.6f})")
                        dp+=8; guard+=1
                i += vsz+psz; continue
        i += 4
    print(f"  ({ncont} containers, scanned for c250-c256 float4 defs)")
