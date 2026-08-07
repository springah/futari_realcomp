// rt_xwma.cpp — host-side xWMA (WMAudio2 / WAVE_FORMAT_WMAUDIO2 0x0161) decoder for the
// Xbox 360 XACT wave banks this game ships (assets/media/Sound/*.xwb).
//
// WHY (banked design, [[futari-audio-bringup]] 2026-07-18 + user directive 07-25):
//   The port has NO software audio decoder. Bank census (all 5 banks, re-verified this leg
//   against the on-disk entry tables):
//     BGM.xwb      13 entries, ALL PCM16 48k stereo      (tag 0)
//     SYS_BGM.xwb   1 entry,       PCM16 48k stereo      (tag 0)
//     SE.xwb       70 entries: 67 xWMA 44.1k mono + 3 PCM
//     VOICE.xwb   134 entries, ALL xWMA 44.1k mono
//     SYS_SE.xwb    7 entries, ALL xWMA 48k stereo
//   ZERO XMA / ADPCM. So every compressed SE/VOICE/SYS_SE voice (the START-press confirm SE
//   the user reports missing, plus ~200 more) is silent BY CONSTRUCTION — there is nothing in
//   the port that turns a WMAudio2 packet into PCM. XMACreateContext/XMAReleaseContext are
//   no-op stubs and are never called (that is the hardware XMA path, unused by these banks).
//
// FORMAT — NOT improvised; each field is grounded in the on-disk bytes:
//   WAVEBANKMINIWAVEFORMAT (the packed DWORD at entry+4, read big-endian):
//     tag:2 | nChannels:3 | nSamplesPerSec:18 | wBlockAlign:8 | wBitsPerSample:1
//   For tag==3 (WMA) wBlockAlign is an INDEX PAIR into the two XACT constant tables
//   (xact3wb.h): low 5 bits -> aWMABlockAlign[], high 3 bits -> aWMAAvgBytesPerSec[].
//   VERIFIED against real data before a line of decoder was written:
//     SE/VOICE   block=99 -> idx (99&31)=3 -> 2230 B/packet, (99>>5)=3 -> 6000 B/s.
//                Every SE PlayRegion length is an exact multiple of 2230 (8920=4x, 4460=2x,
//                11150=5x, 6690=3x, 2230=1x).
//     SYS_SE     block=37 -> idx 5 -> 8192 B/packet, idx 1 -> 24000 B/s.
//                Every SYS_SE PlayRegion length is an exact multiple of 8192 (73728=9x,
//                81920=10x, 90112=11x, 114688=14x).
//   The SEEKTABLES segment (seg 2) is the xWMA dpds table = CUMULATIVE DECODED BYTES per
//   packet. Layout: entryCount u32 offsets, then per entry {u32 packetCount, u32 dpds[...]}.
//   Cross-checked: SYS_SE 7 entries -> 7 counts + 71 dpds words = 78 u32 = 312 B, exactly the
//   segment length minus the 28-byte offset array. dpds[last] is therefore the EXACT expected
//   decoded byte count and is used here as a decode ORACLE (see rt_xwma_decode_xwb_entry).
//
// DECODER BACKEND: the in-box Windows "WMAudio Decoder DMO" (CLSID_CWMADecMediaObject), fed
//   raw nBlockAlign-sized packets with a WAVEFORMATEX(0x0161, cbSize=10) built from the fields
//   above. This is the same codec ff_wmav2 implements (the SDK oracle's FFmpeg route); using
//   the OS decoder keeps the port dependency-free (ole32 only, already linked) and avoids
//   vendoring LGPL sources. Extradata = {dwSamplesPerBlock=0, wEncodeOptions=31,
//   dwSuperBlockAlign=0} — the same 10-byte WMAUDIO2 tail FFmpeg's xwma demuxer synthesizes
//   for container-less xWMA (flags2=31).
//
// LEVER: nothing here runs unless a caller asks. The runtime consumer (rt_audio.cpp bridge)
//   gates every call on RT_AUDIOXWMA (RT_AUDIOXWMA=0 reverts to the previous PCM-only path).
//
// STANDALONE TOOL: compile with -DRT_XWMA_MAIN for an offline decoder/verifier:
//   rt_xwma.exe <bank.xwb>            -> entry table census (tag/format/packets/dpds)
//   rt_xwma.exe <bank.xwb> N out.wav  -> decode entry N to a 16-bit PCM WAV + stats vs dpds
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <mutex>   // std::call_once (MED-11 bank-cache guard)
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <mmreg.h>
#include <objbase.h>
#include <mediaobj.h>
#ifndef DMO_E_NOTACCEPTING
#define DMO_E_NOTACCEPTING ((HRESULT)0x80040205L)   // dmoerror.h; declared here to avoid the extra header
#endif
#endif

// ---------------------------------------------------------------- .xwb parsing
extern "C" {
typedef struct RtXwbEntry {
  int      valid;
  int      tag;          // 0=PCM 1=XMA 2=ADPCM 3=xWMA(WMAudio2)
  int      chans;
  int      rate;
  int      block_index;  // raw miniformat wBlockAlign field
  int      block_align;  // decoded bytes-per-packet (xWMA) / frame size (PCM)
  int      avg_bytes;    // decoded bytes/sec (xWMA)
  int      bits16;       // PCM only
  uint32_t play_off;     // offset within the ENTRYWAVEDATA segment
  uint32_t play_len;
  uint32_t loop_start, loop_total;
  uint32_t dur_samples;  // from entry+0 >> 4
  uint64_t dpds_last;    // cumulative decoded bytes of the last packet (0 if no seek table)
  uint32_t abs_off;      // absolute file offset of the play region
} RtXwbEntry;
int  rt_xwb_read_entry(const char* path, int waveIdx, RtXwbEntry* out);
int  rt_xwb_entry_count(const char* path);
int  rt_xwb_entry_tag(const char* path, int waveIdx);   // -1 on error; 0=PCM 3=xWMA
int  rt_xwma_decode_xwb_entry(const char* path, int waveIdx,
                              int16_t** outPcm, size_t* outFrames, int* outChans, int* outRate);
void rt_xwma_free(int16_t* p);
}

