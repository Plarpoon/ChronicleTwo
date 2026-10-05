#include "common.h"
#include "gameutil.hpp"

#include <libvu0.h>

#include <cmath>
#include <cstdio>
#include <cstring>

#include "dng_main.hpp"
#include "font.hpp"
#include "intersection.hpp"
#include "mg_camera.hpp"
#include "mg_frame.hpp"
#include "mg_math.hpp"
#include "mg_memory.hpp"
#include "mg_visual.hpp"
#include "mglib.hpp"

// Trap on division by zero for variable integer divisors.
#pragma divbyzerocheck on

#ifdef NONMATCHING
/**
 *
 * Skinned frame whose bone matrices MotionProc2 and MotionProc3 last set up.
 *
 */
static mgCFrame *OldSkinFrame;

/**
 *
 * Skinned-vertex accumulator of the frame being skinned; w sums the weights.
 *
 */
static sceVu0FVECTOR def_vrtx[800];

/**
 *
 * Skinned-normal accumulator of the frame being skinned.
 *
 */
static sceVu0FVECTOR def_nml[1];
#endif

// Code (.text)
#ifdef NONMATCHING
/**
 *
 * Interpolates between two quaternions, stored w first, along the shorter arc.
 *
 */
static void QuatSlerp(float *from, float *to, float t, float *out) {
    float cosine;
    float angle;
    float inv_sine;
    float scale_from;
    float scale_to;

    cosine = from[0] * to[0] + from[3] * to[3] + from[2] * to[2] + from[1] * to[1];

    if (cosine < 0.0f) {
        to[0] = -to[0];
        cosine = -cosine;
        to[1] = -to[1];
        to[2] = -to[2];
        to[3] = -to[3];
    }

    if (cosine < 0.01f) {
        out[1] = to[1];
        out[2] = to[2];
        out[3] = to[3];
        out[0] = to[0];
    } else {
        scale_from = 1.0f - t;
        scale_to = t;

        if (1.0f - cosine > 0.01f) {
            angle = acosf(cosine);
            inv_sine = 1.0f / sinf(angle);
            scale_from = inv_sine * sinf((1.0f - t) * angle);
            scale_to = inv_sine * sinf(t * angle);
        }

        out[1] = scale_to * to[1] + scale_from * from[1];
        out[2] = scale_to * to[2] + scale_from * from[2];
        out[3] = scale_to * to[3] + scale_from * from[3];
        out[0] = scale_to * to[0] + scale_from * from[0];
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", QuatSlerp__FPfPffPf);
#endif

#ifdef NONMATCHING
Mot_List *MotionProc(mgCFrame *root, float time, Mot_List *list, mgCCamera *camera) {
    unsigned int  frame_no = (unsigned int) time;
    int           low = 0;
    int           high = list->key_count;
    int           middle;
    unsigned int  key;
    unsigned int  next;
    unsigned int  key_frame;
    float         t;
    mgCFrame     *frame;
    sceVu0FVECTOR value;
    sceVu0FVECTOR rotation;
    sceVu0FVECTOR from;
    sceVu0FVECTOR to;

    while (low < high) {
        middle = (low + high) >> 1;

        if (list->key_frames[middle] <= frame_no) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    key = low - 1;
    next = low;

    if (next > list->key_count - 1) {
        next = key;
    }

    key_frame = list->key_frames[key];
    t = (time - (float) key_frame) / (float) (list->key_frames[next] - key_frame);
    frame = root->GetFrame(list->frame);

    switch (list->type) {
        case MOTION_KEY_ROTATION:
            sceVu0CopyVector(from, list->values[key]);
            sceVu0CopyVector(to, list->values[next]);

            if (t > 0.001f && t < 0.999f) {
                QuatSlerp(list->values[key], list->values[next], t, rotation);
                frame->SetTransMatrix(rotation);
            } else {
                if (t <= 0.001f) {
                    frame->SetTransMatrix(from);
                }

                if (t >= 0.999f) {
                    frame->SetTransMatrix(to);
                }
            }

            break;
        case MOTION_KEY_SCALE:
            if (t > 0.001f && t < 0.999f) {
                sceVu0InterVectorXYZ(value, list->values[next], list->values[key], t);
            } else {
                if (t <= 0.001f) {
                    sceVu0CopyVectorXYZ(value, list->values[key]);
                }

                if (t >= 0.999f) {
                    sceVu0CopyVectorXYZ(value, list->values[next]);
                }
            }

            frame->SetScale(value[0], value[1], value[2]);
            break;
        case MOTION_KEY_TRANSLATION:
            if (t > 0.001f && t < 0.999f) {
                sceVu0InterVectorXYZ(value, list->values[next], list->values[key], t);
            } else {
                if (t <= 0.001f) {
                    sceVu0CopyVectorXYZ(value, list->values[key]);
                }

                if (t >= 0.999f) {
                    sceVu0CopyVectorXYZ(value, list->values[next]);
                }
            }

            frame->trans_matrix[3][0] = value[0];
            frame->trans_matrix[3][1] = value[1];
            frame->trans_matrix[3][2] = value[2];
            frame->changed = 1;
            break;
        case MOTION_KEY_VERTEX: {
            sceVu0FVECTOR *vertices = ((mgCVisualMDT *) frame->visual)->vertex;
            int            driven = list->frame;

            if (t > 0.001f && t < 0.999f) {
                while (driven == list->frame) {
                    sceVu0InterVectorXYZ(value, list->values[next], list->values[key], t);
                    sceVu0CopyVectorXYZ(vertices[list->target - 1], value);
                    list = list->next;

                    if (list == NULL) {
                        return NULL;
                    }
                }

                return list;
            }

            if (t <= 0.001f) {
                while (driven == list->frame) {
                    sceVu0CopyVectorXYZ(vertices[list->target - 1], list->values[key]);
                    list = list->next;

                    if (list == NULL) {
                        return NULL;
                    }
                }
            }

            if (t < 0.999f) {
                return list;
            }

            while (driven == list->frame) {
                sceVu0CopyVectorXYZ(vertices[list->target - 1], list->values[next]);
                list = list->next;

                if (list == NULL) {
                    return NULL;
                }
            }

            return list;
        }
        case MOTION_KEY_CAMERA_POSITION:
            if (camera != NULL) {
                sceVu0InterVectorXYZ(value, list->values[next], list->values[key], t);
                root->GetWorldPosition(value, value);
                camera->SetPos(value[0], value[1], value[2]);
            }

            break;
        case MOTION_KEY_CAMERA_TARGET:
            // The look-at position is never interpolated from the keys here.
            if (camera != NULL) {
                root->GetWorldPosition(value, value);
                camera->SetRef(value[0], value[1], value[2]);
            }

            break;
        case MOTION_KEY_MATERIAL_ALPHA: {
            float       one_minus_t = 1.0f - t;
            mgMaterial *materials = frame->visual->GetpMaterial();

            materials[list->target].diffuse[3] = 1.0f - (t * list->values[next][0] + one_minus_t * list->values[key][0]);
            break;
        }
        case MOTION_KEY_MATERIAL_COLOR: {
            mgMaterial *materials = frame->visual->GetpMaterial();

            sceVu0InterVectorXYZ(materials[list->target].diffuse, list->values[next], list->values[key], t);
            frame->attr->unk_28 = 2;
            break;
        }
        case MOTION_KEY_CAMERA_ROLL:
            if (camera != NULL) {
                camera->SetRoll(-((t * list->values[next][0] + (1.0f - t) * list->values[key][0]) / 180.0f * 3.1415927f));
            }

            break;
        case MOTION_KEY_CAMERA_FOV:
            if (camera != NULL) {
                mgSetProjection(1.0f / tanf((t * list->values[next][0] + (1.0f - t) * list->values[key][0]) * 0.5f / 180.0f * 3.1415927f) * 480.0f * 0.5f);
            }

            break;
        case MOTION_KEY_VISIBLE:
            if (list->values[key][0] < 1.0f) {
                frame->attr->draw = 0;
            } else {
                frame->attr->draw = MG_FRAME_DRAW_VISIBLE | MG_FRAME_DRAW_SKIP_CHILDREN;
            }

            break;
        case MOTION_KEY_UNK_33:
            if (list->values[key][0] < 1.0f) {
                frame->attr->draw = MG_FRAME_DRAW_SKIP_CHILDREN;
            } else {
                frame->attr->draw = MG_FRAME_DRAW_VISIBLE;
            }

            break;
    }

    return list->next;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc__FP8mgCFramefP8Mot_ListP9mgCCamera);
#endif

#ifdef NONMATCHING
Mot_List *MotionProc(mgCFrame *root, unsigned int from_frame, unsigned int to_frame, float blend, Mot_List *list, mgCCamera *camera) {
    int           low;
    int           high;
    int           middle;
    int           key;
    int           next;
    mgCFrame     *frame;
    sceVu0FVECTOR value;
    sceVu0FVECTOR rotation;
    sceVu0FVECTOR from;
    sceVu0FVECTOR to;

    low = 0;
    high = list->key_count;

    while (low < high) {
        middle = (low + high) >> 1;

        if (list->key_frames[middle] <= from_frame) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    key = low - 1;
    low = 0;
    high = list->key_count;

    while (low < high) {
        middle = (low + high) >> 1;

        if (list->key_frames[middle] <= to_frame) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    next = low - 1;
    frame = root->GetFrame(list->frame);

    switch (list->type) {
        case MOTION_KEY_ROTATION:
            sceVu0CopyVector(from, list->values[key]);
            sceVu0CopyVector(to, list->values[next]);

            if (blend > 0.0001f && blend < 0.9999f) {
                QuatSlerp(from, to, blend, rotation);
                frame->SetTransMatrix(rotation);
            } else {
                if (blend <= 0.0001f) {
                    frame->SetTransMatrix(from);
                }

                if (blend >= 0.9999f) {
                    frame->SetTransMatrix(to);
                }
            }

            break;
        case MOTION_KEY_SCALE:
            sceVu0InterVectorXYZ(value, list->values[next], list->values[key], blend);
            frame->SetScale(value[0], value[1], value[2]);
            break;
        case MOTION_KEY_TRANSLATION:
            sceVu0InterVectorXYZ(value, list->values[next], list->values[key], blend);
            frame->trans_matrix[3][0] = value[0];
            frame->trans_matrix[3][1] = value[1];
            frame->trans_matrix[3][2] = value[2];
            frame->changed = 1;
            break;
        case MOTION_KEY_VERTEX: {
            sceVu0FVECTOR *vertices = ((mgCVisualMDT *) frame->visual)->vertex;
            int            driven = list->frame;

            if (blend > 0.0001f && blend < 0.9999f) {
                while (driven == list->frame) {
                    sceVu0InterVectorXYZ(value, list->values[next], list->values[key], blend);
                    sceVu0CopyVectorXYZ(vertices[list->target - 1], value);
                    list = list->next;

                    if (list == NULL) {
                        return NULL;
                    }
                }

                return list;
            }

            if (blend <= 0.0001f) {
                while (driven == list->frame) {
                    sceVu0CopyVectorXYZ(vertices[list->target - 1], list->values[key]);
                    list = list->next;

                    if (list == NULL) {
                        return NULL;
                    }
                }
            }

            if (blend < 0.9999f) {
                return list;
            }

            while (driven == list->frame) {
                sceVu0CopyVectorXYZ(vertices[list->target - 1], list->values[next]);
                list = list->next;

                if (list == NULL) {
                    return NULL;
                }
            }

            return list;
        }
        case MOTION_KEY_CAMERA_POSITION:
            if (camera != NULL) {
                sceVu0InterVectorXYZ(value, list->values[next], list->values[key], blend);
                root->GetWorldPosition(value, value);
                camera->SetPos(value[0], value[1], value[2]);
            }

            break;
        case MOTION_KEY_CAMERA_TARGET:
            if (camera != NULL) {
                sceVu0InterVectorXYZ(value, list->values[next], list->values[key], blend);
                root->GetWorldPosition(value, value);
                camera->SetRef(value[0], value[1], value[2]);
            }

            break;
        case MOTION_KEY_MATERIAL_ALPHA: {
            float       one_minus_blend = 1.0f - blend;
            mgMaterial *materials = frame->visual->GetpMaterial();

            materials[list->target].diffuse[3] = 1.0f - (blend * list->values[next][0] + one_minus_blend * list->values[key][0]);
            frame->attr->unk_28 = 2;
            break;
        }
        case MOTION_KEY_MATERIAL_COLOR: {
            mgMaterial *materials = frame->visual->GetpMaterial();

            sceVu0InterVectorXYZ(materials[list->target].diffuse, list->values[next], list->values[key], blend);
            frame->attr->unk_28 = 2;
            break;
        }
        case MOTION_KEY_CAMERA_ROLL:
            if (camera != NULL) {
                camera->SetRoll(-((blend * list->values[next][0] + (1.0f - blend) * list->values[key][0]) / 180.0f * 3.1415927f));
            }

            break;
        case MOTION_KEY_CAMERA_FOV:
            if (camera != NULL) {
                mgSetProjection(1.0f / tanf((blend * list->values[next][0] + (1.0f - blend) * list->values[key][0]) * 0.5f / 180.0f * 3.1415927f) * 480.0f * 0.5f);
            }

            break;
        case MOTION_KEY_VISIBLE:
            if (list->values[key][0] < 1.0f) {
                frame->attr->draw = 0;
            } else {
                frame->attr->draw = MG_FRAME_DRAW_VISIBLE | MG_FRAME_DRAW_SKIP_CHILDREN;
            }

            break;
        case MOTION_KEY_UNK_33:
            if (list->values[key][0] < 1.0f) {
                frame->attr->draw = MG_FRAME_DRAW_SKIP_CHILDREN;
            } else {
                frame->attr->draw = MG_FRAME_DRAW_VISIBLE;
            }

            break;
    }

    return list->next;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc__FP8mgCFrameUiUifP8Mot_ListP9mgCCamera);
#endif

#ifdef NONMATCHING
/**
 *
 * Adds a vertex moved by a bone matrix and scaled by its weight to an accumulated vertex, and writes the sum to both the accumulator and an output vertex.
 *
 */
static void testVUnew(float (*matrix)[4], float *vertex, float *weight, float *accum, float *out) {
    sceVu0FVECTOR moved;
    int           i;

    for (i = 0; i < 4; i++) {
        moved[i] = matrix[0][i] * vertex[0] + matrix[1][i] * vertex[1] + matrix[2][i] * vertex[2] + matrix[3][i] * vertex[3];
    }

    // Only xyz are weighted; w gains the third matrix row's w.
    accum[0] += moved[0] * weight[0];
    accum[1] += moved[1] * weight[0];
    accum[2] += moved[2] * weight[0];
    accum[3] += matrix[2][3];
    out[0] = accum[0];
    out[1] = accum[1];
    out[2] = accum[2];
    out[3] = accum[3];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", testVUnew__FPA4_fPfPfPfPf);
#endif

#ifdef NONMATCHING
Mot_List *MotionProc2(mgCFrame *root, tagMOTION_TYPE *motion, tagFRAME_INF *frame_info, Mot_List *list) {
    static sceVu0FVECTOR *vert;
    static sceVu0FMATRIX  tmp_SkinMatrix;
    static sceVu0FMATRIX  tmp_SkinMatrix_inv;
    static sceVu0FMATRIX  tmp_ChrMatrix;
    static sceVu0FMATRIX  tmp_BaseSkinMatrix;
    static sceVu0FMATRIX  tmp_BaseSkinMatrix_inv;
    mgCFrame             *bone;
    mgCFrame             *skin;
    tagFRAME_INF         *info;
    sceVu0FMATRIX         bone_matrix;
    sceVu0FMATRIX         bone_base;
    sceVu0FMATRIX         bone_in_skin;
    sceVu0FMATRIX         bone_in_skin_inv;
    sceVu0FMATRIX         skin_bone;
    sceVu0FMATRIX         deform;
    sceVu0FVECTOR         moved;
    sceVu0FVECTOR         weight;
    unsigned int          i;
    int                   vertex;

    if (list->key_count == 0) {
        return list->next;
    }

    bone = root->GetFrame(list->target);
    skin = root->GetFrame(list->frame);
    info = &frame_info[list->frame];

    if (OldSkinFrame != skin) {
        OldSkinFrame = root->GetFrame(list->frame);
        vert = ((mgCVisualMDT *) skin->visual)->vertex;

        for (vertex = 0; vertex < (int) info->vertex_count; vertex++) {
            def_vrtx[vertex][0] = 0.0f;
            def_vrtx[vertex][1] = 0.0f;
            def_vrtx[vertex][2] = 0.0f;
            def_vrtx[vertex][3] = 1.0f;
        }

        skin->GetLWMatrix(tmp_SkinMatrix);
        root->GetLWMatrix(tmp_ChrMatrix);
        mgInversMatrix(tmp_SkinMatrix_inv, tmp_SkinMatrix);
        mgMulMatrix(tmp_BaseSkinMatrix, tmp_ChrMatrix, motion->base_matrices[list->frame]);
        mgInversMatrix(tmp_BaseSkinMatrix_inv, tmp_BaseSkinMatrix);
    }

    sceVu0UnitMatrix(bone_matrix);
    sceVu0UnitMatrix(tmp_SkinMatrix);
    bone->GetLWMatrix(bone_matrix);
    mgMulMatrix(bone_base, tmp_ChrMatrix, motion->base_matrices[list->target]);
    mgMulMatrix(bone_in_skin, tmp_BaseSkinMatrix_inv, bone_base);
    mgInversMatrix(bone_in_skin_inv, bone_in_skin);
    mgMulMatrix(skin_bone, tmp_SkinMatrix_inv, bone_matrix);
    mgMulMatrix(deform, skin_bone, bone_in_skin_inv);

    for (i = 0; i < list->key_count; i++) {
        weight[0] = list->values[i][0] * 0.01f;
        vertex = list->key_frames[i];

        if (list->type == MOTION_KEY_SKIN_WEIGHTED) {
            testVUnew(deform, info->base_vertices[vertex], weight, def_vrtx[vertex], vert[vertex]);
        } else {
            sceVu0ApplyMatrix(moved, deform, info->base_vertices[vertex]);
            moved[3] = 0.0f;
            def_vrtx[vertex][0] += moved[0];
            def_vrtx[vertex][1] += moved[1];
            def_vrtx[vertex][2] += moved[2];
            def_vrtx[vertex][0] /= def_vrtx[vertex][3];
            def_vrtx[vertex][1] /= def_vrtx[vertex][3];
            def_vrtx[vertex][2] /= def_vrtx[vertex][3];
            sceVu0CopyVectorXYZ(vert[vertex], def_vrtx[vertex]);
            def_vrtx[vertex][3] += 1.0f;
        }
    }

    return list->next;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc2__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
#endif

#ifdef NONMATCHING
Mot_List *MotionProc3(mgCFrame *root, tagMOTION_TYPE *motion, tagFRAME_INF *frame_info, Mot_List *list) {
    static sceVu0FVECTOR *vert;
    static sceVu0FVECTOR *nml;
    static sceVu0FMATRIX  tmp_SkinMatrix;
    static sceVu0FMATRIX  tmp_SkinMatrix_inv;
    static sceVu0FMATRIX  tmp_ChrMatrix;
    static sceVu0FMATRIX  tmp_BaseSkinMatrix;
    static sceVu0FMATRIX  tmp_BaseSkinMatrix_inv;
    mgCFrame             *bone;
    mgCFrame             *skin;
    tagFRAME_INF         *info;
    sceVu0FMATRIX         bone_matrix;
    sceVu0FMATRIX         bone_base;
    sceVu0FMATRIX         bone_in_skin;
    sceVu0FMATRIX         bone_in_skin_inv;
    sceVu0FMATRIX         skin_bone;
    sceVu0FMATRIX         deform;
    sceVu0FMATRIX         rotate;
    sceVu0FVECTOR         normal;
    unsigned int          i;
    int                   vertex;

    if (list->type != MOTION_KEY_SKIN_WEIGHTED) {
        return list->next;
    }

    bone = root->GetFrame(list->target);
    skin = root->GetFrame(list->frame);
    info = &frame_info[list->frame];

    if (OldSkinFrame != skin) {
        OldSkinFrame = root->GetFrame(list->frame);
        vert = ((mgCVisualMDT *) skin->visual)->vertex;
        nml = ((mgCVisualMDT *) skin->visual)->normal;

        if (info->vertex_count > 400) {
            printf("###### MAX_VERTX OVER %d/%d######\n", info->vertex_count, 400);
        }

        if (info->normal_count > 800) {
            printf("###### MAX_NORMAL OVER %d/%d######\n", info->normal_count, 800);
        }

        for (i = 0; i < info->vertex_count; i++) {
            def_vrtx[i][0] = 0.0f;
            def_vrtx[i][1] = 0.0f;
            def_vrtx[i][2] = 0.0f;
            def_vrtx[i][3] = 1.0f;
        }

        for (i = 0; i < info->normal_count; i++) {
            def_nml[i][0] = 0.0f;
            def_nml[i][1] = 0.0f;
            def_nml[i][2] = 0.0f;
            def_nml[i][3] = 1.0f;
        }

        skin->attr->unk_28 = 1;
        skin->GetLWMatrix(tmp_SkinMatrix);
        root->GetLWMatrix(tmp_ChrMatrix);
        sceVu0InversMatrix(tmp_SkinMatrix_inv, tmp_SkinMatrix);
        mgMulMatrix(tmp_BaseSkinMatrix, tmp_ChrMatrix, motion->base_matrices[list->frame]);
        mgInversMatrix(tmp_BaseSkinMatrix_inv, tmp_BaseSkinMatrix);
    }

    sceVu0UnitMatrix(bone_matrix);
    sceVu0UnitMatrix(tmp_SkinMatrix);
    bone->GetLWMatrix(bone_matrix);
    mgMulMatrix(bone_base, tmp_ChrMatrix, motion->base_matrices[list->target]);
    mgMulMatrix(bone_in_skin, tmp_BaseSkinMatrix_inv, bone_base);
    mgInversMatrix(bone_in_skin_inv, bone_in_skin);
    mgMulMatrix(skin_bone, tmp_SkinMatrix_inv, bone_matrix);
    mgMulMatrix(deform, skin_bone, bone_in_skin_inv);

    // Normals turn with the bone but do not move with it.
    sceVu0CopyMatrix(rotate, deform);
    rotate[3][0] = 0.0f;
    rotate[3][1] = 0.0f;
    rotate[3][2] = 0.0f;

    for (i = 0; i < list->key_count; i++) {
        sceVu0FVECTOR weight = {0.0f, 0.0f, 0.0f, 0.0f};

        weight[0] = list->values[i][0] * 0.01f;

        if (weight[0] > 0.0f) {
            vertex = list->key_frames[i];
            testVUnew(deform, info->base_vertices[vertex], weight, def_vrtx[vertex], vert[vertex]);
            sceVu0ApplyMatrix(normal, rotate, info->base_normals[vertex]);
            sceVu0InterVectorXYZ(nml[vertex], normal, info->base_normals[vertex], weight[0]);
        }
    }

    return list->next;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MotionProc3__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFP8Mot_List);
#endif

void SetMotionTime(mgCFrame *root, tagMOTION_TYPE *motion, float time, mgCCamera *camera) {
    Mot_List *list;

    for (list = motion->motion_list; list != NULL;) {
        list = MotionProc(root, time, list, camera);
    }
}

void ChangeMotion(mgCFrame *root, tagMOTION_TYPE *motion, unsigned int from_frame, unsigned int to_frame, float blend, mgCCamera *camera) {
    Mot_List *list;

    for (list = motion->motion_list; list != NULL;) {
        list = MotionProc(root, from_frame, to_frame, blend, list, camera);
    }
}

#ifdef NONMATCHING
void DeformMesh(mgCFrame *root, tagMOTION_TYPE *motion, tagFRAME_INF *frame_info, bool with_normals) {
    Mot_List *list = motion->skin_list;

    if (with_normals) {
        while (list != NULL) {
            list = MotionProc3(root, motion, frame_info, list);
        }
    } else {
        while (list != NULL) {
            list = MotionProc2(root, motion, frame_info, list);
        }
    }

    OldSkinFrame = NULL;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", DeformMesh__FP8mgCFrameP14tagMOTION_TYPEP12tagFRAME_INFb);
#endif

#ifdef NONMATCHING
/**
 *
 * Allocates a key list's values and key frames and fills them from the keys of a motion file.
 *
 */
static void SetKeyFrame(Mot_List *list, FRAME_VECTOR_EX_DATA *keys, mgCMemory *memory) {
    unsigned int i;

    list->values = (sceVu0FVECTOR *) memory->Alloc(list->key_count * sizeof(sceVu0FVECTOR) / 16 + 1);
    list->key_frames = (u32 *) memory->Alloc(list->key_count * sizeof(u32) / 16 + 1);

    for (i = 0; i < list->key_count; i++) {
        list->values[i][0] = keys->value[0];
        list->values[i][1] = keys->value[1];
        list->values[i][2] = keys->value[2];
        list->values[i][3] = keys->value[3];
        list->key_frames[i] = keys->frame;
        keys++;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", SetKeyFrame__FP8Mot_ListP20FRAME_VECTOR_EX_DATAP9mgCMemory);
#endif

#ifdef NONMATCHING
void ChangeWeight(Mot_List *list, mgCMemory *memory, unsigned char *file, int frame, tagFRAME_INF *frame_info, mgCVisualMDT *visual, mgCFrame *root, mgCFrame *skin_root) {
    Mot_List      *last;
    Mot_List      *node;
    Mot_List      *built;
    Mot_List      *reversed;
    Mot_List      *following;
    Mot_File_List *header;
    tagFRAME_INF  *info;
    mgFACE_GROUP  *group;
    mgCFace       *face;
    int            i;

    // Unlink the frame's old key lists, leaving last on the final list that remains.
    last = list;

    for (node = list; node != NULL; node = node->next) {
        if (frame == node->frame) {
            last->next = node->next;
        } else {
            last = node;
        }
    }

    built = NULL;

    do {
        header = (Mot_File_List *) file;
        node = (Mot_List *) memory->Alloc(sizeof(Mot_List) / 16 + 1);
        node->frame = frame;
        node->target = root->SearchFrameID(skin_root->GetFrame(header->target)->name);
        node->key_count = header->key_count;
        node->type = header->type;
        SetKeyFrame(node, (FRAME_VECTOR_EX_DATA *) (header + 1), memory);

        if (built == NULL) {
            node->next = NULL;
        } else {
            node->next = built;
        }

        built = node;
        file = (unsigned char *) ((FRAME_VECTOR_EX_DATA *) (header + 1) + node->key_count);
    } while (header->more != 0);

    reversed = NULL;

    while (built != NULL) {
        following = built->next;
        built->next = reversed;
        reversed = built;
        built = following;
    }

    last->next = reversed;

    if (visual != NULL) {
        sceVu0FVECTOR *vertices = visual->vertex;
        sceVu0FVECTOR *normals = visual->normal;

        info = &frame_info[frame];
        info->base_vertices = (sceVu0FVECTOR *) memory->Alloc(visual->vertex_num * sizeof(sceVu0FVECTOR) / 16 + 1);
        info->base_normals = (sceVu0FVECTOR *) memory->Alloc(visual->normal_num * sizeof(sceVu0FVECTOR) / 16 + 1);
        info->vertex_refs = (s32(*)[12]) memory->Alloc(visual->vertex_num * sizeof(*info->vertex_refs) / 16 + 1);
        info->vertex_count = visual->vertex_num;
        info->normal_count = visual->normal_num;
        memcpy(info->base_vertices, vertices, visual->vertex_num * sizeof(sceVu0FVECTOR));
        memcpy(info->base_normals, normals, visual->normal_num * sizeof(sceVu0FVECTOR));

        for (i = 0; i < visual->vertex_num; i++) {
            info->vertex_refs[i][0] = 0;
        }

        for (group = visual->face_group; group != NULL; group = group->next) {
            for (face = group->face; face != NULL; face = face->next) {
                int  index;
                int *refs;

                if (group->face->type & MG_FACE_NO_NORMAL) {
                    break;
                }

                for (index = 0; index < face->index_num; index += face->index_stride) {
                    refs = info->vertex_refs[face->index[index]];
                    refs[refs[0] + 1] = face->index[index + 1];
                    refs[0]++;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", ChangeWeight__FP8Mot_ListP9mgCMemoryPUciP12tagFRAME_INFP12mgCVisualMDTP8mgCFrameP8mgCFrame);
#endif

#ifdef NONMATCHING
int CreateAnimeDataEX(tagMOTION_TYPE *motion, mgCMemory *memory, MOTION_FILE_INFO *files) {
    FRAME_VECTOR_EX_DATA *data;
    Mot_File_List        *header;
    Mot_List             *list;
    Mot_List             *reversed;
    Mot_List             *node;

    if (files[0].name != NULL) {
        motion->base_matrices = (sceVu0FMATRIX *) memory->Alloc(files[0].size / 16 + 1);
        memcpy(motion->base_matrices, files[0].data, files[0].size);
    }

    if (files[1].name != NULL) {
        data = (FRAME_VECTOR_EX_DATA *) files[1].data;
        motion->motion_list = NULL;

        do {
            header = (Mot_File_List *) data;
            list = (Mot_List *) memory->Alloc(sizeof(Mot_List) / 16 + 1);
            list->frame = header->frame;
            list->target = header->target;
            list->key_count = header->key_count;
            list->type = header->type;
            SetKeyFrame(list, &data[1], memory);

            if (motion->motion_list == NULL) {
                list->next = NULL;
            } else {
                list->next = motion->motion_list;
            }

            motion->motion_list = list;
            data = &data[list->key_count + 1];
        } while (header->more != 0);

        reversed = NULL;

        while ((node = motion->motion_list) != NULL) {
            motion->motion_list = node->next;
            node->next = reversed;
            reversed = node;
        }

        motion->motion_list = reversed;
    }

    if (files[2].name != NULL) {
        data = (FRAME_VECTOR_EX_DATA *) files[2].data;
        motion->skin_list = NULL;

        do {
            header = (Mot_File_List *) data;
            list = (Mot_List *) memory->Alloc(sizeof(Mot_List) / 16 + 1);
            list->frame = header->frame;
            list->target = header->target;
            list->key_count = header->key_count;
            list->type = header->type;
            SetKeyFrame(list, &data[1], memory);

            if (motion->skin_list == NULL) {
                list->next = NULL;
            } else {
                list->next = motion->skin_list;
            }

            motion->skin_list = list;
            data = &data[list->key_count + 1];
        } while (header->more != 0);

        reversed = NULL;

        while ((node = motion->skin_list) != NULL) {
            motion->skin_list = node->next;
            node->next = reversed;
            reversed = node;
        }

        motion->skin_list = reversed;
    }

    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CreateAnimeDataEX__FP14tagMOTION_TYPEP9mgCMemoryP16MOTION_FILE_INFO);
#endif

void AnimeDataInit(mgCFrame *root, tagMOTION_TYPE *motion, mgCMemory *memory, tagFRAME_INF **frame_info) {
    *frame_info = (tagFRAME_INF *) memory->stAlloc64((root->GetFrameNum() + 10) * sizeof(tagFRAME_INF) / 16 + 1);
    AnimeDataInit(root, motion, memory, *frame_info);
}

#ifdef NONMATCHING
int AnimeDataInit(mgCFrame *root, tagMOTION_TYPE *motion, mgCMemory *memory, tagFRAME_INF *frame_info) {
    Mot_List     *list = motion->skin_list;
    int           count = root->GetFrameNum();
    int           i;
    mgCFrame     *skin;
    mgCVisualMDT *visual;
    tagFRAME_INF *info;
    mgFACE_GROUP *group;
    mgCFace      *face;

    for (i = 0; i < count; i++) {
        mgCFrame *frame = root->GetFrame(i);

        frame_info[i].parent = frame->parent - root;
        frame_info[i].vertex_count = 0;
        frame_info[i].normal_count = 0;
    }

    for (; list != NULL; list = list->next) {
        if (list->type != MOTION_KEY_SKIN_WEIGHTED && list->type != MOTION_KEY_SKIN_AVERAGED) {
            continue;
        }

        root->GetFrame(list->target);
        skin = root->GetFrame(list->frame);
        info = &frame_info[list->frame];

        // A frame's skinning data is built once, from the first key list that skins it.
        if (info->vertex_count != 0 || skin == NULL || skin->visual == NULL) {
            continue;
        }

        visual = (mgCVisualMDT *) skin->visual;

        {
            sceVu0FVECTOR *vertices = visual->vertex;
            sceVu0FVECTOR *normals = visual->normal;

            info->base_vertices = (sceVu0FVECTOR *) memory->Alloc(visual->vertex_num * sizeof(sceVu0FVECTOR) / 16 + 1);
            info->base_normals = (sceVu0FVECTOR *) memory->Alloc(visual->normal_num * sizeof(sceVu0FVECTOR) / 16 + 1);
            info->vertex_refs = (s32(*)[12]) memory->Alloc(visual->vertex_num * sizeof(*info->vertex_refs) / 16 + 1);
            info->vertex_count = visual->vertex_num;
            info->normal_count = visual->normal_num;
            memcpy(info->base_vertices, vertices, visual->vertex_num * sizeof(sceVu0FVECTOR));
            memcpy(info->base_normals, normals, visual->normal_num * sizeof(sceVu0FVECTOR));
        }

        for (i = 0; i < visual->vertex_num; i++) {
            info->vertex_refs[i][0] = 0;
        }

        for (group = visual->face_group; group != NULL; group = group->next) {
            for (face = group->face; face != NULL; face = face->next) {
                int  index;
                int *refs;

                if (group->face->type & MG_FACE_NO_NORMAL) {
                    break;
                }

                for (index = 0; index < face->index_num; index += face->index_stride) {
                    refs = info->vertex_refs[face->index[index]];
                    refs[refs[0] + 1] = face->index[index + 1];
                    refs[0]++;
                }
            }
        }
    }

    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", AnimeDataInit__FP8mgCFrameP14tagMOTION_TYPEP9mgCMemoryP12tagFRAME_INF);
#endif

int CheckHit(CCPoly *polys, int count, float *from, float *to, float *hit_point, int nearest, int ignore_mask) {
    CollisionInfo info;

    info.unk_08 = 0;
    info.unk_0C = 0;
    info.count = count;
    info.polys = polys;
    return CheckHit(&info, from, to, hit_point, nearest, ignore_mask);
}

#ifdef NONMATCHING
int CheckHit(CollisionInfo *info, float *from, float *to, float *hit_point, int nearest, int ignore_mask) {
    sceVu0FVECTOR point;
    sceVu0FVECTOR diff;
    sceVu0FVECTOR poly_max;
    sceVu0FVECTOR poly_min;
    sceVu0FVECTOR line_max;
    sceVu0FVECTOR line_min;
    sceVu0FVECTOR offset;
    CCPoly       *poly;
    int           count;
    int           i;
    int           hit;
    int           found;
    float         best;
    float         from_side;
    float         to_side;
    float         dist;

    if (info == NULL) {
        return 0;
    }

    hit = -1;
    found = 0;
    mgVectorMaxMin(line_max, line_min, from, to);
    poly = info->polys;
    count = info->count;

    if (poly == NULL || count == 0) {
        return -1;
    }

    for (i = 0; i < count; i++, poly++) {
        if (poly->ignore_mask & ignore_mask) {
            continue;
        }

        mgVectorMaxMin(poly_max, poly_min, poly->vertex[0], poly->vertex[1], poly->vertex[2]);

        if (poly_min[0] > line_max[0] || poly_min[1] > line_max[1] || poly_min[2] > line_max[2]) {
            continue;
        }

        if (line_min[0] > poly_max[0] || line_min[1] > poly_max[1] || line_min[2] > poly_max[2]) {
            continue;
        }

        sceVu0SubVector(offset, from, poly->vertex[0]);
        from_side = sceVu0InnerProduct(poly->normal, offset);
        sceVu0SubVector(offset, to, poly->vertex[0]);
        to_side = sceVu0InnerProduct(poly->normal, offset);

        if (from_side > 0.0f && to_side > 0.0f) {
            continue;
        }

        if (from_side < 0.0f && to_side < 0.0f) {
            continue;
        }

        if (mgIntersectionPoint_line_poly3(from, to, poly->vertex[0], poly->vertex[1], poly->vertex[2], poly->normal, point) == 0) {
            continue;
        }

        if (nearest == 0) {
            sceVu0CopyVector(hit_point, point);
            return i;
        }

        diff[0] = from[0] - point[0];
        diff[1] = from[1] - point[1];
        diff[2] = from[2] - point[2];
        dist = diff[2] * diff[2] + diff[0] * diff[0] + diff[1] * diff[1];

        if (found == 0) {
            sceVu0CopyVector(hit_point, point);
            best = dist;
            hit = i;
        } else if (dist < best) {
            sceVu0CopyVector(hit_point, point);
            best = dist;
            hit = i;
        }

        found = 1;
    }

    return hit;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHit__FP13CollisionInfoPfPfPfii);
#endif

int CheckHitVertical(CCPoly *polys, int count, float *from, float height, float *hit_point, int ignore_mask) {
    CollisionInfo info;

    info.unk_08 = 0;
    info.unk_0C = 0;
    info.count = count;
    info.polys = polys;
    return CheckHitVertical(&info, from, height, hit_point, ignore_mask);
}

#ifdef NONMATCHING
int CheckHitVertical(CollisionInfo *info, float *from, float height, float *hit_point, int ignore_mask) {
    sceVu0FVECTOR to;
    CCPoly       *poly;
    int           count;
    int           i;
    int           best;
    float         best_y;

    if (info == NULL) {
        return -1;
    }

    to[0] = from[0];
    to[1] = from[1] + height;
    to[2] = from[2];
    poly = info->polys;
    count = info->count;
    best = -1;

    if (poly == NULL || count == 0) {
        return -1;
    }

    for (i = 0; i < count; i++, poly++) {
        if (poly->ignore_mask & ignore_mask) {
            continue;
        }

        if (mgIntersectionPoint_line_poly3(from, to, poly->vertex[0], poly->vertex[1], poly->vertex[2], poly->normal, hit_point) == 0) {
            continue;
        }

        if (height <= 0.0f) {
            // Looking down: keep the highest polygon below the point.
            if (hit_point[1] < from[1] && (best < 0 || (best >= 0 && !(hit_point[1] < best_y)))) {
                best_y = hit_point[1];
                best = i;
            }
        } else {
            // Looking up: keep the lowest polygon above the point.
            if (from[1] < hit_point[1] && (best < 0 || (best >= 0 && !(best_y < hit_point[1])))) {
                best_y = hit_point[1];
                best = i;
            }
        }
    }

    if (best >= 0) {
        hit_point[1] = best_y;
    }

    return best;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitVertical__FP13CollisionInfoPffPfi);
#endif

int CheckHits(CCPoly *polys, int count, float *from, float *to, int max_hits, int *hit_polys, float (*hit_points)[4], int sort, int ignore_mask) {
    CollisionInfo info;

    info.unk_08 = 0;
    info.unk_0C = 0;
    info.count = count;
    info.polys = polys;
    return CheckHits(&info, from, to, max_hits, hit_polys, hit_points, sort, ignore_mask);
}

#ifdef NONMATCHING
int CheckHits(CollisionInfo *info, float *from, float *to, int max_hits, int *hit_polys, float (*hit_points)[4], int sort, int ignore_mask) {
    sceVu0FVECTOR point;
    sceVu0FVECTOR poly_max;
    sceVu0FVECTOR poly_min;
    sceVu0FVECTOR line_max;
    sceVu0FVECTOR line_min;
    sceVu0FVECTOR offset;
    sceVu0FVECTOR swap;
    CCPoly       *poly;
    int           count;
    int           i;
    int           j;
    int           hits;
    float         from_side;
    float         to_side;

    hits = 0;
    mgVectorMaxMin(line_max, line_min, from, to);
    poly = info->polys;
    count = info->count;

    for (i = 0; i < count; i++, poly++) {
        if (poly->ignore_mask & ignore_mask) {
            continue;
        }

        mgVectorMaxMin(poly_max, poly_min, poly->vertex[0], poly->vertex[1], poly->vertex[2]);

        if (poly_min[0] > line_max[0] || poly_min[1] > line_max[1] || poly_min[2] > line_max[2]) {
            continue;
        }

        if (line_min[0] > poly_max[0] || line_min[1] > poly_max[1] || line_min[2] > poly_max[2]) {
            continue;
        }

        sceVu0SubVector(offset, from, poly->vertex[0]);
        from_side = sceVu0InnerProduct(poly->normal, offset);
        sceVu0SubVector(offset, to, poly->vertex[0]);
        to_side = sceVu0InnerProduct(poly->normal, offset);

        if (from_side > 0.0f && to_side > 0.0f) {
            continue;
        }

        if (from_side < 0.0f && to_side < 0.0f) {
            continue;
        }

        if (mgIntersectionPoint_line_poly3(from, to, poly->vertex[0], poly->vertex[1], poly->vertex[2], poly->normal, point) == 0) {
            continue;
        }

        if (hits >= max_hits) {
            break;
        }

        hit_polys[hits] = i;
        sceVu0CopyVector(hit_points[hits], point);
        hit_points[hits][3] = mgDistVector(from, point);
        hits++;
    }

    if (sort != 0) {
        if (sort > 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }

        // A descending sort was never written; it sorts ascending as well.
        if (sort < 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }
    }

    return hits;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHits__FP13CollisionInfoPfPfiPiPA4_fii);
#endif

#ifdef NONMATCHING
int CheckHitsPipeY(CCPoly *polys, int count, float *from, float height, int max_hits, int *hit_polys, float (*hit_points)[4], int sort, int ignore_mask) {
    sceVu0FVECTOR top;
    sceVu0FVECTOR pipe_max;
    sceVu0FVECTOR pipe_min;
    sceVu0FVECTOR poly_max;
    sceVu0FVECTOR poly_min;
    sceVu0FVECTOR points[8];
    sceVu0FVECTOR best;
    sceVu0FVECTOR swap;
    CCPoly       *poly;
    float         radius;
    float         normal_y;
    int           point_count;
    int           found;
    int           hits;
    int           i;
    int           j;

    hits = 0;
    radius = from[3];
    top[0] = from[0];
    top[1] = from[1] + height;
    top[2] = from[2];
    top[3] = from[3];
    mgVectorMaxMin(pipe_max, pipe_min, from, top);
    pipe_max[0] += radius;
    pipe_max[2] += radius;
    pipe_min[0] -= radius;
    pipe_min[2] -= radius;
    poly = polys;

    for (i = 0; i < count; i++, poly++) {
        if (poly->ignore_mask & ignore_mask) {
            continue;
        }

        // A wall that is nearly upright has no height under the pipe.
        normal_y = poly->normal[1];

        if (normal_y < 0.0f) {
            normal_y = -normal_y;
        }

        if (normal_y < 0.01f) {
            continue;
        }

        mgVectorMaxMin(poly_max, poly_min, poly->vertex[0], poly->vertex[1], poly->vertex[2]);

        if (poly_min[0] > pipe_max[0] || poly_min[1] > pipe_max[1] || poly_min[2] > pipe_max[2]) {
            continue;
        }

        if (pipe_min[0] > poly_max[0] || pipe_min[1] > poly_max[1] || pipe_min[2] > poly_max[2]) {
            continue;
        }

        point_count = IntersectionPipeYPoly3(from, poly->vertex, poly->normal, points);

        if (point_count <= 0) {
            continue;
        }

        // Keep the highest point that lies within the pipe's height.
        found = 0;

        for (j = 0; j < point_count; j++) {
            if (points[j][1] <= pipe_max[1] && pipe_min[1] <= points[j][1]) {
                if (found == 0) {
                    best[0] = points[j][0];
                    best[1] = points[j][1];
                    best[2] = points[j][2];
                    best[3] = points[j][3];
                    found = 1;
                } else if (best[1] < points[j][1]) {
                    best[0] = points[j][0];
                    best[1] = points[j][1];
                    best[2] = points[j][2];
                    best[3] = points[j][3];
                }
            }
        }

        if (found == 0) {
            continue;
        }

        if (hits >= max_hits) {
            break;
        }

        hit_polys[hits] = i;
        sceVu0CopyVector(hit_points[hits], best);
        hit_points[hits][3] = mgDistVector(from, best);
        hits++;
    }

    if (sort != 0) {
        if (sort > 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }

        // A descending sort was never written; it sorts ascending as well.
        if (sort < 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }
    }

    return hits;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitsPipeY__FP6CCPolyiPffiPiPA4_fii);
#endif

#ifdef NONMATCHING
int CheckHitsPipe(CCPoly *polys, int count, float *from, float *to, int max_hits, int *hit_polys, float (*hit_points)[4], int sort, int ignore_mask) {
    sceVu0FVECTOR pipe_max;
    sceVu0FVECTOR pipe_min;
    sceVu0FVECTOR dir;
    sceVu0FVECTOR points[8];
    sceVu0FVECTOR poly_max;
    sceVu0FVECTOR poly_min;
    sceVu0FVECTOR best;
    sceVu0FVECTOR offset;
    sceVu0FVECTOR swap;
    CCPoly       *poly;
    float         radius;
    float         length;
    float         along;
    int           point_count;
    int           found;
    int           hits;
    int           i;
    int           j;

    hits = 0;
    radius = from[3];
    length = mgDistVector(from, to);
    mgVectorMaxMin(pipe_max, pipe_min, from, to);
    sceVu0SubVector(dir, to, from);
    sceVu0Normalize(dir, dir);
    pipe_max[0] += radius;
    pipe_max[1] += radius;
    pipe_max[2] += radius;
    pipe_min[0] -= radius;
    pipe_min[1] -= radius;
    pipe_min[2] -= radius;
    poly = polys;

    for (i = 0; i < count; i++, poly++) {
        if (poly->ignore_mask & ignore_mask) {
            continue;
        }

        mgVectorMaxMin(poly_max, poly_min, poly->vertex[0], poly->vertex[1], poly->vertex[2]);

        if (poly_min[0] > pipe_max[0] || poly_min[1] > pipe_max[1] || poly_min[2] > pipe_max[2]) {
            continue;
        }

        if (pipe_min[0] > poly_max[0] || pipe_min[1] > poly_max[1] || pipe_min[2] > poly_max[2]) {
            continue;
        }

        point_count = IntersectionPipePoly3(from, dir, poly->vertex, poly->normal, points);

        if (point_count <= 0) {
            continue;
        }

        // Keep the point nearest the pipe's start among those along its length; w holds the distance.
        found = 0;

        for (j = 0; j < point_count; j++) {
            sceVu0SubVector(offset, points[j], from);
            along = sceVu0InnerProduct(offset, dir);
            points[j][3] = along;

            if (along >= 0.0f && along <= length) {
                if (found == 0) {
                    best[0] = points[j][0];
                    best[1] = points[j][1];
                    best[2] = points[j][2];
                    best[3] = points[j][3];
                    found = 1;
                } else if (points[j][3] < best[3]) {
                    best[0] = points[j][0];
                    best[1] = points[j][1];
                    best[2] = points[j][2];
                    best[3] = points[j][3];
                }
            }
        }

        if (found == 0) {
            continue;
        }

        if (hits >= max_hits) {
            break;
        }

        hit_polys[hits] = i;
        sceVu0CopyVector(hit_points[hits], best);
        hits++;
    }

    if (sort != 0) {
        if (sort > 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }

        // A descending sort was never written; it sorts ascending as well.
        if (sort < 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }
    }

    return hits;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitsPipe__FP6CCPolyiPfPfiPiPA4_fii);
#endif

#ifdef NONMATCHING
int CheckHitsSphere(CCPoly *polys, int count, float *sphere, int max_hits, int *hit_polys, float (*hit_points)[4], int sort, int ignore_mask) {
    sceVu0FVECTOR sphere_max;
    sceVu0FVECTOR sphere_min;
    sceVu0FVECTOR poly_max;
    sceVu0FVECTOR poly_min;
    sceVu0FVECTOR push;
    sceVu0FVECTOR normal;
    sceVu0FVECTOR swap;
    CCPoly       *poly;
    int           hits;
    int           i;
    int           j;

    hits = 0;
    sphere_max[0] = sphere[0] + sphere[3];
    sphere_max[1] = sphere[1] + sphere[3];
    sphere_max[2] = sphere[2] + sphere[3];
    sphere_max[3] = sphere[3];
    sphere_min[0] = sphere[0] - sphere[3];
    sphere_min[1] = sphere[1] - sphere[3];
    sphere_min[2] = sphere[2] - sphere[3];
    sphere_min[3] = sphere[3];
    poly = polys;

    for (i = 0; i < count; i++, poly++) {
        if (poly->ignore_mask & ignore_mask) {
            continue;
        }

        mgVectorMaxMin(poly_max, poly_min, poly->vertex[0], poly->vertex[1], poly->vertex[2]);

        if (poly_min[0] > sphere_max[0] || poly_min[1] > sphere_max[1] || poly_min[2] > sphere_max[2]) {
            continue;
        }

        if (sphere_min[0] > poly_max[0] || sphere_min[1] > poly_max[1] || sphere_min[2] > poly_max[2]) {
            continue;
        }

        sceVu0Normalize(normal, poly->normal);

        if (IntersectionSpherePoly3(sphere, poly->vertex, normal, push) == SPHERE_POLY3_NONE) {
            continue;
        }

        if (hits >= max_hits) {
            break;
        }

        hit_polys[hits] = i;
        sceVu0CopyVector(hit_points[hits], push);
        hits++;
    }

    if (sort != 0) {
        if (sort > 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }

        // A descending sort was never written; it sorts ascending as well.
        if (sort < 0) {
            for (i = 0; i < hits - 1; i++) {
                for (j = i + 1; j < hits; j++) {
                    if (hit_points[j][3] < hit_points[i][3]) {
                        int index = hit_polys[i];

                        hit_polys[i] = hit_polys[j];
                        hit_polys[j] = index;
                        sceVu0CopyVector(swap, hit_points[i]);
                        sceVu0CopyVector(hit_points[i], hit_points[j]);
                        sceVu0CopyVector(hit_points[j], swap);
                    }
                }
            }
        }
    }

    return hits;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckHitsSphere__FP6CCPolyiPfiPiPA4_fii);
#endif

#ifdef NONMATCHING
int MoveCheck(float *pos, float *velocity, float *out_pos, MoveCheckInfo *info, CCPoly *polys, int count, int ignore_mask) {
    sceVu0FVECTOR ground;
    sceVu0FVECTOR from;
    sceVu0FVECTOR to;
    sceVu0FVECTOR extension;
    int           hit_polys[64];
    sceVu0FVECTOR hit_points[64];
    sceVu0FVECTOR extended_to;
    CCPoly        ground_poly;
    sceVu0FVECTOR ground_query;
    sceVu0FVECTOR wall_query;
    float         radius;
    float         landing_margin;
    int           retries;

    radius = info->radius;
    if (radius <= 0.0f) {
        radius = 15.0f;
    }
    out_pos[0] = pos[0];
    out_pos[1] = pos[1];
    out_pos[2] = pos[2];
    sceVu0Normalize(extension, velocity);
    sceVu0ScaleVector(extension, extension, 0.3f * radius);
    from[0] = pos[0];
    from[1] = 10.0f + pos[1];
    from[2] = pos[2];
    to[0] = from[0] + velocity[0];
    to[1] = from[1] + velocity[1];
    to[2] = from[2] + velocity[2];
    from[3] = 4.0f;
    sceVu0AddVector(extended_to, to, extension);
    retries = 0;

    while (1) {
        if (CheckHitsPipe(polys, count, from, to, 64, hit_polys, hit_points, 1, ignore_mask) <= 0) {
            from[0] = to[0];
            from[1] = to[1];
            from[2] = to[2];
            to[0] = from[0];
            to[1] = from[1] - 10.0f;
            to[2] = from[2];
            break;
        }
        retries++;
        velocity[0] *= 0.5f;
        velocity[2] *= 0.5f;
        to[0] = from[0] + velocity[0];
        to[1] = from[1] + velocity[1];
        to[2] = from[2] + velocity[2];
        if (retries >= 2) {
            break;
        }
    }

    info->ground_found = 0;
    info->landed = 0;
    landing_margin = 4.0f;
    if (velocity[1] > 0.1f) {
        landing_margin = 0.0f;
    }
    sceVu0CopyVector(ground_query, from);
    if (info->skip_ground == 0 && GetFootPoly(ground_query, 20.0f, &ground_poly, ground, polys, count, ignore_mask) != 0) {
        sceVu0Normalize(ground_poly.normal, ground_poly.normal);
        info->ground_poly = ground_poly;
        info->second_poly = ground_poly;
        info->ground_found = 1;
        info->landed = 0;
        *(u_long128 *)info->ground_point = *(u_long128 *)ground;
        if (ground[1] > ((from[1] + velocity[1]) - 10.0f) - landing_margin) {
            info->landed = 1;
        }
    }
    if (info->landed != 0) {
        out_pos[0] = ground[0];
        out_pos[1] = ground[1];
        out_pos[2] = ground[2];
    } else {
        out_pos[0] = to[0];
        out_pos[1] = to[1];
        out_pos[2] = to[2];
    }
    *(u_long128 *)wall_query = *(u_long128 *)out_pos;
    wall_query[1] += 5.0f;
    info->width_result = CheckWidth(polys, count, wall_query, radius, to, ignore_mask);
    if (info->width_result != 0) {
        wall_query[0] = to[0];
        wall_query[2] = to[2];
    }
    wall_query[3] = 4.0f;
    if (CheckWidthPipe(polys, count, wall_query, radius, to, ignore_mask) != 0) {
        out_pos[0] = to[0];
        out_pos[2] = to[2];
    } else {
        out_pos[0] = wall_query[0];
        out_pos[2] = wall_query[2];
    }
    if (info->skip_ground == 0) {
        sceVu0CopyVector(ground_query, from);
        if (GetFootPoly(ground_query, 20.0f, &ground_poly, ground, polys, count, ignore_mask) != 0) {
            *(u_long128 *)info->ground_point = *(u_long128 *)ground;
            if (ground[1] > ((from[1] + velocity[1]) - 10.0f) - landing_margin) {
                out_pos[1] = ground[1];
            }
        }
    }
    GetCPolyAttr(info, pos, out_pos, 34.0f, polys, count, ignore_mask);
    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", MoveCheck__FPfPfPfP13MoveCheckInfoP6CCPolyii);
#endif

#ifdef NONMATCHING
int GetFootPoly(float *pos, float depth, CCPoly *found, float *ground, CCPoly *polys, int count, int ignore_mask) {
    s16           ground_kind;
    s16           foot_sound;
    s16           area_kind;
    s16           poly_ignore_mask;
    u16           parts_no;
    s16           attribute;
    float         attribute_value;
    int           hit_polys[32];
    sceVu0FVECTOR from;
    sceVu0FVECTOR to;
    sceVu0FVECTOR hit_points[32];
    sceVu0FVECTOR normal;
    float         normal_y;
    CCPoly       *poly;
    int           hits;
    int           found_ground;
    int           i;

    sceVu0CopyVector(from, pos);
    sceVu0CopyVector(to, pos);
    from[3] = 4.0f;
    to[1] -= depth;
    hits = CheckHitsPipeY(polys, count, from, -depth, 32, hit_polys, hit_points, 1, ignore_mask);
    if (hits == 0) {
        return 0;
    }
    ground_kind = 0;
    foot_sound = 0;
    area_kind = 0;
    found_ground = 0;
    for (i = 0; i < hits; i++) {
        sceVu0Normalize(normal, polys[hit_polys[i]].normal);
        normal_y = normal[1];
        if (normal_y < 0.0f) {
            normal_y = -normal_y;
        }
        if (normal_y < 0.05f) {
            continue;
        }
        *found = polys[hit_polys[i]];
        sceVu0CopyVector(ground, hit_points[i]);
        found_ground = 1;
        ground[0] = from[0];
        ground[2] = from[2];
        ground_kind = found->ground_kind;
        foot_sound = found->foot_sound;
        area_kind = found->area_kind;
        poly_ignore_mask = found->ignore_mask;
        parts_no = found->parts_no;
        attribute = found->unk_4a;
        attribute_value = found->unk_4c;
        break;
    }
    for (i = 0; i < hits; i++) {
        poly = &polys[hit_polys[i]];
        if (ground_kind == 0) {
            ground_kind = poly->ground_kind;
        }
        if (foot_sound == 0) {
            foot_sound = poly->foot_sound;
        }
        if (area_kind == 0) {
            area_kind = poly->area_kind;
        }
    }
    found->ground_kind = ground_kind;
    found->foot_sound = foot_sound;
    found->area_kind = area_kind;
    found->ignore_mask = poly_ignore_mask;
    found->parts_no = parts_no;
    found->unk_4a = attribute;
    found->unk_4c = attribute_value;
    return found_ground;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", GetFootPoly__FPffP6CCPolyPfP6CCPolyii);
#endif

#ifdef NONMATCHING
void GetCPolyAttr(MoveCheckInfo *info, float *from, float *to, float height, CCPoly *polys, int count, int ignore_mask) {
    int           hit_polys[32];
    sceVu0FVECTOR above;
    sceVu0FVECTOR below;
    sceVu0FVECTOR hit_points[32];
    int           hits;
    int           i;
    s16           area_kind;

    info->in_water = 0;
    info->crossed_area = 0;
    hits = CheckHits(polys, count, from, to, 32, hit_polys, hit_points, 1, 0);
    for (i = 0; i < hits; i++) {
        area_kind = polys[hit_polys[i]].area_kind;
        if (area_kind == 7 || area_kind == 1) {
            info->crossed_area = 1;
            info->signed_distance = mgDistVector(from, to);
            if (from[1] > to[1]) {
                info->signed_distance *= -1.0f;
            }
            *(u_long128 *)info->crossed_point = *(u_long128 *)hit_points[i];
        }
    }
    sceVu0CopyVector(above, to);
    sceVu0CopyVector(below, to);
    above[1] += height;
    hits = CheckHits(polys, count, above, below, 32, hit_polys, hit_points, 1, 0);
    if (hits != 0) {
        for (i = 0; i < hits; i++) {
            area_kind = polys[hit_polys[i]].area_kind;
            if (area_kind == 7 || area_kind == 1) {
                info->in_water = 1;
                *(u_long128 *)info->water_surface = *(u_long128 *)hit_points[i];
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", GetCPolyAttr__FP13MoveCheckInfoPfPffP6CCPolyii);
#endif

#ifdef NONMATCHING
int CheckWidth(CCPoly *polys, int count, float *pos, float radius, float *out_pos, int ignore_mask) {
    sceVu0FVECTOR to;
    sceVu0FVECTOR positive_hit;
    sceVu0FVECTOR negative_hit;
    sceVu0FVECTOR from;
    sceVu0FVECTOR normal;
    float         diagonal_radius;
    int           sides;
    int           positive;
    int           negative;
    int           hit;

    sides = 0;
    diagonal_radius = radius / 1.4142135f;
    sceVu0CopyVector(from, pos);
    sceVu0CopyVector(out_pos, pos);
    positive = 0;
    negative = 0;
    to[0] = from[0] + diagonal_radius;
    to[1] = from[1];
    to[2] = from[2] + diagonal_radius;
    hit = CheckHit(polys, count, from, to, positive_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            positive = 1;
            sides |= CHECK_WIDTH_SIDE_POS_X | CHECK_WIDTH_SIDE_POS_Z;
        }
    }
    to[0] = from[0] - diagonal_radius;
    to[1] = from[1];
    to[2] = from[2] - diagonal_radius;
    hit = CheckHit(polys, count, from, to, negative_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            negative = 1;
            sides |= CHECK_WIDTH_SIDE_NEG_X | CHECK_WIDTH_SIDE_NEG_Z;
        }
    }
    if (positive != 0 && negative != 0) {
        out_pos[0] = 0.5f * (positive_hit[0] + negative_hit[0]);
        out_pos[2] = 0.5f * (positive_hit[2] + negative_hit[2]);
    } else {
        if (positive != 0) {
            out_pos[0] = positive_hit[0] - diagonal_radius;
            out_pos[2] = positive_hit[2] - diagonal_radius;
        }
        if (negative != 0) {
            out_pos[0] = negative_hit[0] + diagonal_radius;
            out_pos[2] = negative_hit[2] + diagonal_radius;
        }
    }

    sceVu0CopyVector(from, out_pos);
    positive = 0;
    negative = 0;
    to[0] = from[0] + diagonal_radius;
    to[1] = from[1];
    to[2] = from[2] - diagonal_radius;
    hit = CheckHit(polys, count, from, to, positive_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            positive = 1;
            sides |= CHECK_WIDTH_SIDE_POS_X | CHECK_WIDTH_SIDE_NEG_Z;
        }
    }
    to[0] = from[0] - diagonal_radius;
    to[1] = from[1];
    to[2] = from[2] + diagonal_radius;
    hit = CheckHit(polys, count, from, to, negative_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            negative = 1;
            sides |= CHECK_WIDTH_SIDE_NEG_X | CHECK_WIDTH_SIDE_POS_Z;
        }
    }
    if (positive != 0 && negative != 0) {
        out_pos[0] = 0.5f * (positive_hit[0] + negative_hit[0]);
        out_pos[2] = 0.5f * (positive_hit[2] + negative_hit[2]);
    } else {
        if (positive != 0) {
            out_pos[0] = positive_hit[0] - diagonal_radius;
            out_pos[2] = positive_hit[2] + diagonal_radius;
        }
        if (negative != 0) {
            out_pos[0] = negative_hit[0] + diagonal_radius;
            out_pos[2] = negative_hit[2] - diagonal_radius;
        }
    }

    sceVu0CopyVector(from, out_pos);
    positive = 0;
    negative = 0;
    to[0] = from[0] + radius;
    to[1] = from[1];
    to[2] = from[2];
    hit = CheckHit(polys, count, from, to, positive_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            positive = 1;
            sides |= CHECK_WIDTH_SIDE_POS_X;
        }
    }
    to[0] = from[0] - radius;
    to[1] = from[1];
    to[2] = from[2];
    hit = CheckHit(polys, count, from, to, negative_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            negative = 1;
            sides |= CHECK_WIDTH_SIDE_NEG_X;
        }
    }
    if (positive != 0 && negative != 0) {
        out_pos[0] = 0.5f * (positive_hit[0] + negative_hit[0]);
    } else {
        if (positive != 0) {
            out_pos[0] = positive_hit[0] - radius;
        }
        if (negative != 0) {
            out_pos[0] = negative_hit[0] + radius;
        }
    }

    sceVu0CopyVector(from, out_pos);
    positive = 0;
    negative = 0;
    to[0] = from[0];
    to[1] = from[1];
    to[2] = from[2] + radius;
    hit = CheckHit(polys, count, from, to, positive_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            positive = 1;
            sides |= CHECK_WIDTH_SIDE_POS_Z;
        }
    }
    to[0] = from[0];
    to[1] = from[1];
    to[2] = from[2] - radius;
    hit = CheckHit(polys, count, from, to, negative_hit, 1, ignore_mask);
    if (hit >= 0) {
        sceVu0Normalize(normal, polys[hit].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            negative = 1;
            sides |= CHECK_WIDTH_SIDE_NEG_Z;
        }
    }
    if (positive != 0 && negative != 0) {
        out_pos[2] = 0.5f * (positive_hit[2] + negative_hit[2]);
    } else {
        if (positive != 0) {
            out_pos[2] = positive_hit[2] - radius;
        }
        if (negative != 0) {
            out_pos[2] = negative_hit[2] + radius;
        }
    }
    return sides;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckWidth__FP6CCPolyiPffPfi);
#endif

#ifdef NONMATCHING
int CheckWidthPipe(CCPoly *polys, int count, float *pos, float radius, float *out_pos, int ignore_mask) {
    sceVu0FVECTOR to;
    sceVu0FVECTOR positive_hit;
    sceVu0FVECTOR negative_hit;
    sceVu0FVECTOR from;
    sceVu0FVECTOR normal;
    int           hit_polys[32];
    sceVu0FVECTOR hit_points[32];
    float         probe_radius;
    int           sides;
    int           positive;
    int           negative;

    probe_radius = radius * 0.8f;
    sides = 0;
    sceVu0CopyVector(from, pos);
    from[1] += 3.0f * pos[3];
    sceVu0CopyVector(out_pos, pos);
    to[3] = from[3];
    positive = 0;
    negative = 0;
    to[1] = from[1];
    to[0] = from[0] + probe_radius;
    to[2] = from[2];
    if (CheckHitsPipe(polys, count, from, to, 32, hit_polys, hit_points, 1, ignore_mask) > 0) {
        *(u_long128 *)positive_hit = *(u_long128 *)hit_points[0];
        sceVu0Normalize(normal, polys[hit_polys[0]].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            positive = 1;
            sides |= CHECK_WIDTH_SIDE_POS_X;
        }
    }
    to[0] = from[0] - probe_radius;
    to[2] = from[2];
    if (CheckHitsPipe(polys, count, from, to, 32, hit_polys, hit_points, 1, ignore_mask) > 0) {
        *(u_long128 *)negative_hit = *(u_long128 *)hit_points[0];
        sceVu0Normalize(normal, polys[hit_polys[0]].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            negative = 1;
            sides |= CHECK_WIDTH_SIDE_NEG_X;
        }
    }
    if (positive != 0 && negative != 0) {
        out_pos[0] = 0.5f * (positive_hit[0] + negative_hit[0]);
    } else {
        if (positive != 0) {
            out_pos[0] = positive_hit[0] - probe_radius;
        }
        if (negative != 0) {
            out_pos[0] = negative_hit[0] + probe_radius;
        }
    }

    from[0] = out_pos[0];
    from[2] = out_pos[2];
    positive = 0;
    negative = 0;
    to[0] = from[0];
    to[2] = from[2] + probe_radius;
    if (CheckHitsPipe(polys, count, from, to, 32, hit_polys, hit_points, 1, ignore_mask) > 0) {
        *(u_long128 *)positive_hit = *(u_long128 *)hit_points[0];
        sceVu0Normalize(normal, polys[hit_polys[0]].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            positive = 1;
            sides |= CHECK_WIDTH_SIDE_POS_Z;
        }
    }
    to[0] = from[0];
    to[2] = from[2] - probe_radius;
    if (CheckHitsPipe(polys, count, from, to, 32, hit_polys, hit_points, 1, ignore_mask) > 0) {
        *(u_long128 *)negative_hit = *(u_long128 *)hit_points[0];
        sceVu0Normalize(normal, polys[hit_polys[0]].normal);
        if (normal[1] < 0.5f && normal[1] > -0.5f) {
            negative = 1;
            sides |= CHECK_WIDTH_SIDE_NEG_Z;
        }
    }
    if (positive != 0 && negative != 0) {
        out_pos[2] = 0.5f * (positive_hit[2] + negative_hit[2]);
    } else {
        if (positive != 0) {
            out_pos[2] = positive_hit[2] - probe_radius;
        }
        if (negative != 0) {
            out_pos[2] = negative_hit[2] + probe_radius;
        }
    }
    return sides;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CheckWidthPipe__FP6CCPolyiPffPfi);
#endif

int CreateCharaCPoly(CCPoly *polys, int max_polys, float *pos, float *target, float distance, float half_size) {
    sceVu0FVECTOR direction;
    sceVu0FVECTOR centre;
    sceVu0FVECTOR upper_left;
    sceVu0FVECTOR upper_right;
    sceVu0FVECTOR lower_left;
    sceVu0FVECTOR lower_right;
    float         wall_distance;

    if (max_polys < 2) {
        return 0;
    }
    sceVu0SubVector(direction, target, pos);
    direction[1] = 0.0f;
    wall_distance = mgDistVector(direction);
    if (wall_distance > distance) {
        wall_distance = distance;
    }
    if (wall_distance < distance) {
        wall_distance -= 1.0f;
    }
    sceVu0Normalize(direction, direction);
    upper_left[1] = half_size;
    upper_left[0] = -direction[2] * half_size;
    upper_left[2] = direction[0] * half_size;
    upper_left[3] = 1.0f;
    sceVu0CopyVector(upper_right, upper_left);
    upper_right[0] = -upper_left[0];
    upper_right[2] = -upper_left[2];
    sceVu0CopyVector(lower_left, upper_left);
    lower_left[1] = -half_size;
    sceVu0CopyVector(lower_right, upper_right);
    lower_right[1] = -half_size;
    sceVu0ScaleVector(centre, direction, wall_distance);
    sceVu0AddVector(centre, centre, pos);
    sceVu0AddVector(upper_left, upper_left, centre);
    sceVu0AddVector(upper_right, upper_right, centre);
    sceVu0AddVector(lower_left, lower_left, centre);
    sceVu0AddVector(lower_right, lower_right, centre);
    *(u_long128 *)&polys[0].ground_kind = 0;
    sceVu0CopyVector(polys[0].vertex[0], upper_left);
    sceVu0CopyVector(polys[0].vertex[1], upper_right);
    sceVu0CopyVector(polys[0].vertex[2], lower_left);
    sceVu0CopyVector(polys[0].normal, direction);
    *(u_long128 *)&polys[1].ground_kind = 0;
    sceVu0CopyVector(polys[1].vertex[0], lower_left);
    sceVu0CopyVector(polys[1].vertex[1], upper_right);
    sceVu0CopyVector(polys[1].vertex[2], lower_right);
    sceVu0CopyVector(polys[1].normal, direction);
    return 2;
}

float LinerInterpolation(float from, float to, float rate) {
    return from + (rate * (to - from));
}
int LinerInterpolationI(int from, int to, int step, int steps) {
    return from + step * (to - from) / steps;
}

#ifdef NONMATCHING
void RollPos(float *centre, float *pos, float angle, float *out) {
    float centre_x;
    float centre_y;
    float x;
    float y;
    float relative_x;

    centre_x = centre[0];
    centre_y = centre[1];
    x = pos[0];
    y = pos[1];
    relative_x = x - centre_x;
    y -= centre_y;
    out[0] = centre_x + (relative_x * cosf(angle) - y * sinf(angle));
    out[1] = centre_y - (relative_x * sinf(angle) + y * cosf(angle));
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", RollPos__FPfPffPf);
#endif

s32 CheckPosInOutForRect(RECT *rect, s32 x, s32 y) {
    s32 left = rect->x;
    if (x < left) {
        return 0;
    }
    if ((left + rect->width) < x) {
        return 0;
    }
    s32 top = rect->y;
    if (y < top) {
        return 0;
    }
    return (top + rect->height) >= y;
}
float GetDisPosToRect(RECT *rect, int x, int y) {
    float distance_x;
    float distance_y;

    distance_x = rect->x + rect->width / 2 - x;
    distance_y = rect->y + rect->height / 2 - y;
    return sqrt(distance_x * distance_x + distance_y * distance_y);
}

s32 CheckPosInOutFor2P(float x0, float y0, float x1, float y1, float x, float y) {
    float min_x;
    float max_x;
    float max_y;
    float min_y;
    s32 outside;

    max_x = x1;
    max_y = y1;
    min_x = max_x;
    if (x0 < max_x) {
        min_x = x0;
    } else {
        max_x = x0;
    }
    min_y = max_y;
    if (y0 < max_y) {
        min_y = y0;
    } else {
        max_y = y0;
    }
    if (x < min_x) {
        return 0;
    }
    if (max_x < x) {
        return 0;
    }
    if (y < min_y) {
        return 0;
    }
    outside = 1;
    if (!(max_y < y)) {
        outside = 0;
    }
    return outside ^ 1;
}
#ifdef NONMATCHING
int CalcIntersectionPointLineAndLine(float ax0, float ay0, float ax1, float ay1, float bx0, float by0, float bx1, float by1, float *out_x, float *out_y) {
    float slope_a;
    float slope_b;
    float relative_x;

    if (ax0 == ax1 && bx0 == bx1) {
        return 0;
    }
    if (ax0 != ax1) {
        slope_a = (ay1 - ay0) / (ax1 - ax0);
    }
    if (bx0 != bx1) {
        slope_b = (by1 - by0) / (bx1 - bx0);
    }
    if (slope_a == slope_b) {
        return 0;
    }
    if (ax0 == ax1) {
        *out_x = ax0;
        *out_y = slope_b * (ax0 - bx0);
        return 1;
    } else if (bx0 == bx1) {
        *out_x = bx0;
        *out_y = slope_a * (bx0 - ax0);
        return 1;
    } else {
        relative_x = ((by0 - ay0) - slope_b * (bx0 - ax0)) / (slope_a - slope_b);
        *out_x = relative_x + ax0;
        *out_y = (relative_x * slope_a) + ay0;
        return 1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gameutil", CalcIntersectionPointLineAndLine__FffffffffPfPf);
#endif

s32 CalcIntersectionPoint2PAnd2P(float ax0, float ay0, float ax1, float ay1, float bx0, float by0, float bx1, float by1, float *out_x, float *out_y) {
    if (CalcIntersectionPointLineAndLine(ax0, ay0, ax1, ay1, bx0, by0, bx1, by1, out_x, out_y) == 0) {
        return 0;
    }
    if (CheckPosInOutFor2P(ax0, ay0, ax1, ay1, *out_x, *out_y) == 0) {
        return 0;
    }
    return CheckPosInOutFor2P(bx0, by0, bx1, by1, *out_x, *out_y) != 0;
}

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gameutil", at_966__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gameutil", at_967__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(OldSkinFrame, 0x4);
INCLUDE_BSS(vert_845, 0x10);
INCLUDE_BSS(vert_915, 0x10);
INCLUDE_BSS(nml_916, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(def_vrtx, 0x3200);
INCLUDE_BSS(def_nml, 0x10);
INCLUDE_BSS(tmp_SkinMatrix_847, 0x40);
INCLUDE_BSS(tmp_SkinMatrix_inv_848, 0x40);
INCLUDE_BSS(tmp_ChrMatrix_849, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_851, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_inv_852, 0x40);
INCLUDE_BSS(tmp_SkinMatrix_917, 0x40);
INCLUDE_BSS(tmp_SkinMatrix_inv_918, 0x40);
INCLUDE_BSS(tmp_ChrMatrix_919, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_921, 0x40);
INCLUDE_BSS(tmp_BaseSkinMatrix_inv_922, 0x40);
INCLUDE_BSS(at_945, 0x10);
