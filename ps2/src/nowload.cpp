#include "common.h"
#include "nowload.hpp"
#include "sce/eekernel.h"
#include "mglib.hpp"
#include "mg_texture.hpp"
#include "mainloop.hpp"
#include "scenesnd.hpp"
#include "snd_mngr.hpp"
#include "dataread.hpp"
#include <cstdio>
#include <cstring>

extern int cancel_now_loading;
extern int PauseEnableFlag;
extern int PauseFlag__2;
extern int PauseCancelCnt;
extern int ProgBarCnt;
extern float ProgBarWidthStep;
extern float NextProgBarWidth;
extern int InitFlag;
extern float SeCoreVol;
extern PAUSE_INFO PauseInfo;
extern NowLoadingInfo LoadInfo;
extern int TheadID__3;
extern int EndFlag;
extern NowLoadingStep LoopStep;
extern int play_time_count;
extern int wave_status;
extern int bgm_status[7];
extern int load_skip_img;
extern int PauseTexb;
extern unsigned char SkipImage[0x2800];

// Code (.text)
void SwitchNowLoadingThread() {
    RotateThreadReadyQueue(10);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", NowLoadingLoop__FPv);
void CancelNowLoading() {
    cancel_now_loading = 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", CreateNowLoading__FP14NowLoadingInfo);
void NowLoadingBarStep() {
    ProgBarCnt++;
    if (ProgBarCnt >= LoadInfo.step_count) {
        ProgBarCnt = LoadInfo.step_count;
    }
    NextProgBarWidth = (float)(ProgBarCnt + 1) / (float)LoadInfo.step_count;
    if (NextProgBarWidth > 0.99f) {
        NextProgBarWidth = 1.0f;
    }
}

#ifdef NONMATCHING
void NowLoadingBarSteEnd() {
    ProgBarWidthStep = 0.05f;
    ProgBarCnt = LoadInfo.step_count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", NowLoadingBarSteEnd__Fv);
#endif
void DeleteNowLoading() {
    if (LoopStep == NOW_LOADING_STEP_NONE) {
        return;
    }
    SwitchNowLoadingThread();
    EndFlag = 1;
    SwitchNowLoadingThread();
    while (LoopStep != NOW_LOADING_STEP_END) {
        SwitchNowLoadingThread();
    }
    TerminateThread(TheadID__3);
    DeleteThread(TheadID__3);
    mgTexManager.DeleteBlock(LoadInfo.tex_block);
}
NowLoadingInfo::NowLoadingInfo() {
    tex_block = -1;
    unk_4 = 0;
    step_count = 0;
}
#ifdef NONMATCHING
int InitPauseData() {
    unsigned char image_buffer[0x10000];
    char image_path[64];
    char default_path[] = "img/skip.img";
    int image_size;
    char *path = default_path;
    if (LanguageCode >= 2) {
        sprintf(image_path, "img/%d/skip.img", LanguageCode);
        path = image_path;
    }
    if (LoadFile2(path, image_buffer, &image_size, 0) == 0 || image_size >= (int)sizeof(SkipImage)) {
        return 0;
    }
    memcpy(SkipImage, image_buffer, image_size);
    load_skip_img = 1;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", InitPauseData__Fv);
#endif

#ifdef NONMATCHING
int InitPause(int tex_block) {
    char texture_name[] = "pause_work";
    PauseEnableFlag = 1;
    PauseFlag__2 = 0;
    InitFlag = 0;
    PauseCancelCnt = 0;
    mgTexManager.DeleteBlock(tex_block);
    mgTexManager.EnterTexture(tex_block, texture_name, NULL, mgScreenWidth, mgScreenHeight, 32, NULL, 0, 0);
    if (load_skip_img != 0) {
        mgTexManager.EnterIMGFile(SkipImage, tex_block, NULL, NULL);
    }
    PauseTexb = tex_block;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", InitPause__Fi);
#endif
int PauseEnable(int enable) {
    int previous = PauseEnableFlag;
    PauseEnableFlag = enable;
    return previous;
}

int GetPauseFlag() {
    return PauseFlag__2;
}

#ifdef NONMATCHING
int PauseStart(PAUSE_INFO *info) {
    if (PauseEnableFlag == 0 || PauseCancelCnt > 0) {
        return 0;
    }
    PauseCancelCnt = 10;
    InitFlag = 0;
    PauseFlag__2 = 1;
    PauseInfo = *info;
    SeCoreVol = -1.0f;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseStart__FP10PAUSE_INFO);
#endif

void PauseCancel() {
    PauseFlag__2 = 0;
}
void PauseEnd() {
    if (PauseFlag__2 == 0 || InitFlag <= 0) {
        return;
    }
    PauseFlag__2 = 0;
    if (bgm_status[0] == 1) {
        PauseInfo.scene->RePlayBGM();
    }
    if ((wave_status & 0x1000) != 0) {
        sndStreamRePlay();
    }
    sndPortSqReplay(4);
    sndPortSqReplay(0);
    PlayTimeCount(play_time_count);
    if (SeCoreVol >= 0.0f) {
        sndMasterVolFadeInOut(1, 15, SeCoreVol, 0.0f);
    }
    sndSePlay(GetSystemSndID(), 0x19, 0);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseLoop__Fv);
void PauseCount() {
    PauseCancelCnt--;
    if (PauseCancelCnt < 0) {
        PauseCancelCnt = 0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", SCElogoFade__FiP9mgCMemory);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", __sinit_nowload_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_832__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_863__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_864__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_912__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_913__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_920__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_1003__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_1068__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_1069__6__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", D_0037B080__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", LoopStep__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(TheadID__3, 0x4);
INCLUDE_BSS(ProgBarWidth, 0x4);
INCLUDE_BSS(ProgBarWidthStep, 0x4);
INCLUDE_BSS(NextProgBarWidth, 0x4);
INCLUDE_BSS(ProgBarCnt, 0x4);
INCLUDE_BSS(EndFlag, 0x4);
INCLUDE_BSS(cancel_now_loading, 0x4);
INCLUDE_BSS(load_skip_img, 0x4);
INCLUDE_BSS(PauseFlag__2, 0x4);
INCLUDE_BSS(PauseEnableFlag, 0x4);
INCLUDE_BSS(PauseCancelCnt, 0x4);
INCLUDE_BSS(PauseTexb, 0x4);
INCLUDE_BSS(PauseInfo, 0x8);
INCLUDE_BSS(InitFlag, 0x4);
INCLUDE_BSS(SeCoreVol, 0x4);
INCLUDE_BSS(play_time_count, 0x4);
INCLUDE_BSS(wave_status, 0x4);
INCLUDE_BSS(start_vcount, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(ThreadStack__3, 0x1000);
INCLUDE_BSS(LoadInfo, 0x40);
INCLUDE_BSS(SkipImage, 0x2800);
INCLUDE_BSS(bgm_status, 0x20);
