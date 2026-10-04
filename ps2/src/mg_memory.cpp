#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", MG_ADDRESS_CHECK__FPvPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", __nw__FUiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", __nwa__FUiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", Init__9mgCMemoryFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", SetHeapMem__9mgCMemoryFP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", ClearHeapMem__9mgCMemoryFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", Free__9mgCMemoryFP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", StartStackMode__9mgCMemoryFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", EndStackMode__9mgCMemoryFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", stAlloc64__9mgCMemoryFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", stAllocTest__9mgCMemoryFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", stAlloc__9mgCMemoryFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", Alloc__9mgCMemoryFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", stAlign64__9mgCMemoryFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", Align64__9mgCMemoryFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", stSetBuffer__9mgCMemoryFP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_memory", mgCopyString__FPcP9mgCMemory);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_memory", at_166);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_memory", at_238);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_memory", at_288);
