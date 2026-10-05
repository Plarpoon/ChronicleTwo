#include "common.h"
#include "savedata.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", InitSV_CONFIG_OPTION__FP16SV_CONFIG_OPTION);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", Initialize__9CSaveDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", CheckBitFlagNo__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SetBitFlag__9CSaveDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetBitFlag__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SetShortFlag__9CSaveDataFis);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetShortFlag__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SetBuildPartsNum__9CSaveDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetBuildPartsNum__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", AddBuildPartsNum__9CSaveDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetEditData__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetPlaceEditPartsNum__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetMapFlag__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", InitBitCtrl__9CSaveDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SetBitCtrl__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", ResetBitCtrl__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetBitCtrl__9CSaveDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetItem__9CSaveDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", ForceBootTour__9CSaveDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", CheckEventDay__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", CheckTourBoot__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", CheckNowTourEvent__9CSaveDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", CheckNowTourType__9CSaveDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", AddTourCountEtc__9CSaveDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetTourCountEtc__9CSaveDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", FinishTour__9CSaveDataFv);
void CSphidaData::Initialize(void) {
    memset(this, 0, 6216);
}
void CSphidaData::SetHorl(s32 arg0) {
    (*(s16 *)((u8 *)this + 0x1478)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SetHorlScore__11CSphidaDataFii);
s16 CSphidaData::GetNowHorl(void) {
    return (*(s16 *)((u8 *)this + 0x1478));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetHorlScore__11CSphidaDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", ClearPlayerScore__11CSphidaDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", EnterScore__11CSphidaDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetPlayerData__11CSphidaDataFi);
void CSphidaData::InitPlay(void) {
    *(s16 *) ((u8 *) this + 0x1478) = 0;
    memset((u8 *) this + 0x1448, 0, 0x30);
    memset((u8 *) this + 0x147C, 0, 0x1C);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", IsUsed__12GYORACE_DATAFv);
void GYORACE_DATA::Init(void) {
    memset(this, 0, 0xA0);
}
void CGyoRaceData::Initialize(void) {
    memset(this, 0, 0x2C28);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SearchSpace__12CGyoRaceDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", SearchSpaceData__12CGyoRaceDataFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetData__12CGyoRaceDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", __ct__12CSubGameDataFv);
void CSubGameData::Initialize(void) {
    memset(this, 0, 21616);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", PlayEnable__12CSubGameDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetSphidaData__12CSubGameDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/savedata", GetGyoRaceData__12CSubGameDataFv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/savedata", at_453__DATA);
