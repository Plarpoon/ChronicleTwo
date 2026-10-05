#include "common.h"
#include "eventsprite.hpp"
#include <cstring>

// Code (.text)
float ParabolicInitialVectorY(float start_y, float end_y, float gravity, float frames) {
    return ((2.0f * (end_y - start_y)) - (frames * (gravity * frames))) / (2.0f * frames);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", CalcPosParabolicJump__FPfPfPffff);
void CMarker::Draw(void) {
    if (this->count > 0) {
        this->count = this->count - 1;
    }
}
void CMarker::Set(s32 count) {
    this->count = count;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Init__7CMarkerFv);
void CEventSprite::SetName(char *name) {
    strcpy(this->name, name);
}
void CEventSprite::SetDraw(s32 draw) {
    this->draw = draw;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetGet__12CEventSpriteFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetPut__12CEventSpriteFiiii);
void CEventSprite::SetMove(s32 x, s32 y, s32 frames) {
    anime[0] = EVENT_SPRITE_ANIME_NONE;
    anime[1] = -1;
    anime[2] = -1;
    anime[3] = -1;
    anime[0] = EVENT_SPRITE_ANIME_MOVE;
    anime[1] = x;
    anime[2] = y;
    anime[3] = frames;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetFade__12CEventSpriteFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetColor__12CEventSpriteFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Step__12CEventSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Draw__12CEventSpriteFv);
void CEventSprite::Init(void) {
    draw = 0;
    tex_block = 0;
    memset(name, 0, sizeof(name));
    memset(color, 0, sizeof(color));
    memset(get, 0, sizeof(get));
    memset(put, 0, sizeof(put));
    memset(anime, -1, sizeof(anime));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetName__18CEventSpriteMotherFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetDraw__18CEventSpriteMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetGet__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetPut__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetMove__18CEventSpriteMotherFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetFade__18CEventSpriteMotherFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetColor__18CEventSpriteMotherFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Step__18CEventSpriteMotherFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Draw__18CEventSpriteMotherFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Set__18CEventSpriteMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Init__18CEventSpriteMotherFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", __ct__13CEventSprite2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Initialize__13CEventSprite2Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetTexture__13CEventSprite2FPci);
void CEventSprite2::SetDrawFlag(s32 draw_flag) {
    this->draw_flag = draw_flag;
}
void CEventSprite2::SetSpriteType(s32 sprite_type) {
    this->sprite_type = sprite_type;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetPosition__13CEventSprite2FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetColor__13CEventSprite2FPf);
void CEventSprite2::SetPutSize(s32 w, s32 h) {
    put_w = w;
    put_h = h;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetUvSize__13CEventSprite2Fiiii);
void CEventSprite2::SetScale(float scale_x, float scale_y) {
    this->scale_x = scale_x;
    this->scale_y = scale_y;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", GetScale__13CEventSprite2FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", GetPosition__13CEventSprite2FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", GetColor__13CEventSprite2FPf);
s32 CEventSprite2::GetType(void) {
    return sprite_type;
}
void CEventSprite2::SetAlphaBlend(s32 alpha_blend) {
    this->alpha_blend = alpha_blend;
}
void CEventSprite2::SetRotZ(float rot_z) {
    this->rot_z = rot_z;
}
float CEventSprite2::GetRotZ(void) {
    return rot_z;
}
void CEventSprite2::NormalDraw(void) {
    if (draw_flag == EVENT_SPRITE2_DRAW_NORMAL) {
        this->Draw();
    }
}
void CEventSprite2::FirstDraw(void) {
    if (draw_flag == EVENT_SPRITE2_DRAW_FIRST) {
        this->Draw();
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Draw__13CEventSprite2Fv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventsprite", at_1069__4__DATA);
