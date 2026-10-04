#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", AnalyzeEditMap__FiP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", CountPartsType__FiP8CEditMapPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", CountPartsInfoID__FiP8CEditMapPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", CheckSaku__FP8CEditMapi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", GetTreeNum__FP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", GetHouseParts__FP8CEditMapPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", CheckInfoID__FP8CEditMapii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", GetPartsPos__FP8CEditMapiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", AnalyzeSharlot__FP9CEditDataP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", AnalyzeStera__FP9CEditDataP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", AnalyzeBenietio__FP9CEditDataP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", GetColorType__FP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", AnalyzeHeim__FP9CEditDataP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", AnalyzeMoonFlower__FP9CEditDataP8CEditMap);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", CheckLiveChara__FiP8CEditMapii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editanalyze", EditMapInitEvent__FiP8CEditMap);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_913__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_964__4);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_1618__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_1632__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_1633__3);

// Uninitialised data (.bss)
unsigned char at_1297__4[0x10];
