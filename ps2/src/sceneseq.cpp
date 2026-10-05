#include "common.h"
#include "sceneseq.hpp"
#include <cstring>
#include <cmath>

// Code (.text)
void InitSplineKey(SPLINE_KEY * arg0) {
    (*(s32 *)((u8 *)arg0 + 0x0)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x4)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x8)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x14)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x20)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x2c)) = 0;
    (*(s32 *)((u8 *)arg0 + 0xc)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x18)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x24)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x30)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x10)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x1c)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x28)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x34)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", __ct__9C3DSplineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__9C3DSplineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetUpSpline__9C3DSplineFPA4_fPiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", StepS__9C3DSplineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Step__9C3DSplineFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", GetNowXYZ__9C3DSplineFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", __ct__10CCameraPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddCameraPas__10CCameraPasFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", InsCameraPas__10CCameraPasFiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetCameraPas__10CCameraPasFiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", GetCameraPas__10CCameraPasFiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", DelCameraPas__10CCameraPasFi);
s32 CCameraPas::SetFrame(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x204)) = arg0;
    return 0;
}
s32 CCameraPas::GetFrame(void) {
    return (*(s32 *)((u8 *)this + 0x204));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__10CCameraPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Setup__10CCameraPasFv);
void CCameraPas::Run(void) {
    (*(s32 *)((u8 *)this + 0x940)) = 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Step__10CCameraPasFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", CheckEnd__10CCameraPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", __ct__9CCharaPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__9CCharaPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddCharaPas__9CCharaPasFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Setup__9CCharaPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Run__9CCharaPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Step__9CCharaPasFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", CheckEnd__9CCharaPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", InsCharaPas__9CCharaPasFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetCharaPas__9CCharaPasFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", GetCharaPas__9CCharaPasFiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", DelCharaPas__9CCharaPasFi);
void CCharaPas::SetFrame(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x100)) = arg0;
}
s32 CCharaPas::GetFrame(void) {
    return (*(s32 *)((u8 *)this + 0x100));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsPRDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetPos__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetRef__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAHDDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetAngle__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetHeight__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetDist__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetAHD__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMove__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMove2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMoveRef__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMovePos__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMoveAHD__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMoveAHD2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetSyncObj__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsReleaseSyncObj__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAHDSlowing__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsAHDKeep(_SEN_CMR_SEQ * arg0, CSceneCmrSeq * arg1) {
    (*(_SEN_CMR_SEQ * *)((u8 *)arg1 + 0x34)) = arg0;
    return 0;
}
s32 scsAHDReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 2;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsInitPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetPasFrm__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAddPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsStartPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsPRSlowing__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsPRKeep(_SEN_CMR_SEQ * arg0, CSceneCmrSeq * arg1) {
    (*(_SEN_CMR_SEQ * *)((u8 *)arg1 + 0x30)) = arg0;
    return 0;
}
s32 scsPRReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 2;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsFadeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsFadeInit(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsFadeIn__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsFadeOut__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsQuakeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsQuake__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsQuake2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsCharaDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsCharaAttach__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsDummy(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", InitSceneCmrSeq__FP12_SEN_CMR_SEQ);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", __ct__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", ZeroInitialize__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__12CSceneCmrSeqFP12_SEN_CMR_SEQi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Clear__12CSceneCmrSeqFv);
s32 CSceneCmrSeq::CheckEnd(void) {
    s32 *p = (s32 *) this;
    if (p[2] == 0) {
        if (p[4] == 0 && p[6] == 0 && p[8] == 0) {
            return 1;
        }
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Play__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextPrSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextAhdSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextFadeSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextQuakeSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextCharaSeq__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", GetNextSeq__12CSceneCmrSeqFP12_SEN_CMR_SEQi);
void CSceneCmrSeq::PRDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPrSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 1;
        temp_v0[12] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetPos__12CSceneCmrSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetRef__12CSceneCmrSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move__12CSceneCmrSeqFPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move2__12CSceneCmrSeqFPfPfiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MoveRef__12CSceneCmrSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MovePos__12CSceneCmrSeqFPfi);
void CSceneCmrSeq::InitPas(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPrSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 8;
    }
}
void CSceneCmrSeq::SetPasFrm(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPrSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x9;
        temp_v0[12] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddPas__12CSceneCmrSeqFPfPf);
void CSceneCmrSeq::StartPas(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPrSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0xB;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", PRSlowing__12CSceneCmrSeqFfi);
void CSceneCmrSeq::PRKeep(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPrSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0xD;
    }
}
void CSceneCmrSeq::PRReturn(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPrSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0xE;
    }
}
void CSceneCmrSeq::AHDDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextAhdSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0xf;
        temp_v0[12] = arg0;
    }
}
void CSceneCmrSeq::SetAngle(float f) {
    int *p = (int *)this->SearchNextAhdSeq();
    if (p) { p[0] = 0x10; *(float *)(p + 12) = f; }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetHeight__12CSceneCmrSeqFf);
