#ifndef PERSON_ITEMS_H
#define PERSON_ITEMS_H
//������
void weapon_show();
void weapon_replace(const char *name, int param);


//�����
void armour_show();
void armour_replace(int place, const char *name, int def);


//���������
void open_inventory(int* item_count);
void add_to_inv(const char *name, int heal_ammount, int* item_count);
#endif