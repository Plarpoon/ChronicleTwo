#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", menu_wmap_analyze_tag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1072__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1081__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1095);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", geo_table_1183);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1342__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1383__2);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_970__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_971__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_972__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_973__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1184__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1185__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1186__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1187__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1188__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1189__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1302__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1303__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1304__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1305__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1306__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1307__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1308__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1309__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1310__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1311__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1312);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1313);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1314);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1498__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1556__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1557__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1674);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1675);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1676);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1677);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1937__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1938__2);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", D_0037B058);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", __vt__13CWorldMapMenu);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumap", at_1343__2);

// Small uninitialised data (.sbss)
unsigned char spi_wmapstack[0x4];
unsigned char spi_wmaparea_tblnum[0x4];
unsigned char spi_wmaparea_tbl[0x4];
unsigned char spi_wmappos_tblnum[0x4];
unsigned char spi_wmappos_tbl[0x4];
unsigned char MapEnableNum[0x4];
unsigned char WorldMapMenuType[0x4];
unsigned char WorldMap_NextLoopNo[0x4];
unsigned char WorldMap_MapNo[0x4];
unsigned char WorldMap_DngFloor[0x4];
unsigned char at_1218__2[0x4];
unsigned char at_1393__2[0x8];
unsigned char WorldMapPtr[0x4];
unsigned char SubSaveData__2[0x4];
unsigned char SubSphidaData[0x4];
unsigned char SphidaMenuMes[0x4];
unsigned char SphidaMenuQus[0x4];
unsigned char SphidaMenuQusDrawFlag[0x4];
unsigned char SphidaScore[0x4];
unsigned char SphidaTex[0x4];
unsigned char SphidaTex2[0x4];
unsigned char SphidaTex_Sys[0x4];
unsigned char SphidaCursor[0x4];
unsigned char SphidaCursorDrawFlag[0x4];
unsigned char SphidaCursorY[0x4];
unsigned char SphidaCursorCount[0x4];
unsigned char SphidaInfoMsgDrawFlag[0x4];
unsigned char SfidaBGXY[0x4];
unsigned char SphidaScoreListY[0x4];
unsigned char SphidaScoreListBarY[0x4];
unsigned char SphidaSelect[0x8];
unsigned char SphidaMenuPhase[0x4];
unsigned char SfidaMakeLine[0x4];
unsigned char SfidaMoveInitFlag[0x8];
unsigned char at_1764__3[0x8];
unsigned char Sfida_NowPlayHorlBlink[0x4];

// Uninitialised data (.bss)
unsigned char WorldMapStack[0x30];
unsigned char SphidaStack[0x30];
unsigned char SphidaMenuTexbk[0x20];
