#include "common.h"
#include "dbg_font.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToJis__FUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToSerno__FUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", ascii2serno__FUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __ct__11dbgCJISFontFv);
void dbgCJISFont::Initialize(void) {
    texture_id[DBG_FONT_SHEET_FULL_WIDTH_0] = texture_id[DBG_FONT_SHEET_FULL_WIDTH_1] = texture_id[DBG_FONT_SHEET_HALF_WIDTH] = loaded_texture_id = -1;
    texture_name[DBG_FONT_SHEET_FULL_WIDTH_0][0] = texture_name[DBG_FONT_SHEET_FULL_WIDTH_1][0] = texture_name[DBG_FONT_SHEET_HALF_WIDTH][0] = 0;
    x = y = 0;
    char_width = char_height = 16;
    buffer[0] = 0;
    color[0] = color[1] = color[2] = color[3] = 128;
    back_enable = 0;
    back_color[0] = back_color[1] = back_color[2] = 0;
    back_color[3] = 64;
    shadow_enable = 0;
}
void dbgCJISFont::InitTexture(s32 full0_id, s8 *full0_name, s32 full1_id, s8 *full1_name, s32 half_id, s8 *half_name) {
    texture_id[DBG_FONT_SHEET_FULL_WIDTH_0] = full0_id;
    texture_id[DBG_FONT_SHEET_FULL_WIDTH_1] = full1_id;
    texture_id[DBG_FONT_SHEET_HALF_WIDTH] = half_id;
    strcpy(texture_name[DBG_FONT_SHEET_FULL_WIDTH_0], full0_name);
    strcpy(texture_name[DBG_FONT_SHEET_FULL_WIDTH_1], full1_name);
    strcpy(texture_name[DBG_FONT_SHEET_HALF_WIDTH], half_name);
}
void dbgCJISFont::Clear(void) {
    buffer[0] = 0;
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
