#include "common.h"
#include "event_func.hpp"
#include <cstring>
#include <cstdio>

// Code (.text)
CEoh::CEoh(void) {
    (*(s32 *)((u8 *)this + 0x0)) = -1;
    (*(s32 *)((u8 *)this + 0x4)) = -1;
    (*(s32 *)((u8 *)this + 0x8)) = 1;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__4CEohFiP7CObjecti);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__4CEohFiiP11CCharacter2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__4CEohFiP13CEventSprite2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__4CEohFiP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__4CEohFiP10CFuncPoint);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", VectMatMul__FPfPfPA4_f__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CalcPosWorldCoord__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CalcPosWorldCoordGyaku__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetCamWorldCoord__FP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetCamWorldCoordGyaku__FP9mgCCamera);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", __ct__10CEohMotherFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__10CEohMotherFiiP7CObjecti);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__10CEohMotherFiiiP11CCharacter2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__10CEohMotherFiiP13CEventSprite2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__10CEohMotherFiiP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Set__10CEohMotherFiiP10CFuncPoint);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetPos__10CEohMotherFifff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetRot__10CEohMotherFifff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetPos__10CEohMotherFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetRot__10CEohMotherFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetMotion__10CEohMotherFiPcif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CheckMotionEnd__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetMotionTrg__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetSeqStatus__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetStep__10CEohMotherFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetChangeStep__10CEohMotherFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", ResetMotion__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetTexAnim__10CEohMotherFiiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetScale__10CEohMotherFifff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetScale__10CEohMotherFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetShow__10CEohMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetShow__10CEohMotherFiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SearchFrame__10CEohMotherFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetFrameShow__10CEohMotherFiPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetShadow__10CEohMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetShadowFrameShow__10CEohMotherFiPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetTranslate__10CEohMotherFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetColor__10CEohMotherFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetColor__10CEohMotherFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetNowMotionName__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetNowMotionStatus__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetMotionNowTime__10CEohMotherFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetMotionWaitTime__10CEohMotherFif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetFootSoundID__10CEohMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetFramePos__10CEohMotherFiPcPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetSoundID__10CEohMotherFiUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetFrameShow__10CEohMotherFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetFadeFlag__10CEohMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", ResetDAPosition__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", NormalDrive__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", UpdatePosition__10CEohMotherFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetFrameObjAlpha__10CEohMotherFiPcf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetFootSeId__10CEohMotherFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", FileNameConvLanguage__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetStackInt__FP12RS_STACKDATA__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetStackFloat__FP12RS_STACKDATA__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetStackVector__FPfP12RS_STACKDATA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetStackString__FP12RS_STACKDATA__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetStack__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetStack__FP12RS_STACKDATAf__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", BuildArgData__15CEventScriptArgFPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ID_OFFSET__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetArgInt__FP8ARG_DATA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetArgFloat__FP8ARG_DATA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetArgString__FP8ARG_DATA);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetArgVector__FPfP8ARG_DATA);
void CRaster::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = 0;
    (*(s32 *)((u8 *)this + 0x8)) = 0;
    (*(s32 *)((u8 *)this + 0x4)) = 0;
    (*(s32 *)((u8 *)this + 0x10)) = 0;
    (*(s32 *)((u8 *)this + 0xc)) = 0;
    (*(s32 *)((u8 *)this + 0x18)) = 0;
    (*(s32 *)((u8 *)this + 0x14)) = 0;
    (*(s32 *)((u8 *)this + 0x20)) = 0;
    (*(s32 *)((u8 *)this + 0x1c)) = 0;
    (*(s32 *)((u8 *)this + 0x24)) = -1;
    (*(s32 *)((u8 *)this + 0x28)) = 0;
}
void CRaster::SetParam(float arg0, float arg1, float arg2) {
    *(float *) ((u8 *) this + 4) = arg0;
    *(float *) ((u8 *) this + 0xC) = arg1;
    *(float *) ((u8 *) this + 0x14) = arg2;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", StartRaster__7CRasterFfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", StopRaster__7CRasterFfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", StepRaster__7CRasterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", DrawRaster__7CRasterFv);
