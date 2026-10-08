# dngmenu: reverse-engineering notes

`dng_light_circle` and `dngfreemap_num` are const `mgRect<int>` globals: MWCC emits their zero-initialized storage in retail's `.rodata` section and still runs their constructors from the exact 144-byte static initializer. Declaring them without `const` places the storage in `.bss` and breaks the section mapping.

## Additional map behavior

`CalcGlidPutPos` maps a cell to board coordinates `x * 52 - y * 16` and
`y * 20`; its final argument selects whether to add the current scroll.
`CheckIsViewMove` clips a point to the view rectangle, reserving 10 pixels
at the right and bottom, and returns the displacement required to bring it
inside. `SetNextRoomPos` applies that displacement to the scroll target.
`ResetDngMapPos` centres a room on `(256, 208)` and uses `(-100, -100)`
when the requested room is absent.

`DrawGlidCheck` inspects a passage cell's four neighbours. It marks adjoining
rooms above and left with bits `2` and `8`; visited boss or sub rooms set
directional bits `0x40`, `0x80`, `0x100`, or `0x200`. `DrawBackPattern`
draws a translucent black rectangle in event mode. In menu mode it scrolls
the `dt` backdrop by half a pixel per frame and wraps its offset at the
tile width of 128. `DrawLast` covers the menu screen with `dtbg`, while
`DrawDngName` draws `dtname` twice, offset by four pixels for its shadow.

`FadeIn` starts at alpha zero and increases by `128 / frames` per step;
`FadeOut` decreases by the same amount. For nonpositive durations, the
step is 128 in magnitude. `SetKomaMove` starts at the second node of the
path because `koma_path` itself is the piece's starting point.

`CheckDngTreeMapFuncType` returns 2 when the menu's `open_type` is 3,
1 when it is 1 or `TreeMapCallDungeonSubMap` is set, and 0 otherwise. The
flag is read as an unsigned byte even though the assembly reservation is
four bytes. `CheckGeoramaMateria` walks the floor's group identifiers, collects
the item numbers from matching groups, then twice removes items whose
attribute word does not contain bit `0x10`.

`DrawPlayer` draws the `dngop` texture at its room's board position, shifted
four pixels right and thirty up. In event mode it takes positions from the
next path node and retains the last position in `dng_player_pos`; in menu
mode it bobs vertically. The shared `dng_player_blink_cnt` wraps at fifty
frames and also modulates the sprite's brightness. `DngTreeMapDraw`
dispatches to the tree map or save menu using the byte `DngTreeMode`.

`CDngFreeMap::Step` advances an active fade, eases each scroll coordinate
one fifth of the remaining distance towards its target, snaps the value
when its integer distance is zero, wraps the room blink counter at 100,
increases `DngTreeMapActiveLightRate` by 0.05 up to 1, and clears the
queued mark count before the next draw.

`MakeDngTreeMapJumpNo` maps the first floor of each dungeon through
`name_tbl_2728`. It has special transitions from dungeon 0 floor 8 to
`s01`, dungeon 1 floor 6 to `s05`, and dungeon 3 floor 20 to `d04b01`;
the latter can instead select loop 2 when story flag `0x1B6` is set and
`0x1BC` is clear. The first floor of dungeon 6 also sets the main scene's
map to `d07f01`.

`DrawTreeMap` first draws a shrinking highlight around the selected cell
in menu mode. It then visits every grid cell: rooms go through
`DrawRoomOne`, with a half-bright interval during their blink cycle, and
passages go through `DrawRoot` twice, once for each layer. The outgoing
marks come from `DrawGlidCheck`.

`DngTreeMapKey` steps the tree map in map mode. When that step opens the
save screen, it saves map information, sets loop number 2, and gives the
save menu the unused portion of `MenuTreeMapStack` plus the tree menu's
fourth texture block. When the save screen closes, it clears the save
flag, resumes map mode, starts a forty-frame fade and resets the tree
menu to mode 12, step 1 before rebuilding its messages.

`__sinit_dngmenu_cpp` sets the initial source rectangles for the map's
light circle, number glyphs, root placement and floor information frame,
then initializes `MenuTreeMapStack`.

