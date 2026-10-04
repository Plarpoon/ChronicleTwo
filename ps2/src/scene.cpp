#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", f_rand__Fff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", i_rand__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", InitVector__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", RandXYinViewArea__FfffPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Birth__7CRippleFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Step__7CRippleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Draw__7CRippleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Init__7CRippleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Birth__9CParticleFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Step__9CParticleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Draw__9CParticleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Init__9CParticleFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Birth__9CRainDropFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Step__9CRainDropFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Draw__9CRainDropFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Init__9CRainDropFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetCharNo__5CRainFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", ParticleBirth__5CRainFPfi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Stop__5CRainFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Start__5CRainFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Step__5CRainFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Init__5CRainFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", DrawScreenRain__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Draw__5CRainFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__10CSceneDataFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignData__15CSceneCharacterFP11CCharacter2Pc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__15CSceneCharacterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__9CSceneMapFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignData__9CSceneMapFP4CMapPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__13CSceneMessageFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignData__13CSceneMessageFP6ClsMesPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignData__12CSceneCameraFP9mgCCameraPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__12CSceneCameraFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignData__9CSceneSkyFP7CMapSkyPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__9CSceneSkyFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__13CSceneGameObjFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__12CSceneEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignData__12CSceneEffectFP16CEffectScriptManPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", InitAllData__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", Initialize__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetStack__6CSceneFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetStack__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", ClearStack__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignStack__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneCharacter__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneMap__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneMessage__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneCamera__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneSky__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneGameObj__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSceneEffect__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", CheckIMGName__6CSceneFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", CheckMDSName__6CSceneFiPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetData__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignCamera__6CSceneFiP9mgCCameraPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetCameraID__6CSceneFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetCamera__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignMessage__6CSceneFiP6ClsMesPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetMessage__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignChara__6CSceneFiP11CCharacter2Pc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetCharaNo__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetCharaNo__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetCharacter__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignMap__6CSceneFiP4CMapPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetMapName__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetMapID__6CSceneFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetMap__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetSky__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetMainMapNo__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", InScreenFunc__6CSceneFP16InScreenFuncInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", DrawScreenFunc__6CSceneFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignSky__6CSceneFiP7CMapSkyPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", DeleteSky__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AssignEffect__6CSceneFiP16CEffectScriptManPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", DeleteEffect__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetEffect__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", StepEffectScript__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", DrawEffectScript__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", IsActive__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetActive__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", ResetActive__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetStatus__6CSceneFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", ResetStatus__6CSceneFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetStatus__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetType__6CSceneFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetType__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetActiveMap__6CSceneFPP4CMapi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetCharaTexb__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetCharaTexb__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetTime__6CSceneFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", AddTime__6CSceneFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", TimeStep__6CSceneFf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetWind__6CSceneFfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", ResetWind__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", GetWind__6CSceneFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetNowMapNo__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scene", SetNowSubMapNo__6CSceneFi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", at_1503__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", at_1504__3);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", at_853__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", at_1117);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", at_1171);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", __vt__6CScene);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", noname_1188);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", noname_1242);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", noname_1294);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", noname_1381);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", noname_1692);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scene", noname_1709);

// Small uninitialised data (.sbss)
unsigned char init_1519[0x4];

// Uninitialised data (.bss)
unsigned char sun_func_1518[0x1C0];
