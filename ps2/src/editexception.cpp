#include "common.h"

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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", __ct__18CGeyserEffectPointFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", __ct__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", StepGeyserEffect__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawGeyserEffect__FP6CScene);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1175__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1176__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1177__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1178__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1184__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1327);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1329);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1330);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_917__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_918__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_919__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_920__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_921__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1084__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1085);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1086);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1143__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1259);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1385__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1386__3);

// Small uninitialised data (.sbss)
unsigned char rea_chara_id[0x4];
unsigned char rea_mtn_step[0x4];
unsigned char thunder_count[0x4];
unsigned char start_thunder[0x4];
unsigned char next_thunder_cnt[0x4];
unsigned char fade_cnt[0x4];
unsigned char sound_flag[0x4];
unsigned char sound_cnt[0x4];
unsigned char FirePowderFlag[0x4];
unsigned char FirePowderTexb[0x4];
unsigned char SpriteVis[0x4];
unsigned char FirePowFrame[0x4];
unsigned char fire_powder[0x4];
unsigned char GeyserEffectFlag[0x4];
unsigned char GeyserEffectTexb[0x4];
unsigned char GeyserFrame[0x4];
unsigned char GeyserRndSeed[0x4];
unsigned char GeyserEffect[0x4];

// Uninitialised data (.bss)
unsigned char at_1328__2[0x10];
