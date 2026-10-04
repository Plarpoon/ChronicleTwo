#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", AssignMds__9CMapPieceFP8CMdsInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetPoly__9CMapPieceFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", SetTimeBand__9CMapPieceFff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetMaterial__9CMapPieceFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Step__9CMapPieceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetBoundBox__9CMapPieceFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", DrawSub__9CMapPieceFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Copy__9CMapPieceFR9CMapPieceP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Initialize__9CMapPieceFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", Initialize__8CMdsInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", SearchMdsList__11CMdsListSetFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", GetMdsList__11CMdsListSetFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", SearchMDS__11CMdsListSetFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", LoadPCPFile__11CMdsListSetFPcPUiP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", DeleteMdsList__11CMdsListSetFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", LoadIMGFile__11CMdsListSetFPcP15mgCEnterIMGInfoP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mdslist", DeleteIMG__11CMdsListSetFPc);
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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", pcp_tag);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_729);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_730);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_731);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_732);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_754);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_807);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_828);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_829);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", at_830);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", __vt__8CMdsInfo);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mdslist", __vt__9CMapPiece);

// Small uninitialised data (.sbss)
unsigned char now_mds_num[0x4];
unsigned char max_mds_num[0x4];
unsigned char pcpMdsList[0x4];
unsigned char pcpMdsInfo[0x4];
unsigned char pcpNowMdsInfo[0x4];
unsigned char pcpStack[0x4];
unsigned char pcp_file[0x4];
unsigned char pcpAllScissor[0x4];
