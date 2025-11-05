#include <stdio.h>
#include "sys_funcs.h"
#include "dungeon_logic.h"
#include "player_parametrs.h"

//логика оружия ------------------------------------------------------------------------------------------------
void weapon_show(items *weapon){
    printf("Текущее оружие: \n%s, урон: %d\n\n", weapon->name, weapon->param);
}


void weapon_replace(const char *name, int param, items *weapon){
    char enter, text[] = "заменить";
    if(weapon->param != -1){
        printf("Оружие уже есть.\n");
        printf("%s -> %s \nИзменение характеристик при замене: %d -> %d\n", weapon->name, name, weapon->param, param);
        yes_no_input(&enter, text);
        if(enter == 'y'|| enter == 'Y'){
            weapon->param = -1;
        }
    }
    if(weapon->param == -1){
        string_replace(name, weapon->name);
        weapon->param = param;
    }
}


//логика брони ------------------------------------------------------------------------------------------------
void armour_show(items* armour){
    printf("Броня:\n");
    for(int i = 0; i < 3; i++){
        switch(i){
            case 0:
                printf("Голова:   ");
                break;
            case 1:
                printf("Туловище: ");
                break;
            default:
                printf("Ноги:     ");
        }
        printf("%s:  защита - %d\n", armour[i].name, armour[i].param);
    }
    printf("\n");
}


void armour_replace(int place, const char *name, int param, items *armour){
    char enter, text[] = "заменить";
    if(armour[place].param != 0){
        printf("Данный слот брони уже занят. Хотите заменить?\n");
        printf("%s -> %s \nИзменение характеристик при замене: %d -> %d\n", armour[place].name, name, armour[place].param, param);
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



//логика инвентаря ------------------------------------------------------------------------------------------------


int using_item(int num, int* item_count, Parametrs *player, items *inventory){
    int temp = player->hp;
    num--;
    if(num < 0 || num >= *item_count){
        printf("Эта ячейка инвентаря пуста\n");
        clear_input();
        clear_input();
        return 1;
    }
    change_player_param("hp", inventory[num].param, player); //
    printf("Персонаж выпил зелье\nХп восстановилось %d->%d\n", temp, player->hp);
    inventory[num] = inventory[*item_count - 1];
    (*item_count)--;
    return 0;

}


int delete_item(int num, int* item_count, items *inventory){
    num--;
    if(num < 0 || num >= *item_count){
        printf("Эта ячейка инвентаря пуста\n");
        clear_input();
        clear_input();
        return 1;
    }
    inventory[num] = inventory[*item_count - 1];
    (*item_count)--;
    return 0;
}


void open_inventory(int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player){
    int command = 0, fl = 0;
    do{
        armour_show(armour);
        weapon_show(weapon);
        if(*item_count == 0){
            printf("Ваш инвентарь пуст");
            clear_input();
            fl = 1;
        }
        else{
            for(int i = 0; i < *item_count; i++){
                printf("%d. %s - увеличивает хп на %d единиц.\n", i + 1, inventory[i].name, inventory[i].param);
            }
            printf("\nИспользовать предмета из инвентаря - 1, удалить предмет - 2, выйти из инвентаря - 3\n");
            scanf("%d", &command);
            if(command == 1){
                int num, check;
                do{
                    printf("Какой номер хочешь использовать?:");
                    scanf("%d", &num);
                    check = using_item(num, item_count, player, inventory);
                }while(check != 0 && *item_count != 0);
            }
            else if(command == 2){
                int num, check;
                do{
                    printf("Какой номер хочешь убрать из инвентаря?:");
                    scanf("%d", &num);
                    check = delete_item(num, item_count, inventory);
                }while(check != 0 && *item_count != 0);
            }
            clear_screen();
            if(command != 3 && *item_count != 0){
                armour_show(armour);
                weapon_show(weapon);
            }  
        }
    }while(command != 3 && fl != 1);
}


void add_to_inv(const char *name, int param_ammount, int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player){
    char temp = 'n', text[] = "открыть инвентарь?";
    if(*item_count == 10){
        printf("Ваш инвентраь заполнен, чтобы взять предмет используйте или выбросьте что-либо из инвентаря\n");
        yes_no_input(&temp, text);
        if(temp == 'y' || temp == 'Y'){
            open_inventory(item_count, inventory, weapon, armour, player);
        }
    }

    if(*item_count != 10){
        string_replace(name, inventory[*item_count].name);
        inventory[*item_count].param = param_ammount; 
        (*item_count)++;
    }
}