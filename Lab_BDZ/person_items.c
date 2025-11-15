#include <stdio.h>
#include "sys_funcs.h"
#include "dungeon_logic.h"
#include "player_parametrs.h"

//логика оружия ------------------------------------------------------------------------------------------------
int weapon_show(items *weapon, int* class){
    if(weapon == NULL){
        printf("Ошибка передачи в weapon_show");
        return 1;
    }
    if(my_strcmp(weapon->name, "кулачки") == 0){
        printf("\n\nТекущее оружие:  %s, урон: %d\n\n", weapon->name, weapon->param);
    }
    else{
        printf("\n\nТекущее оружие:  %s", weapon->name);
        switch(*class){
            case 0:
                printf(" меч");
                break;
            case 1:
                printf(" лук");
                break;
            case 2:
                printf(" бульбулятор");
                break;
            default:
                printf(" кусь");
                break;

        }
        printf(", урон: %d\n\n", weapon->param);
    }
    return 0;
}

int weapon_replace(const char *name, int param, items *weapon, int* class){
    char enter, text[] = "заменить";
    if(weapon == NULL){
        printf("Ошибка передачи в weapon_replace");
        return 1;
    }
    if(weapon->param != -1){
        printf("Оружие уже есть.\n");
        if(my_strcmp(weapon->name, "кулачки") == 0){
            printf("%s -> %s \nИзменение характеристик при замене: %d -> %d\n", weapon->name, name, weapon->param, param);
        }
        else{
            printf("%s", weapon->name);
            switch(*class){
                case 0:
                    printf(" меч");
                    break;
                case 1:
                    printf(" лук");
                    break;
                case 2:
                    printf(" бульбулятор");
                    break;
                default:
                    printf(" кусь");
                    break;

            }
            printf("-> %s \nИзменение характеристик при замене: %d -> %d\n", name, weapon->param, param);
        }
        yes_no_input(&enter, text);
        if(enter == 'y'|| enter == 'Y'){
            weapon->param = -1;
        }
    }
    if(weapon->param == -1){
        string_replace(name, weapon->name);
        weapon->param = param;
    }
    return 0;
}


//логика брони ------------------------------------------------------------------------------------------------
int armour_show(items* armour){
    if(armour == NULL){
        printf("Ошибка передачи в armour_show");
        return 1;
    }
    printf("        ∧　　∧\n");
    printf("　　　(´・ω ・`)            <- Голова:   %s:  защита - %d\n", armour[0].name, armour[0].param);
    printf("　　＿ノ ヽ ノ＼ __\n");
    printf("　 /　`/ ⌒Ｙ⌒ Ｙ　ヽ        <-\n");
    printf("　(　 (三ヽ人　 /　 |       <- Туловище: %s:  защита - %d\n", armour[1].name, armour[1].param);
    printf("　|　ﾉ⌒＼ ￣￣ヽ　 ノ       <-\n");   
    printf("　ヽ＿＿＿＞､＿＿_／\n");
    printf("　　 ｜( 王 王 ﾉ〈　\n");
    printf("　　　 /ﾐ`ー―彡\\　\n");
    printf("     /  /    \\  \\           <- Ноги:     %s:  защита - %d\n", armour[2].name, armour[2].param);
    printf("    /  /      \\  \\          <-\n");
    printf("  ⊃・ω・⊃　　⊃・ω・⊃ \n");
    return 0;
}


int armour_replace(int place, const char *name, int param, items *armour){
    if(armour == NULL){
        printf("Ошибка передачи в armour_replace");
        return 1;
    }
    char enter, text[] = "заменить";
    /* для автозамены нулевого, но я слишком смешные названия придумал
    if(armour[place].param != 0){
        printf("Данный слот брони уже занят. Хотите заменить?\n");
        printf("%s -> %s \nИзменение характеристик при замене: %d -> %d\n", armour[place].name, name, armour[place].param, param);
        yes_no_input(&enter, text);
        if(enter =='y' || enter == 'Y'){
            armour[place].param = -1;
        }
    }
    */
    printf("Данный слот брони уже занят.\n");
    printf("%s -> %s \nИзменение характеристик при замене: %d -> %d\n", armour[place].name, name, armour[place].param, param);
    yes_no_input(&enter, text);
    if(enter =='y' || enter == 'Y'){
        armour[place].param = -1;
    }
    if(armour[place].param == -1){
        string_replace(name, armour[place].name);
        armour[place].param = param;
    }
    return 0;
}



