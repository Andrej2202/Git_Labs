#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "player_parametrs.h"
#include "text_blocks.h"
#include "sys_funcs.h"
#include "fight.h"


void fight(int lvl){ 
    srand(time(NULL));
    int cube;
    int mob_maxHealth = lvl * 5, mob_health = lvl * 5;
    clear_input();
    getchar();
    while(get_mathInfo("hp") > 0 ){
        clear_screen();
        printf("Твое хп: %d/%d, хп моба %d/%d\n\n", get_mathInfo("hp"), get_mathInfo("max_hp"), mob_health, mob_maxHealth);
        cube = rand() % 6  + 1;
        mob_health -= cube;
        printf("Ты ударил скелета и он потерял %dхп\n", cube);
        getchar();
        if(mob_health <= 0){
            printf("Скелет рассыпался в пыль\n\n");
            int temp_lvl = get_mathInfo("level"), temp_hp = get_mathInfo("max_hp"), temp_strenght = get_mathInfo("strength");
            change_player_param("xp", lvl * 5);
            printf("Герой получил %d xp за победу\n", lvl * 5);
            if(temp_lvl!= get_mathInfo("level")){
                printf("Уровень персонажа повышен до %d\n", get_mathInfo("level"));
                printf("Улучшенные характеристики персонажа: максимальное хп - %d -> %d, базовая сила %d -> %d\n", temp_hp, get_mathInfo("max_hp"), temp_strenght, get_mathInfo("strength"));
            }
            getchar();
            break;
        }
        printf("Скелет сделал выпад и ловким ударом поранил тебя.\n");
        printf("Ты потерял %dхп\n", cube);
        change_player_param("hp", -1 * cube);
        getchar();
        
    }
    if(get_mathInfo("hp") <= 0){
        game_end_text(0);
    }
}