#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", VSyncCallBack__Fi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", ClearScreen__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", init__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", main);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_846);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_847);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_848);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_849);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_850);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_851);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_852);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_853);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_854);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_855);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_856);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_857);

// Small uninitialised data (.sbss)
unsigned char vcount__2[0x4];
