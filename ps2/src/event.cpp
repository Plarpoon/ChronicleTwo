#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", LoadNpcTalkMes__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", ResetNpcTalkMes__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", GetSquareEvent__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", InitEvent__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", SetEventScript__FPcPcP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", RunEvent__FiP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", EventDoorLoop__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", StartEventSyori__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", SkipEventStart__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", SkipEvent__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", CheckEventSkip__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", EventLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", GetEventMessage__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", GetActiveCamera__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", GetCharacter__Fi);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event", __sinit_event_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event", vv_984);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event", at_819__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event", at_820__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event", at_1002__4);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event", D_0037B038);

// Small uninitialised data (.sbss)
unsigned char EventScene[0x4];
unsigned char cnt_1056[0x4];

// Uninitialised data (.bss)
unsigned char EventScript[0x60];
