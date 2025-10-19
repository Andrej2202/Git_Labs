#ifndef TREASURIES_H
#define TREASURIES_H

typedef struct {
    char name[14];
    int  class, param;
    
} item;

void give_treasuries();
#endif