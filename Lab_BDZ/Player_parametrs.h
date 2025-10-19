#ifndef PLAYER_PARAMETRS_H
#define PLAYER_PARAMETRS_H
typedef struct {
    char name[128];
    int hero, hp, max_hp, capacity, strength, level, xp, addit_strength;
    
} Param;


extern Param player;


int change_player_param(char *change, int n);

#endif

