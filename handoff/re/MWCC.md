# MWCC

Compiler traits, quirks and matching techniques for Dark Chronicle (PAL).

## Compiler

- Retail objects are stamped `MW MIPS C Compiler (2.4.1.01)` (`.comment`).
- Of the PS2 Metrowerks compilers in `tools/compilers/mw`, only five stamp that string: `2.4-001213`, `3.0-011126`, `3.0.1-020123`, `3.0.3-020716`, `3.0b22-020926`. `2.3*` stamp `2.3.1.01`; `3.0b38-030307` and everything later stamp `3.0.0`.
- `3.0b22-011126`, `3.0b22-020123` and `3.0b22-020716` are byte-identical to `3.0-011126`, `3.0.1-020123` and `3.0.3-020716`.
- Best match on a sample of 21 small functions (mg_memory, mg_math, password, gyoracesim, crandom): `3.0-011126` 20, `3.0.1-020123` 18, `3.0.3-020716` 17, `3.0b22-020926` 11, `2.4-001213` 6.
- `3.0-011126` alone hoists a float constant's `lui` into the delay slot of a `bc1t`/`bc1f` and repeats it on the fall-through path, as retail does (`mgAngleCmp`, `mgAngleLimit`).

## Flags

- `-opt all` (speed, level 4, intrinsics), `-Cpp_exceptions off -RTTI off`.
- Speed is required: levels 3 and 4 without it do not match. Levels 3 and 4 were not told apart by the sample.
- `password` (`search_txt`, `GetCRC`, `random`) matches only at level 0 with speed (`-O0,p`), so it is not compiled at the level the rest is.
- `-opt speed` pads branch-target labels with a `nop`, at every level including 0.
- `.sdata` threshold is the default 8: file-static scalars are gp-relative.

## Codegen

- A `float` constant is built with `lui`/`ori` and `mtc1`, not loaded from `.rodata`.
- `int % 1024` on a signed value: `bgez`/`andi`/`beqz`/`addiu -0x400`.
- A call's last argument, `this` included, is moved in the delay slot of the `jal`.
- `if (a >= 0.0f) return x; else return y;` emits `c.lt.s` + `bc1t` with the positive block first; `if (a < 0.0f)` emits `bc1f` with the negative block first.
