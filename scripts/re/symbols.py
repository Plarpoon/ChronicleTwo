#!/usr/bin/env python3
"""Write, for every game function, the symbols relevant to it.

    symbols.py [-o build/re/symbols] [unit ...]

Reads build/re/manifest.tsv (scripts/re/manifest.py) and the retail
executable's relocations, and writes `<out>/<unit>.json` for every game unit:

    {"unit": ..., "functions": {<name>: {"address", "size", "section",
        "demangled", "calls": [...], "callers": [...], "data": [...]}}}

- `calls`: functions this one jumps to (`jal`/`j`, R_MIPS_26) or takes the
  address of (HI16/LO16 to code, `"kind": "address"`), in first-reference
  order.
- `callers`: functions (game or library) referencing this one, by address,
  then data words pointing at it (vtables, function tables, the
  `__static_init` table) as `"kind": "data"`.
- `data`: data symbols reached through HI16/LO16 pairs and GPREL16, one entry
  per symbol in first-reference order, with every offset into it that is
  used (`"offsets"`, when any is not the start), the kinds of access the
  instructions make (`"access"`: read, write, address) and a short preview of
  its initial value when it is a string or a single word.

Names are the project's (main.symbols.txt, and the `D_<ADDR8>` names given
to unnamed game data); `demangled` is the CodeWarrior demangling of retail's
own spelling, omitted when it does not parse. A summary of what was resolved,
and of how the manifest's functions compare with the executable's FUNC
symbols, is printed at the end.
"""

import argparse
import bisect
import importlib.util
import json
import math
import os
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "scripts" / "build"))

import disassemble  # noqa: E402
import layout  # noqa: E402

# scripts/build/symbols.py, loaded by path: this module shares its name.
_spec = importlib.util.spec_from_file_location(
    "build_symbols", ROOT / "scripts" / "build" / "symbols.py")
retail_symbols = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(retail_symbols)

R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 2, 4, 5, 6, 7
STT_SECTION = 3
GP = 0x003846F0
CODE = disassemble.CODE_SECTIONS
PREVIEW_SECTIONS = (".rodata", ".data", ".sdata", ".rdata")

# Load and store opcodes, for the access an LO16/GPREL16 immediate is used for.
LOADS = {0x20: "lb", 0x21: "lh", 0x22: "lwl", 0x23: "lw", 0x24: "lbu", 0x25: "lhu",
         0x26: "lwr", 0x27: "lwu", 0x1A: "ldl", 0x1B: "ldr", 0x37: "ld", 0x1E: "lq",
         0x31: "lwc1", 0x35: "ldc1", 0x36: "lqc2"}
STORES = {0x28: "sb", 0x29: "sh", 0x2A: "swl", 0x2B: "sw", 0x2C: "sdl", 0x2D: "sdr",
          0x2E: "swr", 0x3F: "sd", 0x1F: "sq", 0x39: "swc1", 0x3D: "sdc1", 0x3E: "sqc2"}
ADDRESS = {0x09: "addiu", 0x19: "daddiu", 0x08: "addi", 0x18: "daddi"}
LUI = 0x0F


def hex8(value):
    return f"{value:08X}"


def sext16(value):
    value &= 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


# --------------------------------------------------------------------------
# CodeWarrior demangling
# --------------------------------------------------------------------------

BUILTIN = {"v": "void", "c": "char", "s": "short", "i": "int", "l": "long",
           "x": "long long", "f": "float", "d": "double", "r": "long double",
           "b": "bool", "w": "wchar_t", "e": "..."}
OPERATORS = {
    "nw": "operator new", "dl": "operator delete", "nwa": "operator new[]",
    "dla": "operator delete[]", "pl": "operator+", "mi": "operator-",
    "ml": "operator*", "dv": "operator/", "md": "operator%", "er": "operator^",
    "ad": "operator&", "or": "operator|", "co": "operator~", "nt": "operator!",
    "as": "operator=", "lt": "operator<", "gt": "operator>", "apl": "operator+=",
    "ami": "operator-=", "amu": "operator*=", "adv": "operator/=",
    "amd": "operator%=", "aer": "operator^=", "aad": "operator&=",
    "aor": "operator|=", "ls": "operator<<", "rs": "operator>>",
    "ars": "operator>>=", "als": "operator<<=", "eq": "operator==",
    "ne": "operator!=", "le": "operator<=", "ge": "operator>=",
    "aa": "operator&&", "oo": "operator||", "pp": "operator++",
    "mm": "operator--", "cm": "operator,", "rm": "operator->*",
    "rf": "operator->", "cl": "operator()", "vc": "operator[]",
}


