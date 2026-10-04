#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

/**
 * Markers that stand in for code and data not decompiled yet.
 *
 * `INCLUDE_ASM("<directory>", <name>);` supplies a function and
 * `INCLUDE_RODATA("<directory>", <name>__DATA);` an initialised datum, from
 * `<directory>/<name>.s`. tools/mwccgap reads the markers and puts retail's
 * assembled bytes where they stand; the compiler itself sees nothing.
 */
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

/**
 * Reserves an uninitialised datum that has no typed definition yet.
 *
 * Like the `__DATA` name an `INCLUDE_RODATA` marker carries, the array is
 * defined under an alias of the datum's name, so a header can declare the
 * datum with its real type; the build gives the symbol its own name back.
 */
#define INCLUDE_BSS(NAME, SIZE) unsigned char NAME##__DATA[SIZE]

#endif
