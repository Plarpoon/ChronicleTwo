# Translation units of the main executable (PAL, SCES_511.90)

How `ps2/config/pal/main.yaml` divides `.text` (0x100000-0x325C80) into translation units, and what each boundary rests on.

## Evidence available in the binary

- The ELF keeps its symbol table and relocations (`.relmain`). Relocation offsets are virtual addresses.
- Every GCC-compiled library object has its own `.text`/`.data`/`.rodata`/`.bss` SECTION symbol, so library object boundaries are exact.
- MWCC local symbols (static functions, `@N` constants, `name$N` function statics) are grouped per unit in the symbol table, and units appear in link order. A cut between two units is only possible where every section's local address ranges are disjoint and ascending.
- 49 units have a `__sinit_<file>.cpp` function, which gives the source file name. These functions live in `.rdata` (0x379680-0x37AFE0), followed by the `__static_init` pointer table (0x37AFE0-0x37B0A4) and the vtables (0x37B0B0-0x37C6F0).
- `@N` numbers rise with address within a unit; a large drop marks a new unit.
- A function that references a local symbol is in the unit that owns that local.
- Vtables are laid out in unit order, and in reverse class order within a unit.
- Vague-linkage (binding 13) inline bodies are emitted inside the unit that used them, not in a unit of their own.
- Data in `.data`, `.rodata`, `.sdata`, `.sbss`, `.bss`, the sinit area and the vtables follows the same unit order as `.text`.
- `.mwcats` holds one record per MWCC-compiled function (`u8 kind, u8 flags, u16 size, u32 address`, plus a `u32` when `flags & 1`); it carries no unit boundaries.
- The compiler is MW MIPS C Compiler 2.4.1.01 (`.comment`).

## Section map

| Section | Start | End |
|---|---|---|
| .text | 0x00100000 | 0x00325C80 |
| .vutext | 0x00325C80 | 0x0032A320 |
| .data | 0x0032A320 | 0x00363480 |
| .vudata | 0x00363480 | 0x00363580 |
| .rodata | 0x00363580 | 0x00379680 |
| .init (`__sinit_*` code, 16-byte aligned) | 0x00379680 | 0x0037AFE0 |
| .ctor (`__static_init` table) | 0x0037AFE0 | 0x0037B0B0 |
| .vtables | 0x0037B0B0 | 0x0037C6F0 |
| overlay table word, padding | 0x0037C6F0 | 0x0037C700 |
| .sdata | 0x0037C700 | 0x0037CD80 |
| .sbss | 0x0037CD80 | 0x0037EAD5 |
| .bss | 0x0037EAD5 | 0x01F64A00 |

File offset = address - 0xFFF80. `_gp` = 0x3846F0.

## Units

Name source: `sinit` = `__sinit_<name>.cpp` symbol; `dc1` = the first game's name for the same code; `invented` = named for its contents.

