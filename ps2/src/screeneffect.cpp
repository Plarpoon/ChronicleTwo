#include "common.h"
#include "screeneffect.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/screeneffect", DepthOfField__FiPfP10mgCTexturef);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/screeneffect", LensFlare__FPiPfiPcPc);

// Small uninitialised data (.sbss)
INCLUDE_BSS(at_205, 0x8);
INCLUDE_BSS(at_206, 0x8);
INCLUDE_BSS(at_283__2, 0x8);
INCLUDE_BSS(at_292__2, 0x8);
