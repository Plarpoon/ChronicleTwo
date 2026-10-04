#include "common.h"
#include "mg_frame.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Initialize__12mgCFrameAttrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", __ct__12mgCFrameAttrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", QuatToMat__FPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", test1__FPA4_fPA4_fPA4_fPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", test2__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", mgInsideScreen__FP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", mgInsideScreen__FP9mgVu0FBOXPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", mgInsideScreen__FP9mgVu0FBOXPA4_fPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", mgInsideScreen__FPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", mgInsideScreen__FPA4_fPA4_fPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetPosition__9mgCObjectFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetPosition__9mgCObjectFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetPosition__9mgCObjectFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetRotation__9mgCObjectFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetRotation__9mgCObjectFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetRotation__9mgCObjectFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetScale__9mgCObjectFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetScale__9mgCObjectFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetScale__9mgCObjectFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Initialize__9mgCObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", __ct__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Initialize__12mgCFrameBaseFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Initialize__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetName__8mgCFrameFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetTransMatrix__8mgCFrameFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetBBox__8mgCFrameFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetBBox__8mgCFrameFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetBSphere__8mgCFrameFPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetFrame__8mgCFrameFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", RemakeBBox__8mgCFrameFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetWorldBBox__8mgCFrameFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetFrameNum__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetParent__8mgCFrameFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetBrother__8mgCFrameFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetChild__8mgCFrameFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", DeleteParent__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetReference__8mgCFrameFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", DeleteReference__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", ClearChildFlag__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetLocalMatrix__8mgCFrameFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetBBoardMatrix__8mgCFrameFiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetLWMatrix__8mgCFrameFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetLWMatrixTopBottom__8mgCFrameFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetInverseMatrix__8mgCFrameFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetTransMatrix__8mgCFrameFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", StrCmp__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", mgFrameNameComp__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SearchFrame__8mgCFrameFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SearchFrameID__8mgCFrameFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetWorldPosition__8mgCFrameFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetWorldPosition0__8mgCFrameFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetWorldDir__8mgCFrameFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetRotation__8mgCFrameFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetRotation__8mgCFrameFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetRotType__8mgCFrameFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetAttrParam__8mgCFrameFR12mgCFrameAttrii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetAttrParamObjAlpha__8mgCFrameFfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", SetAttrParamDraw__8mgCFrameFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Draw__8mgCFrameFPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetDrawRect__8mgCFrameFP9mgVu0FBOXP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", __as__8mgCFrameFR8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Draw__8mgCFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", ChangeParam__9mgCObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", UseParam__9mgCObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", DrawDirect__9mgCObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Draw__9mgCObjectFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", __sinit_mg_frame_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", at_307__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", D_0037AFE0__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", __vt__8mgCFrame__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", __vt__12mgCFrameBase__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", __vt__9mgCObject__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_324, 0x10);
INCLUDE_BSS(at_341, 0x10);
INCLUDE_BSS(at_844, 0x10);
INCLUDE_BSS(dmy_attr, 0x90);
INCLUDE_BSS(at_1118, 0x10);
INCLUDE_BSS(at_1119, 0x10);
