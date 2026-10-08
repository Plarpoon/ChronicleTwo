# prespr notes

One class, `CPreSprite`, five non-virtual member functions. No globals, no data symbols, no
file-local functions. Not present in the first game (no `CPreSprite` in `chronicle`).

## CPreSprite (0x130), base `mgCDrawPrim` (0x120)
- Base: the first three functions call `mgCDrawPrim` methods on `this`; `SetScirror`/`SetAlphaBlend`
  use `this+0xDC` = `mgCDrawPrim::write` (store one quadword, advance 0x10). Callers construct it
  with `__ct__11mgCDrawPrimFv` directly (implicit inline ctor, no own init), then
  `Initialize(NULL, NULL)` and `Preset2D()`.
- No vtable (no `__vt__10CPreSprite`; base has no virtuals).
- Size 0x130 evidence:
  - `MiniEffPrimMan` (dng_effect global, `CMiniEffPrimMan`) has ELF size 0x940 and holds a
    `CPreSprite` at +0x810 (passed to `CMiniEffPrim::Draw(CPreSprite *)`); nothing after it is
    accessed, so 0x810 + 0x130 = 0x940.
  - `CMiniMapSymbol` (automap) holds a `CPreSprite` at +0x10; next accessed field is +0x140.
  - Stack instances (e.g. `CHealingEffectMan::Draw`, at sp+0x120 in a 0x250 frame;
    `CFlushEffect::Draw`) occupy 0x130 bytes.
  - `mgCDrawPrim` itself is 0x120 (`MenuPrimFix` global), so CPreSprite adds 0x10 bytes.
- `unk_120[0x10]`: never accessed anywhere found. Its real type(s) are unknown; it may be split
  into fields if a user turns up.

## Functions
- `Preset2D()`: AlphaBlendEnable(1), AlphaBlend(1 = MG_ALPHA_BLEND_NORMAL), AlphaTestEnable(1),
  AlphaTest(1, 0), DepthTestEnable(0), ZMask(-1 = MG_Z_MASK_MASKED), Bilinear(0),
  TextureMapEnable(1).
- `SetIRect(x, y, w, h, u, v)`: TextureCrd(u, v); Vertex(x, y, 0); TextureCrd(u+w, v+h);
  Vertex(x+w, y+h, 0). Sprite primitive (callers Begin(6)).
- `SetIStretch(x, y, w, h, u, v, tw, th)`: same, with second texel corner (u+tw, v+th).
- `SetScirror(x, y, w, h)` (retail spelling): writes `*write = x | (x+w)<<16 | y<<32 | (y+h)<<48`,
  `write[1] = 0x40` (SCISSOR_1), write += 0x10. Ints are sign-extended to 64-bit before shifting;
  `s64` casts reproduce the exact instruction sequence.
- `SetAlphaBlend(mode)`: writes ALPHA_1 (reg 0x42) data, then write += 0x10. Values match
  `mgALPHA_BLEND` (mg_drawprim.hpp), parameter is `int` for mangling:
  - 1 NORMAL: 0x44 (A=Cs,B=Cd,C=As,D=Cd)
  - 2 ADD: 0x48 (A=Cs,B=0,C=As,D=Cd)
  - 3 SUB: 0x42 (A=0,B=Cs,C=As,D=Cd)
  - 4 NONE: 0x2A | 0x80<<32 (A=0,B=0,C=FIX,D=Cs, FIX=0x80)
  - other (incl. 5 ADD_FULL, 0): nothing written.
  The compiler emits comparisons in order 4,3,2,1,0. A `switch` with an explicit empty case 0
  placed first reproduces the extra zero/default branch and matches all 0xC4 bytes. The packed
  register entry has two 64-bit fields: data and register address (`SpriteGsPacket`).

## Matching

All five functions are decompiled and score 0 in objdiff. Their text sizes are 0x80, 0xAC, 0xBC,
0x60 and 0xC4 bytes, respectively; padding accounts for the remaining aligned bytes in the unit.
The last two write GIF address/data entries directly. An explicit empty case 0 is essential in
`SetAlphaBlend` because MWCC otherwise removes two branches that retail retains.

## Users
dng_object, dng_debug, dng_status, dng_effect, dng_hud, automap (and others: grep
`build/re/ghidra` for `CPreSprite`). Typed as `CPreSprite *` in `CMiniEffPrim::Draw`,
`CMapEffect_Sprite::Draw`, `CEnemyGekirin::Draw`.
