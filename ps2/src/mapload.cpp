#include "common.h"
#include "mapload.hpp"

#include <cstring>
#include <libvu0.h>

#include "map.hpp"
#include "mapinfo.hpp"
#include "mapparts.hpp"
#include "mdslist.hpp"
#include "mg_math.hpp"
#include "mg_memory.hpp"
#include "object.hpp"
#include "scriptinterpreter.hpp"

/** Non-zero when loading an additional map into the current map. */
extern int mapAddMode;

#ifdef NONMATCHING
/**
 *
 * Map the map script is loading into.
 *
 */
static CMap *mapMap;

/**
 *
 * Node of the map part the map script is building, or null outside a part.
 *
 */
static CList<CMapParts> *mapNowMapParts;

/**
 *
 * Node of the map piece the map script is building, or null outside a piece.
 *
 */
static CList<CMapPiece> *mapNowMapPiece;

/**
 *
 * Memory that everything the map script builds is taken from.
 *
 */
static mgCMemory *mapStack;

/**
 *
 * Non-zero while function points of the map script go to the current map part rather than the map.
 *
 */
static int mapPtsFunc;

/**
 *
 * Next entry of the current piece's materials that the map script fills in.
 *
 */
static int mapMatIdx;

/**
 *
 * Level of detail that the map script is giving pieces to.
 *
 */
static int mapLOD_ID;
#endif

// Code (.text)
MAP_TIME_BAND GetTimeBand(float time) {
    MAP_TIME_BAND band = MAP_TIME_BAND_NIGHT;
    if (time >= 6.0f && time < 9.0f) {
        band = MAP_TIME_BAND_MORNING;
    }
    if (time >= 9.0f && time < 17.0f) {
        band = MAP_TIME_BAND_DAY;
    }
    if (time >= 17.0f && time < 21.0f) {
        band = MAP_TIME_BAND_EVENING;
    }
    return band;
}

float CMap::GetNowTime() {
    if (time_enable) {
        return now_time;
    }
    if (fixed_time_enable) {
        return fixed_time;
    }
    return 12.0f;
}

int CMap::GetNowTimeBand() {
    return GetTimeBand(GetNowTime());
}

#ifdef NONMATCHING
int CMap::GetNowTimeLightBand() {
    int num = time_light_num;
    if (num < 2) {
        return 0;
    }
    if (num == MAP_TIME_BAND_NUM) {
        return GetNowTimeBand();
    }

    // The light sets divide the day evenly, the first starting at 9:00.
    float time = GetNowTime() - 9.0f;
    if (time < 0.0f) {
        time += 24.0f;
    }
    return (int)(time / (24.0f / num)) % num;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetNowTimeLightBand__4CMapFv);
#endif

#ifdef NONMATCHING
void CMap::GetLightingRatio(float *out_ratio) {
    float time = GetNowTime();
    out_ratio[MAP_TIME_BAND_DAY] = 0.0f;
    out_ratio[MAP_TIME_BAND_EVENING] = 0.0f;
    out_ratio[MAP_TIME_BAND_NIGHT] = 0.0f;
    out_ratio[MAP_TIME_BAND_MORNING] = 0.0f;

    // In the last hour of each band the light fades into the next band's.
    float blend = 0.0f;
    int band = GetNowTimeBand();
    int next = (band + 1) % MAP_TIME_BAND_NUM;
    if (band == MAP_TIME_BAND_NIGHT) {
        if (time < 6.0f && time > 5.0f) {
            blend = time - 5.0f;
        }
    } else if (band == MAP_TIME_BAND_EVENING) {
        if (time > 20.0f) {
            blend = time - 20.0f;
        }
    } else if (band == MAP_TIME_BAND_DAY) {
        if (time > 16.0f) {
            blend = time - 16.0f;
        }
    } else if (band == MAP_TIME_BAND_MORNING) {
        if (time > 8.0f) {
            blend = time - 8.0f;
        }
    }
    out_ratio[band] = 1.0f - blend;
    out_ratio[next] = blend;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetLightingRatio__4CMapFPf);
