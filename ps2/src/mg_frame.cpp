#include "common.h"

#include <libvu0.h>

#include <cstring>

#include "mg_drawenv.hpp"
#include "mg_drawprim.hpp"
#include "mg_frame.hpp"
#include "mg_math.hpp"
#include "mg_memory.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"

extern u_char              at_844[];
extern const unsigned char at_307__DATA[];
extern u_char              at_324[];
extern u_char              at_341[];
extern u_char              at_1118[];
extern u_char              at_1119[];

static mgCFrameAttr dmy_attr;

// Code (.text)
void mgCFrameAttr::Initialize() {
    memset(this, 0, sizeof(mgCFrameAttr));
    mgCVisualAttr::Initialize();
    color[0] = color[1] = color[2] = color[3] = 128.0f;
    alpha_ref = -1;
    draw = MG_FRAME_DRAW_VISIBLE;
    z_write = MG_ZBUF_WRITE;
    unk_3c = 0;
    unk_20 = 100.0f;
    fog = 1;
    obj_alpha = 1.0f;
    point_light = 1;
    unk_50[3] = 0.0f;
    unk_50[2] = 0.0f;
    unk_50[0] = 0.0f;
    unk_50[1] = 1.0f;
    depth_bias = 0.0f;
    unk_84 = 0;
}

/**
 *
 * Builds a rotation matrix from a quaternion whose scalar part comes first.
 *
 */
mgCFrameAttr::mgCFrameAttr() {
    Initialize();
}

