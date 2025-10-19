#include <stdio.h>
#include <string.h>
#include "pearson_items.h"
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

    fprintf(file, "%s|%d|%d|%d|%d|%d|%d", player.name, player.hp, player.max_hp, player.strength, player.level, player.xp, dungeon);
    //тут еще влепить инвентаря сохранение, но эт чет лютое гг
    printf("Сохранение прошло успешно.");
    clear_input();
    fclose(file);
    return 0;
}


int read_file(){
    char result[64], name[64];
    int hp = 0, max_hp = 0, strength = 0, level = 0, xp = 0, dungeon = 0, i = 0, fl = 0;
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        clear_input();
        return -1;
    }
    fscanf(file, "%s", result); // пишут что еще огр длинны надо, почитаем
    printf("%s\n", result);
    for(i = 0; result[i] != '\0'; i++){
        if(result[i] == '|'){
            fl++;
        }
        else{
            switch(fl){
                case 0:
                    name[i] = result[i];
                    break;
                case 1:
                    hp *= 10;
                    hp += result[i] - '0';
                    break;
                case 2:
                    max_hp *= 10;
                    max_hp += result[i] - '0';
                    break;
                case 3:
                    strength *= 10;
                    strength += result[i] - '0';
                    break;
                case 4:
                    level *= 10;
                    level += result[i] - '0';
                    break;
                case 5:
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
    printf("Загрузка сохранения прошла успешно.");
    clear_input();
    fclose(file);
    return dungeon;
}