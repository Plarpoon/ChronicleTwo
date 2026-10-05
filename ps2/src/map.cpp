#include "common.h"
#include "map.hpp"

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "collision.hpp"
#include "dataread.hpp"
#include "mapparts.hpp"
#include "mdslist.hpp"
#include "mg_camera.hpp"
#include "mg_drawprim.hpp"
#include "mg_math.hpp"
#include "mg_memory.hpp"
#include "mg_sprite.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"
#include "water.hpp"

// Code (.text)
#ifdef NONMATCHING
int CMapFlagData::SetFlag(int no, int on) {
    u32 mask;
    u32 old_flag;

    if (no < 0 || no >= MAP_FLAG_MAX) {
        return 0;
    }

    mask = 1 << (no % 32);
    old_flag = flag[no / 32];
    if (on) {
        flag[no / 32] = old_flag | mask;
    } else {
        flag[no / 32] = old_flag & ~mask;
    }
    return (old_flag & mask) != 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetFlag__12CMapFlagDataFii);
#endif

#ifdef NONMATCHING
int CMapFlagData::GetFlag(int no) {
    if (no < 0 || no >= MAP_FLAG_MAX) {
        return 0;
    }
    return (flag[no / 32] & (1 << (no % 32))) != 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetFlag__12CMapFlagDataFi);
#endif

char *CMap::Iam() {
    return CMapName;
}

#ifdef NONMATCHING
void CPartsGroup::Initialize() {
    name = NULL;
    off = 0;
    camera_off = 0;
    list = NULL;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__11CPartsGroupFv);
#endif

