#include "common.h"
#include "gameutil.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", QuatSlerp__FPfPffPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc__FP8mgCFramefP8Mot_ListP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", testVUnew__FPA4_fPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", SetMotionTime__FP8mgCFrameP14tagMOTION_TYPEfP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", ChangeMotion__FP8mgCFrameP14tagMOTION_TYPEUiUifP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", DeformMesh__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFb);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", SetKeyFrame__FP8Mot_ListP20FRAME_VECTOR_EX_DATAP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", ChangeWeight__FP8Mot_ListP9mgCMemoryPUciP12tagFRAME_INFP12mgCVisualMDTP8mgCFrameP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CreateAnimeDataEX__FP14tagMOTION_TYPEP9mgCMemoryP16MOTION_FILE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryPP12tagFRAME_INF);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHit__FP6CCPolyiPfPfPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHit__FP13CollisionInfoPfPfPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitVertical__FP6CCPolyiPffPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitVertical__FP13CollisionInfoPffPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHits__FP6CCPolyiPfPfiPiPA4_fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHits__FP13CollisionInfoPfPfiPiPA4_fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitsPipeY__FP6CCPolyiPffiPiPA4_fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitsPipe__FP6CCPolyiPfPfiPiPA4_fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitsSphere__FP6CCPolyiPfiPiPA4_fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MoveCheck__FPfPfPfP13MoveCheckInfoP6CCPolyii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", GetFootPoly__FPffP6CCPolyPfP6CCPolyii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", GetCPolyAttr__FP13MoveCheckInfoPfPffP6CCPolyii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckWidth__FP6CCPolyiPffPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckWidthPipe__FP6CCPolyiPffPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CreateCharaCPoly__FP6CCPolyiPfPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", LinerInterpolation__Ffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", LinerInterpolationI__Fiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", RollPos__FPfPffPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckPosInOutForRect__FP4RECTii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", GetDisPosToRect__FP4RECTii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckPosInOutFor2P__Fffffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CalcIntersectionPointLineAndLine__FffffffffPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CalcIntersectionPoint2PAnd2P__FffffffffPfPf);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gameutil", at_966__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gameutil", at_967__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(OldSkinFrame, 0x4);
INCLUDE_BSS(vert_845, 0x10);
INCLUDE_BSS(vert_915, 0x10);
INCLUDE_BSS(nml_916, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(def_vrtx, 0x3200);
INCLUDE_BSS(def_nml, 0x10);
INCLUDE_BSS(tmp_SkinMatrix_847, 0x40);
INCLUDE_BSS(tmp_SkinMatrix_inv_848, 0x40);
INCLUDE_BSS(tmp_ChrMatrix_849, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_851, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_inv_852, 0x40);
INCLUDE_BSS(tmp_SkinMatrix_917, 0x40);
INCLUDE_BSS(tmp_SkinMatrix_inv_918, 0x40);
INCLUDE_BSS(tmp_ChrMatrix_919, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_921, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_inv_922, 0x40);
INCLUDE_BSS(at_945, 0x10);
