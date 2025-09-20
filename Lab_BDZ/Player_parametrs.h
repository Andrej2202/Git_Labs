typedef struct {
    char name[64];
    int hero, hp, capacity, strength, level;
    
} Param;


Param player;


void change_player_param(char *change, int n){
    if(strcmp(change, "class") == 0){
        player.hero += n;
    }
    if(strcmp(change, "hp") == 0){
        player.hp += n;
    }
    if(strcmp(change, "capacity") == 0){
        player.capacity += n;
    }
    if(strcmp(change, "strength") == 0){
        player.strength += n;
    }
    if(strcmp(change, "level") == 0){
        player.level += n;
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
}


char* get_printInfo(char* ask){
    if(strcmp(ask, "name") == 0){
        return player.name;
    }
    if(strcmp(ask, "class_name") == 0){
        switch(player.hero) {
            case 0: return "Воин";
            case 1: return "Охотник";
            case 2: return "Алхимик";
        }      
    }
    
}


