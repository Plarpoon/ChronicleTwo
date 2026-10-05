#include "common.h"
#include "villagermngr.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Init__Q214CVillagerPlace12ProgressInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Initialize__13CVillagerDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Add__18CVillagerPlaceInfoFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Initialize__13CVillagerMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", GetData__13CVillagerMngrFi);
void CVillagerMngr::Stay(s32 chara_id) {
    CVillagerData *villager = GetData(chara_id);
    if (villager != NULL) {
        villager->stay++;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", CancelStay__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", ExMode__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", SearchDataIDatCharaID__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Register__13CVillagerMngrFiiP18CVillagerPlaceInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", DeleteCharaID__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", NewData__13CVillagerMngrFv);
s32 CVillagerMngr::CheckStay(s32 chara_id) {
    CVillagerData *villager = GetData(chara_id);
    if (villager == NULL) {
        return 0;
    }
    if (villager->ex_mode != 0) {
        return 0;
    }
    if (stop != 0) {
        return 1;
    }
    return villager->stay;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Step__13CVillagerMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", GetAppearVlgr__13CVillagerMngrFiiiPiPP18CVillagerPlaceInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", GetTalkRect__13CVillagerMngrFiPf);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/villagermngr", at_513__DATA);
