#include <stdlib.h>
#include <stdio.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include "person_items.h"
#include "text_blocks.h"

int give_treasuries(int cur_dungeon, items *inventory, items *armour, items *weapon, Parametrs *player){
    treasure possible[15] = { // 0 - 2 - зашита, 3 - оружие, 4 - предметы
        {"Медный шлем", 0, 5},
        {"Медная кираса", 1, 15},
        {"Медные поножи", 2, 5},
        {"Медный", 3, 5}, // меч, лук, бульбулятор, кусь
        {"Малая хилка", 4, 50},

        {"Стальной Шлем", 0, 10},
        {"Стальная Кираса", 1, 30},
        {"Стальные Поножи", 2, 10},
        {"Стальной", 3, 10},
        {"Большая хилка", 4, 100},

        {"Изумрудный шлем", 0, 10},
        {"Изумрудная кираса", 1, 40},
        {"изумрудные поножи", 2, 10},
        {"Изумрудный", 3, 15},
        {"Большая хилка", 4, 100}
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
        treasuries_dungeon_text();
        if(possible[item_num].class < 3){
            printf("%s\n\n", possible[item_num].name);
            check = armour_replace(possible[item_num].class, possible[item_num].name, possible[item_num].param, armour);
        }
        else if(possible[item_num].class == 3){
            printf("%s", possible[item_num].name);
            switch(player->hero){
                case 0:
                    printf(" меч\n\n");
                    break;
                case 1:
                    printf(" лук\n\n");
                    break;
                case 2:
                    printf(" бульбулятор\n\n");
                    break;
                default:
                    printf(" кусь\n\n");
                    break;

            }
            check = weapon_replace(possible[item_num].name, possible[item_num].param, weapon, &player->hero);
        }
        else{
            printf("%s\n\n", possible[item_num].name);
            check = add_to_inv(possible[item_num].name, possible[item_num].param, inventory, armour, weapon, player);
        }
    }
    return check;
}