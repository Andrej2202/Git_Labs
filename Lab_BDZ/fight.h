void fight(int lvl){ 
    srand(time(NULL));
    int cube = rand() % 6  + 1;
    int mob_health = lvl * 5;
    while(mob_health > 0 && get_mathInfo("hp") > 0 ){
        printf("Скелет сделал выпад и ловким ударом поранил тебя.\n");
        printf("Ты потерял %dхп", cube);
        change_player_param("hp", -1 * cube);
        // у сука проверка на 0 и меньше хп
        clear_input();
        getchar();
        cube = rand() % 6  + 1;
        printf("\nТы ударил в ответ и скелет потерял %dхп\n", cube);
        getchar();
    }
    if(get_mathInfo("hp") <= 0){
        printf("Ты пал смертью храбрых...");
        exit(EXIT_SUCCESS); 
    }
    // exit(EXIT_SUCCESS);
}