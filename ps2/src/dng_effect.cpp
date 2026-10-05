#include "common.h"
#include "dng_effect.hpp"
#include <cstring>
#include <cstdlib>

// Code (.text)
float trans_effect_rate(int rate) {
    float f = (float)rate / 255.0f;
    if (1.0f < f) {
        f = 1.0f;
    }
    return f;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", trans_float_to_sceVector__FPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__14CChillAfterHitFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPos__14CChillAfterHitFPffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__14CChillAfterHitFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", LocalTransWorldPrimPos__FPA4_iPffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__14CChillAfterHitFv);
void CFireAfterHit::Initialize(void) {
    active = 0;
    flame_num = 0;
    time = 0;
    rate = 0.0f;
    memset(flame, 0, sizeof(flame));
    memset(trail, 0, sizeof(trail));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPos__13CFireAfterHitFPffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__13CFireAfterHitFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__13CFireAfterHitFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPos__8CTornadoFPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__8CTornadoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__8CTornadoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__8CTornadoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPos__8CThunderFPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__8CThunderFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__8CThunderFv);
void CThunder::Initialize(void) {
    active = 0;
    live_num = 0;
    frame.attr = &attr;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__12CSparcEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CSparcEffectFv);
void CSparcEffect::Initialize(void) {
    state = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPrim__12CMiniEffPrimFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__12CMiniEffPrimFP10CPreSprite);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CMiniEffPrimFv);
void CMiniEffPrim::Initialize(void) {
    state = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPrim__15CMiniEffPrimManFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__15CMiniEffPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__15CMiniEffPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__15CMiniEffPrimManFv);
void CPalletAnime::SetAnim(s16 red, s16 green, s16 blue, s16 pulse_num, s16 duration, s16 repeats) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->pulse_num = pulse_num;
    this->duration = duration;
    elapsed = 0;
    this->repeats = repeats;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPallet__12CPalletAnimeFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CPalletAnimeFv);
void CPalletAnime::Initialize(void) {
    duration = 0;
    elapsed = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__17CHealingEffectManFP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__17CHealingEffectManFv);
void CHealingEffectMan::SetMode(s32 mode) {
    this->mode = mode;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Set__17CHealingEffectManFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__17CHealingEffectManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__14CSwordLuminousFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__14CSwordLuminousFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__16CSWordAfterImageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPointList__16CSWordAfterImageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", AddPoint__16CSWordAfterImageFPfPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__16CSWordAfterImageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__16CSWordAfterImageFP9mgCMemoryii);
void CAfterWire::SetMode(s32 mode) {
    this->mode = mode;
    write_index = 0;
    newest = 0;
    point_num = 0;
    oldest = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPos__10CAfterWireFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", DrawWire__10CAfterWireFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", StepWire__10CAfterWireFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SethitEffect__15CHitEffectImageFPfPfffffii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__15CHitEffectImageFv);
void CHitEffectImage::Draw(void) {
    if (live_num > 0) {
        switch (kind) {
        case HIT_EFFECT_BOARD:
            this->DrawBord();
            return;
        case HIT_EFFECT_SPARK_SHORT:
            this->DrawSpark(3.0f);
            return;
        case HIT_EFFECT_SPARK_LONG:
            this->DrawSpark(9.0f);
            break;
        }
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", DrawBord__15CHitEffectImageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", DrawSpark__15CHitEffectImageFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__12CFlushEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CFlushEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPrim__10CPowerLineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__10CPowerLineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__10CPowerLineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetDeadEffect__11CDeadEffectFPffffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPrim__11CDeadEffectFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__11CDeadEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__11CDeadEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Set__17CMapEffect_SpriteFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__17CMapEffect_SpriteFP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__17CMapEffect_SpriteFP9mgCCameraP10CPreSprite);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Init_LightBoll__18CMapEffectsManegerFP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__18CMapEffectsManegerFP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__18CMapEffectsManegerFP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", AllocEffect__15BattleEffectManFiP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", __ct__11CCharacter2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", __ct__10CPowerLineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", __ct__15CHitEffectImageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__15BattleEffectManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__15BattleEffectManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Set__14CWeaponElementFPA4_fPffif);
void CWeaponElement::Step(void) {
    if (on != 0) {
        switch (kind) {
        case WEAPON_ELEMENT_COLD:
        default:
            this->Step_Cold();
            return;
        case WEAPON_ELEMENT_WIND:
            this->Step_Wind();
            return;
        case WEAPON_ELEMENT_FIRE:
            this->Step_Fire();
            return;
        case WEAPON_ELEMENT_THUNDER:
            this->Step_Thunder();
            break;
        }
    }
}
void CWeaponElement::Draw(void) {
    if (on != 0) {
        switch (kind) {
        case WEAPON_ELEMENT_COLD:
        default:
            this->Draw_Cold();
            return;
        case WEAPON_ELEMENT_WIND:
            this->Draw_Wind();
            return;
        case WEAPON_ELEMENT_FIRE:
            this->Draw_Fire();
            return;
        case WEAPON_ELEMENT_THUNDER:
            this->Draw_Thunder();
            break;
        }
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Init_Cold__14CWeaponElementFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step_Cold__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw_Cold__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Init_Wind__14CWeaponElementFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step_Wind__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw_Wind__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Init_Fire__14CWeaponElementFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step_Fire__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw_Fire__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Init_Thunder__14CWeaponElementFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step_Thunder__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw_Thunder__14CWeaponElementFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatSmoothPass__FPA4_fPA4_fiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", unitRotation__FP8mgCFrameff);
s32 iRand(s32 limit) {
    return (s32) (((float) limit * (float) rand()) / 2.1474836e9f);
}
float fRand(float limit) {
    return (limit * (float) rand()) / 2.1474836e9f;
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", chill_tex_rect_910__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", gb_tbl_1052__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", thn_tbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", thn_uv__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", at_1215__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", at_1216__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", at_3214__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", at_1107__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", at_1981__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_effect", at_2882__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1051, 0x10);
INCLUDE_BSS(at_1214__2, 0x10);