// xact3wb.h constant tables (used ONLY to expand the miniformat index pair).
static const uint32_t kWmaBlockAlign[17] = {
  929, 1487, 1280, 2230, 8917, 8192, 4459, 5945, 2304, 1536, 1485, 1008, 2731, 4096, 6827, 5462, 1280
};
static const uint32_t kWmaAvgBytesPerSec[7] = { 12000, 24000, 4000, 6000, 8000, 20000, 2500 };

static inline uint32_t rx_be32(const uint8_t* p){
  return ((uint32_t)p[0]<<24)|((uint32_t)p[1]<<16)|((uint32_t)p[2]<<8)|(uint32_t)p[3];
}

struct RtXwbHeader {
  uint32_t seg_off[5], seg_len[5];
  uint32_t flags, count, entry_size;
  char     name[65];
};

static int rx_read_header(FILE* f, RtXwbHeader* h){
  uint8_t hdr[256];
  if(std::fseek(f,0,SEEK_SET)!=0) return -1;
  if(std::fread(hdr,1,sizeof hdr,f)!=sizeof hdr) return -1;
  if(std::memcmp(hdr,"DNBW",4)!=0 && std::memcmp(hdr,"WBND",4)!=0) return -2;
  for(int i=0;i<5;i++){ h->seg_off[i]=rx_be32(hdr+12+8*i); h->seg_len[i]=rx_be32(hdr+12+8*i+4); }
  uint32_t d = h->seg_off[0];
  if(d+84 > sizeof hdr) return -3;
  h->flags      = rx_be32(hdr+d);
  h->count      = rx_be32(hdr+d+4);
  std::memcpy(h->name, hdr+d+8, 64); h->name[64]=0;
  h->entry_size = rx_be32(hdr+d+72);
  if(h->entry_size < 16 || h->entry_size > 64) return -4;
  return 0;
}

// dpds[last] for entry i, or 0 when the bank carries no seek tables.
static uint64_t rx_dpds_last(FILE* f, const RtXwbHeader* h, int idx){
  if(!h->seg_len[2] || h->seg_len[2] < 4u*h->count) return 0;
  std::vector<uint8_t> seg(h->seg_len[2]);
  if(std::fseek(f,(long)h->seg_off[2],SEEK_SET)!=0) return 0;
  if(std::fread(seg.data(),1,seg.size(),f)!=seg.size()) return 0;
  // The per-entry offsets are relative to the END of the offset array (verified on SYS_SE:
  // offsets 0x0,0x28,0x50,... with the first table's packetCount landing at seg+28).
  uint32_t tbl = rx_be32(seg.data()+4u*(uint32_t)idx);
  if(tbl==0xFFFFFFFFu) return 0;
  tbl += 4u*h->count;
  if(tbl+4 > seg.size()) return 0;
  uint32_t n = rx_be32(seg.data()+tbl);
  if(!n || tbl+4+4ull*n > seg.size()) return 0;
  return rx_be32(seg.data()+tbl+4+4u*(n-1));
}

extern "C" int rt_xwb_entry_count(const char* path){
  FILE* f=std::fopen(path,"rb"); if(!f) return -1;
  RtXwbHeader h; int r=rx_read_header(f,&h); std::fclose(f);
  return r==0 ? (int)h.count : -1;
}

extern "C" int rt_xwb_entry_tag(const char* path, int waveIdx){
  RtXwbEntry e;
  if(rt_xwb_read_entry(path,waveIdx,&e)!=0) return -1;
  return e.tag;
}

extern "C" int rt_xwb_read_entry(const char* path, int waveIdx, RtXwbEntry* out){
  std::memset(out,0,sizeof *out);
  FILE* f=std::fopen(path,"rb"); if(!f) return -1;
  RtXwbHeader h;
  if(rx_read_header(f,&h)!=0){ std::fclose(f); return -2; }
  if(waveIdx<0 || (uint32_t)waveIdx>=h.count){ std::fclose(f); return -3; }
  uint8_t e[64];
  if(std::fseek(f,(long)(h.seg_off[1]+(uint32_t)waveIdx*h.entry_size),SEEK_SET)!=0){ std::fclose(f); return -4; }
  if(std::fread(e,1,h.entry_size,f)!=h.entry_size){ std::fclose(f); return -5; }
  uint32_t flags_dur = rx_be32(e+0);
  uint32_t fmt       = rx_be32(e+4);
  out->play_off      = rx_be32(e+8);
  out->play_len      = rx_be32(e+12);
  if(h.entry_size>=24){ out->loop_start=rx_be32(e+16); out->loop_total=rx_be32(e+20); }
  out->dur_samples = flags_dur >> 4;
  out->tag         = (int)(fmt & 0x3u);
  out->chans       = (int)((fmt>>2) & 0x7u);
  out->rate        = (int)((fmt>>5) & 0x3FFFFu);
  out->block_index = (int)((fmt>>23) & 0xFFu);
  out->bits16      = (int)((fmt>>31) & 0x1u);
  if(out->tag==3){
    out->block_align = (int)kWmaBlockAlign[(uint32_t)out->block_index & 31u];
    out->avg_bytes   = (int)kWmaAvgBytesPerSec[((uint32_t)out->block_index >> 5) & 7u];
  } else {
    out->block_align = out->block_index;
    out->avg_bytes   = 0;
  }
  out->abs_off   = h.seg_off[4] + out->play_off;
  out->dpds_last = rx_dpds_last(f,&h,waveIdx);
  out->valid     = 1;
  std::fclose(f);
  return 0;
}

