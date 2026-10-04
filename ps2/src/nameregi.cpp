#include "common.h"
#include "nameregi.hpp"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", Sfida_default_Name__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", ALPHA_TABLE1__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", ALPHA_TABLE2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", STR_NUM_TABLE__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE_ASCII1__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE_ASCII2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", ascii_code_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegistFont_Table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameStrSelectModeTable__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegiSearchKanjiIndexTable__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", testchar__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", txt_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", txt_table2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1153__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", LimmitTable_1360__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1377__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", Convtable2_1382__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", addTable_1510__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1513__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1514__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1534__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", nameregist_baseboard_upper_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", colt_1808__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", table_1819__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", tex_commtbl_1822__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", gettbl0_2012__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_892__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_893__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1281__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1282__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1283__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1284__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1285__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1286__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1287__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1288__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1747__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1748__2__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", D_0037B084__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", __vt__13CNameRegiMenu__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegistMax__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", HIRA_TABLE1__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", HIRA_TABLE2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", HIRA_TABLE3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KATA_TABLE1__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KATA_TABLE2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KATA_TABLE3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE1__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", KIGOU_TABLE2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", jis_ptr_table__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", NameRegistGyouLimmitTable__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1081__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", convTbl_1579__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", convtbl_1792__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1795__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", get_Htable_1806__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_1807__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nameregi", at_2031__3__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(NameRegiCode, 0x4);
INCLUDE_BSS(NameRegiMenuPtr, 0x4);
INCLUDE_BSS(OldReloadTexNumber, 0x4);
INCLUDE_BSS(NameRegiTex1, 0x4);
INCLUDE_BSS(NameRegiBGTile, 0x4);
INCLUDE_BSS(NameRegiCursor, 0x4);
INCLUDE_BSS(NameRegiWaku, 0x4);
INCLUDE_BSS(NameregiGaiji, 0x8);
INCLUDE_BSS(at_1621__3, 0x8);
INCLUDE_BSS(at_1661__3, 0x8);
INCLUDE_BSS(at_1684__3, 0x8);
INCLUDE_BSS(at_1686, 0x8);
INCLUDE_BSS(at_1693__2, 0x8);

// Uninitialised data (.bss)
INCLUDE_BSS(Nameregi_Target, 0x50);
INCLUDE_BSS(NameRegiTopic, 0x40);
INCLUDE_BSS(NameRegiStack, 0x30);
INCLUDE_BSS(at_1171__3, 0x10);
INCLUDE_BSS(at_1669, 0x28);
INCLUDE_BSS(at_1755, 0x18);
