#include "common.h"
#include "editmap.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", Iam__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", Initialize__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", ClearGrid__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", ClearHouse__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", ClearAllParts__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", InitialPlaceParts__8CEditMapFP9CEditData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetPoly__8CEditMapFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", CreateTable__8CEditMapFP9mgCMemoryii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", __ct__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePartsInfo__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePartsInfo__8CEditMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePartsInfoAtID__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePartsInfoAtType__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePartsInfoAtPlaceID__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", eNewPlaceParts__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", eNewHouseInfo__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePlaceParts__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePlaceParts__8CEditMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePlaceIDList__8CEditMapFPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetRotMatrix__8CEditMapFPA4_fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetEditAngle90__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetEditAngle__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", ConvEditAngle__8CEditMapFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", AngleLimit__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetEditPos__8CEditMapFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", CmpEditAlt__8CEditMapFff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetEditAlt__8CEditMapFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetGridPos__8CEditMapFPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetMatrix__8CEditMapFPA4_fPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetInversMatrix__8CEditMapFPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", ConvertParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetSameParts__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", BuildEditParts__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetTotalPolyn__8CEditMapFPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", BuildEditParts__8CEditMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", DeleteEditParts__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", RemoveEditParts__8CEditMapFiPfPQ28CEditMap10RemoveInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", PlaceBurnParts__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", BurnEditParts__8CEditMapFPQ28CEditMap10RemoveInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", PlaceEditParts__8CEditMapFPcPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", PlaceEditParts__8CEditMapFiP13EP_PLACE_INFOPfPfPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", PlaceRiverParts__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", CreatePlaceLog__8CEditMapFiP13EP_PLACE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetNearParts__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetNearParts__8CEditMapFR9mgVu0FBOXPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePlaceParts__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetePlaceParts__8CEditMapFPfPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", MagnetParts__8CEditMapFP14CEditPartsInfoPfPfPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", MagnetParts__8CEditMapFP14CEditPartsInfoPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", CheckWallEditParts__8CEditMapFP14CEditPartsInfoPfiiP13EP_PLACE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", Step__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", PreDraw__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", DrawSub__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapEDIT_RIVER__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapRIVER_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapMASK_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapWATER_PARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapEDIT_RIVER_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapFIX_EPARTS_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapFIX_EPARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapFIX_EPARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapINIT_EPARTS_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapINIT_EPARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", emapINIT_EPARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", LoadEditInfo__8CEditMapFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap", __ct__14CEditPartsInfoFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_830__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_988__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_1837__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", emap_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2257__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2278__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_346__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_449__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_450__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_451__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_452__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_474__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2072__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2073__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2074__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2075__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2076__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2077__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2078__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2079__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2080__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2081__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", at_2082__2__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", __vt__14CEditCollision__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", __vt__8CEditMap__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap", CEditMapName__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(emapMap, 0x4);
INCLUDE_BSS(emapInfo, 0x4);
INCLUDE_BSS(emapStack, 0x4);
INCLUDE_BSS(emapIdx, 0x4);
INCLUDE_BSS(emapNowInfo, 0x4);
INCLUDE_BSS(emapRect, 0x4);
INCLUDE_BSS(emapRectNum, 0x4);
INCLUDE_BSS(emapRectIdx, 0x4);
INCLUDE_BSS(emapFixNum, 0x4);
INCLUDE_BSS(emapInitNum, 0x4);
INCLUDE_BSS(emapFixIdx, 0x4);
INCLUDE_BSS(emapInitIdx, 0x4);
INCLUDE_BSS(emapFix, 0x4);
INCLUDE_BSS(emapInit, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_426, 0x10);
