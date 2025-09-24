#ifndef ITEMS_H
#define ITEMS_H
typedef struct{
    char name[10];
    int health;
} inv_item;


extern inv_item inventory[10];
extern int item_count;

int using_item(int num);
void open_inventory();
void add_to_inv(const char *s, int n);
#endif