void CSceneCmrSeq::SetDist(float f) {
    int *p = (int *)this->SearchNextAhdSeq();
    if (p) { p[0] = 0x12; *(float *)(p + 12) = f; }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetAHD__12CSceneCmrSeqFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MoveAHD__12CSceneCmrSeqFfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MoveAHD2__12CSceneCmrSeqFfffiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetSyncObj__12CSceneCmrSeqFiPffffiPc);
void CSceneCmrSeq::ReleaseSyncObj(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextAhdSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x17;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AHDSlowing__12CSceneCmrSeqFfi);
void CSceneCmrSeq::AHDKeep(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextAhdSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x19;
    }
}
void CSceneCmrSeq::AHDReturn(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextAhdSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1A;
    }
}
void CSceneCmrSeq::FadeDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextFadeSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1b;
        temp_v0[12] = arg0;
    }
}
void CSceneCmrSeq::FadeInit(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextFadeSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1C;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", FadeIn__12CSceneCmrSeqFifff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", FadeOut__12CSceneCmrSeqFifff);
void CSceneCmrSeq::QuakeDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextQuakeSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1f;
        temp_v0[12] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Quake__12CSceneCmrSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Quake2__12CSceneCmrSeqFPfi);
void CSceneCmrSeq::CharaDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextCharaSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x22;
        temp_v0[12] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", CharaAttach__12CSceneCmrSeqFifi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsPosDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetPos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMove__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMove2__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsInitPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetPasFrm__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAddPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsStartPas__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsJump__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetEohFramePos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAddPos__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAttachCamera__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsResetDAPosition__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsRotDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetRot__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsRotation__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsRotation2__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsReference__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMotionDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsNextMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMotionWait__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMotionTrg__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetMotStep__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetMotChangeStep__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsResetMotion__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetMotionNowTime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetMotionWaitTime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsNormalDrive__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsMotionTrgWait__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsTexAnimeDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsTexAnime__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsColorDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetColor__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsScaleDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetScale__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSeDelay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSePlay__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsDummy__FP12_SEN_OBJ_SEQP12CSceneObjSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", InitSceneObjSeq__FP12_SEN_OBJ_SEQ);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", __ct__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", ZeroInitialize__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__12CSceneObjSeqFP12_SEN_OBJ_SEQi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Clear__12CSceneObjSeqFv);
