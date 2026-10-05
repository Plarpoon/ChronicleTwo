#include "common.h"
#include "dng_status.hpp"
#include "maintex.hpp"
#include "prespr.hpp"
#include "mg_drawprim.hpp"
#include "dng_main.hpp"
#include "dng_hud.hpp"
#include "scenesnd.hpp"
#include "userdata.hpp"
#include "subgame.hpp"
#include "actionchara.hpp"
#include <cmath>

extern float cur_ang_1005;
extern int init_1006;
extern float palanim_1023;
extern int init_1024;
extern float palanim_1222;
extern int init_1223;

#define DRAW_GAUGE_STRIP(sprite, left, right, top, bottom, u, v) \
    do { \
        (sprite).TextureCrd((u), (v)); \
        (sprite).Vertex((left), (top), 0); \
        (sprite).TextureCrd((u) + 8, (v)); \
        (sprite).Vertex((right), (top), 0); \
        (sprite).TextureCrd((u), (v) + 4); \
        (sprite).Vertex((left), (bottom), 0); \
        (sprite).TextureCrd((u) + 8, (v) + 4); \
        (sprite).Vertex((right), (bottom), 0); \
    } while (0)

void DrawActiveItemCursor(int x, int y, float fade);

// Code (.text)
#ifdef NONMATCHING
void PrintV(int x, int y, int value, mgCTexture *texture, mgRect<int> glyph, int digits,
            int align_right, int pitch, SP_RGBA *color) {
    int parts[8] = {-1, -1, -1, -1, -1, -1, 0, 0};
    int divisor = 1;
    for (int i = 1; i < digits; ++i) divisor *= 10;
    for (int i = digits - 1; i >= 0; --i) {
        parts[i] = value / divisor;
        value %= divisor;
        divisor /= 10;
    }
    int shown = digits;
    for (int i = digits - 1; i > 0 && parts[i] == 0; --i) --shown;
    CPreSprite sprite;
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Texture(texture);
    if (color) sprite.Color(color->r, color->g, color->b, color->a);
    else sprite.Color(0x80, 0x80, 0x80, 0x80);
    if (pitch < 0) pitch = glyph.right;
    if (align_right) x += pitch * (digits - shown);
    for (int i = shown - 1; i >= 0; --i) {
        sprite.SetIRect(x, y, glyph.right, glyph.bottom + 1,
                        glyph.left + glyph.right * parts[i], glyph.top);
        x += pitch;
    }
    sprite.End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", PrintV__FiiiP10mgCTexture9mgRect_i_iiiP7SP_RGBA);
#endif
#ifdef NONMATCHING
void DrawDrumCounter(int x, int y, int value) {
    int parts[5];
    int divisor = 10000;
    for (int i = 0; i < 5; ++i) {
        parts[i] = value / divisor;
        value %= divisor;
        divisor /= 10;
    }
    CPreSprite sprite;
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    for (int i = 0; i < 5; ++i) sprite.SetIRect(x + i * 15, y, 12, 12, parts[i] * 12, 0xE8);
    sprite.End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawDrumCounter__Fiii);
#endif
#ifdef NONMATCHING
void DrawActiveItemCursor(int x, int y, float fade) {
    CPreSprite sprite;
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Bilinear(1);
    sprite.Begin(3);
    sprite.Texture(TEX_SystenFrame);
    sprite.SetAlphaBlend(2);
    sprite.Color(0x80, 0x80, 0x80, (int)(128.0f * fade));
    if (!init_1006) {
        init_1006 = 1;
        cur_ang_1005 = -3.1415927f;
    }
    cur_ang_1005 += 0.017453292f;
    if (cur_ang_1005 > 3.1415927f) cur_ang_1005 -= 25.132742f;
    const float local_x[6] = {-28.0f, 27.0f, -28.0f, 27.0f, -28.0f, 27.0f};
    const float local_y[6] = {-28.0f, -28.0f, 27.0f, -28.0f, 27.0f, 27.0f};
    const int tex_u[6] = {0x84, 0xB9, 0x84, 0xB9, 0x84, 0xB9};
    const int tex_v[6] = {0xCA, 0xCA, 0xFF, 0xCA, 0xFF, 0xFF};
    float sine = sinf(cur_ang_1005);
    float cosine = cosf(cur_ang_1005);
    for (int i = 0; i < 6; ++i) {
        float pos[2] = {(float)x + local_y[i] * sine - local_x[i] * cosine,
                        (float)y + local_x[i] * sine + local_y[i] * cosine};
        sprite.TextureCrd(tex_u[i], tex_v[i]);
        sprite.Vertex(pos);
    }
    sprite.End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawActiveItemCursor__Fiif);
#endif
#ifdef NONMATCHING
void DrawMainUnitStatusBord(float rate) {
    int y = (int)(80.0f * rate) - 0x48;
    int second_x = 0x244 - (int)(300.0f * rate);
    if (SubGameRunning()) {
        y = -0x48;
        second_x = 0x244;
    }
    CActionChara *character = (CActionChara *)DngMainScene->GetCharacter(0);
    bool event_active = character && character->CheckRunEvent();
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    int hp[2] = {battle->GetNowHp_i(), battle->GetMaxHp_i()};
    int whp[2][2];
    int abs[2][2];
    battle->GetNowWhp(0, whp[0]);
    battle->GetNowWhp(1, whp[1]);
    float hp_rate = (float)hp[0] / (float)hp[1];
    float whp_rate[2] = {(float)whp[0][0] / (float)whp[0][1],
                         (float)whp[1][0] / (float)whp[1][1]};
    if (!init_1024) { palanim_1023 = 0.0f; init_1024 = 1; }
    palanim_1023 += 0.19634955f;
    if (palanim_1023 > 0.0f) palanim_1023 -= 3.1415927f;
    int pulse = (int)(-64.0f * sinf(palanim_1023));
    CPreSprite sprite;
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Bilinear(0);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    sprite.SetIRect(0x18, y, 0xCB, 0x15, 0, 0x8C);
    sprite.SetIRect(0xD4, y + 0xE, 0xC, 0xC, 0x78, 0xE8);
    sprite.SetIRect(0x30, y + 0x12, 0x95, 0x2F, 0xEC, 0);
    CGameDataUsed *items = battle->GetActiveItemInfo(0);
    sprite.Texture(TEX_DummyIcon1);
    for (int i = 0; i < 3; ++i) {
        if (items[i].GetNum() > 0)
            sprite.SetIStretch(0x36 + i * 0x2A, y + 0x14, 0x1C, 0x23,
                               i == 1 ? 0x20 : 0, i == 2 ? 0x20 : 0, 0x1F, 0x1F);
    }
    sprite.End();
    if (event_active) {
        DngStatus.cursor_fade += 0.16666667f;
        if (DngStatus.cursor_fade >= 1.0f) DngStatus.cursor_fade = 1.0f;
    } else {
        DngStatus.cursor_fade -= 0.33333334f;
        if (DngStatus.cursor_fade <= 0.0f) DngStatus.cursor_fade = 0.0f;
    }
    DrawActiveItemCursor(DngStatus.active_item * 0x2A + 0x44, y + 0x26, DngStatus.cursor_fade);
    int glyph_words[4] = {0, 0xE8, 0xC, 0xC};
    mgRect<int> &glyph = *(mgRect<int> *)glyph_words;
    for (int i = 0; i < 3; ++i) {
        if (items[i].GetNum() >= 2)
            PrintV(0x40 + i * 0x29, y + 0x2D, items[i].GetNum(), TEX_SystenFrame,
                   glyph, 2, 1, 10, NULL);
    }
    const int sword_pos[7][2] = {{0x10E, 0x12}, {0x10A, 0x21}, {0x10E, 0x30},
                                  {0x119, 0x3B}, {0x128, 0x3F}, {0x137, 0x3B}, {0x142, 0x30}};
    const int sword_tex[4][2] = {{0xDA, 0xCE}, {0xE4, 0xCE}, {0xDA, 0xD8}, {0xE4, 0xD8}};
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Texture(TEX_SystenFrame);
    int alpha = (int)(128.0f * rate);
    sprite.Color(0x80, 0x80, 0x80, alpha);
    int sword_max = battle->GetMagicSwordCounterMax();
    int sword_now = battle->GetMagicSwordCounterNow();
    int sword_element = battle->GetMagicSwordElem();
    for (int i = 0; i < sword_max; ++i) {
        if (i < sword_now && sword_element >= 0 && sword_element < 4)
            sprite.SetIRect(sword_pos[i][0], sword_pos[i][1], 10, 10,
                            sword_tex[sword_element][0], sword_tex[sword_element][1]);
        else sprite.SetIRect(sword_pos[i][0], sword_pos[i][1], 10, 10, 0xD0, 0xD8);
    }
    sprite.End();
    const u32 attribute_mask[7] = {1, 2, 8, 4, 0x10, 0x20, 0x40};
    const int attribute_uv[7][2] = {{0, 0}, {0x18, 0x18}, {0, 0x18}, {0x30, 0},
                                     {0x18, 0}, {0x30, 0x18}, {0x48, 0}};
    u32 attributes = battle->GetAttr();
    if (attributes) {
        sprite.Initialize(NULL, NULL);
        sprite.Preset2D();
        sprite.Begin(6);
        sprite.Texture(TEX_StatusIcon);
        sprite.Color(0x80, 0x80, 0x80, alpha);
        int icon_x = 0x18;
        for (int i = 0; i < 7; ++i) {
            if (attributes & attribute_mask[i]) {
                sprite.SetIRect(icon_x, 0x4A, 0x18, 0x18, attribute_uv[i][0], attribute_uv[i][1]);
                icon_x += 0x1A;
            }
        }
        sprite.End();
    }
    SP_RGBA color = {0x80, 0x80, 0x80, 0x80};
    if (hp_rate < 0.2f) {
        color.r += pulse;
        color.g -= pulse;
        color.b -= pulse;
    }
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(4);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(color.r, color.g, color.b, color.a);
    if (hp[0] > 0) DRAW_GAUGE_STRIP(sprite, 0x32, (int)(171.0f * hp_rate) + 0x2D,
                                 y + 6, y + 0xB, 0x46, 0xA2);
    sprite.End();
    PrintV(0xA1, y + 0xE, hp[0], TEX_SystenFrame, glyph, 5, 1, 10, NULL);
    PrintV(0xDD, y + 0xE, hp[1], TEX_SystenFrame, glyph, 5, 0, 10, NULL);
    for (int weapon = 0; weapon < 2; ++weapon) {
        int x = weapon == 0 ? 0x118 : second_x + 0x3A;
        int board_y = weapon == 0 ? y : 0x11;
        color.r = color.g = color.b = 0x80;
        if (whp_rate[weapon] < 0.2f) {
            if (whp[weapon][0] <= 0) {
                color.r += pulse;
                color.g -= pulse;
                color.b -= pulse;
            } else color.r = color.g = color.b = 0x80 - pulse;
        }
        sprite.Preset2D();
        sprite.Begin(6);
        sprite.Texture(TEX_SystenFrame);
        sprite.Color(color.r, color.g, color.b, 0x80);
        sprite.SetIRect(x, board_y, 0x94, 0x32, 0xEC, weapon == 0 ? 0x2E : 0x60);
        sprite.SetIRect(x + 0x40, board_y + 0x13, 0xC, 0xC, 0x78, 0xE8);
        if (battle->equip[weapon].item_no > 0) {
            sprite.Texture(TEX_DummyIcon2);
            sprite.SetIStretch(x + 4, board_y + 0xA, 0x1C, 0x23,
                               weapon * 0x20, 0, 0x1F, 0x1F);
        }
        sprite.End();
        sprite.Preset2D();
        sprite.Begin(4);
        sprite.Texture(TEX_SystenFrame);
        sprite.Color(0x80, 0x80, 0x80, 0x80);
        DRAW_GAUGE_STRIP(sprite, x + 0x24, x + 0x24 + (int)(95.0f * whp_rate[weapon]),
                       board_y + 5, board_y + 9, 0x46, 0xB2);
        sprite.End();
        battle->GetNowAbs(weapon, abs[weapon]);
        sprite.Preset2D();
        sprite.Begin(4);
        DRAW_GAUGE_STRIP(sprite, x + 0x26,
                       x + 0x26 + (int)(95.0f * ((float)abs[weapon][0] / (float)abs[weapon][1])),
                       board_y + 0xA, board_y + 0xD, 0x46, 0xB6);
        sprite.End();
        PrintV(x + 0xF, board_y + 0x13, whp[weapon][0], TEX_SystenFrame,
               glyph, 5, 1, 10, &color);
        PrintV(x + 0x4C, board_y + 0x13, whp[weapon][1], TEX_SystenFrame,
               glyph, 5, 0, 10, &color);
    }
    if (rate >= 1.0f && !SubGameRunning()) {
        WarningGage2.warning[0] = hp_rate < 0.3f;
        WarningGage2.warning[1] = whp_rate[0] < 0.2f;
        WarningGage2.warning[2] = whp_rate[1] < 0.2f;
        WarningGage2.rate[0] = hp_rate;
        WarningGage2.rate[1] = whp_rate[0];
        WarningGage2.rate[2] = whp_rate[1];
        WarningGage2.layout = 0;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawMainUnitStatusBord__Ff);
#endif
#ifdef NONMATCHING
void DrawRoboUnitStatusBord(float rate) {
    int y = (int)(80.0f * rate) - 0x48;
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    int maximum_hp = battle->GetMaxHp_i();
    int current_hp = battle->GetNowHp_i();
    int whp[2];
    int abs[2];
    battle->GetNowWhp(0, whp);
    float hp_rate = (float)current_hp / (float)maximum_hp;
    float whp_rate = (float)whp[0] / (float)whp[1];
    if (!init_1223) { palanim_1222 = 0.0f; init_1223 = 1; }
    palanim_1222 += 0.19634955f;
    if (palanim_1222 > 0.0f) palanim_1222 -= 3.1415927f;
    int pulse = (int)(-64.0f * sinf(palanim_1222));
    SP_RGBA color = {0x80, 0x80, 0x80, 0x80};
    if (whp_rate < 0.2f) {
        if (whp_rate <= 0.0f) {
            color.r += pulse;
            color.g -= pulse;
            color.b -= pulse;
        } else {
            color.r -= pulse;
            color.g -= pulse;
            color.b -= pulse;
        }
    }
    CPreSprite sprite;
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Bilinear(0);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    sprite.SetIRect(0xBA, y + 8, 0x2A, 0x16, 0xC0, 0);
    sprite.SetIRect(0xDB, y, 0x60, 0x2E, 0x120, 0x92);
    sprite.SetIRect(0x10, y, 0xC0, 0x2A, 0, 0);
    sprite.Color(color.r, color.g, color.b, color.a);
    sprite.SetIRect(0x140, y, 0xB0, 0x28, 0, 0x2A);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    sprite.SetIRect(0x6A, y + 0x14, 0xC, 0xC, 0x78, 0xE8);
    sprite.Color(color.r, color.g, color.b, color.a);
    sprite.SetIRect(0x1A4, y + 0x12, 0xC, 0xC, 0x78, 0xE8);
    sprite.Texture(TEX_DummyIcon2);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    sprite.SetIStretch(0x16, y + 6, 0x1C, 0x23, 0, 0, 0x1F, 0x1F);
    sprite.Color(color.r, color.g, color.b, color.a);
    sprite.SetIStretch(0x1CC, y + 6, 0x1C, 0x23, 0x20, 0, 0x1F, 0x1F);
    sprite.End();
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(4);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    int hp_width = (int)(141.0f * hp_rate);
    DRAW_GAUGE_STRIP(sprite, 0x3E, hp_width + 0x3A, y + 5, y + 9, 0x50, 0xB4);
    sprite.End();
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(4);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(color.r, color.g, color.b, color.a);
    DRAW_GAUGE_STRIP(sprite, 0x151, (int)(107.0f * whp_rate) + 0x151, y + 8, y + 0xC, 0x46, 0xB2);
    sprite.End();
    int glyph_words[4] = {0, 0xE8, 0xC, 0xC};
    mgRect<int> &glyph = *(mgRect<int> *)glyph_words;
    PrintV(0x172, y + 0x12, whp[0], TEX_SystenFrame, glyph, 5, 1, 10, &color);
    PrintV(0x1AE, y + 0x12, whp[1], TEX_SystenFrame, glyph, 5, 0, 10, &color);
    SP_RGBA white = {0x80, 0x80, 0x80, 0x80};
    PrintV(0x38, y + 0x14, current_hp, TEX_SystenFrame, glyph, 5, 1, 10, &white);
    PrintV(0x74, y + 0x14, maximum_hp, TEX_SystenFrame, glyph, 5, 0, 10, &white);
    battle->GetNowAbs(0, abs);
    DrawDrumCounter(0xE6, y + 0x13, abs[0]);
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    sprite.SetIRect(hp_width + 0x39, y - 3, 8, 0x18, 0xB0, 0x2A);
    sprite.End();
    WarningGage2.warning[0] = hp_rate < 0.3f;
    WarningGage2.warning[1] = whp_rate < 0.2f;
    WarningGage2.rate[0] = hp_rate;
    WarningGage2.rate[1] = whp_rate;
    WarningGage2.layout = 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawRoboUnitStatusBord__Ff);
#endif
#ifdef NONMATCHING
void DrawMonsterUnitStatusBord(float rate) {
    if (rate < 1.0f) return;
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    int maximum_hp = battle->GetMaxHp_i();
    int current_hp = battle->GetNowHp_i();
    int whp[2];
    int abs[2];
    battle->GetNowWhp(0, whp);
    float hp_rate = (float)current_hp / (float)maximum_hp;
    CPreSprite sprite;
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(6);
    sprite.Bilinear(0);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    sprite.SetIRect(0x10, 8, 0xCA, 0x16, 0, 0x52);
    sprite.SetIRect(0x12C, 8, 0xC8, 0x24, 0, 0x68);
    sprite.SetIRect(0xA2, 0x18, 0xC, 0xC, 0x78, 0xE8);
    sprite.SetIRect(0x177, 0x1D, 0xC, 0xC, 0x78, 0xE8);
    sprite.End();
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(4);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    int hp_end = (int)(176.0f * hp_rate) + 0x20;
    int hp_bottom = hp_end < 0xC9 ? hp_end : 0xC8;
    DRAW_GAUGE_STRIP(sprite, 0x28, hp_end, 0xE, 0x13, 0x46, 0xA2);
    sprite.End();
    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.Begin(4);
    sprite.Texture(TEX_SystenFrame);
    sprite.Color(0x80, 0x80, 0x80, 0x80);
    int whp_end = (int)(137.0f * ((float)whp[0] / (float)whp[1])) + 0x157;
    DRAW_GAUGE_STRIP(sprite, 0x153, whp_end, 0xD, 0x12, 0x46, 0xA8);
    sprite.End();
    battle->GetNowAbs(0, abs);
    sprite.Preset2D();
    sprite.Begin(4);
    int abs_end = (int)(137.0f * ((float)abs[0] / (float)abs[1])) + 0x157;
    DRAW_GAUGE_STRIP(sprite, 0x157, abs_end, 0x14, 0x17, 0x46, 0xB6);
    sprite.End();
    int glyph_words[4] = {0, 0xE8, 0xC, 0xC};
    mgRect<int> &glyph = *(mgRect<int> *)glyph_words;
    SP_RGBA color = {0x80, 0x80, 0x80, 0x80};
    PrintV(0x6E, 0x18, current_hp, TEX_SystenFrame, glyph, 5, 1, 10, &color);
    PrintV(0xAC, 0x18, maximum_hp, TEX_SystenFrame, glyph, 5, 0, 10, &color);
    PrintV(0x160, 0x1D, whp[1], TEX_SystenFrame, glyph, 5, 1, 10, &color);
    PrintV(0x163, 0x1D, whp[0], TEX_SystenFrame, glyph, 5, 0, 10, &color);
    WarningGage2.warning[0] = hp_rate < 0.3f;
    WarningGage2.rate[0] = hp_rate;
    WarningGage2.layout = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_status", DrawMonsterUnitStatusBord__Ff);
#endif
void DrawStatusBord() {
    int active = DngUserData->active_chr_no;
    float rate = BattleAreaScene->statusbar_rate;
    WarningGage2.warning[0] = 0;
    WarningGage2.warning[1] = 0;
    WarningGage2.warning[2] = 0;
    LockOnModel.pos[3] = 0.0f;
    switch (active) {
    case USER_CHARA_MAX:
    case USER_CHARA_MONICA:
        DrawMainUnitStatusBord(rate);
        break;
    case USER_CHARA_ROBO:
        DrawRoboUnitStatusBord(rate);
        break;
    case USER_CHARA_MONSTER:
        DrawMonsterUnitStatusBord(rate);
        break;
    }
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1048__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1049__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1058__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_status", at_1059__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(cur_ang_1005, 0x4);
INCLUDE_BSS(init_1006, 0x4);
INCLUDE_BSS(palanim_1023, 0x4);
INCLUDE_BSS(init_1024, 0x4);
INCLUDE_BSS(palanim_1222, 0x4);
INCLUDE_BSS(init_1223, 0x4);
