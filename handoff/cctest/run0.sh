cd /w/build/cctest
for d in /w/tools/compilers/mw/*; do
  n=$(basename $d); cc=$(ls $d | grep -i mwcc)
  rm -f t0.o
  wibo $d/$cc -O2 -c -Cpp_exceptions off -RTTI off -o t0.o t0.cpp >out_$n.txt 2>&1
  if [ -f t0.o ]; then
    secs=$(mips-ps2-decompals-objdump -h t0.o | awk '/^ +[0-9]+ /{printf "%s ",$2}')
    com=$(mips-ps2-decompals-objcopy -O binary -j .comment t0.o /dev/stdout 2>/dev/null | tr -d '\0')
    echo "$n | $com | $secs"
  else echo "$n | FAILED: $(head -3 out_$n.txt | tr '\n' ' ')"; fi
done
