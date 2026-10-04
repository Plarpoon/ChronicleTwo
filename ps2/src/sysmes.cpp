#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", GetSystemMessage__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", GetSystemMessage__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", LoadSystemMes__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", GetSystemMesBuffer__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", GetSysMesBuffer__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", CreateSystemMes__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", CreateSystemMes__Fii);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sysmes", __sinit_sysmes_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_482);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_483);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_484);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_485);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_486);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_487);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_488);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_489);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_490);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_491);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_492);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_493);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", at_494);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sysmes", D_0037B000);

// Uninitialised data (.bss)
unsigned char SystemMesStack[0x30];
unsigned char SystemMesBuffer[0xD000];
unsigned char SysMesBuffer[0x13880];
unsigned char SystemMessage[0x2960];
unsigned char SystemMessage2[0x2960];
unsigned char SystemMessage3[0x2960];
