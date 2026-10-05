#include "common.h"
#include "editparts.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", Initialize__14CEditPartsInfoFv);
s32 CEditPartsInfo::GetPartsType(void) {
    if (attr & EDIT_PARTS_ATR_TYPE_ONE) {
        return 1;
    }
    if (attr & EDIT_PARTS_ATR_RIVER) {
        return EDIT_PARTS_TYPE_RIVER;
    }
    return parts_type;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", CreateBox__14CEditPartsInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetPartsHeight__14CEditPartsInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetPartsMaxWidth__14CEditPartsInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetMaterial__14CEditPartsInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetDefColor__14CEditPartsInfoFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", LiveChara__10CEditHouseFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", Initialize__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", StandardPos__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", SetPosition__10CEditPartsFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", SetPosition__10CEditPartsFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetPosition__10CEditPartsFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetLocalPos__10CEditPartsFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", UpDatePosition__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetInfoID__10CEditPartsFv);
s32 CEditParts::GetLiveNPC(void) {
    CEditHouse *part_house = house;
    if (part_house != NULL) {
        return part_house->npc_no[0];
    }
    return -1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", IsWallParts__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", IsFence__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", IsBurn__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetFenceSide__10CEditPartsFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetWallPlane__10CEditPartsFiPQ210CEditParts8WallInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", GetWallGroupNum__10CEditPartsFv);
s32 CEditParts::GetPartsType(void) {
    CEditPartsInfo *part_info = info;
    if (part_info != NULL) {
        return part_info->GetPartsType();
    }
    return -1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", Copy__10CEditPartsFR9CMapPartsP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", CheckTerritory__10CEditPartsFP10CEditParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", CheckColorUpdate__10CEditPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", EditPartsCmpColor__FPfPf);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editparts", at_418__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editparts", __vt__10CEditParts__DATA);
