#include "common.h"
#include "memcard.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", CopyMCBrowserName__FiPcPUs);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetDngTreeFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeMemoryCardFileName__FiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeMemoryCardAlbumName__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", MakeCheckDigit__FiPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", __ct__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", Initialize__18CMemoryCardManagerFP9mgCMemory);
void CMemoryCardManager::InitSaveFileInfoTable(void) {
    s32 entry_no;
    s32 entry_offset;
    CMemoryCardManager *entry_base;

    entry_offset = 0;
    entry_no = 0;
    do {
        entry_base = (CMemoryCardManager *)((u8 *)this + entry_offset);
        memset(&entry_base->dir_table[0], 0, sizeof(MC_DIR_ENTRY));
        entry_no += 1;
        entry_base->dir_table[0].name[0] = 0;
        entry_offset += sizeof(MC_DIR_ENTRY);
    } while (entry_no < 17);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetOpenAttribute__18CMemoryCardManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", InitError__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", InitForMC__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", FinishForMC__18CMemoryCardManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetBuff_Album__18CMemoryCardManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", SetIconData__18CMemoryCardManagerFP12MC_ICON_DATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/memcard", GetIconDataSize__18CMemoryCardManagerFv);
s32 CMemoryCardManager::GetSaveDataSize(s32 type) {
    s32 size;

    size = 0;
    if (type == MC_SIZE_SAVE_TOTAL) {
        size = (GetIconDataSize() + 0x19A) << 0xA;
    }
    if (type == MC_SIZE_SAVE_FILE) {
        size = sizeof(SAVEDATA_FORMAT);
    }
    if (type == MC_SIZE_ALBUM_FILE) {
        size = 0x64CB0;
    }
    if (type == MC_SIZE_ICONS) {
        size = GetIconDataSize() << 0xA;
    }
    if (type == MC_SIZE_ALBUM_TOTAL) {
        size = (GetIconDataSize() << 0xA) + 0x654B0;
    }
    if (type == MC_SIZE_SAVE_KB) {
        size = GetIconDataSize() + 0x199;
    }
    if (type == MC_SIZE_UNK_6) {
        size = 0x20800;
    }
    if (type == MC_SIZE_OMAKE_FILE) {
        size = sizeof(CSubGameData);
    }
    if (type == MC_SIZE_OMAKE_TOTAL) {
        size = (GetIconDataSize() << 0xA) + 0x5C70;
    }
    if (type == MC_SIZE_OMAKE_KB) {
        size = GetIconDataSize() + 0x1B;
    }
    return size;
}
void CMemoryCardManager::SetFuncNo(s32 operation) {
    func_no = operation;
    step = 0;
    if (operation == MC_FUNC_IDLE) {
        search_wait = 11;
    }
}
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
s32 CMemoryCardManager::Convert(void) {
    return 1;
}
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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", cosbit_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", MCBrowsetName__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", MCBrowserName_Offset__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_838__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_839__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1031__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1032__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1033__8__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1034__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2131__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2297__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_808__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_809__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_810__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_811__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_812__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_813__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_814__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_815__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_816__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_817__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_818__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_819__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_843__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_852__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_922__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_923__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_924__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1036__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1229__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1230__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1315__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1453__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1454__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1455__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1456__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1581__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1582__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1679__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1680__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1681__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1953__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_1954__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2083__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", at_2285__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/memcard", NowProgramLoopNo__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(DngTreeSaveFlag, 0x4);
INCLUDE_BSS(old_format_1242, 0x4);
INCLUDE_BSS(iconNo_1323, 0x4);
INCLUDE_BSS(init_1324, 0x4);
INCLUDE_BSS(test_write_num_1476, 0x4);
INCLUDE_BSS(init_1477, 0x4);
INCLUDE_BSS(SubGameOmakeTempBuffer, 0x4);
INCLUDE_BSS(ReadFileNo_2290, 0x4);
INCLUDE_BSS(init_2291, 0x4);
