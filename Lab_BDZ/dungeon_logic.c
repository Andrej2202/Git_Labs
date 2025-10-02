#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fight.h" 
#include "items.h"
#include "sys_funcs.h"
#include "treasuries.h"
#include "text_blocks.h"
#include "dungeon_logic.h"


int dungeon[7][2];

void dungeon_generation(){//Fisher-Yates shuffle
    srand(time(NULL));
    int values[2] = {0, 1}; // 0 - treasuries/nothing; 1 - mob;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            dungeon[i][j] = values[j];
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
    dungeon_generation();
    
    entering_dungeons_text();

    int current_dungeon = 1;
    while(current_dungeon < 7){
        each_dungeon_text(current_dungeon);

        int way = 0;
        do{
            scanf("%d", &way);
            if(way < 1 || way > 3){
                printf("Такого пути не существует");
            }
        }while(way < 1 || way > 3);
        clear_screen();

        if(way == 3){
            open_inventory();
            // add_to_inv("Хилка", 10);
        }
        else{
            switch(dungeon[current_dungeon][way - 1]){
                case 0:
                    give_treasuries();
                    break;
                default:
                    fight(current_dungeon);
            }
            printf("Герой покинул пещеру и пошел дальше по единственному туннелю\n");
            enter_expect();
            current_dungeon++;
        }

        if(current_dungeon != 7){
            clear_screen();
        }
    }
    game_end_text(1);
}