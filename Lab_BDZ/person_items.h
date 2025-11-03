#ifndef PERSON_ITEMS_H
#define PERSON_ITEMS_H
#include "dungeon_logic.h"
//оружие
void weapon_show(items *weapon);
void weapon_replace(const char *name, int param, items *weapon);

 
//броня
void armour_show(items* armour);
void armour_replace(int place, const char *name, int param, items *armour);


//инвентарь
void open_inventory(int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player);
void add_to_inv(const char *name, int param_ammount, int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player);
#endif