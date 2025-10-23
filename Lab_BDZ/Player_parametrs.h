#ifndef PLAYER_PARAMETRS_H
#define PLAYER_PARAMETRS_H
typedef struct {
    char name[128];
    int hero, hp, max_hp, strength, level, xp, addit_strength;
    
} Param;

typedef struct{
    char name[30];
    int param;
} items;

extern Param player;

extern items weapon;
extern items armour[3];
extern items inventory[10];


int change_player_param(char *change, int n);

#endif

