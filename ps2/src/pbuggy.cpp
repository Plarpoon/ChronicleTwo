#include "common.h"
#include "pbuggy.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgInitBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgExitBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgLoopBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgEffectDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgDrawShadowBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", sgSystemDrawBuggy__FP11SubGameInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", CharaControl__FP6CSceneP11CPadControl__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", InitBuggy__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", BuggyDamage__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", PlayBuggyLoopSe__FP6CScenei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", BuggyControl__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", InitBomb__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", TakeBombCheck__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", TakeBomb__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", ThrowBomb__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", BombBomb__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", NowPutBomb__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", BombControl__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", BombCheck__FP6CScene);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/pbuggy", __sinit_pbuggy_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1047__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1048__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1074__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1193__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_942__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_943__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_944__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_945__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_946__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_947__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_948__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_949__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_950__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_951__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_952__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_953__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_954__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_955__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_956__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_957__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_958__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_959__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_960__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_961__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_962__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_963__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_964__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1056__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1156__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1157__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1158__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1159__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1160__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1161__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1302__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1303__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1304__9__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1305__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1306__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1307__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1316__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1433__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1434__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", at_1435__3__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", D_0037B090__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/pbuggy", BuggyHP__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(BuggyChara, 0x4);
INCLUDE_BSS(PorcussChara, 0x4);
INCLUDE_BSS(MucchoChara, 0x4);
INCLUDE_BSS(BombChara, 0x4);
INCLUDE_BSS(StarbullChara, 0x4);
INCLUDE_BSS(GunFireEff, 0x4);
INCLUDE_BSS(GunHitEff, 0x4);
INCLUDE_BSS(BombEffHandle, 0x4);
INCLUDE_BSS(SmokeEffHandle, 0x4);
INCLUDE_BSS(BuggyTexb, 0x4);
INCLUDE_BSS(PorcussTexb, 0x4);
INCLUDE_BSS(MucchoTexb, 0x4);
INCLUDE_BSS(EffectTexb__2, 0x4);
INCLUDE_BSS(EffectTexbNum, 0x4);
INCLUDE_BSS(BombTexb, 0x4);
INCLUDE_BSS(StarbullTexb, 0x4);
INCLUDE_BSS(GunEffTexb, 0x4);
INCLUDE_BSS(SysTexb, 0x4);
INCLUDE_BSS(EffectMan__2, 0x4);
INCLUDE_BSS(RunEventNo__2, 0x4);
INCLUDE_BSS(WorkBuff, 0x4);
INCLUDE_BSS(BuggySndID, 0x4);
INCLUDE_BSS(IntroHelpMesFlag, 0x4);
INCLUDE_BSS(CharaStatus, 0x4);
INCLUDE_BSS(BuggyStatus, 0x4);
INCLUDE_BSS(BuggyStatusStep, 0x4);
INCLUDE_BSS(BuggyHPf, 0x4);
INCLUDE_BSS(TrainHP, 0x4);
INCLUDE_BSS(BuggyActCount, 0x4);
INCLUDE_BSS(BuggySidePos, 0x4);
INCLUDE_BSS(BuggyDamageMotion, 0x4);
INCLUDE_BSS(GunFireEffDraw, 0x4);
INCLUDE_BSS(GunHitEffDraw, 0x4);
INCLUDE_BSS(BombStatus, 0x4);
INCLUDE_BSS(BombCount, 0x4);
INCLUDE_BSS(BombHitObj, 0x4);
INCLUDE_BSS(BombImpact, 0x4);
INCLUDE_BSS(test_1254, 0x4);
INCLUDE_BSS(init_1255, 0x4);
INCLUDE_BSS(reload_cnt_1350, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(StarbullPos, 0x10);
INCLUDE_BSS(EffectBuff, 0x30);
INCLUDE_BSS(BuggyVelo, 0x10);
INCLUDE_BSS(BombVelo, 0x10);
INCLUDE_BSS(PolVoice, 0x20);
