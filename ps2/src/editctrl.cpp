#include "common.h"
#include "editctrl.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", GetUserData__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditOnGround__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", IsWalkMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditControlInit__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditControlStatusInit__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", GetFootEffName__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditMoveChara__FP6CScenePfP17EditMoveCharaInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditCameraControl__FP6CSceneP11CPadControlPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", CharaControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", CancelEyeViewMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", CameraControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", InitEyeCamera__FP11CCharacter2P14CCameraControl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", ResetViewMode__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EyeCamera__FP9mgCCameraP11CCharacter2i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", InitLadder__FiP6CSceneP15CSceneEventData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EndLadder__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", LadderControl__FP6CSceneP11CPadControl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditStepChara__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditDrawShadowChara__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditDrawChara__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", EditDrawEffectChara__FP6CScene);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editctrl", __sinit_editctrl_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", name_978__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", name_id_982__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1080__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1320__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_962__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_979__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_980__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_981__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1239__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1240__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1241__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1355__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1356__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1357__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1465__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1466__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1467__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1468__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1759__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1760__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1761__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1762__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1763__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1764__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1765__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1766__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1767__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", D_0037B008__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(LadderMode, 0x4);
INCLUDE_BSS(LadderStep, 0x4);
INCLUDE_BSS(CharaMotionMode, 0x4);
INCLUDE_BSS(CharaMotionModeCnt, 0x4);
INCLUDE_BSS(CharaFallFlag, 0x4);
INCLUDE_BSS(CharaAngleTargetFlag, 0x4);
INCLUDE_BSS(CharaAngleTarget, 0x4);
INCLUDE_BSS(FixCameraFlag, 0x4);
INCLUDE_BSS(FixCameraChgCnt, 0x4);
INCLUDE_BSS(EyeViewCancelOnce, 0x4);
INCLUDE_BSS(ViewMode, 0x4);
INCLUDE_BSS(viewAngleH, 0x4);
INCLUDE_BSS(viewAngleV, 0x4);
INCLUDE_BSS(AddProj, 0x4);
INCLUDE_BSS(ShutterCnt, 0x4);
INCLUDE_BSS(InitEyeViewFlag, 0x4);
INCLUDE_BSS(move_chara, 0x4);
INCLUDE_BSS(HamonCnt_1075, 0x4);
INCLUDE_BSS(init_1076, 0x4);
INCLUDE_BSS(reference_1252, 0x4);
INCLUDE_BSS(init_1253, 0x4);
INCLUDE_BSS(camera_dist_mode_1317, 0x4);
INCLUDE_BSS(init_1318, 0x4);
INCLUDE_BSS(LadderCamera, 0x4);
INCLUDE_BSS(LdrNext, 0x4);
INCLUDE_BSS(LdrRot, 0x4);
INCLUDE_BSS(OldMtnRate, 0x4);
INCLUDE_BSS(LdrSound, 0x4);
INCLUDE_BSS(LdrBtmFoot, 0x4);
INCLUDE_BSS(LdrTopFoot, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(MoveInfo, 0x110);
INCLUDE_BSS(OldFixCameraPos, 0x10);
INCLUDE_BSS(OldCameraPos, 0x10);
INCLUDE_BSS(LadderData, 0xD0);
INCLUDE_BSS(LdrPos, 0x10);
INCLUDE_BSS(StdPos, 0x10);
INCLUDE_BSS(LdrBottomPos, 0x10);
INCLUDE_BSS(LdrTopPos, 0x10);
INCLUDE_BSS(LdrTopWalk, 0x10);
INCLUDE_BSS(LdrCamPos, 0x10);
