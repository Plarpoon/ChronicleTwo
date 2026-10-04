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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", dony_shoplist__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", menu_shop_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", imglist_1267__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", extbl_1278__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", exe_tbl_1509__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", extbl_1573__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", extbl_1589__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", randam_checktbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", tbl_2469__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2470__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1206__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1207__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1221__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1222__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1223__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1224__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1225__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1226__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1227__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1228__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1252__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1253__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1254__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1268__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1269__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1270__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1279__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1280__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1281__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1282__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1298__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1299__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1300__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1301__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1302__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1303__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1304__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1305__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1306__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1307__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1308__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1510__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1511__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1512__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1513__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1574__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1575__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1576__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1590__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1591__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1592__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1650__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1651__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1652__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1653__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1654__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1655__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1656__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1657__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1658__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1659__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1660__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1661__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1662__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1663__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1664__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1665__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1666__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1667__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1817__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1818__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1819__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1820__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1821__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1822__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1823__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1824__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1825__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1826__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1839__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1840__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_1881__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2114__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2115__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2116__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2117__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2118__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2172__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2173__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2219__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2220__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2221__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2222__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", at_2629__2__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", D_0037B048__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", __vt__14CMenuQuestView__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", __vt__9CShopMenu__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", t_offxy_1832__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", cursor_offsetxy_1836__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", cursortbl_1838__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", rgba_1897__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", QuestMoveRate__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menushop", packname_2171__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(NowSellMode, 0x4);
INCLUDE_BSS(CShopPtr, 0x4);
INCLUDE_BSS(Tex_Shop, 0x4);
INCLUDE_BSS(Tex_Mt0, 0x4);
INCLUDE_BSS(Now_ShopListNum, 0x4);
INCLUDE_BSS(Now_ShopDataReadPtr, 0x4);
INCLUDE_BSS(Now_Shop_ID, 0x4);
INCLUDE_BSS(Spi_PriceList, 0x4);
INCLUDE_BSS(shop_mode_prev_1326, 0x4);
INCLUDE_BSS(init_1327, 0x8);
INCLUDE_BSS(at_1581__2, 0x8);
INCLUDE_BSS(at_1582__3, 0x8);
INCLUDE_BSS(at_1595__3, 0x8);
INCLUDE_BSS(at_1685__2, 0x8);
INCLUDE_BSS(at_1831__2, 0x8);
INCLUDE_BSS(CShopMenuPt, 0x4);
INCLUDE_BSS(QuestMan, 0x4);
INCLUDE_BSS(QuestDataPtr, 0x4);
INCLUDE_BSS(Tex_QuestMemo, 0x4);
INCLUDE_BSS(QuestMenuMes, 0x4);
INCLUDE_BSS(ActiveQuestInfo, 0x4);
INCLUDE_BSS(QuestTilePatternXY, 0x8);
INCLUDE_BSS(QuestCursorPos, 0x8);
INCLUDE_BSS(QuestListTopY, 0x4);
INCLUDE_BSS(QuestCommentWinX, 0x4);
INCLUDE_BSS(QuestScrlBarY, 0x4);
INCLUDE_BSS(QuestScrlBarH, 0x4);
INCLUDE_BSS(QuestViewCommentFlag, 0x4);
INCLUDE_BSS(QuestReactionCommentGyouNum, 0x4);
INCLUDE_BSS(ScoopMan, 0x4);
INCLUDE_BSS(ScmFlagCtrl, 0x4);
INCLUDE_BSS(menu_debug_questselect, 0x4);
INCLUDE_BSS(Menu_Memo_ViewMode, 0x4);
INCLUDE_BSS(MenuQuestView, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(MenuLocalStack, 0x30);
INCLUDE_BSS(QuestCommentMes, 0x10);
