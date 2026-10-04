#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetChrFileSize__FPUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", CheckDrawChara__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", CheckDrawCharaShadow__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", StepChara__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetCharaLighting__6CSceneFPA4_fPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DrawChara__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DrawCharaShadow__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DrawExclamationMark__6CSceneFP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", SearchCharaTexb__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", PreLoadVillager__6CSceneFiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", PreLoadVillagerEnd__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DeleteVillager__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DeleteSubVillager__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DeleteVillager__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", SearchCharaID__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetNowVillagerTime__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetLoadVillagerList__6CSceneFiPiPP18CVillagerPlaceInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", SearchCopyModel__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetObjectNameList__FPcP11CCharacter2PP8mgCFramei);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", CharaObjectOnOff__6CSceneFiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", LoadVillager__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", LoadSubVillager__6CSceneFii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", RegisterVillager__6CSceneFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", RegisterVillager__6CSceneFiiP18CVillagerPlaceInfo);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", RegisterVillager__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetTalkEvent__6CSceneFPfP15CSceneEventData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetMotionName__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetMotionID__FPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", SetCharaMotion__FP11CCharacter2ii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", StepVillager__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", StayNearVillager__6CSceneFPfPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", CancelStayVillager__6CSceneFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", StayVillager__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", CancelStayVillager__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", ExModeVillager__6CSceneFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", SetActiveVillager__6CSceneFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", InScreenChara__6CSceneFPQ26CScene17InScreenCharaInfoPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", LoadGameObject__6CSceneFiiP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", GetGameObjectEvent__6CSceneFPfP15CSceneEventData);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scenevillager", DrawGameObject__6CSceneFi);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_868__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_991__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_992__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", motion_name);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", GameObjInfo);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_815__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1335);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1336);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1337);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1338);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1339__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1441__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1442__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1443__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1444__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1445__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1446__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1447__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1448__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1449__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1464__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1592__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1593__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1594__4);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1595__5);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1842__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1843__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1844__3);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1845__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1846__2);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scenevillager", at_1847__2);

// Uninitialised data (.bss)
unsigned char at_988__3[0x10];
