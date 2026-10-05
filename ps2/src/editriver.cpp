#include "common.h"
#include "editriver.hpp"

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
s32 CEditGrid::SetRiver(float x, float z) {
    s32 grid_pos[2];
    s32 result;
    if (GetLPos(grid_pos, x, z)) {
        result = SetRiver(grid_pos[0], grid_pos[1]);
    } else {
        result = 0;
    }
    return result;
}
s32 CEditGrid::ResetRiver(float x, float z) {
    s32 grid_pos[2];
    s32 result;
    if (GetLPos(grid_pos, x, z)) {
        result = ResetRiver(grid_pos[0], grid_pos[1]);
    } else {
        result = 0;
    }
    return result;
}
s32 CEditGrid::SetRiver(s32 x, s32 z) {
    CGridData *cell;

    cell = Get(x, z);
    if (cell == NULL) {
        return 0;
    }
    cell->river = 1;
    UpdateRiver(x, z);
    UpdateRiver(x - 1, z);
    UpdateRiver(x + 1, z);
    UpdateRiver(x, z + 1);
    UpdateRiver(x, z - 1);
    UpdateRiver(x - 1, z - 1);
    UpdateRiver(x + 1, z - 1);
    UpdateRiver(x + 1, z + 1);
    UpdateRiver(x - 1, z + 1);
    return 1;
}
s32 CEditGrid::ResetRiver(s32 x, s32 z) {
    CGridData *cell;

    cell = Get(x, z);
    if (cell == NULL) {
        return 0;
    }
    if (cell->river == 0) {
        return 0;
    }
    cell->river = 0;
    UpdateRiver(x, z);
    UpdateRiver(x - 1, z);
    UpdateRiver(x + 1, z);
    UpdateRiver(x, z + 1);
    UpdateRiver(x, z - 1);
    UpdateRiver(x - 1, z - 1);
    UpdateRiver(x + 1, z - 1);
    UpdateRiver(x + 1, z + 1);
    UpdateRiver(x - 1, z + 1);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editriver", UpdateRiver__9CEditGridFii);
s32 CEditGrid::River(s32 x, s32 z) {
    CGridData *cell;

    cell = Get(x, z);
    if (cell != NULL) {
        return cell->river;
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
