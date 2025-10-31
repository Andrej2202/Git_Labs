#ifndef SAVING_H
#define SAVING_H

int save_to_file(int dungeon, int item_count);
int read_file(int file_num, int* cur_dungeon, int* item_count);

#endif