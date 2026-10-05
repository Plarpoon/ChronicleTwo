#include "common.h"
#include "editloop.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", GetUserData__Fv__2);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", InitLockCharaCtrl__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", LockCharaCtrl__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", UnLockCharaCtrl__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", IsEditMode__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", InitEditModeChg__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", NowEditModeChg__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditModeChg__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditModeChgStep__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", SetDataPacket__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", PreExitLoop__FP6CScene);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditInit__F13INIT_LOOP_ARG);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", __as__15CameraCtrlParamFRC15CameraCtrlParam);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", __ct__12CActionCharaFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditExit__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", InitSubMapLoadStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", SubMapLoadStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditLoop__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", InitEditEvent__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", ResetEditEvent__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", RestartEditEvent__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditStep__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditDraw__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", UpdateTrBoxFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", BurnEditParts__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", editLoadSound__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditMapJump__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditGotoInterior__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditExitInterior__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditDataSave__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditDataLoad__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", KeepEditAnalyze__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", EditAnalyzeChanged__Fv);
void LoadComVillaager(void) {
}
void LoadMap(void) {
    LoadComVillaager();
}

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editloop", __sinit_editloop_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1045__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1053__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1528__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2271__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_3040__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1032__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1033__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1395__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1396__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1397__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1398__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1399__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1400__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1401__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1402__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1403__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1404__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1405__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1406__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1407__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1408__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1409__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1410__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1411__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1412__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1413__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1414__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1415__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1416__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1417__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1418__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1419__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1420__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1421__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_1422__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2125__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2126__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2127__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2128__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2129__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2130__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2131__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2132__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2133__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2134__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2136__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2261__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2262__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2747__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2748__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2749__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2750__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2751__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2752__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2753__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2948__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2949__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2950__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2951__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2952__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2953__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2954__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2955__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2956__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2957__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2958__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", D_0037B00C__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", MenuInfo__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", DataPktMode__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2346__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editloop", at_2352__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(WaterFrame, 0x4);
INCLUDE_BSS(RedBicMark, 0x4);
INCLUDE_BSS(BlueBicMark, 0x4);
INCLUDE_BSS(TreasureBox, 0x4);
INCLUDE_BSS(MapNo, 0x4);
INCLUDE_BSS(Camera, 0x4);
static INCLUDE_BSS(EventCamera, 0x4);
INCLUDE_BSS(FixCamera, 0x4);
INCLUDE_BSS(EditCamera, 0x4);
INCLUDE_BSS(ActiveCharaNo, 0x4);
INCLUDE_BSS(ControlCharaID, 0x4);
INCLUDE_BSS(WalkChara, 0x4);
INCLUDE_BSS(LoopCounter, 0x4);
INCLUDE_BSS(LoopMode, 0x4);
INCLUDE_BSS(ControlMode, 0x4);
INCLUDE_BSS(SubMapLoadBG, 0x4);
INCLUDE_BSS(now_load_map_no, 0x4);
INCLUDE_BSS(EventSquareJump, 0x4);
INCLUDE_BSS(EditDrawFlag, 0x4);
INCLUDE_BSS(EditDrawCancelFlag, 0x4);
INCLUDE_BSS(PauseFlag, 0x4);
INCLUDE_BSS(LockChara, 0x4);
INCLUDE_BSS(PreEditMenuCnt, 0x4);
INCLUDE_BSS(EditModeChgFlag, 0x4);
INCLUDE_BSS(EditModeChgCnt, 0x4);
INCLUDE_BSS(EditModeChgEvent, 0x4);
INCLUDE_BSS(MainScene__2, 0x4);
INCLUDE_BSS(main_pkt1, 0x4);
INCLUDE_BSS(main_pkt2, 0x4);
INCLUDE_BSS(read_buffer_end, 0x4);
INCLUDE_BSS(MenuDataBuf, 0x4);
INCLUDE_BSS(MenuDataSize, 0x4);
INCLUDE_BSS(FixCharaBuffSize, 0x4);
INCLUDE_BSS(CrossFadeBuff, 0x4);
INCLUDE_BSS(time_step_1481, 0x4);
INCLUDE_BSS(init_1482, 0x4);
INCLUDE_BSS(show_time_step_1484, 0x4);
INCLUDE_BSS(init_1485, 0x4);
INCLUDE_BSS(old_cm_1772, 0x4);
INCLUDE_BSS(rain_flag_1849, 0x4);
INCLUDE_BSS(init_1850, 0x4);
INCLUDE_BSS(start_bt_cnt_1865, 0x4);
INCLUDE_BSS(init_1866, 0x4);
INCLUDE_BSS(encount_flag_1868, 0x4);
INCLUDE_BSS(init_1869, 0x4);
INCLUDE_BSS(show_encount_cnt_1871, 0x4);
INCLUDE_BSS(init_1872, 0x4);
INCLUDE_BSS(next_encount_1874, 0x4);
INCLUDE_BSS(init_1875, 0x4);
INCLUDE_BSS(flag_2408, 0x4);
INCLUDE_BSS(init_2409, 0x4);
INCLUDE_BSS(DelMainNPCflag, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(at_949, 0x10);
INCLUDE_BSS(WaveTable, 0x1210);
INCLUDE_BSS(CharaOldPos, 0x10);
INCLUDE_BSS(EventMes1, 0x2960);
INCLUDE_BSS(buf0, 0x30);
INCLUDE_BSS(buf1, 0x30);
INCLUDE_BSS(data_buf__2, 0x60);
INCLUDE_BSS(init_dbuf, 0x60);
INCLUDE_BSS(WorkBuffer, 0x30);
INCLUDE_BSS(MenuBuffer__2, 0x30);
INCLUDE_BSS(ChrEffBuffer, 0x30);
INCLUDE_BSS(ScriptBuffer__2, 0x30);
INCLUDE_BSS(TotalDataBuff, 0x30);
INCLUDE_BSS(ControlCharaBuff, 0x30);
INCLUDE_BSS(MainDataBuff, 0x30);
INCLUDE_BSS(MainCharaBuff, 0x30);
INCLUDE_BSS(SubDataBuff, 0x30);
INCLUDE_BSS(SubCharaBuff, 0x30);
INCLUDE_BSS(EventBuff, 0xC0);
INCLUDE_BSS(CharaBufs, 0x180);
INCLUDE_BSS(FishingBuff, 0x30);
INCLUDE_BSS(SkyBuff, 0x30);
INCLUDE_BSS(EditEvent, 0x150);
INCLUDE_BSS(EdDebugInfo, 0x40);
INCLUDE_BSS(TestVisual, 0x50);
INCLUDE_BSS(TestFrame, 0x110);
INCLUDE_BSS(at_1077, 0x10);
INCLUDE_BSS(at_3041, 0x10);
INCLUDE_BSS(beforeAnalyze, 0x40);
