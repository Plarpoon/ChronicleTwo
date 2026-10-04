#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezbgm", ezBgmInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezbgm", ezBgm__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezbgm", StreamOpenState__6CSoundFv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_32);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_33__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_52);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_53);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_54);

// Uninitialised data (.bss)
unsigned char sbuff__3[0x40];
unsigned char gCd2[0x30];
