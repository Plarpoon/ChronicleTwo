#include "common.h"
#include "water.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Step__11CFireRasterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetTexture__11CFireRasterFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Draw__11CFireRasterFPfPf);
void CFireRaster::Initialize(void) {
    s32 index = 0;
    do {
        memset(&particle[index], 0, sizeof(particle[index]));
        index++;
    } while (index < 20);
}
void CThunderEffect::Init(void) {
    unk_00 = 0;
    unk_90 = 0;
    unk_94 = 0;
    unk_98 = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Hamon__6CWaterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetVertex__6CWaterFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Shake__6CWaterFiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", Shake__11CWaterFrameFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", GetWater__11CWaterFrameFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/water", SetSize__6CWaterFiiP9mgCMemory);
void CWater::SetParam(float wave_speed, float wave_damping, float param_48, float param_4c) {
    speed = wave_speed;
    damping = wave_damping;
    unk_48 = param_48;
    unk_4c = param_4c;
}
void CWater::SetColor(u8 red, u8 green, u8 blue, u8 alpha) {
    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = alpha;
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
