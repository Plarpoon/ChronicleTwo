#pragma once

#include "common.h"

/**
 * @file
 * Declares the entry, exit and per-frame functions of the debug texture viewer, a main-loop mode that is left empty in the retail build.
 */

/**
 *
 * Parameters that the main loop hands to a mode when it enters it.
 *
 */
struct INIT_LOOP_ARG;

/**
 * Prepares the texture viewer when the main loop enters it; does nothing in the retail build.
 *
 * @mangled InitTextuerViewerMain__F13INIT_LOOP_ARG
 * @address 0x1A3490
 * @size 0x10
 */
void InitTextuerViewerMain(INIT_LOOP_ARG arg);

/**
 * Releases the texture viewer when the main loop leaves it; does nothing in the retail build.
 *
 * @mangled FinishTextuerVieweMain__Fv
 * @address 0x1A34A0
 * @size 0x10
 */
void FinishTextuerVieweMain();

/**
 * Runs one frame of the texture viewer, and returns 1 so that the main loop leaves it at once.
 *
 * @mangled LoopTextuerViewerMain__Fv
 * @address 0x1A34B0
 * @size 0x10
 */
int LoopTextuerViewerMain();
