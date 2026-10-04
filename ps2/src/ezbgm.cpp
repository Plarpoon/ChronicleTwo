#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezbgm", ezBgmInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezbgm", ezBgm__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezbgm", StreamOpenState__6CSoundFv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_32__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_33__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_52__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_53__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezbgm", at_54__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(sbuff__3, 0x40);
INCLUDE_BSS(gCd2, 0x30);
