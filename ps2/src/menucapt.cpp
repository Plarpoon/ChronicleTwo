#include "common.h"
#include "menucapt.hpp"
#include "mg_memory.hpp"
#include "mg_texture.hpp"
#include "mg_drawprim.hpp"
#include "mg_tanime.hpp"
#include "mglib.hpp"
#include "menucommon.hpp"
#include "menudraw.hpp"
#include "menumain.hpp"
#include "mainloop.hpp"
#include "scenesnd.hpp"
#include "sound.hpp"
#include "snd_mngr.hpp"
#include "dataread.hpp"

#include <cstdio>
#include <cstring>

#ifdef NONMATCHING
static int MenuChapterMode;
static MENU_CHAPTER_INFO *MenuChapterInfo;
static mgCTexture *MenuChapterBG;
static mgCTexture *MenuChapter_Logo;
static unsigned int MenuChapterSnd_ID;
static int menu_snd_counter;
static int menu_chap_error_check_cnt;
static int wait_cnt_918;
static int init_919;
static int voiceflag_921;
static int init_922;
static mgCMemory MenuChapterStack;
static char *chap_voice_851[8] = {
    (char *)"0060600.wav", (char *)"0270310.wav", (char *)"0360260.wav", (char *)"0420120.wav",
    (char *)"0500010.wav", (char *)"0600360.wav", (char *)"0700010.wav", (char *)"0800140.wav"
};
#endif

