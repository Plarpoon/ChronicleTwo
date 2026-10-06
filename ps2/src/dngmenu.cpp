#include "common.h"
#include "dngmenu.hpp"
#include "dngfloor.hpp"
#include "gamedata.hpp"
#include "mainloop.hpp"
#include "mapselect.hpp"
#include "menucommon.hpp"
#include "menuaqua.hpp"
#include "menudraw.hpp"
#include "menumain.hpp"
#include "menuop.hpp"
#include "memcard.hpp"
#include "mg_memory.hpp"
#include "scenesnd.hpp"
#include "sysmes.hpp"
#include "userdata.hpp"
#include "mg_drawprim.hpp"
#include "mglib.hpp"
#include "mg_texture.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifdef NONMATCHING
extern float DngTreeMapActiveLightRate;
extern CMenuTreeMap *CMenuTreePt;
extern mgRect<float> treemap_root_put;
static void DrawDngRoomInfo(DNGMAP_ROOM_INFO *room);
#endif

// Code (.text)
#ifdef NONMATCHING
void CDngFreeMap::Initialize() {
    active = 1;
    unk_9 = 0;
    dng_no = 0;
    floor_manager = NULL;
    save_dungeon = NULL;
    mode = DNGMAP_MODE_MENU;
    view_rect.Set(120.0f, 138.0f, 420.0f, 286.0f);
    mark_num = 0;
    next_room_no = -1;
    user_room_no = -1;
    back_scroll = 0.0f;
    pos_x = pos_y = 0.0f;
    next_pos_x = next_pos_y = 200.0f;
    select_glid = NULL;
    InitTexture();
    alpha = 128.0f;
    user_glid = NULL;
    blink_cnt = 0;
    koma_now = koma_path = NULL;
    koma_move = 0;
    fade_mode = DNGMAP_FADE_NONE;
    fade_time = -1;
    fade_step = 0.0f;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Initialize__11CDngFreeMapFv);
