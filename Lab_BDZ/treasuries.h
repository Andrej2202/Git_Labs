#ifndef TREASURIES_H
#define TREASURIES_H

typedef struct {
    char name[64];
    int  class, param;
    
} item;

extern item possible[3];

void give_treasuries();
#endif