void CSceneObjSeq::SetEohNo(s32 arg0) {
    (*(s32 *)((u8 *)this + 0x64)) = arg0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", GetNextSeq__12CSceneObjSeqFP12_SEN_OBJ_SEQ);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextPosSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextRotSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextMotSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextAnmSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextColSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextScaleSeq__12CSceneObjSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SearchNextSeSeq__12CSceneObjSeqFv);
s32 CSceneObjSeq::CheckEnd(void) {
    s32 *p = (s32 *) this;
    if (p[2] == 0) {
        if (p[4] == 0 && p[6] == 0 && p[8] == 0 && p[10] == 0 && p[12] == 0 && p[14] == 0) {
            return 1;
        }
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Play__12CSceneObjSeqFv);
void CSceneObjSeq::PosDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPosSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetPos__12CSceneObjSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move__12CSceneObjSeqFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move2__12CSceneObjSeqFPfiif);
void CSceneObjSeq::InitPas(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPosSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 5;
    }
}
void CSceneObjSeq::SetPasFrm(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextPosSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x6;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddPas__12CSceneObjSeqFPf);
void CSceneObjSeq::StartPas(s32 arg0) {
    struct temp_v0_champs_ce64ab *temp_v0;

    temp_v0 = (struct temp_v0_champs_ce64ab *) (this->SearchNextPosSeq());
    if (temp_v0 != NULL) {
        (*(s32 *)((u8 *)temp_v0 + 0x0)) = 8;
        (*(s32 *)((u8 *)temp_v0 + 0x20)) = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Jump__12CSceneObjSeqFPffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetEohFramePos__12CSceneObjSeqFiPciPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddPos__12CSceneObjSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AttachCamera__12CSceneObjSeqFfi);
void CSceneObjSeq::RotDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextRotSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0xd;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetRot__12CSceneObjSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Rotation__12CSceneObjSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Rotation2__12CSceneObjSeqFPfiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Reference__12CSceneObjSeqFPfi);
void CSceneObjSeq::MotionDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x12;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetMotion__12CSceneObjSeqFPcif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", NextMotion__12CSceneObjSeqFPcif);
void CSceneObjSeq::MotionWait(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x15;
    }
}
void CSceneObjSeq::SetMotionTrg(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x16;
    }
}
void CSceneObjSeq::MotionTrgWait(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x17;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetStep__12CSceneObjSeqFf);
void CSceneObjSeq::SetChengeStep(float f) {
    int *p = (int *)this->SearchNextMotSeq();
    if (p) { p[0] = 0x19; *(float *)(p + 8) = f; }
}
void CSceneObjSeq::ResetMotion(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1A;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetMotionNowTime__12CSceneObjSeqFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetMotionWaitTime__12CSceneObjSeqFf);
void CSceneObjSeq::NormalDrive(void) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x1D;
    }
}
void CSceneObjSeq::TexAnimeDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextAnmSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x1e;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", TexAnime__12CSceneObjSeqFPci);
void CSceneObjSeq::ColorDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextColSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x20;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetColor__12CSceneObjSeqFPfi);
void CSceneObjSeq::ScaleDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextScaleSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x22;
        temp_v0[8] = arg0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetScale__12CSceneObjSeqFPfi);
void CSceneObjSeq::SeDelay(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = (s32 *) (this->SearchNextSeSeq());
    if (temp_v0 != NULL) {
        if (arg0 > 0) {
            arg0 = (arg0 * 50) / 60;
            if (arg0 <= 0) {
                arg0 = 1;
            }
        }
        *temp_v0 = 0x24;
        temp_v0[8] = arg0;
    }
}
void CSceneObjSeq::SePlay(s32 arg0, s32 arg1) {
    struct temp_v0_champs *temp_v0;

    temp_v0 = (struct temp_v0_champs *) (this->SearchNextSeSeq());
    if (temp_v0 != NULL) {
        (*(s32 *)((u8 *)temp_v0 + 0x0)) = 0x25;
        (*(s32 *)((u8 *)temp_v0 + 0x20)) = arg0;
        (*(s32 *)((u8 *)temp_v0 + 0x24)) = arg1;
    }
}
void CSceneObjSeq::ResetDAPosition(void) {
    s32 *temp_v0;
    s32 *temp_v0_2;

    temp_v0 = (s32 *) (this->SearchNextSeSeq());
    if (temp_v0 != NULL) {
        *temp_v0 = 0x26;
    }
    temp_v0_2 = (s32 *) (this->SearchNextMotSeq());
    if (temp_v0_2 != NULL) {
        *temp_v0_2 = 0x26;
    }
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", ScsCmrSeqCallTbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", ScsObjSeqCallTbl__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", at_1527__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", at_2863__DATA);
