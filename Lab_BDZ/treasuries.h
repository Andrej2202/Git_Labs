#ifndef TREASURIES_H
#define TREASURIES_H

typedef struct {
    char name[27];
    int  class, param;
    
} item;

int give_treasuries(int* item_count);
#endif