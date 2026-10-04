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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", npc_spitag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", typetbl_853__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", infocfg_886__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_838__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_839__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_840__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_847__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_898__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_899__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_900__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/npccfg", at_901__3__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(NpcBaseDataTotalNum, 0x4);
INCLUDE_BSS(npc_spi_count_num, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(NpcBaseData, 0x2600);
INCLUDE_BSS(path_885, 0x40);
