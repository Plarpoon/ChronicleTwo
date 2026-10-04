#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", GetMesTxt__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", PhotoAddProjection__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", InitPhotoTitle__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", InitTakePhoto__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", LoadTakePhoto__FiP9mgCMemoryP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", StartTakePhoto__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", EndTakePhoto__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", NowTakePhoto__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", IsEnablePhotoMenu__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", HidePhoto__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", GhostPhotoTiming__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", LoopTakePhoto__FP11CPadControlP15CInventUserData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", DrawTakePhoto__FP17USER_PICTURE_INFOPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", SetTookPhotoData__FP17USER_PICTURE_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", DrawTakePhotoSystem__FiP15CInventUserData);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/photo", __sinit_photo_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", mes_txt);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_936__6);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_793__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_794__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_795__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_796__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_797__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_798__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_799__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_800__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_801__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_802__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_803__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_804__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_805__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_806__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_807__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_808__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_809__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_810__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_811__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_812__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_813__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_814__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_815__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_816__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_817__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_852__6);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_997__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_1055);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", D_0037B088);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", null_txt);

// Small uninitialised data (.sbss)
unsigned char TakePhotoMode[0x4];
unsigned char AddProj__2[0x4];
unsigned char CameraTexb[0x4];
unsigned char WorkTex[0x4];
unsigned char ShutterAnmCnt[0x4];
unsigned char ShowTakePhotoCnt[0x4];
unsigned char OpenMenu[0x4];
unsigned char ShowTitleCnt[0x4];
unsigned char ShowLevelUpCnt[0x4];

// Uninitialised data (.bss)
unsigned char Font__3[0xC0];
unsigned char PhotoTitle[0x80];
