#include "common.h"
#include "dng_status.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", PrintV__FiiiP10mgCTexture9mgRect_i_iiiP7SP_RGBA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawDrumCounter__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawActiveItemCursor__Fiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawMainUnitStatusBord__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawRoboUnitStatusBord__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawMonsterUnitStatusBord__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawStatusBord__Fv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1048__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1049__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1058__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1059__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(cur_ang_1005, 0x4);
INCLUDE_BSS(init_1006, 0x4);
INCLUDE_BSS(palanim_1023, 0x4);
INCLUDE_BSS(init_1024, 0x4);
INCLUDE_BSS(palanim_1222, 0x4);
INCLUDE_BSS(init_1223, 0x4);
