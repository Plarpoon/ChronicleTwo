#include "common.h"
#include "movieviewlp.hpp"
#include "mg_memory.hpp"
#include "mg_texture.hpp"
#include "gaiji.hpp"
#include "dataread.hpp"
#include "movie.hpp"
#include "scenesnd.hpp"
#include "gamepad.hpp"
#include "prespr.hpp"
#include "font.hpp"
#include <cstdio>
#include <cstring>
#include "mglib.hpp"
#include "scriptinterpreter.hpp"
#include "snd_mngr.hpp"

// File-local data supplied by the retail assembly while data migration is pending.
extern CGamePad GamePad__2;
extern CScene *MovieScene;
extern CMovie *MovieView;
extern mgCTexture *RushWork__2;
extern MOVIE_LIST_ENTRY *MovieList;
extern int MovieListNum;
extern short MovieLine;
extern short MovieSelect;
extern short MovieSpecialMode;
extern short MovieSpecialModeInfo[3];
extern int MovieMode;
extern SPI_TAG_PARAM tag_movie[];
extern mgCMemory buf0_791, buf1_794, dbuf0_797, dbuf1_800;
extern char init_792, init_795, init_798, init_801;
extern mgCMemory *spi_MovieStack;
extern int performance_meter_flag;
extern mgCMemory DataBuffer__2;
extern mgCMemory Stack_ReadBuff__2;

