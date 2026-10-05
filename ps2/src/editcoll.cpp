#include "common.h"
#include "editcoll.hpp"

#include <libvu0.h>

#include "mg_math.hpp"
#include "mg_memory.hpp"

// Code (.text)
int ClipBoxXZ(float *max_a, float *min_a, float *max_b, float *min_b) {
    register int status;

    // Only the sign flags of the two subtractions matter: any negative component means apart.
    asm {
        lqc2 $vf10, 0x0($4)
        lqc2 $vf11, 0x0($5)
        lqc2 $vf1, 0x0($6)
        lqc2 $vf2, 0x0($7)
        vnop
        vnop
        vnop
        ctc2.ni $0, $vi16
        vsub.xz $vf25, $vf10, $vf2
        vsub.xz $vf25, $vf1, $vf11
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni status, $vi16
    }

    return (status & MG_VU0_STATUS_SIGN_STICKY) == 0;
}

#ifdef NONMATCHING
float OverlapPoly3AreaXZ(float (*clipped)[4], float (*clipper)[4], mgVu0FBOX *box) {
    sceVu0FVECTOR  polygon[2][7];
    sceVu0FVECTOR  clip[4];
    sceVu0FVECTOR  vertex;
    sceVu0FVECTOR  edge;
    sceVu0FVECTOR  segment;
    sceVu0FVECTOR  to_start;
    sceVu0FVECTOR  to_end;
    sceVu0FVECTOR  crossing;
    sceVu0FVECTOR  side0;
    sceVu0FVECTOR  side1;
    sceVu0FVECTOR  plane;
    sceVu0FVECTOR *result;
    float         *start;
    float         *end;
    float          denominator;
    float          area;
    int            start_inside;
    int            end_inside;
    int            cur;
    int            count;
    int            out;
    int            side;
    int            i;

    cur = 0;
    count = 3;

    // Both triangles are flattened onto the XZ plane and closed by repeating the first corner.
    *(u_long128 *)polygon[0][0] = *(u_long128 *)clipped[0];
    polygon[0][0][1] = 0.0f;
    *(u_long128 *)polygon[0][1] = *(u_long128 *)clipped[1];
    polygon[0][1][1] = 0.0f;
    *(u_long128 *)polygon[0][2] = *(u_long128 *)clipped[2];
    polygon[0][2][1] = 0.0f;
    *(u_long128 *)polygon[0][3] = *(u_long128 *)clipped[0];
    polygon[0][3][1] = 0.0f;
    *(u_long128 *)clip[0] = *(u_long128 *)clipper[0];
    clip[0][1] = 0.0f;
    *(u_long128 *)clip[1] = *(u_long128 *)clipper[1];
    clip[1][1] = 0.0f;
    *(u_long128 *)clip[2] = *(u_long128 *)clipper[2];
    clip[2][1] = 0.0f;
    *(u_long128 *)clip[3] = *(u_long128 *)clipper[0];
    clip[3][1] = 0.0f;

    // Clips the polygon against each edge of the clipper in turn, keeping the part on its inner side.
    for (side = 0; side < 3; side++) {
        sceVu0SubVector(edge, clip[side + 1], clip[side]);
        out = 0;

        for (i = 0; i < count; i++) {
            start = polygon[cur][i];
            end = polygon[cur][i + 1];
            sceVu0SubVector(segment, end, start);
            start_inside = 0;
            end_inside = 0;
            sceVu0SubVector(to_start, start, clip[side]);
            sceVu0SubVector(to_end, end, clip[side]);

            if (-edge[0] * to_start[2] + edge[2] * to_start[0] >= 0.0f) {
                start_inside = 1;
                *(u_long128 *)polygon[!cur][out++] = *(u_long128 *)start;
            }

            if (-edge[0] * to_end[2] + edge[2] * to_end[0] >= 0.0f) {
                end_inside = 1;
            }

            // A side that crosses the clipping line adds the crossing point.
            if (!(start_inside && end_inside) && (start_inside || end_inside)) {
                sceVu0SubVector(to_start, start, clip[side]);
                denominator = segment[0] * edge[2] - segment[2] * edge[0];
                if (denominator != 0.0f) {
                    sceVu0ScaleVector(crossing, segment, (edge[0] * to_start[2] - edge[2] * to_start[0]) / denominator);
                    mgAddVector(crossing, start);
                    *(u_long128 *)polygon[!cur][out++] = *(u_long128 *)crossing;
                }
            }
        }

        count = out;
        cur = !cur;
        result = polygon[cur];
        *(u_long128 *)result[count] = *(u_long128 *)result[0];
    }

    if (count < 3) {
        return 0.0f;
    }

    area = 0.0f;
    for (i = 0; i < count; i++) {
        area += -result[i][0] * result[i + 1][2] + result[i + 1][0] * result[i][2];
    }
    area *= 0.5f;

    if (box != NULL) {
        // The clipper's plane, which lifts the overlap's corners back off the XZ plane.
        sceVu0SubVector(side0, clipper[1], clipper[0]);
        sceVu0SubVector(side1, clipper[2], clipper[1]);
        sceVu0OuterProduct(plane, side0, side1);
        plane[3] = -sceVu0InnerProduct(plane, clipper[0]);

        for (i = 0; i < count; i++) {
            *(u_long128 *)vertex = *(u_long128 *)result[i];
            result[i][1] = -(plane[3] + (vertex[0] * plane[0] + vertex[2] * plane[2])) / plane[1];

            if (i == 0) {
                *(u_long128 *)box->max = *(u_long128 *)result[i];
                *(u_long128 *)box->min = *(u_long128 *)result[i];
            } else {
                mgVectorMaxMin(box->max, box->min, box->max, box->min, result[i]);
            }
        }
    }

    return area;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapPoly3AreaXZ__FPA4_fPA4_fP9mgVu0FBOX);
