#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", IsDraw__14CActiveMonsterFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckStatusAttr__14CActiveMonsterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckView__14CActiveMonsterFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", Step__14CActiveMonsterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", Copy__14CActiveMonsterFR14CActiveMonsterP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", __as__12CActionCharaFRC12CActionChara);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", Initialize__14CActiveMonsterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", GetMonsterTable__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SetPutFlag__18CMonsterLocateInfoFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", Initialize__11CMonsterManFP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawEffectScript__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", StepEffectScript__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", IsBattleStyleDist__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckMonsterTolk__11CMonsterManFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckThrowTarget__11CMonsterManFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SearchBaseIndex__11CMonsterManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", GetMonsterNum__11CMonsterManFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", GetReferPtr2__11CMonsterManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SearchActiveMonsterBlock__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SearchReferBlock__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", EntryRefer__11CMonsterManFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", LoadReferMonsterFile__11CMonsterManFiP16BASE_MONSTER_TBLP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SetActiveMonster__11CMonsterManFiPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawMiniMapSymbol__11CMonsterManFP14CMiniMapSymbol);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawLifeGage__11CMonsterManFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawPiyori__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawActMonster__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawInvisibleMonster__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", DrawShadowActMonster__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", PriorityLevelCheck__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", GetPriorityLevelIndex__11CMonsterManFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckPhoto__11CMonsterManFPQ26CScene17InScreenCharaInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SetNearAreaPiyori__11CMonsterManFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", IsRunEvent__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CollisionCheck__11CMonsterManFP14CActiveMonsterPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", SearchArea__FP6CScenePfPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", HitEffectSet__FP6CScenePfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", GuardEffectSet__FP6CScenePfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", HitScoreSet__FPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckGiftPack__FP14CActiveMonsterP8CColPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", CheckDamage__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", MoveUnit__11CMonsterManFP14CActiveMonsterP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", ThinkHost__11CMonsterManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", _MONSTER_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/monster", LoadMonsterLanguage__Fi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", base_monster_define__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", dung_progtxt_notlift_mons__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1707__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1724__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2031__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2079__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", no_score_uv__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", guard_score_uv__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", vs_attk_index__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", gift_item_tbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", react_tbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2183__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2294__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2699__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", mos_data_anlyze_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1200__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1201__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1202__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1203__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1204__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1205__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1421__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1422__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1423__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1424__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1425__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1426__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1427__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1428__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1429__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1430__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1431__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1999__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2100__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2485__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2486__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2487__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2488__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2588__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2589__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2802__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2809__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", __vt__14CActiveMonster__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(dmg_sc_cnt_2104, 0x4);
INCLUDE_BSS(init_2105, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1704, 0x10);
