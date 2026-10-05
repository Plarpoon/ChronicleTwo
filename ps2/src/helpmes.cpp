#include "common.h"
#include "helpmes.hpp"
#include "mglib.hpp"
#include "mainloop.hpp"
#include "snd_mngr.hpp"
#include "nd_meswin.hpp"
#include "mg_texture.hpp"
#include "dataread.hpp"
#include "mg_memory.hpp"
#include <cstdio>
#include <cstring>

extern HELP_MES_INFO HelpMesInfo;
extern int ShowOffOnce;
extern int WindowMode;
extern ClsMes HelpMes;
extern int LanguageCode;
extern char HelpMesBuff[0x1000];
extern int InitFlag__2;


// Code (.text)
#ifdef NONMATCHING
void LoadHelpMes(u_long128 *buffer) {
    char path[76];
    int size;
    sprintf(path, "etc/help%d.mes", LanguageCode);
    if (LoadFile2(path, buffer, &size, 0) != 0) {
        if (size > sizeof(HelpMesBuff)) {
            printf("HMes Buffer Over!!(%d/%dbyte)", size, sizeof(HelpMesBuff));
            return;
        }
        memcpy(HelpMesBuff, buffer, size);
        InitFlag__2 = 1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", LoadHelpMes__FP1);
#endif
HELP_MES_INFO *GetHepMesInfo() {
    return &HelpMesInfo;
}
#ifdef NONMATCHING
void CreateHelpMes(int tex_no) {
    if (!InitFlag__2) return;
    HelpMes.Init();
    HelpMes.Preset(4);
    HelpMes.SetWindowMode(0);
    HelpMes.SetBuff((short *)HelpMesBuff);
    HelpMes.texture_block = tex_no;
    ShowOffOnce = 0;
    HelpMesInfo.show = 0;
    HelpMesInfo.created = 0;
    HelpMesInfo.time = 0;
    HelpMesInfo.mes_no = -1;
    HelpMesInfo.x = 0;
    HelpMesInfo.y = 0;
    HelpMesInfo.fukidashi_pos = -1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", CreateHelpMes__Fi);
#endif
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
#ifdef NONMATCHING
void __sinit_helpmes_cpp() {
    new ((u_long128 *)&HelpMes) ClsMes;
    HelpMesInfo.time = 0;
    HelpMesInfo.mes_no = -1;
    HelpMesInfo.fukidashi_pos = -1;
    HelpMesInfo.show = 0;
    HelpMesInfo.y = 0;
    HelpMesInfo.x = 0;
    HelpMesInfo.created = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/helpmes", __sinit_helpmes_cpp);
#endif

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
