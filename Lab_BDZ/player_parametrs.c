#include <string.h>
#include <stdio.h>
#include "player_parametrs.h"


Param player;


void change_player_param(char *change, int n){
    if(strcmp(change, "hp") == 0){ // короооооче, бахаем тут адреску и кайфуееем
        player.hp = ((player.hp + n) < (player.max_hp) ? (player.hp + n) : (player.max_hp)); 
    }
    if(strcmp(change, "max_hp") == 0){
        player.max_hp += n;
    }
    if(strcmp(change, "capacity") == 0){
        player.capacity += n;
    }
    if(strcmp(change, "strength") == 0){
        player.strength += n;
    }
    if(strcmp(change, "addit_strength") == 0){
        player.addit_strength += n;
    }
    if(strcmp(change, "xp") == 0){
        while(player.xp + n >= player.level * 10){
            n -= (player.level * 10 - player.xp);
            player.level++;
            player.max_hp += player.max_hp / 10;
            player.strength += player.strength / 10;
            player.xp = 0; 
        }
        player.xp += n;
    }
}

