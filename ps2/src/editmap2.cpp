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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_796__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_983__3__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1042__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1043__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1127__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1128__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1129__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editmap2", at_1130__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(cnt_482, 0x4);
INCLUDE_BSS(init_483, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1050__2, 0x10);
