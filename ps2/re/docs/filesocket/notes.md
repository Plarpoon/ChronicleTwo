# filesocket

The unit contains two file-socket entry points and no data. It owns no classes, structs, enums
or globals (`class_units.tsv` has no row for it). Both functions are already decompiled and
match; `draft.sh filesocket --promote` reports PROMOTE OK.

- `LoadFileSocket(char *path, unsigned int *data)`, 0x28D1D0, 0x10-byte slot: `jr ra` with
  `li v0, 0` in the delay slot. Returns `int`.
- `WriteFileSocket(char *path, unsigned int *data, int size)`, 0x28D1E0, 0x10-byte slot:
  `jr ra; nop`. Returns `void`.

## Callers (dataread)
Both are reached only when `GetFullPath` returns device 2, `FILE_DEV_NET` in `dataread.hpp`
(the "net:" prefix). The caller prints the full path (`at_660`) first.
- `LoadFile2`: stores `LoadFileSocket`'s result into its `int *size` out-parameter and returns
  success only if it is non-zero, so the return value is the loaded byte count. `data` is the
  destination buffer.
- `WriteFile`: calls `WriteFileSocket(fullpath, buf, size)` and reports success unconditionally.

The retail bodies are empty stubs; the parameter types come from the mangled names. No
counterpart in the first game's headers (`chronicle/ps2/include` has no `*Socket` symbols).
