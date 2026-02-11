#ifndef IO_H
#define IO_H
extern volatile unsigned short* vga;
static const char keymap[128];
 void outb(unsigned short port, unsigned char val);
 unsigned char inb(unsigned short port);
  void outw(unsigned short port,unsigned short val);
void putchar(char c, unsigned char color);
void print(const char* str, unsigned char color);
 char readchar(void);
void readstring(char* buf, int max_len);
#endif
