#include "common.h"
#include "fishingobj.hpp"
#include <cstdlib>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetFishingMode__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetFishingMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetWaterLevel__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetWaterLevel__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetActiveHariObj__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetActiveUkiObj__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ExtendLine__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetNowLineLength__Fv);
float GetMinLineLength(void) {
    return 25.0f;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitRodPoint__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetTriPose__FPA4_fPA4_fPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetHariPos__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetUkiPos__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", PullUki__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetShowHari__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetShowHari__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetLurePose__FP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetUkiPose__FP8mgCFrameP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", CastingLure__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", EndCastingLure__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", CatchLine__FPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SlowLineVelo__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ResetLineVelo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ResetLine__FPf);
s32 GetNextChanceCnt(void) {
    return (rand() % 80) + 0x3C;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitFishBattle__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", EndFishBattle__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", CheckRodActionChance__FiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", FishBattle__FP6CSceneP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetFishPosVelo__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", BindFishObj__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", RodStep__FP6CSceneP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", BindPosition__FPfPfff__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", DrawFishingLine__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", DrawFishingActionChance__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitLureObj__FiP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitUkiObj__FiP8mgCFrameP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", MovePoint__8CFishObjFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", FloatPoint__8CFishObjFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", BindStep__8CFishObjFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", Correct__8CFishObjFP6CCPolyif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ParaBlend__FPffPA4_fi);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", __sinit_fishingobj_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_975__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_985__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_986__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1797__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1798__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_896__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_897__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_898__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_899__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_900__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_901__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_902__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_903__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1503__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1564__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", D_0037B08C__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(WaterLevel, 0x4);
INCLUDE_BSS(LineTop, 0x4);
INCLUDE_BSS(LineTopDist, 0x4);
INCLUDE_BSS(CastingLureFlag, 0x4);
INCLUDE_BSS(CastingLureTime, 0x4);
INCLUDE_BSS(AddLineSpeed, 0x4);
INCLUDE_BSS(BattleFlag, 0x4);
INCLUDE_BSS(BattleLineDist, 0x4);
INCLUDE_BSS(ShowHari, 0x4);
INCLUDE_BSS(LureLessFlag, 0x4);
INCLUDE_BSS(NowMode, 0x4);
INCLUDE_BSS(NowFishSpeed, 0x4);
INCLUDE_BSS(NowFishRot, 0x4);
INCLUDE_BSS(ActionChanceNextCnt, 0x4);
INCLUDE_BSS(ActionChanceCnt, 0x4);
INCLUDE_BSS(ActionChanceDir, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(RodPoint, 0xF0);
INCLUDE_BSS(RodPointDist, 0x50);
INCLUDE_BSS(SaoFrame, 0x20);
INCLUDE_BSS(SaoDist, 0x20);
INCLUDE_BSS(LinePoint, 0xC00);
INCLUDE_BSS(LurePoint, 0x90);
INCLUDE_BSS(FlyingPoint, 0x30);
INCLUDE_BSS(FishPoint, 0x30);
INCLUDE_BSS(CastingPoint, 0x10);
INCLUDE_BSS(ReleasePoint, 0x10);
INCLUDE_BSS(BattleStartPos, 0x10);
INCLUDE_BSS(LureObj, 0x3D0);
INCLUDE_BSS(UkiObj, 0x3D0);
INCLUDE_BSS(HariObj, 0x3D0);
INCLUDE_BSS(ChanceBarPos, 0x10);
