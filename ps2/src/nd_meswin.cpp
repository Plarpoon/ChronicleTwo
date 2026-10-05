#include "common.h"
#include "nd_meswin.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MySetPrim__FP11mgCDrawPrimii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", set2DSpriteEasy__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", _set2DSprite__FPcP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", set2DSprite__FP11mgCDrawPrim9mgRect_i_9mgRect_i_P10RGBAQ_TYPE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", FillRect__Fiiiiiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawFukidashi_sub__6ClsMesFP11mgCDrawPrimiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawFukidashi__6ClsMesFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetDrawSpeed__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetDrawSpeedDef__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetCaptionOff__6ClsMesFv);
s32 ClsMes::GetPageAutoFlg(void) {
    return (*(s32 *)((u8 *)this + 0x1dc));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetScrPosFromChar__FP11CCharacter2Pi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetStrWidth__6ClsMesFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetStrWidth__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", AutoSetSub__6ClsMesFP11CCharacter2P11CCharacter2Pi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcAutoPosSetData__FiiiiP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcMesWinXYFromFukidashiXY__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcFukidashiXY__6ClsMesFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", AutoSet__6ClsMesFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetBuffMesIdPtr__FPcii);
void ClsMes::SetHalfFontWPercent(float arg0) {
    if (arg0 < 0.0f) {
        (*(float *)((u8 *)this + 0xd0)) = 0.55f;
        return;
    }
    (*(float *)((u8 *)this + 0xd0)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", __ct__6ClsMesFv);
void ClsMes::SetBuff(s16 * arg0) {
    (*(s16 * *)((u8 *)this + 0x294c)) = arg0;
}
void ClsMes::SetBuff_system(s16 * arg0) {
    (*(s16 * *)((u8 *)this + 0x2950)) = arg0;
}
void ClsMes::SetDefColor(u32 arg0) {
    (*(s32 *)((u8 *)this + 0x1e28)) = arg0;
    (*(s32 *)((u8 *)this + 0x1e2c)) = (*(s32 *)((u8 *)this + 0x1e28));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", Preset__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetWindowMode__6ClsMesFi);
s32 ClsMes::GetWindowMode(void) {
    return (*(s32 *)((u8 *)this + 0x138));
}
void ClsMes::SetWindowBgOpaqueFlg(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x13c)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", StepNpcName__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", StepNormal__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", Step__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", State__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GoNextPage__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MyTextureMake_sub__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MyTextureMake__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetAndGetNameRegistTbl__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWinTbl_value__6ClsMesFPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWinTbl_value__6ClsMesFiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWinTbl_str__6ClsMesFPcPiPi);
void ClsMes::MakeMesWinTbl_str(int i, int *a2, int *a3) { this->MakeMesWinTbl_str((char*)this + i*50 + 0x1E59, a2, a3); }
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWinTbl_item__6ClsMesFiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetMesWidth_system__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetTextLineDataTop__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetTextLineDataTop_system__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", InitMesWinTbl__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetMesWinTbl__6ClsMesFiss);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcSpaceW__6ClsMesFiiPUs);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWinTbl__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWinTbl__6ClsMesFPc);
s32 GetItemNoFromFontNo(s32 arg0) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = (arg0 - 0x8000) - 0x7B00;
    var_v0 = 1;
    if (temp_v1 != 0xFE) {
        var_v0 = 2;
        switch (temp_v1) {                          /* irregular */
        case 0xE7:
            return 0x10;
        case 0xE8:
            return 0xF;
        case 0xE9:
            return 0xE;
        case 0xEA:
            return 0xD;
        case 0xEB:
            return 0xC;
        case 0xEC:
            return 0xB;
        case 0xED:
            return 0xA;
        case 0xEE:
            return 9;
        case 0xEF:
            return 8;
        case 0xF0:
            return 7;
        case 0xF1:
            return 6;
        case 0xF2:
            return 5;
        case 0xFB:
            return 4;
        case 0xFC:
            return 3;
        case 0xFD:
            /* Duplicate return node #32. Try simplifying control flow for better match */
            return var_v0;
        default:
            return -1;
        }
    } else {
        return var_v0;
    }
}
void ClsMes::AddYokoHaba(s32 index, s32 value) {
    if (value < 0) return;
    *(s32 *)((index << 2) + (s32)this + 0x258C) += value;
}
void ClsMes::SetYokoHaba(s32 arg0, s32 arg1) {
    if (arg1 >= 0) {
        *(s32 *) ((arg0 << 2) + (s32) this + 0x258C) = arg1;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", AddPage__6ClsMesFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", NeedMesWinWH__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", NeedMesWinWH__6ClsMesFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWin_init__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWin__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", PreMesMake__FPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeMesWin__6ClsMesFPcii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MakeAnd3DPosSet__6ClsMesFPcPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawFukidashiShadow__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcRectScale__F4RECTfP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetSelectCursorPos__6ClsMesF4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawYesNo__FP11mgCDrawPrimiiiiP10RGBAQ_TYPE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetPos_AbsPosSet__F4RECTiiiPiPi);
float CalcAutoPosSet(float a, float b, float c, float d) {
    float t = b - a;
    t -= c;
    t *= d;
    t += a;
    return t;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", RgbqToUint__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetFontColor__6ClsMesFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetGyouAlpha__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawFont__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetGoalCursorXY__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", StepSelectCursor__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawSelectCursor__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawEquipment__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawCross__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawRightDelta__6ClsMesFP11mgCDrawPrim);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawDigit__6ClsMesFP11mgCDrawPrimiiiiP10RGBAQ_TYPE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawPushButton__6ClsMesFP11mgCDrawPrimii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcCenteringXY__6ClsMesFPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetAbsWinData__6ClsMesFP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetOuterRectXYFromFukidashiPos__6ClsMesFP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcWindowOutRectFromInRect__Fi4RECTP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcWindowInRectFromOutRect__Fi4RECTP4RECT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", DrawMesWin__6ClsMesFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", Parametric__FPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", Quadratic__FfffPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcIntersectionPointSphereAndLine__FPffPfPfPfPf);
s32 CheckPosInOutForArea(float *arg0, float *arg1, float *arg2) {
    float a;
    float b;
    float low;
    s32 i;

    for (i = 0; i < 3; i++) {
        a = arg0[i];
        b = arg1[i];
        low = (a < b) ? a : b;
        if (arg2[i] < low) {
            return 0;
        }
        a = (a > b) ? a : b;
        if (a < arg2[i]) {
            return 0;
        }
    }
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcMoveNextPos__FPfPffPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", InitMovieCC__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MyStrCpyLineFeed__FPcPc);
void GetNextLineTop(s8 **arg0) {
    s8 *var_a2;

    var_a2 = (s8 *) (*arg0);
loop_1:
    if (*var_a2 != 0xA) {
        var_a2 += 1;
        goto loop_1;
    }
    *arg0 = var_a2 + 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", GetTopAddress__FPcii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MovieCCAnalyze__FPcii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MovieCCDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MovieCCInit__FPcii);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", __sinit_nd_meswin_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", p__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_3748__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4057__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4100__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4143__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4185__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", data_4206__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", waku_data__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_1124__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_1317__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_1724__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_1758__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2109__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2110__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2111__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2112__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2113__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2114__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2115__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2116__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2117__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2118__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2119__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2120__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2121__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2122__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2123__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2124__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2366__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2367__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2368__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2369__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2370__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2371__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2372__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2373__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2374__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2375__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2376__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2377__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2378__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2379__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2380__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2381__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2382__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2383__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2384__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2385__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2386__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2387__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2388__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2389__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2390__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2391__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2392__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2393__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2394__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2395__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2396__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2397__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2398__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2567__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2718__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_2900__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4276__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4472__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4574__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4634__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4635__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4636__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", at_4637__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/nd_meswin", D_0037AFEC__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MesAbsDrawOff, 0x4);
INCLUDE_BSS(MovieCCCnt, 0x4);
INCLUDE_BSS(MovieCCW, 0x4);
INCLUDE_BSS(MovieCCH, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(NameRegistTbl, 0xB0);
INCLUDE_BSS(MovieCCFont, 0xC0);
INCLUDE_BSS(MovieCCStart, 0x50);
INCLUDE_BSS(MovieCCClear, 0x50);
INCLUDE_BSS(MovieCCStr, 0x1B60);
