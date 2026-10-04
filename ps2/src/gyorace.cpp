#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", sgInitGyoRace__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", sgLoopGyoRace__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", AutoCam__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", sgMapDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", sgCharaDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", DivSpriteScreen__FR11mgCDrawPrim__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", sgEffectDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", sgSysDrawGyoRace__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", Jikkyou__FP11SubGameInfo);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gyorace", __sinit_gyorace_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", fish_name);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", cam_pos);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1027__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1028__9);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1481__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1524__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1547);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1548);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1766__3);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_903__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_904__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_905__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_906__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_907__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_908__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_909__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_910__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_911__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_912__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_913__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_914__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_915__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_916__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_917__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_918__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_919__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_920__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1373__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1374__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1375__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1376__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1377__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1378__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1379__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1380__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1381);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1382__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1383__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1384__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1696__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1697__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1698__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1699__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1700__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1701);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1702);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", at_1703);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", D_0037B07C);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gyorace", old_cam_no);

// Small uninitialised data (.sbss)
unsigned char gyore_snd_id[0x4];
unsigned char race_cnt[0x4];
unsigned char race_proc_cnt[0x4];
unsigned char race_mode[0x4];
unsigned char time_max[0x4];
unsigned char rank_count[0x4];
unsigned char EffectTex[0x4];
unsigned char EffectTex2[0x4];
unsigned char wind_tex[0x4];
unsigned char hero_no[0x4];
unsigned char water_cam[0x4];
unsigned char cam_no[0x4];
unsigned char win_alpha[0x4];
unsigned char effect_cnt[0x4];
unsigned char mes_count[0x4];
unsigned char jyunkai_flg[0x4];
unsigned char hantei_flg[0x4];
unsigned char goal_cnt[0x4];
unsigned char battle_effect[0x4];
unsigned char battle_EffectPara[0x4];
unsigned char camera_id[0x8];
unsigned char race_rank[0x8];
unsigned char gyo_mes[0x4];
unsigned char CharaTexb[0x4];
unsigned char WindowTexb[0x4];
unsigned char EffectTexb[0x4];
unsigned char ras_off_1762[0x4];
unsigned char init_1763[0x4];

// Uninitialised data (.bss)
unsigned char fish_game_data[0xE0];
unsigned char RaceInfo[0x1E0];
unsigned char old_prog[0x90];
unsigned char fish_rank[0x1C];
unsigned char D_01F5971C[0x4];
unsigned char old_fish_rank[0x20];
unsigned char game_data[0x20];
unsigned char old_ambient[0x10];
unsigned char BuffTextureData[0x30];
unsigned char BuffWorkData[0x30];
unsigned char camera0[0x70];
unsigned char fish_inf[0x110];
unsigned char at_1765__2[0x10];
unsigned char at_1775[0x10];
unsigned char at_1776[0x10];
unsigned char lap_inf_1798[0x30];
unsigned char lap_inf2_1799[0x50];
