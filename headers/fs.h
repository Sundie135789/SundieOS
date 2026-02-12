#ifndef FAT_H
#define FAT_H

void read_sector(int lba, void* buffer);
void write_sector( int lba, void* buffer);
void init_fat(void);

#endif
