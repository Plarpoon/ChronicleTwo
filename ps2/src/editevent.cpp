#include "common.h"

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
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_920__4);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_888__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_916__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_917__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_918__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_919__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1133__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1134__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1135__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1136__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1137__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1138__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1139);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1154);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1152);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1175__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1209);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1210);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1211__2);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", MenuInfo__2);
