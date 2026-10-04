#include "common.h"
#include "intersection.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/intersection", IntersectionPipeYPoly3__FPfPA4_fPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/intersection", IntersectionPipePoly3__FPfPfPA4_fPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/intersection", IntersectionSpherePoly3__FPfPA4_fPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/intersection", IntersectionBox__FPfPfP9mgVu0FBOXPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/intersection", IntersectionBox__FPfPfP9mgVu0FBOXPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/intersection", mt_test__FP12RS_STACKDATAi);

// Uninitialised data (.bss)
INCLUDE_BSS(at_161, 0x10);
