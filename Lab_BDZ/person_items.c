#include <stdio.h>
#include "sys_funcs.h"
#include "person_items.h"
#include "player_parametrs.h"

//������ ������ ------------------------------------------------------------------------------------------------
void weapon_show(){
    printf("������� ������: \n%s, ����: %d\n\n", weapon.name, weapon.param);
}


void weapon_replace(const char *name, int param){
    char enter, text[] = "��������";
    if(weapon.param != -1){
        printf("������ ��� ����.\n");
        printf("%s -> %s \n��������� ������������� ��� ������: %d -> %d\n", weapon.name, name, weapon.param, param);
        yes_no_input(&enter, text);
        if(enter == 'y'|| enter == 'Y'){
            weapon.param = -1;
        }
    }
    if(weapon.param == -1){
        string_replace(name, weapon.name);
        weapon.param = param;
    }
}


//������ ����� ------------------------------------------------------------------------------------------------
void armour_show(){
    printf("�����:\n");
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
        printf("%s:  ������ - %d\n", armour[i].name, armour[i].param);
    }
    printf("\n");
}


void armour_replace(int place, const char *name, int param){
    char enter, text[] = "��������";
    if(armour[place].param != 0){
        printf("������ ���� ����� ��� �����. ������ ��������?\n");
        printf("%s -> %s \n��������� ������������� ��� ������: %d -> %d\n", armour[place].name, name, armour[place].param, param);
        yes_no_input(&enter, text);
        if(enter =='y' || enter == 'Y'){
            armour[place].param = -1;
        }
    }
    if(armour[place].param == 0){
        string_replace(name, armour[place].name);
        armour[place].param = param;
    }
}



//������ ��������� ------------------------------------------------------------------------------------------------


int using_item(int num, int* item_count){
    int temp = player.hp;
    num--;
    if(num < 0 || num >= *item_count){
        printf("��� ������ ��������� �����\n");
        clear_input();
        clear_input();
        return 1;
    }
    change_player_param("hp", inventory[num].param);
    printf("�������� ����� �����\n�� �������������� %d->%d\n", temp, player.hp);
    inventory[num] = inventory[*item_count - 1];
    (*item_count)--;
    return 0;

}


int delete_item(int num, int* item_count){
    num--;
    if(num < 0 || num >= *item_count){
        printf("��� ������ ��������� �����\n");
        clear_input();
        clear_input();
        return 1;
    }
    inventory[num] = inventory[*item_count - 1];
    (*item_count)--;
    return 0;
}


void open_inventory(int* item_count){
    int command = 0, fl = 0;
    do{
        armour_show();
        weapon_show();
        if(*item_count == 0){
            printf("��� ��������� ����");
            clear_input();
            fl = 1;
        }
        else{
            for(int i = 0; i < *item_count; i++){
                printf("%d. %s - ����������� �� �� %d ������.\n", i + 1, inventory[i].name, inventory[i].param);
            }
            printf("\n������������ �������� �� ��������� - 1, ������� ������� - 2, ����� �� ��������� - 3\n");
            scanf("%d", &command);
            if(command == 1){
                int num, check;
                do{
                    printf("����� ����� ������ ������������?:");
                    scanf("%d", &num);
                    check = using_item(num, item_count);
                }while(check != 0 && *item_count != 0);
            }
            else if(command == 2){
                int num, check;
                do{
                    printf("����� ����� ������ ������ �� ���������?:");
                    scanf("%d", &num);
                    check = delete_item(num, item_count);
                }while(check != 0 && *item_count != 0);
            }
            clear_screen();
            if(command != 3 && *item_count != 0){
                armour_show();
                weapon_show();
            }  
        }
    }while(command != 3 && fl != 1);
}


void add_to_inv(const char *name, int param_ammount, int* item_count){
    char temp = 'n', text[] = "������� ���������?";
    if(*item_count == 10){
        printf("��� ��������� ��������, ����� ����� ������� ����������� ��� ��������� ���-���� �� ���������\n");
        yes_no_input(&temp, text);
        if(temp == 'y' || temp == 'Y'){
            open_inventory(item_count);
        }
    }

    if(*item_count != 10){
        string_replace(name, inventory[*item_count].name);
        inventory[*item_count].param = param_ammount; 
        (*item_count)++;
    }
}