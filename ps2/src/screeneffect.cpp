#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/screeneffect", DepthOfField__FiPfP10mgCTexturef);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/screeneffect", LensFlare__FPiPfiPcPc);

// Small uninitialised data (.sbss)
unsigned char at_205[0x8];
unsigned char at_206[0x8];
unsigned char at_283__2[0x8];
unsigned char at_292__2[0x8];
