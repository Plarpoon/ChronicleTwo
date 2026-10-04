#include "common.h"
#include "snd_seseq.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", BigToLittle__FPvPvi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", GetDeltaTime__FPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Initialize__8sndTrackFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Initialize__13sndCSeSeqDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", LoadSMF__13sndCSeSeqDataFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Initialize__9sndCSeSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", SetSeID__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Count__9sndCSeSeqFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Stop__9sndCSeSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Step__9sndCSeSeqFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", chk_trk__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", NoteOn__9sndCSeSeqFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", NoteOff__9sndCSeSeqFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", AllNoteOff__9sndCSeSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", TrackNoteOff__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", CtrlChg__9sndCSeSeqFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", ProgChg__9sndCSeSeqFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", PitchBend__9sndCSeSeqFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", SendVol__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", SendPan__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", SendPitch__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", SaerchVoice__8sndTrackFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", GetEmptyVoice__8sndTrackFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", NoteOn__8sndTrackFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", NoteOff__8sndTrackFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", CtrlChg__8sndTrackFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", ProgChg__8sndTrackFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", PitchBend__8sndTrackFii);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_seseq", at_295__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_seseq", at_296__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_seseq", at_297__2__DATA);
