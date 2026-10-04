#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", _MOVIE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewExit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewLoop__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", __sinit_movieviewlp_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", tag_movie);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_786__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_843__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_844__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1028__8);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1029__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1030__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1031__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1032__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1033__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1034__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1035__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1036__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1037__5);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", D_0037B064);

// Small uninitialised data (.sbss)
unsigned char MovieScene[0x4];
unsigned char MovieView[0x4];
unsigned char RushWork__2[0x4];
unsigned char performance_meter_flag[0x4];
unsigned char MovieListNum[0x4];
unsigned char MovieList[0x4];
unsigned char MovieLine[0x4];
unsigned char MovieSelect[0x4];
unsigned char spi_MovieStack[0x4];
unsigned char MovieSpecialMode[0x4];
unsigned char MovieSpecialModeInfo[0x8];
unsigned char MovieMode[0x4];
unsigned char init_792[0x4];
unsigned char init_795[0x4];
unsigned char init_798[0x4];
unsigned char init_801[0x4];

// Uninitialised data (.bss)
unsigned char DataBuffer__2[0x30];
unsigned char Stack_ReadBuff__2[0x30];
unsigned char buf0_791[0x30];
unsigned char buf1_794[0x30];
unsigned char dbuf0_797[0x30];
unsigned char dbuf1_800[0x30];
