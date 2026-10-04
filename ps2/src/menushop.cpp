#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", GetDonyShopLineUp__FPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", CheckSyojiHin__5CShopFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", CheckRobotCore__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", CheckEventItem__5CShopFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", GetPrice__5CShopFP13CGameDataUsedPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", CheckMoney__5CShopFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", AddMoney__5CShopFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", _SHOP_ANALYZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", _PRICE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", AnalyzeShopList__5CShopFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", AttachForm__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", IsCancelNoneLoadItem__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", UpdataScrlBar__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", InitEnd__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", KeyStep__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", CalcTex__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", CalcCursorPosition__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", SearchNowPosItemExist__9CShopMenuFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", ShopSellListDraw__FRiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", MenuShopInit__FP9mgCMemoryPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", MenuShopKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", MenuShopDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", UnderMsg__14CMenuQuestViewFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", SelectMax__14CMenuQuestViewFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", InitEnd__14CMenuQuestViewFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", KeyStep__14CMenuQuestViewFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", MenuNPCQuestViewInit__FP9mgCMemoryPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", MenuNPCQuestViewKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", MenuNPCQuestViewDraw__Fv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menushop", __sinit_menushop_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", dony_shoplist);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", menu_shop_tag);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", imglist_1267);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", extbl_1278);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", exe_tbl_1509);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", extbl_1573);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", extbl_1589);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", randam_checktbl);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", tbl_2469);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2470);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1206__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1207__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1221__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1222__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1223__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1224__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1225__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1226__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1227__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1228__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1252);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1253);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1254);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1268__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1269__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1270__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1279__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1280__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1281__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1282__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1298__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1299__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1300__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1301__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1302__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1303__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1304__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1305__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1306__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1307__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1308__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1510__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1511__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1512__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1513__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1574);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1575__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1576);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1590__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1591__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1592__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1650);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1651);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1652);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1653);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1654__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1655__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1656__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1657__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1658);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1659);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1660);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1661__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1662);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1663);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1664__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1665);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1666);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1667);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1817);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1818);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1819);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1820);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1821);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1822);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1823__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1824__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1825__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1826__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1839__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1840__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1881);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2114__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2115__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2116__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2117__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2118__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2172__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2173__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2219__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2220);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2221);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2222);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2629__2);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", D_0037B048);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", __vt__14CMenuQuestView);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", __vt__9CShopMenu);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", t_offxy_1832);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", cursor_offsetxy_1836);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", cursortbl_1838);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", rgba_1897);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", QuestMoveRate);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", packname_2171);

// Small uninitialised data (.sbss)
unsigned char NowSellMode[0x4];
unsigned char CShopPtr[0x4];
unsigned char Tex_Shop[0x4];
unsigned char Tex_Mt0[0x4];
unsigned char Now_ShopListNum[0x4];
unsigned char Now_ShopDataReadPtr[0x4];
unsigned char Now_Shop_ID[0x4];
unsigned char Spi_PriceList[0x4];
unsigned char shop_mode_prev_1326[0x4];
unsigned char init_1327[0x8];
unsigned char at_1581__2[0x8];
unsigned char at_1582__3[0x8];
unsigned char at_1595__3[0x8];
unsigned char at_1685__2[0x8];
unsigned char at_1831__2[0x8];
unsigned char CShopMenuPt[0x4];
unsigned char QuestMan[0x4];
unsigned char QuestDataPtr[0x4];
unsigned char Tex_QuestMemo[0x4];
unsigned char QuestMenuMes[0x4];
unsigned char ActiveQuestInfo[0x4];
unsigned char QuestTilePatternXY[0x8];
unsigned char QuestCursorPos[0x8];
unsigned char QuestListTopY[0x4];
unsigned char QuestCommentWinX[0x4];
unsigned char QuestScrlBarY[0x4];
unsigned char QuestScrlBarH[0x4];
unsigned char QuestViewCommentFlag[0x4];
unsigned char QuestReactionCommentGyouNum[0x4];
unsigned char ScoopMan[0x4];
unsigned char ScmFlagCtrl[0x4];
unsigned char menu_debug_questselect[0x4];
unsigned char Menu_Memo_ViewMode[0x4];
unsigned char MenuQuestView[0x4];

// Uninitialised data (.bss)
unsigned char MenuLocalStack[0x30];
unsigned char QuestCommentMes[0x10];
