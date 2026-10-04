#include "common.h"
#include "mg_sprite.hpp"

#include <cmath>

#include "mg_drawprim.hpp"
#include "mg_frame.hpp"
#include "mg_math.hpp"
#include "mglib.hpp"

#ifdef NONMATCHING
/**
 *
 * GIF tag of the GS register writes that draw an mgCSprite, in A+D mode, whose loop count CreatePacket sets.
 *
 */
static sceGifTag sprite_giftag = {0, 1, 0, 0, 0, 0, 1, SCE_GIF_PACKED_AD};
#endif

// Code (.text)
#ifdef NONMATCHING
int mgC3DSprite::CreateRenderInfoPacket(u_int *dest, float (*matrix)[4], mgRENDER_INFO *render_info) {
    sceVu0FMATRIX local_screen;
    sceVu0IVECTOR zero = {0, 0, 0, 0};
    mg3DSpriteRenderInfo *info;
    mgCFrameAttr *attr;
    float scale_x;
    float scale_y;
    float scale_z;
    u_int flags;
    u_int fog_color;
    int size;

    mgMulMatrix(local_screen, render_info->world_screen, matrix);
    info = (mg3DSpriteRenderInfo *)GetScrPad();
    render_info->GetpLightInfo();

    info->dma_tag[0] = MG_DMA_CNT;
    info->dma_tag[1] = 0;
    info->dma_tag[2] = 0;
    info->dma_tag[3] = 0;
    info->vif_code[0] = 0;
    info->vif_code[1] = MG_VIF_BASE | 0x3C;
    info->vif_code[2] = MG_VIF_OFFSET | 0xB4;
    *(u_long128 *)info->unk_20[0] = *(u_long128 *)zero;
    *(u_long128 *)info->unk_20[1] = *(u_long128 *)zero;
    *(u_long128 *)info->unk_20[2] = *(u_long128 *)zero;
    info->unk_50[0] = render_info->unk_fb0[3];
    info->unk_50[1] = render_info->unk_fb0[0];
    info->unk_50[2] = render_info->unk_fb0[1];
    info->unk_50[3] = render_info->unk_fb0[2];
    sceVu0CopyMatrix(info->local_screen, local_screen);
    sceVu0CopyMatrix(info->local_world, matrix);
    render_info->scissor = 0;

    info->fog[0] = render_info->fog.offset;
    info->fog[1] = render_info->fog.near_value;
    info->fog[2] = render_info->fog.far_value;
    info->fog[3] = render_info->fog.scale;

    // The sprites are sized in view space, so the view axes take on the scale of the local transform.
    scale_x = mgDistVector(matrix[0]);
    scale_y = mgDistVector(matrix[1]);
    scale_z = mgDistVector(matrix[2]);
    *(u_long128 *)info->view_screen[0] = *(u_long128 *)render_info->view_screen[0];
    *(u_long128 *)info->view_screen[1] = *(u_long128 *)render_info->view_screen[1];
    *(u_long128 *)info->view_screen[2] = *(u_long128 *)render_info->view_screen[2];
    *(u_long128 *)info->view_screen[3] = *(u_long128 *)render_info->view_screen[3];
    sceVu0ScaleVectorXYZ(info->view_screen[0], info->view_screen[0], scale_x);
    sceVu0ScaleVectorXYZ(info->view_screen[1], info->view_screen[1], scale_y);
    sceVu0ScaleVectorXYZ(info->view_screen[2], info->view_screen[2], scale_z);

    info->vif_code[3] = MG_VIF_UNPACK_V4_32 |
                        (((u_int *)info->program_call - info->vif_code) / 4 - 1) << MG_VIF_NUM_SHIFT;
    info->program_call[0] = 0;
    info->program_call[1] = 0;
    info->program_call[2] = 0;
    info->program_call[3] = MG_VIF_MSCAL;
    info->dma_tag[0] |= (info->flags_tag - info->vif_code) / 4;

    flags = 0;
    if (render_info->clip | render_info->scissor) {
        flags |= MG_3DSPRITE_FLAG_CLIP;
    }
    if (render_info->scissor) {
        flags |= MG_3DSPRITE_FLAG_SCISSOR;
    }
    attr = render_info->attr;
    if (attr->program_mode) {
        flags |= MG_3DSPRITE_FLAG_PROGRAM_MODE;
    }
    if (attr->program_option) {
        flags |= MG_3DSPRITE_FLAG_PROGRAM_OPTION;
    }
    if (render_info->plight_hit) {
        flags |= MG_3DSPRITE_FLAG_POINT_LIGHT;
    }
    if (attr->no_light) {
        flags |= MG_3DSPRITE_FLAG_NO_LIGHT;
    }

    info->flags_tag[0] = MG_DMA_CNT | 6;
    info->flags_tag[1] = 0;
    info->flags_tag[2] = 0;
    info->flags_tag[3] = MG_VIF_UNPACK_V4_32 | 1 << MG_VIF_NUM_SHIFT | 0x26;
    info->flags[0] = flags;
    info->flags[1] = 0;
    info->flags[2] = 0;
    info->flags[3] = 0;
    info->direct_tag[0] = 0;
    info->direct_tag[1] = 0;
    info->direct_tag[2] = 0;
    info->direct_tag[3] = MG_VIF_DIRECT | 4;
    info->giftag[0] = MG_GIFTAG_EOP | 3;
    info->giftag[1] = 1 << MG_GIFTAG_NREG_SHIFT;
    info->giftag[2] = SCE_GIF_PACKED_AD;
    info->giftag[3] = 0;
    info->prmodecont[0] = 0;
    info->prmodecont[1] = 0;
    info->prmodecont[2] = SCE_GS_PRMODECONT;
    info->prmodecont[3] = 0;

    prmode = SCE_GS_SET_PRIM(0, 1, 1, render_info->attr->fog && render_info->fog_enable, 1, 0, 1, 0, 0);
    info->prmode[0] = prmode;
    info->prmode[1] = 0;
    info->prmode[2] = SCE_GS_PRMODE;
    info->prmode[3] = 0;

    // The black and white fog modes do not use the scene's fog colour.
    fog_color = render_info->fog.r | render_info->fog.g << 8 | render_info->fog.b << 16;
    if (render_info->attr->fog >= 2) {
        fog_color = 0;
    }
    info->fogcol[0] = fog_color;
    info->fogcol[1] = 0;
    info->fogcol[2] = SCE_GS_FOGCOL;
    info->fogcol[3] = 0;
    info->ret_tag[0] = MG_DMA_RET;
    info->ret_tag[1] = 0;
    info->ret_tag[2] = 0;
    info->ret_tag[3] = 0;

    size = ((u_int *)(info + 1) - (u_int *)info) / 4;
    SendDMA(dest, size);
    return size;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CreateRenderInfoPacket__11mgC3DSpriteFPUiPA4_fP13mgRENDER_INFO);
