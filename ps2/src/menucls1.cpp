#include "common.h"
#include "menucls1.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", GetHatena__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", GetMenuBigNum__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMenuBigNum2__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMenuBigNum__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", __ct__9CMenuFontFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MenuMesInit__FP6ClsMes);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", __ct__7CDC2MesFv);
void CDC2Mes::SetMessData(s16 *arg0, s16 *arg1) {
    ((ClsMes *) this)->SetBuff_system(arg0);
    ((ClsMes *) this)->SetBuff(arg1);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MsgPreset__7CDC2MesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MsgPreset__7CDC2MesFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgCursor__7CDC2MesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", AddMsgCursor2__7CDC2MesFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", AddMsgCursor__7CDC2MesFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", CommandMsgCursor__7CDC2MesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", YesNoCursor__7CDC2MesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", YesNoCursor2__7CDC2MesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", GetMsgCursor__7CDC2MesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", GetMsgItemNo__7CDC2MesFi);
void CDC2Mes::SetFontColor(s32 r, s32 g, s32 b, s32 a) {
    this->SetDefColor(r | (g << 8 | (a << 24 | b << 16)));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetPutPos__7CDC2MesFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetPutPos__7CDC2MesFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetAbsPos__7CDC2MesFi);
s32 CDC2Mes::GetStringDrawWidthDC(s8 *arg0) {
    s32 temp_v0;

    temp_v0 = (s32) (((ClsMes *) this)->GetStrWidth(arg0));
    if (temp_v0 >= 0) {
        return temp_v0;
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMovePosCenteringGyou__7CDC2MesFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgItemNo__7CDC2MesFPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgItemNo__7CDC2MesFPPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgVolumeNo__7CDC2MesFPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgVolumeNo__7CDC2MesFPiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgVolumeNoOne__7CDC2MesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgItemPos__7CDC2MesFPii);
void CDC2Mes::MakeMsg(s32 arg0) {
    *(s16 *) ((u8 *) this + 0x295E) = arg0;
    *(u8 *) ((u8 *) this + 0x2980) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MakeMsg__7CDC2MesFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MakeMsg__7CDC2MesFP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MakeMsg__7CDC2MesFP13CGameDataUsedP13CGameDataUsed);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", StepMsg__7CDC2MesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", DrawMsg__7CDC2MesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMsgAlpha__7CDC2MesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", Initialize__13CMenuMoveItemFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", AttachForm__13CMenuMoveItemFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", CheckMove__13CMenuMoveItemFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", SetMoveItemInfo__13CMenuMoveItemFP19MENU_ITEM_MOVE_INFOPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", CheckRoboShieldKit__FP16CUserDataManagerP13CGameDataUsediPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", MenuUseItemCheckFunc__FP13CGameDataUsedP14CItemUseTargeti);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", CheckItemUseEnable__12CMenuItemUseFP13CGameDataUsediPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", UseItem__12CMenuItemUseFP13CGameDataUsediPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", UseItem__12CMenuItemUseFP13CGameDataUsedP14CItemUseTarget);
void CMenuItemUse::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
    *(s32 *) ((u8 *) this + 0x18) = 0;
}
s32 CheckNowStateUseThisItem(CGameDataUsed *arg0, CItemUseTarget *arg1) {
    return MenuUseItemCheckFunc(arg0, arg1, 0);
}

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucls1", __sinit_menucls1_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", MenuBigNum__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", sn_944__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1415__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", st_bittable_1654__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_905__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_906__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_907__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_908__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_909__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_910__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_911__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_912__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_913__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_914__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_915__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_916__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_945__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_946__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_947__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_948__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_949__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_950__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_951__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_952__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_953__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_954__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1104__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1328__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1512__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1513__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1514__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1623__3__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", D_0037B028__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucls1", at_1371__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MenuHatena_894, 0x4);
INCLUDE_BSS(init_895, 0x4);
INCLUDE_BSS(MenuHatena_1byte_897, 0x4);
INCLUDE_BSS(init_898, 0x4);
INCLUDE_BSS(at_1433__2, 0x4);
INCLUDE_BSS(MenuUsedItemNo, 0x4);
INCLUDE_BSS(MenuUsedItemType, 0x4);
INCLUDE_BSS(MenuUsedNotErrorCode, 0x4);
INCLUDE_BSS(MenuUsedTarget, 0x8);

// Uninitialised data (.bss)
INCLUDE_BSS(at_1407__2, 0x10);
INCLUDE_BSS(at_1436__3, 0x18);
