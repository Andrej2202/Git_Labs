typedef struct {
    char name[64];
    int hero, hp, capacity, strength, level, xp;
    
} Param;


Param player;


void change_player_param(char *change, int n){
    if(strcmp(change, "hp") == 0){
        player.hp += n;
    }
    if(strcmp(change, "capacity") == 0){
        player.capacity += n;
    }
    if(strcmp(change, "strength") == 0){
        player.strength += n;
    }
    if(strcmp(change, "xp") == 0){
        while(player.xp + n >= player.level * 10){
            n -= (player.level * 10 - player.xp);
            player.level++;
            player.xp = 0; 
        }
        player.xp += n;
    }
}


int get_mathInfo(char* ask){
    if(strcmp(ask, "class") == 0){
        return player.hero;
    }
    if(strcmp(ask, "hp") == 0){
        return player.hp;
    }
    if(strcmp(ask, "capacity") == 0){
        return player.capacity;
    }
    if(strcmp(ask, "strength") == 0){
        return player.strength;
    }
    if(strcmp(ask, "level") == 0){
        return player.level;
    }
    if(strcmp(ask, "xp") == 0){
        return player.xp;
    }
    return -1;
}


char* get_printInfo(char* ask){
    if(strcmp(ask, "name") == 0){
        return player.name;
    }
    if(strcmp(ask, "class_name") == 0){
        switch(player.hero) {
            case 0: return "воин";
            case 1: return "охотник";
            case 2: return "алхимик";
        }      
    }
    return "None";
    
}


