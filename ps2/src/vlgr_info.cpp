#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetVlgrPlaceInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetVlgrPlaceTable__FPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetVillagerInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetVillagerModelName__FiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niNPC__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niNPC_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niPROGRESS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niPROGRESS_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niPLACE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niNOON_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niNIGHT_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niNPC_INFO_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", __ct__13CVillagerInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", niNPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", LoadNPCInfo__FPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", LoadPlaceInfo__FPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiNPC_PLACE_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", __ct__18CVillagerPlaceInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiNPC_PLACE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiNPC_PLACE_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiPLACE_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiMOVE_TO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiWAIT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiMOTION__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiTALK_OFFSET__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiMOVE_MOTION__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiMOVE_SPEED__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiSHADOW__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", vpiGetMotionID__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", giPROG_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", LoadGameInfo__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetGameProgressInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetGameChapter__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", GetGameProgressNum__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", __ct__14CVillagerPlaceFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/vlgr_info", __sinit_vlgr_info_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", ni_tag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", tag__9);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", gi_tag);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_214);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_250);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_351);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_352);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_353__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_354);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_355);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_356__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_357__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_358__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_359__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_364__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_365__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_366__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_367__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_368__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_369__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_370__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_371__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_372__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_373__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_374__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_439__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_450__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_495);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_496);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_497__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_498);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_509);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_555);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_556);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_557);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", D_0037B098);

// Small uninitialised data (.sbss)
unsigned char PlaceInfoNum[0x4];
unsigned char PlaceInfo[0x4];
unsigned char VlgrInfoNum[0x4];
unsigned char VlgrInfo[0x4];
unsigned char ProgressNum[0x4];
unsigned char niStack[0x4];
unsigned char niVlgr[0x4];
unsigned char niProgNum[0x4];
unsigned char niProgTime[0x4];
unsigned char niProgDupliID[0x4];
unsigned char niProgCon[0x4];
unsigned char niProgInfo[0x4];
unsigned char niNowProgInfo[0x4];
unsigned char niPlaceInfo[0x4];
unsigned char niPlaceInfoNum[0x4];
unsigned char niVlgrInfoIdx[0x4];
unsigned char vpiStack[0x4];
unsigned char vpiInfo[0x4];
unsigned char giGamePI[0x4];
unsigned char giStack[0x4];

// Uninitialised data (.bss)
unsigned char VlgrPlace[0x1000];
unsigned char ProgressInfo[0xC00];
