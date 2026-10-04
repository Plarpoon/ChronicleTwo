#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_shadow", SetShadowData__FPUiPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_shadow", CreateFacePacket__12mgCShadowMDTFPUiP7mgCFace);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_shadow", CreateFace__12mgCShadowMDTFP8FACES_IDP9mgCMemoryP9mgCMemoryPP7mgCFace);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_shadow", CreatePacket__12mgCShadowMDTFP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_shadow", DataAssignMDT__12mgCShadowMDTFP10MDT_HEADERP9mgCMemoryP17mgCTextureManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_shadow", CreateRenderInfoPacket__12mgCShadowMDTFPUiPA4_fP13mgRENDER_INFO);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_shadow", prog_vif_208);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_shadow", at_243);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_shadow", __vt__12mgCShadowMDT);

// Uninitialised data (.bss)
unsigned char at_353[0x10];
