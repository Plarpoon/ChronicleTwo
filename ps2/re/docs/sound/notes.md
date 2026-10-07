# sound: reverse-engineering notes

## CSound
- Empty class, `sizeof == 1`: no function reads `this`. The single instance `CSnd` (0x37D168, symbol
  size 0x1) is owned by **mainloop** (`INCLUDE_BSS(CSnd, 0x4)` in `mainloop.cpp`), so it is not
  declared in `sound.hpp`.
- 37 members: 36 in `sound`, plus `StreamOpenState()` in `ezbgm` (`j sceSifCheckStatRpc(&gCd2)`;
  callers use the result, so `int`).
- First-game counterpart: `CSound` in `chronicle/ps2/include/sound.hpp` (also empty). Different
  interface here: no SE/SQ description tables, no `Fade`, no per-bank `LoadHdBd_X`; banks are loaded
  generically per port (`LoadHdBd`/`LoadHdBd2`/`LoadHdBdAdd`), plus EZBGM stream functions.
- Return types: `Init` (0 ok, -1 IOP alloc failed, 1 `sceMSIn_Init` failed), `Exit` (always 0),
  `LoadSeq` (0 / -1), `TransHdBd` (0 / -1), `StreamGetState` (`ezBgm(ch|0x80B0,0) & ~0xFFF`),
  `StreamGetLevel` (tail call; `_STREAM_SILENT_CHECK` uses result as two shorts),
  `TransBdState` (tail call; `sndWaitTransBd` loops on `sndTransBdState()` result).
  `LoadHdBdAdd` returns 0 on the "too many banks" path (`daddu $2,$0,$0`); on success $v0 is left
  holding the last `ezMidi` result (no explicit return in that path) -> declared `int`.
  `LoadHdBd` (0x10) is `j LoadHdBd2` -> `void`; `LoadHdBd2` sets no $v0 -> `void`.
  Other tail-call wrappers (`StopVoice`, `SetReverb`, `SetMasterVol`, `Stop`, `SetStereoMode`)
  have no caller using a result -> `void`.

## Parameters
- `Init(mode0, mode1, depth0, depth1)` -> `set_spu`: per core c: `SD_A_EEA|c = 0x1FFFFF - c*0x20000`,
  effect attr mode = `mode_c | 0x100` (clear WA), `SD_C_EFFECT_ENABLE|c = 1`, EVOL L/R = `(depth_c & 0xFF) << 8`,
  MVOL L/R = 0x3FFF. `sndInitMngr` calls `Init(4, 0, 0x28, 0)`. `SetReverb(core, mode, depth)` same per core.
- `SndInReverb(bool)`: `rSdSetParam` 0x800/0x801 (param 0x08 per core) = 0xFFFC (on) / 0xFFCC (off).
- SE functions: names from `snd_seseq` callers via `snd_mngr::sndSe*PBPrKr`. `sndSePlayPBPrKr(port, bank,
  program, key, velocity, volume, pan, pitch, id)` calls `SE_Play(port, bank, program, key, pan,
  velocity, volume, pitch, id)`. Messages: CC0 (bank select) = bank, program change = program, then
  HS messages: `F9 00 00 volume 00`, `F9 01 00 pan 00`, `FD 10 00 key id velocity 00` (note on).
  `pitch` (param 8) is unused by `SE_Play`. `SE_SetVol`: `FD 00 00 key id volume`. `SE_SetPan`:
  `FD 01 00 key id pan`. `SE_Stop`: `FD 10 00 key id 0` (velocity 0). `SE_SetPitch`:
  `FD 02 00 key id pitch&0x7F (pitch>>7)&0x7F`. All reject `id >= 0x7F` with "SE_ID ERR"; all but
  `SE_SetPitch` require `port.bank_count > 0`. MSIn port = `port - 7`.
