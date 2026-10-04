#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", SwitchNowLoadingThread__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", NowLoadingLoop__FPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", CancelNowLoading__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", CreateNowLoading__FP14NowLoadingInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", NowLoadingBarStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", NowLoadingBarSteEnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", DeleteNowLoading__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", __ct__14NowLoadingInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", InitPauseData__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", InitPause__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseEnable__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", GetPauseFlag__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseStart__FP10PAUSE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseCancel__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseEnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", PauseCount__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", SCElogoFade__FiP9mgCMemory);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nowload", __sinit_nowload_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_832__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_863__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_864__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_912__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_913__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_920__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_1003__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_1068__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", at_1069__6);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", D_0037B080);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nowload", LoopStep);

// Small uninitialised data (.sbss)
unsigned char TheadID__3[0x4];
unsigned char ProgBarWidth[0x4];
unsigned char ProgBarWidthStep[0x4];
unsigned char NextProgBarWidth[0x4];
unsigned char ProgBarCnt[0x4];
unsigned char EndFlag[0x4];
unsigned char cancel_now_loading[0x4];
unsigned char load_skip_img[0x4];
unsigned char PauseFlag__2[0x4];
unsigned char PauseEnableFlag[0x4];
unsigned char PauseCancelCnt[0x4];
unsigned char PauseTexb[0x4];
unsigned char PauseInfo[0x8];
unsigned char InitFlag[0x4];
unsigned char SeCoreVol[0x4];
unsigned char play_time_count[0x4];
unsigned char wave_status[0x4];
unsigned char start_vcount[0x4];

// Uninitialised data (.bss)
unsigned char ThreadStack__3[0x1000];
unsigned char LoadInfo[0x40];
unsigned char SkipImage[0x2800];
unsigned char bgm_status[0x20];
