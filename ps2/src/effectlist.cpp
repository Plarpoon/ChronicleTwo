#include "common.h"
#include "effectlist.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", LoadEFPFile__11CEffectListFPcPUiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", __ct__11mgC3DSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", SaerchEffectIndex__11CEffectListFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", GetEffectVisual__11CEffectListFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", Step__11CEffectListFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", CreatePacket__11CEffectListFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", CreatePacket__14CEffectManagerFP11mgC3DSprite);
void CFadeInOut::Initialize(void) {
    alpha = 0.0f;
    b = 0.0f;
    g = 0.0f;
    r = 0.0f;
    mode = 0;
    speed = 0.0f;
    end = 0;
    cross = 0;
    cross_texture = NULL;
    blur_alpha = 0;
}
void CFadeInOut::ResetFade(void) {
    mode = 0;
    alpha = 0.0f;
    cross = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", FadeIn__10CFadeInOutFifff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", FadeIn__10CFadeInOutFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", FadeOut__10CFadeInOutFifff);
void CFadeInOut::CrossFade(int duration, float alpha) {
    CrossFadeIn(0, duration, alpha);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", CrossFadeIn__10CFadeInOutFiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", CrossFadeOut__10CFadeInOutFiif);
int CFadeInOut::FadeCheck() { return this->end; }
s32 CFadeInOut::NowFade(void) {
    return mode != 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", FadeStep__10CFadeInOutFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", SetCrossTexture__10CFadeInOutFP10mgCTextureP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", CaptureScreen__10CFadeInOutFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", DivSpriteScreen__FR11mgCDrawPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", DivSpriteScreen__FR11mgCDrawPrimiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effectlist", Draw__10CFadeInOutFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effectlist", at_393__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effectlist", at_260__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effectlist", at_261__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effectlist", at_589__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_392, 0x10);
INCLUDE_BSS(at_564__2, 0x10);
INCLUDE_BSS(at_565, 0x10);
INCLUDE_BSS(at_566, 0x10);
INCLUDE_BSS(at_586, 0x10);
INCLUDE_BSS(at_587, 0x10);
INCLUDE_BSS(at_588, 0x10);
