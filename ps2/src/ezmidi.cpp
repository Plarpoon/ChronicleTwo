#include "common.h"
#include "ezmidi.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezmidi", ezMidiInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezmidi", ezMidi__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezmidi", ezTransToIOP2__FPvPvi);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezmidi", at_33__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(sbuff__2, 0x40);
INCLUDE_BSS(gCd, 0x30);
INCLUDE_BSS(transData, 0x10);
