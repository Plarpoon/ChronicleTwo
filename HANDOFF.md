# Handoff — Dark Chronicle (PAL) decompilation bring-up

Written 2026-10-04, when work was stopped mid-task. Nothing is committed: everything below is in
the working tree (plus two staged submodules). `build/`, `ps2/asm/`, `ps2/re/` and `rom/` contents
are git-ignored, so the pieces of them needed to resume are copied into `handoff/`.

## Where things stand

### Done and verified
- **Disc extraction** — `scripts/build/extract.py` (standard library only). Executable is
  `rom/pal/extracted/iso/SCES_511.90`; hashes in `rom/pal/checksum.sha256`, `rom/pal/extracted.sha256`.
- **Symbol list** — `scripts/build/symbols.py` writes `ps2/config/pal/main.symbols.txt` from the
  ELF's own symbol table: names made C identifiers (`@123`→`at_123`; `$ . , < >`→`_`; duplicates
  `__<n>`), one name per address.
- **Split config** — `ps2/config/pal/main.yaml` (splat 0.50, run from `ps2/config/pal`, output
  `ps2/asm/pal`): 150 `asmtu` library units, 149 `cpp` game units, every unit with its own
  `.data/.rodata/.sinit/.ctor/.vtables/.sdata/.sbss/.bss` subsegments. `tools/splat_ext/sinit.py`
  is the extension for a unit's `__sinit` code. splat runs cleanly on this yaml.
  Evidence for every boundary: `handoff/re/translation_units.md`, raw survey tables in `handoff/survey/`.
- **Compiler identified** — `tools/compilers/mw/3.0-011126/mwccps2.exe` with
  `-opt all -Cpp_exceptions off -RTTI off` (decided by the user). Findings: `handoff/re/MWCC.md`;
  test sources and scoring scripts: `handoff/cctest/`. The password unit matched only at `-O0,p`.
  Only the two packages the build uses are in `tools/compilers/mw/`: `3.0-011126` (compiler) and
  `2.4-001213` (linker). The other decompme PS2 MWCC packages can be re-pulled with
  `docker pull ghcr.io/decompme/compilers/ps2/mwcps2-<label>:latest` and export `/compilers`.
- **`scripts/build/layout.py`** — reads the yaml: units, kinds, per-unit section ranges, object
  paths, retail image and relocations.
- Submodules added (staged): `tools/mwccgap` (Adubbz fork, pinned b092f58 like the first game), `tools/m2c`.

### In progress — UNFINISHED AND UNVERIFIED
The task: every game unit compiled from `ps2/src/<unit>.cpp` through mwccgap (`INCLUDE_ASM` per
function, `INCLUDE_RODATA` per initialised datum, `unsigned char name[size];` per bss datum), an
`.lcf`, `build.sh`/`run.sh` container structure, a byte-matching ELF, objdiff tracking.
Plan and contract between the pieces: **`handoff/PLAN.md`** (read this first).

Three Opus agents were implementing it and were stopped part-way. Their files are in the tree
but **none of it has been reviewed or shown to work end to end**; treat each as a draft:

| Package | Files left in the tree | State when stopped |
|---|---|---|
| A — unit objects | `scripts/build/disassemble.py`, `mwccgap.sh`, `postprocess_object.py`, `check_objects.py`, `ps2/src/*.cpp` (149), `ps2/include/common.h`, `include_asm.h` | Sources scaffolded; was writing/testing the wrapper. No evidence yet that any unit object passes `check_objects.py`. Scaffold generator: `handoff/scratch/scaffold.py`. |
| C — link and verify | `scripts/build/lcf.py`, `fixup_sections.sh`, `verify.py`; prototype in `build/pal-link/` (copy of its lcf in `handoff/link-prototype/`) | Had a prototype link from whole-unit assembly and was about to run verify. `ps2/config/pal/SCES_511.90.lcf` does NOT exist yet. Unknown whether the image matched. |
| D — build system/container | `CMakeLists.txt`, `ps2/CMakeLists.txt`, `ps2/cmake/`, `scripts/build/cmake.sh`, `globs.sh`, `make_iso.py`, `build.sh`, `run.sh`, `dev.sh`, `scripts/host/`, `Dockerfile`, `.devcontainer/`, `.gitignore`, `.dockerignore`, `README.md` | Scripts drafted; was starting the CMake rules. Not run. |

Not started: objdiff configuration + progress report, `diff.sh`/`decompile.sh`, re-running
`scripts/build/disassemble.sh` (older wrapper, superseded by `disassemble.py`), docs for the build.

## Key design decisions (so they are not re-derived)
- MWCC 3.0 emits every function and variable in its own ELF section. So a post-compile step
  (`postprocess_object.py`) can rename each section to retail's (`.init`, `.ctor`, `.vtables`,
  `.sdata`…) and set data alignment to 1 with exact extents; no data carve-outs for game code.
- Per-symbol data assembly is generated from the retail ELF bytes + `.relmain` relocations, not
  from splat's data dumps. mwccgap's `INCLUDE_RODATA` wants `.section .rodata`, one label per
  file, and text before each directive.
- bss cannot go through `INCLUDE_RODATA` (it would need tens of MB of zero initialisers), hence
  plain definitions.
- The 3.0-011126 package has no linker; `mwldps2.exe` comes from `2.4-001213`.
- Remaining non-source data in the link: VU blobs (`vutext`, `vudata`), four code-less library
  objects, and the word at 0x37C6F0 (`_overlay_group_addresses`; unknown whether MWLD emits it).

## Environment notes for another machine
- wibo (runs the Windows compilers) fails under Docker Desktop's Rosetta on Apple silicon. On
  this Mac the working setup was an x86_64 colima profile: `DOCKER_CONTEXT=colima-dcdecomp`,
  image `dcdecomp_dev` (the first game's dev image). On x86_64 Linux a plain container works.
- splat was run from a throwaway venv: `pip install "splat64[mips]==0.50.0"`.
- The first game's repository (`../chronicle`) is the model for the build system; its submodules
  were not checked out here.
- Needed inputs that do not travel by git: the disc image at `rom/pal/Dark Chronicle (PAL).iso`,
  `tools/compilers/mw/`, `tools/ghidra` + `ps2/re/ghidra` (optional), `AGENTS.md` (now git-ignored
  by the new `.gitignore` — check that is intended).

## Suggested next steps
1. Read `handoff/PLAN.md`; review package A's files; get two or three small units
   (`mg_memory`, `mglib`, `password`) through `mwccgap.sh` and `check_objects.py`, then all 149.
2. Finish package C against whole-unit assembly until `verify.py` reports a matching image,
   write `ps2/config/pal/SCES_511.90.lcf`, then switch the game objects to the compiled ones.
3. Finish package D's CMake rules against the contract and run `./build.sh` end to end.
4. Add objdiff (`objdiff.json`, target/base objects, progress report) as in the first game.
5. Delete `handoff/` and this file once the build is in place.

## Open questions for the owner
- Per-unit optimisation level (password code is `-O0,p`): pragma in source or per-file flags?
- `.gitignore` now ignores `AGENTS.md` and un-ignores the two checksum files — confirm.
