#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Step__9mgCCameraFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Stay__9mgCCameraFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetPos__9mgCCameraFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetPos__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetNextPos__9mgCCameraFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetNextPos__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetRef__9mgCCameraFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetRef__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetNextRef__9mgCCameraFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetNextRef__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetDir__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetCameraMatrix__9mgCCameraFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetSpeed__9mgCCameraFff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetRoll__9mgCCameraFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetPos__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetRef__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetNextPos__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetNextRef__9mgCCameraFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetAngleH__9mgCCameraFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetAngleV__9mgCCameraFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", __ct__9mgCCameraFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetFollowNextPos__15mgCCameraFollowFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetFollowNext__15mgCCameraFollowFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Step__15mgCCameraFollowFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Stay__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetFollow__15mgCCameraFollowFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", FollowOn__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", FollowOff__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetAngle__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetAngleSoon__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetAngle__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", AddAngle__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetDistance__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetDistance__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", AddDistance__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetHeight__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetHeight__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", AddHeight__15mgCCameraFollowFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", SetFollowOffset__15mgCCameraFollowFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetFollow__15mgCCameraFollowFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", GetFollowOffset__15mgCCameraFollowFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", __ct__15mgCCameraFollowFffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Iam__15mgCCameraFollowFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Suspend__9mgCCameraFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Resume__9mgCCameraFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_camera", Iam__9mgCCameraFv);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_camera", __vt__15mgCCameraFollow);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_camera", __vt__9mgCCamera);

// Small uninitialised data (.sbss)
unsigned char StopCamera__9mgCCamera[0x4];
