# Dark Chronicle (PAL, SCES_511.90): non-text layout of `main`, 0x325c80 to 0x1f64a00

Inputs: the ELF section headers, `symtab.txt`, and `relocs.txt`. relocs.txt addresses are listed 0x100000 too high, and all analysis here subtracts that. I also read the raw `.mwcats`, `.comment` and `.reginfo` bytes. Scripts are in `scratchpad/sec/` (`gen.py` produces the TSV).
File offset = vaddr - 0x100000 + 0x80. The PT_LOAD segment has filesz 0x27cd80 (image ends at vaddr 0x37cd80, which is `_fbss`) and memsz 0x1e64a00 (ends at 0x1f64a00 = `_end` = `__bss_end`). The ELF also has an empty `heap` section at 0x1f64a00.

## 1. Section map

Linker-defined symbols: `__data_start`=0x32a320, `__data_size`=0x523d4, `__data_end`=0x37c6f4, `__static_init`=0x37afe0, `__static_init_end`=0x37b0a4, `__exception_table_start__`=`__exception_table_end__`=0x37c6f0 (the table is empty), `_overlay_group_addresses`=0x37c6f0, `_fbss`=0x37cd80, `__bss_start`=0x37ead5, `__bss_size`=0x1be5f2b, `__bss_end`=`_end`=`end`=0x1f64a00, `_gp`=0x3846f0 (= 0x37c6f0 + 0x8000), `_stack`=0x1f80000, `_stack_size`=0x80000, `_heap_size`=0xffffffff.