// ---------------------------------------------------------------- WMAudio2 decode (Windows DMO)
#ifdef _WIN32
// Public CLSIDs/IIDs spelled out so no extra .lib (wmcodecdspuuid/strmiids/msdmo) is needed.
static const GUID kCLSID_CWMADecMediaObject =
  {0x2EEB4ADF,0x4578,0x4D10,{0xBC,0xA7,0xBB,0x95,0x5F,0x56,0x32,0x0A}};
static const GUID kIID_IMediaObject =
  {0xD8AD0F58,0x5494,0x4102,{0x97,0xC5,0xEC,0x79,0x8E,0x59,0xBC,0xF4}};
static const GUID kIID_IMediaBuffer =
  {0x59EFF8B9,0x938C,0x4A26,{0x82,0xF2,0x95,0xCB,0x84,0xCD,0xC8,0x37}};
static const GUID kMEDIATYPE_Audio =
  {0x73647561,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};
static const GUID kMEDIASUBTYPE_WMAUDIO2 =
  {0x00000161,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};
static const GUID kMEDIASUBTYPE_PCM =
  {0x00000001,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};
static const GUID kFORMAT_WaveFormatEx =
  {0x05589F81,0xC356,0x11CE,{0xBF,0x01,0x00,0xAA,0x00,0x55,0x59,0x5A}};

// Minimal IMediaBuffer over caller-owned memory (the DMO only ever borrows it).
class RtMediaBuffer final : public IMediaBuffer {
public:
  RtMediaBuffer(BYTE* p, DWORD maxLen, DWORD curLen)
    : ref_(1), data_(p), max_(maxLen), len_(curLen) {}
  STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override {
    if(!ppv) return E_POINTER;
    if(riid==IID_IUnknown || riid==kIID_IMediaBuffer){ *ppv=static_cast<IMediaBuffer*>(this); AddRef(); return S_OK; }
    *ppv=nullptr; return E_NOINTERFACE;
  }
  STDMETHODIMP_(ULONG) AddRef() override { return (ULONG)InterlockedIncrement(&ref_); }
  STDMETHODIMP_(ULONG) Release() override { LONG r=InterlockedDecrement(&ref_); return (ULONG)(r<0?0:r); }
  STDMETHODIMP SetLength(DWORD len) override { if(len>max_) return E_INVALIDARG; len_=len; return S_OK; }
  STDMETHODIMP GetMaxLength(DWORD* p) override { if(!p) return E_POINTER; *p=max_; return S_OK; }
  STDMETHODIMP GetBufferAndLength(BYTE** ppb, DWORD* pl) override {
    if(ppb) *ppb=data_; if(pl) *pl=len_; return S_OK;
  }
  void reset(BYTE* p, DWORD maxLen, DWORD curLen){ data_=p; max_=maxLen; len_=curLen; }
private:
  LONG  ref_; BYTE* data_; DWORD max_, len_;
};

struct RtWmaFmt {   // WAVEFORMATEX + the 10-byte WMAUDIO2 tail, contiguous
  WAVEFORMATEX wfx;
  uint8_t      extra[10];
};

static void rx_build_input_fmt(RtWmaFmt* f, int chans, int rate, int blockAlign, int avgBytes){
  std::memset(f,0,sizeof *f);
  f->wfx.wFormatTag      = 0x0161;              // WAVE_FORMAT_WMAUDIO2
  f->wfx.nChannels       = (WORD)chans;
  f->wfx.nSamplesPerSec  = (DWORD)rate;
  f->wfx.nAvgBytesPerSec = (DWORD)avgBytes;
  f->wfx.nBlockAlign     = (WORD)blockAlign;
  f->wfx.wBitsPerSample  = 16;
  f->wfx.cbSize          = 10;
  // WMAUDIO2 tail: dwSamplesPerBlock(0) | wEncodeOptions(31) | dwSuperBlockAlign(0)
  f->extra[4] = 31; f->extra[5] = 0;
}

