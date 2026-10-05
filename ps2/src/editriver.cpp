#include "common.h"
#include "editriver.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", PlaceRiver__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", RemoveRiver__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", CreateGrid__8CEditMapFPfPfP9mgCMemoryPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetRiverNum__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", IsRiverGrid__8CEditMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetRiverNum__8CEditMapFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", DrawRiverMask__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", DrawRiver__8CEditMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", Create__9CEditGridFiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", __ct__9CGridDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", Clear__9CEditGridFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", Initialize__9CEditGridFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", Check__9CEditGridFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", Get__9CEditGridFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetFast__9CEditGridFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetLPos__9CEditGridFPiff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetWPos__9CEditGridFPfii);
s32 CEditGrid::SetRiver(float x, float y) {
    s32 p[2];
    s32 r;
    if (this->GetLPos(p, x, y)) r = this->SetRiver(p[0], p[1]); else r = 0;
    return r;
}
s32 CEditGrid::ResetRiver(float x, float y) {
    s32 p[2];
    s32 r;
    if (this->GetLPos(p, x, y)) r = this->ResetRiver(p[0], p[1]); else r = 0;
    return r;
}
s32 CEditGrid::SetRiver(s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->Get(arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = 1;
    this->UpdateRiver(arg0, arg1);
    this->UpdateRiver(arg0 - 1, arg1);
    this->UpdateRiver(arg0 + 1, arg1);
    this->UpdateRiver(arg0, arg1 + 1);
    this->UpdateRiver(arg0, arg1 - 1);
    this->UpdateRiver(arg0 - 1, arg1 - 1);
    this->UpdateRiver(arg0 + 1, arg1 - 1);
    this->UpdateRiver(arg0 + 1, arg1 + 1);
    this->UpdateRiver(arg0 - 1, arg1 + 1);
    return 1;
}
s32 CEditGrid::ResetRiver(s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->Get(arg0, arg1));
    if (temp_v0 == NULL) {
        return 0;
    }
    if (*temp_v0 == 0) {
        return 0;
    }
    *temp_v0 = 0;
    this->UpdateRiver(arg0, arg1);
    this->UpdateRiver(arg0 - 1, arg1);
    this->UpdateRiver(arg0 + 1, arg1);
    this->UpdateRiver(arg0, arg1 + 1);
    this->UpdateRiver(arg0, arg1 - 1);
    this->UpdateRiver(arg0 - 1, arg1 - 1);
    this->UpdateRiver(arg0 + 1, arg1 - 1);
    this->UpdateRiver(arg0 + 1, arg1 + 1);
    this->UpdateRiver(arg0 - 1, arg1 + 1);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", UpdateRiver__9CEditGridFii);
s32 CEditGrid::River(s32 arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->Get(arg0, arg1));
    if (temp_v0 != NULL) {
        return *temp_v0;
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetRiverPos__9CEditGridFiiPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetRiverPos__9CEditGridFiiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetRiverPoly__9CEditGridFP6CCPolyRC9mgVu0FBOXif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", GetGridBox__9CEditGridFP9mgVu0FBOXPf);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_504__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_505__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_506__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_507__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_590__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_591__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_592__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_593__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_594__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editriver", at_799__3__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_733__2, 0x10);
INCLUDE_BSS(at_734, 0x10);
