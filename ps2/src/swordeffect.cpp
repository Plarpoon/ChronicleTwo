#include "common.h"
#include "swordeffect.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", CreatSmoothPassSW__FPA4_fPA4_fiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", Draw__17CSWordAfterEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", CreatPointList__17CSWordAfterEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", SetTexture__17CSWordAfterEffectFiP10mgCTextureiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", SetTexture__17CSWordAfterEffectFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", StartEffect__17CSWordAfterEffectFP8mgCFrameP8mgCFrameiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", AddPoint__17CSWordAfterEffectFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", Step__17CSWordAfterEffectFv);
void CSWordAfterEffect::Clear(void) {
    active = 0;
    frame1 = NULL;
    frame0 = NULL;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", Initialize__17CSWordAfterEffectFP9mgCMemoryii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/swordeffect", Copy__17CSWordAfterEffectFR17CSWordAfterEffectP9mgCMemory);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/swordeffect", at_356__DATA);
