#include "common.h"
#include "editexception.hpp"
#include "mg_math.hpp"

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
extern s32 GeyserEffectFlag;
extern CGeyserEffect *GeyserEffect;

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", EditExceptionStep__FiP6CScene);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", S51Thunder__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitFirePowder__FiP6CSceneiP9mgCMemory);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawFirePowder__FP6CScene);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", CreatePacket__13CGeyserEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", InitGeyserEffect__FiP6CSceneiP9mgCMemory);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editexception", DrawGeyserEffect__FP6CScene);

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
