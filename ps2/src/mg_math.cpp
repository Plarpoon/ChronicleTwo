#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgFotI4__FPiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgCreateBox8__FPA4_fPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgZeroVector__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgZeroVectorW__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgClipBoxVertex__FPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgClipBox__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgClipBoxW__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgClipInBox__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgClipInBoxW__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgAddVector__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgSubVector__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgNormalizeVector__FPfPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorMin__FPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorMin__FPfPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorMaxMin__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorMaxMin__FPfPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorMaxMin__FPfPfPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgBoxMaxMin__FP9mgVu0FBOXP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgPlaneNormal__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistPlanePoint__FPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistLinePoint__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgReflectionPlane__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgIntersectionSphereLine0__FfPfPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgIntersectionSphereLine__FPfPfPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgIntersectionPoint_line_poly3__FPfPfPfPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgCheckPointPoly3_XYZ__FPfPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgCheckPointPoly3_XZ__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", Check_Point_Poly3__Fffffffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVector__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVectorXZ__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVector2__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVector__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVectorXZ__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVector2__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgDistVectorXZ2__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgUnitMatrix__FPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgZeroMatrix__FPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", MulMatrix3__FPA4_fPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgMulMatrix__FPA4_fPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgInversMatrix__FPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgRotMatrixX__FPA4_ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgRotMatrixY__FPA4_ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgRotMatrixZ__FPA4_ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgRotMatrixXYZ__FPA4_fPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgCreateMatrixPY__FPA4_fPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgLookAtMatrixZ__FPA4_fPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgShadowMatrix__FPA4_fPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgApplyMatrixN__FPA4_fPA4_fPA4_fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgApplyMatrixN_MaxMin__FPA4_fPA4_fPA4_fiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorMinMaxN__FPfPfPA4_fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgApplyMatrix__FPfPfPA4_fPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgVectorInterpolate__FPfPfPffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgAngleInterpolate__Ffffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgAngleCmp__Ffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgAngleLimit__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgRnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgNRnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgCreateSinTable__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgSinf__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_math", mgCosf__Ff);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_math", sin_table_num);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_math", sin_table_unit_1);

// Uninitialised data (.bss)
unsigned char SinTable[0x1000];
