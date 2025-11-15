#ifndef PERSON_ITEMS_H
#define PERSON_ITEMS_H
#include "dungeon_logic.h"
//оружие
int weapon_replace(const char *name, int param, items *weapon, int* class);

 
//броня
int armour_replace(int place, const char *name, int param, items *armour);


//инвентарь
int open_inventory(items *inventory, items *armour, items *weapon, Parametrs *player);
int add_to_inv(const char *name, int param_ammount, items *inventory, items *armour, items *weapon, Parametrs *player);
#endif