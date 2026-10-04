#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", PlaneNormalXZ__FPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFOPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckEditPartsOnRiver__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckRiverParts__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckNormalPlaceParts__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckNormalPlaceParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckLiveNPC__8CEditMapFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetePlacePartsAtInfoID__8CEditMapFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetTerritoryParts__8CEditMapFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetChildParts__8CEditMapFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", RePaintNum__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", PaintFence__8CEditMapFiPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckFenceChain__FP10CEditPartsP10CEditParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", PaintFence__8CEditMapFP10CEditParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", UpdateHouse__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GroundBalance__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", BalanceCheck__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", InScreenFunc__8CEditMapFP16InScreenFuncInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", DrawScreenFunc__8CEditMapFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetSeSrcVolPan__8CEditMapFPiPfPfi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_796__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_983__3);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1042__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1043__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1127__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1128__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1129__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1130__2);

// Small uninitialised data (.sbss)
unsigned char cnt_482[0x4];
unsigned char init_483[0x4];

// Uninitialised data (.bss)
unsigned char at_1050__2[0x10];