// Decode a contiguous run of xWMA packets. Returns 0 on success.
static int rx_dmo_decode(const uint8_t* packets, size_t bytes,
                         int chans, int rate, int blockAlign, int avgBytes,
                         std::vector<int16_t>& out, char* err, size_t errsz){
  auto fail=[&](const char* what, HRESULT hr)->int{
    if(err) std::snprintf(err,errsz,"%s hr=0x%08lX",what,(unsigned long)hr);
    return -1;
  };
  if(blockAlign<=0 || bytes<(size_t)blockAlign) return fail("no packets",0);

  HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
  bool uninit = SUCCEEDED(hr);            // RPC_E_CHANGED_MODE => already initialized elsewhere
  IMediaObject* dmo=nullptr;
  hr = CoCreateInstance(kCLSID_CWMADecMediaObject,nullptr,CLSCTX_INPROC_SERVER,kIID_IMediaObject,(void**)&dmo);
  if(FAILED(hr) || !dmo){ if(uninit) CoUninitialize(); return fail("CoCreateInstance(WMADecMediaObject)",hr); }

  RtWmaFmt in{};  rx_build_input_fmt(&in,chans,rate,blockAlign,avgBytes);
  DMO_MEDIA_TYPE mt{};
  mt.majortype  = kMEDIATYPE_Audio;
  mt.subtype    = kMEDIASUBTYPE_WMAUDIO2;
  mt.bFixedSizeSamples = FALSE; mt.bTemporalCompression = TRUE;
  mt.lSampleSize = 0;
  mt.formattype = kFORMAT_WaveFormatEx;
  mt.cbFormat   = sizeof(WAVEFORMATEX)+10;
  mt.pbFormat   = (BYTE*)&in;
  hr = dmo->SetInputType(0,&mt,0);
  if(FAILED(hr)){ dmo->Release(); if(uninit) CoUninitialize(); return fail("SetInputType",hr); }

  WAVEFORMATEX outw{};
  outw.wFormatTag=WAVE_FORMAT_PCM; outw.nChannels=(WORD)chans; outw.nSamplesPerSec=(DWORD)rate;
  outw.wBitsPerSample=16; outw.nBlockAlign=(WORD)(chans*2);
  outw.nAvgBytesPerSec=outw.nSamplesPerSec*outw.nBlockAlign; outw.cbSize=0;
  DMO_MEDIA_TYPE ot{};
  ot.majortype=kMEDIATYPE_Audio; ot.subtype=kMEDIASUBTYPE_PCM;
  ot.bFixedSizeSamples=TRUE; ot.bTemporalCompression=FALSE; ot.lSampleSize=outw.nBlockAlign;
  ot.formattype=kFORMAT_WaveFormatEx; ot.cbFormat=sizeof(WAVEFORMATEX); ot.pbFormat=(BYTE*)&outw;
  hr = dmo->SetOutputType(0,&ot,0);
  if(FAILED(hr)){ dmo->Release(); if(uninit) CoUninitialize(); return fail("SetOutputType",hr); }

  DWORD outSize=0, outAlign=0;
  if(FAILED(dmo->GetOutputSizeInfo(0,&outSize,&outAlign)) || outSize==0) outSize = 64*1024;
  std::vector<BYTE> obuf(outSize);
  RtMediaBuffer outMB(obuf.data(),(DWORD)obuf.size(),0);

  auto drain=[&](void){
    for(;;){
      outMB.SetLength(0);
      DMO_OUTPUT_DATA_BUFFER db{}; db.pBuffer=&outMB; db.dwStatus=0;
      DWORD status=0;
      HRESULT h2 = dmo->ProcessOutput(0,1,&db,&status);
      if(FAILED(h2)) break;
      BYTE* p=nullptr; DWORD n=0;
      outMB.GetBufferAndLength(&p,&n);
      if(n>=2) out.insert(out.end(),(const int16_t*)p,(const int16_t*)(p+(n & ~1u)));
      if(h2==S_FALSE && n==0) break;
      if(!(db.dwStatus & DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE)) break;
    }
  };

  size_t packets_in=0;
  for(size_t off=0; off+(size_t)blockAlign<=bytes; off+=(size_t)blockAlign){
    RtMediaBuffer inMB(const_cast<BYTE*>(packets+off),(DWORD)blockAlign,(DWORD)blockAlign);
    HRESULT h2 = dmo->ProcessInput(0,&inMB,0,0,0);
    if(h2==DMO_E_NOTACCEPTING){ drain(); h2 = dmo->ProcessInput(0,&inMB,0,0,0); }
    if(FAILED(h2)){ dmo->Release(); if(uninit) CoUninitialize(); return fail("ProcessInput",h2); }
    packets_in++;
    drain();
  }
  dmo->Discontinuity(0);
  drain();
  dmo->Release();
  if(uninit) CoUninitialize();
  if(out.empty()) return fail("decoder produced 0 samples",0);
  (void)packets_in;
  return 0;
}
#endif // _WIN32

// Decode one .xwb entry. On success *outPcm is a malloc'd interleaved LE PCM16 block of
// (*outFrames * *outChans) samples at the bank's NATIVE rate (44100 for SE/VOICE, 48000 for
// SYS_SE) — no resampling here; the consumer decides (the guest has per-voice resamplers, the
// host bridge resamples to the 48k frame ABI).
extern "C" int rt_xwma_decode_xwb_entry(const char* path, int waveIdx,
                                        int16_t** outPcm, size_t* outFrames,
                                        int* outChans, int* outRate){
  if(outPcm) *outPcm=nullptr; if(outFrames) *outFrames=0;
  RtXwbEntry e;
  if(rt_xwb_read_entry(path,waveIdx,&e)!=0) return -1;
  if(e.tag!=3){ std::fprintf(stderr,"[xwma] %s entry %d is tag=%d (not xWMA)\n",path,waveIdx,e.tag); return -2; }
  if(e.chans<1 || e.chans>2 || e.play_len==0) return -3;
#ifndef _WIN32
  std::fprintf(stderr,"[xwma] no host decoder backend on this platform\n");
  return -9;
#else
  std::vector<uint8_t> raw(e.play_len);
  FILE* f=std::fopen(path,"rb"); if(!f) return -4;
  if(std::fseek(f,(long)e.abs_off,SEEK_SET)!=0 || std::fread(raw.data(),1,raw.size(),f)!=raw.size()){
    std::fclose(f); return -5;
  }
  std::fclose(f);
  std::vector<int16_t> pcm;
  pcm.reserve((size_t)e.dur_samples*(size_t)e.chans + 4096);
  char err[160]={0};
  if(rx_dmo_decode(raw.data(),raw.size(),e.chans,e.rate,e.block_align,e.avg_bytes,pcm,err,sizeof err)!=0){
    std::fprintf(stderr,"[xwma] decode FAILED %s entry %d: %s\n",path,waveIdx,err);
    return -6;
  }
  size_t frames = pcm.size()/(size_t)e.chans;
  int16_t* buf = (int16_t*)std::malloc(pcm.size()*sizeof(int16_t));
  if(!buf) return -7;
  std::memcpy(buf,pcm.data(),pcm.size()*sizeof(int16_t));
  if(outPcm) *outPcm=buf; else std::free(buf);
  if(outFrames) *outFrames=frames;
  if(outChans)  *outChans=e.chans;
  if(outRate)   *outRate=e.rate;
  return 0;
#endif
}

extern "C" void rt_xwma_free(int16_t* p){ std::free(p); }

