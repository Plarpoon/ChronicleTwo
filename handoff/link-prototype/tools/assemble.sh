#!/bin/sh
# Run inside dcdecomp_dev from the repo root: assemble every prototype object.
set -e
J=build/pal-link/tools
CPP_ARGS="--set-section-alignment .text=16 --set-section-alignment .init=16"
for s in data rodata ctor vtables sdata sbss bss; do CPP_ARGS="$CPP_ARGS --set-section-alignment .$s=1"; done
export CPP_ARGS ASM_ARGS DATA_ARGS
python3 "$J/jobs.py" > /tmp/jobs.txt
tr '\t' ' ' < /tmp/jobs.txt | xargs -P 8 -n 3 sh -c '
  src="$0"; obj="$1"; kind="$2"
  mkdir -p "$(dirname "$obj")"
  mips-ps2-decompals-as -EL -march=r5900 -mabi=eabi -mno-pdr -non_shared -G0 -I ps2/include -o "$obj" "$src" || exit 255
  case "$kind" in
    cpp) sh scripts/build/fixup_sections.sh "$obj" $CPP_ARGS ;;
    asm) sh scripts/build/fixup_sections.sh "$obj" $ASM_ARGS ;;
    data) sh scripts/build/fixup_sections.sh "$obj" $DATA_ARGS ;;
  esac'
