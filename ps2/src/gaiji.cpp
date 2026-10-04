#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", LoadGaijiImg__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", GetGaijiImgPtr__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", LoadFontTex2Img__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", GetFontTex2ImgPtr__Fv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_258__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_259__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_260__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_261__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_262__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_263__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_264__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_278__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(FontTex_2_Buff, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(GaijiBuff, 0x11800);
