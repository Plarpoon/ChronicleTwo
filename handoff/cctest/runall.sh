#!/bin/sh
# usage: runall.sh <flagset-name> <compiler...>   ; FLAGS, SRCS in env
cd /dc1
export MWCIncludes='include/ps2/std;include/ps2/sce'
fs=$1; shift
for n in "$@"; do
  mkdir -p /w/build/cctest/out/$n/$fs
  for src in ${SRCS:-src/ps2/*.cpp}; do echo "$n $fs $src"; done
done | xargs -P 6 -L 1 sh /w/build/cctest/one.sh
for n in "$@"; do echo "$n/$fs: $(ls /w/build/cctest/out/$n/$fs/*.o 2>/dev/null | wc -l) objects"; done
