#include "common.h"
#include "gyoracesim.hpp"
#include "crandom.hpp"
#include <cstring>

extern grFISH_DATA fish_data[18];
extern int ia[56];
extern int jrand;

int GetRaceDivision(float distance);
float GetCourseR(float position, float lane);
float GetRaceDivisionLength(int division);
static float GetRandomNumber(float mean, float range);
void init_rnd(unsigned int seed);
void RndFishParam(RACE_FISH_PARAM *fish);
void CharacterBonus(grFISH_PARAM *source, RACE_FISH_PARAM *fish, int count);
void FishModifyParam(grFISH_PARAM *source, float *output, float average);
void GetPaseRatio(int tactics, float *ratio);
void SetRaceFishParam(RACE_FISH_PARAM *fish, grRACE_INFO *info);
int StepGyoRace(RACE_FISH_PARAM *fish, grRACE_INFO *info);
void CollisionFish(RACE_FISH_PARAM *fish, int count);
void LaneBattleStep(RACE_FISH_PARAM *fish, int count);
grFISH_DATA *GetFishData(int fish_no);
static float nrnd();
int irnd();


// Code (.text)
#ifdef NONMATCHING
int grGyoRaceSimulate(grRACE_INFO *info) {
    u32 sum = 0;
    u32 random = 0x3526D02F;
    for (int i = 0; i < info->fish_num; ++i) {
        grFISH_PARAM &source = info->fish[i];
        for (int j = 0; source.name[j] != '\0'; ++j) {
            random = random * 0x5D588B65 + 1;
            sum += (signed char)source.name[j] * random;
        }
        int figures[10] = {
            source.fish_no, source.affinity, source.bonus_type, source.power,
            source.stamina, source.speed[0], source.speed[1], source.speed[2],
            source.tactics, source.lane,
        };
        for (int j = 0; j < 10; ++j) {
            random = random * 0x5D588B65 + 1;
            sum += figures[j] * random;
        }
    }
    init_rnd(info->seed == 0 ? sum : info->seed);
    RACE_FISH_PARAM fish[6];
    SetRaceFishParam(fish, info);
    return StepGyoRace(fish, info);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", grGyoRaceSimulate__FP11grRACE_INFO);
#endif
#ifdef NONMATCHING
int grGetFishProgress(grRACE_INFO *info, int fish, float time, grRACE_PROGRESS *out) {
    if (fish < 0 || fish >= info->fish_num || info->progress[fish] == NULL) return 0;
    int step = (int)time;
    int next = step + 1;
    float fraction = time - (float)step;
    if (next >= info->step_max) return 0;
    grRACE_PROGRESS *record = info->progress[fish];
    grRACE_PROGRESS *current = &record[step];
    out->pos = current->pos;
    out->lane = current->lane;
    out->lane_pos = current->lane_pos;
    out->state = current->state;
    out->battle = current->battle;
    out->battle_target = current->battle_target;
    out->battle_hits = current->battle_hits;
    if (out->state == GR_RACE_STATE_NONE) return 0;
    out->pos += fraction * (record[next].pos - out->pos);
    out->lane_pos += fraction * (record[next].lane_pos - out->lane_pos);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", grGetFishProgress__FP11grRACE_INFOifP15grRACE_PROGRESS);
#endif
float FishDist(RACE_FISH_PARAM *fish, RACE_FISH_PARAM *other) {
    return (fish->pos + fish->velocity) - (other->pos + other->velocity);
}
#ifdef NONMATCHING
int StepFish(int step, RACE_FISH_PARAM *fish) {
    if (fish->progress == NULL || step >= fish->progress_num) return 1;
    grRACE_PROGRESS &record = fish->progress[step];
    int division = GetRaceDivision(fish->pos);
    if (division < 0) {
        fish->velocity -= 0.01f;
        if (fish->velocity < 0.0f) fish->velocity = 0.01f;
        fish->pos += fish->velocity;
    } else {
        float target = 0.1f + 0.0002f * fish->speed[division];
        if (fish->rank > 0 && fish->rank < 7) target *= fish->rank_ratio[fish->rank - 1];
        if (fish->boost > 1.0f) fish->boost = 1.0f;
        if (fish->boost < -1.0f) fish->boost = -1.0f;
        float acceleration = fish->accel[division] - (fish->velocity - target) / 0.016f + 1.25f * fish->boost;
        float radius = GetCourseR(fish->pos, record.lane_pos);
        fish->velocity += 0.0016f * acceleration;
        if (fish->velocity < 0.01f) fish->velocity = 0.01f;
        fish->pos += fish->velocity * radius;
        if (fish->boost > 0.0f) {
            fish->boost -= 0.05f;
            if (fish->boost < 0.0f) fish->boost = 0.0f;
        } else if (fish->boost < 0.0f) {
            fish->boost += 0.05f;
            if (fish->boost > 0.0f) fish->boost = 0.0f;
        }
    }
    record.pos = fish->pos;
    record.state = fish->state;
    record.battle = fish->battle;
    record.battle_target = fish->battle_target;
    record.battle_hits = fish->battle_hits;
    record.lane = fish->lane;
    record.lane_pos = (float)fish->lane;
    if (record.pos >= 16.0f) {
        record.state = GR_RACE_STATE_GOAL;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", StepFish__FiP15RACE_FISH_PARAM);
#endif
#ifdef NONMATCHING
void LaneBattleStep(RACE_FISH_PARAM *fish, int count) {
    int lane_count[6] = {0, 0, 0, 0, 0, 0};
    int lane_fish[6][6];
    int order[6];
    for (int i = 0; i < count; ++i) {
        order[i] = i;
        int lane = fish[i].lane;
        lane_fish[lane][lane_count[lane]++] = i;
    }
    for (int i = 0; i < 20; ++i) {
        int a = (irnd() >> 22) % count;
        int b = (irnd() >> 22) % count;
        int swap = order[a];
        order[a] = order[b];
        order[b] = swap;
    }
    for (int turn = 0; turn < count; ++turn) {
        int index = order[turn];
        RACE_FISH_PARAM &current = fish[index];
        int neighbor[2] = {-1, -1};
        bool crowded[2] = {false, false};
        float best_distance[2] = {-1.0f, -1.0f};
        for (int side = 0; side < 2; ++side) {
            int adjacent_lane = current.lane + (side == 0 ? -1 : 1);
            if (adjacent_lane < 0 || adjacent_lane >= 6) continue;
            for (int j = 0; j < lane_count[adjacent_lane]; ++j) {
                int other_index = lane_fish[adjacent_lane][j];
                RACE_FISH_PARAM &other = fish[other_index];
                float distance = FishDist(&other, &current);
                float magnitude = distance < 0.0f ? -distance : distance;
                if (magnitude < 0.075f) crowded[side] = true;
                if (magnitude < 0.05f && other.state != GR_RACE_STATE_BATTLE &&
                    (neighbor[side] < 0 || best_distance[side] < distance)) {
                    neighbor[side] = other_index;
                    best_distance[side] = distance;
                }
            }
        }
        bool fish_ahead = false;
        for (int j = 0; j < lane_count[current.lane]; ++j) {
            float distance = FishDist(&fish[lane_fish[current.lane][j]], &current);
            if (distance > 0.0f && distance < 0.1f) fish_ahead = true;
        }
        if (current.state == GR_RACE_STATE_BATTLE) {
            current.battle_time -= 1.0f;
            RACE_FISH_PARAM &other = fish[current.battle_target];
            float difference = current.power - other.power;
            if (difference > 30.0f) difference = 30.0f;
            if (difference < -30.0f) difference = -30.0f;
            int chance = (int)(((difference + 30.0f) / 60.0f) * 100.0f);
            if (chance < 1) chance = 1;
            if (chance > 100) chance = 100;
            if (rand_prob(chance)) ++current.battle_hits;
            if (current.battle_time < 0.0f) {
                RACE_FISH_PARAM *winner = rand_prob(chance) ? &current : &other;
                RACE_FISH_PARAM *loser = winner == &current ? &other : &current;
                winner->boost = 0.5f;
                loser->boost = -0.25f;
                current.battle_time = 0.0f;
                current.state = GR_RACE_STATE_SWIM;
                current.battle = 0;
                other.state = GR_RACE_STATE_SWIM;
                other.battle = 0;
                other.battle_time = 0.0f;
            }
        } else {
            float crowd_effect = 0.0f;
            float increment = 0.1f * GetRandomNumber(1.0f, 0.5f);
            if (!crowded[0] && !crowded[1]) crowd_effect = -increment;
            if (crowded[0]) crowd_effect += increment;
            if (crowded[1]) crowd_effect += increment;
            current.battle_urge += current.aggression * crowd_effect;
            if (current.battle_urge < 0.0f) current.battle_urge = 0.0f;
        }
        if (current.state == GR_RACE_STATE_BATTLE) continue;
        if (rand_prob(10) && !crowded[0]) {
            if (--current.lane < 0) current.lane = 0;
        } else if (fish_ahead && rand_prob(75)) {
            int change = 0;
            if (!crowded[0]) {
                if (!crowded[1]) change = rand_prob(80) ? 1 : -1;
                else change = -1;
            } else if (!crowded[1]) change = 1;
            current.lane += change;
            if (current.lane < 0) current.lane = 0;
            if (current.lane >= 6) current.lane = 5;
        } else if ((neighbor[0] >= 0 || neighbor[1] >= 0) && current.battle_urge > 1.0f) {
            int target = -1;
            if (crowded[0] && crowded[1]) target = rand_prob(50) ? neighbor[0] : neighbor[1];
            else if (crowded[0]) target = neighbor[0];
            else if (crowded[1]) target = neighbor[1];
            if (target >= 0) {
                RACE_FISH_PARAM &other = fish[target];
                float speed = current.velocity > other.velocity ? current.velocity : other.velocity;
                current.state = GR_RACE_STATE_BATTLE;
                current.battle = 1;
                current.battle_target = target;
                current.battle_hits = 0;
                current.battle_urge = 0.0f;
                current.battle_time = 5.0f;
                current.velocity = speed;
                other.state = GR_RACE_STATE_BATTLE;
                other.battle = 1;
                other.battle_target = index;
                other.battle_hits = 0;
                other.battle_urge = 0.0f;
                other.battle_time = 5.0f;
                other.velocity = speed;
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", LaneBattleStep__FP15RACE_FISH_PARAMi);
#endif
#ifdef NONMATCHING
void CollisionFish(RACE_FISH_PARAM *fish, int count) {
    int order[6];
    float distance[6];
    for (int i = 0; i < count; ++i) {
        order[i] = i;
        distance[i] = fish[i].pos - fish[i].velocity;
    }
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (distance[i] < distance[j]) {
                float old_distance = distance[i];
                distance[i] = distance[j];
                distance[j] = old_distance;
                int old_index = order[i];
                order[i] = order[j];
                order[j] = old_index;
            }
        }
    }
    int lane_count[6] = {0, 0, 0, 0, 0, 0};
    int lane_fish[6][6];
    for (int i = 0; i < count; ++i) {
        int index = order[i];
        int lane = fish[index].lane;
        lane_fish[lane][lane_count[lane]++] = index;
    }
    for (int lane = 0; lane < 6; ++lane) {
        if (lane_count[lane] == 0) continue;
        RACE_FISH_PARAM *ahead = &fish[lane_fish[lane][0]];
        for (int i = 1; i < lane_count[lane]; ++i) {
            RACE_FISH_PARAM *behind = &fish[lane_fish[lane][i]];
            float limit = ahead->pos - 0.05f;
            if (limit < behind->pos) behind->pos = limit;
            ahead = behind;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", CollisionFish__FP15RACE_FISH_PARAMi);
#endif
#ifdef NONMATCHING
int StepGyoRace(RACE_FISH_PARAM *fish, grRACE_INFO *info) {
    for (int i = 0; i < 6; ++i) {
        info->rank[i] = 0;
        info->goal_time[i] = 0.0f;
    }
    int step = 0;
    for (; step < info->step_max; ++step) {
        int finished[6];
        for (int i = 0; i < info->fish_num; ++i) {
            finished[i] = StepFish(step, &fish[i]);
            if (finished[i] && info->goal_time[i] == 0.0f) {
                info->goal_time[i] = (float)step - (fish[i].pos - 16.0f) / fish[i].velocity;
            }
        }
        for (int i = 0; i < info->fish_num; ++i) {
            fish[i].rank = 1;
            for (int j = 0; j < info->fish_num; ++j) {
                if (i != j && fish[i].pos < fish[j].pos) ++fish[i].rank;
            }
        }
        CollisionFish(fish, info->fish_num);
        LaneBattleStep(fish, info->fish_num);
        bool all_finished = true;
        for (int i = 0; i < info->fish_num; ++i) {
            if (!finished[i]) all_finished = false;
        }
        if (all_finished) break;
    }
    for (int i = 0; i < info->fish_num; ++i) {
        info->rank[i] = 1;
        for (int j = 0; j < info->fish_num; ++j) {
            if (i != j && info->goal_time[i] > info->goal_time[j]) ++info->rank[i];
        }
    }
    int next = step + 1;
    for (int extra = 0; extra <= info->after_goal_step && next < info->step_max; ++extra, ++next) {
        for (int i = 0; i < info->fish_num; ++i) StepFish(next, &fish[i]);
    }
    return next;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", StepGyoRace__FP15RACE_FISH_PARAMP11grRACE_INFO);
#endif
s32 GetRaceDivision(float distance) {
    s32 division;

    if (distance < 2.0f) {
        return 0;
    }
    if (distance < 6.0f) {
        return 1;
    }
    if (distance < 10.0f) {
        return 2;
    }
    if (distance < 14.0f) {
        return 3;
    }
    division = -1;
    if (!(distance < 16.0f)) {
        return division;
    }
    division = 4;

    return division;
}
#ifdef NONMATCHING
float GetRaceDivisionLength(int division) {
    if (division < 0) {
        return 0.0f;
    }
    switch (division) {
    case 0:
    case 4:
        return 2.0f;
    default:
        return 4.0f;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetRaceDivisionLength__Fi);
#endif

#ifdef NONMATCHING
float GetCourseR(float position, float lane) {
    // The retail branches all choose the same course radius.
    return 1.0f;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetCourseR__Fff);
#endif
#ifdef NONMATCHING
void FishModifyParam(grFISH_PARAM *source, float *output, float average) {
    output[0] = (float)source->stamina;
    for (int i = 0; i < 3; ++i) output[i + 1] = (float)source->speed[i];
    output[4] = (float)source->power;
    output[5] = 0.5f;
    grFISH_DATA *kind = GetFishData(source->fish_no);
    if (kind != NULL) {
        output[0] *= kind->stamina / 100.0f;
        for (int i = 0; i < 3; ++i) output[i + 1] *= kind->speed[i] / 100.0f;
        output[4] *= kind->power / 100.0f;
        if (source->affinity == kind->affinity) {
            for (int i = 0; i < 5; ++i) output[i] *= 1.1f;
        }
    }
    u32 seed = 1;
    int shift = 0;
    for (int i = 0; source->name[i] != '\0'; ++i) {
        seed += (signed char)source->name[i] << shift;
        shift = (shift + 4) % 28;
    }
    if (seed == 0) seed = 1;
    CRandom random;
    random.seed = seed;
    for (int i = 0; i < 1000; ++i) random.seed = random.seed * 0x5D588B65 + 1;
    for (int i = 0; i < 5; ++i) output[i] *= 1.0f + random.nget() * 0.03f;
    float noise = 25.0f * average / 100.0f;
    if (noise < 6.25f) noise = 6.25f;
    for (int i = 0; i < 4; ++i) {
        float variation = noise * nrnd();
        if (variation < 0.0f) variation = -variation;
        output[i] += variation;
        if (output[i] < 0.0f) output[i] = 0.0f;
    }
    output[5] = GetRandomNumber(0.5f, 0.5f);
    switch (source->tactics) {
    case 0: {
        float factor = GetRandomNumber(1.0f, 0.1f);
        output[5] -= 0.5f;
        for (int i = 1; i <= 3; ++i) output[i] *= factor;
        break;
    }
    case 1: {
        float factor = GetRandomNumber(1.0f, 0.2f);
        for (int i = 1; i <= 3; ++i) output[i] *= factor;
        break;
    }
    case 2:
        output[5] -= 0.3f;
        output[1] *= GetRandomNumber(1.5f, 0.2f);
        output[2] *= 0.873f;
        output[3] *= 0.5f;
        break;
    case 3:
        output[5] += 0.2f;
        output[1] *= 0.8f;
        output[2] *= 0.8f;
        output[3] *= GetRandomNumber(1.8f, 0.4f);
        break;
    case 4: {
        float factor = GetRandomNumber(1.0f, 0.2f);
        output[5] += 0.5f;
        for (int i = 1; i <= 3; ++i) output[i] *= factor;
        break;
    }
    case 5:
        output[5] += 0.1f;
        output[1] *= 0.8f;
        output[2] *= GetRandomNumber(1.3f, 0.3f);
        output[3] *= 0.8f;
        break;
    }
    for (int i = 0; i < 4; ++i) if (output[i] < 0.0f) output[i] = 0.0f;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", FishModifyParam__FP12grFISH_PARAMPff);
#endif
#ifdef NONMATCHING
void CharacterBonus(grFISH_PARAM *source, RACE_FISH_PARAM *fish, int count) {
    float front = 1.0f;
    float back = 1.0f;
    for (int i = 0; i < 6; ++i) fish->rank_ratio[i] = 1.0f;
    switch (source->bonus_type) {
    case GR_CHARA_BONUS_FRONT: {
        float amount = GetRandomNumber(0.0f, 0.01f);
        if (amount < 0.0f) amount = -amount;
        front = 1.0f + amount;
        back = 1.0f - amount;
        break;
    }
    case GR_CHARA_BONUS_BACK: {
        float amount = GetRandomNumber(0.0f, 0.01f);
        if (amount < 0.0f) amount = -amount;
        front = 1.0f - 0.2f * amount;
        back = 1.0f + amount;
        break;
    }
    case GR_CHARA_BONUS_RANDOM:
        front = GetRandomNumber(1.0f, 0.01f);
        back = GetRandomNumber(1.0f, 0.01f);
        break;
    }
    for (int i = 0; i < count; ++i) {
        fish->rank_ratio[i] = front - ((float)i / (float)(count - 1)) * (front - back);
    }
    fish->rank_ratio[0] = 1.0f;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", CharacterBonus__FP12grFISH_PARAMP15RACE_FISH_PARAMi);
#endif
void RndFishParam(RACE_FISH_PARAM *fish) {
    for (int i = 0; i < 5; ++i) {
        fish->speed[i] *= GetRandomNumber(1.0f, 0.5f);
        if (fish->speed[i] < 0.0f) fish->speed[i] = 0.0f;
        fish->accel[i] *= GetRandomNumber(1.0f, 0.5f);
        if (fish->accel[i] < 0.0f) fish->accel[i] = 0.0f;
    }
}
void GetPaseRatio(int tactics, float *ratio) {
    for (int division = 0; division < 5; ++division) {
        ratio[division] = 1.0f;
    }
    float total = 0.0f;
    for (int division = 0; division < 5; ++division) {
        total += ratio[division];
    }
    for (int division = 0; division < 5; ++division) {
        ratio[division] /= total;
    }
}
#ifdef NONMATCHING
void SetRaceFishParam(RACE_FISH_PARAM *fish, grRACE_INFO *info) {
    float average = 0.0f;
    for (int i = 0; i < info->fish_num; ++i) {
        average += info->fish[i].stamina;
        for (int j = 0; j < 3; ++j) average += info->fish[i].speed[j];
    }
    average /= 4.0f * (float)info->fish_num;
    for (int i = 0; i < info->fish_num; ++i) {
        RACE_FISH_PARAM &dst = fish[i];
        memset(&dst, 0, sizeof(dst));
        grFISH_PARAM source = info->fish[i];
        float modified[6];
        float ratio[5];
        FishModifyParam(&source, modified, average);
        CharacterBonus(&source, &dst, info->fish_num);
        dst.speed[0] = modified[1];
        dst.speed[1] = (modified[1] + 0.5f * modified[2]) / 1.5f;
        dst.speed[2] = modified[2];
        dst.speed[3] = (modified[3] + 0.5f * modified[2]) / 1.5f;
        dst.speed[4] = modified[3];
        GetPaseRatio(source.tactics, ratio);
        for (int j = 0; j < 5; ++j) {
            dst.accel[j] = modified[0] * ratio[j] / (10.0f * GetRaceDivisionLength(j));
        }
        dst.power = modified[4];
        dst.aggression = modified[5];
        RndFishParam(&dst);
        dst.velocity = GetRandomNumber(0.02f, 0.02f);
        if (dst.velocity < 0.0f) dst.velocity = 0.0f;
        dst.lane = source.lane;
        dst.state = GR_RACE_STATE_SWIM;
        dst.progress_num = info->step_max;
        dst.progress = info->progress[i];
        memset(dst.progress, 0, info->step_max * sizeof(grRACE_PROGRESS));
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", SetRaceFishParam__FP15RACE_FISH_PARAMP11grRACE_INFO);
#endif
grFISH_DATA *GetFishData(int fish_no) {
    for (int fish_index = 0; fish_index < 18; ++fish_index) {
        if (fish_data[fish_index].fish_no == fish_no) {
            return &fish_data[fish_index];
        }
    }
    return NULL;
}

#ifdef NONMATCHING
void irn55() {
    for (int index = 1; index < 25; ++index) {
        int value = ia[index] - ia[index + 31];
        if (value < 0) {
            value += 1000000000;
        }
        ia[index] = value;
    }
    for (int index = 25; index < 56; ++index) {
        int value = ia[index] - ia[index - 24];
        if (value < 0) {
            value += 1000000000;
        }
        ia[index] = value;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", irn55__Fv);
#endif

#ifdef NONMATCHING
void init_rnd(unsigned int seed) {
    for (int index = 0; index < 56; ++index) {
        ia[index] = 0;
    }
    ia[55] = seed;
    int next = 1;
    for (int index = 1, slot = 21; index < 55; ++index, slot += 21) {
        slot %= 55;
        ia[slot] = next;
        next = seed - next;
        if (next < 0) {
            next += 1000000000;
        }
        seed = ia[slot];
    }
    irn55();
    irn55();
    irn55();
    jrand = 55;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", init_rnd__FUi);
#endif

#ifdef NONMATCHING
int irnd() {
    ++jrand;
    if (jrand >= 56) {
        irn55();
        jrand = 1;
    }
    return ia[jrand];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", irnd__Fv);
#endif
int irnd();
static float rnd() {
    return (float)irnd() / 1000000000.0f;
}
#ifdef NONMATCHING
static float nrnd() {
    float total = 0.0f;
    for (int sample = 0; sample < 12; ++sample) {
        total += rnd();
    }
    return total - 6.0f;
}
static float GetRandomNumber(float mean, float range) {
    return mean + nrnd() * (range / 3.0f);
}
int rand_prob(int percent) {
    return ((irnd() >> 12) % 100) < percent;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", nrnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetRandomNumber__Fff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", rand_prob__Fi);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyoracesim", fish_data__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyoracesim", at_1059__3__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyoracesim", at_483__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(jrand, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(ia, 0xE0);
