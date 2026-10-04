#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StopVoice__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SndInReverb__6CSoundFb);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SetReverb__6CSoundFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", set_spu__Fiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", TransHdBd__Fiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", Init__6CSoundFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", Exit__6CSoundFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", DEL_PORT__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SQ_Play__6CSoundFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SQ_RePlay__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SE_Play__6CSoundFiiiiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SE_SetVol__6CSoundFiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SE_SetPan__6CSoundFiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SE_Stop__6CSoundFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", Step__6CSoundFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", Stop__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SetVol__6CSoundFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SetStereoMode__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SetMasterVol__6CSoundFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", LoadHdBd__6CSoundFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", LoadHdBd2__6CSoundFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", LoadHdBdAdd__6CSoundFiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", LoadSeq__6CSoundFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", SE_SetPitch__6CSoundFiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamOpenFast__6CSoundFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamOpenFromFPLFast__6CSoundFiPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamPlay__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamStop__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamClose__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamEND__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamPause__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamRePlay__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamSetVol__6CSoundFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamGetState__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamGetLevel__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", StreamStandBy__6CSoundFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sound", TransBdState__6CSoundFi);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_218);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_278);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_279);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_280);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_281__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_282__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_283__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_474);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_475);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_476);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_477);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_564__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_576__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_577__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_578__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_595__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_613__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_728);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_733);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_843__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_883);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_884__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_904__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_905);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_906);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_907);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_908);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_929);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sound", at_930);

// Small uninitialised data (.sbss)
unsigned char iopMSINBuffAddr[0x8];
unsigned char bgm_info[0x8];
unsigned char iop_bd_addr[0x4];
unsigned char bd_size_total[0x4];
unsigned char load_m_flg_351[0x4];
unsigned char init_352[0x4];

// Uninitialised data (.bss)
unsigned char msinCtx[0x1C];
unsigned char D_003F3F6C[0x4];
unsigned char msinBfGrp[0x10];
unsigned char msinBfCtx[0x80];
unsigned char msinBf[0x1200];
unsigned char gBank[0x50];
unsigned char midi_state[0x1270];
