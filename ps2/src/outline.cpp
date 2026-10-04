#include "common.h"
#include "outline.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/outline", Initialize__12COutLineDrawFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/outline", SetFrame__12COutLineDrawFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/outline", Draw__12COutLineDrawFPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/outline", Draw__12COutLineDrawFff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/outline", DrawDivSprite__FP11mgCDrawPrim9mgRect_i_P10mgCTexturePiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/outline", DrawDivSprite4__FP11mgCDrawPrim9mgRect_i_P10mgCTexturePiii);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/outline", at_338__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_299__2, 0x10);
INCLUDE_BSS(at_300__2, 0x10);
INCLUDE_BSS(at_325, 0x10);
INCLUDE_BSS(at_395, 0x10);
INCLUDE_BSS(at_396, 0x10);
INCLUDE_BSS(at_398, 0x10);
INCLUDE_BSS(at_399, 0x10);
