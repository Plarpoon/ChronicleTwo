#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_997__4);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_863__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_890__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_891__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_892__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_893__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_894__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_914__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_950__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_1047__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", at_1091__2);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapjump", D_0037B06C);

// Small uninitialised data (.sbss)
unsigned char NowMainMapNo[0x4];
unsigned char NowSubMapNo[0x4];
unsigned char NowInteriorMapNo[0x4];
unsigned char OldInteriorMapNo[0x4];
unsigned char ScriptBuffer[0x4];
unsigned char InteriorFlag[0x4];
unsigned char old_bgm_no[0x4];

// Uninitialised data (.bss)
unsigned char now_script_file[0x40];
unsigned char MainMapInfo__2[0x20];
unsigned char SubMapInfo[0x20];
unsigned char at_912__4[0x80];
unsigned char old_mapname[0x40];
unsigned char OldPos[0x10];
unsigned char OldRot[0x10];
unsigned char OldCamPos[0x10];
unsigned char OldCamRef[0x10];
unsigned char PrevInterior[0x40];
unsigned char NowInterior[0x40];
unsigned char OldBgmStatus[0x20];