static void QuatToMat(float *quaternion, float (*matrix)[4]) {
    float yy;
    float zz;
    float ww;
    float y;
    float xy;
    float z;
    float xz;
    float zw;
    float xw;
    float yz;
    float yw;
    float x;
    float w;
    y = quaternion[1];
    z = quaternion[2];
    w = quaternion[3];
    x = quaternion[0];
    yz = y * z;
    zz = z * z;
    zw = z * w;
    xz = x * z;
    xy = x * y;
    yy = y * y;
    yw = y * w;
    ww = w * w;
    xw = x * w;
    matrix[0][0] = 1.0f - (2.0f * (zz + ww));
    matrix[0][1] = 2.0f * (yz - xw);
    matrix[0][2] = 2.0f * (yw + xz);
    matrix[0][3] = 0.0f;
    matrix[1][0] = 2.0f * (yz + xw);
    matrix[1][1] = 1.0f - (2.0f * (yy + ww));
    matrix[1][2] = 2.0f * (zw - xy);
    matrix[1][3] = 0.0f;
    matrix[2][0] = 2.0f * (yw - xz);
    matrix[2][1] = 2.0f * (zw + xy);
    matrix[2][2] = 1.0f - (2.0f * (yy + zz));
    matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

// clang-format off
/**
 *
 * Transforms eight corners by the product of two matrices, leaving the results in VU0
 * registers vf10-vf17, and gets the box around them.
 *
 */
#ifdef NONMATCHING
static float projected_corners[8][4];

// 29.6% match, 89 words off
void test1(float (*corners)[4], float (*screen)[4], float (*matrix)[4], float *out_max,
           float *out_min) {
    float combined[4][4];
    for (int column = 0; column < 4; column++) {
        for (int row = 0; row < 4; row++) {
            combined[column][row] = screen[0][row] * matrix[column][0] +
                                    screen[1][row] * matrix[column][1] +
                                    screen[2][row] * matrix[column][2] +
                                    screen[3][row] * matrix[column][3];
        }
    }

    for (int corner = 0; corner < 8; corner++) {
        for (int row = 0; row < 4; row++) {
            float value = combined[0][row] * corners[corner][0] +
                          combined[1][row] * corners[corner][1] +
                          combined[2][row] * corners[corner][2] +
                          combined[3][row] * corners[corner][3];
            projected_corners[corner][row] = value;
            if (corner == 0) {
                out_max[row] = value;
                out_min[row] = value;
            } else {
                if (value > out_max[row]) {
                    out_max[row] = value;
                }
                if (value < out_min[row]) {
                    out_min[row] = value;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", test1__FPA4_fPA4_fPA4_fPfPf);
#endif
// clang-format on
// clang-format off
/**
 *
 * Divides the eight corners that test1 left in vf10-vf17 through by their depth and gets
 * the screen-space box around them.
 *
 */
#ifdef NONMATCHING
// ~1.3% match, 77 words off
void test2(float *out_max, float *out_min) {
    for (int corner = 0; corner < 8; corner++) {
        float depth = projected_corners[corner][3];
        if (depth < 0.0f) {
            depth = -depth;
        }
        float x = projected_corners[corner][0] / depth;
        float y = projected_corners[corner][1] / depth;
        if (corner == 0) {
            out_max[0] = out_min[0] = x;
            out_max[1] = out_min[1] = y;
            out_max[2] = out_min[2] = projected_corners[corner][2];
            out_max[3] = out_min[3] = projected_corners[corner][3];
        } else {
            float values[4] = {x, y, projected_corners[corner][2], projected_corners[corner][3]};
            for (int axis = 0; axis < 4; axis++) {
                if (values[axis] > out_max[axis]) {
                    out_max[axis] = values[axis];
                }
                if (values[axis] < out_min[axis]) {
                    out_min[axis] = values[axis];
                }
            }
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", test2__FPfPf);
#endif
// clang-format on

int mgInsideScreen(mgVu0FBOX *box) {
    sceVu0FMATRIX matrix;
    sceVu0FVECTOR corners[8];

    mgUnitMatrix(matrix);
    mgCreateBox8(corners, box->max, box->min);
    return mgInsideScreen(corners, matrix);
}

int mgInsideScreen(mgVu0FBOX *box, float (*matrix)[4]) {
    sceVu0FVECTOR corners[8];

    mgCreateBox8(corners, box->max, box->min);
    return mgInsideScreen(corners, matrix);
}

#pragma global_optimizer off

int mgInsideScreen(mgVu0FBOX *box, float (*matrix)[4], float *out_max, float *out_min) {
    sceVu0FVECTOR corners[8];
    mgCreateBox8(corners, box->max, box->min);
    return mgInsideScreen(corners, matrix, out_max, out_min);
}

#pragma global_optimizer reset

int mgInsideScreen(float (*corners)[4], float (*matrix)[4]) {
    sceVu0FVECTOR max;
    sceVu0FVECTOR min;

    return mgInsideScreen(corners, matrix, max, min);
}

#pragma global_optimizer off
int mgInsideScreen(float (*corners)[4], float (*matrix)[4], float *out_max, float *out_min) {
    mgRENDER_INFO *info = &mgRenderInfo;
    float (*screen)[4] = info->world_screen_rel;
    asm {
        lqc2 vf11, 0(screen)
        lqc2 vf12, 0x10(screen)
        lqc2 vf13, 0x20(screen)
        lqc2 vf14, 0x30(screen)
        lqc2 vf5, 0(matrix)
        lqc2 vf6, 0x10(matrix)
        lqc2 vf7, 0x20(matrix)
        lqc2 vf8, 0x30(matrix)
        vmulax.xyzw ACC, vf11, vf5x
        vmadday.xyzw ACC, vf12, vf5y
        vmaddaz.xyzw ACC, vf13, vf5z
        vmaddw.xyzw vf1, vf14, vf5w
        vmulax.xyzw ACC, vf11, vf6x
        vmadday.xyzw ACC, vf12, vf6y
        vmaddaz.xyzw ACC, vf13, vf6z
        vmaddw.xyzw vf2, vf14, vf6w
        vmulax.xyzw ACC, vf11, vf7x
        vmadday.xyzw ACC, vf12, vf7y
        vmaddaz.xyzw ACC, vf13, vf7z
        vmaddw.xyzw vf3, vf14, vf7w
        vmulax.xyzw ACC, vf11, vf8x
        vmadday.xyzw ACC, vf12, vf8y
        vmaddaz.xyzw ACC, vf13, vf8z
        vmaddw.xyzw vf4, vf14, vf8w
        lqc2 vf10, 0(corners)
        lqc2 vf11, 0x10(corners)
        lqc2 vf12, 0x20(corners)
        lqc2 vf13, 0x30(corners)
        lqc2 vf14, 0x40(corners)
        lqc2 vf15, 0x50(corners)
        lqc2 vf16, 0x60(corners)
        lqc2 vf17, 0x70(corners)
        vmulax.xyzw ACC, vf1, vf10x
        vmadday.xyzw ACC, vf2, vf10y
        vmaddaz.xyzw ACC, vf3, vf10z
        vmaddw.xyzw vf10, vf4, vf10w
        vmulax.xyzw ACC, vf1, vf11x
        vmadday.xyzw ACC, vf2, vf11y
        vmaddaz.xyzw ACC, vf3, vf11z
        vabs.w vf20, vf10
        vmaddw.xyzw vf11, vf4, vf11w
        vdiv Q, vf0w, vf20w
        vabs.w vf21, vf11
        vwaitq
        vmulq.xy vf10, vf10, Q
        vdiv Q, vf0w, vf21w
        vmulax.xyzw ACC, vf1, vf12x
        vmadday.xyzw ACC, vf2, vf12y
        vmaddaz.xyzw ACC, vf3, vf12z
        vmaddw.xyzw vf12, vf4, vf12w
        vmulax.xyzw ACC, vf1, vf13x
        vwaitq
        vmulq.xy vf11, vf11, Q
        vabs.w vf22, vf12
        vmadday.xyzw ACC, vf2, vf13y
        vmaddaz.xyzw ACC, vf3, vf13z
        vmaddw.xyzw vf13, vf4, vf13w
        vdiv Q, vf0w, vf22w
        vmulax.xyzw ACC, vf1, vf14x
        vmadday.xyzw ACC, vf2, vf14y
        vabs.w vf23, vf13
        vmaddaz.xyzw ACC, vf3, vf14z
        vmaddw.xyzw vf14, vf4, vf14w
        vmax.xyzw vf30, vf10, vf11
        vmini.xyzw vf31, vf10, vf11
        vmulq.xy vf12, vf12, Q
        vdiv Q, vf0w, vf23w
        vabs.w vf24, vf14
        vmulax.xyzw ACC, vf1, vf15x
        vmadday.xyzw ACC, vf2, vf15y
        vmaddaz.xyzw ACC, vf3, vf15z
        vmaddw.xyzw vf15, vf4, vf15w
        vmax.xyzw vf30, vf30, vf12
        vmini.xyzw vf31, vf31, vf12
        vmulq.xy vf13, vf13, Q
        vdiv Q, vf0w, vf24w
        vabs.w vf25, vf15
        vmulax.xyzw ACC, vf1, vf16x
        vmadday.xyzw ACC, vf2, vf16y
        vmaddaz.xyzw ACC, vf3, vf16z
        vmaddw.xyzw vf16, vf4, vf16w
        vmax.xyzw vf30, vf30, vf13
        vmini.xyzw vf31, vf31, vf13
        vmulq.xy vf14, vf14, Q
        vdiv Q, vf0w, vf25w
        vabs.w vf26, vf16
        vmulax.xyzw ACC, vf1, vf17x
        vmadday.xyzw ACC, vf2, vf17y
        vmaddaz.xyzw ACC, vf3, vf17z
        vmaddw.xyzw vf17, vf4, vf17w
        vmax.xyzw vf30, vf30, vf14
        vmini.xyzw vf31, vf31, vf14
        vmulq.xy vf15, vf15, Q
        vdiv Q, vf0w, vf26w
        vabs.w vf27, vf17
        vnop
        vmax.xyzw vf30, vf30, vf15
        vmini.xyzw vf31, vf31, vf15
        vnop
        vwaitq
        vmulq.xy vf16, vf16, Q
        vdiv Q, vf0w, vf27w
        vnop
        vmax.xyzw vf30, vf30, vf16
        vmini.xyzw vf31, vf31, vf16
        vnop
        vnop
        vwaitq
        vmulq.xy vf17, vf17, Q
        vmax.xyzw vf30, vf30, vf17
        vmini.xyzw vf31, vf31, vf17
        sqc2 vf30, 0(out_max)
        sqc2 vf31, 0(out_min)
    }
    return mgClipBoxW(out_max, out_min, info->screen_box_max, info->screen_box_min);
}
#pragma global_optimizer reset

void mgCObject::SetPosition(float *position) {
    if (this->position[0] != position[0] || this->position[1] != position[1] ||
        this->position[2] != position[2]) {
        use_srt = 1;
        sceVu0CopyVector(this->position, position);
        this->position[3] = 1.0f;
        changed = 1;
    }
}

void mgCObject::SetPosition(float x, float y, float z) {
    float position[4];
    *(u_long128 *) position = *(u_long128 *) at_307__DATA;
    position[0] = x;
    position[1] = y;
    position[2] = z;

    mgCObject::SetPosition(position);
}

void mgCObject::GetPosition(float *out_position) {
    sceVu0CopyVector(out_position, position);
}

void mgCObject::SetRotation(float *rotation) {
    if (this->rotation[0] != rotation[0] || this->rotation[1] != rotation[1] ||
        this->rotation[2] != rotation[2]) {
        use_srt = 1;
        changed = 1;
        sceVu0CopyVector(this->rotation, rotation);
        this->rotation[3] = 0.0f;
    }
}

void mgCObject::SetRotation(float x, float y, float z) {
    float rotation[4];
    *(u_long128 *) rotation = *(u_long128 *) at_324;
    rotation[0] = x;
    rotation[1] = y;
    rotation[2] = z;

    mgCObject::SetRotation(rotation);
}

void mgCObject::GetRotation(float *out_rotation) {
    sceVu0CopyVector(out_rotation, rotation);
}

void mgCObject::SetScale(float *scale) {
    if (this->scale[0] != scale[0] || this->scale[1] != scale[1] || this->scale[2] != scale[2]) {
        use_srt = 1;
        this->scale[0] = scale[0];
        this->scale[1] = scale[1];
        this->scale[2] = scale[2];
        changed = 1;
        this->scale[3] = 0.0f;
    }
}

void mgCObject::SetScale(float x, float y, float z) {
    float scale[4];
    *(u_long128 *) scale = *(u_long128 *) at_341;
    scale[0] = x;
    scale[1] = y;
    scale[2] = z;

    mgCObject::SetScale(scale);
}

void mgCObject::GetScale(float *out_scale) {
    sceVu0CopyVector(out_scale, scale);
}

void mgCObject::Initialize() {
    SetPosition(0.0f, 0.0f, 0.0f);
    SetRotation(0.0f, 0.0f, 0.0f);
    SetScale(1.0f, 1.0f, 1.0f);
    changed = 1;
    use_srt = 0;
}

mgCFrame::mgCFrame() {
    Initialize();
}

// Defined inline in mg_frame.hpp.
void mgCFrame::Initialize() {
    elder = NULL;
    brother = NULL;
    child = NULL;
    parent = NULL;
    sceVu0UnitMatrix(lw_matrix);
    sceVu0UnitMatrix(trans_matrix);
    name = NULL;
    rot_type = 0;
    reference = 0;
    visual = NULL;
    attr = NULL;
    frame_num = 0;
    frame_list = NULL;
    init_matrix = NULL;
    bound = NULL;
    mgCObject::Initialize();
}

void mgCFrame::SetName(char *name) {
    this->name = name;
}

void mgCFrame::SetTransMatrix(float *quaternion) {
    float saved_row[4];
    changed = 1;
    *(u_long128 *) saved_row = *(u_long128 *) trans_matrix[3];
    QuatToMat(quaternion, trans_matrix);
    *(u_long128 *) trans_matrix[3] = *(u_long128 *) saved_row;
}

void mgCFrame::SetBBox(float *max, float *min) {
    if (bound != 0) {
        sceVu0CopyVector(bound->max, max);
        sceVu0CopyVector(bound->min, min);

        float *extremes[4];
        extremes[0] = bound->min;
        extremes[1] = bound->max;

        for (s32 i = 0; i < 8; i++) {
            bound->corner[i][3] = 1.0f;
            bound->corner[i][0] = extremes[(i & 1) != 0][0];
            bound->corner[i][1] = extremes[(i & 2) != 0][1];
            bound->corner[i][2] = extremes[(i & 4) != 0][2];
        }
    }
}

void mgCFrame::GetBBox(float *out_max, float *out_min) {
    if (bound == NULL) {
        mgZeroVectorW(out_max);
        mgZeroVectorW(out_min);
    } else {
        sceVu0CopyVector(out_max, bound->max);
        sceVu0CopyVector(out_min, bound->min);
    }
}

void mgCFrame::SetBSphere(float *center, float radius) {
    if (bound != NULL) {
        sceVu0CopyVector(bound->center, center);
        bound->radius = radius;
    }
}

mgCFrame *mgCFrame::GetFrame(int index) {
    if (index < 0 || index > this->frame_num || this->frame_list == 0) {
        return 0;
    }

    return this->frame_list[index];
}

int mgCFrame::RemakeBBox(float *out_max, float *out_min) {
    float      matrix[4][4];
    mgCVisual *frame_visual = visual;

    if (frame_visual == 0) {
        return 0;
    }

    GetLWMatrix(matrix);

    if (frame_visual->CreateBBox(out_max, out_min, matrix) != 0) {
        SetBBox(out_max, out_min);
        return 1;
    }

    return 0;
}

int mgCFrame::GetWorldBBox(mgVu0FBOX *box) {
    mgVu0FBOX world_box;
    float     matrix[4][4];
    float     center[4];

    struct {
        float x;
        float y;
        float z;
        u_int w;
    } half;

    mgVu0FBOX child_box;
    s32       found = 0;

    if (visual != 0 && bound != 0) {
        found = 1;
        GetLWMatrix(matrix);

        mgApplyMatrix(world_box.max, world_box.min, matrix,
                      ((mgCFrame::BoundInfo *) bound)->max,
                      ((mgCFrame::BoundInfo *) bound)->min);

        if (attr != 0 && attr->billboard != 0) {
            float extent;
            sceVu0AddVector(center, world_box.max, world_box.min);
            sceVu0ScaleVector(center, center, 0.5f);
            sceVu0SubVector(&half.x, world_box.max, center);

            if (half.x > half.y) {
                extent = half.x > half.z ? half.x : half.z;
            } else {
                extent = half.y > half.z ? half.y : half.z;
            }

            half.z = extent;
            half.y = extent;
            half.x = extent;
            half.w = 0;
            sceVu0AddVector(world_box.max, center, &half.x);
            sceVu0SubVector(world_box.min, center, &half.x);
        }
    }

    for (mgCFrame *node = child; node != 0; node = node->brother) {
        if (node->GetWorldBBox(&child_box) != 0) {
            if (found == 0) {
                world_box = child_box;
            } else {
                mgVectorMaxMin(world_box.max, world_box.min, world_box.max, world_box.min, child_box.max,
                               child_box.min);
            }

            found = 1;
        }
    }

    *box = world_box;
    return found;
}

#pragma global_optimizer reset

int mgCFrame::GetFrameNum() {
    s32       count;
    mgCFrame *node;
    s32       child_count;

    node = child;
    count = 1;

    if (node != NULL) {
        do {
            child_count = node->GetFrameNum();
            node = node->brother;
            count += child_count;
        } while (node != NULL);
    }

    return count;
}

void mgCFrame::SetParent(mgCFrame *parent) {
    if (this->parent == NULL) {
        this->parent = parent;

        if (parent != NULL) {
            parent->SetChild(this);
        }
    }
}

void mgCFrame::SetBrother(mgCFrame *new_brother) {
    if (new_brother != 0) {
        mgCFrame *next = brother;

        if (next != 0) {
            next->SetBrother(new_brother);
        } else {
            brother = new_brother;
            brother->elder = this;
        }
    }
}

void mgCFrame::SetChild(mgCFrame *new_child) {
    mgCFrame *first;

    if (new_child != NULL) {
        first = child;

        if (first != NULL) {
            first->SetBrother(new_child);
        } else {
            child = new_child;
        }

        new_child->parent = this;
    }
}

void mgCFrame::DeleteParent() {
    if (parent != NULL) {
        if (parent->child == this) {
            parent->child = brother;
            parent = NULL;

            if (brother != NULL) {
                brother->elder = NULL;
            }

            brother = NULL;
            elder = NULL;
        } else {
            parent = NULL;

            if (elder != NULL) {
                elder->brother = brother;
            }

            brother = NULL;
            elder = NULL;
        }
    }
}

void mgCFrame::SetReference(mgCFrame *reference) {
    if (parent == NULL && reference != NULL) {
        parent = reference;
        this->reference = 1;
        changed = 1;
    }
}

void mgCFrame::DeleteReference() {
    parent = NULL;
    reference = 0;
    changed = 1;
}

#pragma global_optimizer off

void mgCFrame::ClearChildFlag() {
    mgCFrame *frame;
    int       flag = 1;

    if (child != NULL) {
        child->changed = flag;
        frame = child;

        if (frame->brother != NULL) {
            mgCFrame *next;

            while ((next = frame->brother) != NULL) {
                next->changed = flag;
                frame = frame->brother;
            }

            return;
        }
    }
}

#pragma global_optimizer reset
#pragma schedule reset

#pragma global_optimizer off
void mgCFrame::GetLocalMatrix(float (*matrix)[4]) {
    sceVu0FVECTOR translation;

    if (use_srt) {
        float *factor;
        float (*trans)[4];
        trans = trans_matrix;
        factor = scale;
        asm {
            lqc2 vf10, 0x0(factor)
            lqc2 vf1, 0x0(trans)
            lqc2 vf2, 0x10(trans)
            lqc2 vf3, 0x20(trans)
            lqc2 vf4, 0x30(trans)
            vmul.xyzw vf1, vf1, vf10
            vmul.xyzw vf2, vf2, vf10
            vmul.xyzw vf3, vf3, vf10
            vmulw.xyzw vf4, vf4, vf0w
            sqc2 vf1, 0x0(matrix)
            sqc2 vf2, 0x10(matrix)
            sqc2 vf3, 0x20(matrix)
            sqc2 vf4, 0x30(matrix)
        }
        if (rot_type & MG_FRAME_ROT_LOCAL_ORIGIN) {
            sceVu0CopyVector(translation, matrix[3]);
            mgZeroVectorW(matrix[3]);
        }
        if (rot_type & MG_FRAME_ROT_APPLY) {
            if (rotation[0] != 0.0f) sceVu0RotMatrixX(matrix, matrix, rotation[0]);
            if (rotation[1] != 0.0f) sceVu0RotMatrixY(matrix, matrix, rotation[1]);
            if (rotation[2] != 0.0f) sceVu0RotMatrixZ(matrix, matrix, rotation[2]);
        }
        if (rot_type & MG_FRAME_ROT_LOCAL_ORIGIN) {
            sceVu0AddVector(matrix[3], translation, position);
            matrix[3][3] = 1.0f;
        } else {
            sceVu0AddVector(matrix[3], matrix[3], position);
            matrix[3][3] = 1.0f;
        }
    } else {
        sceVu0CopyMatrix(matrix, trans_matrix);
    }
}
#pragma global_optimizer reset

#pragma global_optimizer off
void mgCFrame::GetBBoardMatrix(int mode, float (*matrix)[4], mgRENDER_INFO *render_info) {
    sceVu0FVECTOR position;
    sceVu0FVECTOR direction;
    sceVu0FVECTOR dimensions;
    sceVu0FMATRIX world;
    sceVu0FMATRIX pitch;

    GetLWMatrix(world);
    dimensions[0] = mgDistVector(world[0]);
    dimensions[1] = mgDistVector(world[0]);
    dimensions[2] = mgDistVector(world[0]);
    *(u_long128 *)position = *(u_long128 *)world[3];
    sceVu0UnitMatrix(matrix);
    if (mode & 2) {
        sceVu0SubVector(matrix[2], render_info->camera_pos, position);
        matrix[2][1] = 0.0f;
        matrix[2][3] = 0.0f;
        sceVu0Normalize(matrix[2], matrix[2]);
        matrix[0][0] = matrix[2][2];
        matrix[0][2] = -matrix[2][0];
        matrix[2][0] = matrix[2][0];
        matrix[2][2] = matrix[2][2];
    }
    if (mode & 1) {
        sceVu0UnitMatrix(pitch);
        sceVu0SubVector(direction, render_info->camera_pos, position);
        sceVu0Normalize(direction, direction);
        float rise = direction[1];
        direction[1] = 0.0f;
        direction[3] = 0.0f;
        float horizontal = mgDistVector(direction);
        pitch[1][1] = horizontal;
        pitch[2][2] = horizontal;
        pitch[1][2] = -rise;
        pitch[2][1] = rise;
        sceVu0SubVector(matrix[2], render_info->camera_pos, position);
        matrix[2][1] = 0.0f;
        matrix[2][3] = 0.0f;
        sceVu0Normalize(matrix[2], matrix[2]);
        matrix[0][0] = matrix[2][2];
        matrix[0][2] = -matrix[2][0];
        mgMulMatrix(matrix, matrix, pitch);
    }
    float *factor = dimensions;
    asm {
        lqc2 vf10, 0x0(factor)
        lqc2 vf1, 0x0(matrix)
        lqc2 vf2, 0x10(matrix)
        lqc2 vf3, 0x20(matrix)
        lqc2 vf4, 0x30(matrix)
        vmul.xyzw vf1, vf1, vf10
        vmul.xyzw vf2, vf2, vf10
        vmul.xyzw vf3, vf3, vf10
        vmulw.xyzw vf4, vf4, vf0w
        sqc2 vf1, 0x0(matrix)
        sqc2 vf2, 0x10(matrix)
        sqc2 vf3, 0x20(matrix)
        sqc2 vf4, 0x30(matrix)
    }
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
    sceVu0CopyMatrix(lw_matrix, matrix);
    changed = 0;
    ClearChildFlag();
}
#pragma global_optimizer reset

#pragma global_optimizer off
void mgCFrame::GetLWMatrix(float (*matrix)[4]) {
    sceVu0FMATRIX parent_matrix;
    sceVu0FMATRIX local;

    switch (reference) {
    case 0:
        break;
    default:
        changed = 1;
        break;
    }
    if (!changed) {
        mgCFrame *frame = parent;
        if (frame == NULL) {
            sceVu0CopyMatrix(matrix, lw_matrix);
            return;
        }
        while (frame != NULL) {
            if (frame->changed) break;
            frame = frame->parent;
            if (frame == NULL) {
                sceVu0CopyMatrix(matrix, lw_matrix);
                return;
            }
        }
    }

    ClearChildFlag();
    GetLocalMatrix(local);
    if (parent == NULL) {
        sceVu0CopyMatrix(lw_matrix, local);
        sceVu0CopyMatrix(matrix, lw_matrix);
        changed = 0;
    } else {
        parent->GetLWMatrix(parent_matrix);
        float (*right)[4];
        float (*left)[4];
        float (*out)[4];
        out = lw_matrix;
        left = parent_matrix;
        right = local;
        asm {
            lqc2 vf5, 0x0(right)
            lqc2 vf1, 0x0(left)
            lqc2 vf2, 0x10(left)
            lqc2 vf3, 0x20(left)
            lqc2 vf4, 0x30(left)
            vmulax.xyzw ACC, vf1, vf5x
            vmadday.xyzw ACC, vf2, vf5y
            vmaddaz.xyzw ACC, vf3, vf5z
            vmaddw.xyzw vf20, vf4, vf5w
            lqc2 vf6, 0x10(right)
            lqc2 vf7, 0x20(right)
            lqc2 vf8, 0x30(right)
            vmulax.xyzw ACC, vf1, vf6x
            vmadday.xyzw ACC, vf2, vf6y
            vmaddaz.xyzw ACC, vf3, vf6z
            vmaddw.xyzw vf21, vf4, vf6w
            vmulax.xyzw ACC, vf1, vf7x
            vmadday.xyzw ACC, vf2, vf7y
            vmaddaz.xyzw ACC, vf3, vf7z
            vmaddw.xyzw vf22, vf4, vf7w
            vmulax.xyzw ACC, vf1, vf8x
            vmadday.xyzw ACC, vf2, vf8y
            vmaddaz.xyzw ACC, vf3, vf8z
            vmaddw.xyzw vf23, vf4, vf8w
            sqc2 vf20, 0x0(out)
            sqc2 vf21, 0x10(out)
            sqc2 vf22, 0x20(out)
            sqc2 vf23, 0x30(out)
            sqc2 vf20, 0x0(matrix)
            sqc2 vf21, 0x10(matrix)
            sqc2 vf22, 0x20(matrix)
            sqc2 vf23, 0x30(matrix)
        }
        changed = 0;
    }
}
#pragma global_optimizer reset

#pragma global_optimizer off
void mgCFrame::GetLWMatrixTopBottom(float (*matrix)[4]) {
    sceVu0FMATRIX parent_matrix;
    sceVu0FMATRIX local;

    if (reference) {
        GetLWMatrix(matrix);
        return;
    }
    if (!changed) {
        if (parent == NULL) {
            sceVu0CopyMatrix(matrix, lw_matrix);
            return;
        }
        if (!parent->changed) {
            sceVu0CopyMatrix(matrix, lw_matrix);
            return;
        }
    }
    ClearChildFlag();
    GetLocalMatrix(local);
    if (parent == NULL) {
        sceVu0CopyMatrix(lw_matrix, local);
        sceVu0CopyMatrix(matrix, lw_matrix);
        changed = 0;
    } else {
        sceVu0CopyMatrix(parent_matrix, parent->lw_matrix);
        float (*right)[4];
        float (*left)[4];
        float (*out)[4];
        out = lw_matrix;
        left = parent_matrix;
        right = local;
        asm {
            lqc2 vf5, 0x0(right)
            lqc2 vf1, 0x0(left)
            lqc2 vf2, 0x10(left)
            lqc2 vf3, 0x20(left)
            lqc2 vf4, 0x30(left)
            vmulax.xyzw ACC, vf1, vf5x
            vmadday.xyzw ACC, vf2, vf5y
            vmaddaz.xyzw ACC, vf3, vf5z
            vmaddw.xyzw vf20, vf4, vf5w
            lqc2 vf6, 0x10(right)
            lqc2 vf7, 0x20(right)
            lqc2 vf8, 0x30(right)
            vmulax.xyzw ACC, vf1, vf6x
            vmadday.xyzw ACC, vf2, vf6y
            vmaddaz.xyzw ACC, vf3, vf6z
            vmaddw.xyzw vf21, vf4, vf6w
            vmulax.xyzw ACC, vf1, vf7x
            vmadday.xyzw ACC, vf2, vf7y
            vmaddaz.xyzw ACC, vf3, vf7z
            vmaddw.xyzw vf22, vf4, vf7w
            vmulax.xyzw ACC, vf1, vf8x
            vmadday.xyzw ACC, vf2, vf8y
            vmaddaz.xyzw ACC, vf3, vf8z
            vmaddw.xyzw vf23, vf4, vf8w
            sqc2 vf20, 0x0(out)
            sqc2 vf21, 0x10(out)
            sqc2 vf22, 0x20(out)
            sqc2 vf23, 0x30(out)
            sqc2 vf20, 0x0(matrix)
            sqc2 vf21, 0x10(matrix)
            sqc2 vf22, 0x20(matrix)
            sqc2 vf23, 0x30(matrix)
        }
        changed = 0;
    }
}
#pragma global_optimizer reset

void mgCFrame::GetInverseMatrix(float (*matrix)[4]) {
    sceVu0FMATRIX lw;
    sceVu0FVECTOR translation;
    float         det;
    float         inv_det;

    GetLWMatrix(lw);
    det = 0.0f;
    det += lw[0][0] * lw[1][1] * lw[2][2];
    det += lw[0][1] * lw[1][2] * lw[2][0];
    det += lw[0][2] * lw[1][0] * lw[2][1];
    det -= lw[0][0] * lw[1][2] * lw[2][1];
    det -= lw[0][1] * lw[1][0] * lw[2][2];
    det -= lw[0][2] * lw[1][1] * lw[2][0];
    sceVu0UnitMatrix(matrix);
    inv_det = 1.0f / det;

    matrix[0][0] = lw[1][1] * lw[2][2] - lw[1][2] * lw[2][1];
    matrix[1][0] = lw[1][2] * lw[2][0] - lw[1][0] * lw[2][2];
    matrix[2][0] = lw[1][0] * lw[2][1] - lw[1][1] * lw[2][0];
    matrix[0][1] = lw[2][1] * lw[0][2] - lw[2][2] * lw[0][1];
    matrix[1][1] = lw[2][2] * lw[0][0] - lw[2][0] * lw[0][2];
    matrix[2][1] = lw[2][0] * lw[0][1] - lw[2][1] * lw[0][0];
    matrix[0][2] = lw[0][1] * lw[1][2] - lw[0][2] * lw[1][1];
    matrix[1][2] = lw[0][2] * lw[1][0] - lw[0][0] * lw[1][2];
    matrix[2][2] = lw[0][0] * lw[1][1] - lw[0][1] * lw[1][0];
    sceVu0ScaleVector(matrix[0], matrix[0], inv_det);
    sceVu0ScaleVector(matrix[1], matrix[1], inv_det);
    sceVu0ScaleVector(matrix[2], matrix[2], inv_det);

    sceVu0ApplyMatrix(translation, matrix, lw[3]);
    sceVu0ScaleVectorXYZ(matrix[3], translation, -1.0f);
    matrix[3][3] = 1.0f;
}

void mgCFrame::SetTransMatrix(float (*matrix)[4]) {
    sceVu0CopyMatrix(trans_matrix, matrix);
    changed = 1;
}

/**
 *
 * Compares two frame names up to their "--" flags. Returns 1 when they match, 0 otherwise.
 *
 */
static int StrCmp(char *left, char *right) {
    if (left == 0 || right == 0) {
        return 0;
    }

    char *end_a = left;
    char *end_b = right;
    s32   ch;
    s32   length_a = 0;
    s32   length_b = 0;

    while ((ch = *end_a) != 0) {
        if ((s8) ch == '-' && end_a[1] == '-') {
            break;
        }

        length_a++;
        end_a++;
    }

    while ((ch = *end_b) != 0) {
        if ((s8) ch == '-' && end_b[1] == '-') {
            break;
        }

        length_b++;
        end_b++;
    }

    if (length_a != length_b) {
        return 0;
    }

    char *pa = left;
    char *pb = right;

    for (s32 i = 0; i < length_a; i++, pa++, pb++) {
        if (*pa != *pb) {
            return 0;
        }
    }

    return 1;
}

int mgFrameNameComp(char *left, char *right) {
    return StrCmp(left, right);
}

mgCFrame *mgCFrame::SearchFrame(char *name) {
    mgCFrame *found;
    mgCFrame *node;

    if (StrCmp(this->name, name) != 0) {
        return this;
    }

    for (node = child; node != 0; node = node->brother) {
        if ((found = node->SearchFrame(name)) != 0) {
            return found;
        }
    }

    return 0;
}

int mgCFrame::SearchFrameID(char *name) {
    if (frame_list == 0) {
        return -1;
    }

    s32 index = 0;

    while (index < frame_num) {
        mgCFrame *entry = frame_list[index];

        if (entry != 0 && StrCmp(entry->name, name) != 0) {
            return index;
        }

        index++;
    }

    return -1;
}

void mgCFrame::GetWorldPosition(float *out_position, float *local_position) {
    sceVu0FMATRIX lw;

    local_position[3] = 1.0f;
    GetLWMatrix(lw);
    sceVu0ApplyMatrix(out_position, lw, local_position);
}

void mgCFrame::GetWorldPosition0(float *out_position) {
    sceVu0FMATRIX lw;

    GetLWMatrix(lw);
    *(u_long128 *) out_position = *(u_long128 *) lw[3];
}

void mgCFrame::GetWorldDir(float *out_dir, float *local_dir) {
    sceVu0FMATRIX lw;
    float         w;

    // A w of zero leaves the translation out of the transform.
    w = local_dir[3];
    local_dir[3] = 0.0f;
    GetLWMatrix(lw);
    sceVu0ApplyMatrix(out_dir, lw, local_dir);
    local_dir[3] = w;
}

void mgCFrame::SetRotation(float *rot) {
    rot_type |= 1;
    mgCObject::SetRotation(rot);
}

void mgCFrame::SetRotation(float x, float y, float z) {
    float rotation[4];
    *(u_long128 *) rotation = *(u_long128 *) at_844;
    rotation[0] = x;
    rotation[1] = y;
    rotation[2] = z;

    SetRotation(rotation);
}

void mgCFrame::SetRotType(int type) {
    rot_type = type;

    if (type & MG_FRAME_ROT_LOCAL_ORIGIN) {
        rot_type |= MG_FRAME_ROT_APPLY;
    }
}

void mgCFrame::SetAttrParam(mgCFrameAttr &attr, int recurse, int mask) {
    mgCFrameAttr *dst = this->attr;

    if (dst != 0) {
        if (mask == 0) {
            dst->alpha_ref = attr.alpha_ref;
            dst->alpha_blend = attr.alpha_blend;
            dst->z_write = attr.z_write;
            dst->z_test = attr.z_test;
            dst->alpha_test = attr.alpha_test;
            dst->dest_alpha_test = attr.dest_alpha_test;
            dst->draw = attr.draw;
            dst->clip_enable = attr.clip_enable;
            dst->unk_20 = attr.unk_20;
            dst->unk_24 = attr.unk_24;
            dst->unk_28 = attr.unk_28;
            dst->program_option = attr.program_option;
            dst->fog = attr.fog;
            dst->unk_34 = attr.unk_34;
            dst->unk_38 = attr.unk_38;
            dst->unk_3c = attr.unk_3c;
            dst->program_mode = attr.program_mode;
            dst->obj_alpha = attr.obj_alpha;
            dst->no_cull = attr.no_cull;
            dst->ambient_boost = attr.ambient_boost;
            *(mgVec4 *) &dst->unk_50[0] = *(mgVec4 *) &attr.unk_50[0];
            dst->no_light = attr.no_light;
            *(mgVec4 *) dst->color = *(mgVec4 *) attr.color;
            dst->point_light = attr.point_light;
            dst->unk_84 = attr.unk_84;
            dst->billboard = attr.billboard;
            dst->depth_bias = attr.depth_bias;
        } else {
            if (mask & 0x1) {
                dst->draw = attr.draw;
            }

            if (mask & 0x2) {
                this->attr->alpha_ref = attr.alpha_ref;
            }

            if (mask & 0x4) {
                this->attr->alpha_blend = attr.alpha_blend;
            }

            if (mask & 0x8) {
                this->attr->z_write = attr.z_write;
            }

            if (mask & 0x10) {
                this->attr->z_test = attr.z_test;
            }

            if (mask & 0x20) {
                this->attr->clip_enable = attr.clip_enable;
            }

            if (mask & 0x40) {
                this->attr->unk_20 = attr.unk_20;
            }

            if (mask & 0x80) {
                this->attr->unk_24 = attr.unk_24;
            }

            if (mask & 0x100) {
                this->attr->unk_28 = attr.unk_28;
            }

            if (mask & 0x200) {
                this->attr->program_option = attr.program_option;
            }

            if (mask & 0x400) {
                this->attr->fog = attr.fog;
            }

            if (mask & 0x800) {
                this->attr->unk_34 = attr.unk_34;
            }

            if (mask & 0x1000) {
                this->attr->unk_38 = attr.unk_38;
            }

            if (mask & 0x2000) {
                this->attr->unk_3c = attr.unk_3c;
            }

            if (mask & 0x4000) {
                this->attr->program_mode = attr.program_mode;
            }

            if (mask & 0x8000) {
                this->attr->no_light = attr.no_light;
            }

            if (mask & 0x10000) {
                *(u_long128 *) this->attr->color = *(u_long128 *) attr.color;
            }

            if (mask & 0x20000) {
                this->attr->point_light = attr.point_light;
            }

            if (mask & 0x40000) {
                this->attr->obj_alpha = attr.obj_alpha;
            }

            if (mask & 0x80000) {
                this->attr->billboard = attr.billboard;
            }

            if (mask & 0x100000) {
                this->attr->no_cull = attr.no_cull;
            }

            if (mask & 0x200000) {
                this->attr->depth_bias = attr.depth_bias;
            }

            if (mask & 0x800000) {
                this->attr->ambient_boost = attr.ambient_boost;
            }

            if (mask & 0x400000) {
                this->attr->dest_alpha_test = attr.dest_alpha_test;
            }
        }
    }

    if (recurse == 0) {
        return;
    }

    mgCFrame *frame = child;

    if (frame != 0) {
        do {
            frame->SetAttrParam(attr, 1, mask);
            frame = frame->brother;
        } while (frame != 0);
    }
}

void mgCFrame::SetAttrParamObjAlpha(float alpha, int recurse) {
    if (attr != 0) {
        this->attr->obj_alpha = alpha;
    }

    if (recurse == 0) {
        return;
    }

    mgCFrame *frame = child;

    if (frame != 0) {
        do {
            frame->SetAttrParamObjAlpha(alpha, 1);
            frame = frame->brother;
        } while (frame != 0);
    }
}

void mgCFrame::SetAttrParamDraw(int value, int recurse) {
    mgCFrameAttr *attr;
    mgCFrame     *node;

    attr = this->attr;

    if (attr != NULL) {
        this->attr->draw = value;
    }

    if (recurse == 0) {
        return;
    }

    for (node = child; node != NULL; node = node->brother) {
        node->SetAttrParamDraw(value, 1);
    }
}

#ifdef NONMATCHING
// 63.2% match, 188 words off
int mgCFrame::Draw(unsigned int *packet) {
    int           words = 0;
    sceVu0FMATRIX world;
    if (attr != NULL && attr->billboard != 0) {
        GetBBoardMatrix(attr->billboard, world, &mgRenderInfo);
    } else {
        GetLWMatrixTopBottom(world);
    }

    if (attr != NULL && (attr->draw & MG_FRAME_DRAW_VISIBLE) && visual != NULL) {
        bool visible = true;
        if (!attr->no_cull && bound != NULL) {
            sceVu0FVECTOR screen_max;
            sceVu0FVECTOR screen_min;
            visible = mgInsideScreen(bound->corner, world, screen_max, screen_min) != 0;
            if (visible) {
                mgRenderInfo.clip = mgClipInBoxW(screen_max, screen_min,
                                                 mgRenderInfo.gs_box_max,
                                                 mgRenderInfo.gs_box_min) == 0;
                mgRenderInfo.scissor = (attr->program_mode & 2)
                                           ? attr->clip_enable != 0
                                           : (attr->clip_enable != 0 || mgRenderInfo.all_scissor != 0);
            }
        }
        if (visible) {
            mgRenderInfo.attr = attr;
            sceVu0CopyVector(mgRenderInfo.object_color, attr->color);
            mgRenderInfo.plight_hit = 0;
            if (mgRenderInfo.plight_enable && attr->point_light &&
                !attr->no_light && bound != NULL) {
                sceVu0FMATRIX transposed;
                sceVu0TransposeMatrix(transposed, world);
                float scale = mgDistVector(transposed[0]);
                float y_scale = mgDistVector(transposed[1]);
                float z_scale = mgDistVector(transposed[2]);
                if (y_scale > scale) {
                    scale = y_scale;
                }
                if (z_scale > scale) {
                    scale = z_scale;
                }
                float         radius = bound->radius * scale;
                sceVu0FVECTOR center;
                sceVu0CopyVector(center, bound->center);
                center[3] = 1.0f;
                sceVu0ApplyMatrix(center, world, center);
                mgLIGHT_INFO *light = mgRenderInfo.GetpLightInfo();
                for (int i = 0; i < 4; i++) {
                    mgPOINT_LIGHT &point = light->point_light[i];
                    if (point.power > 0.0f &&
                        mgDistVector(point.pos, center) < radius + point.range) {
                        mgRenderInfo.plight_hit = 1;
                        break;
                    }
                }
            }
            words = visual->Draw(packet, world, NULL);
        }
    }
    if (attr != NULL && (attr->draw & MG_FRAME_DRAW_SKIP_CHILDREN)) {
        return words;
    }
    for (mgCFrame *node = child; node != NULL; node = node->brother) {
        if (node->attr == NULL || (node->attr->draw & MG_FRAME_DRAW_SKIP_BY_PARENT) == 0) {
            words += node->Draw(packet + words * 4);
        }
    }
    return words;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", Draw__8mgCFrameFPUi);
#endif

#pragma global_optimizer off
#ifdef NONMATCHING
// 20.4% match, 337 words off
int mgCFrame::GetDrawRect(mgVu0FBOX *rect, mgCDrawManager *manager) {
    if (manager == NULL) {
        manager = &mgDrawManager;
    }
    mgRENDER_INFO *render = manager->render_info;
    mgCFrameAttr  *draw_attr = attr != NULL ? attr : &dmy_attr;
    sceVu0FMATRIX  world;
    if (draw_attr->billboard != 0) {
        GetBBoardMatrix(draw_attr->billboard, world, render);
    } else {
        GetLWMatrixTopBottom(world);
    }

    int found = 0;
    if ((draw_attr->draw & MG_FRAME_DRAW_VISIBLE) && visual != NULL && bound != NULL) {
        sceVu0FMATRIX screen;
        sceVu0MulMatrix(screen, render->world_screen_rel, world);
        sceVu0FVECTOR maximum;
        sceVu0FVECTOR minimum;
        for (int i = 0; i < 8; i++) {
            sceVu0FVECTOR point;
            sceVu0ApplyMatrix(point, screen, bound->corner[i]);
            float depth = point[3] < 0.0f ? -point[3] : point[3];
            point[0] /= depth;
            point[1] /= depth;
            if (i == 0) {
                sceVu0CopyVector(maximum, point);
                sceVu0CopyVector(minimum, point);
            } else {
                for (int axis = 0; axis < 4; axis++) {
                    if (maximum[axis] < point[axis]) {
                        maximum[axis] = point[axis];
                    }
                    if (minimum[axis] > point[axis]) {
                        minimum[axis] = point[axis];
                    }
                }
            }
        }
        float half_width = (float) mgScreenWidth * 0.5f;
        float half_height = (float) mgScreenHeight * 0.5f;
        if (maximum[0] >= -half_width && minimum[0] <= half_width &&
            maximum[1] >= -half_height && minimum[1] <= half_height &&
            minimum[3] >= (float) render->scissor) {
            maximum[0] += half_width;
            minimum[0] += half_width;
            maximum[1] += half_height;
            minimum[1] += half_height;
            sceVu0CopyVector(rect->max, maximum);
            sceVu0CopyVector(rect->min, minimum);
            found = 1;
        }
    }
    if (draw_attr->draw & MG_FRAME_DRAW_SKIP_CHILDREN) {
        return found;
    }
    for (mgCFrame *node = child; node != NULL; node = node->brother) {
        if (node->attr != NULL && (node->attr->draw & MG_FRAME_DRAW_SKIP_BY_PARENT)) {
            continue;
        }
        mgVu0FBOX child_rect;
        if (node->GetDrawRect(&child_rect, NULL)) {
            if (found == 0) {
                *rect = child_rect;
            } else {
                mgVectorMaxMin(rect->max, rect->min, rect->max, rect->min,
                               child_rect.max, child_rect.min);
            }
            found = 1;
        }
    }
    return found;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_frame", GetDrawRect__8mgCFrameFP9mgVu0FBOXP14mgCDrawManager);
#endif
#pragma global_optimizer reset

mgCFrame &mgCFrame::operator=(mgCFrame &other) {
    memcpy(this, &other, sizeof(mgCFrame));
    parent = child = brother = NULL;
    changed = 1;
    reference = 0;

    // The copy builds its matrix from its parts unless they are all at their defaults.
    use_srt = 0;

    if (position[0] != 0.0f || position[1] != 0.0f || position[2] != 0.0f) {
        use_srt = 1;
    }

    if (rotation[0] != 0.0f || rotation[1] != 0.0f || rotation[2] != 0.0f) {
        use_srt = 1;
    }

    if (scale[0] != 1.0f || scale[1] != 1.0f || scale[2] != 1.0f) {
        use_srt = 1;
    }

    return *this;
}

int mgCFrame::Draw() {
    return Draw(NULL);
}

void mgCObject::ChangeParam() {
    changed = 1;
}

void mgCObject::UseParam() {
    changed = 1;
}

int mgCObject::DrawDirect() {
    return 0;
}

int mgCObject::Draw() {
    return 0;
}

// Static initialiser (.init)

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", at_307__DATA);

// Static initialiser table (.ctor)

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", __vt__8mgCFrame__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", __vt__12mgCFrameBase__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_frame", __vt__9mgCObject__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_324, 0x10);
INCLUDE_BSS(at_341, 0x10);
INCLUDE_BSS(at_844, 0x10);
INCLUDE_BSS(at_1118, 0x10);
INCLUDE_BSS(at_1119, 0x10);
