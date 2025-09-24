#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dungeon_logic.h"
#include "text_blocks.h"
#include "sys_funcs.h"
#include "items.h"
#include "fight.h" 


int dungeon[7][3];

void dungeon_generation(){//Fisher-Yates shuffle
    srand(time(NULL));
    int values[3] = {0, 1, 2}; // 0 - empty; 1 - treasuries; 2 - mob

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            dungeon[i][j] = values[j];
        }

        for (int j = 2; j > 0; j--) {
            int k = rand() % (j + 1); 
            int temp = dungeon[i][j];
            dungeon[i][j] = dungeon[i][k];
            dungeon[i][k] = temp;
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
        scanf("%d", &way);
        clear_screen();

        if(way == 4){
            open_inventory();
            add_to_inv("Хилка", 10);
        }
        else{
            switch(dungeon[current_dungeon][way - 1]){
                case 0:
                    empty_dungeon_text();
                    break;
                case 1:
                    treasuries_dungeon_text();
                    printf("Положить предмет в сумку?(y/n):");
                    char ans;
                    scanf(" %c", &ans);
                    if(ans == 'Y' || ans == 'y'){
                        add_to_inv("Хилка", 10);
                    }
                    getchar();
                    break;
                case 2:
                    mob_dungeon_text();
                    fight(current_dungeon);
            }
            printf("Герой покинул пещеру и пошел дальше по единственному туннелю\n");
            getchar();
            current_dungeon++;
        }

        if(current_dungeon != 7){
            clear_screen();
        }
    }
    game_end_text(1);
}