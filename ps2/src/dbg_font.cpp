#include "common.h"
#include "dbg_font.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToJis__FUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToSerno__FUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", ascii2serno__FUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __ct__11dbgCJISFontFv);
void dbgCJISFont::Initialize(void) {
    (*(s32 *)((u8 *)this + 0xc)) = -1;
    (*(s32 *)((u8 *)this + 0x8)) = -1;
    (*(s32 *)((u8 *)this + 0x4)) = -1;
    (*(s32 *)((u8 *)this + 0x0)) = -1;
    (*(s8 *)((u8 *)this + 0x50)) = 0;
    (*(s8 *)((u8 *)this + 0x30)) = 0;
    (*(s8 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0x74)) = 0;
    (*(s32 *)((u8 *)this + 0x70)) = 0;
    (*(s32 *)((u8 *)this + 0x7c)) = 16;
    (*(s32 *)((u8 *)this + 0x78)) = 16;
    (*(s8 *)((u8 *)this + 0x88)) = 0;
    (*(s32 *)((u8 *)this + 0x894)) = 128;
    (*(s32 *)((u8 *)this + 0x890)) = 128;
    (*(s32 *)((u8 *)this + 0x88c)) = 128;
    (*(s32 *)((u8 *)this + 0x888)) = 128;
    (*(s32 *)((u8 *)this + 0x898)) = 0;
    (*(s32 *)((u8 *)this + 0x8a4)) = 0;
    (*(s32 *)((u8 *)this + 0x8a0)) = 0;
    (*(s32 *)((u8 *)this + 0x89c)) = 0;
    (*(s32 *)((u8 *)this + 0x8a8)) = 64;
    (*(s32 *)((u8 *)this + 0x8ac)) = 0;
}
void dbgCJISFont::InitTexture(s32 arg0, s8 *arg1, s32 arg2, s8 *arg3, s32 arg4, s8 *arg5) {
    (*(s32 *)((u8 *)this + 0x0)) = arg0;
    (*(s32 *)((u8 *)this + 0x4)) = arg2;
    (*(s32 *)((u8 *)this + 0x8)) = arg4;
    strcpy(&(*(s8 *)((u8 *)this + 0x10)), arg1);
    strcpy(&(*(s8 *)((u8 *)this + 0x30)), arg3);
    strcpy(&(*(s8 *)((u8 *)this + 0x50)), arg5);
}
void dbgCJISFont::Clear(void) {
    (*(s8 *)((u8 *)this + 0x88)) = 0;
}
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
