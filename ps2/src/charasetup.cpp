#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", GetCharacterSnd__FP16CUserDataManageriPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", SetupMainUnit__FP1P9mgCMemoryP9mgCMemoryiP6CSceneP16CUserDataManagerii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", GetCharaMemAllocSize__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", GetCharaMemAllocPtr__FP9mgCMemoryP9mgCMemoryii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", SetupUnitMan__FP6CSceneP16CUserDataManageriP14ROBO_INFO_DATA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", SetupMints__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", SetupMonica__FP6CSceneP16CUserDataManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", SetupRobo__FP6CSceneP16CUserDataManagerP14ROBO_INFO_DATA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", GetRoboPartsInfo__FP16CUserDataManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charasetup", SetupMonster__FP6CSceneP16CUserDataManager);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_919__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", mem_table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1110);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1113);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1161);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1162);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1216__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", robo_info_body);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1281__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", fname_tbl_1291);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", fname_tbl2_1298);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_868__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_869__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_870__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_871__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_872__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1000__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1001__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1002__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1003__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1004__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1005__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1006__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1007__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1008__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1009__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1010__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1011__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1012__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1013__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1014__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1015__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1016__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1017__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1018__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1111__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1112__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1149);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1150);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1212__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1213__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1214__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1215__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1268);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1269);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1270);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1271);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1272);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1273);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1274);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1275);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1276);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1277);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1292__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1293__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1294__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1295__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1296__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1297__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1299__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1300__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1301__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1302__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1303__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1304__3);

// Uninitialised data (.bss)
unsigned char robo_dat[0x30];
unsigned char r_robo_pname_1282[0x40];
unsigned char fname_1290[0x40];
