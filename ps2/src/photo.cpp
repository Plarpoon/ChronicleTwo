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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", mes_txt__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_936__6__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_793__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_794__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_795__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_796__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_797__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_798__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_799__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_800__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_801__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_802__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_803__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_804__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_805__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_806__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_807__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_808__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_809__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_810__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_811__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_812__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_813__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_814__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_815__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_816__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_817__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_852__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_997__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", at_1055__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", D_0037B088__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/photo", null_txt__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(TakePhotoMode, 0x4);
INCLUDE_BSS(AddProj__2, 0x4);
INCLUDE_BSS(CameraTexb, 0x4);
INCLUDE_BSS(WorkTex, 0x4);
INCLUDE_BSS(ShutterAnmCnt, 0x4);
INCLUDE_BSS(ShowTakePhotoCnt, 0x4);
INCLUDE_BSS(OpenMenu, 0x4);
INCLUDE_BSS(ShowTitleCnt, 0x4);
INCLUDE_BSS(ShowLevelUpCnt, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(Font__3, 0xC0);
INCLUDE_BSS(PhotoTitle, 0x80);
