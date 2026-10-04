#include "common.h"
#include "menusystemdata.hpp"
#include <cstring>

// Code (.text)
CMenuSystemData::CMenuSystemData() {
    MenuSystemDataInit();
}

void CMenuSystemData::MenuSystemDataInit() {
    memset(this, 0, 4);
}

int CMenuSystemData::CheckGetAlready(int item_no) {
    for (int i = 0; i < MENU_SYSTEM_GHOBI_NUM; i++) {
        if (ghobi[i].item_no == item_no) {
            return 1;
        }
    }
    return 0;
}

#ifdef NONMATCHING
void CMenuSystemData::GetGhobi(int item_no) {
    for (int i = 0; i < MENU_SYSTEM_GHOBI_NUM; i++) {
        if (ghobi[i].item_no <= 0) {
            ghobi[i].item_no = item_no;
            return;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/menusystemdata", GetGhobi__15CMenuSystemDataFi);
#endif
