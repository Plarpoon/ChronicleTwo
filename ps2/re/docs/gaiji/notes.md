# gaiji: header notes

Unit owns no classes (`build/re/class_units.tsv` has no `gaiji` rows). The header declares only
the four global functions. No first-game counterpart unit exists (`chronicle/ps2/include` has no
gaiji header).

## Globals
- `GaijiBuff` @ `0x01F465F0`, `.bss`, `0x11800` bytes. It must have external linkage because
  the retail `vutext.data.s` references its symbol. Destination of `LoadFile` in
  `LoadGaijiImg`; returned by `GetGaijiImgPtr`. Callers (mainloop `MenuInit`, editloop `EditInit`,
  maintex `MainTextureInterface`, event_func `LoadMovie`, title, movieviewlp, mainloop3, convviewlp)
  pass the result to `mgCTextureManager::EnterIMGFile(u_char *img, ...)`, hence the `u_char *`
  return type. A `u_char[0x11800]` declaration matches the retail image and linker references.
- `FontTex_2_Buff` @ `0x0037E4B4`, `.sbss`, 4 bytes: pointer to the second font texture image.
  Read by `LoadFontTex2Img` (null check, then `LoadFile` destination) and returned by
  `GetFontTex2ImgPtr`. Being local, and no function of this unit writing it, it is always null in
  retail: `LoadFontTex2Img` always returns 0 and `GetFontTex2ImgPtr` returns null. It is a
  local `u_char *`.

## Functions
- `LoadGaijiImg()` -> `int`: switch on `LanguageCode` (mainloop.hpp `LanguageCodeNo`), loads
  `meswin/<lang>/gaiji.img` into `GaijiBuff` via `LoadFile(char*, void*, int*)` (dataread.hpp),
  returns the size written to the local `int`. Jump table `at_264` (6 entries, cases 0-5):
  `LANG_JAPANESE` -> `meswin/jpn/gaiji.img` (`at_258`), `LANG_FRENCH` -> `meswin/eu/fra/...`
  (`at_259`), `LANG_GERMAN` -> `eu/ger` (`at_260`), `LANG_ITALIAN` -> `eu/ita` (`at_261`),
  `LANG_SPANISH` -> `eu/spn` (`at_262`), default (incl. `LANG_ENGLISH` = 1 and >= 6) ->
  `meswin/usa/gaiji.img` (`at_263`). Note case 1 in the jump table goes to the default block;
  the default case in source is written before case 2 in Ghidra's ordering, check the disassembly
  block order (jpn, fra, ger, ita, spn, default/usa) when matching. Size local at `sp+0x1C`.
- `GetGaijiImgPtr()` -> `u_char *`: returns `GaijiBuff`.
- `LoadFontTex2Img()` -> `int`: `if (FontTex_2_Buff) { if (LanguageCode == LANG_JAPANESE)
  { LoadFile("meswin/font2.img", FontTex_2_Buff, &size); return size; } else 0 }`; returns 0
  otherwise.
- `GetFontTex2ImgPtr()` -> `u_char *`: returns `FontTex_2_Buff`.
- Callers of the loaders (`MainLoop`, `LanguageChange` in mainloop) ignore the return values.

## Matching result
- All four functions and the unit's data are in C++ source. The English case has an explicit
  branch to the shared USA load block; this preserves MWCC's six-entry switch table without
  duplicating the USA call. The rebuilt executable verifies byte-identically in every section.
