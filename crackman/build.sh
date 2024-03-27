#!/bin/sh

source /usr/local/cell/ps3toolchain.sh

FLAGS="-I/usr/local/cell/target/ppu/include -Ilib/cpython/Include -Ilib/cpython -Isrc"
LD_FLAGS="-L./lib -L/usr/local/cell/target/ppu/lib -lc -lm -lpython3.6m -lfs_stub -ffunction-sections -fdata-sections -zgc-sections -Wl,--strip-unused-data"

ppu-lv2-gcc $FLAGS -c src/main.c -o src/main.o
ppu-lv2-gcc $FLAGS -c src/print.c -o src/print.o

ppu-lv2-gcc $LD_FLAGS -mprx -o src/crackman.prx src/main.o src/print.o && \
make_fself.exe src/crackman.prx bin/crackman.sprx
# ppu-lv2-gcc $LD_FLAGS -o src/crackman.elf src/main.o src/print.o
# make_fself.exe src/crackman.elf bin/crackman.self
