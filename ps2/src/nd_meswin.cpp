#include "common.h"
#include "nd_meswin.hpp"

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
    return page_auto;
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
void ClsMes::SetHalfFontWPercent(float percent) {
    if (percent < 0.0f) {
        half_font_w_percent = 0.55f;
        return;
    }
    half_font_w_percent = percent;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", __ct__6ClsMesFv);
void ClsMes::SetBuff(s16 *buffer) {
    buff = buffer;
}
void ClsMes::SetBuff_system(s16 *buffer) {
    buff_system = buffer;
}
void ClsMes::SetDefColor(u32 rgba) {
    def_color = rgba;
    color = def_color;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", Preset__6ClsMesFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", SetWindowMode__6ClsMesFi);
s32 ClsMes::GetWindowMode(void) {
    return window_mode;
}
void ClsMes::SetWindowBgOpaqueFlg(s32 opaque) {
    bg_opaque = opaque;
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
s32 GetItemNoFromFontNo(s32 font_code) {
    s32 symbol;
    s32 item_no;

    symbol = (font_code - 0x8000) - 0x7B00;
    item_no = 1;
    if (symbol != 0xFE) {
        item_no = 2;
        switch (symbol) {
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
            return item_no;
        default:
            return -1;
        }
    } else {
        return item_no;
    }
}
void ClsMes::AddYokoHaba(s32 index, s32 value) {
    if (value < 0) return;
    line_w[index] += value;
}
void ClsMes::SetYokoHaba(s32 index, s32 width) {
    if (width >= 0) {
        line_w[index] = width;
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
float CalcAutoPosSet(float min, float max, float size, float ratio) {
    float position = max - min;
    position -= size;
    position *= ratio;
    position += min;
    return position;
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
s32 CheckPosInOutForArea(float *corner_a, float *corner_b, float *pos) {
    float first;
    float second;
    float lower;
    s32 axis;

    for (axis = 0; axis < 3; axis++) {
        first = corner_a[axis];
        second = corner_b[axis];
        lower = (first < second) ? first : second;
        if (pos[axis] < lower) {
            return 0;
        }
        first = (first > second) ? first : second;
        if (first < pos[axis]) {
            return 0;
        }
    }
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", CalcMoveNextPos__FPfPffPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", InitMovieCC__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/nd_meswin", MyStrCpyLineFeed__FPcPc);
void GetNextLineTop(char **text) {
    char *next = *text;
    while (true) {
        if (*next == '\n') {
            break;
        }
        next++;
    }
    *text = next + 1;
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
