#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1208);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1226__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1242__2);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_809__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_810__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_811__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_812__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_813__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_814__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_815__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_816__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_817__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_818__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_819__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_820__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_821__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_822__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_823__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_824__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_825__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_826__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_827__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_828__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_829__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_830__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_831__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_832__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_889__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_890__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_891__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_979__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1204__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1205__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1206);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1207);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1222__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1223__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1224__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1225__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1382);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1383);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1384);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1385__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1386__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1387__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1388__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1389__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1390);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1391);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1392);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1393);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1394__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1395__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1396__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1397__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1398__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1399__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1400__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1401__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1402__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", at_1403__2);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/eventedit", D_0037B040);

// Small uninitialised data (.sbss)
unsigned char g_cp_mode[0x4];
unsigned char g_cp_cursor[0x4];
unsigned char g_cp_selno[0x4];
unsigned char g_chara_pas_mode[0x4];
unsigned char g_chara_pas_cursor[0x4];
unsigned char g_chara_pas_selno[0x4];

// Uninitialised data (.bss)
unsigned char g_cmr_pas[0x950];
unsigned char g_chara_pas[0x4B0];
unsigned char g_info[0x40];
