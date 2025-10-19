#ifndef PERSON_ITEMS_H
#define PERSON_ITEMS_H
//оружие
void weapon_show();
void weapon_replace(const char *name, int param);


//броня
void armour_show();
void armour_replace(int place, const char *name, int def);


//инвентарь
extern int item_count;


int using_item(int num);
int delete_item(int num);
void open_inventory();
void add_to_inv(const char *name, int heal_ammount);
#endif