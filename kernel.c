extern char kernel_start[];
extern char kernel_end[];
#define max_cmd_len 32
#include "headers/io.h"
#include "headers/shell.h"
#include "headers/screen.h"
#include "headers/fat.h"
// problem is in create_file. diagnose
void delay(unsigned int ms){
  volatile unsigned int i;
  for(i =0; i<ms;i++){
    __asm__ __volatile__("nop");
  }
}
void uitoa(unsigned int value, char* str){
char buf[12];
int i =0;
if (value == 0){
  str[0] = '0';
  str[1] = 0;
  return;
}
while(value >0){
buf[i++] = '0' + (value % 10);
value /= 10;
}

int j;
for(j=0;j<i;j++){
  str[j] = buf[i-j-1];
}
str[i] = 0;
}
unsigned int kernel_size(){
  return (unsigned int)(kernel_end-kernel_start);
}
void kernel_main(void){
// init_fat();
 // create_file("test.txt");
  clear_screen();
  print("SundieOS v1.0\n", 0x0F);
  print("CPU: Intel i5-13400F\n", 0x09); 
  unsigned int size = kernel_size();
  char buf[12];
  uitoa(size, buf);
  print("Kernel Size: ", 0x09);
  print(buf, 0x09);
  print(" bytes\n", 0x09); 
  print("Loading shell...", 0x0A);
  delay(500000000);
  clear_screen();
  load_shell();
  while (1) {
    __asm__ volatile("hlt");
  }

}
