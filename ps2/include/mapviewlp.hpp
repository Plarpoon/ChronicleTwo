#pragma once

#include "common.h"

/**
 * @file
 * Declares the entry, exit and per-frame functions of the debug map viewer, a main-loop mode that is left empty in the retail build.
 */

/**
 *
 * Parameters that the main loop hands to a mode when it enters it.
 *
 */
struct INIT_LOOP_ARG;

/**
 * Prepares the map viewer when the main loop enters it; does nothing in the retail build.
 *
 * @mangled MapViewInit__F13INIT_LOOP_ARG
 * @address 0x1A34C0
 * @size 0x10
 */
void MapViewInit(INIT_LOOP_ARG arg);

/**
 * Releases the map viewer when the main loop leaves it; does nothing in the retail build.
 *
 * @mangled MapViewExit__Fv
 * @address 0x1A34D0
 * @size 0x10
 */
void MapViewExit();

/**
 * Runs one frame of the map viewer, and returns 1 so that the main loop leaves it at once.
 *
 * @mangled MapViewLoop__Fv
 * @address 0x1A34E0
 * @size 0x10
 */
int MapViewLoop();
