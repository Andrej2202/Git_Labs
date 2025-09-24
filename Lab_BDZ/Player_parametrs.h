#ifndef PLAYER_PARAMETRS_H
#define PLAYER_PARAMETRS_H
typedef struct {
    char name[64];
    int hero, hp, capacity, strength, level, xp, max_hp, addit_strength;
    
} Param;


extern Param player;


void change_player_param(char *change, int n);

int get_mathInfo(char* ask);

char* get_printInfo(char* ask);
#endif

