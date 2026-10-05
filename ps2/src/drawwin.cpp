#include "common.h"
#include "drawwin.hpp"
#include "nd_meswin.hpp"

// These expansions keep the geometry next to each retail function's draw calls.
#define DrawWindowPart(prim, part, x, y, width, height, color) \
    do { \
        mgRect<int> screen(x, y, width, height); \
        mgRect<int> texture(data[part][0], data[part][1], data[part][2], data[part][3]); \
        set2DSprite(prim, screen, texture, color); \
    } while (0)

#define DrawWindowTile(prim, x, y, width, height, tex_x, tex_y, tex_width, tex_height, color) \
    do { \
        mgRect<int> screen(x, y, width, height); \
        mgRect<int> texture(tex_x, tex_y, tex_width, tex_height); \
        set2DSprite(prim, screen, texture, color); \
    } while (0)

#define DrawWindowRow(prim, part, win, y, height, color) \
    do { \
        DrawWindowPart(prim, part, win.x, y, 0x17, height, color); \
        DrawWindowPart(prim, part + 1, win.x + 0x17, y, win.width - 0x2E, height, color); \
        DrawWindowPart(prim, part + 2, win.x + win.width - 0x17, y, 0x17, height, color); \
    } while (0)

#define WindowFillAlpha(alpha, opaque) ((opaque) ? 0x80 : (alpha) * 0x36 / 128)

