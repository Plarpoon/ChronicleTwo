# sndviewlp notes

Debug sound viewer mode of the main loop. All three functions are 0x10-byte stubs in retail; the unit
owns no classes, structs, enums or global data (no `INCLUDE_RODATA`/`INCLUDE_BSS` in the `.cpp`).
No first-game counterpart exists. Same shape as `charaviewlp` and `texviewlp`.

## Functions
| Function | Body | Notes |
|---|---|---|
| `InitSoundViewerMain(INIT_LOOP_ARG)` | `jr $31; nop` | empty; `void` |
| `FinishSoundVieweMain()` | `jr $31; nop` | empty; `void` (retail spelling `Viewe` kept) |
| `LoopSoundViewerMain()` | `jr $31; addiu $2,$0,1` | `return 1;` declared `int` (matches `LOOP_MAIN_FUNC` in `mainloop.hpp`) |

## How the main loop uses them
- `mainloop` tables `LoopInit` (0x3392E0), `LoopMain` (0x339310), `LoopExit` (0x339340), 10 entries
  each. `LoopMain[7]` (0x33932C) is `LoopSoundViewerMain`, so this mode is loop index 7.
- `MainLoop` calls the init entry with the `INIT_LOOP_ARG` (passed by value = pointer to a copy),
  then the main entry each frame until it returns non-zero, then the exit entry. Returning 1 leaves
  the mode on its first frame.

## INIT_LOOP_ARG
- Declared complete (size 0x50) in `ps2/include/mainloop.hpp`, which this header includes; the `.cpp`
  can therefore define `InitSoundViewerMain` taking it by value.

All three definitions match retail byte for byte.
