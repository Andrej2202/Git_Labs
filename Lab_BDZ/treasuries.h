#ifndef TREASURIES_H
#define TREASURIES_H
#include "dungeon_logic.h"
typedef struct {
    char name[27];
    int  class, param;
    
} treasure;

int give_treasuries(int *item_count, items *inventory, items *armour, items *weapon, Parametrs *player);
#endif