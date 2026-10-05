#include "common.h"
#include "villagermngr.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Init__Q214CVillagerPlace12ProgressInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Initialize__13CVillagerDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Add__18CVillagerPlaceInfoFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Initialize__13CVillagerMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", GetData__13CVillagerMngrFi);
void CVillagerMngr::Stay(s32 arg0) {
    struct temp_v0_champs_681136 *temp_v0;

    temp_v0 = (struct temp_v0_champs_681136 *) (this->GetData(arg0));
    if (temp_v0 != NULL) {
        (*(s32 *)((u8 *)temp_v0 + 0x2c)) = (s32) ((*(s32 *)((u8 *)temp_v0 + 0x2c)) + 1);
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", CancelStay__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", ExMode__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", SearchDataIDatCharaID__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Register__13CVillagerMngrFiiP18CVillagerPlaceInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", DeleteCharaID__13CVillagerMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", NewData__13CVillagerMngrFv);
s32 CVillagerMngr::CheckStay(s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (this->GetData(arg0));
    if (temp_v0 == NULL) {
        return 0;
    }
    if ((*(s32 *)((u8 *)temp_v0 + 0x20)) != 0) {
        return 0;
    }
    if ((*(s32 *)((u8 *)this + 0x0)) != 0) {
        return 1;
    }
    return (*(s32 *)((u8 *)temp_v0 + 0x2c));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", Step__13CVillagerMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", GetAppearVlgr__13CVillagerMngrFiiiPiPP18CVillagerPlaceInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/villagermngr", GetTalkRect__13CVillagerMngrFiPf);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/villagermngr", at_513__DATA);
