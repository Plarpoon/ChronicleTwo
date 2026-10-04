#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", name_978);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", name_id_982);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1080);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1320);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_962);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_979__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_980);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_981);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1239);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1240);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1241);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1355);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1356);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1357__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1465__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1466__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1467__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1468__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1759);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1760);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1761);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1762);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1763);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1764);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1765);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1766);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", at_1767);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editctrl", D_0037B008);

// Small uninitialised data (.sbss)
unsigned char LadderMode[0x4];
unsigned char LadderStep[0x4];
unsigned char CharaMotionMode[0x4];
unsigned char CharaMotionModeCnt[0x4];
unsigned char CharaFallFlag[0x4];
unsigned char CharaAngleTargetFlag[0x4];
unsigned char CharaAngleTarget[0x4];
unsigned char FixCameraFlag[0x4];
unsigned char FixCameraChgCnt[0x4];
unsigned char EyeViewCancelOnce[0x4];
unsigned char ViewMode[0x4];
unsigned char viewAngleH[0x4];
unsigned char viewAngleV[0x4];
unsigned char AddProj[0x4];
unsigned char ShutterCnt[0x4];
unsigned char InitEyeViewFlag[0x4];
unsigned char move_chara[0x4];
unsigned char HamonCnt_1075[0x4];
unsigned char init_1076[0x4];
unsigned char reference_1252[0x4];
unsigned char init_1253[0x4];
unsigned char camera_dist_mode_1317[0x4];
unsigned char init_1318[0x4];
unsigned char LadderCamera[0x4];
unsigned char LdrNext[0x4];
unsigned char LdrRot[0x4];
unsigned char OldMtnRate[0x4];
unsigned char LdrSound[0x4];
unsigned char LdrBtmFoot[0x4];
unsigned char LdrTopFoot[0x4];

// Uninitialised data (.bss)
unsigned char MoveInfo[0x110];
unsigned char OldFixCameraPos[0x10];
unsigned char OldCameraPos[0x10];
unsigned char LadderData[0xD0];
unsigned char LdrPos[0x10];
unsigned char StdPos[0x10];
unsigned char LdrBottomPos[0x10];
unsigned char LdrTopPos[0x10];
unsigned char LdrTopWalk[0x10];
unsigned char LdrCamPos[0x10];
