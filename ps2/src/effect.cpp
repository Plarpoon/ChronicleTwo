#include "common.h"
#include "effect.hpp"
#include <cstring>

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", UniformityRand__Fff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", RegularityRand__Fffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", InitEffectParam__FP12EFFECT_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ct__7CEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Initialize__7CEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", SetEffect__7CEffectFP12EFFECT_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Step__7CEffectFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Draw__7CEffectFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ct__11CEffectCtrlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __dt__11CEffectCtrlFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Ctrl__11CEffectCtrlFP7CEffecti);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Initialize__11CEffectCtrlFv);
void CEffectCtrl::Run(void) {
    (*(s32 *)((u8 *)this + 0x10)) = 1;
    (*(s32 *)((u8 *)this + 0x50)) = 0;
    (*(s32 *)((u8 *)this + 0x64)) = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", SetOrigin__11CEffectCtrlFPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __as__11CEffectCtrlFRC11CEffectCtrl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __BUFFER_SIZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __EFFECT_START__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __EFFECT_END__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __WAIT_FRAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __IMG_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SIZE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __DIR__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __NUM__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __NUM_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __COUNT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __CNT_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __REPEAT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __REP_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __POS__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __POS_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __VELO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __VELO_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __VELO_MUL__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ACC__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ACC_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ACC_MUL__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __MOVE_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __MOVE_P1__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __MOVE_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __MOVE_P2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __MOVE_P2_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SVELO__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SVELO_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE_P1__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE_P2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __SCALE_P2_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_BLEND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_P1__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_P1_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_P2__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ALPHA_P2_RAND__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __TEX_GET_RECT__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __TEX_GET_TYPE__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __TEX_NAME__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __GRAVITY__FP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", __ct__14CEffectManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Initialize__14CEffectManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", EntryEffCtrls__14CEffectManagerFP7CEffectiP11CEffectCtrli);
void CEffectManager::SetEffectNums(s32 arg0, s32 arg1) {
    (*(s32 *)((u8 *)this + 0x24)) = arg0;
    (*(s32 *)((u8 *)this + 0x2c)) = arg1;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Ctrl__14CEffectManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Step__14CEffectManagerFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Draw__14CEffectManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Run__14CEffectManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Stop__14CEffectManagerFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", EnterEffectCtrl__14CEffectManagerF11CEffectCtrlPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", GetBufferNums__14CEffectManagerFPciPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", Load__14CEffectManagerFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/effect", SetOrigin__14CEffectManagerFPf);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", effm_tag__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_383__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_382__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_566__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_567__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_568__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_569__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_570__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_571__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_572__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_573__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_574__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_575__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_576__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_577__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_578__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_579__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_580__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_581__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_582__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_583__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_584__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_585__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_586__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_587__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_588__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_589__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_590__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_591__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_592__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_593__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_594__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_595__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_596__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_597__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_598__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_599__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_600__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_601__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_602__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_603__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_604__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_605__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_606__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_607__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_608__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_609__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_610__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_611__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_612__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/effect", at_848__2__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(g_tmp_effm, 0x4);
INCLUDE_BSS(g_tmp_effc, 0x4);
INCLUDE_BSS(g_eff_entry_flag, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(g_tmp_eff_name, 0x20);
