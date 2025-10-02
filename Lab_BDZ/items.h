#ifndef ITEMS_H
#define ITEMS_H
typedef struct{
    char name[10];
    int heal;
} inv_item;

typedef struct{
    char name[20];
    int def;
    int heal;
} armour;


extern armour items[3];
extern inv_item inventory[10];
extern int item_count;


void items_show();
void item_replace(int place, char *name, int def, int heal);


int using_item(int num);
void open_inventory();
void add_to_inv(const char *s, int n);
#endif