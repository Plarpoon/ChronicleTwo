#!/bin/sh
# dis.sh <compiler/flagset> <obj> <func>...
o=/w/build/cctest/out2/$1/$2.o; shift; shift
for f in "$@"; do mips-ps2-decompals-objdump -d -z $o | awk "/<$f>:/{p=1} p{print} p&&/^\$/{exit}" | cut -f1,3- ; done
