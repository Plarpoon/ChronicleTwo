#include "common.h"
#include "scriptinterpreter.hpp"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetLine__9input_strFPciPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", get__9input_strFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", spiGetStackInt__FP9SPI_STACK);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", spiGetStackFloat__FP9SPI_STACK);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", spiGetStackString__FP9SPI_STACK);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", spiGetStackVector__FPfP9SPI_STACK);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", PushStack__18CScriptInterpreterF9SPI_STACK);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", __as__9SPI_STACKFRC9SPI_STACK);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetNextTAG__18CScriptInterpreterFi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetStack__18CScriptInterpreterFP9SPI_STACKi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetStringBuff__18CScriptInterpreterFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", Run__18CScriptInterpreterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", hash__18CScriptInterpreterFPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetTag__18CScriptInterpreterFP13SPI_TAG_PARAM);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetScript__18CScriptInterpreterFPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", __ct__18CScriptInterpreterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", __ct__9input_strFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetArgBin__18CScriptInterpreterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetArg__18CScriptInterpreterFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", back__9input_strFv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SearchCommand__18CScriptInterpreterFPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SkipSpace__FR9input_str);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", CheckChar__Fc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", PreProcess__FR9input_str);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_215__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_382__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_524__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_165__DATA);
