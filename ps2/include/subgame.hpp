#pragma once

#include "common.h"

class CScene;

/**
 *
 * Carries the scene and mode-specific parameters into a sub game.
 *
 */
struct SubGameInfo {
    CScene *scene; /**< Scene in which the sub game runs. */
    int unk_4;
    int unk_8;
    int unk_c;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1c;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2c;
};

STATIC_ASSERT(sizeof(SubGameInfo) == 0x30);
