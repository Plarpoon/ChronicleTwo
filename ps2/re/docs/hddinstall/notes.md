# hddinstall: reverse-engineering notes

## Overview
Twelve global functions at 0x320C80..0x320D3F, each 0x10 bytes. Every one is a stub in this
(PAL) build: the HDD installer was compiled out. No classes, no data symbols, no file-local
symbols. No counterpart in the first game's decompilation.

Bodies (all `jr ra` + delay slot, two trailing nops):
- `daddu v0, zero, zero` (return 0): HddConectCheck, CheckAppInstall, CheckInstallSpace,
  MountHDDFileSystem, UmountHDDFileSystem, CreateInstallThread, StepInstallThread,
  InstallPause, UninstallApp.
- nothing in v0 (void): DeleteInstallThread, InstallCancel.
- `mtc1 zero, f0` (return 0.0f): GetInstallProgress.

The source definitions use `int f(...) { return 0; }`, `void f() {}`, and
`float f() { return 0.0f; }`. All twelve functions match retail byte for byte.

## Signatures and evidence
- `u_long128 *` mangles as `P1` under this MWCC (verified by compiling `int A(u_long128*)`
  -> `A__FP1`, `int B(u_long128*, int)` -> `B__FP1i`). So `CreateInstallThread__FP1i` is
  `(u_long128 *work, int work_size)`; the build/re demangle "(i*)" is wrong.
  Callers: TitleHDDInstallKey passes HDDINFO.work (+0x20) and `0x70000` (matches the
  `Alloc(0x70000)` in TitleHDDInstallInit); HDDMenuLoop passes `inst_work` and `0xA0000`
  (a1 is set in the jal delay slot, which Ghidra drops). Return: non-zero = started
  (HDDMenuLoop sets now_install = 1; title sets HDDINFO.installing).
- `HddConectCheck(int *state)`: called with NULL (CheckHDDInstall, InitHDDMenu, HDDMenuLoop)
  or `&HDDINFO.hdd_state` (title). Result tested `> 0`. Title compares hdd_state with 1 and 3
  (meaning not established; no enum declared).
- `CheckAppInstall()`: tested `> 0` / `== 0`; title notes record -1000/-1001 for
  app_install selecting message 0x6B (could come from this or CheckAppInstallForTitle).
- `CheckInstallSpace()`: tested `> 0`.
- `MountHDDFileSystem()`: ChangeHddFile (dataread) requires `> 0` before switching
  DefaultFileDev to FILE_DEV_HDD. `UmountHDDFileSystem()`: ChangeDefaultFile ignores the
  result; declared int because the stub sets v0.
- `StepInstallThread()`: `< 1` means finished; the value is stored as the result/error code
  (HDDINFO.result, error_code). Title phase 5 treats result 0 as success. 2-valued checks in
  TitleHDDInstallKey phase 6 are on YesNoCursor2, not on this.
- `InstallPause()`: used as a toggle. Title calls it entering the cancel question, again
  when the answer is "no" (resume), and before InstallCancel when "yes"; HDDMenuLoop calls
  it on pad button 0x10. Result unused.
- `InstallCancel()`: HDDMenuLoop on button 0x40; title after InstallPause. Then
  StepInstallThread is polled until `< 1`, then DeleteInstallThread.
- `GetInstallProgress()`: float, converted with fptosi; title divides by 10 to pick one of
  ten images, so 0..100 percent.
- `UninstallApp()`: result stored to HDDMenuLoop's error_code.

## Unresolved
- No enums declared: result/error codes and hdd_state values only appear as literals
  (1, 3, -1000, -1001) at call sites outside this unit; their meaning is not shown here.
