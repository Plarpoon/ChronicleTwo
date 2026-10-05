#include "common.h"
#include "dngfloor.hpp"

// Code (.text)
void CDngFloorManager::Initialize(void) {
    dng_no = 0;
    glid_info = NULL;
    glid_num = 0;
    glid_w = 0;
    glid_h = 0;
}
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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_886__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", D_0036178C__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", offsetTable_911__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", tree_map_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", diff_conditiontable_1102__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", check_bittable_1123__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", cbit_1158__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1259__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", search_tbl_1366__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", search_tbl_1370__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", search_tbl_1372__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1395__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_882__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_883__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_884__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_885__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_942__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_943__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_944__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_945__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_946__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_947__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_948__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_949__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_950__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_951__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_952__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_976__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_977__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_978__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1200__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1468__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_1469__5__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", at_938__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngfloor", fl_t_1467__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(tree_dngmap, 0x4);
INCLUDE_BSS(tree_glid_info, 0x4);
INCLUDE_BSS(tree_spi_stack, 0x4);
INCLUDE_BSS(tree_spi_rootinfo, 0x4);
INCLUDE_BSS(tree_spi_roominfo, 0x4);
INCLUDE_BSS(menu_dng_debug_glidcnt, 0x4);
