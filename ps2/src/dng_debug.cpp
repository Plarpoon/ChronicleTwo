#include "common.h"
#include "dng_debug.hpp"

#include <cstdio>
#include <cstdlib>

#include "dng_event.hpp"
#include "dng_main.hpp"
#include "effscript.hpp"
#include "font.hpp"
#include "mainloop.hpp"
#include "mglib.hpp"
#include "monster.hpp"
#include "prespr.hpp"
#include "savedata.hpp"
#include "scenesnd.hpp"
#include "userdata.hpp"

#ifdef NONMATCHING
/**
 * Value and lower bound of one debug menu setting.
 */
struct DebugCommandValue {
    int value;   /**< Setting shown beside the command label. */
    int minimum; /**< Lowest setting accepted by the menu. */
};
STATIC_ASSERT(sizeof(DebugCommandValue) == 8);

static char *command_str[] = { /**< Labels of the debug menu, ended by NULL. */
    "RunEvent      ",
    "EnemyLoader   ",
    "DebugCamera   ",
    "CharaMove     ",
    "EnemyReset    ",
    "LockOnMode    ",
    "Infomation    ",
    "SkipFloor     ",
    "Sound Flag    ",
    "Monster Talk  ",
    "Effect_id     ",
    "Effect_Vol    ",
    NULL
};
static DebugCommandValue command_int[DNG_DEBUG_CMD_NUM] = { /**< Values and lower bounds of the debug menu settings. */
    { 100, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 1, 0 },
    { 0, 0 },
    { 1, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 }
};
static CFont dbFont; /**< Font used by the dungeon debug windows. */
DNG_DEBUG_INFO dbinfo;

static void dngDebugExit();
static void DBGCMD_ReloadEnemy(int monster_no, int reset);
static void DrawSystemParamInfo();
static void DrawSystemParamInfo2();
#endif

// Code (.text)
DNG_DEBUG_INFO *dngGetDebugInfo() {
    return &dbinfo;
}

#ifdef NONMATCHING
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
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugInit__Fv);
#endif

#ifdef NONMATCHING
void dngDebugStart() {
    dbinfo.active = 1;
    dbinfo.command = -1;
    dbinfo.first_enemy_load = 1;
    command_int[DNG_DEBUG_CMD_DEBUG_CAMERA].value = DebugInfo.debug_camera;
    command_int[DNG_DEBUG_CMD_CHARA_MOVE].value = DebugInfo.chara_move;
    command_int[DNG_DEBUG_CMD_LOCK_ON_MODE].value = BattleAreaScene->unk_9e;
    command_int[DNG_DEBUG_CMD_SOUND_FLAG].value = dbinfo.sound_flag;
    command_int[DNG_DEBUG_CMD_MONSTER_TALK].value = dbinfo.monster_talk;
    command_int[DNG_DEBUG_CMD_EFFECT_ID].value = dbinfo.effect_id;
    command_int[DNG_DEBUG_CMD_EFFECT_VOL].value = (int)dbinfo.effect_vol;
    GamePad__2.SetAutoRepeat(0xF000, 15, 4);
    GamePad__2.SetAutoRepeat(0x5000, 8, 1);
    dbinfo.saved_battle_area_unk_8 = BattleAreaScene->pause_flag;
    BattleAreaScene->pause_flag = 0xF;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugStart__Fv);
#endif

