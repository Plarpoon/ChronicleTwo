#include "common.h"
#include "movie.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", Load__6CMovieFPcPP9mgCMemoryiibbb);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", Load__6CMovieFPcP9mgCMemoryiibb);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", Load__6CMovieFPcP9mgCMemoryiibbb);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", Play__6CMovieFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", SwitchThread__6CMovieFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", Term__6CMovieFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", EndCheck__6CMovieFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", IsStarted__6CMovieFv);
int CMovie::GetVoBufDataSize() { return 0x1C0000; }
int CMovie::GetViBufDataSize() { return 0x80000; }
s32 CMovie::GetViBufTagSize(void) {
    return 0x1010;
}
s32 CMovie::GetMpegWorkSize(s32 width, s32 height) {
    s32 half_work_units;
    s32 pixel_work_units;

    pixel_work_units = width * height * 9;
    half_work_units = pixel_work_units >> 1;
    if (pixel_work_units < 0) {
        half_work_units = (s32) (pixel_work_units + 1) >> 1;
    }
    return half_work_units + 0x1768;
}
int CMovie::GetReadBufSize() { return 0x50050; }
s32 CMovie::GetTagProgSize(s32 width, s32 height) {
    s32 macroblocks;
    s32 tag_pages;
    s32 tag_bytes_rounded;
    s32 macroblock_columns;
    s32 macroblock_groups;

    macroblock_columns = width >> 4;
    if (width < 0) {
        macroblock_columns = (s32) (width + 0xF) >> 4;
    }
    macroblocks = macroblock_columns * height;
    macroblock_groups = macroblocks >> 4;
    if (macroblocks < 0) {
        macroblock_groups = (s32) (macroblocks + 0xF) >> 4;
    }
    tag_bytes_rounded = (((macroblock_groups * 6) + 0x6E) * 4) + 0x3F;
    tag_pages = tag_bytes_rounded >> 6;
    if (tag_bytes_rounded < 0) {
        tag_pages = (s32) (tag_bytes_rounded + 0x3F) >> 6;
    }
    return tag_pages << 8;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecCreate__6CMovieFP8VideoDecPUciP1P1iP9TimeStampi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecSetStream__6CMovieFP8VideoDeciiPFP7sceMpegP13sceMpegCbDataPv_iPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecDelete__6CMovieFP8VideoDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecFlush__6CMovieFP8VideoDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", defMain__FPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecMain__FPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", stepMain__FPv);
s32 mpegError(sceMpeg *mpeg, sceMpegCbDataError *error, void *user) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", mpegNodata__FP7sceMpegP13sceMpegCbDataPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", mpegStopDMA__FP7sceMpegP13sceMpegCbDataPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", mpegRestartDMA__FP7sceMpegP13sceMpegCbDataPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", mpegTS__FP7sceMpegP22sceMpegCbDataTimeStampPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoCallback__FP7sceMpegP16sceMpegCbDataStrPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", pcmCallback__FP7sceMpegP16sceMpegCbDataStrPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", vblankHandler__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", handler_endimage__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", voBufCreate__FP5VoBufP6VoDataP5VoTagi);
void voBufReset(VoBuf *buffer) {
    buffer->write = 0;
    buffer->count = 0;
}
s32 voBufIsFull(VoBuf *buffer) {
    return buffer->count == buffer->size;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", voBufIncCount__FP5VoBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", voBufGetData__FP5VoBuf);
s32 voBufIsEmpty(VoBuf *buffer) {
    return buffer->count == 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", voBufGetTag__FP5VoBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", voBufDecCount__FP5VoBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", getFIFOindex__FP5ViBufPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", setD3_CHCR__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", setD4_CHCR__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", scTag2__FP5QWORDPvUiUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufCreate__FP5ViBufP1P1iP9TimeStampi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufReset__FP5ViBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufBeginPut__FP5ViBufPPUcPiPPUcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufEndPut__FP5ViBufi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufAddDMA__FP5ViBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufStopDMA__FP5ViBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufRestartDMA__FP5ViBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufDelete__FP5ViBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufFlush__FP5ViBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufModifyPts__FP5ViBufP9TimeStamp);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufPutTs__FP5ViBufP9TimeStamp);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", viBufGetTs__FP5ViBufP9TimeStamp);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", strFileOpen__FP7StrFilePc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", strFileSeek__FP7StrFile);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", strFileClose__FP7StrFile);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", strFileRead__FP7StrFilePvi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", readBufCreate__FP7ReadBuf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", readBufBeginPut__FP7ReadBufPPUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", readBufEndPut__FP7ReadBufi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", readBufBeginGet__FP7ReadBufPPUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", readBufEndGet__FP7ReadBufi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecCreate__FP8AudioDecPUcii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecDelete__FP8AudioDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecPause__FP8AudioDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecResume__FP8AudioDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecStart__FP8AudioDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecReset__FP8AudioDec);
s32 audioDecIsPreset(AudioDec *decoder) {
    return decoder->total_bytes_sent >= decoder->iop_buff_size;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecSendToIOP__FP8AudioDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", iopGetArea__FPiPiPiPiP8AudioDeci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", sendToIOP2area__FiiiiPUciPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", sendToIOP__FiPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", changeMasterVolume__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", changeInputVolume__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", startDisplay__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", switchThread__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecSetState__FP8VideoDecUi);
s32 videoDecGetState(VideoDec *decoder) {
    return decoder->state;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", decBs0__FP8VideoDec);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", setImageTag__FPUiPviii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecBeginPut__FP8VideoDecPPUcPiPPUcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecPutTs__FP8VideoDecllPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", videoDecEndPut__FP8VideoDeci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", cpy2area__FPUciPUciPUciPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecBeginPut__FP8AudioDecPPUcPiPPUcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", audioDecEndPut__FP8AudioDeci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movie", isAudioOK__Fv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1276__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1287__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_318__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_319__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_320__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_321__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_322__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_323__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_584__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_810__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1028__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1029__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1030__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1031__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1032__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1033__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1034__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1035__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1036__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1037__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1038__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1109__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1110__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_1270__3__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movie", at_468__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(frd, 0x4);
INCLUDE_BSS(TexName, 0x4);
INCLUDE_BSS(readBuf, 0x4);
INCLUDE_BSS(writerest, 0x4);
INCLUDE_BSS(readrest, 0x4);
INCLUDE_BSS(isWithAudio, 0x4);
INCLUDE_BSS(isStarted, 0x4);
INCLUDE_BSS(isStrFileInit, 0x4);
INCLUDE_BSS(Loop, 0x4);
INCLUDE_BSS(MpegW, 0x4);
INCLUDE_BSS(MpegH, 0x4);
INCLUDE_BSS(isCountVblank, 0x4);
INCLUDE_BSS(isFrameEnd, 0x4);
INCLUDE_BSS(Cb, 0x4);
INCLUDE_BSS(stepMainStatus, 0x4);
INCLUDE_BSS(stepMainExitFlag, 0x4);
INCLUDE_BSS(cnt_513, 0x4);
INCLUDE_BSS(init_514, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(videoDec, 0xC0);
INCLUDE_BSS(audioDec, 0x60);
INCLUDE_BSS(voBuf, 0x20);
INCLUDE_BSS(infile, 0x40);
INCLUDE_BSS(_0_buf, 0x800);
INCLUDE_BSS(at_344, 0x20);
INCLUDE_BSS(at_349, 0x20);
