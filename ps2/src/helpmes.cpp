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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", at_799__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", at_800__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", D_0037B094__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(InitFlag__2, 0x4);
INCLUDE_BSS(WindowMode, 0x4);
INCLUDE_BSS(ShowOffOnce, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(HelpMesBuff, 0x1000);
INCLUDE_BSS(HelpMes, 0x295C);
INCLUDE_BSS(D_01F628BC, 0x4);
INCLUDE_BSS(HelpMesInfo, 0x20);
