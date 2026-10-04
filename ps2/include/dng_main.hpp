#pragma once

#include "common.h"
#include "collision.hpp"

/**
 *
 * Holds the ground and special-area hits found while moving a character.
 *
 */
struct MoveCheckInfo {
    float       radius;                 /**< Radius used by the movement query. */
    int         skip_ground;            /**< Skips the ground search when set. */
    int         landed;                 /**< Indicates a ground contact. */
    u8          unk_c[4];
    CCPoly      ground_poly;            /**< Ground polygon under the character. */
    int         ground_found;           /**< Indicates that a ground polygon was found. */
    u8          unk_64[0xc];
    CCPoly      second_poly;            /**< Other polygon retained by the movement query. */
    sceVu0FVECTOR ground_point;         /**< Ground contact point. */
    int         width_result;           /**< Result of the width check. */
    int         in_water;               /**< Indicates a water-area contact. */
    u8          unk_d8[8];
    sceVu0FVECTOR water_surface;        /**< Water surface contact point. */
    int         crossed_area;           /**< Indicates a special-area crossing. */
    float       signed_distance;        /**< Signed distance to the special area. */
    u8          unk_f8[8];
    sceVu0FVECTOR crossed_point;        /**< Special-area crossing point. */

    /**
     *
     * Clears the movement query state.
     *
     * @mangled Initialize__13MoveCheckInfoFv
     * @address 0x1CF550
     * @size 0x10
     */
    void Initialize();
} __attribute__((aligned(16)));

STATIC_ASSERT(sizeof(MoveCheckInfo) == 0x110);
