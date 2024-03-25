#!/bin/sh

source /usr/local/cell/ps3toolchain.sh

FLAGS="-I/usr/local/cell/target/ppu/include -Ilib/cpython/Include -Ilib/cpython -Isrc"
LD_FLAGS="-L./lib -lc -lpython3.6m -lm -lfs_stub -ffunction-sections -fdata-sections -zgc-sections -Wl,--strip-unused-data"

ppu-lv2-gcc $FLAGS -c src/main.c -o src/main.o
ppu-lv2-gcc $FLAGS -c src/print.c -o src/print.o

#ppu-lv2-gcc -mprx -L./lib -lc -lm -o src/crackman.prx src/main.o -ffunction-sections -fdata-sections -zgc-sections -Wl,--strip-unused-data && \
#smake_fself.exe src/crackman.prx bin/crackman.sprx
ppu-lv2-gcc $LD_FLAGS -o src/crackman.elf src/main.o src/print.o
make_fself.exe src/crackman.elf bin/crackman.self
