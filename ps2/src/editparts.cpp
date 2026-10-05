#include "common.h"
#include "editparts.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editparts", Initialize__14CEditPartsInfoFv);
s32 CEditPartsInfo::GetPartsType(void) {
    s32 temp_v1;

    temp_v1 = (*(s32 *)((u8 *)this + 0x4));
    if (temp_v1 & 0x40) {
        return 1;
    }
    if (temp_v1 & 0x80) {
        return 0xB;
    }
    return (*(s32 *)((u8 *)this + 0x24));
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
    struct temp_v0_champs_2c6891 *temp_v0;

    temp_v0 = (struct temp_v0_champs_2c6891 *) ((*(s32 *)((u8 *)this + 0x328)));
    if (temp_v0 != NULL) {
        return (*(s32 *)((u8 *)temp_v0 + 0x4));
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
    void *p = this->info;
    if (p != 0) return ((CEditPartsInfo *)p)->GetPartsType();
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
