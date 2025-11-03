#include <stdio.h>
#include <stdlib.h>
#include "fight.h"
#include "sys_funcs.h"
#include "text_blocks.h"
#include "person_items.h"
#include "player_parametrs.h"


int fight(int lvl, int* item_count, int* fight_result, items *inventory, items *armour, items *weapon, Parametrs *player){ 
    mob_dungeon_text();
    int cube = 0, mob_maxHealth = lvl * 5, mob_health = lvl * 5;
    clear_input();

    while(player->hp > 0 ){
        clear_screen();
        printf("Твое хп: %d/%d, хп моба %d/%d\n\n", player->hp, player->max_hp, mob_health, mob_maxHealth);
        cube = rand() % 6  + 1;
        mob_health -= cube;
        printf("Ты ударил скелета и он потерял %dхп\n", cube);
        clear_input();

        if(mob_health <= 0){
            printf("Скелет рассыпался в пыль\n\n");
            int temp_lvl = player->level, temp_hp = player->max_hp, temp_strenght = player->strength;
            change_player_param("xp", lvl * 5, player);
            printf("Герой получил %d xp за победу\n", lvl * 5);
            if(temp_lvl != player->level){
                int count_heals = player->level - temp_lvl;
                printf("Уровень персонажа повышен %d -> %d\n", temp_lvl, player->level);
                printf("Герой получил %d больших хилок\n", count_heals);
                for(int i = 0; i < count_heals; i++){
                    add_to_inv("Большая хилка", 20, item_count, inventory, armour, weapon, player);
                }
                printf("Улучшенные характеристики персонажа: максимальное хп - %d -> %d, базовая сила %d -> %d\n", temp_hp, player->max_hp, temp_strenght, player->strength);
            }
            clear_input();
            *fight_result = 1;
            return 0;
        }

        printf("Скелет сделал выпад и ловким ударом поранил тебя.\n");
        printf("Ты потерял %dхп\n", cube);
        change_player_param("hp", -1 * cube, player);
        clear_input();
    }
    *fight_result = 0;
    return 0;
}