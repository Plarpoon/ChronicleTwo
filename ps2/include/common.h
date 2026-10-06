#ifndef COMMON_H
#define COMMON_H

/**
 * @file
 * Provides the integer aliases, assembly inclusion markers and size assertion used by game code.
 */

#include "include_asm.h"
#include "types.h"

/** Checks a compile-time condition by forming an array type. */
#define STATIC_ASSERT(expr) typedef char _static_assert_##__COUNTER__[(expr) ? 1 : -1]

#endif
