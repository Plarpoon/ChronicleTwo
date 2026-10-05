#include "common.h"
#include "water.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Step__11CFireRasterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetTexture__11CFireRasterFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Draw__11CFireRasterFPfPf);
void CFireRaster::Initialize(void) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        memset((u8 *) this + var_s1 + 0x70, 0, 0x20);
        var_s0 += 1;
        var_s1 += 0x20;
    } while (var_s0 < 0x14);
}
void CThunderEffect::Init(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x90)) = 0;
    (*(s32 *)((u8 *)this + 0x94)) = 0;
    (*(s32 *)((u8 *)this + 0x98)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Hamon__6CWaterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetVertex__6CWaterFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Shake__6CWaterFiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Shake__11CWaterFrameFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", GetWater__11CWaterFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetSize__6CWaterFiiP9mgCMemory);
void CWater::SetParam(float arg0, float arg1, float arg2, float arg3) {
    (*(float *)((u8 *)this + 0x40)) = arg0;
    (*(float *)((u8 *)this + 0x44)) = arg1;
    (*(float *)((u8 *)this + 0x48)) = arg2;
    (*(float *)((u8 *)this + 0x4c)) = arg3;
}
void CWater::SetColor(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    (*(s32 *)((u8 *)this + 0x30)) = arg0 & 0xFF;
    (*(s32 *)((u8 *)this + 0x34)) = arg1 & 0xFF;
    (*(s32 *)((u8 *)this + 0x38)) = arg2 & 0xFF;
    (*(s32 *)((u8 *)this + 0x3c)) = arg3 & 0xFF;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", __ct__6CWaterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", CreateRenderInfoPacket__6CWaterFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Draw__6CWaterFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", CreatePacket__6CWaterFP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetTexture__11CWaterFrameFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Step__11CWaterFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetParam__11CWaterFrameFffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetColor__11CWaterFrameFUcUcUcUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Shake__11CWaterFrameFiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", CreatePacket__11CWaterFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", CreateWaterFrame__FiiPfPfP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Initialize__11CWaterFrameFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/water", prog_vif_351__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/water", progf_vif_352__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/water", __vt__11CWaterFrame__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/water", __vt__6CWater__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_287__2, 0x10);
