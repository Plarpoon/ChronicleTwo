#include "common.h"
#include "funcpoint.hpp"

// Code (.text)
s32 CheckTime(float arg0, float arg1, float arg2) {
    /* L'ordre des declarations decide de l'attribution des registres chez
     * MWCC. Celui-ci n'est pas celui de m2c : il a ete trouve en enumerant
     * les ordres possibles, et c'est le seul qui rende les octets du disque.
     * */
    s32 var_v0;

    if (!(arg2 <= arg1)) {
        if (arg0 < arg1) {
            return 0;
        }
        var_v0 = 1;
        if (arg0 < arg2) {
            var_v0 = 0;
        }
        return var_v0 ^ 1;
    }
    if (!(arg1 <= arg2)) {
        if (!(arg0 < arg1)) {
            /* Duplicate return node #12. Try simplifying control flow for better match */
            return 1;
        }
        if (!(arg0 < arg2)) {
            return 0;
        }
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", LimitTime__Ff);
float SubTime(float a, float b) {
    float t = LimitTime(a - b);
    if (t <= 12.0f) return t;
    return 24.0f - t;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Initialize__10CFuncPointFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Check__10CFuncPointFP15CFuncPointCheck);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", CheckOver__FPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Step__9CObjAnimeFP12CObjAnimeEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", SetParam__9CObjAnimeFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetParam__9CObjAnimeFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", AssignFuncAnime__9CObjAnimeFP10CFuncPointP9CMapParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Add__14CFuncPointMngrFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Initialize__19CList_10CFuncPoint_Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Add__14CFuncPointMngrFiP19CList_10CFuncPoint_);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Reserve__14CFuncPointMngrFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", __ct__19CList_10CFuncPoint_Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetReserve__14CFuncPointMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", AddFromReserve__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetNum__14CFuncPointMngrFi);
s32 CFuncPointMngr::GetEventNum(s32 arg0) {
    s32 var_s0;
    struct var_v0_champs *var_v0;

    var_s0 = 0;
    this->GetStart(6);
    var_v0 = (struct var_v0_champs *) (this->Get());
    if (var_v0 != NULL) {
        do {
            if ((*(s32 *)((u8 *)var_v0 + 0x20)) & arg0) {
                var_s0 += 1;
            }
            var_v0 = (struct var_v0_champs *) (this->Get());
        } while (var_v0 != NULL);
    }
    this->GetEnd();
    return var_s0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", EnableFuncNum__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetStart__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Get__14CFuncPointMngrFv);
void CFuncPointMngr::GetEnd(void) {
    (*(s32 *)((u8 *)this + 0x2c)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Search__14CFuncPointMngrFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetLight__14CFuncPointMngrFPfP10CFuncPointiP15CFuncPointChecki);
void CFuncPointMngr::Step(s32 i, CFuncPointCheck *c) { this->UpdateFlag(i, c); }
s32 CFuncPointMngr::UpdateFlag(s32 arg0, CFuncPointCheck *arg1) {
    CFuncPoint *temp_v0;
    CFuncPoint *temp_v0_2;
    CFuncPoint *var_s0;
    s32 temp_v0_3;
    s32 var_s1;

    this->GetStart(arg0);
    var_s1 = 0;
    temp_v0 = (CFuncPoint *) (this->Get());
    var_s0 = (CFuncPoint *) (temp_v0);
    if (temp_v0 != NULL) {
        do {
            temp_v0_3 = (s32) (var_s0->Check(arg1));
            (*(s32 *)((u8 *)var_s0 + 0x1b0)) = temp_v0_3;
            if (temp_v0_3 != 0) {
                var_s1 += 1;
            }
            temp_v0_2 = (CFuncPoint *) (this->Get());
            var_s0 = (CFuncPoint *) (temp_v0_2);
        } while (temp_v0_2 != NULL);
    }
    this->GetEnd();
    return var_s1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", UpdateStatus__14CFuncPointMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Copy__14CFuncPointMngrFR14CFuncPointMngrP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Initialize__14CFuncPointMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", DrawFireEffect__FPA4_fP14CFuncPointMngrP15CFuncPointCheckfP10mgCTextureP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", DrawFireRaster__FPA4_fP14CFuncPointMngrP15CFuncPointCheckP11CFireRaster);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetSeSrcVolPan__FPA4_fP14CFuncPointMngrP15CFuncPointCheckPiPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetLightAnimeWeight__FP10CFuncPointi);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/funcpoint", at_475__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/funcpoint", at_1118__3__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/funcpoint", __vt__14CFuncPointMngr__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/funcpoint", __vt__19CList_10CFuncPoint___DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(init_1175, 0x4);
INCLUDE_BSS(init_1204, 0x4);
INCLUDE_BSS(init_1208, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(sp_3d_1174, 0x50);
INCLUDE_BSS(frame_1203, 0x110);
INCLUDE_BSS(Bound_1206, 0xB0);
INCLUDE_BSS(attr_1207, 0x90);