#endif

void CMap::GetLightingFlareRatio(float *out_ratio) {
    GetLightingRatio(out_ratio);
    out_ratio[MAP_TIME_BAND_NIGHT] = 0.0f;
}

void CMap::GetLightingSunRatio(float *out_ratio) {
    float time = GetNowTime();
    GetLightingRatio(out_ratio);
    if (time < 6.0f) {
        if (time > 4.0f) {
            out_ratio[MAP_TIME_BAND_NIGHT] = 0.0f;
            out_ratio[MAP_TIME_BAND_MORNING] = 0.0f;
        } else if (time > 3.0f) {
            out_ratio[MAP_TIME_BAND_NIGHT] = 1.0f - (time - 3.0f);
        }
    }
    if (out_ratio[MAP_TIME_BAND_NIGHT] > 0.0f) {
        out_ratio[MAP_TIME_BAND_MORNING] = 0.0f;
        out_ratio[MAP_TIME_BAND_EVENING] = 0.0f;
    }
}

#ifdef NONMATCHING
int CMap::GetTimeLightingRatio(float *out_ratio) {
    int num = time_light_num;
    if (num == MAP_TIME_BAND_NUM) {
        GetLightingRatio(out_ratio);
    } else {
        float time = GetNowTime();
        for (int i = 0; i < num; i++) {
            out_ratio[i] = 0.0f;
        }
        if (num < 2) {
            out_ratio[0] = 1.0f;
        } else {
            // The light set in use fades into the next over the last hour before the next starts.
            int band = GetNowTimeLightBand();
            float start = band * (24.0f / num) + 9.0f;
            if (start >= 24.0f) {
                start -= 24.0f;
            }
            float ratio = (start + 24.0f / num) - time;
            if (ratio >= 1.0f) {
                ratio = 1.0f;
            }
            out_ratio[band] = ratio;
            out_ratio[(band + 1) % num] = 1.0f - ratio;
        }
    }
    return num;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetTimeLightingRatio__4CMapFPf);
#endif

void CMap::GetSunPoint(float *out_pos) {
    sceVu0FVECTOR sun = {0.0f, -1900.0f, 700.0f, 1.0f};
    sceVu0FMATRIX matrix;

    mgUnitMatrix(matrix);
    sceVu0RotMatrixZ(matrix, matrix, mgAngleLimit((GetNowTime() * 6.2831855f) / 24.0f));
    sceVu0RotMatrixY(matrix, matrix, sun_angle);
    sceVu0ApplyMatrix(out_pos, matrix, sun);
}

#ifdef NONMATCHING
float CMap::GetLightNoTime(int light_no) {
    int num = time_light_num;
    if (light_no < num && GetTimeEnable()) {
        if (num == MAP_TIME_BAND_NUM) {
            switch (light_no) {
            case MAP_TIME_BAND_MORNING:
                return 6.5f;
            case MAP_TIME_BAND_DAY:
                return 9.5f;
            case MAP_TIME_BAND_EVENING:
                return 17.5f;
            case MAP_TIME_BAND_NIGHT:
                return 21.5f;
            default:
                return -1.0f;
            }
        }
        float time = (24.0f * light_no) / num + 9.5f;
        if (time < 0.0f) {
            time += 24.0f;
        }
        return time;
    }
    return -1.0f;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetLightNoTime__4CMapFi);
#endif

int CMap::GetTimeEnable() {
    return time_enable;
}

