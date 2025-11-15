#include <stdlib.h>
#include <stdio.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include "person_items.h"
#include "text_blocks.h"

int give_treasuries(int cur_dungeon, items *inventory, items *armour, items *weapon, Parametrs *player){
    treasure possible[15] = { // 0 - 2 - зашита, 3 - оружие, 4 - предметы
        {"Медный шлем", 0, 20},
        {"Медный кираса", 1, 50},
        {"Медный поножи", 2, 10},
        {"Медный", 3, 10}, // меч, лук, бульбулятор
        {"Малая хилка", 4, 10},

        {"Стальной Шлем", 0, 20},
        {"Стальной Кираса", 1, 50},
        {"Стальной Поножи", 2, 10},
        {"Стальной", 3, 10},
        {"Большая хилка", 4, 20},

        {"Изумрудный шлем", 0, 20},
        {"Изумрудная кираса", 1, 50},
        {"изумрудные поножи", 2, 10},
        {"Изумрудный", 3, 10},
        {"Большая хилка", 4, 20}
    };
    cur_dungeon--;
    int way = rand() % 2, item_num = rand() % 5 + 5 * (cur_dungeon / 3), check;

    if (inventory == NULL || armour == NULL || weapon == NULL || player == NULL) {
        printf("Ошибка получения параметров в give_treasuries");
        return 1;
    }
    
    if(way == 0){
        empty_dungeon_text();
    }
    else{
        treasuries_dungeon_text(possible[item_num].name);
        if(possible[item_num].class < 3){
            check = armour_replace(possible[item_num].class, possible[item_num].name, possible[item_num].param, armour);
        }
        else if(possible[item_num].class == 3){
            check = weapon_replace(possible[item_num].name, possible[item_num].param, weapon, &player->hero);
        }
        else{
            check = add_to_inv(possible[item_num].name, possible[item_num].param, inventory, armour, weapon, player);
        }
    }
    return check;
}