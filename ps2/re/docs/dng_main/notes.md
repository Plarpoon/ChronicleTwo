# dng_main notes

Dungeon main-loop mode (`InitDungeonMain` / `LoopDungeonMain` / `FinishDungeonMain` are the
LoopInit/LoopMain/LoopExit entries) plus most of the dungeon's shared globals.

## Owned types

### MoveCheckInfo (0x110)
Only class owned by the unit (`Initialize` = `memset(this, 0, 0x110)` gives the size). First game:
`MoveCheckInfo` in gameutil.hpp, 0xD0; this game prefixes 0x10 bytes and appends 0x40.
Layout from `MoveCheck` / `GetCPolyAttr` (gameutil):
- 0x00 float radius: read by MoveCheck, <= 0 -> 15.0. CActionChara::RunScript writes height*2+4.
- 0x04 skip_ground: foot-poly search only runs when 0.
- 0x08 landed: set when the foot point is above the step end.
- 0x10 CCPoly ground_poly / 0x60 ground_found / 0x70 CCPoly second_poly (same poly copied twice)
  / 0xC0 ground_point (foot point vector). CActionChara+0x962 = ground_poly.foot_sound.
- 0xD0 width_result = CheckWidth result.
- 0xD4 in_water / 0xE0 water_surface: GetCPolyAttr, a raised probe hitting area_kind 7 or 1.
  DngStep checks MainChara+0x9E4 (=0x910+0xD4) and spawns the water ripple effect at +0x9F0.
- 0xF0 crossed_area / 0xF4 signed_distance (mgDistVector, negated when moving down) /
  0x100 crossed_point: GetCPolyAttr, segment hitting area_kind 7 or 1.
- 0x0C, 0x64..0x6F, 0xD8..0xDF, 0xF8..0xFF never touched -> unk.
Embedded in CActionChara at 0x910 and CActiveMonster at 0x1360, EditMoveCharaInfo (editctrl).
CMonsterMan's inline array construction calls `MoveCheckInfo::Initialize` (the out-of-line copy here).

### DNG_STATUS (0x1C, `DngStatus`) -- name ours, no retail type name known
- 0x00 mode (DNG_STATUS_MODE). Values from LoopDungeonMain/RunMainEvent/DngMainKey:
  0 field (DngMainKey + DngStep), 1 menu from field (MenuMainKey), 2 event (RunMainEvent),
  3 event editor (EventEdit), 4 menu from event (EventLoop returned 2), 5 leave (loop returns 1).
  RunMainEvent: EventLoop 3 -> 5, 2 -> 4, 1 -> 0.
- 0x04 dungeon_no: INIT_LOOP_ARG.map_no; EntryEventScript arg, index into map name table,
  CBPot::SetObject2 arg, monster-talk file name (event_func).
- 0x08 eye_view: InitEyeCamera sets 1, ResetEyeView clears.
- 0x0C active_item: slot * 0x6C into the active item list (actionchara, dng_status).
- 0x10 cursor_fade float (init 1.0; dng_status fades it).
- 0x14 status_count: CheckStatusError counts to 0x2C then flashes status ailments.
- 0x18 debug_window: DebugMainDraw draws a debug box when set; Sphida/DBGCMD clear it.
Symbol size 0x1C (bss slot 0x20).

### ACCUME_EFFECT (0x330, `AccumulateEffect`) -- name ours
Pointed to by CActionChara+0x7CC (`accume_effect`, still `void *` in actionchara.hpp).
`_SET_ACCUME_FLAG` (actscript): [0] = frame from ACTION_ACCUME, 0x310 = mode (script value;
1 = start), on start also 0x314=0, 0x318=0, 0x31C=3.0f, 0x320=0, 0x324=0 and zeroes 0x290..0x30F.
CommonStageClassInit clears 0x0, 0x310, 0x320. No code found that steps/draws it by name;
only those fields are named.

### DNG_STATUS_MODE enum -- names ours (see above).

