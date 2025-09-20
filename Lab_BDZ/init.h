void class_pick(){
    class_pick_text();
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
    player.xp = 0;
    clear_screen();
    dungeon_exploring();
}


void start() {
    char s = ' ';
    do{
        printf("Здравствуй, исследователь подземелий!\n");
        printf("Для продолжения истории на протяжении всей истории используй enter\n");
        getchar();
        clear_screen();
        printf("Введи имя игрока:\n");
        scanf("%s", &player.name);
        printf("%s, верно?(y/n)\n", player.name);
        scanf(" %c", &s);
        clear_screen();
    }while(s != 'y' && s != 'Y');

    class_pick();
}