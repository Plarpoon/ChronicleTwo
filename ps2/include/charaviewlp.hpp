#pragma once

#include "common.h"

/**
 * @file
 * Declares the entry, exit and per-frame functions of the debug character viewer, a main-loop mode that is left empty in the retail build.
 */

/**
 *
 * Parameters that the main loop hands to a mode when it enters it.
 *
 */
struct INIT_LOOP_ARG;

/**
 * Prepares the character viewer when the main loop enters it; does nothing in the retail build.
 *
 * @mangled InitCharaViewerMain__F13INIT_LOOP_ARG
 * @address 0x1A3460
 * @size 0x10
 */
void InitCharaViewerMain(INIT_LOOP_ARG arg);

/**
 * Releases the character viewer when the main loop leaves it; does nothing in the retail build.
 *
 * @mangled FinishCharaVieweMain__Fv
 * @address 0x1A3470
 * @size 0x10
 */
void FinishCharaVieweMain();

/**
 * Runs one frame of the character viewer, and returns 1 so that the main loop leaves it at once.
 *
 * @mangled LoopCharaViewerMain__Fv
 * @address 0x1A3480
 * @size 0x10
 */
int LoopCharaViewerMain();
