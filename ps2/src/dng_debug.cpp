#include "common.h"
#define DNG_DEBUG_SOURCE
#include "dng_debug.hpp"
#include "colprim.hpp"
#include "actionchara.hpp"
#include "dng_event.hpp"
#include "dng_main.hpp"
#include "effscript.hpp"
#include "font.hpp"
#include "gamepad.hpp"
#include "mainloop.hpp"
#include "mg_drawprim.hpp"
#include "mg_memory.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"
#include "monster.hpp"
#include "prespr.hpp"
#include "savedata.hpp"
#include "savedatadungeon.hpp"
#include "scenesnd.hpp"
#include "snd_mngr.hpp"
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
#ifdef NONMATCHING
void dngDebugDraw() {
    if (!dbinfo.active) return;
    mgTexManager.ReloadTexture(0x6C, (sceVif1Packet *)NULL);
    mgCDrawPrim background;
    background.Initialize(NULL, NULL);
    ((CPreSprite *)&background)->Preset2D();
    background.TextureMapEnable(0);
    background.Begin(6);
    background.Color(16, 16, 16, 72);
    background.Vertex(14, 70, 0);
    background.Vertex(260, 332, 0);
    background.End();

    char text[512];
    char *end = text;
    end += sprintf(end, "--== DEBUG MENU ==--\n");
    for (int row = 0; command_str[row]; ++row) {
        end += sprintf(end, row == dbinfo.cursor ? "->" : "  ");
        end += sprintf(end, command_str[row]);
        end += sprintf(end, "%d\n", command_int[row * 2]);
    }
    if (dbinfo.cursor == DNG_DEBUG_CMD_ENEMY_LOADER) {
        end += sprintf(end, "\n");
        int selected = -1;
        for (int i = 0; base_monster_define[i].id != -1; ++i) {
            if (base_monster_define[i].id == command_int[DNG_DEBUG_CMD_ENEMY_LOADER * 2]) {
                end += sprintf(end, "[G%d]%s\n", base_monster_define[i].grade,
                               base_monster_define[i].name);
                selected = i;
                break;
            }
        }
        if (selected < 0) {
            end += sprintf(end, "[%d]--------\n", command_int[DNG_DEBUG_CMD_ENEMY_LOADER * 2]);
        } else if (base_monster_define[selected].grade > 0) {
            for (int i = 0; base_monster_define[i].id != -1; ++i) {
                if (base_monster_define[i].gift_type == base_monster_define[selected].gift_type) {
                    sprintf(end, "BASE > %s\n", base_monster_define[i].name);
                    break;
                }
            }
        }
    }
    dbFont.DrawDirect(text, 16, 72);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugDraw__Fv);
