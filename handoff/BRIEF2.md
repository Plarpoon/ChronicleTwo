# Survey brief 2: per-unit DATA boundaries, Dark Chronicle (PAL)

A previous survey fixed the translation units (TUs) of `.text`. Now every non-text section must be
divided among those same units so a splat config can give each unit its `.data`, `.rodata`, `.sdata`,
`.sbss`, `.bss` (and static-init / vtable) ranges. You survey ONE section group and report; a
coordinator collates. Read-only research: do NOT edit either repository. Write only under the scratchpad.

## Inputs (scratchpad = `/private/tmp/claude-501/-Users-aarongauntlett-Development-chronicletwo/d95f929c-3637-4ad5-93fc-76b03211c79f/scratchpad/`)
- ELF: `/Users/aarongauntlett/Development/chronicletwo/rom/pal/extracted/iso/SCES_511.90` (section `main`: vaddr 0x100000 at file offset 0x80, size 0x27cd80; file_off = vaddr - 0xfff80). No objdump; use python3 + struct.
- `symtab.txt` — symbol table in symtab order: `index value(hex8) size(hex) type bind section name` (bind 13 = MWCC vague linkage).
- `relocs_fixed.txt` — relocations: `vaddr(hex8) type symtab_index` (2=R_MIPS_32, 4=R_MIPS_26, 5=HI16, 6=LO16, 7=GPREL16). Addresses here are correct virtual addresses.
- `units.tsv` — THE FIXED UNIT LIST in link order: `index text_start text_end unit name_source confidence`. Units `crt0` and `lib/...` are library objects (already done — see `out_lib_data.tsv`); all others are MWCC game units. Unit order in every section equals this order.
- Earlier findings you should reuse rather than redo: `out_sections.md` (section map, notes), `out_sections_data.tsv` (first-pass per-group data ranges, with ~45 `AMBIGUOUS START` rows), scripts in `sec/`; and the `# NOTES` parts of `out_A1.tsv`, `out_A2.tsv`, `out_A3.tsv`, `out_B1.tsv`, `out_B2.tsv`, which list each unit's local data ranges per section.

## Section map
.data 0x32a320–0x363480 (library part ends 0x338080; game from 0x338080) · .vudata 0x363480–0x363580 ·
.rodata 0x363580–0x379680 (library to 0x366cb0; game A 0x366cb0–0x3728a0; libgcc 0x3728a0–0x372ca0; game B 0x372ca0–0x379680, content ends ~0x37961b) ·
.rdata 0x379680–0x37c700: `__sinit_*` code 0x379680–0x37afe0, `__static_init` table 0x37afe0–0x37b0a4 (pad to 0x37b0b0), vtables 0x37b0b0–0x37c6f0, `_overlay_group_addresses` 0x37c6f0 ·
.sdata 0x37c700–0x37cd80 · .sbss 0x37cd80–0x37ead5 · .bss 0x37ead5–0x1f64a00 (library to 0x385ec0; game A 0x385ec0–0x1f35080; libgcc 0x1f35080–0x1f350c0; game B 0x1f350c0–0x1f649d0; `errno` 0x1f649d0).
Game part A = units from `mg_texture` through `sceneload`; part B = `filesocket` through `convviewlp`.

## Facts established
- MWCC local symbols (statics, `@N`, `name$N`) are grouped per unit in the symtab, units in link order; each unit's locals occupy an ascending, disjoint address range in every section.
- `@N`/`$N` numbers rise with address inside a unit; a big drop marks a new unit.
- A function referencing a LOCAL symbol is in the unit owning that local, so a local's unit = the unit (from units.tsv) of the functions that reference it. This anchors every local exactly.
- Global objects have no such grouping: a global lying between the last local of unit X and the first local of a later unit Y may belong to X, Y, or any unit in between (units with no locals can still own global data). This is what must be resolved.

## Evidence to use for globals in gaps (state which you used per boundary)
1. Monotone order: the assignment must be non-decreasing in unit index with address.
2. Who references it: collect, per global, the units of the functions that reference it via relocations (HI16/LO16/GPREL16/R_MIPS_32 from data). The defining unit is very often the heaviest or the only referrer; `__sinit_<unit>.cpp` functions initialising an object is strong evidence that the object is defined in that unit.
3. Name/class affinity (e.g. an object of class CFoo next to unit holding CFoo's methods; `__vt__` → class's unit), and DC1 knowledge in `/Users/aarongauntlett/Development/chronicle` (`config/pal/main.yaml`, `src/ps2/*.cpp`, `include/`) for same-named globals.
4. Alignment padding / zero gaps and symbol sizes: MWCC aligns each unit's section contribution (typically to 8 or 16); a jump in alignment or padding larger than the next symbol needs suggests a unit boundary.
5. Initialised-data contents (pointers inside a .data object to functions/strings of a known unit — R_MIPS_32 relocs inside the object).
6. Bytes not covered by any symbol: attribute by the above; unreferenced leading padding goes to the preceding unit.

## Required output
A TSV at the path named in your task: `section  start(hex)  end(hex, exclusive)  unit  confidence(high|med|low)  evidence`,
sorted by address, covering your section range(s) completely with no gaps or overlaps, `unit` exactly as spelled in units.tsv,
unit order non-decreasing. A unit may be absent from a section (owns nothing there). Start addresses must be symbol addresses
(or the section/part start). Below a `# NOTES` line list every boundary that is uncertain with the alternative(s), and any
symbol whose owner you could not determine. Verify with a script before finishing: (a) full coverage, (b) monotone unit order,
(c) every local symbol lies in the range of the unit whose functions reference it — report the count of violations (should be 0).
Final message: brief summary (row count, number of low/med boundaries, violations).