#endif
void CDngFreeMap::InitTexture(void) {
    map_tex = NULL;
    last_tex = NULL;
    koma_tex = NULL;
    name_tex = NULL;
    tex_block = -1;
}
#ifdef NONMATCHING
void CDngFreeMap::SetUserGlid(int room_no) {
    user_glid = NULL;
    if (room_no >= 0) {
        user_glid = GetRoomGlid(room_no);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", SetUserGlid__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::CalcGlidPutPos(GLID_INFO *glid, float &x, float &y, int board) {
    if (glid != NULL) {
        x = (float)(glid->x * 52 - glid->y * 16);
        y = (float)(glid->y * 20);
        if (board == 0) {
            x += pos_x;
            y += pos_y;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", CalcGlidPutPos__11CDngFreeMapFP9GLID_INFORfRfi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::CheckIsViewMove(int x, int y, float &move_x, float &move_y) {
    int clipped_x = x;
    int clipped_y = y;
    if ((float)x < view_rect.left) {
        clipped_x = (int)view_rect.left;
    }
    if ((float)clipped_x > view_rect.right - 10.0f) {
        clipped_x = (int)(view_rect.right - 10.0f);
    }
    if ((float)y < view_rect.top) {
        clipped_y = (int)view_rect.top;
    }
    if ((float)(clipped_y - 10) > view_rect.bottom) {
        clipped_y = (int)(view_rect.bottom - 10.0f);
    }
    move_x = (float)(clipped_x - x);
    move_y = (float)(clipped_y - y);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", CheckIsViewMove__11CDngFreeMapFiiRfRf);
#endif
#ifdef NONMATCHING
void CDngFreeMap::SetNextRoomPos(GLID_INFO *glid) {
    if (glid != NULL) {
        float x, y, move_x, move_y;
        CalcGlidPutPos(glid, x, y, 0);
        CheckIsViewMove((int)x, (int)y, move_x, move_y);
        next_pos_x = pos_x + move_x;
        next_pos_y = pos_y + move_y;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", SetNextRoomPos__11CDngFreeMapFP9GLID_INFO);
#endif
GLID_INFO *CDngFreeMap::GetNextGlid(GLID_INFO *glid, int *direction) {
    if (glid == NULL || floor_manager == NULL) {
        return NULL;
    }
    return floor_manager->GetNextGlid(glid, direction);
}
GLID_INFO *CDngFreeMap::GetRoomGlid(int room_no) {
    return floor_manager != NULL ? floor_manager->GetDngMapFloorGlidInfo(room_no) : NULL;
}
GLID_INFO *CDngFreeMap::GetEntranceRoomGlid() {
    if (floor_manager == NULL) {
        return NULL;
    }
    for (int i = 0; i < floor_manager->glid_num; i++) {
        GLID_INFO *glid = &floor_manager->glid_info[i];
        if (glid->type == GLID_TYPE_ROOM && (glid->room.flag & DNGMAP_ROOM_FLAG_START)) {
            return glid;
        }
    }
    return NULL;
}
#ifdef NONMATCHING
void CDngFreeMap::SetTextureInfo() {
    map_tex = mgTexManager.GetTexture("dt", -1);
    last_tex = mgTexManager.GetTexture("dtbg", -1);
    koma_tex = mgTexManager.GetTexture("dngop", -1);
    name_tex = mgTexManager.GetTexture("dtname", -1);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", SetTextureInfo__11CDngFreeMapFv);
#endif
#ifdef NONMATCHING
void CDngFreeMap::ResetDngMapPos(int room_no, int at_once) {
    GLID_INFO *glid = GetRoomGlid(room_no);
    if (glid == NULL) {
        pos_x = next_pos_x = -100.0f;
        pos_y = next_pos_y = -100.0f;
        return;
    }
    float x, y;
    CalcGlidPutPos(glid, x, y, 1);
    next_pos_x = 256.0f - x;
    next_pos_y = 208.0f - y;
    if (at_once != 0) {
        pos_x = next_pos_x;
        pos_y = next_pos_y;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", ResetDngMapPos__11CDngFreeMapFii);
#endif
#ifdef NONMATCHING
void CDngFreeMap::DrawBackPattern(int opacity) {
    mgCDrawPrim *prim = GetMenuPrim();
    if (mode == DNGMAP_MODE_EVENT && opacity >= 0) {
        SetSpriteEnv(prim, 2);
        prim->Bilinear(1);
        prim->AntiAliasing(1);
        prim->Begin(6);
        prim->Color(0, 0, 0, 32);
        prim->Vertex(0, 0, 0);
        prim->Vertex(mgScreenWidth, mgScreenHeight, 0);
        prim->End();
    }
    if (mode == DNGMAP_MODE_MENU && map_tex != NULL) {
        mgRect<int> tile;
        tile.Set(0, 256, 128, 128);
        DrawMenuTilePattern(prim, map_tex, back_scroll, back_scroll, tile, 1, NULL);
        back_scroll += 0.5f;
        if (back_scroll >= 0.0f) {
            back_scroll -= (float)tile.right;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawBackPattern__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::DrawDngName(int opacity) {
    if (name_tex != NULL) {
        mgRect<int> tex_rect;
        tex_rect.Set(0, 0, 256, 96);
        mgCDrawPrim *prim = GetMenuPrim();
        SetSpriteEnv(prim, 0);
        prim->Begin(6);
        prim->Texture(name_tex);
        prim->Color(10, 10, 10, (int)(0.25f * (float)opacity));
        PrimQuad(prim, 4.0f, 4.0f, tex_rect);
        prim->Color(128, 128, 128, 128);
        PrimQuad(prim, 0.0f, 0.0f, tex_rect);
        prim->End();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawDngName__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::DrawLast() {
    if (last_tex == NULL || mode == DNGMAP_MODE_EVENT) {
        return;
    }
    mgCDrawPrim *prim = GetMenuPrim();
    SetSpriteEnv(prim, 4);
    prim->AlphaBlend(1);
    prim->Begin(6);
    prim->Texture(last_tex);
    prim->Color(128, 128, 128, 128);
    prim->TextureCrd(0, 0);
    prim->Vertex(0, 0, 0);
    prim->TextureCrd(128, 128);
    prim->Vertex(mgScreenWidth, mgScreenHeight, 0);
    prim->End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawLast__11CDngFreeMapFv);
#endif
#ifdef NONMATCHING
/**
 *
 * Offset of a passage mark from its grid cell.
 *
 */
struct RootMarkOffset { s16 x; s16 y; };
extern RootMarkOffset markOffsetTable_1092[];
extern RootMarkOffset zerumaito_offset_1110;
extern s16 root_type_texturecrd_1216[][2];
void CDngFreeMap::DrawRoot(mgRect<float> rect, DNGMAP_ROOT_INFO *root, int shadow, unsigned int marks, int opacity) {
    if (root == NULL || (float)mgScreenWidth < rect.left || rect.top > (float)(mgScreenHeight + 20)) {
        return;
    }
    mgRect<float> &put = treemap_root_put;
    put = rect;
    if (shadow != 0) {
        put.left += 8.0f;
        put.top += 8.0f;
    }
    float red = mode == DNGMAP_MODE_EVENT ? 128.0f : 212.0f;
    float green = mode == DNGMAP_MODE_EVENT ? 111.0f : 192.0f;
    float blue = mode == DNGMAP_MODE_EVENT ? 0.0f : 144.0f;
    float mark_color = mode == DNGMAP_MODE_EVENT ? 64.0f : 128.0f;
    RootMarkOffset *mark = markOffsetTable_1092;
    mgCDrawPrim *prim = GetMenuPrim();
    SetSpriteEnv(prim, 2);
    prim->Begin(1);
    prim->Color((int)red, (int)green, (int)blue, opacity);
    if (shadow != 0) {
        prim->Color(0, 0, 0, (int)(0.05f * (float)opacity));
    }
    if (root->shape == 1 || (root->shape >= 2 && root->shape < 4) ||
        (root->shape >= 4 && root->shape < 6) || (root->shape >= 6 && root->shape < 8)) {
        put.left -= 5.0f;
    }
    put.right = put.left + 52.0f;
    put.bottom = put.top + 20.0f;
    switch (root->shape) {
        case 0:
            put.left += 26.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left + (float)i, put.top, 0.0f);
                prim->Vertex(put.left + (float)i - 16.0f, put.bottom, 0.0f);
            }
            if (dng_no == 6) mark = &zerumaito_offset_1110;
            break;
        case 1:
            if (marks & 0x100) put.left += 14.0f;
            put.top += 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - (float)i, put.top + (float)i, 0.0f);
                prim->Vertex(put.right - (float)i, put.top + (float)i, 0.0f);
            }
            mark = &markOffsetTable_1092[1];
            break;
        case 2:
            put.left += 25.0f;
            put.top += 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - (float)i, put.top + (float)i, 0.0f);
                prim->Vertex(put.right - (float)i, put.top + (float)i, 0.0f);
            }
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left + (float)i, put.top, 0.0f);
                prim->Vertex(put.left + (float)i - 10.0f, put.bottom, 0.0f);
            }
            mark = &markOffsetTable_1092[2];
            break;
        case 3:
            put.right -= 27.0f;
            put.top += 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - (float)i, put.top + (float)i, 0.0f);
                prim->Vertex(put.right - (float)i, put.top + (float)i, 0.0f);
            }
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.right + (float)i, put.top, 0.0f);
                prim->Vertex(put.right + (float)i - 10.0f, put.bottom, 0.0f);
            }
            mark = &markOffsetTable_1092[3];
            break;
        case 4:
            put.left += 26.0f;
            put.bottom -= 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left + (float)i, put.top, 0.0f);
                prim->Vertex(put.left + (float)i - 10.0f, put.bottom + 2.0f, 0.0f);
            }
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - 7.0f - (float)i, put.bottom + (float)i, 0.0f);
                prim->Vertex(put.right - 5.0f - (float)i, put.bottom + (float)i, 0.0f);
            }
            mark = &markOffsetTable_1092[4];
            break;
        case 5:
            put.right -= 26.0f;
            put.bottom -= 10.0f;
            put.left += 1.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - 6.0f - (float)i, put.bottom + (float)i, 0.0f);
                prim->Vertex(put.right - 6.0f - (float)i, put.bottom + (float)i, 0.0f);
            }
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.right + (float)i, put.top, 0.0f);
                prim->Vertex(put.right + (float)i - 9.0f, put.bottom, 0.0f);
            }
            mark = &markOffsetTable_1092[5];
            put.left = put.right;
            break;
        case 6:
            put.left += 15.5f;
            put.top += 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left + (float)i, put.bottom, 0.0f);
                prim->Vertex(put.right - (float)i, put.top + (float)i, 0.0f);
            }
            break;
        case 7:
            put.left -= 1.0f;
            put.right -= 35.0f;
            put.top += 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - (float)i / 2.0f, put.top + (float)i, 0.0f);
                prim->Vertex(put.right - (float)i, put.bottom, 0.0f);
            }
            break;
        case 8:
            put.left += 26.0f;
            put.right -= 5.5f;
            put.bottom -= 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left + 1.5f - (float)i, put.top, 0.0f);
                prim->Vertex(put.right - (float)i / 2.0f, put.bottom + (float)i, 0.0f);
            }
            break;
        case 9:
            put.left -= 6.0f;
            put.right -= 26.0f;
            put.bottom -= 10.0f;
            for (int i = 0; i < 3; i++) {
                prim->Vertex(put.left - (float)i, put.bottom + (float)i, 0.0f);
                prim->Vertex(put.right + (float)i, put.top, 0.0f);
            }
            break;
    }
    prim->End();
    prim->Bilinear(0);
    prim->TextureMapEnable(1);
    prim->Begin(6);
    prim->Color((int)red, (int)green, (int)blue, opacity);
    if (shadow != 0) {
        prim->Color(0, 0, 0, (int)(0.05f * (float)opacity));
    }
    prim->Texture(map_tex);
    if (root->type != 0 && root->opened != 0 && root->show_mark != 0 && mark != NULL) {
        prim->Color((int)mark_color, (int)mark_color, (int)mark_color, opacity);
        if (shadow != 0) {
            prim->Color(0, 0, 0, (int)(0.05f * (float)opacity));
        }
        int u = root_type_texturecrd_1216[root->type][0];
        int v = root_type_texturecrd_1216[root->type][1];
        prim->TextureCrd(u, v);
        prim->Vertex(rect.left + (float)mark->x, rect.top + (float)mark->y, 0.0f);
        prim->TextureCrd(u + 22, v + 22);
        prim->Vertex(rect.left + (float)mark->x + 22.0f, rect.top + (float)mark->y + 22.0f, 0.0f);
    }
    prim->End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawRoot__11CDngFreeMapF9mgRect_f_P16DNGMAP_ROOT_INFOiUii);
