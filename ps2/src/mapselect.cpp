#include "common.h"
#include "mapselect.hpp"
#ifdef NONMATCHING
#include "character.hpp"
#include "dataread.hpp"
#include "editdata.hpp"
#include "font.hpp"
#include "gamepad.hpp"
#include "mainloop.hpp"
#include "mg_frame.hpp"
#include "mg_memory.hpp"
#include "savedata.hpp"
#include "scenesnd.hpp"
#include "scriptinterpreter.hpp"
#include "vlgr_info.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

static int MapNameNum;
static MAP_NAME_INFO *map_name;
static int pMapNameBuff;
static int pCharBuff;
static char *CharBuff;
static int now_no;
static u_long128 MapNameBuff[MAP_NAME_BUFF_SIZE];
static mgCMemory *MenuStack;
static int SelectMode;
static int SelectMapType;
static int select_1009;
static int init_1010;
static int SedSel;
static int EventInfoNum;
static int BossEventTop;
static int sel_event;
static int top_event;
static char **SelectMapList[MAP_SEL_TYPE_NUM];
static int SelectMapNum[MAP_SEL_TYPE_NUM];
EVENT_VIEW_INFO *EventInfo;
int BossBattleSelFlag;
extern SPI_TAG_PARAM tag__7[3];
extern char *map_sel_type[MAP_SEL_TYPE_NUM];
extern char SelectMapName[0x100];
extern int select__1049[16];
extern int top__1050[16];
extern int SedSelData[SED_ITEM_NUM];
extern char *config_str[1];
static char *GetLine(char **columns, char *position, char *end);
#endif


// Code (.text)
#ifdef NONMATCHING
/**
 * Initializes the map table and its string buffer from the script count.
 */
