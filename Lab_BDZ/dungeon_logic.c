#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "fight.h" 
#include "saving.h"
#include "sys_funcs.h"
#include "treasuries.h"
#include "text_blocks.h"
#include "person_items.h"
#include "dungeon_logic.h"
#include "player_parametrs.h"


int dungeon_generation(int* dungeon){
    if(dungeon == NULL){
        printf("Ошибка получения dungeon в dungeon_generation");
        return 1;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            *(dungeon + i * 2 + j) = j;
        }

        int k = rand() % 2; 
        if(k == 1){
            int temp = *(dungeon + i * 2 + 0);
            *(dungeon + i * 2 + 0) = *(dungeon + i * 2 + 1);
            *(dungeon + i * 2 + 1) = temp;
        }
    }
    return 0;
}


int dungeon_exploring(){
    int dungeon[7][2];
    int current_dungeon = 1, way = 0, check = 0, fight_result = 0, item_count = 0, saving_fl = 0;
    Parametrs player;
    items weapon = {"Базовый меч", 0};
    items armour[3] = {
        {"Шапка петушок", 0},
        {"Майка алкоголичка", 0},
        {"Штаны 40 гривен", 0}
    };
    items inventory[10] = {0};

    check = dungeon_generation(&dungeon[0][0]);
    if(check != 0){
        return 1;
    }

    clear_screen();
    printf("Здравствуй, исследователь подземелий!\n");
    printf("Для продолжения повествования на протяжении всей истории используй enter\n");
    clear_input();
    clear_screen();
    check = class_pick(&player);
    if(check != 0){
        return 1;
    }

    entering_dungeons_text(&player);
    while(current_dungeon < 7){
        do{
            each_dungeon_text();
            check = scanf("%d", &way);            
            clear_input();
            if(way < 1 || way > 5){
                clear_screen();
                printf("Такого пути не существует, введите заново\n");
            }
        }while(check != 1 || (way < 1 || way > 5));
        clear_screen();
        
        if(way == 3){
            check = open_inventory(&item_count, inventory, armour, &weapon, &player); 
            if(check != 0){
                return 1;
            }
            clear_input();
        }
        else if(way == 4){
            saving_fl = 1;
            check = save_to_file(current_dungeon, item_count, inventory, armour, &weapon, &player);
            if(check != 0){
                return 1;
            }
        }
        else if(way == 5){
            if(saving_fl == 1){
                check = read_file(&current_dungeon, &item_count, inventory, armour, &weapon, &player);
                if(check != 0){
                    return 1;
                }
            }
            else{
                printf("Вы еще не сохранялись");
                clear_input();
            }
            
        }
        else{
            if(dungeon[current_dungeon][way - 1] == 0){
                check = give_treasuries(&item_count, inventory, armour, &weapon, &player);
                if(check != 0){
                    return 1;
                }
            }
            else{
                check = fight(current_dungeon, &item_count, &fight_result, inventory, armour, &weapon, &player);
                if(check != 0){
                    return 1;
                }
                if(fight_result == 0){
                    break;
                }
            }
            printf("Герой покинул пещеру и пошел дальше по единственному туннелю\n");
            clear_input();
            current_dungeon++;
        }

        if(current_dungeon != 7){
            clear_screen();
        }
    }
    
    if(saving_fl == 1 && remove("data.txt") != 0){
        printf("Ошибка удаления файла");
    }
    if(fight_result == 0){
        game_end_text(0);
    }
    else{
        game_end_text(1);
    } 
    return 0;
}