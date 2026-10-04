#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditSetEffectBuffer__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", __ct__12CPaintEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditInitPlaceEffect__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPlaceEffect__FP10CEditPartsPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPaintEffect__FP10CEditPartsPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPEffectStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPEffectDraw__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditGetPEffectState__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPEffectEndCheck__Fv);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", EditPlaceAnimeEndCheck__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", __ct__11CStarEffectFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editeff", __sinit_editeff_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1038__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1039__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1040__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1106__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_1107__4);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", at_821__5);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", D_0037B070);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", __vt__12CPaintEffect);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editeff", __vt__11CStarEffect);

// Small uninitialised data (.sbss)
unsigned char EffectFlag[0x4];
unsigned char EffectState[0x4];
unsigned char PaintEffect[0x4];

// Uninitialised data (.bss)
unsigned char _StarEffect[0x300];
unsigned char CurPartsBuff[0x30];
unsigned char at_1037__6[0x20];
unsigned char at_1112__3[0x10];
unsigned char PlaceAnime[0x1B0];
