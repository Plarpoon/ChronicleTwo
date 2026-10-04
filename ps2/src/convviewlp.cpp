#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/convviewlp", SVConvViewInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/convviewlp", SVConvViewExit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/convviewlp", SVConvViewLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/convviewlp", InitSaveFileInfoTablePtr__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/convviewlp", SaveDataConvertLoop__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/convviewlp", __sinit_convviewlp_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1072__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1073__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1074__5__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1016__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1017__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1018__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1019__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1020__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1021__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1022__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1023__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1024__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1025__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1026__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1027__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1028__10__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1029__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1030__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1031__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1159__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1160__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1161__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1162__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1163__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1164__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1165__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1166__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1167__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1168__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1169__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", D_0037B0A0__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MovieScene__2, 0x4);
INCLUDE_BSS(ConvMode, 0x4);
INCLUDE_BSS(SlotSelect, 0x4);
INCLUDE_BSS(FileListNum, 0x4);
INCLUDE_BSS(ConvertPhase, 0x4);
INCLUDE_BSS(ConvertFileNum, 0x4);
INCLUDE_BSS(ConvertResult, 0x4);
INCLUDE_BSS(ConvertResultDispTime, 0x34);
INCLUDE_BSS(SaveFileInfoTablePtr, 0x4);
INCLUDE_BSS(SAVEDATA_BUFFER, 0x4);
INCLUDE_BSS(init_817, 0x4);
INCLUDE_BSS(init_820, 0x4);
INCLUDE_BSS(init_823, 0x4);
INCLUDE_BSS(init_826, 0x1);

// Uninitialised data (.bss)
INCLUDE_BSS(DataBuffer__3, 0x30);
INCLUDE_BSS(Stack_ReadBuff__3, 0x30);
INCLUDE_BSS(SaveFileInfoTableSizeConvert, 0x200);
INCLUDE_BSS(buf0_816, 0x30);
INCLUDE_BSS(buf1_819, 0x30);
INCLUDE_BSS(dbuf0_822, 0x30);
INCLUDE_BSS(dbuf1_825, 0x30);