class Unparsed(Exception):
    pass


class Demangler:
    """A recursive-descent reader of one mangled suffix."""

    def __init__(self, text):
        self.s = text
        self.i = 0

    def peek(self):
        return self.s[self.i] if self.i < len(self.s) else ""

    def take(self, n=1):
        if self.i + n > len(self.s):
            raise Unparsed
        out = self.s[self.i:self.i + n]
        self.i += n
        return out

    def number(self):
        start = self.i
        while self.peek().isdigit():
            self.i += 1
        if start == self.i:
            raise Unparsed
        return int(self.s[start:self.i])

    def class_name(self):
        """`<len><name>`, with any template arguments demangled."""
        n = self.number()
        raw = self.take(n)
        return template_name(raw)

    def qualified(self):
        """`Q<n><name>...` or `<len><name>`, as a list of components."""
        if self.peek() == "Q":
            self.take()
            count = int(self.take())
            return [self.class_name() for _ in range(count)]
        if self.peek().isdigit():
            return [self.class_name()]
        raise Unparsed

    def type(self):
        """A type, as a function from a declarator to a declaration."""
        c = self.peek()
        if c == "C" or c == "V":
            self.take()
            word = "const" if c == "C" else "volatile"
            inner = self.type()
            if inner.simple:
                return Decl(lambda d, inner=inner: f"{word} {inner(d)}", True)
            return Decl(lambda d, inner=inner: inner(f" {word}" + (f" {d}" if d else "")))
        if c == "P" or c == "R":
            self.take()
            inner = self.type()
            mark = "*" if c == "P" else "&"
            return Decl(lambda d, inner=inner: inner(wrap(inner, mark + d)))
        if c == "A":
            self.take()
            n = self.number()
            if self.take() != "_":
                raise Unparsed
            inner = self.type()
            return Decl(lambda d, inner=inner, n=n: inner(f"{d}[{n}]"), False, True)
        if c == "F":
            self.take()
            params = self.params(stop="_")
            if self.take() != "_":
                raise Unparsed
            ret = self.type()
            return Decl(lambda d, ret=ret, params=params: ret(f"{d}({params})"), False, True)
        if c == "M":
            self.take()
            cls = "::".join(self.qualified())
            inner = self.type()
            return Decl(lambda d, inner=inner, cls=cls: inner(wrap(inner, f"{cls}::*{d}")))
        if c in ("U", "S"):
            self.take()
            base = self.take()
            if base not in "csilx":
                raise Unparsed
            word = "unsigned" if c == "U" else "signed"
            name = f"{word} {BUILTIN[base]}"
            return Decl(lambda d, name=name: join(name, d), True)
        if c in BUILTIN:
            self.take()
            name = BUILTIN[c]
            return Decl(lambda d, name=name: join(name, d), True)
        if c == "Q" or c.isdigit():
            name = "::".join(self.qualified())
            return Decl(lambda d, name=name: join(name, d), True)
        raise Unparsed

    def params(self, stop=""):
        out = []
        while self.peek() and self.peek() != stop:
            out.append(self.type()(""))
        if out == ["void"]:
            return ""
        return ", ".join(out)


class Decl:
    """A type rendered around a declarator; `compound` types (functions,
    arrays) need parentheses around a pointer declarator."""

    def __init__(self, render, simple=False, compound=False):
        self.render = render
        self.simple = simple
        self.compound = compound

    def __call__(self, declarator):
        return self.render(declarator)


def join(base, declarator):
    if not declarator:
        return base
    if declarator[0] in "*&[(":
        return base + declarator
    return f"{base} {declarator}"


def wrap(inner, declarator):
    return f"({declarator})" if inner.compound else declarator


def template_name(raw):
    """`CList<9CMapPiece>` -> `CList<CMapPiece>`; arguments that are not
    types (integer constants) are kept as written."""
    if "<" not in raw:
        return raw
    if not raw.endswith(">"):
        raise Unparsed
    head, args = raw[:raw.index("<")], raw[raw.index("<") + 1:-1]
    parts, depth, start = [], 0, 0
    for k, ch in enumerate(args):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == "," and depth == 0:
            parts.append(args[start:k])
            start = k + 1
    parts.append(args[start:])
    out = []
    for part in parts:
        if re.fullmatch(r"-?\d+", part):
            out.append(part)
            continue
        d = Demangler(part)
        text = d.type()("")
        if d.i != len(part):
            raise Unparsed
        out.append(text)
    return f"{head}<{', '.join(out)}>"


