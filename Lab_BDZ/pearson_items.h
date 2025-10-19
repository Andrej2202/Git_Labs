#ifndef ITEMS_H
#define ITEMS_H
typedef struct{
    char name[20];
    int heal;
} inv_item;

typedef struct{
    char name[20];
    int def;
} armour_item;


extern armour_item armour[3];
extern inv_item inventory[10];
extern int item_count;


void armour_show();
void armour_replace(int place, const char *name, int def);


int using_item(int num);
void open_inventory();
void add_to_inv(const char *s, int n);
#endif