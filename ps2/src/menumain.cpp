#include "common.h"
#include "menumain.hpp"

// Code (.text)
void MenuScreenBlackBeltSet(s32 arg0) {
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuLoopType__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CheckTrushMenu__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", menu_GetSaveDataDungeon__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", menu_GetBattleAreaScene__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuSysData__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CheckBitFlagMenu__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CheckShortFlagMenu__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CheckStartChapter8__FP9CSaveData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", InitMenuEtcSpecialFlag__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", SetMenuEtcFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuEtcFlag__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuPrim__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuMainImageDataEnter__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", SetMenuFrameRate__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", SetMenuKeyCtrlEnv__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", DisablePadReset__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuMainInit__FP13MENU_INIT_ARG);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuMainExit__Fv);
s32 MenuMainLoop(void) {
    s32 temp_s0;

    temp_s0 = MenuMainKey();
    MenuMainDraw();
    return temp_s0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuMainKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuMainDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", NextMenuInit__FiP9mgCMemoryPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuCamInit__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuWorldTrans__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuPolygonSetEnv__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuPolygonEnvReset__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuCfgFileName__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuMainMessageBuffer__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuMainIMGPtr__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetMenuMainPosCfgBuffer__FPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", SetCommonMenuModeID__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", GetCommonMenuModeID__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CursorSaveOptionState__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", ReturnMenuIntern__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuAreaBoardNameStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CheckEventDay__FPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MakeMenuTopic__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", DrawMenuTopic__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuInternInit__FP9mgCMemoryii);
void CMenuInter::Initialize(s32 arg0) {
    (*(s16 *)((u8 *)this + 0x10)) = 1;
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 6;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s8 *)((u8 *)this + 0x12)) = 0;
    (*(s8 *)((u8 *)this + 0x13)) = 30;
    (*(s8 *)((u8 *)this + 0x14)) = 1;
    (*(s32 *)((u8 *)this + 0x8)) = -1;
    (*(s8 *)((u8 *)this + 0x15)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuCommonBaseDataEnter__FP9mgCMemoryPUiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuBaseTextureReEnter__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", InitEnd__10CMenuInterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", PushOk__10CMenuInterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", ReadBGTexture__10CMenuInterFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuInternSelectKey__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuInternSelectDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CopyActiveItemAndWeapon__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", CopyActiveIconTexture__FPP10mgCTextureiPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", MenuDebugModeDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", BookshelfMessageMake__FP6ClsMesiii);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menumain", __sinit_menumain_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", light_1062__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", lightcolor_1063__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_keyfunctbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_drawfunctbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_basedgRef__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_basedgCamPos__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", CommonMenuModeID__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1699__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_maintopic_colortbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_maintopic_colortbl_shadow__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", topic_tbl_1777__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", filetbl_2141__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", monster_table__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1028__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1440__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1598__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1599__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1621__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1624__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1625__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1630__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1635__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1640__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1683__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1684__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1736__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1737__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1738__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1739__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1740__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1741__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1742__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1778__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1779__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1780__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1781__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1782__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1783__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1784__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1785__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1786__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1787__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1788__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1789__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1859__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1930__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1931__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1932__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1933__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1934__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1935__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1936__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1937__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1938__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1956__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1957__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1958__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2003__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2004__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2142__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2143__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2144__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2145__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2146__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2329__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2330__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2331__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2332__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2333__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2334__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2335__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2344__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2345__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2439__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2440__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_2450__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", D_0037B030__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", MenuPrim__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", MenuPrevEndCode__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", MenuBGTextureBlock__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", MenuItemIconTextureBlock__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1514__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", menu_main_cfgname_1620__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", acttbl_1682__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", MenuTopicAlpha__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", fname_1858__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1865__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1866__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", at_1867__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menumain", loopnumtbl_2360__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MenuMainScene, 0x4);
