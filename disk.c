#include "headers/io.h"
#include "headers/disk.h"

void write_sector(unsigned int lba, unsigned char* buffer){
  while (inb(0x1f7) & 0x80); // wait until its not busy
  while(!(inb(0x1f7)&0x08)); // wait until the disk port is ready
  outb(0x1f6, 0x0E | ((lba >> 24) & 0x0F));
  outb(0x1f2, 1);
  outb(0x1f3, lba & 0xFF);
  outb(0x1f4, (lba>>8) & 0xFF);
  outb(0x1f5, (lba>>16) & 0xFF);
  outb(0x1f7, 0x30);

  while (inb(0x1F7) & 0x80);
  while (!(inb(0x1F7) & 0x08));
  
  for(int i=0;i<256;i++){
    unsigned int word = buffer[i*2] | (buffer[i*2+1] << 8);
    outw(0x1f0, word);
  }
}
