#include "common.h"
#include "mg_sprite.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CreateRenderInfoPacket__11mgC3DSpriteFPUiPA4_fP13mgRENDER_INFO);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__11mgC3DSpriteFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", BeginCreatePacket__11mgC3DSpriteFiP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CPSetDrawEnv__11mgC3DSpriteFP10mgCDrawEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CPSetTexture__11mgC3DSpriteFP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", BeginCPSprite__11mgC3DSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CPSetSprite__11mgC3DSpriteFPfPfPfPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", EndCPSprite__11mgC3DSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", EndCreatePacket__11mgC3DSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Initialize__9mgCSpriteFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", SetColor__9mgCSpriteFiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CreatePacket__9mgCSpriteFP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__9mgCSpriteFPUiPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__9mgCSpriteFPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Iam__13mgCVisualPrimFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__11mgC3DSpriteFPA4_fP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Initialize__11mgC3DSpriteFv);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", sprite_giftag__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", prog_vif_291__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", progf_vif_292__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", at_298__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", at_324__2__DATA);

// Virtual tables (.vtables)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", __vt__9mgCSprite__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mg_sprite", __vt__11mgC3DSprite__DATA);

// Uninitialised data (.bss)
INCLUDE_BSS(at_199, 0x10);
