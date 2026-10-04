#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", _NPC_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", _NPC_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", LoadNPCCfg__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", GetPartyCharaMessage__Fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", GetNPCModelName__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", GetNPCName__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", GetPartyCharaModelName__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/npccfg", GetPartyNPCData__Fi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", npc_spitag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", typetbl_853);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", infocfg_886);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_838__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_839__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_840__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_847__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_898__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_899__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_900__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_901__3);

// Small uninitialised data (.sbss)
unsigned char NpcBaseDataTotalNum[0x4];
unsigned char npc_spi_count_num[0x4];

// Uninitialised data (.bss)
unsigned char NpcBaseData[0x2600];
unsigned char path_885[0x40];
