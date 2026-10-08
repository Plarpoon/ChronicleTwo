# mg_texture: native data and hash-table matching

The unit owns texture records, their VRAM upload packets, named texture blocks,
and a chained lookup table. Its layouts and member purposes are documented in
`ps2/include/mg_texture.hpp`.

## Native initialized data

The 0x1B0-byte initialized-data run at 0x338080–0x338230 now comes from ordinary
C++ arrays. Its four pieces remain in retail order and retain their extents and
16-byte placement alignment:

| Symbol | Extent | Meaning |
| --- | --- | --- |
| `texflush_dma` | 0x30 | DMA CNT packet with VIF DIRECT, an A+D GIF tag, and a GS TEXFLUSH write. |
| `lut_1246` | 0x80 | Byte destinations for the alternating columns in `BlockConv32to8`. |
| `block_table8_1266` | 0x80 | Row-major 8-bit block coordinates mapped to GS block numbers. |
| `block_table32_1267` | 0x80 | Row-major 32-bit block coordinates mapped to GS block numbers. |

The byte tables preserve the little-endian ordering of the packet and the lookup
values. Retail ELF binding confirms all four tables are file-local. The block tables
are separate mutable `int[32]` arrays even though their
current values agree; each has its own retail symbol and address. The array
initializers preserve all data bytes, all unit instructions, and all 160
relocations against the prior object. After the normal `fixup_sections.sh` stage
removes MWCC dead sections, `check_objects.py mg_texture --obj-dir
/tmp/engine-satansfiddle -v` reports only the three existing hash-function
instruction differences below.

## Hash lookup

`AddHash`, `DelHash`, and `SearchHash` were checked with `decompile.sh` and m2c.
The bucket links are 8-byte `mgTEXTURE_HASH` records with a texture pointer at
0x00 and next link at 0x04. `hash_table` is the manager's array of 101 bucket heads
at 0x24; `hash_stack` is its separate free-node stack. `AddHash` obtains a free
node and appends it to its name's chain. `DelHash` unlinks the matching texture
and returns that node to the free stack. `SearchHash` compares names and applies
an optional texture-block filter.

Each existing native implementation differs from retail by one commutative
`addu` operand order when forming the bucket address. Retail adds scaled index
then manager base; typed member-array indexing emits base then index. All other
instructions and relocations match. Casts on the index, base, or member array,
unsigned indices, swapped subscript syntax, local manager pointers, and direct
bucket-load expressions did not produce the retail instruction. These functions
remain fuzzy; no zero-difference match is claimed.

## Full-image 32-to-8 conversion analysis

`decompile.sh Conv32To8__FiiPUc` confirms a 64 KiB local static output
workspace and two 8 KiB stack pages. The source-page pitch is
`pages_x * row_bytes`, with 256-byte rows in the temporary 32-bit page;
the destination pitch is `pages_x * width`, with 128-byte rows in the
converted page. The original dimensions determine the final copy size.
One-page images retain their width and half-height source row count;
multi-page images clamp those dimensions to 128 by 64 pixels.

A native candidate with typed array indexing and nested row/column offsets
reproduces the 0x29C-byte body topology and every call/data relocation when
it shares the preceding page converter's optimization-level-2 scope. The
remaining differences are a permutation of four saved registers holding
width, page columns, source row bytes, and the inner row index. Default
optimization level 3 instead emits 0x258 bytes. Merely preserving schedule
off, adding a standard register hint, or separating the input width from
the working width does not close the register allocation difference.
The source fallback remains active; no optimization-setting change is
retained from these trials.
