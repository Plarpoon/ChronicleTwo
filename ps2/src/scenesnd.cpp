#include "common.h"
#include "scenesnd.hpp"
#include <cstring>
#include <cstdio>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", Init__Q26CScene8BGM_INFOFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitSnd__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitBGM__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitSeSrc__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitSeEnv__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitSeBattle__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitSeBas__6CSceneFv);
void CScene::SeAllStop(void) {
    this->StopSeSrc();
    sndSeAllStop(-1);
    this->InitLooSeMngr();
}
void CScene::SoundAllStop(void) {
    this->StopBGM(0);
    this->InitBGM();
    this->SeAllStop();
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", InitLooSeMngr__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetActiveBgmInfo__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", PlayBGM__6CSceneFiif);
void CScene::PauseBGM(void) {
    void *info = (void *)this->GetActiveBgmInfo();
    s32 status = *(s32 *)((char *)info + 0x20);
    if (status >= 0) sndSePause(*(u32 *)((char *)info + 4), status);
}
void CScene::RePlayBGM(void) {
    int *p = (int *)this->GetActiveBgmInfo();
    if (p[8] >= 0) sndSePlay(p[1], p[8], 0);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", StopBGM__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SetVolBGM__6CSceneFi);
int CScene::GetVolBGM(void) {
    return *(int *)((char *)this->GetActiveBgmInfo() + 0x10);
}
int CScene::GetBGMState(void) { void *p=(void *)this->GetActiveBgmInfo(); return sndGetSeStatus(*(unsigned int *)((char *)p+4), *(int *)((char *)p+0x20)); }
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SetVolfBGM__6CSceneFf);
float CScene::GetVolfBGM(void) {
    return *(float *)((char *)this->GetActiveBgmInfo() + 0x14);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", FadeOutBGM__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", FadeInBGM__6CSceneFi);
void CScene::AutoChangeBGMVol(int arg0) {
    *(int *)((char *)this->GetActiveBgmInfo() + 0x24) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SetActiveBgmStatus__6CSceneFPQ26CScene10BGM_STATUS);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", PlayEnvBGM__6CSceneFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SetEnvBGMVol__6CSceneFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetEnvBGMVol__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", StopEnvBGM__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", AutoChangeEnvBGM__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", AutoChangeEnvOffset__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", PlayEnvBgm__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetSeSrcID__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetNumber3__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetBgmFile__6CSceneFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetSeSrcFile__6CSceneFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetSeEnvFile__6CSceneFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetSeBaseFile__6CSceneFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetSeBattleFile__6CSceneFPci);
s32 CScene::CheckLoadBGM(s32 arg0) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (this->GetActiveBgmInfo());
    if (arg0 < 0) {
        return 0;
    }
    return arg0 != (*(s32 *)((u8 *)temp_v0 + 0x8));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", CheckLoadSeSrc__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", CheckLoadSeEnv__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", CheckLoadSeBattle__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", CheckLoadSeBase__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SearchSndDataID__6CSceneFi);
int CScene::GetDefBgmNo(int id) { short *p=(short *)this->SearchSndDataID(id); if(p!=0) return p[1]; return -1; }
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetDefEventSeFile__6CSceneFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSound__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadBGM__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeSrc__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeEnv__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeBattle__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeBase__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadBGMPack__6CSceneFiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeSrcPack__6CSceneFiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeEnvPack__6CSceneFiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeBattlePack__6CSceneFiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSeBasePack__6CSceneFiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", PrePlaySeSrc__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", PlaySeSrc__6CSceneFiff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", check_se_play__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetTimeBgmVolf__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", StepSnd__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", StopSeSrc__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", PlayMapSeSrc__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SePlayOpenDoor__6CSceneFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SePlayCloseDoor__6CSceneFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", SePlayFoot__6CSceneFiiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", GetLine__FPPcPcPc__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSndRevInfo__6CSceneFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenesnd", LoadSndFileInfo__6CSceneFPci);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1011__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1012__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1013__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1018__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1023__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1028__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1033__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1038__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1132__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1194__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1195__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1766__2__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenesnd", at_1615__2__DATA);
