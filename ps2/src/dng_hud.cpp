#include "common.h"
#include "dng_hud.hpp"
#include "character.hpp"

// Code (.text)
void CLevelupInfo::SetLevelUpInfo(s32 screen_x, s32 screen_y, s32 source, s32 value) {
    unk_00 = 0;
    unk_04 = 0;
    unk_08 = 0;
    unk_0c = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1c = 0;
    progress = 0.0f;
    phase = LEVELUP_INFO_PHASE_APPEAR;
    x = screen_x - 0x23;
    y = screen_y - 6;
    unk_30 = source;
    unk_34 = value;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__12CLevelupInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__12CLevelupInfoFv);
void CPiyori::Initialize(void) {
    target = NULL;
}
void CPiyori::Reset(void) {
    target = NULL;
    time = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Set__7CPiyoriFP9mgCObjectffs);
void CPiyori::Set(mgCObject *target, s16 time) {
    if (target != NULL) {
        CCharacter2 *character = reinterpret_cast<CCharacter2 *>(target);
        this->Set(target, 2.0f * character->body_height, 2.0f * character->body_width, time);
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__7CPiyoriFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__7CPiyoriFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Set__9CGiftMarkFP11CCharacter2f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__9CGiftMarkFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__9CGiftMarkFv);
void CGiftMark::Initialize(void) {
    chara = NULL;
    active = 0;
    angle = 0.0f;
    time = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__13CEnemyGekirinFP10CPreSpriteii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__13CEnemyGekirinFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", SetView__14CEnemyLifeGageFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Set__14CEnemyLifeGageFPfiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Draw__14CEnemyLifeGageFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", Step__14CEnemyLifeGageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", ResetGekirin__14CEnemyLifeGageFi);
void CEnemyLifeGage::Initialize(s32 gekirin_num) {
    this->ResetGekirin(gekirin_num);
    hp = 0;
    max_hp = 0;
    view = 0;
    scale = 0.0f;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_hud", SetValue__12CDamageScoreFPfi);
void CDamageScore::SetColor(s16 red, s16 green, s16 blue) {
    color[0] = red;
    color[1] = green;
    color[2] = blue;
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
void CLockOnModel::Initialize(CScene *scene) {
    this->scene = scene;
    name = NULL;
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_hud", gekirin_anim__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_hud", at_1221__2__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_hud", __vt__12CLockOnModel__DATA);
