#include "common.h"
#include "map.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetFlag__12CMapFlagDataFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetFlag__12CMapFlagDataFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Iam__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__11CPartsGroupFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Add__11CPartsGroupFP23CList_14PartsGroupData_);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__9CMapWaterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Clear__9CMapWaterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPartsGroup__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AddPartsGroup__4CMapFPcP9CMapPartsP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__23CList_14PartsGroupData_Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SearchPartsGroup__4CMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SearchPartsGroupNo__4CMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SerachEmptyPartsGroupNo__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetPlacePartsBuff__4CMapFP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlacPartsTable__4CMapFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetCameraInfoTable__4CMapFP11CCameraInfoi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetCameraInfo__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", NewPlaceParts__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SearchMDS__4CMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateEffect__4CMapFPUiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SaerchEffectIndex__4CMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AddParts__4CMapFP17CList_9CMapParts_);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetParts__4CMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateDrawRect__4CMapFP9mgCMemoryP9mgVu0FBOXP9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Initialize__18CList_P9CMapParts_Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateOcclusion__4CMapFPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", PlaceParts__4CMapFPcPfPfPfP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", PlacePartsEnd__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", ClearPlaceParts__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlaceParts__4CMapFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlaceParts__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", ConvertParts__4CMapFP9CMapParts);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlaceParts__4CMapFP9mgVu0FBOXPP9CMapPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPlaceColParts__4CMapFP9mgVu0FBOXPP9CMapPartsi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateFuncCheck__4CMapFP15CFuncPointCheck);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetBBox__4CMapFP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", PreDraw__4CMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetCharaLight__4CMapFP9mgCObjectP10CFuncPointii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetFuncPLight__4CMapFPfP15CFuncPointCheck);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__10CFuncPointFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", ResetFuncPLight__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawSub__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Draw__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawDirect__9CMapPartsFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawEffect__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawFireEffect__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawFireRaster__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawWater__4CMapFP9mgCCameraP10mgCTextureP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawTrBox__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetShow__7CObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetPoly__4CMapFiP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetColPoly__4CMapFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetCameraPoly__4CMapFP6CCPolyR9mgVu0FBOXi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetTrBoxColPoly__4CMapFP6CCPolyPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetFixCameraPos__4CMapFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", FixCameraPartsOnOff__4CMapFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetEvent__4CMapFPfiP12MapEventInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", InScreenFunc__4CMapFP16InScreenFuncInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawScreenFunc__4CMapFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", EffectStep__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AnimeStep__4CMapFP12CObjAnimeEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Step__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetSeSrcVolPan__4CMapFPiPfPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateMap__4CMapFP11CMdsListSetP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", AssignFuncPoint__4CMapFP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__9CObjAnimeFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CreateTrBox__4CMapFP15CMapTreasureBoxiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", __ct__15CMapTreasureBoxFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetTrBox__4CMapFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DeleteTrBox__4CMapFiP12CMapFlagData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", UpdateTrBoxFlag__4CMapFP12CMapFlagData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", LoadData__4CMapFPUiPUiPiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", CheckFuncEvent__FP10CFuncPointPfiP12MapEventInfoPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Draw__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawDirect__4CMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Draw__7CObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", DrawDirect__7CObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Show__7CObjectFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetFarDist__7CObjectFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetFarDist__7CObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", SetNearDist__7CObjectFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", GetNearDist__7CObjectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/map", Copy__7CObjectFR7CObjectP9mgCMemory);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_327__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_574__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_1352__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_1353__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_1927__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", at_2008__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__4CMap__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__18CList_P9CMapParts___DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__23CList_14PartsGroupData___DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", __vt__9CMapWater__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/map", CMapName__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(init_1249, 0x4);
INCLUDE_BSS(init_1301, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(ft_1248, 0xE00);
INCLUDE_BSS(attr_1300, 0x90);
