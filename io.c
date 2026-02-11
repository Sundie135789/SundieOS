#include "headers/io.h"
static const char keymap[128] = {
    0,   27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0,   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0,   '\\','z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
    '*', 0,   ' ', 0
};

  void outb(unsigned short port, unsigned char val){
  __asm__ __volatile__("outb %0, %1" : : "a"(val), "Nd"(port));
}
  unsigned char inb(unsigned short port){
  unsigned char ret;
  __asm__ __volatile__("inb %1, %0" :  "=a"(ret) : "Nd"(port));
  return ret;
}
   void outw(unsigned short port, unsigned short val){
  __asm__ __volatile__("outw %0, %1" : : "a"(val), "Nd"(port));
}
volatile unsigned short* vga = (volatile unsigned short*)0xB8000;
int cursor = 0;
void putchar(char c, unsigned char color) {
    if (c == '\n') {
        cursor += 80 - (cursor % 80);
    } else {
        vga[cursor] = ((unsigned short)color << 8) | c;
        cursor++;
    }
}

void print(const char* str, unsigned char color) {
    int i = 0;
    while (str[i] != 0) {
        putchar(str[i], color);
        i++;
    }
}

char readchar() {
  while(!(inb(0x64) & 0x01));
  unsigned char scancode = inb(0x60);
  if(scancode > 127)return 0; 
  return keymap[scancode];
}
void readstring(char *buf, int max_len){
  int i=0;
  while(1){
    char c = readchar();  
    if (c == '\n' || c == '\r'){
      buf[i] = '\0';
      putchar('\n',0x0F);
      break;
    }
    if (i < max_len - 1){
      buf[i++] = c;
      putchar(c, 0x0F);
    }
  }
  buf[i] = '\0';
}
