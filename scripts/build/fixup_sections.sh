#!/bin/sh
# Prepare an object for MWLD, in a single objcopy pass.
#
#     fixup_sections.sh <object> [objcopy arguments...]
#
# 1. Strips zero-sized sections. GNU as always emits .text, .data and .bss
#    headers, even for a file that never puts anything in them, and splat's
#    whole-unit files name every section a unit could own; MWLD rejects any
#    zero-sized input section.
# 2. Restores the functions MWCC marked for the linker to keep one copy of.
#    Their symbols are global in what the compiler wrote, but it places them
#    among the locals, and every objcopy pass rebuilds the table from sh_info
#    and demotes them; a local copy is a second definition MWLD lays out in
#    full. postprocess_object.py leaves their names beside the object, in
#    <object>.coal.
# 3. Applies any extra objcopy arguments given after the object, such as
#    `--set-section-alignment .text=8`: the linker script places every input
#    section on the alignment its object states (see the comment at the top
#    of ps2/config/pal/SCES_511.90.lcf), so an object must never ask for more
#    than its retail address has.
#
# This runs once per object, so it stays at two processes: one readelf, one
# objcopy, and the objcopy only when there is something to do.

# The binutils-mips-ps2-decompals tools. Override MIPS_TOOL_PREFIX in the
# environment for a differently-named build of them.
: "${MIPS_TOOL_PREFIX:=mips-ps2-decompals-}"

obj="$1"
shift

# Every section MWLD lays out that came out empty. objcopy removes sections
# by name, and a compiled object has one section per function or datum under
# the same few names, so a name is only removed when every section bearing
# it is empty.
remove=$("${MIPS_TOOL_PREFIX}readelf" -SW "$obj" | awk '
  { sub(/^ *\[[ 0-9]+\] +/, "") }
  $2 == "PROGBITS" || $2 == "NOBITS" {
      if ($5 ~ /^0+$/) { if (!($1 in full)) empty[$1] = 1 }
      else { full[$1] = 1; delete empty[$1] }
  }
  END { for (name in empty) printf "--remove-section=%s ", name }')

coal=""
[ -s "$obj.coal" ] && coal="--globalize-symbols=$obj.coal"

if [ -n "$remove" ] || [ -n "$coal" ] || [ "$#" -gt 0 ]; then
  "${MIPS_TOOL_PREFIX}objcopy" -I elf32-littlemips -O elf32-littlemips \
    $remove $coal "$@" "$obj"
fi
