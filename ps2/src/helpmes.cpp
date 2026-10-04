#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", LoadHelpMes__FP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", GetHepMesInfo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", CreateHelpMes__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", StepHelpMes__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", ShowOffOnceHelpMes__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", DrawHelpMes__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", ShowHelpMes__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", ShowErrorHelpMes__Fii);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", __sinit_helpmes_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", at_799__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", at_800__5);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", D_0037B094);

// Small uninitialised data (.sbss)
unsigned char InitFlag__2[0x4];
unsigned char WindowMode[0x4];
unsigned char ShowOffOnce[0x4];

// Uninitialised data (.bss)
unsigned char HelpMesBuff[0x1000];
unsigned char HelpMes[0x295C];
unsigned char D_01F628BC[0x4];
unsigned char HelpMesInfo[0x20];
