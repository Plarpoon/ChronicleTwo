#include "common.h"
#include "sceneevent.hpp"
#include "scenesnd.hpp"
#include "collision.hpp"
#include "mapsky.hpp"
#include "mg_camera.hpp"
#include "mg_math.hpp"
#include "mglib.hpp"
#include "mg_texture.hpp"
#include "mg_tanime.hpp"
#include "screeneffect.hpp"
#include <cstring>

#include <cstdio>

// Code (.text)
#ifdef NONMATCHING
void CScene::UpDateMapInfo() {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    for (int index = 0; index < count; ++index) {
        if (maps[index] != NULL) maps[index]->now_time = time;
    }
    CMap *map = GetMap(active_map);
    if (map == NULL) return;
    CMapLightingInfo lighting;
    map->GetLightInfo(&lighting);
    mgFogEnable(lighting.fog_enable);
    if (lighting.fog_enable) {
        mgSetFogParam(lighting.fog.near_dist, lighting.fog.far_dist, lighting.fog.r,
                      lighting.fog.g, lighting.fog.b, lighting.fog.far_value, lighting.fog.near_value);
    }
    mgSetRenderInfo(lighting.projection, 3.0f, 50000.0f);
    mgSetLight(lighting.light_dir, lighting.light_color);
    mgSetAmbient(lighting.ambient);
    mgResetPlight();
    if (lighting.plight_enable) {
        mgPlightEnable(1);
        for (int light = 0; light < 4; ++light) mgSetPlight(light, &lighting.point_light[light]);
    }
    mgSetBackGround(lighting.bg_color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", UpDateMapInfo__6CSceneFv);
#endif
#ifdef NONMATCHING
int CScene::GetColPoly(CCPoly *polys, mgVu0FBOX &box, int max) {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    int total = 0;
    for (int index = 0; index < count; ++index) {
        int found = maps[index]->GetColPoly(polys, box, max);
        total += found;
        max -= found;
        polys += found;
        if (max < 0) {
            break;
        }
    }
    return total;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", GetColPoly__6CSceneFP6CCPolyR9mgVu0FBOXi);
#endif
#ifdef NONMATCHING
int CScene::GetCameraPoly(CCPoly *polys, mgVu0FBOX &box, int max) {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    int total = 0;
    for (int index = 0; index < count; ++index) {
        int found = maps[index]->GetCameraPoly(polys, box, max);
        total += found;
        max -= found;
        polys += found;
        if (max < 0) {
            break;
        }
    }
    return total;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", GetCameraPoly__6CSceneFP6CCPolyR9mgVu0FBOXi);
#endif
void CScene::RunEvent(int requested_event_no, CSceneEventData *data) {
    if (event_run) {
        printf("start event running!!\n");
        if (event_no == 100) {
            return;
        }
    }
    event_no = requested_event_no;
    if (data != NULL) {
        event_data = *data;
    }
    event_run = 1;
}
#ifdef NONMATCHING
int CScene::GetMapEvent(float *pos, int check_type, CSceneEventData *data) {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    int last_event_no = 0;
    for (int index = 0; index < count; ++index) {
        MapEventInfo event_info;
        CFuncPoint *point = maps[index]->GetEvent(pos, check_type, &event_info);
        if (event_info.event_no != 0) last_event_no = event_info.event_no;
        if (point == NULL) continue;
        if (data != NULL) {
            data->event = point->event;
            sceVu0CopyVector(data->position, point->position);
            sceVu0CopyVector(data->rotation, point->rotation);
            sceVu0CopyVector(data->scale, point->scale);
            data->map_event = event_info;
        }
        return 1;
    }
    map_event_no = last_event_no;
    int object_slot = GetGameObjectEvent(pos, data);
    if (object_slot < 0) return 0;
    map_event_no = 1;
    if (check_type == 1) {
        if (data != NULL) {
            if (object_slot == 0x78) data->event.event_no = 300;
            else if (object_slot == 0x7A) data->event.event_no = 400;
        }
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", GetMapEvent__6CSceneFPfiP15CSceneEventData);
#endif
#ifdef NONMATCHING
int CScene::GetFixCameraPos(float *pos, float *camera) {
    sceVu0FVECTOR raised;
    sceVu0CopyVector(raised, pos);
    raised[1] += 1.0f;
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    for (int index = 0; index < count; ++index) {
        if (maps[index]->GetFixCameraPos(raised, camera)) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", GetFixCameraPos__6CSceneFPfPf);
#endif
void CScene::FixCameraPartsOnOff(float *pos) {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    for (int index = 0; index < count; ++index) {
        maps[index]->FixCameraPartsOnOff(pos);
    }
}
void CScene::EyeViewDrawOnOff(int on) {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    for (int index = 0; index < count; ++index) {
        CPartsGroup *shown = maps[index]->SearchPartsGroup("eyeview_on");
        CPartsGroup *hidden = maps[index]->SearchPartsGroup("eyeview_off");
        if (shown != NULL) shown->off = !on;
        if (hidden != NULL) hidden->off = on;
    }
}
void CScene::GetSunPosition(float *pos) {
    sceVu0FVECTOR camera_pos;
    mgZeroVector(camera_pos);
    mgCCamera *camera = GetCamera(active_camera);
    if (camera != NULL) camera->GetPos(camera_pos);
    CMap *map = GetMap(active_map);
    if (map == NULL) return;
    map->GetSunPoint(pos);
    sceVu0Normalize(pos, pos);
    sceVu0ScaleVector(pos, pos, 5000.0f);
    pos[0] += camera_pos[0];
    pos[1] += map->unk_dc;
    pos[2] += camera_pos[2];
}
void CScene::GetMoonPosition(float *pos) {
    GetSunPosition(pos);
    pos[1] *= -1.0f;
}
#ifdef NONMATCHING
void CScene::DrawSky(int no) {
    CMapSky *sky = no < 0 ? GetSky(1) : GetSky(no);
    if (sky == NULL && no < 0) sky = GetSky(0);
    if (sky == NULL) return;
    sceVu0FVECTOR camera_pos;
    mgZeroVector(camera_pos);
    mgCCamera *camera = GetCamera(active_camera);
    if (camera != NULL) camera->GetPos(camera_pos);
    CMap *map = GetMap(active_map);
    if (map == NULL || !map->sky_info) return;
    camera_pos[1] = map->unk_dc;
    CMapLightingInfo lighting;
    float ratio[4];
    float sun_ratio[4];
    sceVu0FVECTOR sun_pos;
    sceVu0FVECTOR moon_pos;
    map->GetLightInfo(&lighting);
    map->GetLightingRatio(ratio);
    map->GetLightingSunRatio(sun_ratio);
    GetSunPosition(sun_pos);
    GetMoonPosition(moon_pos);
    sceVu0FVECTOR color0;
    sceVu0FVECTOR color1;
    sceVu0CopyVector(color0, lighting.bg_color);
    sceVu0CopyVector(color1, lighting.bg_color2);
    sceVu0ScaleVector(color0, color0, 0.0078125f);
    sceVu0ScaleVector(color1, color1, 0.0078125f);
    color0[3] = 1.0f;
    color1[3] = 1.0f;
    sky->DrawSkyBack(camera_pos, color0, color1);
    sky->DrawSky(camera_pos, sun_pos, moon_pos, map->GetNowTimeBand(), ratio, sun_ratio);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", DrawSky__6CSceneFi);
#endif
#ifdef NONMATCHING
void CScene::DrawLensFlare(int texb, char *name0, char *name1) {
    CMap *map = GetMap(active_map);
    if (map == NULL || !map->sky_info || !map->lens_flare) return;
    float ratio[4];
    map->GetLightingFlareRatio(ratio);
    if (ratio[0] == 0.0f && ratio[1] == 0.0f && ratio[3] == 0.0f) return;
    sceVu0FVECTOR color = { 0.0f, 0.0f, 0.0f, 1.0f };
    for (int band = 0; band < 4; ++band) {
        color[0] += ratio[band];
        color[1] += ratio[band];
        color[2] += ratio[band];
    }
    sceVu0FVECTOR sun_pos;
    GetSunPosition(sun_pos);
    int screen[4];
    if (mgTransWorldScreen(screen, sun_pos)) {
        screen[2] = mgTransZPrim(10000.0f);
        LensFlare(screen, color, texb, name0, name1);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", DrawLensFlare__6CSceneFiPcPc);
#endif
void CScene::EffectStep() {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    for (int index = 0; index < count; ++index) {
        maps[index]->EffectStep();
    }
    fire_raster.Step();
}
#ifdef NONMATCHING
void CScene::DrawEffect(int mode) {
    CMap *maps[4];
    int count = GetActiveMap(maps, 4);
    for (int index = 0; index < count; ++index) {
        CMap *map = maps[index];
        if (map->effect_list.block >= 0) {
            mgTexManager.ReloadTexture(map->effect_list.block, (sceVif1Packet *)NULL);
            map->DrawEffect();
        }
    }
    mgTexManager.ReloadTexture(mode, (sceVif1Packet *)NULL);
    for (int index = 0; index < count; ++index) {
        CMap *map = maps[index];
        if (map == NULL) continue;
        map->fire_raster = &fire_raster;
        map->DrawFireEffect(mode);
        map->fire_raster = NULL;
    }
    mgCTexture *texture = mgTexManager.GetTexture("fire", mode);
    fire_raster.SetTexture(texture);
    mgCTexture frame;
    mgGetFrameBuffer(&frame);
    mgRect<int> frame_rect(0, 0, (mgScreenWidth - 1) * 16, (mgScreenHeight - 1) * 16);
    mgSetPkMoveImage(&frame, frame_rect, texture, 0, 0, 0);
    for (int index = 0; index < count; ++index) {
        CMap *map = maps[index];
        if (map == NULL) continue;
        map->fire_raster = &fire_raster;
        map->DrawFireRaster();
        map->fire_raster = NULL;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneevent", DrawEffect__6CSceneFi);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneevent", col_1003__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneevent", at_1013__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneevent", at_858__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneevent", at_958__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneevent", at_959__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneevent", at_1093__DATA);
