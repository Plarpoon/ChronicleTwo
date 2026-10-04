#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", GetTextureInfo__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", MainTextureInterface__FP9mgCMemoryP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", calcWeaponParamWhp__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", calcWeaponParam2__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", SetDamageParam__FP8CColPrimi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", AddExpWeaponParam__Ffii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", SetSwordBlurEffect__FP11CCharacter2P9mgCMemoryi);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_792__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_793__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_794__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_795__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_796__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_797__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_798__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_799__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_800__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_801__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_802__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_803__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_804__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_819__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_820__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_821__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_822__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_823__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_824__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_825__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_826__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_827__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_828__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_829__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_830__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_831__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_832__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_936__3);

// Small uninitialised data (.sbss)
unsigned char TEX_ShadowTexture[0x4];
unsigned char TEX_SystenFrame[0x4];
unsigned char TEX_SystenFrame2[0x4];
unsigned char TEX_StatusIcon[0x4];
unsigned char TEX_DummyIcon1[0x4];
unsigned char TEX_DummyIcon2[0x4];
unsigned char TEX_SystemEffect1[0x4];
unsigned char TEX_SystemEffect2[0x4];
unsigned char TEX_SystemEffect3[0x4];
unsigned char TEX_SystemEffectSw[0x4];
unsigned char TEX_ExFx_FIRE[0x4];
unsigned char TEX_ExFx_ICE[0x4];
unsigned char TEX_ExFx_THUN[0x4];