#endif

#ifdef NONMATCHING
int mgC3DSprite::Draw(u_int *tag, float (*matrix)[4], mgCDrawManager *manager) {
    mgRENDER_INFO *render_info;
    mgCMemory *data_memory;
    u_long128 *render_packet;
    u_int *p;

    if (manager == NULL) {
        manager = &mgDrawManager;
    }
    render_info = manager->render_info;
    texture_manager = manager->texture_manager;
    if (packet == NULL) {
        return 0;
    }

    data_memory = manager->data_memory;
    render_packet = data_memory->stAllocTest(0x3C);
    data_memory->Alloc(CreateRenderInfoPacket((u_int *)render_packet, matrix, render_info));
    if (tag == NULL) {
        return 0;
    }

    tag[0] = MG_DMA_CALL;
    tag[1] = (u_int)render_packet;
    tag[2] = 0;
    tag[3] = 0;
    p = &tag[4];
    p = &p[mgSendVuProg(p, MG_VU_PROG_3DSPRITE)];
    p[0] = MG_DMA_CALL;
    p[1] = (u_int)packet;
    p[2] = 0;
    p[3] = 0;
    return (&p[4] - tag) / 4;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__11mgC3DSpriteFPUiPA4_fP14mgCDrawManager);
#endif

void mgC3DSprite::BeginCreatePacket(int mode, mgCDrawManager *manager) {
    if (manager == NULL) {
        manager = &mgDrawManager;
    }
    memory = manager->data_memory;
    packet = &memory->stack[memory->stack_used];
    packet_start = (u_long128 *)((u_int)packet | MG_UNCACHED);
    packet_cur = packet_start;
    this->mode = mode;
    prog_started = 0;
}

