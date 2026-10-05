#include "common.h"
#include "mdslist.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", AssignMds__9CMapPieceFP8CMdsInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetPoly__9CMapPieceFiP6CCPolyR9mgVu0FBOXi);
void CMapPiece::SetTimeBand(float start, float end) {
    time_start = start;
    time_end = end;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetMaterial__9CMapPieceFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Step__9CMapPieceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetBoundBox__9CMapPieceFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", DrawSub__9CMapPieceFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Copy__9CMapPieceFR9CMapPieceP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Initialize__9CMapPieceFv);
void CMdsInfo::Initialize(void) {
    name = NULL;
    type = MDS_TYPE_MODEL;
    frame = NULL;
    chara = NULL;
    far_dist = -1.0f;
    far_fade = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", SearchMdsList__11CMdsListSetFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetMdsList__11CMdsListSetFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", SearchMDS__11CMdsListSetFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", LoadPCPFile__11CMdsListSetFPcPUiP9mgCMemoryi);
s32 CMdsListSet::DeleteMdsList(char *name) {
    CMdsList *mds_list = SearchMdsList(name);
    if (mds_list == NULL) {
        return 0;
    }
    mds_list->name = NULL;
    mds_list->num = 0;
    mds_list->list = NULL;
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", LoadIMGFile__11CMdsListSetFPcP15mgCEnterIMGInfoP9mgCMemory);
void CMdsListSet::DeleteIMG(char *name) {
    CIMGList *img_list = SearchIMGList(name);
    if (img_list != NULL) {
        img_list->name = NULL;
        img_list->info = NULL;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", SearchIMGList__11CMdsListSetFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetTextureBlockNo__11CMdsListSetFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Initialize__11CMdsListSetFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetList__8CMdsListFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetListID__8CMdsListFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetList__8CMdsListFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", LoadIMGFile__8CIMGListFPcP15mgCEnterIMGInfoP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", pcpMDS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", pcpTYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", pcpFAR_CLIP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", pcpMDS_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", LoadPCPFile__8CMdsListFPcPUiP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", __ct__8CMdsInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", CreateChara__FPUiPcP9mgCMemory);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", pcp_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_729__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_730__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_731__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_732__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_754__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_807__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_828__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_829__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_830__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", __vt__8CMdsInfo__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", __vt__9CMapPiece__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(now_mds_num, 0x4);
INCLUDE_BSS(max_mds_num, 0x4);
INCLUDE_BSS(pcpMdsList, 0x4);
INCLUDE_BSS(pcpMdsInfo, 0x4);
INCLUDE_BSS(pcpNowMdsInfo, 0x4);
INCLUDE_BSS(pcpStack, 0x4);
INCLUDE_BSS(pcp_file, 0x4);
INCLUDE_BSS(pcpAllScissor, 0x4);
