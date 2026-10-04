#include "common.h"
#include "main.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", VSyncCallBack__Fi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", ClearScreen__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", init__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/main", main);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_846__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_847__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_848__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_849__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_850__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_851__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_852__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_853__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_854__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_855__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_856__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/main", at_857__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(vcount__2, 0x4);
