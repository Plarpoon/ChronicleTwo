#!/bin/sh
# Run inside dcdecomp_dev from the repo root: link the prototype.
LD=${LD:-tools/compilers/mw/3.0b38-030307/mwldps2.exe}
FLAGS=${FLAGS:--map -nostdlib -m ENTRYPOINT -nodead -g}
python3 scripts/build/lcf.py -o build/pal-link/SCES_511.90.lcf || exit 1
wibo $LD $FLAGS -o build/pal-link/SCES_511.90 build/pal-link/SCES_511.90.lcf @build/pal-link/main_o_files
