#include "headers/screen.h"
#include "headers/io.h"
extern int cursor;
void clear_screen(){ 
  for(int i=0; i<80*25;i++){
    vga[i] = 0x00;
  }
  cursor = 0;
}