def special_name(name, cls):
    """The C++ spelling of a function's own name within its class."""
    if name == "__ct":
        if not cls:
            raise Unparsed
        return re.sub(r"<.*", "", cls[-1])
    if name == "__dt":
        if not cls:
            raise Unparsed
        return "~" + re.sub(r"<.*", "", cls[-1])
    if name.startswith("__op"):
        d = Demangler(name[4:])
        text = d.type()("")
        if d.i != len(name) - 4:
            raise Unparsed
        return f"operator {text}"
    if name.startswith("__") and name[2:] in OPERATORS:
        return OPERATORS[name[2:]]
    return name


def demangle_at(text, split):
    name, rest = text[:split], text[split + 2:]
    if not name or not rest:
        raise Unparsed
    d = Demangler(rest)
    cls = []
    if d.peek() == "Q" or d.peek().isdigit():
        cls = d.qualified()
    const = False
    if d.peek() == "C":
        d.take()
        const = True
    if d.peek() != "F":
        # A static data member.
        if d.i != len(rest) or not cls or const or name.startswith("__"):
            raise Unparsed
        return "::".join(cls + [name])
    d.take()
    params = d.params()
    if d.i != len(rest):
        raise Unparsed
    func = special_name(name, cls)
    out = "::".join(cls + [func]) + f"({params})"
    return out + " const" if const else out


def demangle(text):
    """CodeWarrior's demangling of a name, or None when it does not parse."""
    if not text or text.startswith("@") or "__" not in text[1:]:
        return None
    # The name and its mangled suffix are split at a `__`; a name may itself
    # begin with `__` (constructors, operators), so the search starts past it.
    start = 2 if text.startswith("__") else 1
    k = text.find("__", start)
    while k != -1:
        try:
            return demangle_at(text, k)
        except (Unparsed, IndexError, ValueError, KeyError):
            pass
        k = text.find("__", k + 1)
    return None


# --------------------------------------------------------------------------
# The executable
# --------------------------------------------------------------------------

