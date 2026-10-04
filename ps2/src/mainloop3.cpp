#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", FutureMapSelect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", InitHDDMenu__FP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", HDDMenuLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", EmergencyMessage__Fi);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", __sinit_mainloop3_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_801__5);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_802__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_803__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_805__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_807__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_809__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_810__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_870__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_871__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_872__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_873__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_881__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_882__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_939__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_940__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_941__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_942__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_943__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_944__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_945__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_946__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_947__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_948__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_949__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_950__7);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_951__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_952__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_953__5);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", D_0037B09C);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_804__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_806__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_808__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_811__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_883__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_884__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", emergency_mes);

// Small uninitialised data (.sbss)
unsigned char select_795[0x4];
unsigned char init_796[0x4];
unsigned char sel_map_798[0x4];
unsigned char init_799[0x4];
unsigned char HddConnect[0x4];
unsigned char AppInstall[0x4];
unsigned char FreeSpace[0x4];
unsigned char sel_hdd[0x4];
unsigned char now_install[0x4];
unsigned char error_code[0x4];
unsigned char inst_work[0x4];
unsigned char col_962[0x4];
unsigned char init_963[0x4];
unsigned char txt_965[0x4];

// Uninitialised data (.bss)
unsigned char buf0__2[0x30];
unsigned char buf1__2[0x30];
unsigned char dbuf0[0x30];
unsigned char dbuf1[0x30];
unsigned char Stack__2[0x30];
