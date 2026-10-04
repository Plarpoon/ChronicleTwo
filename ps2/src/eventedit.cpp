#include "common.h"
#include "eventedit.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", OutPutFile__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", DrawBox__FPfPfiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", DrawBox__FPA4_fiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", VectMatMul__FPfPfPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", evLoadDebugFont__FiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", MoveCamera__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", MoveCameraRef__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", MoveChara__FP11CCharacter2P9mgCCameraP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", InitEventEdit__FiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", ChkEventEditStart__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", EventEdit__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", DrawEventEdit__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/eventedit", __sinit_eventedit_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1208__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1226__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1242__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_809__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_810__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_811__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_812__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_813__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_814__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_815__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_816__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_817__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_818__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_819__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_820__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_821__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_822__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_823__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_824__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_825__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_826__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_827__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_828__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_829__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_830__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_831__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_832__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_889__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_890__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_891__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_979__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1204__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1205__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1206__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1207__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1222__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1223__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1224__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1225__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1382__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1383__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1384__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1385__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1386__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1387__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1388__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1389__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1390__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1391__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1392__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1393__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1394__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1395__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1396__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1397__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1398__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1399__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1400__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1401__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1402__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1403__2__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", D_0037B040__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(g_cp_mode, 0x4);
INCLUDE_BSS(g_cp_cursor, 0x4);
INCLUDE_BSS(g_cp_selno, 0x4);
INCLUDE_BSS(g_chara_pas_mode, 0x4);
INCLUDE_BSS(g_chara_pas_cursor, 0x4);
INCLUDE_BSS(g_chara_pas_selno, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(g_cmr_pas, 0x950);
INCLUDE_BSS(g_chara_pas, 0x4B0);
INCLUDE_BSS(g_info, 0x40);
