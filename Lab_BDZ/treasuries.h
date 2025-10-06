#ifndef TREASURIES_H
#define TREASURIES_H
typedef struct {
    char name[64];
    int application, armour, regen_hp, attack;
    
} item;


void give_treasuries();
#endif