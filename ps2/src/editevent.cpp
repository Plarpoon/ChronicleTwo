#include "common.h"
#include "editevent.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", Reset__10CEditEventFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", StartEvent__10CEditEventFP15CSceneEventData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", Step__10CEditEventFP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", Draw__10CEditEventFP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", GeoramaFunc__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", CheckPlaceBurnParts__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", LoadIntNPC__FP12GeoFuncParamP12RS_STACKDATAi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", LoadGeoNPC__FP12GeoFuncParami);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", GeoUpdateNpcPos__FP6CScene);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_920__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_888__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_916__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_917__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_918__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_919__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1133__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1134__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1135__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1136__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1137__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1138__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1139__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1154__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1152__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1175__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1209__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1210__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1211__2__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", MenuInfo__2__DATA);
