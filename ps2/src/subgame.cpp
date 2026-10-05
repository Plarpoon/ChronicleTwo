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
void sgCPlayVoice::Open(s32 arg0) {
    if ((*(s32 *)((u8 *)this + 0x0)) > 0) {
        this->Close();
    }
    (*(s32 *)((u8 *)this + 0x0)) = 1;
    (*(s32 *)((u8 *)this + 0x4)) = arg0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
}
void sgCPlayVoice::SetVol(float arg0, float arg1) {
    float var_f12;
    float var_f13;

    var_f12 = arg0;
    var_f13 = arg1;
    if (var_f12 < 0.0f) {
        var_f12 = 0.0f;
    }
    if (!(var_f12 <= 1.0f)) {
        var_f12 = 1.0f;
    }
    (*(float *)((u8 *)this + 0x10)) = var_f12;
    if (var_f13 < 0.0f) {
        var_f13 = var_f12;
    }
    if (!(var_f13 <= 1.0f)) {
        var_f13 = 1.0f;
    }
    (*(float *)((u8 *)this + 0xc)) = var_f13;
}
void sgCPlayVoice::Play(void) {
    (*(s32 *)((u8 *)this + 0x8)) = 1;
}
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