// Code (.text)
#ifdef NONMATCHING
void CalcSelectCursorPos(RECT win, int *cursor_pos) {
    int inner_width = win.width - 0x2E;
    cursor_pos[0] = win.x + 0x17 + inner_width * 5 / 20 - 0x1E;
    cursor_pos[1] = win.y + win.height - 0x29;
    cursor_pos[2] = win.x + 0x17 + inner_width * 15 / 20 - 0x1E;
    cursor_pos[3] = cursor_pos[1];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", CalcSelectCursorPos__F4RECTPi);
#endif
void OffsetYesNoWin(RECT *win, RECT *shadow) {
    if (win->width < 0xA6) {
        win->width = 0xA6;
        shadow->width = 0xA6;
    }
}
#ifdef NONMATCHING
void DrawVersatileWin_yesno(mgCDrawPrim *prim, RECT win, RGBAQ_TYPE *color, int alpha, int opaque) {
    MySetPrim(prim, 1, 0);
    DrawWindowRow(prim, VWIN_TOP_L, win, win.y, 0x19, color);
    DrawWindowPart(prim, VWIN_SIDE_L, win.x, win.y + 0x19, 0x17, win.height - 0x50, color);
    FillRect(win.x + 0xD, win.y + 0x10, win.width - 0x18, win.height - 0x43,
             0, 0, 0, WindowFillAlpha(alpha, opaque));
    DrawWindowPart(prim, VWIN_SIDE_R, win.x + win.width - 0x17, win.y + 0x19,
                   0x17, win.height - 0x50, color);
    DrawWindowRow(prim, VWIN_BAND_L, win, win.y + win.height - 0x37, 0xE, color);
    DrawWindowRow(prim, VWIN_LOWER_SIDE_L, win, win.y + win.height - 0x29, 0x10, color);
    DrawWindowRow(prim, VWIN_LOWER_BOTTOM_L, win, win.y + win.height - 0x19, 0x19, color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_yesno__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
#endif
#ifdef NONMATCHING
void MyMenuHelpWinDraw(mgCDrawPrim *prim, RECT win, int alpha) {
    RGBAQ_TYPE color = {0x80, 0x80, 0x80, (u8)alpha, 1.0f};
    const int sx[3] = {win.x, win.x + 0x18, win.x + win.width - 0x18};
    const int sy[3] = {win.y, win.y + 0x16, win.y + win.height - 0x16};
    const int sw[3] = {0x18, win.width - 0x30, 0x18};
    const int sh[3] = {0x16, win.height - 0x2C, 0x16};
    const int tx[3] = {0xC0, 0xD8, 0xE8};
    const int ty[3] = {0xA6, 0xBC, 0xD0};
    const int tw[3] = {0x18, 0x10, 0x18};
    const int th[3] = {0x16, 0x14, 0x16};
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            DrawWindowTile(prim, sx[col], sy[row], sw[col], sh[row],
                           tx[col], ty[row], tw[col], th[row], &color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", MyMenuHelpWinDraw__FP11mgCDrawPrim4RECTi);
#endif
#ifdef NONMATCHING
void MyMenuFloatingWinDraw(mgCDrawPrim *prim, RECT win, int point_x, int point_y,
                           RGBAQ_TYPE *frame_color, RGBAQ_TYPE *fill_color) {
    MySetPrim(prim, 1, 0);
    const int sx[3] = {win.x, win.x + 7, win.x + win.width - 7};
    const int sy[3] = {win.y, win.y + 9, win.y + win.height - 9};
    const int sw[3] = {7, win.width - 14, 7};
    const int sh[3] = {9, win.height - 18, 9};
    const int outer_tx[3] = {0xA0, 0xA7, 0xC9};
    const int inner_tx[3] = {0x70, 0x77, 0x99};
    const int ty[3] = {0, 9, 0x27};
    const int tw[3] = {7, 0x22, 7};
    const int th[3] = {9, 0x1E, 9};
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            DrawWindowTile(prim, sx[col], sy[row], sw[col], sh[row],
                           outer_tx[col], ty[row], tw[col], th[row], fill_color);
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col) {
            if (row == 1 && col == 1) continue;
            DrawWindowTile(prim, sx[col], sy[row], sw[col], sh[row],
                           inner_tx[col], ty[row], tw[col], th[row], frame_color);
        }
    MySetPrim(prim, 4, 0);
    int x, y, tx, ty_outer, ty_inner;
    if (point_x < win.x) {
        x = win.x - 13; y = point_y - 10; tx = 0xA6; ty_outer = 0x45; ty_inner = 0x30;
    } else if (point_x > win.x + win.width) {
        x = win.x + win.width - 8; y = point_y - 10; tx = 0xBB; ty_outer = 0x45; ty_inner = 0x30;
    } else if (point_y < win.y) {
        x = point_x - 10; y = win.y - 13; tx = 0x7C; ty_outer = 0x45; ty_inner = 0x30;
    } else if (point_y > win.y + win.height) {
        x = point_x - 10; y = win.y + win.height - 8; tx = 0x91; ty_outer = 0x45; ty_inner = 0x30;
    } else return;
    DrawWindowTile(prim, x, y, 0x15, 0x15, tx, ty_outer, 0x15, 0x15, fill_color);
    DrawWindowTile(prim, x, y, 0x15, 0x15, tx, ty_inner, 0x15, 0x15, frame_color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", MyMenuFloatingWinDraw__FP11mgCDrawPrim4RECTiiP10RGBAQ_TYPEP10RGBAQ_TYPE);
#endif
#ifdef NONMATCHING
void DrawVersatileWin_1(mgCDrawPrim *prim, RECT win, RGBAQ_TYPE *color, int alpha, int opaque) {
    MySetPrim(prim, 1, 0);
    DrawWindowRow(prim, VWIN_TOP_L, win, win.y, 0x19, color);
    DrawWindowPart(prim, VWIN_SIDE_L, win.x, win.y + 0x19, 0x17, win.height - 0x32, color);
    FillRect(win.x + 0xD, win.y + 0x10, win.width - 0x18, win.height - 0x1A,
             0, 0, 0, WindowFillAlpha(alpha, opaque));
    DrawWindowPart(prim, VWIN_SIDE_R, win.x + win.width - 0x17, win.y + 0x19,
                   0x17, win.height - 0x32, color);
    DrawWindowRow(prim, VWIN_BOTTOM_L, win, win.y + win.height - 0x19, 0x19, color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_1__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
#endif
void DrawVersatileWin_1(mgCDrawPrim *prim, RECT win, RGBAQ_TYPE *color, int alpha) {
    DrawVersatileWin_1(prim, win, color, alpha, 0);
}
#ifdef NONMATCHING
void DrawVersatileWin_3(mgCDrawPrim *prim, RECT win, int select_y, RGBAQ_TYPE *color, int alpha, int opaque) {
    MySetPrim(prim, 1, 0);
    int band_top = select_y - 7;
    int band_bottom = select_y + 7;
    int bottom_top = win.y + win.height - 0x19;
    DrawWindowRow(prim, VWIN_TOP_L, win, win.y, 0x19, color);
    DrawWindowPart(prim, VWIN_SIDE_L, win.x, win.y + 0x19, 0x17,
                   band_top - (win.y + 0x19), color);
    FillRect(win.x + 0xD, win.y + 0x10, win.width - 0x18,
             band_top - (win.y + 0xC), 0, 0, 0, WindowFillAlpha(alpha, opaque));
    DrawWindowPart(prim, VWIN_SIDE_R, win.x + win.width - 0x17, win.y + 0x19,
                   0x17, band_top - (win.y + 0x19), color);
    DrawWindowRow(prim, VWIN_BAND_L, win, band_top, 0xE, color);
    DrawWindowRow(prim, VWIN_LOWER_SIDE_L, win, band_bottom,
                  bottom_top - band_bottom, color);
    DrawWindowRow(prim, VWIN_LOWER_BOTTOM_L, win, bottom_top, 0x19, color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_3__FP11mgCDrawPrim4RECTiP10RGBAQ_TYPEii);
#endif
#ifdef NONMATCHING
void DrawVersatileWin_4(mgCDrawPrim *prim, RECT win, RGBAQ_TYPE *color, int alpha, int opaque) {
    MySetPrim(prim, 1, 0);
    DrawWindowRow(prim, VWIN_TOP4_L, win, win.y, 0x19, color);
    DrawWindowPart(prim, VWIN_SIDE_L, win.x, win.y + 0x19, 0x17, win.height - 0x32, color);
    FillRect(win.x + 0xD, win.y + 0xC, win.width - 0x18, win.height - 0x16,
             0, 0, 0, WindowFillAlpha(alpha, opaque));
    DrawWindowPart(prim, VWIN_SIDE_R, win.x + win.width - 0x17, win.y + 0x19,
                   0x17, win.height - 0x32, color);
    DrawWindowRow(prim, VWIN_BOTTOM_L, win, win.y + win.height - 0x19, 0x19, color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawVersatileWin_4__FP11mgCDrawPrim4RECTP10RGBAQ_TYPEii);
#endif
void DrawVersatileWin_4(mgCDrawPrim *prim, RECT win, RGBAQ_TYPE *color, int alpha) {
    DrawVersatileWin_4(prim, win, color, alpha, 0);
}
#ifdef NONMATCHING
void DrawDQFukidashi(mgCDrawPrim *prim, RECT win, int tail_x, int tail_y,
                     RGBAQ_TYPE *color, int tail_on, int mode) {
    MySetPrim(prim, 1, 0);
    int inside_x = win.x + 0x10;
    int inside_width = win.width - 0x20;
    int right_x = win.x + win.width - 0x10;
    int bottom_y = win.y + win.height - 0x10;
    DrawWindowTile(prim, win.x, win.y, 0x10, 0x10, 0, 0xD0, 0x10, 0x10, color);
    if (tail_on) {
        if (tail_x - 8 < inside_x) tail_x = inside_x + 8;
        if (tail_x + 8 > inside_x + inside_width) tail_x = inside_x + inside_width - 8;
        DrawWindowTile(prim, inside_x, win.y, tail_x - 8 - inside_x, 0x10,
                       0x10, 0xD0, 0x10, 0x10, color);
        DrawWindowTile(prim, tail_x - 8, win.y - 0x10, 0x10, 0x20,
                       0x30, 0xD0, 0x10, 0x20, color);
        DrawWindowTile(prim, tail_x + 8, win.y, inside_x + inside_width - (tail_x + 8),
                       0x10, 0x10, 0xD0, 0x10, 0x10, color);
    } else {
        DrawWindowTile(prim, inside_x, win.y, inside_width, 0x10,
                       0x10, 0xD0, 0x10, 0x10, color);
    }
    DrawWindowTile(prim, right_x, win.y, 0x10, 0x10, 0x20, 0xD0, 0x10, 0x10, color);
    DrawWindowTile(prim, win.x, win.y + 0x10, 0x10, win.height - 0x20,
                   0, 0xE0, 0x10, 0x10, color);
    DrawWindowTile(prim, inside_x, win.y + 0x10, inside_width, win.height - 0x20,
                   0x10, 0xE0, 0x10, 0x10, color);
    DrawWindowTile(prim, right_x, win.y + 0x10, 0x10, win.height - 0x20,
                   0x20, 0xE0, 0x10, 0x10, color);
    DrawWindowTile(prim, win.x, bottom_y, 0x10, 0x10, 0, 0xF0, 0x10, 0x10, color);
    DrawWindowTile(prim, inside_x, bottom_y, inside_width, 0x10,
                   0x10, 0xF0, 0x10, 0x10, color);
    DrawWindowTile(prim, right_x, bottom_y, 0x10, 0x10, 0x20, 0xF0, 0x10, 0x10, color);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/drawwin", DrawDQFukidashi__FP11mgCDrawPrim4RECTiiP10RGBAQ_TYPEii);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/drawwin", data__DATA);
