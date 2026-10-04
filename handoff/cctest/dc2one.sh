#!/bin/sh
# dc2one.sh <compiler> : compile dc2/*.cpp with flag sets from dc2/flags.txt for one compiler
cd /w/build/cctest/dc2
for n in "$@"; do
d=/w/tools/compilers/mw/$n; cc=$(ls $d | grep -i mwcc)
while IFS="$(printf '\t')" read fs flags; do
  out=/w/build/cctest/out2/$n/$fs; mkdir -p $out
  for src in *.cpp; do b=$(basename $src .cpp); eval "wibo $d/$cc $flags -c -o $out/$b.o $src" >$out/$b.log 2>&1; done
done < flags.txt
done