void CScreenEffect::Initialize(void) {
    ((CRaster *) this)->Initialize();
    (*(s32 *)((u8 *)this + 0x2c)) = 0;
    (*(s32 *)((u8 *)this + 0x30)) = 0;
    (*(s32 *)((u8 *)this + 0x34)) = 0;
    (*(s32 *)((u8 *)this + 0x38)) = 0;
    (*(s32 *)((u8 *)this + 0x3c)) = 0;
    (*(s32 *)((u8 *)this + 0x40)) = 0;
    (*(s32 *)((u8 *)this + 0x44)) = 0;
    (*(s32 *)((u8 *)this + 0x48)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Step__13CScreenEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", Draw__13CScreenEffectFv);
void CScreenEffect::InitRaster(float arg0, float arg1, float arg2) {
    ((CRaster *) this)->Initialize();
    ((CRaster *) this)->SetParam(arg0, arg1, arg2);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", StartRaster__13CScreenEffectFfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", StopRaster__13CScreenEffectFfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetSepiaTexture__13CScreenEffectFP10mgCTextureP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CaptureSepiaScreen__13CScreenEffectFv);
void CScreenEffect::SetSepiaFlag(s32 arg0) {
    if ((*(s32 *)((u8 *)this + 0x2c)) != 0) {
        (*(s32 *)((u8 *)this + 0x30)) = arg0;
        return;
    }
    (*(s32 *)((u8 *)this + 0x30)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetMonoFlashTexture__13CScreenEffectFPP10mgCTexturePP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CaptureMonoFlashScreen__13CScreenEffectFv);
void CScreenEffect::SetMonoFlashFlag(s32 arg0, s32 arg1) {
    if (((*(s32 *)((u8 *)this + 0x34)) != 0) || ((*(s32 *)((u8 *)this + 0x38)) != 0)) {
        (*(s32 *)((u8 *)this + 0x3c)) = arg0;
    } else {
        (*(s32 *)((u8 *)this + 0x3c)) = 0;
    }
    (*(s32 *)((u8 *)this + 0x40)) = arg1;
    (*(s32 *)((u8 *)this + 0x44)) = 0;
    (*(s32 *)((u8 *)this + 0x48)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", InitWorldCoord__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetLocalFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetLocalFlag__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetLocalCnt__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetLocalCnt__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetLocalCnt2__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", InitLocalCnt__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventInfoCommandInitialize__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EventSeqInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EventTimeDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventFirstDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventFinish__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", InitDramaScene__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CancelDramaScene__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventMenuExit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventLoopInit__Fv);
void EdSetBrokenObject(void) {
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", ResetMesFileBuffAll__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventMapInit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", EdEventTermination__Fv);
void EdEventEnd(void) {
    ResetMesFileBuffAll();
    EventSeqInit();
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetObjSeq__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PADON__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PADDOWN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PADUP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_APAD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CheckLoadedBGFile__FPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetLoadBGBuff__FPcPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_INTERIOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_OUTSIDE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _INITIALIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_CHARA_sub__FiPPciPUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_CHARA_sub__FiPPciPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHARA_ACTIVE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CLEAR_STACK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ASSIGN_STACK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CURRENT_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHANGE_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DELETE_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MOTION_sub__FiPciPUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MAP_JUMP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_RAIN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DEL_EXT_MOTION__FP12RS_STACKDATAi);
s32 _SET_MARKER(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_WORLD_COORD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FINISH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_DUN_WORLD_COORD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DEL_IMG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_DNG_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_USE_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_LOCAL_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_LOCAL_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_SELECT_PARTY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_LOADBG_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_LOADBG_FILE_MONS_TALK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_LOADBG_FILE__FP12RS_STACKDATAi);
s32 _GET_TB_ITEMNO(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_TB_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_TB_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SUB_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ITEM_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ITEM_SPACE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetConfigCaptionOff__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", LoadMovie__FPcP9mgCMemoryb);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MOVIE__FP12RS_STACKDATAi);
s32 _INIT_LOCAL_CNT(RS_STACKDATA *arg0, s32 arg1) {
    InitLocalCnt();
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CROSSFADE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ADJUST_POLYGON_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_ACTIVE_LIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_PAKU_ANIM__FP12RS_STACKDATAi);
s32 _RESET_PAKU_ANIM(RS_STACKDATA *arg0, s32 arg1) {
    PakuAnimEohNo = -1;
    memset(&PakuAnimName, 0, 0x40);
    memset(&PakuAnimName2, 0, 0x40);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _TRG_PAKU_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _RESET_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ACTIVE_CHR_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_ACTIVE_CHR_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_SET_FLOOR_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_GET_FLOOR_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_PAKU_MOTION__FP12RS_STACKDATAi);
s32 _RESET_PAKU_MOTION(RS_STACKDATA *arg0, s32 arg1) {
    PakuMotionEohNo = -1;
    memset(&PakuMotionName, 0, 0x40);
    memset(&PakuMotionName2, 0, 0x40);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _TRG_PAKU_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_BG_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_DNG_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_DNG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_EDIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MENU_PARAM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_CHARA_NPC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _AUTO_SET_TREASURE_BOX__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _AUTO_SET_MONSTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_DUNGEON_MAP_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MONSTER_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NPC_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_NPC_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NOW_PARTY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_LOCAL_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_LOCAL_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_LOCAL_CNT2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_TRAIN_NPC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_DRAW_CHAPTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_PROJECTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PROJECTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FADE_IN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FADE_OUT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_DEBUG_COMMAND__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CD_SEEK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ROT_LOOK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MOTION_BLUR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SCRIPT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_TALK_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _HIT_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _COPY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_START_BUTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MOVE_INTERIOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MONSTER_TALK_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FUNC_POINT_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NOW_MAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NOW_SUBMAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_OLD_MAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_OLD_SUBMAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_RAIN_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_EDIT_PARTS_POS__FP12RS_STACKDATAi);
s32 _GET_CONTENTS_POS(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BPOT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BPOT_STATUS__FP12RS_STACKDATAi);
s32 _GET_PERSON_STATUS(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CONTROL_CHRID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CAMERA_NEXT_REF__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_MENU__FP12RS_STACKDATAi);
s32 _GET_MENU_STATUS(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_EQUIP_ITEMNO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_TIME_STEP_ENABLE__FP12RS_STACKDATAi);
s32 _SET_DOOR_MATERIAL(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _INIT_DRAMA_SCENE(RS_STACKDATA *arg0, s32 arg1) {
    InitDramaScene();
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_ACTIVE_CMRID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_BEFORE_CMRID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNGMAP_LOAD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNGMAP_DELETE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNGMAP_MOVE_PIECE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNGMAP_ONOFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNGMAP_SET_FADE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BEFORE_CAMERA_NEXT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BEFORE_CAMERA_NEXT_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CAMERA_NEXT_POS__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHK_INTERSECTION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHK_INTERSECTION_POINT_PIPE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_FOLLOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_FOLLOW_A__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_FOLLOW_OFS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_FOLLOW_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FCAMERA_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FCAMERA_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_REF_ANGLE__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_SET_STAGE_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_GET_STAGE_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CAMERA_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FCAMERA_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FCAMERA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FCAMERA_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_INVENTION_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FUNCTION_MAP_JUMP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FUNCTION_DOOR_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MONEY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_MONEY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ITEM_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_BUTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_LANGUAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_INVENT_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_AI__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_INVENT_PHOTO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PHOTO_NUM__FP12RS_STACKDATAi);
s32 _SET_CONTENTS_ETC(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_STATUS__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_SUBGAME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_GYORACE_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_GYORACE_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_SAVEDATA_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_SAVEDATA_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DEL_MONSTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MENU_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MENU_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ANALYZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_DIORAMA_PERCENT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GEORAMA_FUNC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_EDITMODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHAPTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NPC_TRAIN_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _REGISTER_VILLAGER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EYE_VIEW_DRAW_ON_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_QUEST_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_QUEST_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_OLD_INTERIOR_MAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_EVENT_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STOPWATCH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FUNC_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetChara__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_TALK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _TURN_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_TEX_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_SCALE__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DEL_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SHADOW_CLIP_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_COORDINATE_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_WIDTH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_WEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHARA_DA_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MOT_NOW_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_MOTION_END__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ACTCHR_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_EX_SOUNDID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ACTCHR_SOUND_INFO_COPY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetMes__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MES_MAKE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MES_CLOSE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MES_NEXTPAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_AUTOSET__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_SHIPPO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_DRAWSPEED__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_CURSOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_OKURI__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_WIN_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_MES_COMPLETE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_MES_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_MES__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_FUKIDASHI__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_WINDOW_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_PRESET__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_ITEM_DIRECT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MES_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PARTY_CHARA_MES_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MES_SET_BUFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MES_WINDOW_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MES_VOICE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_QUESTION_GYOU__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MES_QUESTION_GYOU__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_CLOSE_CNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MES_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MES_sub__FPciP6ClsMes);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MES__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_MES_MONS_TALK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MES_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MES_STR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MES_OKURI__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FISHINGTOURNAMENT_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_FAR_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MODEL_LIGHT_SWITCH__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MODEL_LIGHT_COLOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_OMAKE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_WIND__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_OMAKE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetCamera__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CAMERA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CAMERA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CAMERA_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CAMERA_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CAMERA_SPEED__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CAMERA_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BEFORE_CAMERA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BEFORE_CAMERA_REF__FP12RS_STACKDATAi);
s32 _ASQ_INIT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SYNC_CHARA(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SET_POS(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOVE(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOVE_STEP(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ROT_REF(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ROT_ANGLE(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_CLEAR_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_WAIT_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ROT_MOVE(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SET_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_DELAY_ROT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_TRG(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_PLAY(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_STOP(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_MOTION_NEXT(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ANIME_TRG(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_ANIME(RS_STACKDATA *stack, int argc) {
    return 1;
}
s32 _ASQ_SE_PLAY(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_DRAW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_GET__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_PUT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_NAME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_MOVE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_FADE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IMG_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", GetEventSprite__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_DRAW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_TEXTURE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_PUTSIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_UVSIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPRITE_SET_ALPHAB__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_CHECK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_PRDELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_AHDDELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_ANGLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_HEIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_AHD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_MOVE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_MOVE2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_MOVE_REF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_INIT_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SET_PAS_FRM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_ADD_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_START_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_PR_SLOWING__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_PR_KEEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_PR_RETURN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_MOVE_AHD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_MOVE_AHD2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_RELEASE_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_AHD_SLOWING__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_AHD_KEEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_AHD_RETURN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_FADE_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_FADE_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_FADE_IN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_FADE_OUT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_QUAKE_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_QUAKE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_QUAKE2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_CHARA_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_CHARA_ATTACH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CMRS_MOVE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_CHECK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_POS_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_MOVE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_MOVE2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_INIT_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_PAS_FRM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_ADD_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_START_PAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_JUMP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_EOH_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_ADD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_ATTACH_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_ROT_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_ROTATION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_ROTATION2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_MOTION_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_NEXT_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_MOTION_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_CHENGE_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SEQ_MOT_TRG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SEQ_MOT_TRG_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_RESET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_MOTION_NOW_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_MOTION_WAIT_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_TEXA_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_TEX_ANIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_COLOR_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SCALE_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SE_DELAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_RESET_DA_POSITION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _OBJS_NORMAL_DRIVE__FP12RS_STACKDATAi);
s32 _ASQ_CHECK(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_INIT_PORT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_LOAD_SOUND__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_SND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SE_PAUSE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SET_SE_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SET_SE_PAN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SET_SE_PITCH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SE_ALL_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PLAY_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STOP_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CommandStreamOpenFromFPL__FiPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CommandStreamOpen__FiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", VpkFileNameFromVoiceNo__FPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_OPEN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CommandStreamPlay__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_STANDBY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_GET_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_SYS_SND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_OPEN_CHECK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SE_ENV__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PLAY_ENV_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SYS_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _INIT_SE_SRC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _INIT_SE_ENV__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _INIT_SE_BAS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SE_SRC__FP12RS_STACKDATAi);
s32 _LOAD_SE_FOOT(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _LOAD_SE_DOOR(RS_STACKDATA *stack, int argc) {
    return 0;
}
s32 _LOAD_SE_BOX(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SE_BATTLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_DELETE_PORT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FADE_IN_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FADE_OUT_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STOP_ENV_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_BGM_VOL__FP12RS_STACKDATAi);
s32 _SND_SET_REVERB(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_SET_ENV_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_SILENT_CHECK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _AUTO_CHANGE_ENV__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _BGM_LOAD_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SOUND_LOAD_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _BGM_LOAD_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SOUND_LOAD_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SE_BASE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SOUND__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_CLOSE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", CommandStreamOpen2__FiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_OPEN2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_BGM_PACK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BGM_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MASTER_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MASTER_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BTL_BGM_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_BTL_BGM_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_IN_REVERB__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_STOP_SRC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SND_PAUSE_BGM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _STREAM_OPEN3__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ACTIVE_BGM_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_ACTIVE_BGM_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BGM_STATUS_NOW_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_SE_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SE_ALL_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SOUND_ALL_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _BGM_PLAY_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _BGM_PLAY_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_DEF_BGM_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MOVIE_CC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _REGISTER_VILLAGER2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FISHINGTOURNAMENT_ETC__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_EDIT_OBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_SPRITE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_TEX_ANIM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_GET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_FRAME_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_SHADOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_TRANSLATE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_FOOT_SOUND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_GET_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_SOUND_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_GET_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_CHROBJ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_FADE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_RESET_DA_POSITION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_SHADOW_FRAME_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_GEOSTONE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_SEARCH_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_NORMAL_DRIVE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_FRAME_ALPHA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_FUNCP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SET_FOOT_SE_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _EOH_SYNC_DOOR_PARTS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_UP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_PLAY_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_MINIMAP_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_MM_LINE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_MM_LINE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_PIN_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_PIN_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_BALL_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_BALL_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_PIN_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_PIN_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_BALL_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_BALL_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_PAR_COUNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_PAR_COUNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_MINI_LEVEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_TEXB__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_STATUS_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_RESET_POWGAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_START_POWGAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_TRIGGER_POWGAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_SHOT_POW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_POWGAGE_CODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_POWGAGE_SAFE_LEVEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_CULB_DEF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_SPIN_MARK_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_CULB_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_CALC_CARRY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_PG_CURSOR_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_COL_MODEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_PRIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_LAST_CHALLENGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_LAST_CHALLENGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_OMAKE_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_NOW_HOLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_NOW_HOLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_SET_SCORE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SPHIDA_GET_SCORE__FP12RS_STACKDATAi);
s32 _TEST(RS_STACKDATA *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MT_TEST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ZERO_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _NORMAL_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _COPY_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SUB_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SCALE_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DIV_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DIST_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DIST_VECTOR2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SQRT__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ATAN2F__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ANGLE_CMP__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ANGLE_LIMIT__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_RAND__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LINE_POINT_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CREATE_SWORD_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DELETE_SWORD_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SWORD_EFFECT_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SWORD_EFFECT_ADD_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_CHARA_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_CHARA_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _POST_TREASURE_BOX__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PARTS_ORIGIN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_SET_ROTATE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_ROT_BACK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_MOVE_CAMERA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_SET_ROT_CANCEL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_MOVE_RANGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NEAR_TBOX_POS__FP12RS_STACKDATAi);
s32 _CONV_CHRNO_S2L(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SWE_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SWE_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SWE_SET_TEXTURE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SWE_START_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_EVENT_DATA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_SET_PREV_FLOOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_GET_PREV_FLOOR__FP12RS_STACKDATAi);
s32 _DNG_SET_FAST_FLOOR(RS_STACKDATA *stack, int argc) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FLOOR_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FLOOR_INFO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NEXT_FLOOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PAD_AUTO_REPEAT_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PAD_SET_AUTO_REPEAT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_PAUSE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_CHECK_PAUSE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_RESET_TIMER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_GET_TIMER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_SKIN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHK_CAMERA_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PARTS_FUNC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _RANDOM_CIRCLE_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _RANDOM_CIRCLE_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_XCHG_MAP_LIGHT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GEOSTONE_ANIME_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GEOSTONE_SET_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GEOSTONE_SET_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GEOSTONE_DEL_REFERENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ROBO_MOVE_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_EXIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_EXIT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_E3_VERSION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHK_PAD_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CTRLC_STAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _BSCN_SET_BLIGHT_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_RND_CIRCLE_TRAPID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_RND_CIRCLE_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_STATUSBAR_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_PULL_ITEM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MENU_CHARA_CHENGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_EVENT_INFO_SNDID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_PARTS_POS__FP12RS_STACKDATAi);
s32 _CANCEL_DRAMA_SCENE(RS_STACKDATA *arg0, s32 arg1) {
    CancelDramaScene();
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_RNDC_MOT_NOWT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_MOT_NOWT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHARA_NORMAL_DRIVE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHARA_RESET_DA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_SETUP_MAIN_UNIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _JOIN_PARTY_MEMBER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_CHANGE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_CHANGE_MASK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_EQUIP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_PACK_FILE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_BIT_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_BIT_CTRL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LOAD_ARG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_ITEM_HAVE_NUM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_SKIP_BOTTON__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_SKIP_FCOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_DEBUG_MODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MAP_TYPE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_COLLISION_ALL_CLR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MAP_DRAW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_MC_LOAD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_NOW_MAP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_TBOX_PARAM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CANCEL_LOAD_VILLAGER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CANCEL_NOW_LOADING__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_INITIALIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_INIT_FIX__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_CLEAR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_LOAD_BASE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_CREATE__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_FINISH__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_DELETE__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_SET_VECT1__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_SET_VECT2__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_SET_TARGET_ID__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_LOAD_BASE_PACK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ESM_SET_VALUE__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_CONDITION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_HP_RATE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_GET_ITEM_LIMIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_ITEM_OVER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NOW_LOOP_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IS_CLEAR_DESTROY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IS_CLEAR_PRACTICE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _IS_PLAY_SUB_GAME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _RESET_SUBJECT_COUNTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SCR_EFF_INIT_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SCR_EFF_START_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SCR_EFF_STOP_RASTER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MPCHARA_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FUNC_POINT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PARTS_NAME_STRCMP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_TRIAL_VERSION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FLOOR_EPISODE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FUNC_POINT_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FUNC_POINT_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ACTCHR_SET_DEF_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_FUSION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_DEBUG_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _MINIMAP_DOOR_ENABLE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_CHECK_BOSS_MAP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_RUN_EVENT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_ENABLE_CHARA_CHANGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _INIT_SEPIA__FP12RS_STACKDATAi);
s32 _START_SEPIA(RS_STACKDATA *arg0, s32 arg1) {
    (&EventScreenEffect)->CaptureSepiaScreen();
    (&EventScreenEffect)->SetSepiaFlag(1);
    return 1;
}
s32 _END_SEPIA(RS_STACKDATA *arg0, s32 arg1) {
    (&EventScreenEffect)->SetSepiaFlag(0);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _COPY_MONS2SCNCHR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", __ct__7CObjectFRC7CObject);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _UNLOCK_STACK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _RESET_EVENT_TRG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SEARCH_CHARA_NO__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_NEAR_RANDOM_STONE_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _INIT_MONO_FLASH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _START_MONO_FLASH__FP12RS_STACKDATAi);
s32 _END_MONO_FLASH(RS_STACKDATA *arg0, s32 arg1) {
    (&EventScreenEffect)->SetMonoFlashFlag(0, 0);
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DELETE_VILLAGER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_SET_WEATHER__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_MAXHP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_CHARA_DEFENCE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PLACE_PARTS_NAME_STRCMP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GOTO_USE_ITEM2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DBG_SET_ANALYZE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ATRAMIRIA_ON_OFF__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_YARIKOMI_MEDAL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_MAP_EFFECT_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_MAP_EFFECT_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_FLOOR_INIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_FLOOR_FINISH__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CLEAR_RND_STONE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_FLOOR_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_FLOOR_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _AMG_GET_ATTR_STATUS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_NEAR_DIST__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _SET_KEEP_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_KEEP_TIME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _GET_DOOR_PARTS_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _CHECK_EQUEP_CHANGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _ADD_HP_RATE2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_EFFECT_ALL_CLEAR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _AUTO_CHENGE_BGM_VOL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _UDATA_GET_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _UDATA_ADD_WHP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _UDATA_GET_ABS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _UDATA_ADD_ABS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _DNG_CREATE_EFFECT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _LEAVE_MONICA_ITEM_CHECK__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _PAUSE_ENABLE_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", _FORCE_BOOT_TOUR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", SetEventFunc__FP10CRunScript);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/event_func", __sinit_event_func_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1084__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", esa_ext_func_info__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3242__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", vv_3333__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3339__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4517__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6800__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", ext_func_info__2__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1080__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1081__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1082__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1083__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1103__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1104__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1245__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1246__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1333__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1346__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1357__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1760__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1761__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1904__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1905__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1906__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1907__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1908__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1910__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_1909__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2245__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2246__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2247__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2248__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2249__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2291__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2292__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2333__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2334__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2393__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2664__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2836__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2837__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2838__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_2839__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3328__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3329__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3631__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3632__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3633__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3634__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3635__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3636__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3822__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3823__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_3884__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4072__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4261__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4262__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4263__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4264__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4265__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4266__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4267__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4268__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4269__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4270__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4271__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4274__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4273__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4272__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4291__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4360__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4437__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_4573__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5262__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5263__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5264__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5410__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5411__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5412__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5413__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5414__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5415__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5416__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5417__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5418__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5419__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5420__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5421__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5422__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5424__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5726__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_5736__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6703__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6773__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6774__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6775__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6776__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6781__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6782__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6816__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6834__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_6839__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_7117__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8230__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8406__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8458__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8480__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8902__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8903__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_8904__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_9148__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_9622__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_9744__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_9745__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_10100__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", at_10101__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/event_func", D_0037B03C__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(EventMarker, 0x4);
INCLUDE_BSS(SwordEffect, 0x4);
INCLUDE_BSS(EventEffectScript, 0x4);
INCLUDE_BSS(p_use_item, 0x4);
INCLUDE_BSS(SetWorldCoordFlg, 0x4);
INCLUDE_BSS(PakuAnimEohNo, 0x4);
INCLUDE_BSS(PakuMotionEohNo, 0x4);
INCLUDE_BSS(PakuMotionType, 0x4);
INCLUDE_BSS(PakuMotionType2, 0x4);
INCLUDE_BSS(nowScriptArg, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(EdEventInfo, 0x12A0);
INCLUDE_BSS(EventObjHandleMother, 0x200);
INCLUDE_BSS(esMother, 0x440);
INCLUDE_BSS(EventLocalFlag, 0x100);
INCLUDE_BSS(EventLocalCnt, 0x100);
INCLUDE_BSS(EventRain, 0xABF0);
INCLUDE_BSS(Hit_para, 0x6400);
INCLUDE_BSS(HitEffect, 0x1E0);
INCLUDE_BSS(PakuAnimName, 0x40);
INCLUDE_BSS(PakuAnimName2, 0x40);
INCLUDE_BSS(PakuMotionName, 0x40);
INCLUDE_BSS(PakuMotionName2, 0x40);
INCLUDE_BSS(event_snd_buff, 0x8010);
INCLUDE_BSS(BuffEventSnd, 0x30);
INCLUDE_BSS(event_snd2_buff, 0x1410);
INCLUDE_BSS(BuffEventSnd2, 0x30);
INCLUDE_BSS(EventDngMap, 0x110);
INCLUDE_BSS(cmr_seq_tbl, 0x6000);
INCLUDE_BSS(CameraSeq, 0xB10);
INCLUDE_BSS(obj_seq_tbl, 0x5000);
INCLUDE_BSS(ObjectSeq, 0xBE00);
INCLUDE_BSS(EventSprite2, 0x1800);
INCLUDE_BSS(EventScriptArg, 0x10);
INCLUDE_BSS(EventScreenEffect, 0x50);
INCLUDE_BSS(ext_func__2, 0x1770);
