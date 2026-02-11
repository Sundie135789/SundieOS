#include "headers/fat.h"
#include "headers/io.h"
#include "headers/string.h"
#include "headers/disk.h"
unsigned int clusters[cluster_count];
char data[cluster_count][cluster_size];
int numFiles = 0;
FileEntry root[max_files];

void init_fat(){
  for(int i=0;i<cluster_count;i++) clusters[i] = 0;
  for(int i=0;i<max_files;i++) root[i].used = 0;
}
int find_space(){
  int i;
  for(i=0; i<max_files;i++){
    if(!root[i].used) break;
  }  
  if (i == max_files) return 1;
  return i;
}
void create_file(char* fileName){
  int index = find_space();
  if(index == 1){
    print("Error: Not enough space on the disk. ", 0x04);
    return;
  }
  numFiles++;
  strcpy(root[index].name,fileName);
  root[index].firstCluster = 100 * numFiles;
  root[index].size = 0; 
  root[index].used = 1;
  unsigned char empty[512];
  for(int i = 0; i < 512; i++) empty[i] = 0;
  write_sector(100*numFiles, empty);
}
/*
typedef struct {
  char name[12];
  unsigned int firstCluster, size;
  int used;
} FileEntry;*/
