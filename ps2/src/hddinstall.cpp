#include "common.h"

// Code (.text)
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", HddConectCheck__FPi);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", CheckAppInstall__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", CheckInstallSpace__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", MountHDDFileSystem__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", UmountHDDFileSystem__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", CreateInstallThread__FP1i);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", DeleteInstallThread__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", StepInstallThread__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", InstallPause__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", InstallCancel__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", GetInstallProgress__Fv);
INCLUDE_ASM("ps2/asm/pal/nonmatchings/hddinstall", UninstallApp__Fv);
