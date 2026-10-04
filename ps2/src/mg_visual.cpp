#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", GetScrPad__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SendDMA__FPvi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", mgSetPkTEX0__FPUiUlUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", mgSetPkTEX0__FPUiUlUlUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", mgSetPkTexFlush_TagCnt__FPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetPointLight__FPUiPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetMaterialRef__12mgCVisualMDTFP1P10mgMateriali);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetPModeRef__12mgCVisualMDTFP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Initialize__13mgCVisualAttrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", __ct__13mgCVisualAttrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", GetTextureManager__9mgCVisualFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetDrawEnvGifTag__9mgCVisualFP1P13mgRENDER_INFOP10mgCDrawEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Initialize__12mgCVisualMDTFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CopyMaterial__FP10mgMaterialP13MDT_MATERIAL_P17mgCTextureManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CopyMDTData__12mgCVisualMDTFP10MDT_HEADERP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CopyMDTDataPointer__12mgCVisualMDTFP10MDT_HEADERP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", GetMaterial__12mgCVisualMDTFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", GetColor__12mgCVisualMDTFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateBBox__12mgCVisualMDTFPfPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateFace__12mgCVisualMDTFP8FACES_IDP9mgCMemoryP9mgCMemoryPP7mgCFace);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", DataAssignMDT__12mgCVisualMDTFP10MDT_HEADERP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", DataAssignMDT__15mgCVisualFixMDTFP10MDT_HEADERP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Draw__12mgCVisualMDTFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreatePacket__12mgCVisualMDTFP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreatePacket__15mgCVisualFixMDTFP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData0__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData1__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData2__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData3__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData4__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData5__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData6__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetData7__FiiPPiP1P1P1P1P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateFacePacket__12mgCVisualMDTFPUiP7mgCFace);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateRenderInfoPacket__12mgCVisualMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateExtRenderInfoPacket__12mgCVisualMDTFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Copy__15mgCVisualFixMDTFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", __as__12mgCVisualMDTFRC12mgCVisualMDT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetDrawEnv__FP10mgCDrawEnvP13mgCVisualAttrP10mgCDrawEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateRenderInfoPacket__13mgCVisualPrimFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Initialize__13mgCVisualPrimFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Iam__15mgCVisualFixMDTFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", giftag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_tex0_dma);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_tex0_giftag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_texa_dma);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_texa_giftag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", texflush_dma__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif_dif);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif_d);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_pw);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif_d_tex);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_data_func__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", prog_vif_730);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", progf_vif_731);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", at_769);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", __vt__13mgCVisualPrim);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", __vt__15mgCVisualFixMDT);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", __vt__12mgCVisualMDT);

// Small uninitialised data (.sbss)
unsigned char start_dma[0x4];
unsigned char buff_id[0x4];
unsigned char prev_tex[0x4];
