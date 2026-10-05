#include "common.h"
#include "eventsprite.hpp"
#include <cstring>

// Code (.text)
float ParabolicInitialVectorY(float arg0, float arg1, float arg2, float arg3) {
    return ((2.0f * (arg1 - arg0)) - (arg3 * (arg2 * arg3))) / (2.0f * arg3);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", CalcPosParabolicJump__FPfPfPffff);
void CMarker::Draw(void) {
    if (this->count > 0) {
        this->count = this->count - 1;
    }
}
void CMarker::Set(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x0)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Init__7CMarkerFv);
void CEventSprite::SetName(char *a) {
    strcpy((char *) this + 8, a);
}
void CEventSprite::SetDraw(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x0)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetGet__12CEventSpriteFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetPut__12CEventSpriteFiiii);
void CEventSprite::SetMove(s32 arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((u8 *)this + 0x78)) = -1;
    (*(s32 *)((u8 *)this + 0x7c)) = -1;
    (*(s32 *)((u8 *)this + 0x80)) = -1;
    (*(s32 *)((u8 *)this + 0x84)) = -1;
    (*(s32 *)((u8 *)this + 0x78)) = 0;
    (*(s32 *)((u8 *)this + 0x7c)) = arg0;
    (*(s32 *)((u8 *)this + 0x80)) = arg1;
    (*(s32 *)((u8 *)this + 0x84)) = arg2;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetFade__12CEventSpriteFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetColor__12CEventSpriteFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Step__12CEventSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Draw__12CEventSpriteFv);
void CEventSprite::Init(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
    memset(&(*(s32 *)((u8 *)this + 0x8)), 0, 0x40);
    memset(&(*(s32 *)((u8 *)this + 0x48)), 0, 0x10);
    memset(&(*(s32 *)((u8 *)this + 0x58)), 0, 0x10);
    memset(&(*(s32 *)((u8 *)this + 0x68)), 0, 0x10);
    memset(&(*(s32 *)((u8 *)this + 0x78)), -1, 0x10);
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
void CEventSprite2::SetDrawFlag(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x0)) = arg0;
}
void CEventSprite2::SetSpriteType(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x4)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetPosition__13CEventSprite2FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetColor__13CEventSprite2FPf);
void CEventSprite2::SetPutSize(s32 arg0, s32 arg1) {
    (*(s32 *)((u8 *)this + 0x54)) = arg0;
    (*(s32 *)((u8 *)this + 0x58)) = arg1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", SetUvSize__13CEventSprite2Fiiii);
void CEventSprite2::SetScale(float arg0, float arg1) {
    (*(float *)((u8 *)this + 0x6c)) = arg0;
    (*(float *)((u8 *)this + 0x70)) = arg1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", GetScale__13CEventSprite2FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", GetPosition__13CEventSprite2FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", GetColor__13CEventSprite2FPf);
s32 CEventSprite2::GetType(void) {
    return (*(s32 *)((u8 *)this + 0x4));
}
void CEventSprite2::SetAlphaBlend(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x2c)) = arg0;
}
void CEventSprite2::SetRotZ(float arg0) {
    (*(float *)((u8 *)this + 0x50)) = arg0;
}
float CEventSprite2::GetRotZ(void) {
    return (*(float *)((u8 *)this + 0x50));
}
void CEventSprite2::NormalDraw(void) {
    if ((*(s32 *)((u8 *)this + 0x0)) == 1) {
        this->Draw();
    }
}
void CEventSprite2::FirstDraw(void) {
    if ((*(s32 *)((u8 *)this + 0x0)) == 2) {
        this->Draw();
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventsprite", Draw__13CEventSprite2Fv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventsprite", at_1069__4__DATA);
