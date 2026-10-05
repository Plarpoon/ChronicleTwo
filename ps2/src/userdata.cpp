#include "common.h"
#include "userdata.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetUserDataMan__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetFishTournament__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAquariumData__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckFill__11COMMON_GAGEFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRate__11COMMON_GAGEFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetFillRate__11COMMON_GAGEFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddPoint__11COMMON_GAGEFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddRate__11COMMON_GAGEFf);
float GetCommonGageRate(COMMON_GAGE *arg0) {
    if (arg0 != NULL) return arg0->GetRate();
    return 0.0f;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CalcBreedFishParam__FP14BREEDFISH_USED);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetFishingGamePreEquip__FP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", ReEquipFishingGameWeapon__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckFishingWeapon__FP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GameDataSwap__FP13CGameDataUsedP13CGameDataUsedi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckNowRoboUseCapacity__FP9ROBO_DATAPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", __ct__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Init__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckTypeEnableStack__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetDataPath__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsWhoEquip__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetLevel__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetPalletColor__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetSpectolNo__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckStackRemain__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNum__13CGameDataUsedFv);
u8 CGameDataUsed::GetActiveSetNum(void) {
    return this->IsActiveSet();
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddNum__13CGameDataUsedFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetUseCapacity__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddFishHp__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Boiled__13CGameDataUsedFv);
u8 CGameDataUsed::IsActiveSet(void) {
    struct temp_v0_champs_3a34f9 *temp_v0;

    temp_v0 = (struct temp_v0_champs_3a34f9 *) (GetCommonItemData((s32) (*(s16 *)((u8 *)this + 0x2))));
    if (temp_v0 != NULL) {
        return (*(s32 *)((u8 *)temp_v0 + 0x1c));
    }
    return 0U;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetName__13CGameDataUsedFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetName__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", TransToPassword__13CGameDataUsedFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", TransToData__13CGameDataUsedFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DeleteNum__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", RemainFusion__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddFusionPoint__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetEffectReadType__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMsgAddInfo__13CGameDataUsedFPPcPPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetWHp__13CGameDataUsedFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsRepair__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Repair__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetEnableRepairItemNo__13CGameDataUsedFv);
s32 CGameDataUsed::IsEnableUseRepair(s32 arg0) {
    return arg0 == this->GetEnableRepairItemNo();
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboInfoType__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboJointName__13CGameDataUsedFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboSoundFileName__13CGameDataUsedFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsBroken__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsLevelUp__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LevelUp__13CGameDataUsedFv);
s32 CGameDataUsed::IsTrush(void) {
    s32 var_s0;
    s32 var_v0;
    struct temp_v0_champs *temp_v0;

    var_s0 = 0;
    temp_v0 = (struct temp_v0_champs *) (GetCommonItemData((s32) (*(s16 *)((u8 *)this + 0x2))));
    if ((temp_v0 != NULL) && ((*(s32 *)((u8 *)temp_v0 + 0x24)) & 1)) {
        var_s0 = 1;
    }
    var_v0 = var_s0;
    if ((*(s16 *)((u8 *)this + 0x0)) == 6) {
        if ((*(u16 *)((u8 *)this + 0x48)) & 2) {
            var_s0 = 0;
        }
        var_v0 = var_s0;
    }
    return var_v0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsSpectolTrans__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", ToSpectolTrans__13CGameDataUsedFP13CGameDataUsedi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetStatusParam__13CGameDataUsedFPs);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetStatusParam__13CGameDataUsedFPsf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsBuildUp__13CGameDataUsedFPiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsFishingRod__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetActiveElem__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAttackType__13CGameDataUsedFv);
s8 CGameDataUsed::GetModelNo(void) {
    struct temp_v0_champs_54f1f6 *temp_v0;

    if ((*(s16 *)((u8 *)this + 0x0)) == 3) {
        temp_v0 = (struct temp_v0_champs_54f1f6 *) (GetWeaponInfoData((s32) (*(s16 *)((u8 *)this + 0x2))));
        if (temp_v0 != NULL) {
            return (*(s8 *)((u8 *)temp_v0 + 0x49));
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMainCharaModelName__FiPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckParamLimmit__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", TimeCheck__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetGiftBoxItemNum__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetGiftBoxItem__13CGameDataUsedFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetGiftBoxItemNo__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetGiftBoxSameItemNum__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyGameData__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyDataWeapon__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyDataAttach__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyDataItem__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyDataFish__13CGameDataUsedFi);
s32 CGameDataUsed::CopyDataGiftBox(s32 arg0) {
    if (GetItemInfoData(arg0) == 0) {
        return 0;
    }
    (*(s16 *)((u8 *)this + 0x0)) = 7;
    (*(s16 *)((u8 *)this + 0x2)) = (s16) arg0;
    (*(s8 *)((u8 *)this + 0x4)) = GetItemDataType(arg0);
    (*(s16 *)((u8 *)this + 0x14)) = 0;
    (*(s16 *)((u8 *)this + 0x12)) = 0;
    (*(s16 *)((u8 *)this + 0x10)) = 0;
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyDataItem__13CGameDataUsedFP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyDataRoboPart__13CGameDataUsedFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Initialize__13CFishAquariumFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAquariumFishTop__13CFishAquariumFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchAqua1NotUsed__13CFishAquariumFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", FishIntoAquarium__13CFishAquariumFiiP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAquariumFishNum__13CFishAquariumFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckHaigouTankSex__13CFishAquariumFP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", RefreshParam__13CFishAquariumFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetShiledKitLimmit__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddPoint__9ROBO_DATAFf);
s32 ROBO_DATA::GetDefenceVol(void) {
    return *(s16 *) ((u8 *) this + 0xD0) + (*(u16 *) ((u8 *) this + 0x1E8) << 2);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterBaseInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterHengeParam__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAttackVol__16MOS_CHANGE_PARAMFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetDefenceVol__16MOS_CHANGE_PARAMFi);
s32 MOS_CHANGE_PARAM::CheckClassChange(void) {
    s16 temp_a1;

    temp_a1 = (*(s16 *)((u8 *)this + 0x4));
    if (temp_a1 >= 3) {
        return 0;
    }
    return temp_a1 < (*(s16 *)((u8 *)this + 0x2)) / 25;
}
s32 MOS_CHANGE_PARAM::GetDegreeLevel(void) {
    s32 var_v0;

    var_v0 = (*(s16 *)((u8 *)this + 0x2)) / 6;
    if (var_v0 > 0xF) {
        var_v0 = 0xF;
    }
    return var_v0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LevelUp__16MOS_CHANGE_PARAMFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Initialize__11CMonsterBoxFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterBajjiData__11CMonsterBoxFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterBajjiDataByMonsterID__11CMonsterBoxFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EnableChange__11CMonsterBoxFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsChange__11CMonsterBoxFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AllCure__11CMonsterBoxFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetConvertIndexFromFishNo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", __ct__14CFishingRecordFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetFishRecord__14CFishingRecordFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckRecordFish__14CFishingRecordFiff);
void CFishingTournament::Initialize(void) {
    memset(this, 0, 112);
}
void CFishingTournament::ResetRecord(void) {
    memset(&(*(s32 *)((u8 *)this + 0x20)), 0, 80);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EntryFish__18CFishingTournamentFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EntryRemain__18CFishingTournamentFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRecord__18CFishingTournamentFi);
void CFishingTournament::SetRank(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 0x64) {
        arg0 = 0x64;
    }
    (*(s16 *)((u8 *)this + 0x4)) = (s16) arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SortRecord__18CFishingTournamentFv);
s32 CFishingTournament::CalcTopWeight(void) {
    this->SortRecord();
    return (*(s16 *)((u8 *)this + 0x34)) + ((*(s16 *)((u8 *)this + 0x24)) + (*(s16 *)((u8 *)this + 0x2c)));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Initialize__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", RefreshParam__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetUsedDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCharaDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCharaHpGage__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddHp__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetHp__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddHp_Rate__16CUserDataManagerFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetWHpGage__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAbsGage__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddWhp__16CUserDataManagerFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetWhp__16CUserDataManagerFiiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddAbs__16CUserDataManagerFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAbs__16CUserDataManagerFiiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", JoinPartyMember__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LeavePartyMember__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowPartyMember__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EnableCharaChange__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DisableCharaChange__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckEnableCharaChange__16CUserDataManagerFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckQuickChange__16CUserDataManagerFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EnableCharaChangeMask__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DisableCharaChangeMask__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", InitCharaChangeMask__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetEnableCharaChangeFlag__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCharaStatusAttirbutePtr__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetCharaStatusAttirbute__16CUserDataManagerFiUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetCharaStatusAttirbuteVol__16CUserDataManagerFiUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCharaStatusAttirbute__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterBajjiDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterBajjiDataPtrMosId__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetItemBoardOverNum__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetItemBoardMaxNum__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetActiveChrNo__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetRoboName__16CUserDataManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboName__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboNameDefault__16CUserDataManagerFv);
void CUserDataManager::SetVoiceUnit(s32 arg0) {
    (*(s8 *)((u8 *)this + 0x467c)) = (s8) arg0;
    if (arg0 != 0) {
        this->SetRoboVoiceFlag(1);
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckVoiceUnit__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetRoboVoiceFlag__16CUserDataManagerFi);
s32 CUserDataManager::CheckRoboVoiceFlag(void) {
    s32 var_v0;

    var_v0 = (*(s8 *)((u8 *)this + 0x467c)) != 0;
    if (var_v0 != 0) {
        var_v0 = (*(s8 *)((u8 *)this + 0x467d)) != 0;
    }
    return var_v0 & 0xFF;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddRoboAbs__16CUserDataManagerFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboAbs__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckCapacity__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckRobotCore__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetDefenceVol__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", JoinPartyChara__16CUserDataManagerFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetPartyCharaStatus__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetPartyCharaStatus__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", NowPartyCharaID__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LeaveHouse__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetPartyCharaInfo__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", UseNpcAbility__16CUserDataManagerFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AllWeaponRepair__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", RefreshNPCStatus__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetFishingRodNo__16CUserDataManagerFv);
s32 CUserDataManager::NowFishingStyle(void) {
    CGameDataUsed *temp_a0;

    temp_a0 = (CGameDataUsed *) (&(*(s32 *)((u8 *)this + 0x40b8)));
    if (temp_a0 != NULL) {
        return temp_a0->IsFishingRod();
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetActiveEsa__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetActiveEsa__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetFishBait__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DeleteBait__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetFishInAquarium__16CUserDataManagerFiff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckFishRecordUpdate__16CUserDataManagerFiff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetFishRecord__16CUserDataManagerFiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRodStatus__16CUserDataManagerFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddFp__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetChrEquip__16CUserDataManagerFiP13CGameDataUsed);
s32 CUserDataManager::SetChrEquip(s32 arg0, s32 arg1) {
    CGameDataUsed *temp_v0;

    if (arg1 <= 0) {
        return 0;
    }
    if ((arg0 < 0) || (arg0 > 2)) {
        return 0;
    }
    if (this->SearchEquip(arg0, arg1) != 0) {
        return 0;
    }
    temp_v0 = (CGameDataUsed *) (this->SearchItemOnItemBrd(arg1, 1));
    if (temp_v0 == NULL) {
        return 0;
    }
    this->SetChrEquip(arg0, temp_v0);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetChrEquipDirect__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchEquip__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCharaEquipDataPath__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddFusionPoint__16CUserDataManagerFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchSpaceUsedData__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchSpaceUsedData__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchSpaceUsedDataPtr__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchSpaceUsedDataPtr__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchActiveItemTableSpace__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchItemOnItemBrd__16CUserDataManagerFii);
s32 CUserDataManager::GetNumStackOverBoard(void) {
    s32 var_s0;
    u8 *var_s1;
    s32 var_s2;

    var_s0 = 0;
    var_s1 = (u8 *) (this->GetUsedDataPtr(GetNowBagMax(0)));
    for (var_s2 = 0; var_s2 < this->GetItemBoardOverNum(); var_s2++, var_s1 += 0x6C) {
        if ((*(s16 *)((u8 *)var_s1 + 0x2)) > 1) {
            var_s0 += 1;
        }
    }
    return var_s0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchAllHaveItem__16CUserDataManagerFi);
s32 CUserDataManager::FishInAquarium(CGameDataUsed *arg0, s32 arg1) {
    CFishAquarium *temp_s0;
    s32 temp_v0;

    temp_s0 = (CFishAquarium *) (&(*(CFishAquarium *)((u8 *)this + 0x4958)));
    if ((arg1 < 0) || (arg1 > 2)) {
        return 0;
    }
    temp_v0 = (s32) (temp_s0->SearchAqua1NotUsed(0));
    if ((temp_v0 < 0) || (arg0 == NULL)) {
        return 0;
    }
    temp_s0->FishIntoAquarium(arg1, temp_v0, arg0);
    arg0->Init();
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckElectricFish__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNumSameItem__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddYarikomiMedal__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetYarikomiMedal__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetItem__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetItemNotOver__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetOverItem__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckItemLimmitOver__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DeleteItem_Local__FP13CGameDataUsedii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DeleteItem__16CUserDataManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CopyGameData__16CUserDataManagerFP13CGameDataUsedi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddMoney__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetCostumeBit__16CUserDataManagerFUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCostumeBit__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCostume__16CUserDataManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CountFish__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetEnvUserDataMan__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetCharaDefaultWeapon__FiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LanguageEquipChange__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckEquipChange__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Initialize__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetEquipTablePtr__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetChrNo__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterID__16CBattleCharaInfoFv);
s16 CBattleCharaInfo::GetNowNPC(void) {
    return (*(s16 *)((u8 *)this + 0x4));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", UseNPCPoint__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetActiveItemInfo__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", UseActiveItem__16CBattleCharaInfoFP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetSpecialStatus__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetPalletNo__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", RefreshParamater__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowAccessWHp__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowAccessAbs__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddWhp__16CBattleCharaInfoFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowWhp__16CBattleCharaInfoFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetWhpNowVol__16CBattleCharaInfoFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetMagicSwordPow__16CBattleCharaInfoFii);
s16 CBattleCharaInfo::GetMagicSwordElem(void) {
    s16 var_v0;

    var_v0 = -1;
    if (!((*(s16 *)((u8 *)this + 0x0)) == 1)) {
        return var_v0;
    }
    var_v0 = (*(s16 *)((u8 *)this + 0x18));

    return var_v0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMagicSwordPow__16CBattleCharaInfoFv);
s16 CBattleCharaInfo::GetMagicSwordCounterNow(void) {
    if ((*(s16 *)((u8 *)this + 0x0)) != 1) {
        return 0;
    }
    return (*(s16 *)((u8 *)this + 0x1a));
}
s32 CBattleCharaInfo::GetMagicSwordCounterMax(void) {
    s16 temp_v0;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    struct temp_a1_champs_334560 *temp_a1;

    temp_a1 = (struct temp_a1_champs_334560 *) ((*(s32 *)((u8 *)this + 0x30)));
    if (temp_a1 == NULL) {
        return 0;
    }
    if ((*(s16 *)((u8 *)this + 0x0)) != 1) {
        return 0;
    }
    if (temp_a1 == NULL) {
        return 0;
    }
    temp_v0 = (s16) ((*(s32 *)((u8 *)temp_a1 + 0x24)));
    temp_v1 = temp_v0 - 0x20;
    if (temp_v0 < 0x20) {
        return 0;
    }
    var_v0_2 = temp_v1 >> 4;
    if (temp_v1 < 0) {
        var_v0_2 = (s32) (temp_v1 + 0xF) >> 4;
    }
    var_v0 = var_v0_2 + 3;
    if (var_v0 > 7) {
        var_v0 = 7;
    }
    return var_v0;
}
void CBattleCharaInfo::ClearMagicSwordPow(void) {
    (*(s16 *)((u8 *)this + 0x18)) = -1;
    (*(s16 *)((u8 *)this + 0x1a)) = 0;
    (*(s16 *)((u8 *)this + 0x1c)) = 0;
    (*(s16 *)((u8 *)this + 0x1e)) = 0;
    (*(s16 *)((u8 *)this + 0x20)) = 0;
    (*(s16 *)((u8 *)this + 0x22)) = 0;
    (*(s16 *)((u8 *)this + 0x24)) = 0;
    (*(s16 *)((u8 *)this + 0x26)) = 0;
    (*(s16 *)((u8 *)this + 0x28)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddAbs__16CBattleCharaInfoFifPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddAbsRate__16CBattleCharaInfoFifPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowAbs__16CBattleCharaInfoFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LevelUpWeapon__16CBattleCharaInfoFP13CGameDataUsed);
s16 CBattleCharaInfo::GetDefenceVol(void) {
    return (*(s16 *)((u8 *)this + 0x6c));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddHp_Point__16CBattleCharaInfoFff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddHp_Rate__16CBattleCharaInfoFfif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetHpRate__16CBattleCharaInfoFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMaxHp_i__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowHp_i__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetAttr__16CBattleCharaInfoFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetAttrVol__16CBattleCharaInfoFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAttr__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", ForceSet__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRandomCircleTrapID__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetRandamCircleStatus__FiRf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", StatusParamStep__16CBattleCharaInfoFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", Step__16CBattleCharaInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetBattleCharaInfo__Fv);
void ConvertItemAttrToCharaAttr(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_v1;
    s32 var_a3;

    var_v1 = 0;
    var_a3 = 0;
    if (arg0 & 0x10000) {
        var_v1 |= 1;
    }
    if (arg0 & 0x100000) {
        var_v1 |= 2;
    }
    if (arg0 & 0x40000) {
        var_v1 |= 4;
    }
    if (arg0 & 0x4000) {
        var_v1 |= 8;
    }
    if (arg0 & 0x400000) {
        var_v1 |= 0x10;
    }
    if (arg0 & 0x02000000) {
        var_v1 |= 0x20;
    }
    if (arg0 & 0x08000000) {
        var_v1 |= 0x40;
    }
    if (arg0 & 0x20000) {
        var_a3 |= 1;
    }
    if (arg0 & 0x200000) {
        var_a3 |= 2;
    }
    if (arg0 & 0x80000) {
        var_a3 |= 4;
    }
    if (arg0 & 0x8000) {
        var_a3 |= 8;
    }
    if (arg0 & 0x04000000) {
        var_a3 |= 0x20;
    }
    if (arg0 & 0x10000000) {
        var_a3 |= 0x40;
    }
    if (arg1 != NULL) {
        *arg1 = var_v1;
    }
    if (arg2 != NULL) {
        *arg2 = var_a3;
    }
}
s32 CheckBadStatus(s32 arg0) {
    if ((arg0 & 1) || (arg0 & 2) || (arg0 & 4) || (arg0 & 8) || (arg0 & 0x20) || (arg0 & 0x40)) {
        return 1;
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckWeaponAttribute__FUiUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckBuildUpMonsterCondition__FP11CDataWeapon);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", KillMonsterCount__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchEquipType__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsItemtypeWhoisEquip__FiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsCheckParty__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAquariumFish0__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetUserItemHaveNum__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckItemOver__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckItemLimmitOver__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckGetItemLimmitOver__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckGetItemRemainNum__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckItemDngKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", PlayerPartyCure__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", UserDataRefresh__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DeleteErekiFish__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowBagMax__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LeaveMonicaItemCheck__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AquaFishFatigueClear__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", DebugGetItem__FP16CUserDataManageri);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", __sinit_userdata_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", mos_henge_param__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", basefish_1288__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", symbol_tbl_1338__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", magic_str_1462__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", strtbl_1505__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", htbl_1662__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", fish_record_dataindex_convert__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_3192__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", robo_nametable_3330__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_4196__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", weptbl_4503__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_table_5400__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", equip_type_tbl_5456__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", cureItemtable_5744__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", itemtbl_5745__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", start_tbl_5746__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", e3_town_5747__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", e3_dng_5748__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", e3_boss_5749__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", init_partytbl_5752__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", dbg_set2_5775__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", dbg_set3_5776__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", subgame1_5788__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_896__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_897__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_898__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_899__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_900__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_901__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_902__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_903__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_904__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_905__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_906__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_907__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_908__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_909__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_910__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_911__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_912__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_913__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_914__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_915__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_916__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_917__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_918__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_919__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_920__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_921__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_922__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_923__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_924__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_925__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_926__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_927__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_928__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_929__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_930__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_931__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_932__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_933__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_934__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_935__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_936__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_937__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_938__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_939__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_940__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_941__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1289__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1290__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1291__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1292__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1293__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1294__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1295__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1339__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1340__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1341__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1342__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1343__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1344__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1378__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1379__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1463__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1464__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1465__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1466__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1467__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1468__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1469__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1470__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1506__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1507__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1623__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1624__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_1637__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_2006__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_2007__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_2018__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_2019__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_3331__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_3332__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_3333__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_3334__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_4442__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", D_0037B004__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", f_2005__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", aquarium_fish_maxtbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", use_limmit_table_2558__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", lifetbl_2854__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", at_4695__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", tbl1_5167__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", tbl2_5168__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/userdata", dbg_set1_5774__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(FishGamePreEquip, 0x4);
INCLUDE_BSS(BattleParamater_Time, 0x4);
INCLUDE_BSS(BattleParamater_TimeBand, 0x4);
INCLUDE_BSS(at_5773, 0x8);

// Uninitialised data (.bss)
INCLUDE_BSS(word_1327, 0x70);
INCLUDE_BSS(temp_1510, 0x40);
INCLUDE_BSS(at_2061, 0x20);
INCLUDE_BSS(BattleParamater, 0x90);
