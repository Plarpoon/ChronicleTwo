#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", LoadGaijiImg__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", GetGaijiImgPtr__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", LoadFontTex2Img__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gaiji", GetFontTex2ImgPtr__Fv);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_258);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_259__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_260__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_261__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_262);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_263);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_264);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gaiji", at_278__2);

// Small uninitialised data (.sbss)
unsigned char FontTex_2_Buff[0x4];

// Uninitialised data (.bss)
unsigned char GaijiBuff[0x11800];
