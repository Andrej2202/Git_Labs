#include <stdio.h>
#include "sys_funcs.h"
#include "saving.h"
#include "player_parametrs.h"


Param player;
items weapon = {"Базовый ", 0};
items armour[3] = {
    {"Базовый шлем", 0},
    {"Базовая кираса", 0},
    {"Базовые поножи", 0}
};
items inventory[10] = {0};

int change_player_param(char *change, int n){
    if(my_strcmp(change, "hp") == 0){
        player.hp = ((player.hp + n) < (player.max_hp) ? (player.hp + n) : (player.max_hp)); 
    }
    if(my_strcmp(change, "max_hp") == 0){
        player.max_hp += n;
    }
    if(my_strcmp(change, "strength") == 0){
        player.strength += n;
    }
    if(my_strcmp(change, "addit_strength") == 0){
        player.addit_strength += n;
    }
    if(my_strcmp(change, "xp") == 0){
        while(player.xp + n >= player.level * 10){
            n -= (player.level * 10 - player.xp);
            player.level++;
            player.max_hp += player.max_hp / 10;
            player.strength += player.strength / 10;
            player.xp = 0; 
        }
        player.xp += n;
    }
    return 0;
}


int clear_player_parametrs(){
    int temp = 0;
    read_file(1, &temp);
    return 0;
}
