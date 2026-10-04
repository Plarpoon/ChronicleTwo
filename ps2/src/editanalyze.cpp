#include "common.h"
#include "editanalyze.hpp"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_913__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_964__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_1618__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_1632__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editanalyze", at_1633__3__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1297__4, 0x10);
