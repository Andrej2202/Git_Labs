#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fight.h" 
#include "saving.h"
#include "sys_funcs.h"
#include "treasuries.h"
#include "text_blocks.h"
#include "person_items.h"
#include "dungeon_logic.h"
#include "player_parametrs.h"


int dungeon_generation(int* dungeon){
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


void dungeon_exploring(){
    int dungeon[7][2];
    int current_dungeon = 1, way = 0, check = 0, fight_result = 0, temp = -1, item_count = 0;

    dungeon_generation(&dungeon[0][0]);

    entering_dungeons_text();

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
            open_inventory(&item_count);
            clear_input();
        }
        else if(way == 4){
            save_to_file(current_dungeon, item_count);
        }
        else if(way == 5){
            temp = read_file(0, &current_dungeon, &item_count);
            if(temp != 0){
                printf("Ошибка загрузки сохранения.");
                clear_input();
            }
        }
        else{
            if(dungeon[current_dungeon][way - 1] == 0){
                give_treasuries(&item_count);
            }
            else{
                fight(current_dungeon, &item_count, &fight_result);
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
    item_count = 0;
    temp = clear_player_parametrs();
    if(temp != 0){
        printf("ошибка очистки параметров персонажа"); 
    }
    if(fight_result == 0){
        game_end_text(0);
    }
    else{
        game_end_text(1);
    }
}