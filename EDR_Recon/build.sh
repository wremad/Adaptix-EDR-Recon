#!/bin/bash

mkdir -p build

x86_64-w64-mingw32-gcc \
-c src/entry.c \
-o build/entry.x64.o \
-Iinclude \
-masm=intel

i686-w64-mingw32-gcc \
-c src/entry.c \
-o build/entry.x86.o \
-Iinclude \
-masm=intel

echo "[+] Build completed"
