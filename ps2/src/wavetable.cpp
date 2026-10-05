#include "common.h"
#include "wavetable.hpp"

#include <cstdlib>
#include <libvu0.h>

#include "mg_drawprim.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"

// Code (.text)
CWaveTable::CWaveTable() {
    int row;
    int col;

    for (row = 0; row < WAVE_TABLE_DIM; row++) {
        for (col = 0; col < WAVE_TABLE_DIM; col++) {
            height[1][row][col] = 0.0f;
            height[0][row][col] = 0.0f;
        }
    }

    current = 0;
}

#ifdef NONMATCHING
CWaveTable::~CWaveTable() {
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", __dt__10CWaveTableFv);
#endif

#ifdef NONMATCHING
void CWaveTable::CreateTexture(mgCTexture *texture) {
    if (texture != NULL && texture->bpp >= 24) {
        mgSetPkFrameBuffer(texture);

        mgCDrawPrim   prim;
        sceVu0FVECTOR position;
        float         cell_width;
        float         cell_height;
        float         origin_x;
        float         origin_y;
        float         x;
        float         y;
        float         intensity;
        int           row;
        int           col;
        int           left;
        int           right;

        prim.Initialize(NULL, NULL);
        prim.DepthTestEnable(0);
        prim.ZMask(-1);
        prim.Shading(1);
        prim.AlphaBlendEnable(1);

        position[2] = 0.0f;
        position[3] = 0.0f;
        cell_width = texture->width / 23.0f;
        cell_height = texture->height / 23.0f;
        origin_x = mgScreenOffx;
        origin_y = mgScreenOffy;

        // One triangle strip per row of cells, shaded by the slope of the surface along the row.
        prim.Begin2();

        for (row = 0, y = 0.0f; row < WAVE_TABLE_DIM - 1; row++, y += 1.0f) {
            prim.BeginPrim2(4, 0x4141, 0, 4);

            for (col = 0, x = 0.0f; col < WAVE_TABLE_DIM; col++, x += 1.0f) {
                position[0] = origin_x + x * cell_width;
                position[1] = origin_y + y * cell_height;

                left = col;
                if (left > WAVE_TABLE_DIM - 2) {
                    left = 0;
                }
                right = (left + 1) % WAVE_TABLE_DIM;

                intensity = (height[current][row][left] - height[current][row][right]) * 540.0f + 40.0f;
                if (intensity > 200.0f) {
                    intensity = 200.0f;
                }
                if (intensity < 0.0f) {
                    intensity = 0.0f;
                }

                {
                    sceVu0FVECTOR color = { 0.0f, 0.0f, 0.0f, 96.0f };

                    color[0] = intensity;
                    color[1] = intensity;
                    color[2] = intensity;
                    prim.Data0(color);
                }
                prim.Data4(position);

                intensity = (height[current][(row + 1) % WAVE_TABLE_DIM][left] - height[current][(row + 1) % WAVE_TABLE_DIM][right]) * 540.0f + 40.0f;
                if (intensity < 0.0f) {
                    intensity = 0.0f;
                }
                if (intensity > 200.0f) {
                    intensity = 200.0f;
                }

                {
                    sceVu0FVECTOR color = { 0.0f, 0.0f, 0.0f, 96.0f };

                    color[0] = intensity;
                    color[1] = intensity;
                    color[2] = intensity;
                    position[1] += cell_height;
                    prim.Data0(color);
                }
                prim.Data4(position);
            }

            prim.EndPrim2();
        }

        prim.End2();

        // Darkens the whole texture so that old ripples fade.
        prim.Shading(0);
        prim.AlphaBlend(2);
        prim.Begin(6);
        prim.Color(0, 0, 0, 0x80);
        prim.Vertex(-1, -1, 0);
        prim.Vertex(texture->width + 1, texture->height + 1, 0);
        prim.End();

        mgSetPkFrameBuffer(-1, -1, -1, -1);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", CreateTexture__10CWaveTableFP10mgCTexture);
#endif

void CWaveTable::GetEffect() {
    static int cnt = 0;
    int        i;
    int        col;
    int        row;

    // Every fifth step drops four random disturbances onto the surface.
    if (cnt == 0) {
        for (i = 0; i < 4; i++) {
            col = rand() % 22 + 1;
            row = rand() % 22 + 1;
            height[current][row][col] += (rand() / 2147483648.0f - 0.5f) * 0.04f;
        }
    }

    cnt++;
    if (cnt > 4) {
        cnt = 0;
    }

    Effect();
    current = 1 - current;
}

#ifdef NONMATCHING
void CWaveTable::Effect() {
    int now;
    int next;
    int row;
    int col;

    now = current;
    next = 1 - now;

    // The field of the step before is overwritten with the next step of the wave equation.
    for (row = 1; row < WAVE_TABLE_DIM - 1; row++) {
        for (col = 1; col < WAVE_TABLE_DIM - 1; col++) {
            height[next][row][col] = (height[now][row - 1][col] + (height[now][row + 1][col] + (height[now][row][col - 1] + height[now][row][col + 1]))) * 0.0196f
                                     + (height[now][row][col] * 1.9216f - height[next][row][col])
                                     - (height[now][row][col] - height[next][row][col]) * 0.0015f;
        }
    }

    // The two edge columns of each row are averaged, which joins the surface where it wraps.
    for (row = 1; row < WAVE_TABLE_DIM - 1; row++) {
        height[next][row][1] = height[next][row][WAVE_TABLE_DIM - 2] = (height[next][row][1] + height[next][row][WAVE_TABLE_DIM - 2]) * 0.5f;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/wavetable", Effect__10CWaveTableFv);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", at_251__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", at_256__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/wavetable", __vt__10CWaveTable__DATA);
