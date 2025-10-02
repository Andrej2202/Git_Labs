#include <stdio.h>
#include "init.h"
#include "sys_funcs.h"
#include "sys_funcs.h"
#include "text_blocks.h"
#include "dungeon_logic.h"
#include "player_parametrs.h"


void class_pick(){
    int res = 0;
    do{
        clear_screen();
        class_pick_text();
        res = scanf("%d", &player.hero);
        clear_input();
    }while(res != 1);
    player.hero -= 1;
    printf("%d", player.hero);
    clear_input();
    enter_expect();
    switch(player.hero) {
        case 0:
            player.hp = 45000; 
            player.strength = 25; 
            player.capacity = 80;
            break;

        case 1:
            player.hp = 150000; 
            player.strength = 50; 
            player.capacity = 60;
            break;

        case 2:
            player.hp = 400000; 
            player.strength = 20; 
            player.capacity = 30;
            break;
        default:
            player.hp = 400000; 
            player.strength = 0; 
            player.capacity = 0;
    }  
    player.max_hp = player.hp;
    player.level = 1;
    player.xp = 0;
    player.addit_strength = 0;
    clear_screen();
    dungeon_exploring();
}


void start() {
    clear_screen();
    char s = ' ';
    do{
        printf("Здравствуй, исследователь подземелий!\n");
        printf("Для продолжения повествования на протяжении всей истории используй enter\n");
        enter_expect();
        clear_screen();
        printf("Введи имя игрока:\n");
        scanf("%s", player.name);
        printf("%s, верно?(y/n)\n", player.name);
        scanf(" %c", &s);
        clear_screen();
    }while(s != 'y' && s != 'Y');

    class_pick();
}