// Code (.text)
#ifdef NONMATCHING
void MenuChapterInit(mgCMemory *stack, int *tex_block, int open_type, int chapter) {
    char image_path[96];
    char voice_path[140];
    int file_size;
    MenuChapterStack.stSetBuffer(stack->stack + stack->stack_used, stack->stack_size - stack->stack_used);
    MenuChapterInfo = (MENU_CHAPTER_INFO *)MenuChapterStack.Alloc(2);
    MenuChapterInfo->tex_block[0] = tex_block[0];
    MenuChapterInfo->tex_block[1] = tex_block[1];
    MenuChapterInfo->logo_alpha = 0.0f;
    sprintf(image_path, "chap%d.img", chapter);
    MenuChapterStack.Align64();
    u_long128 *image_buffer = MenuChapterStack.stack + MenuChapterStack.stack_used;
    file_size = LoadFileMenu(image_path, image_buffer, 1);
    if (file_size <= 0) {
        file_size = LoadFileMenu((char *)"chap0.img", image_buffer, 1);
    }
    MenuChapterStack.Alloc((file_size + 15) >> 4);
    mgTexManager.EnterIMGFile((unsigned char *)image_buffer, MenuChapterInfo->tex_block[0], 0, 0);
    MenuChapterBG = mgTexManager.GetTexture((char *)"chapbg", -1);
    MenuChapter_Logo = mgTexManager.GetTexture((char *)"chaplogo", -1);

    mgCMemory sound_memory;
    sound_memory.stSetBuffer(MenuChapterStack.stack + MenuChapterStack.stack_used, 0x280);
    MenuChapterStack.Alloc(0x280);
    MenuChapterStack.Align64();
    menu_snd_counter = 0;
    unsigned int *sound_buffer = (unsigned int *)(MenuChapterStack.stack + MenuChapterStack.stack_used);
    LoadFile2((char *)"snd2/sp/SP_007.snd", sound_buffer, &file_size, 0);
    MenuChapterStack.Alloc((file_size + 15) >> 4);
    sndInitPort(8);
    MenuChapterSnd_ID = sndLoadSound(8, sound_buffer, &sound_memory);
    strcpy(voice_path, chap_voice_851[chapter]);
    CSnd.StreamOpenFast(1, voice_path);
    while (CSnd.StreamOpenState() != 0) {}
    CSnd.StreamStandBy(1);
    while (CSnd.StreamOpenState() != 0) {}
    MenuChapterMode = MENU_CHAPTER_MODE_FADE_IN;
    MenuMainScene->fade.FadeIn(30);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", MenuChapterInit__FP9mgCMemoryPiii);
#endif
#ifdef NONMATCHING
int MenuChapterKey() {
    if (init_919 == 0) {
        wait_cnt_918 = 0;
        init_919 = 1;
    }
    if (init_922 == 0) {
        voiceflag_921 = 0;
        init_922 = 1;
    }
    int fade_done = MenuMainScene->fade.FadeCheck();
    if (MenuChapterMode == MENU_CHAPTER_MODE_FADE_OUT) {
        return fade_done != 0;
    }
    if (MenuChapterMode == MENU_CHAPTER_MODE_SHOW) {
        ++MenuChapterInfo->show_cnt;
        ++menu_chap_error_check_cnt;
        int stream_state = CSnd.StreamGetState(1);
        if (stream_state == 0x8000 || menu_chap_error_check_cnt > 1500) {
            voiceflag_921 = 1;
        }
        if (voiceflag_921 != 0 && stream_state == 0) {
            if (menu_snd_counter == 0) {
                CSnd.StreamStop(1);
                CSnd.StreamClose(1);
            }
            ++menu_snd_counter;
        }
        if (menu_snd_counter == 36) {
            sndSePlay(MenuChapterSnd_ID, 0, 0);
        }
        if (MenuChapterInfo->show_cnt > 300 && menu_snd_counter > 345) {
            MenuMainScene->fade.FadeOut(60, 0.0f, 0.0f, 0.0f);
            MenuChapterMode = MENU_CHAPTER_MODE_FADE_OUT;
        }
        return 0;
    }
    if (MenuChapterMode == MENU_CHAPTER_MODE_FADE_IN && fade_done != 0) {
        ++menu_snd_counter;
        if (menu_snd_counter == 2) {
            CSnd.StreamSetVol(1, 32767, 32767);
            CSnd.StreamPlay(1);
            wait_cnt_918 = 0;
        }
        if (CalcMenuAdd(&MenuChapterInfo->logo_alpha, 3.0f, 128.0f) != 0) {
            MenuChapterMode = MENU_CHAPTER_MODE_SHOW;
            MenuChapterInfo->show_cnt = 0;
            menu_snd_counter = 0;
            menu_chap_error_check_cnt = 0;
            voiceflag_921 = 0;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", MenuChapterKey__Fv);
#endif
#ifdef NONMATCHING
void MenuChapterDraw() {
    mgTexManager.ReloadTexture(MenuChapterInfo->tex_block[0], (sceVif1Packet *)0);
    DrawMenuFillBox(128, 0, 0, 0);
    mgCDrawPrim prim;
    SetSpriteEnv(&prim, 0);
    prim.Begin(MG_PRIM_SPRITE);
    if (MenuChapterBG != 0) {
        prim.Texture(MenuChapterBG);
        prim.Color(128, 128, 128, 128);
        mgRect<int> source(0, 0, 512, 448);
        mgRect<int> screen(0, 0, 512, mgScreenHeight);
        PrimQuad(&prim, screen, source);
    }
    if (MenuChapter_Logo != 0) {
        prim.Texture(MenuChapter_Logo);
        prim.Color(128, 128, 128, (int)MenuChapterInfo->logo_alpha);
        mgRect<int> title(0, 0, 512, 64);
        PrimQuad(&prim, 0.0f, (float)mgScreenHeight / 2.0f - 32.0f - 12.0f, title);
        prim.Color(128, 128, 128, 128);
        mgRect<int> overlay(0, 64, 512, 64);
        PrimQuad(&prim, 0.0f, 0.0f, overlay);
    }
    prim.End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", MenuChapterDraw__Fv);
#endif

// Static initialiser (.init)
#ifndef NONMATCHING
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menucapt", __sinit_menucapt_cpp);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", chap_voice_851__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_852__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_853__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_854__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_855__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_856__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_857__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_858__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_859__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_902__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_903__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_904__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_905__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", at_906__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/menucapt", D_0037B054__DATA);

// Small uninitialised data (.sbss)
#ifndef NONMATCHING
INCLUDE_BSS(MenuChapterMode, 0x4);
INCLUDE_BSS(MenuChapterInfo, 0x4);
INCLUDE_BSS(MenuChapterBG, 0x4);
INCLUDE_BSS(MenuChapter_Logo, 0x4);
INCLUDE_BSS(MenuChapterSnd_ID, 0x4);
INCLUDE_BSS(menu_snd_counter, 0x4);
INCLUDE_BSS(menu_chap_error_check_cnt, 0x4);
INCLUDE_BSS(wait_cnt_918, 0x4);
INCLUDE_BSS(init_919, 0x4);
INCLUDE_BSS(voiceflag_921, 0x4);
INCLUDE_BSS(init_922, 0x4);
#endif

// Uninitialised data (.bss)
#ifndef NONMATCHING
INCLUDE_BSS(MenuChapterStack, 0x30);
#endif
