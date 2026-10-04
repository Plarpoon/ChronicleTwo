#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", EditDebugInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", EditDebugMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", EditDebugStart__FiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", PrintCursor__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", EditDebugLoop__FP6CSceneP13EditDebugInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", EditDebugEnd__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", InitLightingEdit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", EndLightingEdit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", IsLightingEditMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", LightingEdit__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", tagGyoFish__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editdebug", LoadGyorace__Fv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", SelMax);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", SelData);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", SelText);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", SelHelp);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", LightSel);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", LightListNum);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1219);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1222);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1231);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1243);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1321);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1385);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1386);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1387);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1388);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1542);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_989);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_990);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_991);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_992);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_993);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_994);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_995);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_996);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_997);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_998);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_999);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1000);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1001);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1002);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1003);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1004);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1005);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1028__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1029__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1057);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1058);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1181);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1182);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1183);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1184);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1185);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1186);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1187);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1188);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1189);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1190);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1191);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1216__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1217);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1218);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1220);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1221);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1223);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1225);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1227);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1228);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1229);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1230);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1240__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1241__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1242);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1495);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1496);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1497);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1498);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1499);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1500);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1501__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1502);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1503);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1504);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1505);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1506__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1507__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1508);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1509);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1510);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1511);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1512);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1513);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1514);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1541);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1544__2);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", EventNo);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1059);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1063__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1224);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editdebug", at_1226);

// Small uninitialised data (.sbss)
unsigned char EditDebugFlag[0x4];
unsigned char EditDebugTexb[0x4];
unsigned char Select[0x4];
unsigned char SelTAG[0x4];
unsigned char sg_type[0x4];
unsigned char map_jump[0x4];
unsigned char save_no[0x4];
unsigned char load_no[0x4];
unsigned char condition[0x4];
unsigned char map_flag_no[0x4];
unsigned char LEditFlag[0x4];
unsigned char LightType[0x4];
unsigned char DirLightNo[0x4];
unsigned char fish_num[0x4];

// Uninitialised data (.bss)
unsigned char at_1237[0x10];
