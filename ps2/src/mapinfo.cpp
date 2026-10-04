#include "common.h"
#include "mapinfo.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", Initialize__11CCameraInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", GetDrawInfo__11CCameraInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", Initialize__8CMapInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", GetImgName__8CMapInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", GetPCPName__8CMapInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", GetMapFile__8CMapInfoFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", GetAddMapFile__8CMapInfoFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", GetLightingInfo__8CMapInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapIMG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapPCP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapACTIVE_LIGHT_SET__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapLIGHT_SET__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapFOV__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapBGCOLOR__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapBGCOLOR2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapAMBIENT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapLIGHT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapPLIGHT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapFOG_ENABLE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapFOG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapLIGHT_SET_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapFLOOR__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapCHARA_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapTIME_FLAG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapTIME_LIGHT_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapDEF_FOOT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapSKY_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapLENS_FLARE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapTIME_CFADE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapALL_SCISSOR__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", mapCHARA_LIGHT_ADJUST__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", LoadMapInfo__8CMapInfoFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", __ct__16CMapLightingInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", amapIMG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", amapPCP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", AddMapInfo__8CMapInfoFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapinfo", OutputLightData__8CMapInfoFPc);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", mapinfo_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", add_mapinfo_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_360__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_361__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_362__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_363__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_364__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_365__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_366__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_367__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_368__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_369__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_370__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_371__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_372__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_373__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_374__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_375__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_376__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_377__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_378__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_379__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_380__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_381__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_382__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_704__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_705__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_706__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_707__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_708__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_709__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_710__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_711__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_712__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_713__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MapInfo, 0x4);
INCLUDE_BSS(MapInfoStack, 0x4);
INCLUDE_BSS(now_img_num, 0x4);
INCLUDE_BSS(now_pcp_num, 0x4);
INCLUDE_BSS(LightingInfo, 0x4);
