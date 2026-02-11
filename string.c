#include "headers/string.h"
int strlen(char* string){
  int size = 0;  
  while(1){
    if(string[size] == '\0'){
      break;
    }
    size++;
  }
  return size;
}
int strcmp(char* first, char* second){
  if(strlen(first) != strlen(second)){
    return 1;
  }else{
    for(int i=0; i<strlen(first);i++){
      if(first[i] != second[i]){
        return 1;
      }
    }
    return 0;
  } 
}
int strprefix(char* string, char* prefix){
  int size = strlen(prefix);
  for(int i=0; i<size;i++){
    if(string[i] != prefix[i]){
      return 1;
    }
  }
  return 0;
}
void strcpy(char* dest, char* src){
  int i;
  for(i = 0; src[i] != '\0'; i++){
    dest[i] = src[i];
  }
  dest[i] = '\0';
}



