#include "common.h"
#include "charaviewlp.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charaviewlp", InitCharaViewerMain__F13INIT_LOOP_ARG);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charaviewlp", FinishCharaVieweMain__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/charaviewlp", LoopCharaViewerMain__Fv);