#ifdef NONMATCHING
void CPartsGroup::Add(CList<PartsGroupData> *entry) {
    CList<PartsGroupData> *last;

    last = list;
    if (last == NULL) {
        list = entry;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = entry;
    if (entry != NULL) {
        entry->prev = last;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Add__11CPartsGroupFP23CList_14PartsGroupData_);
#endif

#ifdef NONMATCHING
void CMapWater::Initialize() {
    frame = NULL;
    *(u_long128 *)follow = 0;
    parts = NULL;
    parts_max = 0;
    parts_num = 0;
    parts_name = NULL;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__9CMapWaterFv);
#endif

void CMapWater::Clear() {
    int i;

    parts_num = 0;
    if (parts != NULL) {
        for (i = 0; i < parts_max; i++) {
            parts[i] = NULL;
        }
    }
}

CPartsGroup *CMap::GetPartsGroup(int no) {
    if (no < 0 || no >= parts_group_max) {
        return NULL;
    }
    return &parts_group[no];
}

#ifdef NONMATCHING
int CMap::AddPartsGroup(char *name, CMapParts *parts, mgCMemory *stack) {
    CList<PartsGroupData> *entry;
    CPartsGroup          *group;
    char                 *group_name;
    int                   no;

    no = SearchPartsGroupNo(name);
    group_name = NULL;
    if (no < 0) {
        no = SerachEmptyPartsGroupNo();
        group_name = mgCopyString(name, stack);
    }
    group = GetPartsGroup(no);
    if (group == NULL) {
        return -1;
    }
    if (group_name != NULL) {
        group->name = group_name;
    }
    entry = new ((u_long128 *)stack->Alloc(3)) CList<PartsGroupData>;
    entry->data.parts = parts;
    group->Add(entry);
    return no;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AddPartsGroup__4CMapFPcP9CMapPartsP9mgCMemory);
#endif

#ifdef NONMATCHING
// Defined inline in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__23CList_14PartsGroupData_Fv);
#endif

CPartsGroup *CMap::SearchPartsGroup(char *name) {
    return GetPartsGroup(SearchPartsGroupNo(name));
}

#ifdef NONMATCHING
int CMap::SearchPartsGroupNo(char *name) {
    int i;

    for (i = 0; i < parts_group_max; i++) {
        if (parts_group[i].name != NULL && strcmp(parts_group[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SearchPartsGroupNo__4CMapFPc);
#endif

#ifdef NONMATCHING
int CMap::SerachEmptyPartsGroupNo() {
    int i;

    for (i = 0; i < parts_group_max; i++) {
        if (parts_group[i].name == NULL) {
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SerachEmptyPartsGroupNo__4CMapFv);
#endif

#ifdef NONMATCHING
void CMap::Initialize() {
    int i;

    parts_list = NULL;
    effect_list.pack = NULL;
    effect_list.name = NULL;
    effect_list.block = -1;
    effect_list.effect_num = 0;
    effect_list.managers = NULL;
    effect_list.sprites = NULL;
    place_parts = NULL;
    place_parts_max = 0;
    draw_parts_num = 0;
    draw_parts = NULL;
    mds_list_set = NULL;
    camera_info_num = 0;
    camera_info = NULL;
    draw_rect_max = MAP_DRAW_RECT_MAX;
    for (i = 0; i < MAP_DRAW_RECT_MAX; i++) {
        draw_rect[i].outside = 0;
        draw_rect[i].used = 0;
        draw_rect[i].parts = NULL;
    }
    parts_group_max = MAP_PARTS_GROUP_MAX;
    for (i = 0; i < MAP_PARTS_GROUP_MAX; i++) {
        parts_group[i].Initialize();
    }
    parts_event = 0;
    func_point.CFuncPointMngr::Initialize();
    obj_anime_num = 0;
    obj_anime = NULL;
    tr_box_num = 0;
    tr_box = NULL;
    tr_box_texture = -1;
    tr_box_model = NULL;
    unk_30c = 0;
    now_time = 0.0f;
    water_surface_num = 0;
    water_surface = NULL;
    water_num = 0;
    water = NULL;
    fire_raster = NULL;
    anime_time = 0.0f;
    anime_frame = 0;
    occlusion_num = 0;
    for (i = 0; i < MAP_OCCLUSION_MAX; i++) {
        memset(&occlusion[i], 0, sizeof(COcclusion));
    }
    bbox_valid = 0;
    mgZeroVectorW(bbox.max);
    mgZeroVectorW(bbox.min);
    piece_load_skip = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__4CMapFv);
#endif

#ifdef NONMATCHING
void CMap::SetPlacePartsBuff(mgCMemory *stack, int max) {
    place_parts = new ((u_long128 *)stack->Alloc((sizeof(CMapParts) * max + 15) / 16 + 2)) CMapParts[max];
    draw_parts = new ((u_long128 *)stack->Alloc((sizeof(CMapParts *) * max + 15) / 16 + 2)) CMapParts *[max];
    place_parts_max = max;
    ClearPlaceParts();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetPlacePartsBuff__4CMapFP9mgCMemoryi);
#endif

#ifdef NONMATCHING
// Defined inline in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__9CMapPartsFv);
#endif

CMapParts *CMap::GetPlacPartsTable(int *out_max) {
    *out_max = place_parts_max;
    return place_parts;
}

void CMap::SetCameraInfoTable(CCameraInfo *table, int num) {
    camera_info_num = num;
    camera_info = table;
}

CCameraInfo *CMap::GetCameraInfo(int no) {
    if (no < 0 || no >= camera_info_num) {
        return NULL;
    }
    return &camera_info[no];
}

#ifdef NONMATCHING
CMapParts *CMap::NewPlaceParts() {
    int i;

    for (i = 0; i < place_parts_max; i++) {
        if (place_parts[i].name[0] == 0) {
            return &place_parts[i];
        }
    }
    return NULL;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", NewPlaceParts__4CMapFv);
#endif

CMdsInfo *CMap::SearchMDS(char *name) {
    CMdsInfo *model;

    model = NULL;
    if (mds_list_set != NULL) {
        model = mds_list_set->SearchMDS(name);
    }
    return model;
}

void CMap::CreateEffect(unsigned int *pack, int tex_block, mgCMemory *stack) {
    effect_list.LoadEFPFile("test", pack, tex_block, stack);
}

int CMap::SaerchEffectIndex(char *name) {
    return effect_list.SaerchEffectIndex(name);
}

#ifdef NONMATCHING
void CMap::AddParts(CList<CMapParts> *parts) {
    CList<CMapParts> *last;

    if (parts == NULL) {
        return;
    }
    last = parts_list;
    if (last == NULL) {
        parts_list = parts;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = parts;
    if (parts != NULL) {
        parts->prev = last;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AddParts__4CMapFP17CList_9CMapParts_);
#endif

CMapParts *CMap::GetParts(char *name) {
    CList<CMapParts> *entry;
    CMapParts       *parts;

    if (name == NULL || name[0] == 0) {
        return NULL;
    }
    for (entry = parts_list; entry != NULL; entry = entry->next) {
        parts = &entry->data;
        if (parts != NULL && parts->name != NULL && strcasecmp(name, parts->name) == 0) {
            return parts;
        }
    }
    return NULL;
}

#ifdef NONMATCHING
void CMap::CreateDrawRect(mgCMemory *stack, mgVu0FBOX *area, mgVu0FBOX *parts_box, int outside) {
    mgVu0FBOX           bounds;
    MapDrawOffRect     *rect;
    CList<CMapParts *> *entry;
    CList<CMapParts *> *last;
    CMapParts          *parts;
    int                 i;

    rect = NULL;
    for (i = 0; i < draw_rect_max; i++) {
        if (!draw_rect[i].used) {
            rect = &draw_rect[i];
            break;
        }
    }
    area->max[3] = 1.0f;
    area->min[3] = 1.0f;
    parts_box->max[3] = 1.0f;
    parts_box->min[3] = 1.0f;
    if (rect != NULL) {
        rect->used = 1;
        rect->area = *area;
        rect->outside = outside;
        parts = place_parts;
        for (i = 0; i < place_parts_max; i++, parts++) {
            if (parts->name[0] != 0 && parts->GetBoundBox(&bounds) && mgClipInBox(bounds.max, bounds.min, parts_box->max, parts_box->min)) {
                entry = new ((u_long128 *)stack->Alloc(3)) CList<CMapParts *>;
                entry->data = parts;
                last = rect->parts;
                if (last == NULL) {
                    rect->parts = entry;
                } else {
                    while (last->next != NULL) {
                        last = last->next;
                    }
                    last->next = entry;
                    if (entry != NULL) {
                        entry->prev = last;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateDrawRect__4CMapFP9mgCMemoryP9mgVu0FBOXP9mgVu0FBOXi);
#endif

#ifdef NONMATCHING
// Defined inline in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__18CList_P9CMapParts_Fv);
#endif

void CMap::CreateOcclusion(float (*corner)[4]) {
    if (occlusion_num < MAP_OCCLUSION_MAX) {
        occlusion[occlusion_num].enable = 1;
        *(u_long128 *)occlusion[occlusion_num].vertex[0] = *(u_long128 *)corner[0];
        *(u_long128 *)occlusion[occlusion_num].vertex[1] = *(u_long128 *)corner[1];
        *(u_long128 *)occlusion[occlusion_num].vertex[2] = *(u_long128 *)corner[2];
        *(u_long128 *)occlusion[occlusion_num].vertex[3] = *(u_long128 *)corner[3];
        occlusion_num++;
    }
}

CMapParts *CMap::PlaceParts(char *name, float *pos, float *rot, float *scale, mgCMemory *stack) {
    CMapParts *model;
    CMapParts *parts;

    model = GetParts(name);
    if (model == NULL) {
        return NULL;
    }
    parts = NewPlaceParts();
    if (parts == NULL) {
        return NULL;
    }
    model->Copy(*parts, stack);
    parts->SetPosition(pos);
    parts->SetRotation(rot);
    parts->SetScale(scale);
    return parts;
}

#ifdef NONMATCHING
void CMap::PlacePartsEnd() {
    mgVu0FBOX  bounds;
    CMapParts *parts;
    CMapWater *surface;
    char      *name;
    int        i;
    int        j;

    for (i = 0; i < water_num; i++) {
        surface = &water[i];
        if (surface->frame != NULL && surface->parts_name == NULL) {
            surface->parts[surface->parts_num++] = NULL;
        }
    }
    place_parts_num = place_parts_max;
    for (i = 0; i < place_parts_max; i++) {
        parts = &place_parts[i];
        if (parts->name[0] != 0) {
            place_parts_num = i + 1;
        }
        if (parts->GetBoundBox(&bounds)) {
            if (!bbox_valid) {
                bbox = bounds;
                bbox_valid = 1;
            } else {
                mgBoxMaxMin(&bbox, &bounds);
            }
        }
        name = parts->parts_name;
        if (name != NULL) {
            for (j = 0; j < water_num; j++) {
                surface = &water[j];
                if (surface->frame != NULL && surface->parts_name != NULL && strcmp(surface->parts_name, name) == 0) {
                    if (surface->parts_num < surface->parts_max) {
                        surface->parts[surface->parts_num++] = parts;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", PlacePartsEnd__4CMapFv);
#endif

#ifdef NONMATCHING
void CMap::ClearPlaceParts() {
    int i;

    place_parts_num = place_parts_max;
    for (i = 0; i < place_parts_max; i++) {
        place_parts[i].Initialize();
        draw_parts[i] = NULL;
    }
    for (i = 0; i < water_num; i++) {
        water[i].Clear();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", ClearPlaceParts__4CMapFv);
#endif

CMapParts *CMap::GetPlaceParts(char *name) {
    int i;

    for (i = 0; i < place_parts_num; i++) {
        if (strcmp(name, place_parts[i].name) == 0) {
            return &place_parts[i];
        }
    }
    return NULL;
}

CMapParts *CMap::GetPlaceParts(int no) {
    if (no < 0 || place_parts_num < no) {
        return NULL;
    }
    return &place_parts[no];
}

int CMap::ConvertParts(CMapParts *parts) {
    int no;

    no = -1;
    if (parts != NULL) {
        no = parts - place_parts;
    }
    return no;
}

#ifdef NONMATCHING
int CMap::GetPlaceParts(mgVu0FBOX *box, CMapParts **out_parts, int max) {
    mgVu0FBOX  bounds;
    CMapParts *parts;
    int        count;
    int        i;

    if (box == NULL) {
        return 0;
    }
    parts = place_parts;
    count = 0;
    for (i = 0; i < place_parts_num; i++, parts++) {
        if (parts->name[0] != 0 && parts->GetBoundBox(&bounds) && mgClipBox(bounds.max, bounds.min, box->max, box->min)) {
            out_parts[count++] = parts;
            if (count >= max) {
                break;
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlaceParts__4CMapFP9mgVu0FBOXPP9CMapPartsi);
#endif

#ifdef NONMATCHING
int CMap::GetPlaceColParts(mgVu0FBOX *box, CMapParts **out_parts, int max) {
    CMapParts *parts;
    int        count;
    int        i;

    if (box == NULL) {
        return 0;
    }
    parts = place_parts;
    count = 0;
    for (i = 0; i < place_parts_num; i++, parts++) {
        if (parts->name[0] != 0 && parts->CheckColBox(box)) {
            out_parts[count++] = parts;
            if (count >= max) {
                break;
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlaceColParts__4CMapFP9mgVu0FBOXPP9CMapPartsi);
#endif

void CMap::CreateFuncCheck(CFuncPointCheck *check) {
    check->time = GetNowTime();
    check->anime_frame = anime_frame;
}

int CMap::GetBBox(mgVu0FBOX *out_box) {
    *out_box = bbox;
    return bbox_valid;
}

#ifdef NONMATCHING
int CMap::PreDraw(float *view_pos) {
    CFuncPointCheck         check;
    CMapParts              *parts;
    MapDrawOffRect         *rect;
    CPartsGroup            *group;
    CList<CMapParts *>     *rect_entry;
    CList<PartsGroupData>  *group_entry;
    CList<CMapPiece>       *piece;
    int                     active_occlusion;
    int                     index;
    int                     hide;

    if (bbox_valid != 0 && mgInsideScreen(&bbox) == 0) {
        draw_parts_num = 0;
        return 0;
    }

    active_occlusion = 0;
    for (index = 0; index < occlusion_num; index++) {
        if (occlusion[index].enable != 0) {
            occlusion[index].Setup(mgRenderInfo.view);
            active_occlusion++;
        }
    }

    CreateFuncCheck(&check);
    func_point.UpdateFlag(FUNC_POINT_FIRE, &check);
    func_point.UpdateFlag(FUNC_POINT_FLARE, &check);
    func_point.Step(FUNC_POINT_PLIGHT, &check);
    func_point.UpdateFlag(FUNC_POINT_EFFECT, &check);

    parts = place_parts;
    for (index = 0; index < place_parts_num; index++, parts++) {
        if (active_occlusion > 0) {
            parts->in_screen = parts->InsideScreen(occlusion, occlusion_num);
        } else {
            parts->in_screen = parts->InsideScreen();
        }
        if (parts->in_screen != 0) {
            parts->StepFuncPoint(check);
        }
    }

    rect = draw_rect;
    for (index = 0; index < draw_rect_max; index++, rect++) {
        if (rect->used != 0) {
            if (rect->outside == 0) {
                hide = !(view_pos[0] < rect->area.min[0])
                    && !(view_pos[1] < rect->area.min[1])
                    && !(view_pos[2] < rect->area.min[2])
                    && view_pos[0] <= rect->area.max[0]
                    && view_pos[1] <= rect->area.max[1]
                    && view_pos[2] <= rect->area.max[2];
            } else {
                hide = view_pos[0] <= rect->area.min[0]
                    || view_pos[1] <= rect->area.min[1]
                    || view_pos[2] <= rect->area.min[2]
                    || !(view_pos[0] < rect->area.max[0])
                    || !(view_pos[1] < rect->area.max[1])
                    || !(view_pos[2] < rect->area.max[2]);
            }
            if (hide != 0) {
                for (rect_entry = rect->parts; rect_entry != NULL; rect_entry = rect_entry->next) {
                    if (rect_entry->data != NULL) {
                        rect_entry->data->in_screen = 0;
                    }
                }
            }
        }
    }

    group = parts_group;
    for (index = 0; index < parts_group_max; index++, group++) {
        if (group->name != NULL && (group->camera_off != 0 || group->off != 0)) {
            for (group_entry = group->list; group_entry != NULL; group_entry = group_entry->next) {
                if (group_entry->data.parts != NULL) {
                    group_entry->data.parts->in_screen = 0;
                }
            }
            group->camera_off = 0;
        }
    }

    draw_parts_num = 0;
    if (draw_parts == NULL) {
        return 0;
    }

    parts = place_parts;
    for (index = 0; index < place_parts_num; index++, parts++) {
        if (parts->name[0] != '\0') {
            if (parts->in_screen != 0) {
                draw_parts[draw_parts_num++] = parts;
            } else {
                for (piece = parts->piece_list; piece != NULL; piece = piece->next) {
                    piece->data.fade_alpha = -1.0f;
                }
            }
        }
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", PreDraw__4CMapFPf);
#endif

#ifdef NONMATCHING
int CMap::GetCharaLight(mgCObject *chara, CFuncPoint *points, int max, int use_parts) {
    CFuncPoint       candidate;
    CFuncPoint       nearest;
    CMapParts       *parts;
    sceVu0FMATRIX    world_matrix;
    sceVu0FMATRIX    inverse_matrix;
    sceVu0FVECTOR    local_position;
    float            distance;
    int              nearest_distance;
    CFuncPointCheck  check;
    sceVu0FVECTOR    chara_position;
    sceVu0FVECTOR    direction;
    sceVu0FVECTOR    color;
    CFuncPoint      *point;
    float            attenuation;
    int              light_num;
    int              light_mode;
    int              index;

    if (max <= 0) {
        return 0;
    }

    CreateFuncCheck(&check);
    chara->GetPosition(chara_position);
    chara_position[3] = 0.0f;
    chara_position[1] += 20.0f;
    light_mode = 1;
    if (use_parts != 0) {
        light_mode |= 0x2;
    }

    light_num = func_point.GetLight(chara_position, points, max, &check, light_mode);
    if (light_num >= 3) {
        light_num = 2;
    }
    for (index = 0; index < light_num; index++) {
        point = &points[index];
        sceVu0SubVector(direction, point->position, chara_position);
        attenuation = point->plight.power * point->plight.power / mgDistVector2(direction);
        if (!(attenuation <= 1.0f)) {
            attenuation = 1.0f;
        }
        sceVu0ScaleVector(color, point->plight.color, 0.4f * (attenuation * GetLightAnimeWeight(point, anime_frame)));
        color[3] = 128.0f;
        sceVu0Normalize(direction, direction);
        mgSetLight(3 - index, direction, color);
    }

    if (use_parts != 0) {
        chara->GetPosition(chara_position);
        chara_position[3] = 1.0f;
        GetNowTime();

        nearest_distance = 0x4876E000;
        nearest.type = FUNC_POINT_NONE;
        parts = place_parts;
        for (index = 0; index < place_parts_num; index++, parts++) {
            if ((parts->func_point_mngr.flag & FUNC_POINT_MNGR_LIGHT) != 0 && parts->name[0] != '\0') {
                chara_position[3] = 1.0f;
                parts->GetLWMatrix(world_matrix);
                mgInversMatrix(inverse_matrix, world_matrix);
                sceVu0ApplyMatrix(local_position, inverse_matrix, chara_position);
                local_position[3] = 0.0f;
                if (parts->func_point_mngr.GetLight(local_position, &candidate, 1, &check, light_mode) > 0) {
                    distance = mgDistVector(candidate.position, local_position);
                    if (distance < nearest_distance) {
                        nearest_distance = (int)distance;
                        nearest = candidate;
                        nearest.position[3] = 1.0f;
                        sceVu0ApplyMatrix(nearest.position, world_matrix, nearest.position);
                    }
                }
            }
        }

        if (nearest.type == FUNC_POINT_PLIGHT) {
            sceVu0SubVector(direction, nearest.position, chara_position);
            attenuation = nearest.plight.power / mgDistVector(direction);
            attenuation *= attenuation;
            if (!(attenuation <= 1.0f)) {
                attenuation = 1.0f;
            }
            sceVu0ScaleVector(color, nearest.plight.color, 0.4f * (attenuation * GetLightAnimeWeight(&nearest, anime_frame)));
            color[3] = 128.0f;
            sceVu0Normalize(direction, direction);
            mgSetLight(2, direction, color);
        }
    }
    return light_num;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetCharaLight__4CMapFP9mgCObjectP10CFuncPointii);
#endif

int CMap::SetFuncPLight(float *pos, CFuncPointCheck *check) {
    static CFuncPoint points[8];
    sceVu0FVECTOR    color;
    CFuncPoint      *point;
    int              light_num;
    int              index;

    light_num = func_point.GetLight(pos, points, 3, check, 0);
    for (index = 0; index < light_num; index++) {
        point = &points[index];
        sceVu0ScaleVector(color, point->plight.color, GetLightAnimeWeight(point, anime_frame));
        mgSetPlight(3 - index, point->position, color, point->plight.power, point->plight.range);
    }
    return light_num;
}

void CMap::ResetFuncPLight(int num) {
    int index;

    for (index = 0; index < num; index++) {
        mgSetPlight(3 - index, NULL);
    }
}

#ifdef NONMATCHING
int CMap::DrawSub(int direct) {
    CFuncPointCheck check;
    sceVu0FVECTOR  sphere;
    CMapParts     *parts;
    int            previous_plight;
    int            previous_lighting;
    int            light_num;
    int            draw_num;
    int            index;

    previous_plight = mgGetPlightEnable();
    previous_lighting = mgActiveLighting(2, 1);
    CreateFuncCheck(&check);
    draw_num = 0;
    GetNowTime();
    for (index = 0; index < draw_parts_num; index++) {
        parts = draw_parts[index];
        parts->CopyFuncPointCheck(check);
        if ((func_point.flag & FUNC_POINT_MNGR_LIGHT) != 0) {
            parts->GetBoundSphere(sphere);
            light_num = SetFuncPLight(sphere, &check);
        } else {
            light_num = 0;
        }
        if (light_num > 0) {
            mgPlightEnable(1);
        }
        if (direct != 0) {
            draw_num += parts->DrawDirect();
        } else {
            draw_num += parts->Draw();
        }
        ResetFuncPLight(light_num);
    }
    mgPlightEnable(previous_plight);
    if (previous_lighting >= 0) {
        mgActiveLighting(previous_lighting, 0);
    }
    return draw_num;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawSub__4CMapFi);
#endif

#ifdef NONMATCHING
// Defined inline in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Draw__9CMapPartsFv);
#endif

#ifdef NONMATCHING
// Defined inline in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawDirect__9CMapPartsFv);
#endif

#ifdef NONMATCHING
void CMap::DrawEffect() {
    static mgCFrameAttr  attr;
    CFuncPointCheck      check;
    CFuncPoint          *point;
    CMapParts           *parts;
    int                  index;

    GetNowTime();
    effect_list.CreatePacket();
    CreateFuncCheck(&check);

    attr.draw = MG_FRAME_DRAW_VISIBLE | MG_FRAME_DRAW_SKIP_CHILDREN;
    attr.fog = 2;
    attr.no_cull = 1;
    attr.depth_bias = 1.015f;
    func_point.GetStart(FUNC_POINT_EFFECT);
    for (point = func_point.Get(); point != NULL; point = func_point.Get()) {
        if (point->Check(&check) != 0) {
            point->frame.SetVisual(effect_list.GetEffectVisual(point->effect.index));
            point->frame.attr = &attr;
            mgDrawDirect(&point->frame);
        }
    }
    func_point.GetEnd();

    for (index = 0; index < draw_parts_num; index++) {
        parts = draw_parts[index];
        if (parts->CheckDraw() != 0) {
            parts->func_point_mngr.GetStart(FUNC_POINT_EFFECT);
            for (point = parts->func_point_mngr.Get(); point != NULL; point = parts->func_point_mngr.Get()) {
                if (point->active != 0) {
                    point->frame.SetReference(&parts->frame);
                    point->frame.SetVisual(effect_list.GetEffectVisual(point->effect.index));
                    point->frame.attr = &attr;
                    mgDrawDirect(&point->frame);
                    point->frame.DeleteReference();
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawEffect__4CMapFv);
#endif

#ifdef NONMATCHING
void CMap::DrawFireEffect(int tex_block) {
    CFuncPointCheck check;
    sceVu0FMATRIX  world_matrix;
    mgCTexture    *fire_texture;
    mgCTexture    *light_texture;
    CMapParts     *parts;
    int            index;

    CreateFuncCheck(&check);
    mgTexManager.ReloadTexture(tex_block, (sceVif1Packet *)NULL);
    fire_texture = mgTexManager.GetTexture("fire_wrk", tex_block);
    light_texture = mgTexManager.GetTexture("lightling", tex_block);
    mgUnitMatrix(world_matrix);
    ::DrawFireEffect(world_matrix, &func_point, &check, 1.0f, fire_texture, light_texture);
    if (draw_parts != NULL) {
        for (index = 0; index < draw_parts_num; index++) {
            parts = draw_parts[index];
            if ((parts->func_point_mngr.flag & FUNC_POINT_MNGR_BURN) != 0 && parts->CheckDraw() != 0) {
                parts->GetLWMatrix(world_matrix);
                ::DrawFireEffect(world_matrix, &parts->func_point_mngr, &check, 1.0f, fire_texture, light_texture);
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawFireEffect__4CMapFi);
#endif

#ifdef NONMATCHING
void CMap::DrawFireRaster() {
    CFuncPointCheck check;
    sceVu0FMATRIX  world_matrix;
    CMapParts     *parts;
    int            index;

    CreateFuncCheck(&check);
    mgUnitMatrix(world_matrix);
    ::DrawFireRaster(world_matrix, &func_point, &check, fire_raster);
    if (draw_parts != NULL) {
        for (index = 0; index < draw_parts_num; index++) {
            parts = draw_parts[index];
            if (parts->name[0] != '\0' && parts->CheckDraw() != 0) {
                parts->GetLWMatrix(world_matrix);
                ::DrawFireRaster(world_matrix, &parts->func_point_mngr, &check, fire_raster);
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawFireRaster__4CMapFv);
#endif

#ifdef NONMATCHING
void CMap::DrawWater(mgCCamera *camera, mgCTexture *screen, mgCTexture *overlay) {
    mgCDrawPrim    prim;
    sceVu0FVECTOR  overlay_position;
    sceVu0FVECTOR  overlay_rotation;
    sceVu0FVECTOR  overlay_scale;
    mgCTexture     framebuffer;
    mgRect<int>    screen_rect(0, 0, (mgScreenWidth - 1) * 16, (mgScreenHeight - 1) * 16);
    sceVu0FVECTOR  camera_position;
    sceVu0FVECTOR  camera_direction;
    sceVu0FVECTOR  camera_rotation;
    sceVu0FMATRIX  identity;
    sceVu0FMATRIX  parts_matrix;
    sceVu0FVECTOR  position;
    sceVu0FVECTOR  rotation;
    sceVu0FVECTOR  scale;
    CMapWater     *placement;
    CWaterFrame   *surface;
    CMapParts     *parts;
    int            surface_no;
    int            placement_no;
    int            parts_no;
    int            ripple_row;
    int            ripple_column;

    if (water_surface_num <= 0) {
        return;
    }
    if (screen == NULL) {
        return;
    }
    if (water_num <= 0) {
        return;
    }

    mgZeroVector(camera_position);
    mgZeroVector(camera_rotation);
    if (camera != NULL) {
        camera->GetDir(camera_direction);
        camera->GetPos(camera_position);
        sceVu0Normalize(camera_direction, camera_direction);
        sceVu0ScaleVector(camera_direction, camera_direction, 400.0f);
        mgAddVector(camera_position, camera_direction);
        camera_rotation[1] = mgAngleLimit(atan2f(camera_direction[0], camera_direction[2]));
    }

    for (surface_no = 0; surface_no < water_surface_num; surface_no++) {
        if (water_surface[surface_no] != NULL) {
            water_surface[surface_no]->CreatePacket();
            water_surface[surface_no]->SetTexture(screen);
            ripple_row = (int)(48.0f * ((float)rand() / 2147483648.0f));
            ripple_column = (int)(32.0f * ((float)rand() / 2147483648.0f));
            water_surface[surface_no]->Shake(ripple_row, ripple_column, 0.1f);
            water_surface[surface_no]->SetParam(0.15f, 0.0045f, 0.0f, 16.0f);
            water_surface[surface_no]->Step();
            water_surface[surface_no]->SetColor(0x80, 0x80, 0x80, 0x80);
        }
    }

    mgTexManager.ReloadTexture(screen->block, (sceVif1Packet *)NULL);

    mgGetFrameBuffer(&framebuffer);
    mgSetPkMoveImage(&framebuffer, screen_rect, screen, 0, 0, 0);
    placement = water;
    mgUnitMatrix(identity);

    for (placement_no = 0; placement_no < water_num; placement_no++, placement++) {
        surface = placement->frame;
        if (surface != NULL) {
            placement->GetPosition(position);
            placement->GetRotation(rotation);
            placement->GetScale(scale);
            if (placement->follow[0] != 0) {
                position[0] = camera_position[0];
            }
            if (placement->follow[1] != 0) {
                position[1] = camera_position[1];
            }
            if (placement->follow[2] != 0) {
                position[2] = camera_position[2];
            }
            surface->SetPosition(position);
            surface->SetRotation(rotation);
            if (placement->follow[0] != 0 && placement->follow[2] != 0) {
                surface->SetRotation(camera_rotation);
            }
            surface->SetScale(scale);

            for (parts_no = 0; parts_no < placement->parts_num; parts_no++) {
                parts = placement->parts[parts_no];
                if (parts == NULL) {
                    mgDrawDirect(surface);
                } else {
                    parts->GetLWMatrix(parts_matrix);
                    surface->SetTransMatrix(parts_matrix);
                    mgDrawDirect(surface);
                    surface->SetTransMatrix(identity);
                }
            }
        }
    }

    if (overlay != NULL) {
        prim.Initialize(NULL, NULL);
        prim.DepthTestEnable(0);
        prim.ZMask(-1);
        prim.TextureMapEnable(1);
        prim.AlphaBlendEnable(0);
        prim.AlphaTestEnable(0);
        mgSetPkFrameBuffer(screen);
        prim.Begin(6);
        prim.Texture(overlay);
        prim.Color(0x80, 0x80, 0x80, 0x80);
        prim.TextureCrd(0, 0);
        prim.Vertex(0, 0, 0);
        prim.TextureCrd(0x80, 0x80);
        prim.Vertex(mgScreenWidth, mgScreenHeight, 0);
        prim.End();
        mgSetPkFrameBuffer(-1, -1, -1, -1);
        placement = water;

        for (placement_no = 0; placement_no < water_num; placement_no++, placement++) {
            surface = placement->frame;
            if (surface != NULL) {
                placement->GetPosition(overlay_position);
                placement->GetRotation(overlay_rotation);
                placement->GetScale(overlay_scale);
                placement->GetPosition(overlay_position);
                placement->GetRotation(overlay_rotation);
                placement->GetScale(overlay_scale);
                if (placement->follow[0] != 0) {
                    overlay_position[0] = camera_position[0];
                }
                if (placement->follow[1] != 0) {
                    overlay_position[1] = camera_position[1];
                }
                if (placement->follow[2] != 0) {
                    overlay_position[2] = camera_position[2];
                }
                surface->SetPosition(overlay_position);
                surface->SetRotation(overlay_rotation);
                if (placement->follow[0] != 0 && placement->follow[2] != 0) {
                    surface->SetRotation(camera_rotation);
                }
                surface->SetColor(0x80, 0x80, 0x80, 0x20);
                surface->SetParam(0.15f, 0.0045f, 0.0f, 300.0f);
                surface->SetScale(overlay_scale);

                for (parts_no = 0; parts_no < placement->parts_num; parts_no++) {
                    parts = placement->parts[parts_no];
                    if (parts == NULL) {
                        mgDrawDirect(surface);
                    } else {
                        parts->GetLWMatrix(parts_matrix);
                        surface->SetTransMatrix(parts_matrix);
                        mgDrawDirect(surface);
                        surface->SetTransMatrix(identity);
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawWater__4CMapFP9mgCCameraP10mgCTextureP10mgCTexture);
#endif

#ifdef NONMATCHING
void CMap::DrawTrBox() {
    CFuncPointCheck   check;
    sceVu0FVECTOR     light_sphere;
    CMapTreasureBox  *box;
    int               plight_enable;
    int               lighting;
    int               light_num;
    int               box_no;

    if (tr_box_num == 0) {
        return;
    }
    if (tr_box == NULL) {
        return;
    }

    mgTexManager.ReloadTexture(tr_box_texture, (sceVif1Packet *)NULL);
    plight_enable = mgGetPlightEnable();
    lighting = mgActiveLighting(2, 1);

    CreateFuncCheck(&check);
    GetNowTime();
    box = tr_box;
    for (box_no = 0; box_no < tr_box_num; box_no++, box++) {
        if (box->active != 0 && (box->parts == NULL || box->parts->GetShow() != 0)) {
            if (func_point.flag & FUNC_POINT_MNGR_LIGHT) {
                box->GetPosition(light_sphere);
                light_sphere[3] = 40.0f;
                light_num = SetFuncPLight(light_sphere, &check);
            } else {
                light_num = 0;
            }
            if (light_num > 0) {
                mgPlightEnable(1);
            }
            box->DrawDirect();
            ResetFuncPLight(light_num);
        }
    }
    mgPlightEnable(plight_enable);
    if (lighting >= 0) {
        mgActiveLighting(lighting, 0);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawTrBox__4CMapFv);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetShow__7CObjectFv);
#endif

#ifdef NONMATCHING
int CMap::GetPoly(int kind, CCPoly *polys, mgVu0FBOX &box, int max) {
    CMapParts *parts_table[128];
    CMapParts *parts;
    CCPoly    *out;
    int        parts_count;
    int        count;
    int        copied;
    int        remaining;
    int        j;
    u16        i;

    out = polys;
    remaining = max;
    parts_count = GetPlaceColParts(&box, parts_table, 128);
    count = 0;
    for (i = 0; i < parts_count; i++) {
        parts = parts_table[i];
        if (parts->name[0] != 0 && parts->GetShow()) {
            copied = parts->GetPoly(kind, out, box, remaining);
            for (j = 0; j < copied; j++, out++) {
                out->parts_no = i;
            }
            remaining -= copied;
            count += copied;
            if (remaining <= 0) {
                break;
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPoly__4CMapFiP6CCPolyR9mgVu0FBOXi);
#endif

int CMap::GetColPoly(CCPoly *polys, mgVu0FBOX &box, int max) {
    return GetPoly(1, polys, box, max);
}

int CMap::GetCameraPoly(CCPoly *polys, mgVu0FBOX &box, int max) {
    return GetPoly(3, polys, box, max);
}

#ifdef NONMATCHING
int CMap::GetTrBoxColPoly(CCPoly *polys, float *pos, int max) {
    sceVu0FVECTOR   position;
    CMapTreasureBox *box;
    int             count;
    int             copied;
    int             i;

    count = 0;
    box = tr_box;
    for (i = 0; i < tr_box_num; i++, box++) {
        if (box->active && (box->parts == NULL || box->parts->GetShow())) {
            box->GetWorldPosition(position);
            copied = CreateCharaCPoly(polys, max, position, pos, 5.0f, 20.0f);
            count += copied;
            max -= copied;
            polys += copied;
            if (max < 0) {
                break;
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetTrBoxColPoly__4CMapFP6CCPolyPfi);
#endif

#ifdef NONMATCHING
int CMap::GetFixCameraPos(float *pos, float *out_camera_pos) {
    sceVu0FVECTOR projection[8];
    sceVu0FVECTOR direction;
    sceVu0FVECTOR offset;
    sceVu0FVECTOR projection_sum;
    CCameraInfo  *selected;
    CCameraInfo  *camera;
    float         segment_length2;
    float         weight;
    float         nearest_distance2;
    float         nearest_distance;
    float         distance;
    int           camera_no;
    int           rect_no;
    int           segment_no;
    int           projection_num;
    int           nearest_projection;
    int           point_no;

    selected = NULL;
    camera = camera_info;
    for (camera_no = 0; camera_no < camera_info_num; camera_no++, camera++) {
        if (camera->rect[0] == NULL) {
            selected = camera;
        }
    }
    camera = camera_info;
    for (camera_no = 0; camera_no < camera_info_num; camera_no++, camera++) {
        for (rect_no = 0; rect_no < camera->rect_num; rect_no++) {
            if (camera->rect[rect_no] == NULL) {
                break;
            }
            if (camera->rect[rect_no]->InsidePoint(pos) != 0) {
                selected = camera;
            }
        }
    }

    if (selected == NULL) {
        return MAP_FIX_CAMERA_NONE;
    }
    if (selected->pos_num >= 2) {
        projection_num = 0;
        nearest_projection = -1;
        for (segment_no = 0; segment_no < selected->pos_num - 1; segment_no++) {
            sceVu0SubVector(direction, selected->pos[segment_no + 1], selected->pos[segment_no]);
            sceVu0SubVector(offset, pos, selected->pos[segment_no]);
            segment_length2 = mgDistVector2(direction);
            weight = sceVu0InnerProduct(direction, offset) / segment_length2;
            if (!(weight < 0.0f) && weight <= 1.0f) {
                sceVu0ScaleVector(projection[projection_num], direction, weight);
                mgAddVector(projection[projection_num], selected->pos[segment_no]);
                if (nearest_projection < 0) {
                    nearest_projection = projection_num;
                } else {
                    nearest_distance2 = mgDistVector2(pos, projection[nearest_projection]);
                    if (mgDistVector2(pos, projection[projection_num]) < nearest_distance2) {
                        nearest_projection = projection_num;
                    }
                }
                projection_num++;
            }
        }

        mgZeroVector(projection_sum);
        for (point_no = 0; point_no < projection_num; point_no++) {
            mgAddVector(projection_sum, projection[point_no]);
        }
        point_no = 0;
        if (projection_num > 0) {
            *(u_long128 *)out_camera_pos = *(u_long128 *)projection[nearest_projection];
            nearest_distance = mgDistVector(out_camera_pos, pos);
        } else {
            nearest_distance = mgDistVector(selected->pos[0], pos);
            *(u_long128 *)out_camera_pos = *(u_long128 *)selected->pos[0];
            point_no = 1;
        }
        for (; point_no < selected->pos_num; point_no++) {
            distance = mgDistVector(pos, selected->pos[point_no]);
            if (distance < nearest_distance) {
                nearest_distance = distance;
                *(u_long128 *)out_camera_pos = *(u_long128 *)selected->pos[point_no];
            }
        }
        return MAP_FIX_CAMERA_PATH;
    }
    *(u_long128 *)out_camera_pos = *(u_long128 *)selected->pos[0];
    return MAP_FIX_CAMERA_POINT;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetFixCameraPos__4CMapFPfPf);
#endif

#ifdef NONMATCHING
void CMap::FixCameraPartsOnOff(float *camera_pos) {
    CCameraInfo     *camera;
    CCameraInfo     *selected;
    CCameraDrawInfo *draw_info;
    CPartsGroup     *group;
    int              camera_no;
    int              draw_no;

    camera = camera_info;
    for (camera_no = 0; camera_no < camera_info_num; camera_no++, camera++) {
        for (draw_no = 0; draw_no < 4; draw_no++) {
            draw_info = camera->GetDrawInfo(draw_no);
            if (draw_info != NULL) {
                group = GetPartsGroup(draw_info->group_no);
                if (group != NULL) {
                    group->camera_off = 0;
                }
            }
        }
    }
    camera = camera_info;
    selected = NULL;
    for (camera_no = 0; camera_no < camera_info_num; camera_no++, camera++) {
        if (mgDistVector(camera->pos[0], camera_pos) < 10.0f) {
            selected = camera;
            break;
        }
    }
    if (selected != NULL) {
        for (draw_no = 0; draw_no < 4; draw_no++) {
            draw_info = selected->GetDrawInfo(draw_no);
            if (draw_info != NULL) {
                group = GetPartsGroup(draw_info->group_no);
                if (group != NULL) {
                    group->camera_off = 1;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", FixCameraPartsOnOff__4CMapFPf);
#endif

#ifdef NONMATCHING
CFuncPoint *CMap::GetEvent(float *pos, int check_type, MapEventInfo *info) {
    MapEventInfo    event_info;
    MapEventInfo    nearest_info;
    CFuncPoint     *nearest_point;
    CFuncPoint     *point;
    CMapParts      *parts;
    CFuncPointMngr *manager;
    float          nearest_distance;
    float          distance;
    int            last_event;
    int            accepted;
    int            parts_no;
    int            row;

    nearest_point = NULL;
    event_info.event_no = 0;
    mgUnitMatrix(event_info.matrix);
    event_info.point_no = -1;
    event_info.parts_no = -1;
    func_point.GetStart(FUNC_POINT_EVENT);
    nearest_distance = 0.0f;
    last_event = 0;
    point = func_point.Get();
    while (point != NULL) {
        if (CheckFuncEvent(point, pos, check_type, &event_info, &distance) == 0) {
            if (event_info.event_no != 0) {
                last_event = event_info.event_no;
            }
        } else {
            event_info.point_no = point->event.point_no;
            if (nearest_point == NULL || distance < nearest_distance) {
                nearest_distance = distance;
                nearest_point = point;
                nearest_info.check_type = event_info.check_type;
                nearest_info.event_no = event_info.event_no;
                for (row = 0; row < 4; row++) {
                    *(u_long128 *)nearest_info.matrix[row] = *(u_long128 *)event_info.matrix[row];
                }
                nearest_info.parts_no = event_info.parts_no;
                nearest_info.point_no = event_info.point_no;
            }
        }
        point = func_point.Get();
    }

    parts = place_parts;
    if (parts_event != 0) {
        for (parts_no = 0; parts_no < place_parts_max; parts_no++, parts++) {
            manager = &parts->func_point_mngr;
            if ((manager->flag & FUNC_POINT_MNGR_EVENT) && parts->name[0] != '\0' && parts->GetShow() != 0) {
                manager->GetStart(FUNC_POINT_EVENT);
                point = manager->Get();
                while (point != NULL) {
                    point->frame.SetReference(&parts->frame);
                    accepted = CheckFuncEvent(point, pos, check_type, &event_info, &distance);
                    point->frame.DeleteReference();
                    event_info.parts_no = parts_no;
                    if (event_info.event_no != 0) {
                        last_event = event_info.event_no;
                    }
                    if (accepted != 0) {
                        event_info.point_no = point->event.point_no;
                        if (nearest_point == NULL || distance < nearest_distance) {
                            nearest_distance = distance;
                            nearest_point = point;
                            nearest_info.check_type = event_info.check_type;
                            nearest_info.event_no = event_info.event_no;
                            for (row = 0; row < 4; row++) {
                                *(u_long128 *)nearest_info.matrix[row] = *(u_long128 *)event_info.matrix[row];
                            }
                            nearest_info.parts_no = event_info.parts_no;
                            nearest_info.point_no = event_info.point_no;
                        }
                    }
                    point = manager->Get();
                }
            }
        }
    }
    if (info != NULL) {
        info->check_type = nearest_info.check_type;
        info->event_no = nearest_info.event_no;
        for (row = 0; row < 4; row++) {
            *(u_long128 *)info->matrix[row] = *(u_long128 *)nearest_info.matrix[row];
        }
        info->parts_no = nearest_info.parts_no;
        info->point_no = nearest_info.point_no;
        info->event_no = last_event;
    }
    return nearest_point;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetEvent__4CMapFPfiP12MapEventInfo);
#endif

#ifdef NONMATCHING
CFuncPoint *CMap::InScreenFunc(InScreenFuncInfo *info) {
    CMapParts *parts;
    CFuncPoint *nearest;
    CFuncPoint *point;
    float       distance;
    int         point_info;
    int         i;

    nearest = NULL;
    parts = place_parts;
    point_info = 0;
    distance = 0.0f;
    for (i = 0; i < place_parts_max; i++, parts++) {
        if (parts->name[0] != 0 && parts->CheckDraw()) {
            point = parts->InScreenFunc(info);
            if (point != NULL && (nearest == NULL || info->dist < distance)) {
                nearest = point;
                point_info = info->unk_04;
                distance = info->dist;
            }
        }
    }
    info->unk_04 = point_info;
    return nearest;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", InScreenFunc__4CMapFP16InScreenFuncInfo);
#endif

#ifdef NONMATCHING
void CMap::DrawScreenFunc(mgCFrame *marker) {
    CMapParts *parts;
    int        i;

    parts = place_parts;
    for (i = 0; i < place_parts_max; i++, parts++) {
        if (parts->name[0] != 0 && parts->CheckDraw()) {
            parts->DrawScreenFunc(marker);
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawScreenFunc__4CMapFP8mgCFrame);
#endif

void CMap::EffectStep() {
    anime_time += 1.0f;
    anime_frame = (int)anime_time;
    effect_list.Step();
}

#ifdef NONMATCHING
void CMap::AnimeStep(CObjAnimeEnv *env) {
    CFuncPointCheck check;
    CObjAnime      *animation;
    int             i;

    CreateFuncCheck(&check);
    for (i = 0; i < place_parts_num; i++) {
        place_parts[i].AnimeStep(&check, env);
    }
    if (obj_anime_num > 0) {
        animation = obj_anime;
        if (animation == NULL) {
            return;
        }
        for (i = 0; i < obj_anime_num; i++, animation++) {
            if (animation->func_point != NULL && animation->func_point->Check(&check)) {
                animation->Step(env);
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AnimeStep__4CMapFP12CObjAnimeEnv);
#endif

#ifdef NONMATCHING
void CMap::Step() {
    int i;

    for (i = 0; i < place_parts_num; i++) {
        place_parts[i].Step();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Step__4CMapFv);
#endif

#ifdef NONMATCHING
int CMap::GetSeSrcVolPan(int *se_no, float *vol, float *pan, int max) {
    CFuncPointCheck check;
    sceVu0FMATRIX  matrix;
    CMapParts     *parts;
    int            count;
    int            copied;
    int            remaining;
    int            i;

    CreateFuncCheck(&check);
    mgUnitMatrix(matrix);
    copied = ::GetSeSrcVolPan(matrix, &func_point, &check, se_no, vol, pan, max);
    count = copied;
    remaining = max - copied;
    se_no += copied;
    vol += copied;
    pan += copied;
    parts = place_parts;
    for (i = 0; i < place_parts_max; i++, parts++) {
        if (parts->name[0] != 0 && parts->CheckDraw() && (parts->func_point_mngr.flag & FUNC_POINT_MNGR_SOUND)) {
            parts->GetLWMatrix(matrix);
            if (remaining <= 0) {
                return count;
            }
            copied = ::GetSeSrcVolPan(matrix, &parts->func_point_mngr, &check, se_no, vol, pan, remaining);
            count += copied;
            remaining -= copied;
            se_no += copied;
            vol += copied;
            pan += copied;
        }
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetSeSrcVolPan__4CMapFPiPfPfi);
#endif

void CMap::CreateMap(CMdsListSet *mds_list_set, mgCMemory *stack) {
    char *script;
    int   size;

    script = GetAddMapFile(&size);
    if (script != NULL && size > 0) {
        LoadMapFile(script, size, stack, 1);
    }
    script = GetMapFile(&size);
    LoadMapFile(script, size, stack, 0);
}

#ifdef NONMATCHING
void CMap::AssignFuncPoint(mgCMemory *stack) {
    CObjAnime  *animation;
    CFuncPoint *point;
    CMapParts  *parts;

    obj_anime_num = func_point.GetNum(FUNC_POINT_ANIME);
    if (obj_anime_num > 0) {
        obj_anime = new (stack->Alloc((obj_anime_num * sizeof(CObjAnime) + 15) / 16 + 2)) CObjAnime[obj_anime_num];
        animation = obj_anime;
        if (animation != NULL) {
            func_point.GetStart(FUNC_POINT_ANIME);
            for (point = func_point.Get(); point != NULL; point = func_point.Get(), animation++) {
                animation->frame = NULL;
                animation->piece = NULL;
                animation->parts = NULL;
                animation->func_point = NULL;
                animation->back = 0;
                animation->stop = 0;
                animation->func_point = point;
                parts = NULL;
                if (point->anime.parts_name != NULL) {
                    parts = GetPlaceParts(point->anime.parts_name);
                }
                animation->AssignFuncAnime(point, parts);
            }
            func_point.GetEnd();
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AssignFuncPoint__4CMapFP9mgCMemory);
#endif

#ifdef NONMATCHING
// Defined inline in funcpoint.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__9CObjAnimeFv);
#endif

#ifdef NONMATCHING
void CMap::CreateTrBox(CMapTreasureBox *model, int tex_block, mgCMemory *stack) {
    mgCFrame        *top_frame;
    CMapParts       *parts;
    CFuncPointMngr  *manager;
    CFuncPoint      *point;
    int              parts_index;
    int              box_index;

    if (model == NULL || model->CObjectFrame::frame == NULL) {
        return;
    }
    top_frame = model->CObjectFrame::frame->SearchFrame("top");
    if (top_frame != NULL) {
        top_frame->SetRotType(2);
    }
    model->fade = 1;
    tr_box_texture = tex_block;
    tr_box_model = model;
    tr_box_num = func_point.GetEventNum(FUNC_EVENT_TREASURE_BOX);
    parts = place_parts;
    for (parts_index = 0; parts_index < place_parts_max; parts_index++, parts++) {
        if (parts->name[0] != '\0') {
            tr_box_num += parts->func_point_mngr.GetEventNum(FUNC_EVENT_TREASURE_BOX);
        }
    }

    tr_box = new (stack->Alloc((tr_box_num * sizeof(CMapTreasureBox) + 15) / 16 + 2)) CMapTreasureBox[tr_box_num];
    if (tr_box == NULL) {
        tr_box_num = 0;
    }

    box_index = 0;
    for (parts_index = -1; parts_index < place_parts_max; parts_index++) {
        if (box_index >= tr_box_num) {
            break;
        }
        parts = NULL;
        if (parts_index < 0) {
            manager = &func_point;
        } else {
            parts = &place_parts[parts_index];
            manager = &parts->func_point_mngr;
        }
        manager->GetStart(FUNC_POINT_EVENT);
        for (point = manager->Get(); point != NULL; point = manager->Get()) {
            if ((point->event.flag & FUNC_EVENT_TREASURE_BOX) != 0) {
                tr_box_model->Copy(tr_box[box_index], stack);
                tr_box[box_index].AssignFuncPoint(point, parts);
                point->event.point_no = box_index;
                box_index++;
            }
        }
        manager->GetEnd();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateTrBox__4CMapFP15CMapTreasureBoxiP9mgCMemory);
#endif

#ifdef NONMATCHING
// Defined inline in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__15CMapTreasureBoxFv);
#endif

#ifdef NONMATCHING
CMapTreasureBox *CMap::GetTrBox(int no) {
    if (no < 0 || tr_box_num < no || tr_box == NULL) {
        return NULL;
    }
    return &tr_box[no];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetTrBox__4CMapFi);
#endif

void CMap::DeleteTrBox(int no, CMapFlagData *flags) {
    CMapTreasureBox *box;

    box = GetTrBox(no);
    if (box != NULL) {
        box->active = 0;
        if (box->flag_no > 0) {
            if (flags != NULL) {
                flags->SetFlag(box->flag_no, 1);
            }
            if (box->func_point != NULL) {
                box->func_point->enable = 0;
            }
        }
    }
}

#ifdef NONMATCHING
void CMap::UpdateTrBoxFlag(CMapFlagData *flags) {
    CMapTreasureBox *box;
    int             i;

    if (flags != NULL) {
        box = tr_box;
        for (i = 0; i < tr_box_num; i++, box++) {
            if (box->flag_no > 0) {
                box->active = flags->GetFlag(box->flag_no) == 0;
                if (box->func_point != NULL) {
                    box->func_point->enable = box->active;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", UpdateTrBoxFlag__4CMapFP12CMapFlagData);
#endif

#ifdef NONMATCHING
void CMap::LoadData(unsigned int *pcp_pack, unsigned int *img_pack, int *tex_block, mgCMemory *stack) {
    mgCEnterIMGInfo info;
    char          *name;
    unsigned int  *file;
    int            block;
    int            first_block;
    int            index;

    if (mds_list_set != NULL) {
        block = *tex_block;
        for (index = 0; (name = GetImgName(index)) != NULL; index++) {
            file = GetPackFile(img_pack, name, NULL);
            printf("%x %s\n", file, name);
            if (file != NULL) {
                first_block = block;
                block += mgTexManager.EnterIMGFile((u_char *)file, block, stack, &info) + 1;
                mgTexManager.EndEnterTexture(first_block);
                mds_list_set->LoadIMGFile(name, &info, stack);
            }
        }
        for (index = 0; (name = GetPCPName(index)) != NULL; index++) {
            file = GetPackFile(pcp_pack, name, NULL);
            if (file != NULL) {
                mds_list_set->LoadPCPFile(name, file, stack, all_scissor);
            }
        }
        *tex_block = block - *tex_block;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", LoadData__4CMapFPUiPUiPiP9mgCMemory);
#endif

#ifdef NONMATCHING
int CheckFuncEvent(CFuncPoint *point, float *pos, int check_type, MapEventInfo *info, float *out_dist) {
    sceVu0FMATRIX matrix;
    sceVu0FVECTOR world_position;
    sceVu0FVECTOR normalized_offset;
    float         scale_x;
    float         scale_y;
    float         scale_z;
    u32           flags;

    if (point->Check(NULL) == 0) {
        return 0;
    }
    point->frame.GetLWMatrix(matrix);
    *(u_long128 *)world_position = *(u_long128 *)matrix[3];
    scale_x = mgDistVector(matrix[0]);
    scale_y = mgDistVector(matrix[1]);
    scale_z = mgDistVector(matrix[2]);
    normalized_offset[0] = (world_position[0] - pos[0]) / scale_x;
    normalized_offset[1] = (world_position[1] - pos[1]) / scale_y;
    normalized_offset[2] = (world_position[2] - pos[2]) / scale_z;
    if (!(mgDistVector(normalized_offset) <= 1.0f)) {
        return 0;
    }
    if (info != NULL) {
        if (point->event.event_no > 0) {
            info->event_no = point->event.event_no;
        }
        info->check_type = check_type;
        flags = point->event.flag;
        if (flags & (FUNC_EVENT_ACTION | FUNC_EVENT_ITEM)) {
            switch (check_type) {
            case 0:
                if (flags & FUNC_EVENT_ACTION) {
                    return 0;
                }
                if (flags & FUNC_EVENT_ITEM) {
                    return 0;
                }
                break;
            case 1:
                if (!(flags & FUNC_EVENT_ACTION)) {
                    return 0;
                }
                break;
            case 2:
                if (!(flags & FUNC_EVENT_ITEM)) {
                    return 0;
                }
                break;
            }
        }
        *(u_long128 *)info->matrix[0] = *(u_long128 *)matrix[0];
        *(u_long128 *)info->matrix[1] = *(u_long128 *)matrix[1];
        *(u_long128 *)info->matrix[2] = *(u_long128 *)matrix[2];
        *(u_long128 *)info->matrix[3] = *(u_long128 *)matrix[3];
    }
    if (out_dist != NULL) {
        *out_dist = mgDistVector(world_position, pos);
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CheckFuncEvent__FP10CFuncPointPfiP12MapEventInfoPf);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Draw__4CMapFv);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawDirect__4CMapFv);
#endif

#ifdef NONMATCHING
int CObject::Draw() { return 0; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Draw__7CObjectFv);
#endif
int CObject::DrawDirect() { return 0; }
#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Show__7CObjectFi);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetFarDist__7CObjectFf);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetFarDist__7CObjectFv);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetNearDist__7CObjectFf);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetNearDist__7CObjectFv);
#endif

#ifdef NONMATCHING
// Defined inline in map.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Copy__7CObjectFR7CObjectP9mgCMemory);
#endif


// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_327__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_574__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_1352__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_1353__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_1927__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_2008__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__4CMap__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__18CList_P9CMapParts___DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__23CList_14PartsGroupData___DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__9CMapWater__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", CMapName__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(init_1301, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(attr_1300, 0x90);
