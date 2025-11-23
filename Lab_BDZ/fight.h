#ifndef FIGHT_H
#define FIGHT_H
#include "dungeon_logic.h"

int fight(int lvl, items *inventory, items *armour, items *weapon, Parametrs *player); 

int boss_fight(int lvl, items *inventory, items *armour, items *weapon, Parametrs *player);
#endif