#include <stdio.h>
#include <string.h>
#include "person_items.h"
#include "saving.h"
#include "sys_funcs.h"
#include "player_parametrs.h"


int save_to_file(int dungeon){
    FILE *file = fopen("data.txt", "w"); // w - перезапись a - дозапись
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        clear_input();
        return 1;
    }
    //основные параметры
    fprintf(file, "%d|%d|%d|%d|%d|%d\n", player.hp, player.max_hp, player.strength, player.level, player.xp, dungeon);
    //оружие
    fprintf(file, "%s|%d\n", weapon.name, weapon.param);
    //броня
    for(int i = 0; i < 3; i++){
        fprintf(file, "%s|%d\n", armour[i].name, armour[i].param);
    }
    //инвентарь
    for(int i = 0; i < 10; i++){
        fprintf(file, "%s|%d\n", inventory[i].name, inventory[i].param);
    }

    printf("Сохранение прошло успешно.");
    clear_input();
    fclose(file);
    return 0;
}


int read_file(){
    char result[64];
    int hp = 0, max_hp = 0, strength = 0, level = 0, xp = 0, dungeon = 0, i = 0, fl = 0;
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        clear_input();
        return -1;
    }
    fscanf(file, "%s", result); // пишут что еще огр длинны надо, почитаем
    printf("%s\n", result); //считали основные параметры
    for(i = 0; result[i] != '\n'; i++){
        if(result[i] == '|'){
            fl++;
        }
        else{
            switch(fl){
                case 0:
                    hp *= 10;
                    hp += result[i] - '0';
                    break;
                case 1:
                    max_hp *= 10;
                    max_hp += result[i] - '0';
                    break;
                case 2:
                    strength *= 10;
                    strength += result[i] - '0';
                    break;
                case 3:
                    level *= 10;
                    level += result[i] - '0';
                    break;
                case 4:
                    xp *= 10;
                    xp += result[i] - '0';
                    break;
                default:
                    dungeon *= 10;
                    dungeon += result[i] - '0';
            }
        }
    }
    
    player.hp = hp;
    player.max_hp = max_hp;
    player.strength = strength;
    player.level = level;
    // нужно считать еще оружие, броню и инвентарь
    printf("Загрузка сохранения прошла успешно.");
    clear_input();
    fclose(file);
    return dungeon;
    
}