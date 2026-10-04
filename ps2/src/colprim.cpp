#include "common.h"

#include "colprim.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", SetDamage__8CColPrimFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", SetCoord__8CColPrimFPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", SetCoord__8CColPrimFPfPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", SetCoord__8CColPrimFP8mgCFramef);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", SetCoord__8CColPrimFP8mgCFrameP8mgCFramef);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", IsHit__8CColPrimFP6CScenei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", IsReversVec__8CColPrimFP8CColPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", GetReversVec__8CColPrimFPf);
void CColPrim::DebugDraw() {}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", Step__8CColPrimFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", Delete__8CColPrimFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", Initialize__8CColPrimFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", GetPrim__11CColPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", GetID2Prim__11CColPrimManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", ActivePrimNum__11CColPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", Delete__11CColPrimManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", CheckHit__11CColPrimManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", IsReversVec__11CColPrimManFP8CColPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", Step__11CColPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/colprim", Initialize__11CColPrimManFP6CScene);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/colprim", Damage_Param_Table__DATA);