| Start | End | Unit | Name source | Confidence | Evidence |
|---|---|---|---|---|---|
| 0x100000 | 0x1000D0 | crt0 | dc1 | high | asm crt0; .text SECTION idx2 size 0xc8 (_start/ENTRYPOINT 0x100008,_exit 0x1000b8,_root 0x1000c0); 8 bytes pad to 0x1000d0 |
| 0x1000D0 | 0x100190 | lib/mwcc/fpcmp | invented | low | _dpfne.._dpfge wrappers calling libgcc dpcmp; no locals; DC1 had _dpf* glued after crt0 and mwInit elsewhere (separate obj) |
| 0x100190 | 0x1001C0 | lib/mwcc/mwinit | invented | low | mwInit only (calls __initialize_cpp_rts); DC1 had mwInit with mwOverlayInit/mwBload/mwLoadOverlay (stripped here) |
| 0x1001C0 | 0x1004F0 | lib/mwcc/CPlusLib | invented | low | __construct_array,__construct_new_array,__dl__FPv + vague exception dtor/what; symtab run 5-7 (@196,@204,own __RTTI exception local) rodata 0x363580-0x3635a2; start vs mwInit unproven |
| 0x1004F0 | 0x1005D0 | lib/mwcc/New | invented | med | default_new_handler(L)+vague bad_alloc dtor/what; symtab run 8-15 (@34..@47, 2nd local __RTTI exception); owns .data _new_handler_func/__throws_bad_alloc |
| 0x1005D0 | 0x1009A0 | lib/mwcc/NMWException | invented | low | __nw__FUi(@47 dup of New TU @47 => different TU),__throw_catch_compare,unexpected,terminate,duhandler(L),dthandler(L); run 16-20 incl thandler/uhandler .data; __nw__FUi may be its own TU |
| 0x1009A0 | 0x100A30 | lib/mwcc/global_destructor_chain | invented | low | __register_global_object (bss __global_destructor_chain 0x37ec48) + __initialize_cpp_rts (no locals; grouping guessed) |
| 0x100A30 | 0x102190 | lib/mwcc/MWException | invented | med | __Decode*Number,__end__catch,__ThrowHandler(refs locals FindExceptionHandler etc),__unexpected,..,NextAction,FindExceptionRecord, vague bad_exception dtor/what; run 21-37, @408..@1073 monotone rodata 0x363660-0x363806; start (Decode/__end__catch vs global_destructor) unproven |
| 0x102190 | 0x102630 | lib/mwcc/ExceptionPS2 | invented | low | __TransferControl,__throw,__SkipUnwindInfo,__FindExceptionTable,__SetupFrameInfo,__PopStackFrame: platform-specific frame helpers, no locals; split from MWException because vague what__bad_exception (0x102180) ends that TU |
| 0x102630 | 0x104288 | lib/sce/libgraph | dc1 | high | 17 GCC obj(s) (.text secsym boundaries); funcs: sceGsResetGraph sceGsGetGParam sceGsResetPath sceGsSetDefDispEnv sceGsPutDispEnv sceGszbufaddr ...(+12) |
| 0x104288 | 0x104D58 | lib/sce/libdma | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: memclr(L) sceDmaGetChan sceDmaReset sceDmaDebug sceDmaPutEnv sceDmaGetEnv ...(+11) |
| 0x104D58 | 0x106630 | lib/sce/libdev | invented | med | SCE libdev (sceDevCons*/sceDevFont*, chaMem*) - not in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: sceDevFontDefault(L) sceDevFontIdle(L) sceDevFontSetColor(L) sceDevConsInit sceDevConsOpen sceDevConsClose ...(+27) |
| 0x106630 | 0x106958 | lib/sce/pkt/libgifpk | dc1 | high | 11 GCC obj(s) (.text secsym boundaries); funcs: sceGifPkInit sceGifPkReset sceGifPkTerminate sceGifPkCnt sceGifPkRef sceGifPkEnd ...(+5) |
| 0x106958 | 0x106D00 | lib/sce/pkt/libvifpk | dc1 | high | 13 GCC obj(s) (.text secsym boundaries); funcs: sceVif1PkInit sceVif1PkReset sceVif1PkTerminate sceVif1PkCnt sceVif1PkCall sceVif1PkEnd ...(+7) |
| 0x106D00 | 0x107A50 | lib/sce/libvu0 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceVu0ApplyMatrix sceVu0MulMatrix sceVu0OuterProduct sceVu0InnerProduct sceVu0Normalize sceVu0TransposeMatrix ...(+36) |
| 0x107A50 | 0x10F4E0 | lib/sce/libmpeg | invented | med | SCE libmpeg (sceMpeg*, _ipuVdec/_doCSC/_sysbit/demux internals, _defStopDMA used by sceMpegCreate) - not in DC1; 7 GCC obj(s) (.text secsym boundaries); funcs: _motionComp0(L) _getAllRefs _getRef0 _doMC(L) _rix_000 _ri0_000 ...(+135) |
| 0x10F4E0 | 0x10FB00 | lib/sce/libipu | invented | med | SCE libipu (sceIpuStopDMA/RestartDMA/Sync, sceIpuInit + iqval/vqval/__ps2_libinfo__) - not in DC1; 2 GCC obj(s) (.text secsym boundaries); funcs: setD3_CHCR(L) setD4_CHCR(L) sceIpuStopDMA sceIpuRestartDMA sceIpuSync setD4_CHCR(L) ...(+1) |
| 0x10FB00 | 0x1103A0 | lib/sce/kernl/klib | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: RFU000_FullReset ResetEE SetGsCrt RFU003 _Exit RFU005 ...(+132) |
| 0x1103A0 | 0x110770 | lib/sce/kernl/glue | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceResetttyinit VSync VSync2 write read open ...(+10) |
| 0x110770 | 0x1109F0 | lib/sce/kernl/cache | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _sceSDC SyncDCache iSyncDCache _sceIDC InvalidDCache iInvalidDCache |
| 0x1109F0 | 0x110D60 | lib/sce/kernl/intr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: QueryIntrContext DisableIntc EnableIntc DisableDmac EnableDmac iEnableIntc ...(+8) |
| 0x110D60 | 0x1110C0 | lib/sce/kernl/thread | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: topThread(L) InitThread iWakeupThread iRotateThreadReadyQueue iSuspendThread |
| 0x1110C0 | 0x1112A0 | lib/sce/kernl/deci2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceDeci2Open sceDeci2Close sceDeci2ReqSend sceDeci2Poll sceDeci2ExRecv sceDeci2ExSend ...(+4) |
| 0x1112A0 | 0x1117C0 | lib/sce/kernl/tty | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: QueueInit(L) QueuePeekWriteDone(L) QueuePeekReadDone(L) sceTtyHandler(L) sceTtyWrite sceTtyRead ...(+1) |
| 0x1117C0 | 0x112138 | lib/sce/kernl/kprintf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: kputchar(L) deci2Putchar(L) serialPutchar(L) ftoi(L) printfloat(L) _printf ...(+2) |
| 0x112138 | 0x112880 | lib/sce/kernl/sifcmd | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _set_sreg(L) _change_addr(L) sceSifGetSreg sceSifSetSreg sceSifGetDataTable sceSifInitCmd ...(+10) |
| 0x112880 | 0x1137E0 | lib/sce/kernl/sifrpc | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceSifInitRpc sceSifExitRpc _sceRpcGetPacket(L) _sceRpcFreePacket(L) _sceRpcGetFPacket(L) _sceRpcGetFPacket2(L) ...(+16) |
| 0x1137E0 | 0x116E78 | lib/sce/kernl/filestub | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _sceFsIobSemaMK(L) new_iob(L) get_iob(L) _sceFs_Rcv_Intr(L) _sceFsSemInit(L) _sceFsWaitS(L) ...(+34) |
| 0x116E78 | 0x117178 | lib/sce/kernl/iopheap | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceSifInitIopHeap sceSifAllocIopHeap sceSifAllocSysMemory sceSifFreeSysMemory sceSifFreeIopHeap sceSifLoadIopHeap |
| 0x117178 | 0x117ED8 | lib/sce/kernl/eeloadfile | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _lf_bind(L) _lf_version(L) sceSifLoadFileReset _sceSifLoadModuleBuffer(L) sceSifStopModule sceSifUnloadModule ...(+12) |
| 0x117ED8 | 0x118188 | lib/sce/kernl/iopreset | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceSifResetIop sceSifIsAliveIop sceSifSyncIop sceSifRebootIop |
| 0x118188 | 0x1186C0 | lib/sce/kernl/tlbfunc | invented | med | libkernl obj (SetTLBHandler..InitTLB32MB, data tlbsrc/kernelTLB/defaultTLB); SCE/ps2sdk-style file name, not in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: SetTLBHandler SetDebugHandler Copy(L) kCopy(L) GetEntryAddress(L) setup(L) ...(+13) |
| 0x1186C0 | 0x118A20 | lib/sce/kernl/tlbtrap | invented | low | libkernl asm obj (_kTLBException/_kExitTLBHandler/_kDebugException, bss hstack/EER*); name guessed; 1 GCC obj(s) (.text secsym boundaries); funcs: _kTLBException _kExitTLBHandler _kDebugException |
| 0x118A20 | 0x118A80 | lib/sce/kernl/diei | invented | low | libkernl obj DIntr/EIntr; name guessed; 1 GCC obj(s) (.text secsym boundaries); funcs: DIntr EIntr |
| 0x118A80 | 0x118BC0 | lib/sce/kernl/initsys | invented | low | libkernl obj _InitSys/_setup/supplement_crt0(L); name guessed; 1 GCC obj(s) (.text secsym boundaries); funcs: supplement_crt0(L) kFindAddress(L) FindAddress(L) GetSystemCallTableEntry(L) setup(L) _setup ...(+1) |
| 0x118BC0 | 0x118D40 | lib/sce/kernl/libosd | invented | low | libkernl obj InitExecPS2/PatchIsNeeded(L), data osdsrc/SysExecPS2Entry; name guessed; 1 GCC obj(s) (.text secsym boundaries); funcs: setup(L) Copy(L) kCopy(L) GetEntryAddress(L) PatchIsNeeded(L) InitExecPS2 |
| 0x118D40 | 0x118E50 | lib/sce/kernl/exit | invented | low | libkernl obj TerminateLibrary(L)/ExecPS2/LoadExecPS2/Exit/ExecOSD wrappers (klib has _Exit/_ExecPS2 stubs); name guessed; 1 GCC obj(s) (.text secsym boundaries); funcs: TerminateLibrary(L) ExecPS2 LoadExecPS2 Exit ExecOSD |
| 0x118E50 | 0x119180 | lib/sce/sdr_main | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceSdRemoteInit sceSdTransToIOP sceSdCallBack sceSdRemote |
| 0x119180 | 0x1194B8 | lib/libm/math/e_atan2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_atan2 |
| 0x1194B8 | 0x11A1E0 | lib/libm/math/e_pow | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_pow |
| 0x11A1E0 | 0x11A700 | lib/libm/math/e_rem_pio2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_rem_pio2 |
| 0x11A700 | 0x11AA08 | lib/libm/math/e_sqrt | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_sqrt |
| 0x11AA08 | 0x11AE38 | lib/libm/math/ef_acos | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_acosf |
| 0x11AE38 | 0x11B120 | lib/libm/math/ef_atan2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_atan2f |
| 0x11B120 | 0x11B500 | lib/libm/math/ef_rem_pio2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_rem_pio2f |
| 0x11B500 | 0x11B638 | lib/libm/math/ef_sqrt | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __ieee754_sqrtf |
| 0x11B638 | 0x11B888 | lib/libm/math/k_cos | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_cos |
| 0x11B888 | 0x11C3F0 | lib/libm/math/k_rem_pio2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_rem_pio2 |
| 0x11C3F0 | 0x11C5C8 | lib/libm/math/k_sin | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_sin |
| 0x11C5C8 | 0x11C720 | lib/libm/math/kf_cos | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_cosf |
| 0x11C720 | 0x11D070 | lib/libm/math/kf_rem_pio2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_rem_pio2f |
| 0x11D070 | 0x11D178 | lib/libm/math/kf_sin | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_sinf |
| 0x11D178 | 0x11D410 | lib/libm/math/kf_tan | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __kernel_tanf |
| 0x11D410 | 0x11D820 | lib/libm/math/s_atan | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: atan |
| 0x11D820 | 0x11D868 | lib/libm/common/s_copysign | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: copysign |
| 0x11D868 | 0x11D970 | lib/libm/math/s_cos | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: cos |
| 0x11D970 | 0x11D9A8 | lib/libm/math/s_fabs | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: fabs |
| 0x11D9A8 | 0x11D9C8 | lib/libm/common/s_finite | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: finite |
| 0x11D9C8 | 0x11DBA0 | lib/libm/math/s_floor | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: floor |
| 0x11DBA0 | 0x11DBE8 | lib/libm/math/s_isinf | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: isinf |
| 0x11DBE8 | 0x11DC20 | lib/libm/math/s_isnan | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: isnan |
| 0x11DC20 | 0x11DC48 | lib/libm/common/s_matherr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: matherr |
| 0x11DC48 | 0x11DE48 | lib/libm/common/s_rint | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: rint |
| 0x11DE48 | 0x11E000 | lib/libm/common/s_scalbn | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: scalbn |
| 0x11E000 | 0x11E0F8 | lib/libm/math/s_sin | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sin |
| 0x11E0F8 | 0x11E3A0 | lib/libm/math/sf_atan | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: atanf |
| 0x11E3A0 | 0x11E3D0 | lib/libm/common/sf_copysign | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: copysignf |
| 0x11E3D0 | 0x11E4B8 | lib/libm/math/sf_cos | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: cosf |
| 0x11E4B8 | 0x11E4D8 | lib/libm/math/sf_fabs | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: fabsf |
| 0x11E4D8 | 0x11E5C0 | lib/libm/math/sf_floor | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: floorf |
| 0x11E5C0 | 0x11E5E8 | lib/libm/math/sf_isnan | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: isnanf |
| 0x11E5E8 | 0x11E748 | lib/libm/common/sf_scalbn | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: scalbnf |
| 0x11E748 | 0x11E838 | lib/libm/math/sf_sin | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sinf |
| 0x11E838 | 0x11E8C0 | lib/libm/math/sf_tan | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: tanf |
| 0x11E8C0 | 0x11E9D8 | lib/libm/math/w_atan2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: atan2 |
| 0x11E9D8 | 0x11EE08 | lib/libm/math/w_pow | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: pow |
| 0x11EE08 | 0x11EF18 | lib/libm/math/w_sqrt | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sqrt |
| 0x11EF18 | 0x11F018 | lib/libm/math/wf_acos | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: acosf |
| 0x11F018 | 0x11F140 | lib/libm/math/wf_atan2 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: atan2f |
| 0x11F140 | 0x11F258 | lib/libm/math/wf_sqrt | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sqrtf |
| 0x11F258 | 0x120E50 | lib/sce/eecdvd | dc1 | high | 6 GCC obj(s) (.text secsym boundaries); funcs: CB_DelayTh(L) sceCdDelayThread sceCdCallback _sceCd_cd_callback _Cdvd_cbLoop sceCdInitEeCB ...(+29) |
| 0x120E50 | 0x1221E8 | lib/sce/libpad | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _send_to_iop(L) scePadInit scePadInit2(L) scePadEnd scePadPortOpen scePadPortClose ...(+24) |
| 0x1221E8 | 0x123A50 | lib/sce/libmc | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceMcInit sceMcEnd _lmcGetClientPtr sceMcChangeThreadPriority sceMcGetSlotMax sceMcOpen ...(+22) |
| 0x123A50 | 0x123CE8 | lib/sce/msinput | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: sceMSIn_Init sceMSIn_ATick sceMSIn_Load put_message(L) sceMSIn_PutMsg sceMSIn_PutExcMsg ...(+1) |
| 0x123CE8 | 0x123D08 | lib/libc/stdlib/abort | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: abort |
| 0x123D08 | 0x123D20 | lib/libc/stdlib/abs | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: abs |
| 0x123D20 | 0x123D40 | lib/libc/stdlib/atof | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: atof |
| 0x123D40 | 0x123D68 | lib/libc/stdlib/atoi | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: atoi |
| 0x123D68 | 0x123E28 | lib/libc/callocr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _calloc_r |
| 0x123E28 | 0x123E80 | lib/libc/reent/closer | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _close_r |
| 0x123E80 | 0x125268 | lib/libc/stdlib/dtoa | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: quorem(L) _dtoa_r |
| 0x125268 | 0x125278 | lib/libc/errno/errno | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __errno |
| 0x125278 | 0x125328 | lib/libc/stdlib/exit | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: exit |
| 0x125328 | 0x125430 | lib/libc/stdio/fflush | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: fflush |
| 0x125430 | 0x125688 | lib/libc/stdio/findfp | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: std(L) __sfmoreglue __sfp _cleanup_r _cleanup __sinit |
| 0x125688 | 0x1256C0 | lib/libc/stdio/fprintf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: fprintf |
| 0x1256C0 | 0x125B50 | lib/libc/freer | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _free_r _malloc_trim_r |
| 0x125B50 | 0x125BB0 | lib/libc/reent/fstatr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _fstat_r |
| 0x125BB0 | 0x125F88 | lib/libc/stdio/fvwrite | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __sfvwrite |
| 0x125F88 | 0x126020 | lib/libc/stdio/fwalk | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _fwalk |
| 0x126020 | 0x126040 | lib/libc/string/index | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: index |
| 0x126040 | 0x126130 | lib/libc/locale/locale | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _setlocale_r _localeconv_r setlocale localeconv |
| 0x126130 | 0x126190 | lib/libc/reent/lseekr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _lseek_r |
| 0x126190 | 0x1262E0 | lib/libc/stdio/makebuf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __smakebuf |
| 0x1262E0 | 0x126318 | lib/libc/stdlib/malloc | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: malloc free |
| 0x126318 | 0x126CE8 | lib/libc/stdlib/mallocr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: malloc_extend_top(L) _malloc_r |
| 0x126CE8 | 0x126D28 | lib/libc/stdlib/mbtowc_r | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _mbtowc_r |
| 0x126D28 | 0x126E08 | lib/libc/machine/r5900/memchr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: memchr |
| 0x126E08 | 0x126EA0 | lib/libc/machine/r5900/memcmp | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: memcmp |
| 0x126EA0 | 0x126F50 | lib/libc/machine/r5900/memcpy | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: memcpy |
| 0x126F50 | 0x127058 | lib/libc/machine/r5900/memmove | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: memmove |
| 0x127058 | 0x127118 | lib/libc/machine/r5900/memset | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: memset |
| 0x127118 | 0x127128 | lib/libc/stdlib/mlock | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __malloc_lock __malloc_unlock |
| 0x127128 | 0x128148 | lib/libc/stdlib/mprec | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _Balloc _Bfree _multadd _s2b _hi0bits _lo0bits ...(+11) |
| 0x128148 | 0x1281D8 | lib/libc/stdio/printf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _printf_r printf |
| 0x1281D8 | 0x128218 | lib/libc/stdlib/rand | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: srand rand |
| 0x128218 | 0x128278 | lib/libc/reent/readr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _read_r |
| 0x128278 | 0x1282D8 | lib/libc/reent/sbrkr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _sbrk_r |
| 0x1282D8 | 0x128628 | lib/libc/signal/signal | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _init_signal_r _signal_r _raise_r __sigtramp_r raise signal ...(+2) |
| 0x128628 | 0x1286A8 | lib/libc/reent/signalr | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _kill_r _getpid_r |
| 0x1286A8 | 0x128780 | lib/libc/stdio/sprintf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _sprintf_r sprintf |
| 0x128780 | 0x1288F0 | lib/libc/stdio/stdio | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __sread __swrite __sseek __sclose |
| 0x1288F0 | 0x1289A8 | lib/libc/string/strcasecmp | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strcasecmp |
| 0x1289A8 | 0x128AD8 | lib/libc/machine/r5900/strcat | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strcat |
| 0x128AD8 | 0x128C68 | lib/libc/machine/r5900/strchr | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: strchr |
| 0x128C68 | 0x128DB0 | lib/libc/machine/r5900/strcmp | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strcmp |
| 0x128DB0 | 0x128EC8 | lib/libc/machine/r5900/strcpy | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strcpy |
| 0x128EC8 | 0x129000 | lib/libc/machine/r5900/strlen | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strlen |
| 0x129000 | 0x1291B0 | lib/libc/machine/r5900/strncat | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: strncat |
| 0x1291B0 | 0x129368 | lib/libc/machine/r5900/strncmp | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strncmp |
| 0x129368 | 0x129528 | lib/libc/machine/r5900/strncpy | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: strncpy |
| 0x129528 | 0x129578 | lib/libc/string/strrchr | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: strrchr |
| 0x129578 | 0x1295E8 | lib/libc/string/strstr | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: strstr |
| 0x1295E8 | 0x12A540 | lib/libc/stdlib/strtod | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _strtod_r strtod strtodf |
| 0x12A540 | 0x12A7B0 | lib/libc/stdlib/strtol | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _strtol_r strtol |
| 0x12A7B0 | 0x12A7D0 | lib/libc/ctype/toupper | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: toupper |
| 0x12A7D0 | 0x12C0F0 | lib/libc/stdio/vfprintf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __sprint(L) __sbprintf(L) vfprintf _vfprintf_r cvt(L) exponent(L) |
| 0x12C0F0 | 0x12C148 | lib/libc/stdio/vsprintf | invented | med | newlib/libgcc source file name for these funcs (dir per DC1 convention), not present in DC1; 1 GCC obj(s) (.text secsym boundaries); funcs: vsprintf |
| 0x12C148 | 0x12C1A8 | lib/libc/reent/writer | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: _write_r |
| 0x12C1A8 | 0x12C2C0 | lib/libc/stdio/wsetup | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __swsetup |
| 0x12C2C0 | 0x12F840 | mg_texture | invented | high | locals run 1214-1232 (GetZBufVram..Conv32To8 statics); mgCTexture/Block/Manager; next fn mgFotI4 starts math. dc1 name: texture |
| 0x12F840 | 0x131790 | mg_math | invented | med | locals sin_table_num/SinTable/Check_Point_Poly3/MulMatrix3; mg* vector/matrix free fns. Split from camera only by purpose (dc1 has separate mathutil/camera); no local/@N evidence either way |
| 0x131790 | 0x1321E0 | mg_camera | invented | med | mgCCamera+mgCCameraFollow, no locals. Iam/Suspend/Resume__9mgCCamera vague bodies emitted after CameraFollow => camera and camerafollow are ONE TU; ends after vague block |
| 0x1321E0 | 0x134A20 | mg_dataset | invented | high | locals conv_new_text/htoi/CreateFrameVisual/CopyFrame; mgLoadMDSFile, mgCMDTBuilder; @N bss drop 933->369 at next TU; ends after mgCVisual vague block. dc1 equiv: dataset |
| 0x134A20 | 0x136160 | mg_drawprim | invented | med | mgCDrawPrim+mgCDrawManager; local bss @369 (Vertex fff); @N 369 -> 324 drop into mg_frame. End ambiguous: mgCFrameAttr (136160-136220) could belong here instead of mg_frame |
| 0x136160 | 0x138EE0 | mg_frame | sinit | high | __sinit_mg_frame.cpp; statics QuatToMat/test1/test2/StrCmp; mgCObject, mgCFrame; ends after mgCFrame/mgCObject vague block. Start med (mgCFrameAttr placement) |
| 0x138EE0 | 0x139F20 | mg_drawenv | invented | high | mgCDrawEnv+mgRENDER_INFO; local @184; @N drops 1119->184 (in) and 184->166 (out) |
| 0x139F20 | 0x13A580 | mg_memory | invented | high | MG_ADDRESS_CHECK, operator new, mgCMemory, mgCopyString; locals @166,@238,@288 (two runs merged, monotone) |
| 0x13A580 | 0x13B2E0 | mg_shadow | invented | high | static SetShadowData + mgCShadowMDT; @N bss 353->199 drop at next TU |
| 0x13B2E0 | 0x13C340 | mg_sprite | invented | high | mgC3DSprite+mgCSprite; ends after vague Draw/Iam block; vtables reversed-order consistent |
| 0x13C340 | 0x13EA20 | mg_tanime | sinit | high | __sinit_mg_tanime.cpp; mgCTexAnimeData/mgCTextureAnime + tex* script statics; weak Set__9mgRect<i> first used by TexAnime kept here |
| 0x13EA20 | 0x141850 | mg_visual | invented | high | GetScrPad/SendDMA/mgSetPkTEX0, mgCVisualMDT/FixMDT/Prim/Attr, statics SetData0-7/SetDrawEnv; ends after vague block; @N 873->769 drop at start |
| 0x141850 | 0x1466D0 | mglib | sinit | high | __sinit_mglib.cpp; mgInit/mgBeginFrame/...; ends after vague __ct__9mgCMemory |
| 0x1466D0 | 0x147890 | scriptinterpreter | dc1 | high | input_str::GetLine (@165) + spiGetStack* + CScriptInterpreter + statics SkipSpace/CheckChar/PreProcess; @N 1569->165 drop at start; 5 VU objects follow in link order |
| 0x147890 | 0x148A90 | collision | invented | high | CCollision/CCollisionMDT/CColFrame, statics pre_trance_normal/trance_normal, LoadCollisionFile, CreateCollisionMDT; CCollisionMDT vague virtuals emitted at TU end + vtable order (CColFrame,CCollisionMDT,CCollision reversed) => one TU. dc1 equiv: collisionmdt |
| 0x148A90 | 0x14A650 | dataread | dc1 | med | file I/O (ChangeDir, LoadFileBG, LoadFile2, file cache, statics SearchFile/GetDevType/CDRead); GetPackFile*/DivPathName tail (14a190-14a650) has no locals - placed here because dc1 dataread holds LoadFile2+GetPackFile |
| 0x14A650 | 0x14BD00 | gamepad | dc1 | high | CGamePad + statics pad_button_read/read_pad/AxisCalibration/GamePadStep; @N 845->248 drop at start |
| 0x14BD00 | 0x151910 | gameutil | dc1 | low | statics QuatSlerp/testVUnew/SetKeyFrame, MotionProc*, AnimeData*, then local-less CheckHit*/MoveCheck/CheckWidth*/LinerInterpolation/RollPos/Calc* (dc1 gameutil has same set). End boundary uncertain anywhere in 14df30..151cb0; chose before MySetPrim |
| 0x151910 | 0x15D470 | nd_meswin | sinit | med | __sinit_nd_meswin.cpp; ClsMes; set2DSprite refs @1124; _set2DSprite uses MesAbsDrawOff (sbss 37cf74 just after gameutil sbss). Start (MySetPrim/set2DSpriteEasy/_set2DSprite) low; end high (@N 4637->846 drop) |
| 0x15D470 | 0x15D830 | main | dc1 | med | statics VSyncCallBack/ClearScreen/init + main; own R/SB locals; @N drops in/out. Name dc1/invented (no sinit). 1 VU object follows in link order |
| 0x15D830 | 0x162080 | map | dc1 | high | CMapFlagData + CPartsGroup + CMap; ends after CMap/CObject vague block; @N 2008->438 drop to next |
| 0x162080 | 0x166250 | mapload | invented | med | map time/lighting (GetTimeBand.., GetSunPoint) + map*/cfg* script statics + LoadMapFile/LoadCfgFile; end ambiguous (CCameraInfo/CMapInfo accessors 166250-1664a0 could be here) |
| 0x166250 | 0x167660 | mapinfo | invented | med | CCameraInfo::Initialize, CMapInfo accessors, map* statics (mapIMG..), LoadMapInfo/AddMapInfo/OutputLightData; @N 1544->704 drop at statics; start low-med |
| 0x167660 | 0x169930 | mapparts | dc1 | high | CMapParts, CMapTreasureBox, CCharacter2 vague inlines (one with local @244 in D 338d60, @N low => new TU); vtable order CMapTreasureBox,CList<CObjAnime>,CMapParts precedes CMdsInfo,CMapPiece => CMapPiece is next TU |
| 0x169930 | 0x16AE00 | mdslist | invented | med | CMapPiece, CMdsInfo, CMdsListSet, CMdsList, CIMGList, pcp* statics, LoadPCPFile, static CreateChara; vtable order => separate from mapparts and from object |
| 0x16AE00 | 0x16B550 | object | dc1 | med | CObject + CObjectFrame, no locals; vtable order (CObjectFrame before CObject, reversed) => one TU, after CMapPiece/CMdsInfo TU and before CActionChara TU. dc1 had object+objectframe split |
| 0x16B550 | 0x1741F0 | actionchara | invented | high | CActionChara (+static RockOn_TargetSel etc.); ends after vague __as__11CCharacter2; @N 2210->1395 drop next |
| 0x1741F0 | 0x17ABD0 | character | dc1 | high | CCharacter2 + ScanInfoFile/_CLOTH/_LOD_MODEL statics; ends after vague __as__7CObject; @N 1395->855 drop next |
| 0x17ABD0 | 0x17D680 | dynamicanime | invented | high | CDynamicAnime/CDACollision/CDAColPipe + dyn* statics |
| 0x17D680 | 0x17E280 | outline | invented | high | COutLineDraw + statics DrawDivSprite/DrawDivSprite4; @N 1074->299 drop at start, 399->260 at end |
| 0x17E280 | 0x17F760 | effectlist | invented | med | CEffectList, CEffectManager::CreatePacket (rest of CEffectManager is in 'effect'), CFadeInOut, statics DivSpriteScreen; @N 589->205 drop at end |
| 0x17F760 | 0x1809E0 | screeneffect | invented | low | DepthOfField + LensFlare, each only sbss locals (@205,206 / @283,292 monotone) - may be two TUs |
| 0x1809E0 | 0x1846F0 | effect | dc1 | high | statics UniformityRand/RegularityRand + CEffect/CEffectCtrl/__XXX__ script statics/CEffectManager; @N 848->387 drop next |
| 0x1846F0 | 0x185710 | mapsky | invented | med | CMapSky + LoadSkyPack/_SKY_* statics; end ambiguous (CFireRaster/CThunderEffect::Init 185710-185df0 have no locals) |
| 0x185710 | 0x1874A0 | water | dc1 | med | CWater/CWaterFrame (runs 72,73 merged: vtable order CWaterFrame,CWater reversed => one TU), CreateWaterFrame, ends after vague Initialize__11CWaterFrame; CFireRaster+CThunderEffect::Init at start placed here with low confidence |
| 0x1874A0 | 0x188090 | dbg_font | sinit | high | __sinit_dbg_font.cpp; Sjis statics + dbgCJISFont |
| 0x188090 | 0x189E30 | runscript | dc1 | high | CRunScript VM + error statics + rsGetStackInt/rsSetStack; @N 420->168 in, 699->218 out |
| 0x189E30 | 0x18C770 | sound | dc1 | high | CSound + TransHdBd/set_spu; @N 930->33 drop at end |
| 0x18C770 | 0x18C970 | ezmidi | invented | med | ezMidiInit/ezMidi/ezTransToIOP2 with @33 + own bss (3f64c0-3f6540); very low @N suggests tiny file |
| 0x18C970 | 0x18DA20 | snd_seseq | invented | med | statics BigToLittle/GetDeltaTime + sndCSeSeqData/sndCSeSeq/sndTrack; end ambiguous: CLoopSeMngr (18da20-18df60, no locals) could be here |
| 0x18DA20 | 0x191DF0 | snd_mngr | sinit | high | __sinit_snd_mngr.cpp; snd* API, sndPortInfo, statics GetPortInfo/CSndStep/PlaySeSeq...; ends after vague ctors; start med (CLoopSeMngr placement) |
| 0x191DF0 | 0x195A00 | mainloop | sinit | high | __sinit_mainloop.cpp; Get*/NextLoop/statics InitPadTable, gc* statics; ends after vague __ct__16CUserDataManager/__ct__9CEditData |
| 0x195A00 | 0x197BA0 | gamedata | sinit | high | __sinit_gamedata.cpp; GetGameDataPt + CData* ctors + CGameData + item helpers; @N 2085->1048 drop at start, 1501->482 at end; SetPtr__14CItemUseTarget kept here |
| 0x197BA0 | 0x198100 | sysmes | sinit | med | __sinit_sysmes.cpp; GetSystemMessage/LoadSystemMes/CreateSystemMes; end ambiguous (GetUserDataMan..CalcBreedFishParam 198100-198330 placed in userdata) |
| 0x198100 | 0x1A3460 | userdata | sinit | med | OPEN-END: true end 0x1a3460 (beyond slice end 0x1a0000). __sinit_userdata.cpp; CGameDataUsed, CFishingRecord, CUserDataManager, CBattleCharaInfo, DebugGetItem; @N 5773->251 drop after; start med |
| 0x1A3460 | 0x1A3490 | charaviewlp | invented | low | Init/Finish/LoopCharaViewerMain 8-byte stubs, no locals; may instead be part of userdata or one combined viewer TU with next two |
| 0x1A3490 | 0x1A34C0 | texviewlp | invented | low | Init/Finish/LoopTextuerViewerMain stubs, no locals |
| 0x1A34C0 | 0x1A34F0 | mapviewlp | invented | low | MapViewInit/Exit/Loop stubs, no locals |
| 0x1A34F0 | 0x1A4050 | wavetable | invented | med | CWaveTable only; runs 3215-3218 (@251-303, drop from userdata @5773); __vt__10CWaveTable G 0x37bc38 |
| 0x1A4050 | 0x1A54C0 | editcoll | invented | med | static ClipBoxXZ/OverlapPoly3AreaXZ (locals 3219,3220) + CEditCollision methods; split from wavetable by symtab cut + class |
| 0x1A54C0 | 0x1A8C80 | editctrl | sinit | high | static GetUserData 0x1a54c0 owns run 3221-3297; end med: EditStepChara..EditDrawEffectChara (0x1a8aa0-0x1a8c74, no locals) assigned here by purpose |
| 0x1A8C80 | 0x1AAEF0 | editdebug | invented | med | run 3298-3404 (@989.. drop from editctrl @1767): EditDebug*, LightingEdit, static tagGyoFish/LoadGyorace |
| 0x1AAEF0 | 0x1B16D0 | editloop | sinit | high | static GetUserData 0x1aaef0 .. LoadMap 0x1b16c0 all ref run 3405-3572 |
| 0x1B16D0 | 0x1B6980 | editmap | invented | high | CEditMap::Iam 0x1b16d0 .. LoadEditInfo + vague __ct__14CEditPartsInfo 0x1b6790 (emitted after LoadEditInfo); run 3573-3622 (@346 start). End med |
| 0x1B6980 | 0x1B7400 | editparts | invented | med | CEditPartsInfo methods, CEditHouse::LiveChara, CEditParts, EditPartsCmpColor; locals 3623-3624 (@418, drop from editmap @2278, too low to be same TU as next); start boundary vs editmap med |
| 0x1B7400 | 0x1BB040 | dng_object | invented | med | CRocketLauncher/CMachineGun/CLaserGun/CPullItem(Manager)/CRoboVoiceSystem; run 3625-3758 one TU (@923..1854 monotone) |
| 0x1BB040 | 0x1BBE10 | colprim | invented | med | CColPrim+CColPrimMan, no locals; Damage_Param_Table G data 0x33af10 sits between dng_object data and dng_debug data; could alternatively be tail of dng_object |
| 0x1BBE10 | 0x1BCEC0 | dng_debug | sinit | high | dngGetDebugInfo(dbinfo) .. DrawDebugWindow; runs 3759-3794 (@871-1133). End med: DrawActiveItemCursor statics restart at $1005/@1048 |
| 0x1BCEC0 | 0x1BFA40 | dng_status | invented | med | PrintV, DrawDrumCounter (no locals, only called by status boards), DrawActiveItemCursor..DrawStatusBord; locals 3795-3805 (@1005-1223) |
| 0x1BFA40 | 0x1CA710 | dng_effect | invented | med | static trans_effect_rate 0x1bfa40 (chill_tex_rect$910 drop from @1223) .. CWeaponElement Draw_Thunder (@3214), run 3806-3820 one TU. End low: CreatSmoothPass/unitRotation/iRand/fRand (0x1ca070-0x1ca70c, no locals) placed here |
| 0x1CA710 | 0x1CD130 | dng_hud | invented | low | CLevelupInfo,CPiyori,CGiftMark,CEnemyGekirin(gekirin_anim),CEnemyLifeGage,CDamageScore(@1221 drop from @3214 => new TU by 0x1cbda0),CDamageScore2,CLockOnModel,CWarningGage2 + vague CLockOnModel::Initialize 0x1cd120. Start anywhere in 0x1ca070..0x1cbda0 |
| 0x1CD130 | 0x1D5D60 | dng_main | sinit | high | GetWeaponEffect 0x1cd130 .. DBGCMD_RunScript + vague ctors 0x1d5c80-0x1d5d54; run 3823-4017 |
| 0x1D5D60 | 0x1DAF60 | automap | invented | high | CMiniMapSymbol, CHealingPoint, SPI _ROOM_* statics, CAutoMapGen; run 4018-4336 one TU |
| 0x1DAF60 | 0x1E1AB0 | monster | invented | high | CActiveMonster, CMonsterMan, static Hit*/_MONSTER_NAME, LoadMonsterLanguage; run 4337-4385 (@1200-2809) |
| 0x1E1AB0 | 0x1E9260 | runscript_opcodes | dc1 | high | CMonsterMan::RunScript + RS_STACKDATA opcode statics + SetMonsterScript/ExtendTable; run 4386-4582 (@1480/1728 drop from @2699/2809). DC1 analogue TU runscript_opcodes. End med |
| 0x1E9260 | 0x1E9580 | prespr | invented | low | CPreSprite methods only, no locals; may instead be head of maintex or tail of runscript_opcodes |
| 0x1E9580 | 0x1EA340 | maintex | invented | med | GetTextureInfo/MainTextureInterface (@792-832, TEX_* G sbss 0x37d4f0..), calcWeaponParam*, SetDamageParam, AddExpWeaponParam (@936), SetSwordBlurEffect (uses TEX_SystemEffectSw) |
| 0x1EA340 | 0x1EBC70 | charasetup | invented | med | GetCharacterSnd (@868 drop from @936) .. SetupMonster; run 4611-4681 |
| 0x1EBC70 | 0x1F3D70 | dngmenu | sinit | high | CDngFreeMap::Initialize .. DngTreeMapDraw + vague CBaseMenuClass inlines + W mgRect<f>::Set 0x1f3d50; run 4682-4827 |
| 0x1F3D70 | 0x1FF8E0 | editmenu | sinit | high | GetPenkiColor .. MenuRemovalDraw + vague InitEnd 0x1ff8d0; run 4828-5097 |
| 0x1FF8E0 | 0x20E460 | inventmn | sinit | high | GetInventUserDataPtr (no locals, name) .. MenuInventDraw; run 5098-5425 |
| 0x20E460 | 0x21EAD0 | menuaqua | sinit | high | OPEN-END: static Get_aquarium_paul_table 0x20e460 .. DrawSubGameUnderLine (ends 0x21eacc); run 5426-5719. menucls1 begins 0x21ead0 (GetHatena refs menucls1 locals) |
| 0x21EAD0 | 0x2214F0 | menucls1 | sinit | high | runs idx 5720-5760 (__sinit_menucls1.cpp, no text locals); GetHatena/SetMenuBigNum/MakeMsg(CGameDataUsed)/MenuUseItemCheckFunc ref its locals; CMenuItemUse::UseItem uses MenuUsedTarget (sbss 0x37d9d8, inside menucls1 sbss gap); classes CMenuFont/CDC2Mes/CMenuMoveItem/CMenuItemUse |
| 0x2214F0 | 0x234C80 | menudraw | sinit | high | run idx 5761-5946 (__sinit_menudraw.cpp); AttachMessageForm 0x2214f0 refs @873 (menudraw rodata); ends with CMenuEffect + W templates PrimQuad<f>/<i>; end boundary med (stub MenuScreenBlackBeltSet 0x234c80 could be either side) |
| 0x234C80 | 0x239470 | menumain | sinit | high | run idx 5947-6079 (__sinit_menumain.cpp); GetMenuLoopType 0x234c90 refs menumain sbss; last func BookshelfMessageMake refs menumain locals |
| 0x239470 | 0x252CF0 | menusys | sinit | high | run idx 6080-6587 (__sinit_menusys.cpp); first func DrawTrushMenuMessage is a menusys local; ends after MenuItemSelectDraw (refs menusys); end boundary med: GetRandI/GetRandF (0x252cf0-0x252d58) have no evidence |
| 0x252CF0 | 0x2576F0 | menucommon | invented | med | run idx 6588-6884 (no sinit): ReCalcBox local 0x252d60 .. _MENU_DEBUG_PRINTF + MenuCommandAnalyze (refs menu_execommand_analyze_tag); menu utilities + SPI menu-form script commands; start uncertain (GetRandI/F placed here, low) |
| 0x2576F0 | 0x2583E0 | event | sinit | high | runs idx 6885-6892 (__sinit_event.cpp, .p__sinit_event, vv$984); LoadNpcTalkMes/SetEventScript/EventDoorLoop/EventLoop ref its locals; GetEventMessage/GetActiveCamera/GetCharacter use EventScene (sbss global inside event's range) |
| 0x2583E0 | 0x2608F0 | sceneseq | invented | high | run idx 6893-6974 (no sinit): InitSplineKey local 0x2583e0, scs* statics, ScsCmrSeqCallTbl/ScsObjSeqCallTbl; classes C3DSpline/CCameraPas/CCharaPas/CSceneCmrSeq/CSceneObjSeq; last local-ref func TexAnime__12CSceneObjSeq 0x2604c0; end boundary med (class grouping) |
| 0x2608F0 | 0x281AB0 | event_func | sinit | med | run idx 6975-7819 (__sinit_event_func.cpp); first text local FileNameConvLanguage 0x262cc0; 0x2608f0-0x262cc0 (CEoh, VectMatMul, CalcPosWorldCoord*, CEohMother) has NO local refs: placed here because CalcPosWorldCoord/SetCamWorldCoord use SetWorldCoordFlg (sbss global inside event_func range) and EventObjHandleMother(CEohMother) is constructed in __sinit_event_func; could instead be a locals-free TU; end high (SetEventFunc refs event_func, OutPutFile is eventedit local) |
| 0x281AB0 | 0x2850B0 | eventedit | sinit | high | runs idx 7820-7899 (__sinit_eventedit.cpp; MoveChara local idx 7899 is referenced by EventEdit so the 135/136 cut is spurious); ends after DrawEventEdit |
| 0x2850B0 | 0x288970 | scene | invented | med | runs idx 7900-7912 (no sinit): CRipple::Draw refs @853, CRain::Step refs @1117, CScene::GetData @1171 jumptable, InScreenFunc @1503/@1504/init$1519/sun_func$1518, Assign* noname$N sdata; f_rand/i_rand/RandXYinViewArea used only by rain/ripple; @N monotone 853..1709 across ripple/rain and CScene so one TU assumed (alt: split at 0x286890 CSceneData) |
| 0x288970 | 0x289E48 | sceneload | invented | med | OPEN-END at libgcc 0x289e48 (TU fully inside slice): runs idx 7913-7925: LoadMapData local 0x288970, LoadChara/CopyChara/LoadMapFromMemory/LoadMap ref its @N; @N restart (rodata @1171->@885, data @1504->@820) proves new TU after idx 7912; start boundary med (23 locals-free CScene methods 0x2882e0-0x288960 assigned to scene) |
| 0x289E48 | 0x28A538 | lib/libgcc/_divdi3 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __divdi3 |
| 0x28A538 | 0x28A598 | lib/libgcc/_fixdfdi | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __fixdfdi |
| 0x28A598 | 0x28A688 | lib/libgcc/_fixunsdfdi | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __fixunsdfdi |
| 0x28A688 | 0x28A720 | lib/libgcc/_floatdidf | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __floatdidf |
| 0x28A720 | 0x28AD88 | lib/libgcc/_moddi3 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __moddi3 |
| 0x28AD88 | 0x28ADE8 | lib/libgcc/_muldi3 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __muldi3 |
| 0x28ADE8 | 0x28B3B8 | lib/libgcc/_udivdi3 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __udivdi3 |
| 0x28B3B8 | 0x28B8F8 | lib/libgcc/_umoddi3 | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __umoddi3 |
| 0x28B8F8 | 0x28C5F0 | lib/libgcc/dp-bit | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __pack_d __unpack_d _fpadd_parts(L) dpadd dpsub dpmul ...(+9) |
| 0x28C5F0 | 0x28D1D0 | lib/libgcc/fp-bit | dc1 | high | 1 GCC obj(s) (.text secsym boundaries); funcs: __pack_f __unpack_f _fpadd_parts(L) fpadd fpsub fpmul ...(+9) |
| 0x28D1D0 | 0x28D1F0 | filesocket | invented | low | two 8-byte stubs called from LoadFile2/WriteFile; no locals; unrelated to following mg class; could instead head visualmotion |
| 0x28D1F0 | 0x28EB50 | visualmotion | invented | high | all mgCVisualMotionMDT methods + static SetData0-7 (symtab run 7970-7983); vtable 0x37c260 first of part B |
| 0x28EB50 | 0x28ED90 | ezbgm | invented | high | ezBgmInit/ezBgm/CSound::StreamOpenState ref gCd2/sbuff/@32-54 (run 7984-7990); @N restart 358->32 |
| 0x28ED90 | 0x293EC0 | dng_event | sinit | high | __sinit_dng_event run 7991-8051; CStartupEpisodeTitle/MessageTaskManager/CRedMarkModel (no locals) placed here: dungeon-main helpers, CRedMarkModel vtable sits after CGeoStone vtable |
| 0x293EC0 | 0x295160 | eventsprite | invented | med | single-local run 8052 (@1069, "" used by CEventSprite2::Draw); @N drop 2529->1069; CMarker/CEventSprite* constructed by event_func sinit; Parabolic* (used by scsJump) placed here, start could be 0x294060 |
| 0x295160 | 0x29A5D0 | menushop | sinit | high | __sinit_menushop run 8053-8193; GetDonyShopLineUp..MenuNPCQuestViewDraw; CMenuQuestView+CShopMenu vtables adjacent |
| 0x29A5D0 | 0x29C470 | editriver | invented | high | CEditMap river methods + CEditGrid; runs 8194-8205 data @504-799; @N drop 2470->504 |
| 0x29C470 | 0x29FDF0 | movie | invented | high | CMovie + static mpeg/vobuf/vibuf/audioDec helpers (run 8206-8326, strings cdrom0/\\MOVIE\\/sceMpeg) |
| 0x29FDF0 | 0x2A02B0 | editmapeffect | invented | med | CEditMap::DrawFireEffect/DrawFireRaster/DrawEffect/AnimeStep; run 8327-8330 (fire_wrk, lightling, attr$378, init$379); rodata @N drop 1270->358; end at 0x2a02b0 by class |
| 0x2A02B0 | 0x2A2E70 | funcpoint | invented | med | CheckTime..GetLightAnimeWeight: CFuncPoint/CObjAnime/CFuncPointMngr + free DrawFire*; run 8331-8340 sorted wholly after 8327-8330 (separate TU vs editmapeffect); start by CheckTime used by CFuncPoint::Check |
| 0x2A2E70 | 0x2A9270 | title | sinit | high | __sinit_title run 8341-8511; title_init_rand..TitleLangSelDraw |
| 0x2A9270 | 0x2A92A0 | sndviewlp | invented | low | 3 x 8-byte stubs Init/Finish/LoopSoundViewerMain in loop table; no locals; same pattern as chara/texture/map viewer stub groups at 0x1a3460; could belong to title or editinfo |
| 0x2A92A0 | 0x2A9FF0 | editinfo | invented | high | CEditInfoMngr + static emap* SPI handlers (run 8512-8581, @368-396); CEditMap::GetEvent 0x2a9e50 (no locals) attached here by adjacency (low) |
| 0x2A9FF0 | 0x2ACCD0 | scenesnd | invented | med | CScene BGM/snd methods + GetNumber3/GetLine statics (run 8582-8596, snd2/bgm strings); start at CScene::BGM_INFO::Init (0x2a9ff0) vs CEditMap::GetEvent uncertain |
| 0x2ACCD0 | 0x2AEF10 | editdata | sinit | high | __sinit_editdata run 8597-8633; EditAnalyzeDataSrc::Init..__ct__14EditAnalyzeSrcFv (ctor called by __sinit_editdata) |
| 0x2AEF10 | 0x2AF5B0 | menucapt | sinit | high | __sinit_menucapt run 8634-8661; MenuChapterInit/Key/Draw (chap%d.img strings) |
| 0x2AF5B0 | 0x2AFA60 | npccfg | invented | high | static _NPC_NUM/_NPC_INFO, LoadNPCCfg..GetPartyNPCData (run 8662-8678, npc%d.cfg); rodata @N 906->838 drop vs menucapt |
| 0x2AFA60 | 0x2B41F0 | menumap | sinit | high | __sinit_menumap run 8679-8766; _WMAP_*..SphidaScoreViewDraw |
| 0x2B41F0 | 0x2C4260 | menuchr | sinit | high | __sinit_menuchr run 8767-9210; MENU_BGREAD_INFO2 helpers (no locals) at start used mostly by menuchr; weak Set__9mgRect<s> 0x2c4240 at end (used by MenuCharaChangeStarDraw) |
| 0x2C4260 | 0x2CB730 | menuop | sinit | high | __sinit_menuop run 9211-9426; InitMenuReturnMsg..SubGameSaveDraw (manual/option/save/subgame save menus) |
| 0x2CB730 | 0x2CC360 | movieviewlp | sinit | high | __sinit_movieviewlp run 9427-9465 incl static _MOVIE__FP9SPI_STACKi; MovieViewInit/Exit/Loop |
| 0x2CC360 | 0x2CD390 | sceneevent | invented | high | CScene map-info/event/lens-flare/effect methods (run 9466-9471, eyeview_on/fire_work); @N drop 1037->858; ends before GetChrFileSize |
| 0x2CD390 | 0x2D0670 | scenevillager | invented | high | CScene chara/villager/object methods + GetChrFileSize/GetMotionName/SetCharaMotion statics (run 9472-9508); @N drop 1093->815 |
| 0x2D0670 | 0x2D1A50 | pot | invented | high | CalcReflectionVector + CFragment/CBPot/CPot (run 9509-9514, box/rock/rnd_obj); @N drop 1847->1196 |
| 0x2D1A50 | 0x2D2720 | villagermngr | invented | med | CVillagerPlace/CVillagerData/CVillagerPlaceInfo/CVillagerMngr; single-local run 9515 (@513 in CVillagerMngr::Step); @N drop 1438->513; separated from actscript only by symtab order + @N gap 513->1118 |
| 0x2D2720 | 0x2D6C00 | actscript | invented | high | ParabolicInitialVector, GetStack*/SetStack, ~110 RS_STACKDATA action-script handlers, Shot*Gun, SetActionScript/SetActionExtendTable (run 9516-9655) |
| 0x2D6C00 | 0x2D8AA0 | mapselect | invented | high | OPEN-END (crosses 0x2d8000): mlMAP_NAME*, LoadMapName..MapSelectLoop, SaveDataEditLoop, EventViewLoop, GetLine, AtraMiriaOnOff (run 9656-9732); next TU (font, run 9733-9829, @N drop 1471->812) starts 0x2d8aa0 GetGaijiW |
| 0x2D8AA0 | 0x2DAE90 | font | invented | med | run 9733-9829 (@784..1543, meswin/fonttbl_*.bin, FontTex_s_*); GetGaijiW/H use GaijiDataTbl (first global after run51 data, precedes run53 data); CFont methods through Init__5CFontFv |
| 0x2DAE90 | 0x2DB1B0 | occlusion | invented | low | COcclusion::Setup/CheckSphere only; no locals/data refs; split from font by class (could belong to font or window TU) |
| 0x2DB1B0 | 0x2DD5D0 | drawwin | invented | low | free window-draw fns (CalcSelectCursorPos..DrawDQFukidashi); no locals; sole users of global `data` 0x35b570 which sits between font data and editmode data; could be tail of font TU |
| 0x2DD5D0 | 0x2DD740 | gaiji | invented | high | runs 9830-9839: @258..278 (tiny TU, @N reset from 1543), meswin/*/gaiji.img, GaijiBuff, FontTex_2_Buff; LoadGaijiImg..GetFontTex2ImgPtr |
| 0x2DD740 | 0x2E2DE0 | editmode | sinit | high | __sinit_editmode.cpp; local CheckControl at 0x2dd740; last ref CheckEditToWalk |
| 0x2E2DE0 | 0x2E3C10 | intersection | invented | med | run 10064 @161 (tiny TU) used by IntersectionPipeYPoly3; Intersection* fns; mt_test__FP12RS_STACKDATAi (8-byte stub, 0x2e3c00) placed here by adjacency, could start mapjump |
| 0x2E3C10 | 0x2E4DE0 | mapjump | sinit | high | __sinit_mapjump.cpp; GetMainMapNo first ref, InteriorMapJump last |
| 0x2E4DE0 | 0x2EDDD0 | effscript | invented | high | run 10098-10271 @943..3645; CEffectScriptMan + effect-script RS_STACKDATA ext funcs; strings dungeon/eff_script/%s.* |
| 0x2EDDD0 | 0x2F0E50 | sphida | invented | high | runs 10272-10278 (GolfClubDef, sphida_bar); GetSphidaClubDef..CSphida::DrawMiniMapSymbol incl CPowGage, DPrimEnterSprite |
| 0x2F0E50 | 0x2F23E0 | cameracontrol | invented | med | runs 10279-10280 (@396 data, @373 bss: small TU) referenced by CCameraControl::SetRotate/SetCheckRef; start at CameraCtrlParam::SetFixHeight by class; ends with vague Iam__14CCameraControlFv |
| 0x2F23E0 | 0x2F26F0 | padcontrol | invented | low | CPadControl methods only, no locals; separated from camera TU by class (could be tail of cameracontrol) |
| 0x2F26F0 | 0x2F49B0 | editmap2 | invented | high | runs 10281-10293; local PlaneNormalXZ at 0x2f26f0 first; CEditMap methods; CheckFenceChain local; UpdateHouse refs runs 64+65 |
| 0x2F49B0 | 0x2F62D0 | editevent | invented | high | run 10294-10316: CEditEvent + Georama funcs (LoadGeoNPC, info.cfg, npc_pos); start at CEditEvent::Reset by class |
| 0x2F62D0 | 0x2F6390 | menusystemdata | invented | low | CMenuSystemData methods only; no locals/refs; could belong to editevent or memcard |
| 0x2F6390 | 0x2FA530 | memcard | invented | high | runs 10317-10372: CMemoryCardManager, BESCES-51190dkcl strings, cosbit_table; CopyMCBrowserName first ref, GetCosInfo last; includes McCheckMCPs2* |
| 0x2FA530 | 0x2FB260 | swordeffect | invented | med | run 10373 @356 (small TU) used by CSWordAfterEffect::StartEffect; CreatSmoothPassSW + CSWordAfterEffect methods |
| 0x2FB260 | 0x2FC2A0 | savedata | invented | med | run 10374 @453 used by CSaveData::Initialize; InitSV_CONFIG_OPTION + CSaveData + CSphidaData + CGyoRaceData + CSubGameData (no locals; grouped as save-data classes) |
| 0x2FC2A0 | 0x2FC4F0 | savedatadungeon | invented | med | runs 10375-10376 (limmit_table, @79) used by CSaveDataDungeon methods; @79 < @453 => separate TU from savedata |
| 0x2FC4F0 | 0x2FDD70 | editexception | invented | high | run 10377-10415: EditExceptionStep, S51Thunder, FirePowder, CGeyserEffect (effect/firerain.img, effect/geyser.img) |
| 0x2FDD70 | 0x2FFAE0 | dngfloor | invented | med | runs 10416-10466: CDngFloorManager + _TREE_MAPINFO/_ROOM_* script cmds; start at CDngFloorManager::Initialize by class; GetCountSphedaClear/CheckFishingRecord (no refs) included by adjacency |
| 0x2FFAE0 | 0x3015F0 | editeff | sinit | high | __sinit_editeff.cpp; EditSetEffectBuffer first ref; ends with vague __ct__11CStarEffectFv; PlaceAnime bss global used |
| 0x3015F0 | 0x308FC0 | fishing | sinit | high | __sinit_fishing.cpp; local GetFishParam at 0x3015f0; LoadFishPlaceData last |
| 0x308FC0 | 0x309A00 | subgame | sinit | high | __sinit_subgame.cpp; InitSubGame..sgDrawSubGameSystem + sgCPlayVoice (@985 %d.wav) |
| 0x309A00 | 0x30E5C0 | gyorace | sinit | high | __sinit_gyorace.cpp; sgInitGyoRace..Jikkyou |
| 0x30E5C0 | 0x30F890 | nowload | sinit | high | __sinit_nowload.cpp; SwitchNowLoadingThread (no refs) by name/adjacency, NowLoadingLoop..SCElogoFade |
| 0x30F890 | 0x313880 | nameregi | sinit | high | __sinit_nameregi.cpp; SetEventKeyword..CNameRegiMenu::DrawMessage |
| 0x313880 | 0x314DB0 | photo | sinit | high | __sinit_photo.cpp; GetMesTxt..DrawTakePhotoSystem |
| 0x314DB0 | 0x318B70 | fishingobj | sinit | high | __sinit_fishingobj.cpp; SetFishingMode..ParaBlend incl CFishObj |
| 0x318B70 | 0x31BDD0 | pbuggy | sinit | high | __sinit_pbuggy.cpp; sgInitBuggy..BombCheck |
| 0x31BDD0 | 0x31E310 | editanalyze | invented | high | run 11156-11170: AnalyzeEditMap/AnalyzeSharlot/Heim/MoonFlower.., EditMapInitEvent |
| 0x31E310 | 0x31EAD0 | helpmes | sinit | high | __sinit_helpmes.cpp; LoadHelpMes..ShowErrorHelpMes |
| 0x31EAD0 | 0x31FBD0 | vlgr_info | sinit | high | __sinit_vlgr_info.cpp; GetVlgrPlaceInfo..GetGameProgressNum + vague __ct__14CVillagerPlaceFv |
| 0x31FBD0 | 0x320090 | quest | invented | med | runs 11263-11275 (quest_cmd_tag, spi_quest*); GetQuestData..GetQuestRequestStatus; CMonsterBook::CountKill (no refs) by adjacency |
| 0x320090 | 0x320C80 | mainloop3 | sinit | high | __sinit_mainloop3.cpp; FutureMapSelect..EmergencyMessage (buf0/dbuf0 bss) |
| 0x320C80 | 0x320D40 | hddinstall | invented | low | 12 HDD/install stub fns (HddConectCheck..UninstallApp), no locals; could be tail of mainloop3 |
| 0x320D40 | 0x321850 | password | invented | high | runs 11332-11341 @211: search_txt, ConvLongToTxt, GetCRC, Encode/DecodeBinData, txt_table, random_seed |
| 0x321850 | 0x321B90 | crandom | invented | low | CRandom::nget + abs__Ff, no locals; could be tail of password or head of gyoracesim |
| 0x321B90 | 0x324AC0 | gyoracesim | invented | high | runs 11342-11366 (fish_data, jrand, ia): grGyoRaceSimulate..GetRandomNumber |
| 0x324AC0 | 0x325C80 | convviewlp | sinit | high | __sinit_convviewlp.cpp; SVConvViewInit..SaveDataConvertLoop (last fn ends 0x325c60; 0x325c60-0x325c80 padding before .vutext) |

## Per-unit data

Every unit's `.data`, `.rodata`, `.sdata`, `.sbss`, `.bss`, `.init`, `.ctor` and `.vtables` ranges are in `main.yaml`. Local symbols fix a range wherever a unit has them: a local belongs to the unit whose functions reference it. Global objects lying between two units' locals were placed by which unit references them, by which `__sinit` constructs them, and by class.

- Game `.rodata` holds only local symbols, so every boundary there is exact.
- A global vtable sits in the unit holding the class's first non-inline virtual function; a vague-linkage vtable sits in the first unit that references it.
- `__sinit_<file>.cpp` functions and their `__static_init` entries are in unit order, one per unit that has static initialisers.
- The word at 0x37C6F0 (`_overlay_group_addresses`, value 0x00100000) is referenced by nothing and is left outside any unit, as `main/rdata`.
- Library bss ends at 0x385EC0; libgcc's `.rodata` (0x3728A0-0x372CA0) and `.bss` (0x1F35080-0x1F350C0) sit between the two halves of the game, as its text does.

### Boundaries that are not certain

| Section | Start | Unit | Confidence | Evidence |
|---|---|---|---|---|
| .data | 0x00341DA0 | monster | med | 14 locals (dung_progtxt_notlift_mons..mos_data_anlyze_tag) ref only by monster; global base_monster_define: refs monster GetMonsterTable/CMonsterMan::GetReferPtr2 (+dng_debug,dng_main earlier units, excluded by order); alt automap (no refs) |
| .data | 0x003551C0 | menusys | med | 50 locals (WepStatusInfoStrTable..imgtbl$8945) ref only by menusys; global menu_item_swap_sndtbl: refs menusys (4 funcs) +inventmn,menushop (outside window); alt menucommon (no refs) |
| .sdata | 0x0037C748 | mainloop | low | 4 locals anchored by referencing functions, 1 globals; gap globals: between snd_mngr @1469 and mainloop @973; only referrer is main (159, outside candidate range); name affinity to mainloop; alt snd_mngr |
| .sdata | 0x0037CC4C | memcard | med | no locals, 1 globals; gap globals: between editevent MenuInfo and dngfloor @938; memcard is the only referrer inside candidate range editevent..dngfloor (others dngmenu, menumain); alt any of menusystemdata..editexception |
| .sbss | 0x0037CF74 | nd_meswin | med | no locals, 4 globals; gap globals: MesAbsDrawOff/MovieCC* referenced only by nd_meswin; nd_meswin MovieCC* bss globals likewise follow gameutil locals; alt gameutil (DC1 defines MesAbsDrawOff in gameutil.cpp, which held message-window code) |
| .sbss | 0x0037DE24 | menucommon | med | 18 locals anchored by referencing functions, 2 globals; gap globals: refs menumain, menuaqua, menucommon; menucommon only in-range referrer (menusys does not reference); alt menusys |
| .bss | 0x00396FF0 | mg_tanime | med | first=nowTexData; 1 locals, 0 globals; sinit |
| .bss | 0x00397030 | mglib | med | first=mgGiftagAD; 8 locals, 7 globals; sinit; mgGiftagAD: refs mglib:42 vs mg_tanime:4, mg_visual:0; precedes mgRenderInfo (sinit mglib); unit start 16-aligned after nowTexData; mgRenderInfo: __sinit_mglib constructs; refs mglib:130; mgBackColor: between mglib sinit objects; refs mglib only; mgTexManager..mgDrawManager(2 globals): __sinit_mglib constructs; mgDBuff: between mglib objects; refs mglib:88; mgPickZBuff: refs mglib only |
| .bss | 0x003ECFC0 | gameutil | med | first=def_vrtx; 13 locals, 0 globals |
| .bss | 0x003F0460 | nd_meswin | med | first=NameRegistTbl; 0 locals, 5 globals; sinit; NameRegistTbl: refs nd_meswin only; precedes MovieCCFont (sinit nd_meswin); MovieCCFont: __sinit_nd_meswin constructs; MovieCCStart..MovieCCStr(3 globals): refs nd_meswin only |
| .bss | 0x003F6540 | snd_mngr | med | first=PortInfo; 7 locals, 0 globals; sinit |
| .bss | 0x003FA5A0 | mainloop | med | first=GamePad; 21 locals, 3 globals; sinit; GamePad: snd_mngr never refs; mainloop:106 refs; contiguous with DebugInfo (sinit mainloop); PadCtrl: snd_mngr never refs; mainloop:18; between GamePad and DebugInfo (sinit mainloop); DebugInfo: __sinit_mainloop constructs |
| .bss | 0x01E95C60 | gamedata | med | first=GameItemDataManage; 11 locals, 1 globals; sinit; GameItemDataManage: refs gamedata:58 vs mainloop:6 |
| .bss | 0x01EFB410 | menuaqua | low | first=Aquarium_NameregistStack; 15 locals, 1 globals; sinit; MenuDCMsg: refs menuaqua:26, menucls1:0 (every other global here is referenced by its owner); no sinit constructs it; alt menucls1 (CDC2Mes methods live there) |
| .bss | 0x01EFBA68 | menucls1 | low | first=@1407; 2 locals, 0 globals |
| .bss | 0x01EFBA90 | menudraw | med | first=menu_limmit_displayflag; 30 locals, 7 globals; sinit; menu_limmit_displayflag: refs menusys:4, menudraw:2, menucls1:0; alt menucls1; MenuMesForm: follows menu_limmit_displayflag; refs menudraw:2, menucls1:0; alt menucls1 |
| .bss | 0x01EFD370 | menucommon | med | first=MenuSpiTextureName; 1 locals, 1 globals; MenuCommandAnalyzeInfo: refs menucommon:8, event:0; Menu* name; alt event |
| .bss | 0x01EFD400 | event | med | first=EventScript; 1 locals, 0 globals; sinit |
| .bss | 0x01EFD460 | event_func | med | first=EdEventInfo; 10 locals, 15 globals; sinit; EdEventInfo: refs event_func:448 vs event:106; DC1 defines EdEventInfo next to ObjHandle (cf. EventObjHandleMother, sinit event_func); alt event; EventObjHandleMother..PakuMotionName2(11 globals): __sinit_event_func constructs EventObjHandleMother; run referenced by event_func; followed by event_func locals |
| .bss | 0x01F3C760 | menumap | med | first=WorldMapStack; 3 locals, 0 globals; sinit |
| .bss | 0x01F3C7E0 | menuchr | med | first=MenuCharaBuild2; 33 locals, 6 globals; sinit; MenuCharaBuild2: refs menusys/menuchr only, menumap:0; precedes MenuActionCharaBuffer (sinit menuchr); alt menumap; MenuActionChara: refs menuchr:26, menumap:0; alt menumap; MenuActionCharaBuffer: __sinit_menuchr constructs; MenuLoadItemNo: refs menuchr:26 |

## Open questions

- `CEditMap` and `CScene` methods are spread over several units (`editmap`, `editriver`, `editmapeffect`, `editinfo`, `editmap2`; `scene`, `sceneload`, `scenesnd`, `sceneevent`, `scenevillager`); local-symbol ownership shows these are separate units.
- Text units marked low confidence have no local symbols and were separated by class or purpose alone; each could be part of a neighbour.
- The Metrowerks runtime units (`lib/mwcc/*`) and six `lib/sce/kernl` objects have invented names.
