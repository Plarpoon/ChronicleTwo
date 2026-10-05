#include "common.h"
#include "fishingobj.hpp"
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <libvu0.h>
#include "mg_math.hpp"
#include "gameutil.hpp"
#include "mg_frame.hpp"
#include "mg_drawprim.hpp"
#include "mglib.hpp"
#include "scenesnd.hpp"
#include "dng_main.hpp"

#ifdef NONMATCHING
static float WaterLevel;
static int LineTop;
static float LineTopDist;
static int CastingLureFlag;
static int CastingLureTime;
static int AddLineSpeed;
static int BattleFlag;
static float BattleLineDist;
static int ShowHari;
static int LureLessFlag;
static int NowMode;
static int NowFishSpeed;
static float NowFishRot;
static int ActionChanceNextCnt;
static int ActionChanceCnt;
static int ActionChanceDir;
static FISH_POINT RodPoint[5];
static FISH_ROD_SEGMENT RodPointDist[5];
static mgCFrame *SaoFrame[8];
static float SaoDist[8];
static FISH_POINT LinePoint[64];
static FISH_POINT LurePoint[3];
static FISH_POINT FlyingPoint;
static FISH_POINT FishPoint;
static sceVu0FVECTOR CastingPoint;
static sceVu0FVECTOR ReleasePoint;
static sceVu0FVECTOR BattleStartPos;
static CFishObj LureObj;
static CFishObj UkiObj;
static CFishObj HariObj;
static sceVu0FVECTOR ChanceBarPos;

static CFishObj *GetActiveHariObj();
static CFishObj *GetActiveUkiObj();
static int GetNextChanceCnt();
static void BindPosition(float *point0, float *point1, float length, float rate);
static void ParaBlend(float *out, float time, sceVu0FVECTOR *samples, int count);

static void SetObjectPoint(FISH_POINT &point, float x, float y, float z) {
    point.pos[0] = x;
    point.pos[1] = y;
    point.pos[2] = z;
    point.pos[3] = 1.0f;
}

static void SetObjectBind(FISH_BIND &bind, FISH_POINT &first, FISH_POINT &second) {
    bind.point0 = &first;
    bind.point1 = &second;
    bind.rate = 0.5f;
    bind.length = mgDistVector(first.pos, second.pos);
}
#endif

// Code (.text)
#ifdef NONMATCHING
void SetFishingMode(int mode) { NowMode = mode; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetFishingMode__Fi);
#endif
#ifdef NONMATCHING
int GetFishingMode() { return NowMode; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetFishingMode__Fv);
#endif
#ifdef NONMATCHING
void SetWaterLevel(float level) { WaterLevel = level; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetWaterLevel__Ff);
#endif
#ifdef NONMATCHING
float GetWaterLevel() { return WaterLevel; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetWaterLevel__Fv);
#endif
#ifdef NONMATCHING
static CFishObj *GetActiveHariObj() {
    return NowMode == FISHING_MODE_LURE ? &LureObj : &HariObj;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetActiveHariObj__Fv);
#endif
#ifdef NONMATCHING
static CFishObj *GetActiveUkiObj() {
    return NowMode == FISHING_MODE_LURE ? 0 : &UkiObj;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetActiveUkiObj__Fv);
