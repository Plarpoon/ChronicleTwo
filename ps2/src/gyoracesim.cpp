#include "common.h"
#include "gyoracesim.hpp"

extern grFISH_DATA fish_data[18];
extern int ia[56];
extern int jrand;


// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", grGyoRaceSimulate__FP11grRACE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", grGetFishProgress__FP11grRACE_INFOifP15grRACE_PROGRESS);
float FishDist(RACE_FISH_PARAM *fish, RACE_FISH_PARAM *other) {
    return (fish->pos + fish->velocity) - (other->pos + other->velocity);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", StepFish__FiP15RACE_FISH_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", LaneBattleStep__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", CollisionFish__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", StepGyoRace__FP15RACE_FISH_PARAMP11grRACE_INFO);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", FishModifyParam__FP12grFISH_PARAMPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", CharacterBonus__FP12grFISH_PARAMP15RACE_FISH_PARAMi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", RndFishParam__FP15RACE_FISH_PARAM);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", SetRaceFishParam__FP15RACE_FISH_PARAMP11grRACE_INFO);
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
