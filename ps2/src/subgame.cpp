#include "common.h"
#include "subgame.hpp"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/subgame", at_985__3__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/subgame", D_0037B078__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(SubGame, 0x4);
INCLUDE_BSS(MenuOpenFlag, 0x4);
INCLUDE_BSS(ItemOver, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(GameInfo, 0x30);
