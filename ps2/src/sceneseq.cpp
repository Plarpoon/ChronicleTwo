#include "common.h"
#include "sceneseq.hpp"

// Code (.text)
void InitSplineKey(SPLINE_KEY * key) {
    key->frame = 0;
    key->length = 0;
    key->a[0] = 0;
    key->b[0] = 0;
    key->c[0] = 0;
    key->d[0] = 0;
    key->a[1] = 0;
    key->b[1] = 0;
    key->c[1] = 0;
    key->d[1] = 0;
    key->a[2] = 0;
    key->b[2] = 0;
    key->c[2] = 0;
    key->d[2] = 0;
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
s32 CCameraPas::SetFrame(s32 frame_count) {
    frame = frame_count;
    return 0;
}
s32 CCameraPas::GetFrame(void) {
    return frame;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__10CCameraPasFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Setup__10CCameraPasFv);
void CCameraPas::Run(void) {
    run = 1;
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
void CCharaPas::SetFrame(s32 frame_count) {
    frame = frame_count;
}
s32 CCharaPas::GetFrame(void) {
    return frame;
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
s32 scsAHDKeep(_SEN_CMR_SEQ * sequence, CSceneCmrSeq * owner) {
    owner->ahd_keep = sequence;
    return SCENE_SEQ_NEXT;
}
s32 scsAHDReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return SCENE_SEQ_RETURN;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsInitPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsSetPasFrm__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsAddPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsStartPas__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsPRSlowing__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsPRKeep(_SEN_CMR_SEQ * sequence, CSceneCmrSeq * owner) {
    owner->pr_keep = sequence;
    return SCENE_SEQ_NEXT;
}
s32 scsPRReturn(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return SCENE_SEQ_RETURN;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsFadeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsFadeInit(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return SCENE_SEQ_NEXT;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsFadeIn__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsFadeOut__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsQuakeDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsQuake__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsQuake2__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsCharaDelay__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", scsCharaAttach__FP12_SEN_CMR_SEQP12CSceneCmrSeq);
s32 scsDummy(_SEN_CMR_SEQ *sequence, CSceneCmrSeq *owner) {
    return SCENE_SEQ_WAIT;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", InitSceneCmrSeq__FP12_SEN_CMR_SEQ);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", __ct__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", ZeroInitialize__12CSceneCmrSeqFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Initialize__12CSceneCmrSeqFP12_SEN_CMR_SEQi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Clear__12CSceneCmrSeqFv);
s32 CSceneCmrSeq::CheckEnd(void) {
    if (pr_seq == 0) {
        if (ahd_seq == 0 && fade_seq == 0 && quake_seq == 0) {
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
void CSceneCmrSeq::PRDelay(s32 frames) {
    _SEN_CMR_SEQ *command = SearchNextPrSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_CMR_CMD_PR_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetPos__12CSceneCmrSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetRef__12CSceneCmrSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move__12CSceneCmrSeqFPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move2__12CSceneCmrSeqFPfPfiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MoveRef__12CSceneCmrSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MovePos__12CSceneCmrSeqFPfi);
void CSceneCmrSeq::InitPas(void) {
    _SEN_CMR_SEQ *command = SearchNextPrSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_INIT_PAS;
    }
}
void CSceneCmrSeq::SetPasFrm(s32 frames) {
    _SEN_CMR_SEQ *command = SearchNextPrSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_CMR_CMD_SET_PAS_FRM;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddPas__12CSceneCmrSeqFPfPf);
void CSceneCmrSeq::StartPas(void) {
    _SEN_CMR_SEQ *command = SearchNextPrSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_START_PAS;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", PRSlowing__12CSceneCmrSeqFfi);
void CSceneCmrSeq::PRKeep(void) {
    _SEN_CMR_SEQ *command = SearchNextPrSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_PR_KEEP;
    }
}
void CSceneCmrSeq::PRReturn(void) {
    _SEN_CMR_SEQ *command = SearchNextPrSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_PR_RETURN;
    }
}
void CSceneCmrSeq::AHDDelay(s32 frames) {
    _SEN_CMR_SEQ *command = SearchNextAhdSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_CMR_CMD_AHD_DELAY;
        command->frame = frames;
    }
}
void CSceneCmrSeq::SetAngle(float angle) {
    _SEN_CMR_SEQ *command = SearchNextAhdSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_SET_ANGLE;
        command->value = angle;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetHeight__12CSceneCmrSeqFf);
void CSceneCmrSeq::SetDist(float distance) {
    _SEN_CMR_SEQ *command = SearchNextAhdSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_SET_DIST;
        command->value = distance;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetAHD__12CSceneCmrSeqFfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MoveAHD__12CSceneCmrSeqFfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", MoveAHD2__12CSceneCmrSeqFfffiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetSyncObj__12CSceneCmrSeqFiPffffiPc);
void CSceneCmrSeq::ReleaseSyncObj(void) {
    _SEN_CMR_SEQ *command = SearchNextAhdSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_RELEASE_SYNC_OBJ;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AHDSlowing__12CSceneCmrSeqFfi);
void CSceneCmrSeq::AHDKeep(void) {
    _SEN_CMR_SEQ *command = SearchNextAhdSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_AHD_KEEP;
    }
}
void CSceneCmrSeq::AHDReturn(void) {
    _SEN_CMR_SEQ *command = SearchNextAhdSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_AHD_RETURN;
    }
}
void CSceneCmrSeq::FadeDelay(s32 frames) {
    _SEN_CMR_SEQ *command = SearchNextFadeSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_CMR_CMD_FADE_DELAY;
        command->frame = frames;
    }
}
void CSceneCmrSeq::FadeInit(void) {
    _SEN_CMR_SEQ *command = SearchNextFadeSeq();
    if (command != NULL) {
        command->cmd = SCENE_CMR_CMD_FADE_INIT;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", FadeIn__12CSceneCmrSeqFifff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", FadeOut__12CSceneCmrSeqFifff);
void CSceneCmrSeq::QuakeDelay(s32 frames) {
    _SEN_CMR_SEQ *command = SearchNextQuakeSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_CMR_CMD_QUAKE_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Quake__12CSceneCmrSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Quake2__12CSceneCmrSeqFPfi);
void CSceneCmrSeq::CharaDelay(s32 frames) {
    _SEN_CMR_SEQ *command = SearchNextCharaSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_CMR_CMD_CHARA_DELAY;
        command->frame = frames;
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
void CSceneObjSeq::SetEohNo(s32 eoh_no) {
    this->eoh_no = eoh_no;
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
    if (pos_seq == 0) {
        if (rot_seq == 0 && mot_seq == 0 && anm_seq == 0 && col_seq == 0 && scale_seq == 0 && se_seq == 0) {
            return 1;
        }
    }
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Play__12CSceneObjSeqFv);
void CSceneObjSeq::PosDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextPosSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_POS_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetPos__12CSceneObjSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move__12CSceneObjSeqFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Move2__12CSceneObjSeqFPfiif);
void CSceneObjSeq::InitPas(void) {
    _SEN_OBJ_SEQ *command = SearchNextPosSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_INIT_PAS;
    }
}
void CSceneObjSeq::SetPasFrm(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextPosSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_SET_PAS_FRM;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddPas__12CSceneObjSeqFPf);
void CSceneObjSeq::StartPas(s32 grounded) {
    _SEN_OBJ_SEQ *command = SearchNextPosSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_START_PAS;
        command->grounded = grounded;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Jump__12CSceneObjSeqFPffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetEohFramePos__12CSceneObjSeqFiPciPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AddPos__12CSceneObjSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", AttachCamera__12CSceneObjSeqFfi);
void CSceneObjSeq::RotDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextRotSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_ROT_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetRot__12CSceneObjSeqFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Rotation__12CSceneObjSeqFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Rotation2__12CSceneObjSeqFPfiif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", Reference__12CSceneObjSeqFPfi);
void CSceneObjSeq::MotionDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_MOTION_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetMotion__12CSceneObjSeqFPcif);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", NextMotion__12CSceneObjSeqFPcif);
void CSceneObjSeq::MotionWait(void) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_MOTION_WAIT;
    }
}
void CSceneObjSeq::SetMotionTrg(void) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_MOTION_TRG;
    }
}
void CSceneObjSeq::MotionTrgWait(void) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_MOTION_TRG_WAIT;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetStep__12CSceneObjSeqFf);
void CSceneObjSeq::SetChengeStep(float step) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_SET_MOT_CHANGE_STEP;
        command->value = step;
    }
}
void CSceneObjSeq::ResetMotion(void) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_RESET_MOTION;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetMotionNowTime__12CSceneObjSeqFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetMotionWaitTime__12CSceneObjSeqFf);
void CSceneObjSeq::NormalDrive(void) {
    _SEN_OBJ_SEQ *command = SearchNextMotSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_NORMAL_DRIVE;
    }
}
void CSceneObjSeq::TexAnimeDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextAnmSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_TEX_ANIME_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", TexAnime__12CSceneObjSeqFPci);
void CSceneObjSeq::ColorDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextColSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_COLOR_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetColor__12CSceneObjSeqFPfi);
void CSceneObjSeq::ScaleDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextScaleSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_SCALE_DELAY;
        command->frame = frames;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/sceneseq", SetScale__12CSceneObjSeqFPfi);
void CSceneObjSeq::SeDelay(s32 frames) {
    _SEN_OBJ_SEQ *command = SearchNextSeSeq();
    if (command != NULL) {
        if (frames > 0) {
            frames = (frames * 50) / 60;
            if (frames <= 0) {
                frames = 1;
            }
        }
        command->cmd = SCENE_OBJ_CMD_SE_DELAY;
        command->frame = frames;
    }
}
void CSceneObjSeq::SePlay(s32 sound_id, s32 sound_no) {
    _SEN_OBJ_SEQ *command = SearchNextSeSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_SE_PLAY;
        command->no = sound_id;
        command->se_no = sound_no;
    }
}
void CSceneObjSeq::ResetDAPosition(void) {
    _SEN_OBJ_SEQ *command = SearchNextSeSeq();
    if (command != NULL) {
        command->cmd = SCENE_OBJ_CMD_RESET_DA_POSITION;
    }
    _SEN_OBJ_SEQ *motion_command = SearchNextMotSeq();
    if (motion_command != NULL) {
        motion_command->cmd = SCENE_OBJ_CMD_RESET_DA_POSITION;
    }
}

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", ScsCmrSeqCallTbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", ScsObjSeqCallTbl__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", at_1527__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/sceneseq", at_2863__DATA);
