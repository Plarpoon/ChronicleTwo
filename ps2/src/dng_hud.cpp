#include "common.h"
#include "dng_hud.hpp"

// Code (.text)
void CLevelupInfo::SetLevelUpInfo(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0x14)) = 0;
    (*(s32 *)((u8 *)this + 0x18)) = 0;
    (*(s32 *)((u8 *)this + 0x1c)) = 0;
    (*(s32 *)((u8 *)this + 0x20)) = 0;
    (*(s32 *)((u8 *)this + 0x24)) = 1;
    (*(s32 *)((u8 *)this + 0x28)) = arg0 - 0x23;
    (*(s32 *)((u8 *)this + 0x2c)) = arg1 - 6;
    (*(s32 *)((u8 *)this + 0x30)) = arg2;
    (*(s32 *)((u8 *)this + 0x34)) = arg3;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__12CLevelupInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__12CLevelupInfoFv);
void CPiyori::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
}
void CPiyori::Reset(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s16 *)((u8 *)this + 0x1c)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Set__7CPiyoriFP9mgCObjectffs);
void CPiyori::Set(mgCObject *arg0, s16 arg1) {
    if (arg0 != NULL) {
        this->Set(arg0, 2.0f * (*(float *)((u8 *)arg0 + 0x110)), 2.0f * (*(float *)((u8 *)arg0 + 0x10c)), arg1);
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__7CPiyoriFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__7CPiyoriFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Set__9CGiftMarkFP11CCharacter2f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__9CGiftMarkFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__9CGiftMarkFv);
void CGiftMark::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s16 *)((u8 *)this + 0x10)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__13CEnemyGekirinFP10CPreSpriteii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__13CEnemyGekirinFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", SetView__14CEnemyLifeGageFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Set__14CEnemyLifeGageFPfiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__14CEnemyLifeGageFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__14CEnemyLifeGageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", ResetGekirin__14CEnemyLifeGageFi);
void CEnemyLifeGage::Initialize(s32 arg0) {
    this->ResetGekirin(arg0);
    (*(s32 *)((u8 *)this + 0x14)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0x1c)) = 0;
    (*(s32 *)((u8 *)this + 0x20)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", SetValue__12CDamageScoreFPfi);
void CDamageScore::SetColor(s16 arg0, s16 arg1, s16 arg2) {
    (*(s16 *)((u8 *)this + 0x48)) = arg0;
    (*(s16 *)((u8 *)this + 0x4a)) = arg1;
    (*(s16 *)((u8 *)this + 0x4c)) = arg2;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", SetSprite__12CDamageScoreFPfiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__12CDamageScoreFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__12CDamageScoreFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", SetValue__13CDamageScore2Fiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__13CDamageScore2FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__13CDamageScore2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__12CLockOnModelFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", DrawMess__12CLockOnModelFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__12CLockOnModelFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__13CWarningGage2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__13CWarningGage2Fv);
void CLockOnModel::Initialize(CScene * arg0) {
    (*(CScene * *)((u8 *)this + 0x80)) = arg0;
    (*(s32 *)((u8 *)this + 0x8c)) = 0;
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_hud", gekirin_anim__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_hud", at_1221__2__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_hud", __vt__12CLockOnModel__DATA);