INCLUDE_BSS(MenuActiveSaveData, 0x4);
INCLUDE_BSS(MenuUserDataManPtr, 0x4);
INCLUDE_BSS(MenuSystemDataPtr, 0x4);
INCLUDE_BSS(MenuConfigPtr, 0x4);
INCLUDE_BSS(MenuSaveDataDungeonPtr, 0x4);
INCLUDE_BSS(MenuFishAquarium, 0x4);
INCLUDE_BSS(MenuNowMapNo, 0x4);
INCLUDE_BSS(MenuNowMapType, 0x4);
INCLUDE_BSS(MenuMainSubDataPackAdr, 0x4);
INCLUDE_BSS(CMenuInterPt, 0x4);
INCLUDE_BSS(MenuInterMes, 0x4);
INCLUDE_BSS(MenuInterMesDrawFlag, 0x4);
INCLUDE_BSS(MenuAreaBrdForm, 0x4);
INCLUDE_BSS(MenuTimeBrdForm, 0x4);
INCLUDE_BSS(MenuAreaName, 0x4);
INCLUDE_BSS(MenuNowTime, 0x4);
INCLUDE_BSS(SndPortVol_Enemy, 0x4);
INCLUDE_BSS(ItemOverFlowCheckFlag, 0x4);
INCLUDE_BSS(MenuDrawEnv, 0x4);
INCLUDE_BSS(MenuCommonInfo, 0x4);
INCLUDE_BSS(MenuLoopType, 0x4);
INCLUDE_BSS(MenuEtcSpecialCode, 0x4);
INCLUDE_BSS(MenuEtcInfo, 0x8);
INCLUDE_BSS(MenuMoveItemPtr, 0x4);
INCLUDE_BSS(MenuBGMVolume_Save, 0x4);
INCLUDE_BSS(MenuFormMI2, 0x4);
INCLUDE_BSS(MenuItemCommandCounter, 0x4);
INCLUDE_BSS(menu_debug_flag, 0x4);
INCLUDE_BSS(MenuTopicAlphaCalc, 0x4);
INCLUDE_BSS(TopicTex, 0x4);
INCLUDE_BSS(old_light_menu, 0x4);
INCLUDE_BSS(HatumeiMenuOkFlag, 0x4);
INCLUDE_BSS(WorldMapOkFlag, 0x4);
INCLUDE_BSS(ManualMenuOkFlag, 0x4);
INCLUDE_BSS(DngMoveMenuOkFlag, 0x4);
INCLUDE_BSS(MenuDoubleDrawCheck, 0x4);
INCLUDE_BSS(refresh_cnt_1523, 0x4);
INCLUDE_BSS(init_1524, 0x8);
INCLUDE_BSS(at_1697__2, 0x8);
INCLUDE_BSS(at_1698__2, 0x8);
INCLUDE_BSS(MenuTopicType, 0x4);
INCLUDE_BSS(MenuTopicLength, 0x4);
INCLUDE_BSS(TopicFontX, 0x8);
INCLUDE_BSS(at_1976, 0x8);
INCLUDE_BSS(at_2209__3, 0x8);

// Uninitialised data (.bss)
INCLUDE_BSS(MenuMainStack, 0x30);
INCLUDE_BSS(MenuMainStack_Next, 0x30);
INCLUDE_BSS(CMenuInterStatic, 0x20);
INCLUDE_BSS(MenuPrimFix, 0x120);
INCLUDE_BSS(MenuItemUse, 0x20);
INCLUDE_BSS(MenuMainTextureReadBuf, 0x30);
INCLUDE_BSS(MenuSoundBuffer, 0x30);
INCLUDE_BSS(MenuArg, 0xA0);
INCLUDE_BSS(menu_old_chara_position, 0x10);
INCLUDE_BSS(menu_old_chara_rotation, 0x10);
INCLUDE_BSS(workchr_1622, 0x60);
INCLUDE_BSS(CommonMenuModeID2, 0x20);
INCLUDE_BSS(TopicFont, 0xC0);
INCLUDE_BSS(at_2351, 0x20);
