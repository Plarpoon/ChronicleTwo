#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetFixHeight__15CameraCtrlParamFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetFixDist__15CameraCtrlParamFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", __ct__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", GetActiveParam__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetRotCameraCancel__14CCameraControlFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", BitSetRotCameraCancel__14CCameraControlFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", BitResetRotCameraCancel__14CCameraControlFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", InitStatus__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", ControlOn__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", ControlOff__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", Stay__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", Step__14CCameraControlFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", MoveCamera__14CCameraControlFP11CPadControlPfP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", MoveCamera__14CCameraControlFPQ214CCameraControl7ControlPfP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", Rotate__14CCameraControlFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetRotate__14CCameraControlFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetHeight__14CCameraControlFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", RotBack__14CCameraControlFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", CancelRotBack__14CCameraControlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetCheckRef__14CCameraControlFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", SetCheckRef__14CCameraControlFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", CheckCollision__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", AutoMove__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", CheckGround__14CCameraControlFP6CCPolyi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", GetCameraMatrix__14CCameraControlFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", CopyParam__14CCameraControlFR14CCameraControl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/cameracontrol", Iam__14CCameraControlFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/cameracontrol", at_396__3__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/cameracontrol", __vt__14CCameraControl__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_373__3, 0x10);