static int mlMAP_NAME_NUM(SPI_STACK *arguments, int argument_count) {
    pMapNameBuff = 0;
    pCharBuff = 0;
    MapNameNum = spiGetStackInt(arguments);
    int rows = MapNameNum + 1;
    map_name = (MAP_NAME_INFO *)&MapNameBuff[pMapNameBuff];
    pMapNameBuff += (rows * sizeof(MAP_NAME_INFO)) / 16 + 1;
    CharBuff = (char *)&MapNameBuff[pMapNameBuff];
    for (int index = 0; index < rows; ++index) memset(&map_name[index], 0, sizeof(MAP_NAME_INFO));
    now_no = 0;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", mlMAP_NAME_NUM__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
/**
 * Copies one map entry from script arguments into the map table.
 */
static int mlMAP_NAME(SPI_STACK *arguments, int argument_count) {
    char *strings[3];
    char *copied[3];
    for (int index = 0; index < 3; ++index) {
        strings[index] = spiGetStackString(&arguments[index]);
        if (strings[index] == NULL || strings[index][0] == 0) copied[index] = NULL;
        else {
            copied[index] = &CharBuff[pCharBuff];
            strcpy(copied[index], strings[index]);
            pCharBuff += strlen(strings[index]) + 1;
        }
    }
    MAP_NAME_INFO &entry = map_name[now_no++];
    entry.name = copied[0]; entry.title = copied[1]; entry.add_path = copied[2];
    entry.type = spiGetStackInt(&arguments[3]);
    entry.sel_type = spiGetStackInt(&arguments[4]);
    entry.snd_data_id = argument_count >= 6 ? spiGetStackInt(&arguments[5]) : -1;
    if (argument_count >= 7) entry.area_no = spiGetStackInt(&arguments[6]);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", mlMAP_NAME__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
void LoadMapName(int language, u_long128 *buffer) {
    MapNameNum = 0;
    char path[0x80];
    sprintf(path, "map/map%d.cfg", language);
    int file_size;
    if (LoadFile2(path, buffer, &file_size, 0)) {
        CScriptInterpreter interpreter;
        interpreter.SetTag(tag__7);
        interpreter.SetScript((char *)buffer, file_size);
        interpreter.Run();
        pMapNameBuff += pCharBuff / 16 + 1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", LoadMapName__FiP1);
#endif
#ifdef NONMATCHING
/**
 * Returns a map table entry only for a valid map number.
 */
static MAP_NAME_INFO *GetMapNameInfo(int map_no) {
    if (map_no < 0 || map_no >= MapNameNum) return NULL;
    return &map_name[map_no];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapNameInfo__Fi);
#endif
#ifdef NONMATCHING
char *GetMapPath(char *path, char *name) {
    int length = strlen(name);
    strcpy(path, "map/");
    char first[2] = { name[0], 0 };
    strcat(path, first);
    strcat(path, "/");
    if (length >= 3) {
        char prefix[4] = { name[0], name[1], name[2], 0 };
        strcat(path, prefix);
        strcat(path, "/");
    }
    if (length >= 6) {
        char group[4] = { name[3], name[4], name[5], 0 };
        strcat(path, group);
        strcat(path, "/");
    }
    return strcat(path, name);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapPath__FPcPc);
#endif
#ifdef NONMATCHING
int GetMapType(int map_no) {
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    return entry == NULL ? -1 : entry->type;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapType__Fi);
#endif
#ifdef NONMATCHING
int GetMapAreaNo(int map_no) {
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    return entry == NULL ? -1 : entry->area_no;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapAreaNo__Fi);
#endif
#ifdef NONMATCHING
int GetMapSelType(int map_no) {
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    return entry == NULL ? 0 : entry->sel_type;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapSelType__Fi);
#endif
#ifdef NONMATCHING
int GetMapSndDataID(int map_no) {
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    return entry == NULL ? -1 : entry->snd_data_id;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapSndDataID__Fi);
#endif
#ifdef NONMATCHING
char *GetMapName(int map_no, char **title) {
    if (title != NULL) *title = NULL;
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    if (entry == NULL) return SelectMapName;
    if (title != NULL) *title = entry->title;
    return entry->name;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapName__FiPPc);
#endif
#ifdef NONMATCHING
int SearchMapNo(char *name) {
    if (name == NULL) return -1;
    for (int map_no = 0; map_no < MapNameNum; ++map_no) {
        if (map_name[map_no].name != NULL && strcmp(map_name[map_no].name, name) == 0) return map_no;
    }
    return -1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", SearchMapNo__FPc);
#endif
#ifdef NONMATCHING
char *GetMapTitle(int map_no) {
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    return entry == NULL ? NULL : entry->title;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetMapTitle__Fi);
#endif
#ifdef NONMATCHING
char *GetAddMapPath(int map_no) {
    MAP_NAME_INFO *entry = GetMapNameInfo(map_no);
    return entry == NULL ? NULL : entry->add_path;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetAddMapPath__Fi);
#endif
#ifdef NONMATCHING
void InitMapSelect(mgCMemory *stack) {
    MenuStack = stack;
    SetCurrentDir(NULL);
    int list_size;
    LoadFile((char *)"map/map.lst", read_buffer, &list_size);
    for (int type = 0; type < MAP_SEL_TYPE_NUM; ++type) {
        SelectMapNum[type] = 0;
        SelectMapList[type] = (char **)stack->Alloc(0x22);
        for (int index = 0; index < SELECT_MAP_MAX; ++index) SelectMapList[type][index] = NULL;
    }
    SelectMode = MAP_SELECT_MODE_TYPE;
    input_str lines;
    lines.buffer = (char *)read_buffer;
    lines.size = list_size;
    char line[0x100];
    if (lines.GetLine(line, sizeof(line), NULL) && lines.GetLine(line, sizeof(line), NULL)) {
        do {
            for (char *letter = line; *letter != 0; ++letter) {
                if (*letter == '\\') *letter = '/';
            }
            bool shared_map = false;
            for (char *letter = line; *letter != 0; ++letter) {
                if (strncmp(letter, "cmn", 3) == 0) { shared_map = true; break; }
            }
            if (line[0] == 0 || shared_map) continue;
            char directory[0x80], name[0x80], extension[0x80];
            DivPathNameExt(line, directory, name, extension);
            int type = GetMapSelType(SearchMapNo(name));
            if (type >= 0 && type < MAP_SEL_TYPE_NUM && SelectMapNum[type] < SELECT_MAP_MAX) {
                SelectMapList[type][SelectMapNum[type]++] = mgCopyString(name, stack);
            }
        } while (lines.GetLine(line, sizeof(line), NULL));
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", InitMapSelect__FP9mgCMemory);
#endif
#ifdef NONMATCHING
/**
 * Steps and draws the debug map category picker.
 */
static int MapTypeSelect() {
    if (!init_1010) { select_1009 = 0; init_1010 = 1; }
    if (GamePad__2.Down(PAD_UP)) --select_1009;
    if (GamePad__2.Down(PAD_DOWN)) ++select_1009;
    if (select_1009 < 0) select_1009 = MAP_SEL_TYPE_NUM - 1;
    if (select_1009 >= MAP_SEL_TYPE_NUM) select_1009 = 0;
    if (GamePad__2.Down(PAD_CIRCLE) && SelectMapNum[select_1009] > 0) {
        SelectMapType = select_1009;
        SelectMode = MAP_SELECT_MODE_MAP;
    }
    if (GamePad__2.Down(PAD_CROSS)) SelectMode = MAP_SELECT_MODE_CANCEL;
    char display[0x400];
    char *cursor = display;
    cursor += sprintf(cursor, "\n\n");
    for (int type = 0; type < MAP_SEL_TYPE_NUM; ++type) {
        cursor += sprintf(cursor, "%s%s%s\n", type == select_1009 ? ">>" : "  ", map_sel_type[type], type == select_1009 ? "<<" : "");
    }
    GetDebugFont()->DrawDirect(display, 10, 10);
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", MapTypeSelect__Fv);
#endif
#ifdef NONMATCHING
/**
 * Steps and draws the maps in the selected category.
 */
static int MapSelect() {
    int &selected = select__1049[SelectMapType];
    int &top = top__1050[SelectMapType];
    int row = selected - top;
    if (GamePad__2.Down(PAD_UP)) --selected;
    if (GamePad__2.Down(PAD_DOWN)) ++selected;
    bool paged = false;
    if (GamePad__2.Down(PAD_L1)) { top -= 8; paged = true; }
    if (GamePad__2.Down(PAD_R1)) { top += 8; paged = true; }
    int count = SelectMapNum[SelectMapType];
    if (selected < 0) selected = 0;
    if (selected >= count) selected = count - 1;
    if (!paged) {
        if (selected - top >= 8) ++top;
        if (selected < top) --top;
    }
    if (top + 8 >= count) top = count - 8;
    if (top < 0) top = 0;
    if (paged) selected = top + row;
    int chosen_map = SearchMapNo(SelectMapList[SelectMapType][selected]);
    char display[0x800];
    char *cursor = display;
    cursor += sprintf(cursor, "\n\nMapNo = %d\n", chosen_map);
    int last = top + 8;
    if (last > count) last = count;
    for (int index = top; index < last; ++index) {
        char *name = SelectMapList[SelectMapType][index];
        int map_no = SearchMapNo(name);
        char *title = NULL;
        GetMapName(map_no, &title);
        cursor += sprintf(cursor, "%s%s%s", index == selected ? ">>" : "  ", name, map_no < 0 ? "    *" : "    ");
        if (title != NULL) cursor += sprintf(cursor, "%s", title);
        cursor += sprintf(cursor, "%s\n", index == selected ? "<<" : "");
    }
    GetDebugFont()->DrawDirect(display, 10, 10);
    if (GamePad__2.Down(PAD_CROSS)) SelectMode = MAP_SELECT_MODE_TYPE;
    if (GamePad__2.Down(PAD_CIRCLE)) {
        strcpy(SelectMapName, SelectMapList[SelectMapType][selected]);
        SelectMode = MAP_SELECT_MODE_DECIDE;
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", MapSelect__Fv);
#endif
#ifdef NONMATCHING
int MapSelectLoop() {
    switch (SelectMode) {
    case MAP_SELECT_MODE_CANCEL: return MAP_SELECT_CANCEL;
    case MAP_SELECT_MODE_DECIDE: return MAP_SELECT_DECIDE;
    case MAP_SELECT_MODE_TYPE: MapTypeSelect(); return MAP_SELECT_CONTINUE;
    case MAP_SELECT_MODE_MAP: MapSelect(); return MAP_SELECT_CONTINUE;
    default: return MAP_SELECT_CONTINUE;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", MapSelectLoop__Fv);
#endif
void InitSaveDataEdit(mgCMemory *stack) {
}
#ifdef NONMATCHING
int SaveDataEditLoop() {
    CScene *scene = GetMainScene();
    CSaveData *save = GetSaveData();
    SedSelData[SED_PLAY_TIME] = GetPlayTimeCountFlag();
    GAME_PROGRESS_INFO *progress = GetGameProgressInfo(SedSelData[SED_PROGRESS]);
    char *progress_name = progress == NULL ? NULL : progress->name;
    const char *marker[2] = {"  ", ">>"};
    const char *on_off[2] = {"OFF", "ON"};
    char display[0x800];
    char *cursor = display;
    cursor += sprintf(cursor, "Save Data Editer\n\n");
    cursor += sprintf(cursor, "%sPROGRESS  %d(%s)\n", marker[SedSel == SED_PROGRESS], SedSelData[SED_PROGRESS], progress_name == NULL ? "" : progress_name);
    cursor += sprintf(cursor, "%sTIME      %5.1f\n", marker[SedSel == SED_TIME], save->now_time);
    cursor += sprintf(cursor, "%sFLAG      %4d = %s\n", marker[SedSel == SED_FLAG], SedSelData[SED_FLAG], on_off[save->GetBitFlag(SedSelData[SED_FLAG]) != 0]);
    cursor += sprintf(cursor, "%sGEO COMP  %d\n", marker[SedSel == SED_GEO_COMP], SedSelData[SED_GEO_COMP]);
    cursor += sprintf(cursor, "%sPLAY TIME %d\n", marker[SedSel == SED_PLAY_TIME], SedSelData[SED_PLAY_TIME]);
    cursor += sprintf(cursor, "%sCONFIG    %s = %d\n", marker[SedSel == SED_CONFIG], config_str[0], save->config.caption_off);
    SedSelData[SED_PROGRESS] = save->game_progress;
    if (SedSel == SED_PROGRESS) {
        if (GamePad__2.Down(PAD_RIGHT)) ++SedSelData[SED_PROGRESS];
        if (GamePad__2.Down(PAD_LEFT)) --SedSelData[SED_PROGRESS];
        if (SedSelData[SED_PROGRESS] <= 0) SedSelData[SED_PROGRESS] = 1;
        if (SedSelData[SED_PROGRESS] >= GetGameProgressNum()) SedSelData[SED_PROGRESS] = GetGameProgressNum() - 1;
        save->game_progress = SedSelData[SED_PROGRESS];
    }
    if (SedSel == SED_TIME) {
        int hour = (int)save->now_time;
        if (GamePad__2.Down(PAD_RIGHT)) ++hour;
        if (GamePad__2.Down(PAD_LEFT)) --hour;
        hour %= 24;
        if (GamePad__2.Down(PAD_TRIANGLE)) hour = 0;
        scene->SetTime((float)hour);
        save->now_time = (float)hour;
    }
    if (SedSel == SED_FLAG) {
        if (GamePad__2.Down(PAD_RIGHT)) ++SedSelData[SED_FLAG];
        if (GamePad__2.Down(PAD_LEFT)) --SedSelData[SED_FLAG];
        if (GamePad__2.Down(PAD_R1)) SedSelData[SED_FLAG] += 10;
        if (GamePad__2.Down(PAD_L1)) SedSelData[SED_FLAG] -= 10;
        if (GamePad__2.Down(PAD_R2)) SedSelData[SED_FLAG] += 100;
        if (GamePad__2.Down(PAD_L2)) SedSelData[SED_FLAG] -= 100;
        if (SedSelData[SED_FLAG] < 0) SedSelData[SED_FLAG] = 0;
        if (GamePad__2.Down(PAD_CIRCLE)) save->SetBitFlag(SedSelData[SED_FLAG], !save->GetBitFlag(SedSelData[SED_FLAG]));
    }
    if (SedSel == SED_GEO_COMP) {
        if (GamePad__2.Down(PAD_RIGHT)) ++SedSelData[SED_GEO_COMP];
        if (GamePad__2.Down(PAD_LEFT)) --SedSelData[SED_GEO_COMP];
        if (SedSelData[SED_GEO_COMP] < 0) SedSelData[SED_GEO_COMP] = 0;
        if (GamePad__2.Down(PAD_CIRCLE) || GamePad__2.Down(PAD_TRIANGLE)) {
            DebugInfo.georama_debug = 1;
            CEditData *edit = save->GetEditData(SedSelData[SED_GEO_COMP]);
            if (edit != NULL) edit->dbgSetAllContintionFlag(SedSelData[SED_GEO_COMP], GamePad__2.Down(PAD_CIRCLE));
        }
    }
    if (SedSel == SED_PLAY_TIME) {
        if (GamePad__2.Down(PAD_RIGHT)) SedSelData[SED_PLAY_TIME] = 1;
        if (GamePad__2.Down(PAD_LEFT)) SedSelData[SED_PLAY_TIME] = 0;
        PlayTimeCount(SedSelData[SED_PLAY_TIME]);
    }
    if (SedSel == SED_CONFIG) {
        if (GamePad__2.Down(PAD_RIGHT)) ++SedSelData[SED_CONFIG];
        if (GamePad__2.Down(PAD_LEFT)) --SedSelData[SED_CONFIG];
        SedSelData[SED_CONFIG] = 0;
        if (GamePad__2.Down(PAD_CIRCLE)) save->config.caption_off = !save->config.caption_off;
    }
    if (GamePad__2.Down(PAD_DOWN)) ++SedSel;
    if (GamePad__2.Down(PAD_UP)) --SedSel;
    if (SedSel < 0) SedSel = SED_ITEM_NUM - 1;
    if (SedSel >= SED_ITEM_NUM) SedSel = 0;
    GetDebugFont()->DrawDirect(display, 10, 10);
    return GamePad__2.Down(PAD_CROSS) != 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", SaveDataEditLoop__Fv);
#endif
#ifdef NONMATCHING
int EventViewLoop() {
    char display[0x480];
    char *cursor = display;
    cursor += sprintf(cursor, "\nEvent \n");
    if (BossBattleSelFlag) {
        if (top_event < BossEventTop) top_event = BossEventTop;
        BossBattleSelFlag = 0;
    }
    const char *marker[2] = {"  ", ">>"};
    int last = top_event + 10;
    if (last > EventInfoNum) last = EventInfoNum;
    for (int index = top_event; index < last; ++index) {
        EVENT_VIEW_INFO &entry = EventInfo[index];
        if (entry.name != NULL) cursor += sprintf(cursor, "%s%s   %s\n", marker[index == top_event + sel_event], entry.name, entry.detail);
    }
    GetDebugFont()->DrawDirect(display, 10, 10);
    if (GamePad__2.Down(PAD_UP)) --sel_event;
    if (GamePad__2.Down(PAD_DOWN)) ++sel_event;
    if (GamePad__2.Down(PAD_LEFT | PAD_L1)) top_event -= 10;
    if (GamePad__2.Down(PAD_RIGHT | PAD_R1)) top_event += 10;
    if (top_event < 0) top_event = 0;
    if (top_event >= EventInfoNum - 1) top_event -= 10;
    if (sel_event < 0) {
        sel_event = 9;
        if (top_event + 9 >= EventInfoNum) sel_event = EventInfoNum - top_event - 1;
    }
    if (sel_event >= 10 || top_event + sel_event >= EventInfoNum) sel_event = 0;
    if (GamePad__2.Down(PAD_CIRCLE)) {
        EVENT_VIEW_INFO &entry = EventInfo[top_event + sel_event];
        if (entry.map_no >= 0) {
            INIT_LOOP_ARG arg;
            memset(&arg, 0, sizeof(arg));
            arg.map_no = entry.map_no;
            arg.floor_no = entry.floor_no;
            arg.event_no = entry.event_no;
            NextLoop(entry.dungeon ? LOOP_DUNGEON : LOOP_EDIT, arg);
            return EVENT_VIEW_START;
        }
    }
    return GamePad__2.Down(PAD_CROSS) ? EVENT_VIEW_CANCEL : EVENT_VIEW_CONTINUE;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", EventViewLoop__Fv);
#endif
#ifdef NONMATCHING
void LoadEventViewData(u_long128 *buffer, mgCMemory *stack) {
    int file_size;
    if (!LoadFile2((char *)"event/view_pal.txt", buffer, &file_size, 0)) return;
    EventInfo = (EVENT_VIEW_INFO *)stack->Alloc(0x382);
    for (int index = 0; index < EVENT_VIEW_MAX; ++index) memset(&EventInfo[index], 0, sizeof(EVENT_VIEW_INFO));
    EventInfoNum = 0;
    BossEventTop = 0;
    char fields[16][0x80];
    char *columns[16];
    for (int index = 0; index < 16; ++index) columns[index] = fields[index];
    char *end = (char *)buffer + file_size;
    char *next = GetLine(columns, (char *)buffer, end);
    while (next < end && EventInfoNum < EVENT_VIEW_MAX) {
        next = GetLine(columns, next, end);
        EVENT_VIEW_INFO &entry = EventInfo[EventInfoNum++];
        entry.map_no = SearchMapNo(columns[0]);
        entry.floor_no = 0;
        entry.dungeon = 0;
        if (columns[1][0] != 0) {
            entry.map_no = atoi(columns[1]) - 1;
            entry.floor_no = atoi(columns[2]);
            entry.dungeon = 1;
        }
        entry.event_no = atoi(columns[3]);
        entry.name = mgCopyString(columns[6], stack);
        entry.detail = mgCopyString(columns[7], stack);
        if (strcmp(columns[8], "B") != 0) ++BossEventTop;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", LoadEventViewData__FP1P9mgCMemory);
#endif
#ifdef NONMATCHING
/**
 * Splits a tab-separated event record into its columns.
 */
static char *GetLine(char **columns, char *position, char *end) {
    int column = 0;
    int length = 0;
    for (int index = 0; index < 16; ++index) if (columns[index] != NULL) columns[index][0] = 0;
    while (position < end) {
        if (*position == '\r' || *position == '\n') {
            if (*position == '\r' && position + 1 < end && position[1] == '\n') ++position;
            ++position;
            break;
        }
        if (*position == '\t') {
            if (column < 16 && columns[column] != NULL) columns[column][length] = 0;
            ++column; length = 0;
        } else if (*position != ' ' && column < 16 && columns[column] != NULL && length < 0x7F) {
            columns[column][length++] = *position;
        }
        ++position;
    }
    if (column < 16 && columns[column] != NULL) columns[column][length] = 0;
    return position;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", GetLine__FPPcPcPc__3);
#endif
#ifdef NONMATCHING
void AtraMiriaOnOff(int type, CCharacter2 *chara, int on) {
    if (chara == NULL || chara->CObjectFrame::frame == NULL) return;
    mgCFrame *model = chara->CObjectFrame::frame;
    if (type == 0) {
        mgCFrame *atlamillia = model->SearchFrame((char *)"atoramiria");
        mgCFrame *cord = model->SearchFrame((char *)"himo");
        if (atlamillia != NULL)
            atlamillia->attr->draw = on ? MG_FRAME_DRAW_VISIBLE | MG_FRAME_DRAW_SKIP_BY_PARENT : MG_FRAME_DRAW_SKIP_CHILDREN;
        if (cord != NULL)
            cord->attr->draw = on ? MG_FRAME_DRAW_VISIBLE : MG_FRAME_DRAW_SKIP_CHILDREN;
    }
    if (type == 1) {
        mgCFrame *atlamillia = model->SearchFrame((char *)"atoramiria");
        if (atlamillia != NULL)
            atlamillia->attr->draw = on ? MG_FRAME_DRAW_VISIBLE : MG_FRAME_DRAW_SKIP_CHILDREN;
    }
    if (type == 2) {
        mgCFrame *gem = model->SearchFrame((char *)"atora");
        if (gem != NULL)
            gem->attr->draw = on ? MG_FRAME_DRAW_VISIBLE | MG_FRAME_DRAW_SKIP_BY_PARENT : MG_FRAME_DRAW_SKIP_CHILDREN;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapselect", AtraMiriaOnOff__FiP11CCharacter2i);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", map_sel_type__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", SelectMapName__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", tag__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", select__1049__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", top__1050__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", SedSelData__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_792__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_793__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_794__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_795__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_796__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_797__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_798__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_799__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_800__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_801__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_842__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_859__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_860__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1004__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1005__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1040__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1041__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1042__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1043__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1044__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1045__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1103__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1104__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1105__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1117__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1126__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1127__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1222__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1223__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1224__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1225__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1226__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1227__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1228__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1323__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1324__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1372__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1373__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1469__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1470__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1471__3__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", config_str__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1125__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1128__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1270__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapselect", at_1377__2__DATA);

// Small uninitialised data (.sbss)
#ifndef NONMATCHING
INCLUDE_BSS(MapNameNum, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(map_name, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(pMapNameBuff, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(pCharBuff, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(CharBuff, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(now_no, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(MenuStack, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(SelectMode, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(SelectMapType, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(select_1009, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(init_1010, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(SedSel, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(EventInfo, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(EventInfoNum, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(BossEventTop, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(sel_event, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(top_event, 0x4);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(BossBattleSelFlag, 0x4);
#endif

// Uninitialised data (.bss)
#ifndef NONMATCHING
INCLUDE_BSS(MapNameBuff, 0x8000);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(SelectMapList, 0x20);
#endif
#ifndef NONMATCHING
INCLUDE_BSS(SelectMapNum, 0x20);
#endif