`CMenuTreeMap::MsgInit` attaches `systree.mes` to all eight message windows,
applies preset 15, enables zero values, and configures the command
analyzer's menu and system message buffers. Its `MSG_INIT` script sets up
the shared message window. That window begins with message 300 and appends
message 81 or 80 for the two special opening modes, then places two lines
near the screen bottom. The second line moves to x=600 while the save
screen is inactive.

`DrawRoot` draws passage shapes 0 through 9 as three parallel line strips
or pairs of strips. Its first call is the shadow layer, shifted eight
pixels down and right and drawn at five percent alpha; its second call is
the coloured layer. Menu mode uses a warm tint, while event mode uses a
darker red. Opened passage types with `show_mark` draw a 22 by 22 mark from
`root_type_texturecrd_1216`, positioned with `markOffsetTable_1092` (or
`zerumaito_offset_1110` for shape 0 in dungeon 6).

`DrawRoomOne` chooses a room picture from `dt` according to its visited
state, texture number, and start/exit/boss/sub flags. Dungeon numbers 4–6
use a slightly larger destination rectangle. It draws a shadow in menu
mode, dims rooms other than the player's in event mode, advances each
room's mark phase by the mode-specific value in `stepCntTbl_1501`, and
queues the bobbing mark rectangle. An unvisited room receives a small
overlay unless it is the player's room. Visited rooms can display up to
three glyphs from `dtname`, chosen by the room flags.

`DrawGeoramaMateria` draws a page of up to fourteen georama item names in
two columns, using `GeoramaMateriaInfoDrawPage` for the starting item and
`GeoramaMateriaNum` for the end. It reloads the floor information texture
for the frame, reloads the message texture for the names, then displays
the page count in the lower right.

`DngTreeMapInit` reserves a work buffer from the remaining menu stack,
constructs the tree menu and floor map inside it, loads the floor grid when
the opening mode requires it, and reads the menu's data list. It sets each
of the eight message windows to use the system message buffer and gives
the second window the digit font. The menu cursor texture file is
`frametex.img`.

`CMenuTreeMap::InitEnd` loads the dungeon map picture and floor information
texture, chooses a room from saved progress (or the marked boss/sub room),
centres the map on it, starts the opening fade, and loads `systree.mes`.
It then reads the dungeon treasure script into an aligned buffer and
builds the treasure tables if that read succeeds.

`CMenuTreeMap::Draw` draws the floor map and, when enabled, the shared help
message. It draws the selected floor's information and medals, eases the
cursor towards that room, and draws the cursor or money board. During the
save transition it animates the second help line and its colour.

`CDngFreeMap::Draw` skips inactive or fully transparent maps and maps
without a texture. It clamps opacity to 0–128, reloads `dt`, draws the
backdrop, whole-screen overlay, cells and player piece, then composites
queued room marks with `dtname` outside event mode. With
`menu_debug_flag` set it additionally draws a diagnostic panel for the
selected room, including its links, visit count and eight save flags.

Unit: dungeon floor map (`CDngFreeMap`) and the dungeon menu's tree map (`CMenuTreeMap`).
No first-game counterpart (Dark Cloud 1 has no class of either name; nothing equivalent found
in `/home/adubbz/development/chronicle/ps2/include`).

## Header dependencies
- `CMenuTreeMap : CBaseMenuClass` -> `menusys.hpp` (did not exist when this header was written).
- `CDC2Mes mes[8]` by value -> `menucls1.hpp` (exists; asserts `sizeof(CDC2Mes) == 0x2A50`).
- `TRESURE_BOX_FLOOR_INFO tresure` by value -> `dng_event.hpp` (did not exist). Its size must be
  0x1A40C: `AutoSetTreasureBox` (dng_event) does `__nw(0x1A40C)` for one.
- Forward-declared only: `GLID_INFO`, `DNGMAP_ROOM_INFO`, `DNGMAP_ROOT_INFO` (dngfloor owns
  them: `CDngFloorManager` returns/takes `GLID_INFO*`), `CDngFloorManager`, `CSaveDataDungeon`,
  `mgCMemory`, `mgCTexture`.
