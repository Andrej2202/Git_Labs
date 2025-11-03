#include <stdio.h>
#include <string.h>
#include "saving.h"
#include "sys_funcs.h"
#include "player_parametrs.h"
#define IS_HEADER(s) \
    (my_strcmp("===MAIN_PARAMETRS===", (s)) == 0 || \
     my_strcmp("===WEAPON===", (s)) == 0 || \
     my_strcmp("===ARMOUR===", (s)) == 0 || \
     my_strcmp("===INVENTORY===", (s)) == 0 || \
     my_strcmp("===END_OF_SAVE===", (s)) == 0)


int save_to_file(int dungeon, int item_count, items *inventory, items *armour, items *weapon, Parametrs *player){
    FILE *file = fopen("data.txt", "w"); // w - перезапись a - дозапись
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        clear_input();
        return -1;
    }
    //основные параметры
    fprintf(file, "===MAIN_PARAMETRS===\n");
    fprintf(file, "%d|%d|%d|%d|%d|%d|%d\n", player->hp, player->max_hp, player->strength, player->level, player->xp, dungeon, item_count);
    //оружие
    fprintf(file, "===WEAPON===\n");
    fprintf(file, "%s|%d\n", weapon->name, weapon->param);
    //броня
    fprintf(file, "===ARMOUR===\n");
    for(int i = 0; i < 3; i++){
        fprintf(file, "%s|%d\n", armour[i].name, armour[i].param);
    }
    //инвентарь
    fprintf(file, "===INVENTORY===\n");
    for(int i = 0; i < 10; i++){
        fprintf(file, "%s|%d\n", inventory[i].name, inventory[i].param);
    }
    fprintf(file, "===END_OF_SAVE===\n");
    printf("Сохранение прошло успешно.");
    clear_input();
    fclose(file);
    return 0;
}


int read_mainParam(char *res, int* cur_dungeon, int* item_count, Parametrs *player){
    int hp = 0, max_hp = 0, strength = 0, level = 0, xp = 0, dungeon = 0, item_c = 0,  fl = 0;
    if(res == NULL) return 1;

    for(int i = 0; res[i] != '\0'; i++){
        if(res[i] == '|'){
            fl++;
        }
        else{
            switch(fl){
                case 0:
                    hp *= 10;
                    hp += res[i] - '0';
                    break;
                case 1:
                    max_hp *= 10;
                    max_hp += res[i] - '0';
                    break;
                case 2:
                    strength *= 10;
                    strength += res[i] - '0';
                    break;
                case 3:
                    level *= 10;
                    level += res[i] - '0';
                    break;
                case 4:
                    xp *= 10;
                    xp += res[i] - '0';
                    break;
                case 5:
                    dungeon *= 10;
                    dungeon += res[i] - '0';
                    break;
                case 6:
                    item_c *= 10;
                    item_c += res[i] - '0';
                    break;
                default:
                 return 1;
            }
        }
    } 
    player->hp = hp;
    player->max_hp = max_hp;
    player->strength = strength;
    player->level = level;
    *item_count = item_c;
    *cur_dungeon = dungeon;
    return 0;
}


int read_weapon(char *res, items *weapon){
    int fl = 0, param = 0, result = 0;
    char name[64] = ""; 
    if(res == NULL) return 1;

    for(int i = 0; res[i] != '\0'; i++){
        if(res[i] == '|'){
            fl++;
        }
        else{
            switch(fl){
                case 0:
                    name[i] += res[i];
                    break;
                default:
                    param *= 10;
                    param += res[i] - '0';
            }
        }
    } 
    weapon->param = param;
    result = string_replace(name, weapon->name);
    return result;
}


int read_armour_and_inv(char *res, int place, items *inv_armour){
    int fl = 0, param = 0, result = 0;
    char name[64] = ""; 
    if(res == NULL) return 1;

    for(int i = 0; res[i] != '\0'; i++){
        if(res[i] == '|'){
            fl++;
        }
        else{
            switch(fl){
                case 0:
                    name[i] += res[i];
                    break;
                default:
                    param *= 10;
                    param += res[i] - '0';
            }
        }
    }
    
    inv_armour[place].param = param;
    result = string_replace(name, inv_armour[place].name);
    return result;
}


int read_file(int file_num, int* cur_dungeon, int* item_count, items *inventory, items *armour, items *weapon, Parametrs *player){
    char result[64];
    int  counter = 0, armour_place = 0, inv_place = 0, error_count = 0;
    FILE *file;
    if(file_num == 0){
        file = fopen("data.txt", "r");
    }
    else{
        file = fopen("clear_data.txt", "r");
    }

    if (file == NULL) {
        return -1;
    }
    do{
        fgets(result, sizeof(result), file);
        // printf("%s", result);
        remove_n(result);
        if(IS_HEADER(result)){
            counter++;
            continue;
        }
        switch(counter){
            case 1:
                error_count += read_mainParam(result, cur_dungeon, item_count, player);
                break;
            case 2:
                error_count += read_weapon(result, weapon);
                break;
            case 3:
                error_count += read_armour_and_inv(result, armour_place, armour);
                armour_place++;
                break;
            case 4:
                error_count += read_armour_and_inv(result, inv_place, inventory);
                inv_place++;
                break;
            default:
                printf("Error: you're out from save");
                return 1;
        }
        if(error_count != 0){
            printf("Error in switch");
            return 1;
        }
        // printf("%s\n", result);
    }while(my_strcmp("===END_OF_SAVE===", result));
    if(file_num == 0){
        printf("Загрузка сохранения прошла успешно.");
        clear_input();
    }
    fclose(file);
    return 0;
    
}