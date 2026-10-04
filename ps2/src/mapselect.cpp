#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", mlMAP_NAME_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", mlMAP_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", LoadMapName__FiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapNameInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapPath__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapType__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapAreaNo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapSelType__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapSndDataID__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapName__FiPPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", SearchMapNo__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapTitle__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetAddMapPath__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", InitMapSelect__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", MapTypeSelect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", MapSelect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", MapSelectLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", InitSaveDataEdit__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", SaveDataEditLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", EventViewLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", LoadEventViewData__FP1P9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetLine__FPPcPcPc__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", AtraMiriaOnOff__FiP11CCharacter2i);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", map_sel_type__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", SelectMapName__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", tag__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", select__1049__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", top__1050__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", SedSelData__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_792__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_793__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_794__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_795__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_796__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_797__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_798__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_799__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_800__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_801__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_842__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_859__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_860__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1004__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1005__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1040__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1041__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1042__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1043__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1044__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1045__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1103__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1104__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1105__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1117__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1126__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1127__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1222__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1223__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1224__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1225__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1226__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1227__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1228__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1323__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1324__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1372__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1373__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1469__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1470__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1471__3__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", config_str__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1125__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1128__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1270__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1377__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MapNameNum, 0x4);
INCLUDE_BSS(map_name, 0x4);
INCLUDE_BSS(pMapNameBuff, 0x4);
INCLUDE_BSS(pCharBuff, 0x4);
INCLUDE_BSS(CharBuff, 0x4);
INCLUDE_BSS(now_no, 0x4);
INCLUDE_BSS(MenuStack, 0x4);
INCLUDE_BSS(SelectMode, 0x4);
INCLUDE_BSS(SelectMapType, 0x4);
INCLUDE_BSS(select_1009, 0x4);
INCLUDE_BSS(init_1010, 0x4);
INCLUDE_BSS(SedSel, 0x4);
INCLUDE_BSS(EventInfo, 0x4);
INCLUDE_BSS(EventInfoNum, 0x4);
INCLUDE_BSS(BossEventTop, 0x4);
INCLUDE_BSS(sel_event, 0x4);
INCLUDE_BSS(top_event, 0x4);
INCLUDE_BSS(BossBattleSelFlag, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(MapNameBuff, 0x8000);
INCLUDE_BSS(SelectMapList, 0x20);
INCLUDE_BSS(SelectMapNum, 0x20);
