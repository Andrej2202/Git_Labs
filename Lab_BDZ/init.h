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
        printf("Здравствуй, исследователь подземелий!\n");
        printf("Введи имя игрока:\n");
        scanf("%s", &player.name);
        printf("%s, верно?(y/n)\n", player.name);
        scanf(" %c", &s);
        clear_screen();
    }while(s != 'y' && s != 'Y');

    class_pick();
}


void class_pick(){
    printf("%s, выбери своего героя:\n\n", player.name);
    printf("1) Воин: Почему я не умираю? Потому что смерть боится, что я начну драку и в аду.\n");
    printf("Здоровье: Сила: Грузоподьемность:\n");
    printf("2) Охотник: Ты не услышишь шагов. Не увидишь тени. Успеешь только пожалеть, что вышел сегодня из дома.\n");
    printf("Здоровье: Сила: Грузоподьемность:\n");
    printf("3) Алхимик: Мой мозг — оружие. Моя колба — арсенал. Смерть врагов — побочный эффект.\n");
    printf("Здоровье: Сила: Грузоподьемность:\n");
    printf("Вашим героеем будет(1/2/3):");
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