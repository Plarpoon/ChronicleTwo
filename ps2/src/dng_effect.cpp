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
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    memset(&(*(s32 *)((u8 *)this + 0x10)), 0, 0x2A0);
    memset(&(*(s32 *)((u8 *)this + 0x2b0)), 0, 0x690);
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
    (*(s8 *)((u8 *)this + 0xdb0)) = 0;
    (*(s8 *)((u8 *)this + 0xdb1)) = 0;
    (*(void * *)((u8 *)this + 0xf4)) = &(*(s32 *)((u8 *)this + 0x110));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__12CSparcEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CSparcEffectFv);
void CSparcEffect::Initialize(void) {
    (*(s8 *)((u8 *)this + 0xa9)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPrim__12CMiniEffPrimFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__12CMiniEffPrimFP10CPreSprite);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CMiniEffPrimFv);
void CMiniEffPrim::Initialize(void) {
    (*(s8 *)((u8 *)this + 0x10)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPrim__15CMiniEffPrimManFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__15CMiniEffPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__15CMiniEffPrimManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Initialize__15CMiniEffPrimManFv);
void CPalletAnime::SetAnim(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    (*(s16 *)((u8 *)this + 0x0)) = arg0;
    (*(s16 *)((u8 *)this + 0x2)) = arg1;
    (*(s16 *)((u8 *)this + 0x4)) = arg2;
    (*(s16 *)((u8 *)this + 0x6)) = arg3;
    (*(s16 *)((u8 *)this + 0xa)) = arg4;
    (*(s16 *)((u8 *)this + 0x8)) = 0;
    (*(s16 *)((u8 *)this + 0xc)) = arg5;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", CreatPallet__12CPalletAnimeFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__12CPalletAnimeFv);
void CPalletAnime::Initialize(void) {
    (*(s16 *)((u8 *)this + 0xa)) = 0;
    (*(s16 *)((u8 *)this + 0x8)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Draw__17CHealingEffectManFP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__17CHealingEffectManFv);
void CHealingEffectMan::SetMode(s32 arg0) {
    (*(s16 *)((u8 *)this + 0x314)) = arg0;
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
void CAfterWire::SetMode(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x0)) = arg0;
    (*(s16 *)((u8 *)this + 0x116)) = 0;
    (*(s16 *)((u8 *)this + 0x118)) = 0;
    (*(s16 *)((u8 *)this + 0x112)) = 0;
    (*(s16 *)((u8 *)this + 0x114)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SetPos__10CAfterWireFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", DrawWire__10CAfterWireFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", StepWire__10CAfterWireFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", SethitEffect__15CHitEffectImageFPfPfffffii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_effect", Step__15CHitEffectImageFv);
void CHitEffectImage::Draw(void) {
    s32 temp_a1;

    if ((*(s32 *)((u8 *)this + 0x28)) > 0) {
        temp_a1 = (*(s32 *)((u8 *)this + 0x44));
        switch (temp_a1) {                          /* irregular */
        case 0:
            this->DrawBord();
            return;
        case 1:
            this->DrawSpark(3.0f);
            return;
        case 2:
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
    s16 temp_v1;

    if (*(s16 *) ((u8 *) this + 0x5AC) != 0) {
        temp_v1 = *(s16 *) ((u8 *) this + 0x5A4);
        switch (temp_v1) {
        case 1:
        default:
            this->Step_Cold();
            return;
        case 3:
            this->Step_Wind();
            return;
        case 0:
            this->Step_Fire();
            return;
        case 2:
            this->Step_Thunder();
            break;
        }
    }
}
void CWeaponElement::Draw(void) {
    s16 temp_v1;

    if (*(s16 *) ((u8 *) this + 0x5AC) != 0) {
        temp_v1 = *(s16 *) ((u8 *) this + 0x5A4);
        switch (temp_v1) {
        case 1:
        default:
            this->Draw_Cold();
            return;
        case 3:
            this->Draw_Wind();
            return;
        case 0:
            this->Draw_Fire();
            return;
        case 2:
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
s32 iRand(s32 arg0) {
    return (s32) (((float) arg0 * (float) rand()) / 2.1474836e9f);
}
float fRand(float arg0) {
    return (arg0 * (float) rand()) / 2.1474836e9f;
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
