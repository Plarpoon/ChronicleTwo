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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_919__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", mem_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1110__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1113__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1161__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1162__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1216__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", robo_info_body__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1281__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", fname_tbl_1291__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", fname_tbl2_1298__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_868__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_869__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_870__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_871__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_872__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1000__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1001__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1002__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1003__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1004__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1005__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1006__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1007__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1008__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1009__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1010__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1011__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1012__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1013__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1014__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1015__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1016__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1017__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1018__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1111__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1112__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1149__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1150__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1212__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1213__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1214__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1215__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1268__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1269__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1270__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1271__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1272__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1273__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1274__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1275__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1276__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1277__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1292__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1293__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1294__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1295__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1296__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1297__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1299__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1300__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1301__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1302__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1303__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/charasetup", at_1304__3__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(robo_dat, 0x30);
INCLUDE_BSS(r_robo_pname_1282, 0x40);
INCLUDE_BSS(fname_1290, 0x40);
