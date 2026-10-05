#include "common.h"
#include "effscript.hpp"
#include <cstring>
#include <cstdio>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", Initialize__16CEffectScriptManFP9mgCMemoryii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetWorkBuffer__16CEffectScriptManFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SearchBaseNo__16CEffectScriptManFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", LoadBaseEffSpt__16CEffectScriptManFiP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", LoadBaseEffSpt__16CEffectScriptManFPcP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", ClearBaseFromLevel__16CEffectScriptManFiPii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetBaseChara__16CEffectScriptManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetBaseChara__16CEffectScriptManFPc);
s32 CEffectScriptMan::GetNotUsedTexb(void) {
    s32 used = texb_used;
    if (used >= texb_num) {
        return -1;
    }
    return texb_start + used;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", AddTexb__16CEffectScriptManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", BuildBase__16CEffectScriptManFiP1iP1iP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", BuildBase__16CEffectScriptManFPcP1iP1iP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", BuildPack__16CEffectScriptManFiPUiP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", BuildPack__16CEffectScriptManFPcPUiP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetNeedFilePath__16CEffectScriptManFiPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetNeedFilePath__16CEffectScriptManFPcPcPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", CreateEffSpt__16CEffectScriptManFiii);
s32 CEffectScriptMan::CreateEffSpt(char *name, s32 user_id, s32 use_slot) {
    _EFF_SCRIPT *effect = CreateEffSpt(SearchBaseNo(name), user_id, use_slot);
    if (effect != NULL) {
        return effect->slot;
    }
    return -1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", ClearEffectFromChrid__16CEffectScriptManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", ClearEffectFromLevel__16CEffectScriptManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", DeleteEffSpt__16CEffectScriptManFP11_EFF_SCRIPT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", DeleteEffSpt__16CEffectScriptManFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", AllClearEffSpt__16CEffectScriptManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", Step__16CEffectScriptManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", Draw__16CEffectScriptManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", AssignSprite__16CEffectScriptManFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", DeleteSprite__16CEffectScriptManFP10_ES_SPRITE);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", AssignCharacter__16CEffectScriptManFP11_EFF_SCRIPTi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetScriptProgNo__16CEffectScriptManFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", Pause__16CEffectScriptManFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", PauseFromLevel__16CEffectScriptManFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetScriptVect1__16CEffectScriptManFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetScriptVect1__16CEffectScriptManFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetScriptVect2__16CEffectScriptManFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetScriptVect2__16CEffectScriptManFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetScriptTargetId__16CEffectScriptManFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetScriptTargetId__16CEffectScriptManFRiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetScriptUserId__16CEffectScriptManFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetScriptUserId__16CEffectScriptManFRiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetColPrim__16CEffectScriptManFP8CColPrimii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetValue__16CEffectScriptManFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetValue__16CEffectScriptManFifii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetOrigin__16CEffectScriptManFPfii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetCharacter__16CEffectScriptManFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetCharacter__16CEffectScriptManFP11CCharacter2ii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetTexb__16CEffectScriptManFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetEffSptBaseDefPtr__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", DrawEffSptSprite__FP11_EFF_SCRIPTP10mgCTexturePfP11mgC3DSpriteP16CMapLightingInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetSpritePtr__FP11_EFF_SCRIPTi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetStackInt__FP12RS_STACKDATA__4);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetStackFloat__FP12RS_STACKDATA__4);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetStackVector__FPfP12RS_STACKDATA__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", GetStackString__FP12RS_STACKDATA__4);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetStack__FP12RS_STACKDATAi__4);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetStack__FP12RS_STACKDATAf__4);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ZERO_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _NORMAL_VECTOR__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COPY_VECTOR__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ADD_VECTOR__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SUB_VECTOR__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCALE_VECTOR__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _DIV_VECTOR__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _DIST_VECTOR__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _DIST_VECTOR2__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SQRT__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ATAN2F__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ANGLE_CMP__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ANGLE_LIMIT__FP12RS_STACKDATAi__3);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_RAND__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_REF_ROT__FP12RS_STACKDATAi__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_DIR_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SET_ORIGIN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_ORIGIN__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _AUTO_SET_OFFSET__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_WORK_VECT1__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_WORK_VECT2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_TARGET_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_USER_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SET_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_MOTION__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_MOT_STEP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_MOT_WAIT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_DIR_VECTOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_REF_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_ADD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_ADD_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_ADD_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_COPY_CHARA__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_POS2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_ROT2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_SCALE2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_MOTION2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_ADD_POS2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_ADD_ROT2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_ADD_SCALE2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_SHOW2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_GET_FRAME_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_FRAME_SHOW__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_CHK_MOT_END__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CHR_SET_LIGHT_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_ASSIGN_SPRITE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_DELETE_SPRITE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_TEXNAME__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_ALPHAB__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_INIT_SPRITE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_DRAW_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_GET_DRAW_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_UV_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_PUT_SIZE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_GET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_GET_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_GET_SCALE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_GET_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_VAN_SET_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_VAN_SET_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_VAN_SET_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_VAN_SET_SCL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_ADD_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_ADD_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_ADD_COLOR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_WORLD_ROT__FP12RS_STACKDATAi);
s32 _SPT_SET_LIFE(RS_STACKDATA *stack, int argument_count) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_VELO_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_ACC_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_VELO_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_ACC_ROTZ__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_VELO_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_ACC_COL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_BLINKING__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_VELO_SCL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SET_ACC_SCL__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_SCALE_CONV__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SPT_COLOR_CONV__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_CHR_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_CHR_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_CHR_FRM_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_CHR_FRM_DIR__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_CHR_FRM_ROT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_ENTRY_OBJ_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _INTERSECTION_POINT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _MON_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _MON_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _BTL_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _BTL_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _BSE_SE_PLAY__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _BSE_SE_STOP__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _MON_SE_PLAY2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _MON_SE_STOP2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SET_LIGHT_FLAG__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _SCN_GET_CHR_ENTOBJ_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _CREATE_DAMAGE__FP12RS_STACKDATAi);
s32 _DELETE_DAMAGE(RS_STACKDATA *stack, int argument_count) {
    return 0;
}
s32 _DMG_SET_POS(RS_STACKDATA *stack, int argument_count) {
    return 0;
}
s32 _DMG_SET_FRONT_VECT(RS_STACKDATA *stack, int argument_count) {
    return 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _DMG_SET_DAMAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_CREATE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_SET_COORD__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_DELETE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_GET_HITCNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_GET_GIFT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_GET_REVCNT__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_SET_DAMAGE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _COLPRIM_GET_HIT_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ES_CREATE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ES_SET_VECT1__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ES_SET_VECT2__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ES_SET_TARGET_ID__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ES_SET_VALUE__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _ES_SET_COLPRIM__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", _GET_EOH_POS__FP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetEffectScript__FP10CRunScriptPcP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effscript", SetEffectScriptFunc__Fv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", eff_spt_base_def__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_2311__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_2498__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", ext_func_info__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_943__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1099__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1100__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1101__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1102__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1103__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1104__7__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1127__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1128__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1129__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1143__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1144__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1145__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1336__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1337__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1338__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1339__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1340__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1341__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1655__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_1705__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_2025__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3303__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3304__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3398__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3495__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3536__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3644__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effscript", at_3645__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(now_scene, 0x4);
INCLUDE_BSS(EffScriptMan, 0x4);
INCLUDE_BSS(now_script, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(ext_func__4, 0x400);
INCLUDE_BSS(at_2067, 0x10);