// Code (.text)
#ifdef NONMATCHING
static int _MOVIE(SPI_STACK *args, int argc) {
    MOVIE_LIST_ENTRY *entry = &MovieList[MovieListNum];
    if (entry == NULL) {
        return 0;
    }
    char *title = spiGetStackString(&args[0]);
    char *file_name = spiGetStackString(&args[1]);
    int bgm_no = argc >= 3 ? spiGetStackInt(&args[2]) : -1;
    entry->name = mgCopyString(title, spi_MovieStack);
    entry->file_name = mgCopyString(file_name, spi_MovieStack);
    entry->bgm_no = bgm_no;
    MovieListNum++;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", _MOVIE__FP9SPI_STACKi);
#endif
#ifdef NONMATCHING
void MovieViewInit(INIT_LOOP_ARG arg) {
    MovieScene = GetMainScene();
    MovieScene->Initialize();
    mgInitFont();
    mgCMemory *main_stack = GetMainStack();
    main_stack->stack_used = 0;
    main_stack->lock = 0;
    if (!init_792) { buf0_791.Init(); init_792 = 1; }
    if (!init_795) { buf1_794.Init(); init_795 = 1; }
    if (!init_798) { dbuf0_797.Init(); init_798 = 1; }
    if (!init_801) { dbuf1_800.Init(); init_801 = 1; }
    u_long128 *vif0 = main_stack->stAlloc64(10000);
    u_long128 *vif1 = main_stack->stAlloc64(10000);
    mgInitVif1Packet(vif0, vif1, 10000);
    buf0_791.stSetBuffer(main_stack->stAlloc64(30000), 30000);
    buf1_794.stSetBuffer(main_stack->stAlloc64(30000), 30000);
    dbuf0_797.stSetBuffer(main_stack->stAlloc64(60000), 60000);
    dbuf1_800.stSetBuffer(main_stack->stAlloc64(60000), 60000);
    DataBuffer__2.stSetBuffer(main_stack->stAlloc64(100000), 100000);
    mgSetPacketBuffer(&buf0_791, &buf1_794);
    mgSetDataBuffer(&dbuf0_797, &dbuf1_800, 1);
    mgSetBackGround(0.0f, 0.0f, 0.0f, 128.0f);
    SetTextureTable(100, 20, &DataBuffer__2);
    mgTexManager.EnterIMGFile(GetGaijiImgPtr(), 0, NULL, NULL);
    ReLoadFontTexture(0);
    mgTexManager.EnterIMGFile(GetFontTex2ImgPtr(), 0, NULL, NULL);
    MovieView = new ((u_long128 *)main_stack->Alloc(0x2396)) CMovie;
    MovieListNum = 0;
    MovieList = new ((u_long128 *)main_stack->Alloc(0x32)) MOVIE_LIST_ENTRY[64];
    MovieLine = 0;
    MovieSelect = 0;
    MovieSpecialMode = MOVIE_SPECIAL_MODE_NONE;
    spi_MovieStack = main_stack;
    char script[0x5000];
    int script_size;
    if (LoadFile2("mv.cfg", script, &script_size, 0) != 0) {
        CScriptInterpreter interpreter;
        interpreter.SetTag(tag_movie);
        interpreter.SetScript(script, script_size);
        interpreter.Run();
    }
    main_stack->Align64();
    Stack_ReadBuff__2.stSetBuffer(main_stack->stAlloc(0), 0);
    Stack_ReadBuff__2.stack_used = 0;
    Stack_ReadBuff__2.lock = 0;
    Stack_ReadBuff__2.Align64();
    MovieSpecialModeInfo[0] = MovieSpecialModeInfo[1] = MovieSpecialModeInfo[2] = 0;
    mgTexManager.EnterTexture(10, "moviework", NULL, mgScreenWidth, mgScreenHeight, 32, NULL, 0, 0);
    RushWork__2 = mgTexManager.GetTexture("moviework", 10);
    performance_meter_flag = mgGetPerformanceMeterFlag();
    mgPerformanceMeter(0);
    MovieMode = MOVIE_VIEW_MODE_SELECT;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewInit__F13INIT_LOOP_ARG);
#endif
void MovieViewExit() {
    sndSeAllStop(-1);
    mgCloseFont();
    mgPerformanceMeter(performance_meter_flag);
}
#ifdef NONMATCHING
int MovieViewLoop() {
    if (MovieMode == MOVIE_VIEW_MODE_SELECT) {
        if (GamePad__2.Down(PAD_START) || GamePad__2.Down(PAD_CROSS)) {
            return 1;
        }
        if (GamePad__2.Down(PAD_UP)) --MovieSelect;
        if (GamePad__2.Down(PAD_DOWN)) ++MovieSelect;
        if (GamePad__2.Down(PAD_L1)) MovieSelect -= 7;
        if (GamePad__2.Down(PAD_R1)) MovieSelect += 7;
        if (MovieSelect < 0) MovieSelect = 0;
        if (MovieSelect >= MovieListNum) MovieSelect = MovieListNum - 1;
        if (MovieSelect < MovieLine) --MovieLine;
        if (MovieLine < 0) MovieLine = 0;
        if (MovieLine + 7 < MovieSelect) ++MovieLine;

        if (GamePad__2.Down(PAD_CIRCLE)) {
            Stack_ReadBuff__2.stack_used = 0;
            Stack_ReadBuff__2.lock = 0;
            MOVIE_LIST_ENTRY &entry = MovieList[MovieSelect];
            mgTexManager.ReloadTexture(10, (sceVif1Packet *)NULL);
            if (entry.bgm_no > 0) {
                MovieScene->StopBGM(0);
                MovieScene->LoadBGM(entry.bgm_no, Stack_ReadBuff__2.stAlloc(0));
                MovieScene->PlayBGM(0, -1, 1.0f);
            }
            MovieSpecialMode = MOVIE_SPECIAL_MODE_NONE;
            char *file_name = entry.file_name;
            if (strcmp(entry.name, "promo") == 0) {
                MovieSpecialMode = MOVIE_SPECIAL_MODE_PROMO;
                MovieSpecialModeInfo[0] = 1;
                file_name = "PROMO1.PSS";
            } else if (strcmp(entry.name, "promo_tv") == 0) {
                MovieSpecialMode = MOVIE_SPECIAL_MODE_PROMO_TV;
                MovieSpecialModeInfo[0] = 1;
                file_name = "PROMO1TV.PSS";
            }
            MovieView->Load(file_name, &Stack_ReadBuff__2, 0x200, 0x1A0, true, false);
            MovieView->Play("moviework");
            do { MovieView->SwitchThread(); } while (!MovieView->IsStarted());
            MovieMode = MOVIE_VIEW_MODE_PLAY;
        }
        mgTexManager.ReloadTexture(0, (sceVif1Packet *)NULL);
        CFont font;
        font.Init();
        font.SetClearance(16, 20);
        font.SetFuchi(5);
        font.SetColor(0x80686A6B);
        char label[256];
        sprintf(label, "  :%18s    %s", "映像", "BGMID");
        for (int row = MovieLine, y = 40; row < MovieLine + 8 && row < MovieListNum && y < 201; ++row, y += 20) {
            sprintf(label, "  %d:%18s  ", row, MovieList[row].name);
            if (row == MovieSelect) label[1] = '>';
            font.SetStr(label);
            font.SetPos(40, y);
            font.DrawDirect(font.str, font.pos_x, font.pos_y);
        }
        return 0;
    }
    if (MovieMode == MOVIE_VIEW_MODE_PLAY) {
        mgPerformanceMeter(0);
        mgTexManager.ReloadTexture(10, (sceVif1Packet *)NULL);
        MovieView->SwitchThread();
        CPreSprite sprite;
        sprite.Initialize(NULL, NULL);
        sprite.Preset2D();
        sprite.AlphaBlendEnable(0);
        sprite.TextureMapEnable(1);
        sprite.Begin(MG_PRIM_SPRITE);
        sprite.Color(0, 0, 0, 0x80);
        sprite.SetIRect(0, 0, 0x200, 0x1A0, 0, 0);
        sprite.Texture(RushWork__2);
        sprite.Color(0x80, 0x80, 0x80, 0x80);
        sprite.SetIRect(0, 0, 0x200, mgScreenHeight, 0, 0);
        sprite.End();
        if (GamePad__2.Down(PAD_R1) || GamePad__2.Down(PAD_R2) ||
            GamePad__2.Down(PAD_L1) || GamePad__2.Down(PAD_L2)) {
            mgPerformanceMeter(mgGetPerformanceMeterFlag() ^ 1);
        }
        if (MovieView->EndCheck() || GamePad__2.Down(PAD_START)) {
            MovieView->Term();
            MovieView->SwitchThread();
            MovieMode = MOVIE_VIEW_MODE_SELECT;
            MovieScene->StopBGM(0);
            Stack_ReadBuff__2.stack_used = 0;
            Stack_ReadBuff__2.lock = 0;
            if (MovieSpecialMode == MOVIE_SPECIAL_MODE_PROMO || MovieSpecialMode == MOVIE_SPECIAL_MODE_PROMO_TV) {
                ++MovieSpecialModeInfo[0];
                if (MovieSpecialModeInfo[0] < 4) {
                    char file_name[64];
                    if (MovieSpecialMode == MOVIE_SPECIAL_MODE_PROMO)
                        sprintf(file_name, "PROMO%d.PSS", MovieSpecialModeInfo[0]);
                    else
                        sprintf(file_name, "PROMO%dTV.PSS", MovieSpecialModeInfo[0]);
                    MovieView->Load(file_name, &Stack_ReadBuff__2, 0x200, 0x1A0, true, false);
                    MovieView->Play("moviework");
                    do { MovieView->SwitchThread(); } while (!MovieView->IsStarted());
                    MovieMode = MOVIE_VIEW_MODE_PLAY;
                } else {
                    MovieSpecialModeInfo[0] = 0;
                    MovieSpecialMode = MOVIE_SPECIAL_MODE_NONE;
                }
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/movieviewlp", MovieViewLoop__Fv);
#endif

// Static initialiser (.init)
extern "C" void __sinit_movieviewlp_cpp() {
    DataBuffer__2.Init();
    Stack_ReadBuff__2.Init();
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", tag_movie__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_786__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_843__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_844__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1028__8__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1029__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1030__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1031__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1032__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1033__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1034__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1035__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1036__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", at_1037__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/movieviewlp", D_0037B064__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(MovieScene, 0x4);
INCLUDE_BSS(MovieView, 0x4);
INCLUDE_BSS(RushWork__2, 0x4);
INCLUDE_BSS(performance_meter_flag, 0x4);
INCLUDE_BSS(MovieListNum, 0x4);
INCLUDE_BSS(MovieList, 0x4);
INCLUDE_BSS(MovieLine, 0x4);
INCLUDE_BSS(MovieSelect, 0x4);
INCLUDE_BSS(spi_MovieStack, 0x4);
INCLUDE_BSS(MovieSpecialMode, 0x4);
INCLUDE_BSS(MovieSpecialModeInfo, 0x8);
INCLUDE_BSS(MovieMode, 0x4);
INCLUDE_BSS(init_792, 0x4);
INCLUDE_BSS(init_795, 0x4);
INCLUDE_BSS(init_798, 0x4);
INCLUDE_BSS(init_801, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(DataBuffer__2, 0x30);
INCLUDE_BSS(Stack_ReadBuff__2, 0x30);
INCLUDE_BSS(buf0_791, 0x30);
INCLUDE_BSS(buf1_794, 0x30);
INCLUDE_BSS(dbuf0_797, 0x30);
INCLUDE_BSS(dbuf1_800, 0x30);
