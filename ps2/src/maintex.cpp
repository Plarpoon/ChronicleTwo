#include "common.h"
#include "maintex.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", GetTextureInfo__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", MainTextureInterface__FP9mgCMemoryP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", calcWeaponParamWhp__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", calcWeaponParam2__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", SetDamageParam__FP8CColPrimi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", AddExpWeaponParam__Ffii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", SetSwordBlurEffect__FP11CCharacter2P9mgCMemoryi);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_792__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_793__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_794__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_795__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_796__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_797__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_798__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_799__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_800__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_801__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_802__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_803__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_804__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_819__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_820__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_821__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_822__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_823__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_824__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_825__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_826__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_827__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_828__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_829__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_830__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_831__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_832__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_936__3__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(TEX_ShadowTexture, 0x4);
INCLUDE_BSS(TEX_SystenFrame, 0x4);
INCLUDE_BSS(TEX_SystenFrame2, 0x4);
INCLUDE_BSS(TEX_StatusIcon, 0x4);
INCLUDE_BSS(TEX_DummyIcon1, 0x4);
INCLUDE_BSS(TEX_DummyIcon2, 0x4);
INCLUDE_BSS(TEX_SystemEffect1, 0x4);
INCLUDE_BSS(TEX_SystemEffect2, 0x4);
INCLUDE_BSS(TEX_SystemEffect3, 0x4);
INCLUDE_BSS(TEX_SystemEffectSw, 0x4);
INCLUDE_BSS(TEX_ExFx_FIRE, 0x4);
INCLUDE_BSS(TEX_ExFx_ICE, 0x4);
INCLUDE_BSS(TEX_ExFx_THUN, 0x4);
