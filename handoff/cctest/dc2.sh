#!/bin/sh
# dc2.sh : compile every dc2/*.cpp with every compiler x flagset listed in dc2/flags.txt (name<TAB>flags)
cd /w/build/cctest/dc2
for d in /w/tools/compilers/mw/*; do
  n=$(basename $d); cc=$(ls $d | grep -i mwcc)
  while IFS="$(printf '\t')" read fs flags; do
    out=/w/build/cctest/out2/$n/$fs; mkdir -p $out
    for src in *.cpp; do
      b=$(basename $src .cpp)
      eval "wibo $d/$cc $flags -c -o $out/$b.o $src" >$out/$b.log 2>&1
    done
  done < flags.txt
done
echo done
