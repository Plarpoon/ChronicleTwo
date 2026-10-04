#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", __ct__10CWaveTableFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", __dt__10CWaveTableFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", CreateTexture__10CWaveTableFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", GetEffect__10CWaveTableFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", Effect__10CWaveTableFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", at_251);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", at_256);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", __vt__10CWaveTable);

// Small uninitialised data (.sbss)
unsigned char cnt_302[0x4];
unsigned char init_303[0x4];
