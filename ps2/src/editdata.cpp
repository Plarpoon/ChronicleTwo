#include "common.h"
#include "editdata.hpp"
#include <cstring>

// Code (.text)
void EditAnalyzeDataSrc::Init(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s16 *)((u8 *)this + 0x4)) = 0;
    (*(s16 *)((u8 *)this + 0x6)) = 0;
    (*(s8 *)((u8 *)this + 0x8)) = -1;
    (*(s8 *)((u8 *)this + 0x9)) = -1;
    (*(s8 *)((u8 *)this + 0xa)) = -1;
    (*(s8 *)((u8 *)this + 0xb)) = -1;
    (*(s8 *)((u8 *)this + 0xc)) = -1;
    (*(s8 *)((u8 *)this + 0xd)) = -1;
    (*(s8 *)((u8 *)this + 0xe)) = -1;
    (*(s8 *)((u8 *)this + 0xf)) = -1;
    (*(s32 *)((u8 *)this + 0x10)) = -1;
    (*(s32 *)((u8 *)this + 0x14)) = 0;
    (*(s32 *)((u8 *)this + 0x18)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", Init__14EditAnalyzeSrcFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", GetAnalyzeDataSrc__Fii);
void CEditData::Initialize(void) {
    memset(this, 0, 0x5510);
    this->InitPlaceData();
    memset((u8 *) this + 0x5040, 0, 0xD0);
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
s32 CEditData::GetAnalyzeFlag(s32 arg0, s32 arg1) {
    /* Les emplacements de pile portent la taille que le commerce leur donne,
     * lue sur l'ecart entre deux adresses prises, et ils sont declares dans
     * l'ordre croissant de leur decalage : MWCC attribue la pile dans l'ordre
     * des declarations, m2c les ecrit a l'envers. Deux entiers a la place de
     * ces tableaux rendaient un cadre de la moitie, et l'ordre de m2c les
     * echangeait. */
    s32 sp10[8];
    s32 sp30[8];
    return this->GetAnalyzeFlag(arg0, arg1, sp10, sp30);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdata", dbgSetContintionFlag__9CEditDataFiii);
void CEditData::dbgSetAnalyzeFlag(s32 arg0, s32 arg1, s32 arg2) {
    u8 *data;
    s32 i;

    data = (u8 *) this->GetAnalyzeData(arg0, arg1);
    if (data == NULL) {
        return;
    }
    for (i = 0; i < 8; i++) {
        s8 flag = (s8) data[8 + i];
        if (flag < 0) {
            break;
        }
        this->dbgSetContintionFlag(arg0, flag, arg2);
    }
}
void CEditData::dbgSetAllContintionFlag(int a, int b) {
    char *q;
    int i = 0;
    do {
        q = (char *)this + i;
        q[0x5050] = b; q[0x5051] = b; q[0x5052] = b; q[0x5053] = b;
        q[0x5054] = b; q[0x5055] = b; q[0x5056] = b; q[0x5057] = b;
        i += 8;
    } while (i < 64);
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
s32 GetMaxPolyn(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xFA0;
    if (arg0 != 4) {
        var_v0 = 0x1770;
        switch (arg0) {                             /* irregular */
        case 0:
            return 0xFA0;
        case 1:
            return 0x1770;
        case 2:
            return 0x1770;
        case 3:
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        return var_v0;
    }
}
s32 GetMaxDrawMem(s32 arg0) {
    s32 var_v0;

    var_v0 = 0xBB80;
    if (arg0 != 4) {
        var_v0 = 0xD2F0;
        switch (arg0) {                             /* irregular */
        case 0:
            return 0xBB80;
        case 1:
            return 0xC350;
        case 2:
            return 0xD2F0;
        case 3:
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        return var_v0;
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
