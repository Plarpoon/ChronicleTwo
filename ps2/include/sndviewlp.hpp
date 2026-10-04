#pragma once

#include "common.h"
#include "mainloop.hpp"

/**
 * @file
 * Declares the entry, exit and per-frame functions of the debug sound viewer, a main-loop mode that is left empty in the retail build.
 */

/**
 * Prepares the sound viewer when the main loop enters it; does nothing in the retail build.
 *
 * @mangled InitSoundViewerMain__F13INIT_LOOP_ARG
 * @address 0x2A9270
 * @size 0x10
 */
void InitSoundViewerMain(INIT_LOOP_ARG arg);

/**
 * Releases the sound viewer when the main loop leaves it; does nothing in the retail build.
 *
 * @mangled FinishSoundVieweMain__Fv
 * @address 0x2A9280
 * @size 0x10
 */
void FinishSoundVieweMain();

/**
 * Runs one frame of the sound viewer, and returns 1 so that the main loop leaves it at once.
 *
 * @mangled LoopSoundViewerMain__Fv
 * @address 0x2A9290
 * @size 0x10
 */
int LoopSoundViewerMain();