## Global functions
Not local in retail: GetWeaponEffect, InitDungeonMain, CommonStageClassInit (also called by
dng_event LoadDungeonMapFile), FinishDungeonMain (empty), LoopDungeonMain (returns 1 when
DngStatus becomes 5). All others are local -> static in the .cpp.
GetWeaponEffect returns `&wep_effect[cnt]` (CWeaponElement, stride 0x7C0, 8 entries, cycles).

`InitDungeonMain` owns a function-local `mgCMemory` for the debug event stack. At
0x001CF490, retail checks a one-byte GP-relative initialization guard and calls
`mgCMemory::Init()` once before `stSetBuffer` and `InitEventEdit`. The stack is
the 0x30-byte BSS object `debug_event_stack_1106` at 0x01EF7380; the guard is
`init_1107` at 0x0037D470, followed by three alignment bytes. MWCC generates
both naturally from the local static declaration, but its generated ordinal
differs from retail's source ordinal. The object postprocessor maps the pair
to the retail symbol names without defining a compiler initializer manually.
The current C++ draft of `InitDungeonMain` is 0x20D8 bytes, short of retail's
0x2110-byte function, and changes the layout of later text. The default build
uses the retail assembly while the draft is kept under `NONMATCHING`; its
retail BSS storage and guard are supplied by the corresponding data placeholders.
The draft also caused MWCC to emit `MoveCheckInfo::Initialize`, camera assignment,
the active monster constructor, one data object, a treasure-box vtable, and
49 read-only constants. The assembly fallback supplies these at their retail
addresses until the C++ draft can reproduce the complete unit layout.

## Globals (types from __sinit, InitDungeonMain, CommonStageClassInit)
Retail names with `__2` in main.symbols are these globals (other units have locals of the same
name): MainBuffer, MainChara, EventCamera, BuffWorkData. viewAngleH/V, WaveTable are local here.
- MainBuffer mgCMemory* (GetMainStack); BuffReadData u_long128* (stAlloc64 200000).
- NowFloorInfoPtr: CSaveDataDungeon::GetFloorInfoPtr result (0x14-byte record, +0x10 s16 incremented
  by CMonsterMan::ThinkHost). Type name unknown -> forward-declared `DNG_FLOOR_SAVE` (ours).
- ActionScriptEnv RUN_SCRIPT_ENV (8 bytes): item_chara = ItemBaseData, texb = 0x68.
- DngSaveData CSaveData* (GetSaveData); DngUserData = DngSaveData+0x1D2A0 (CUserDataManager*);
  DngSaveDataDungeon = DngSaveData+0x1C5B4.
- DngMainScene CScene* (GetMainScene). BattleAreaScene = DngMainScene + 0x2F90 (same as
  menu_GetBattleAreaScene). Its type is unknown -> forward-declared `DNG_BATTLE_AREA` (ours).
  Offsets used here: 0x8 flags (0x2, 0x400 event, 0x800, 0x8000), 0xC, 0x24, 0x44, 0x46, 0x48,
  0x49, 0x4C, 0x50, 0x54, 0x5C, 0x64, 0x78, 0x7C (CTreasureBoxManager*), 0x84, 0x88, 0x8C, 0x90,
  0x98, 0x9C, 0x9E, 0xA0 (texb). CDngFloorManager sits at scene+0x2FA4.
- DngMainMap CMap* (CScene::GetMap). ActiveMonster CMonsterMan* (new 0x100F0).
- DngMess/DngMess2/EventMess/MonsterMess ClsMes* (new 0x2958).
- RedMarkModel CRedMarkModel* (new 0x90). TreasureBoxModel CCharacter2* (new 0x660).
  TreasureBoxMan CTreasureBoxManager* (new 0xAA0: 0x10 header, 24 CTreasureBox of 0x70, tail).
  `__vt__12CTreasureBox` is emitted in this unit (inline ctor used here).