#endif
#ifdef NONMATCHING
int ExtendLine(float length) {
    if (BattleFlag != 0) {
        BattleLineDist += length;
        if (BattleLineDist < 20.0f) {
            BattleFlag = 0;
            LineTop = 59;
            LineTopDist = 5.0f;
            return -1;
        }
        return 0;
    }
    if (length > 0.0f) {
        LineTopDist += length;
        while (LineTopDist > 5.0f) {
            LineTopDist -= 5.0f;
            --LineTop;
            if (LineTop >= 0) {
                sceVu0CopyVector(LinePoint[LineTop].pos, RodPoint[4].pos);
                sceVu0CopyVector(LinePoint[LineTop].old_pos, RodPoint[4].pos);
                mgZeroVector(LinePoint[LineTop].velo);
            }
        }
        if (LineTop < 0) {
            LineTop = 0;
            LineTopDist = 5.0f;
            return 1;
        }
    }
    if (length < 0.0f) {
        LineTopDist += length;
        while (LineTopDist < 0.0f) {
            ++LineTop;
            LineTopDist += 5.0f;
        }
        if (LineTop >= 59) {
            LineTop = 59;
            LineTopDist = 5.0f;
            return -1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ExtendLine__Ff);
#endif
#ifdef NONMATCHING
float GetNowLineLength() {
    if (BattleFlag != 0) {
        return BattleLineDist;
    }
    return 5.0f * (float)(63 - LineTop) + LineTopDist;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetNowLineLength__Fv);
#endif
float GetMinLineLength(void) {
    return 25.0f;
}
#ifdef NONMATCHING
void InitRodPoint(mgCFrame *reference, mgCFrame *rod) {
    for (int i = 0; i < 5; i++) {
        mgZeroVector(RodPoint[i].pos);
        mgZeroVector(RodPoint[i].old_pos);
        mgZeroVector(RodPoint[i].velo);
    }
    for (int i = 0; i < 64; i++) {
        mgZeroVector(LinePoint[i].pos);
        mgZeroVector(LinePoint[i].old_pos);
        mgZeroVector(LinePoint[i].velo);
    }
    for (int i = 0; i < 3; i++) {
        mgZeroVector(LurePoint[i].pos);
        mgZeroVector(LurePoint[i].old_pos);
        mgZeroVector(LurePoint[i].velo);
    }
    const char *joint_names[8] = {"sao1", "sao2", "sao3", "sao4", "sao5", "sao6", "sao7", "sao8"};
    for (int i = 0; i < 8; i++) {
        SaoFrame[i] = rod->SearchFrame((char *)joint_names[i]);
    }
    sceVu0FVECTOR root;
    sceVu0FVECTOR tip;
    sceVu0FVECTOR joint;
    sceVu0FVECTOR span;
    sceVu0FVECTOR offset;
    sceVu0FVECTOR position;
    SaoFrame[0]->GetWorldPosition0(root);
    SaoFrame[7]->GetWorldPosition0(tip);
    for (int i = 0; i < 8; i++) {
        SaoFrame[i]->GetWorldPosition0(joint);
        SaoDist[i] = mgDistVector(root, joint);
    }
    sceVu0SubVector(span, tip, root);
    for (int i = 0; i < 5; i++) {
        sceVu0ScaleVector(offset, span, (float)i / 4.0f);
        sceVu0AddVector(position, root, offset);
        sceVu0CopyVector(RodPoint[i].pos, position);
        sceVu0CopyVector(RodPoint[i].old_pos, position);
        mgZeroVector(RodPoint[i].velo);
        if (i > 0) {
            RodPointDist[i].length = mgDistVector(RodPoint[i].pos, RodPoint[i - 1].pos);
        }
        RodPointDist[i].stiffness = ((float)(5 - i) * 0.3f) / 5.0f + 0.3f;
        if (RodPointDist[i].stiffness > 1.0f) {
            RodPointDist[i].stiffness = 1.0f;
        }
        RodPointDist[i].damping = ((float)(5 - i) * 0.2f) / 5.0f + 0.2f;
    }
    ResetLine(tip);
    LineTop = 59;
    LineTopDist = 5.0f;
    EndCastingLure();
    BattleFlag = 0;
    NowMode = FISHING_MODE_BAIT;
    ShowHari = 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitRodPoint__FP8mgCFrameP8mgCFrame);
#endif
#ifdef NONMATCHING
static void GetTriPose(sceVu0FMATRIX pose, sceVu0FVECTOR points[3], int axes[3]) {
    int first_axis = axes[0] < 0 ? -axes[0] : axes[0];
    int second_axis = axes[1] < 0 ? -axes[1] : axes[1];
    int normal_axis = axes[2] < 0 ? -axes[2] : axes[2];
    sceVu0SubVector(pose[first_axis], points[1], points[0]);
    sceVu0Normalize(pose[first_axis], pose[first_axis]);
    mgPlaneNormal(pose[normal_axis], points[0], points[1], points[2]);
    sceVu0Normalize(pose[normal_axis], pose[normal_axis]);
    sceVu0OuterProduct(pose[second_axis], pose[normal_axis], pose[first_axis]);
    for (int axis = 0; axis < 3; axis++) {
        sceVu0Normalize(pose[axis], pose[axis]);
        if (axes[axis] < 0) {
            sceVu0ScaleVector(pose[-axes[axis]], pose[-axes[axis]], -1.0f);
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetTriPose__FPA4_fPA4_fPi);
#endif
#ifdef NONMATCHING
void GetHariPos(float *pos, float *velo) {
    sceVu0CopyVector(pos, LinePoint[63].pos);
    sceVu0CopyVector(velo, LinePoint[63].velo);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetHariPos__FPfPf);
#endif
#ifdef NONMATCHING
void GetUkiPos(float *pos, float *velo) {
    sceVu0CopyVector(pos, LinePoint[60].pos);
    sceVu0CopyVector(velo, LinePoint[60].velo);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetUkiPos__FPfPf);
#endif
#ifdef NONMATCHING
void PullUki(float power) { LinePoint[63].velo[1] -= power; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", PullUki__Ff);
#endif
#ifdef NONMATCHING
void SetShowHari(int show) { ShowHari = show; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetShowHari__Fi);
#endif
#ifdef NONMATCHING
int GetShowHari() {
    sceVu0FVECTOR pos;
    sceVu0FVECTOR velo;
    GetHariPos(pos, velo);
    if (pos[1] < GetWaterLevel() - 3.0f) {
        return 0;
    }
    return ShowHari;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetShowHari__Fv);
#endif
#ifdef NONMATCHING
int SetLurePose(mgCFrame *lure) {
    if (lure == 0 || NowMode == FISHING_MODE_BAIT) {
        return 0;
    }
    sceVu0FMATRIX matrix;
    sceVu0FVECTOR points[3];
    int axes[3] = {0, 1, 2};
    mgUnitMatrix(matrix);
    for (int i = 0; i < 3; i++) {
        sceVu0CopyVector(points[i], LureObj.point[i].pos);
    }
    GetTriPose(matrix, points, axes);
    lure->SetPosition(LinePoint[63].pos);
    lure->SetTransMatrix(matrix);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetLurePose__FP8mgCFrame);
#endif
#ifdef NONMATCHING
int SetUkiPose(mgCFrame *uki, mgCFrame *hari) {
    if (uki == 0 || hari == 0 || NowMode == FISHING_MODE_LURE) {
        return 0;
    }
    sceVu0FMATRIX matrix;
    sceVu0FVECTOR points[3];
    int uki_axes[3] = {-1, 2, 0};
    int hari_axes[3] = {-1, 0, 2};
    mgUnitMatrix(matrix);
    sceVu0CopyVector(points[0], UkiObj.point[0].pos);
    sceVu0CopyVector(points[1], UkiObj.point[1].pos);
    sceVu0AddVector(points[2], UkiObj.point[1].pos, UkiObj.point[2].pos);
    mgAddVector(points[2], UkiObj.point[3].pos);
    sceVu0ScaleVector(points[2], points[2], 1.0f / 3.0f);
    GetTriPose(matrix, points, uki_axes);
    uki->SetTransMatrix(matrix);
    uki->SetPosition(LinePoint[60].pos);

    sceVu0CopyVector(points[0], HariObj.point[0].pos);
    sceVu0AddVector(points[1], HariObj.point[1].pos, HariObj.point[2].pos);
    sceVu0ScaleVector(points[1], points[1], 0.5f);
    sceVu0CopyVector(points[2], HariObj.point[2].pos);
    GetTriPose(matrix, points, hari_axes);
    hari->SetTransMatrix(matrix);
    hari->SetPosition(LinePoint[63].pos);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SetUkiPose__FP8mgCFrameP8mgCFrame);
#endif
#ifdef NONMATCHING
int CastingLure(float *target) {
    sceVu0FVECTOR direction;
    sceVu0CopyVector(CastingPoint, target);
    sceVu0CopyVector(ReleasePoint, LinePoint[63].pos);
    sceVu0CopyVector(FlyingPoint.pos, LinePoint[63].pos);
    sceVu0CopyVector(FlyingPoint.old_pos, LinePoint[63].pos);
    mgZeroVector(FlyingPoint.velo);
    sceVu0SubVector(direction, target, LinePoint[63].pos);
    float horizontal_distance = mgDistVectorXZ(direction);
    float rise_speed = sqrtf((horizontal_distance * 2.0f * 0.6f) / 1.6f);
    float horizontal_speed = rise_speed * 1.0f;
    CastingLureTime = (int)((horizontal_distance * 2.0f) / horizontal_speed);
    direction[1] = 0.0f;
    sceVu0Normalize(direction, direction);
    sceVu0ScaleVector(FlyingPoint.velo, direction, horizontal_speed);
    AddLineSpeed = 0;
    CastingLureFlag = 1;
    FlyingPoint.velo[1] = rise_speed * 0.8f;
    return CastingLureTime;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", CastingLure__FPf);
#endif
#ifdef NONMATCHING
void EndCastingLure() {
    CastingLureFlag = 0;
    CastingLureTime = 0;
    AddLineSpeed = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", EndCastingLure__Fv);
#endif
#ifdef NONMATCHING
int CatchLine(float *target, float max_dist) {
    sceVu0FVECTOR delta;
    sceVu0FVECTOR next_pos;
    CFishObj *hari = GetActiveHariObj();
    sceVu0SubVector(delta, target, LinePoint[63].pos);
    float distance = mgDistVector(delta);
    int reached = distance < max_dist;
    if (reached) {
        sceVu0CopyVector(next_pos, target);
    } else {
        sceVu0Normalize(delta, delta);
        sceVu0ScaleVector(delta, delta, max_dist);
        sceVu0AddVector(next_pos, LinePoint[63].pos, delta);
    }
    sceVu0CopyVector(LinePoint[63].pos, next_pos);
    sceVu0CopyVector(LinePoint[63].old_pos, next_pos);
    mgZeroVector(LinePoint[63].velo);
    if (hari != 0) {
        sceVu0CopyVector(hari->point[0].pos, next_pos);
        sceVu0CopyVector(hari->point[0].old_pos, next_pos);
        mgZeroVector(hari->point[0].velo);
    }
    return reached;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", CatchLine__FPff);
#endif
#ifdef NONMATCHING
void SlowLineVelo(float rate) {
    for (int i = LineTop; i < 64; i++) {
        sceVu0ScaleVector(LinePoint[i].velo, LinePoint[i].velo, rate);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", SlowLineVelo__Ff);
#endif
#ifdef NONMATCHING
void ResetLineVelo() {
    sceVu0FVECTOR top_pos;
    sceVu0CopyVector(top_pos, LinePoint[LineTop].pos);
    for (int i = LineTop; i < 64; i++) {
        sceVu0CopyVector(LinePoint[i].pos, top_pos);
        sceVu0CopyVector(LinePoint[i].old_pos, top_pos);
        mgZeroVector(LinePoint[i].velo);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ResetLineVelo__Fv);
#endif
#ifdef NONMATCHING
void ResetLine(float *pos) {
    LineTop = 59;
    sceVu0CopyVector(LinePoint[59].pos, pos);
    sceVu0CopyVector(LinePoint[59].old_pos, pos);
    mgZeroVector(LinePoint[59].velo);
    for (int i = LineTop + 1; i < 64; i++) {
        sceVu0CopyVector(LinePoint[i].pos, LinePoint[i - 1].pos);
        LinePoint[i].pos[1] -= 5.0f;
        sceVu0CopyVector(LinePoint[i].old_pos, LinePoint[i].pos);
        mgZeroVector(LinePoint[i].velo);
    }
    sceVu0CopyVector(LureObj.point[0].pos, LinePoint[63].pos);
    sceVu0CopyVector(LureObj.point[0].old_pos, LureObj.point[0].pos);
    mgZeroVector(LureObj.point[0].velo);
    sceVu0CopyVector(UkiObj.point[0].pos, LinePoint[60].pos);
    sceVu0CopyVector(UkiObj.point[0].old_pos, UkiObj.point[0].pos);
    mgZeroVector(UkiObj.point[0].velo);
    sceVu0CopyVector(HariObj.point[0].pos, LinePoint[63].pos);
    sceVu0CopyVector(HariObj.point[0].old_pos, HariObj.point[0].pos);
    mgZeroVector(HariObj.point[0].velo);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ResetLine__FPf);
#endif
s32 GetNextChanceCnt(void) {
    return (rand() % 80) + 0x3C;
}
#ifdef NONMATCHING
int InitFishBattle() {
    sceVu0CopyVector(BattleStartPos, LinePoint[63].pos);
    sceVu0CopyVector(FishPoint.pos, LinePoint[63].pos);
    sceVu0CopyVector(FishPoint.old_pos, LinePoint[63].pos);
    mgZeroVector(FishPoint.velo);
    BattleLineDist = mgDistVector(LinePoint[63].pos, RodPoint[4].pos);
    NowFishSpeed = 0;
    BattleFlag = 1;
    NowFishRot = 0;
    ActionChanceNextCnt = GetNextChanceCnt();
    ActionChanceCnt = 0;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitFishBattle__Fv);
#endif
#ifdef NONMATCHING
int EndFishBattle() {
    BattleFlag = 0;
    ActionChanceNextCnt = 0;
    ActionChanceCnt = 0;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", EndFishBattle__Fv);
#endif
#ifdef NONMATCHING
int CheckRodActionChance(int dir, int *just) {
    *just = 0;
    if (BattleFlag == 0 || ActionChanceCnt <= 0) {
        return 0;
    }
    int match = dir * ActionChanceDir;
    if (match > 0) {
        return 1;
    }
    if (match < 0) {
        return -1;
    }
    *just = ActionChanceCnt == 28;
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", CheckRodActionChance__FiPi);
#endif
#ifdef NONMATCHING
int FishBattle(CScene *scene, CCPoly *poly_buffer, int poly_max) {
    if (BattleFlag == 0) {
        return 0;
    }
    CCharacter2 *player = scene->GetCharacter(scene->player_chara);
    sceVu0FVECTOR player_pos;
    sceVu0FVECTOR player_rot;
    sceVu0FVECTOR heading;
    sceVu0FVECTOR next_pos;
    player->GetPosition(player_pos);
    player->GetRotation(player_rot);
    float target_angle = player_rot[1] + (mgRnd() - 0.5f) * 2.5132742f;
    if (ActionChanceCnt <= 0) {
        --ActionChanceNextCnt;
        ActionChanceCnt = 0;
        if (ActionChanceNextCnt <= 0) {
            ActionChanceCnt = 30;
            ActionChanceDir = rand() % 2 == 0 ? -1 : 1;
        }
    }
    if (ActionChanceCnt > 0) {
        target_angle = ActionChanceDir > 0 ? player_rot[1] - mgRnd() * 1.2566371f :
                                              player_rot[1] + mgRnd() * 1.2566371f;
        sceVu0FVECTOR float_velo;
        GetUkiPos(ChanceBarPos, float_velo);
        ChanceBarPos[1] = WaterLevel;
        --ActionChanceCnt;
        if (ActionChanceCnt <= 0) {
            ActionChanceCnt = 0;
            ActionChanceNextCnt = GetNextChanceCnt();
        }
    }
    NowFishRot = mgAngleInterpolate(NowFishRot, mgAngleLimit(target_angle), 0.1f, 0);
    NowFishSpeed = 8;
    FishPoint.velo[0] = (float)NowFishSpeed * sinf(NowFishRot);
    FishPoint.velo[1] = 0.0f;
    FishPoint.velo[2] = (float)NowFishSpeed * cosf(NowFishRot);
    FishPoint.pos[1] = WaterLevel - 10.0f;
    sceVu0CopyVector(next_pos, FishPoint.pos);
    next_pos[0] += FishPoint.velo[0];
    next_pos[2] += FishPoint.velo[2];
    mgVu0FBOX query_box;
    sceVu0CopyVector(query_box.max, FishPoint.pos);
    sceVu0CopyVector(query_box.min, FishPoint.pos);
    for (int axis = 0; axis < 3; axis++) {
        query_box.max[axis] += 100.0f;
        query_box.min[axis] -= 100.0f;
    }
    int poly_count = scene->GetColPoly(poly_buffer, query_box, poly_max);
    MoveCheckInfo check;
    memset(&check, 0, sizeof(check));
    check.radius = 10.0f;
    MoveCheck(FishPoint.pos, FishPoint.velo, next_pos, &check, poly_buffer, poly_count, 0);
    sceVu0SubVector(heading, next_pos, player_pos);
    sceVu0Normalize(heading, heading);
    sceVu0InnerProduct(heading, player_rot);
    FishPoint.pos[0] = next_pos[0];
    FishPoint.pos[2] = next_pos[2];
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", FishBattle__FP6CSceneP6CCPolyi);
#endif
#ifdef NONMATCHING
void GetFishPosVelo(float *pos, float *velo) {
    sceVu0CopyVector(pos, FishPoint.pos);
    sceVu0CopyVector(velo, FishPoint.velo);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", GetFishPosVelo__FPfPf);
#endif
#ifdef NONMATCHING
static void BindFishObj() {
    CFishObj *hari = GetActiveHariObj();
    CFishObj *uki = GetActiveUkiObj();
    sceVu0CopyVector(LinePoint[LineTop].pos, RodPoint[4].pos);
    sceVu0CopyVector(LinePoint[LineTop].old_pos, RodPoint[4].pos);
    mgZeroVector(LinePoint[LineTop].velo);
    for (int step = 0; step < 4; step++) {
        for (int i = LineTop; i < 63; i++) {
            float rate = i > 58 ? 0.52f : 0.5f;
            float length = i == LineTop ? LineTopDist : 5.0f;
            BindPosition(LinePoint[i].pos, LinePoint[i + 1].pos, length, rate);
        }
        if (CastingLureFlag != 0) {
            sceVu0CopyVector(LinePoint[63].pos, FlyingPoint.pos);
        }
        if (LureLessFlag == 0) {
            BindPosition(LinePoint[63].pos, hari->point[0].pos, 0.0f, 0.45f);
        }
        hari->BindStep();
        if (uki != 0) {
            BindPosition(LinePoint[60].pos, uki->point[0].pos, 0.0f, 0.4f);
            uki->BindStep();
        }
        sceVu0CopyVector(LinePoint[LineTop].pos, RodPoint[4].pos);
        sceVu0CopyVector(LinePoint[LineTop].old_pos, RodPoint[4].pos);
        mgZeroVector(LinePoint[LineTop].velo);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", BindFishObj__Fv);
#endif
#ifdef NONMATCHING
void RodStep(CScene *scene, u_long128 *poly_buffer) {
    CCPoly *polys = (CCPoly *)poly_buffer;
    CFishObj *hari = GetActiveHariObj();
    CFishObj *uki = GetActiveUkiObj();
    sceVu0FVECTOR frame_pos;
    SaoFrame[0]->GetWorldPosition0(frame_pos);
    sceVu0CopyVector(RodPoint[0].pos, frame_pos);
    sceVu0CopyVector(RodPoint[0].old_pos, frame_pos);
    mgZeroVector(RodPoint[0].velo);
    SaoFrame[1]->GetWorldPosition0(frame_pos);
    sceVu0CopyVector(RodPoint[1].pos, frame_pos);
    sceVu0CopyVector(RodPoint[1].old_pos, frame_pos);
    mgZeroVector(RodPoint[1].velo);

    if (CastingLureFlag != 0) {
        FlyingPoint.velo[1] -= 0.6f;
        float cast_distance = mgDistVectorXZ(ReleasePoint, CastingPoint);
        float flown_distance = mgDistVectorXZ(ReleasePoint, FlyingPoint.pos);
        sceVu0FVECTOR flight_step;
        sceVu0CopyVector(flight_step, FlyingPoint.velo);
        if (flown_distance > cast_distance * 0.8f) {
            float scale = (cast_distance - flown_distance) / (cast_distance * 0.2f);
            flight_step[0] *= scale;
            flight_step[2] *= scale;
            ExtendLine(mgDistVectorXZ(flight_step));
        } else {
            float top_gap = mgDistVector(LinePoint[LineTop].pos, LinePoint[LineTop + 1].pos);
            if (top_gap > LineTopDist) {
                ExtendLine(0.8f * mgDistVectorXZ(flight_step));
            }
            for (int i = LineTop + 1; i < 63; i++) {
                sceVu0FVECTOR pull;
                sceVu0SubVector(pull, FlyingPoint.pos, LinePoint[i].pos);
                sceVu0Normalize(pull, pull);
                sceVu0ScaleVector(pull, pull, 2.0f);
                mgAddVector(LinePoint[i].velo, pull);
            }
        }
        float remaining = mgDistVectorXZ(CastingPoint, FlyingPoint.pos);
        if (remaining < mgDistVectorXZ(flight_step)) {
            flight_step[0] = 0.0f;
            flight_step[2] = 0.0f;
            FlyingPoint.velo[0] = 0.0f;
            FlyingPoint.velo[2] = 0.0f;
            FlyingPoint.pos[0] = CastingPoint[0];
            FlyingPoint.pos[2] = CastingPoint[2];
        }
        mgAddVector(FlyingPoint.pos, flight_step);
        sceVu0CopyVector(LinePoint[63].pos, FlyingPoint.pos);
        sceVu0CopyVector(LinePoint[63].old_pos, FlyingPoint.pos);
        mgZeroVector(LinePoint[63].velo);
        --CastingLureTime;
    }

    for (int i = 2; i < 5; i++) {
        sceVu0CopyVector(RodPoint[i].old_pos, RodPoint[i].pos);
        if (BattleFlag == 0) {
            mgAddVector(RodPoint[i].pos, RodPoint[i].velo);
        }
    }
    mgVu0FBOX line_box;
    sceVu0CopyVector(line_box.max, LinePoint[LineTop].pos);
    sceVu0CopyVector(line_box.min, LinePoint[LineTop].pos);
    for (int i = LineTop; i < 64; i++) {
        FISH_POINT &point = LinePoint[i];
        sceVu0CopyVector(point.old_pos, point.pos);
        mgAddVector(point.pos, point.velo);
        point.pos[1] -= 0.36f;
        mgVectorMaxMin(line_box.max, line_box.min, line_box.max, line_box.min, point.pos);
    }
    hari->MovePoint();
    if (uki != 0) {
        uki->MovePoint();
    }

    // Keep the rod's four moving masses spaced between its fixed joints and tip.
    for (int pass = 0; pass < 2; pass++) {
        if (BattleFlag != 0) {
            BindPosition(RodPoint[4].pos, FishPoint.pos, BattleLineDist, 0.2f);
        } else {
            BindPosition(RodPoint[4].pos, LinePoint[LineTop].pos, 0.0f, 0.8f);
        }
        for (int i = 3; i >= 2; i--) {
            sceVu0FVECTOR across;
            sceVu0FVECTOR half_across;
            sceVu0FVECTOR segment;
            sceVu0FVECTOR bend;
            sceVu0SubVector(across, RodPoint[i + 1].pos, RodPoint[i - 1].pos);
            sceVu0ScaleVector(half_across, across, 0.5f);
            sceVu0SubVector(segment, RodPoint[i].pos, RodPoint[i - 1].pos);
            sceVu0SubVector(bend, half_across, segment);
            sceVu0ScaleVector(bend, bend, RodPointDist[i].damping);
            mgAddVector(segment, bend);
            sceVu0Normalize(segment, segment);
            sceVu0ScaleVector(segment, segment, RodPointDist[i].length);
            sceVu0AddVector(RodPoint[i].pos, RodPoint[i - 1].pos, segment);
        }
        for (int i = 1; i < 4; i++) {
            sceVu0FVECTOR direction;
            sceVu0FVECTOR desired;
            sceVu0FVECTOR actual;
            sceVu0FVECTOR error;
            sceVu0SubVector(direction, RodPoint[i].pos, RodPoint[i - 1].pos);
            sceVu0Normalize(direction, direction);
            sceVu0ScaleVector(desired, direction, RodPointDist[i].length);
            sceVu0SubVector(actual, RodPoint[i + 1].pos, RodPoint[i].pos);
            sceVu0SubVector(error, desired, actual);
            sceVu0ScaleVector(error, error, RodPointDist[i].stiffness);
            mgAddVector(actual, error);
            sceVu0Normalize(actual, actual);
            sceVu0ScaleVector(actual, actual, RodPointDist[i].length);
            sceVu0AddVector(RodPoint[i + 1].pos, RodPoint[i].pos, actual);
        }
    }
    if (BattleFlag != 0) {
        for (int pass = 0; pass < 4; pass++) {
            sceVu0CopyVector(hari->point[0].pos, FishPoint.pos);
            sceVu0CopyVector(hari->point[0].old_pos, FishPoint.pos);
            mgZeroVector(hari->point[0].velo);
            sceVu0CopyVector(LinePoint[63].pos, FishPoint.pos);
            sceVu0CopyVector(LinePoint[63].old_pos, FishPoint.pos);
            mgZeroVector(LinePoint[63].velo);
            hari->BindStep();
            if (uki != 0) {
                sceVu0FVECTOR float_pos;
                sceVu0SubVector(float_pos, FishPoint.pos, RodPoint[4].pos);
                sceVu0Normalize(float_pos, float_pos);
                sceVu0ScaleVector(float_pos, float_pos, 15.0f);
                sceVu0SubVector(float_pos, FishPoint.pos, float_pos);
                sceVu0CopyVector(LinePoint[60].pos, float_pos);
                sceVu0CopyVector(LinePoint[60].old_pos, float_pos);
                mgZeroVector(LinePoint[60].velo);
                sceVu0CopyVector(uki->point[0].pos, float_pos);
                sceVu0CopyVector(uki->point[0].old_pos, float_pos);
                mgZeroVector(uki->point[0].velo);
                uki->BindStep();
            }
        }
    } else {
        sceVu0CopyVector(LinePoint[LineTop].pos, RodPoint[4].pos);
        sceVu0CopyVector(LinePoint[LineTop].old_pos, RodPoint[4].pos);
        mgZeroVector(LinePoint[LineTop].velo);
        BindFishObj();
    }
    for (int i = 1; i < 5; i++) {
        sceVu0SubVector(RodPoint[i].velo, RodPoint[i].pos, RodPoint[i].old_pos);
        sceVu0ScaleVector(RodPoint[i].velo, RodPoint[i].velo, 0.6f);
        RodPoint[i].velo[1] -= 0.6f;
        RodPoint[i].pos[3] = 1.0f;
    }

    // Move the model's seven flexible rod joints along the solved rod curve.
    sceVu0FVECTOR curve[5];
    for (int i = 0; i < 5; i++) {
        sceVu0CopyVector(curve[i], RodPoint[i].pos);
    }
    for (int i = 1; i < 8; i++) {
        mgCFrame *joint = SaoFrame[i];
        mgCFrame *parent = joint->parent;
        sceVu0FMATRIX joint_matrix;
        sceVu0FMATRIX parent_world;
        sceVu0FMATRIX parent_inverse;
        sceVu0FMATRIX parent_basis;
        sceVu0FVECTOR before;
        sceVu0FVECTOR after;
        sceVu0FVECTOR forward;
        sceVu0CopyMatrix(joint_matrix, joint->trans_matrix);
        parent->GetLWMatrix(parent_world);
        mgInversMatrix(parent_inverse, parent_world);
        sceVu0CopyMatrix(parent_basis, parent->trans_matrix);
        float fraction = SaoDist[i] / SaoDist[7];
        ParaBlend(before, 0.99f * SaoDist[i - 1] / SaoDist[7], curve, 5);
        before[3] = 1.0f;
        ParaBlend(after, 0.99f * fraction, curve, 5);
        sceVu0SubVector(forward, after, before);
        forward[3] = 0.0f;
        sceVu0ApplyMatrix(joint_matrix[0], parent_inverse, forward);
        if (i != 1) {
            sceVu0ApplyMatrix(joint_matrix[3], parent_inverse, before);
        }
        sceVu0OuterProduct(joint_matrix[2], joint_matrix[0], parent_basis[0]);
        sceVu0OuterProduct(joint_matrix[1], joint_matrix[2], joint_matrix[0]);
        sceVu0Normalize(joint_matrix[0], joint_matrix[0]);
        sceVu0Normalize(joint_matrix[1], joint_matrix[1]);
        sceVu0Normalize(joint_matrix[2], joint_matrix[2]);
        joint->SetTransMatrix(joint_matrix);
    }

    for (int axis = 0; axis < 3; axis++) {
        line_box.max[axis] += 20.0f;
        line_box.min[axis] -= 20.0f;
    }
    line_box.max[3] = 1.0f;
    line_box.min[3] = 1.0f;
    int poly_count = scene->GetColPoly(polys, line_box, 1024);
    for (int i = 0; i < poly_count; i++) {
        if (polys[i].area_kind == 7) {
            polys[i].ignore_mask |= 8;
        }
    }
    for (int i = LineTop; i < 64; i++) {
        int previous = i - 1 < LineTop ? LineTop : i - 1;
        int following = i + 1 > 63 ? 63 : i + 1;
        float heights[3] = {LinePoint[i].pos[1], LinePoint[previous].pos[1], LinePoint[following].pos[1]};
        for (int first = 0; first < 2; first++) {
            for (int second = first + 1; second < 3; second++) {
                if (heights[first] < heights[second]) {
                    float exchange = heights[first];
                    heights[first] = heights[second];
                    heights[second] = exchange;
                }
            }
        }
        sceVu0FVECTOR from;
        sceVu0FVECTOR to;
        sceVu0FVECTOR hit;
        sceVu0CopyVector(from, LinePoint[i].pos);
        sceVu0CopyVector(to, LinePoint[i].pos);
        from[1] = heights[0] + 4.0f;
        to[1] = heights[2] - 1.0f;
        float damping = 0.95f;
        if (CheckHit(polys, poly_count, from, to, hit, 1, 9) >= 0 && hit[1] + 1.0f >= LinePoint[i].pos[1]) {
            LinePoint[i].pos[1] += 0.4f * (hit[1] + 1.0f - LinePoint[i].pos[1]);
            damping = 0.95f * (i == 63 ? 0.05f : 0.1f);
        }
        sceVu0SubVector(LinePoint[i].velo, LinePoint[i].pos, LinePoint[i].old_pos);
        sceVu0ScaleVector(LinePoint[i].velo, LinePoint[i].velo, damping);
    }
    if (CastingLureTime <= 0) {
        EndCastingLure();
    }
    if (CastingLureFlag != 0) {
        sceVu0CopyVector(LinePoint[63].pos, FlyingPoint.pos);
        if (LineTop < 62) {
            sceVu0ScaleVector(LinePoint[62].pos, FlyingPoint.velo, 0.8f);
        }
        if (LineTop < 61) {
            sceVu0ScaleVector(LinePoint[61].pos, FlyingPoint.velo, 0.5f);
        }
    }
    hari->Correct(polys, poly_count, LureLessFlag == 0 ? 1.0f : 0.4f);
    if (uki != 0) {
        uki->Correct(polys, poly_count, 1.0f);
    }
    float water = GetWaterLevel();
    for (int i = LineTop; i < 64; i++) {
        if (uki != 0 && i == 60) {
            continue;
        }
        if (i == 63) {
            continue;
        }
        FISH_POINT &point = LinePoint[i];
        if (point.pos[1] < water) {
            float lift = water - point.pos[1];
            if (lift > 0.61f) {
                lift = 0.61f;
            }
            if (point.pos[1] < water - 0.05f) {
                point.velo[0] *= 0.1f;
                point.velo[1] *= 0.1f;
                point.velo[2] *= 0.1f;
            }
            point.velo[1] += lift;
        }
    }
    hari->FloatPoint(water);
    if (uki != 0) {
        uki->FloatPoint(water);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", RodStep__FP6CSceneP1);
#endif
#ifdef NONMATCHING
static void BindPosition(float *point0, float *point1, float length, float rate) {
    sceVu0FVECTOR difference;
    sceVu0FVECTOR correction0;
    sceVu0FVECTOR correction1;
    sceVu0SubVector(difference, point0, point1);
    float distance = mgDistVector(difference);
    float error = distance - length;
    sceVu0ScaleVector(correction0, difference, ((1.0f - rate) * error) / distance);
    sceVu0ScaleVector(correction1, difference, (rate * error) / distance);
    mgSubVector(point0, correction0);
    mgAddVector(point1, correction1);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", BindPosition__FPfPfff__2);
#endif
#ifdef NONMATCHING
void DrawFishingLine() {
    sceVu0FVECTOR start;
    sceVu0FVECTOR rod_back;
    sceVu0FVECTOR offset;
    sceVu0FVECTOR fish_pos;
    int first_screen[4];
    int second_screen[4];
    sceVu0CopyVector(start, RodPoint[4].pos);
    sceVu0CopyVector(rod_back, RodPoint[3].pos);
    sceVu0SubVector(offset, rod_back, start);
    sceVu0ScaleVector(offset, offset, 0.1f);
    mgAddVector(start, offset);
    sceVu0CopyVector(fish_pos, FishPoint.pos);
    start[3] = 1.0f;
    fish_pos[3] = 1.0f;

    mgCDrawPrim prim;
    prim.Initialize(0, 0);
    prim.DepthTestEnable(1);
    prim.AlphaBlendEnable(1);
    prim.ZMask(MG_Z_MASK_WRITE);
    prim.TextureMapEnable(0);
    prim.Begin(MG_PRIM_LINE);
    prim.Color(220, 220, 220, 16);
    if (BattleFlag == 0) {
        LinePoint[LineTop + 1].pos[3] = 1.0f;
        if (mgTransWorldScreen(first_screen, start) & mgTransWorldScreen(second_screen, LinePoint[LineTop + 1].pos)) {
            prim.Vertex4(first_screen);
            prim.Vertex4(second_screen);
        }
        for (int i = LineTop + 1; i < 63; i++) {
            LinePoint[i].pos[3] = 1.0f;
            LinePoint[i + 1].pos[3] = 1.0f;
            if (mgTransWorldScreen(first_screen, LinePoint[i].pos) & mgTransWorldScreen(second_screen, LinePoint[i + 1].pos)) {
                if (LinePoint[i].pos[1] < GetWaterLevel()) {
                    prim.Color(220, 220, 220, 0);
                }
                prim.Vertex4(first_screen);
                if (LinePoint[i + 1].pos[1] < GetWaterLevel()) {
                    prim.Color(220, 220, 220, 0);
                }
                prim.Vertex4(second_screen);
            }
        }
    } else if (mgTransWorldScreen(first_screen, start) & mgTransWorldScreen(second_screen, fish_pos)) {
        prim.Vertex4(first_screen);
        prim.Vertex4(second_screen);
    }
    prim.End();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", DrawFishingLine__Fv);
#endif
#ifdef NONMATCHING
void DrawFishingActionChance() {
    sceVu0FVECTOR start;
    sceVu0FVECTOR rod_back;
    sceVu0FVECTOR delta;
    sceVu0FVECTOR marker;
    sceVu0CopyVector(start, RodPoint[4].pos);
    sceVu0CopyVector(rod_back, RodPoint[3].pos);
    sceVu0SubVector(delta, rod_back, start);
    sceVu0ScaleVector(delta, delta, 0.1f);
    mgAddVector(start, delta);
    start[3] = 1.0f;

    mgCDrawPrim prim;
    prim.Initialize(0, 0);
    prim.DepthTestEnable(1);
    prim.AlphaBlendEnable(1);
    prim.ZMask(MG_Z_MASK_WRITE);
    prim.TextureMapEnable(0);
    if (BattleFlag != 0 && ActionChanceCnt > 0) {
        sceVu0SubVector(delta, start, FishPoint.pos);
        sceVu0ScaleVector(delta, delta, (WaterLevel - FishPoint.pos[1]) / delta[1]);
        sceVu0AddVector(marker, FishPoint.pos, delta);
        marker[3] = 1.0f;
        int top_left[4];
        int bottom_right[4];
        if (mgTransWorldPrim3DSprite(top_left, bottom_right, marker, 10.0f, 10.0f, 0)) {
            int sum_x = top_left[0] + bottom_right[0];
            int sum_y = top_left[1] + bottom_right[1];
            int center_x = (sum_x + (sum_x < 0)) >> 1;
            int center_y = (sum_y + (sum_y < 0)) >> 1;
            top_left[0] = center_x - 256;
            bottom_right[0] = center_x + 256;
            top_left[1] = center_y - 224;
            bottom_right[1] = center_y + 224;
            prim.DepthTestEnable(0);
            prim.TextureMapEnable(1);
            prim.Coord(1);
            prim.ZMask(MG_Z_MASK_MASKED);
            prim.Begin(MG_PRIM_SPRITE);
            prim.Color(128, 128, 128, 128);
            prim.Texture(mgTexManager.GetTexture((char *)"fish_juji", -1));
            if (ActionChanceDir > 0) {
                top_left[0] += 384;
                bottom_right[0] += 384;
                prim.TextureCrd(26, 22);
                prim.Vertex4(top_left);
                prim.TextureCrd(52, 44);
                prim.Vertex4(bottom_right);
            }
            if (ActionChanceDir < 0) {
                top_left[0] -= 384;
                bottom_right[0] -= 384;
                prim.TextureCrd(0, 22);
                prim.Vertex4(top_left);
                prim.TextureCrd(26, 44);
                prim.Vertex4(bottom_right);
            }
            prim.End();
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", DrawFishingActionChance__Fv);
#endif
#ifdef NONMATCHING
void InitLureObj(int lure_no, mgCFrame *lure) {
    memset(&LureObj, 0, sizeof(LureObj));
    LureLessFlag = 0;
    if (lure_no < 0 || lure == 0) {
        LureLessFlag = 1;
        LureObj.point_num = 1;
        SetObjectPoint(LureObj.point[0], 0.0f, 0.0f, 0.0f);
        return;
    }

    lure->SetPosition(0.0f, 0.0f, 0.0f);
    lure->SetRotation(0.0f, 0.0f, 0.0f);
    mgCFrame *body = lure->SearchFrame((char *)"obj1");
    float body_length = 4.0f;
    if (lure_no == 0 && body != 0) {
        sceVu0FVECTOR body_pos;
        body->GetWorldPosition0(body_pos);
        body_length = mgDistVector(body_pos);
    }
    LureObj.point_num = 5;
    for (int i = 0; i < LureObj.point_num; i++) {
        mgZeroVector(LureObj.point[i].pos);
        mgZeroVector(LureObj.point[i].old_pos);
        mgZeroVector(LureObj.point[i].velo);
    }
    SetObjectPoint(LureObj.point[0], 0.0f, 0.0f, 0.0f);
    SetObjectPoint(LureObj.point[1], 0.0f, 0.0f, body_length);
    SetObjectPoint(LureObj.point[2], 0.0f, -1.0f, body_length * 0.5f);
    SetObjectPoint(LureObj.point[3], 0.0f, 1.0f, body_length + 2.0f);
    SetObjectPoint(LureObj.point[4], 0.0f, -1.0f, body_length + 2.0f);
    SetObjectBind(LureObj.bind[0], LureObj.point[0], LureObj.point[1]);
    SetObjectBind(LureObj.bind[1], LureObj.point[1], LureObj.point[2]);
    SetObjectBind(LureObj.bind[2], LureObj.point[0], LureObj.point[2]);
    SetObjectBind(LureObj.bind[3], LureObj.point[1], LureObj.point[3]);
    SetObjectBind(LureObj.bind[4], LureObj.point[1], LureObj.point[4]);
    SetObjectBind(LureObj.bind[5], LureObj.point[3], LureObj.point[4]);
    LureObj.bind_num = 6;
    LureObj.float_num = 2;
    LureObj.float_info[0].point0 = &LureObj.point[0];
    LureObj.float_info[0].point1 = &LureObj.point[2];
    LureObj.float_info[0].unk_8 = 0;
    LureObj.float_info[0].buoyancy = 2.5f;
    LureObj.float_info[1].point0 = &LureObj.point[1];
    LureObj.float_info[1].point1 = &LureObj.point[2];
    LureObj.float_info[1].unk_8 = 0;
    LureObj.float_info[1].buoyancy = 2.5f;
    sceVu0FVECTOR rod_tip;
    SaoFrame[7]->GetWorldPosition0(rod_tip);
    for (int i = 0; i < LureObj.point_num; i++) {
        mgAddVector(LureObj.point[i].pos, rod_tip);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitLureObj__FiP8mgCFrame);
#endif
#ifdef NONMATCHING
void InitUkiObj(int no, mgCFrame *uki, mgCFrame *hari) {
    sceVu0FVECTOR rod_tip;
    SaoFrame[7]->GetWorldPosition0(rod_tip);

    UkiObj.point_num = 4;
    for (int i = 0; i < UkiObj.point_num; i++) {
        mgZeroVector(UkiObj.point[i].pos);
        mgZeroVector(UkiObj.point[i].old_pos);
        mgZeroVector(UkiObj.point[i].velo);
    }
    SetObjectPoint(UkiObj.point[0], 0.0f, 2.0f, 0.0f);
    SetObjectPoint(UkiObj.point[1], 0.0f, -1.5f, 3.0f);
    SetObjectPoint(UkiObj.point[2], 2.5980763f, -1.5f, -1.5f);
    SetObjectPoint(UkiObj.point[3], -2.5980763f, -1.5f, -1.5f);
    for (int i = 0; i < UkiObj.point_num; i++) {
        mgAddVector(UkiObj.point[i].pos, rod_tip);
    }
    SetObjectBind(UkiObj.bind[0], UkiObj.point[0], UkiObj.point[1]);
    SetObjectBind(UkiObj.bind[1], UkiObj.point[0], UkiObj.point[2]);
    SetObjectBind(UkiObj.bind[2], UkiObj.point[0], UkiObj.point[3]);
    SetObjectBind(UkiObj.bind[3], UkiObj.point[1], UkiObj.point[2]);
    SetObjectBind(UkiObj.bind[4], UkiObj.point[2], UkiObj.point[3]);
    SetObjectBind(UkiObj.bind[5], UkiObj.point[3], UkiObj.point[1]);
    UkiObj.bind_num = 6;
    UkiObj.float_num = 3;
    for (int i = 0; i < UkiObj.float_num; i++) {
        UkiObj.float_info[i].point0 = &UkiObj.point[i + 1];
        UkiObj.float_info[i].point1 = &UkiObj.point[0];
        UkiObj.float_info[i].unk_8 = 0;
        UkiObj.float_info[i].buoyancy = 1.6f;
    }

    HariObj.point_num = 3;
    for (int i = 0; i < HariObj.point_num; i++) {
        mgZeroVector(HariObj.point[i].pos);
        mgZeroVector(HariObj.point[i].old_pos);
        mgZeroVector(HariObj.point[i].velo);
    }
    SetObjectPoint(HariObj.point[0], 0.0f, 0.0f, 0.0f);
    SetObjectPoint(HariObj.point[1], 1.0f, -4.0f, 0.0f);
    SetObjectPoint(HariObj.point[2], -1.0f, -4.0f, 0.0f);
    for (int i = 0; i < HariObj.point_num; i++) {
        mgAddVector(HariObj.point[i].pos, rod_tip);
    }
    SetObjectBind(HariObj.bind[0], HariObj.point[0], HariObj.point[1]);
    SetObjectBind(HariObj.bind[1], HariObj.point[0], HariObj.point[2]);
    SetObjectBind(HariObj.bind[2], HariObj.point[1], HariObj.point[2]);
    HariObj.bind_num = 3;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", InitUkiObj__FiP8mgCFrameP8mgCFrame);
#endif
#ifdef NONMATCHING
void CFishObj::MovePoint() {
    for (int i = 0; i < point_num; i++) {
        sceVu0CopyVector(point[i].old_pos, point[i].pos);
        mgAddVector(point[i].pos, point[i].velo);
        point[i].pos[1] -= 0.6f;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", MovePoint__8CFishObjFv);
#endif
#ifdef NONMATCHING
void CFishObj::FloatPoint(float water_level) {
    for (int i = 0; i < float_num; i++) {
        FISH_FLOAT &pair = float_info[i];
        float first_height = pair.point0->pos[1];
        float second_height = pair.point1->pos[1];
        float span = first_height - second_height;
        float abs_span = span < 0.0f ? -span : span;
        if (abs_span < 0.01f) {
            continue;
        }
        float submerged = water_level - (second_height < first_height ? second_height : first_height);
        float depth = submerged / abs_span;
        if (depth < 0.0f) {
            continue;
        }
        if (depth > 1.0f) {
            depth = 1.0f;
        }
        pair.point0->velo[0] *= 0.3f;
        pair.point0->velo[2] *= 0.3f;
        pair.point0->velo[1] += pair.buoyancy * depth;
    }
    for (int i = 0; i < point_num; i++) {
        if (point[i].pos[1] < water_level) {
            point[i].velo[0] *= 0.1f;
            if (point[i].velo[1] < 0.0f) {
                point[i].velo[1] *= 0.1f;
            }
            point[i].velo[2] *= 0.1f;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", FloatPoint__8CFishObjFf);
#endif
#ifdef NONMATCHING
void CFishObj::BindStep() {
    for (int i = 0; i < bind_num; i++) {
        BindPosition(bind[i].point0->pos, bind[i].point1->pos, bind[i].length, bind[i].rate);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", BindStep__8CFishObjFv);
#endif
#ifdef NONMATCHING
void CFishObj::Correct(CCPoly *poly, int poly_num, float damping) {
    for (int i = 0; i < point_num; i++) {
        FISH_POINT &current = point[i];
        float upper = current.pos[1] > current.old_pos[1] ? current.pos[1] : current.old_pos[1];
        float lower = current.pos[1] < current.old_pos[1] ? current.pos[1] : current.old_pos[1];
        sceVu0FVECTOR from;
        sceVu0FVECTOR to;
        sceVu0FVECTOR hit;
        sceVu0FVECTOR correction;
        mgZeroVector(correction);
        sceVu0CopyVector(from, current.pos);
        sceVu0CopyVector(to, current.pos);
        from[1] = upper + 4.0f;
        to[1] = lower - 1.0f;
        int hit_poly = CheckHit(poly, poly_num, from, to, hit, 1, 9);
        float friction = 0.95f;
        if (hit_poly >= 0 && current.pos[1] < hit[1] + 1.0f) {
            correction[1] = -current.velo[1] * 0.5f;
            current.pos[1] += hit[1] + 1.0f - current.pos[1];
            friction = 0.19f;
        }
        sceVu0SubVector(current.velo, current.pos, current.old_pos);
        sceVu0ScaleVector(current.velo, current.velo, friction * damping);
        mgAddVector(current.velo, correction);
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", Correct__8CFishObjFP6CCPolyif);
#endif
#ifdef NONMATCHING
static void ParaBlend(float *out, float time, sceVu0FVECTOR *samples, int count) {
    sceVu0FMATRIX basis = {
        {-1.0f, 3.0f, -3.0f, 1.0f},
        {2.0f, -5.0f, 4.0f, -1.0f},
        {-1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 2.0f, 0.0f, 0.0f}
    };
    float interval = 1.0f / (float)(count - 1);
    int index = (int)(time / interval);
    float fraction = (time - (float)index * interval) * (float)(count - 1);
    int indices[4] = {index - 1, index, index + 1, index + 2};
    if (indices[0] < 0) {
        indices[0] = 0;
    }
    for (int i = 1; i < 4; i++) {
        if (indices[i] >= count) {
            indices[i] = count - 1;
        }
    }
    sceVu0FMATRIX coefficients;
    sceVu0FMATRIX control;
    for (int row = 0; row < 4; row++) {
        sceVu0CopyVector(coefficients[row], basis[row]);
        sceVu0CopyVector(control[row], samples[indices[row]]);
        control[row][3] = 0.0f;
    }
    sceVu0TransposeMatrix(coefficients, coefficients);
    sceVu0TransposeMatrix(control, control);
    mgMulMatrix(coefficients, coefficients, control);
    sceVu0TransposeMatrix(coefficients, coefficients);
    sceVu0FVECTOR power = {fraction * fraction * fraction, fraction * fraction, fraction, 1.0f};
    sceVu0ScaleVector(power, power, 0.5f);
    sceVu0ApplyMatrix(out, coefficients, power);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", ParaBlend__FPffPA4_fi);
#endif

// Static initialiser (.init)
#ifdef NONMATCHING
extern "C" void __sinit_fishingobj_cpp() {
    memset(&LureObj, 0, sizeof(LureObj));
    memset(&UkiObj, 0, sizeof(UkiObj));
    memset(&HariObj, 0, sizeof(HariObj));
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/fishingobj", __sinit_fishingobj_cpp);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_975__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_985__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_986__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1797__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1798__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_896__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_897__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_898__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_899__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_900__6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_901__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_902__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_903__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1503__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", at_1564__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/fishingobj", D_0037B08C__DATA);

// Small uninitialised data (.sbss)
#ifndef NONMATCHING
INCLUDE_BSS(WaterLevel, 0x4);
INCLUDE_BSS(LineTop, 0x4);
INCLUDE_BSS(LineTopDist, 0x4);
INCLUDE_BSS(CastingLureFlag, 0x4);
INCLUDE_BSS(CastingLureTime, 0x4);
INCLUDE_BSS(AddLineSpeed, 0x4);
INCLUDE_BSS(BattleFlag, 0x4);
INCLUDE_BSS(BattleLineDist, 0x4);
INCLUDE_BSS(ShowHari, 0x4);
INCLUDE_BSS(LureLessFlag, 0x4);
INCLUDE_BSS(NowMode, 0x4);
INCLUDE_BSS(NowFishSpeed, 0x4);
INCLUDE_BSS(NowFishRot, 0x4);
INCLUDE_BSS(ActionChanceNextCnt, 0x4);
INCLUDE_BSS(ActionChanceCnt, 0x4);
INCLUDE_BSS(ActionChanceDir, 0x4);
#endif

// Uninitialised data (.bss)
#ifndef NONMATCHING
INCLUDE_BSS(RodPoint, 0xF0);
INCLUDE_BSS(RodPointDist, 0x50);
INCLUDE_BSS(SaoFrame, 0x20);
INCLUDE_BSS(SaoDist, 0x20);
INCLUDE_BSS(LinePoint, 0xC00);
INCLUDE_BSS(LurePoint, 0x90);
INCLUDE_BSS(FlyingPoint, 0x30);
INCLUDE_BSS(FishPoint, 0x30);
INCLUDE_BSS(CastingPoint, 0x10);
INCLUDE_BSS(ReleasePoint, 0x10);
INCLUDE_BSS(BattleStartPos, 0x10);
INCLUDE_BSS(LureObj, 0x3D0);
INCLUDE_BSS(UkiObj, 0x3D0);
INCLUDE_BSS(HariObj, 0x3D0);
INCLUDE_BSS(ChanceBarPos, 0x10);
#endif
