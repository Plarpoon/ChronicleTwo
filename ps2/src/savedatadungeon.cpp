#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedatadungeon", GetFloorInfoPtr__16CSaveDataDungeonFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedatadungeon", Initialize__16CSaveDataDungeonFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedatadungeon", SetFloorID__16CSaveDataDungeonFi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/savedatadungeon", limmit_table);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/savedatadungeon", at_79);