#ifdef NONMATCHING
void mgC3DSprite::CPSetDrawEnv(mgCDrawEnv *env) {
    u_int *p;
    int alpha;

    if (env != NULL) {
        p = (u_int *)packet_cur;
        p[0] = MG_DMA_CNT | 4;
        p[2] = 0;
        p[1] = 0;
        p[3] = MG_VIF_DIRECT | 4;
        packet_cur++;
        *(mgCDrawEnv *)packet_cur = *env;
        packet_cur += sizeof(mgCDrawEnv) / sizeof(u_long128);

        alpha = env->GetAlphaMacroID();
        if (alpha == MG_ALPHA_MACRO_ADD || alpha == MG_ALPHA_MACRO_SUB) {
            // Additive and subtractive blends fog towards black so that fogged pixels fade out.
            p = (u_int *)packet_cur;
            p[0] = MG_DMA_CNT | 2;
            p[1] = 0;
            p[2] = 0;
            p[3] = MG_VIF_DIRECT | 2;
            p[4] = MG_GIFTAG_EOP | 1;
            p[5] = 1 << MG_GIFTAG_NREG_SHIFT;
            p[6] = SCE_GIF_PACKED_AD;
            p[7] = 0;
            p[8] = 0;
            p[9] = 0;
            p[10] = SCE_GS_FOGCOL;
            p[11] = 0;
            packet_cur += 3;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CPSetDrawEnv__11mgC3DSpriteFP10mgCDrawEnv);
#endif

void mgC3DSprite::CPSetTexture(mgCTexture *texture) {
    if (texture != NULL) {
        packet_cur += mgSetPkTexFlush_TagCnt((u_int *)packet_cur);
        packet_cur += mgSetPkTEX0((u_int *)packet_cur, texture->tex0.value, *(u_long *)&texture->tex1);
    }
}

#ifdef NONMATCHING
void mgC3DSprite::BeginCPSprite() {
    sceGifTag *giftag;

    batch_tag = (u_int *)packet_cur++;
    batch_giftag = (sceGifTag *)packet_cur++;
    batch_header = (u_int *)packet_cur++;
    sprite_num = 0;

    giftag = batch_giftag;
    *(u_long128 *)giftag = 0;
    giftag->EOP = 1;
    giftag->PRE = 1;
    if (mode == MG_3DSPRITE_MODE_ROTATE) {
        giftag->PRIM = SCE_GS_SET_PRIM(SCE_GS_PRIM_TRISTRIP, 1, 1, 0, 1, 0, 0, 0, 0);
        giftag->NREG = 9;
        giftag->REGS0 = SCE_GS_RGBAQ;
        giftag->REGS1 = SCE_GS_UV;
        giftag->REGS2 = SCE_GS_XYZF2;
        giftag->REGS3 = SCE_GS_UV;
        giftag->REGS4 = SCE_GS_XYZF2;
        giftag->REGS5 = SCE_GS_UV;
        giftag->REGS6 = SCE_GS_XYZF2;
        giftag->REGS7 = SCE_GS_UV;
        giftag->REGS8 = SCE_GS_XYZF2;
    } else {
        giftag->PRIM = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 1, 1, 0, 1, 0, 0, 0, 0);
        giftag->NREG = 5;
        giftag->REGS0 = SCE_GS_RGBAQ;
        giftag->REGS1 = SCE_GS_UV;
        giftag->REGS2 = SCE_GS_XYZF2;
        giftag->REGS3 = SCE_GS_UV;
        giftag->REGS4 = SCE_GS_XYZF2;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", BeginCPSprite__11mgC3DSpriteFv);
#endif

#ifdef NONMATCHING
void mgC3DSprite::CPSetSprite(float *pos, float *size, float *color, float *uv0, float *uv1) {
    *packet_cur++ = *(u_long128 *)pos;
    if (mode == MG_3DSPRITE_MODE_ROTATE) {
        float *rotated = (float *)packet_cur++;

        *(u_long128 *)rotated = *(u_long128 *)size;
        rotated[2] = sinf(size[2]);
        rotated[3] = cosf(size[2]);
    } else {
        *packet_cur++ = *(u_long128 *)size;
    }
    *packet_cur++ = *(u_long128 *)color;
    *packet_cur++ = *(u_long128 *)uv0;
    *packet_cur++ = *(u_long128 *)uv1;

    sprite_num++;
    if (sprite_num > MG_3DSPRITE_BATCH_MAX) {
        EndCPSprite();
        BeginCPSprite();
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CPSetSprite__11mgC3DSpriteFPfPfPfPfPf);
#endif

#ifdef NONMATCHING
void mgC3DSprite::EndCPSprite() {
    static u_int prog_vif[4] = {0, 0, 0, MG_VIF_MSCAL | 2};
    static u_int progf_vif[4] = {0, 0, 0, MG_VIF_MSCNT};
    u_int flush[4] = {MG_VIF_FLUSHA, 0, 0, 0};
    u_int qwc;
    u_int *p;

    qwc = ((u_long128 *)packet_cur - (u_long128 *)batch_tag) - 1;
    batch_tag[0] = qwc | MG_DMA_CNT;
    batch_tag[1] = 0;
    batch_tag[2] = 0;
    batch_tag[3] = qwc << MG_VIF_NUM_SHIFT | MG_VIF_UNPACK_V4_32 | MG_VIF_UNPACK_FLG;
    batch_header[0] = sprite_num;
    batch_header[1] = mode;
    batch_header[2] = 0;
    batch_header[3] = 6;

    if (sprite_num > 0) {
        p = (u_int *)packet_cur++;
        p[0] = MG_DMA_CNT | 2;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        // The first batch starts the VU program; later batches continue it.
        if (prog_started == 0) {
            *packet_cur++ = *(u_long128 *)prog_vif;
            prog_started = 1;
        } else {
            *packet_cur++ = *(u_long128 *)progf_vif;
        }
        *packet_cur++ = *(u_long128 *)flush;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", EndCPSprite__11mgC3DSpriteFv);
#endif

void mgC3DSprite::EndCreatePacket() {
    u_int *p;

    p = (u_int *)packet_cur;
    packet_cur += 3;
    p[0] = MG_DMA_CNT | 1;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = MG_VIF_FLUSHA;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = MG_DMA_RET;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    memory->Alloc(packet_cur - packet_start);
}

void mgCSprite::Initialize() {
    mgCVisualPrim::Initialize();
    texture = NULL;
    depth = -1.0f;
    SetColor(0x80, 0x80, 0x80, 0x80);
    attr.z_write = MG_ZBUF_NO_WRITE;
    attr.z_test = MG_DEPTH_TEST_ALWAYS;
}

#ifdef NONMATCHING
void mgCSprite::SetColor(int r, int g, int b, int a) {
    color.bits.r = r;
    color.bits.g = g;
    color.bits.b = b;
    color.bits.a = a;
    color.bits.q = 0;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", SetColor__9mgCSpriteFiiii);
#endif

#ifdef NONMATCHING
u_int mgCSprite::CreatePacket(mgCDrawManager *manager) {
    mgCMemory *packet_memory;
    mgCMemory *data_memory;
    u_int *start;
    u_int *p;
    u_long *ad;
    u_long z;
    int screen_z[4];
    float view[4];

    packet_memory = manager->packet_memory;
    data_memory = manager->data_memory;
    start = (u_int *)&packet_memory->stack[packet_memory->stack_used];
    p = start;
    if (texture != NULL) {
        p = &p[mgSetPkTEX0(p, texture->tex0.value, *(u_long *)&texture->tex1) * 4];
    }

    p[0] = MG_DMA_CNT | 9;
    p[1] = 0;
    p[2] = 0;
    p[3] = MG_VIF_DIRECT | 9;
    sprite_giftag.NLOOP = 8;
    *(sceGifTag *)&p[4] = sprite_giftag;

    // Drawn at depth zero unless a view depth is given and lands on the screen.
    z = 0;
    if (depth >= 1.0f) {
        view[0] = 0.0f;
        view[1] = 0.0f;
        view[2] = depth;
        view[3] = 1.0f;
        if (mgTransViewPrim(screen_z, view)) {
            z = screen_z[2];
        }
    }

    ad = (u_long *)&p[8];
    ad[0] = 1;
    ad[1] = SCE_GS_PRMODECONT;
    ad[2] = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, texture != NULL, 0, 1, 0, 1, 0, 0);
    ad[3] = SCE_GS_PRIM;
    ad[4] = color.value;
    ad[5] = SCE_GS_RGBAQ;
    ad[6] = SCE_GS_SET_UV(uv.left, uv.top);
    ad[7] = SCE_GS_UV;
    ad[8] = (u_long)(screen.left + mgScreenOffx * 16) | (u_long)(screen.top + mgScreenOffy * 16) << 16 | z << 32;
    ad[9] = SCE_GS_XYZ2;
    ad[10] = SCE_GS_SET_UV(uv.right, uv.bottom);
    ad[11] = SCE_GS_UV;
    ad[12] = (u_long)(screen.right + mgScreenOffx * 16) | (u_long)(screen.bottom + mgScreenOffy * 16) << 16 | z << 32;
    ad[13] = SCE_GS_XYZ2;
    ad[14] = 0;
    ad[15] = SCE_GS_TEXFLUSH;
    p = (u_int *)&ad[16];
    p[0] = MG_DMA_RET;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;

    packet_memory->Alloc((&p[4] - start) / 4);
    data_memory->Alloc(0);
    return (u_int)start & 0x0FFFFFFF;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", CreatePacket__9mgCSpriteFP14mgCDrawManager);
#endif

#ifdef NONMATCHING
int mgCSprite::Draw(u_int *tag, float (*matrix)[4], mgCDrawManager *manager) {
    mgRENDER_INFO *render_info;
    mgCMemory *data_memory;
    u_long128 *render_packet;
    u_int sprite_packet;

    if (manager == NULL) {
        manager = &mgDrawManager;
    }
    render_info = manager->render_info;
    texture_manager = manager->texture_manager;
    data_memory = manager->data_memory;
    render_packet = data_memory->stAllocTest(0x3C);
    data_memory->Alloc(CreateRenderInfoPacket((u_int *)render_packet, matrix, render_info));
    sprite_packet = CreatePacket(manager);
    if (tag == NULL) {
        return 0;
    }

    tag[0] = MG_DMA_CALL;
    tag[1] = (u_int)render_packet;
    tag[2] = 0;
    tag[3] = 0;
    tag[4] = MG_DMA_CALL;
    tag[5] = sprite_packet;
    tag[6] = 0;
    tag[7] = 0;
    return 2;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__9mgCSpriteFPUiPA4_fP14mgCDrawManager);
#endif

#ifdef NONMATCHING
// Defined in mg_sprite.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__9mgCSpriteFPA4_fP14mgCDrawManager);
#endif

#ifdef NONMATCHING
// Defined in mg_visual.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Iam__13mgCVisualPrimFv);
#endif

#ifdef NONMATCHING
// Defined in mg_sprite.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Draw__11mgC3DSpriteFPA4_fP14mgCDrawManager);
#endif

#ifdef NONMATCHING
// Defined in mg_sprite.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/mg_sprite", Initialize__11mgC3DSpriteFv);
#endif

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
