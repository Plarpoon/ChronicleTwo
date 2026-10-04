#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", mapinfo_tag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", add_mapinfo_tag);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_360);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_361);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_362);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_363);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_364);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_365);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_366);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_367);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_368);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_369__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_370__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_371);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_372);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_373);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_374);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_375);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_376);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_377);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_378);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_379);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_380);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_381);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_382__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_704);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_705);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_706);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_707);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_708);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_709);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_710);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_711);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_712);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapinfo", at_713__2);

// Small uninitialised data (.sbss)
unsigned char MapInfo[0x4];
unsigned char MapInfoStack[0x4];
unsigned char now_img_num[0x4];
unsigned char now_pcp_num[0x4];
unsigned char LightingInfo[0x4];
