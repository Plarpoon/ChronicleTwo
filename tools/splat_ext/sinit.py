"""A unit's static initialiser, `__sinit_<file>.cpp`.

MWCC emits the function into a section of its own, which the retail link
places after `.rodata` as `.init`, not in `.text`. A `.sinit` subsegment is that
code: it is disassembled like any other, but belongs to the unit of the same
name and is written into that unit's file, never one of its own.
"""

from typing import Optional

from splat.segtypes.common.asm import CommonSegAsm


class PS2SegSinit(CommonSegAsm):
    # The unit's `.text` stays the segment its other sections are siblings of.
    @staticmethod
    def is_text() -> bool:
        return False

    def get_linker_section(self) -> str:
        return ".init"

    def get_section_flags(self) -> Optional[str]:
        return "ax"

    def should_self_split(self) -> bool:
        return False

    def split(self, rom_bytes: bytes):
        return
