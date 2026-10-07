# menusystemdata notes

## CMenuSystemData (size 0x308, no vtable, no base)
Embedded in `CSaveData` at +0x640C0 (`GetMenuSysData__Fv` in menumain returns `GetSaveData() + 0x640C0`;
`MenuMainInit` sets `MenuSystemDataPtr = MenuActiveSaveData + 0x640C0`). In the memory-card / convview
save buffers it is at +0x64140 (buffer has a 0x80 header before CSaveData); `__sinit_mainloop_cpp` constructs
the static `SaveData` copy. No counterpart class found in the first game.

Size: the ghobi array ends at 0x288 + 32*4 = 0x308, and the next CSaveData member (the BitCtrl byte used by
`Init/Get/Set/ResetBitCtrl__9CSaveData`) is at +0x643C8 = 0x640C0 + 0x308. No accesses in between.

Offset evidence:
| Off | Field | Evidence |
|---|---|---|
| 0x00/0x02 | item_board_select / item_board_top | menusys `MenuItemInit` reads `MenuSystemDataPtr[0..1]` into `MenuItem_ItemBoardTopSelect/TopLine`; `CMenuItemInfo::ExitEnd` writes them back |
| 0x04/0x06 | unk_4/unk_6 | `CMenuItemInfo::ExitEnd` writes 0; never read |
| 0x08 | item_key_arg_no | ExitEnd writes `this->key_arg_no` (CBaseMenuClass +0x14) |
| 0x0A | item_cursor | ExitEnd writes `(s16)MenuCommonInfo->cursor` (CMenuKeyFunc +0x70) |
| 0x20/0x22 | invent_item | inventmn `MenuInventInit` / `CMenuInvent::ExitEnd` <-> CMenuInvent item_cursor/item_top (+0x11C/+0x120) |
| 0x2E | invent_unk_2e | same functions <-> CMenuInvent `unk_392` (meaning unknown) |
| 0x30..0x3E | invent_card/photo/album/memo | <-> CMenuInvent card_*, photo_*, album_*, memo_* (+0x114..+0x138), all as s16 |
| 0x50..0x6A | georama_list[7] | editmenu `MenuGeoramaInit` (pairs 0..2 via `SetGeoListInfo`) / `CMenuGeorama::ExitEnd` (all 7) <-> `CMenuGeorama::list_info[7]` (GEORAMA_LIST_INFO, s32 pairs there; s16 pairs here) |
| 0x288 | ghobi[32] | `CheckGetAlready` / `GetGhobi`: `lh 0x288(this + i*4)`, i < 0x20; GetGhobi `sh` into first slot with value <= 0 |

Restoring only happens when `CursorSaveOptionState()` is non-zero (cursor-memory option).

`MENU_SYSTEM_GHOBI.unk_2`: the element stride is 4 but only the s16 at +0 is ever touched. Could equally be
`s16 ghobi[32][2]`; type and field names (`MENU_SYSTEM_LIST_CURSOR`, `MENU_SYSTEM_GHOBI`) are not retail.
"Ghobi" is retail's word (from the symbol); the entries are Donny's goods: `GetDonyShopLineUp` (menushop)
skips `dony_shoplist` items for which `CheckGetAlready` is true, and `CShopMenu::KeyStep` calls `GetGhobi(item)`
when `NowSellMode == SHOP_SELL_MODE_DONY` (3).

## Functions
- The constructor, `MenuSystemDataInit`, and `CheckGetAlready` compile and match the retail
  game image. `GetGhobi` has a named compiling draft; its first promotion attempt differed by
  two instructions, so the `NONMATCHING` guard retains the retail assembly fallback.
- `CMenuSystemData()`: just calls `MenuSystemDataInit()`, returns this.
- `MenuSystemDataInit()`: tail-calls `memset(this, 0, 4)`. Size 4 is almost certainly a retail bug
  (`sizeof(this)` / sizeof a pointer); write it as `memset(this, 0, 4)` or `sizeof(this)`. Declared `void`
  (v0 is memset's result via the tail jump; no caller uses it). `CSaveData::Initialize` calls it directly.
- `CheckGetAlready(int)`: returns 1 if any `ghobi[i].item_no == item_no`, else 0. Loop counter and byte
  offset in separate registers (i, i*4).
- `GetGhobi(int)`: void; loop exits on the first slot with `item_no <= 0` (`bgtz` skip), stores `(s16)item_no`
  there; store address recomputed as `i*4 + this` (`sll`, `addu`) separately from the load address.

## Globals
None owned by this unit. `MenuSystemDataPtr` (CMenuSystemData*) belongs to menumain.
