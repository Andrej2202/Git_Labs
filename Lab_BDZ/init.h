void clear_screen_input() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void start() {
    char s = ' ';
    do{
        printf("����������, ������������� ����������!\n");
        printf("����� ��� ������:\n");
        scanf("%s", &player.name);
        printf("%s, �����?(y/n)\n", player.name);
        scanf(" %c", &s);
        clear_screen();
    }while(s != 'y' && s != 'Y');

    class_pick();
}


void class_pick(){
    printf("%s, ������ ������ �����:\n\n", player.name);
    printf("1) ����: ������ � �� ������? ������ ��� ������ ������, ��� � ����� ����� � � ���.\n");
    printf("��������: ����: ����������������:\n");
    printf("2) �������: �� �� �������� �����. �� ������� ����. ������� ������ ��������, ��� ����� ������� �� ����.\n");
    printf("��������: ����: ����������������:\n");
    printf("3) �������: ��� ���� � ������. ��� ����� � �������. ������ ������ � �������� ������.\n");
    printf("��������: ����: ����������������:\n");
    printf("����� ������� �����(1/2/3):");
    scanf("%d", &player.hero);
    player.hero -= 1;
    switch(player.hero) {
        case 0:
            player.hp = 45; 
            player.strength = 25; 
            player.capacity = 80;
            break;

        case 1:
            player.hp = 15; 
            player.strength = 50; 
            player.capacity = 60;
            break;

        case 2:
            player.hp = 40; 
            player.strength = 20; 
            player.capacity = 30;
            break;
    }  
    player.level = 1;
    clear_screen_input();
}