// ================================================================================================
// .xsb (XACT3 SoundBank) PARSER — 2026-07-31 BETA AUDIO leg.
//
// WHY THIS EXISTS (the defect it fixes): everything upstream of the host bridge deals in CUE
// INDICES, not wave indices. The game's cue table 0x885C5D14 stores a SOUNDBANK CUE INDEX, and the
// shell's SoundBank::Prepare (sub_820EEE00) takes a cue index too — its own bounds check reads
// numSimpleCues at xsb+0x13 / numComplexCues at xsb+0x15, which is how we know the object it holds
// is the verbatim .xsb image (four independent header fields match: +0x13, +0x15, +0x22 simple-cue
// table, +0x26 complex-cue table; see FUN_820eee00 / FUN_820f0d18 / FUN_820f0d78 in the shell
// decomp). The bridge has been treating that index as a .xwb WAVE index. Measured from the shipped
// banks, that identity assumption is WRONG:
//     BGM.xsb   cue2 -> wave 11, cue3 -> wave 2, cue4 -> wave 3 ... (11 of 13 cues mis-map)
//     SYS_SE    cue0 -> wave 6, cue1 -> wave 5, ... cue6 -> wave 0  (fully REVERSED)
//   (SE and VOICE happen to be identity, which is why the 07-29 leg's decodes all looked right.)
//
// Layout — every offset below is read out of the shipped files, not guessed:
//   0x00 'KBDS'            magic (reversed 'SDBK', like the .xwb's 'DNBW')
//   0x13 u16 numSimpleCues     0x15 u16 numComplexCues      0x1b u8 numWaveBanks
//   0x1c u16 numSounds
//   0x22 u32 simpleCuesOffset  0x26 u32 complexCuesOffset (0xFFFFFFFF when none)
//   0x2a u32 cueNamesOffset    0x3a u32 waveBankNameTableOffset (64-byte entries)
//   0x42 u32 cueNameIndexOffset  -> { u32 nameOffset; u16 hashNext } per cue, IN CUE-INDEX ORDER
//   simple cue  =  5 bytes { u8 flags; u32 soundOffset }
//   complex cue = 15 bytes { u8 flags; u32 soundOffset; ... }
//   sound       =  { u8 flags; u16 category; u8 volume; u16 pitch; u16 ?; u8 size; ... }
//                  size is at +8. flags bit0 CLEAR => 12-byte "simple sound": wave u16 @+9,
//                  waveBank u8 @+11. flags bit0 SET => clip/event sound: the trailing PlayWave
//                  event carries wave u16 @ size-8 and waveBank u8 @ size-6.
//   Verified end-to-end: SYS_SE cue names (BGM_Sample/SE_OK01/SE_Cancel02/SE_Cancel01/SE_Select02/
//   SE_Select01/SE_OK02) line up 1:1 with the reversed wave map, and SYS_SE wave 6 — the one
//   "BGM_Sample" points at — is the longest/loudest entry in the bank (4.01 s, rms 6961, 100%
//   nonzero) exactly as a music sample should be.
//
// Every parsed wave index is RANGE-CHECKED against the referenced .xwb's real entry count; a bank
// that fails the check falls back to identity and says so, so a layout surprise degrades to the
// old behaviour instead of playing garbage.
// ================================================================================================
extern "C" {
typedef struct RtXsbCue {
  int  waveIndex;
  int  waveBankIndex;
  int  fromXsb;          // 1 = parsed, 0 = identity fallback
  const char* name;      // cue name (points into the cached bank image; never freed)
  int  category;         // XACT category index (sound record +1, u16) -> sound.xgs table
  int  loopInfinite;     // 1 = event sound (flags bit0 set, size>=36) whose PlayWave carries
                         // XACT's 0xFF infinite-loop marker; 0 = one-shot 12-byte simple sound.
                         // Split verified against the shipped banks: m05_govr (game over) is the
                         // ONLY size-12 cue in BGM.xsb, and the L-named SE are all size-36.
  float volume;          // ★ 2026-08-01 per-sound authored volume as LINEAR gain. Sound record
                         // byte +3 (after flags u8 + category u16), decoded with the exact XACT
                         // builder curve (FAudio FACT_internal.c read_volbyte, the reference
                         // XACT reimplementation): dB*100 = 3969*log10(byte/28240)+8715, then
                         // 10^(dB100/2000). Shipped SE range: byte 160..243 -> 0.79x..1.82x.
} RtXsbCue;
int         rt_xsb_bank_count(void);
const char* rt_xsb_bank_name(int i);
// Identify a resident SoundBank image by its first bytes. Exact prefix match first (the shell maps
// the .xsb verbatim), then a (numSimpleCues,numComplexCues) fallback — that pair is unique across
// the five shipped banks. Returns the bank's basename ("SYS_SE") or nullptr.
const char* rt_xsb_identify(const unsigned char* hdr, int len);
// cueIndex -> wave. Returns 0 on success. bankName is the .xsb basename.
int         rt_xsb_cue(const char* bankName, int cueIndex, RtXsbCue* out);
// The .xwb basename this soundbank's waves live in (wave-bank name table entry).
const char* rt_xsb_wavebank(const char* bankName, int waveBankIndex);
}

static inline uint16_t rx_be16(const uint8_t* p){ return (uint16_t)(((uint32_t)p[0]<<8)|p[1]); }

struct RtXsbBank {
  std::string          name;       // basename, e.g. "SYS_SE"
  std::vector<uint8_t> img;        // whole file (all five are < 5 KB)
  std::vector<RtXsbCue> cues;
  std::vector<std::string> wbnames;
  int ns=0, nc=0;
  bool parsed=false, ok=false;
};

// The five banks the game ships. Order is only for logging.
static const char* kXsbNames[] = { "BGM", "SE", "VOICE", "SYS_SE", "SYS_BGM" };
static const int   kXsbCount   = 5;

