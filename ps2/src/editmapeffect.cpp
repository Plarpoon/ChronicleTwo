#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", DrawFireEffect__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", DrawFireRaster__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", DrawEffect__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", AnimeStep__8CEditMapFP12CObjAnimeEnv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmapeffect", at_358__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmapeffect", at_359);

// Small uninitialised data (.sbss)
unsigned char init_379[0x4];

// Uninitialised data (.bss)
unsigned char attr_378[0x90];
