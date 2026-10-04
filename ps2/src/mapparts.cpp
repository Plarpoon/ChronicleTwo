#include "common.h"
#include "mapparts.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", Initialize__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SetName__9CMapPartsFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SetPartsName__9CMapPartsFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", AddPiece__9CMapPartsFP17CList_9CMapPiece_);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SearchPiece__9CMapPartsFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SearchPieceColType__9CMapPartsFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetPoly__9CMapPartsFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetColPoly__9CMapPartsFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetCameraPoly__9CMapPartsFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", UpDatePosition__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SetColor__9CMapPartsFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetColor__9CMapPartsFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetDefColor__9CMapPartsFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", UpdateColor__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", PreDraw__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", DrawSub__9CMapPartsFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", DrawDirect__9CMapPieceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", Draw__9CMapPieceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", DrawStep__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", CreateBoundBox__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", CheckColBox__9CMapPartsFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetBBox__9CMapPartsFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetBoundBox__9CMapPartsFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetBoundSphere__9CMapPartsFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetLWMatrix__9CMapPartsFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", InsideScreen__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", InsideScreen__9CMapPartsFP10COcclusioni);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", InScreenFunc__9CMapPartsFP16InScreenFuncInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", DrawScreenFunc__9CMapPartsFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", Step__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", AnimeStep__9CMapPartsFP15CFuncPointCheckP12CObjAnimeEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", StepFuncPoint__9CMapPartsFR15CFuncPointCheck);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", CopyFuncPointCheck__9CMapPartsFR15CFuncPointCheck);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", Copy__9CMapPartsFR9CMapPartsP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", AssignFuncAnime__9CMapPartsFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", Initialize__17CList_9CObjAnime_Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", Initialize__15CMapTreasureBoxFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", AssignFuncPoint__15CMapTreasureBoxFP10CFuncPointP9CMapParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetWorldPosition__15CMapTreasureBoxFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetMotionStatus__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetNowMotionName__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetNowFrameWait__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SetNowFrame__11CCharacter2Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetNowFrame__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetStep__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SetFadeFlag__11CCharacter2Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetFadeFlag__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", GetCopySize__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapparts", SetPosition__11CCharacter2Ffff);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapparts", at_244__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapparts", __vt__15CMapTreasureBox__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapparts", __vt__17CList_9CObjAnime___DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapparts", __vt__9CMapParts__DATA);
