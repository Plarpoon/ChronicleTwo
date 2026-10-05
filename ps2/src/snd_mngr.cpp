#include "common.h"
#include "snd_mngr.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", Create__11CLoopSeMngrFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", __ct__15SND_LOOP_SE_SEQFv);
void CLoopSeMngr::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", Clear__11CLoopSeMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetLoopSe__11CLoopSeMngrFPiUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", SeLoopPlayStop__11CLoopSeMngrFUiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", SeLoopPlayStop__11CLoopSeMngrFUiiiffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", Step__11CLoopSeMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", AllSeStop__11CLoopSeMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetReverbDepth__Fi);
u32 sndCreateID(u32 a, s32 b) {
    return (a & 0xFFFF0000) | (b & 0xFFFF);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetSeNo__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetPortInfo__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetSeSeq__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetEmptySeSeq__FPi);
u32 GetPortNo(u32 arg0) {
    return (arg0 >> 24) & 0xFF;
}
u32 GetBankNo(u32 arg0) {
    return (arg0 >> 16) & 0xFF;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetBankInfo__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetSeInfo__FUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndInitMngr__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndWaitSema__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSignalSema__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndInitPort__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndInitSeSeq__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetReverb__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStopVoice__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", SetMasterVol__Fif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", FadeMasterVol__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetMasterVol__Fif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetMasterVol__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndMasterVolFadeInOut__Fiiff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetPortVol__Fif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetPortVol__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndTransBdState__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndWaitTransBd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", CSndStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", CSndStepWait__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStep__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndFlush__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", SeAllStop_Sub__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSeAllStop__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetSeDefVol__FUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", IsBgmPort__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetCSndPortNo__FiPiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndLoadSound__FiPUiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", __ct__13sndCSeSeqDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndDeletePort__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetPortBankNo__FUiPiPi);
void sndSePlay(u32 a, s32 b, s32 c) {
    sndSePlaySeID(a, b, -1, -1, 0x40, 0x2000, c);
}
void sndSePlayV(u32 a, s32 b, s32 c, s32 d) {
    sndSePlaySeID(a, b, -1, c, 0x40, 0x2000, d);
}
void sndSePlayVP(u32 a, s32 b, s32 c, s32 d, s32 e) {
    sndSePlaySeID(a, b, -1, c, d, 0x2000, e);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSePlayVPf__FUiiffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSePlayVf__FUiifi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSePause__FUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetSeStatus__FUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndPortSqPause__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndPortSqReplay__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSeCheck__FUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSePlaySeID__FUiiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSeStop__FUiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSeVol__FUiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePan__FUiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSeVolf__FUiifi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePanf__FUiifi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePitch__FUiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetMicPos__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetVolPan__FPfPfPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndGetVolPan__FPfPfPfPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndVolLimit__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSePlayPrKr__FUiiiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSeStopPrKr__FUiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSeVolPrKr__FUiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePanPrKr__FUiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePitchPrKr__FUiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSePlayPBPrKr__Fiiiiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSeStopPBPrKr__Fiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSeVolPBPrKr__Fiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePanPBPrKr__Fiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSePitchPBPrKr__Fiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSqPlay__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSqStop__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSetSqVol__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndSqRePlay__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", GetLine__FPPcPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", SearchSeq__11sndBankInfoFPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", LoadSeInfoTxt__11sndPortInfoFiPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", __ct__9sndSeInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", LoadVolInfoTxt__11sndPortInfoFiPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStopSeSeq__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", PlaySeSeq__FUiP13sndCSeSeqDatai);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", StopSeSeq__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", SetVolSeSeq__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamOpenFast__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamOpenState__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamStandBy__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamSetVol__Fff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamPlay__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamPause__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamRePlay__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamGetState__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", sndStreamClose__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", __ct__9sndCSeSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", __ct__11sndPortInfoFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/snd_mngr", __sinit_snd_mngr_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_732__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_816__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_896__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_897__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_898__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_899__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_900__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1549__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1625__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1626__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1627__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1628__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1629__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1630__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1631__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1632__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1633__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1634__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1635__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1636__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1679__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1680__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", D_0037AFF4__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", EnableSndMngr__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", snd_sema_id__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", MasterVol__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", MasterVolFade__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", snd_old_vsync__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/snd_mngr", at_1469__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(ReverbType, 0x8);
INCLUDE_BSS(ReverbDepthe, 0x8);
INCLUDE_BSS(init_snd, 0x8);
INCLUDE_BSS(feMasterVol, 0x8);
INCLUDE_BSS(fnowMasterVol, 0x8);
INCLUDE_BSS(fstpMasterVol, 0x8);

// Uninitialised data (.bss)
INCLUDE_BSS(PortInfo, 0x29C0);
INCLUDE_BSS(SeSequencer, 0x1600);
INCLUDE_BSS(PortVolf, 0x40);
INCLUDE_BSS(MicPos, 0x10);
INCLUDE_BSS(MicDir, 0x10);
INCLUDE_BSS(at_1555, 0x30);
INCLUDE_BSS(at_1648, 0x10);
