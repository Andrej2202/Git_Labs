#include <stdio.h>
#include <stdlib.h>
#include "fight.h"
#include "sys_funcs.h"
#include "text_blocks.h"
#include "person_items.h"
#include "player_parametrs.h"


int fight(int lvl, int* item_count, int* fight_result, items *inventory, items *armour, items *weapon, Parametrs *player){ 
    mob_dungeon_text();
    int cube = 0, mob_maxHealth = lvl * 10, mob_health = lvl * 10, check = 0, player_strike = 0, mob_strike = 0;
    clear_input();
    if(inventory == NULL || armour == NULL || weapon == NULL || player == NULL){
        printf("Ошибка передачи параметров в fight");
        return 1;
    }

    while(player->hp > 0 ){
        clear_screen();
        printf("Твое хп: %d/%d, хп моба %d/%d\n\n", player->hp, player->max_hp, mob_health, mob_maxHealth);
        cube = rand() % 6  + 1;
        player_strike = player->strength * cube;
        mob_health -= player_strike;
        printf("Ты ударил скелета и он потерял %dхп\n", (player_strike < mob_health) ? player_strike : mob_health);
        clear_input();

        if(mob_health <= 0){
            printf("Скелет рассыпался в пыль\n\n");
            int temp_lvl = player->level, temp_hp = player->max_hp, temp_strenght = player->strength;
            check = change_player_param("xp", lvl * 5, player);
            if(check != 0){
                return 1;
            }
            printf("Герой получил %d xp за победу\n", lvl * 5);
            if(temp_lvl != player->level){
                int count_heals = player->level - temp_lvl;
                printf("Уровень персонажа повышен %d -> %d\n", temp_lvl, player->level);
                printf("Герой получил %d больших хилок\n", count_heals);
                for(int i = 0; i < count_heals; i++){
                    check = add_to_inv("Большая хилка", 20, item_count, inventory, armour, weapon, player);
                    if(check != 0){
                        return 1;
                    }
                }
                printf("Улучшенные характеристики персонажа: максимальное хп - %d -> %d, базовая сила %d -> %d\n", temp_hp, player->max_hp, temp_strenght, player->strength);
            }
            clear_input();
            *fight_result = 1;
            return 0;
        }

        printf("Скелет сделал выпад и ловким ударом поранил тебя.\n");
        printf("Ты потерял %dхп\n", cube);
        check = change_player_param("hp", -1 * cube, player);
        if(check != 0){
            return 1;
        }
        clear_input();
    }
    *fight_result = 0;
    return 0;
}
