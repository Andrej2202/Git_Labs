#include <stdio.h>
#include "items.h"
#include"sys_funcs.h"
#include "player_parametrs.h"

//������ ������

//������ �����
armour items[3] = {0}; // 0 - head; 1 - chest; 2 - legs

void items_show(){
    for(int i = 0; i < 3; i++){
        printf("%s: %d %d\n", items[i].name, items[i].heal, items[i].def);
    }
}


void item_replace(int place, char *name, int def, int heal){
    if(items[place].def == 0 && items[place].heal == 0){
        snprintf(items[place].name, sizeof(items[place].name), "%s", name);
        items[place].heal = heal;
        items[place].def = def;
    }
}
//������ ���������
inv_item inventory[10] = {0};

int item_count = 0;


int using_item(int num){
    num--;
    if(num < 0 || num >= item_count){
        printf("��� ������ ��������� �����\n");
        return 0;
    }
    int temp = get_mathInfo("hp");
    change_player_param("hp", inventory[num].heal);
    printf("�������� ����� �����\n�� �������������� %d->%d\n", temp, get_mathInfo("hp"));
    inventory[num] = inventory[item_count - 1];
    item_count--;
    return 1;

}


void open_inventory(){
    if(item_count == 0){
        printf("��� ��������� ����");
        clear_input();
        clear_screen();
    }
    else{
        int command = 0;
        do{
            for(int i = 0; i < item_count; i++){
                printf("%d. %s - ����������� �� �� %d ������.\n", i + 1, inventory[i].name, inventory[i].heal);
            }
            printf("\n������������ �������� �� ��������� - 1, ������� ������� - 2, ����� �� ��������� - 3\n");
            scanf("%d", &command);
            if(command == 1){
                int it, check;
                do{
                    printf("����� ����� ������ ������������?:");
                    scanf("%d", &it);
                    check = using_item(it);
                }while(check!=1);
            }
            else if(command == 2){
                printf(" ");
            }
            clear_screen();
        }while(command != 3);
    }
}


void add_to_inv(const char *name, int heal_ammount){
    if(item_count == 10){
        printf("��� ��������� ��������, ����� ����� ������� ����������� ��� ��������� ���-���� �� ���������\n");
        printf("������� ���������?(y/n):");
        char temp = 'n';
        scanf(" %c", &temp);
        if(temp == 'y' || temp == 'Y'){
            open_inventory();
        }
        
    }

    if(item_count != 10){
        snprintf(inventory[item_count].name, sizeof(inventory[item_count].name), "%s", name);
        inventory[item_count].heal = heal_ammount; 
        item_count++;
    }
}