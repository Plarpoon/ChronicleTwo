#include "common.h"
#include "mg_visual.hpp"

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
void mgCVisualMDT::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x20)) = 0;
    (*(s32 *)((u8 *)this + 0x30)) = 0;
    (*(s32 *)((u8 *)this + 0x24)) = 0;
    (*(s32 *)((u8 *)this + 0x34)) = 0;
    (*(s32 *)((u8 *)this + 0x28)) = 0;
    (*(s32 *)((u8 *)this + 0x38)) = 0;
    (*(s32 *)((u8 *)this + 0x2c)) = 0;
    (*(s32 *)((u8 *)this + 0x3c)) = 0;
    (*(s32 *)((u8 *)this + 0x40)) = 0;
    (*(s32 *)((u8 *)this + 0x44)) = 0;
    (*(s32 *)((u8 *)this + 0x48)) = 0;
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s32 *)((u8 *)this + 0x14)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 60;
    (*(s32 *)((u8 *)this + 0x14)) = 180;
}
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
int mgCVisualMDT::CreateExtRenderInfoPacket(u_int *packet, float (*matrix)[4], mgRENDER_INFO *info) { return 0; }
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Copy__15mgCVisualFixMDTFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", __as__12mgCVisualMDTFRC12mgCVisualMDT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", SetDrawEnv__FP10mgCDrawEnvP13mgCVisualAttrP10mgCDrawEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", CreateRenderInfoPacket__13mgCVisualPrimFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Initialize__13mgCVisualPrimFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_visual", Iam__15mgCVisualFixMDTFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", giftag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_tex0_dma__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_tex0_giftag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_texa_dma__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_texa_giftag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", texflush_dma__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif_dif__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif_d__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_pw__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", mat_vif_d_tex__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", set_data_func__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", prog_vif_730__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", progf_vif_731__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", at_769__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", __vt__13mgCVisualPrim__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", __vt__15mgCVisualFixMDT__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_visual", __vt__12mgCVisualMDT__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(start_dma, 0x4);
INCLUDE_BSS(buff_id, 0x4);
INCLUDE_BSS(prev_tex, 0x4);
