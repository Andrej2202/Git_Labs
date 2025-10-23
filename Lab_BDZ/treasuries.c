#include <stdlib.h>
#include <stdio.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include"person_items.h"
#include "text_blocks.h"

int give_treasuries(){
    item possible[6] = { // 0 - 2 - зашита, 3 - оружие, 4 - предметы
        {"Ultra Pro Kiber MAX Шлем", 0, 20},
        {"Ultra Pro Kiber MAX Кираса", 1, 50},
        {"Ultra Pro Kiber MAX Поножи", 2, 10},
        {"Ultra Pro Kiber MAX Меч", 3, 40},
        {"Малая хилка", 2, 10},
        {"Большая хилка", 2, 20}
    };
    int way = rand() % 2, item_num = rand() % 6;
    if(way == 0){
        empty_dungeon_text();
    }
    else{
        treasuries_dungeon_text(possible[item_num].name);
        if(possible[item_num].class < 3){
            armour_replace(possible[item_num].class, possible[item_num].name, possible[item_num].param);
        }
        else if(possible[item_num].class == 4){
            weapon_replace(possible[item_num].name, possible[item_num].param);
        }
        else{
            add_to_inv(possible[item_num].name, possible[item_num].param);
        }
    }
    return 0;
}