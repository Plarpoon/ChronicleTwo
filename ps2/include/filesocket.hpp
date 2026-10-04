#pragma once

#include "common.h"

/**
 *
 * Reports that the file socket cannot load a file.
 *
 * @mangled LoadFileSocket__FPcPUi
 * @address 0x28D1D0
 * @size 0x10
 */
int LoadFileSocket(char *path, unsigned int *data);

/**
 *
 * Discards a request to write through the file socket.
 *
 * @mangled WriteFileSocket__FPcPUii
 * @address 0x28D1E0
 * @size 0x10
 */
void WriteFileSocket(char *path, unsigned int *data, int size);
