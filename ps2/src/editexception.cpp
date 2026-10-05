#include "common.h"
#include "editexception.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", EditExceptionStep__FiP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitNpcCameraReaction__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitS51Thunder__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", S51Thunder__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitFirePowder__FiP6CSceneiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", StepFirePowder__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawFirePowder__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", Create__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", Step__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", GetEmpty__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", CreatePoint__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", CreatePacket__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitGeyserEffect__FiP6CSceneiP9mgCMemory);
CGeyserEffectPoint::CGeyserEffectPoint(void) {
    active = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", __ct__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", StepGeyserEffect__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawGeyserEffect__FP6CScene);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1175__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1176__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1177__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1178__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1184__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1327__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1329__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1330__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_917__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_918__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_919__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_920__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_921__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1084__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1085__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1086__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1143__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1259__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1385__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1386__3__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(rea_chara_id, 0x4);
INCLUDE_BSS(rea_mtn_step, 0x4);
INCLUDE_BSS(thunder_count, 0x4);
INCLUDE_BSS(start_thunder, 0x4);
INCLUDE_BSS(next_thunder_cnt, 0x4);
INCLUDE_BSS(fade_cnt, 0x4);
INCLUDE_BSS(sound_flag, 0x4);
INCLUDE_BSS(sound_cnt, 0x4);
INCLUDE_BSS(FirePowderFlag, 0x4);
INCLUDE_BSS(FirePowderTexb, 0x4);
INCLUDE_BSS(SpriteVis, 0x4);
INCLUDE_BSS(FirePowFrame, 0x4);
INCLUDE_BSS(fire_powder, 0x4);
INCLUDE_BSS(GeyserEffectFlag, 0x4);
INCLUDE_BSS(GeyserEffectTexb, 0x4);
INCLUDE_BSS(GeyserFrame, 0x4);
INCLUDE_BSS(GeyserRndSeed, 0x4);
INCLUDE_BSS(GeyserEffect, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1328__2, 0x10);
