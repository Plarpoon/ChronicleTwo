#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", FutureMapSelect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", InitHDDMenu__FP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", HDDMenuLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", EmergencyMessage__Fi);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mainloop3", __sinit_mainloop3_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_801__5__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_802__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_803__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_805__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_807__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_809__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_810__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_870__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_871__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_872__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_873__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_881__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_882__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_939__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_940__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_941__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_942__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_943__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_944__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_945__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_946__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_947__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_948__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_949__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_950__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_951__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_952__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_953__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", D_0037B09C__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_804__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_806__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_808__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_811__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_883__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", at_884__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mainloop3", emergency_mes__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(select_795, 0x4);
INCLUDE_BSS(init_796, 0x4);
INCLUDE_BSS(sel_map_798, 0x4);
INCLUDE_BSS(init_799, 0x4);
INCLUDE_BSS(HddConnect, 0x4);
INCLUDE_BSS(AppInstall, 0x4);
INCLUDE_BSS(FreeSpace, 0x4);
INCLUDE_BSS(sel_hdd, 0x4);
INCLUDE_BSS(now_install, 0x4);
INCLUDE_BSS(error_code, 0x4);
INCLUDE_BSS(inst_work, 0x4);
INCLUDE_BSS(col_962, 0x4);
INCLUDE_BSS(init_963, 0x4);
INCLUDE_BSS(txt_965, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(buf0__2, 0x30);
INCLUDE_BSS(buf1__2, 0x30);
INCLUDE_BSS(dbuf0, 0x30);
INCLUDE_BSS(dbuf1, 0x30);
INCLUDE_BSS(Stack__2, 0x30);
