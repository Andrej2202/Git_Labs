#ifndef PERSON_ITEMS_H
#define PERSON_ITEMS_H
#include "dungeon_logic.h"
//оружие
int weapon_show(items *weapon);
int weapon_replace(const char *name, int param, items *weapon);

 
//броня
int armour_show(items* armour);
int armour_replace(int place, const char *name, int param, items *armour);


//инвентарь
int open_inventory(int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player);
int add_to_inv(const char *name, int param_ammount, int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player);
#endif