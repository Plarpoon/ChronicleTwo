#include "common.h"
#include "editinfo.hpp"
#include <cstring>

// Code (.text)
void CEditInfoMngr::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(CEditPartsInfo * *)((u8 *)this + 0x4)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(ePlaceData * *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0x14)) = 0;
}
void CEditInfoMngr::SetePartsInfoTable(CEditPartsInfo * arg0, s32 arg1) {
    (*(s32 *)((u8 *)this + 0x0)) = arg1;
    (*(CEditPartsInfo * *)((u8 *)this + 0x4)) = arg0;
}
void CEditInfoMngr::SeteFixPartsTable(ePlaceData * arg0, s32 arg1) {
    (*(s32 *)((u8 *)this + 0x8)) = arg1;
    (*(ePlaceData * *)((u8 *)this + 0xc)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", GetePartsInfo__13CEditInfoMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", GetePartsInfo__13CEditInfoMngrFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", GetePartsInfoAtID__13CEditInfoMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", GetePartsInfoAtType__13CEditInfoMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapEDIT_PARTS_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapEDIT_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapID__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_ATR__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_MATERIAL__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapCPOINT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapWEIGHT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapGEO_STONE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapMAX_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPAINT_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPAINT_USED__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPLACE_EPS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapMAP_NO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPOLYN__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapGROUND_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapBLOCK_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapRIVER_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapFENCE_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapRECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPLACE_RECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPLACE_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_RECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPARTS_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPUT_RECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapPUT_RECT_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", emapEDIT_PARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", LoadEditInfo__13CEditInfoMngrFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editinfo", GetEvent__8CEditMapFPfiP12MapEventInfo);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", emap_tag__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_368__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_369__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_370__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_371__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_372__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_373__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_374__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_375__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_376__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_377__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_378__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_379__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_380__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_381__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_382__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_383__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_384__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_385__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_386__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_387__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_388__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_389__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_390__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_391__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_392__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_393__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_394__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_395__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editinfo", at_396__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(emapInfo__2, 0x4);
INCLUDE_BSS(emapStack__2, 0x4);
INCLUDE_BSS(emapIdx__2, 0x4);
INCLUDE_BSS(emapMatID, 0x4);
INCLUDE_BSS(emapNowInfo__2, 0x4);
INCLUDE_BSS(emapRectType, 0x4);
INCLUDE_BSS(emapRect__2, 0x4);
INCLUDE_BSS(emapRectNum__2, 0x4);
INCLUDE_BSS(emapRectIdx__2, 0x4);
INCLUDE_BSS(emapFixNum__2, 0x4);
INCLUDE_BSS(emapFixIdx__2, 0x4);
