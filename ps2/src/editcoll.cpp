#include "common.h"
#include "editcoll.hpp"
#include "mg_math.hpp"

// Code (.text)
#ifdef NONMATCHING
int ClipBoxXZ(float *max_a, float *min_a, float *max_b, float *min_b) {
    return max_a[0] >= min_b[0] && max_a[2] >= min_b[2] &&
           max_b[0] >= min_a[0] && max_b[2] >= min_a[2];
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", ClipBoxXZ__FPfPfPfPf);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapPoly3AreaXZ__FPA4_fPA4_fP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", Copy__14CEditCollisionFR14CEditCollisioniP9mgCMemory);
#ifdef NONMATCHING
float CEditCollision::AreaXZ() {
    float total_area = 0.0f;
    for (int index = 0; index < poly_count; ++index) {
        const CCPoly &triangle = poly[index];
        const float *first = triangle.vertex[0];
        const float *second = triangle.vertex[1];
        const float *third = triangle.vertex[2];
        float signed_area = (second[0] * first[2] - first[0] * second[2] +
                             third[0] * second[2] - second[0] * third[2] +
                             first[0] * third[2] - third[0] * first[2]) * 0.5f;
        if (signed_area < 0.0f) signed_area = -signed_area;
        total_area += signed_area;
    }
    return total_area;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", AreaXZ__14CEditCollisionFv);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapPoly3XZ__14CEditCollisionFPA4_fPfP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapXZ__14CEditCollisionFR14CEditCollisionPA4_fP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", OverlapPoly3XZ__14CEditCollisionFPA4_fPA4_fPf);
#ifdef NONMATCHING
void CEditCollision::ApplyMatrix(float (*matrix)[4]) {
    if (poly == NULL) return;
    for (int index = 0; index < poly_count; ++index) {
        CCPoly &triangle = poly[index];
        mgApplyMatrixN(triangle.vertex, matrix, triangle.vertex, 3);
        for (int corner = 0; corner < 3; ++corner) {
            float height = triangle.vertex[corner][1];
            triangle.vertex[corner][1] = static_cast<int>(height + (height < 0.0f ? -0.5f : 0.5f));
        }
        mgPlaneNormal(triangle.normal, triangle.vertex[0], triangle.vertex[1], triangle.vertex[2]);
        sceVu0Normalize(triangle.normal, triangle.normal);
    }
    CreateBBox();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", ApplyMatrix__14CEditCollisionFPA4_f);
#endif
#ifdef NONMATCHING
void CEditCollision::DeleteVerticalPoly() {
    if (poly == NULL) return;
    for (int index = 0; index < poly_count; ++index) {
        sceVu0FVECTOR normal;
        sceVu0Normalize(normal, poly[index].normal);
        float vertical_component = normal[1];
        if (vertical_component < 0.0f) vertical_component = -vertical_component;
        if (vertical_component < 0.01f) {
            if (poly_count == 0) break;
            --poly_count;
            poly[index] = poly[poly_count];
            --index;
        }
    }
    CreateBBox();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", DeleteVerticalPoly__14CEditCollisionFv);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editcoll", PickupVerticalPoly__14CEditCollisionFv);
