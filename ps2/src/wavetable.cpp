#include "common.h"
#include "wavetable.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", __ct__10CWaveTableFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", __dt__10CWaveTableFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", CreateTexture__10CWaveTableFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", GetEffect__10CWaveTableFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", Effect__10CWaveTableFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", at_251__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", at_256__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", __vt__10CWaveTable__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(cnt_302, 0x4);
INCLUDE_BSS(init_303, 0x4);