#ifdef NONMATCHING
void dngDebugDraw() {
    char *write;
    int   line;
    int   monster_index;
    int   selected_monster;
    int   base_index;

    if (dbinfo.active != 0) {
        mgTexManager.ReloadTexture(0x6C, (sceVif1Packet *)NULL);

        CPreSprite sprite;
        char       text[2048];

        sprite.Initialize(NULL, NULL);
        sprite.Preset2D();
        sprite.TextureMapEnable(0);
        sprite.Begin(MG_PRIM_SPRITE);
        sprite.Color(0x10, 0x10, 0x10, 0x48);
        sprite.Vertex(14, 70, 0);
        sprite.Vertex(260, 332, 0);
        sprite.End();

        write = text;
        write += sprintf(write, "--== DEBUG MENU ==--\n");
        for (line = 0; command_str[line] != NULL; line++) {
            if (line == dbinfo.cursor) {
                write += sprintf(write, "->");
            } else {
                write += sprintf(write, "  ");
            }
            write += sprintf(write, command_str[line]);
            write += sprintf(write, "%d\n", command_int[line].value);
        }
        if (dbinfo.cursor == DNG_DEBUG_CMD_ENEMY_LOADER) {
            write += sprintf(write, "\n");
            selected_monster = -1;
            for (monster_index = 0; base_monster_define[monster_index].id != -1; monster_index++) {
                if (command_int[DNG_DEBUG_CMD_ENEMY_LOADER].value == base_monster_define[monster_index].id) {
                    write += sprintf(write, "[G%d]%s\n", base_monster_define[monster_index].grade,
                                     base_monster_define[monster_index].name);
                    selected_monster = monster_index;
                    break;
                }
            }
            if (selected_monster == -1) {
                sprintf(write, "[%d]--------\n", command_int[DNG_DEBUG_CMD_ENEMY_LOADER].value);
            } else if (base_monster_define[selected_monster].grade > 0) {
                for (base_index = 0; base_monster_define[base_index].id != -1; base_index++) {
                    if (base_monster_define[base_index].gift_type == base_monster_define[selected_monster].gift_type) {
                        sprintf(write, "BASE > %s\n", base_monster_define[base_index].name);
                        break;
                    }
                }
            }
        }
        dbFont.DrawDirect(text, 16, 72);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugDraw__Fv);
#endif

#ifdef NONMATCHING
/**
 * Closes the debug menu and saves its edited settings.
 */
static void dngDebugExit() {
    dbinfo.active = 0;
    GamePad__2.AutoRepeatOff();
    BattleAreaScene->pause_flag = dbinfo.saved_battle_area_unk_8;
    DebugInfo.debug_camera = command_int[DNG_DEBUG_CMD_DEBUG_CAMERA].value;
    DebugInfo.chara_move = command_int[DNG_DEBUG_CMD_CHARA_MOVE].value;
    BattleAreaScene->unk_9e = command_int[DNG_DEBUG_CMD_LOCK_ON_MODE].value;
    dbinfo.sound_flag = command_int[DNG_DEBUG_CMD_SOUND_FLAG].value;
    dbinfo.monster_talk = command_int[DNG_DEBUG_CMD_MONSTER_TALK].value;
    dbinfo.effect_id = command_int[DNG_DEBUG_CMD_EFFECT_ID].value;
    dbinfo.effect_vol = command_int[DNG_DEBUG_CMD_EFFECT_VOL].value;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugExit__Fv);
#endif

#ifdef NONMATCHING
int dngDebugKey() {
    DebugCommandValue   *setting;
    CTreasureBoxManager *boxes;
    int                 step;
    int                 minimum;
    int                 box;
    int                 dungeon;
    int                 floor;

    if (dbinfo.active == 0) {
        return 0;
    }
    if (GamePad__2.Down(0x4000) != 0 && dbinfo.cursor < DNG_DEBUG_CMD_NUM - 1) {
        dbinfo.cursor++;
    }
    if (GamePad__2.Down(0x1000) != 0 && dbinfo.cursor > 0) {
        dbinfo.cursor--;
    }
    setting = &command_int[dbinfo.cursor];
    if (GamePad__2.Down(0x2000) != 0) {
        setting->value++;
    }
    if (GamePad__2.Down(0x8000) != 0) {
        setting->value--;
    }
    step = 10;
    if (dbinfo.cursor == DNG_DEBUG_CMD_ENEMY_LOADER) {
        step = 4;
    }
    if (GamePad__2.Down(0x8) != 0) {
        setting->value += step;
    }
    if (GamePad__2.Down(0x4) != 0) {
        setting->value -= step;
    }
    if (GamePad__2.Down(0x2) != 0) {
        setting->value += 100;
    }
    if (GamePad__2.Down(0x1) != 0) {
        setting->value -= 100;
    }
    minimum = command_int[dbinfo.cursor].minimum;
    if (setting->value <= minimum) {
        setting->value = minimum;
    }
    if (GamePad__2.Down(0x20) != 0) {
        if (dbinfo.cursor == DNG_DEBUG_CMD_RUN_EVENT) {
            dbinfo.command = dbinfo.cursor;
            dbinfo.event_no = command_int[dbinfo.cursor].value;
            dngDebugExit();
            return 1;
        }
        if (dbinfo.cursor == DNG_DEBUG_CMD_ENEMY_LOADER) {
            DBGCMD_ReloadEnemy(command_int[DNG_DEBUG_CMD_ENEMY_LOADER].value, dbinfo.first_enemy_load);
            dbinfo.first_enemy_load = 0;
        }
        if (dbinfo.cursor == DNG_DEBUG_CMD_ENEMY_RESET) {
            boxes = DngMainScene->battle_area.treasure_box;
            if (boxes != NULL) {
                for (box = 0; box < 24; box++) {
                    boxes->box[box].Initialize();
                }
            }
            ActiveMonster->Initialize(DngMainScene);
            DngSaveData->SetBitFlag(0x13D, 1);
            dngDebugExit();
            return 1;
        }
        if (dbinfo.cursor == DNG_DEBUG_CMD_SKIP_FLOOR) {
            dungeon = DngSaveDataDungeon->stage_id;
            floor = DngSaveDataDungeon->floor_id[dungeon];
            DngUserData->GetItem(GetGateKeyIndex(dungeon, floor), 1);
            DngUserData->GetItem(GetKeyDoorIndex(dungeon, floor), 1);
            DngUserData->GetItem(0x132, 1);
            DngUserData->GetItem(0x131, 1);
            dngDebugExit();
            return 1;
        }
        if (dbinfo.cursor == DNG_DEBUG_CMD_SOUND_FLAG) {
            if (command_int[dbinfo.cursor].value == 0) {
                DngMainScene->PauseBGM();
            } else {
                DngMainScene->RePlayBGM();
            }
        }
    }
    if (GamePad__2.Down(0x400) != 0) {
        dngDebugExit();
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", dngDebugKey__Fv);
#endif

#ifdef NONMATCHING
// Defined inline in dng_event.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", Initialize__12CTreasureBoxFv);
#endif

#ifdef NONMATCHING
/**
 * Loads a monster kind and places it near the player, resetting its memory when requested.
 */
static void DBGCMD_ReloadEnemy(int monster_no, int reset) {
    CCharacter2  *player;
    CMonsterMan  *monsters;
    mgCMemory    *stack;
    mgCMemory    *memory;
    sceVu0FVECTOR position;
    sceVu0FVECTOR rotation;
    int           slot;
    int           base_index;

    player = DngMainScene->GetCharacter(0);
    if (ActiveMonster != NULL) {
        if (reset != 0) {
            FxScriptMan->AllClearEffSpt();
            BuffEffectScriptData.ClearHeapMem();
            ActiveMonster->Initialize(DngMainScene);
            DngMainScene->AssignStack(3);
            DngMainScene->ClearStack(3);
            stack = DngMainScene->GetStack(3);
            monsters = ActiveMonster;
            for (slot = 0; slot < MONSTER_ACTIVE_MAX; slot++) {
                memory = &monsters->memory[slot];
                memory->stSetBuffer(stack->stAlloc64(4000), 4000);
                memory->stack_used = 0;
                memory->lock = 0;
            }
            sndInitPort(SND_PORT_ENEMY);
        } else {
            stack = DngMainScene->GetStack(3);
        }
        if (ActiveMonster->SearchBaseIndex(monster_no) < 0) {
            ActiveMonster->EntryRefer(monster_no, stack);
        }
        player->GetPosition(position);
        position[0] += 20.0f * (float)rand() / 2147483648.0f - 10.0f;
        position[2] += 20.0f * (float)rand() / 2147483648.0f - 10.0f;
        rotation[3] = 1.0f;
        rotation[2] = 0.0f;
        rotation[1] = 0.0f;
        rotation[0] = 0.0f;
        base_index = ActiveMonster->SearchBaseIndex(monster_no);
        if (base_index != -1) {
            ActiveMonster->SetActiveMonster(base_index, position, rotation, -1);
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DBGCMD_ReloadEnemy__Fii);
#endif

#ifdef NONMATCHING
/**
 * Draws the player position and primitive and scene memory usage.
 */
static void DrawSystemParamInfo() {
    CPreSprite    sprite;
    char          text[2048];
    sceVu0FVECTOR position;
    char         *write;
    mgCMemory    *map_stack;
    mgCMemory    *monster_stack;
    mgCMemory    *event_stack;

    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.TextureMapEnable(0);
    sprite.Begin(MG_PRIM_SPRITE);
    sprite.Color(0x10, 0x10, 0x10, 0x48);
    sprite.Vertex(14, 278, 0);
    sprite.Vertex(260, 412, 0);
    sprite.End();
    DngMainScene->GetCharacter(0)->GetPosition(position);
    write = text;
    write += sprintf(write, "POS %.1f %.1f %.1f\n", position[0], position[1], position[2]);
    write += sprintf(write, "PRIM %d/%d\n", ColPrimMan.ActivePrimNum(), 64);
    map_stack = DngMainScene->GetStack(1);
    monster_stack = DngMainScene->GetStack(3);
    DngMainScene->GetStack(4);
    event_stack = DngMainScene->GetStack(5);
    write += sprintf(write, "STACK:MAP\t %d\n", map_stack->stack_used * 16 / 1024);
    write += sprintf(write, "STACK:MOMS\t %d\n", monster_stack->stack_used * 16 / 1024);
    sprintf(write, "STACK:EVENT  %d/%d\n", (event_stack->stack_size - event_stack->stack_used) * 16 / 1024,
            event_stack->stack_size * 16 / 1024);
    dbFont.DrawDirect(text, 16, 280);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo__Fv);
#endif

#ifdef NONMATCHING
/**
 * Draws the player and targeted monster positions and scene memory usage.
 */
static void DrawSystemParamInfo2() {
    CPreSprite      sprite;
    char            text[2048];
    sceVu0FVECTOR   position;
    sceVu0FVECTOR   monster_position;
    CActionChara   *player;
    CActiveMonster *monster;
    float           height;
    float           width;
    char           *write;
    mgCMemory      *map_stack;
    mgCMemory      *monster_stack;
    mgCMemory      *event_stack;

    sprite.Initialize(NULL, NULL);
    sprite.Preset2D();
    sprite.TextureMapEnable(0);
    sprite.Begin(MG_PRIM_SPRITE);
    sprite.Color(0x10, 0x10, 0x10, 0x48);
    sprite.Vertex(14, 178, 0);
    sprite.Vertex(324, 408, 0);
    sprite.End();
    write = text;
    player = (CActionChara *)DngMainScene->GetCharacter(0);
    player->GetPosition(position);
    if (player->lock_on != 0) {
        monster = ActiveMonster->active[player->target_no - MONSTER_ACTIVE_MAX];
        if (monster != NULL) {
            monster->GetPosition(monster_position);
            height = monster->height;
            width = monster->mons_move_check.radius;
        }
    }
    write += sprintf(write, "POS %.1f %.1f %.1f\n", position[0], position[1], position[2]);
    if (player->lock_on != 0) {
        write += sprintf(write, "MONS POS %.1f %.1f %.1f\n", monster_position[0], monster_position[1], monster_position[2]);
        write += sprintf(write, "MONS HIGH %.1f   WIDTH %.1f\n", height, width);
    }
    write += sprintf(write, "PRIM %d/%d\n", ColPrimMan.ActivePrimNum(), 64);
    map_stack = DngMainScene->GetStack(1);
    monster_stack = DngMainScene->GetStack(3);
    DngMainScene->GetStack(4);
    event_stack = DngMainScene->GetStack(5);
    write += sprintf(write, "STACK:MAP\t %d\n", map_stack->stack_used * 16 / 1024);
    write += sprintf(write, "STACK:MOMS\t %d\n", monster_stack->stack_used * 16 / 1024);
    sprintf(write, "STACK:EVENT  %d/%d\n", (event_stack->stack_size - event_stack->stack_used) * 16 / 1024,
            event_stack->stack_size * 16 / 1024);
    dbFont.DrawDirect(text, 16, 180);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawSystemParamInfo2__Fv);
#endif

#ifdef NONMATCHING
void DrawDebugWindow() {
    if (command_int[DNG_DEBUG_CMD_INFORMATION].value == 2) {
        DrawSystemParamInfo();
    }
    if (command_int[DNG_DEBUG_CMD_INFORMATION].value == 3) {
        DrawSystemParamInfo2();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_debug", DrawDebugWindow__Fv);
#endif

// Static initialiser (.init)
#ifdef NONMATCHING
// The file-scope dbFont definition initializes the font.
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