class Elf:
    """The retail executable's image, symbol table and relocations, in table
    order with each relocation's symbol index."""

    def __init__(self, path=layout.ELF_PATH):
        data = Path(path).read_bytes()
        shoff, = struct.unpack_from("<I", data, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
        sections = []
        for i in range(shnum):
            fields = struct.unpack_from("<10I", data, shoff + i * shentsize)
            sections.append(dict(zip(("name", "type", "flags", "addr", "offset", "size",
                                      "link", "info", "align", "entsize"), fields)))
        names = sections[shstrndx]["offset"]
        for s in sections:
            s["name"] = data[names + s["name"]:data.index(b"\0", names + s["name"])].decode()
        main = next(s for s in sections if s["name"] == "main")
        self.base = main["addr"]
        self.image = data[main["offset"]:main["offset"] + main["size"]]
        self.symbols, _ = retail_symbols.read_symbols(Path(path))
        symtab = next(s for s in sections if s["type"] == 2)
        for k, sym in enumerate(self.symbols):
            _n, _v, _s, info, _o, shndx = struct.unpack_from(
                "<IIIBBH", data, symtab["offset"] + k * 16)
            sym["bind"] = info >> 4
            sym["shndx"] = shndx
        rel = next(s for s in sections if s["name"] == ".relmain")
        self.relocations = []
        for k in range(rel["size"] // 8):
            offset, info = struct.unpack_from("<II", data, rel["offset"] + k * 8)
            self.relocations.append((offset, info & 0xFF, info >> 8))
        self.relocated = {}
        for offset, kind, _sym in self.relocations:
            self.relocated.setdefault(offset, kind)

    def word(self, address):
        return struct.unpack_from("<I", self.image, address - self.base)[0]

    def bytes(self, lo, hi):
        return self.image[lo - self.base:hi - self.base]

    def holds(self, address):
        return self.base <= address < self.base + len(self.image)


# --------------------------------------------------------------------------
# Names and places
# --------------------------------------------------------------------------

class World:
    """Every name the project gives an address, which unit owns it, and which
    function contains a code address."""

    def __init__(self, manifest):
        self.layout = layout.Layout()
        self.index = layout.SymbolIndex()
        self.pieces = disassemble.Pieces(self.layout, self.index)
        self.elf = Elf()
        self.manifest = manifest

        # Unit ownership, by address.
        ranges = sorted((lo, hi, unit, section)
                        for (unit, section), (lo, hi) in self.layout.ranges.items() if hi > lo)
        self.unit_starts = [r[0] for r in ranges]
        self.unit_ranges = ranges

        # Retail spelling of every listed name, and the listed name of every
        # ELF symbol.
        spelled = retail_symbols.spelled(self.elf.symbols)
        self.original = {}
        self.elf_name = {}
        for sym in self.elf.symbols:
            name = spelled.get(sym["idx"])
            if name is None:
                continue
            if name in self.index.by_name and self.index.by_name[name][0] == sym["value"]:
                self.original.setdefault(name, sym["name"])
                self.elf_name[sym["idx"]] = name

        # Data names: the listed symbols and the pieces invented for game data,
        # with sizes from retail where it gives one, else the piece's extent.
        defined = self.pieces.defined()
        self.data_starts = [a for a, _n in defined]
        self.data_names = [n for _a, n in defined]
        self.size = {}
        for address, name, size, _func in self.index.rows:
            if size:
                self.size[name] = size
        self.extent = {}
        for unit in self.layout.units("cpp"):
            for _section, run in self.pieces.unit(unit):
                for name, start, end in run:
                    self.extent[name] = (start, end)
        self.address_of = {n: a for a, n in defined}

        # Functions: the manifest's, then every listed function of the other
        # units' code.
        funcs = {}
        for row in manifest:
            funcs[row["address"]] = (row["address"] + row["size"], row["symbol"], row["unit"], True)
        game_code = [(lo, hi) for lo, hi, unit, section in ranges
                     if section in CODE and self.layout.kinds.get(unit) == "cpp"]
        code_ranges = [(lo, hi, unit) for lo, hi, unit, section in ranges if section in CODE]
        for address, name, _size, is_func in self.index.rows:
            if address in funcs or name in layout.LINKER_SYMBOLS:
                continue
            if any(lo <= address < hi for lo, hi in game_code):
                continue
            unit = self.unit_of(address)
            if unit and layout.section_of(address) in CODE:
                funcs[address] = (None, name, unit, False)
        starts = sorted(funcs)
        self.func_starts = starts
        self.funcs = []
        for k, start in enumerate(starts):
            end, name, unit, game = funcs[start]
            if end is None:
                nxt = starts[k + 1] if k + 1 < len(starts) else None
                hi = next(h for lo, h, u in code_ranges if lo <= start < h)
                end = min(nxt, hi) if nxt else hi
            self.funcs.append((start, end, name, unit, game))

    def unit_of(self, address):
        i = bisect.bisect_right(self.unit_starts, address) - 1
        if i >= 0:
            lo, hi, unit, section = self.unit_ranges[i]
            if lo <= address < hi:
                return unit
        return None

    def unit_range(self, address):
        i = bisect.bisect_right(self.unit_starts, address) - 1
        if i >= 0:
            lo, hi, _unit, _section = self.unit_ranges[i]
            if lo <= address < hi:
                return lo, hi
        return None

    def function_at(self, address):
        """(start, end, name, unit, is_game) of the function holding address."""
        i = bisect.bisect_right(self.func_starts, address) - 1
        if i >= 0:
            f = self.funcs[i]
            if f[0] <= address < f[1]:
                return f
        return None

    def demangled(self, name):
        return demangle(self.original.get(name, ""))

    def data_symbol(self, address, sym=None):
        """(name, start) of the data symbol a target address belongs to.

        The symbol at or before the address within the same unit's section
        run is taken when the address lies inside it. MWCC relocates a
        file's data against whichever of its symbols it likes, so the
        relocation's own symbol only decides an address that lies outside
        every symbol (`a[i - 1]`, or one past the end), and then only when
        the address is near it. Otherwise it is the symbol before the
        address, or an invented `D_<ADDR8>` when its run has none.
        """
        i = bisect.bisect_right(self.data_starts, address) - 1
        bounds = self.unit_range(address)
        before = None
        if i >= 0 and (bounds is None or self.data_starts[i] >= bounds[0]):
            before = self.data_names[i], self.data_starts[i]
            size = self.symbol_size(*before)
            if address == before[1] or (size and address < before[1] + size):
                return before
        if sym is not None and sym["type"] != STT_SECTION and sym["idx"] in self.elf_name \
                and agrees(sym, address):
            name = self.elf_name[sym["idx"]]
            if name not in layout.LINKER_SYMBOLS:
                return name, sym["value"]
        return before or (disassemble.invented_name(address), address)

    def symbol_size(self, name, start):
        if name in self.size:
            return self.size[name]
        if name in self.extent:
            lo, hi = self.extent[name]
            return hi - lo
        return None


# --------------------------------------------------------------------------
# Relocations
# --------------------------------------------------------------------------

def float_text(raw):
    """The shortest decimal spelling that reads back as these four bytes."""
    value = struct.unpack("<f", raw)[0]
    for digits in range(1, 10):
        text = f"{value:.{digits}g}"
        if struct.pack("<f", float(text)) == raw:
            break
    if "e" not in text and "." not in text and "n" not in text:
        text += ".0"
    return text


def preview(world, name, start, size, how):
    """A short decoded preview of a datum's initial bytes, or None."""
    elf = world.elf
    section = layout.section_of(start)
    if section not in PREVIEW_SECTIONS or not size or not elf.holds(start + size - 1):
        return None
    if any(elf.relocated.get(a) == R_MIPS_32 for a in range(start, start + size, 4)
           if a % 4 == 0):
        return None
    raw = elf.bytes(start, start + size)
    text = string_text(raw)
    if size != 4:
        return text
    # A four-byte datum only ever taken by address and holding a short
    # string is that string; one loaded as a word is a number.
    if text is not None and not how and len(text) > 3:
        return text
    value = struct.unpack("<I", raw)[0]
    as_float = struct.unpack("<f", raw)[0]
    is_float = "float" in how or (
        "int" not in how and 0xFFFF < value < 0xFFFF0000
        and math.isfinite(as_float) and 1e-6 <= abs(as_float) <= 1e9)
    if is_float and (as_float == 0 or 1e-30 <= abs(as_float) <= 1e30):
        return float_text(raw) + "f"
    signed = value - (1 << 32) if value & 0x80000000 else value
    return str(signed) if -0x10000 < signed < 0x10000 else f"0x{value:08X}"


def string_text(raw):
    """The bytes as a quoted string, when they are printable ASCII ended by a
    NUL with only zero padding after it."""
    end = raw.find(b"\0")
    if end <= 0 or any(raw[end:]):
        return None
    text = raw[:end]
    if not all(32 <= b < 127 or b in (9, 10, 13) for b in text):
        return None
    s = text.decode("ascii")
    if len(s) > 80:
        s = s[:77] + "..."
    return json.dumps(s)


def agrees(sym, target):
    """Whether a completed address fits the symbol its relocation names: near
    a named symbol (an index can reach a little outside it), or at or after
    a section symbol's start."""
    if sym is None or not sym["name"]:
        return True
    if sym["type"] == STT_SECTION:
        return target >= sym["value"]
    return -0x1000 <= target - sym["value"] <= max(sym["size"], 4) + 0x1000


class Analysis:
    def __init__(self, world):
        self.world = world
        self.elf = world.elf
        self.calls = defaultdict(dict)       # caller start -> {callee start: kind}
        self.callers = defaultdict(dict)     # callee start -> {caller start: kind}
        self.data_callers = defaultdict(dict)  # callee start -> {(name, start): offset}
        self.data = defaultdict(dict)        # function start -> {name: entry}
        self.stats = Counter()
        self.unresolved = Counter()
        self.unresolved_examples = defaultdict(list)
        self.game_relocations = 0

    def note_unresolved(self, reason, address):
        self.unresolved[reason] += 1
        if len(self.unresolved_examples[reason]) < 5:
            self.unresolved_examples[reason].append(hex8(address))

    def run(self):
        by_function = defaultdict(list)
        for offset, kind, sym in self.elf.relocations:
            section = layout.section_of(offset)
            if section in CODE:
                f = self.world.function_at(offset)
                if f is not None and f[4]:
                    self.game_relocations += 1
                if f is None:
                    self.stats["code relocation outside any function"] += 1
                    continue
                by_function[f[0]].append((offset, kind, sym))
            elif kind == R_MIPS_32:
                self.data_word(offset)
        for start, rels in by_function.items():
            self.function(self.world.function_at(start), sorted(rels))

    def data_word(self, offset):
        target = self.elf.word(offset)
        f = self.world.function_at(target)
        if f is None or f[0] != target or not f[4]:
            return
        listed = self.world.index.by_name
        lo, hi = listed["__static_init"][0], listed["__static_init_end"][0]
        if lo <= offset < hi:
            name, start = "__static_init", lo
        else:
            name, start = self.world.data_symbol(offset)
        self.data_callers[target].setdefault((name, start), offset - start)

    def edge(self, caller, callee_start, kind):
        caller_start = caller[0]
        known = self.calls[caller_start].get(callee_start)
        if known is None or (known == "address" and kind == "call"):
            # A function both called and address-taken is a call.
            self.calls[caller_start][callee_start] = kind if known is None else "call"
        prev = self.callers[callee_start].get(caller_start)
        self.callers[callee_start][caller_start] = "call" if "call" in (prev, kind) else kind

    def function(self, func, rels):
        start, end, name, unit, game = func
        elf = self.elf
        his = [(o, s, (elf.word(o) >> 16) & 0x1F) for o, k, s in rels if k == R_MIPS_HI16]
        paired = set()
        for offset, kind, sym_index in rels:
            sym = elf.symbols[sym_index] if sym_index else None
            word = elf.word(offset)
            if kind == R_MIPS_26:
                target = ((offset + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
                callee = self.world.function_at(target)
                if callee is None:
                    if game:
                        self.note_unresolved("R_MIPS_26 to no function", offset)
                    continue
                if callee[0] != target and game:
                    self.stats["R_MIPS_26 into the middle of a function"] += 1
                self.edge(func, callee[0], "call")
                if game:
                    self.stats["R_MIPS_26 calls"] += 1
            elif kind == R_MIPS_HI16:
                continue
            elif kind == R_MIPS_LO16:
                base = (word >> 21) & 0x1F
                hi = self.pair(offset, word, sym_index, base, his)
                if hi is None:
                    if game:
                        self.note_unresolved("LO16 without a HI16", offset)
                    continue
                paired.add(hi)
                target = ((elf.word(hi) & 0xFFFF) << 16) + sext16(word)
                target &= 0xFFFFFFFF
                self.target(func, offset, word, target, sym)
            elif kind == R_MIPS_GPREL16:
                target = (GP + sext16(word)) & 0xFFFFFFFF
                if (word >> 21) & 0x1F != 28 and game:
                    self.stats["GPREL16 not based on $gp"] += 1
                self.target(func, offset, word, target, sym)
            else:
                if game:
                    self.note_unresolved(f"relocation type {kind} in code", offset)
        if game:
            # A HI16 no LO16 was paired with is still accounted for when one
            # that was loads the same register with the same value against the
            # same symbol: the two are alternatives on different paths.
            values = {(s, r, elf.word(o) & 0xFFFF) for o, s, r in his if o in paired}
            for o, s, r in his:
                if o in paired:
                    self.stats["HI16 paired"] += 1
                elif (s, r, elf.word(o) & 0xFFFF) in values:
                    self.stats["HI16 equivalent to a paired one"] += 1
                else:
                    self.note_unresolved("HI16 with no LO16", o)

    def pair(self, offset, word, sym_index, base, his):
        """The HI16 this LO16 completes.

        Candidates are taken in order: those loading the LO16's base register
        against the same symbol, nearest before it and then nearest after it
        (a `lui` in a branch's delay slot can sit after the code it feeds);
        then those loading the register against any symbol, nearest before.
        The first whose completed address agrees with a named relocation
        symbol is taken, else the first candidate.
        """
        def nearest(found):
            before = [h for h in found if h[0] < offset]
            after = [h for h in found if h[0] > offset]
            return before[::-1] + after

        same = [h for h in his if h[2] == base and h[1] == sym_index]
        register = [h for h in his if h[2] == base and h[1] != sym_index and h[0] < offset]
        candidates = nearest(same) + register[::-1]
        if not candidates:
            return None
        sym = self.elf.symbols[sym_index]
        for h in candidates:
            target = (((self.elf.word(h[0]) & 0xFFFF) << 16) + sext16(word)) & 0xFFFFFFFF
            if agrees(sym, target):
                if h[0] > offset:
                    self.stats["LO16 paired with a later HI16"] += 1
                return h[0]
        self.stats["LO16 paired with no agreeing HI16"] += 1
        return candidates[0][0]

    def target(self, func, offset, word, target, sym):
        world = self.world
        game = func[4]
        if game and not agrees(sym, target):
            self.stats["target disagreeing with its relocation's symbol"] += 1
        section = layout.section_of(target)
        if section in CODE:
            callee = world.function_at(target)
            if callee is None:
                if game:
                    self.note_unresolved("address of code in no function", offset)
                return
            self.edge(func, callee[0], "address")
            if game:
                self.stats["function addresses taken"] += 1
            return
        if not game:
            return
        if section is None:
            self.note_unresolved("target outside the image", offset)
            return
        name, start = world.data_symbol(target, sym)
        opcode = word >> 26
        if opcode in LOADS:
            access, how = "read", LOADS[opcode]
        elif opcode in STORES:
            access, how = "write", STORES[opcode]
        elif opcode in ADDRESS:
            access, how = "address", ADDRESS[opcode]
        else:
            access, how = None, None
        entries = self.data[func[0]]
        entry = entries.get(name)
        if entry is None:
            entry = entries[name] = {"name": name, "address": hex8(start),
                                     "section": layout.section_of(start),
                                     "_access": [], "_unknown": False,
                                     "_how": set(), "_offsets": []}
            size = world.symbol_size(name, start)
            if size:
                entry["size"] = f"{size:X}"
            unit = world.unit_of(start)
            if unit:
                entry["unit"] = unit
            demangled = world.demangled(name)
            if demangled:
                entry["demangled"] = demangled
        if access is None:
            entry["_unknown"] = True
        elif access not in entry["_access"]:
            entry["_access"].append(access)
        if how in ("lwc1", "swc1"):
            entry["_how"].add("float")
        elif how in ("lw", "sw"):
            entry["_how"].add("int")
        off = target - start
        if off not in entry["_offsets"]:
            entry["_offsets"].append(off)
        self.stats["data references"] += 1


# --------------------------------------------------------------------------
# Output
# --------------------------------------------------------------------------

def read_manifest(path):
    rows = []
    for line in Path(path).read_text().splitlines():
        if not line.strip():
            continue
        unit, symbol, address, size, section, assembly = line.split("\t")
        rows.append(dict(unit=unit, symbol=symbol, address=int(address, 16),
                         size=int(size, 16), section=section, assembly=assembly))
    return rows


def function_ref(world, start, kind=None):
    f = world.function_at(start)
    out = {"name": f[2], "address": hex8(start), "unit": f[3]}
    demangled = world.demangled(f[2])
    if demangled:
        out["demangled"] = demangled
    if kind and kind != "call":
        out["kind"] = kind
    return out


def finish_data(world, entry):
    out = {k: v for k, v in entry.items() if not k.startswith("_")}
    offsets = entry["_offsets"]
    if any(offsets):
        out["offsets"] = [f"{o:X}" if o >= 0 else f"-{-o:X}" for o in offsets]
    # Every use is listed only when every instruction's use is known.
    if entry["_access"] and not entry["_unknown"]:
        out["access"] = entry["_access"]
    start = int(entry["address"], 16)
    size = world.size.get(entry["name"]) or world.symbol_size(entry["name"], start)
    how = entry["_how"] if len(entry["_how"]) == 1 else set()
    value = preview(world, entry["name"], start, size, how) if size else None
    if value is not None:
        out["value"] = value
    return out


def build(world, analysis, units):
    demangle_stats = Counter()
    failed = []
    out = {}
    for row in world.manifest:
        if units and row["unit"] not in units:
            continue
        start = row["address"]
        entry = {"address": hex8(start), "size": f"{row['size']:X}", "section": row["section"]}
        original = world.original.get(row["symbol"])
        demangled = demangle(original) if original else None
        if demangled:
            entry["demangled"] = demangled
            demangle_stats["ok"] += 1
        elif original and "__" in original[1:] and not original.startswith("__sinit_"):
            demangle_stats["failed"] += 1
            failed.append(original)
        else:
            demangle_stats["plain"] += 1
        entry["calls"] = [function_ref(world, s, k) for s, k in analysis.calls[start].items()]
        callers = [function_ref(world, s, k) for s, k in sorted(analysis.callers[start].items())]
        for (name, dstart), offset in sorted(analysis.data_callers[start].items(),
                                             key=lambda kv: kv[0][1]):
            ref = {"name": name, "address": hex8(dstart), "kind": "data",
                   "section": layout.section_of(dstart)}
            if offset:
                ref["offset"] = f"{offset:X}"
            unit = world.unit_of(dstart + offset)
            if unit:
                ref["unit"] = unit
            callers.append(ref)
        entry["callers"] = callers
        entry["data"] = [finish_data(world, e) for e in analysis.data[start].values()]
        out.setdefault(row["unit"], {})[row["symbol"]] = entry
    return out, demangle_stats, failed


def compare_with_elf(world):
    """How the manifest's functions line up with retail's FUNC symbols."""
    game_code = [(lo, hi) for (unit, section), (lo, hi) in world.layout.ranges.items()
                 if section in CODE and world.layout.kinds.get(unit) == "cpp"]
    manifest = {r["address"]: r["symbol"] for r in world.manifest}
    funcs = [s for s in world.elf.symbols if s["type"] == 2
             and any(lo <= s["value"] < hi for lo, hi in game_code)]
    at = defaultdict(list)
    for s in funcs:
        at[s["value"]].append(s)
    missing = sorted(a for a in at if a not in manifest)
    aliases = [(a, [s["name"] for s in ss]) for a, ss in sorted(at.items()) if len(ss) > 1]
    not_func = sorted(a for a in manifest if a not in at)
    print(f"retail FUNC symbols in game code: {len(funcs)} at {len(at)} addresses")
    print(f"  FUNC addresses the manifest lacks: {len(missing)}"
          + "".join(f"\n    {hex8(a)} {[s['name'] for s in at[a]]}" for a in missing[:5]))
    print(f"  addresses holding more than one FUNC symbol: {len(aliases)}"
          + "".join(f"\n    {hex8(a)} {n}" for a, n in aliases[:3]))
    print(f"  manifest rows with no FUNC symbol: {len(not_func)}"
          + "".join(f"\n    {hex8(a)} {manifest[a]}" for a in not_func[:5]))
    glabels = jlabels = 0
    for unit in world.layout.units("cpp"):
        section = ".text"
        for line in (ROOT / world.layout.reference(unit)).read_text().splitlines():
            m = disassemble.SECTION_LINE.match(line)
            if m:
                section = m.group(1)
            elif section in CODE:
                stripped = line.strip()
                glabels += stripped.startswith("glabel ")
                jlabels += stripped.startswith("jlabel ")
    print(f"  game reference objects' code labels: {glabels} glabel + {jlabels} jlabel"
          f" (jump-table targets) = {glabels + jlabels}")


def self_check(world, analysis, out, units):
    problems = []
    seen = Counter()
    for unit, funcs in out.items():
        for name in funcs:
            seen[name, unit] += 1
    for row in world.manifest:
        if units and row["unit"] not in units:
            continue
        if seen[row["symbol"], row["unit"]] != 1:
            problems.append(f"{row['symbol']} appears {seen[row['symbol'], row['unit']]} times")
    stats = analysis.stats
    accounted = (stats["R_MIPS_26 calls"] + stats["HI16 paired"]
                 + stats["HI16 equivalent to a paired one"] + stats["data references"]
                 + stats["function addresses taken"] + sum(analysis.unresolved.values()))
    if not units and accounted != analysis.game_relocations:
        problems.append(f"{analysis.game_relocations} relocations in game functions,"
                        f" {accounted} accounted for")
    for caller, callees in analysis.calls.items():
        for callee in callees:
            if caller not in analysis.callers[callee]:
                problems.append(f"{hex8(caller)} -> {hex8(callee)} has no caller entry")
    for callee, callers in analysis.callers.items():
        for caller in callers:
            if callee not in analysis.calls[caller]:
                problems.append(f"{hex8(caller)} -> {hex8(callee)} has no call entry")
    return problems


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-m", "--manifest", default="build/re/manifest.tsv")
    ap.add_argument("-o", "--output", default="build/re/symbols")
    ap.add_argument("units", nargs="*", help="game units to write (default: all)")
    args = ap.parse_args()
    os.chdir(ROOT)

    world = World(read_manifest(args.manifest))
    analysis = Analysis(world)
    analysis.run()
    units = set(args.units)
    out, demangle_stats, failed = build(world, analysis, units)

    directory = Path(args.output)
    for unit, funcs in out.items():
        path = directory / f"{unit}.json"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps({"unit": unit, "functions": funcs}, indent=1) + "\n")

    nfuncs = sum(len(f) for f in out.values())
    edges = sum(len(e["calls"]) for f in out.values() for e in f.values())
    drefs = sum(len(e["data"]) for f in out.values() for e in f.values())
    print(f"wrote {len(out)} units, {nfuncs} functions to {directory}")
    print(f"call edges: {edges}; data symbols referenced: {drefs}")
    for key, value in sorted(analysis.stats.items()):
        print(f"  {key}: {value}")
    print(f"relocations in game functions: {analysis.game_relocations}")
    print(f"unresolved relocations in game functions: {sum(analysis.unresolved.values())}")
    for reason, count in analysis.unresolved.most_common():
        print(f"  {reason}: {count} (e.g. {', '.join(analysis.unresolved_examples[reason])})")
    print(f"demangled: {demangle_stats['ok']} ok, {demangle_stats['failed']} failed,"
          f" {demangle_stats['plain']} not mangled"
          + (f" (failed e.g. {', '.join(failed[:5])})" if failed else ""))
    compare_with_elf(world)
    problems = self_check(world, analysis, out, units)
    for p in problems[:20]:
        print("CHECK:", p)
    print(f"self-check: {'ok' if not problems else f'{len(problems)} problems'}")
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
