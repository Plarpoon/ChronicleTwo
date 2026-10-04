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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1072__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1073__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1074__5);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1016__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1017__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1018__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1019__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1020__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1021__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1022__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1023__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1024__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1025__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1026__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1027__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1028__10);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1029__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1030__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1031__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1159__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1160__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1161__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1162__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1163__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1164__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1165__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1166__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1167__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1168);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", at_1169);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/convviewlp", D_0037B0A0);

// Small uninitialised data (.sbss)
unsigned char MovieScene__2[0x4];
unsigned char ConvMode[0x4];
unsigned char SlotSelect[0x4];
unsigned char FileListNum[0x4];
unsigned char ConvertPhase[0x4];
unsigned char ConvertFileNum[0x4];
unsigned char ConvertResult[0x4];
unsigned char ConvertResultDispTime[0x34];
unsigned char SaveFileInfoTablePtr[0x4];
unsigned char SAVEDATA_BUFFER[0x4];
unsigned char init_817[0x4];
unsigned char init_820[0x4];
unsigned char init_823[0x4];
unsigned char init_826[0x1];

// Uninitialised data (.bss)
unsigned char DataBuffer__3[0x30];
unsigned char Stack_ReadBuff__3[0x30];
unsigned char SaveFileInfoTableSizeConvert[0x200];
unsigned char buf0_816[0x30];
unsigned char buf1_819[0x30];
unsigned char dbuf0_822[0x30];
unsigned char dbuf1_825[0x30];
