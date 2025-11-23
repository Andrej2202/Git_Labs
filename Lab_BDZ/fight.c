#include <stdio.h>
#include <stdlib.h>
#include "fight.h"
#include "sys_funcs.h"
#include "text_blocks.h"
#include "person_items.h"
#include "player_parametrs.h"


int fight(int lvl, items *inventory, items *armour, items *weapon, Parametrs *player){ 
    mob_dungeon_text();
    int rand_buff = rand() % 50 + 30;
    int cube = 0, mob_maxHealth = lvl * 10 + rand_buff, mob_health = lvl * 10 + rand_buff, check = 0, player_strike = 0, mob_strike = 0, player_armour = 0;
    clear_input();
    if(inventory == NULL || armour == NULL || weapon == NULL || player == NULL){
        printf("Ошибка передачи параметров в mob_fight");
        return 1;
    }
    player_armour = armour[0].param + armour[1].param + armour[2].param;
    while(player->hp > 0 ){
        clear_screen();
        printf("Твое хп: %d/%d, хп моба %d/%d\n\n", player->hp, player->max_hp, mob_health, mob_maxHealth);
        cube = rand() % 6  + 1;
        player_strike = player->strength * cube + weapon->param;
        printf("Ты ударил скелета и он потерял %dхп\n", (player_strike < mob_health) ? player_strike : mob_health);
        mob_health -= player_strike;
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
                printf("Герой получил %d стандартную хилку\n", count_heals);
                for(int i = 0; i < count_heals; i++){
                    check = add_to_inv("Стандартная хилка", 75, inventory, armour, weapon, player);
                    if(check != 0){
                        return 1;
                    }
                }
                printf("Улучшенные характеристики персонажа: максимальное хп - %d -> %d, базовая сила %d -> %d\n", temp_hp, player->max_hp, temp_strenght, player->strength);
            }
            clear_input();
            return 0;
        }

        printf("Скелет сделал выпад");
        mob_strike = cube * 2 * lvl - player_armour;
        mob_strike = (mob_strike > 0) ? (mob_strike) : 0;
        mob_strike = (mob_strike < player->hp) ? (mob_strike) : (player->hp);
        if(mob_strike == 0){
            printf(", меч с лязгом прошел по броне, но не нанес урон.");
        }
        else{
            printf(" и ловким ударом поранил тебя.\nТы потерял %dхп\n", mob_strike);
            check = change_player_param("hp", -1 * mob_strike, player);
        }
        if(check != 0){
            return 1;
        }
        clear_input();
    }
    return 0;
}


int boss_fight(int lvl, items *inventory, items *armour, items *weapon, Parametrs *player){ 
    boss_dungeon_text(&player->hero);
    int rand_buff = rand() % 100 - 50;
    int cube = 0, boss_maxHealth = 2 * player->hp + rand_buff, boss_health = 2 * player->hp + rand_buff, check = 0, player_strike = 0, boss_strike = 0, player_armour = 0, phase_strike = 0;
    if(inventory == NULL || armour == NULL || weapon == NULL || player == NULL){
        printf("Ошибка передачи параметров в fight");
        return 1;
    }
    player_armour = armour[0].param + armour[1].param + armour[2].param;
    boss_maxHealth -= (boss_maxHealth % 2);
    boss_health = boss_maxHealth;

    for(int i = 0; i < 2; i++){
        while(player->hp > 0 ){
            clear_screen();
            printf("Фаза %d/2\n", i+1);
            printf("Твое хп: %d/%d, хп босса %d/%d\n\n", player->hp, player->max_hp, boss_health, boss_maxHealth);
            cube = rand() % 6  + 1;
            player_strike = player->strength * cube + weapon->param;
            if(i == 0){
                printf("Ты ударил короля скелетов и он потерял %dхп\n", (player_strike < boss_health) ? player_strike : boss_health + 50);
            }
            else{
                printf("Ты ударил короля скелетов и он потерял %dхп\n", (player_strike < boss_health) ? player_strike : boss_health);
            }
            boss_health -= player_strike;
            clear_input();

            if(boss_health <= boss_maxHealth / 2 && i == 0){
                end_of_phase_1_text();
                clear_input();
                break;
            }
            if(boss_health <= 0){
                good_end_text();
                return 0;
            }

            printf("Босс сделал выпад");
            boss_strike = cube * 3 * lvl + phase_strike - player_armour;
            boss_strike = (boss_strike > 0) ? (boss_strike) : 0;
            boss_strike = (boss_strike < player->hp) ? (boss_strike) : (player->hp);
            if(boss_strike == 0){
                printf(", меч с лязгом прошел по броне, но не нанес урон.");
            }
            else{
                printf(" и ловким ударом поранил тебя.\nТы потерял %dхп\n", boss_strike);
                check = change_player_param("hp", -1 * boss_strike, player);
            }
            if(check != 0){
                return 1;
            }
            clear_input();
        }
        if(player->hp <= 0){
            break;
        }
        if(i == 0){
            fight(1, inventory, armour, weapon, player);
            if(player->hp <= 0){
                break;
            }
            printf("Только вы избавились от первого скелета, как второй более крупный скелетик напал на вас сзади.\n");
            fight(3, inventory, armour, weapon, player);
            if(player->hp <= 0){
                break;
            }
            phase_2_text();
            char enter, text[] = "открыть инвентарь";
            yes_no_input(&enter, text);
            if(enter == 'Y' || enter == 'y'){
                open_inventory(inventory, armour, weapon, player);
            }
            phase_strike = 10;
        }
    }
    bad_end_text();
    return 0;
}