- `LoadHdBd*(port, hd, hd_size, bd, bd_size)`: EE address/size of bank header and body
  (`sndLoadSound` passes them). `LoadSeq(port, address, size)`: EE address and size of a sequence.
- `StreamSetVol(ch, left, right)`: arg = `left << 16 | right`; `sndStreamSetVol(float,float)` passes
  `fptosi(x * 32767)` each, channel 1.
- EZBGM commands (arg `ch | cmd`): 0x10 close, 0x30 stop(Close), 0x40 standby start, 0x50 play/replay,
  0x60 pause/stop, 0x70 end(END), 0x80 set volume (and reset with 0 before open), 0x8000 set buffer
  (0x3000 mono / 0x4000 stereo), 0x8020 open, 0x80B0 state, 0x80C0 (0x10 mono / 0 stereo),
  0x80D0 standby info (bit 0 = stereo), 0x80E0 level, 0x80F0 open from FPL.
- EZMIDI commands used (arg `port + cmd`): 0x00 play, 0x20 stop, 0x30 (before play), 0x40 set
  sequence, 0xA0 (value `unk_98`), 0xB0 volume (`vol==256 ? 256 : (int)(vol*2.015748f)`),
  0x9050 load bank (`&gBank`), 0x8010 (Init: returns IOP MSIn buffer address, arg 0x4000), 0x80F0 (Exit), 0xC0 stereo mode.

## MIDI_PORT (0x124) / MIDI_STATE (0x1240)
`midi_state` (0x3F5250, local, size 0x1240 = 16 * 0x124). Stride 0x124 seen everywhere (`port*0x124`,
`*0x49` on word arrays). Init's per-port loop gives the layout:

| Off | Type | Name | Evidence |
|---|---|---|---|
| 0x00 | s32 | unk_00 | Init: 0 then per-port 0/1/2 (1,2,8,14,15 = 2; 13 = 1). Never read in sound. |
| 0x04 | s8 | spu_direction | `sb`; LoadHdBd2/Add `lb` compare 0 / 1 (SpuAllocDirection). Port 13 = 1. |
| 0x08 | s32 | linked_port | Init -1; LoadHdBd2/Add also load gBank into it, copy bank ptr / next addr, bump its bank_count; DEL_PORT deletes it. Port 2 -> 14, port 14 -> 2. |
| 0x0C | s32[16] | dependent_port | Init -1 (loop 16); loops to count at 0x4C; stopped and given this port's spu addresses. |
| 0x4C | s32 | dependent_port_count | port1: [15,2,14] n=3; port8: [1,15,2,14] n=4; port10: [8,1,15,2,14] n=5; port15: [2,14] n=2. |
| 0x50 | void*[16] | bank | IOP hd addresses (`gBank.hd_address`), freed with sceSifFreeSysMemory. |
| 0x90 | s32 | bank_count | `< 0x10` check in LoadHdBdAdd; SE_* require > 0. |
| 0x94 | s32 | spu_address | Init: ports 0,3 = 0x5210; 1,2,8,10,14,15 = 0x7D210; 7,12,13 = 0x18AE20; 9 = 0x1E0000; 11 = 0x1A82E0. Not zeroed in the generic loop. |
| 0x98 | s32 | unk_98 | Sent with EZMIDI 0xA0 after LoadHdBd2. Init: 0x3040 (0,3), 0x3032 (1), 0x3039 (2,14), 0x3010 (7), 0x3035 (8), 0x3038 (9), 0x3037 (10), 0x3033 (11), 0x3034 (12), 0x3036 (13), 0x3031 (15). |
| 0x9C | s32 | spu_next_address | Init = spu_address; upward: load at it then += bd_size+0x10; downward: -= bd_size+0x10 and load there. |
| 0xA0 | void*[10] | sequence | LoadSeq stores `[count]`; SQ_Play reads `[seq_no]` (seq_no < count). Init zeroes 10 (8 unrolled + 2). |
| 0xC8 | void* | resident_sequence | LoadSeq when count==0: ezMidi(port+0x40, addr), frees old, stores addr. DEL_PORT/LoadHdBd2 re-send it, free sequence[1..]. |
| 0xCC | s32[10] | unk_CC | Only zeroed by Init (10 entries). First game's `MIDI_SEQUENCE *sequence[10]` sits here. |
| 0xF4 | s32 | sequence_count | LoadSeq prints "SEQ_MAX OVER" when > 15 -- note the arrays are only 10 long. |
| 0xF8 | MIDI_FADE[2] | fade | Step: 0xF8 active (lw), 0xFC target (lwc1+cvt.s.w -> int), 0x100 volume (float), 0x104 step (float). Init zeroes 0x108 (fade[1].active). |
| 0x118 | s32 | unk_118 | Init 0; ports 13 and 15 = 1. Not read in sound. |
| 0x11C/0x120 | s32 | unk_11C/unk_120 | Init 0 only. |

