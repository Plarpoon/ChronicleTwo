#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", MenuChapterInit__FP9mgCMemoryPiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", MenuChapterKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", MenuChapterDraw__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", __sinit_menucapt_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", chap_voice_851);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_852__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_853__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_854__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_855__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_856__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_857__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_858__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_859__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_902__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_903__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_904__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_905__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_906__5);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", D_0037B054);

// Small uninitialised data (.sbss)
unsigned char MenuChapterMode[0x4];
unsigned char MenuChapterInfo[0x4];
unsigned char MenuChapterBG[0x4];
unsigned char MenuChapter_Logo[0x4];
unsigned char MenuChapterSnd_ID[0x4];
unsigned char menu_snd_counter[0x4];
unsigned char menu_chap_error_check_cnt[0x4];
unsigned char wait_cnt_918[0x4];
unsigned char init_919[0x4];
unsigned char voiceflag_921[0x4];
unsigned char init_922[0x4];

// Uninitialised data (.bss)
unsigned char MenuChapterStack[0x30];
