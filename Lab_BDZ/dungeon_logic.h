int dungeon[7][3];
int current_dungeon = 1;

void dungeon_generation(){//Fisher-Yates shuffle
    srand(time(NULL));
    int values[3] = {0, 1, 2};

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
    
    entering_dungeon_text();

    printf("Для начала пути нажмите enter");
    getchar();
    /*
    for (int i = 0; i < 7; i++){
        
    }
    */
}