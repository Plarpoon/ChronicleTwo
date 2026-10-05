#include "common.h"
#include "funcpoint.hpp"

// Code (.text)
s32 CheckTime(float time, float start, float end) {
    s32 outside;

    if (!(end <= start)) {
        if (time < start) {
            return 0;
        }
        outside = 1;
        if (time < end) {
            outside = 0;
        }
        return outside ^ 1;
    }
    if (!(start <= end)) {
        if (!(time < start)) {
            return 1;
        }
        if (!(time < end)) {
            return 0;
        }
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
s32 CFuncPointMngr::GetEventNum(s32 event_flag) {
    s32 count = 0;
    GetStart(FUNC_POINT_EVENT);
    CFuncPoint *point = Get();
    if (point != NULL) {
        do {
            if (point->event.flag & event_flag) {
                count += 1;
            }
            point = Get();
        } while (point != NULL);
    }
    GetEnd();
    return count;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", EnableFuncNum__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetStart__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Get__14CFuncPointMngrFv);
void CFuncPointMngr::GetEnd(void) {
    now = NULL;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Search__14CFuncPointMngrFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetLight__14CFuncPointMngrFPfP10CFuncPointiP15CFuncPointChecki);
void CFuncPointMngr::Step(s32 i, CFuncPointCheck *c) { this->UpdateFlag(i, c); }
s32 CFuncPointMngr::UpdateFlag(s32 type, CFuncPointCheck *check) {
    CFuncPoint *first;
    CFuncPoint *next;
    CFuncPoint *point;
    s32 active;
    s32 count;

    GetStart(type);
    count = 0;
    first = Get();
    point = first;
    if (first != NULL) {
        do {
            active = point->Check(check);
            point->active = active;
            if (active != 0) {
                count += 1;
            }
            next = Get();
            point = next;
        } while (next != NULL);
    }
    GetEnd();
    return count;
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
