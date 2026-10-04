#!/bin/sh
# one.sh <compiler> <flagset> <src>
n=$1; fs=$2; src=$3
d=/w/tools/compilers/mw/$n; cc=$(ls $d | grep -i mwcc)
out=/w/build/cctest/out/$n/$fs; b=$(basename $src .cpp)
eval "wibo $d/$cc $FLAGS -i include/ps2 -c -o $out/$b.o $src" >$out/$b.log 2>&1
