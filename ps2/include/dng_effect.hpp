#pragma once

#include "common.h"

/**
 *
 * Animates a character's palette between two colours for a set duration.
 *
 */
struct CPalletAnime {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 elapsed;   /**< Frames elapsed in the current palette cycle. */
    s16 duration;  /**< Frames in the current palette cycle. */
    s16 repeats;   /**< Cycles left, or -1 to repeat indefinitely. */

    /**
     *
     * Sets the colours and timing of a palette animation.
     *
     * @mangled SetAnim__12CPalletAnimeFssssss
     * @address 0x1C2600
     * @size 0x20
     */
    void SetAnim(short, short, short, short, short, short);

    /**
     *
     * Blends the target palette toward this animation's colour.
     *
     * @mangled CreatPallet__12CPalletAnimeFPfPf
     * @address 0x1C2620
     * @size 0x130
     */
    int CreatPallet(float *out, float *base);

    /**
     *
     * Advances the palette animation by one frame.
     *
     * @mangled Step__12CPalletAnimeFv
     * @address 0x1C2750
     * @size 0x70
     */
    void Step();

    /**
     *
     * Clears the palette animation.
     *
     * @mangled Initialize__12CPalletAnimeFv
     * @address 0x1C27C0
     * @size 0x10
     */
    void Initialize();
};

STATIC_ASSERT(sizeof(CPalletAnime) == 0xe);
