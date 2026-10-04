#pragma once

#include "common.h"

/**
 * @file
 * Declares the transfer of files over the network socket, the device that
 * paths with the "net:" prefix name; retail keeps only empty stubs.
 */

/**
 *
 * Loads a file sent over the network socket; gives the number of bytes loaded, always zero in retail.
 *
 * @mangled LoadFileSocket__FPcPUi
 * @address 0x28D1D0
 * @size 0x10
 */
int LoadFileSocket(char *path, unsigned int *data);

/**
 *
 * Writes a file over the network socket; does nothing in retail.
 *
 * @mangled WriteFileSocket__FPcPUii
 * @address 0x28D1E0
 * @size 0x10
 */
void WriteFileSocket(char *path, unsigned int *data, int size);
