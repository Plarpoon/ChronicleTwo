#pragma once

/**
 * @file
 * Declares CodeWarrior runtime conversion helpers used by game code.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Converts a floating-point value to a signed integer using the runtime helper.
 */
int fptosi(float value);

/**
 * Converts a floating-point value to an unsigned integer using the runtime helper.
 */
unsigned int fptoui(float value);

/**
 * Initializes an array allocated with the CodeWarrior placement-array layout.
 */
void *__construct_new_array(void *buffer, void *(*constructor)(void *), void *destructor, unsigned int element_size,
                            int count);

#ifdef __cplusplus
}
#endif
