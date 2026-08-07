import collections, re, sys
sys.path.insert(0, '_tmpscripts')
import l2_seg

L, blocks, decl_owner, users = l2_seg.build()

WATCH = ['GA_DSHIFT', 'GA_FIELD_ACTIVE', 'GA_GM_FRAME_GATE', 'GA_ASSET_COMMIT',
         'GA_MB_RELOAD', 'GA_MB_CREDITED', 'GA_MB_MODE64',
         'GAME_ENTRY_ORD1_VAL', 'GAME_ENTRY_ORD1', 'GAME_MODULE_BASENAME_STR',
         'GAME_MODULE_BASENAME', 'GAME_HMODULE', 'GAME_XSTART', 'RECO_LOADER',
         'GAME_DRIVER', 'MODE_DISPATCH', 'SINGLETON_ADDR', 'CB248_INIT', 'CB248_SINGLETON',
         'rt_heapdump', 'g_game_tick_modectx', 'g_import_calls', 'rt_alloc', 'rt_indirect_call',
         'g_rt_romactive', 'g_rt_menu_heartbeat', 'g_rt_realstage', 'g_game_unloaded',
         'path_is_game', 'path_is_foreign_module', 'str_icontains', 'rt_load_game_data_sections',
         '__imp__sub_821706E8']

# provisional dest per block from the current classifier (pre-override refinement)
for nm in WATCH:
    own = set(decl_owner.get(nm, ()))
    hits = collections.Counter()
    where = []
    for bk in blocks:
        if bk['i'] in own:
            continue
        if nm in bk['refs']:
            hits[bk['fd']] += 1
            where.append(bk['a'])
    print('%-28s owners=%-8s users=%-24s at %s' % (
        nm, [blocks[o]['a'] for o in own], dict(hits), where[:8]))

print()
print('=== abn +8 rename map: which shifted symbols land in which dest ===')
mp = open('out_reco_abn/abn_symbol_map.h', encoding='utf-8', errors='replace').read()
ren = set(re.findall(r'#define\s+(sub_8[0-9A-Fa-f]{7})\s', mp))
print('renamed base syms in map:', len(ren))
cnt = collections.Counter()
detail = collections.defaultdict(list)
for bk in blocks:
    ds = set()
    for r in bk['refs']:
        if r in ren or (r.startswith('__imp__') and r[7:] in ren):
            ds.add(r)
    if ds:
        cnt[bk['fd']] += len(ds)
        detail[bk['fd']].append((bk['a'], sorted(ds)[:3]))
print('blocks referencing a renamed symbol, by dest:', dict(cnt))
for d in sorted(detail):
    print('  %s: %d blocks, first few: %s' % (d, len(detail[d]), detail[d][:4]))
