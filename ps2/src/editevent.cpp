#include "common.h"
#include "editevent.hpp"
#include "dataread.hpp"
#include "cameracontrol.hpp"
#include "editloop.hpp"
#include "editmap.hpp"
#include "editparts.hpp"
#include "gamedata.hpp"
#include "mainloop.hpp"
#include "mapjump.hpp"
#include "menumain.hpp"
#include "mg_math.hpp"
#include "mg_texture.hpp"
#include "mglib.hpp"
#include "nd_meswin.hpp"
#include "padcontrol.hpp"
#include "runscript.hpp"
#include "savedata.hpp"
#include "scenesnd.hpp"
#include "snd_mngr.hpp"
#include "userdata.hpp"
#include "vlgr_info.hpp"
#include <cstring>
#include <cstdio>
#include <cmath>

static int CheckPlaceBurnParts(GeoFuncParam *param, RS_STACKDATA *args, int argc);
static int LoadIntNPC(GeoFuncParam *param, RS_STACKDATA *args, int argc);
static int LoadGeoNPC(GeoFuncParam *param, int check_only);

// Code (.text)
void CEditEvent::Reset() {
    state = EDIT_EVENT_STATE_IDLE;
    unk_c = 0;
    count = 0;
    type = EDIT_EVENT_TYPE_NONE;
    door_se = -1;
    map_name[0] = 0;
    memset(&data, 0, sizeof(data));
}
#ifdef NONMATCHING
int CEditEvent::StartEvent(CSceneEventData *event_data) {
    if (event_data == NULL) return 0;
    if (state == EDIT_EVENT_STATE_RUNNING || state == EDIT_EVENT_STATE_UNK_2) {
        printf("now running!!!\n");
        return 0;
    }
    state = EDIT_EVENT_STATE_RUNNING;
    count = 0;
    step = 0;
    type = EDIT_EVENT_TYPE_NONE;
    data = *event_data;
    if (data.event.flag & FUNC_EVENT_DOOR) {
        type = data.event.flag & FUNC_EVENT_ED_DOOR ? EDIT_EVENT_TYPE_HOUSE_DOOR : EDIT_EVENT_TYPE_DOOR;
        if (data.event.flag & FUNC_EVENT_CLOSE_DOOR) data.event.point_no = 0xF9;
    }
    if (data.event.flag & FUNC_EVENT_TREASURE_BOX) type = EDIT_EVENT_TYPE_TREASURE_BOX;
    if (data.event.flag & FUNC_EVENT_BOOK) type = EDIT_EVENT_TYPE_BOOK;
    if (type == EDIT_EVENT_TYPE_NONE) return 0;
    projection = mgGetProjection();
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", StartEvent__10CEditEventFP15CSceneEventData);
#endif
#ifdef NONMATCHING
int CEditEvent::Step(CScene *scene) {
    if (state != EDIT_EVENT_STATE_RUNNING) return EDIT_EVENT_RESULT_IDLE;
    ++count;
    CEditMap *map = (CEditMap *)scene->GetMap(scene->active_map);
    CSaveData *save = GetSaveData();
    CMapFlagData *map_flags = save->GetMapFlag(scene->GetMainMapNo());
    CCharacter2 *character = scene->GetCharacter(scene->player_chara);
    mgCCamera *camera = scene->GetCamera(scene->active_camera);
    if (character == NULL || camera == NULL || map == NULL) return EDIT_EVENT_RESULT_END;
    ClsMes *message = scene->GetMessage(1);
    int result = EDIT_EVENT_RESULT_CONTINUE;
    float camera_pos[4], chara_pos[4], chara_rot[4];
    camera->GetPos(camera_pos);
    character->GetPosition(chara_pos);
    character->GetRotation(chara_rot);

    if (type == EDIT_EVENT_TYPE_HOUSE_DOOR) {
        switch (step) {
        case EDIT_HOUSE_DOOR_STEP_OPEN_MENU:
            MenuArg.open_type = 0xC;
            MenuArg.scene = scene;
            MenuArg.param[0] = data.chara_no;
            ((CCameraControl *)camera)->CancelRotBack();
            KeepEditAnalyze();
            ++step;
            result = EDIT_EVENT_RESULT_MENU;
            break;
        case EDIT_HOUSE_DOOR_STEP_MENU_END:
            mgSetProjection(projection);
            if (MenuArg.end_code == 9) {
                type = EDIT_EVENT_TYPE_DOOR;
                count = step = 0;
            } else {
                ++step;
                EditDataSave();
                CEditParts *parts = map->GetePlaceParts(data.chara_no);
                if (MenuArg.end_code == 0xD && parts != NULL && parts->GetInfoID() == 0x49) {
                    scene->fade.FadeOut(0x12, 0.0f, 0.0f, 0.0f);
                    reload_geo_npc = 1;
                } else {
                    count = 0x14;
                    reload_geo_npc = 0;
                }
            }
            break;
        case EDIT_HOUSE_DOOR_STEP_WAIT:
            if (count >= 0x14 || scene->fade.FadeCheck()) {
                if (reload_geo_npc) {
                    scene->fade.FadeIn(0x14);
                    GeoFuncParam param = {scene};
                    LoadGeoNPC(&param, 0);
                }
                if (EditAnalyzeChanged()) scene->RunEvent(0x136, NULL);
                result = EDIT_EVENT_RESULT_END;
            }
            break;
        }
    } else if (type == EDIT_EVENT_TYPE_DOOR) {
        float *door_pos = data.map_event.matrix[3];
        float target_angle = atan2f(data.map_event.matrix[2][0], data.map_event.matrix[2][2]);
        switch (step) {
        case EDIT_DOOR_STEP_START:
            if (strcmp(data.event.unk_38, "exit") != 0) {
                strcpy(map_name, data.event.unk_38);
                if (data.event.flag & FUNC_EVENT_ED_DOOR) {
                    CEditParts *parts = map->GetePlaceParts(data.chara_no);
                    int villager = parts != NULL ? parts->GetLiveNPC() : -1;
                    CVillagerInfo *info = GetVillagerInfo(villager);
                    reload_geo_npc = villager;
                    if (strlen(map_name) < 4) {
                        static const char *suffix[4] = {"ia", "ib", "ic", "id"};
                        strcat(map_name, info != NULL ? suffix[info->house_type % 4] : "ia");
                    }
                }
                ((CCameraControl *)camera)->RotBack(mgAngleLimit(3.1415927f + target_angle));
            }
            door_se = -1;
            memcpy(return_pos, chara_pos, sizeof(return_pos));
            memcpy(return_rot, chara_rot, sizeof(return_rot));
            step = EDIT_DOOR_STEP_APPROACH;
            break;
        case EDIT_DOOR_STEP_APPROACH: {
            character->SetMotion("\225\340\202\253", 0);
            float rotation[4] = {0.0f, mgAngleInterpolate(chara_rot[1], target_angle, 0.3f, 0), 0.0f, 1.0f};
            float position[4];
            mgVectorInterpolate(position, chara_pos, door_pos, 1.0f, 0);
            if (mgDistVector(data.map_event.matrix[0]) < 20.0f) character->SetPosition(position);
            character->SetRotation(rotation);
            if ((!mgAngleCmp(rotation[1], target_angle, 0.1f) && mgDistVectorXZ(position, door_pos) < 1.0f) || count > 200) {
                step = EDIT_DOOR_STEP_OPEN;
                count = data.event.unk_2c < 0 ? 0xE : 0;
                if (data.event.unk_2c >= 0)
                    character->SetMotion((char *)(data.event.flag & FUNC_EVENT_CLOSE_DOOR ? "\203h\203A\212J\202\251\202\310\202\242" : "\203h\203A\212J\202\257"), 2);
            }
            break;
        }
        case EDIT_DOOR_STEP_OPEN:
            if (data.event.flag & FUNC_EVENT_CLOSE_DOOR) {
                if (character->CheckMotionEnd() || count >= 0x3D || !scene->CheckDrawChara(scene->player_chara)) step = EDIT_DOOR_STEP_RETURN;
                if (count == 0x1E) scene->SePlayOpenDoor(0x18, door_pos);
            } else {
                if (count == 0xF && (data.event.flag & FUNC_EVENT_UNK_100)) scene->fade.FadeOut(0x1E, 0.0f, 0.0f, 0.0f);
                if (count == 0x14) {
                    scene->SePlayOpenDoor(data.event.unk_30, door_pos);
                    door_se = data.event.unk_30;
                }
                if (count >= 0x10 && scene->fade.FadeCheck()) step = EDIT_DOOR_STEP_LEAVE;
            }
            break;
        case EDIT_DOOR_STEP_LEAVE:
            ((CCameraControl *)camera)->CancelRotBack();
            if (data.event.point_no > 0) {
                scene->RunEvent(data.event.point_no, &data);
                result = EDIT_EVENT_RESULT_END;
            } else if (scene->fade.FadeCheck()) {
                if (!strcmp(data.event.unk_38, "exit")) {
                    scene->fade.FadeIn(0x1E);
                    result = EDIT_EVENT_RESULT_EXIT;
                } else {
                    PreLoadSync();
                    scene->fade.FadeIn(0x1E);
                    result = data.event.flag & FUNC_EVENT_ED_DOOR ? EDIT_EVENT_RESULT_ENTER_HOUSE : EDIT_EVENT_RESULT_ENTER;
                }
            }
            break;
        case EDIT_DOOR_STEP_RETURN: {
            float position[4];
            mgVectorInterpolate(position, chara_pos, return_pos, 1.0f, 0);
            float rotation[4] = {0.0f, mgAngleInterpolate(chara_rot[1], atan2f(camera_pos[0] - chara_pos[0], camera_pos[2] - chara_pos[2]), 0.2f, 0), 0.0f, 1.0f};
            if (mgDistVector(position, return_pos) < 1.0f) {
                step = EDIT_DOOR_STEP_WAIT;
                character->SetMotion("\202\276\202\337\202\276\202\337", 2);
            } else character->SetMotion("\225\340\202\253", 0);
            character->SetPosition(position);
            character->SetRotation(rotation);
            break;
        }
        case EDIT_DOOR_STEP_WAIT:
            if (character->CheckMotionEnd() || count >= 301 || !scene->CheckDrawChara(scene->player_chara)) result = EDIT_EVENT_RESULT_END;
            break;
        }
    } else if (type == EDIT_EVENT_TYPE_TREASURE_BOX) {
        CMapTreasureBox *box = map->GetTrBox(data.chara_slot);
        mgCFrame *lid = box != NULL && box->CObjectFrame::frame != NULL ? box->CObjectFrame::frame->SearchFrame("top") : NULL;
        if (lid == NULL) { step = EDIT_TREASURE_BOX_STEP_DELETE; result = EDIT_EVENT_RESULT_END; }
        else switch (step) {
        case EDIT_TREASURE_BOX_STEP_START:
            character->SetMotion("\227\247\202\277", 0);
            count = 0;
            if (CheckGetItemLimmitOver(box->item_no, box->item_num) < box->item_num) {
                message->Preset(4);
                message->SetWindowMode(4);
                message->MakeMesWin(0xC);
                step = EDIT_TREASURE_BOX_STEP_FULL_MESSAGE;
            } else {
                step = EDIT_TREASURE_BOX_STEP_OPEN;
                lid->SetRotation(0.0f, 0.0f, 0.0f);
                sndSePlay(scene->se_base_id, 0x3C, 0);
            }
            break;
        case EDIT_TREASURE_BOX_STEP_OPEN:
            if (++count >= 3) step = EDIT_TREASURE_BOX_STEP_LIFT;
            break;
        case EDIT_TREASURE_BOX_STEP_LIFT: {
            float rotation[4];
            lid->GetRotation(rotation);
            rotation[0] -= 0.05f;
            lid->SetRotation(rotation);
            if (rotation[0] < -1.0f) {
                step = EDIT_TREASURE_BOX_STEP_WAIT;
                box->active = 0;
                message->Preset(4);
                message->SetWindowMode(4);
                message->MakeMesWin(box->item_num < 2 ? 0xA : 0xB);
                sndSePlay(GetSystemSndID(), 0x12, 0);
                save->GetItem(box->item_no, box->item_num);
            }
            count = 0;
            break;
        }
        case EDIT_TREASURE_BOX_STEP_WAIT:
            if (++count >= 0x15) step = EDIT_TREASURE_BOX_STEP_MESSAGE;
            break;
        case EDIT_TREASURE_BOX_STEP_MESSAGE:
        case EDIT_TREASURE_BOX_STEP_FULL_MESSAGE:
            if (PadCtrl.Btn(0) || PadCtrl.Btn(1)) {
                message->Preset(0);
                sndSePlay(GetSystemSndID(), 0x19, 0);
                ++step;
            }
            break;
        case EDIT_TREASURE_BOX_STEP_DELETE:
            map->DeleteTrBox(data.chara_slot, map_flags);
            result = EDIT_EVENT_RESULT_END;
            break;
        case EDIT_TREASURE_BOX_STEP_END:
            result = EDIT_EVENT_RESULT_END;
            break;
        }
    } else if (type == EDIT_EVENT_TYPE_BOOK) {
        switch (step) {
        case EDIT_BOOK_STEP_START:
            character->SetMotion("\227\247\202\277", 0);
            message->Preset(4);
            message->SetWindowMode(4);
            BookshelfMessageMake(message, data.event.unk_2c, data.event.unk_30, data.event.unk_34);
            step = EDIT_BOOK_STEP_READ;
            count = 0x1E;
            break;
        case EDIT_BOOK_STEP_READ:
            if (message->State() == 0) step = EDIT_BOOK_STEP_DONE;
            else if (PadCtrl.Btn(0) || PadCtrl.Btn(1)) {
                if (message->State() == 5) message->GoNextPage();
                else if (message->State() == 3) { step = EDIT_BOOK_STEP_DONE; count = 5; }
                sndSePlay(GetSystemSndID(), 0x19, 0);
            }
            if (--count < 0) step = EDIT_BOOK_STEP_CLOSE;
            break;
        case EDIT_BOOK_STEP_DONE:
            step = EDIT_BOOK_STEP_CLOSE;
            break;
        case EDIT_BOOK_STEP_CLOSE:
            message->Preset(0);
            result = EDIT_EVENT_RESULT_END;
            break;
        }
    } else result = EDIT_EVENT_RESULT_END;
    if (result != EDIT_EVENT_RESULT_CONTINUE && result != EDIT_EVENT_RESULT_MENU) state = EDIT_EVENT_STATE_END;
    return result;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", Step__10CEditEventFP6CScene);
#endif
#ifdef NONMATCHING
int CEditEvent::Draw(CScene *scene) { return 0; }
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", Draw__10CEditEventFP6CScene);
#endif
#ifdef NONMATCHING
int GeoramaFunc(GeoFuncParam *param, RS_STACKDATA *args, int argc) {
    switch (rsGetStackInt(args)) {
    case GEORAMA_FUNC_LOAD_INT_NPC: return LoadIntNPC(param, args + 1, argc - 1);
    case GEORAMA_FUNC_LOAD_GEO_NPC: return LoadGeoNPC(param, 0);
    case GEORAMA_FUNC_CHECK_PLACE_BURN: return CheckPlaceBurnParts(param, args + 1, argc - 1);
    case GEORAMA_FUNC_TEST: printf("georama test function\n"); return 0;
    default: return 1;
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", GeoramaFunc__FP12GeoFuncParamP12RS_STACKDATAi);
#endif
static int CheckPlaceBurnParts(GeoFuncParam *param, RS_STACKDATA *args, int argc) {
    if (argc != 1) return 0;
    rsSetStack(args, 0);
    if (param->scene == NULL) return 0;
    CEditMap *map = (CEditMap *)param->scene->GetMap(param->scene->active_map);
    if (map == NULL) return 0;
    rsSetStack(args, map->PlaceBurnParts());
    return 1;
}
#ifdef NONMATCHING
static int LoadIntNPC(GeoFuncParam *param, RS_STACKDATA *args, int argc) {
    CScene *scene = param->scene;
    int villager = scene->event_data.unk_cc;
    char model_name[64];
    if (!GetVillagerModelName(villager, model_name)) return 1;
    if (!LoadFile2(model_name, scene->read_buff, NULL, 0)) return 0;
    scene->AssignStack(4);
    mgCMemory *stack = scene->GetStack(4);
    if (stack->stGetRest() < 0xC800) {
        printf("geo int chara memory over!!\n");
        return 0;
    }
    int slot = rsGetStackInt(args);
    int tex_block = scene->GetCharaTexb(slot);
    mgTexManager.DeleteBlock(tex_block);
    scene->LoadChara(slot, (unsigned int *)scene->read_buff, "info.cfg", stack, stack, stack, tex_block, 0);
    CCharacter2 *character = scene->GetCharacter(slot);
    if (character == NULL) return 0;
    CMap *map = scene->GetMap(scene->active_map);
    if (map != NULL) {
        CFuncPoint *point = map->func_point.Search("npc_pos");
        if (point != NULL) {
            sceVu0FVECTOR rotation = {0.0f, 0.0f, 0.0f, 1.0f};
            character->SetPosition(point->position);
            character->SetRotation(rotation);
        }
    }
    scene->SetCharaNo(slot, villager);
    scene->RegisterVillager(slot, villager, stack);
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", LoadIntNPC__FP12GeoFuncParamP12RS_STACKDATAi);
#endif
#ifdef NONMATCHING
static int LoadGeoNPC(GeoFuncParam *param, int check_only) {
    CScene *scene = param->scene;
    if (scene->GetMainMapNo() != 1) return 0;
    CEditMap *map = (CEditMap *)scene->GetMap(scene->active_map);
    if (map == NULL) return 0;
    if (!check_only) scene->DeleteVillager();
    int part_no;
    if (map->GetePlacePartsAtInfoID(0x49, &part_no, 1) <= 0) return 0;
    CEditParts *parts = map->GetePlaceParts(part_no);
    if (parts == NULL) return 0;
    int villager = parts->GetLiveNPC();
    char model_name[64];
    if (!GetVillagerModelName(villager, model_name)) return 1;
    if (check_only) return 1;
    if (!LoadFile2(model_name, scene->read_buff, NULL, 0)) return 0;
    scene->AssignStack(2);
    mgCMemory *stack = scene->GetStack(2);
    int tex_block = scene->GetCharaTexb(8);
    mgTexManager.DeleteBlock(tex_block);
    scene->LoadChara(8, (unsigned int *)scene->read_buff, "info.cfg", stack, stack, stack, tex_block, 0);
    CCharacter2 *character = scene->GetCharacter(8);
    if (character == NULL) return 0;
    CFuncPoint *point = parts->func_point_mngr.Search("npc_pos");
    if (point != NULL) {
        sceVu0FMATRIX matrix;
        sceVu0FVECTOR position;
        sceVu0FVECTOR rotation;
        parts->GetLWMatrix(matrix);
        memcpy(position, point->position, sizeof(position));
        position[3] = 1.0f;
        sceVu0ApplyMatrix(position, matrix, position);
        parts->GetRotation(rotation);
        rotation[1] = mgAngleLimit(rotation[1] + point->rotation[1]);
        rotation[0] = rotation[2] = 0.0f;
        character->SetPosition(position);
        character->SetRotation(rotation);
        scene->SetActive(1, 8);
    }
    scene->SetCharaNo(8, villager);
    return scene->RegisterVillager(8, villager, stack);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", LoadGeoNPC__FP12GeoFuncParami);
#endif
#ifdef NONMATCHING
void GeoUpdateNpcPos(CScene *scene) {
    if (scene->GetMainMapNo() != 1) return;
    CEditMap *map = (CEditMap *)scene->GetMap(scene->active_map);
    int part_no;
    if (map == NULL || map->GetePlacePartsAtInfoID(0x49, &part_no, 1) <= 0) return;
    CEditParts *parts = map->GetePlaceParts(part_no);
    if (parts == NULL) return;
    int slot = scene->SearchCharaID(parts->GetLiveNPC());
    CCharacter2 *character = scene->GetCharacter(slot);
    CFuncPoint *point = parts->func_point_mngr.Search("npc_pos");
    if (character == NULL || point == NULL) return;
    scene->StayVillager(slot);
    sceVu0FMATRIX matrix;
    sceVu0FVECTOR position;
    sceVu0FVECTOR rotation;
    parts->GetLWMatrix(matrix);
    memcpy(position, point->position, sizeof(position));
    position[3] = 1.0f;
    sceVu0ApplyMatrix(position, matrix, position);
    parts->GetRotation(rotation);
    rotation[1] = mgAngleLimit(rotation[1] + point->rotation[1]);
    rotation[0] = rotation[2] = 0.0f;
    character->SetPosition(position);
    character->SetRotation(rotation);
    scene->CancelStayVillager(slot);
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/editevent", GeoUpdateNpcPos__FP6CScene);
#endif

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_920__4__DATA);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_888__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_916__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_917__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_918__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_919__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1133__5__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1134__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1135__4__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1136__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1137__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1138__3__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1139__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1154__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1152__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1175__2__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1209__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1210__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", at_1211__2__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/editevent", MenuInfo__2__DATA);
