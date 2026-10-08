# Remaining native matching plan

## Baseline and completion gate

At local revision `f0a4ce9`, the retail comparison contains 6,872 functions:
6,657 native matches and 215 outstanding functions. The outstanding inventory
comprises 192 guarded drafts, 15 assembly-only functions, and eight native
functions with residual differences. Assembly fallbacks and inline assembly do
not count as decompiled functions.

Each promotion requires documented dependency types, m2c analysis through
`decompile.sh`, source and header compliance with `AGENTS.md`, a zero-difference
whole-unit object comparison including resolved relocations, and a 100% objdiff
function comparison. Preserve retail function order and migrate associated data
to native definitions. Do not replace compiler-generated constructors or vtable
stores with manually written equivalents. Refresh the inventory after validated
batches; publish only after the complete game builds and its executable matches.

## Dependency order

| Phase | Work | Prerequisite and exit evidence |
| --- | --- | --- |
| 1 | Restore the eight native residuals in mg_texture, menuaqua, nd_meswin, actionchara, and actscript. | Existing typed implementations; all 149 game object checks and executable comparison pass. |
| 2 | Resolve shared native allocation/constructor lowering, beginning with mg_tanime and funcpoint, then dependent mg_dataset, map, scene, and list routines. | Document CList/CObject, mgCFrame, and CMapParts dependencies; prove natural C++ allocation and null-check behavior with exact whole-unit checks before applying it to callers. |
| 3 | Complete small UI, scalar, and scene routines; migrate required native tables and repair owning declarations before consumers. | Prefer documented dependency-complete routines; leave a draft guarded until its entire unit passes. |
| 4 | Resolve VU and hardware routines through reproducible compiler support and native source. | Explain hardware effects and types; no inline assembly or instruction-byte substitution qualifies as a match. |
| 5 | Audit remaining source, headers, and data; regenerate the function inventory and verify the complete game. | Zero outstanding native functions, every unit exact, linked retail executable exact, and documentation/source review complete. |

Phases 2–4 may overlap only when they own different translation units and do not
change a shared dependency. Shared compiler changes must be generic, reproducible
from the repository's pinned toolchain, and tested against unaffected units.
Profiles must preserve existing selectors. A function-specific address or
occurrence counter is not a semantic explanation of compiler behavior.

## Current ownership and measured results

The Astra coordinator integrates unit changes and maintains the dependency plan.
The primary agent owns actionchara, shared compiler support, full-game validation,
and publishing. Luna workers own separate translation units; their private
experiments are independently checked before integration. Agent analysis may run
concurrently, but memory-intensive compiler jobs use
`flock /tmp/ct-rest-compile.lock` serially to avoid host swap exhaustion.

- **mg_texture:** native AddHash, DelHash, and SearchHash now pass the whole-unit
  check (0x3674 bytes, 160 relocations), and all three objdiff scores are 100%.
  Direct table indexing and one shared optimization-level region are required;
  whole-unit level 2 was tested and changes unrelated functions.
- **menuaqua:** a callee-scoped 1.0f argument-order selector restores
  DrawEsaDropRoot. Canonical whole-unit validation passes 0x11C54 bytes and 2,970
  relocations; standard canonical objdiff reports 100% for the 316-byte function.
- **nd_meswin:** DrawMesWin needs different constant scheduling for calls sharing
  the same callee and literal. Broad 0.5f/0.95f selectors do not match; investigate
  a stable semantic discriminator without instruction or occurrence targeting.
- **actionchara:** duplicate assembly literal definitions account for most
  original failures. Two remaining native rotation calls require preserving
  zero across a nested unitRotation call; generic semantic compiler selection
  is under investigation.
- **actscript:** _SHOT retains a register-allocation residual. Earlier literal,
  local-variable, and helper-mask variants did not resolve it.
- **mg_tanime / funcpoint:** next small constructor-dependent trials test native
  allocation and scoped optimization; manual initializer/vtable writes remain
  prohibited.

Per-unit notes contain the detailed observations and failed experiments. Counts
above are a revision-specific baseline, not a claim that the remaining work is
complete or that a guarded draft is matched.