#endif

#ifdef NONMATCHING
void CEditCollision::Copy(CEditCollision &dest, int area_kind, mgCMemory *memory) {
    u_int size;
    int   count;
    int   out;
    int   i;

    count = 0;
    for (i = 0; i < poly_count; i++) {
        if (poly[i].area_kind == area_kind) {
            count++;
        }
    }

    if (count < 1 || memory == NULL) {
        dest.poly_count = 0;
        dest.poly = NULL;
        return;
    }

    size = count * sizeof(CCPoly);
    dest.poly_count = count;
    dest.poly = new (memory->Alloc(((size & 0xF) != 0 ? size / 16 + 1 : size / 16) + 2)) CCPoly[count];

    if (dest.poly != NULL) {
        out = 0;
        for (i = 0; i < poly_count; i++) {
            if (poly[i].area_kind == area_kind) {
                dest.poly[out++] = poly[i];
            }
        }
    }

    CreateBBox();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", Copy__14CEditCollisionFR14CEditCollisioniP9mgCMemory);
#endif

#ifdef NONMATCHING
float CEditCollision::AreaXZ() {
    CCPoly *p;
    float   area;
    float   total;
    int     count;
    int     i;

    total = 0.0f;
    count = poly_count;
    p = poly;
    for (i = 0; i < count; i++, p++) {
        area = 0.5f * (-p->vertex[0][0] * p->vertex[1][2] + p->vertex[1][0] * p->vertex[0][2] +
                       (-p->vertex[1][0] * p->vertex[2][2] + p->vertex[2][0] * p->vertex[1][2]) +
                       (-p->vertex[2][0] * p->vertex[0][2] + p->vertex[0][0] * p->vertex[2][2]));
        total += area < 0.0f ? -area : area;
    }

    return total;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", AreaXZ__14CEditCollisionFv);
#endif

int CEditCollision::OverlapPoly3XZ(float (*triangle)[4], float *area, mgVu0FBOX *box) {
    sceVu0FVECTOR tri_max;
    sceVu0FVECTOR tri_min;
    mgVu0FBOX     overlap_box;
    sceVu0FVECTOR poly_max;
    sceVu0FVECTOR poly_min;
    CCPoly       *p;
    float         overlap;
    float         total;
    int           overlap_count;
    int           i;

    p = poly;
    if (p == NULL) {
        return 0;
    }

    mgVectorMaxMin(tri_max, tri_min, triangle[0], triangle[1], triangle[2]);

    if (area != NULL) {
        *area = 0.0f;
    }

    if (box != NULL) {
        mgZeroVectorW(box->max);
        mgZeroVectorW(box->min);
    }

    if (!ClipBoxXZ(tri_max, tri_min, bbox.max, bbox.min)) {
        return 0;
    }

    total = 0.0f;
    overlap_count = 0;
    for (i = 0; i < poly_count; i++, p++) {
        mgVectorMaxMin(poly_max, poly_min, p->vertex[0], p->vertex[1], p->vertex[2]);
        if (ClipBoxXZ(tri_max, tri_min, poly_max, poly_min)) {
            overlap = OverlapPoly3AreaXZ(triangle, p->vertex, &overlap_box);
            overlap = overlap < 0.0f ? -overlap : overlap;
            total += overlap;

            if (overlap > 0.0) {
                if (box != NULL) {
                    if (overlap_count == 0) {
                        *box = overlap_box;
                    } else {
                        mgBoxMaxMin(box, &overlap_box);
                    }
                }
                overlap_count++;
            }
        }
    }

    if (area != NULL) {
        *area = total;
    }

    if (total > 0.0f) {
        return 1;
    }

    return 0;
}

#ifdef NONMATCHING
float CEditCollision::OverlapXZ(CEditCollision &other, float (*matrix)[4], mgVu0FBOX *box) {
    sceVu0FVECTOR triangle[3];
    mgVu0FBOX     overlap_box;
    float         area;
    CCPoly       *p;
    float         total;
    int           count;
    int           merged;
    int           i;

    total = 0.0f;
    merged = 0;
    count = other.poly_count;
    p = other.poly;
    for (i = 0; i < count; i++, p++) {
        mgApplyMatrixN(triangle, matrix, p->vertex, 3);
        if (OverlapPoly3XZ(triangle, &area, &overlap_box)) {
            total += area;

            if (box != NULL) {
                if (merged == 0) {
                    merged = 1;
                    *box = overlap_box;
                } else {
                    mgBoxMaxMin(box, &overlap_box);
                }
            }
        }
    }

    return total;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapXZ__14CEditCollisionFR14CEditCollisionPA4_fP9mgVu0FBOX);
#endif

#ifdef NONMATCHING
int CEditCollision::OverlapPoly3XZ(float (*triangle)[4], float (*matrix)[4], float *area) {
    sceVu0FVECTOR tri_max;
    sceVu0FVECTOR tri_min;
    sceVu0FVECTOR box_max;
    sceVu0FVECTOR box_min;
    sceVu0FVECTOR placed[3];
    CCPoly       *p;
    float         overlap;
    float         total;
    int           i;

    p = poly;
    if (p == NULL) {
        return 0;
    }

    mgVectorMaxMin(tri_max, tri_min, triangle[0], triangle[1], triangle[2]);

    if (area != NULL) {
        *area = 0.0f;
    }

    mgApplyMatrix(box_max, box_min, matrix, bbox.max, bbox.min);
    if (!ClipBoxXZ(tri_max, tri_min, box_max, box_min)) {
        return 0;
    }

    total = 0.0f;
    for (i = 0; i < poly_count; i++, p++) {
        mgApplyMatrixN(placed, matrix, p->vertex, 3);

        // Only triangles with no corner above ground level count.
        if (placed[0][1] <= 0.1f && placed[1][1] <= 0.1f && placed[2][1] <= 0.1f) {
            overlap = OverlapPoly3AreaXZ(triangle, placed, NULL);
            total += overlap < 0.0f ? -overlap : overlap;
        }
    }

    if (area != NULL) {
        *area = total;
    }

    if (total > 0.0f) {
        return 1;
    }

    return 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapPoly3XZ__14CEditCollisionFPA4_fPA4_fPf);
#endif

void CEditCollision::ApplyMatrix(float (*matrix)[4]) {
    CCPoly *p;
    int     i;
    int     j;

    p = poly;
    if (p == NULL) {
        return;
    }

    for (i = 0; i < poly_count; i++, p++) {
        mgApplyMatrixN(p->vertex, matrix, p->vertex, 3);

        // Heights are rounded to the nearest whole unit.
        for (j = 0; j < 3; j++) {
            if (p->vertex[j][1] > 0.0f) {
                p->vertex[j][1] = (int)(p->vertex[j][1] + 0.5f);
            } else {
                p->vertex[j][1] = (int)(p->vertex[j][1] - 0.5f);
            }
        }

        mgPlaneNormal(p->normal, p->vertex[0], p->vertex[1], p->vertex[2]);
        sceVu0Normalize(p->normal, p->normal);
    }

    CreateBBox();
}

#ifdef NONMATCHING
void CEditCollision::DeleteVerticalPoly() {
    sceVu0FVECTOR normal;
    CCPoly       *polys;
    CCPoly       *p;
    int           i;

    polys = poly;
    if (polys == NULL) {
        return;
    }

    // A vertical triangle is replaced by the last one, which is then examined in its place.
    for (i = 0; i < poly_count; i++) {
        p = &polys[i];
        sceVu0Normalize(normal, p->normal);
        if ((normal[1] < 0.0f ? -normal[1] : normal[1]) < 0.01f) {
            if (poly_count == 0) {
                break;
            }
            poly_count--;
            i--;
            *p = poly[poly_count];
        }
    }

    CreateBBox();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", DeleteVerticalPoly__14CEditCollisionFv);
#endif

#ifdef NONMATCHING
int CEditCollision::PickupVerticalPoly() {
    sceVu0FVECTOR normal;
    sceVu0FVECTOR normal_a;
    sceVu0FVECTOR normal_b;
    CCPoly       *polys;
    CCPoly       *p;
    CCPoly       *same_wall;
    float         distance;
    int           wall_count;
    int           i;
    int           j;

    polys = poly;
    if (polys == NULL) {
        return 0;
    }

    // A triangle that is not vertical is replaced by the last one, which is then examined in its place.
    for (i = 0; i < poly_count; i++) {
        p = &polys[i];
        sceVu0Normalize(normal, p->normal);
        if ((normal[1] < 0.0f ? -normal[1] : normal[1]) > 0.01f) {
            if (poly_count == 0) {
                break;
            }
            poly_count--;
            i--;
            *p = poly[poly_count];
        }
    }

    CreateBBox();

    // Triangles on the same plane as an earlier one share its wall number.
    wall_count = 0;
    p = poly;
    for (i = 0; i < poly_count; i++, p++) {
        same_wall = NULL;
        for (j = 0; j < i; j++) {
            sceVu0Normalize(normal_a, p->normal);
            sceVu0Normalize(normal_b, poly[j].normal);
            if (mgDistVector(normal_a, normal_b) <= 0.01f) {
                distance = sceVu0InnerProduct(normal_a, p->vertex[0]);
                distance -= sceVu0InnerProduct(normal_b, poly[j].vertex[0]);
                if ((distance < 0.0f ? -distance : distance) <= 0.01f) {
                    same_wall = &poly[j];
                    break;
                }
            }
        }

        if (same_wall != NULL) {
            p->ignore_mask = same_wall->ignore_mask;
        } else {
            p->ignore_mask = wall_count;
            wall_count++;
        }
    }

    return wall_count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", PickupVerticalPoly__14CEditCollisionFv);
#endif
