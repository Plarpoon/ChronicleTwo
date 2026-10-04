#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", SetEventKeyword__FPcPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", CheckDeleteNameRegisteItem__FP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", GetActiveFontMode__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", CopyAsciiToJis__13CNameRegiMenuFPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", CopyJisToAscii__13CNameRegiMenuFPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", CheckChronicleKanjiFont__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", GetNameRegistFontKanjiList__FiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", AdjustWaku__FP7CDC2MesP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", search_txt_jis__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", search_txt_asci__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", ConvertShitJiss2Ascii__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", ConvertAscii2ShitJiss__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", NameRegistInit__FP9mgCMemoryPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", NameRegistKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", NameRegistDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", CheckInputWord__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", nameregist_local_key__FP17MENU_SELECT_PARAMRiPsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", ConvertPositionNameRegi__13CNameRegiMenuFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", CheckKanjiPosition__13CNameRegiMenuFiPsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", KeyStep__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", GetSelectedActiveFont__13CNameRegiMenuFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", ChangeFontSelectMode__13CNameRegiMenuFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", ConvertNameRegiBaseBoardTable__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", DrawBaseBoard__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", DrawActiveFont__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", StepMarkCursor__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", DrawMarkCursor__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", DrawSelectedWord__13CNameRegiMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", DrawMessage__13CNameRegiMenuFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nameregi", __sinit_nameregi_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", Sfida_default_Name);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", ALPHA_TABLE1);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", ALPHA_TABLE2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", STR_NUM_TABLE);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE_ASCII1);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE_ASCII2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", ascii_code_table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegistFont_Table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameStrSelectModeTable);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegiSearchKanjiIndexTable);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", testchar);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", txt_table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", txt_table2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1153);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", LimmitTable_1360);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1377__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", Convtable2_1382);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", addTable_1510);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1513__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1514__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1534);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", nameregist_baseboard_upper_table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", colt_1808);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", table_1819);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", tex_commtbl_1822);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", gettbl0_2012);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_892__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_893__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1281__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1282__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1283__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1284__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1285__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1286__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1287__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1288__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1747__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1748__2);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", D_0037B084);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", __vt__13CNameRegiMenu);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegistMax);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", HIRA_TABLE1);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", HIRA_TABLE2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", HIRA_TABLE3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KATA_TABLE1);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KATA_TABLE2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KATA_TABLE3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE1);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", jis_ptr_table);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegistGyouLimmitTable);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1081__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", convTbl_1579);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", convtbl_1792);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1795);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", get_Htable_1806);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1807);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_2031__3);

// Small uninitialised data (.sbss)
unsigned char NameRegiCode[0x4];
unsigned char NameRegiMenuPtr[0x4];
unsigned char OldReloadTexNumber[0x4];
unsigned char NameRegiTex1[0x4];
unsigned char NameRegiBGTile[0x4];
unsigned char NameRegiCursor[0x4];
unsigned char NameRegiWaku[0x4];
unsigned char NameregiGaiji[0x8];
unsigned char at_1621__3[0x8];
unsigned char at_1661__3[0x8];
unsigned char at_1684__3[0x8];
unsigned char at_1686[0x8];
unsigned char at_1693__2[0x8];

// Uninitialised data (.bss)
unsigned char Nameregi_Target[0x50];
unsigned char NameRegiTopic[0x40];
unsigned char NameRegiStack[0x30];
unsigned char at_1171__3[0x10];
unsigned char at_1669[0x28];
unsigned char at_1755[0x18];
