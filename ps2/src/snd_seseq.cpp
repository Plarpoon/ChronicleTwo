#include "common.h"
#include "snd_seseq.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", BigToLittle__FPvPvi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", GetDeltaTime__FPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Initialize__8sndTrackFv);
void sndCSeSeqData::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x4)) = 1;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", LoadSMF__13sndCSeSeqDataFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Initialize__9sndCSeSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", SetSeID__9sndCSeSeqFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", Count__9sndCSeSeqFf);
void sndCSeSeq::Stop(void) {
    this->AllNoteOff();
    (*(s32 *)((u8 *)this + 0x14)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
}
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
s32 sndTrack::NoteOff(s32 arg0, s32 arg1) {
    s8 *temp_v0;

    temp_v0 = (s8 *) (this->SaerchVoice((s32) (*(s8 *)((u8 *)this + 0x2)), arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = 0;
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_seseq", CtrlChg__8sndTrackFii);
s32 sndTrack::ProgChg(s32 arg0) {
    (*(s8 *)((u8 *)this + 0x2)) = arg0;
    return 0;
}
s32 sndTrack::PitchBend(s32 arg0, s32 arg1) {
    (*(s8 *)((u8 *)this + 0x4)) = arg1;
    (*(s8 *)((u8 *)this + 0x5)) = arg0;
    return 1;
}

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_seseq", at_295__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_seseq", at_296__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_seseq", at_297__2__DATA);
