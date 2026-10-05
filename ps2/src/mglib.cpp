#include "common.h"
#include "mglib.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgPerformanceMeter__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetPerformanceMeterFlag__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", VSyncCallBack__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgInitVSyncCallBack__FPFi_i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetRotateThread__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", WaitVSync__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetVSyncCount__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", GetScreenSize__FiPiPiPiPiPiPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgInit__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgInitVif1Packet__FP1P1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPacketBuffer__FP9mgCMemoryP9mgCMemory);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetDataBuffer__FP9mgCMemoryP9mgCMemoryi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetDataBuffer__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetTopVRAMAddress__Fv);
float mgGetNowFrameRate(void) {
    return (float)mgFrameRate;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgBeginFrame__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgBeginPacket__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgBeginDraw__FP9mgCMemoryPiP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgEndDraw__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgPreEndDraw__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgEndDrawReloadTexture__FiP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgEndDraw__FiP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgStoreFrameImage__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgEndFrame__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSendPacket__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgEndPacket__FP14mgCDrawManager);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgWaitFrame__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgDraw__FP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgDrawDirect__FP8mgCFrame);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgDrawDirect__FP9mgCVisualPA4_f);
void mgDrawDirectStart(void) {
    sceVif1PkTerminate(mgVif1Packet);
    ddraw_size = 0;
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgDrawDirect2__FP8mgCFrame);
void mgDrawDirectEnd(void) {
    if ((s32) ddraw_size > 0) sceVif1PkReserve(mgVif1Packet, ddraw_size * 4);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetDrawRect__FP8mgCFrameP9mgVu0FBOX);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgBeginDrawShadow__FP10mgCTextureP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgEndDrawShadow__FP10mgCTextureP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetRenderInfo__Ffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetProjection__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetProjection__Fv);
void mgSetBackGround(float *arg0) {
    sceVu0CopyVector(mgBackColor, arg0);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetBackGround__Fffff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgInitLighting__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgInitActiveLighting__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgActiveLighting__Fii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetLight__FPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetLight__FPA4_fPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetLight__FiPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetAmbient__FPf);
void mgGetAmbient(float *arg0) {
    (&mgRenderInfo)->GetAmbient(arg0);
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPlight__FiPfPfff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPlight__FiP13mgPOINT_LIGHT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetPlight__FiP13mgPOINT_LIGHT);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgResetPlight__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetViewMatrix__FPA4_fPf);
void mgSetDropShadowMatrix(float *arg0, float *arg1, float *arg2) {
    (&mgRenderInfo)->SetDropShadowMatrix(arg0, arg1, arg2);
}
void mgFogEnable(s32 arg0) {
    (&mgRenderInfo)->FogEnable(arg0);
}
s32 mgGetFogEnable(void) {
    return (&mgRenderInfo)->GetFogEnable();
}
void mgPlightEnable(s32 arg0) {
    (&mgRenderInfo)->PlightEnable(arg0);
}
s32 mgGetPlightEnable(void) {
    return (&mgRenderInfo)->GetPlightEnable();
}
void mgSetFogParam(float a, float b, u8 c, u8 d, u8 e, float f, float g) {
    (&mgRenderInfo)->SetFogParam(a, b, c, d, e, f, g);
}
void mgSetFogParam(mgFOG_PARAM *arg0) {
    (&mgRenderInfo)->SetFogParam((*(float *)((u8 *)arg0 + 0x0)), (*(float *)((u8 *)arg0 + 0x4)), (*(u8 *)((u8 *)arg0 + 0x8)), (*(u8 *)((u8 *)arg0 + 0x9)), (*(u8 *)((u8 *)arg0 + 0xa)), (*(float *)((u8 *)arg0 + 0x10)), (*(float *)((u8 *)arg0 + 0x14)));
}
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetFogParam__FP11mgFOG_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetAllScissorFlag__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgFlushRenderInfo__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkTextureRepeat__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkTextureRepeat__F10sceGsClamp);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkFrameBuffer__FP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkFrameBuffer__Fiiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetFrameBuffer__FP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetFrameBackBuffer__FP10mgCTexture);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetpDrawEnv__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkMoveImage__FP10mgCTexture9mgRect_i_P10mgCTextureiii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkMoveImage__FP9sceGsTex09mgRect_i_P9sceGsTex0iii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkMoveImage__FP10mgCTexture9mgRect_i_P10mgCTexture9mgRect_i_P10mgCDrawEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkMoveImage__FP9sceGsTex09mgRect_i_P9sceGsTex0i9mgRect_i_P10mgCDrawEnv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetPkClearScreen__FUcUcUcUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgStoreImage__FP10mgCTextureP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgStoreZBuffImage__FR9mgRect_i_P1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgConvZBuffToDist__FUi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetTextureZ__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", prim_clip_check__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgTransWorldPrim__FPiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgTransWorldScreen__FPiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgTransViewPrim__FPiPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgTransWorldView__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgTransZPrim__Ff);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetDistFromCamera__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetDirFromCamera__FPfPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetCameraPos__FPf);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetCameraPose__FPA4_f);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgTransWorldPrim3DSprite__FPiPiPfffi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", CheckVuProgID__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgGetVuProgPacket__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSendVuProg__FPUii);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetUserVuProg__FPP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgSetUserVuProgAdr__FiP1);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", StoreImage__Fi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgInitFont__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", mgCloseFont__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", __ct__9mgCMemoryFv);

