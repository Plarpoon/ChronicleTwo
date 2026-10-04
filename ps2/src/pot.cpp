#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", CalcReflectionVector__FPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Draw__9CFragmentFPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Step__9CFragmentFP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Set__9CFragmentFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Init__9CFragmentFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Clash__5CBPotFPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Step__5CBPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", SetObject2__5CBPotFiP9CMapParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Init__5CBPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", HoldStep__4CPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", FlyStep__4CPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Clear__4CPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Bakuhatsu__4CPotFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Step__4CPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Throw__4CPotFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Hold__4CPotFP9CMapParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pot", Init__4CPotFi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", box_offset);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", iwa0_offset);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", iwa1_offset);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", at_1196);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", at_1323__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", at_1324);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", at_1325__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", at_1326);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pot", at_1438__4);
