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
float GetCommonGageRate(COMMON_GAGE *gage) {
    if (gage != NULL) return gage->GetRate();
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
    CDataCommon *item = GetCommonItemData(item_no);
    if (item != NULL) {
        return item->active_set;
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
s32 CGameDataUsed::IsEnableUseRepair(s32 item_no) {
    return item_no == GetEnableRepairItemNo();
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboInfoType__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboJointName__13CGameDataUsedFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRoboSoundFileName__13CGameDataUsedFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsBroken__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", IsLevelUp__13CGameDataUsedFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LevelUp__13CGameDataUsedFv);
s32 CGameDataUsed::IsTrush(void) {
    s32 is_rubbish = 0;
    CDataCommon *item = GetCommonItemData(item_no);
    if (item != NULL && (item->attribute & ITEM_ATTRIBUTE_TRUSH)) {
        is_rubbish = 1;
    }
    if (used_type == USED_ITEM_TYPE_FISH) {
        if (data.fish.flags & BREEDFISH_FLAG_ELECTRIC) {
            is_rubbish = 0;
        }
    }
    return is_rubbish;
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
    if (used_type == USED_ITEM_TYPE_WEAPON) {
        CDataWeapon *weapon = GetWeaponInfoData(item_no);
        if (weapon != NULL) {
            return weapon->model_no;
        }
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
s32 CGameDataUsed::CopyDataGiftBox(s32 item_no) {
    if (GetItemInfoData(item_no) == NULL) {
        return 0;
    }
    used_type = USED_ITEM_TYPE_GIFT_BOX;
    this->item_no = item_no;
    item_type = GetItemDataType(item_no);
    data.giftbox.item_no[2] = 0;
    data.giftbox.item_no[1] = 0;
    data.giftbox.item_no[0] = 0;
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
    return parts[1].data.robopart.defence + (shield_kit_num << 2);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterBaseInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMonsterHengeParam__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetAttackVol__16MOS_CHANGE_PARAMFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetDefenceVol__16MOS_CHANGE_PARAMFi);
s32 MOS_CHANGE_PARAM::CheckClassChange(void) {
    if (class_level >= 3) {
        return 0;
    }
    return class_level < level / 25;
}
s32 MOS_CHANGE_PARAM::GetDegreeLevel(void) {
    s32 degree = level / 6;
    if (degree > 15) {
        degree = 15;
    }
    return degree;
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
    memset(this, 0, sizeof(*this));
}
void CFishingTournament::ResetRecord(void) {
    memset(entry, 0, sizeof(entry));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EntryFish__18CFishingTournamentFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", EntryRemain__18CFishingTournamentFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetRecord__18CFishingTournamentFi);
void CFishingTournament::SetRank(s32 rank) {
    if (rank < 0) {
        rank = 0;
    }
    if (rank > 100) {
        rank = 100;
    }
    this->rank = rank;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SortRecord__18CFishingTournamentFv);
s32 CFishingTournament::CalcTopWeight(void) {
    this->SortRecord();
    return entry[2].weight + (entry[0].weight + entry[1].weight);
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
void CUserDataManager::SetVoiceUnit(s32 fitted) {
    robo_data.voice_unit = fitted;
    if (fitted != 0) {
        this->SetRoboVoiceFlag(1);
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", CheckVoiceUnit__16CUserDataManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SetRoboVoiceFlag__16CUserDataManagerFi);
s32 CUserDataManager::CheckRoboVoiceFlag(void) {
    s32 enabled = robo_data.voice_unit != 0;
    if (enabled != 0) {
        enabled = robo_data.voice_flag != 0;
    }
    return enabled & 0xFF;
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
    CGameDataUsed *rod = &chara_data[0].equip[0];
    if (rod != NULL) {
        return rod->IsFishingRod();
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
s32 CUserDataManager::SetChrEquip(s32 chara, s32 item_no) {
    CGameDataUsed *item;

    if (item_no <= 0) {
        return 0;
    }
    if ((chara < 0) || (chara > 2)) {
        return 0;
    }
    if (this->SearchEquip(chara, item_no) != 0) {
        return 0;
    }
    item = this->SearchItemOnItemBrd(item_no, 1);
    if (item == NULL) {
        return 0;
    }
    this->SetChrEquip(chara, item);
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
    s32 count = 0;
    CGameDataUsed *item = GetUsedDataPtr(GetNowBagMax(0));
    for (s32 index = 0; index < GetItemBoardOverNum(); index++, item++) {
        if (item->item_no > 1) {
            count += 1;
        }
    }
    return count;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", SearchAllHaveItem__16CUserDataManagerFi);
s32 CUserDataManager::FishInAquarium(CGameDataUsed *fish, s32 tank) {
    CFishAquarium *aquarium = &this->aquarium;
    if ((tank < 0) || (tank > 2)) {
        return 0;
    }
    s32 space = aquarium->SearchAqua1NotUsed(0);
    if ((space < 0) || (fish == NULL)) {
        return 0;
    }
    aquarium->FishIntoAquarium(tank, space, fish);
    fish->Init();
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
    return now_npc;
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
    s16 element = -1;
    if (!(chr_no == USER_CHARA_MONICA)) {
        return element;
    }
    element = magic_sword_elem;
    return element;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetMagicSwordPow__16CBattleCharaInfoFv);
s16 CBattleCharaInfo::GetMagicSwordCounterNow(void) {
    if (chr_no != USER_CHARA_MONICA) {
        return 0;
    }
    return magic_sword_num;
}
s32 CBattleCharaInfo::GetMagicSwordCounterMax(void) {
    CGameDataUsed *weapon = equip;
    if (weapon == NULL) {
        return 0;
    }
    if (chr_no != USER_CHARA_MONICA) {
        return 0;
    }
    if (weapon == NULL) {
        return 0;
    }
    s16 power = weapon->data.weapon.status[1];
    if (power < 32) {
        return 0;
    }
    s32 max_charges = (power - 32) / 16 + 3;
    if (max_charges > 7) {
        max_charges = 7;
    }
    return max_charges;
}
void CBattleCharaInfo::ClearMagicSwordPow(void) {
    magic_sword_elem = -1;
    magic_sword_num = 0;
    for (s32 i = 0; i < 7; i++) {
        magic_sword_pow[i] = 0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddAbs__16CBattleCharaInfoFifPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", AddAbsRate__16CBattleCharaInfoFifPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", GetNowAbs__16CBattleCharaInfoFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/userdata", LevelUpWeapon__16CBattleCharaInfoFP13CGameDataUsed);
s16 CBattleCharaInfo::GetDefenceVol(void) {
    return defence;
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
void ConvertItemAttrToCharaAttr(s32 attr, s32 *add, s32 *cure) {
    s32 add_attr = 0;
    s32 cure_attr = 0;
    if (attr & 0x10000) {
        add_attr |= CHARA_STATUS_POISON;
    }
    if (attr & 0x100000) {
        add_attr |= CHARA_STATUS_UNK_2;
    }
    if (attr & 0x40000) {
        add_attr |= CHARA_STATUS_UNK_4;
    }
    if (attr & 0x4000) {
        add_attr |= CHARA_STATUS_UNK_8;
    }
    if (attr & 0x400000) {
        add_attr |= CHARA_STATUS_POWER;
    }
    if (attr & 0x02000000) {
        add_attr |= CHARA_STATUS_UNK_20;
    }
    if (attr & 0x08000000) {
        add_attr |= CHARA_STATUS_UNK_40;
    }
    if (attr & 0x20000) {
        cure_attr |= CHARA_STATUS_POISON;
    }
    if (attr & 0x200000) {
        cure_attr |= CHARA_STATUS_UNK_2;
    }
    if (attr & 0x80000) {
        cure_attr |= CHARA_STATUS_UNK_4;
    }
    if (attr & 0x8000) {
        cure_attr |= CHARA_STATUS_UNK_8;
    }
    if (attr & 0x04000000) {
        cure_attr |= CHARA_STATUS_UNK_20;
    }
    if (attr & 0x10000000) {
        cure_attr |= CHARA_STATUS_UNK_40;
    }
    if (add != NULL) {
        *add = add_attr;
    }
    if (cure != NULL) {
        *cure = cure_attr;
    }
}
s32 CheckBadStatus(s32 attr) {
    if ((attr & CHARA_STATUS_POISON) || (attr & CHARA_STATUS_UNK_2) ||
        (attr & CHARA_STATUS_UNK_4) || (attr & CHARA_STATUS_UNK_8) ||
        (attr & CHARA_STATUS_UNK_20) || (attr & CHARA_STATUS_UNK_40)) {
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