#endif
#ifdef NONMATCHING
unsigned int CDngFreeMap::DrawGlidCheck(GLID_INFO *glid) {
    unsigned int marks = 0;
    if (glid == NULL) {
        return 0;
    }
    for (int direction = 0; direction < GLID_DIR_NUM; direction++) {
        GLID_INFO *neighbour = glid->link_glid[direction];
        if (neighbour == NULL || glid->type != GLID_TYPE_ROOT || neighbour->type != GLID_TYPE_ROOM) {
            continue;
        }
        if (direction == GLID_DIR_UP && neighbour->y + 1 == glid->y) {
            marks |= 2;
        }
        if (direction == GLID_DIR_LEFT && neighbour->x + 1 == glid->x) {
            marks |= 8;
        }
        if ((neighbour->room.flag & (DNGMAP_ROOM_FLAG_SUB | DNGMAP_ROOM_FLAG_BOSS)) && neighbour->room.visited != 0) {
            if (neighbour->x == glid->x) {
                if (neighbour->y == glid->y - 1) marks |= 0x40;
                if (neighbour->y == glid->y + 1) marks |= 0x80;
            }
            if (neighbour->y == glid->y) {
                if (neighbour->x == glid->x - 1) marks |= 0x100;
                if (neighbour->x == glid->x + 1) marks |= 0x200;
            }
        }
    }
    return marks;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawGlidCheck__11CDngFreeMapFP9GLID_INFO);
#endif
#ifdef NONMATCHING
/**
 *
 * Source rectangle of a room's letter or symbol.
 *
 */
struct RoomGlyph { s16 x; s16 y; s16 w; s16 h; };
/**
 *
 * Offset of a room's letter or symbol within its picture.
 *
 */
