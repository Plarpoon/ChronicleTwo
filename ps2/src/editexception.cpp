#include "common.h"
#include "editexception.hpp"
#include "mg_math.hpp"
#include "mg_memory.hpp"
#include "mg_frame.hpp"
#include "mg_drawenv.hpp"
#include "mg_texture.hpp"
#include "mg_tanime.hpp"
#include "mg_camera.hpp"
#include "mapparts.hpp"
#include "mdslist.hpp"
#include "map.hpp"
#include "mapload.hpp"
#include "editmap.hpp"
#include "editparts.hpp"
#include "scenesnd.hpp"
#include "savedata.hpp"
#include "mainloop.hpp"
#include "dataread.hpp"
#include "event_func.hpp"
#include "snd_mngr.hpp"
#include "mglib.hpp"

#include <cmath>
#include <cstdlib>
#include <cstring>

extern s32 rea_chara_id;
extern s32 rea_mtn_step;
extern s32 thunder_count;
extern s32 start_thunder;
extern s32 next_thunder_cnt;
extern s32 fade_cnt;
extern s32 sound_flag;
extern s32 sound_cnt;
extern s32 FirePowderFlag;
extern FirePowder *fire_powder;
extern s32 FirePowderTexb;
extern mgC3DSprite *SpriteVis;
extern mgCFrame *FirePowFrame;
extern s32 GeyserEffectFlag;
extern CGeyserEffect *GeyserEffect;
extern s32 GeyserEffectTexb;
extern mgCFrame *GeyserFrame;
extern s32 GeyserRndSeed;

