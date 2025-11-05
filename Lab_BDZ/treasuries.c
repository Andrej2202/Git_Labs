#include <stdlib.h>
#include <stdio.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include "person_items.h"
#include "text_blocks.h"

int give_treasuries(int *item_count, items *inventory, items *armour, items *weapon, Parametrs *player){
    treasure possible[6] = { // 0 - 2 - зашита, 3 - оружие, 4 - предметы
        {"Ultra Pro Kiber MAX Шлем", 0, 20},
        {"Ultra Pro Kiber MAX Кираса", 1, 50},
        {"Ultra Pro Kiber MAX Поножи", 2, 10},
        {"Ultra Pro Kiber MAX Меч", 3, 40},
        {"Малая хилка", 4, 10},
        {"Большая хилка", 4, 20}
    };
    int way = rand() % 2, item_num = rand() % 6;

    if (item_count == NULL || inventory == NULL || armour == NULL || weapon == NULL || player == NULL) {
        return 1;
    }
    
    if(way == 0){
        empty_dungeon_text();
    }
    else{
        treasuries_dungeon_text(possible[item_num].name);
        if(possible[item_num].class < 3){
            armour_replace(possible[item_num].class, possible[item_num].name, possible[item_num].param, armour);
        }
        else if(possible[item_num].class == 3){
            weapon_replace(possible[item_num].name, possible[item_num].param, weapon);
        }
        else{
            add_to_inv(possible[item_num].name, possible[item_num].param, item_count, inventory, armour, weapon, player);
        }
    }
    return 0;
}