//логика инвентаря ------------------------------------------------------------------------------------------------


int using_item(int num, Parametrs *player, items *inventory){
    int temp = player->hp;
    num--;
    if(num < 0 || num >= player->item_count){
        printf("Эта ячейка инвентаря пуста\n");
        clear_input();
        clear_input();
        return 1;
    }
    change_player_param("hp", inventory[num].param, player); //
    printf("Персонаж выпил зелье\nХп восстановилось %d->%d\n", temp, player->hp);
    clear_input();
    clear_input();
    inventory[num] = inventory[player->item_count - 1];
    player->item_count--;
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


int main_parametrs_show(Parametrs *player){
    if(player == NULL){
        printf("Ошибка передачи параметров в main_parametrs_show");
        return 1;
    }

    printf("Основные параметры:\n");
    printf("HP:  %d/%d\n", player->hp, player->max_hp);
    printf("LVL: %d\n", player->level);
    printf("XP:  %d/%d\n\n", player->xp, player->level * 10);
    return 0;
}


int open_inventory(items *inventory, items *armour, items *weapon, Parametrs *player){
    int command = 0, fl = 0, check = 0, num = 0;
    if(inventory == NULL || armour == NULL || weapon == NULL || player == NULL){
        printf("Ошибка передачи параметров в open_iventory");
        return 1;
    }
    do{
        check += armour_show(armour);
        check += weapon_show(weapon, &player->hero);
        check += main_parametrs_show(player);
        if(check != 0){
            return 1;
        }
        if(player->item_count == 0){
            printf("Ваш инвентарь пуст");
            fl = 1;
        }
        else{
            for(int i = 0; i < player->item_count; i++){
                printf("%d. %s - увеличивает хп на %d единиц.\n", i + 1, inventory[i].name, inventory[i].param);
            }
            printf("\nИспользовать предмета из инвентаря - 1, удалить предмет - 2, выйти из инвентаря - 3\n");
            scanf("%d", &command);
            if(command == 1){
                do{
                    printf("Какой номер хочешь использовать?:");
                    scanf("%d", &num);
                    check = using_item(num, player, inventory);
                }while(check != 0 && player->item_count != 0);
            }
            else if(command == 2){
                do{
                    printf("Какой номер хочешь убрать из инвентаря?:");
                    scanf("%d", &num);
                    check = delete_item(num, &(player->item_count), inventory);
                }while(check != 0 && player->item_count != 0);
            }
            clear_screen();
            if(command != 3 && player->item_count != 0){
                check = armour_show(armour);
                check += weapon_show(weapon, &player->hero);
                if(check != 0){
                    return 1;
                }
            }  
        }
    }while(command != 3 && fl != 1);
    return 0;
}


int add_to_inv(const char *name, int param_ammount, items *inventory, items *armour, items *weapon, Parametrs *player){
    char temp = 'n', text[] = "открыть инвентарь?";
    if(inventory == NULL || armour == NULL || weapon == NULL || player == NULL){
        printf("Ошибка передачи параметров в open_iventory");
        return 1;
    }
    if(player->item_count == player->max_items){
        printf("Ваш инвентраь заполнен, чтобы взять предмет используйте или выбросьте что-либо из инвентаря\n");
        yes_no_input(&temp, text);
        if(temp == 'y' || temp == 'Y'){
            open_inventory(inventory, weapon, armour, player);
        }
    }

    if(player->item_count != player->max_items){
        string_replace(name, inventory[player->item_count].name);
        inventory[player->item_count].param = param_ammount; 
        player->item_count++;
    }
    return 0; 
}