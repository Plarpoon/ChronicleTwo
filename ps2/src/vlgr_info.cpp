#include "common.h"
#include "vlgr_info.hpp"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", ni_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", tag__9__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", gi_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_214__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_250__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_351__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_352__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_353__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_354__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_355__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_356__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_357__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_358__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_359__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_364__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_365__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_366__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_367__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_368__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_369__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_370__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_371__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_372__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_373__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_374__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_439__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_450__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_495__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_496__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_497__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_498__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_509__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_555__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_556__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", at_557__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/vlgr_info", D_0037B098__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(PlaceInfoNum, 0x4);
INCLUDE_BSS(PlaceInfo, 0x4);
INCLUDE_BSS(VlgrInfoNum, 0x4);
INCLUDE_BSS(VlgrInfo, 0x4);
INCLUDE_BSS(ProgressNum, 0x4);
INCLUDE_BSS(niStack, 0x4);
INCLUDE_BSS(niVlgr, 0x4);
INCLUDE_BSS(niProgNum, 0x4);
INCLUDE_BSS(niProgTime, 0x4);
INCLUDE_BSS(niProgDupliID, 0x4);
INCLUDE_BSS(niProgCon, 0x4);
INCLUDE_BSS(niProgInfo, 0x4);
INCLUDE_BSS(niNowProgInfo, 0x4);
INCLUDE_BSS(niPlaceInfo, 0x4);
INCLUDE_BSS(niPlaceInfoNum, 0x4);
INCLUDE_BSS(niVlgrInfoIdx, 0x4);
INCLUDE_BSS(vpiStack, 0x4);
INCLUDE_BSS(vpiInfo, 0x4);
INCLUDE_BSS(giGamePI, 0x4);
INCLUDE_BSS(giStack, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(VlgrPlace, 0x1000);
INCLUDE_BSS(ProgressInfo, 0xC00);
