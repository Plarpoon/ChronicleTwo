#include "common.h"
#include "funcpoint.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", CheckTime__Ffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", LimitTime__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", SubTime__Fff);
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
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetEventNum__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", EnableFuncNum__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetStart__14CFuncPointMngrFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Get__14CFuncPointMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetEnd__14CFuncPointMngrFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Search__14CFuncPointMngrFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", GetLight__14CFuncPointMngrFPfP10CFuncPointiP15CFuncPointChecki);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", Step__14CFuncPointMngrFiP15CFuncPointCheck);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/funcpoint", UpdateFlag__14CFuncPointMngrFiP15CFuncPointCheck);
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
