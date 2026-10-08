# Sound driver native analysis

## CSound::SQ_Play

`decompile.sh SQ_Play__6CSoundFiii` confirms the existing `MIDI_PORT` layout:
0x124-byte port stride, sequence table at +0xa0, sequence count at +0xf4.
The sequence index must be below the count; negative indices are not rejected.
The loaded IOP sequence address is passed to `ezMidi` command port+0x40.
Commands port+0x20, +0xb0, +0x30 and the bare port reset, set volume, position
and start playback. Volume 256 bypasses scaling; other values convert
`2.015748f * volume` to signed integer. Three diagnostic strings belong to this
function. CSound owns no per-instance state; `midi_state` provides port data.

The native function and the complete sound unit pass canonical byte and resolved
relocation comparison (0x2dec bytes, 681 relocations). Select the loaded sequence
in a positive `seq_no < sequence_count` branch, with the diagnostic and early
return in the alternative branch. The helper profile for `sound.cpp` seeds the
integer argument-register read mask to 0x20 ($a1); floating helper mask remains
zero. This prevents `$a1` from being prepared for `ezMidi` across `fptosi` and
restores the retail conversion branch delay slot. The three sequence diagnostic
strings are native literals; their duplicate assembly markers are removed.

## CSound::LoadSeq

`decompile.sh LoadSeq__6CSoundFiii` confirms IOP allocation of 256 bytes for
sizes at most 256, or `size + 256` otherwise. An allocation failure reports an
error and returns -1. The new sequence is inserted at sequence_count; its EE
payload is copied to the IOP allocation. For the first sequence, port+0x40
receives the address and any previous resident_sequence is freed. The count is
incremented; counts at least 16 report overflow after insertion. The sequence
and resident table fields agree with the existing MIDI_PORT layout.

LoadSeq remains a fallback. Caching the whole MIDI_PORT emits 0x168 bytes;
caching its sequence_count field separately emits 0x184 rather than retail
0x180. The latter inserts a field-pointer adjustment after the first count load,
where retail constructs and retains the count's direct address before loading.
A field reference, field pointer and direct global port-array representation
produce the same remaining address scheduling. The original aggregate layout
is retained.

## CSound::Step

`decompile.sh Step__6CSoundFv` confirms updates of the first fade in each of
16 MIDI ports. Positive steps stop only after exceeding target volume (unordered
comparisons also enter that branch); negative steps stop after falling below it.
Each active fade calls SetVol with port zero. Nine MSIN_BUFFER records are then
sent when their length is nonzero and at most 512 as unsigned; oversized records
are discarded. The full 512-byte record is transferred, and length is cleared
regardless of transfer status. Native fade-structure caching changes address
register allocation from retail's separately retained active/step/volume fields;
the fallback remains.