- The header was verified to compile, and `dngmenu.cpp` to compile with it, against stub
  versions of the three missing types with the sizes above (CBaseMenuClass 0x110 with its
  vptr at 0x10C).

## CDngFreeMap (size 0x110)
Size: `DngTreeMapInit` `__nw(0x110)`; symbol `EventDngMap` (event_func) size 0x110.
Constructor is inline (emitted in `DngTreeMapInit` and `__sinit_event_func_cpp`): it calls
`mgRect<float>::Set(0,0,0,0)` on the rect at 0x20 and on each of the 8 rects at 0x40, then
`Initialize()`. That means `mgRect<T>` has a default constructor `{ Set(0,0,0,0); }` (and the
globals in `__sinit_dngmenu_cpp` show a 4-argument constructor calling `Set`). `mgRect` lives in
`mg_tanime.hpp` with no constructors; they have to be added there before the constructor matches.
`mgRect<float>::Set` (0x1F3D50) is emitted in this unit and comes from that template.

| Off | Type | Name | Evidence |
|---|---|---|---|
| 0x00 | CSaveDataDungeon* | save_dungeon | DngTreeMapInit stores MenuSaveDataDungeonPtr; LoadDngInfo `GetSaveData()+0x1C5B4` |
| 0x04 | CDngFloorManager* | floor_manager | `menu_GetBattleAreaScene()+0x14`; GetRoomGlid/GetNextGlid call through it |
| 0x08 | u8 | active | Initialize =1; Step/Draw return when 0 |
| 0x09 | u8 | unk_9 | only zeroed in Initialize |
| 0x0A | s16 | dng_no | LoadDngInfo param 3; DngTreeMapInit; compared 1..6 in LoadDngInfo, 6 in DrawRoot |
| 0x0C | s16 | mode | 0 Initialize (menu), 1 LoadDngInfo (event); indexes `stepCntTbl_1501[2]` |
| 0x10 | float | back_scroll | DrawBackPattern tile offset, +0.5 per frame |
| 0x14-0x1F | | unk_14 | never accessed |
| 0x20 | mgRect<float> | view_rect | Initialize Set(120,138,420,286); LoadDngInfo Set(60,40,W-40,H-40); CheckIsViewMove |
| 0x30 | s32 | mark_num | DrawRoomOne appends to 0x40[], Step zeroes, Draw iterates |
| 0x34-0x3F | | unk_34 | never accessed |
| 0x40 | mgRect<float>[8] | mark_rect | DrawRoomOne writes `this+0x40+n*0x10`; Draw draws each with name_tex sprite (0xC0,0xD2,0x40,0x2E) |
| 0xC0 | s16 | user_room_no | LoadDngInfo param 4; Initialize -1 |
| 0xC2 | s16 | next_room_no | LoadDngInfo param 5; Initialize -1; heavily adjusted in LoadDngInfo per dungeon |
| 0xC4 | GLID_INFO* | user_glid | SetUserGlid; DrawPlayer |
| 0xC8 | s16 | blink_cnt | Step ++ wrap at 100; DrawTreeMap `%25 < 14` blink |
| 0xCC | GLID_INFO* | select_glid | CMenuTreeMap::Step copies its select_glid here; Draw debug readout; CMenuTreeMap::Draw |
| 0xD0 | s16 | tex_block | InitTexture -1; LoadDngInfo param 2; DeleteTexBlock |
| 0xD4 | mgCTexture* | name_tex | "dtname" / "dtname_dn" |
| 0xD8 | mgCTexture* | map_tex | "dt" / "dt_dn"; Draw reloads its block `*(s16*)tex` |
| 0xDC | mgCTexture* | last_tex | "dtbg"; DrawLast full screen |
| 0xE0 | mgCTexture* | koma_tex | "dngop" / "dngop_dn"; DrawPlayer |
| 0xE4 | DNGMAP_KOMA_POS* | koma_path | LoadDngInfo builds the list |
| 0xE8 | DNGMAP_KOMA_POS* | koma_now | SetKomaMove sets `koma_path->next`; DrawPlayer advances |
| 0xEC | s16 | koma_move | SetKomaMove param |
| 0xF0 | float | alpha | Initialize 128.0; Step clamps 0..128 |
| 0xF4 | s32 | fade_time | FadeIn/FadeOut param; Initialize -1 |
| 0xF8 | float | fade_step | +-128/time |
| 0xFC | s32 | fade_mode | -1 Initialize, 0 FadeIn, 1 FadeOut |
| 0x100/0x104 | float | pos_x/pos_y | scroll; eased towards 0x108/0x10C by 1/5 in Step |
| 0x108/0x10C | float | next_pos_x/y | Initialize 200.0; ResetDngMapPos `256-x`, `208-y` |

