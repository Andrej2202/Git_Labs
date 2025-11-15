#ifndef SAVING_H
#define SAVING_H
#include "dungeon_logic.h"

int save_to_file(int dungeon, items *inventory, items *armour, items *weapon, Parametrs *player); 
int read_file(int* cur_dungeon, items *inventory, items *armour, items *weapon, Parametrs *player);

#endif