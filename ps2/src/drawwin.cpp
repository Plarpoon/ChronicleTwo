#include "common.h"
#include "drawwin.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", CalcSelectCursorPos__F4RECTPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", OffsetYesNoWin__FP4RECTP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_yesno__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", MyMenuHelpWinDraw__FP11mgCDrawPrim4RECTi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", MyMenuFloatingWinDraw__FP11mgCDrawPrim4RECTiiP10RGBAQ_TYPEP10RGBAQ_TYPE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_1__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_1__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_3__FP11mgCDrawPrim4RECTiP10RGBAQ_TYPEii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_4__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_4__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawDQFukidashi__FP11mgCDrawPrim4RECTiiP10RGBAQ_TYPEii);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/drawwin", data__DATA);