| range | contents | evidence |
|---|---|---|
| 0x100000–0x325c80 | .text | (already established) |
| 0x325c80–0x32a320 | .vutext: 6 VU microcode runs from 5 dvp-as objects. Their `.vutext` SECTION syms are at 0x325c80, 0x326350, 0x326cc0, 0x326f90 and 0x329fd0. The last label is `.vif.12` at 0x32a318. | `.vutext` SECTION symbols |
| 0x32a320–0x363480 | .data. Content ends at 0x363440 (`@1074`+0x80, convviewlp); zero pad to the 0x80 boundary. | `__data_start` |
| 0x32a320–0x32a380 | Probably crt0's `.data`: 0x60 zero bytes with no symbols and no relocation targets. DC1's crt0 .data is 0x40 zero bytes. | |
| 0x32a380–0x32a3a0 | MW C++ runtime .data: `_new_handler_func__3std`, `__throws_bad_alloc__3std`, `thandler__3std`, `uhandler__3std` | |
| 0x32a3a0–0x338080 | GCC SDK/libc objects' .data, in text link order | per-object `.data` SECTION syms |
| 0x338080–0x363440 | MWCC game .data (TU part A, then part B) | local runs |
| 0x363480–0x363580 | .vudata (one VU object, `My_dma_start0`, `My_DrawEnv`; 0x100 bytes, the same size as DC1's) | `.vudata` SECTION sym |
| 0x363580–0x379680 | .rodata. In order: the MW runtime (0x363580–0x363808), the GCC objects (first SECTION sym 0x363808 through 0x366cb0), game part A (0x366cb0–0x3728a0), libgcc (0x3728a0–0x372ce0), then game part B (0x372ce0–0x37961b). Zero pad 0x37961b–0x379680 (ALIGN 0x80). | |
| 0x379680–0x37afe0 | .init: 49 `__sinit_<file>.cpp` functions, each 0x10-aligned, in TU order. The last ends at 0x37afdc. What precedes it is only the rodata ALIGN(0x80) zero pad; there is no literal pool or other data between them. | `.mwcats` code records continue into this range |
| 0x37afe0–0x37b0a4 | .ctor: the `__static_init` table, 49 x 4 bytes (`.p__sinit_*`), in the same order as .init. Pad to 0x37b0b0. | `__static_init`/`_end` |
| 0x37b0b0–0x37c6f0 | .vtables: 75 vtables (0x14c0 bytes plus 8/16-byte padding), grouped per TU in TU order | see notes |
| 0x37c6f0 | `.exception` table: empty (start == end) | |
| 0x37c6f0–0x37c6f4 | `_overlay_group_addresses`: one word, `0x00100000`. `__data_end` = 0x37c6f4 | |
| 0x37c6f4–0x37c700 | 12 zero bytes. **There is no MWLD literal pool.** DC1 had one at 0x2a8e28–0x2a9500. Here no symbol or relocation targets this gap. | |
| 0x37c700–0x37cd80 | .sdata. Content ends at 0x37cd30 (`@483`); zero pad to the 0x80 boundary (`_fbss`). All gp-relative (R_MIPS_GPREL16) targets lie in 0x37c700–0x37ead5. | GPREL relocs |
| 0x37cd80–0x37ead5 | .sbss. Ends unaligned at `__bss_start` (convviewlp's `init$826`, 1 byte at 0x37ead4). There is an unnamed 0x30 hole at 0x37ea90–0x37eac0 inside convviewlp's run. | |
| 0x37ead5–0x1f64a00 | .bss. Pad to 0x37eb00, where crt0 `.bss`/`_args` (0x144) starts on a 128-byte boundary. Then the GCC library bss (to 0x385ec0), game part A bss (0x385ec0–0x1f35080), libgcc bss (`thenan.3` in dp-bit and fp-bit, 0x1f35080–0x1f350c0), and game part B bss (0x1f350c0–0x1f649d0). Last is `errno` (global, likely COMMON) at 0x1f649d0, padded to 0x1f64a00. | |
| 0x1f64a00 | .vubss: 5 empty SECTION syms (one per VU object) at `_end` | |

The table in the same tuple style as `chronicle/scripts/build/region.py` uses the DC1 convention. That convention makes .rodata end at the start of `.init`, and makes `.rdata` cover init, ctor, vtables, the overlay table and the literal pool, up to .sdata:

```python
"main": (
    (".text",   "text",   0x00100000, 0x00325C80),
    (".vutext", "data",   0x00325C80, 0x0032A320),
    (".data",   "data",   0x0032A320, 0x00363480),
    (".vudata", "data",   0x00363480, 0x00363580),
    (".rodata", "rodata", 0x00363580, 0x00379680),
    (".rdata",  "rdata",  0x00379680, 0x0037C700),  # .init 0x379680, .ctor 0x37afe0, .vtables 0x37b0b0, overlay table 0x37c6f0; no literal pool
    (".sdata",  "sdata",  0x0037C700, 0x0037CD80),
    (".sbss",   "sbss",   0x0037CD80, 0x0037EAD5),
    (".bss",    "bss",    0x0037EAD5, 0x01F64A00),
),
# "literal_pool": none. 0x37c6f4-0x37c700 is padding only (DC1 PAL had {8: (0x2A8E28,0x2A8EF8), 4: (0x2A8EF8,0x2A9500)})
```

Splat `main.yaml` equivalents (file offset = vaddr - 0xfff80):
- `{start: 0x225d00, type: data, name: vutext, linker_section: .vutext}` (vaddr 0x325c80)
- `.data` per-object entries from 0x22a3a0 (vaddr 0x32a320). The crt0 piece is 0x22a3a0 and the MW runtime 0x22a400. Use the `.data` rows of out_sections_data.tsv.
- `{start: 0x263500, type: data, name: vudata, linker_section: .vudata}` (vaddr 0x363480)
- `.rodata` entries from 0x263600 (vaddr 0x363580)
- `{start: 0x279700, type: rdata, name: rdata}` (vaddr 0x379680)
- `{start: 0x27c780, type: sdata, name: sdata}` (vaddr 0x37c700)
- `{start: 0x27ce00, type: sbss, vram: 0x37cd80}`, then the .bss entries at `start: 0x27ce00, vram: 0x37ead5...` (crt0 at vram 0x37eb00)
- `bss_size` = 0x1f64a00 - 0x37cd80 = **0x1be7c80**. This follows DC1's convention of measuring bss_size from `_fbss` (DC1: 0x1dc4000 - 0x2a9a80 = 0x1b1a580).

## 2. `.mwcats`, `.comment`, `.reginfo`

`.mwcats` (sh_type 0xca2a82c2, link=4 `main`, 0xdc48 bytes) is a flat array of 6912 variable-length records, sorted strictly by address:

```
u8  kind     = 2 (code) for every record
u8  flags    bit0: an extra u32 follows
u16 size     function size in bytes; equals the ELF symbol size for every record
u32 address  function start (always a FUNC symbol start)
[u32 extra]  only when flags&1: byte offset, within the function, of a terminal tail-call `j` instruction
```

- flags&1 is set on 274 records. Example: `mwInit` at 0x100190 has size 0x24 and extra 0x1c, and the word at +0x1c is `j`. Size-0xc stubs have extra 4. In every inspected case the extra is the offset of the `j` that ends the function with a tail call. It is probably there so a profiler or debugger can tell a function that ends in `j` from one that ends in `jr ra`.
- Records exist for exactly the MWCC-compiled functions: 6912 = 7788 FUNC symbols below 0x325c80, minus 887 GCC SDK/libc functions (0x102630–0x12c2c0) and 38 libgcc functions (0x289e48–0x28d1d0), plus the 49 `__sinit_*` functions in .init. crt0 (0x100000–0x1000c8) has no records; the first record is 0x1000d0.
- **There is nothing per-object in it.** It has no file names, no separators and no grouping, and it is in pure address order. The only boundaries it reveals are compiler boundaries: the three big gaps in coverage are 0x102630–0x12c2c0 (GCC SDK/libc), 0x289e44–0x28d1d0 (libgcc) and 0x325c60–0x379680 (vutext and data). The padding between consecutive records is always 0, 4, 8 or 0xc zero bytes, so it gives no TU information either. It is useful only to confirm the MW/GCC split and the exact function sizes.

`.comment`: `"MW MIPS C Compiler (2.4.1.01)\0PlayStation2\0"`.
`.reginfo`: ri_gprmask=0xf7fffffe, ri_cprmask={0, 0xffffffff, 0, 0}, ri_gp_value=0x3846f0.

## 3. Per-TU layout of data, rodata, sdata, sbss and bss

**Method.** Local symbols are in the symtab in link order, one contiguous run per object, with the order scrambled inside each run. I computed every "consistent cut" in the local-symbol sequence: a cut at index b is valid when, in every output section, everything before b ends at or below where everything after b starts. Every true object boundary is such a cut. I then merged adjacent cut-groups wherever any function or data object (global or local) references locals in more than one group. I also attributed global containers that lie strictly inside a group's local span. This left 158 groups in the MWCC ranges. GCC objects are handled exactly, through their per-object `.data`/`.rodata`/`.bss` SECTION symbols, each attributed to its object by relocations against the section symbol (103 of 112 SECTION syms). The other 9 belong to data-only objects (or locale.c) and are named from their contents.

**Findings**
- Per-TU data is laid out in the same TU order as text, in every section. GCC objects: the owner object index is strictly increasing with address in .data (27), .rodata (56) and .bss (20). MWCC: the groups are simultaneously ascending in text, data, rodata, sdata, sbss, bss, init and ctor; that is how they were built, and 818 raw cuts exist, so the orders really do agree. libgcc's rodata (0x3728a0–0x372ce0) and bss (0x1f35080–0x1f350c0) sit between game parts A and B, just as its text does. The VU objects' symtab runs (indices 1413–1733, 1910–1928) are interleaved among the game TUs at their link positions.
- GCC library objects have no .sdata/.sbss (0 locals there). In the gp area only MWCC TUs contribute; small initialised data (≤8 bytes, including small `@N` strings and doubles) goes in per-TU .sdata, so there is no pooled literal section.
- `@N` numbers increase with address within one TU's section: 21 inversions in 4751 adjacent pairs, all of them between consecutive numbers. A large drop marks a new TU, for example 0x366d60 `@184` followed by 0x366d80 `@166`. The TSV includes each group's @N range.
- The `.init`, `.ctor`, `.sdata` and `.sbss` orders all follow TU order. The 49 sinit TUs, in order: mg_frame, mg_tanime, mglib, nd_meswin, dbg_font, snd_mngr, mainloop, gamedata, sysmes, userdata, editctrl, editloop, dng_debug, dng_main, dngmenu, editmenu, inventmn, menuaqua, menucls1, menudraw, menumain, menusys, event, event_func, eventedit, dng_event, menushop, title, editdata, menucapt, menumap, menuchr, menuop, movieviewlp, editmode, mapjump, editeff, fishing, subgame, gyorace, nowload, nameregi, photo, fishingobj, pbuggy, helpmes, vlgr_info, mainloop3, convviewlp.
- .vtables also follow TU order. Inside one TU the vtables are not in method-address order: all 15 order inversions among the 48 vtables with own methods pair classes from the same file (mgCCameraFollow/mgCCamera, mgCFrame/mgCObject, CWaterFrame/CWater and so on). Each TU's block is padded to 8 or 16 bytes.
- GCC data-only objects (no `.text` SECTION symbol; the linker apparently drops empty sections' symbols):
  - .data: `_defIQM`/`_defNIQM` (0x334640, libmpeg), `__ps2_klibinfo__` (0x334740, klib), the `_sce_sdr_*` globals (0x335df8, a second sdr object), and `impure_data`/`_impure_ptr` (0x337918, which also has an 8-byte .rodata at 0x366858)
  - .rodata: `__infinity` (0x366118, s_infconst), `__fdlib_version` (0x366120, s_lib_ver), `_ctype_` (0x3666f0, ctype_)

**Output** `out_sections_data.tsv`: 670 rows (.vutext 6, .data 135, .vudata 1, .rodata 183, .init 49, .ctor 49, .sdata 45, .sbss 88, .bss 114).
- `start` is the GCC SECTION symbol, or for MWCC the first local of the group in that section. `end` is the next row's start.
- `tu_hint` is the sinit name if there is one; otherwise `tu@<addr of first local function>`; otherwise `anon(symtab a-b)` for groups that have no local functions. GCC rows give the DC1 library name plus `[obj@text]`, or `obj@text(firstfunc)` where DC1 has no equivalent.
- For MWCC rows, global objects in the gap before the first local make the true start uncertain. Where every gap global is referenced only from one side's local-function text span, I moved the start (5 rows) or confirmed it (4 rows). 45 rows still say `AMBIGUOUS START` and list the globals in the gap; text TU boundaries from the per-slice surveys will settle those.

**Caveats**
- Groups are a lower bound on TU separation, not an exact TU list. A TU whose functions are all global and that has no locals is invisible here; its data, if any, falls inside the previous row's range. A few small `anon` groups could be a false split of a neighbouring TU when no relocation links them. The @N ranges in the evidence column help decide these cases. Example: groups 1268/1269 (`@184`, `@166`) are definitely different TUs from each other.
- GCC names that come from DC1 are by object. DC2 splits some libraries into more objects than DC1's single asmtu (eecdvd appears as obj@11f258, obj@120570 and obj@120970), so the `[obj@...]` suffix is what identifies each one.
