#include "common.h"
#include "gamedata.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetGameDataPt__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", __ct__9CDataItemFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", __ct__11CDataAttachFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", __ct__11CDataWeaponFv);
u8 CDataRoboPart::GetOffsetNo() { return this->offset_no; }
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", __ct__14CDataBreedFishFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", Initialize__9CGameDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATACOMINIT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATACOM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _MES_SYS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _MES_SYS_SPECTOL__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEPNUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP_ST__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP_ST_L__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP2_ST__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP2_ST_L__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP_SPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAWEP_BUILDUP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAITEMINIT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAITEM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAATTACHINIT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAATTACH_ST__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAATTACH_ST2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAATTACH_ST_SP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAROBOINIT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAROBO_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAFISHINIT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAFISH__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAGAURDNUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", _DATAGAURD__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", LoadGameDataAnalyze__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", LoadData__9CGameDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", LoadItemSystemMes__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", InitItemMes__9CGameDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetCommonData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetWeaponData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetAttachData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetRoboData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetFishData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetGuardData__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetDataType__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetDataTypeStartListNo__9CGameDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetCommonItemData__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemInfoData__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetWeaponInfoData__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetRoboPartInfoData__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetBreedFishInfoData__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemFileName__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemFilePath__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemDataType__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemDataAttribute__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", ConvertUsedItemType__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemMessageNo__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemMessage__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetItemIconNo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", SetItemSpectolPoint__FiP11ATTACH_USEDi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", ItemCmdMsgSet__FiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetMenuCommandMsg__FiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", CheckItemEquip__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", SearchItemByName__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetRidePodCore__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", Init_USEITEM_EFFECT__FP14USEITEM_EFFECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", GetUsedItemAfterEffect__FiP14USEITEM_EFFECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", SetPtr__14CItemUseTargetFiPv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamedata", __sinit_gamedata_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", etcitem_spectol_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", gamedata_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", ItemCmdMsgTbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", table_1553__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1018__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1019__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1020__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1021__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1022__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1023__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1024__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1025__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1026__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1027__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1028__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1029__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1030__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1031__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1032__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1033__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1034__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1035__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1036__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1037__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1038__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1039__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1040__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1041__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1048__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1063__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1064__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1065__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1066__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1067__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1068__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1069__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1079__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1283__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1284__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1307__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1308__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1309__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1310__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1311__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", at_1501__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", D_0037AFFC__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamedata", msg_offsettbl_1363__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(gamedata_build_stack, 0x4);
INCLUDE_BSS(comdatapt, 0x4);
INCLUDE_BSS(comdatapt_num, 0x4);
INCLUDE_BSS(SpiWeaponPt, 0x4);
INCLUDE_BSS(SpiItemPt, 0x4);
INCLUDE_BSS(SpiAttach, 0x4);
INCLUDE_BSS(SpiRoboPart, 0x4);
INCLUDE_BSS(SpiFish, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(GameItemDataManage, 0x30);
INCLUDE_BSS(local_com_itemdata, 0x4A40);
INCLUDE_BSS(local_itemdata, 0xA20);
INCLUDE_BSS(local_weapondata, 0x2270);
INCLUDE_BSS(local_attachdata, 0x390);
INCLUDE_BSS(local_robodata, 0x990);
INCLUDE_BSS(local_fishdata, 0x190);
INCLUDE_BSS(local_guarddata, 0x50);
INCLUDE_BSS(local_itemdatano_converttable, 0x400);
INCLUDE_BSS(gamedata_sysword_buffer_1073, 0x2800);
INCLUDE_BSS(filename_1267, 0x20);
INCLUDE_BSS(item_file_path_1288, 0x80);
