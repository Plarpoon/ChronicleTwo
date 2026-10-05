#include "common.h"
#include "gyoracesim.hpp"

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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetRaceDivisionLength__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetCourseR__Fff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", FishModifyParam__FP12grFISH_PARAMPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", CharacterBonus__FP12grFISH_PARAMP15RACE_FISH_PARAMi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", RndFishParam__FP15RACE_FISH_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetPaseRatio__FiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", SetRaceFishParam__FP15RACE_FISH_PARAMP11grRACE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetFishData__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", irn55__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", init_rnd__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", irnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", rnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", nrnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", GetRandomNumber__Fff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", rand_prob__Fi);

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
