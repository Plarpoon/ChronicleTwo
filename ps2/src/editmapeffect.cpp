#include "common.h"
#include "editmapeffect.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", DrawFireEffect__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", DrawFireRaster__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", DrawEffect__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmapeffect", AnimeStep__8CEditMapFP12CObjAnimeEnv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmapeffect", at_358__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmapeffect", at_359__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(init_379, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(attr_378, 0x90);
