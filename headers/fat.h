#ifndef FAT_H
#define FAT_H

#define cluster_count 128
#define cluster_size 512
#define max_files 16

typedef struct {
  char name[12];
  unsigned int firstCluster, size;
  int used;
} FileEntry;
extern unsigned int clusters[cluster_count];
extern char data[cluster_count][cluster_size];
extern int numFiles;
extern FileEntry root[max_files];
void init_fat();
int find_space();
void create_file(char* fileName);
#endif