struct RoomGlyphOffset { s16 x; s16 y; };
extern RoomGlyph get_moji_tbl_1524[];
extern RoomGlyphOffset put_moji_tbl_1525[];
extern float stepCntTbl_1501[2];
void CDngFreeMap::DrawRoomOne(mgRect<float> rect, DNGMAP_ROOM_INFO *room, unsigned int unused, int opacity, float brightness) {
    if (room == NULL || rect.left > (float)(mgScreenWidth + 20) || rect.top > (float)(mgScreenHeight + 30)) {
        return;
    }
    rect.left -= 30.0f;
    rect.top -= 42.0f;
    mgRect<float> picture = rect;
    mgCDrawPrim *prim = GetMenuPrim();
    SetSpriteEnv(prim, 0);
    picture.right = 96.0f;
    picture.bottom = 66.0f;
    if (dng_no == 4 || dng_no == 5 || dng_no == 6) {
        picture.right = 100.0f;
        picture.bottom = 68.0f;
    }
    mgRect<int> tex;
    mgRect<int> special;
    tex.Set(0, 66, 96, 66);
    special.Set(192, 198, 96, 96);
    if (room->visited == 0) {
        tex.left = 0;
        tex.top = 0;
    } else {
        tex.left += tex.right * (room->tex_no % 5);
        tex.top += tex.bottom * (room->tex_no / 5);
        if (room->flag & DNGMAP_ROOM_FLAG_START) {
            tex.left = 96;
            tex.top = 0;
        }
        if (room->flag & DNGMAP_ROOM_FLAG_EXIT) {
            tex.left = 192;
            tex.top = 0;
        }
        if (room->flag & (DNGMAP_ROOM_FLAG_SUB | DNGMAP_ROOM_FLAG_BOSS)) {
            tex.left = special.left + (room->tex_no % 3) * 96;
            tex.top = special.top + (room->tex_no / 3) * 96;
            tex.right = special.right;
            tex.bottom = room->tex_no >= 3 ? 90 : special.bottom;
            picture.right = (float)special.right;
            picture.bottom = (float)special.bottom;
        }
        picture.left += (float)room->offset_x;
        picture.top += (float)room->offset_y;
    }
    int level = (int)(128.0f * brightness);
    float event_brightness = 1.0f;
    if (mode == DNGMAP_MODE_EVENT && user_glid != NULL && &user_glid->room != room) {
        level = (int)(64.0f * brightness);
        event_brightness = 0.5f;
    }
    if (mode == DNGMAP_MODE_MENU) {
        prim->Begin(6);
        prim->Texture(map_tex);
        prim->Color(0, 0, 0, (int)(0.25f * (float)opacity));
        PrimQuad(prim, picture.left + 8.0f, picture.top + 8.0f, tex);
        prim->End();
    }
    SetSpriteEnv(prim, 0);
    room->mark_phase += stepCntTbl_1501[mode];
    if (room->mark_phase > 3.1415927f) {
        room->mark_phase -= 6.2831855f;
    }
    int red = 192;
    if (room->mark != 0) {
        float phase = room->mark_phase;
        while (phase > 3.1415927f) phase -= 6.2831855f;
        while (phase < -3.1415927f) phase += 6.2831855f;
        if (phase > 0.0f) red = (int)(7.0f * (float)level / 8.0f);
    } else {
        red = level;
    }
    prim->Bilinear(0);
    prim->Begin(6);
    prim->Texture(map_tex);
    prim->Color(red, red, red, opacity);
    PrimQuad(prim, picture, tex);
    prim->End();
    if (room->visited == 0 && user_glid != NULL && &user_glid->room != room) {
        prim->Begin(6);
        prim->Color(red, red, red, opacity);
        prim->TextureCrd(492, 66);
        prim->Vertex((int)(picture.left + 40.0f), (int)(picture.top + 25.0f), 0);
        prim->TextureCrd(512, 96);
        prim->Vertex((int)(picture.left + 60.0f), (int)(picture.top + 55.0f), 0);
        prim->End();
    }
    if (room->mark != 0) {
        float bob = 0.71875f * (6.0f * sinf(-room->mark_phase));
        mgRect<float> &mark = mark_rect[mark_num++];
        mark.left = picture.left + 64.0f;
        mark.top = picture.top + 4.0f - bob;
        mark.right = 64.0f + bob;
        mark.bottom = 46.0f + bob;
    }
    if (name_tex != NULL && room->visited == 1) {
        for (int i = 0; i < 3; i++) {
            if (!(room->flag & (1 << (i + 1)))) continue;
            RoomGlyph *glyph = &get_moji_tbl_1524[i];
            if (glyph->x < 0) continue;
            RoomGlyphOffset *offset = &put_moji_tbl_1525[i];
            prim->TextureMapEnable(1);
            prim->Begin(6);
            prim->Texture(name_tex);
            int tint = (int)(128.0f * event_brightness);
            prim->Color(tint, tint, tint, opacity);
            mgRect<int> glyph_rect;
            glyph_rect.Set(glyph->x, glyph->y, glyph->w, glyph->h);
            PrimQuad(prim, picture.left + (float)offset->x, picture.top + (float)offset->y, glyph_rect);
            prim->End();
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawRoomOne__11CDngFreeMapF9mgRect_f_P16DNGMAP_ROOM_INFOUiif);
#endif
#ifdef NONMATCHING
void CDngFreeMap::DrawGlid(mgRect<float> rect) {
    mgCDrawPrim prim;
    SetSpriteEnv(&prim, 1);
    prim.AntiAliasing(1);
    prim.Begin(2);
    prim.Color(255, 0, 0, (int)alpha);
    prim.Vertex(rect.left, rect.top, 0.0f);
    prim.Vertex(rect.left + rect.right, rect.top, 0.0f);
    prim.Vertex(rect.left + rect.right - 16.0f, rect.top + 20.0f, 0.0f);
    prim.Vertex(rect.left - 16.0f, rect.top + 20.0f, 0.0f);
    prim.Vertex(rect.left, rect.top, 0.0f);
    prim.End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawGlid__11CDngFreeMapF9mgRect_f_);
#endif
#ifdef NONMATCHING
static int CheckGeoramaMateria(TRESURE_BOX_FLOOR_INFO *info, int floor_no, int *items) {
    if (info == NULL || floor_no < 0) {
        return 0;
    }
    int count = 0;
    TRESURE_BOX_FLOOR *floor = &info->floor[floor_no];
    for (int floor_group = 0; floor_group < floor->group_num; floor_group++) {
        int group_id = floor->group_id[floor_group];
        if (group_id < 0) {
            break;
        }
        TRESURE_BOX_GROUP *group = NULL;
        for (int i = 0; i < info->group_num; i++) {
            if (info->group[i].group_id == group_id) {
                group = &info->group[i];
                break;
            }
        }
        if (group != NULL) {
            for (int i = 0; i < group->item_num; i++) {
                items[count++] = group->item[i].item_no;
            }
        }
    }
    for (int pass = 0; pass < 2; pass++) {
        for (int i = 0; i < count; i++) {
            if (!(GetItemDataAttribute(items[i]) & 0x10)) {
                local_sort1(i, &count, items);
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", CheckGeoramaMateria__FP22TRESURE_BOX_FLOOR_INFOiPi);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawDngRoomInfo__FP16DNGMAP_ROOM_INFO);
#ifdef NONMATCHING
extern mgCTexture *Floor_InfoTex;
extern unsigned char GeoramaMateriaInfoDrawPage;
extern short GeoramaMateriaNum;
extern mgRect<int> Floor_Info;
extern short dngboardbrdtbl[24];
extern short dngboardbrdtbl_2[12];
extern char at_1993[];

void DrawGeoramaMateria(int top_y, char *title, int unused_count, int *items, int tex_block) {
    int left = (mgScreenWidth - 0x1AE) >> 1;
    int column_left = mgScreenWidth / 3;
    int column_right = mgScreenWidth - column_left;
    mgTexManager.ReloadTexture(tex_block, (sceVif1Packet *)NULL);
    CMenuFont font;
    DrawMenuFillBox((float)(left + 6), (float)(top_y + 6), 422.0f, 272.0f,
                    0x59, 0xC, 0xC, 0xC);
    mgCDrawPrim *prim = GetMenuPrim();
    SetSpriteEnv(prim, 0);
    prim->Begin(6);
    prim->Texture(Floor_InfoTex);
    prim->Color(0x80, 0x80, 0x80, 0x80);
    mgRect<int> panel(left, top_y, 0x1AE, 0x46);
    Menu3DivideTextureDraw(prim, panel, dngboardbrdtbl, 1);
    panel.Set(left, top_y + 0x46, 0x1AE, 0xD2 - dngboardbrdtbl[15]);
    Menu3DivideTextureDraw(prim, panel, &dngboardbrdtbl[12], 1);
    panel.Set(left, top_y + 0x118 - dngboardbrdtbl_2[3], 0x1AE, dngboardbrdtbl_2[3]);
    Menu3DivideTextureDraw(prim, panel, dngboardbrdtbl_2, 1);
    PrimQuad(prim, (float)((mgScreenWidth >> 1) - (Floor_Info.right >> 1)) - 1.0f,
             (float)top_y + 10.0f, Floor_Info);
    prim->End();

    mgTexManager.ReloadTexture(MenuArg.mes_tex_block, (sceVif1Packet *)NULL);
    int text_w, text_h;
    font.SetStr(title);
    font.CalcDrawWH(font.str, &text_w, &text_h);
    font.SetPos((mgScreenWidth - text_w) >> 1, top_y + 0x26);
    font.DrawDirect(font.str, font.pos_x, font.pos_y);

    int first = GeoramaMateriaInfoDrawPage * 14;
    int last = first + 14;
    if (GeoramaMateriaNum < last) last = GeoramaMateriaNum;
    int row_y = top_y + 0x47;
    for (int index = first; index < last; ++index) {
        char *name = GetItemMessage(items[index]);
        if (name == NULL) continue;
        font.SetStr(name);
        font.CalcDrawWH(font.str, &text_w, &text_h);
        int column = (index % 2 == 0) ? column_left : column_right;
        font.SetPos(column - (text_w >> 1), row_y);
        font.DrawDirect(font.str, font.pos_x, font.pos_y);
        if (index % 2 != 0) row_y += 0x18;
    }
    char page[32];
    sprintf(page, at_1993, GeoramaMateriaInfoDrawPage + 1, GeoramaMateriaNum / 14 + 1);
    font.SetStr(page);
    font.SetPos(left + 0x186, top_y + 0xEF);
    font.DrawDirect(font.str, font.pos_x, font.pos_y);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawGeoramaMateria__FiPciPii);
#endif
#ifdef NONMATCHING
extern mgRect<int> dng_light_circle;
void CDngFreeMap::DrawTreeMap(int opacity) {
    mgRect<float> cell_rect;
    cell_rect.Set(0.0f, 0.0f, 52.0f, 20.0f);
    if (mode == DNGMAP_MODE_MENU) {
        mgCDrawPrim *prim = GetMenuPrim();
        float x, y;
        CalcGlidPutPos(select_glid, x, y, 0);
        x -= 38.0f;
        y -= 31.0f;
        float reach_x = 62.0f * (1.0f - DngTreeMapActiveLightRate);
        float reach_y = 40.0f * (1.0f - DngTreeMapActiveLightRate);
        SetSpriteEnv(prim, 4);
        prim->Bilinear(0);
        prim->Begin(6);
        prim->Texture(map_tex);
        prim->Color(128, 128, 128, (int)(0.5f * (float)opacity));
        prim->TextureCrd(dng_light_circle.left, dng_light_circle.top);
        prim->Vertex(x + reach_x, y + reach_y, 0.0f);
        prim->TextureCrd(dng_light_circle.left + dng_light_circle.right,
                         dng_light_circle.top + dng_light_circle.bottom);
        prim->Vertex(x + 124.0f - reach_x, y + 80.0f - reach_y, 0.0f);
        prim->End();
    }
    for (int i = 0; i < floor_manager->glid_num; i++) {
        GLID_INFO *glid = &floor_manager->glid_info[i];
        CalcGlidPutPos(glid, cell_rect.left, cell_rect.top, 0);
        if (menu_debug_flag != 0) {
            DrawGlid(cell_rect);
        }
        unsigned int marks = DrawGlidCheck(glid);
        if (glid->type == GLID_TYPE_ROOM) {
            float brightness = 1.0f;
            if (glid->blink != 0 && blink_cnt % 25 < 14) {
                brightness = 0.5f;
            }
            DrawRoomOne(cell_rect, &glid->room, 0, opacity, brightness);
        } else if (glid->type == GLID_TYPE_ROOT) {
            DrawRoot(cell_rect, &glid->root, 1, marks, opacity);
            DrawRoot(cell_rect, &glid->root, 0, marks, opacity);
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawTreeMap__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
extern float dng_player_pos[2];
extern int dng_player_blink_cnt;
void CDngFreeMap::DrawPlayer(int opacity) {
    if (user_glid == NULL || koma_tex == NULL) {
        return;
    }
    float x, y;
    CalcGlidPutPos(user_glid, x, y, 0);
    x += 4.0f;
    y -= 30.0f;
    if (mode == DNGMAP_MODE_EVENT) {
        if (koma_move != 0 && koma_now != NULL) {
            dng_player_pos[0] = koma_now->x;
            dng_player_pos[1] = koma_now->y;
            koma_now = koma_now->next;
        }
        x = dng_player_pos[0];
        y = dng_player_pos[1];
    }
    if (mode == DNGMAP_MODE_MENU) {
        y -= 6.0f * sinf(0.06283186f * (float)dng_player_blink_cnt);
    }
    dng_player_blink_cnt++;
    if (dng_player_blink_cnt >= 50) {
        dng_player_blink_cnt = 0;
    }
    float brightness = 16.0f + alpha + 16.0f * sinf(0.06283186f * (float)dng_player_blink_cnt);
    if (brightness < 0.0f) {
        brightness = 0.0f;
    }
    mgCDrawPrim *prim = GetMenuPrim();
    SetSpriteEnv(prim, 0);
    prim->Bilinear(1);
    prim->Begin(6);
    prim->Texture(koma_tex);
    int level = (int)brightness;
    prim->Color(level, level, level, opacity);
    mgRect<int> tex_rect;
    tex_rect.Set(0, 0, 30, 48);
    PrimQuad(prim, x, y, tex_rect);
    prim->End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DrawPlayer__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::Step() {
    if (active == 0) {
        return;
    }
    if (fade_mode == DNGMAP_FADE_IN) {
        alpha += fade_step;
        if (alpha > 128.0f) {
            alpha = 128.0f;
        }
    } else if (fade_mode == DNGMAP_FADE_OUT) {
        alpha += fade_step;
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
    }
    pos_x += (next_pos_x - pos_x) / 5.0f;
    pos_y += (next_pos_y - pos_y) / 5.0f;
    if (abs((int)(pos_x - next_pos_x)) < 1) {
        pos_x = next_pos_x;
    }
    if (abs((int)(pos_y - next_pos_y)) < 1) {
        pos_y = next_pos_y;
    }
    blink_cnt++;
    if (blink_cnt >= DNGMAP_BLINK_CYCLE) {
        blink_cnt = 0;
    }
    DngTreeMapActiveLightRate += 0.05f;
    if (DngTreeMapActiveLightRate >= 1.0f) {
        DngTreeMapActiveLightRate = 1.0f;
    }
    mark_num = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Step__11CDngFreeMapFv);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Draw__11CDngFreeMapFv);
#ifdef NONMATCHING
void CDngFreeMap::FadeIn(int frames) {
    fade_mode = DNGMAP_FADE_IN;
    fade_time = frames;
    fade_step = 128.0f;
    if (frames > 0) {
        fade_step = 128.0f / (float)frames;
    }
    alpha = 0.0f;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", FadeIn__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::FadeOut(int frames) {
    fade_mode = DNGMAP_FADE_OUT;
    fade_time = frames;
    fade_step = -128.0f;
    if (frames > 0) {
        fade_step = -128.0f / (float)frames;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", FadeOut__11CDngFreeMapFi);
#endif
#ifdef NONMATCHING
void CDngFreeMap::DeleteTexBlock() {
    if (tex_block >= 0) {
        mgTexManager.DeleteBlock(tex_block);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DeleteTexBlock__11CDngFreeMapFv);
#endif
void CDngFreeMap::SetKomaMove(int moving) {
    koma_move = moving;
    koma_now = koma_path;
    if (koma_now != NULL) {
        koma_now = koma_now->next;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", LoadDngInfo__11CDngFreeMapFP9mgCMemoryiiii);
#ifdef NONMATCHING
extern unsigned char DngTreeMode;
extern unsigned char TreeMapCallDungeonSubMap;
int CheckDngTreeMapFuncType() {
    if (MenuCommonInfo->open_type == 3) {
        return 2;
    }
    if (MenuCommonInfo->open_type == 1 || TreeMapCallDungeonSubMap == 1) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", CheckDngTreeMapFuncType__Fv);
#endif
#ifdef NONMATCHING
extern char *name_tbl_2728[8];
void MakeDngTreeMapJumpNo(int dng_no, int floor_id, int *loop_no, int *map_no) {
    if (dng_no == 0 && floor_id == 8) {
        *loop_no = 1;
        *map_no = SearchMapNo("s01");
    }
    if (dng_no == 1 && floor_id == 6) {
        *loop_no = 1;
        *map_no = SearchMapNo("s05");
    }
    if (dng_no == 3 && floor_id == 20) {
        *loop_no = 1;
        *map_no = SearchMapNo("d04b01");
        if (CheckBitFlagMenu(0x1B6) != 0 && CheckBitFlagMenu(0x1BC) == 0) {
            *loop_no = 2;
            *map_no = dng_no;
        }
    }
    if (floor_id == 0) {
        *loop_no = 1;
        *map_no = SearchMapNo(name_tbl_2728[dng_no]);
        if (dng_no == 6) {
            GetMainScene()->SetNowMapNo(SearchMapNo("d07f01"));
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", MakeDngTreeMapJumpNo__FiiPiPi);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", InitEnd__12CMenuTreeMapFv);
#ifdef NONMATCHING
extern short TreeMapSaveDispY;
extern unsigned char TreeMapSaveFlag;
void CMenuTreeMap::MsgInit() {
    for (int i = 0; i < DNG_TREE_MAP_MES_MAX; i++) {
        mes[i].SetMessData(mes_data, mes_data);
        mes[i].MsgPreset(15);
        mes[i].fuchi = 5;
        mes[i].value_zero = 1;
    }
    MenuCommandAnalyzeInfo.mes_buff[0] = mes_data;
    MenuCommandAnalyzeInfo.mes_buff[1] = GetMenuMainMessageBuffer();
    MenuCommandAnalyzeInfo.system_mes_buff[0] = mes_data;
    MenuCommandAnalyzeInfo.system_mes_buff[1] = GetSystemMesBuffer();
    ExeScript("MSG_INIT");
    CDC2Mes *message = MenuDCMsg[6];
    message->SetDrawSize(16, 20);
    message->ClsMes::mes_no = -1;
    message->MakeMsg(300);
    if (CheckDngTreeMapFuncType() == 2) {
        message->MakeMsg(81);
    } else if (CheckDngTreeMapFuncType() == 1) {
        message->MakeMsg(80);
    }
    message->StepMsg();
    int y = mgScreenHeight - 50;
    message->line_pos[0][0] = (mgScreenWidth >> 2) - (message->line_w[0] >> 1);
    message->line_pos[0][1] = y;
    message->line_pos_on[0] = 1;
    message->line_pos[1][0] = ((mgScreenWidth >> 2) * 3) - (message->line_w[1] >> 1);
    message->line_pos[1][1] = y;
    message->line_pos_on[1] = 1;
    TreeMapSaveDispY = y;
    if (TreeMapSaveFlag == 0) {
        message->line_pos[1][0] = 600;
        message->line_pos[1][1] = y;
        message->line_pos_on[1] = 1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", MsgInit__12CMenuTreeMapFv);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Step__12CMenuTreeMapFv);
#ifdef NONMATCHING
extern CDC2Mes *MenuDngMes[DNG_TREE_MAP_MES_MAX];
extern CDngFreeMap *MenuDngMap;
extern unsigned char dngfloor_infoview;
extern unsigned char dngfloor_backdraw;
extern int dngfloor_backdraw_alpha;
extern unsigned char GeoramaMateriaInfoDrawFlag;
extern unsigned char DngAskMessageDrawFlag;
extern short TreeMapSaveDispCount;
extern short TreeMapSaveNum;
extern float TreeMapSaveHopCount;
void CMenuTreeMap::Draw() {
    if ((mode & 2) && unk_11a == 1) {
        return;
    }
    MenuDngMap->Draw();
    int show_help = help_view != 0 && dngfloor_infoview == 0 && key_arg_no == 0;
    if (menu_debug_flag != 0) show_help = 0;
    mgCDrawPrim *prim = GetMenuPrim();
    if (show_help) {
        mgTexManager.ReloadTexture(MenuArg.mes_tex_block, (sceVif1Packet *)NULL);
        MenuDCMsg[6]->StepMsg();
        MenuDCMsg[6]->DrawMsg();
        if (TreeMapSaveFlag == 1) {
            TreeMapSaveDispCount++;
            if (TreeMapSaveDispCount >= 90) TreeMapSaveDispCount = 0;
            MenuDCMsg[6]->line_color[1] = 0x80E0E060;
            if (TreeMapSaveNum == 0) {
                if (TreeMapSaveHopCount < 0.6829549f || TreeMapSaveHopCount > 2.4586377f) {
                    MenuDCMsg[6]->line_color[1] = 0x80686A6B;
                }
                TreeMapSaveHopCount += 0.06829549f;
                if (TreeMapSaveHopCount >= 3.1415927f) TreeMapSaveHopCount -= 3.1415927f;
                MenuDCMsg[6]->line_pos[1][1] = (int)((float)TreeMapSaveDispY - 10.0f * sinf(TreeMapSaveHopCount));
                MenuDCMsg[6]->line_pos_on[1] = 1;
            }
        }
    }
    if (MenuDngMap->select_glid != NULL) {
        if (dngfloor_backdraw != 0) {
            CalcMenuAdd(&dngfloor_backdraw_alpha, 3, 64);
        } else {
            CalcMenuAdd(&dngfloor_backdraw_alpha, -3, 0);
        }
        DrawMenuFillBox(dngfloor_backdraw_alpha, 0, 0, 0);
        int medal = GetUserDataMan()->GetYarikomiMedal();
        int number_x = 540;
        int number_y = 0;
        int number_alpha = 0;
        if (Floor_InfoTex != NULL) {
            mgTexManager.ReloadTexture(Floor_InfoTex->block, (sceVif1Packet *)NULL);
            int alpha = dngfloor_backdraw_alpha * 2;
            SetSpriteEnv(prim, 0);
            prim->Begin(6);
            prim->Texture(Floor_InfoTex);
            prim->Color(0, 0, 0, alpha / 3);
            mgRect<int> board(0, 182, 164, 56);
            PrimQuad(prim, 289.0f, 25.0f, board);
            prim->Color(128, 128, 128, alpha);
            PrimQuad(prim, 286.0f, 22.0f, board);
            prim->End();
            number_y = 39;
            number_x = 410 - GetNumberKeta(medal) * 16;
            number_alpha = alpha;
        }
        DrawDngRoomInfo(&MenuDngMap->select_glid->room);
        if (GeoramaMateriaInfoDrawFlag != 0 && Floor_InfoTex != NULL) {
            DrawGeoramaMateria(94, MenuDngMap->select_glid->room.title,
                                GeoramaMateriaNum, georama_materia, Floor_InfoTex->block);
        }
        MenuDngMap->DrawDngName(128);
        mgTexManager.ReloadTexture(MenuArg.mes_tex_block, (sceVif1Packet *)NULL);
        CMenuFont font;
        char number[64];
        SetMenuBigNum(number, medal);
        font.SetStr(number);
        font.SetPos(number_x, number_y);
        font.DrawDirect(font.str, font.pos_x, font.pos_y);
        for (int i = 0; i < DNG_TREE_MAP_MES_MAX; i++) {
            MenuDngMes[i]->StepMsg();
            MenuDngMes[i]->DrawMsg();
        }
    }
    float x, y;
    MenuDngMap->CalcGlidPutPos(select_glid, x, y, 0);
    x -= 58.0f;
    y -= 8.0f;
    cursor_pos[0] += (x - cursor_pos[0]) / 4.0f;
    cursor_pos[1] += (y - cursor_pos[1]) / 4.0f;
    if (cursor_reset != 0) {
        cursor_pos[0] = x;
        cursor_pos[1] = y;
        cursor_reset = 0;
    }
    int cursor_alpha = (mode == 1 || mode == 2) ? 0 : 128;
    if (cursor_view != 0) {
        mgCTexture *cursor = mgTexManager.GetTexture("mnmain", -1);
        if (cursor == NULL) {
            return;
        }
        mgTexManager.ReloadTexture(cursor->block, (sceVif1Packet *)NULL);
        MenuCursorDraw(cursor, cursor_pos, 0.0f, cursor_alpha);
    }
    if (money_view != 0 && Floor_InfoTex != NULL) {
        mgTexManager.ReloadTexture(Floor_InfoTex->block, (sceVif1Packet *)NULL);
        SetSpriteEnv(prim, 0);
        int y_money = mgScreenHeight - 76;
        prim->Begin(6);
        prim->Texture(Floor_InfoTex);
        prim->Color(128, 128, 128, 128);
        mgRect<int> money_rect(0, 144, 184, 36);
        PrimQuad(prim, 302.0f, (float)y_money, money_rect);
        mgRect<int> number_rect(0, 126, 12, 18);
        PrimDrawNumber(prim, GetUserDataMan()->money, 0, 426, y_money + 7,
                       number_rect, -1, 0);
        prim->End();
    }
    mgTexManager.ReloadTexture(MenuArg.mes_tex_block, (sceVif1Packet *)NULL);
    if (key_arg_no == 1 && DngAskMessageDrawFlag == 1) {
        MenuDCMsg[3]->StepMsg();
        MenuDCMsg[3]->DrawMsg();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Draw__12CMenuTreeMapFv);
#endif
#ifdef NONMATCHING
int CMenuTreeMap::FadeInOutMenu() {
    int done = 0;
    switch (mode) {
        case 1:
            done = FadeCheckMenu();
            if (done != 0) {
                FadeOutMenu(40, 0.0f);
            }
            break;
        case 2:
            if (unk_11a == 0) {
                done = FadeCheckMenu();
            }
            break;
    }
    return done;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", FadeInOutMenu__12CMenuTreeMapFv);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DngTreeMapInit__FP9mgCMemoryPiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Init__6ClsMesFv);
#ifdef NONMATCHING
extern mgCMemory MenuTreeMapStack;
extern CDngFreeMap *MenuDngMap;
int DngTreeMapKey() {
    int result = 0;
    if (DngTreeMode == DNG_TREE_MODE_MAP) {
        result = CMenuTreePt->Step();
        if (DngTreeMode == DNG_TREE_MODE_SAVE) {
            SetDngTreeFlag(1);
            SaveMapInfo(MenuDngMap->dng_no);
            NowProgramLoopNo = 2;
            mgCMemory save_stack;
            save_stack.stSetBuffer(MenuTreeMapStack.stGetTop(), MenuTreeMapStack.stGetRest());
            MenuSaveInit(&save_stack, &CMenuTreePt->tex_block[3], 7);
        }
    } else if (DngTreeMode == DNG_TREE_MODE_SAVE) {
        result = MenuSaveKey();
        if (result != 0) {
            SetDngTreeFlag(0);
            DngTreeMode = DNG_TREE_MODE_MAP;
            result = 0;
            CMenuTreePt->FadeInMenu(40, 0.0f);
            CMenuTreePt->mode = 12;
            CMenuTreePt->step = 1;
            CMenuTreePt->MsgInit();
        }
    }
    return result;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DngTreeMapKey__Fv);
#endif
#ifdef NONMATCHING
void DngTreeMapDraw() {
    switch (DngTreeMode) {
        case DNG_TREE_MODE_MAP:
            CMenuTreePt->Draw();
            break;
        case DNG_TREE_MODE_SAVE:
            MenuSaveDraw();
            break;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", DngTreeMapDraw__Fv);
#endif
int CBaseMenuClass::IsCreateObject(int select_key, int push_button) { return 1; }
int CBaseMenuClass::IsMakeObject(int select_key, int push_button) { return 0; }
int CBaseMenuClass::IsAskExtend(int select_key, int push_button) { return 0; }
int CBaseMenuClass::ItemCmdAfter(int cmd_ret, ITEMCMD_RET_PARA *ret) { return 0; }
void CBaseMenuClass::ExitEnd() {}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", Set__9mgRect_f_Fffff);

// Static initialiser (.init)
#ifdef NONMATCHING
extern mgRect<int> dngfreemap_num;
extern mgRect<float> treemap_root_put;
extern mgRect<int> Floor_Info;
extern "C" void __sinit_dngmenu_cpp() {
    dng_light_circle.Set(388, 304, 124, 80);
    dngfreemap_num.Set(0, 0, 12, 18);
    treemap_root_put.Set(0.0f, 0.0f, 0.0f, 0.0f);
    Floor_Info.Set(0, 238, 256, 18);
    MenuTreeMapStack.Init();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dngmenu", __sinit_dngmenu_cpp);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", markOffsetTable_1092__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", root_type_texturecrd_1216__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", get_moji_tbl_1524__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", put_moji_tbl_1525__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", DngInfoMedalNumMsg__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", dngboardbrdtbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", dngboardbrdtbl_1__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", dngboardbrdtbl_2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", medal_xytbl_1736__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootTable_2119__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", Table_2133__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", bittable_2134__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable0_2230__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable1_2231__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable2_2232__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable3_2233__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable4_2234__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable5_2235__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable6_2236__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable7_2237__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable8_2238__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTable9_2239__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RootHokanTablePtrTable_2240__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RoomHokanTable0_2241__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RoomHokanTable1_2242__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RoomHokanTable2_2243__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RoomHokanTable3_2244__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", RoomHokanTablePtrTable_2245__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", is_reverse_tbl_2246__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", name_tbl_2728__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", bitTable_2900__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3141__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", dng_light_circle__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", dngfreemap_num__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_1018__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_1019__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_1020__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_1021__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_1993__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2120__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2121__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2122__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2123__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2176__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2177__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2178__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2179__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2180__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2181__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2182__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2183__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2184__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2185__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2186__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2187__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2188__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2189__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2681__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2682__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2683__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2684__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2685__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2729__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2730__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2731__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2732__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2733__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2734__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2735__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2739__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2740__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2741__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2742__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2786__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2787__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2788__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2789__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2790__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_2826__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3342__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3343__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3344__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3345__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3346__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3347__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3348__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3349__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3350__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3451__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3539__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3540__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", D_0037B018__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", __vt__12CMenuTreeMap__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", zerumaito_offset_1110__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", stepCntTbl_1501__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", DngInfoStageNo__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", dng_player_pos__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", old_hokantbl_useno_2247__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", is_reverse_tbl_room_2248__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", maxidtable_2752__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3043__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dngmenu", at_3164__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MenuDngDebugFlagSelect, 0x4);
INCLUDE_BSS(MenuDngMap, 0x4);
INCLUDE_BSS(dngfloor_infoview, 0x4);
INCLUDE_BSS(dngfloor_backdraw, 0x4);
INCLUDE_BSS(dngfloor_backdraw_alpha, 0x4);
INCLUDE_BSS(Floor_InfoTex, 0x4);
INCLUDE_BSS(DngInfoFishOkFlag, 0x4);
INCLUDE_BSS(DngInfoSphidaOkFlag, 0x4);
INCLUDE_BSS(DngAskMessageDrawFlag, 0x4);
INCLUDE_BSS(DngInfoFloorInfo, 0x4);
INCLUDE_BSS(DngInfoRoomInfo, 0x4);
INCLUDE_BSS(DngInfoDrawAlpha, 0x8);
INCLUDE_BSS(DngInfoMedalMsgPutPos, 0x8);
INCLUDE_BSS(AlphaRate_1743, 0x4);
INCLUDE_BSS(init_1744, 0x4);
INCLUDE_BSS(GeoramaMateriaInfoDrawFlag, 0x4);
INCLUDE_BSS(GeoramaMateriaInfoDrawPage, 0x4);
INCLUDE_BSS(GeoramaMateriaNum, 0x4);
INCLUDE_BSS(DngTreeMapActiveLightRate, 0x4);
INCLUDE_BSS(dng_player_blink_cnt, 0x4);
INCLUDE_BSS(DngTreeMode, 0x4);
INCLUDE_BSS(TreeMapSaveFlag, 0x4);
INCLUDE_BSS(TreeMapSaveNum, 0x4);
INCLUDE_BSS(TreeMapSaveDispCount, 0x4);
INCLUDE_BSS(TreeMapSaveHopCount, 0x4);
INCLUDE_BSS(TreeMapSaveDispY, 0x4);
INCLUDE_BSS(TreeMapCallDungeonSubMap, 0x4);
INCLUDE_BSS(TreeMapCalledWorldMap, 0x4);
INCLUDE_BSS(MenuCursorDataBuff, 0x4);
INCLUDE_BSS(CMenuTreePt, 0x4);
INCLUDE_BSS(old_direction_2830, 0x4);
INCLUDE_BSS(init_2831, 0x4);
INCLUDE_BSS(old_glid_2833, 0x4);
INCLUDE_BSS(init_2834, 0x4);
INCLUDE_BSS(NextFloorGlid_2836, 0x4);
INCLUDE_BSS(init_2837, 0x4);
INCLUDE_BSS(at_3040__2, 0x4);
INCLUDE_BSS(at_3145, 0x8);
INCLUDE_BSS(at_3199, 0x8);
INCLUDE_BSS(at_3478, 0x8);

// Uninitialised data (.bss)
INCLUDE_BSS(MenuDngMes, 0x20);
INCLUDE_BSS(treemap_root_put, 0x10);
INCLUDE_BSS(Floor_Info, 0x10);
INCLUDE_BSS(MenuTreeMapStack, 0x30);
INCLUDE_BSS(at_3142, 0x10);
