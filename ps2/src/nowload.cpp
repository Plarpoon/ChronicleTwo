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
