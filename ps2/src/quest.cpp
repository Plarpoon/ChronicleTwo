#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", GetQuestData__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", Initialize__13CQuestManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", GetQuestInfo__13CQuestManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_NEW__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_COMMENT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", quest_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", LoadCfg__13CQuestManagerFP9mgCMemoryPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", Initialize__10CQuestDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", SetQuestFlag__10CQuestDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", QuestClear__10CQuestDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", GetPlayQuestData__10CQuestDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", QuestRequestSetFlag__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", QuestRequestClear__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", GetQuestRequestStatus__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/quest", CountKill__12CMonsterBookFii);

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
