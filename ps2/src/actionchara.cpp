#include "common.h"
#include "actionchara.hpp"

// Code (.text)
void CActionChara::ResetAccele(void) {
    accele.accele[2] = 0;
    accele.accele[1] = 0;
    accele.accele[0] = 0;
    accele.speed = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", ResetAction__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", ResetScript__12CActionCharaFv);
s32 CActionChara::CheckRunEvent(void) {
    s32 can_run = menu_flag;
    if (hold_type != 0) {
        can_run = 0;
    }
    return can_run;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetMaskFlag__12CActionCharaFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", EntryObject__12CActionCharaFPci);
void CActionChara::CalcCollision(void) {
    ACTION_OBJECT *entry = object;
    s32 index = 0;
    do {
        mgCFrame *frame = entry->frame;
        if (frame != NULL) {
            frame->GetWorldPosition0(entry->pos);
        }
        index += 1;
        entry += 1;
    } while (index < 8);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", EntryBodyCol__12CActionCharaFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", EntryDamage2__12CActionCharaFPcPcPcfPcffPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", EntryDamage2__12CActionCharaFP8mgCFrameP8mgCFramePcfPcffPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", AllDeleteDamage__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetSwEffectPtr__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetSoundInfoCopy__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetFadeFlag__12CActionCharaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetFarDist__12CActionCharaFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetNearDist__12CActionCharaFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetCameraDist__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", Show__12CActionCharaFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetShow__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckKeri__12CActionCharaFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckEnemyCatch__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", ThrowItemObject__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", UsedItemAction__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", EntryThrowItem__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RemoveThrowItem__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetNowFrameWait__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetNowFrame__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckMotionEnd__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetMotionStatus__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetWaitToFrame__12CActionCharaFPcfPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetMotion__12CActionCharaFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetMotion__12CActionCharaFPcii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", ResetMotion__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", Draw__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", DrawDirect__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", DrawShadowDirect__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", DrawEffect__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", StepEffect__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SearchChara__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SearchObject__12CActionCharaFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", ResetParent__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetRef__12CActionCharaFP12CActionCharaPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GetTargetDist__12CActionCharaFP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RockOn_TargetSel__FP6CScenei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", DistCheck_Action2__FP6CSceneffPfiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", Check_LockOn__FP6CScenefi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CollisionCheck__12CActionCharaFPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RockOn__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", HumanMoveIF__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", HumanShrowMoveIF__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", HumanTameMoveIF__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", HumanGunMoveIF__12CActionCharaFPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RoboWalkMoveIF__12CActionCharaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RoboTankMoveIF__12CActionCharaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RoboBikeMoveIF__12CActionCharaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RoboAirMoveIF__12CActionCharaFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", MonsterMoveIF__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", GuardEffectSet__FP6CScenePf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", HitEffectSet__FP6CScenePf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckAmuletAvoid__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckEquipSetItem__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckDamage__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", LoadActionFile__12CActionCharaFPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", InitScript__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", SetHold__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", RunScript__12CActionCharaFP6CSceneP14RUN_SCRIPT_ENV);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", CheckReleaseTimming__12CActionCharaFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", StepParam__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", Step__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", ShadowStep__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", Initialize__12CActionCharaFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", Copy__12CActionCharaFR12CActionCharaP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/actionchara", __as__11CCharacter2FRC11CCharacter2);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1398__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2048__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2543__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2586__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2720__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2818__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2846__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_3289__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_3291__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1325__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1357__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1358__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1394__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1427__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_1428__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2209__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2210__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2211__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2212__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2213__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2214__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2215__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2216__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2217__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2294__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2295__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2333__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2334__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2420__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2421__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2422__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2423__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2504__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2505__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2506__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2507__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2508__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2509__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2510__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2629__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2630__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2631__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2632__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2633__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2634__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2713__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2714__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_2840__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_3085__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_3262__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_3263__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", at_3389__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/actionchara", __vt__12CActionChara__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(old_angle, 0x4);
INCLUDE_BSS(ang_3371, 0x4);
INCLUDE_BSS(init_3372, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_3107, 0x10);
