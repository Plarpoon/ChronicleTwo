#include "common.h"
#include "dbg_font.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToJis__FUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToSerno__FUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", ascii2serno__FUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __ct__11dbgCJISFontFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", Initialize__11dbgCJISFontFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", InitTexture__11dbgCJISFontFiPciPciPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", Clear__11dbgCJISFontFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __putc__11dbgCJISFontFUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", PrintDirect__11dbgCJISFontFiiPce);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __sinit_dbg_font_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", at_288__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", at_419__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", at_420__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", D_0037AFF0__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(JisFont, 0x8B0);
