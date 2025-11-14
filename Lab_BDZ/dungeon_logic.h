#ifndef DUNGEON_LOGIC_H
#define DUNGEON_LOGIC_H
typedef struct {
    char name[128];
    int hero, hp, max_hp, strength, level, xp;
    
} Parametrs; 

typedef struct{
    char name[34];
    int param;
} items;

int dungeon_exploring();
#endif