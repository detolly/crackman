#!/bin/sh

source /usr/local/cell/ps3toolchain.sh

ppu-lv2-gcc -I/usr/local/cell/target/ppu/include -Ilib/cpython/Include -Ilib/cpython -c src/main.c -o src/main.o
#ppu-lv2-gcc -mprx -L./lib -lc -lm -o src/crackman.prx src/main.o -ffunction-sections -fdata-sections -zgc-sections -Wl,--strip-unused-data && \
#smake_fself.exe src/crackman.prx bin/crackman.sprx
ppu-lv2-gcc -L./lib -lc -lpython3.6m -lm -lfs_stub -o src/crackman.elf src/main.o -ffunction-sections -fdata-sections -zgc-sections -Wl,--strip-unused-data
make_fself.exe src/crackman.elf bin/crackman.self
