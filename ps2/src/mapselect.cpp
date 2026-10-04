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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", map_sel_type);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", SelectMapName);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", tag__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", select__1049);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", top__1050);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", SedSelData);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_792__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_793__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_794__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_795__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_796__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_797__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_798__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_799__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_800__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_801__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_842__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_859__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_860__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1004__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1005__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1040__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1041__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1042__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1043__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1044__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1045__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1103__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1104__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1105__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1117__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1126);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1127);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1222__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1223__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1224__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1225__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1226__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1227__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1228__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1323__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1324__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1372__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1373__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1469__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1470__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1471__3);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", config_str);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1125);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1128__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1270__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1377__2);

// Small uninitialised data (.sbss)
unsigned char MapNameNum[0x4];
unsigned char map_name[0x4];
unsigned char pMapNameBuff[0x4];
unsigned char pCharBuff[0x4];
unsigned char CharBuff[0x4];
unsigned char now_no[0x4];
unsigned char MenuStack[0x4];
unsigned char SelectMode[0x4];
unsigned char SelectMapType[0x4];
unsigned char select_1009[0x4];
unsigned char init_1010[0x4];
unsigned char SedSel[0x4];
unsigned char EventInfo[0x4];
unsigned char EventInfoNum[0x4];
unsigned char BossEventTop[0x4];
unsigned char sel_event[0x4];
unsigned char top_event[0x4];
unsigned char BossBattleSelFlag[0x4];

// Uninitialised data (.bss)
unsigned char MapNameBuff[0x8000];
unsigned char SelectMapList[0x20];
unsigned char SelectMapNum[0x20];
