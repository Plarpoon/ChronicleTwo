#include "common.h"
#include "dynamicanime.hpp"
#include <cstdio>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", BindPosition__FPfPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", ResetPosition__13CDynamicAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", Step__13CDynamicAnimeFv);
int CDACollision::CheckHit(float *position) { return 0; }
void CDynamicAnime::SetWind(float power, float *direction) {
    wind_power = power;
    sceVu0Normalize(wind_dir, direction);
}
void CDynamicAnime::ResetWind(void) {
    wind_power = 0.0f;
}
void CDynamicAnime::SetFloor(float height) {
    floor_enable = 1;
    floor_y = height;
}
void CDynamicAnime::ResetFloor(void) {
    floor_enable = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", FramePose__13CDynamicAnimeFP8mgCFrameP13DA_FRAME_POSE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", PreCollision__13CDynamicAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", Initialize__13CDynamicAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewFrameTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewVertexTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewFixVertexTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewDrawFrameTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewBindVertexTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewBoundingBoxTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", NewCollisionTable__13CDynamicAnimeFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", SetFrame__13CDynamicAnimeFiP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", GetFrame__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", pGetFramePose__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", CheckVertexID__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", SetInitVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", GetInitVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", SetNowVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", SetOldVertex__13CDynamicAnimeFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", pGetFixVertex__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", SetDrawFrame__13CDynamicAnimeFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", GetDrawFrame__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", pGetBindVertex__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", pGetBoundingBox__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", SetCollision__13CDynamicAnimeFiP12CDACollision);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", DrawSub__13CDynamicAnimeFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", Copy__13CDynamicAnimeFR13CDynamicAnimeP8mgCFrameP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFRAME_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFRAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFRAME_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynVERTEX_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynVERTEX__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynVERTEX_L__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynVERTEX_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFIX_VERTEX_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFixVertex__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFIX_VERTEX__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFIX_VERTEX_C__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFIX_VERTEX_S__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFIX_VERTEX_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", FRAME_POSE_Sub__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFRAME_POSE_L__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynFRAME_POSE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynDRAW_FRAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynBIND_VERTEX_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynBIND_VERTEX__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynBIND_VERTEX_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynBOUNDING_BOX_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynBOUNDING_BOX__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynBOUNDING_BOX_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynCOLLISION_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynCOLLISION__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", Initialize__10CDAColPipeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", Initialize__12CDACollisionFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynCOLLISION_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynGRAVITY__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynK__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", dynWind__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", Load__13CDynamicAnimeFPciP8mgCFrameP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dynamicanime", CheckHit__10CDAColPipeFPf);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", dynmc_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_816__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_817__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_818__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_819__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_820__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_821__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_822__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_823__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_824__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_825__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_826__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_827__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_828__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_829__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_830__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_831__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_832__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_833__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_834__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_835__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_836__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_837__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_838__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_839__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_840__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_841__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_842__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_855__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_976__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_977__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_978__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_979__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_1025__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", at_1074__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", __vt__10CDAColPipe__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dynamicanime", __vt__12CDACollision__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(dynNowDA, 0x4);
INCLUDE_BSS(dynStack, 0x4);
INCLUDE_BSS(dynTopFrame, 0x4);
INCLUDE_BSS(dynFrameCount, 0x4);
INCLUDE_BSS(dynVertexCount, 0x4);
INCLUDE_BSS(dynFixVertexCount, 0x4);
INCLUDE_BSS(dynBindVertexCount, 0x4);
INCLUDE_BSS(dynBBoxCount, 0x4);
INCLUDE_BSS(dynColCount, 0x4);
