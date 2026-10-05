#include "common.h"
#include "dng_object.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", SetPos__15CRocketLauncherFPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__15CRocketLauncherFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Draw__15CRocketLauncherFv);
void CRocketLauncher::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = -1;
    (*(s32 *)((u8 *)this + 0x150)) = 0;
    (*(s32 *)((u8 *)this + 0x154)) = 0;
    (*(s32 *)((u8 *)this + 0x174)) = 0;
    (*(s32 *)((u8 *)this + 0x160)) = -1;
    (*(s32 *)((u8 *)this + 0x164)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Get__18CRocketLauncherManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Draw__18CRocketLauncherManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__18CRocketLauncherManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Clear__18CRocketLauncherManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Initialize__18CRocketLauncherManFP8mgCFrameiP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Set__11CMachineGunFPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__11CMachineGunFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", SetPos__9CLaserGunFPfPfPf);
void CLaserGun::SetVisualCode(s32 arg0) {
    (*(s16 *)((u8 *)this + 0x108)) = (s16) arg0;
    if (arg0 == 0) {
        (*(s32 *)((u8 *)this + 0xfc)) = 0x3DCCCCCD;
        (*(s32 *)((u8 *)this + 0x100)) = 0x3DCCCCCD;
        (*(s32 *)((u8 *)this + 0x104)) = 0x3F000000;
        (*(s32 *)((u8 *)this + 0x110)) = 0x42800000;
        (*(s32 *)((u8 *)this + 0x114)) = 0x43000000;
        (*(s32 *)((u8 *)this + 0x118)) = 0x42800000;
    }
    if (arg0 == 1) {
        (*(s32 *)((u8 *)this + 0xfc)) = 0x3E4CCCCD;
        (*(s32 *)((u8 *)this + 0x100)) = 0x3ECCCCCD;
        (*(s32 *)((u8 *)this + 0x104)) = 0x3F4CCCCD;
        (*(s32 *)((u8 *)this + 0xdc)) = 0x41F00000;
        (*(s32 *)((u8 *)this + 0x110)) = 0x42800000;
        (*(s32 *)((u8 *)this + 0x114)) = 0x42800000;
        (*(s32 *)((u8 *)this + 0x118)) = 0x43000000;
    }
    if (arg0 == 2) {
        (*(s32 *)((u8 *)this + 0xfc)) = 0x3E4CCCCD;
        (*(s32 *)((u8 *)this + 0x100)) = 0x3ECCCCCD;
        (*(s32 *)((u8 *)this + 0x104)) = 0x3FB33333;
        (*(s32 *)((u8 *)this + 0xdc)) = 0x41700000;
        (*(s32 *)((u8 *)this + 0xe0)) = 0x40A00000;
        (*(s32 *)((u8 *)this + 0xe4)) = 0x42200000;
        (*(s32 *)((u8 *)this + 0x110)) = 0x43000000;
        (*(s32 *)((u8 *)this + 0x114)) = 0x42000000;
        (*(s32 *)((u8 *)this + 0x118)) = 0x43000000;
    }
    if (arg0 == 3) {
        (*(s32 *)((u8 *)this + 0xfc)) = 0x3E4CCCCD;
        (*(s32 *)((u8 *)this + 0x100)) = 0x3E4CCCCD;
        (*(s32 *)((u8 *)this + 0x104)) = 0x3F19999A;
        (*(s32 *)((u8 *)this + 0xdc)) = 0;
        (*(s32 *)((u8 *)this + 0xe0)) = 0x40000000;
        (*(s32 *)((u8 *)this + 0xe4)) = 0x420C0000;
        (*(s32 *)((u8 *)this + 0xf0)) = 0;
        (*(s32 *)((u8 *)this + 0xf4)) = 0x1869F;
        (*(s32 *)((u8 *)this + 0xf8)) = 0x4B;
        (*(s32 *)((u8 *)this + 0x110)) = 0;
        (*(s32 *)((u8 *)this + 0x114)) = 0x43000000;
        (*(s32 *)((u8 *)this + 0x118)) = 0x43000000;
    }
    if (arg0 == 4) {
        (*(s32 *)((u8 *)this + 0xfc)) = 0x3ECCCCCD;
        (*(s32 *)((u8 *)this + 0x100)) = 0x3ECCCCCD;
        (*(s32 *)((u8 *)this + 0x104)) = 0x3FE66666;
        (*(s32 *)((u8 *)this + 0xdc)) = 0x41200000;
        (*(s32 *)((u8 *)this + 0xe0)) = 0x40A00000;
        (*(s32 *)((u8 *)this + 0xe4)) = 0x41F00000;
        (*(s32 *)((u8 *)this + 0xf0)) = 0;
        (*(s32 *)((u8 *)this + 0xf4)) = 5;
        (*(s32 *)((u8 *)this + 0xf8)) = 0x4B;
        (*(s32 *)((u8 *)this + 0x110)) = 0x43000000;
        (*(s32 *)((u8 *)this + 0x114)) = 0x42800000;
        (*(s32 *)((u8 *)this + 0x118)) = 0;
    }
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__9CLaserGunFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Draw__9CLaserGunFv);
void CLaserGun::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x0)) = -1;
    (*(s32 *)((u8 *)this + 0xd0)) = 0;
    (*(s32 *)((u8 *)this + 0xd4)) = 0;
    (*(s32 *)((u8 *)this + 0x120)) = 0;
    (*(s32 *)((u8 *)this + 0xe8)) = -1;
    (*(s32 *)((u8 *)this + 0xec)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Get__12CLaserGunManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Draw__12CLaserGunManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__12CLaserGunManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Clear__12CLaserGunManFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Initialize__12CLaserGunManFP8mgCFrameiP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Draw__9CPullItemFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__9CPullItemFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", IsGet__9CPullItemFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", SetItem__9CPullItemFPfPfi);