`DNGMAP_KOMA_POS` is an invented name (no retail symbol): `{float x, y; next}` nodes allocated
with `mgCMemory::Alloc(1)` (one 16-byte unit; only 0xC used). Built from
`RootHokanTable*` (20 s16 x/y pairs each) and `RoomHokanTable*`
(10 pairs each) offsets in LoadDngInfo.

Not a virtual class (no vtable symbol, no vptr store).

## CMenuTreeMap (size 0x2FBE0)
Size: `DngTreeMapInit` `__nw(0x2FBE0)` (after `Alloc(0x2FC0)` units). Base `CBaseMenuClass` is
0x110 (its ctor does `memset(this, 0, 0x110)`, vptr at 0x10C). Constructor inline in
`DngTreeMapInit`: base ctor, vptr = `__vt__12CMenuTreeMap`, 8x `CDC2Mes` ctor, then
0x11A=0, 0x120=0, 0x153B0=0, base 0x14=0, 0x153C0=1, 0x153B8=0, 0x153BC=0, 0x153C4=0, then
for i<8: `MenuDngMes[i] = &mes[i]; ClsMes::Init(); SetBuff_system(GetSystemMesBuffer())`, then
`MenuDngMes[1]+0x224C = 0x10`. `MenuDngMes` is a file-local static, so the constructor body has
to be defined in dngmenu.cpp (declared only in the header).

| Off | Type | Name | Evidence |
|---|---|---|---|
| 0x110 | float[2] | cursor_pos | passed as `float*` to MenuCursorDraw; eased in Draw |
| 0x118 | s16 | dng_no | DngTreeMapInit param 4 (clamped 0..6) |
| 0x11A | s16 | unk_11a | only ever set 0; tested in FadeInOutMenu and Draw |
| 0x11C | s16 | jump_pay | set 1 when `BattleAreaScene+0x5C == 0 && MenuCommonInfo+0x50 == 1` and not sub map; jump then `AddMoney(-money/2)` |
| 0x120 | GLID_INFO* | select_glid | InitEnd/Step |
| 0x124-0x12F | | unk_124 | never accessed |
| 0x130 | CDC2Mes[8] | mes | stride 0x2A50 to 0x153B0; Step uses mes[1],[3]..[6] (0x2B80, 0x8020, 0xAA70, 0xD4C0, 0xFF10) |
| 0x153B0 | short* | mes_data | "systree.mes" pack file; SetMessData |
| 0x153B4 | s32 | cursor_view | Draw draws cursor when set |
| 0x153B8 | s32 | cursor_reset | Draw snaps cursor_pos and clears |
| 0x153BC | s32 | money_view | Draw: PrimDrawNumber of user money (`UserDataMan+0x44D9C`) |
| 0x153C0 | s32 | help_view | ctor 1; Draw gates the shared help window |
| 0x153C4 | u8 | tresure_loaded | InitEnd sets 1 after CreatTresuarBoxInfo |
| 0x153C8 | TRESURE_BOX_FLOOR_INFO | tresure | CreatTresuarBoxInfo / CheckGeoramaMateria |
| 0x2F7D4 | s32[0x103] | georama_materia | CheckGeoramaMateria output; DrawGeoramaMateria input. Count 0x103 is only the remaining bytes (0x40C) up to the class size; no bound is visible in the code |

