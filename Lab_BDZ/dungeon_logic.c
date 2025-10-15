#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fight.h" 
#include "items.h"
#include "saving.h"
#include "sys_funcs.h"
#include "treasuries.h"
#include "text_blocks.h"
#include "dungeon_logic.h"


int dungeon[7][2];

void dungeon_generation(){
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            dungeon[i][j] = j;
        }

        int k = rand() % 2; 
        if(k == 1){
            int temp = dungeon[i][0];
            dungeon[i][0] = dungeon[i][1];
            dungeon[i][1] = temp;
        }
        
    }
}


void dungeon_exploring(){
    
    int current_dungeon = 1, way = 0, check = 0, fight_result = 0, temp = -1;

    dungeon_generation();
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
            open_inventory();
        }
        else if(way == 4){
            save_to_file(current_dungeon);
        }
        else if(way == 5){
            temp = read_file();
            if(temp != -1){
                current_dungeon = temp;
            }
        }
        else{
            if(dungeon[current_dungeon][way - 1] == 0){
                int sub_way = rand() % 2;
                if(sub_way == 0){
                    empty_dungeon_text();
                }
                else{
                    give_treasuries();
                } 
            }
            else{
                fight_result = fight(current_dungeon);
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
    if(fight_result == 0){
        game_end_text(0);
    }
    else{
        game_end_text(1);
    }
}