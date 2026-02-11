.section .multiboot
.align 4
.long 0x1badb002
.long 0x0
.long -(0x1badb002 + 0x0)

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.global _start
.text
_start:
    mov $stack_top, %esp
    call kernel_main
    jmp .
