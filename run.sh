#!/bin/bash

as --32 boot.s -o boot.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c kernel.c -o kernel.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c io.c -o io.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c string.c -o string.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c shell.c -o shell.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c screen.c -o screen.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c fat.c -o fat.o
gcc -m32 -ffreestanding -fno-pie -O0 -fno-stack-protector -c disk.c -o disk.o

ld -m elf_i386 -T linker.ld -o kernel.elf boot.o fat.o io.o string.o shell.o screen.o kernel.o disk.o
cp kernel.elf iso/boot/kernel.elf
grub-mkrescue -o os.iso iso
qemu-system-i386 -cdrom os.iso
#if [ ! -f disk.img ]; then
 # dd if=/dev/zero of=disk.img bs=1M count=20
#fi

#qemu-system-i386 -boot d -cdrom os.iso -drive file=disk.img,format=raw,if=ide

