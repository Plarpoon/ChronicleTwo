#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", conv_new_text__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", htoi__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", mgSetFrameAttr__FP8mgCFramei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", SearchVisualType__FP18mgCreateVisualTypePc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", CreateFrameVisual__FP8mgCFrameP9mgCMemoryP9mgCMemoryP8mgCFrameP13MDTOBJ_HEADERP10MDT_HEADERiP17mgCTextureManagerPUiiPP8mgCFramePA4_A4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", SetVisual__8mgCFrameFP9mgCVisual);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Initialize__15mgCVisualFixMDTFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Initialize__9mgCVisualFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", mgLoadMDSFile__FP10MDS_HEADERP9mgCMemoryP18mgCreateVisualTypeP17mgCTextureManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", mgLoadMDSFile__FP10mgLoadData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", mgCreateBBoxSphere__FPfPfPfPA4_fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", CopyFrame__FP8mgCFrameP8mgCFrameP9mgCMemoryiPP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Iam__9mgCVisualFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Copy__9mgCVisualFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", CopyFrameSub__FP8mgCFrameP9mgCMemoryiPP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", mgCopyFrame__FP8mgCFrameP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Begin__13mgCMDTBuilderFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", End__13mgCMDTBuilderFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", End__13mgCMDTBuilderFP8mgCFrameP12mgCVisualMDTP10mgLoadData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", BeginData__13mgCMDTBuilderFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", SetData__13mgCMDTBuilderFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", SetData__13mgCMDTBuilderFffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", SetMaterial__13mgCMDTBuilderFPfPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", EndData__13mgCMDTBuilderFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", BeginFaces__13mgCMDTBuilderFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", EndFaces__13mgCMDTBuilderFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", BeginPrim__13mgCMDTBuilderFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", AddFace__13mgCMDTBuilderFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", EndPrim__13mgCMDTBuilderFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Iam__12mgCVisualMDTFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", GetMaterialNum__12mgCVisualMDTFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", GetpMaterial__12mgCVisualMDTFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Draw__12mgCVisualMDTFPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", CreatePacket__9mgCVisualFP9mgCMemoryP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", GetMaterialNum__9mgCVisualFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", GetpMaterial__9mgCVisualFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", GetMaterial__9mgCVisualFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", CreateBBox__9mgCVisualFPfPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", CreateRenderInfoPacket__9mgCVisualFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Draw__9mgCVisualFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_dataset", Draw__9mgCVisualFPA4_fP14mgCDrawManager);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_dataset", at_387);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_dataset", at_550);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_dataset", at_618);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_dataset", at_886);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_dataset", __vt__15mgCShadowFixMDT);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_dataset", __vt__9mgCVisual);

// Small uninitialised data (.sbss)
unsigned char name_def_276[0x4];
unsigned char init_277[0x4];
unsigned char flag_571[0x4];
unsigned char init_572[0x4];

// Uninitialised data (.bss)
unsigned char at_717[0x10];
unsigned char at_933[0x10];
