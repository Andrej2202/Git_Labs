#ifndef SAVING_H
#define SAVING_H
#include "dungeon_logic.h"

int save_to_file(int dungeon, int item_count, items *inventory, items *armour, items *weapon, Parametrs *player); 
int read_file(int file_num, int* cur_dungeon, int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player);

#endif