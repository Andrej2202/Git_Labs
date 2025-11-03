#ifndef DUNGEON_LOGIC_H
#define DUNGEON_LOGIC_H
typedef struct {
    char name[128];
    int hero, hp, max_hp, strength, level, xp, addit_strength;
    
} Parametrs; 

typedef struct{
    char name[30];
    int param;
} items;

void dungeon_exploring();
#endif