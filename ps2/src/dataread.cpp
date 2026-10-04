#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", size_to_sector__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetMainFileDev__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", ChangeHddFile__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", ChangeDefaultFile__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", SetIoErrCallBack__FPFi_i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", SetCurrentDir__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetCurrentDir__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", ChangeDir__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", SearchFile__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", InitReadBG__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", LoadFileBG__FPcP1Pi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetReadBGFile__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetReadBGFile__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", StartReadBG__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", ReadBG__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", ReadBGSync__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", BreakReadBG__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", InitCDFile__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetDevType__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", ConvStr__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetFullPath__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", LoadFile__FPcPvPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", LoadFile2__FPcPvPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", CDRead__FPcPUiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", align_size__FUiUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetNewFileCache__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", InitFileCache__FP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", DeleteFileCache__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", EntryFileCache__FPcP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", LoadFileCacheBG__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", SearchFileCache__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", SearchFileCache__FPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", WriteFile__FPcPvi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetPackFile__FPUiPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetPackFile__FPUiiPPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetPackFileExt__FPUiPcPPUiiPiPPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", GetPackFileNum__FPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", DivPathName__FPcPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dataread", DivPathNameExt__FPcPcPcPc);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", TopDir);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", CurrentDir__2);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_183);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_190);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_369__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_370);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_438);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_439);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_440);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_441);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_530);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_531);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_532);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_533);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_534);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_564);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_571);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_659);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_660);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_713);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_714);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", DefaultFileDev);

// Small uninitialised data (.sbss)
unsigned char header_num[0x4];
unsigned char packfile_buff[0x4];
unsigned char data_sector[0x4];
unsigned char error_cb[0x4];
unsigned char old_vsync[0x4];
unsigned char start_vsync[0x4];
unsigned char CacheAddress[0x4];
unsigned char NowCacheAddress[0x4];
unsigned char FileCacheType[0x4];

// Uninitialised data (.bss)
unsigned char header_buff[0x50000];
unsigned char bg_read_info[0x2400];
unsigned char at_259[0x100];
unsigned char at_554[0x10];
unsigned char at_583[0x100];
unsigned char FileCache[0x400];
unsigned char at_845[0x130];
