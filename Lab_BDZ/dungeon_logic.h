int dungeon[7][3];
int current_dungeon = 1;

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
    for (int i = 0; i < 7; i++){
        each_dungeon_text(i);

        int way = 0;
        scanf("%d", &way);
        current_dungeon = i + 1;
        clear_screen();
        switch(dungeon[i][way - 1]){
            case 0:
                empty_dungeon_text();
                break;
            case 1:
                treasuries_dungeon_text();
                break;
            case 2:
                mob_dungeon_text();
                fight(current_dungeon);
        }
        printf("Герой покинул пещеру и пошел дальше по единственному туннелю\n");
        getchar();
        if(i != 6){
            clear_screen();
        }
    }
    game_end_text(1);
}