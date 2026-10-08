# pbuggy: bomb initialization calibration

`InitBomb__FP6CScene` marks the bomb available, activates its scene object,
positions the bomb and Starbull character, sets Starbull's rotation to
`(0.0f, pi, 0.0f)`, and starts its motion.

The verified MWCC 3.0 row selects `pbuggy.cpp`, `InitBomb__FP6CScene`,
`binary32`, IEEE bits `0x40490fdb` (the float pi literal), and
`evaluate_first: true`. It restores the retail order of the two differing
instructions in rotation setup. The selector uses the mangled function and
literal bits, with no occurrence indices or source edits.

Validation used the full production mwccgap wrapper, normal section fixup,
and the canonical object checker. All function bytes and resolved relocations
match. The unit preserves its original `0x34b4` bytes, 819 relocations, and two
existing data issues: `PolVoice` has size `0x14` versus the retail `0x20` symbol
extent, and the BSS run ends at `0x01f5ef44` versus `0x01f5ef50`. These data
issues remain unresolved; this calibration establishes the function match.

See [MWCC matching notes](../../../../docs/MWCC.md) for the compiler-state
rationale and verification workflow.
