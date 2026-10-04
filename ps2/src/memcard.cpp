#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CopyMCBrowserName__FiPcPUs);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetDngTreeFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeMemoryCardFileName__FiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeMemoryCardAlbumName__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeCheckDigit__FiPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", __ct__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", Initialize__18CMemoryCardManagerFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", InitSaveFileInfoTable__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetOpenAttribute__18CMemoryCardManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", InitError__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", InitForMC__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", FinishForMC__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetBuff_Album__18CMemoryCardManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetIconData__18CMemoryCardManagerFP12MC_ICON_DATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetIconDataSize__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetSaveDataSize__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetFuncNo__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetFuncNo__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CheckMaxUniqueCounter__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetUpdateFile__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CheckDataFileNum__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CheckOmake__18CMemoryCardManagerFPUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CheckDebugCode__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", InitPlayDataInfo__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", UpDateViewInfo__18CMemoryCardManagerFP13SAVEDATA_INFOP15SAVEDATA_FORMAT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", Step__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetVersion__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SearchMcType__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", Write__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", Convert__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeDir__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetCostumeList__FUliPs);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SaveToMc__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", LoadFromMc__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SaveAlbum__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", LoadAlbum__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CheckAlbum__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SaveOamkeFile__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", LoadOmakeFile__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CheckOmakeFile__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", Format__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", DeleteFile__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", McError__18CMemoryCardManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", UnFormat__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetSaveFileInfoFromMc__18CMemoryCardManagerFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetAllSaveFileInfo__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", McCheckMCPs2__FP12MC_CARD_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", McCheckMCPs2Boot__FP12MC_CARD_INFOi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetCosInfo__Fi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", cosbit_table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", MCBrowsetName);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", MCBrowserName_Offset);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_838__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_839__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1031__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1032__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1033__8);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1034__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2131__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2297);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_808__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_809__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_810__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_811__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_812__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_813__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_814__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_815__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_816__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_817__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_818__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_819__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_843__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_852__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_922__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_923__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_924__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1036__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1229__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1230__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1315__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1453__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1454__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1455__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1456__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1581__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1582__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1679__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1680__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1681);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1953);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1954);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2083__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2285);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", NowProgramLoopNo);

// Small uninitialised data (.sbss)
unsigned char DngTreeSaveFlag[0x4];
unsigned char old_format_1242[0x4];
unsigned char iconNo_1323[0x4];
unsigned char init_1324[0x4];
unsigned char test_write_num_1476[0x4];
unsigned char init_1477[0x4];
unsigned char SubGameOmakeTempBuffer[0x4];
unsigned char ReadFileNo_2290[0x4];
unsigned char init_2291[0x4];
