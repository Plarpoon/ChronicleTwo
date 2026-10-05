#include "common.h"
#include "gyoracesim.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", grGyoRaceSimulate__FP11grRACE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", grGetFishProgress__FP11grRACE_INFOifP15grRACE_PROGRESS);
float FishDist(RACE_FISH_PARAM *arg0, RACE_FISH_PARAM *arg1) {
    return ((*(float *)((u8 *)arg0 + 0x54)) + (*(float *)((u8 *)arg0 + 0x50))) - ((*(float *)((u8 *)arg1 + 0x54)) + (*(float *)((u8 *)arg1 + 0x50)));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", StepFish__FiP15RACE_FISH_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", LaneBattleStep__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", CollisionFish__FP15RACE_FISH_PARAMi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyoracesim", StepGyoRace__FP15RACE_FISH_PARAMP11grRACE_INFO);
s32 GetRaceDivision(float arg0) {
    s32 var_v0;

    if (arg0 < 2.0f) {
        return 0;
    }
    if (arg0 < 6.0f) {
        return 1;
    }
    if (arg0 < 10.0f) {
        return 2;
    }
    if (arg0 < 14.0f) {
        return 3;
    }
    var_v0 = -1;
    if (!(arg0 < 16.0f)) {
        return var_v0;
    }
    var_v0 = 4;

    return var_v0;
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