// Static initialiser (.init)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mglib", __sinit_mglib_cpp);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", dimx_281__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", at_1389__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", prog_adr__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", at_1538__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", at_715__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", at_716__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", at_1568__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", at_1569__DATA);

// Static initialiser table (.ctor)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", D_0037AFE8__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", font_cons__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", rot_priority__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/mglib", now_prog_id__DATA);

// Small uninitialised data (.sbss)
INCLUDE_BSS(mgAntialiasing, 0x4);
INCLUDE_BSS(mgFrameRate, 0x4);
INCLUDE_BSS(mgNowFrameRate, 0x4);
INCLUDE_BSS(DmaCH1, 0x4);
INCLUDE_BSS(DmaCH2, 0x4);
INCLUDE_BSS(DmaCH8, 0x4);
INCLUDE_BSS(mgVif1Packet, 0x4);
INCLUDE_BSS(mgClearBackFlag, 0x4);
INCLUDE_BSS(mgScreenMode, 0x4);
INCLUDE_BSS(mgScreenWidth, 0x4);
INCLUDE_BSS(mgScreenHeight, 0x4);
INCLUDE_BSS(mgScreenNX, 0x4);
INCLUDE_BSS(mgScreenNY, 0x4);
INCLUDE_BSS(mgScreenMX, 0x4);
INCLUDE_BSS(mgScreenMY, 0x4);
INCLUDE_BSS(mgScreenOffx, 0x4);
INCLUDE_BSS(mgScreenOffy, 0x4);
INCLUDE_BSS(mgScreenDepth, 0x4);
INCLUDE_BSS(mgScreenZDepth, 0x4);
INCLUDE_BSS(mgScreenLeft, 0x4);
INCLUDE_BSS(mgScreenRight, 0x4);
INCLUDE_BSS(mgScreenTop, 0x4);
INCLUDE_BSS(mgScreenBottom, 0x4);
INCLUDE_BSS(VSyncField, 0x8);
INCLUDE_BSS(mgTEX1_1, 0x8);
INCLUDE_BSS(mgTEX1_2, 0x8);
INCLUDE_BSS(mgTEST_1, 0x8);
INCLUDE_BSS(mgTEST_2, 0x8);
INCLUDE_BSS(mgZBUF_1, 0x8);
INCLUDE_BSS(mgZBUF_2, 0x8);
INCLUDE_BSS(mgALPHA_1, 0x8);
INCLUDE_BSS(mgALPHA_2, 0x8);
INCLUDE_BSS(mgTEXA_1, 0x8);
INCLUDE_BSS(mgTEXA_2, 0x8);
INCLUDE_BSS(mgFRAME_1, 0x8);
INCLUDE_BSS(mgDBuffID, 0x4);
INCLUDE_BSS(mgDataID, 0x4);
INCLUDE_BSS(mgChangeLight, 0x8);
INCLUDE_BSS(packetbuf, 0x8);
INCLUDE_BSS(packet_size, 0x4);
INCLUDE_BSS(frame_buf0, 0x4);
INCLUDE_BSS(frame_buf1, 0x4);
INCLUDE_BSS(font_draw_flag, 0x4);
INCLUDE_BSS(draw_performance_meter, 0x8);
INCLUDE_BSS(mgDIMX, 0x8);
INCLUDE_BSS(vcount, 0x4);
INCLUDE_BSS(old_vcount, 0x4);
INCLUDE_BSS(over_vsync, 0x4);
INCLUDE_BSS(VSyncCallBack2, 0x4);
INCLUDE_BSS(call_back_active, 0x4);
INCLUDE_BSS(h_count, 0x4);
INCLUDE_BSS(capture_on, 0x4);
INCLUDE_BSS(cap_ture_cnt, 0x4);
INCLUDE_BSS(count_580, 0x4);
INCLUDE_BSS(init_581, 0x4);
INCLUDE_BSS(cpu_ratio_583, 0x4);
INCLUDE_BSS(init_584, 0x4);
INCLUDE_BSS(free_ratio_586, 0x4);
INCLUDE_BSS(init_587, 0x4);
INCLUDE_BSS(ddraw_size, 0x4);
INCLUDE_BSS(user_prog_adr, 0x4);
INCLUDE_BSS(user_prog_num, 0x4);
INCLUDE_BSS(image_num_1535, 0x4);
INCLUDE_BSS(init_1536, 0x4);

// Uninitialised data (.bss)
INCLUDE_BSS(mgGiftagAD, 0x10);
INCLUDE_BSS(mgRenderInfo, 0x1020);
INCLUDE_BSS(mgBackColor, 0x10);
INCLUDE_BSS(mgTexManager, 0x220);
INCLUDE_BSS(mgDrawManager, 0x80);
INCLUDE_BSS(mgDBuff, 0x230);
INCLUDE_BSS(mgPickZBuff, 0x40);
INCLUDE_BSS(vifpacket, 0x40);
INCLUDE_BSS(packet_buf, 0x60);
INCLUDE_BSS(data_buf, 0x60);
INCLUDE_BSS(frame_tex, 0x70);
INCLUDE_BSS(store_data_614, 0x1000);
INCLUDE_BSS(at_863, 0x10);
INCLUDE_BSS(fixz_tex, 0xE0);
INCLUDE_BSS(gs_simage, 0xA0);
