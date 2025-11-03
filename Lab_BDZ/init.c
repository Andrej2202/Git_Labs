#include <stdio.h>
#include "init.h"
#include "sys_funcs.h"
#include "text_blocks.h"
#include "dungeon_logic.h"
#include "player_parametrs.h"


void class_pick(Parametrs *player){
    int check = 0;
    char s = ' ';
    do{
        printf("¬веди им€ игрока:\n");
        fgets(player->name, sizeof(player->name), stdin);
        for (int i = 0; player->name[i] != '\0'; i++){
            if (player->name[i] == '\n'){
                player->name[i] = '\0';
                break;
            }
        }
        printf("%s, верно?(y/n)\n", player->name);
        scanf(" %c", &s);
        clear_input();
        clear_screen();
    }while(s != 'y' && s != 'Y');

    do{
        clear_screen();
        class_pick_text(player);
        check = scanf("%d", &player->hero);
        clear_input();
    }while(check != 1 && ((player->hero < 0 || player->hero > 2) && (player->hero != 78)));
    player->hero -= 1;
    switch(player->hero) {
        case 0:
            player->hp = 45000; 
            player->strength = 25;
            break;

        case 1:
            player->hp = 150000; 
            player->strength = 50;
            break;

        case 2:
            player->hp = 400000; 
            player->strength = 20;
            break;
        default:
            player->hp = 400000; 
            player->strength = 1;
    }  
    player->max_hp = player->hp;
    player->level = 1;
    player->xp = 0;
    player->addit_strength = 0;
    clear_screen();
}