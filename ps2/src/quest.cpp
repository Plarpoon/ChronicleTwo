#include "common.h"
#include "quest.hpp"
#include "mainloop.hpp"
#include "savedata.hpp"
#include "scriptinterpreter.hpp"
#include "mg_memory.hpp"
#include <cstring>

#ifdef NONMATCHING
static CQuestManager *spi_questman; /**< Request list currently being read from a script. */
static mgCMemory *spi_queststack; /**< Heap used for the request list. */
static QUEST_INFO *spi_quest_info; /**< Request currently being filled. */

static int quest_NUM(SPI_STACK *arguments, int argument_count);
static int quest_NEW(SPI_STACK *arguments, int argument_count);
static int quest_COMMENT(SPI_STACK *arguments, int argument_count);
static int quest_END(SPI_STACK *arguments, int argument_count);

static SPI_TAG_PARAM quest_cmd_tag[] = {
    {"NUM", quest_NUM},
    {"NEW", quest_NEW},
    {"COMMENT", quest_COMMENT},
    {"END", quest_END},
    {NULL, NULL},
};
#endif

// Code (.text)
static CQuestData *GetQuestData() {
    CSaveData *save_data = GetSaveData();
    return save_data != NULL ? &save_data->quest_data : NULL;
}
void CQuestManager::Initialize(void) {
    num = 0;
    info = NULL;
}
QUEST_INFO *CQuestManager::GetQuestInfo(int id) {
    for (int index = 0; index < num; ++index) {
        if (info[index].id == id) {
            return &info[index];
        }
    }
    return NULL;
}
#ifdef NONMATCHING
static int quest_NUM(SPI_STACK *arguments, int argument_count) {
    int request_count = spiGetStackInt(arguments);
    unsigned int allocation_size = request_count * sizeof(QUEST_INFO);
    spi_questman->num = request_count;
    int allocation_quads = (allocation_size + 0xF) / 0x10;
    spi_questman->info = new (spi_queststack->Alloc(allocation_quads + 2)) QUEST_INFO[request_count];
    spi_quest_info = spi_questman->info;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_NUM__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
static int quest_NEW(SPI_STACK *arguments, int argument_count) {
    spi_quest_info->id = spiGetStackInt(arguments);
    strcpy(spi_quest_info->name, spiGetStackString(&arguments[1]));
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_NEW__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
static int quest_COMMENT(SPI_STACK *arguments, int argument_count) {
    int comment_index = spiGetStackInt(arguments);
    char *comment = spiGetStackString(&arguments[1]);
    if (comment_index == 0) {
        strcpy(spi_quest_info->comment, comment);
    }
    if (comment_index > 0) {
        strcpy(spi_quest_info->reaction[comment_index - 1], comment);
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_COMMENT__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
static int quest_END(SPI_STACK *arguments, int argument_count) {
    ++spi_quest_info;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_END__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
void CQuestManager::LoadCfg(mgCMemory *stack, char *script, int script_size) {
    spi_questman = this;
    spi_queststack = stack;
    CScriptInterpreter interpreter;
    interpreter.SetTag(quest_cmd_tag);
    interpreter.SetScript(script, script_size);
    interpreter.Run();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", LoadCfg__13CQuestManagerFP9mgCMemoryPci);
#endif
void CQuestData::Initialize() {
    memset(this, 0, sizeof(*this));
}
#ifdef NONMATCHING
void CQuestData::SetQuestFlag(int id, int flag) {
    if (id >= 0 && id < QUEST_PLAY_DATA_MAX) {
        play[id].accepted = flag;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", SetQuestFlag__10CQuestDataFii);
#endif
#ifdef NONMATCHING
void CQuestData::QuestClear(int id) {
    if (id >= 0 && id < QUEST_PLAY_DATA_MAX) {
        play[id].cleared = 1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", QuestClear__10CQuestDataFi);
#endif
#ifdef NONMATCHING
QUEST_PLAY_DATA *CQuestData::GetPlayQuestData(int id) {
    if (id >= 0 && id < QUEST_PLAY_DATA_MAX) {
        return &play[id];
    }
    return NULL;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", GetPlayQuestData__10CQuestDataFi);
#endif
void QuestRequestSetFlag(int id, int flag) {
    CQuestData *quest_data = GetQuestData();
    if (quest_data != NULL) {
        quest_data->SetQuestFlag(id, flag);
    }
}
void QuestRequestClear(int id, int unused) {
    CQuestData *quest_data = GetQuestData();
    if (quest_data != NULL) {
        quest_data->QuestClear(id);
    }
}
int GetQuestRequestStatus(int id) {
    CQuestData *quest_data = GetQuestData();
    if (quest_data == NULL) {
        return QUEST_REQUEST_STATUS_INVALID;
    }
    QUEST_PLAY_DATA *progress = quest_data->GetPlayQuestData(id);
    if (progress == NULL) {
        return QUEST_REQUEST_STATUS_INVALID;
    }
    if (progress->cleared != 0) {
        return QUEST_REQUEST_STATUS_CLEARED;
    }
    return progress->accepted != 0;
}
#ifdef NONMATCHING
int CMonsterBook::CountKill(int monster_id, int count) {
    if (monster_id < 0 || monster_id >= MONSTER_BOOK_ENTRY_MAX) {
        return 0;
    }
    MONSTER_BOOK_ENTRY &monster = entry[monster_id];
    monster.kill_count += static_cast<u16>(count);
    if (monster.kill_count > MONSTER_BOOK_KILL_MAX) {
        monster.kill_count = MONSTER_BOOK_KILL_MAX;
    }
    return monster.kill_count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", CountKill__12CMonsterBookFii);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/quest", quest_cmd_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/quest", at_878__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/quest", at_879__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/quest", at_880__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/quest", at_881__4__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(spi_questman, 0x4);
INCLUDE_BSS(spi_queststack, 0x4);
INCLUDE_BSS(spi_quest_info, 0x4);
