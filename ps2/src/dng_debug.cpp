#include "common.h"
#include "dng_debug.hpp"
#include "colprim.hpp"
#include "dng_event.hpp"
#include "dng_main.hpp"
#include "font.hpp"
#include "gamepad.hpp"
#include "mainloop.hpp"
#include "mg_drawprim.hpp"
#include "mg_memory.hpp"
#include "mg_texture.hpp"
#include "monster.hpp"
#include "prespr.hpp"
#include "savedata.hpp"
#include "scenesnd.hpp"
#include "userdata.hpp"
#include <cstdio>
#include <cstdlib>

extern CGamePad GamePad__2;
extern CFont dbFont;
extern int command_int[];
extern char *command_str[];

/**
 * Closes the dungeon debug menu and applies its edited settings.
 */
static void dngDebugExit();
/**
 * Loads a chosen monster kind beside the player, refreshing monster memory on the first load.
 */
static void DBGCMD_ReloadEnemy(int monster_id, int clear_first);
/**
 * Draws the first dungeon system-parameter panel.
 */
static void DrawSystemParamInfo();
/**
 * Draws the second dungeon system-parameter panel.
 */
static void DrawSystemParamInfo2();

// Code (.text)
DNG_DEBUG_INFO *dngGetDebugInfo() { return &dbinfo; }
void dngDebugInit() {
    dbinfo.active = 0;
    dbinfo.cursor = 0;
    dbinfo.sound_flag = 1;
    dbinfo.monster_talk = 0;
    dbinfo.effect_id = 0;
    dbinfo.effect_vol = 0.0f;
    dbFont.Init();
    dbFont.SetClearance(20, 20);
}
#ifdef NONMATCHING
void dngDebugStart() {
    dbinfo.active = 1;
    dbinfo.command = -1;
    dbinfo.first_enemy_load = 1;
    command_int[DNG_DEBUG_CMD_DEBUG_CAMERA * 2] = DebugInfo.debug_camera;
    command_int[DNG_DEBUG_CMD_CHARA_MOVE * 2] = DebugInfo.chara_move;
    command_int[DNG_DEBUG_CMD_LOCK_ON_MODE * 2] = BattleAreaScene->unk_9e;
    command_int[DNG_DEBUG_CMD_SOUND_FLAG * 2] = dbinfo.sound_flag;
    command_int[DNG_DEBUG_CMD_MONSTER_TALK * 2] = dbinfo.monster_talk;
    command_int[DNG_DEBUG_CMD_EFFECT_ID * 2] = dbinfo.effect_id;
    command_int[DNG_DEBUG_CMD_EFFECT_VOL * 2] = (int)dbinfo.effect_vol;
    GamePad__2.SetAutoRepeat(0xF000, 15, 4);
    GamePad__2.SetAutoRepeat(PAD_UP | PAD_DOWN, 8, 1);
    dbinfo.saved_battle_area_unk_8 = BattleAreaScene->pause_flag;
    BattleAreaScene->pause_flag = 15;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugStart__Fv);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugDraw__Fv);
static void dngDebugExit() {
    dbinfo.active = 0;
    GamePad__2.AutoRepeatOff();
    BattleAreaScene->pause_flag = dbinfo.saved_battle_area_unk_8;
    DebugInfo.debug_camera = command_int[DNG_DEBUG_CMD_DEBUG_CAMERA * 2];
    DebugInfo.chara_move = command_int[DNG_DEBUG_CMD_CHARA_MOVE * 2];
    BattleAreaScene->unk_9e = command_int[DNG_DEBUG_CMD_LOCK_ON_MODE * 2];
    dbinfo.sound_flag = command_int[DNG_DEBUG_CMD_SOUND_FLAG * 2];
    dbinfo.monster_talk = command_int[DNG_DEBUG_CMD_MONSTER_TALK * 2];
    dbinfo.effect_id = command_int[DNG_DEBUG_CMD_EFFECT_ID * 2];
    dbinfo.effect_vol = (float)command_int[DNG_DEBUG_CMD_EFFECT_VOL * 2];
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", Initialize__12CTreasureBoxFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DBGCMD_ReloadEnemy__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo2__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawDebugWindow__Fv);

// Static initialiser (.init)
#ifdef NONMATCHING
void __sinit_dng_debug_cpp() { dbFont.Init(); }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", __sinit_dng_debug_cpp);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", command_str__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", command_int__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_871__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_872__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_873__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_874__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_875__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_876__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_877__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_878__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_879__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_880__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_881__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_882__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_968__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_969__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_970__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_971__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_972__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_973__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_974__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_975__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1103__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1104__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1105__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1106__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1107__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1132__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", at_1133__2__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_debug", D_0037B010__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(dbFont, 0xC0);
INCLUDE_BSS(dbinfo, 0x20);