static void rx_sound_dir(char* out, size_t n){
  const char* root = getenv("RT_GAME_ROOT");
  if(root) std::snprintf(out,n,"%s/media/Sound",root);
  else     std::snprintf(out,n,"%s","assets/media/Sound");
}

static std::vector<RtXsbBank>& rx_banks(){
  // CODE_REVIEW_0804 MED-11: population is once-guarded now — `if(v.empty())` let two guest
  // threads dispatching cues concurrently both populate (vector reallocation UB). C++ only
  // guarantees thread-safe INITIALIZATION of the static, not the lazy fill.
  static std::vector<RtXsbBank> v;
  static std::once_flag vOnce;
  std::call_once(vOnce, []{
  if(v.empty()){
    char dir[1024]; rx_sound_dir(dir,sizeof dir);
    for(int i=0;i<kXsbCount;i++){
      RtXsbBank b; b.name = kXsbNames[i];
      char p[1200]; std::snprintf(p,sizeof p,"%s/%s.xsb",dir,kXsbNames[i]);
      FILE* f=std::fopen(p,"rb");
      if(f){
        std::fseek(f,0,SEEK_END); long sz=std::ftell(f); std::fseek(f,0,SEEK_SET);
        if(sz>0x50 && sz<1<<20){ b.img.resize((size_t)sz);
          if(std::fread(b.img.data(),1,b.img.size(),f)!=b.img.size()) b.img.clear(); }
        std::fclose(f);
      }
      v.push_back(std::move(b));
    }
  }
  });
  return v;
}

// Parse one bank's cue table. Idempotent.
static void rx_xsb_parse(RtXsbBank& b){
  if(b.parsed) return;
  b.parsed = true;
  const uint8_t* d = b.img.data(); size_t n = b.img.size();
  if(n < 0x50 || std::memcmp(d,"KBDS",4)!=0){
    std::fprintf(stderr,"[xsb] %s: missing or not a SoundBank (%zu bytes)\n",b.name.c_str(),n);
    return;
  }
  b.ns = (int)rx_be16(d+0x13);
  b.nc = (int)rx_be16(d+0x15);
  uint32_t simpleOff = rx_be32(d+0x22), cplxOff = rx_be32(d+0x26);
  uint32_t wbnOff    = rx_be32(d+0x3a), nameIdx = rx_be32(d+0x42);
  int      nwb       = (int)d[0x1b];
  for(int i=0;i<nwb;i++){
    uint32_t o = wbnOff + (uint32_t)i*64u;
    if(o+64<=n){ char t[65]; std::memcpy(t,d+o,64); t[64]=0; b.wbnames.push_back(t); }
    else b.wbnames.push_back(b.name);           // degrade to "same name as the soundbank"
  }
  if(b.wbnames.empty()) b.wbnames.push_back(b.name);
  // Range-check parsed wave indices against the real .xwb entry count (0 = "unknown, skip check").
  char wbpath[1200], dir[1024]; rx_sound_dir(dir,sizeof dir);
  std::snprintf(wbpath,sizeof wbpath,"%s/%s.xwb",dir,b.wbnames[0].c_str());
  int wbEntries = rt_xwb_entry_count(wbpath);

  int total = b.ns + b.nc, bad = 0;
  for(int i=0;i<total;i++){
    RtXsbCue c{ i, 0, 0, nullptr, -1, 0, 1.0f };
    uint32_t so = 0;
    if(i < b.ns){ uint32_t o = simpleOff + (uint32_t)i*5u + 1u;      if(o+4<=n) so = rx_be32(d+o); }
    else        { uint32_t o = cplxOff + (uint32_t)(i-b.ns)*15u + 1u; if(o+4<=n) so = rx_be32(d+o); }
    if(so && (size_t)so+9 <= n){
      const uint8_t* r = d + so;
      uint32_t sz = r[8];
      if((size_t)so + sz <= n && sz >= 12){
        // Category index (sound record +1, u16) -> the sound.xgs table shared by ALL five banks:
        //   0 Global 1 Default 2 Music 3 BGM 4 SE 5 VOICE 6 SYS_BGM 7 SYS_SE
        // Verified 5/5 against the shipped banks, and it is the same index space the engine's
        // SetVolume(category) calls use.
        c.category = (int)rx_be16(r+1);
        // Per-sound authored volume (byte at +3; see RtXsbCue::volume for the exact curve).
        // byte 0 would be -inf dB; treat as authored-silent.
        if(r[3]) c.volume = std::pow(10.0f,(3969.0f*std::log10((float)r[3]/28240.0f)+8715.0f)/2000.0f);
        else     c.volume = 0.0f;
        if(!(r[0] & 1)){                       // simple sound: wave ref inline -> ONE-SHOT
          c.waveIndex = (int)rx_be16(r+9); c.waveBankIndex = (int)r[11]; c.fromXsb = 1;
          c.loopInfinite = 0;
        } else if(sz >= 16){                   // clip/event sound: trailing PlayWave event
          c.waveIndex = (int)rx_be16(r+sz-8);  c.waveBankIndex = (int)r[sz-6]; c.fromXsb = 1;
          c.loopInfinite = 1;                  // see RtXsbCue::loopInfinite for the evidence
        }
      }
    }
    if(c.fromXsb && wbEntries > 0 && (c.waveIndex < 0 || c.waveIndex >= wbEntries)){
      ++bad; c.fromXsb = 0; c.waveIndex = i; c.waveBankIndex = 0;   // out of range -> identity (category kept)
    }
    // cue name (index-ordered {u32 nameOffset; u16 hashNext} table)
    uint32_t no = nameIdx + (uint32_t)i*6u;
    if(nameIdx && (size_t)no+4 <= n){
      uint32_t s = rx_be32(d+no);
      if((size_t)s < n && d[s]) c.name = (const char*)(d+s);
    }
    b.cues.push_back(c);
  }
  b.ok = (bad == 0) && !b.cues.empty();
  int mapped=0; for(auto& c : b.cues) if(c.fromXsb) ++mapped;
  std::fprintf(stderr,"[xsb] %s: %d cues (%d simple + %d complex) -> waveBank '%s' (%d entries); "
                      "%d/%zu cue->wave mapped from the bank%s\n",
    b.name.c_str(),total,b.ns,b.nc,b.wbnames[0].c_str(),wbEntries,mapped,b.cues.size(),
    bad? "  [WARN some out of range -> identity fallback]":"");
}

