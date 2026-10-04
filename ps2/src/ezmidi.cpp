#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezmidi", ezMidiInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezmidi", ezMidi__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/ezmidi", ezTransToIOP2__FPvPvi);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/ezmidi", at_33);

// Uninitialised data (.bss)
unsigned char sbuff__2[0x40];
unsigned char gCd[0x30];
unsigned char transData[0x10];
