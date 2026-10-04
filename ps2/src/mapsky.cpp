#include "common.h"
#include "mapsky.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", Initialize__7CMapSkyFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", DrawSkyBack__7CMapSkyFPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", DrawSky__7CMapSkyFPfPfPfiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", LoadPack__7CMapSkyFPUiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", LoadSkyPack__FP12MAP_SKY_INFOPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", CheckSkyID__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SKY_IMG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SKY_MDS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SUN_MDS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SKYB_MDS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SKY_BG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SKY_ANIME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", _SKYB_ANIME__FP9SPI_STACKi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_387__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", tag__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_386__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_457__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_462__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_463__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_464__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_465__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_466__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_467__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_468__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(skyInfo, 0x4);
INCLUDE_BSS(skyAnmNum, 0x4);
INCLUDE_BSS(skybAnmNum, 0x4);