// Code (.text)
#ifdef NONMATCHING
void EditExceptionStep(int map_no, CScene *scene) {
    if (scene == NULL) return;
    CMap *map = scene->GetMap(scene->active_map);
    mgCCamera *camera = scene->GetCamera(scene->active_camera);
    if (map == NULL || camera == NULL) return;
    float camera_pos[4];
    camera->GetPos(camera_pos);
    if (map_no != 2 && map_no != 9) return;
    CMapParts *parts = map->GetPlaceParts("p07_g0301");
    if (parts == NULL) return;
    CMapPiece *piece07 = parts->SearchPiece("g0301_07-m");
    CMapPiece *piece08 = parts->SearchPiece("g0301_08-m");
    if (piece07 == NULL || piece08 == NULL || piece07->frame == NULL || piece08->frame == NULL) return;
    mgCFrame *fade_frame = piece07->frame->SearchFrame("na");
    if (fade_frame == NULL || fade_frame->attr == NULL) return;
    mgCTexture *texture = mgTexManager.GetTexture("g0301_21", -1);
    if (texture == NULL) return;
    mgCTextureAnime *anime = mgTexManager.GetTexAnime(texture->block);
    if (anime == NULL) return;
    CList<mgCTexAnimeData> *list = anime->GetAnimeList(anime->SearchGroupName("na"));
    if (list == NULL) return;
    int length = list->data.dest_h;
    int frame = list->data.period_y - 20;
    if (frame < 0) frame = 0;
    int quarter = length / 4;
    float alpha = 0.0f;
    if (frame < quarter) alpha = (float)frame / (float)quarter;
    else if (frame < quarter * 3) alpha = 1.0f - (float)(frame - quarter) / (float)(quarter * 2);
    fade_frame->attr->obj_alpha = alpha;
    piece08->frame->SetAttrParamObjAlpha((1.0f + sinf(6.2831855f * (float)list->data.period_y / (float)length)) / 0.5f, 1);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", EditExceptionStep__FiP6CScene);
#endif
void InitNpcCameraReaction() {
    rea_mtn_step = 0;
    rea_chara_id = -1;
}
void InitS51Thunder() {
    thunder_count = 0;
    start_thunder = 0;
    next_thunder_cnt = 60;
    fade_cnt = 0;
    sound_cnt = 0;
    sound_flag = 0;
}
#ifdef NONMATCHING
void S51Thunder(CScene *scene) {
    char *map_name = scene->GetMapName(scene->active_map);
    if (map_name == NULL || strcmp(map_name, "s51") != 0) return;
    if (next_thunder_cnt == 0) {
        fade_cnt = 40;
        thunder_count = 4;
        next_thunder_cnt = rand() % 150 + 10;
        sound_flag = 1;
        sound_cnt = rand() % 20;
        if (next_thunder_cnt < sound_cnt) sound_cnt = 1;
    }
    if (sound_flag != 0 && --sound_cnt <= 0) {
        sound_cnt = 0;
        sound_flag = 0;
        sndSePlay(EdEventInfo.snd_id[4], rand() % 4 + 21, 0);
    }
    --fade_cnt;
    --thunder_count;
    --next_thunder_cnt;
    if (fade_cnt < 0) fade_cnt = 0;
    float flash = (float)fade_cnt / 40.0f;
    CMap *map = scene->GetMap(scene->active_map);
    float time_ratio;
    if (map == NULL || map->GetTimeLightingRatio(&time_ratio) < 2) return;
    float ratio[2] = {1.0f - flash, flash};
    CMapLightingInfo lighting;
    map->GetLightInfo(&lighting, ratio, 2);
    mgSetLight(lighting.light_dir, lighting.light_color);
    mgSetAmbient(lighting.ambient);
    const char *names[2] = {"p05_s5102-0", "p11_s5102-0"};
    for (int i = 0; i < 2; ++i) {
        CMapParts *parts = map->GetPlaceParts((char *)names[i]);
        if (parts == NULL) continue;
        parts->show = 1;
        for (CList<CMapPiece> *node = parts->piece_list; node != NULL; node = node->next) {
            node->data.draw_enable = 1;
            node->data.time_start = flash;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", S51Thunder__FP6CScene);
#endif
#ifdef NONMATCHING
void InitFirePowder(int map_no, CScene *scene, int texb, mgCMemory *memory) {
    FirePowderFlag = 0;
    if ((map_no != 3 && map_no != 0x57 && map_no != 0x55) || GetSaveData()->GetBitFlag(0x208)) return;
    int size;
    if (!LoadFile2("effect/firerain.img", scene->read_buff, &size, 0)) return;
    u_char *image = (u_char *)memory->Alloc((size + 15) / 16);
    memcpy(image, scene->read_buff, size);
    FirePowderFlag = 1;
    FirePowderTexb = texb;
    mgTexManager.DeleteBlock(texb);
    mgTexManager.EnterIMGFile(image, texb, NULL, NULL);
    SpriteVis = new (memory->Alloc(7)) mgC3DSprite;
    fire_powder = new (memory->Alloc(0x202)) FirePowder[FIRE_POWDER_NUM];
    FirePowFrame = new (memory->Alloc(0x13)) mgCFrame;
    FirePowFrame->attr = new (memory->Alloc(0xB)) mgCFrameAttr;
    FirePowFrame->attr->draw = 2;
    FirePowFrame->attr->clip_enable = -1;
    FirePowFrame->SetVisual(SpriteVis);
    for (int i = 0; i < FIRE_POWDER_NUM; ++i) {
        FirePowder &particle = fire_powder[i];
        particle.pos[0] = 2.0f * (200.0f * (mgRnd() - 0.5f));
        particle.pos[1] = 2.0f * (300.0f * (mgRnd() - 0.5f));
        particle.pos[2] = 2.0f * (200.0f * (mgRnd() - 0.5f));
        particle.pos[3] = 0.0f;
        particle.phase_speed = 0.1f + 0.1f * mgRnd();
        particle.sway_x = 2.0f * (2.0f * (mgRnd() - 0.5f));
        particle.sway_z = 2.0f * (2.0f * (mgRnd() - 0.5f));
        particle.fall_speed = -(0.1f + 0.5f * mgRnd());
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitFirePowder__FiP6CSceneiP9mgCMemory);
#endif
void StepFirePowder(CScene *scene) {
    if (!FirePowderFlag) return;
    for (int particle_index = 0; particle_index < FIRE_POWDER_NUM; ++particle_index) {
        FirePowder &particle = fire_powder[particle_index];
        particle.pos[1] += particle.fall_speed;
        if (particle.pos[1] < -300.0f) particle.pos[1] = 300.0f;
        particle.pos[3] += particle.phase_speed;
        if (particle.pos[3] > 3.1415927f) particle.pos[3] -= 6.2831855f;
    }
}
#ifdef NONMATCHING
void DrawFirePowder(CScene *scene) {
    if (!FirePowderFlag) return;
    mgTexManager.ReloadTexture(FirePowderTexb, (sceVif1Packet *)NULL);
    SpriteVis->Initialize();
    mgCDrawEnv draw_env = *mgGetpDrawEnv(0);
    draw_env.SetZBuf(-1);
    draw_env.SetAlpha(2);
    SpriteVis->BeginCreatePacket(0, NULL);
    SpriteVis->CPSetDrawEnv(&draw_env);
    SpriteVis->CPSetTexture(mgTexManager.GetTexture("firerain", -1));
    SpriteVis->BeginCPSprite();
    float size[4] = {15.0f, 15.0f, 0.0f, 0.0f};
    float color[4] = {128.0f, 128.0f, 128.0f, 64.0f};
    float uv0[4][4] = {{0.0f, 0.0f, 0.0f, 0.0f}, {0.5f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 0.5f, 0.0f, 0.0f}, {0.5f, 0.5f, 0.0f, 0.0f}};
    float uv1[4][4] = {{0.5f, 0.5f, 0.0f, 0.0f}, {1.0f, 0.5f, 0.0f, 0.0f},
                       {0.5f, 1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f, 0.0f}};
    for (int i = 0; i < FIRE_POWDER_NUM; ++i) {
        FirePowder &particle = fire_powder[i];
        float sway = particle.sway_x * sinf(particle.pos[3]);
        float pos[4] = {particle.pos[0] + sway, particle.pos[1], particle.pos[2] + sway, 1.0f};
        SpriteVis->CPSetSprite(pos, size, color, uv0[i & 3], uv1[i & 3]);
    }
    SpriteVis->EndCPSprite();
    SpriteVis->EndCreatePacket();
    mgCCamera *camera = scene->GetCamera(scene->active_camera);
    float camera_pos[4], camera_dir[4];
    camera->GetPos(camera_pos);
    camera->GetDir(camera_dir);
    mgNormalizeVector(camera_dir, camera_dir, 200.0f);
    mgAddVector(camera_pos, camera_dir);
    int old_fog = mgGetFogEnable();
    mgFOG_PARAM old_fog_param;
    mgGetFogParam(&old_fog_param);
    float old_scale = mgRenderInfo.fog.scale;
    mgRenderInfo.fog.scale = 600.0f;
    mgFogEnable(1);
    mgSetFogParam(50.0f, 400.0f, 100, 0, 0, 255.0f, 0.0f);
    mgFlushRenderInfo();
    const float half_extent[3] = {200.0f, 300.0f, 200.0f};
    float centre[4];
    for (int axis = 0; axis < 3; ++axis) {
        int cell = (int)(camera_pos[axis] / half_extent[axis]);
        cell += cell >= 0 ? 1 : -1;
        centre[axis] = (float)(cell / 2) * (2.0f * half_extent[axis]);
    }
    centre[3] = 1.0f;
    for (int x = -1; x < 2; ++x) {
        for (int z = -1; z < 2; ++z) {
            for (int y = -1; y < 2; ++y) {
                float pos[4] = {centre[0] + 2.0f * x * half_extent[0],
                                centre[1] + 2.0f * y * half_extent[1],
                                centre[2] + 2.0f * z * half_extent[2], 1.0f};
                FirePowFrame->SetPosition(pos);
                mgDrawDirect(FirePowFrame);
            }
        }
    }
    mgFogEnable(old_fog);
    mgRenderInfo.fog.scale = old_scale;
    mgSetFogParam(&old_fog_param);
    mgFlushRenderInfo();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawFirePowder__FP6CScene);
#endif
void CGeyserEffect::Create() {
    if (wait <= 0) {
        if (wait == 0) erupting = 1;
        wait = static_cast<int>(150.0f * mgRnd()) + 100;
        erupt_frame = 0;
        erupt_count = static_cast<int>(32.0f * mgRnd()) + 48;
    }
    --wait;
    if (erupting) {
        if (erupt_frame % 12 != 0) {
            --erupt_count;
            CreatePoint();
        }
        ++erupt_frame;
        if (erupt_count <= 0) erupting = 0;
    }
}
void CGeyserEffect::Step() {
    Create();
    if (!point) return;
    for (int point_index = 0; point_index < point_num; ++point_index) {
        CGeyserEffectPoint &effect_point = point[point_index];
        if (!effect_point.active) continue;
        effect_point.alpha -= 0.02f;
        effect_point.pos[1] += effect_point.rise_speed;
        effect_point.scale += 0.1f;
        effect_point.pos[3] += effect_point.phase_speed;
        if (effect_point.pos[3] > 3.1415927f) effect_point.pos[3] -= 6.2831855f;
        if (effect_point.alpha < 0.0f) effect_point.active = 0;
    }
}
CGeyserEffectPoint *CGeyserEffect::GetEmpty() {
    if (!point) return NULL;
    for (int point_index = 0; point_index < point_num; ++point_index) {
        if (!point[point_index].active) return &point[point_index];
    }
    return NULL;
}
void CGeyserEffect::CreatePoint() {
    CGeyserEffectPoint *effect_point = GetEmpty();
    if (!effect_point) return;
    effect_point->active = 1;
    effect_point->alpha = 1.0f;
    effect_point->rise_speed = 2.6f + 0.4f * mgRnd();
    effect_point->scale = 1.0f;
    effect_point->sway_x = 2.0f * (2.0f * (mgRnd() - 0.5f));
    effect_point->sway_z = 2.0f * (2.0f * (mgRnd() - 0.5f));
    effect_point->phase_speed = 0.1f + 0.1f * mgRnd();
    mgZeroVectorW(effect_point->pos);
}
#ifdef NONMATCHING
void CGeyserEffect::CreatePacket() {
    if (point_num == 0 || point == NULL) return;
    sprite.Initialize();
    mgCDrawEnv draw_env = *mgGetpDrawEnv(0);
    draw_env.SetZBuf(-1);
    draw_env.SetAlpha(2);
    sprite.BeginCreatePacket(0, NULL);
    sprite.CPSetDrawEnv(&draw_env);
    sprite.CPSetTexture(texture);
    sprite.BeginCPSprite();
    float size[4] = {15.0f, 15.0f, 0.0f, 0.0f};
    float color[4] = {128.0f, 128.0f, 128.0f, 64.0f};
    float uv0[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float uv1[4] = {1.0f, 1.0f, 0.0f, 0.0f};
    for (int i = 0; i < point_num; ++i) {
        CGeyserEffectPoint &particle = point[i];
        if (!particle.active) continue;
        float phase = sinf(particle.pos[3]);
        float pos[4] = {
            particle.pos[0] + particle.scale * particle.sway_x * phase,
            particle.pos[1],
            particle.pos[2] + particle.scale * particle.sway_z * phase,
            1.0f
        };
        color[3] = 64.0f * particle.alpha;
        size[0] = size[1] = 15.0f * particle.scale;
        sprite.CPSetSprite(pos, size, color, uv0, uv1);
    }
    sprite.EndCPSprite();
    sprite.EndCreatePacket();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", CreatePacket__13CGeyserEffectFv);
#endif
#ifdef NONMATCHING
void InitGeyserEffect(int map_no, CScene *scene, int texb, mgCMemory *memory) {
    GeyserEffectFlag = 0;
    if (map_no != 3) return;
    int size;
    if (!LoadFile2("effect/geyser.img", scene->read_buff, &size, 0)) return;
    u_char *image = (u_char *)memory->Alloc((size + 15) / 16);
    memcpy(image, scene->read_buff, size);
    GeyserEffectFlag = 1;
    GeyserEffectTexb = texb;
    mgTexManager.DeleteBlock(texb);
    mgTexManager.EnterIMGFile(image, texb, NULL, NULL);
    GeyserFrame = new (memory->Alloc(0x13)) mgCFrame;
    GeyserFrame->attr = new (memory->Alloc(0xB)) mgCFrameAttr;
    GeyserFrame->attr->draw = 2;
    GeyserFrame->attr->clip_enable = -1;
    GeyserEffect = new (memory->Alloc(0x22)) CGeyserEffect[GEYSER_EFFECT_NUM];
    for (int i = 0; i < GEYSER_EFFECT_NUM; ++i) {
        CGeyserEffect &emitter = GeyserEffect[i];
        emitter.point_num = GEYSER_EFFECT_POINT_NUM;
        emitter.point = new (memory->Alloc(0x92)) CGeyserEffectPoint[GEYSER_EFFECT_POINT_NUM];
        emitter.texture = mgTexManager.GetTexture("geyser_eff", -1);
    }
    GeyserRndSeed = rand();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitGeyserEffect__FiP6CSceneiP9mgCMemory);
#endif
CGeyserEffectPoint::CGeyserEffectPoint(void) {
    active = 0;
}
#ifdef NONMATCHING
CGeyserEffect::CGeyserEffect() {
    point_num = 0;
    point = NULL;
    sprite.Initialize();
    wait = -1;
    erupting = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", __ct__13CGeyserEffectFv);
#endif
void StepGeyserEffect(CScene *scene) {
    if (!GeyserEffectFlag) return;
    for (int emitter_index = 0; emitter_index < GEYSER_EFFECT_NUM; ++emitter_index) {
        GeyserEffect[emitter_index].Step();
    }
}
#ifdef NONMATCHING
void DrawGeyserEffect(CScene *scene) {
    if (!GeyserEffectFlag) return;
    CEditMap *map = (CEditMap *)scene->GetMap(scene->active_map);
    if (map == NULL) return;
    int ids[20];
    int count = map->GetePlacePartsAtInfoID(0x4C, ids, 20);
    if (count <= 0) return;
    mgGetDataBuffer();
    mgTexManager.ReloadTexture(GeyserEffectTexb, (sceVif1Packet *)NULL);
    for (int i = 0; i < GEYSER_EFFECT_NUM; ++i) GeyserEffect[i].CreatePacket();
    for (int i = 0; i < count; ++i) {
        CEditParts *parts = map->GetePlaceParts(ids[i]);
        if (parts == NULL) continue;
        int emitter = ((ids[i] * 0x10DE8 + 1) >> 16) % GEYSER_EFFECT_NUM;
        float pos[4];
        parts->GetPosition(pos);
        GeyserFrame->SetVisual(&GeyserEffect[emitter].sprite);
        GeyserFrame->SetPosition(pos);
        mgDrawDirect(GeyserFrame);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawGeyserEffect__FP6CScene);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1175__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1176__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1177__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1178__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1184__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1327__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1329__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1330__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_917__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_918__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_919__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_920__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_921__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1084__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1085__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1086__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1143__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1259__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1385__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editexception", at_1386__3__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(rea_chara_id, 0x4);
INCLUDE_BSS(rea_mtn_step, 0x4);
INCLUDE_BSS(thunder_count, 0x4);
INCLUDE_BSS(start_thunder, 0x4);
INCLUDE_BSS(next_thunder_cnt, 0x4);
INCLUDE_BSS(fade_cnt, 0x4);
INCLUDE_BSS(sound_flag, 0x4);
INCLUDE_BSS(sound_cnt, 0x4);
INCLUDE_BSS(FirePowderFlag, 0x4);
INCLUDE_BSS(FirePowderTexb, 0x4);
INCLUDE_BSS(SpriteVis, 0x4);
INCLUDE_BSS(FirePowFrame, 0x4);
INCLUDE_BSS(fire_powder, 0x4);
INCLUDE_BSS(GeyserEffectFlag, 0x4);
INCLUDE_BSS(GeyserEffectTexb, 0x4);
INCLUDE_BSS(GeyserFrame, 0x4);
INCLUDE_BSS(GeyserRndSeed, 0x4);
INCLUDE_BSS(GeyserEffect, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1328__2, 0x10);
