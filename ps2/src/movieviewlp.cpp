#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", _MOVIE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewExit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewLoop__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", __sinit_movieviewlp_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", tag_movie__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_786__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_843__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_844__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1028__8__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1029__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1030__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1031__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1032__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1033__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1034__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1035__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1036__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1037__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", D_0037B064__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MovieScene, 0x4);
INCLUDE_BSS(MovieView, 0x4);
INCLUDE_BSS(RushWork__2, 0x4);
INCLUDE_BSS(performance_meter_flag, 0x4);
INCLUDE_BSS(MovieListNum, 0x4);
INCLUDE_BSS(MovieList, 0x4);
INCLUDE_BSS(MovieLine, 0x4);
INCLUDE_BSS(MovieSelect, 0x4);
INCLUDE_BSS(spi_MovieStack, 0x4);
INCLUDE_BSS(MovieSpecialMode, 0x4);
INCLUDE_BSS(MovieSpecialModeInfo, 0x8);
INCLUDE_BSS(MovieMode, 0x4);
INCLUDE_BSS(init_792, 0x4);
INCLUDE_BSS(init_795, 0x4);
INCLUDE_BSS(init_798, 0x4);
INCLUDE_BSS(init_801, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(DataBuffer__2, 0x30);
INCLUDE_BSS(Stack_ReadBuff__2, 0x30);
INCLUDE_BSS(buf0_791, 0x30);
INCLUDE_BSS(buf1_794, 0x30);
INCLUDE_BSS(dbuf0_797, 0x30);
INCLUDE_BSS(dbuf1_800, 0x30);
