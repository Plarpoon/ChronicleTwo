#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

/**
 * Markers that stand in for code and data not decompiled yet.
 *
 * `INCLUDE_ASM("<directory>", <name>);` supplies a function and
 * `INCLUDE_RODATA("<directory>", <name>);` an initialised datum, from
 * `<directory>/<name>.s`. tools/mwccgap reads the markers and puts retail's
 * assembled bytes where they stand; the compiler itself sees nothing.
 */
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#endif
