#include <stdio.h>
#include "init.h"
#include "sys_funcs.h"
#include "text_blocks.h"


int class_pick(Parametrs *player){
    int check = 0;
    char s = ' ';
    if(player == NULL){
        printf("Ошибка получения player в class_pick");
        return 1;
    }
    do{
        printf("Введи имя игрока:\n");
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
    }while(check != 1 || ((player->hero < 0 || player->hero > 3) && (player->hero != 78)));
    player->hero -= 1;
    switch(player->hero) {
        case 0:
            player->hp = 200; 
            player->strength = 5;
            player->max_items = 3;
            break;

        case 1:
            player->hp = 100; 
            player->strength = 10;
            player->max_items = 5;
            break;

        case 2:
            player->hp = 150; 
            player->strength = 8;
            player->max_items = 4;
            break;
        default:
            player->hp = 400000; 
            player->strength = 1;
    }  
    player->max_hp = player->hp;
    player->level = 1;
    player->xp = 0;
    player->item_count = 0;
    clear_screen();
    return 0;
}