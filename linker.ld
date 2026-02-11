ENTRY(_start)

SECTIONS {
  . = 1M;
  .text : {
    *(.multiboot)
    *(.text*)
  }
  .rodata : { *(.rodata*) }
  .data : { *(.data*) }
  .bss  : { *(.bss*) }
  kernel_start = 1M;
  kernel_end = .;
}