static RtXsbBank* rx_find(const char* name){
  if(!name) return nullptr;
  for(auto& b : rx_banks()) if(b.name == name){ rx_xsb_parse(b); return &b; }
  return nullptr;
}

extern "C" int rt_xsb_bank_count(void){ return kXsbCount; }
extern "C" const char* rt_xsb_bank_name(int i){ return (i>=0&&i<kXsbCount)?kXsbNames[i]:nullptr; }

extern "C" const char* rt_xsb_identify(const unsigned char* hdr, int len){
  if(!hdr || len < 0x17) return nullptr;
  auto& v = rx_banks();
  // 1) exact prefix match — the shell maps the .xsb bytes verbatim, so this should always hit.
  int cmpLen = len < 32 ? len : 32;
  for(auto& b : v)
    if(b.img.size() >= (size_t)cmpLen && std::memcmp(b.img.data(),hdr,(size_t)cmpLen)==0)
      return b.name.c_str();
  // 2) fallback: (numSimpleCues,numComplexCues) — unique across the five shipped banks
  //    (13/0, 70/0, 134/0, 1/6, 1/0). Logged once so a live divergence is visible.
  uint16_t ns = rx_be16(hdr+0x13), nc = rx_be16(hdr+0x15);
  for(auto& b : v){
    if(b.img.size() < 0x17) continue;
    if(rx_be16(b.img.data()+0x13)==ns && rx_be16(b.img.data()+0x15)==nc){
      static int warned=0;
      if(!warned++) std::fprintf(stderr,"[xsb] identify: prefix mismatch, matched %s by cue counts (%u/%u)\n",
                                 b.name.c_str(),ns,nc);
      return b.name.c_str();
    }
  }
  return nullptr;
}

extern "C" int rt_xsb_cue(const char* bankName, int cueIndex, RtXsbCue* out){
  if(!out) return -1;
  out->waveIndex = cueIndex; out->waveBankIndex = 0; out->fromXsb = 0; out->name = nullptr;
  out->category = -1; out->loopInfinite = 0; out->volume = 1.0f;
  RtXsbBank* b = rx_find(bankName);
  if(!b || b->cues.empty()) return -2;
  if(cueIndex < 0 || (size_t)cueIndex >= b->cues.size()) return -3;
  *out = b->cues[(size_t)cueIndex];
  return 0;
}

// PCM entry geometry for the host bridge's streamer — replaces the bridge's own truncated
// 2 KB header peek (which could not even reach VOICE.xwb's 3216-byte metadata segment) and
// hands over the LOOP REGION, which the bridge previously ignored (it looped the whole
// PlayRegion; BGM entry0's real loop is [66053, +1396363] samples = "play the intro once,
// then loop the body").  Sample units, exactly as stored. Returns 0 on success.
extern "C" int rt_xwb_pcm_info(const char* path,int waveIdx,
                               unsigned* absOff,unsigned* len,int* chans,int* rate,int* tag,
                               unsigned* loopStartSamples,unsigned* loopTotalSamples){
  RtXwbEntry e;
  if(rt_xwb_read_entry(path,waveIdx,&e)!=0) return -1;
  if(absOff) *absOff=e.abs_off;
  if(len)    *len=e.play_len;
  if(chans)  *chans=e.chans?e.chans:2;
  if(rate)   *rate=e.rate?e.rate:48000;
  if(tag)    *tag=e.tag;
  if(loopStartSamples) *loopStartSamples=e.loop_start;
  if(loopTotalSamples) *loopTotalSamples=e.loop_total;
  return 0;
}

extern "C" const char* rt_xsb_wavebank(const char* bankName, int waveBankIndex){
  RtXsbBank* b = rx_find(bankName);
  if(!b || b->wbnames.empty()) return bankName;
  if(waveBankIndex < 0 || (size_t)waveBankIndex >= b->wbnames.size()) return b->wbnames[0].c_str();
  return b->wbnames[(size_t)waveBankIndex].c_str();
}

