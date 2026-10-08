# wavetable: reverse-engineering notes

## C++ draft status
The constructor, destructor, `CreateTexture`, and `GetEffect` are native C++.
Only `Effect` retains `INCLUDE_ASM` in the matching build. Its guarded draft
compiles to the retail 0x510-byte length with `-O3,p`, but 27 instructions
differ: the compiler assigns the 0.0196f and 1.9216f constants to opposite
floating registers, propagating the difference through the unrolled wave
calculation and the final seam loop. The guarded draft also flattens the
three-dimensional height array through raw float pointers, so it does not
meet the source-type requirements for promotion.

Private MWCC trials using typed two-dimensional array indexing, typed row
array pointers, and a typed flat-array union all compile but yield scalar
inner loops of 0x208 or 0x290 bytes instead of retail's eight-column
unroll. This shows that the currently close instruction schedule depends on
the flat pointer expression; an exact, type-safe source form is still needed.
Scoped optimization level four also leaves the typed two-dimensional loop
scalar at 0x208 bytes, so the mismatch is not resolved by stronger standard
optimization.
These private trials changed neither the canonical source nor Satan's Fiddle.

`CreateTexture` is byte-matched but still uses two flat-pointer expressions
to select the current height plane. Replacing them with direct
`height[current][row]` indexing or an equivalent typed flat-array view keeps
the 0x420-byte size but changes instructions at 0x1A370D onward. Hoisting a
typed row-array pointer shrinks the function to 0x400 bytes and moves later
literals and calls. These private type-cleanup forms therefore cannot replace
the matched source without further source-schedule analysis.

## CWaveTable (size 0x1208)
No counterpart in the first game's headers.

Size: `operator new(0x1208, ...)` in `TitleBootInit__Fv` (title); the globals `WaveTable`
(editloop, 0x1EC97B0) and `WaveTable__2` (dng_main, 0x1EE5260) are 0x1208 bytes each and are
constructed in `__sinit_*` with `__register_global_object(..., __dt__10CWaveTableFv, ...)`.
`WaveTable__3` (title, 0x37DFE8) is a `CWaveTable *`. These globals belong to those units.

| Offset | Field | Evidence |
|---|---|---|
| 0x0000 | `float height[2][24][24]` | ctor zeroes 24 rows x 24 cols at `+0` and `+0x900` (row stride 0x60, buffer stride 0x900); every other function indexes `this + current*0x900 + row*0x60 + col*4` with `lwc1` |
| 0x1200 | `int current` | ctor sets 0; `GetEffect` flips `current = 1 - current` after `Effect()` |
| 0x1204 | vtable pointer | ctor/dtor store `__vt__10CWaveTable` here (MWCC puts the vptr after the data members of the first polymorphic class) |

Vtable `__vt__10CWaveTable` (0x37BC38, size 0xC): `{0, 0, __dt__10CWaveTableFv}` -- only the
virtual destructor.

## Function behaviour
- `CWaveTable()`: zeroes both height fields, `current = 0`. Inner loop unrolled by 8.
- `~CWaveTable()`: standard MWCC dtor (`short` delete flag, `operator delete` when > 0).
- `GetEffect()`: function-local statics `cnt_302` (int) / `init_303` (1-byte guard) at 0x37D208/
  0x37D20C. When `cnt == 0`, four times: `height[current][rand()%22+1][rand()%22+1] +=
  (rand()/2147483648.0f - 0.5f) * 0.04f` (first rand gives the column, second the row). Then
  `cnt++`, reset to 0 when `> 4` (so disturbances every 5th call). Then `Effect()`, then flip
  `current`. Returns void (callers ignore any result).
- `Effect()`: `prev = 1 - current`. For rows 1..22, cols 1..22:
  `h[prev][r][c] = (h[cur][r-1][c] + h[cur][r+1][c] + h[cur][r][c-1] + h[cur][r][c+1]) * 0.0196f
  + (h[cur][r][c] * 1.9216f - h[prev][r][c]) - (h[cur][r][c] - h[prev][r][c]) * 0.0015f`.
  Then for rows 1..22, `h[prev][r][1] = h[prev][r][22] = (both) * 0.5f` (horizontal seam).
  Both loops unrolled by 8 in retail.
- `CreateTexture(mgCTexture *tex)`: returns early if `tex == NULL` or `tex->bpp <= 23` (bpp at
  +6, `short`). `mgSetPkFrameBuffer(tex)`; local `mgCDrawPrim` (0x120 bytes on stack),
  `Initialize(NULL, NULL)`, `DepthTestEnable(0)`, `ZMask(-1)`, `Shading(1)`,
  `AlphaBlendEnable(1)`. Cell size `width/23.0f`, `height/23.0f`; origin
  `(float)mgScreenOffx/Offy`. `Begin2()`; 23 rows (r = 0..22), each `BeginPrim2(4, 0x4141, 0, 4)`
  (triangle strip), 24 columns (c = 0..23, column index clamped `c > 22 -> 0`). Per column two
  vertices: intensity `I = clamp((h[cur][r][c] - h[cur][r][(c+1)%24]) * 540 + 40, 0, 200)`, colour
  `{I, I, I, 96.0}` via `Data0`, position via `Data4`; second vertex uses row `(r+1)%24` and
  y + cell height. Colour vectors come from the literals `at_251`/`at_256` (`{0,0,0,96.0f}`,
  last word read from 0x33A83C / 0x33A84C), i.e. a `float[4]` local initialised from a constant
  aggregate. `EndPrim2`, `End2`. Then `Shading(0)`, `AlphaBlend(2)`, `Begin(6)` (sprite),
  `Color(0,0,0,0x80)`, `Vertex(-1,-1,0)`, `Vertex(width+1, height+1, 0)`, `End()`, and
  `mgSetPkFrameBuffer(-1,-1,-1,-1)`.

## Callers
`GetEffect` and `CreateTexture` are called from `DngMainDraw__Fv`, `EditDraw__Fv`,
`TitleMapDraw__Fv` around `mgEndDrawReloadTexture` for the water texture.

## Global data
None with plain names: `cnt_302`/`init_303` are `GetEffect`'s function-local statics, `at_251`/
`at_256` are compiler literals. No `extern`s in the header.

## Naming
Field names `height`/`current` and the enum `WAVE_TABLE_DIM` (24) are descriptive, not retail.
