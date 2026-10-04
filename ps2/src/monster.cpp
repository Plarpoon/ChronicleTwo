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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", base_monster_define);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", dung_progtxt_notlift_mons);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1707);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1724__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2031);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2079__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", no_score_uv);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", guard_score_uv);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", vs_attk_index);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", gift_item_tbl);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", react_tbl);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2183);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2294__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2699);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", mos_data_anlyze_tag);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1200);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1201);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1202);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1203);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1204);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1205);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1421__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1422__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1423);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1424);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1425);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1426);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1427__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1428__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1429__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1430__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1431__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_1999);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2100);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2485);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2486);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2487);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2488);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2588);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2589);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2802);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", at_2809);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/monster", __vt__14CActiveMonster);

// Small uninitialised data (.sbss)
unsigned char dmg_sc_cnt_2104[0x4];
unsigned char init_2105[0x4];

// Uninitialised data (.bss)
unsigned char at_1704[0x10];
