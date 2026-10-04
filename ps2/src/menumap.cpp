#include "common.h"
#include "menumap.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", _WMAP_POSNUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", _WMAP_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", _WMAP_AREANUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", _WMAP_AREA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", worldmap_analyze__FP9mgCMemoryPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SetMsgBuffer__13CWorldMapMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", KeyStep__13CWorldMapMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", Draw__13CWorldMapMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", WorldMoveInit__FP9mgCMemoryPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", WorldMoveKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", WorldMoveDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaScreListUpdate__FP7CDC2Mesi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaMenuInit__FP9mgCMemoryPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", OmakeSfidaSelect__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaMenuKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaMenuDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaScoreViewInit__FP9mgCMemoryPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaScoreViewKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", SphidaScoreViewDraw__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumap", __sinit_menumap_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", menu_wmap_analyze_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1072__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1081__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1095__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", geo_table_1183__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1342__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1383__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_970__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_971__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_972__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_973__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1184__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1185__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1186__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1187__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1188__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1189__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1302__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1303__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1304__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1305__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1306__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1307__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1308__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1309__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1310__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1311__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1312__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1313__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1314__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1498__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1556__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1557__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1674__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1675__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1676__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1677__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1937__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1938__2__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", D_0037B058__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", __vt__13CWorldMapMenu__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1343__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(spi_wmapstack, 0x4);
INCLUDE_BSS(spi_wmaparea_tblnum, 0x4);
INCLUDE_BSS(spi_wmaparea_tbl, 0x4);
INCLUDE_BSS(spi_wmappos_tblnum, 0x4);
INCLUDE_BSS(spi_wmappos_tbl, 0x4);
INCLUDE_BSS(MapEnableNum, 0x4);
INCLUDE_BSS(WorldMapMenuType, 0x4);
INCLUDE_BSS(WorldMap_NextLoopNo, 0x4);
INCLUDE_BSS(WorldMap_MapNo, 0x4);
INCLUDE_BSS(WorldMap_DngFloor, 0x4);
INCLUDE_BSS(at_1218__2, 0x4);
INCLUDE_BSS(at_1393__2, 0x8);
INCLUDE_BSS(WorldMapPtr, 0x4);
INCLUDE_BSS(SubSaveData__2, 0x4);
INCLUDE_BSS(SubSphidaData, 0x4);
INCLUDE_BSS(SphidaMenuMes, 0x4);
INCLUDE_BSS(SphidaMenuQus, 0x4);
INCLUDE_BSS(SphidaMenuQusDrawFlag, 0x4);
INCLUDE_BSS(SphidaScore, 0x4);
INCLUDE_BSS(SphidaTex, 0x4);
INCLUDE_BSS(SphidaTex2, 0x4);
INCLUDE_BSS(SphidaTex_Sys, 0x4);
INCLUDE_BSS(SphidaCursor, 0x4);
INCLUDE_BSS(SphidaCursorDrawFlag, 0x4);
INCLUDE_BSS(SphidaCursorY, 0x4);
INCLUDE_BSS(SphidaCursorCount, 0x4);
INCLUDE_BSS(SphidaInfoMsgDrawFlag, 0x4);
INCLUDE_BSS(SfidaBGXY, 0x4);
INCLUDE_BSS(SphidaScoreListY, 0x4);
INCLUDE_BSS(SphidaScoreListBarY, 0x4);
INCLUDE_BSS(SphidaSelect, 0x8);
INCLUDE_BSS(SphidaMenuPhase, 0x4);
INCLUDE_BSS(SfidaMakeLine, 0x4);
INCLUDE_BSS(SfidaMoveInitFlag, 0x8);
INCLUDE_BSS(at_1764__3, 0x8);
INCLUDE_BSS(Sfida_NowPlayHorlBlink, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(WorldMapStack, 0x30);
INCLUDE_BSS(SphidaStack, 0x30);
INCLUDE_BSS(SphidaMenuTexbk, 0x20);
