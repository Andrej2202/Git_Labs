#include <stdio.h>
#include "sys_funcs.h"
#include "player_parametrs.h"




int change_player_param(char *change, int n, Parametrs *player){
    if(player == NULL){
        printf("Ошибка передачи данных в change_player_parametrs");
        return 1;
    }
    if(my_strcmp(change, "hp") == 0){
        player->hp = ((player->hp + n) < (player->max_hp) ? (player->hp + n) : (player->max_hp)); 
    }
    if(my_strcmp(change, "max_hp") == 0){
        player->max_hp += n;
    }
    if(my_strcmp(change, "strength") == 0){
        player->strength += n;
    }
    if(my_strcmp(change, "xp") == 0){
        while(player->xp + n >= player->level * 10){
            n -= (player->level * 10 - player->xp);
            player->level++;
            player->max_hp += player->max_hp / 10;
            player->strength += (player->strength / 4 < 6) ? (player->strength / 4) : (5);
            player->xp = 0; 
        }
        player->xp += n;
    }
    return 0;
}