Vtable `__vt__12CMenuTreeMap` (0x37BF70, 0x20): `0, 0, IsCreateObject, IsMakeObject,
IsAskExtend, ItemCmdAfter, InitEnd (CMenuTreeMap), ExitEnd` -- all but InitEnd are
`CBaseMenuClass`'s, emitted here as weak inline copies (IsCreateObject returns 1, the other
three return 0, ExitEnd empty). Step calls InitEnd through the vtable at +0x18.

`*(s16*)this` (base) is the menu state: 0 running, 1 opening (calls InitEnd when the fade and
BG read finish), 2 closing, 0xC returning from the save menu. Base 0x14 is the sub-screen
(0 map, 1 floor info, 2 georama list); base 0x2 is a sub-state used with 0xC.

## Enums
- `DNGMAP_MODE` (CDngFreeMap::mode): 0 menu, 1 event (see above).
- `DNGMAP_FADE`: -1/0/1 (Initialize, FadeIn, FadeOut).
- `DNG_TREE_MAP_RESULT`: CMenuTreeMap::Step returns 2 when `DAT_01efc64c == 5` (jump chosen),
  1 otherwise on close, 0 while open; DngTreeMapKey passes it through; menumap's WorldMoveKey
  tests 1 and 2.
- `DNG_TREE_MODE`: `DngTreeMode` static, 0 tree map, 1 save menu (DngTreeMapKey/Draw).
- `CheckDngTreeMapFuncType` gives 2 when `MenuCommonInfo+0x50 == 3` (menumain opens the tree
  map with mode 3 from a save point, setting TreeMapSaveFlag), 1 when it is 1 or
  `TreeMapCallDungeonSubMap`, else 0. No enum: the meaning of mode 1 is not established.

## Globals
Only four of the unit's data symbols are global (others are LOCAL in retail, so `static` in the
.cpp): `TreeMapSaveFlag` (u8, lbu), `TreeMapSaveNum` (s16, lh; menuop increments per save),
`TreeMapCallDungeonSubMap` (u8; menumain SetCommonMenuModeID), `TreeMapCalledWorldMap` (u8;
menumap). Statics of note: `MenuDngMap` (CDngFreeMap*), `CMenuTreePt` (CMenuTreeMap*),
`MenuDngMes` (CDC2Mes*[8]), `MenuTreeMapStack` (mgCMemory, 0x30), `treemap_root_put`
(mgRect<float>), `Floor_Info`, `dng_light_circle`, `dngfreemap_num` (mgRect<int>),
`dng_player_pos` (float[2]), `Floor_InfoTex` (mgCTexture*, "dngfibrd"), `DngTreeMode` (s16),
`GeoramaMateriaNum` (s16), `DngInfoStageNo` (u8).

## Non-members
`CheckGeoramaMateria`, `DrawDngRoomInfo`, `DrawGeoramaMateria` are LOCAL in retail -> static in
the .cpp, not in the header. `ClsMes::Init` (0x1F38E0) is emitted here but declared in
`nd_meswin.hpp`.

## GLID_INFO / DNGMAP_ROOM_INFO as seen from here (for dngfloor's header)
GLID_INFO stride 0x70 (CDngFloorManager +4 array, +8 count, +0xC/+0xE grid width/height):
+0 s16 kind (0 passage, 1 room), +2 s16 grid x, +4 s16 grid y, +0xC GLID_INFO*[4] neighbours,
+0x1C u8 blink, +0x20 DNGMAP_ROOM_INFO / DNGMAP_ROOT_INFO. Room info (relative to +0x20):
+4 char* georama list, +8 s8 floor id, +0xC u32 flags (2 entrance, 4, 8, 0x10 special floors),
+0x18 s16 message no, +0x3E/+0x40 s16 draw offset, +0x42 s8 picture, +0x45 u8 (cleared/visited;
also read as glid+0x65 in DrawGlidCheck), +0x46 u8 mark (bobbing mark, glid+0x66 in InitEnd),
+0x48 float mark phase (DrawRoomOne).

