#include "common.h"
#include "dng_event.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DrawEpisode__20CStartupEpisodeTitleFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Switch__20CStartupEpisodeTitleFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Step__20CStartupEpisodeTitleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Initialize__20CStartupEpisodeTitleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Draw__18MessageTaskManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Step__18MessageTaskManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Print__18MessageTaskManagerFPciii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Clear__18MessageTaskManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Initialize__18MessageTaskManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Draw__13CRedMarkModelFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Step__13CRedMarkModelFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", GeoDraw__9CGeoStoneFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DrawMiniMapSymbol__9CGeoStoneFP14CMiniMapSymbol);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", SetFlag__9CGeoStoneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", GeoStep__9CGeoStoneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CheckEvent__9CGeoStoneFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Initialize__9CGeoStoneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Draw__13CRandomCircleFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Step__13CRandomCircleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DrawSymbol__13CRandomCircleFP14CMiniMapSymbol);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CheckArea__13CRandomCircleFPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", GetPosition__13CRandomCircleFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CheckEvent__13CRandomCircleFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", SetCircle__13CRandomCircleFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Clear__13CRandomCircleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Initialize__13CRandomCircleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Draw__12CTreasureBoxFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DrawShadow__12CTreasureBoxFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", SetLargeModel__19CTreasureBoxManagerFP11CCharacter2i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", SetCollisionModel__19CTreasureBoxManagerFPUiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", PutTreasureBox__19CTreasureBoxManagerFiPffiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CheckArea__19CTreasureBoxManagerFPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DrawMiniMapSymbol__19CTreasureBoxManagerFP14CMiniMapSymbol);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Draw__19CTreasureBoxManagerFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DrawShadow__19CTreasureBoxManagerFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", PickupCollision__19CTreasureBoxManagerFPfP6CCPoly9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", MimicCount__19CTreasureBoxManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CheckEvent__19CTreasureBoxManagerFPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", GetGateKeyIndex__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", GetKeyDoorIndex__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", Lamb2WolfManager__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", LoopSoundManager__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", BattleSoundManager__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", StatusWarningSnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", BattleAreaBGMCtrl__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", ScriptDebugCommand__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", XChgMapLighting__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", XChgMapRotation__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", SearchMapEventParts__FiPP9CMapPartsPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", SearchMapFlatPosition__FPfP11CAutoMapGen);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", GetDungeonEventPoint__FPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _GROUP_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _GROUP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _ITEM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _FLOOR_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _FLOOR__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CreatTresuarBoxInfo__FP22TRESURE_BOX_FLOOR_INFOPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", PickupRandomItemCheckMax__FP22TRESURE_BOX_FLOOR_INFOi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", PickupRandomItem__FP22TRESURE_BOX_FLOOR_INFOii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CheckObjectPutArea__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", ScanEyePoint__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", AutoSetTreasureBox__FiPff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", AutoSetTreasureBox__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _FLS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _FL__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", _FLE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", CreatMonsterFloorInfo__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", AutoSetMonster__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", AutoSetMonster__FiPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DungeonFloorInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", DungeonFloorFinish__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", LoadDungeonMapFile__FPcPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", MinimapDoorEnable__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", LoadMonsterFile__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", LoadMonsterFile__Fii);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_event", __sinit_dng_event_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1082__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1248__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", gatekey_index__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", keydoor_key_index__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", xchg_rot_list__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", tag__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1936__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", tag2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1274__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1279__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1466__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1467__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1468__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1645__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1732__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1825__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1826__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1827__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1828__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1829__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1905__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_1965__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2159__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2198__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2199__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2200__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2446__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2447__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2448__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2449__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2450__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2451__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2452__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2453__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2454__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2455__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2456__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", at_2529__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", D_0037B044__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", __vt__9CGeoStone__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_event", __vt__13CRedMarkModel__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(counter_1489, 0x4);
INCLUDE_BSS(nowTbFloor, 0x4);
INCLUDE_BSS(nowTboxGroup, 0x4);
INCLUDE_BSS(nowTboxItemCnt, 0x4);
INCLUDE_BSS(FLS_FLOOR_ID, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1348, 0x10);
INCLUDE_BSS(MainMapInfo, 0x20);
