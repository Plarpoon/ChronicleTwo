#include "common.h"
#include "sceneload.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", LoadMapData__FR17SCN_LOADMAP_INFO2i);
void SCN_LOADMAP_INFO2::Initialize(void) {
    memset(this, 0, 0x1A8);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", LoadChara__6CSceneFiPUiPcP9mgCMemoryP9mgCMemoryP9mgCMemoryii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", DeleteChara__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", CopyChara__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", LoadMapFromMemory__6CSceneFiP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", LoadMapFromMemory__6CSceneFiiP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", Initialize__39mgCObjectStack_21CList_12EMAP_MESSAGE__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", __ct__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", LoadMapBGStep__6CSceneFP17SCN_LOADMAP_INFO2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", LoadMap__6CSceneFiP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", __as__17SCN_LOADMAP_INFO2FRC17SCN_LOADMAP_INFO2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneload", DeleteMap__6CSceneFii);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_820__6__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_885__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_886__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_887__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_888__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_889__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_890__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_958__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_959__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_1116__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_1117__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneload", at_1118__2__DATA);