`LoadDngInfo` uses the unused portion of its caller's stack for a temporary
arena. It loads `dmap%d.img` into the assigned texture block with the `_dn`
suffix, then positions the board at the current room. When an event has a
next room, dungeon-specific branch rules reduce jumps to a nearby room. The
function creates a linked path of piece positions: ten interpolation points
for the destination room, twenty for each intervening passage cell, and ten
for any intervening room. Direction and passage shape select the point table
and whether it is read forward or backward. The first path node is the
piece's starting point; subsequent nodes drive event movement. The returned
value is the number of quadwords consumed from the temporary arena.

`CMenuTreeMap::Step` handles cursor navigation, floor detail messages,
confirmation of travel to a floor, the save-menu handoff, and debug controls.
Its persistent static state records the previous direction and selected
cell so movement can distinguish a held key from a new selection.

`DrawDngRoomInfo` draws the floor detail panel only when a room and its
texture are available. Its height varies with the language and whether the
floor has a geostone, spheda challenge or fishing test. The panel fades in
six alpha units per frame and out eight. It draws the border and seal pulse,
then places four challenge rows and their message windows; the medal message
uses a language-specific position.

The medal overlay's UV coordinates in `DrawDngRoomInfo` remain uncertain:
retail copies packed words from `medal_xytbl_1736` into rectangle locals.
The current draft uses the existing highlight rectangle for that overlay,
so its placement needs further work during matching.

`mgRect<float>::Set` stores its four arguments directly into the left, top,
right and bottom fields. The explicit float specialization is a separate
retail symbol from the generic template, emitted by a native specialization.

## Native static initialization

The light-circle and free-map number rectangles are zero-filled 0x10-byte data globals whose four-argument constructors call `mgRect<int>::Set`. The root placement rectangle uses the default `mgRect<float>` constructor; the floor-information rectangle uses four arguments. A native `mgCMemory MenuTreeMapStack` completes the same initialization order. Together these globals emit the 144-byte retail `__sinit_dngmenu_cpp` exactly and retain the original data/BSS section assignments after object postprocessing. This replaces the guarded handwritten initializer and assembly fallback.

## Small floor-map functions: native assessment

The m2c output confirms the existing drafts for `SetUserGlid`,
`CalcGlidPutPos`, `SetTextureInfo`, `FadeIn`, `FadeOut`, `DeleteTexBlock`,
and `Initialize`. Dependencies are already typed and documented:
`CDngFreeMap` is 0x110 bytes, `GLID_INFO` grid coordinates are signed
16-bit fields at offsets 2 and 4, and the texture block is signed 16-bit
at 0xD0. Texture manager lookup takes a name and block number; deletion
takes the sign-extended block. Fade duration and state are 32-bit integers
with float alpha and step. Grid projection uses signed integer arithmetic
before conversion to float; its null case leaves both output references
unchanged. Initialization writes the Y scroll before X, X target before
Y target, and current path pointer before path head.

`mgRect<float>::Set` has four scalar float stores, confirmed by m2c. Its
native specialization is assessed alongside the small functions because
the assembly fallback coexists with an implicitly instantiated template
body and creates an unnamed extra text section in the baseline object.

### Canonical native result

All eight assessed functions have zero byte and resolved-relocation
differences: `Initialize`, `SetUserGlid`, `CalcGlidPutPos`, `SetTextureInfo`,
`FadeIn`, `FadeOut`, `DeleteTexBlock`, and `mgRect<float>::Set`. The entire
isolated wrapper object passes the canonical comparator (0x8C30 compared
bytes and 1097 relocations). The assembly fallback for the float rectangle
specialization creates an anonymous extra text section in the prior
object, preventing text comparison; the native specialization resolves
that section issue and the associated unresolved targets.

Initialization requires the binary32 286.0 value (`0x438f0000`) in
`Initialize__11CDngFreeMapFv` to evaluate first. This is an unscoped stable
Satan's Fiddle identity. It restores the early f15 load without changing
the rectangle arguments. Separate assignments preserve the target-scroll
and path-pointer store order.

MWCC emits retail's `slt` plus branch when the comparison operands are
written `0 <= room_no` and `0 < frames`; writing the variable first emits
the dedicated signed-zero branch. Grid X projection adds the negative
row contribution (`x * 52 + y * -16`), preserving retail's negation
before the shift. Texture deletion binds the manager before testing the
block number so the manager address is available at the retail branch.
