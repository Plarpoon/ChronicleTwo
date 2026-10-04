#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetZBufVram__FPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", CheckCopyToZBufVram__FP10mgCTexturePi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", __ct__10mgCTextureFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Initialize__10mgCTextureFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Bilinear__10mgCTextureFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", __ct__15mgCTextureBlockFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Initialize__15mgCTextureBlockFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Add__15mgCTextureBlockFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Delete__15mgCTextureBlockFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", __ct__17mgCTextureManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", SetTableBuffer__17mgCTextureManagerFiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Initialize__17mgCTextureManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", hash__17mgCTextureManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", AddHash__17mgCTextureManagerFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", DelHash__17mgCTextureManagerFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", SearchHash__17mgCTextureManagerFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", SearchTextureName__17mgCTextureManagerFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", SearchTexture__17mgCTextureManagerFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetTexture__17mgCTextureManagerFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetTextureBlock__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetRemainVRAM__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", EnterTexture__17mgCTextureManagerFiPcPP1iiiP1Uli);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", EnterTexture__17mgCTextureManagerFiPcP8TM2_headii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", EnterIMGFile__17mgCTextureManagerFPUciP9mgCMemoryP15mgCEnterIMGInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetIMGVersion__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", mgGetIMGHeaderNum__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", mgGetIMGHeader__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", DeleteTexture__17mgCTextureManagerFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", DeleteTexture__17mgCTextureManagerFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", DeleteBlock__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", EndEnterTexture__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", mgLoadImage__FPUiiiiP1iiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", SetTexFlush_TagCnt__FPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", ReloadTexture__17mgCTextureManagerFiP13sceVif1Packet);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", ReloadTexture__17mgCTextureManagerFiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", __as__9sceGsTex0FRC9sceGsTex0);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", ReloadCLUT__17mgCTextureManagerFP10mgCTexturePUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", ReloadCLUT__17mgCTextureManagerFP10mgCTextureP13sceVif1Packet);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", TexAnimeOn__17mgCTextureManagerFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", TexAnimeOff__17mgCTextureManagerFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", TexAnimeAllOff__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetGroupNameList__17mgCTextureManagerFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", DeleteTexAnimeGroup__17mgCTextureManagerFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", DeleteTexAnime__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", GetTexAnime__17mgCTextureManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", BlockConv32to8__FPUcPUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", PageConv32to8__FiiPUcPUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_texture", Conv32To8__FiiPUc);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", texflush_dma);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", lut_1246);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", block_table8_1266);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", block_table32_1267);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_497);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_629);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_866);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_867);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_868);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_869);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_texture", at_884);

// Uninitialised data (.bss)
unsigned char conv_work_1306[0x10000];
