# Build bring-up plan: Dark Chronicle (PAL) matching build

Goal: `./build.sh` builds `build/pal/SCES_511.90` whose loaded image (file bytes 0x100000–0x37CD80 of
section `main`) is byte-identical to retail, with every game translation unit compiled from
`ps2/src/<unit>.cpp` through tools/mwccgap (retail assembly standing in for every function and datum),
libraries linked from split assembly, an `.lcf` linker script, objdiff tracking, and the same
`build.sh` / `run.sh` container structure as the first game.

Repositories
- This project: `/Users/aarongauntlett/Development/chronicletwo` (work here).
- First game, the model to follow (READ-ONLY reference): `/Users/aarongauntlett/Development/chronicle`
  (`src/ps2/CMakeLists.txt`, `src/ps2/cmake/*.cmake`, `scripts/build/*`, `scripts/host/*`, `build.sh`,
  `run.sh`, `diff.sh`, `decompile.sh`, `Dockerfile`, `config/pal/SCUS_971.11.lcf`, `include/ps2/include_asm.h`).
  Port its structure, but simply: none of its overlay, NTSC/PAL carry, statefix, literal-pool or
  expression-override machinery applies here. Layout differs: this project keeps everything PS2 under
  `ps2/` (`ps2/src`, `ps2/include`, `ps2/config/pal`, `ps2/asm/pal`), scripts under `scripts/`, tools under `tools/`.
- Project rules: read `/Users/aarongauntlett/Development/chronicletwo/AGENTS.md` (comment style: state
  purpose, no process/history narration; match surrounding code).

Facts already established (see also `ps2/re/ai/main/translation_units.md`, `ps2/re/MWCC.md`)
- Retail ELF `rom/pal/extracted/iso/SCES_511.90`: one loadable section `main` at vaddr 0x100000,
  file offset 0x80, size 0x27CD80, align 0x80; `.relmain` keeps all relocations (r_offset = vaddr);
  symbol table intact. `_gp` = 0x3846F0. Section map is in `scripts/build/layout.py` (`SECTIONS`).
- Compiler: `tools/compilers/mw/3.0-011126/mwccps2.exe`, flags `-opt all -Cpp_exceptions off -RTTI off`.
  That package has no linker; `mwldps2.exe` exists in `tools/compilers/mw/2.4-001213`, `2.3.3-000906`
  and `3.0b38-030307`.
- MWCC 3.0 emits EVERY function and EVERY variable in an ELF section of its own (one `.text` per
  function, one `.data`/`.sdata`/`.rodata`/`.bss`/`.sbss` per object), each with its own alignment;
  objects ≤ 8 bytes go to `.sdata`/`.sbss`. So a section can be renamed/realigned per symbol after compiling.
- `ps2/config/pal/main.yaml` (splat 0.50, run from `ps2/config/pal`): 150 `asmtu` units (crt0, `lib/...`)
  and 149 `cpp` game units, each with named sibling subsegments `.data`, `.rodata`, `.sinit` (linked as
  `.init`: the unit's `__sinit_<file>_cpp` function), `.data`+`linker_section: .ctor`,
  `.data`+`linker_section: .vtables`, `.sdata`, `.sbss`, `.bss`; data-only units (`vutext`, `vudata`,
  `rdata`, `lib/libc/reent/impure`, `lib/libc/ctype/ctype_`, `lib/libm/common/s_infconst`, `s_lib_ver`).
  splat writes: `ps2/asm/pal/<unit>.s` (whole unit, all sections) for every unit;
  `ps2/asm/pal/nonmatchings/<unit>/<func>.s` for functions a source marks `INCLUDE_ASM`
  (`matchings/` otherwise); `ps2/asm/pal/data/...` per-section dumps.
- `ps2/config/pal/main.symbols.txt` (from `scripts/build/symbols.py`): retail names made C identifiers
  (`@123`→`at_123`, `$ . , < >`→`_`, duplicates get `__<n>`), one name per address.
- `scripts/build/layout.py`: `Layout` (units, kinds, per-unit section ranges, object paths),
  `read_symbols`, `SymbolIndex`, `Retail` (image bytes + relocation map), `LINKER_SYMBOLS`.
  Shared module: extend it only additively, and say so in your report.
- `ps2/include/macro.inc` is the first game's (glabel/jlabel/alabel).

Running tools (IMPORTANT)
- The Windows compilers run under `wibo`, which works only in the x86_64 colima VM, NOT Docker Desktop:
  `export DOCKER_CONTEXT=colima-dcdecomp` then
  `docker run --rm -v "$PWD":/w -w /w -e HOME=/tmp dcdecomp_dev <command>`
  The image `dcdecomp_dev` has wibo, `mips-ps2-decompals-{as,ld,objcopy,objdump,readelf}`, python3 with
  splat64 0.50, cmake, ninja, objdiff-cli. Each compile takes ~1.5 s there, so batch commands in ONE
  `docker run` (e.g. a shell script with `xargs -P 8`) rather than many.
- zsh gotcha on the host: write `"${var}:latest"`, never `$var:latest`.
- Do not `git commit`. Do not touch `rom/`, `tools/compilers`, `tools/ghidra`, `ps2/re/ghidra`, or the
  first game's repository. Do not edit files another work package owns (below); if you need a change
  there, describe it in your report.

Contract between work packages
- Source of a game unit: `ps2/src/<unit>.cpp`:
    #include "common.h"
    INCLUDE_ASM("ps2/asm/pal/nonmatchings/<unit>", <function>);      // every function, address order, sinit last
    INCLUDE_RODATA("ps2/asm/pal/nonmatchings/<unit>", <symbol>);     // every initialised datum, any section
    unsigned char <symbol>[0x<extent>];                               // every .sbss/.bss datum
  `ps2/include/common.h` includes `include_asm.h` (empty `INCLUDE_ASM`/`INCLUDE_RODATA` macros).
- Per-symbol assembly: `ps2/asm/pal/nonmatchings/<unit>/<symbol>.s`, generated (never committed) by
  `scripts/build/disassemble.py`, which runs splat and then writes what splat does not.
- Objects: `build/pal/obj/<unit>.cpp.o` (game), `build/pal/obj/<unit>.s.o` (asm units),
  as `Layout.object_path` says; data-only units `build/pal/obj/data/<name>.<kind>.s.o`.
- Compile a game unit: `scripts/build/mwccgap.sh <obj> <depfile> <src> <mwcc flags...>` (runs mwccgap,
  then `scripts/build/postprocess_object.py <obj>`).
- Assemble an asm unit: `mips-ps2-decompals-as -EL -march=r5900 -mabi=eabi -mno-pdr -non_shared -G0 -I ps2/include -o <obj> <src>`
  then `scripts/build/fixup_sections.sh <obj> [objcopy args]`.
- Linker script: `ps2/config/pal/SCES_511.90.lcf` (checked in; generated/maintained with `scripts/build/lcf.py`).
- Link: `wibo <mwld> <flags> -o build/pal/SCES_511.90 ps2/config/pal/SCES_511.90.lcf @build/pal/main_o_files`.
- Verify: `python3 scripts/build/verify.py` (extracted-file hashes; built image vs retail, section by section).
