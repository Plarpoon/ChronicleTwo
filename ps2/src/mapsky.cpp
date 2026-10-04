#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_387__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", tag__2);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_386);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_457);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_462);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_463);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_464);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_465);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_466);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_467);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapsky", at_468);

// Small uninitialised data (.sbss)
unsigned char skyInfo[0x4];
unsigned char skyAnmNum[0x4];
unsigned char skybAnmNum[0x4];
