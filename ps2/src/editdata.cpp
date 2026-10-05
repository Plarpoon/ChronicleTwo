#include "common.h"
#include "editdata.hpp"
#include <cstring>

// Code (.text)
void EditAnalyzeDataSrc::Init(void) {
    message = NULL;
    percent = 0;
    geo_floor = 0;
    con_no[0] = -1;
    con_no[1] = -1;
    con_no[2] = -1;
    con_no[3] = -1;
    con_no[4] = -1;
    con_no[5] = -1;
    con_no[6] = -1;
    con_no[7] = -1;
    unk_10 = -1;
    on_parts = NULL;
    off_parts = NULL;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", Init__14EditAnalyzeSrcFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetAnalyzeDataSrc__Fii);
void CEditData::Initialize(void) {
    memset(this, 0, sizeof(*this));
    InitPlaceData();
    memset(&analyze, 0, sizeof(analyze));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", InitPlaceData__9CEditDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", SaveData__8CEditMapFP9CEditData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", LoadData__8CEditMapFP9CEditData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetCulturePoint__FP10CEditPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", CultureAnalyzeParts__8CEditMapFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", CultureAnalyze__8CEditMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetOnOffParts__8CEditMapFPcPP9CMapPartsPP9CMapPiecei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", PartsOnOff__8CEditMapFiP9CEditData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetPartsNumID__9CEditDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", Analyze__9CEditDataFiiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", Analize__9CEditDataFiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetAnalyzeData__9CEditDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetAnalyzeSrc__9CEditDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetAnalyzePercent__9CEditDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetAnalyzeFlag__9CEditDataFiiPiPi);
s32 CEditData::GetAnalyzeFlag(s32 map_no, s32 data_no) {
    s32 condition_numbers[EDIT_ANALYZE_CON_NO_MAX];
    s32 condition_flags[EDIT_ANALYZE_CON_NO_MAX];
    return GetAnalyzeFlag(map_no, data_no, condition_numbers, condition_flags);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", dbgSetContintionFlag__9CEditDataFiii);
void CEditData::dbgSetAnalyzeFlag(s32 map_no, s32 data_no, s32 flag) {
    EditAnalyzeDataSrc *request = GetAnalyzeData(map_no, data_no);
    if (request == NULL) {
        return;
    }
    for (s32 i = 0; i < EDIT_ANALYZE_CON_NO_MAX; i++) {
        s8 condition_no = request->con_no[i];
        if (condition_no < 0) {
            break;
        }
        dbgSetContintionFlag(map_no, condition_no, flag);
    }
}
void CEditData::dbgSetAllContintionFlag(int map_no, int flag) {
    int condition_no = 0;
    do {
        s8 *conditions = &analyze.condition[condition_no];
        conditions[0] = flag;
        conditions[1] = flag;
        conditions[2] = flag;
        conditions[3] = flag;
        conditions[4] = flag;
        conditions[5] = flag;
        conditions[6] = flag;
        conditions[7] = flag;
        condition_no += 8;
    } while (condition_no < EDIT_ANALYZE_CONDITION_MAX);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", dbgGetContintionFlag__9CEditDataFiiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", LoadEditAnalyzeData__FiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", LoadEditAnalyzeData__FPciP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaGEO_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaCONDITION__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaCON_NO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaON_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaOFF_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaPERCENT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaEND_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", eaEND_GEO_ANALYZE__FP9SPI_STACKi);
s32 GetMaxPolyn(s32 map_no) {
    s32 max_polygons = 0xFA0;
    if (map_no != 4) {
        max_polygons = 0x1770;
        switch (map_no) {
        case 0:
            return 0xFA0;
        case 1:
            return 0x1770;
        case 2:
            return 0x1770;
        case 3:
            return max_polygons;
        default:
            return 0;
        }
    } else {
        return max_polygons;
    }
}
s32 GetMaxDrawMem(s32 map_no) {
    s32 max_draw_memory = 0xBB80;
    if (map_no != 4) {
        max_draw_memory = 0xD2F0;
        switch (map_no) {
        case 0:
            return 0xBB80;
        case 1:
            return 0xC350;
        case 2:
            return 0xD2F0;
        case 3:
            return max_draw_memory;
        default:
            return 0;
        }
    } else {
        return max_draw_memory;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", __ct__14EditAnalyzeSrcFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", __sinit_editdata_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", tag__6__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_713__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_714__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_917__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1131__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1281__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1282__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1290__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1291__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1292__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1293__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1294__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1295__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1296__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1297__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", at_1298__3__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdata", D_0037B050__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(init_1273, 0x4);
INCLUDE_BSS(eaAnaSrc, 0x4);
INCLUDE_BSS(eaAnaData, 0x4);
INCLUDE_BSS(eaStack, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(AnalyzeSrc, 0x1040);
INCLUDE_BSS(buff_1271, 0x3000);
INCLUDE_BSS(Stack_1272, 0x30);
