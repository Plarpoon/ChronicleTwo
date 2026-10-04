#include "common.h"
#include "mapjump.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", GetMainMapNo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", GetSubMapNo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", ClearSubMapNo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", __ct__14MapJumpMapInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", SetMainMapInfo__FP14MapJumpMapInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", SetSubMapInfo__FP14MapJumpMapInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", SetScriptBuffer__FP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", PreLoadSync__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", MapJump__FP6CSceneP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", GetLoadMapInfo__FP17SCN_LOADMAP_INFO2i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", LoadSubMap__FP6CSceneii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", LoadMapScript__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", ReloadMapScript__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", LoadScript__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", GetOldInteriorMapNo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", InitInterior__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", InInterior__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", SaveBeforeInterior__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", SetInteriorDoorPos__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", GotoInterior__FP6CScenei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", DeleteInterior__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", ExitInterior__FP6CScenePi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", InteriorMapJump__FP6CScenei);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapjump", __sinit_mapjump_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_997__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_863__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_890__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_891__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_892__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_893__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_894__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_914__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_950__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_1047__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_1091__2__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", D_0037B06C__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(NowMainMapNo, 0x4);
INCLUDE_BSS(NowSubMapNo, 0x4);
INCLUDE_BSS(NowInteriorMapNo, 0x4);
INCLUDE_BSS(OldInteriorMapNo, 0x4);
INCLUDE_BSS(ScriptBuffer, 0x4);
INCLUDE_BSS(InteriorFlag, 0x4);
INCLUDE_BSS(old_bgm_no, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(now_script_file, 0x40);
INCLUDE_BSS(MainMapInfo__2, 0x20);
INCLUDE_BSS(SubMapInfo, 0x20);
INCLUDE_BSS(at_912__4, 0x80);
INCLUDE_BSS(old_mapname, 0x40);
INCLUDE_BSS(OldPos, 0x10);
INCLUDE_BSS(OldRot, 0x10);
INCLUDE_BSS(OldCamPos, 0x10);
INCLUDE_BSS(OldCamRef, 0x10);
INCLUDE_BSS(PrevInterior, 0x40);
INCLUDE_BSS(NowInterior, 0x40);
INCLUDE_BSS(OldBgmStatus, 0x20);
