#include <stdlib.h>
#include <stdio.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include"person_items.h"
#include "text_blocks.h"

void give_treasuries(){
    item possible[6] = { // 0 - зашита, 1 - оружие, 2 - предметы
        {"Шлем", 0, 20},
        {"Кираса", 0, 50},
        {"Поножи", 0, 10},
        {"Меч", 1, 40},
        {"Малая хилка", 2, 10},
        {"Большая хилка", 2, 20}
    };
    int way = rand() % 2, item_num = rand() % 6;
    if(way == 0){
        empty_dungeon_text();
    }
    else{
        treasuries_dungeon_text(possible[item_num].name);
        if(possible[item_num].class == 0){

        }
        else if(possible[item_num].class == 1){

        }
        else{
            add_to_inv(possible[item_num].name, possible[item_num].param);
        }
    }
}