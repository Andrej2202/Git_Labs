void fight(int lvl){ 
    srand(time(NULL));
    int cube = rand() % 6  + 1;
    int mob_health = lvl * 5;
    while(mob_health > 0 && get_mathInfo("hp") > 0 ){
        printf("������ ������ ����� � ������ ������ ������� ����.\n");
        printf("�� ������� %d��", cube);
        change_player_param("hp", -1 * cube);
        // � ���� �������� �� 0 � ������ ��
        clear_input();
        getchar();
        cube = rand() % 6  + 1;
        printf("\n�� ������ � ����� � ������ ������� %d��\n", cube);
        getchar();
    }
    if(get_mathInfo("hp") <= 0){
        printf("�� ��� ������� �������...");
        exit(EXIT_SUCCESS); 
    }
    // exit(EXIT_SUCCESS);
}