#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", search_txt__Fc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", ConvLongToTxt__FUlPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", ConvTxtToLong__FPcPUl);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", ConvertBinToTxt__FPUciPc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", ConvertTxtToBin__FPcPUc);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", GetCRC__FPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", random__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", EncodeBinData__FPUciPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", DecodeBinData__FPUciPUci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", EncodePassword__FPUciPUciPci);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/password", DecodePassword__FPcPUciPUci);

// Initialised data (.data)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/password", txt_table__2);

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/password", at_211);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/password", random_seed);
