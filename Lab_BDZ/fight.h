void fight(int lvl){ 
    srand(time(NULL));
    int cube = rand() % 6  + 1;
    int mob_health = lvl * 5;
    clear_input();
    while(get_mathInfo("hp") > 0 ){
        clear_screen();
        printf("���� ��: %d, �� ���� %d", get_mathInfo("hp"), mob_health);
        cube = rand() % 6  + 1;
        mob_health -= cube;
        printf("\n�� ������ ������� � �� ������� %d��\n", cube);
        getchar();
        if(mob_health <= 0){
            printf("������ ���������� � ����\n");
            int temp = get_mathInfo("level");
            change_player_param("xp", lvl * 5);
            printf("����� ������� %d xp �� ������\n", lvl * 5);
            if(temp != get_mathInfo("level")){
                printf("������� ��������� ������� �� %d\n", get_mathInfo("level"));
            }
            getchar();
            break;
        }
        printf("������ ������ ����� � ������ ������ ������� ����.\n");
        printf("�� ������� %d��\n", cube);
        change_player_param("hp", -1 * cube);
        getchar();
        
    }
    if(get_mathInfo("hp") <= 0){
        game_end_text(0);
    }
    // exit(EXIT_SUCCESS);
}