#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", Initialize__16CDngFloorManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _TREE_MAPINFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _GLID_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOT_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_LINK__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_OPTION__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_KEYROOM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_TEXNO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_FLOOR_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_FLOOR_INFO2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", _ROOM_TITLE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", AnalyzeFile__16CDngFloorManagerFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", LoadDataTable__16CDngFloorManagerFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetDngMapFloorGlidInfo__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", IsGeoStone__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetSphedaPrize__16CDngFloorManagerFiiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetSphedaPrize__16CDngFloorManagerFiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", IsPlaySubGame__16CDngFloorManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", IsSealFloor__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", IsClearMostFastDestroy__16CDngFloorManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", IsClearPractice__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetDngMapFloorInfo__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetActiveFloorInfo__16CDngFloorManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", RelationGlid__16CDngFloorManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", CheckDrawGlidInfo__16CDngFloorManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetNextGlid__16CDngFloorManagerFP9GLID_INFOPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetNextRoom__16CDngFloorManagerFiiP9GLID_INFOiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetKeyNextRoom__16CDngFloorManagerFiiP9GLID_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetDngMapNextFloorID__16CDngFloorManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetFloorTitle__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetDngMapNextRoot__16CDngFloorManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", GetCountSphedaClear__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngfloor", CheckFishingRecord__Ff);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_886__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", D_0036178C);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", offsetTable_911);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", tree_map_tag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", diff_conditiontable_1102);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", check_bittable_1123);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", cbit_1158);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1259__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", search_tbl_1366);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", search_tbl_1370);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", search_tbl_1372);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1395__4);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_882__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_883__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_884__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_885__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_942__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_943__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_944__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_945__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_946__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_947__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_948__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_949__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_950__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_951__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_952__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_976__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_977__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_978__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1200__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1468__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1469__5);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_938__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", fl_t_1467);

// Small uninitialised data (.sbss)
unsigned char tree_dngmap[0x4];
unsigned char tree_glid_info[0x4];
unsigned char tree_spi_stack[0x4];
unsigned char tree_spi_rootinfo[0x4];
unsigned char tree_spi_roominfo[0x4];
unsigned char menu_dng_debug_glidcnt[0x4];
