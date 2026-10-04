#include "common.h"
#include "dataread.hpp"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", TopDir__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", CurrentDir__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_183__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_190__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_369__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_370__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_438__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_439__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_440__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_441__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_530__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_531__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_532__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_533__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_534__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_564__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_571__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_659__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_660__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_713__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", at_714__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dataread", DefaultFileDev__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(header_num, 0x4);
INCLUDE_BSS(packfile_buff, 0x4);
INCLUDE_BSS(data_sector, 0x4);
INCLUDE_BSS(error_cb, 0x4);
INCLUDE_BSS(old_vsync, 0x4);
INCLUDE_BSS(start_vsync, 0x4);
INCLUDE_BSS(CacheAddress, 0x4);
INCLUDE_BSS(NowCacheAddress, 0x4);
INCLUDE_BSS(FileCacheType, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(header_buff, 0x50000);
INCLUDE_BSS(bg_read_info, 0x2400);
INCLUDE_BSS(at_259, 0x100);
INCLUDE_BSS(at_554, 0x10);
INCLUDE_BSS(at_583, 0x100);
INCLUDE_BSS(FileCache, 0x400);
INCLUDE_BSS(at_845, 0x130);
