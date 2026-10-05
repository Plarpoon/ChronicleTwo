#include "common.h"
#include "mapsky.hpp"
#include <cstring>

// Code (.text)
void CMapSky::Initialize(void) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    struct temp_a3_champs_4de5e1 *temp_a3;
    struct temp_t0_champs_4de5e1 *temp_t0;

    var_a2 = 0;
    var_a3 = 0;
    do {
        temp_t0 = (struct temp_t0_champs_4de5e1 *) ((u8 *) this + var_a3);
        var_a2 += 1;
        (*(s32 *)((u8 *)temp_t0 + 0x0)) = 0;
        (*(s32 *)((u8 *)temp_t0 + 0x30)) = 0;
        var_a3 += 4;
        (*(s32 *)((u8 *)temp_t0 + 0x60)) = 0;
        (*(s32 *)((u8 *)temp_t0 + 0x40)) = 0;
        (*(s32 *)((u8 *)temp_t0 + 0x10)) = 0;
        (*(s32 *)((u8 *)temp_t0 + 0x50)) = 0;
        (*(s32 *)((u8 *)temp_t0 + 0x20)) = 0;
        (*(s32 *)((u8 *)temp_t0 + 0x70)) = -1;
    } while (var_a2 < 4);
    var_a1 = 0;
    var_a2_2 = 0;
    do {
        temp_a3 = (struct temp_a3_champs_4de5e1 *) ((u8 *) this + var_a2_2);
        var_a1 += 8;
        (*(s32 *)((u8 *)temp_a3 + 0x88)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0x8c)) = 0;
        var_a2_2 += 0x40;
        (*(s32 *)((u8 *)temp_a3 + 0x90)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0x94)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0x98)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0x9c)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xa0)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xa4)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xa8)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xac)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xb0)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xb4)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xb8)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xbc)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xc0)) = 0;
        (*(s32 *)((u8 *)temp_a3 + 0xc4)) = 0;
    } while (var_a1 < 0x10);
    (*(s32 *)((u8 *)this + 0x80)) = 0;
    (*(s32 *)((u8 *)this + 0x84)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", DrawSkyBack__7CMapSkyFPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", DrawSky__7CMapSkyFPfPfPfiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", LoadPack__7CMapSkyFPUiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapsky", LoadSkyPack__FP12MAP_SKY_INFOPci);
s32 CheckSkyID(s32 i) {
    s32 r;
    if (i < 0 || i >= 4) r = 0; else r = 1;
    return r;
}
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
