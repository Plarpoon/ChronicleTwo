#include "common.h"
#include "gamepad.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Init__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Close__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", pad_button_read__FP10PAD_STATUSii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", read_pad__FP10PAD_STATUSii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", WaitEnable__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Connect__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", UpDate__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Step__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", AxisCalibration__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetRX__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetRY__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetLX__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetLY__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetRX2__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", CancelAutoRepeat__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", CancelAutoRepeat2__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", SetAutoRepeat__8CGamePadFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", SetAutoRepeat2__8CGamePadFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", KeyLock__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", KeyLock2__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", DebugKeyLock__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetPadOn__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetPadDown__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetPadUp__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetRXf__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetRYf__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetLXf__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetLYf__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GetRXf2__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", On__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", On2__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Down__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Down2__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Up__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", AutoRepeatOff__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", MenuModeOn__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", MenuModeOff__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", SetVibration__8CGamePadFiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", VibrationEnable__8CGamePadFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", StopVibration__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", CaptureStart__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", CaptureEnd__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", CapturePlay__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Capture__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", Play__8CGamePadFP10PAD_STATUS);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", SaveCapture__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", LoadCapture__8CGamePadFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", SwitchGamePadThread__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", GamePadStep__FPv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/gamepad", CreateGamePadThread__FP8CGamePad);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamepad", at_248__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamepad", at_904__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamepad", at_909__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/gamepad", at_910__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(rpad_256, 0x4);
INCLUDE_BSS(init_257, 0x4);
INCLUDE_BSS(cnt_374, 0x4);
INCLUDE_BSS(init_375, 0x4);
INCLUDE_BSS(TheadID, 0x4);
INCLUDE_BSS(GamePad, 0x4);
INCLUDE_BSS(old_vsync__2, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(pad_dma_buf, 0x400);
INCLUDE_BSS(pad_dma_buf2, 0x400);
INCLUDE_BSS(ThreadStack, 0x400);
