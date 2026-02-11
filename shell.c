#include "headers/shell.h"
#include "headers/string.h"
#include "headers/screen.h"
#include "headers/io.h"
#include "headers/fat.h"
int newline = 1;
void load_shell(){
  const char *path = "Home >";
  char inputBuffer[32];
  while(1){
    print(path, 0x0F);  
    readstring(inputBuffer, 32);   
    runCommand(inputBuffer);
    if(newline == 1) putchar('\n', 0x00);
    newline = 1;
  }
}
void runCommand(char* command){
  if(strcmp(command, "clear") == 0){
    newline = 0;
    clear_screen();
  }else if(strprefix(command, "echo") == 0){
    char output[32];
    int j = 0;
    for(int i=5;i<strlen(command) && j < sizeof(output)-1;i++){
      output[j++] = command[i];
    }
    output[j]  = '\0';
    print(output, 0x0F);
  } 
  else if(strcmp(command, "ls")==0){
    for(int i=0; i<numFiles;i++){
      print(root[i].name, 0x09);
      print(" ", 0x00);
    }
  }
  else{
    print("Invalid command", 0x0F);
  }
}
