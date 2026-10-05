#include "common.h"
#include "sphida.hpp"
#include <cstring>
#include <cstdio>
#include <cstdlib>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", GetSphidaClubDef__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", DPrimEnterSprite__FP11mgCDrawPrimiiiiffff);
void CPowGage::Initialize(void) {
    pos_y = 0.0f;
    pos_x = 0.0f;
    texture = NULL;
    power = 0.0f;
    safe_level = 2;
    code = -10;
    state = -1;
    reverse = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", Step__8CPowGageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", Draw__8CPowGageFv);
void InitSphida(void) {
    Sphida = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", GetSphidaPtr__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", __ct__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", Initialize__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", SetUp__7CSphidaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", s17_SetUp__7CSphidaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", Omake_SetUp__7CSphidaFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", Step__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", InitStatusSprite__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", DrawStatusSprite__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", DrawParCounter__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", Draw__7CSphidaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", SetCollisionModel__7CSphidaFP10MDS_HEADERP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", PickupCollision__7CSphidaFPfP6CCPoly9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sphida", DrawMiniMapSymbol__7CSphidaFP14CMiniMapSymbol);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", GolfClubDef__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", at_940__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", at_1088__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", at_1089__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", at_1090__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", at_1138__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sphida", at_1221__5__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(Sphida, 0x4);
