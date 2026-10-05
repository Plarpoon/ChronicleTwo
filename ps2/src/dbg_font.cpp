#include "common.h"
#include "dbg_font.hpp"
#include "mg_drawprim.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"
#include <cstdio>
#include <cstring>

static unsigned long SjisToJis(unsigned long sjis);
static unsigned long SjisToSerno(unsigned long sjis);
static unsigned long ascii2serno(unsigned char character);

// Code (.text)
#ifdef NONMATCHING
static unsigned long SjisToJis(unsigned long sjis) {
    unsigned long lead = (sjis >> 8) & 0xFF;
    unsigned long trail = sjis & 0xFF;
    if (lead >= 0x81 && lead < 0xA0) lead -= 0x81;
    else if (lead >= 0xE0 && lead < 0xF0) lead -= 0xC1;
    unsigned long row = lead * 2 + 1;
    if (trail >= 0x40 && trail < 0x7F) trail -= 0x40;
    else if (trail >= 0x80 && trail < 0x9F) trail -= 0x41;
    else if (trail >= 0x9F && trail < 0xFD) {
        trail -= 0x9F;
        row++;
    }
    return (row << 8) + trail + 0x2021;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToJis__FUl);
#endif
#ifdef NONMATCHING
static unsigned long SjisToSerno(unsigned long sjis) {
    unsigned long jis = SjisToJis(sjis);
    return ((jis >> 8) - 0x21) * 94 + (jis & 0xFF) - 0x21;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", SjisToSerno__FUl);
#endif
#ifdef NONMATCHING
static unsigned long ascii2serno(unsigned char character) {
    static const unsigned short glyphs[64] = {
        0x227E, 0x212C, 0x215F, 0x2160, 0x212B, 0x212F, 0x2237, 0x21E6,
        0x21E8, 0x21EA, 0x21EC, 0x21EE, 0x2228, 0x222A, 0x222C, 0x2208,
        0x227E, 0x21E7, 0x21E9, 0x21EB, 0x21ED, 0x21EF, 0x21F0, 0x21F2,
        0x21F4, 0x21F6, 0x21F8, 0x21FA, 0x21FC, 0x21FE, 0x2200, 0x2202,
        0x2204, 0x2206, 0x2209, 0x220B, 0x220D, 0x220F, 0x2210, 0x2211,
        0x2212, 0x2213, 0x2214, 0x2217, 0x221A, 0x221D, 0x2220, 0x2223,
        0x2224, 0x2225, 0x2226, 0x2227, 0x2229, 0x222B, 0x222D, 0x222E,
        0x222F, 0x2230, 0x2231, 0x2232, 0x2234, 0x2238, 0x2134, 0x2135
    };
    return character >= 0xA0 && character < 0xE0 ? glyphs[character - 0xA0] : DBG_FONT_SERNO_UNKNOWN;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", ascii2serno__FUc);
#endif
#ifdef NONMATCHING
dbgCJISFont::dbgCJISFont() {
    Initialize();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __ct__11dbgCJISFontFv);
#endif
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
#ifdef NONMATCHING
void dbgCJISFont::__putc(unsigned long serno) {
    if (serno >= DBG_FONT_SERNO_END) return;
    int sheet = DBG_FONT_SHEET_FULL_WIDTH_0;
    int glyph_width = 16;
    if (serno >= DBG_FONT_SERNO_HALF_WIDTH) {
        sheet = DBG_FONT_SHEET_HALF_WIDTH;
        serno -= DBG_FONT_SERNO_HALF_WIDTH;
        glyph_width = 9;
    } else if (serno >= DBG_FONT_SERNO_SHEET_1) {
        sheet = DBG_FONT_SHEET_FULL_WIDTH_1;
        serno -= DBG_FONT_SERNO_SHEET_1;
    }
    if (loaded_texture_id != texture_id[sheet]) mgTexManager.ReloadTexture(texture_id[sheet], (sceVif1Packet *)NULL);
    mgCTexture *texture = mgTexManager.GetTexture(texture_name[sheet], -1);
    loaded_texture_id = texture_id[sheet];
    mgCDrawPrim prim;
    prim.Initialize(NULL, NULL);
    prim.DepthTestEnable(0);
    prim.AlphaTestEnable(0);
    prim.AlphaBlendEnable(1);
    int advance = char_width - (16 - (glyph_width - 1));
    if (back_enable) {
        prim.Begin(6);
        prim.Color(back_color[0], back_color[1], back_color[2], back_color[3]);
        prim.Vertex(x - 1, y - 1, 0);
        prim.Vertex(x + advance, y + char_height + 1, 0);
        prim.End();
    }
    prim.TextureMapEnable(1);
    int tex_x = (serno & 63) * 16;
    int tex_y = (serno >> 6) * 16;
    if (shadow_enable) {
        prim.Begin(6);
        prim.Texture(texture);
        prim.Color(0, 0, 0, 128);
        prim.TextureCrd(tex_x + 1, tex_y + 1);
        prim.Vertex(x - 1, y - 1, 0);
        prim.TextureCrd(tex_x + glyph_width - 1, tex_y + 15);
        prim.Vertex(x + advance, y + char_height + 1, 0);
        prim.End();
    }
    prim.Begin(6);
    prim.Texture(texture);
    prim.Color(color[0], color[1], color[2], color[3]);
    prim.TextureCrd(tex_x + 1, tex_y + 1);
    prim.Vertex(x, y, 0);
    prim.TextureCrd(tex_x + glyph_width - ((serno & 63) == 63), tex_y + 16 - ((serno >> 6) == 63));
    prim.Vertex(x + advance, y + char_height, 0);
    prim.End();
    x += advance + 2;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __putc__11dbgCJISFontFUl);
#endif
#ifdef NONMATCHING
void dbgCJISFont::PrintDirect(int start_x, int start_y, char *format, ...) {
    char text[0x408];
    // The runtime's varargs forwarding needs a target-specific argument-list type.
    sprintf(text, "%s", format);
    x = start_x;
    y = start_y;
    prev_serno = 0;
    for (char *cursor = text; *cursor != 0;) {
        unsigned char first = (unsigned char)*cursor;
        if (first & 0x80) {
            if (first >= 0xA1 && first < 0xE0) {
                unsigned long serno = ascii2serno(first);
                if ((serno == DBG_FONT_SERNO_DAKUTEN || serno == DBG_FONT_SERNO_HANDAKUTEN) && prev_serno != 0) {
                    serno = prev_serno + (serno == DBG_FONT_SERNO_DAKUTEN ? 1 : 2);
                    prev_serno = 0;
                    x -= char_width - 8;
                } else {
                    prev_serno = serno;
                }
                __putc(serno);
                ++cursor;
            } else {
                unsigned long sjis = ((unsigned long)first << 8) | (unsigned char)cursor[1];
                __putc(SjisToSerno(sjis));
                cursor += 2;
            }
        } else if (first == '\n') {
            y += char_height;
            x = 0;
            ++cursor;
        } else if (first == '\t') {
            x += char_width * 2;
            ++cursor;
        } else if (strncmp(cursor, "ESC[$", 5) == 0) {
            back_enable = ~back_enable;
            cursor += 5;
        } else if (strncmp(cursor, "ESC[#", 5) == 0) {
            shadow_enable = ~shadow_enable;
            cursor += 5;
        } else {
            __putc(first + 0x204D);
            ++cursor;
        }
    }
    loaded_texture_id = -1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", PrintDirect__11dbgCJISFontFiiPce);
#endif

// Static initialiser (.init)
#ifdef NONMATCHING
extern "C" void __sinit_dbg_font_cpp() {
    new ((u_long128 *)&JisFont) dbgCJISFont;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dbg_font", __sinit_dbg_font_cpp);
#endif

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", at_288__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", at_419__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", at_420__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dbg_font", D_0037AFF0__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(JisFont, 0x8B0);
