# Survey brief: Dark Chronicle (PAL) translation-unit boundaries

Goal of the overall job: a splat `main.yaml` for the PS2 game "Dark Chronicle" (PAL, SCES_511.90)
that splits the executable into translation units (TUs). You are surveying ONE slice and
reporting findings; a coordinator collates. This is read-only research: do NOT edit anything in
either repository. Write scratch scripts/outputs only under the scratchpad directory (below).

## Inputs
- ELF (not stripped, relocations kept): `/Users/aarongauntlett/Development/chronicletwo/rom/pal/extracted/iso/SCES_511.90`
  - One loadable section `main`: vaddr 0x100000, file offset 0x80, size 0x27cd80. file_off = vaddr - 0x100000 + 0x80.
  - No objdump/readelf on this machine; use python3 + struct. (`pip install --user capstone` or `rabbitizer` only if you really need disassembly.)
- Scratchpad: `/private/tmp/claude-501/-Users-aarongauntlett-Development-chronicletwo/d95f929c-3637-4ad5-93fc-76b03211c79f/scratchpad/`
  - `symtab.txt` — whole symbol table IN SYMTAB ORDER, tab separated:
    `index  value(hex8)  size(hex)  type  bind  section  name`
    bind: L local, G global, W weak, 13 = MWCC vague-linkage (inline funcs / vtables, deduplicated by the linker).
  - `funcs_by_addr.txt` — FUNC symbols sorted by address (same columns).
  - `relocs.txt` — every relocation: `address(hex8)  type  symtab_index` (type 2=R_MIPS_32, 4=R_MIPS_26, 5=HI16, 6=LO16, 7=GPREL16).
- The first game's decomp ("Dark Cloud", same developer/engine, also MWCC + same SDK), for naming and layout conventions:
  `/Users/aarongauntlett/Development/chronicle` — see `config/pal/main.yaml` (TU list with `asmtu`/`cpp` units,
  `lib/libc/...`, `lib/sce/...`, `lib/libgcc/...`, `lib/libm/...` naming) and `config/pal/main.symbols.txt`, `src/ps2/*.cpp`, `include/`.

## Layout already established
- 0x100000–0x102630: crt0 + Metrowerks C++ runtime (exception handling etc.)
- 0x102630–0x12c2c0: GCC-compiled SDK/libc objects. Each object has its own `.text` SECTION symbol + `gcc2_compiled.` marker in symtab (indices ~40–1213), plus `.data/.rodata/.bss` SECTION symbols.
- 0x12c2c0–0x289e48: MWCC game code, part A (symtab local-symbol indices ~1214–7926)
- 0x289e48–0x28d1d0: libgcc objects (symtab ~7927–7970)
- 0x28d1d0–0x325c80: MWCC game code, part B (symtab locals ~7971–11420)
- 0x325c80–0x32a320: .vutext (VU microprograms); then .data from 0x32a320; .rodata around 0x363808..; a static-init code area 0x379680–0x37afe0 holding `__sinit_<file>.cpp` functions; `__static_init` pointer table 0x37afe0–0x37b0a4; vtables after; `_gp`=0x3846f0; bss to 0x1f64a00.
- Symtab index >= ~11421 are globals (not grouped by TU).

## Heuristics for MWCC TU boundaries (use all; state which you relied on)
1. Local symbols (static functions, `@N` literals, `name$N` function-statics, `.p__sinit_*`) appear in the symtab grouped per TU, and TUs appear in symtab in link (= address) order. Within a TU the order is scrambled, but a TU's locals form one contiguous symtab run. So successive runs whose text/data/rodata/bss address ranges are disjoint and ascending mark TU changes.
2. `__sinit_<file>.cpp` / `.p__sinit_<file>.cpp` locals give the REAL source file name of the TU whose symtab run contains them. Use these names verbatim (minus `.cpp`).
3. `@N` compiler-generated symbols increase with position within a TU (address-sorted @N numbers within one TU's rodata/data are monotone); a drop back to a small N at a higher address indicates a new TU. The whole game was compiled in one MWCC invocation.
4. Relocations: a function (global or local) that references a LOCAL symbol must be in the TU that owns that local. Use relocs.txt to attribute global functions to TU runs, and so to place the exact text boundary between two adjacent TUs.
5. Data/rodata/bss of a TU are laid out in the same TU order as text, so the ordering of referenced data addresses helps confirm boundaries.
6. One class per TU if unclear: all methods of a class (`Method__NClassF...`) belong together; otherwise group logically by purpose (e.g. all memcard functions together). A class name prefix (mgC*, CMenu*, CDng*, etc.) is a hint, not proof.
7. Vague-linkage (bind 13) functions are inline bodies emitted in the TU that used them — they sit inside or at the end of that TU's text range; do not treat them as their own TU.
8. TU names: first prefer `__sinit_` names; then debug/assert strings or filenames in the binary; then the first game's TU name for the equivalent code (check `chronicle/config/pal/main.yaml` + `main.symbols.txt` for where the same function/class lived); otherwise a short lowercase descriptive name in the same style (e.g. `mg_texture`, `menusave`). Mark invented names as such.
9. Function alignment: MWCC functions here are aligned to 0x10; GCC objects to 8. TU starts are function starts.

## Required output
Write your result to the output file named in your task, as TSV, one TU per line, sorted by address:
`start_vaddr(hex)  end_vaddr(hex, exclusive)  tu_name  name_source(sinit|string|dc1|invented)  confidence(high|med|low)  evidence(short)`
Every function in your slice must fall in exactly one TU; no gaps. If your slice's first/last TU appears
to continue outside your slice, say so in the evidence column (prefix `OPEN-START`/`OPEN-END`) and give
your best estimate of its true extent. Also list, below a `# NOTES` line, anything ambiguous, any heuristics you
discovered, and for each TU the address ranges of its .data/.rodata/.bss locals if you determined them cheaply.
Your final message should be a brief summary (counts, the uncertain boundaries) — the TSV file is the deliverable.