#endif
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
#ifdef NONMATCHING
int dngDebugKey() {
    if (!dbinfo.active) return 0;
    if (GamePad__2.Down(PAD_DOWN) && dbinfo.cursor < DNG_DEBUG_CMD_NUM - 1) ++dbinfo.cursor;
    if (GamePad__2.Down(PAD_UP) && dbinfo.cursor > 0) --dbinfo.cursor;
    int &value = command_int[dbinfo.cursor * 2];
    if (GamePad__2.Down(PAD_RIGHT)) ++value;
    if (GamePad__2.Down(PAD_LEFT)) --value;
    int step = dbinfo.cursor == DNG_DEBUG_CMD_ENEMY_LOADER ? 4 : 10;
    if (GamePad__2.Down(PAD_R1)) value += step;
    if (GamePad__2.Down(PAD_L1)) value -= step;
    if (GamePad__2.Down(PAD_R2)) value += 100;
    if (GamePad__2.Down(PAD_L2)) value -= 100;
    int minimum = command_int[dbinfo.cursor * 2 + 1];
    if (value <= minimum) value = minimum;
    if (GamePad__2.Down(PAD_CIRCLE)) {
        switch (dbinfo.cursor) {
        case DNG_DEBUG_CMD_RUN_EVENT:
            dbinfo.command = dbinfo.cursor;
            dbinfo.event_no = value;
            dngDebugExit();
            return 1;
        case DNG_DEBUG_CMD_ENEMY_LOADER:
            DBGCMD_ReloadEnemy(value, dbinfo.first_enemy_load);
            dbinfo.first_enemy_load = 0;
            break;
        case DNG_DEBUG_CMD_ENEMY_RESET:
            if (DngMainScene->battle_area.treasure_box)
                for (int i = 0; i < 24; ++i)
                    DngMainScene->battle_area.treasure_box->box[i].Initialize();
            ActiveMonster->Initialize(DngMainScene);
            DngSaveData->SetBitFlag(0x13D, 1);
            dngDebugExit();
            return 1;
        case DNG_DEBUG_CMD_SKIP_FLOOR: {
            int dungeon = DngSaveDataDungeon->stage_id;
            int floor = DngSaveDataDungeon->floor_id[dungeon];
            DngUserData->GetItem(GetGateKeyIndex(dungeon, floor), 1);
            DngUserData->GetItem(GetKeyDoorIndex(dungeon, floor), 1);
            DngUserData->GetItem(0x132, 1);
            DngUserData->GetItem(0x131, 1);
            dngDebugExit();
            return 1;
        }
        case DNG_DEBUG_CMD_SOUND_FLAG:
            if (value == 0) DngMainScene->PauseBGM();
            else DngMainScene->RePlayBGM();
            break;
        }
    }
    if (GamePad__2.Down(PAD_L3)) dngDebugExit();
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugKey__Fv);
#endif
#ifdef NONMATCHING
void CTreasureBox::Initialize() {
    state = TREASURE_BOX_STATE_NONE;
    lid_open = 0.0f;
    flags = 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", Initialize__12CTreasureBoxFv);
#endif
#ifdef NONMATCHING
static void DBGCMD_ReloadEnemy(int monster_id, int clear_first) {
    CActionChara *player = (CActionChara *)DngMainScene->GetCharacter(0);
    if (!ActiveMonster) return;
    if (clear_first) {
        FxScriptMan->AllClearEffSpt();
        BuffEffectScriptData.ClearHeapMem();
        ActiveMonster->Initialize(DngMainScene);
        DngMainScene->AssignStack(3);
        DngMainScene->ClearStack(3);
        mgCMemory *stack = DngMainScene->GetStack(3);
        for (int i = 0; i < MONSTER_ACTIVE_MAX; ++i) {
            ActiveMonster->memory[i].stSetBuffer(stack->stAlloc64(4000), 4000);
            ActiveMonster->memory[i].stack_used = 0;
            ActiveMonster->memory[i].lock = 0;
        }
        sndInitPort(5);
    }
    mgCMemory *stack = DngMainScene->GetStack(3);
    if (ActiveMonster->SearchBaseIndex(monster_id) < 0)
        ActiveMonster->EntryRefer(monster_id, stack);
    float position[4], direction[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    player->GetPosition(position);
    position[0] += 20.0f * (float)rand() / 2147483600.0f - 10.0f;
    position[2] += 20.0f * (float)rand() / 2147483600.0f - 10.0f;
    int base_index = ActiveMonster->SearchBaseIndex(monster_id);
    if (base_index != -1) ActiveMonster->SetActiveMonster(base_index, position, direction, -1);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DBGCMD_ReloadEnemy__Fii);
#endif
#ifdef NONMATCHING
static void DrawSystemParamInfo() {
    mgCDrawPrim background;
    background.Initialize(NULL, NULL);
    ((CPreSprite *)&background)->Preset2D();
    background.TextureMapEnable(0);
    background.Begin(6);
    background.Color(16, 16, 16, 72);
    background.Vertex(14, 278, 0);
    background.Vertex(260, 412, 0);
    background.End();

    float position[4];
    DngMainScene->GetCharacter(0)->GetPosition(position);
    char text[2048];
    char *end = text;
    end += sprintf(end, "POS %.1f %.1f %.1f\n", position[0], position[1], position[2]);
    end += sprintf(end, "PRIM %d/%d\n", ColPrimMan.ActivePrimNum(), 64);
    mgCMemory *map_stack = DngMainScene->GetStack(1);
    mgCMemory *monster_stack = DngMainScene->GetStack(3);
    DngMainScene->GetStack(4);
    mgCMemory *event_stack = DngMainScene->GetStack(5);
    end += sprintf(end, "STACK:MAP\t %d\n", map_stack->stack_used / 64);
    end += sprintf(end, "STACK:MOMS\t %d\n", monster_stack->stack_used / 64);
    sprintf(end, "STACK:EVENT  %d/%d\n", (event_stack->stack_size - event_stack->stack_used) / 64,
            event_stack->stack_size / 64);
    dbFont.DrawDirect(text, 16, 280);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo__Fv);
#endif
#ifdef NONMATCHING
static void DrawSystemParamInfo2() {
    mgCDrawPrim background;
    background.Initialize(NULL, NULL);
    ((CPreSprite *)&background)->Preset2D();
    background.TextureMapEnable(0);
    background.Begin(6);
    background.Color(16, 16, 16, 72);
    background.Vertex(14, 178, 0);
    background.Vertex(324, 408, 0);
    background.End();

    CActionChara *player = (CActionChara *)DngMainScene->GetCharacter(0);
    float position[4];
    player->GetPosition(position);
    char text[2048];
    char *end = text;
    end += sprintf(end, "POS %.1f %.1f %.1f\n", position[0], position[1], position[2]);
    if (player->lock_on) {
        int index = player->target_no - 24;
        CActiveMonster *target = ActiveMonster->active[index];
        if (target) {
            target->GetPosition(position);
            end += sprintf(end, "MONS POS %.1f %.1f %.1f\n", position[0], position[1], position[2]);
            end += sprintf(end, "MONS HIGH %.1f   WIDTH %.1f\n", target->height,
                           target->mons_move_check.radius);
        }
    }
    end += sprintf(end, "PRIM %d/%d\n", ColPrimMan.ActivePrimNum(), 64);
    mgCMemory *map_stack = DngMainScene->GetStack(1);
    mgCMemory *monster_stack = DngMainScene->GetStack(3);
    DngMainScene->GetStack(4);
    mgCMemory *event_stack = DngMainScene->GetStack(5);
    end += sprintf(end, "STACK:MAP\t %d\n", map_stack->stack_used / 64);
    end += sprintf(end, "STACK:MOMS\t %d\n", monster_stack->stack_used / 64);
    sprintf(end, "STACK:EVENT  %d/%d\n", (event_stack->stack_size - event_stack->stack_used) / 64,
            event_stack->stack_size / 64);
    dbFont.DrawDirect(text, 16, 180);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo2__Fv);
#endif
void DrawDebugWindow() {
    if (command_int[DNG_DEBUG_CMD_INFORMATION * 2] == 2) DrawSystemParamInfo();
    if (command_int[DNG_DEBUG_CMD_INFORMATION * 2] == 3) DrawSystemParamInfo2();
}

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
