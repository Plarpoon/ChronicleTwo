#include "common.h"
#include "editeff.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditSetEffectBuffer__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", __ct__12CPaintEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditInitPlaceEffect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPlaceEffect__FP10CEditPartsPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPaintEffect__FP10CEditPartsPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPEffectStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPEffectDraw__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditGetPEffectState__Fv);
s32 EditPEffectEndCheck(void) {
    if (EditGetPEffectState() == 3) {
        EditInitPlaceEffect();
        return 3;
    }
    return (EditGetPEffectState() == 0) ^ 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", ParamInit__11CStarEffectFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Step__11CStarEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Draw__11CStarEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", ParamInit__12CPaintEffectFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Step__12CPaintEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Draw__12CPaintEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditInitPlaceAnime__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditNowPlaceAnime__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditSetPlaceAnime__FiP9CMapParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPlaceAnime__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPlaceAnime2__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPlaceAnimeDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Step__11CPlaceAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Step2__11CPlaceAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", Draw__11CPlaceAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditGetPlaceAnimeState__Fv);
s32 EditPlaceAnimeEndCheck(void) {
    if (EditGetPlaceAnimeState() == 3) {
        EditInitPlaceAnime();
        return 3;
    }
    return (EditGetPlaceAnimeState() == 0) ^ 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", __ct__11CStarEffectFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", __sinit_editeff_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1038__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1039__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1040__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1106__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1107__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_821__5__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", D_0037B070__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", __vt__12CPaintEffect__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", __vt__11CStarEffect__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(EffectFlag, 0x4);
INCLUDE_BSS(EffectState, 0x4);
INCLUDE_BSS(PaintEffect, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(_StarEffect, 0x300);
INCLUDE_BSS(CurPartsBuff, 0x30);
INCLUDE_BSS(at_1037__6, 0x20);
INCLUDE_BSS(at_1112__3, 0x10);
INCLUDE_BSS(PlaceAnime, 0x1B0);
