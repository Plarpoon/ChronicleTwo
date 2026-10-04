#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetFishingMode__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetFishingMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetWaterLevel__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetWaterLevel__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetActiveHariObj__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetActiveUkiObj__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ExtendLine__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetNowLineLength__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetMinLineLength__Fv);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetNextChanceCnt__Fv);
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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_975__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_985__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_986__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1797);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1798);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_896__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_897__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_898__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_899__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_900__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_901__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_902__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_903__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1503__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1564);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", D_0037B08C);

// Small uninitialised data (.sbss)
unsigned char WaterLevel[0x4];
unsigned char LineTop[0x4];
unsigned char LineTopDist[0x4];
unsigned char CastingLureFlag[0x4];
unsigned char CastingLureTime[0x4];
unsigned char AddLineSpeed[0x4];
unsigned char BattleFlag[0x4];
unsigned char BattleLineDist[0x4];
unsigned char ShowHari[0x4];
unsigned char LureLessFlag[0x4];
unsigned char NowMode[0x4];
unsigned char NowFishSpeed[0x4];
unsigned char NowFishRot[0x4];
unsigned char ActionChanceNextCnt[0x4];
unsigned char ActionChanceCnt[0x4];
unsigned char ActionChanceDir[0x4];

// Uninitialised data (.bss)
unsigned char RodPoint[0xF0];
unsigned char RodPointDist[0x50];
unsigned char SaoFrame[0x20];
unsigned char SaoDist[0x20];
unsigned char LinePoint[0xC00];
unsigned char LurePoint[0x90];
unsigned char FlyingPoint[0x30];
unsigned char FishPoint[0x30];
unsigned char CastingPoint[0x10];
unsigned char ReleasePoint[0x10];
unsigned char BattleStartPos[0x10];
unsigned char LureObj[0x3D0];
unsigned char UkiObj[0x3D0];
unsigned char HariObj[0x3D0];
unsigned char ChanceBarPos[0x10];