// ---------------------------------------------------------------- offline tool
#ifdef RT_XWMA_MAIN
static void write_wav16(const char* out, const int16_t* pcm, size_t frames, int chans, int rate){
  FILE* f=std::fopen(out,"wb"); if(!f){ std::fprintf(stderr,"cannot write %s\n",out); return; }
  uint32_t dbytes=(uint32_t)(frames*(size_t)chans*2);
  uint32_t riff=36+dbytes, fmtsz=16, brate=(uint32_t)(rate*chans*2);
  uint16_t fmt=1, ch=(uint16_t)chans, bits=16, align=(uint16_t)(chans*2);
  uint32_t srate=(uint32_t)rate;
  std::fwrite("RIFF",1,4,f); std::fwrite(&riff,4,1,f); std::fwrite("WAVEfmt ",1,8,f);
  std::fwrite(&fmtsz,4,1,f); std::fwrite(&fmt,2,1,f); std::fwrite(&ch,2,1,f);
  std::fwrite(&srate,4,1,f); std::fwrite(&brate,4,1,f); std::fwrite(&align,2,1,f);
  std::fwrite(&bits,2,1,f); std::fwrite("data",1,4,f); std::fwrite(&dbytes,4,1,f);
  std::fwrite(pcm,2,frames*(size_t)chans,f); std::fclose(f);
}
int main(int argc,char** argv){
  if(argc<2){ std::fprintf(stderr,"usage: %s <bank.xwb> [entryIdx out.wav]   |   %s xsb [bankName]\n",argv[0],argv[0]); return 1; }
  // `xsb` mode: dump the cue->wave map of every SoundBank (offline acceptance for the .xsb parser;
  // needs RT_GAME_ROOT or a cwd with assets/media/Sound).
  if(std::strcmp(argv[1],"xsb")==0){
    int rc=0;
    for(int i=0;i<rt_xsb_bank_count();i++){
      const char* bn = rt_xsb_bank_name(i);
      if(argc>2 && std::strcmp(argv[2],bn)!=0) continue;
      const char* wb = rt_xsb_wavebank(bn,0);
      char wpath[1200]; { char dir[1024]; rx_sound_dir(dir,sizeof dir);
                          std::snprintf(wpath,sizeof wpath,"%s/%s.xwb",dir,wb); }
      int entries = rt_xwb_entry_count(wpath);
      std::printf("== %s.xsb -> %s.xwb (%d entries)\n",bn,wb,entries);
      int ident=0, mapped=0, n=0;
      for(int c=0;;c++){
        RtXsbCue q;
        if(rt_xsb_cue(bn,c,&q)!=0) break;
        ++n; if(q.fromXsb) ++mapped; if(q.waveIndex==c) ++ident;
        RtXwbEntry e; int tag=-1;
        if(entries>0 && q.waveIndex<entries && rt_xwb_read_entry(wpath,q.waveIndex,&e)==0) tag=e.tag;
        std::printf("   cue%-4d %-18s -> wave %-4d bank %d  tag=%d %s%s\n",
          c, q.name?q.name:"(unnamed)", q.waveIndex, q.waveBankIndex, tag,
          q.fromXsb?"":"[IDENTITY-FALLBACK]", (q.waveIndex!=c)?"  <<< NOT identity":"");
      }
      std::printf("   %d cues, %d parsed from the bank, %d coincide with identity\n",n,mapped,ident);
      if(n==0) rc=2;
    }
    return rc;
  }
  const char* path=argv[1];
  int n=rt_xwb_entry_count(path);
  if(n<0){ std::fprintf(stderr,"cannot parse %s\n",path); return 1; }
  if(argc<4){
    std::printf("bank=%s entries=%d\n",path,n);
    int tags[4]={0,0,0,0};
    for(int i=0;i<n;i++){
      RtXwbEntry e; if(rt_xwb_read_entry(path,i,&e)!=0) continue;
      if(e.tag>=0&&e.tag<4) tags[e.tag]++;
      if(i<8||n<=8)
        std::printf("  entry[%3d] tag=%d ch=%d %6dHz blkIdx=%3d blk=%5d avg=%6d play=[0x%X,%u] "
                    "pkts=%.2f durSamp=%u dpdsLast=%llu\n",
          i,e.tag,e.chans,e.rate,e.block_index,e.block_align,e.avg_bytes,e.play_off,e.play_len,
          e.block_align? (double)e.play_len/(double)e.block_align : 0.0,
          e.dur_samples,(unsigned long long)e.dpds_last);
    }
    std::printf("  tag histogram: PCM=%d XMA=%d ADPCM=%d xWMA=%d\n",tags[0],tags[1],tags[2],tags[3]);
    return 0;
  }
  int idx=std::atoi(argv[2]); const char* out=argv[3];
  RtXwbEntry e; if(rt_xwb_read_entry(path,idx,&e)!=0){ std::fprintf(stderr,"bad entry\n"); return 1; }
  int16_t* pcm=nullptr; size_t frames=0; int ch=0,rate=0;
  if(rt_xwma_decode_xwb_entry(path,idx,&pcm,&frames,&ch,&rate)!=0){ std::fprintf(stderr,"DECODE FAILED\n"); return 2; }
  double peak=0, acc=0; size_t nz=0, total=frames*(size_t)ch;
  for(size_t i=0;i<total;i++){ double v=pcm[i]; acc+=v*v; if(std::fabs(v)>peak) peak=std::fabs(v); if(pcm[i]) nz++; }
  double rms = total? std::sqrt(acc/(double)total) : 0.0;
  write_wav16(out,pcm,frames,ch,rate);
  std::printf("DECODED %s entry %d -> %s\n",path,idx,out);
  std::printf("  in : tag=%d %dch %dHz blockAlign=%d avgBytes=%d playLen=%u (%u packets)\n",
              e.tag,e.chans,e.rate,e.block_align,e.avg_bytes,e.play_len,
              e.block_align?e.play_len/(unsigned)e.block_align:0);
  std::printf("  out: %zu frames %dch %dHz = %.3f s ; bytes=%zu dpdsLast=%llu (delta=%lld)\n",
              frames,ch,rate,(double)frames/(double)(rate?rate:1),total*2,
              (unsigned long long)e.dpds_last,(long long)(total*2)-(long long)e.dpds_last);
  std::printf("  hdr durSamples=%u (%.3f s)  decoded/expected=%.4f\n",
              e.dur_samples,(double)e.dur_samples/(double)(rate?rate:1),
              e.dur_samples? (double)frames/(double)e.dur_samples : 0.0);
  std::printf("  stats: peak=%.0f rms=%.1f nonzero=%zu/%zu (%.1f%%)\n",
              peak,rms,nz,total,total?100.0*(double)nz/(double)total:0.0);
  rt_xwma_free(pcm);
  return (rms>1.0 && frames>0) ? 0 : 3;
}
#endif