void CPullItem::Clear(void) {
    (*(s8 *)((u8 *)this + 0x74)) = -1;
    (*(s32 *)((u8 *)this + 0x7c)) = 0;
}
void CPullItem::Initialize(void) {
    (*(s32 *)((u8 *)this + 0x7c)) = 0;
    (*(s16 *)((u8 *)this + 0x42)) = 0;
    (*(s16 *)((u8 *)this + 0x30)) = 0;
    (*(s16 *)((u8 *)this + 0x32)) = 0;
    (*(s16 *)((u8 *)this + 0x34)) = 32;
    (*(s16 *)((u8 *)this + 0x36)) = 32;
    (*(s16 *)((u8 *)this + 0x50)) = 0;
    (*(s16 *)((u8 *)this + 0x44)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", GetList__16CPullItemManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Clear__16CPullItemManagerFv);
void CRoboVoiceSystem::SetStatus(s32 arg0, s32 arg1) {
    (*(s16 *)((u8 *)this + 0x0)) = 1;
    (*(s32 *)((u8 *)this + 0xc)) = arg0;
    (*(s16 *)((u8 *)this + 0x10)) = arg1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", StartVoiceSystem__16CRoboVoiceSystemFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", StopVoice__16CRoboVoiceSystemFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/dng_object", Step__16CRoboVoiceSystemFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_923__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1112__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1240__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_tbl__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_tbl2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_tbl3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_tbl4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_tbl5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_tbl6__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", mons_attr_list__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", dung_progtxt_badge_already__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", dung_progtxt_badge_get__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", dung_progtxt_gkey_get__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", dung_progtxt_steal__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", dung_progtxt_getitem_overnum__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", dung_progtxt_getitem__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1800__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1801__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1802__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1803__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1806__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_961__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1291__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1428__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1429__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1430__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1431__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1432__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1433__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1434__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1435__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1436__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1437__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1438__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1439__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1440__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1441__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1442__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1443__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1444__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1445__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1446__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1447__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1448__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1449__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1450__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1451__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1452__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1453__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1454__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1455__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1456__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1457__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1458__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1459__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1460__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1461__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1462__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1463__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1464__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1465__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1466__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1467__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1468__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1469__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1470__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1471__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1472__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1473__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1474__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1475__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1476__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1477__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1478__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1479__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1480__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1481__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1482__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1483__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1484__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1485__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1486__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1487__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1488__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1489__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1490__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1491__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1492__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1493__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1494__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1495__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1496__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1497__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1498__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1499__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1500__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1501__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1502__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1503__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1504__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1505__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1506__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1507__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1508__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1509__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1510__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1511__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1512__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1513__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1514__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1515__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1516__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1517__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1518__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1519__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1520__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1521__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1522__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1523__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1524__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1525__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1526__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1527__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1528__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1529__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1530__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1531__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1736__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1853__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1854__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1804__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/dng_object", at_1805__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(anim_1410, 0x4);
INCLUDE_BSS(init_1411, 0x4);