- `Step` only processes `fade[0]` of each port, and calls `SetVol(0, vol)` with port 0 constant.
- No unit other than sound references `midi_state` (or any of the sound globals except `iop_bd_addr`).

## Other data
- `gBank` (0x3F5200, local, symbol size 0x44, BSS slot 0x50): MIDI_BANK. 0x00 bank_no (0 for
  LoadHdBd2, old bank_count for Add), 0x04 hd IOP addr, 0x08 = iop_bd_addr, 0x0C bd_size, 0x10 SPU
  dest address; 0x14..0x43 never touched. Passed to EZMIDI 0x9050 (argument-block flag 0x1000 ->
  64-byte block). First game's MIDI_BANK (0x40) lacked bank_no.
- `iop_bd_addr` (0x37D0F8, **global**, also read by `movie::strFileOpen`): IOP staging area,
  `sceSifAllocSysMemory(1, 0x6DD00, 0)` in Init; bodies over 0x6DD00 bytes are sent in two parts.
- `iopMSINBuffAddr` (local, .sbss 0x8 slot): IOP address of the 9 MSIn buffers (`ezMidi(0x8010,0x4000)`).
- `bgm_info` (local, 8 bytes): per-stream-channel word from EZBGM open/standby (bit 0 = stereo).
- `bd_size_total` (local): zeroed in Init only.
- `load_m_flg_351`, `init_352`: function-local static (and its guard) inside Init.
- `msinCtx` (sceCslCtx, 0x14): {buffGrpNum 2, &msinBfGrp, 0, 0, 0}. `D_003F3F6C` is padding after it.
- `msinBfGrp` (sceCslBuffGrp[2]): [0] = {0, 0}, [1] = {9, msinBfCtx}.
- `msinBfCtx` (sceCslBuffCtx[9], 0x48): {0, &msinBf[i]}.
- `msinBf` (MSIN_BUFFER[9], 0x1200): size = 0x200, length = 0 at Init. Step sends each buffer with
  length 1..0x200 to `iopMSINBuffAddr + i*0x200` then clears length; DEL_PORT/LoadHdBd2 clear
  `msinBf[port-7].length`.
- All of the above except `iop_bd_addr` are LOCAL in retail, so they belong as `static` in sound.cpp.

## Unresolved / for the body writer
- `sceSifAllocSysMemory` / `sceSifFreeSysMemory` / `sceSifCheckStatRpc` are not yet declared in
  `ps2/include/sce`; `ezBgm`/`ezBgmInit` have no header yet (ezbgm unit).
- TransHdBd checks "SYS AREA HAKAI?" when the destination range straddles 0x18AE20.
- Port roles (BGM, SE, ...) are not established from this unit; no port enum was declared.

The guarded `CSound::LoadHdBd2` draft differs mostly because retail holds the port argument in `s4` and bank data argument in `s3`, while MWCC reverses those saved registers. Declaring the port parameter `register` did not change that allocation. Its isolated linked image remains different and the assembly fallback stays active.
