#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", InitSubGame__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", SubGameRunning__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", GetSubGameNo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", GetNowSubGameInfo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgMenuOpenEnable__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgSetMenuOpenEnableFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgGetItemOver__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgGetItemOverReset__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgGetItemOverFlagOn__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgInitSubGame__FiP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgLoopSubGame__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgLoopSubGame2__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgExitSubGame__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgRestartSubGame__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgBreakSubGame__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgDrawSubGameMap__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgDrawSubGameCharaShadow__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgDrawSubGameChara__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgDrawSubGameEffect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", sgDrawSubGameSystem__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", Open__12sgCPlayVoiceFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", SetVol__12sgCPlayVoiceFff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", Play__12sgCPlayVoiceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", Step__12sgCPlayVoiceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", Close__12sgCPlayVoiceFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/subgame", __sinit_subgame_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/subgame", at_985__3);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/subgame", D_0037B078);

// Small uninitialised data (.sbss)
unsigned char SubGame[0x4];
unsigned char MenuOpenFlag[0x4];
unsigned char ItemOver[0x4];

// Uninitialised data (.bss)
unsigned char GameInfo[0x30];
