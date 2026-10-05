#include "common.h"

#include "occlusion.hpp"
#include "mg_math.hpp"

// Code (.text)
#ifdef NONMATCHING
void COcclusion::Setup(sceVu0FMATRIX view_matrix) {
    if (enable == 0) {
        return;
    }

    setup = 1;
    sceVu0FVECTOR view_vertex[4];
    sceVu0FVECTOR origin;
    mgApplyMatrixN(view_vertex, view_matrix, vertex, 4);
    mgVectorMin(view_min, view_vertex[0], view_vertex[1], view_vertex[2], view_vertex[3]);
    mgZeroVector(origin);

    mgPlaneNormal(plane, view_vertex[2], view_vertex[1], view_vertex[0]);
    sceVu0Normalize(plane, plane);
    plane[3] = -sceVu0InnerProduct(plane, view_vertex[0]);

    if (plane[3] > 0.0f) {
        mgPlaneNormal(plane, view_vertex[0], view_vertex[1], view_vertex[2]);
        sceVu0Normalize(plane, plane);
        plane[3] = -sceVu0InnerProduct(plane, view_vertex[0]);
        mgPlaneNormal(side_plane[0], origin, view_vertex[1], view_vertex[2]);
        mgPlaneNormal(side_plane[1], origin, view_vertex[3], view_vertex[0]);
        mgPlaneNormal(side_plane[2], origin, view_vertex[0], view_vertex[1]);
        mgPlaneNormal(side_plane[3], origin, view_vertex[2], view_vertex[3]);
    } else {
        mgPlaneNormal(side_plane[0], origin, view_vertex[2], view_vertex[1]);
        mgPlaneNormal(side_plane[1], origin, view_vertex[0], view_vertex[3]);
        mgPlaneNormal(side_plane[2], origin, view_vertex[1], view_vertex[0]);
        mgPlaneNormal(side_plane[3], origin, view_vertex[3], view_vertex[2]);
    }

    for (int side = 0; side < 4; ++side) {
        sceVu0Normalize(side_plane[side], side_plane[side]);
        side_plane[side][3] = 0.0f;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/occlusion", Setup__10COcclusionFPA4_f);
#endif
#ifdef NONMATCHING
int COcclusion::CheckSphere(sceVu0FVECTOR sphere) {
    if (enable == 0 || setup == 0) {
        return 0;
    }
    if (sphere[2] - sphere[3] < view_min[2]) {
        return 0;
    }
    if (sceVu0InnerProduct(plane, sphere) + plane[3] < sphere[3]) {
        return 0;
    }
    for (int side = 0; side < 4; ++side) {
        if (sceVu0InnerProduct(side_plane[side], sphere) < sphere[3]) {
            return 0;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/occlusion", CheckSphere__10COcclusionFPf);
#endif
