#include "common.h"
#include "helpmes.hpp"
#include "mglib.hpp"
#include "mainloop.hpp"
#include "snd_mngr.hpp"
#include "nd_meswin.hpp"
#include "mg_texture.hpp"

extern HELP_MES_INFO HelpMesInfo;
extern int ShowOffOnce;
extern int WindowMode;
extern ClsMes HelpMes;


// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", LoadHelpMes__FP1);
HELP_MES_INFO *GetHepMesInfo() {
    return &HelpMesInfo;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", CreateHelpMes__Fi);
#ifdef NONMATCHING
void StepHelpMes() {
    HELP_MES_INFO *info = GetHepMesInfo();
    if (info == NULL || !info->show) {
        return;
    }
    if (!info->created) {
        HelpMes.Preset(4);
        HelpMes.SetWindowMode(WindowMode);
        HelpMes.MakeMesWin(info->mes_no);
        HelpMes.fade_speed = 1.0f;
        if (info->fukidashi_pos < 0) {
            HelpMes.abs_win.x = info->x;
            HelpMes.abs_win.y = info->y;
        } else {
            HelpMes.fukidashi_pos = info->fukidashi_pos;
        }
        info->created = 1;
    }
    HelpMes.Step();
    if (info->time > 0 && --info->time == 0) {
        info->show = 0;
        info->created = 0;
        info->time = 0;
        info->mes_no = -1;
        info->x = 0;
        info->y = 0;
        info->fukidashi_pos = -1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", StepHelpMes__Fv);
#endif
void ShowOffOnceHelpMes() {
    ShowOffOnce = 1;
}
#ifdef NONMATCHING
void DrawHelpMes() {
    if (DebugInfo.param_off != 0) {
        return;
    }
    HELP_MES_INFO *info = GetHepMesInfo();
    if (info == NULL || !info->show) {
        return;
    }
    if (ShowOffOnce != 0) {
        ShowOffOnce = 0;
        return;
    }
    mgTexManager.ReloadTexture(HelpMes.texture_block, (sceVif1Packet *)NULL);
    HelpMes.DrawMesWin();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", DrawHelpMes__Fv);
#endif
#ifdef NONMATCHING
void ShowHelpMes(int mes_no, int time) {
    HELP_MES_INFO *info = GetHepMesInfo();
    if (info == NULL) {
        return;
    }
    if (info->mes_no != mes_no) {
        info->show = 0;
        info->created = 0;
        info->time = 0;
        info->mes_no = -1;
        info->x = 0;
        info->y = 0;
        info->fukidashi_pos = -1;
    }
    info->show = 1;
    info->mes_no = mes_no;
    info->time = time > 0 ? time + 1 : time;
    info->x = 18;
    info->y = mgScreenHeight - 31;
    info->fukidashi_pos = -1;
    WindowMode = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", ShowHelpMes__Fii);
#endif

#ifdef NONMATCHING
void ShowErrorHelpMes(int mes_no, int time) {
    HELP_MES_INFO *info = GetHepMesInfo();
    if (info == NULL) {
        return;
    }
    if (info->mes_no != mes_no) {
        info->show = 0;
        info->created = 0;
        info->time = 0;
        info->mes_no = -1;
        info->x = 0;
        info->y = 0;
        info->fukidashi_pos = -1;
    }
    info->show = 1;
    info->mes_no = mes_no;
    info->time = time > 0 ? time + 1 : time;
    info->fukidashi_pos = 8;
    WindowMode = 4;
    sndSePlay(GetSystemSndID(), 28, 0);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", ShowErrorHelpMes__Fii);
#endif

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", __sinit_helpmes_cpp);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", at_799__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", at_800__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/helpmes", D_0037B094__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(InitFlag__2, 0x4);
INCLUDE_BSS(WindowMode, 0x4);
INCLUDE_BSS(ShowOffOnce, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(HelpMesBuff, 0x1000);
INCLUDE_BSS(HelpMes, 0x295C);
INCLUDE_BSS(D_01F628BC, 0x4);
INCLUDE_BSS(HelpMesInfo, 0x20);
