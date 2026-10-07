# editanalyze notes

## Ownership
No class or struct is owned by this unit (`class_units.tsv` has no row for it). The header holds
only free-function prototypes and the `EditAnalyzeMap` enum. No first-game counterpart unit.

## Linkage
Local in retail (`local_symbols.tsv`), so `static` in the `.cpp`, not in the header:
`CheckSaku(CEditMap*, int)`, `GetTreeNum(CEditMap*)`, `CheckInfoID(CEditMap*, int, int)`,
`AnalyzeSharlot/Stera/Benietio/Heim/MoonFlower(CEditData*, CEditMap*)`,
`GetColorType(CEditParts*, int)`.
Global (in header): `AnalyzeEditMap`, `CountPartsType`, `CountPartsInfoID`, `GetHouseParts`,
`GetPartsPos`, `CheckLiveChara`, `EditMapInitEvent`.

External callers: `AnalyzeEditMap` <- `EditDataSave`, `EditDataLoad` (editloop, passes `MapNo`);
`EditMapInitEvent` <- `SubMapLoadStep`, `EditMapJump`, `EditExitInterior`;
`CheckLiveChara` <- `CRemovalMenu::KeyStep` (args: `MenuMainScene+0x2e60` map no,
`MenuMainMapInfo`, `this+0x418` house slot, a villager value from `this+0x144[this+0x14f8]`).

## Functions
- `AnalyzeEditMap(map_no, map)`: null-checks map, `GetSaveData()->GetEditData(map_no)`, dispatches
  0..4 to Sharlot/Stera/Benietio/Heim/MoonFlower. Enum `EditAnalyzeMap` comes from this; each
  `AnalyzeX` calls `CEditData::Analize(<same index>, cond[64], ...)` (Stera passes 1), so the
  index matches `EDIT_ANALYZE_MAP_MAX` (editdata.hpp) numbering.
- `AnalyzeX`: two 64-int stack arrays (first zeroed = condition results, second filled with -1),
  filled from `CEditMap::BalanceCheck`, `CheckLiveNPC`, `GetePlacePartsAtInfoID`, culture points
  (`CEditData+4` = `culture_point`) thresholds, save bit flags; then `CEditData::Analize`.
- `CountPartsType/CountPartsInfoID(value, map, list, num)`: count slots in `list[num]` whose
  `GetePlaceParts(slot)` is non-null and `GetPartsType()`/`GetInfoID()` == value. Return int.
- `GetHouseParts(map, list, max)`: loops over the 4 info IDs in `at_913__6` (.data, 0x10:
  `{1, 9, 0x16, 0x1F}`, a local `int[4]` initialiser) calling `GetePlacePartsAtInfoID(id, list,
  max)`, advancing list and reducing max; returns total. Those four IDs are the house parts.
- `GetPartsPos(map, no, pos)`: returns `CEditParts*` (NULL if map or slot empty) after calling the
  part's virtual at vtable offset 0x18 with `pos` (position getter; slot not yet named in
  editparts/mapparts headers -- verify).
- `GetColorType(parts, which)`: `CMapParts::GetColor(which, col)`, compares against
  `CEditPartsInfo::GetDefColor` of the info pointer at `CEditParts+0x324`; if it differs, scales by
  128 and finds the nearest of 8 `GetPenkiColor(i)` colours within distance 2.0. Returns 0..7 or -1.
- `CheckLiveChara(map_no, map, no, chara)`: switch on `chara` 0..0x19 (jump table `at_1618__2`,
  .rodata 0x68 = 26 entries). Uses `GetTerritoryParts(no, buf[0x200], 0x200)` then
  CountPartsType(2/6/7/8)/CountPartsInfoID(7/0x11/0x12), `GetRiverNum(no, 300.0f)`, position y
  (>= 134 for map 2, else >= 84), `CultureAnalyzeParts(no, 0) > 0x13`, `GetInfoID` == 1/0x4b/0x16,
  `GetColorType` == 5/6, and `info+0x1c == 1`. Returns 0/1 as int (m2c: s32). The part's info
  pointer at +0x324 null -> 0. Meaning of `chara` values not established beyond being villager
  kinds from the removal menu; no enum made.
- `EditMapInitEvent(map_no, map)`: only for map_no == 14: `CFuncPointMngr::Search` at
  `CEditMap+0xcb0` for `"dun07"` (`at_1632__3`), sets found point `+0x10` = `GetBitFlag(800)`;
  `CMap::GetPlaceParts("p02_e05a02-0")` (`at_1633__3`) then virtual at vtable 0x54 with
  `flag == 0` (likely a show/hide). Map 14 is not named; no map-number enum exists yet.

## Data (all compiler-generated, no externs)
`at_913__6` (.data 0x10, house info IDs), `at_964__4` (.data), `at_1618__2` (jump table),
`at_1632__3` / `at_1633__3` (strings), `at_1297__4` (.bss 0x10, used by AnalyzeMoonFlower only;
likely a function-local static).

## Unresolved
- Names of the five towns behind the retail function names (enum uses the retail spellings).
- `chara` value meanings in CheckLiveChara; CEditParts vtable slots 0x18 and 0x54.
