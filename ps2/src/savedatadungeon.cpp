#include "common.h"
#include "savedatadungeon.hpp"
#include <cstdio>
#include <cstring>

extern short limmit_table[];
extern const char at_79[];

// Code (.text)
#ifdef NONMATCHING
DNG_FLOOR_SAVE *CSaveDataDungeon::GetFloorInfoPtr(int stage, int floor) {
    if (stage < 0 || stage >= SAVE_DUNGEON_NUM || floor < 0 || floor >= limmit_table[stage]) {
        return 0;
    }

    int offset = 0;
    for (int i = 0; i < stage; i++) {
        offset += limmit_table[i];
    }
    return &floor_info[offset + floor];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedatadungeon", GetFloorInfoPtr__16CSaveDataDungeonFii);
#endif

#ifdef NONMATCHING
void CSaveDataDungeon::Initialize() {
    memset(floor_info, 0, sizeof(floor_info));
    for (int stage = 0; stage < SAVE_DUNGEON_NUM; stage++) {
        DNG_FLOOR_SAVE *first = GetFloorInfoPtr(stage, 0);
        if (first != 0) {
            first->visit_count = 1;
            first->flag = DNG_FLOOR_FLAG_OPEN | DNG_FLOOR_FLAG_UNK_2;
        }
        DNG_FLOOR_SAVE *second = GetFloorInfoPtr(stage, 1);
        if (second != 0) {
            second->flag = DNG_FLOOR_FLAG_OPEN;
        }
    }
    for (int stage = 0; stage < SAVE_DUNGEON_NUM; stage++) {
        prev_floor_id[stage] = -1;
        floor_id[stage] = 1;
    }
    stage_id = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedatadungeon", Initialize__16CSaveDataDungeonFv);
#endif

void CSaveDataDungeon::SetFloorID(int floor) {
    prev_floor_id[stage_id] = floor_id[stage_id];
    floor_id[stage_id] = floor;
    printf(at_79, stage_id, prev_floor_id[stage_id], floor);
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/savedatadungeon", limmit_table__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/savedatadungeon", at_79__DATA);