#ifdef NONMATCHING
void CMap::GetLightInfo(CMapLightingInfo *out_info) {
    if (out_info == NULL) {
        return;
    }

    int num = time_light_num;
    if (GetActiveLightNo() >= num || (!GetTimeEnable() && !fixed_time_enable)) {
        CMapLightingInfo *info = GetLightingInfo(GetActiveLightNo());
        if (info != NULL) {
            *out_info = *info;
            return;
        }
    }

    CMapLightingInfo *list[8];
    float ratio[8];
    sceVu0FVECTOR sun;

    int band = GetNowTimeLightBand();
    for (int i = 0; i < num; i++) {
        list[i] = CMapInfo::GetLightingInfo(i);
        if (list[i] == NULL) {
            return;
        }
    }
    *out_info = *list[band];

    if (time_light_blend) {
        GetLightInfo(out_info, ratio, GetTimeLightingRatio(ratio));

        // The first directional light follows the sun, never lower than a fixed height.
        GetSunPoint(sun);
        sceVu0Normalize(sun, sun);
        if (sun[1] < 0.2f) {
            sun[1] = 0.2f;
            sceVu0Normalize(sun, sun);
        }
        out_info->light_dir[0][0] = sun[0];
        out_info->light_dir[1][0] = sun[1];
        out_info->light_dir[2][0] = sun[2];
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetLightInfo__4CMapFP16CMapLightingInfo);
#endif

#ifdef NONMATCHING
// Generated by the compiler from CMapLightingInfo in mapload.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __as__16CMapLightingInfoFRC16CMapLightingInfo);
#endif

CMapLightingInfo *CMap::GetLightingInfo(int no) {
    return CMapInfo::GetLightingInfo(no);
}

#ifdef NONMATCHING
int CMap::GetActiveLightNo() {
    return CMapInfo::GetActiveLightNo();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetActiveLightNo__4CMapFv);
#endif

#ifdef NONMATCHING
// Defined in mapinfo.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetActiveLightNo__8CMapInfoFv);
#endif

#ifdef NONMATCHING
void CMap::GetLightInfo(CMapLightingInfo *out_info, float *ratio, int num) {
    sceVu0FMATRIX light_dir;
    sceVu0FMATRIX light_color;
    sceVu0FVECTOR ambient;
    sceVu0FVECTOR bg_color;
    sceVu0FVECTOR bg_color2;
    sceVu0FVECTOR fog;
    sceVu0FVECTOR fog_color;
    CMapLightingInfo *list[8];
    sceVu0FVECTOR work;
    int fog_num = 0;
    int i;
    int j;

    for (i = 0; i < time_light_num; i++) {
        list[i] = CMapInfo::GetLightingInfo(i);
        if (list[i] == NULL) {
            return;
        }
    }

    mgZeroVector(ambient);
    mgZeroVector(fog);
    mgZeroVector(fog_color);
    mgZeroVector(bg_color);
    mgZeroVector(bg_color2);
    mgZeroMatrix(light_dir);
    mgZeroMatrix(light_color);

    for (i = 0; i < num; i++) {
        if (ratio[i] > 0.0f) {
            CMapLightingInfo *info = list[i];
            sceVu0ScaleVector(work, info->ambient, ratio[i]);
            mgAddVector(ambient, work);
            sceVu0ScaleVector(work, info->bg_color, ratio[i]);
            mgAddVector(bg_color, work);
            sceVu0ScaleVector(work, info->bg_color2, ratio[i]);
            mgAddVector(bg_color2, work);

            // Only the sets that draw fog weigh in its colour and distances.
            if (info->fog_enable) {
                work[0] = info->fog.r;
                work[1] = info->fog.g;
                work[2] = info->fog.b;
                work[3] = info->fog.unk_b;
                sceVu0ScaleVector(work, work, ratio[i]);
                mgAddVector(fog_color, work);
                work[0] = info->fog.near_dist;
                work[1] = info->fog.far_dist;
                work[2] = info->fog.far_value;
                work[3] = info->fog.near_value;
                sceVu0ScaleVector(work, work, ratio[i]);
                mgAddVector(fog, work);
                fog_num++;
            }

            for (j = 0; j < 4; j++) {
                sceVu0ScaleVector(work, info->light_dir[j], ratio[i]);
                mgAddVector(light_dir[j], work);
                sceVu0ScaleVector(work, info->light_color[j], ratio[i]);
                mgAddVector(light_color[j], work);
            }
        }
    }

    // Each row now holds one light's direction, normalised unless the blend cancelled it out.
    sceVu0TransposeMatrix(light_dir, light_dir);
    for (i = 0; i < 4; i++) {
        if (mgDistVector(light_dir[i]) > 0.0f) {
            sceVu0Normalize(light_dir[i], light_dir[i]);
        }
    }

    if (mgAbs(ambient[3] - 128.0f) < 0.01f) {
        ambient[3] = 128.0f;
    }

    sceVu0CopyVector(out_info->ambient, ambient);
    sceVu0CopyVector(out_info->bg_color, bg_color);
    sceVu0CopyVector(out_info->bg_color2, bg_color2);
    for (i = 0; i < 4; i++) {
        out_info->light_dir[0][i] = light_dir[i][0];
        out_info->light_dir[1][i] = light_dir[i][1];
        out_info->light_dir[2][i] = light_dir[i][2];
        sceVu0CopyVector(out_info->light_color[i], light_color[i]);
    }
    out_info->fog.r = fog_color[0];
    out_info->fog.g = fog_color[1];
    out_info->fog.b = fog_color[2];
    out_info->fog.unk_b = fog_color[3];
    out_info->fog.near_dist = fog[0];
    out_info->fog.far_dist = fog[1];
    out_info->fog.far_value = fog[2];
    out_info->fog.near_value = fog[3];
    out_info->fog_enable = fog_num > 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetLightInfo__4CMapFP16CMapLightingInfoPfi);
#endif

#ifdef NONMATCHING
// Defined in mapload.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mgAbs__Ff);
#endif

#ifdef NONMATCHING
/**
 *
 * Handles a map script tag that does nothing.
 *
 */
static int mapDummy(SPI_STACK *stack, int argument_count) {
    return 1;
}
#else
s32 mapDummy(SPI_STACK *stack, int argc) {
    return 1;
}
#endif

#ifdef NONMATCHING
/**
 *
 * Tells whether the map script being loaded adds to a map already loaded.
 *
 */
static int IsAddMode() {
    return mapAddMode;
}
#else
s32 IsAddMode(void) {
    return mapAddMode;
}
#endif

#ifdef NONMATCHING
/**
 *
 * Starts a map part of the name of the first argument, which the tags up to PARTS_END build.
 *
 */
static int mapPARTS(SPI_STACK *stack, int argument_count) {
    mapNowMapParts = new (mapStack->Alloc(algn16_size(sizeof(CList<CMapParts>)) + 2)) CList<CMapParts>;
    CMapParts *parts = mapNowMapParts->pGetData();
    char *name = spiGetStackString(stack);
    parts->SetName(name);
    parts->SetPartsName(name);
    mapLOD_ID = 0;
    mapPtsFunc = 1;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
// Defined in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", pGetData__17CList_9CMapParts_Fv);
#endif

#ifdef NONMATCHING
// Defined in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__17CList_9CMapParts_Fv);
#endif

#ifdef NONMATCHING
// Defined in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", Initialize__17CList_9CMapParts_Fv);
#endif

#ifdef NONMATCHING
CObject::CObject() {
    Initialize();
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__7CObjectFv);
#endif

#ifdef NONMATCHING
// Defined in mg_frame.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__9mgCObjectFv);
#endif

#ifdef NONMATCHING
// Defined in mapload.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", algn16_size__FUi);
#endif

#ifdef NONMATCHING
/**
 *
 * Gives the current map part its far clip distance and whether it fades out there.
 *
 */
static int mapFAR_CLIP(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    mapNowMapParts->pGetData()->far_dist = spiGetStackFloat(&stack[0]);
    mapNowMapParts->pGetData()->fade = spiGetStackInt(&stack[1]);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFAR_CLIP__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Sets whether the current map part is drawn without the scene's lights and without point lights.
 *
 */
static int mapLIGHT_FLAG(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    mapNowMapParts->pGetData()->no_light = spiGetStackInt(&stack[0]);
    mapNowMapParts->pGetData()->no_plight = spiGetStackInt(&stack[1]);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapLIGHT_FLAG__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Sets the four move flags of the current map part, one per argument.
 *
 */
static int mapMOVE_FLAG(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    CMapParts *parts = mapNowMapParts->pGetData();
    parts->move_flag = 0;
    if (spiGetStackInt(&stack[0])) {
        parts->move_flag |= 1;
    }
    if (spiGetStackInt(&stack[1])) {
        parts->move_flag |= 2;
    }
    if (spiGetStackInt(&stack[2])) {
        parts->move_flag |= 4;
    }
    if (spiGetStackInt(&stack[3])) {
        parts->move_flag |= 8;
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapMOVE_FLAG__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Gives the current map part four levels of detail at the standard distances.
 *
 */
static int mapLOD_START(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    float *dist = (float *)mapStack->Alloc(1);
    CMapParts *parts = mapNowMapParts->pGetData();
    dist[0] = 600.0f;
    dist[1] = 1000.0f;
    dist[2] = 1400.0f;
    dist[3] = 1800.0f;
    parts->SetLODDist(dist, 4);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapLOD_START__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
// Defined in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetLODDist__9CMapPartsFPfi);
#endif

#ifdef NONMATCHING
/**
 *
 * Sets whether the current map part blends between its levels of detail.
 *
 */
static int mapLOD_BLEND(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    mapNowMapParts->pGetData()->SetLODBlend(spiGetStackInt(stack));
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapLOD_BLEND__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
// Defined in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetLODBlend__9CMapPartsFi);
#endif

#ifdef NONMATCHING
/**
 *
 * Puts a piece of the current map part into a level of detail, hiding it until that level is reached.
 *
 */
static int mapLOD_PIECE(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    CMapParts *parts = mapNowMapParts->pGetData();
    int level = spiGetStackInt(&stack[0]);
    CMapPiece *piece = parts->SearchPiece(spiGetStackString(&stack[1]));
    if (piece != NULL) {
        if (level > 0) {
            piece->show = 0;
            piece->fade_alpha = 0.0f;
        }
        if (parts->GetLODBlend()) {
            piece->fade = 1;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapLOD_PIECE__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
// Defined in mapparts.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetLODBlend__9CMapPartsFv);
#endif

#ifdef NONMATCHING
/**
 *
 * Ends a level of detail, so that the next pieces go to the following level.
 *
 */
static int mapLOD_END(SPI_STACK *stack, int argument_count) {
    mapLOD_ID++;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapLOD_END__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Starts a piece of the current map part that uses the model data of the first argument, shown unless the second argument is zero.
 *
 */
static int mapPIECE(SPI_STACK *stack, int argument_count) {
    if (mapNowMapParts == NULL) {
        return 0;
    }
    char *name = spiGetStackString(stack);
    if (name == NULL) {
        return 0;
    }
    int show = 1;
    if (argument_count > 1) {
        show = spiGetStackInt(&stack[1]);
    }
    if (!(mapMap->piece_load_skip & 1)) {
        mapNowMapPiece = new (mapStack->Alloc(algn16_size(sizeof(CList<CMapPiece>)) + 2)) CList<CMapPiece>;
        CMapPiece *piece = mapNowMapPiece->pGetData();
        int size = strlen(name) + 1;
        char *copy = (char *)mapStack->Alloc(size / 16 + (size % 16 != 0));
        strcpy(copy, name);
        piece->SetName(copy);
        piece->show = show;
        CMdsInfo *mds = mapMap->SearchMDS(copy);
        if (mds != NULL) {
            piece->AssignMds(mds);
        }
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
// Defined in mdslist.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetName__9CMapPieceFPc);
#endif

#ifdef NONMATCHING
// Defined in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", pGetData__17CList_9CMapPiece_Fv);
#endif

#ifdef NONMATCHING
// Defined in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__17CList_9CMapPiece_Fv);
#endif

#ifdef NONMATCHING
// Defined in mg_tanime.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", Initialize__17CList_9CMapPiece_Fv);
#endif

#ifdef NONMATCHING
// Defined in mdslist.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__9CMapPieceFv);
#endif

#ifdef NONMATCHING
// Defined in object.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__12CObjectFrameFv);
#endif

#ifdef NONMATCHING
/**
 *
 * Renames the model data that the current piece uses.
 *
 */
static int mapPIECE_NAME(SPI_STACK *stack, int argument_count) {
    if (mapNowMapPiece == NULL) {
        return 0;
    }
    CMapPiece *piece = mapNowMapPiece->pGetData();
    char *name = spiGetStackString(stack);
    if (name != NULL) {
        char *copy = (char *)mapStack->Alloc(algn16_size(strlen(name) + 1));
        strcpy(copy, name);
        piece->SetName(copy);
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_NAME__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Moves the current piece to the position of the three arguments.
 *
 */
static int mapPIECE_POS(SPI_STACK *stack, int argument_count) {
    if (mapNowMapPiece == NULL) {
        return 0;
    }
    CMapPiece *piece = mapNowMapPiece->pGetData();
    if (piece == NULL) {
        return 0;
    }
    sceVu0FVECTOR position;
    spiGetStackVector(position, stack);
    piece->SetPosition(position);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_POS__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Turns the current piece to the angles of the three arguments.
 *
 */
static int mapPIECE_ROT(SPI_STACK *stack, int argument_count) {
    if (mapNowMapPiece == NULL) {
        return 0;
    }
    CMapPiece *piece = mapNowMapPiece->pGetData();
    if (piece == NULL) {
        return 0;
    }
    sceVu0FVECTOR rotation;
    spiGetStackVector(rotation, stack);
    piece->SetRotation(rotation);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_ROT__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Scales the current piece by the three arguments.
 *
 */
static int mapPIECE_SCALE(SPI_STACK *stack, int argument_count) {
    if (mapNowMapPiece == NULL) {
        return 0;
    }
    CMapPiece *piece = mapNowMapPiece->pGetData();
    if (piece == NULL) {
        return 0;
    }
    sceVu0FVECTOR scale;
    spiGetStackVector(scale, stack);
    piece->SetScale(scale);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_SCALE__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
/**
 *
 * Gives the current piece as many material colour entries as the first argument, filled in by the PIECE_MATERIAL tags that follow.
 *
 */
static int mapPIECE_MATERIAL_START(SPI_STACK *stack, int argument_count) {
    if (mapNowMapPiece == NULL) {
        return 0;
    }
    mapMatIdx = 0;
    int num = spiGetStackInt(stack);
    if (num > 0) {
        PieceMaterial *material = new (mapStack->Alloc(algn16_size(num * sizeof(PieceMaterial)) + 2)) PieceMaterial[num];
        if (material != NULL) {
            mapNowMapPiece->pGetData()->SetMaterial(material, num);
        }
    }
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_MATERIAL_START__FP9SPI_STACKi);
#endif

#ifdef NONMATCHING
// Defined in mdslist.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetMaterial__9CMapPieceFP13PieceMateriali);
#endif
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__13PieceMaterialFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", Initialize__13PieceMaterialFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_MATERIAL__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetMaterial__8mgCFrameFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", GetFrame__12CObjectFrameFv);
s32 mapPIECE_MATERIAL_END(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_COL_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_TIME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPIECE_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapMAP_PARTS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapMAP_FAR_CLIP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS_GROUP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS_ROT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapPARTS_SCALE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapMAP_PARTS_END__FP9SPI_STACKi);
s32 map_MAP_INFO_TOP(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapCAMERA_INFO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__11CCameraInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__15CCameraDrawInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", Initialize__15CCameraDrawInfoFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFIX_CAMERA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFIX_CAMERA_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFIX_CAMERA_POS2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFIX_CAMERA_OFF_GROUP__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFIX_CAMERA_RECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetCollision__9CColFrameFP10CCollision);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__10CCollisionFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFIX_CAMERA_END__FP9SPI_STACKi);
s32 mapCAMERA_INFO_END(SPI_STACK *stack, s32 argument_count) {
    if (IsAddMode() != 0) {
        return 1;
    }
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_POINT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_FLAG__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_FIRE_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_PLIGHT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_ANIME_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_INVENT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_EVENT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_SOUND_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_EFFECT_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetBound__8mgCFrameFPQ28mgCFrame9BoundInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetScale__10CFuncPointFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetRotation__10CFuncPointFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", SetPosition__10CFuncPointFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_DATA_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", mapFUNC_POINT_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", LoadMapFile__4CMapFPciP9mgCMemoryi);
void CMap::SetPieceLoadSkip(s32 skip) {
    piece_load_skip = skip;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgDRAW_OFF_RECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgOCCLUSION_PLANE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgFUNC_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgFUNC_EVENT_DATA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgFUNC_DATA_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_SURFACE_NUM__FP9SPI_STACKi);
s32 cfgWATER_SURFACE_START(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_VERTEX__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_PARAM__FP9SPI_STACKi);
s32 cfgWATER_SHAKE(SPI_STACK *stack, int argc) {
    return 1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_SURFACE_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_DRAW_NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", __ct__9CMapWaterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", cfgWATER_DRAW__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mapload", LoadCfgFile__4CMapFPciP9mgCMemory);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_438__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", map_tag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", cfg_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_611__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_612__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_613__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_614__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_615__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_616__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_617__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_618__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_619__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_620__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_621__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_622__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_623__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_624__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_625__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_626__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_627__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_628__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_629__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_630__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_631__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_632__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_633__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_634__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_635__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_636__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_637__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_638__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_639__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_640__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_641__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_642__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_643__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_644__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_645__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_646__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_647__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_648__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_649__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_650__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_651__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_652__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_653__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_654__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_655__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_656__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_657__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_658__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_659__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_660__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_661__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_662__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1064__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1128__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1129__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1130__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1131__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1132__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1133__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1134__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1135__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1136__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1278__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1279__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1280__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1281__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1282__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1283__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1284__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1370__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1371__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1372__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1373__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1374__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1375__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1376__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1377__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1378__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1379__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1380__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1436__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1437__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1438__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1439__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", at_1544__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", __vt__17CList_9CMapPiece___DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mapload", __vt__17CList_9CMapParts___DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(mapMap, 0x4);
INCLUDE_BSS(mapNowMapParts, 0x4);
INCLUDE_BSS(mapNowMapPiece, 0x4);
INCLUDE_BSS(mapStack, 0x4);
INCLUDE_BSS(mapFarDist, 0x4);
INCLUDE_BSS(mapFarAlpha, 0x4);
INCLUDE_BSS(mapShow, 0x4);
INCLUDE_BSS(mapLOD_ID, 0x4);
INCLUDE_BSS(mapCameraInfoIdx, 0x4);
INCLUDE_BSS(mapCameraRectIdx, 0x4);
INCLUDE_BSS(mapFuncPointIdx, 0x4);
INCLUDE_BSS(mapNowFuncPoint, 0x4);
INCLUDE_BSS(mapMatIdx, 0x4);
INCLUDE_BSS(mapPtsFunc, 0x4);
INCLUDE_BSS(mapAddMode, 0x4);
INCLUDE_BSS(ReserveFuncFlag, 0x4);
INCLUDE_BSS(WaterIndex, 0x4);
INCLUDE_BSS(cfgWater, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(mapPlacePartsName, 0x100);
INCLUDE_BSS(mapMapPartsName, 0x100);
INCLUDE_BSS(mapMapPartsGroupName, 0x100);
INCLUDE_BSS(mapPos, 0x10);
INCLUDE_BSS(mapRot, 0x10);
INCLUDE_BSS(mapScale, 0x10);
