#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", PrintV__FiiiP10mgCTexture9mgRect_i_iiiP7SP_RGBA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawDrumCounter__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawActiveItemCursor__Fiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawMainUnitStatusBord__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawRoboUnitStatusBord__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawMonsterUnitStatusBord__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawStatusBord__Fv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1048__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1049);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1058__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1059__2);

// Small uninitialised data (.sbss)
unsigned char cur_ang_1005[0x4];
unsigned char init_1006[0x4];
unsigned char palanim_1023[0x4];
unsigned char init_1024[0x4];
unsigned char palanim_1222[0x4];
unsigned char init_1223[0x4];
