void class_pick(){
    class_pick_text();
    scanf("%d", &player.hero);
    player.hero -= 1;
    switch(player.hero) {
        case 0:
            player.hp = 45000; 
            player.strength = 25; 
            player.capacity = 80;
            break;

        case 1:
            player.hp = 150000; 
            player.strength = 50; 
            player.capacity = 60;
            break;

        case 2:
            player.hp = 400000; 
            player.strength = 20; 
            player.capacity = 30;
            break;
    }  
    player.max_hp = player.hp;
    player.level = 1;
    player.xp = 0;
    player.addit_strength = 0;
    clear_screen();
    dungeon_exploring();
}


void start() {
    clear_screen();
    char s = ' ';
    do{
        printf("����������, ������������� ����������!\n");
        printf("��� ����������� ������������� �� ���������� ���� ������� ��������� enter\n");
        getchar();
        clear_screen();
        printf("����� ��� ������:\n");
        scanf("%s", player.name);
        printf("%s, �����?(y/n)\n", player.name);
        scanf(" %c", &s);
        clear_screen();
    }while(s != 'y' && s != 'Y');

    class_pick();
}