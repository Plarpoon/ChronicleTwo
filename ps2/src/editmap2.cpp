#include "common.h"
#include "editmap2.hpp"

// Code (.text)
void PlaneNormalXZ(float *a0, float *a1, float *a2, float *a3) {
    asm {
        lqc2 vf15, 0(a1)
        vsub.xyzw vf10, vf10, vf10
        lqc2 vf16, 0(a2)
        vsub.xyzw vf11, vf11, vf11
        lqc2 vf17, 0(a3)
        vsub.xz vf10, vf16, vf15
        vsub.xz vf11, vf17, vf15
        vopmula.xyz ACC, vf10, vf11
        vopmsub.xyz vf12, vf11, vf10
        sqc2 vf12, 0(a0)
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetEditPartsAlt__8CEditMapFP14CEditPartsInfoPffPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckEditParts__8CEditMapFP14CEditPartsInfoPffP13EP_PLACE_INFOPP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckEditPartsOnRiver__8CEditMapFP14CEditPartsInfoPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckRiverParts__8CEditMapFPf);
s32 CEditMap::CheckNormalPlaceParts(s32 arg0) {
    void *parts = this->GetePlaceParts(arg0);
    return this->CheckNormalPlaceParts((CEditParts *)parts);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckNormalPlaceParts__8CEditMapFP10CEditParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", CheckLiveNPC__8CEditMapFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetePlacePartsAtInfoID__8CEditMapFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetTerritoryParts__8CEditMapFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editmap2", GetChildParts__8CEditMapFiPii);
s32 CEditMap::RePaintNum(s32 count) {
    return count / 2;
}
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
