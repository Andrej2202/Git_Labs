#include <stdio.h>
#include "items.h"
#include"sys_funcs.h"
#include "player_parametrs.h"

//������ ������

//������ �����
armour_item armour[3] = {
    {"", -1},
    {"", -1},
    {"", -1}
}; // 0 - head; 1 - chest; 2 - legs

void armour_show(){
    for(int i = 0; i < 3; i++){
        switch(i){
            case 0:
                printf("������:   ");
                break;
            case 1:
                printf("��������: ");
                break;
            default:
                printf("����:     ");
        }
        if(armour[i].def == -1){
            printf("������� �����������.\n");
        }
        else{
            printf("%s:  ������ - %d\n", armour[i].name, armour[i].def);
        }
    }
}


void armour_replace(int place, const char *name, int def){
    if(armour[place].def == -1){
        snprintf(armour[place].name, sizeof(armour[place].name), "%s", name);
        armour[place].def = def;
    }
    else{
        char res;
        printf("� ��������� ������������ �����\n");
        clear_input();
        do{
            res = 'y';
        }while(res != 'y' && res != 'Y');
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
    int temp = player.hp;
    change_player_param("hp", inventory[num].heal);
    printf("�������� ����� �����\n�� �������������� %d->%d\n", temp, player.hp);
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