- MainChara: CScene::GetCharacter(0); CActionChara methods called on it -> CActionChara*.
- FxScriptMan CEffectScriptMan* (new 0x1190). BTsuboCol CColPrim*. TornadoModel mgCFrame*.
- SparcModel mgCFrame*[3] (symbol 0xC; three mgLoadMDSFile results copied into each CSparcEffect).
- PullItemMan CPullItemManager by value (list = PullItem, num = 0x48). PullItem CPullItem[72].
- mgCMemory: BuffPaketList[2], BuffPaketData[2], BaseCharacter[6], BuffEventData[4]
  (__construct_array with mgCMemory ctor), the others single.
- DamageScore CDamageScore (ctor inlined: memset +0x48), DamageScoreMons CDamageScore[8],
  DamageScore2 CDamageScore2, LevelupInfo CLevelupInfo, LockOnModel CLockOnModel,
  WarningGage2 CWarningGage2, ColPrimMan CColPrimMan, RocketLauncher CRocketLauncherMan,
  MachineGun CMachineGun, LaserGun CLaserGunMan, VoiceUnit CRoboVoiceSystem.
- MsgTaskMan MessageTaskManager (0x36C), StartupEpisodeTitle CStartupEpisodeTitle (0x18),
  BattleFX BattleEffectMan (0x48), map_effect CMapEffectsManeger (0x14), AutoMapGen CAutoMapGen
  (0x2A0, mgCDrawPrim at +0x50), RandomCircle CRandomCircle (0x6A0, CCharacter2 at +0x40),
  GeoStone CGeoStone (0x670, CCharacter2-derived), MainCamera/EventCamera CCameraControl (0x1F0),
  HealingEffectMan CHealingEffectMan (0x330), MiniEffPrimMan CMiniEffPrimMan (0x940, mgCDrawPrim
  at +0x204), BTsubo CPot (0x80), BTsubo2 CBPot (0xC50, CFragment[?] of 0x60 from +0x40).
- ItemBaseData CCharacter2[19]; LaserGunModel CCharacter2.
- Local (static, in .cpp later): debag_param, viewAngleH/V, init_camera, DebugPause, test_dist,
  wep_effect_cnt, debug_cursor/mons_no/mons_cur/mons_num, nowload (NowLoadingInfo),
  WaveTable (CWaveTable, registered for destruction), SwordLuminous (CSwordLuminous),
  wep_effect (CWeaponElement[8]), backup_pos, cam_table, debug_no.

`debug_no` occupies 0x20 bytes at 0x0033D400: eight `int` slots, with only
the first seven indexed by the debug menu. The final zero belongs to the
array itself, before `at_3734` at 0x0033D420.

`DngMainKey` compiles to the retail instruction layout except near
0x001D417C: MWCC loads the two immediate coordinates for `SetNextRef` in
the reverse order from retail, while passing the same values. Introducing a
plain local, then separate locals in either declaration order, did not change
that order. The default build uses the retail assembly while the C++ draft
remains under `NONMATCHING` pending a code generation solution. Its three data
pieces (`at_2994`, `at_3336`, `at_3337`) are supplied alongside the fallback.

## Unresolved / pending
- NOT yet declared in the header because dng_effect.hpp does not define the classes and MWCC
  rejects arrays of incomplete type (the header is included by actionchara.hpp/editctrl.hpp, so
  it must keep compiling): `CAfterWire afterWire[16]` (0x120 each), `CSparcEffect Sparc_fx[6]`
  (0xB0), `CThunder thunder[6]` (0xDC0), `CTornado tornado[6]` (0x380), `CChillAfterHit
  chillAfterHit[6]` (0x7A0), `CFireAfterHit fireAfterHit[6]` (0x940). Add them (with
  `#include "dng_effect.hpp"`) once that header declares the classes.
- DNG_BATTLE_AREA / DNG_FLOOR_SAVE are forward declarations with our names; the owners
  (scene / savedatadungeon) should define and rename them.
- Single by-value globals of classes whose headers do not exist yet (CMapEffectsManeger,
  MessageTaskManager, CStartupEpisodeTitle, BattleEffectMan, CAutoMapGen, CRandomCircle,
  CGeoStone, CCameraControl, CHealingEffectMan, CMiniEffPrimMan, CPot, CBPot) are declared
  with forward-declared classes; include their headers when they exist.
