#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngGetDebugInfo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugStart__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugExit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", Initialize__12CTreasureBoxFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DBGCMD_ReloadEnemy__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo2__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawDebugWindow__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", __sinit_dng_debug_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", command_str);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", command_int);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_871);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_872);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_873__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_874);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_875);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_876);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_877);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_878);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_879);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_880);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_881);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_882);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_968);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_969);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_970);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_971);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_972);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_973__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_974__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_975);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1103);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1104);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1105);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1106);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1107);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1132__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1133__2);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", D_0037B010);

// Uninitialised data (.bss)
unsigned char dbFont[0xC0];
unsigned char dbinfo[0x20];
