#include "common.h"
#include "maintex.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"
#include "mg_memory.hpp"
#include "mainloop.hpp"
#include "dataread.hpp"
#include "gaiji.hpp"
#include "photo.hpp"
#include "dng_main.hpp"
#include "effectlist.hpp"
#include "scene.hpp"
#include "scenesnd.hpp"
#include "userdata.hpp"
#include "monster.hpp"
#include "colprim.hpp"
#include "swordeffect.hpp"
#include "character.hpp"
#include "dng_hud.hpp"
#include "dng_effect.hpp"
#include "snd_mngr.hpp"
#include <cstdio>

// Code (.text)
void GetTextureInfo(CScene *scene) {
    TEX_ShadowTexture = mgTexManager.GetTexture("work", -1);
    TEX_SystenFrame = mgTexManager.GetTexture("frame", -1);
    TEX_SystenFrame2 = mgTexManager.GetTexture("frame2", -1);
    TEX_StatusIcon = mgTexManager.GetTexture("status_icon", -1);
    TEX_DummyIcon1 = mgTexManager.GetTexture("icon_dmy1", -1);
    TEX_DummyIcon2 = mgTexManager.GetTexture("icon_dmy2", -1);
    TEX_SystemEffect1 = mgTexManager.GetTexture("effect00", -1);
    TEX_SystemEffect2 = mgTexManager.GetTexture("effect01", -1);
    TEX_SystemEffect3 = mgTexManager.GetTexture("effect02", -1);
    TEX_SystemEffectSw = mgTexManager.GetTexture("sweff", -1);
    TEX_ExFx_FIRE = mgTexManager.GetTexture("bteffe_fla", -1);
    TEX_ExFx_ICE = mgTexManager.GetTexture("bteffe_chi", -1);
    TEX_ExFx_THUN = mgTexManager.GetTexture("bteffe_lig", -1);
}
#ifdef NONMATCHING
void MainTextureInterface(mgCMemory *memory, CScene *scene) {
    mgTexManager.EnterIMGFile(GetGaijiImgPtr(), 0x58, NULL, NULL);
    ReLoadFontTexture(0x58);
    mgTexManager.EnterIMGFile(GetFontTex2ImgPtr(), 0x58, NULL, NULL);
    memory->Align64();
    u_long128 *image = memory->stAllocTest(1);
    char path[80];
    int size;
    sprintf(path, "img/esystem%d.img", LanguageCode);
    LoadFile(path, image, &size);
    mgTexManager.EnterIMGFile((u_char *)image, 0x67, memory, NULL);
    memory->Alloc((size + 15) / 16);
    LoadTakePhoto(0x67, memory, image);
    memory->Align64();
    u_long128 *pack = memory->stAllocTest(1);
    sprintf(path, "dungeon/articles/tex01_%d.chr", LanguageCode);
    LoadFile(path, pack, &size);
    memory->Alloc((size + 15) / 16);
    const char *names[7] = {"frame_basic.img", "effect00.img", "beffect_00.img", "potbeam.img",
                            "water_ref.img", "fire.img", "bteffe_4ex.img"};
    int blocks[7] = {0x48, 0x49, 0x4A, 0x4A, 0x59, 0x4B, 0x6B};
    for (int i = 0; i < 7; ++i) {
        mgTexManager.EnterIMGFile((u_char *)GetPackFile((u_int *)pack, (char *)names[i], &size),
                                  blocks[i], i == 4 ? NULL : memory, NULL);
    }
    printf("TEXBLK_LAST = %d\n", 0xAE);
    mgTexManager.EnterTexture(0x64, "work", NULL, mgScreenWidth, mgScreenHeight, 0x20, NULL, 0, 0);
    mgTexManager.EnterTexture(0x64, "work2", NULL, mgScreenWidth / 3, mgScreenHeight / 3, 0x20, NULL, 0, 0);
    mgTexManager.EnterTexture(0x4B, "fire_work", NULL, mgScreenWidth, mgScreenHeight, 0x20, NULL, 0, 0);
    mgTexManager.EnterTexture(0x65, "capture", NULL, mgScreenWidth, mgScreenHeight, 0x13, NULL, 0, 0);
    mgTexManager.EnterTexture(0x59, "water_work", NULL, mgScreenWidth, mgScreenHeight, 0x13, NULL, 0, 0);
    scene->fade.SetCrossTexture(mgTexManager.GetTexture("capture", -1), &BuffReadData[0x20000]);
    GetTextureInfo(scene);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", MainTextureInterface__FP9mgCMemoryP6CScene);
#endif
#ifdef NONMATCHING
void calcWeaponParamWhp(CActiveMonster *monster, CColPrim *col_prim) {
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    int kind = col_prim->param->kind;
    if (kind != 0 && kind != 4 && kind != 11 && kind != 12) return;
    float previous = (float)battle->GetWhpNowVol(0);
    float wear = (float)monster->whp * 0.5f;
    wear -= wear * (float)battle->weapon_param[0].status[1] * 0.005f;
    if (col_prim->status & 0x20) wear *= 1.3f;
    if (col_prim->status & 0x40) wear *= 0.8f;
    if (battle->AddWhp(0, -wear) <= 0.0f && previous > 0.0f) battle->AddAbsRate(0, -0.1f, NULL);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", calcWeaponParamWhp__FP14CActiveMonsterP8CColPrim);
#endif
#ifdef NONMATCHING
void calcWeaponParam2(int type, int divisor) {
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    int status = battle->GetSpecialStatus(1);
    if (type != 1 && type != 5) return;
    float previous = (float)battle->GetWhpNowVol(1);
    float wear = 1.0f - (float)battle->weapon_param[1].status[1] * 0.002f;
    if (status & 0x20) wear *= 1.3f;
    if (status & 0x40) wear *= 0.8f;
    if (battle->AddWhp(1, -(wear / (float)divisor)) <= 0.0f && previous > 0.0f)
        battle->AddAbsRate(1, -0.1f, NULL);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", calcWeaponParam2__Fii);
#endif
#ifdef NONMATCHING
void SetDamageParam(CColPrim *col_prim, int chara_no) {
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    if (battle->chr_no == USER_CHARA_MONSTER) {
        col_prim->damage = battle->weapon_param[chara_no].status[0];
    } else {
        int whp;
        battle->GetNowWhp(chara_no, &whp);
        col_prim->damage = whp > 0 ? battle->weapon_param[chara_no].status[0] : 0;
        for (int i = 0; i < DAMAGE_ELEMENT_MAX; ++i)
            col_prim->element[i] = battle->weapon_param[chara_no].status[i + 2];
        u32 status = battle->GetSpecialStatus(chara_no);
        if ((status & 4) && iRand(10) != 1) status &= ~4;
        if ((status & 8) && iRand(20) != 1) status &= ~8;
        col_prim->status = status;
    }
    col_prim->attacker = battle->chr_no;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", SetDamageParam__FP8CColPrimi);
#endif
#ifdef NONMATCHING
void AddExpWeaponParam(float exp, int chara_no, int type) {
    CBattleCharaInfo *battle = GetBattleCharaInfo();
    int level_up = 0;
    int slot = 0;
    if (battle->chr_no == chara_no) {
        switch (type) {
        case 1:
        case 8:
            battle->AddAbs(0, exp, &level_up);
            slot = 0;
            break;
        case 2:
            battle->AddAbs(1, exp, &level_up);
            slot = 1;
            break;
        case 3: {
            float half = exp / 2.0f;
            if (battle->AddAbs(0, half, &level_up) >= 1.0f) slot = 0;
            if (battle->AddAbs(1, half, &level_up) >= 1.0f) slot = 1;
            break;
        }
        case 4:
            battle->AddAbs(0, exp, NULL);
            break;
        }
    } else {
        switch (battle->chr_no) {
        case USER_CHARA_MONSTER:
            battle->AddAbs(0, exp, &level_up);
            slot = 0;
            break;
        case USER_CHARA_ROBO:
            battle->AddAbs(0, exp, NULL);
            break;
        case USER_CHARA_MAX:
        case USER_CHARA_MONICA: {
            float half = exp / 2.0f;
            if (battle->AddAbs(0, half, &level_up) >= 1.0f) slot = 0;
            if (battle->AddAbs(1, half, &level_up) >= 1.0f) slot = 1;
            break;
        }
        }
    }
    if (level_up != 0) {
        LevelupInfo.SetLevelUpInfo(0x100, mgScreenHeight / 2, slot, 0);
        sndSePlay(SystemSND_ID, 0x1E, 0);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", AddExpWeaponParam__Ffii);
#endif
#ifdef NONMATCHING
void SetSwordBlurEffect(CCharacter2 *chara, mgCMemory *memory, int blur_type) {
    CSWordAfterEffect *effect = new (memory->Alloc(12)) CSWordAfterEffect;
    chara->sword_effect[0] = effect;
    effect->Initialize(memory, 12, 8);
    int u = 0;
    int v = 0x20;
    if (blur_type == 0) {
        u = 0x40;
        v = 0;
    } else if (blur_type == 1) {
        v = 0;
    }
    effect->SetTexture(0x4A, TEX_SystemEffectSw, u, v, 0x40, 0x20);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/maintex", SetSwordBlurEffect__FP11CCharacter2P9mgCMemoryi);
#endif

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_792__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_793__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_794__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_795__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_796__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_797__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_798__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_799__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_800__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_801__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_802__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_803__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_804__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_819__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_820__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_821__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_822__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_823__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_824__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_825__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_826__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_827__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_828__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_829__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_830__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_831__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_832__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/maintex", at_936__3__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(TEX_ShadowTexture, 0x4);
INCLUDE_BSS(TEX_SystenFrame, 0x4);
INCLUDE_BSS(TEX_SystenFrame2, 0x4);
INCLUDE_BSS(TEX_StatusIcon, 0x4);
INCLUDE_BSS(TEX_DummyIcon1, 0x4);
INCLUDE_BSS(TEX_DummyIcon2, 0x4);
INCLUDE_BSS(TEX_SystemEffect1, 0x4);
INCLUDE_BSS(TEX_SystemEffect2, 0x4);
INCLUDE_BSS(TEX_SystemEffect3, 0x4);
INCLUDE_BSS(TEX_SystemEffectSw, 0x4);
INCLUDE_BSS(TEX_ExFx_FIRE, 0x4);
INCLUDE_BSS(TEX_ExFx_ICE, 0x4);
INCLUDE_BSS(TEX_ExFx_THUN, 0x4);
